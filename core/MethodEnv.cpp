/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


#include "avmplus.h"

namespace avmplus
{

    void MethodEnv::argcError(int32_t argc)
    {
        MethodSignaturep ms = get_ms();
        AvmAssert(!ms->argcOk(argc));
        toplevel()->argumentErrorClass()->throwError(kWrongArgumentCountError,
                               core()->toErrorString(method),
                               core()->toErrorString(ms->requiredParamCount()),
                               core()->toErrorString(argc));
    }

    MethodEnv::MethodEnv(MethodInfo* method, ScopeChain* scope) :
        method(method),
        _scope(scope),
        activationOrMCTable(0)
    {
        AvmAssert(method != NULL);
        core()->exec->init(this);

        if (method->declaringTraits() != this->vtable()->traits)
        {
        #ifdef AVMPLUS_VERBOSE
            core()->console << "ERROR " << method->getMethodName() << " " << method->declaringTraits() << " " << this->vtable()->traits << "\n";
        #endif
            AvmAssertMsg(0, "(method->declaringTraits != vtable->traits)");
            toplevel()->throwVerifyError(kCorruptABCError);
        }

        // activation info used to be created here, but is now created lazily
    }

#ifdef DEBUGGER
    void MethodEnv::debugEnter( const uint8_t* frame_sst,
                                CallStackNode* callstack,
                                FramePtr framep,
                                volatile intptr_t *eip)
    {
        AvmAssert(this != 0);
        AvmAssert(callstack != 0);
        callstack->init(this, framep, frame_sst, eip);
        debugEnterInner();
    }

    void MethodEnv::debugEnterInner()
    {
        AvmAssert(this != 0);
        AvmCore* core = this->core();

        Sampler* s = core->get_sampler();

        // this shouldn't ever be called unless there's a debugger
        AvmAssert(core->debugger() != NULL);
        Debugger* debugger = core->debugger();
        if (debugger)
            debugger->_debugMethod(this);

        if (s)
            s->sampleCheck();

        // method_id can legitimately be -1 for activations, but we don't care about those here,
        // so just ignore them.
        const int32_t method_id = this->method->method_id();
        if (method_id >= 0)
        {
            this->abcEnv()->invocationCount(method_id) += 1;    // returns a reference, so this works
        }
    }

    void MethodEnv::debugExit(CallStackNode* callstack)
    {
        AvmAssert(this != 0);
        AvmAssert(callstack != 0);
        AvmCore* core = this->core();

        Sampler* s = core->get_sampler();
        if (s != 0)
        {
            // do this before popping the stack, so that the time slice
            // gets attributed to the function that is exiting
            s->sampleCheck();
        }

        core->callStack = callstack->next();

        // trigger a faked "line number changed" since we exited the function and are now back on the old line (well, almost)
        if (core->callStack && core->callStack->linenum() > 0)
        {
            int32_t line = core->callStack->linenum();
            core->callStack->set_linenum(-1);
            Debugger* debugger = core->debugger();
            if (debugger)
                debugger->debugLine(line);
        }
    }

    uint64_t MethodEnv::invocationCount() const
    {
        const int32_t method_id = this->method->method_id();
        if (method_id < 0) return 0;
        return this->abcEnv()->invocationCount(method_id);
    }
#endif // DEBUGGER

    void FASTCALL MethodEnv::nullcheckfail(Atom atom)
    {
        AvmAssert(AvmCore::isNullOrUndefined(atom));

        // TypeError in ECMA
        Toplevel* toplevel = this->toplevel();
        ErrorClass *error = toplevel->typeErrorClass();
        if( error ){
            error->throwError(
                    (atom == undefinedAtom) ? kConvertUndefinedToObjectError :
                                        kConvertNullToObjectError);
        } else {
            toplevel->throwVerifyError(kCorruptABCError);
        }
    }

    ArrayObject* MethodEnv::createRest(Atom* argv, int32_t argc)
    {
        // create arguments Array using argv[param_count..argc]
        MethodSignaturep ms = get_ms();
        const int32_t param_count = ms->param_count();
        Atom* extra = argv + param_count + 1;
        const int32_t extra_count = argc > param_count ? argc - param_count : 0;
        return toplevel()->arrayClass->newarray(extra, extra_count);
    }

#if defined VMCFG_NANOJIT || defined VMCFG_AOT

    Atom MethodEnv::getpropertyHelper(Atom obj, /* not const */ Multiname *multi, VTable *vtable, Atom index)
    {
        if (atomIsIntptr(index) && atomCanBeInt32(index))
        {
            return getpropertylate_i(obj, (int32_t)atomGetIntptr(index));
        }

        if (atomKind(index) == kDoubleType)
        {
            int32_t i = AvmCore::integer_i(index);
            if ((double)i == AvmCore::atomToDouble(index))
            {
                return getpropertylate_i(obj, i);
            }
        }

        if (AvmCore::isObject(index))
        {
            ScriptObject* i = AvmCore::atomToScriptObject(index);
            if (i->traits() == core()->traits.qName_itraits)
            {
                QNameObject* qname = (QNameObject*) i;
                qname->getMultiname(*multi);
            }
            else if(!multi->isRtns() && AvmCore::isDictionary(obj))
            {
                return AvmCore::atomToScriptObject(obj)->getAtomProperty(index);
            }
            else
            {
                multi->setName(core()->intern(index));
            }
        }
        else
        {
            multi->setName(core()->intern(index));
        }

        return toplevel()->getproperty(obj, multi, vtable);
    }

    void MethodEnv::initpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index)
    {
        if (atomIsIntptr(index) && atomCanBeInt32(index))
        {
            setpropertylate_i(obj, (int32_t)atomGetIntptr(index), value);
            return;
        }

        if (atomKind(index) == kDoubleType)
        {
            int32_t i = AvmCore::integer(index);
            uint32_t u = uint32_t(i);
            if ((double)u == AvmCore::atomToDouble(index))
            {
                setpropertylate_u(obj, u, value);
                return;
            }
            else if ((double)i == AvmCore::atomToDouble(index))
            {
                setpropertylate_i(obj, i, value);
                return;
            }
        }

        if (AvmCore::isObject(index))
        {
            ScriptObject* i = AvmCore::atomToScriptObject(index);
            if (i->traits() == core()->traits.qName_itraits)
            {
                QNameObject* qname = (QNameObject*) i;
                qname->getMultiname(*multi);
            }
            else
            {
                multi->setName(core()->intern(index));
            }
        }
        else
        {
            multi->setName(core()->intern(index));
        }

        initproperty(obj, multi, value, vtable);
    }

    void MethodEnv::setpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index)
    {
        // the positive-integer case is inlined into setprop_index in jit-calls.h,
        // this handles the negative case
        if (atomIsIntptr(index) && atomCanBeInt32(index))
        {
            setpropertylate_i(obj, (int32_t)atomGetIntptr(index), value);
            return;
        }

        if (atomKind(index) == kDoubleType)
        {
            int32_t i = AvmCore::integer(index);
            uint32_t u = uint32_t(i);
            if ((double)u == AvmCore::atomToDouble(index))
            {
                setpropertylate_u(obj, u, value);
                return;
            }
            else if ((double)i == AvmCore::atomToDouble(index))
            {
                setpropertylate_i(obj, i, value);
                return;
            }
        }

        if (AvmCore::isObject(index))
        {
            ScriptObject* i = AvmCore::atomToScriptObject(index);
            if (i->traits() == core()->traits.qName_itraits)
            {
                QNameObject* qname = (QNameObject*) i;
                qname->getMultiname(*multi);
            }
            else if(!multi->isRtns() && AvmCore::isDictionary(obj))
            {
                AvmCore::atomToScriptObject(obj)->setAtomProperty(index, value);
                return;
            }
            else
            {
                multi->setName(core()->intern(index));
            }
        }
        else
        {
            multi->setName(core()->intern(index));
        }

        toplevel()->setproperty(obj, multi, value, vtable);
    }

    Atom MethodEnv::delpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom index)
    {
        AvmCore* core = this->core();

        if (AvmCore::isObject(obj) && AvmCore::isObject(index))
        {
            if (AvmCore::isXMLList(index) )
            {
                // Error according to E4X spec, section 11.3.1
                toplevel()->throwTypeError(kDeleteTypeError, core->toErrorString(toplevel()->toTraits(index)));
            }
            ScriptObject* i = AvmCore::atomToScriptObject(index);
            if (i->traits() == core->traits.qName_itraits)
            {
                QNameObject* qname = (QNameObject*) i;
                qname->getMultiname(*multi);
            }
            else if(!multi->isRtns() && AvmCore::isDictionary(obj))
            {
                bool res = AvmCore::atomToScriptObject(obj)->deleteAtomProperty(index);
                return res ? trueAtom : falseAtom;
            }
            else
            {
                multi->setName(core->intern(index));
            }
        }
        else
        {
            multi->setName(core->intern(index));
        }

        return delproperty(obj, multi);
    }

    void MethodEnv::initMultinameLateForDelete(Multiname& name, Atom index)
    {
        AvmCore *core = this->core();

        if (AvmCore::isObject(index))
        {
            if (AvmCore::isXMLList(index))
            {
                // Error according to E4X spec, section 11.3.1
                toplevel()->throwTypeError(kDeleteTypeError, core->toErrorString(toplevel()->toTraits(index)));
            }

            ScriptObject* i = AvmCore::atomToScriptObject(index);
            if (i->traits() == core->traits.qName_itraits)
            {
                QNameObject* qname = (QNameObject*) i;
                bool attr = name.isAttr();
                qname->getMultiname(name);
                if (attr)
                    name.setAttr(attr);
                return;
            }
        }

        name.setName(core->intern(index));
    }
#endif

    ScriptObject* MethodEnv::newcatch(Traits* traits)
    {
        AvmCore* core = this->core();
        Toplevel* toplevel = this->toplevel();
        if (traits == core->traits.object_itraits)
        {
            // don't need temporary vtable.  this is a scope for a finally clause
            // todo: asc shouldn't even call OP_newcatch in a finally clause
            return toplevel->objectClass->construct();
        }
        else
        {
            VTable* vt = core->newVTable(traits, NULL, toplevel);
            ScopeChain* catchScope = this->scope()->cloneWithNewVTable(core->GetGC(), vt, this->abcEnv());
            vt->resolveSignatures(catchScope);
            return core->newObject(vt, NULL);
        }
    }

#ifdef VMCFG_NANOJIT
    ArrayObject* MethodEnv::createArgumentsHelper(int argc, uint32_t *ap)
    {
        // create arguments using argv[1..argc].
        // Even tho E3 says create an Object, E4 says create an Array so thats what we will do.
        AvmAssert(argc >= 0);
        MMgc::GC::AllocaAutoPtr _atomv;
        Atom* atomv = (Atom*) VMPI_alloca(core(), _atomv, (argc+1) * sizeof(Atom));
        method->getMethodSignature()->boxArgs(core(), argc, ap, atomv);
        return createArguments(atomv, argc);
    }

    ArrayObject* MethodEnv::createRestHelper(int argc, uint32_t *ap)
    {
        // create rest Array using argv[param_count..argc]
        MethodSignaturep ms = get_ms();
        const int rest_offset = ms->rest_offset();
        union {
            char* extra_8;
            Atom* extra;
        };
        extra_8 = (char*)ap + rest_offset;
        const int param_count = ms->param_count();
        const int extra_count = argc > param_count ? argc - param_count : 0;
        return toplevel()->arrayClass->newarray(extra, extra_count);
    }

#endif // VMCFG_NANOJIT

    /*bool*/ int32_t MethodEnv::haspropertylate_u(Atom obj, uint32_t index) const
    {
        // keep in sync with Toplevel::in_operator
        ScriptObject *o = (atomKind(obj) == kObjectType) ?
            AvmCore::atomToScriptObject(obj) :
            this->toplevel()->toPrototype(obj);
        bool present = o->hasUintProperty(index);
        return (int32_t)present;
    }

    /*bool*/ int32_t MethodEnv::haspropertylate_i(Atom obj, int32_t index) const
    {
        // keep in sync with Toplevel::in_operator
        ScriptObject *o = (atomKind(obj) == kObjectType) ?
            AvmCore::atomToScriptObject(obj) :
            this->toplevel()->toPrototype(obj);
        bool present;
        if (index >= 0) {
            present = o->hasUintProperty((uint32_t)index);
        } else {
            Atom interned = this->core()->internInt(index)->atom();
            present = o->hasAtomProperty(interned);
        }
        return (int32_t)present;
    }

    Atom MethodEnv::getpropertylate_i(Atom obj, int32_t index) const
    {
        // here we put the case for bind-none, since we know there are no bindings
        // with numeric names.
        if (atomKind(obj) == kObjectType)
        {
            if (index >= 0)
            {
                // try dynamic lookup on instance.  even if the traits are sealed,
                // we might need to search the prototype chain
                return AvmCore::atomToScriptObject(obj)->getUintProperty(index);
            }
            else
            {
                // negative - we must intern the integer
                return AvmCore::atomToScriptObject(obj)->getAtomProperty(this->core()->internInt(index)->atom());
            }
        }
        else
        {
            // primitive types are not dynamic, so we can go directly
            // to their __proto__ object
            AvmCore* core = this->core();
            Toplevel *toplevel = this->toplevel();
            ScriptObject *protoObject = toplevel->toPrototype(obj);
            return protoObject->ScriptObject::getStringPropertyFromProtoChain(core->internInt(index), protoObject, toplevel->toTraits(obj));
        }
    }

    Atom MethodEnv::getpropertylate_u(Atom obj, uint32_t index) const
    {
        // here we put the case for bind-none, since we know there are no bindings
        // with numeric names.
        if (atomKind(obj) == kObjectType)
        {
            // try dynamic lookup on instance.  even if the traits are sealed,
            // we might need to search the prototype chain
            return AvmCore::atomToScriptObject(obj)->getUintProperty(index);
        }
        else
        {
            // primitive types are not dynamic, so we can go directly
            // to their __proto__ object
            AvmCore* core = this->core();
            Toplevel *toplevel = this->toplevel();
            ScriptObject *protoObject = toplevel->toPrototype(obj);
            return protoObject->ScriptObject::getStringPropertyFromProtoChain(core->internUint32(index), protoObject, toplevel->toTraits(obj));
        }
    }

    ScriptObject* MethodEnv::finddef(const Multiname* multiname) const
    {
        // getting toplevel() is slightly more expensive than it used to be (more indirection)...
        // so only extract in the (rare) event of an exception

        AbcEnv* abcEnv = this->abcEnv();
        AvmCore* core = abcEnv->core();
        ScriptEnv* script = core->domainMgr()->findScriptEnvInAbcEnvByMultiname(abcEnv, *multiname);
        if (script == (ScriptEnv*)BIND_AMBIGUOUS)
            this->toplevel()->throwReferenceError(kAmbiguousBindingError, multiname);

        if (script == (ScriptEnv*)BIND_NONE)
            this->toplevel()->throwReferenceError(kUndefinedVarError, multiname);

        ScriptObject* global = script->global;
        if (!global)
        {
            global = script->initGlobal();
            script->coerceEnter(global->atom());
        }
        return global;
    }

    /*static*/ ScopeChain* ScriptEnv::createScriptScope(const ScopeTypeChain* stc, VTable* _vtable, AbcEnv* _abcEnv)
    {
        AvmCore* core = _vtable->core();
        // NOTE the namespace here is the default xml namespaces. we use the caller's public
        return ScopeChain::create(core->GetGC(), _vtable, _abcEnv, stc, NULL, core->findPublicNamespace());
    }

    ScriptObject* ScriptEnv::initGlobal()
    {
        AvmAssert(this->global == NULL);
        // object not defined yet.  define it by running the script that exports it
        this->vtable()->resolveSignatures(this->scope());
        // resolving the vtable also resolves the traits, if necessary
        ObjectClass* const objectClass = this->toplevel()->objectClass;
        ScriptObject* const delegate = objectClass ? objectClass->prototypePtr() : NULL;
        global = this->core()->newObject(this->vtable(), delegate);
        return global;
    }

    ScriptObject* MethodEnv::op_newobject(Atom* sp, int argc) const
    {
        // pre-size the hashtable since we know how many vars are coming
        VTable* object_ivtable = toplevel()->object_ivtable;
        AvmCore* core = this->core();

        ScriptObject* o = ScriptObject::create(core->GetGC(), object_ivtable, toplevel()->objectClass->prototypePtr(), 2*argc+1);

        for (; argc-- > 0; sp -= 2)
        {
            Atom name = sp[-1];
            //verifier should ensure names are String
            //todo have the verifier take care of interning too
            AvmAssert(AvmCore::isString(name));

            o->setAtomProperty(core->internString(name)->atom(), sp[0]);
        }
        return o;
    }



    Atom MethodEnv::nextname(Atom objAtom, int index) const
    {
        //  Handle special case inputs;
        //  bad index returns null,
        //  null object throws error.
        if (index <= 0)
        {
            return nullStringAtom;
        }

        if (AvmCore::isNullOrUndefined(objAtom))
        {
            toplevel()->throwTypeError(
                           (objAtom == undefinedAtom) ? kConvertUndefinedToObjectError :
                           kConvertNullToObjectError);
        }

        switch (atomKind(objAtom))
        {
        case kObjectType:
            return AvmCore::atomToScriptObject(objAtom)->nextName(index);
        case kNamespaceType:
            return AvmCore::atomToNamespace(objAtom)->nextName(this->core(), index);
        default:
            ScriptObject* proto = toplevel()->toPrototype(objAtom);  // cn: types like Number are sealed, but their prototype could have dynamic properties
            return proto ? proto->nextName(index) : undefinedAtom;
        }
    }

    Atom MethodEnv::nextvalue(Atom objAtom, int index) const
    {
        //  Handle special case inputs;
        //  bad index returns undefined,
        //  null object throws error.
        if (index <= 0)
        {
            return undefinedAtom;
        }

        if (AvmCore::isNullOrUndefined(objAtom))
        {
            toplevel()->throwTypeError(
                           (objAtom == undefinedAtom) ? kConvertUndefinedToObjectError :
                           kConvertNullToObjectError);
        }

        switch (atomKind(objAtom))
        {
        case kObjectType:
            return AvmCore::atomToScriptObject(objAtom)->nextValue(index);
        case kNamespaceType:
            return AvmCore::atomToNamespace(objAtom)->nextValue(index);
        default:
            ScriptObject*  proto = toplevel()->toPrototype(objAtom);
            return (proto ? proto->nextValue(index) : undefinedAtom);
        }
    }

    int MethodEnv::hasnext(Atom objAtom, int index) const
    {
        if (index < 0)
            return 0;

        if (!AvmCore::isNullOrUndefined(objAtom))
        {
            switch (atomKind(objAtom))
            {
            case kObjectType:
                return AvmCore::atomToScriptObject(objAtom)->nextNameIndex(index);
            case kNamespaceType:
                return AvmCore::atomToNamespace(objAtom)->nextNameIndex(index);
            default:
                ScriptObject* proto = toplevel()->toPrototype(objAtom);
                int nextIndex = ( proto ? proto->nextNameIndex(index) : 0);
                return nextIndex;
            }
        }
        else
        {
            return 0;
        }
    }

    int MethodEnv::hasnextproto(Atom& objAtom, int& index) const
    {
        if (index < 0)
            return 0;

        ScriptObject *delegate = NULL;

        if (!AvmCore::isNullOrUndefined(objAtom))
        {
            switch (atomKind(objAtom))
            {
            case kObjectType:
                {
                    ScriptObject *object = AvmCore::atomToScriptObject(objAtom);
                    delegate = object->getDelegate();
                    index = object->nextNameIndex(index);
                }
                break;
            case kNamespaceType:
                {
                    index = AvmCore::atomToNamespace(objAtom)->nextNameIndex(index);
                    delegate = toplevel()->namespaceClass->prototypePtr();
                }
                break;
            default:
                {
                    ScriptObject* proto = toplevel()->toPrototype(objAtom);
                    delegate = proto ? proto->getDelegate() : NULL;
                    index = ( proto ? proto->nextNameIndex(index) : 0);
                }
            }
        }
        else
        {
            index = 0;
        }

        while (index == 0 && delegate != NULL)
        {
            // Advance to next object on prototype chain
            ScriptObject *object = delegate;
            objAtom = object->atom();
            delegate = object->getDelegate();
            index = object->nextNameIndex(index);
        }

        if (index == 0)
        {
            // If we're done, set object local to null
            objAtom = nullObjectAtom;
        }

        return index != 0;
    }

    // see 13.2 creating function objects
    ClassClosure* MethodEnv::newfunction(MethodInfo *function,
                                     ScopeChain* outer,
                                     Atom* scopes) const
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();
        MMgc::GC* gc = core->GetGC();

        FunctionClass* functionClass = toplevel->functionClass;
        VTable* fvtable = functionClass->ivtable();
        AvmAssert(fvtable->ivtable == NULL || fvtable->ivtable == toplevel->object_ivtable);
        fvtable->ivtable = toplevel->object_ivtable;
        AvmAssert(fvtable->linked);

        const ScopeTypeChain* fstc = function->declaringScope();
        // functions should never have 'extra' scopes
        AvmAssert(fstc->size == fstc->fullsize);

        ScopeChain* fscope = ScopeChain::create(gc, fvtable, this->abcEnv(), fstc, outer, core->dxns());
        for (int i=outer->getSize(), n=fscope->getSize(); i < n; i++)
        {
            fscope->setScope(gc, i, *scopes++);
        }

        FunctionEnv* fenv = FunctionEnv::create(gc, function, fscope);
        FunctionObject* c = FunctionObject::create(gc, fvtable, fenv);
        c->setDelegate(functionClass->prototypePtr());

        c->createVanillaPrototype();
        c->prototypePtr()->setStringProperty(core->kconstructor, c->atom());
        c->prototypePtr()->setStringPropertyIsEnumerable(core->kconstructor, false);

        fenv->closure = c;

        return c;
    }

    /**
     * given a classInfo, create a new ClassClosure object and return it on the stack.
     */

    ClassClosure* MethodEnv::newclass(Traits* ctraits,
                            ClassClosure *base,
                            ScopeChain* outer,
                            Atom* scopes) const
    {
        AvmCore* core = this->core();
        MMgc::GC* gc = core->GetGC();
        // adds clarity to what is usually just global$init()
        SAMPLE_FRAME("[newclass]", core);
        Toplevel* toplevel = this->toplevel();
        AbcEnv* abcEnv = this->abcEnv();

        Traits* itraits = ctraits->itraits;
        const BuiltinType bt = Traits::getBuiltinType(itraits);

        // finish resolving the base class
        if (!base && itraits->base)
        {
            // class has a base but no base object was provided
            ErrorClass* error = toplevel->typeErrorClass();
            if (error)
                error->throwError(kConvertNullToObjectError);
            else
                toplevel->throwTypeError(kCorruptABCError);
        }

        // have to use local variables for CodeWarrior
        Traits* baseIvtableTraits = base ? base->ivtable()->traits : 0;
        Traits* itraitsBase = itraits->base;
        // make sure the traits of the base vtable matches the base traits
        if (!((base == NULL && itraits->base == NULL) || (base != NULL && itraitsBase == baseIvtableTraits)))
        {
            ErrorClass* error = toplevel->verifyErrorClass();
            if (error)
                error->throwError(kInvalidBaseClassError);
            else
                toplevel->throwTypeError(kCorruptABCError);
        }

        VTable* ivtable = core->newVTable(itraits, base ? base->ivtable() : NULL, toplevel);

        // This is a little weird, as the cvtable should have the ivtable as its base
        // i.e. Class$ derives from Class
        VTable* cvbase = (bt == BUILTIN_class) ? ivtable : toplevel->class_ivtable;
        VTable* cvtable = core->newVTable(ctraits, cvbase, toplevel);

        // class scopechain = [..., class]
        AvmAssert(ctraits->init != NULL);
        ScopeChain* cscope = ScopeChain::create(gc, cvtable, abcEnv, ctraits->init->declaringScope(), outer, core->dxns());
        int i = outer->getSize();
        for (int n=cscope->getSize(); i < n; i++)
        {
            cscope->setScope(gc, i, *scopes++);
        }

        // Note: iff itraits == class_itraits, we used to use cscope (rather than iscope) for ivtable,
        // but that appears to be simply wrong: it doesn't match the expectations of the ScopeTypeChain filled in for Class.
        AvmAssert(itraits->init != NULL);
        ScopeChain* iscope = ScopeChain::create(gc, ivtable, abcEnv, itraits->init->declaringScope(), cscope, core->dxns());
        ivtable->resolveSignatures(iscope);
            // Don't resolve signatures for Object$ until after Class has been set up
            // which should happen very soon after Object is setup.
        if (bt != BUILTIN_object)
            cvtable->resolveSignatures(cscope);

        cvtable->ivtable = ivtable;

        switch (itraits->builtinType)
        {
            case BUILTIN_object:
            {
                // we just defined Object
                toplevel->object_ivtable = ivtable;

                AvmAssert(toplevel->object_cscope == NULL);
                // save for later
                toplevel->object_cscope = cscope;

                // We can finish setting up the toplevel object now that
                // we have the real Object vtable
                VTable* toplevel_vtable = toplevel->global()->vtable;
                toplevel_vtable->base = ivtable;
                toplevel_vtable->linked = false;
                toplevel_vtable->resolveSignatures(toplevel->toplevel_scope());
                break;
            }
            case BUILTIN_class:
            {
                // we just defined Class
                toplevel->class_ivtable = ivtable;

                // Can't run the Object$ initializer until after Class is done since
                // Object$ needs the real Class vtable as its base
                VTable* objectclass_cvtable = toplevel->objectClass->vtable;
                objectclass_cvtable->base = ivtable;
                objectclass_cvtable->resolveSignatures(toplevel->object_cscope);
                objectclass_cvtable->init->coerceEnter(toplevel->objectClass->atom());
                break;
            }
            case BUILTIN_vectorobj:
            {
                AvmAssert(toplevel->vectorobj_cscope == NULL);
                AvmAssert(toplevel->vectorobj_iscope == NULL);
                // save for later
                toplevel->vectorobj_cscope = cscope;
                toplevel->vectorobj_iscope = iscope;
                break;
            }
        }

        CreateClassClosureProc createClassClosure = cvtable->traits->getCreateClassClosureProc();
        AvmAssert(createClassClosure != NULL);
        ClassClosure* cc = (*createClassClosure)(cvtable);

        if (cc->prototypePtr())
        {
            // C.prototype.__proto__ = Base.prototype
            if (base != NULL)
                cc->prototypePtr()->setDelegate( base->prototypePtr() );

            // C.prototype.constructor = C {DontEnum}
            cc->prototypePtr()->setStringProperty(core->kconstructor, cc->atom());
            cc->prototypePtr()->setStringPropertyIsEnumerable(core->kconstructor, false);
        }

        if (bt != BUILTIN_class)
        {
            AvmAssert(i == iscope->getSize()-1);
            iscope->setScope(gc, i, cc->atom());
        }

        if (toplevel->classClass)
        {
            cc->setDelegate( toplevel->classClass->prototypePtr() );
        }

        // Invoke the class init function.
        // Don't run it for Object - that has to wait until after Class$ is set up
        if (cvtable != toplevel->objectClass->vtable)
            cvtable->init->coerceEnter(cc->atom());

        return cc;
    }

    void MethodEnv::initproperty(Atom obj, const Multiname* multiname, Atom value, VTable* vtable) const
    {
        Toplevel* toplevel = this->toplevel();

        Traitsp declarer = NULL;
        Binding b = toplevel->getBindingAndDeclarer(vtable->traits, *multiname, declarer);

        if (AvmCore::bindingKind(b) == BKIND_CONST)
        {
            if (this->method != declarer->init.value())
                toplevel->throwReferenceError(kConstWriteError, multiname, vtable->traits);

            b = AvmCore::makeSlotBinding(AvmCore::bindingToSlotId(b), BKIND_VAR);
        }
        toplevel->setproperty_b(obj, multiname, value, vtable, b);
    }

    void MethodEnv::setpropertylate_i(Atom obj, int32_t index, Atom value) const
    {
        if (AvmCore::isObject(obj))
        {
            ScriptObject* o = AvmCore::atomToScriptObject(obj);
            if (index >= 0)
            {
                o->setUintProperty(index, value);
            }
            else
            {
                // negative index - we must intern the integer
                o->setAtomProperty(this->core()->internInt(index)->atom(), value);
            }
        }
        else
        {
            // obj represents a primitive Number, Boolean, int, or String, and primitives
            // are sealed and final.  Cannot add dynamic vars to them.

            // throw a ReferenceError exception  Property not found and could not be created.
            Multiname tempname(core()->getPublicNamespace(method->pool()), core()->internInt(index));
            toplevel()->throwReferenceError(kWriteSealedError, &tempname, toplevel()->toTraits(obj));
        }
    }

    void MethodEnv::setpropertylate_u(Atom obj, uint32_t index, Atom value) const
    {
        if (AvmCore::isObject(obj))
        {
            AvmCore::atomToScriptObject(obj)->setUintProperty(index, value);
        }
        else
        {
            // obj represents a primitive Number, Boolean, int, or String, and primitives
            // are sealed and final.  Cannot add dynamic vars to them.

            // throw a ReferenceError exception  Property not found and could not be created.
            Multiname tempname(core()->getPublicNamespace(method->pool()), core()->internUint32(index));
            toplevel()->throwReferenceError(kWriteSealedError, &tempname, toplevel()->toTraits(obj));
        }
    }

    Atom MethodEnv::callsuper(const Multiname* multiname, int argc, Atom* atomv) const
    {
        VTable* base = this->vtable()->base;
        Toplevel* toplevel = this->toplevel();
        Binding b = toplevel->getBinding(base->traits, multiname);
        switch (AvmCore::bindingKind(b))
        {
        default:
            toplevel->throwReferenceError(kCallNotFoundError, multiname, base->traits);

        case BKIND_METHOD:
        {
            MethodEnv* superenv = base->methods[AvmCore::bindingToMethodId(b)];
            return superenv->coerceEnter(argc, atomv);
        }
        case BKIND_VAR:
        case BKIND_CONST:
        {
            uint32_t slot = AvmCore::bindingToSlotId(b);
            ScriptObject* method = AvmCore::atomToScriptObject(atomv[0])->getSlotObject(slot);
            // inlined equivalent of op_call
            if (!method)
                toplevel->throwTypeErrorWithName(kCallOfNonFunctionError, "value");
            return method->call(argc, atomv);
        }
        case BKIND_SET:
        {
            // read on write-only property
            toplevel->throwReferenceError(kWriteOnlyError, multiname, base->traits);
        }
        case BKIND_GET:
        case BKIND_GETSET:
        {
            // Invoke the getter
            int m = AvmCore::bindingToGetterId(b);
            MethodEnv *f = base->methods[m];
            Atom method = f->coerceEnter(atomv[0]);
            return toplevel->op_call(method, argc, atomv);
        }
        }
    }

    Atom MethodEnv::delproperty(Atom obj, const Multiname* multiname) const
    {
        Toplevel* toplevel = this->toplevel();
        Traits* traits = toplevel->toTraits(obj); // includes null check
        if (AvmCore::isObject(obj))
        {
            Binding b = toplevel->getBinding(traits, multiname);
            if (b == BIND_NONE)
            {
                bool b = AvmCore::atomToScriptObject(obj)->deleteMultinameProperty(multiname);
#ifdef VMCFG_LOOKUP_CACHE
                // Deleting a deletable bound property means deleting a dynamic global property, so
                // invalidate the lookup cache (because subsequent lookups should fail).
                if (b)
                    core()->invalidateLookupCache();
#endif
                return b ? trueAtom : falseAtom;
            }
            else if (AvmCore::isMethodBinding(b))
            {
                if (AvmCore::isXMLorXMLList(obj) && multiname->containsAnyPublicNamespace())
                {
                    // dynamic props should hide declared methods on delete
                    ScriptObject* so = AvmCore::atomToScriptObject(obj);
                    bool b = so->deleteMultinameProperty(multiname);
                    return b ? trueAtom : falseAtom;
                }
            }
        }
        else
        {
            toplevel->throwReferenceError(kDeleteSealedError, multiname, traits);
        }

        return falseAtom;
    }

    Atom MethodEnv::getsuper(Atom obj, const Multiname* multiname) const
    {
        VTable* vtable = this->vtable()->base;
        Toplevel* toplevel = this->toplevel();
        Binding b = toplevel->getBinding(vtable->traits, multiname);
        switch (AvmCore::bindingKind(b))
        {
        default:
            toplevel->throwReferenceError(kReadSealedError, multiname, vtable->traits);

        case BKIND_METHOD:
        {
            // extracting a virtual method
            MethodEnv *m = vtable->methods[AvmCore::bindingToMethodId(b)];
            return toplevel->methodClosureClass->create(m, obj)->atom();
        }

        case BKIND_VAR:
        case BKIND_CONST:
            return AvmCore::atomToScriptObject(obj)->getSlotAtom(AvmCore::bindingToSlotId(b));

        case BKIND_SET:
        {
            // read on write-only property
            toplevel->throwReferenceError(kWriteOnlyError, multiname, vtable->traits);
        }
        case BKIND_GET:
        case BKIND_GETSET:
        {
            // Invoke the getter
            int m = AvmCore::bindingToGetterId(b);
            MethodEnv *f = vtable->methods[m];
            return f->coerceEnter(obj);
        }
        }
    }


    void MethodEnv::setsuper(Atom obj, const Multiname* multiname, Atom value) const
    {
        VTable* vtable = this->vtable()->base;
        Toplevel* toplevel = this->toplevel();
        Binding b = toplevel->getBinding(vtable->traits, multiname);
        switch (AvmCore::bindingKind(b))
        {
        default:
            toplevel->throwReferenceError(kWriteSealedError, multiname, vtable->traits);

        case BKIND_CONST:
            toplevel->throwReferenceError(kConstWriteError, multiname, vtable->traits);

        case BKIND_METHOD:
            toplevel->throwReferenceError(kCannotAssignToMethodError, multiname, vtable->traits);

        case BKIND_GET:
            toplevel->throwReferenceError(kConstWriteError, multiname, vtable->traits);

        case BKIND_VAR:
            // @todo, this does a redundant coercion -- no harm done, just slightly more work than necessary
            AvmCore::atomToScriptObject(obj)->coerceAndSetSlotAtom(AvmCore::bindingToSlotId(b), value);
            return;

        case BKIND_SET:
        case BKIND_GETSET:
        {
            // Invoke the setter
            uint32_t m = AvmCore::bindingToSetterId(b);
            AvmAssert(m < vtable->traits->getTraitsBindings()->methodCount);
            MethodEnv* method = vtable->methods[m];
            Atom atomv_out[2] = { obj, value };
            // coerce value to proper type, then call enter
            method->coerceEnter(1, atomv_out);
            return;
        }
        }
    }

    Atom MethodEnv::findWithProperty(Atom atom, const Multiname* multiname)
    {
        Toplevel* toplevel = this->toplevel();
        if (atomKind(atom)==kObjectType)
        {
            // usually scope objects are ScriptObject's

            ScriptObject* o = AvmCore::atomToScriptObject(atom);

            // search the delegate chain for a value.  we must look at
            // traits at each step along the way in case we have class
            // instances on the scope chain
            do
            {
                // ISSUE it is incorrect to return a reference to an object on the prototype
                // chain, we should only return the scopechain object; the next operation
                // could be a setproperty, and we don't want to mutate prototype objects this way.

                // look at the traits first, stop if found.
                Binding b = toplevel->getBinding(o->traits(), multiname);
                if (b != BIND_NONE)
                    return atom;
                if (o->hasMultinameProperty(multiname))
                    return atom;
            }
            while ((o = o->getDelegate()) != NULL);
        }
        else
        {
            // primitive value on scope chain!

            // first iteration looks at traits only since primitive values don't have
            // dynamic variables

            Binding b = toplevel->getBinding(toplevel->toTraits(atom), multiname);
            if (b != BIND_NONE)
                return atom;

            // then we continue starting at the prototype for this primitive type
            ScriptObject* o = toplevel->toPrototype(atom);
            do
            {
                Binding b = toplevel->getBinding(o->traits(), multiname);
                if (b != BIND_NONE)
                    return atom;
                if (o->hasMultinameProperty(multiname))
                    return atom;
            }
            while ((o = o->getDelegate()) != NULL);
        }

        return nullObjectAtom;
    }

    /**
     * return the object on the scope chain that owns the given property.
     * if no object has that property, return scope[0].  we search each
     * delegate chain but only return objects that are on the scope chain.
     * this way, find+get and find+set are both correct.  find+set should
     * not mutate a prototype object.
     */
    Atom MethodEnv::findproperty(ScopeChain* outer,
                                 Atom* scopes,
                                 int extraScopes,
                                 const Multiname* multiname,
                                 bool strict,
                                 Atom* withBase)
    {
        Toplevel* toplevel = this->toplevel();

        // look in each with frame in the current stack frame
        Atom* scopep = &scopes[extraScopes-1];
        if (withBase)
        {
            for (; scopep >= withBase; scopep--)
            {
                Atom result = findWithProperty(*scopep, multiname);
                if (!AvmCore::isNull(result))
                {
                    return result;
                }
            }
        }

        // if we're in global$init (outer_depth==0), don't check "this" scope just yet.
        int outer_depth = outer->getSize();
        for (; scopep > scopes; scopep--)
        {
            Atom a = *scopep;
            Traits* t = toplevel->toTraits(a);
            Binding b = toplevel->getBinding(t, multiname);
            if (b != BIND_NONE)
                return a;
        }

        const ScopeTypeChain* outerTraits = outer->scopeTraits();

        if (outer_depth > 0 && scopep >= scopes)
        {
            // consider "this" scope now, but constrain it to the declaringTraits of
            // the current method (verifier ensures this is safe)
            Atom a = *scopep;
            Traits *t;
            if (outerTraits->fullsize > outerTraits->size)
            {
                // scope traits has extra constraint for "this" scope, see OP_newclass in verifier
                t = outerTraits->getScopeTraitsAt(outerTraits->size);
            }
            else
            {
                // "this" scope type is the runtime type
                t = toplevel->toTraits(a);
            }

            Binding b = toplevel->getBinding(t, multiname);
            if (b != BIND_NONE)
                return a;
        }

        // now search outer scopes
        for (int i=outer_depth-1; i > 0; i--)
        {
            if (outerTraits->getScopeIsWithAt(i))
            {
                Atom result = findWithProperty(outer->getScope(i), multiname);
                if (!AvmCore::isNull(result))
                    return result;
            }
            else
            {
                // only look at the properties on the captured (verify time) type, not the actual type,
                // of the outer scope object.
                Atom a = outer->getScope(i);
                Traits* t = outerTraits->getScopeTraitsAt(i);
                Binding b = toplevel->getBinding(t, multiname);
                if (b != BIND_NONE)
                    return a;
            }
        }

        // No imported definitions or global scope can have attributes.  (Using filter
        // operator with non existent attribute will get here.
        if (multiname->isAttr())
        {
            if (strict)
                toplevel->throwReferenceError(kUndefinedVarError, multiname);
            return undefinedAtom;
        }

        // now we have searched all the scopes, except global
        {
            Atom global = outer->getSize() > 0 ? outer->getScope(0) : *scopes;
            Atom obj = findglobalproperty(global, multiname);
            if (AvmCore::isNullOrUndefined(obj)) {
                if (strict)
                    toplevel->throwReferenceError(kUndefinedVarError, multiname);
                obj = global;
            }
            return obj;
        }

    }

    Atom MethodEnv::findglobalproperty(Atom target_global, const Multiname* multiname)
    {
        // wildcards used here always fail later on, so just check now.
        if (multiname->isAnyName() || multiname->isAnyNamespace())
            return nullObjectAtom;

        Toplevel* toplevel = this->toplevel();

        // look for imported definition (similar logic to OP_finddef).  This will
        // find definitions in this script and in other scripts.
        AbcEnv* abcEnv = this->abcEnv();
        AvmCore* core = abcEnv->core();
        ScriptEnv* script = core->domainMgr()->findScriptEnvInAbcEnvByMultiname(abcEnv, *multiname);
        if (script != (ScriptEnv*)BIND_NONE)
        {
            if (script == (ScriptEnv*)BIND_AMBIGUOUS)
                toplevel->throwReferenceError(kAmbiguousBindingError, multiname);

            ScriptObject* global = script->global;
            if (global == NULL)
            {
                global = script->initGlobal();
                script->coerceEnter(script->global->atom());
            }
            return global->atom();
        }

        // no imported definition found.  look for dynamic props
        // on the global object

        // search the delegate chain for a value.  The delegate
        // chain for the global object will only contain vanilla
        // objects (Object.prototype) so we can skip traits

        ScriptObject* o = AvmCore::isObject(target_global) ?
            AvmCore::atomToScriptObject(target_global) :
            toplevel->toPrototype(target_global);
        do
        {
            if (o->hasMultinameProperty(multiname))
                return target_global;
        }
        while ((o = o->getDelegate()) != NULL);

        return nullObjectAtom;
    }

    Namespace* MethodEnv::internRtns(Atom nsAtom)
    {
        if ((atomKind(nsAtom) != kNamespaceType) || AvmCore::isNull(nsAtom))
            toplevel()->throwTypeError(kIllegalNamespaceError);
        return core()->internNamespace(AvmCore::atomToNamespace(nsAtom));
    }

    ArrayObject* MethodEnv::createArguments(Atom *atomv, int argc)
    {
        Toplevel* toplevel = this->toplevel();
        ArrayObject *arguments = toplevel->arrayClass->newarray(atomv+1,argc);
        ScriptObject *closure;
        if (method->needClosure())
        {
            closure = toplevel->methodClosureClass->create(this, atomv[0]);
        }
        else
        {
            closure = ((FunctionEnv*)this)->closure;
        }
        arguments->setStringProperty(core()->kcallee, closure->atom());
        arguments->setStringPropertyIsEnumerable(core()->kcallee, false);
        return arguments;
    }

    Atom MethodEnv::getdescendants(Atom obj, const Multiname* multiname)
    {
        if (AvmCore::isObject (obj))
        {
            return core()->atomToScriptObject(obj)->getDescendants (multiname);
        }
        else
        {
            // Rhino simply returns undefined for other Atom types
            // SpiderMonkey throws TypeError.  We're doing TypeError.
            toplevel()->throwTypeError(kDescendentsError, core()->toErrorString(toplevel()->toTraits(obj)));
            return undefinedAtom; // not reached
        }
    }

    void MethodEnv::checkfilter(Atom obj)
    {
        if ( !AvmCore::isXMLorXMLList(obj) )
        {
            Toplevel* toplevel = this->toplevel();
            toplevel->throwTypeError(kFilterError, core()->toErrorString(toplevel->toTraits(obj)));
        }
    }

    VTable* MethodEnv::buildActivationVTable()
    {
        const ScopeTypeChain* activationScopeTraits = method->activationScope();

        Toplevel* toplevel = this->toplevel();

        // This can happen when the ABC has MethodInfo data but not MethodBody data
        if (!activationScopeTraits)
        {
            toplevel->throwVerifyError(kCorruptABCError);
        }

        Traits* activationTraits = activationScopeTraits->traits();
        AvmAssert(activationTraits != NULL);

        AvmCore* core = this->core();
        VTable* activation = core->newVTable(activationTraits, NULL, toplevel);
        ScopeChain* activationScope = this->scope()->cloneWithNewVTable(core->GetGC(), activation, this->abcEnv(), activationScopeTraits);
        activation->resolveSignatures(activationScope);
        return activation;
    }

    VTable* MethodEnv::getActivationVTable()
    {
        if (!method->needActivation())
            return NULL;

        VTable* activation;
        const int type = getType();
        if (!activationOrMCTable)
        {
            activation = buildActivationVTable();
            setActivationOrMCTable(activation, kActivation);
        }
        else if (type == kMethodTable)
        {
            activation = buildActivationVTable();
            ActivationMethodTablePair *amtp = new (core()->GetGC()) ActivationMethodTablePair(activation, getMethodClosureTable());
            setActivationOrMCTable(amtp, kActivationMethodTablePair);
        }
        else if (type == kActivationMethodTablePair)
        {
            activation = getPair()->activation;
        }
        else
        {
            activation = (VTable*)(activationOrMCTable&~7);
        }
        AvmAssert(activation != NULL);
        return activation;
    }

    ScriptObject *MethodEnv::newUninitializedActivation()
    {
        VTable *vtable = getActivationVTable();
        AvmCore *core = this->core();
        MMgc::GC *gc = core->GetGC();
        SAMPLE_FRAME("[activation-object]", core);
        ScriptObject* obj = ScriptObject::create(gc, vtable, 0/*delegate*/);
        return obj;
    }

    ScriptObject *MethodEnv::newActivation()
    {
        ScriptObject* obj = newUninitializedActivation();
        MethodEnv *init = obj->vtable->init;
        if (init)
            init->coerceEnter(obj->atom());
        return obj;
    }

    WeakKeyHashtable *MethodEnv::getMethodClosureTable()
    {
        int type = getType();
        if(!activationOrMCTable)
        {
            WeakKeyHashtable *wkh = new (core()->GetGC()) WeakKeyHashtable(core()->GetGC());
            setActivationOrMCTable(wkh, kMethodTable);
            return wkh;
        }
        else if(type == kActivation)
        {
            WeakKeyHashtable *wkh = new (core()->GetGC()) WeakKeyHashtable(core()->GetGC());
            ActivationMethodTablePair *amtp = new (core()->GetGC()) ActivationMethodTablePair(getActivationVTable(), wkh);
            setActivationOrMCTable(amtp, kActivationMethodTablePair);
            return wkh;
        }
        else if(type == kActivationMethodTablePair)
        {
            return getPair()->methodTable;
        }
        return (WeakKeyHashtable*)(activationOrMCTable&~7);
    }

#ifdef VMCFG_LOOKUP_CACHE
    void MethodEnv::cleanLookupCache(ExactStructContainer<LookupCache>* self)
    {
        for ( uint32_t i=0 ; i < self->capacity() ; i++ )
            self->get(i).object = NULL;
    }

    void MethodEnv::createLookupCache()
    {
        AvmAssert(lookup_cache == NULL);

        lookup_cache = ExactStructContainer<LookupCache>::create(core()->gc, cleanLookupCache, method->lookup_cache_size());
    }
#endif

#ifdef _DEBUG
    void FASTCALL check_unbox(MethodEnv* env, bool u)
    {
        AvmAssert((env->method->unboxThis() != 0) == u);
    }
#endif

#ifdef DEBUGGER
    ArrayObject* MethodEnv::getLexicalScopes()
    {
        if(_scope->getSize() == 0)
            return NULL;

        ArrayObject *scopes = toplevel()->arrayClass->newArray(_scope->getSize());

        for(int i=_scope->getSize()-1, j=0; i >= 0; i--, j++) {
            Atom scope = _scope->getScope(i);
            scopes->setUintProperty(j, scope);
        }

        return scopes;
    }
#endif
}
