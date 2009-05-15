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

namespace avmplus
{
#undef DEBUG_EARLY_BINDING

	Toplevel::Toplevel(AbcEnv* abcEnv) : 
		_abcEnv(abcEnv),
		_builtinClasses(NULL),
		_global(NULL)
	{
		_builtinClasses = (ClassClosure**) core()->GetGC()->Alloc(sizeof(ClassClosure*) * core()->builtinPool->classCount(), MMgc::GC::kZero | MMgc::GC::kContainsPointers);

		AvmCore* core = this->core();
		MMgc::GC* gc = core->GetGC();
		PoolObject* pool = abcEnv->pool();
		Traits* mainTraits = pool->getScriptTraits(pool->scriptCount()-1);

			// create a temp object vtable to use, since the real one isn't created yet
			// later, in OP_newclass, we'll replace with the real Object vtable, so methods
			// of Object and Class have the right scope.
		object_ivtable = core->newVTable(core->traits.object_itraits, NULL, NULL);
		ScopeChain* object_iscope = ScopeChain::create(gc, object_ivtable, abcEnv, core->traits.object_istc, NULL, core->newNamespace(core->kEmptyString));
		object_ivtable->resolveSignatures(object_iscope);

		// global objects are subclasses of Object
		bool wasResolved = mainTraits->isResolved();
		VTable* mainVTable = core->newVTable(mainTraits, object_ivtable, this);
		AvmAssert(mainTraits->isResolved());
		if (!wasResolved)
			mainTraits->init_declaringScopes(ScopeTypeChain::createEmpty(core->GetGC(), mainTraits));
		ScriptEnv* main = new (gc) ScriptEnv(mainTraits->init, mainVTable, abcEnv);
		mainVTable->init = main;
		toplevel_scope = ScopeChain::create(gc, mainVTable, abcEnv, mainTraits->init->declaringScope(), NULL, core->newNamespace(core->kEmptyString));
		mainVTable->resolveSignatures(toplevel_scope);

		_global = new (gc, mainVTable->getExtraSize()) ScriptObject(mainVTable, NULL);
		main->global = _global;

		// create temporary vtable for Class, so we have something for OP_newclass
		// to use when it creates Object$ and Class$.  once that happens, we replace
		// with the real Class$ vtable.
		class_ivtable = core->newVTable(core->traits.class_itraits, object_ivtable, this);
		ScopeChain* class_iscope = ScopeChain::create(gc, class_ivtable, abcEnv, core->traits.class_istc, NULL, core->newNamespace(core->kEmptyString));
		class_ivtable->resolveSignatures(class_iscope);

		core->exportDefs(mainTraits, main);
	}

	ScriptEnv* Toplevel::mainEntryPoint() const
	{
		MethodEnv* me = this->global()->vtable->init;
		AvmAssert(me->isScriptEnv());
		return (ScriptEnv*)(me);
	}

	ClassClosure* Toplevel::findClassInPool(int class_id, PoolObject* pool)
	{
		Traits* traits = pool->getClassTraits(class_id)->itraits;
		Multiname qname(traits->ns(), traits->name());
		AvmAssert(_global != NULL);
		ScriptObject* container = _global->vtable->init->finddef(&qname);

		Atom classAtom = getproperty(container->atom(), &qname, container->vtable);
		ClassClosure* cc = (ClassClosure*)AvmCore::atomToScriptObject(classAtom);
		return cc;
	}

	ClassClosure* Toplevel::resolveBuiltinClass(int class_id)
	{
		ClassClosure* cc = findClassInPool(class_id, core()->builtinPool);
		//builtinClasses[class_id] = cc;
		WBRC(core()->GetGC(), _builtinClasses, &_builtinClasses[class_id], cc);
		return cc;
	}

	ScriptObject* Toplevel::toPrototype(Atom atom)
	{
		if (!AvmCore::isNullOrUndefined(atom))
		{
			switch (atom&7)
			{
			default:
			
			case kNamespaceType:
				return namespaceClass->prototype;

			case kStringType:
				return stringClass->prototype;

			case kObjectType:
				return AvmCore::atomToScriptObject(atom)->getDelegate();

			case kDoubleType:
			case kIntegerType:
				// ISSUE what about int?
				return numberClass->prototype;

			case kBooleanType:
				return booleanClass->prototype;
			}
		}
		else
		{
			// TypeError in ECMA
			throwTypeError(
				(atom == undefinedAtom) ? kConvertUndefinedToObjectError :
											kConvertNullToObjectError);
			return NULL;
		}
	}

	// equivalent to ToObject, obj->traits.  exception if null or undefined.
	VTable* Toplevel::toVTable(Atom atom)
	{
		if (!AvmCore::isNullOrUndefined(atom))
		{
			switch (atom&7)
			{
			case kObjectType:
				return AvmCore::atomToScriptObject(atom)->vtable;
			case kNamespaceType:
				return namespaceClass->ivtable();
			case kStringType:
				return stringClass->ivtable();
			case kBooleanType:
				return booleanClass->ivtable();
			case kIntegerType:
			case kDoubleType:
				// ISSUE what about int?
				return numberClass->ivtable();
			}
		}
		else
		{
            // TypeError in ECMA
			throwTypeError(
					(atom == undefinedAtom) ? kConvertUndefinedToObjectError :
										kConvertNullToObjectError);
		}
		return NULL;
	}
	
	// equivalent to ToObject, obj->traits.  exception if null or undefined.
	Traits* Toplevel::toTraits(Atom atom)
	{
		if (!AvmCore::isNullOrUndefined(atom))
		{
			switch (atom&7)
			{
			case kObjectType:
				return AvmCore::atomToScriptObject(atom)->traits();
			case kNamespaceType:
				return core()->traits.namespace_itraits;
			case kStringType:
				return core()->traits.string_itraits;
			case kBooleanType:
				return core()->traits.boolean_itraits;
			case kIntegerType:
			case kDoubleType:
				// ISSUE what about int?
				return core()->traits.number_itraits;
			}
		}
		else
		{
            // TypeError in ECMA
			ErrorClass *error = typeErrorClass();
			if( error )
				error->throwError(
					(atom == undefinedAtom) ? kConvertUndefinedToObjectError :
										kConvertNullToObjectError);
			else
				throwVerifyError(kCorruptABCError);
		}
		return NULL;
	}
	
    /**
     * OP_call.
     *
     * arg0 = argv[0]
     * arg1 = argv[1]
     * argN = argv[argc]
     */
    Atom Toplevel::op_call(Atom method, int argc, Atom* atomv)
    {
		// The construction of the multiname and the resulting error string is
		// delegated because in-lining it here prevents the call to call() from
		// being a tail call - the address of a local multiname is taken, this
		// makes GCC (arguably incorrectly, given the scope of the variable)
		// turn off tail calling.
		
		if (!AvmCore::isObject(method))
			throwTypeErrorWithName(kCallOfNonFunctionError, "value");
		
		return AvmCore::atomToScriptObject(method)->call(argc, atomv);
    }

    /**
     * OP_construct.  Note that arguments are in the opposite order from AVM.
     *
	 * this = argv[0] // ignored
     * arg1 = argv[1]
     * argN = argv[argc]
     */
    Atom Toplevel::op_construct(Atom ctor, int argc, Atom* atomv)
    {
		if (!AvmCore::isObject(ctor))
		{
			throwTypeError(kConstructOfNonFunctionError);
		}

		ScriptObject *ct = AvmCore::atomToScriptObject(ctor);
		Atom val = ct->construct(argc, atomv);
		return val;
	}

	/**
	* OP_applytype.
	*
	* arg1 = argv[0]
	* argN = argv[argc-1]
	*/
	Atom Toplevel::op_applytype(Atom factory, int argc, Atom* atomv)
	{
		if (!AvmCore::isObject(factory))
		{
			throwTypeError(kTypeAppOfNonParamType);
		}
		return AvmCore::atomToScriptObject(factory)->applyTypeArgs(argc, atomv);
	}
	
	// E4X 10.5.1, pg 37
	QNameObject* Toplevel::ToAttributeName(Atom attributeName)
	{
		if (!AvmCore::isNullOrUndefined(attributeName))
		{
			AvmCore* core = this->core();
			switch (attributeName&7)
			{
			case kNamespaceType:
				attributeName = AvmCore::atomToNamespace(attributeName)->getURI()->atom();
				break;
			case kObjectType:
				// check for XML, XMLList, Object, AttributeName, AnyName
				// if XML, toString, then do default string case
				// if XMLList, toString, then do default string case
				// if AttributeName, return the input argument
				// if AnyName, return the result of calling "ToAttributeName(*)"
				// if QName, return attributeName
				// otherwise, do toString, then to default case
				if (AvmCore::isQName(attributeName))
				{
					QNameObject *q = AvmCore::atomToQName(attributeName);
					if (q->isAttr())
						return q;
					else
						return new (core->GetGC(), qnameClass()->ivtable()->getExtraSize()) QNameObject(qnameClass(), attributeName, true);
				}
				else
				{
					attributeName = core->string(attributeName)->atom();
					break;
				}
				break;
			case kStringType:
				{
					break;
				}
			case kBooleanType:
			case kIntegerType:
			case kDoubleType:
			default: // number
				throwTypeError(kConvertUndefinedToObjectError);
			}

			return new (core->GetGC(), qnameClass()->ivtable()->getExtraSize()) QNameObject(qnameClass(), attributeName, true);
		}
		else
		{
			throwTypeError(kConvertUndefinedToObjectError);
			return NULL;
		}
	}

	// E4X 10.6.1, page 38
	// This returns a Multiname create from a unqualified generic type.
	// The multiname returned will have one namespace and will be correctly
	// marked as an attribute if input is an attribute
	void Toplevel::ToXMLName(const Atom p, Multiname& m) 
	{
		Stringp s = NULL;
		AvmCore* core = this->core();

		if (!AvmCore::isNullOrUndefined(p))
		{
			switch (p & 7)
			{
			case kNamespaceType:
				s = AvmCore::atomToNamespace(p)->getURI();
				break;
			case kObjectType:
				{
					// check for XML, XMLList, Object, AttributeName, AnyName
					// if XML, toString, then do default string case
					// if XMLList, toString, then do default string case
					// if AttributeName, return the input argument
					// if AnyName, return the result of calling "ToAttributeName(*)"
					// if QName, return attributeName
					if (AvmCore::isQName(p))
					{
						QNameObject *q = AvmCore::atomToQName(p);

						m.setAttr(q->isAttr() ? true : false);
						m.setNamespace(core->newNamespace(q->get_uri()));
						Stringp name = q->get_localName();
						if (name == core->kAsterisk)
						{
							m.setAnyName(); // marks it as an anyName
						}
						else
						{
							m.setName(name);
						}
						return;
					}
					else // XML, XMLList or generic object - convert to string
					{
						s = core->string(p);
						break;
					}
				}
			case kIntegerType:
			case kDoubleType:
			case kStringType:
			case kBooleanType:
				{
					s = core->string(p);
					break;
				}
			}
		}
		else
		{
			throwTypeError(kConvertUndefinedToObjectError);
			return;
		}

		// At this point p should be a string atom
		AvmAssert (s != 0);

		// if s is integer, throw TypeError
		// if first character of s is "@", return __toAttributeName (string - @)
		// else, return QName (s)
		if (s->charAt(0) == '@')
		{
			// __toAttributeName minus the @
			Stringp news = s->substring(1, s->length());
			m.setName(core->internString(news));
			m.setAttr();
		}
		else
		{
			m.setName(core->internString(s));
		}

		if (m.getName() == core->kAsterisk)
		{
			m.setAnyName(); // marks it as an anyName
		}

		m.setNamespace(core->publicNamespace);
	}

	void Toplevel::CoerceE4XMultiname(const Multiname *m, Multiname &out)
	{
		// This function is used to convert raw string access into correct
		// Multiname types:
		// x["*"]
		// x["@*"]
		// Unqualified anyName types are correct handled in Multiname::matches
		// so we do not edit their namespaces here.  (They should have one
		// namespace which is null according to the E4X spec.)
		//
		// Unqualified regular types have the default XML namespace added to their
		// namespace count here.

		AvmAssert(!m->isRuntime());

		AvmCore *core = this->core();

		if (m->isQName())
		{
			AvmAssert(m->namespaceCount() == 1);
			out.setNamespace(m);
			out.setQName();
		}
		else
		{
			// If we're any namespace, no work required.
			if (m->isAnyNamespace())
			{
				out.setAnyNamespace();
			}
			else
			{
				// search for a match in our nsSet for the defaultNamespace
				Namespace *defaultNs = this->getDefaultNamespace();
				bool bMatch = false;
				for (int i=0, n=m->namespaceCount(); i < n; i++)
				{
					Namespace *ns = m->getNamespace(i);
					if (ns && ns->getPrefix() == defaultNs->getPrefix() && 
						ns->getURI() == defaultNs->getURI() &&
						ns->getType() == defaultNs->getType())
					{
						bMatch = true;
						break;
					}
				}

				// For an unqualified reference, we need to add in the default xml namespace
				// since we did not find a match for it in our namespace set
				if (!bMatch)
				{
					int newNameCount = m->namespaceCount() + 1;
					NamespaceSet *nsset = core->newNamespaceSet(newNameCount);
					for (int i=0, n=m->namespaceCount(); i < n; i++)
					{
						nsset->namespaces[i] = m->getNamespace(i);
					}
					//Stringp s1 = string(getDefaultNamespace()->getPrefix());
					//Stringp s2 = string(getDefaultNamespace()->getURI());
					nsset->namespaces[newNameCount-1] = this->getDefaultNamespace();
					out.setNsset(nsset);
				}
				else
				{	
					if (m->namespaceCount() > 1)
						out.setNsset(m->getNsset());
					else
						out.setNamespace (m->getNamespace());
				}
			}
		}

		out.setAttr(m->isAttr() ? true : false);

		if (m->isAnyName())
		{
			out.setAnyName();
		}
		else
		{
			Stringp s = m->getName();
			if ((s->length() == 1) && (s->charAt(0) == '*'))
			{
				// Mark is as an "anyName" (name == undefined makes isAnyName true)
				out.setAnyName();
			}
			else if ((s->length() >= 1) && (s->charAt(0) == '@'))
			{
				// If we're already marked as an attribute, we don't want to modify 
				// our string in any way.  Degenerative cases where you call:
				// XML.attribute (new QName("@*"))
				if (!out.isAttr())
				{
					// check for "@*"
					if ((s->length() == 2) && (s->charAt(1) == '*'))
						out.setAnyName();
					else
						out.setName(core->internString(s->substring(1, s->length())));
					out.setAttr();
				}
				else
				{
					if (m->isAnyName())
						out.setAnyName();
					else
						out.setName(m->getName());
				}
			}
			else
			{
				if (m->isAnyName())
					out.setAnyName();
				else
					out.setName(m->getName());
			}
		}
	}

	Atom Toplevel::callproperty(Atom base, const Multiname* multiname, int argc, Atom* atomv, VTable* vtable)
	{
		Binding b = getBinding(vtable->traits, multiname);
		switch (AvmCore::bindingKind(b))
		{
		case BKIND_METHOD:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callproperty method " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// force receiver == base.  if caller used OP_callproplex then receiver was null.
			atomv[0] = base;
			MethodEnv* method = vtable->methods[AvmCore::bindingToMethodId(b)];
			AvmAssert(method != NULL);
			return method->coerceEnter(argc, atomv);
		}
		case BKIND_VAR:
		case BKIND_CONST:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callproperty slot " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			Atom method = AvmCore::atomToScriptObject(base)->getSlotAtom(AvmCore::bindingToSlotId(b));
			return op_call(method, argc, atomv);
		}
		case BKIND_GET:
		case BKIND_GETSET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callproperty getter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// Invoke the getter on base
			int m = AvmCore::bindingToGetterId(b);
			MethodEnv *f = vtable->methods[m];
			Atom method = f->coerceEnter(base);
			return op_call(method, argc, atomv);
		}
		case BKIND_SET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callproperty setter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// read on write-only property
			throwReferenceError(kWriteOnlyError, multiname, vtable->traits);
		}
		default:
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callproperty dynamic " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			if (AvmCore::isObject(base))
			{
				return AvmCore::atomToScriptObject(base)->callProperty(multiname, argc, atomv);
			}
			else
			{
				// primitive types are not dynamic, so we can go directly
				// to their __proto__ object
				ScriptObject* proto = toPrototype(base);
				Atom method = proto->getMultinameProperty(multiname);
				return op_call(method, argc, atomv);
			}
		}
	}

	Atom Toplevel::constructprop(const Multiname* multiname, int argc, Atom* atomv, VTable* vtable)
	{
		Binding b = getBinding(vtable->traits, multiname);
		Atom obj = atomv[0];
		AvmCore* core = this->core();
		switch (AvmCore::bindingKind(b))
		{
		case BKIND_METHOD:
		{
			// can't invoke method as constructor
			MethodEnv* env = vtable->methods[AvmCore::bindingToMethodId(b)];
			throwTypeError(kCannotCallMethodAsConstructor, core->toErrorString(env->method));
		}
		case BKIND_VAR:
		case BKIND_CONST:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "constructprop slot " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			Atom ctor = AvmCore::atomToScriptObject(obj)->getSlotAtom(AvmCore::bindingToSlotId(b));
			if (!AvmCore::istype(ctor, CLASS_TYPE) && !AvmCore::istype(ctor, FUNCTION_TYPE))
				throwTypeError(kNotConstructorError, core->toErrorString(multiname));
			return op_construct(ctor, argc, atomv);
		}
		case BKIND_GET:
		case BKIND_GETSET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "constructprop getter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// Invoke the getter
			int m = AvmCore::bindingToGetterId(b);
			MethodEnv *f = vtable->methods[m];
			Atom ctor = f->coerceEnter(obj);
			return op_construct(ctor, argc, atomv);
		}
		case BKIND_SET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "constructprop setter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// read on write-only property
			throwReferenceError(kWriteOnlyError, multiname, vtable->traits);
		}
		default:
			#ifdef DEBUG_EARLY_BINDING
			core->console << "constructprop dynamic " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			if ((obj&7)==kObjectType)
			{
				return AvmCore::atomToScriptObject(obj)->constructProperty(multiname, argc, atomv);
			}
			else
			{
				// primitive types are not dynamic, so we can go directly
				// to their __proto__ object
				ScriptObject* proto = toPrototype(obj);
				Atom ctor = proto->getMultinameProperty(multiname);
				return op_construct(ctor, argc, atomv);
			}
		}
	}	

	Atom Toplevel::instanceof(Atom atom, Atom ctor)
	{
		AvmCore* core = this->core();
		if ((ctor&7) != kObjectType ||
			(!AvmCore::istype(ctor, core->traits.function_itraits) &&
			!AvmCore::istype(ctor, core->traits.class_itraits)))
		{
			throwTypeError(kCantUseInstanceofOnNonObjectError);
		}
		// check for null before tryign to call toPrototype(atom), which will throw an error for null.
		if (AvmCore::isNull(atom))
   			return falseAtom;

		ClassClosure* c = (ClassClosure*)AvmCore::atomToScriptObject(ctor);

		ScriptObject *proto = c->prototype;
		ScriptObject *o = toPrototype(atom);

		for (; o != NULL; o = o->getDelegate())
		{
			if (o == proto)
				return trueAtom;
		}

		return falseAtom;
	}

	
	Traits* Toplevel::toClassITraits(Atom atom)
	{
		switch (atom&7)
		{
		case kObjectType:
		{
			if( !AvmCore::isNull(atom) )
			{
				Traits* itraits = AvmCore::atomToScriptObject(atom)->traits()->itraits;
				if (itraits == NULL)
					throwTypeError(kIsTypeMustBeClassError);
				return itraits;
			}
			// else fall through and report an error
		}
		default:
            // TypeError in ECMA
			// ISSUE the error message should say "whatever" is not a class
			throwTypeError(
					   (atom == undefinedAtom) ? kConvertUndefinedToObjectError :
											kConvertNullToObjectError);
			return NULL;
		}
	}

	Atom Toplevel::in_operator(Atom nameatom, Atom obj) 
	{
		AvmCore* core = this->core();
		Traits* t = this->toTraits(obj); // includes null check

		bool has_interned = false;
		if (!AvmCore::isDictionaryLookup(nameatom, obj))
		{
			Stringp name = core->intern(nameatom);
			has_interned = true;

			// ISSUE should we try this on each object on the proto chain or just the first?
			TraitsBindingsp td = t->getTraitsBindings();
			if (td->findBinding(name, core->publicNamespace) != BIND_NONE)
				return trueAtom;

			nameatom = name->atom();
		}

		ScriptObject* o = (obj&7)==kObjectType ? 
				AvmCore::atomToScriptObject(obj) : 
				this->toPrototype(obj);
		do
		{
			if (o->hasAtomProperty(nameatom))
				return trueAtom;

			// First hasAtomProperty call can be a dictionary and take any 
			// type of object but the rest need an interned string.
			if (!has_interned)
			{
				nameatom=core->intern(nameatom)->atom();
				has_interned = true;
			}
		}
		while ((o = o->getDelegate()) != NULL);
		return falseAtom;
	}

	/**
	 * implements ECMA implicit coersion.  returns the coerced value,
	 * or throws a TypeError if coersion is not possible.
	 */
	 
	 // NOTE: parts of this function have been explicitly inlined into MethodEnv::unbox1 for
	 // efficiency. If you change/fix this method, you may need to change/fix MethodEnv::unbox1 as well.
    Atom Toplevel::coerce(Atom atom, Traits* expected) const
    {
		Traits* actual;
		AvmCore* core = this->core();

		// these types always succeed
		const BuiltinType ebt = Traits::getBuiltinType(expected);
		switch (ebt)
		{
			case BUILTIN_any:
				return atom;
			case BUILTIN_boolean:
				return AvmCore::booleanAtom(atom);
			case BUILTIN_number:
				return core->numberAtom(atom);
			case BUILTIN_string:
				return AvmCore::isNullOrUndefined(atom) ? nullStringAtom : core->string(atom)->atom();
			case BUILTIN_int:
				return core->intAtom(atom);
			case BUILTIN_uint:
				return core->uintAtom(atom);
			case BUILTIN_object:
				return atom == undefinedAtom ? nullObjectAtom : atom;
		}
		// else fall thru

		if (AvmCore::isNullOrUndefined(atom))
			return (ebt == BUILTIN_void) ? undefinedAtom : nullObjectAtom;

		switch (atomKind(atom))
		{
		case kStringType:
			actual = STRING_TYPE;
			break;

		case kBooleanType:
			actual = BOOLEAN_TYPE;
			break;

		case kDoubleType:
			actual = NUMBER_TYPE;
			break;

		case kIntegerType:
			actual = INT_TYPE;
			break;

		case kNamespaceType:
			actual = NAMESPACE_TYPE;
			break;

		case kObjectType:
			actual = AvmCore::atomToScriptObject(atom)->traits();
			break;

		default:
			// unexpected atom type
			AvmAssert(false);
			return false;
		}

		if (actual->containsInterface(expected))
		{
			return atom;
		}
		else
		{
			// failed
#ifdef AVMPLUS_VERBOSE
			//core->console << "checktype failed " << expected << " <- " << atom << "\n";
#endif
			throwTypeError(kCheckTypeFailedError, core->atomToErrorString(atom), core->toErrorString(expected));
			return atom;//unreachable
		}
    }

	void Toplevel::coerceobj(ScriptObject* obj, Traits* expected) const
	{
		if (obj && !obj->traits()->containsInterface(expected))
		{
			// failed
#ifdef DEBUGGER
			//core->console << "checktype failed " << expected << " <- " << atom << "\n";
#endif
			throwTypeError(kCheckTypeFailedError, core()->atomToErrorString(obj->atom()), core()->toErrorString(expected));
		}
	}
	
    Atom Toplevel::add2(Atom lhs, Atom rhs)
    {
		AvmCore* core = this->core();

		// do common cases first/quick:
		if (AvmCore::isNumber(lhs) && AvmCore::isNumber(rhs))
		{
			// C++ porting note. if either side is undefined, null or NaN then result must be NaN.
			// Java's + operator ensures this for double operands.
			// cn:  null should convert to 0, so I think the above comment is wrong for null.
			goto add_numbers;
		}
		else if (AvmCore::isString(lhs) || AvmCore::isString(rhs) || AvmCore::isDate(lhs) || AvmCore::isDate(rhs))
		{
			goto concat_strings;
		}


		// then look for the more unlikely cases
		
		// E4X, section 11.4.1, pg 53
		
		if (AvmCore::isXMLorXMLList(lhs) && AvmCore::isXMLorXMLList(rhs))
		{
			XMLListObject *l = new (core->GetGC()) XMLListObject(xmlListClass());
			l->_append(lhs);
			l->_append(rhs);
			return l->atom();
		}
		
		// to catch oddball cases like:
		//   function foo() { };
		//   foo.prototype.valueOf = function() { return new Object(); }
		//   foo.prototype.toString = function() { return 2; }
		//   print( new foo() + 33 ); // should be 35
		//
		// we need to follow the E3 spec:
		// 1. call ToPrimitive() on lhs and rhs, then
		// if L is String || R is String, concat, else add toNumber(lhs) to toNumber(rhs)

		// ToPrimitive() will call [[DefaultValue]], which calls valueOf().  If the result is
		//  a primitive, return that value else call toString() instead.

		// from E3:
		// NOTE No hint is provided in the calls to ToPrimitive in steps 5 and 6. All native ECMAScript objects except Date objects handle
		// the absence of a hint as if the hint Number were given; Date objects handle the absence of a hint as if the hint String were given.
		// Host objects may handle the absence of a hint in some other manner.
		
		lhs = AvmCore::primitive(lhs); // Date is handled above with the String argument case,  we don't have to check for it here.
		rhs = AvmCore::primitive(rhs);

		if (!(AvmCore::isString(lhs) || AvmCore::isString(rhs)))
		{
			goto add_numbers;
		}
		// else fall thru to concat_strings

concat_strings:
		return core->concatStrings(core->string(lhs), core->string(rhs))->atom();

add_numbers:	
		return core->doubleToAtom(AvmCore::number(lhs) + AvmCore::number(rhs));
    }

	bool Toplevel::hasproperty(Atom obj, const Multiname* multiname, VTable* vtable)
	{
		const Binding propBinding = getBinding(vtable->traits, multiname);
		bool result = false;
		switch (AvmCore::bindingKind(propBinding))
		{
		case BKIND_NONE:
			{
				// Property does not have binding.  Might be a dynamic property.
				// Have to walk the prototype chain.
				const ScriptObject* curObj = AvmCore::isObject(obj) ?
												AvmCore::atomToScriptObject(obj) :
												toPrototype(obj);
				
				if (curObj->isValidDynamicName(multiname))
				{
					// Walk the prototype chain looking for the property.
					while ((!result) && (curObj != NULL))
					{
						result = curObj->hasMultinameProperty(multiname);
						curObj = curObj->getDelegate();
					}
				}
			}
			break;
		case BKIND_METHOD:	// "property" is really a method.
		case BKIND_VAR:		// "property" is a member variable.
		case BKIND_CONST:	// "property" is a member constant.
		case BKIND_GET:     // "property" is implemented with getter
		case BKIND_SET:		// "property" is implemented with setter
		case BKIND_GETSET:	// "property" is implemented with getter and setter
			result = true;
			break;
		default:
			AvmAssert(false);
		}
		return result;
	}

	bool Toplevel::deleteproperty(Atom obj, const Multiname* multiname, VTable* vtable) const
	{
		const Binding propBinding = getBinding(vtable->traits, multiname);
		bool result = false;
		switch (AvmCore::bindingKind(propBinding))
		{
		case BKIND_NONE:
			{
				// Property does not have binding.  See if a dynamic property
				// with the specified name can be set on the object.
				// For it to be legal to set a dynamic property on the
				// object in question, the object must be a regular ( not a primitive )
				// script object, the property name must be a legal dynamic property name,
				// and the object must not be sealed ( must be a dynamic object ).
				if (AvmCore::isObject(obj))
				{
					ScriptObject* o = AvmCore::atomToScriptObject(obj);
					if (o->isValidDynamicName(multiname) && o->traits()->needsHashtable())
					{
						result = o->deleteMultinameProperty(multiname);
					}
				}
			}
			break;

		case BKIND_METHOD:
			{
				if (multiname->contains(core()->publicNamespace) && isXmlBase(obj)) 
				{
					ScriptObject* o = AvmCore::atomToScriptObject(obj);
					// dynamic props should hide declared methods
					result = o->deleteMultinameProperty(multiname);
				}
			}
			break;

		case BKIND_VAR:	
		case BKIND_CONST:	
		case BKIND_GET:
		case BKIND_SET:
		case BKIND_GETSET:
			result = false;
			break;
		default:
			AvmAssert(false);
		}
		return result;
	}

	Atom Toplevel::getproperty(Atom obj, const Multiname* multiname, VTable* vtable)
    {
		Binding b = getBinding(vtable->traits, multiname);
		AvmCore* core = this->core();
        switch (AvmCore::bindingKind(b))
        {
		case BKIND_METHOD: 
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getproperty method " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			if (multiname->contains(core->publicNamespace) && isXmlBase(obj))
			{
				// dynamic props should hide declared methods
				ScriptObject* so = AvmCore::atomToScriptObject(obj);
				return so->getMultinameProperty(multiname);
			}
			// extracting a method
			MethodEnv *m = vtable->methods[AvmCore::bindingToMethodId(b)];
			return methodClosureClass->create(m, obj)->atom();
		}

        case BKIND_VAR:
        case BKIND_CONST:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getproperty slot " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			int slot = AvmCore::bindingToSlotId(b);
			return AvmCore::atomToScriptObject(obj)->getSlotAtom(slot);
		}

		case BKIND_NONE:
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getproperty dynamic " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			if ((obj&7) == kObjectType)
			{
				// try dynamic lookup on instance.  even if the traits are sealed,
				// we might need to search the prototype chain
				return AvmCore::atomToScriptObject(obj)->getMultinameProperty(multiname);
			}
			else
			{
				// primitive types are not dynamic, so we can go directly
				// to their __proto__ object.  but they are sealed, so fail if
				// the property is not found on the proto chain.

				ScriptObject* delegate = toPrototype(obj);
				if (delegate->isValidDynamicName(multiname))
				{
					return delegate->ScriptObject::getStringPropertyFromProtoChain(multiname->getName(), delegate, toTraits(obj));
				}
				else
				{
					throwReferenceError(kReadSealedError, multiname, toTraits(obj));
					return undefinedAtom;
				}
			}

		case BKIND_GET:
		case BKIND_GETSET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getproperty getter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// Invoke the getter
			int m = AvmCore::bindingToGetterId(b);
			MethodEnv *f = vtable->methods[m];
			return f->coerceEnter(obj);
		}
		case BKIND_SET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getproperty setter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// read on write-only property
			throwReferenceError(kWriteOnlyError, multiname, vtable->traits);
		}

		default:
	        // internal error
			AvmAssert(false);
			return undefinedAtom;
        }
    }

    void Toplevel::setproperty(Atom obj, const Multiname* multiname, Atom value, VTable* vtable) const
    {
		Binding b = getBinding(vtable->traits, multiname);
		setproperty_b(obj,multiname,value,vtable,b);
	}

	void Toplevel::setproperty_b(Atom obj, const Multiname* multiname, Atom value, VTable* vtable, Binding b) const
	{
        switch (AvmCore::bindingKind(b))
        {
		case BKIND_METHOD: 
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setproperty method " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			if (multiname->contains(core()->publicNamespace) && isXmlBase(obj))
			{
				// dynamic props should hide declared methods
				ScriptObject* so = AvmCore::atomToScriptObject(obj);
				so->setMultinameProperty(multiname, value);
				return;
			}
			// trying to assign to a method.  error.
			throwReferenceError(kCannotAssignToMethodError, multiname, vtable->traits);
		}

		case BKIND_CONST:
		{
			// OP_setproperty can never set a const.  initproperty must be used
			throwReferenceError(kConstWriteError, multiname, vtable->traits);
			return;
		}
		case BKIND_VAR:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setproperty slot " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			int slot = AvmCore::bindingToSlotId(b);
			const TraitsBindingsp td = vtable->traits->getTraitsBindings();
			AvmCore::atomToScriptObject(obj)->setSlotAtom(slot, coerce(value, td->getSlotTraits(slot)));
            return;
		}

		case BKIND_SET: 
		case BKIND_GETSET: 
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setproperty setter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			// Invoke the setter
			uint32 m = AvmCore::bindingToSetterId(b);
			AvmAssert(m < vtable->traits->getTraitsBindings()->methodCount);
			MethodEnv* method = vtable->methods[m];
			Atom atomv_out[2] = { obj, value };
			method->coerceEnter(1, atomv_out);
			return;
		}
		case BKIND_GET: 
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setproperty getter " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			throwReferenceError(kConstWriteError, multiname, vtable->traits);
			return;
		}

		case BKIND_NONE:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setproperty dynamic " << vtable->traits << " " << multiname->getName() << "\n";
			#endif
			if (AvmCore::isObject(obj))
			{
				AvmCore::atomToScriptObject(obj)->setMultinameProperty(multiname, value);
			}
			else
			{
				// obj represents a primitive Number, Boolean, int, or String, and primitives
				// are sealed and final.  Cannot add dynamic vars to them.

				// property could not be found and created.
				throwReferenceError(kWriteSealedError, multiname, vtable->traits);
			}
			return;
		}

		default:
			// internal error if we get here
			AvmAssert(false);
        }
    }

	// E4X 12.1.1, pg 59
	Namespace* Toplevel::getDefaultNamespace()
	{
		// Walking the scope chain now would require a pointer into the local
		// variable space of the currently executing function.  Instead we save/
		// restore the defaultNamespace location as we enter/leave methods, so we
		// always can get to the current value.
		AvmCore* core = this->core();
#ifdef _DEBUG
		AvmAssert(!core->dxnsAddr || (uintptr)(*core->dxnsAddr) != 0xcccccccc);
#endif
		if (!core->dxnsAddr || !(*core->dxnsAddr))
			throwTypeError(kNoDefaultNamespaceError);
		return *core->dxnsAddr;
	}

	/**
	 * find the binding for a property given a full multiname reference.  The lookup
	 * must produce a single binding, or it's an error.  Note that the name could be
	 * bound to the same binding in multiple namespaces.
	 */
	Binding Toplevel::getBinding(Traits* traits, const Multiname* ref) const
	{
		Binding b = BIND_NONE;
		if (traits && ref->isBinding())
		{
			if (!traits->isResolved())
				traits->resolveSignatures(this);
				
			TraitsBindingsp tb = traits->getTraitsBindings();
			if (!ref->isNsset())
			{
				b = tb->findBinding(ref->getName(), ref->getNamespace());
			}
			else
			{
				b = tb->findBinding(ref->getName(), ref->getNsset());
				if (b == BIND_AMBIGUOUS)
				{
					// ERROR.  more than one binding is available.  throw exception.
					throwTypeError(kAmbiguousBindingError, core()->toErrorString(ref));
				}
			}
		}
		return b;
	}

	Stringp Toplevel::decodeURI(ScriptObject* self, Stringp uri)
	{
		AvmCore* core = self->core();
		if (!uri) uri = core->knull;
		Stringp out = decode(core, uri, false);
		if (!out) {
			self->toplevel()->uriErrorClass()->throwError(kInvalidURIError, core->toErrorString("decodeURI"));
		}
		return out;
    }

	Stringp Toplevel::decodeURIComponent(ScriptObject* self, Stringp uri)
	{
		AvmCore* core = self->core();
		if (!uri) uri = core->knull;
		Stringp out = decode(core, uri, true);
		if (!out) {
			self->toplevel()->uriErrorClass()->throwError(kInvalidURIError, core->toErrorString("decodeURIComponent"));
		}
		return out;
    }

	Stringp Toplevel::encodeURI(ScriptObject* self, Stringp uri)
	{
		AvmCore* core = self->core();
		if (!uri) uri = core->knull;
		Stringp out = encode(core, uri, false);
		if (!out) {
			self->toplevel()->uriErrorClass()->throwError(kInvalidURIError, core->toErrorString("encodeURI"));
		}
		return out;
    }

	Stringp Toplevel::encodeURIComponent(ScriptObject* self, Stringp uri)
	{
		AvmCore* core = self->core();
		if (!uri) uri = core->knull;
		Stringp out = encode(core, uri, true);
		if (!out) {
			self->toplevel()->uriErrorClass()->throwError(kInvalidURIError, core->toErrorString("encodeURIComponent"));
		}
		return out;
    }
	
	bool Toplevel::isNaN(ScriptObject*, double n)
	{
        return MathUtils::isNaN(n);
    }

	/**
	 * isFinite(number) in section 15.1.2.5 of ecma 262 edition 3
	 *
	 * Applies ToNumber to argument then returns false if the result is NaN, Negative
	 * Infinity, or Positive Infinity, and true otherwise
	 *
	 * Special case - if isFinite is called with no args, should return false based on 
	 * section 10.1.3 that states if a function is called with less arguments then
	 * params, the variables get assigned 'undefined'.  ToNumber(undefined) returns NaN
	 * 
	 * @return true if arg is Finite, false otherwise
	 */
	bool Toplevel::isFinite(ScriptObject*, double d)
	{
		return !(MathUtils::isInfinite(d)||MathUtils::isNaN(d));
    }

	double Toplevel::parseInt(ScriptObject* self, Stringp in, int radix)
	{
		AvmCore* core = self->core();
		if (!in) in = core->knull;
		double n = MathUtils::parseInt(in, radix, false);
		return n;
    }

	double Toplevel::parseFloat(ScriptObject* self, Stringp in)
	{
		double result;
		
		AvmCore* core = self->core();
		if (!in) in = core->knull;
		if (!MathUtils::convertStringToDouble(in, &result, false))
			result = MathUtils::kNaN;

		return result;
    }

	Stringp Toplevel::escape(ScriptObject* self, Stringp in)
	{
		AvmCore* core = self->core();

		if (!in) in = core->knull;

		StringBuffer buffer(core);
		
		StringIndexer str_idx(in);
		for (int i=0, n=in->length(); i<n; i++) {
			wchar ch = str_idx[i];
			if (contains(unescaped, ch)) {
				buffer << ch;
			} else if (ch & 0xff00) {
				buffer << "%u";
				buffer.writeHexWord(ch);
			} else {
				buffer << '%';
				buffer.writeHexByte((uint8)ch);
			}
		}

		return core->newStringUTF8(buffer.c_str());
    }

	Stringp Toplevel::escapeBytes(Stringp input)
	{
		AvmCore* core = this->core();

		StUTF8String inputUTF8(input);
		const uint8_t* src = (const uint8_t*) inputUTF8.c_str();

		StringBuffer buffer(core);
		
		for (int i=0, n=inputUTF8.length(); i<n; i++) {
			uint8_t ch = src[i];
			if (contains(unescaped, ch)) {
				buffer << (wchar)ch;
			} else {
				buffer << '%';
				buffer.writeHexByte((uint8_t)ch);
			}
		}
		return core->newStringUTF8(buffer.c_str());
    }
	
	Atom Toplevel::eval(ScriptObject* self, Atom input)
	{
		(void)self;
		(void)input;
#ifdef VMCFG_EVAL
		if (AvmCore::isString(input)) {
			AvmCore* core = self->core();
			CodeContext* codeContext = core->codeContext();
# ifdef DEBUGGER
			DomainEnv* domainEnv = codeContext->domainEnv();
#else
			DomainEnv* domainEnv = NULL;
#endif
			String* filename = NULL;						// should be NULL to denote eval code, for now
			NativeInitializer* nativeInitializer = NULL;	// "native" not supported for eval code
			Toplevel* toplevel = (Toplevel*)self;
			String *newsrc = AvmCore::atomToString(input)->appendLatin1("\0", 1);
			return core->handleActionSource(newsrc, filename, domainEnv, toplevel, nativeInitializer, codeContext);
		}
#endif // VMCFG_EVAL
		return undefinedAtom;
	}
	
	// Helper function.
	int Toplevel::parseHexChar(wchar c)
	{
		if ('0' <= c && c <= '9') {
			return c-'0';
		}
		if ('A' <= c && c <= 'F') {
			return c-'A'+10;
		}
		if ('a' <= c && c <= 'f') {
			return c-'a'+10;
		}
		return -1;
	}

	Stringp Toplevel::unescape(ScriptObject* self, Stringp in)
	{
		AvmCore* core = self->core();

		if (!in) in = core->knull;

		Stringp out = core->kEmptyString;
		int32_t pos = 0;
		StringIndexer str(in);
		while (pos < in->length())
		{
			utf32_t ch = str[pos++];
			if (ch == '%') 
			{
				int32_t curPos = pos;
				int len = 2;
				if (pos < (in->length() - 5) && str[pos] == 'u')
				{
					len = 4;
					pos++;
				}
				if ((pos + len) <= in->length())
				{
					ch = 0;
					while (len--) 
					{
						int v = parseHexChar((wchar) str[pos++]);
						if (v < 0) 
						{
							pos = curPos;
							ch = '%';
							break;
						}
						ch = (utf32_t)((ch<<4) | v);
					}
				}
			}
			wchar ch16 = (wchar) ch;
			// note: this code is allowed to construct a string
			// containing illegal UTF16 sequences!
			out = out->append16(&ch16, 1);
		}
		return out;
    }
	
	Stringp Toplevel::encode(AvmCore* core, Stringp in, bool encodeURIComponentFlag)
	{
		StringBuffer out(core);

		StUTF16String in16(in);
		const wchar *src = in16.c_str();
		int len = in->length();

		while (len--) {
			wchar ch = *src;

			if (contains(uriUnescaped, ch) ||
				(!encodeURIComponentFlag &&
				 contains(uriReservedPlusPound, ch)))
			{
				out << (char)ch;
				src++;
			} else {
				if (ch >= 0xDC00 && ch <= 0xDFFF) {
					return NULL;
				}
				uint32 V;
				if (ch >= 0xD800 && ch < 0xDC00) {
					if (src[1] < 0xDC00 || src[1] > 0xDFFF) {
						return NULL;
					}
					V = (ch - 0xD800) * 0x400 + (src[1] - 0xDC00) * 0x10000;
					src += 2;
				} else {
					V = ch;
					src++;
				}
				uint8 Octets[6];
				int OctetsLen = UnicodeUtils::Ucs4ToUtf8(V, Octets);
				if (!OctetsLen) {
					return NULL;
				}
				for (int i=0; i<OctetsLen; i++) {
					out << '%';
					out.writeHexByte(Octets[i]);
				}
			}
		}
		return core->newStringUTF8(out.c_str());
	}
	
	Stringp Toplevel::decode(AvmCore* core, Stringp in, bool decodeURIComponentFlag)
	{
		StringIndexer chars(in);
		int length = in->length();
		wchar *out = (wchar*) core->GetGC()->Alloc(length*2+1); // decoded result is at most length wchar chars long
		int outLen = 0;

		for (int k = 0; k < length; k++) {
			wchar C = chars[k];
			if (C == '%') {
				int start = k;
				if ((k + 2) >= length) {
					return NULL;
				}
				int v1 = parseHexChar(chars[k+1]);
				if (v1 == -1) {
					return NULL;
				}
				int v2 = parseHexChar(chars[k+2]);
				if (v2 == -1) {
					return NULL;
				}
				k += 2;
				uint8 B = (uint8)((v1<<4) | v2);
				uint32 V;
				if (!(B & 0x80)) {
					V = (wchar)B;
				} else {
					// 13. Let n be the smallest non-negative number
					//     such that (B << n) & 0x80 is equal to 0.
					int n = 1;
					while (((B<<n) & 0x80) != 0) {
						n++;
					}

					// 14. If n equals 1 or n is greater than 4,
					//     throw a URIError exception.
					if (n == 1 || n > 4) {
						return NULL;
					}
					uint8 Octets[4];
					Octets[0] = B;
					if (k + 3*(n-1) >= length) {
						return NULL;
					}
					for (int j=1; j<n; j++) {
						k++;
						if (chars[k] != '%') {
							return NULL;
						}
						int v1 = parseHexChar(chars[k+1]);
						if (v1 == -1) {
							return NULL;
						}
						int v2 = parseHexChar(chars[k+2]);
						if (v2 == -1) {
							return NULL;
						}
						B = (uint8)((v1<<4) | v2);
						
						// 23. If the two most significant bits
						//     in B are not 10, throw a URIError exception.
						if ((B&0xC0) != 0x80) {
							return NULL;
						}
						
						k += 2;
						Octets[j] = B;
					}

					// 29. Let V be the value obtained by applying the UTF-8 transformation
					// to Octets, that is, from an array of octets into a 32-bit value.
					if (!UnicodeUtils::Utf8ToUcs4(Octets, n, &V)) {
						return NULL;
					}
				}

				if (V < 0x10000) {
					// Check for reserved set
					if (!decodeURIComponentFlag) {
						if (contains(uriReservedPlusPound, V)) {
							while (start <= k) {
								out[outLen++] = chars[start++];
							}
						} else {
							out[outLen++] = (wchar)V;
						}
					} else {
						out[outLen++] = (wchar)V;
					}
				} else {
					// 31. If V is greater than 0x10FFFF, throw a URIError exception.
					if (V > 0x10FFFF) {
						return NULL;
					}
					// 32. Let L be (((V - 0x10000) & 0x3FF) + 0xDC00).
					// 33. Let H be ((((V - 0x10000) >> 10) & 0x3FF) + 0xD800).						
					uint32 L = (((V - 0x10000) & 0x3FF) + 0xDC00);
					uint32 H = ((((V - 0x10000) >> 10) & 0x3FF) + 0xD800);
					out[outLen++] = (wchar)H;
					out[outLen++] = (wchar)L;
				}
			} else {
				out[outLen++] = C;
			}
		}

		return core->newStringUTF16(out, outLen);
	}

	/*
	 * uriUnescaped is defined in Section 15.1 of the ECMA-262 specification
	 */
	const uint32 Toplevel::uriUnescaped[] = {
		0x00000000,
		0x03ff6782,
		0x87fffffe,
		0x47fffffe
	};
	
	/*
	 * uriReserved is defined in Section 15.1 of the ECMA-262 specification
	 * The '#' sign is added in accordance with the definition of
	 * the encodeURI/decodeURI functions
	 */
	const uint32 Toplevel::uriReservedPlusPound[] = {
		0x00000000,
		0xac009858,
		0x00000001,
		0x00000000
	};

	/**
	 * unescaped is a bitmap representing the set of 69 nonblank
	 * characters defined in ECMA-262 Section B.2.1 for the
	 * escape top-level function
	 */
	const uint32 Toplevel::unescaped[] = {
		0x00000000,
		0x03ffec00,
		0x87ffffff,
		0x07fffffe
	};

	bool Toplevel::isXMLName(ScriptObject* self, Atom v)
	{
		return self->core()->isXMLName(v);
	}

	unsigned int Toplevel::readU30(const byte *&p) const
	{
		unsigned int result = AvmCore::readU30(p);
		if (result & 0xc0000000)
			throwVerifyError(kCorruptABCError);
		return result;
	}

	void Toplevel::throwVerifyError(int id) const
	{
		verifyErrorClass()->throwError(id);
	}

#ifdef DEBUGGER
	void Toplevel::throwVerifyError(int id, Stringp arg1) const
	{
		verifyErrorClass()->throwError(id, arg1);
	}

	void Toplevel::throwVerifyError(int id, Stringp arg1, Stringp arg2) const
	{
		verifyErrorClass()->throwError(id, arg1, arg2);
	}
#endif

	void Toplevel::throwTypeError(int id) const
	{
		typeErrorClass()->throwError(id);
	}

	void Toplevel::throwTypeError(int id, Stringp arg1) const
	{
		typeErrorClass()->throwError(id, arg1);
	}

	void Toplevel::throwTypeError(int id, Stringp arg1, Stringp arg2) const
	{
		typeErrorClass()->throwError(id, arg1, arg2);
	}

	void Toplevel::throwTypeErrorWithName(int id, const char* namestr) const
	{
		// The construction of the multiname and the resulting error string is
		// delegated to this function because in-lining it in the caller prevents
		// taill calling.  See comments in op_call, above.
		
		Multiname name(core()->publicNamespace, core()->internString(core()->newStringLatin1(namestr)));
		throwTypeError(id, core()->toErrorString(&name));
	}
	
	void Toplevel::throwError(int id) const
	{
		errorClass()->throwError(id);
	}

	void Toplevel::throwError(int id, Stringp arg1) const
	{
		errorClass()->throwError(id, arg1);
	}

	void Toplevel::throwError(int id, Stringp arg1, Stringp arg2) const
	{
		errorClass()->throwError(id, arg1, arg2);
	}

	void Toplevel::throwArgumentError(int id) const
	{
		argumentErrorClass()->throwError(id);
	}

	void Toplevel::throwArgumentError(int id, Stringp arg1) const
	{
		argumentErrorClass()->throwError(id, arg1);
	}

	void Toplevel::throwArgumentError(int id, const char *s) const
	{
		argumentErrorClass()->throwError(id, core()->toErrorString(s));
	}

	void Toplevel::throwArgumentError(int id, Stringp arg1, Stringp arg2) const
	{
		argumentErrorClass()->throwError(id, arg1, arg2);
	}

	void Toplevel::throwRangeError(int id) const
	{
		rangeErrorClass()->throwError(id);
	}

	void Toplevel::throwRangeError(int id, Stringp arg1) const
	{
		rangeErrorClass()->throwError(id, arg1);
	}

	void Toplevel::throwRangeError(int id, Stringp arg1, Stringp arg2) const
	{
		rangeErrorClass()->throwError(id, arg1, arg2);
	}

	void Toplevel::throwRangeError(int id, Stringp arg1, Stringp arg2, Stringp arg3) const
	{
		rangeErrorClass()->throwError(id, arg1, arg2, arg3);
	}

	void Toplevel::throwReferenceError(int id, const Multiname* multiname, const Traits* traits) const
	{
		referenceErrorClass()->throwError(id, core()->toErrorString(multiname), core()->toErrorString((Traits*)traits));
	}

	void Toplevel::throwReferenceError(int id, const Multiname* multiname) const
	{
		referenceErrorClass()->throwError(id, core()->toErrorString(multiname));
	}

	DateClass* Toplevel::dateClass() { return (DateClass*)getBuiltinClass(avmplus::NativeID::abcclass_Date); }
	RegExpClass* Toplevel::regexpClass() { return (RegExpClass*)getBuiltinClass(avmplus::NativeID::abcclass_RegExp); }
	XMLClass* Toplevel::xmlClass() { return (XMLClass*)getBuiltinClass(avmplus::NativeID::abcclass_XML); }
	XMLListClass* Toplevel::xmlListClass() { return (XMLListClass*)getBuiltinClass(avmplus::NativeID::abcclass_XMLList); }
	QNameClass* Toplevel::qnameClass() { return (QNameClass*)getBuiltinClass(avmplus::NativeID::abcclass_QName); }
	ErrorClass* Toplevel::errorClass() const { return getErrorClass(avmplus::NativeID::abcclass_Error); }
	ErrorClass* Toplevel::argumentErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_ArgumentError); }
	ErrorClass* Toplevel::evalErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_EvalError); }
	ErrorClass* Toplevel::typeErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_TypeError); }
	ErrorClass* Toplevel::rangeErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_RangeError); }
	ErrorClass* Toplevel::uriErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_URIError); }
	ErrorClass* Toplevel::referenceErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_ReferenceError); }
	ErrorClass* Toplevel::securityErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_SecurityError); }
	ErrorClass* Toplevel::syntaxErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_SyntaxError); }
	ErrorClass* Toplevel::verifyErrorClass() const { return getErrorClass(avmplus::NativeID::abcclass_VerifyError); }
}
