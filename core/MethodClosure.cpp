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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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
#include "BuiltinNatives.h"

using namespace MMgc;

namespace avmplus
{

    // overrides ClassClosure::construct()
    Atom MethodClosureClass::construct(int /*argc*/, Atom* /*argv*/)
    {
        // It's illegal to call "new MethodClosure", and only possible from
        // builtin code, so nobody should do it.
        AvmAssert(false);
        return nullObjectAtom;
    }

    // overrides ClassClosure::call()
    Atom MethodClosureClass::call(int argc, Atom* argv)
    {
        return construct(argc,argv);
    }

    MethodClosureClass::MethodClosureClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        Toplevel* toplevel = this->toplevel();

        AvmAssert(traits()->getSizeOfInstance() == sizeof(MethodClosureClass));

        setPrototypePtr(toplevel->functionClass()->createEmptyFunction());
    }

    // Function called as constructor ... not supported from user code
    // this = argv[0] (ignored)
    // arg1 = argv[1]
    // argN = argv[argc]
    MethodClosure* MethodClosureClass::create(MethodEnv* m, Atom obj)
    {
        WeakKeyHashtable* mcTable = m->getMethodClosureTable();
        Atom mcWeakAtom = mcTable->get(obj);
        GCWeakRef* ref = (GCWeakRef*)AvmCore::atomToGenericObject(mcWeakAtom);
        union {
            GCObject* mc_o;
            MethodClosure* mc;
        };

        if (!ref || ref->isNull())
        {
            mc = MethodClosure::create(gc(), this->ivtable(), m, obj);
            // since MC inherits from CC, we must explicitly set the prototype and delegate since the
            // ctor will leave those null (and without delegate set, apply() and friends won't be found
            // in pure ES3 code)
            mc->setPrototypePtr(prototypePtr());
            mc->setDelegate(prototypePtr());
            mcWeakAtom = AvmCore::genericObjectToAtom(mc->GetWeakRef());
            mcTable->add(obj, mcWeakAtom);
        }
        else
        {
            mc_o = ref->get();
        }
        return mc;
    }

    // ---------------------------

    // [ed] why does the E4 semantics MethodClosure have a slot table?
    // [jd] The slot table of a method closure is used to hold the value of the length
    // property for the method. Dont know how important this is, but there you go.
    // [ed] 9/15/04 we're implementing length as a getter instead of a slot.

    /*virtual*/ MethodClosure* MethodClosure::toMethodClosure() const
    {
        return const_cast<MethodClosure*>(this);
    }

#ifdef AVMPLUS_VERBOSE
    PrintWriter& MethodClosure::print(PrintWriter& prw) const
    {
        return prw << "MC{" << asAtom(get_savedThis()) << " " << m_callEnv->method << "}@" << asAtomHex(atom());
    }
#endif

    /*virtual*/ bool MethodClosure::isValid() const
    {
        return true;
    }

#ifdef _DEBUG
    /*virtual*/ bool MethodClosure::isWeak() const
    {
        return false;
    }
#endif

    /*virtual*/ Atom MethodClosure::get_savedThis() const
    {
        return m_savedThis;
    }

    /*virtual*/ Atom MethodClosure::get_savedThisOrNull() const
    {
        return m_savedThis;
    }
    
    /*virtual*/ MethodClosure* MethodClosure::weaken() const
    {
        // no need to weaken if savedThis isn't an Object.
        if (!AvmCore::isObject(m_savedThis))
            return const_cast<MethodClosure*>(this);
        return WeakMethodClosure::create(gc(), this->vtable, m_callEnv, m_savedThis);
    }
    
    bool MethodClosure::equals(const MethodClosure* that) const
    {
        // Don't assert: the pre-existing code in Flash didn't do so.
        // Instead, allow two "invalid" MC's to equal each other.
        // AvmAssert(this->isValid());
        // AvmAssert(that != NULL && that->isValid());
        return that != NULL &&
                this->m_callEnv == that->m_callEnv &&
                this->get_savedThisOrNull() == that->get_savedThisOrNull();
    }

    uintptr_t MethodClosure::hashKey() const
    {
        // Don't assert: just use the null result to form the hashKey.
        // AvmAssert(isValid());
        return ((uintptr_t(m_callEnv.value()) << 8) | (uintptr_t(get_savedThisOrNull()) >> 3));
    }

    // this = argv[0] (ignored)
    // arg1 = argv[1]
    // argN = argv[argc]
    Atom MethodClosure::construct(int /*argc*/, Atom* /*argv*/)
    {
        // can't invoke method closure as constructor:
        //     m = o.m;
        //     new m(); // error
        toplevel()->throwTypeError(kCannotCallMethodAsConstructor, core()->toErrorString(m_callEnv->method));
        return undefinedAtom;
    }

    /*virtual*/ Atom MethodClosure::get_coerced_receiver(Atom /*a*/) const
    {
        return m_savedThis;
    }

    // ---------------------------


    /*virtual*/ bool WeakMethodClosure::isValid() const
    {
        return !m_weakSavedThis->isNull();
    }

#ifdef _DEBUG
    /*virtual*/ bool WeakMethodClosure::isWeak() const
    {
        return true;
    }
#endif

    /*virtual*/ MethodClosure* WeakMethodClosure::weaken() const
    {
        return const_cast<WeakMethodClosure*>(this); // My, that was easy.
    }

    REALLY_INLINE Atom WeakMethodClosure::_get_savedThis() const
    {
        ScriptObject* const savedThis = (ScriptObject*)(m_weakSavedThis->get());
        // You shouldn't call this unless you know it's valid.
        AvmAssert(savedThis != NULL);
        return savedThis->atom();
    }

    /*virtual*/ Atom WeakMethodClosure::get_savedThis() const
    {
        return _get_savedThis();
    }

    /*virtual*/ Atom WeakMethodClosure::get_savedThisOrNull() const
    {
        ScriptObject* const savedThis = (ScriptObject*)(m_weakSavedThis->get());
        // Don't assert, just return nullObjectAtom.
        return savedThis ? savedThis->atom() : nullObjectAtom;
    }

    /*virtual*/ Atom WeakMethodClosure::get_coerced_receiver(Atom /*a*/) const
    {
        return _get_savedThis();
    }

}
