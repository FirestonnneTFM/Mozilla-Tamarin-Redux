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

namespace avmplus
{
	PoolObject::PoolObject(AvmCore* core, ScriptBuffer& sb, const byte* startPos) :
		core(core),
		cpool_int(0),
		cpool_uint(0),
		cpool_double(core->GetGC(), 0),
		cpool_string(core->GetGC(), 0),
		cpool_ns(core->GetGC(), 0),
		cpool_ns_set(core->GetGC(), 0),
		cpool_mn(0),
		bugFlags(0),
		methods(core->GetGC(), 0),
		metadata_infos(0),
		cinits(core->GetGC(), 0),
		scripts(core->GetGC(), 0),
		abcStart(startPos)
	{
		namedTraits = new(core->GetGC()) MultinameHashtable();
		privateNamedScripts = new(core->GetGC()) MultinameHashtable();
		m_code = sb.getImpl();
#if defined(AVMPLUS_MIR)
		codeBuffer = new (core->GetGC()) GrowableBuffer(core->GetGC()->GetGCHeap());
#endif
		version = AvmCore::readU16(&code()[0]) | AvmCore::readU16(&code()[2])<<16;
	}

	PoolObject::~PoolObject()
	{
		#ifdef AVMPLUS_MIR
		delete codeBuffer;
		#endif
		#ifdef AVMPLUS_WORD_CODE
		delete word_code.cpool_mn;
		#endif
	}
	
    AbstractFunction* PoolObject::getMethodInfo(uint32 index)
    {
		AvmAssert(index < methodCount);
		return methods[index];
    }

	Traits* PoolObject::getBuiltinTraits(Stringp name) const
	{
		AvmAssert(BIND_NONE == 0);
		return (Traits*) namedTraits->getName(name);
	}

	Traits* PoolObject::getTraits(Stringp name, Namespace* ns, bool recursive/*=true*/) const
	{
		// look for class in VM-wide type table
		Traits* t = domain->getNamedTraits(name, ns, recursive);

		// look for class in current ABC file
		if (t == NULL)
			t = (Traits*) namedTraits->get(name, ns);
		return t;
	}

	Traits* PoolObject::getTraits(Stringp name, bool recursive/*=true*/) const
	{
		return getTraits(name, core->publicNamespace, recursive);
	}

	Traits* PoolObject::getTraits(const Multiname& mname, const Toplevel* toplevel, bool recursive/*=true*/) const
	{
		// do full lookup of multiname, error if more than 1 match
		// return Traits if 1 match, NULL if 0 match, throw ambiguity error if >1 match
		Traits* match = NULL;
		if (mname.isBinding())
		{
			// multiname must not be an attr name, have wildcards, or have runtime parts.
			for (int i=0, n=mname.namespaceCount(); i < n; i++)
			{
				Traits* t = getTraits(mname.getName(), mname.getNamespace(i), recursive);
				if (t != NULL)
				{
					if (match == NULL)
					{
						match = t;
					}
					else if (match != t)
					{
						// ambiguity
						if (toplevel)
							toplevel->throwReferenceError(kAmbiguousBindingError, mname);
						AvmAssert(!"unhandled ambiguous binding");
					}
				}
			}
		}
		return match;
	}

	void PoolObject::addNamedTraits(Stringp name, Namespace* ns, Traits* traits)
	{
		namedTraits->add(name, ns, (Binding)traits);
	}

	Namespace* PoolObject::getNamespace(int index) const
	{
		return cpool_ns[index];  
	}

	NamespaceSetp PoolObject::getNamespaceSet(int index) const
	{
		return cpool_ns_set[index];  
	}

	Stringp PoolObject::getString(int index) const
	{
		return cpool_string[index];  
	}

	Atom PoolObject::getDefaultValue(const Toplevel* toplevel, uint32 index, CPoolKind kind, Traits* t) const
	{
		// toplevel actually can be null, when resolving the builtin classes...
		// but they should never cause verification errors in functioning builds
		//AvmAssert(toplevel != NULL);

		AvmAssert(index != 0);
		uint32_t maxcount = 0;
		// Look in the cpool specified by kind
		switch(kind)
		{
		case CONSTANT_Int:
			if (index >= (maxcount = constantIntCount))
				goto range_error;
			return core->intToAtom(cpool_int[index]);

		case CONSTANT_UInt:
			if (index >= (maxcount = constantUIntCount))
				goto range_error;
			return core->uintToAtom(cpool_uint[index]);

		case CONSTANT_Double:
			if (index >= (maxcount = constantDoubleCount))
				goto range_error;
			return kDoubleType|(uintptr)cpool_double[index];

		case CONSTANT_Utf8:
			if (index >= (maxcount = constantStringCount))
				goto range_error;
			return cpool_string[index]->atom();

		case CONSTANT_True:
			return trueAtom;

		case CONSTANT_False:
			return falseAtom;

		case CONSTANT_Namespace:
        case CONSTANT_PackageNamespace:
        case CONSTANT_PackageInternalNs:
        case CONSTANT_ProtectedNamespace:
        case CONSTANT_ExplicitNamespace:
        case CONSTANT_StaticProtectedNs:
		case CONSTANT_PrivateNs:
			if (index >= (maxcount = constantNsCount))
				goto range_error;
			return cpool_ns[index]->atom();

		case CONSTANT_Null:
			return nullObjectAtom;

		default:
			// Multinames & NamespaceSets are invalid default values.
			if (t)
			{
				toplevel->throwVerifyError(kIllegalDefaultValue, core->toErrorString(Multiname(t->ns, t->name)));
			}
			else
			{
				toplevel->throwVerifyError(kCorruptABCError);
			}
			return undefinedAtom; // not reached
		}

range_error:
		if (toplevel)
			toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(maxcount));
		AvmAssert(!"unhandled verify error");
		return undefinedAtom; // not reached
	}

	void PoolObject::parseMultiname(const byte *pos, Multiname& m) const
	{
		// the multiname has already been validated so we don't do
		// any checking here, we just fill in the Multiname object
		// with the information we have parsed.

		int index;
		CPoolKind kind = (CPoolKind) *(pos++);
        switch (kind)
        {
		case CONSTANT_Qname: 
		case CONSTANT_QnameA:
		{
			// U16 namespace_index
            // U16 name_index
			// parse a multiname with one namespace (aka qname)

			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyNamespace();
			else
				m.setNamespace(getNamespace(index));

			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyName();
			else
				m.setName(getString(index));

			m.setQName();
			m.setAttr(kind==CONSTANT_QnameA);
			break;
		}

		case CONSTANT_RTQname:
		case CONSTANT_RTQnameA: 
		{
			// U16 name_index
			// parse a multiname with just a name; ns fetched at runtime

			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyName();
			else
				m.setName(getString(index));

			m.setQName();
			m.setRtns();
			m.setAttr(kind==CONSTANT_RTQnameA);
			break;
		}

		case CONSTANT_RTQnameL:
		case CONSTANT_RTQnameLA:
		{
			m.setQName();
			m.setRtns();
			m.setRtname();
			m.setAttr(kind==CONSTANT_RTQnameLA);
			break;
		}

		case CONSTANT_Multiname:
		case CONSTANT_MultinameA:
		{
			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyName();
			else
				m.setName(getString(index));

			index = AvmCore::readU30(pos);
			AvmAssert(index != 0);
			m.setNsset(getNamespaceSet(index));

			m.setAttr(kind==CONSTANT_MultinameA);
			break;
		}

		case CONSTANT_MultinameL:
		case CONSTANT_MultinameLA:
		{
			m.setRtname();

			index = AvmCore::readU30(pos);
			AvmAssert(index != 0);
			m.setNsset(getNamespaceSet(index));

			m.setAttr(kind==CONSTANT_MultinameLA);
			break;
		}

		case CONSTANT_TypeName:
		{
			index = AvmCore::readU30(pos);
			Atom a = cpool_mn[index];
			parseMultiname(atomToPos(a), m);
			index = AvmCore::readU30(pos);
			AvmAssert(index==1);
			m.setTypeParameter(AvmCore::readU30(pos));
			break;
		}
		
		default:
			AvmAssert(false);
		}

		return;
	}


	void PoolObject::resolveQName(uint32_t index, Multiname &m, const Toplevel* toplevel) const
	{
		if (index == 0 || index >= constantMnCount)
		{
			if (toplevel)
				toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(constantMnCount));
			AvmAssert(!"unhandled verify error");
		}

		parseMultiname(cpool_mn[index], m);
		if (!m.isQName())
		{
			if (toplevel)
				toplevel->throwVerifyError(kCpoolEntryWrongTypeError, core->toErrorString(index));
			AvmAssert(!"unhandled verify error");
		}
	}

	Traits* PoolObject::resolveTypeName(uint32 index, const Toplevel* toplevel, bool allowVoid/*=false*/) const
	{
		// only save the type name for now.  verifier will resolve to traits
		if (index == 0)
		{
			return NULL;
		}

		// check contents is a multiname.  in the cpool, and type system, kObjectType means multiname.
		if (index >= constantMnCount)
		{
			if (toplevel)
				toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(constantMnCount));
			AvmAssert(!"unhandled verify error");
		}

		Multiname m;
		parseMultiname(cpool_mn[index], m);

		Traits* t = getTraits(m, toplevel);
		if(m.isParameterizedType())
		{
			Traits* param_traits = resolveTypeName(m.getTypeParameter(), toplevel);
			t = resolveParameterizedType(toplevel, t, param_traits);
		}
		if (!t)
		{
			#ifdef AVMPLUS_VERBOSE
			if (!toplevel || !toplevel->verifyErrorClass())
				core->console << "class not found: " << m << " index=" << index << "\n";
			#endif
			if (toplevel)
				toplevel->throwVerifyError(kClassNotFoundError, core->toErrorString(&m));
			AvmAssert(!"unhandled verify error");
		}
		if (!allowVoid && t == VOID_TYPE)
		{
			if (toplevel)
				toplevel->throwVerifyError(kIllegalVoidError);
			AvmAssert(!"unhandled verify error");
		}

		return t;
	}

	Traits* PoolObject::resolveParameterizedType(const Toplevel* toplevel, Traits* base, Traits* param_traits ) const
	{
		Traits* r = NULL;
		if( base == core->traits.vector_itraits)
		{
			// Only vector is parameterizable for now...
			if(!param_traits) // Vector.<*>
				r = core->traits.vectorobj_itraits;  
			else if( param_traits == core->traits.int_itraits)
				r = core->traits.vectorint_itraits;
			else if (param_traits == core->traits.uint_itraits)
				r = core->traits.vectoruint_itraits;
			else if (param_traits == core->traits.number_itraits)
				r = core->traits.vectordouble_itraits;
			else
			{
				Stringp fullname = core->internString( core->concatStrings(core->newString("Vector.<"), 
					core->concatStrings(param_traits->formatClassName(), core->newString(">")))->atom());

				Multiname newname;
				newname.setName(fullname);
				newname.setNamespace(base->ns);

				r = getTraits(newname, toplevel);

				if( !r )
				{
					r = core->traits.vectorobj_itraits->newParameterizedITraits(fullname, base->ns);
					core->traits.vector_itraits->pool->domain->addNamedTrait(fullname, base->ns, r);
				}
			}
		}
		return r;
	}

#ifdef AVMPLUS_TRAITS_CACHE
#else
	bool PoolObject::allowEarlyBinding(Traits* t) const
	{
		// the compiler can early bind to a type's slots when it's defined
		// in the same abc file (ensuring it came from the same compiler)
		// or when the base class came from another abc file and has zero slots
		// this ensures you cant use the early opcodes to access an external type's
		// private members.
		while (t != NULL && t->slotCount > 0)
		{
			if (t->pool != this && t->slotCount > 0)
			{
				return false;
			}
			t = t->base;
		}
		return true;
	}
#endif

#ifdef AVMPLUS_TRAITS_CACHE
	// nothing
#else
    uint32_t PoolObject::resolveTraits(Traits *traits, int firstSlot, const Toplevel* toplevel)
    {
		uint32_t offset = traits->getSlotAreaStart();
		int padoffset = -1;

		const byte* pos = traits->getTraitsPos();
		AvmAssert(pos != NULL);

		int nameCount = AvmCore::readU30(pos);

		int slot_id = firstSlot;
		
		AbcGen gen(core->GetGC(), traits->slotCount * 7);

		bool earlySlotBinding = allowEarlyBinding(traits);

        for (int i=0; i < nameCount; i++)
        {
			Multiname qn;
			resolveQName(pos, qn, toplevel);
			Stringp name = qn.getName();
			Namespace* ns = qn.getNamespace();
            int tag = (TraitKind)pos[0];
			TraitKind kind = (TraitKind) (tag & 0x0f); //Get rid of the flags
			pos += 1;
			int skip = 0;
			int id = 0;
			int info = 0;
			int value_index = 0;
			CPoolKind value_kind = (CPoolKind)0;
			// Check for version metadata
			switch (kind)
			{
			case TRAIT_Slot:
			case TRAIT_Const:
			case TRAIT_Class:
				id = AvmCore::readU30(pos); // slot id
				info = AvmCore::readU30(pos); // type or class info
				if( kind == TRAIT_Slot || kind == TRAIT_Const )
				{
					value_index = AvmCore::readU30(pos); // value
					if( value_index )
						value_kind = (CPoolKind)*pos++;
				}
				break;
			case TRAIT_Getter:
			case TRAIT_Setter:
			case TRAIT_Method:
				id = AvmCore::readU30(pos);  // disp id
				info = AvmCore::readU30(pos);  // method
				break;
			default:
				// unsupported traits type
				toplevel->throwVerifyError(kUnsupportedTraitsKindError, core->toErrorString(kind));
			}
			const byte* meta_pos = pos;
			if( tag & ATTR_metadata )
			{
				uint32_t metadataCount = AvmCore::readU30(pos);
				for( uint32_t metadata = 0; metadata < metadataCount; ++metadata)
				{
					uint32_t index = AvmCore::readU30(pos);
					if (stripMetadataIndexes.indexOf(index)!=-1 )
						skip = 1;  // Stripping this definition, 
				}
			}
			if( skip ) 
			{ 
				continue;
			}

			switch (kind)
			{
			case TRAIT_Slot:
			case TRAIT_Const:
			{
				// compute the slot
				uint32 useSlotId = id;
                if(!earlySlotBinding ) useSlotId = 0;
				if (!useSlotId)
					useSlotId = slot_id++;
				else
					useSlotId--;

				// compute the type
				Traits* slotTraits = resolveTypeName(info, toplevel);

				// default value for this slot.
				int slotOffset;
				if ((slotTraits == NUMBER_TYPE)
					#ifdef AVMPLUS_64BIT
					|| ((slotTraits != INT_TYPE) && (slotTraits != UINT_TYPE) && (slotTraits != BOOLEAN_TYPE))
					#endif			
				)
				{
					// 8-aligned, 8-byte field
					if (offset&7)
					{
						padoffset = offset;
						offset += 4;
					}
					slotOffset = offset;
					offset += 8;
				}
				else
				{
					// 4-aligned, 4-byte field
					if (padoffset != -1)
					{
						slotOffset = padoffset;
						padoffset = -1;
					}
					else
					{
						slotOffset = offset;
						offset += 4;
					}
				}

				traits->setSlotInfo(value_index, useSlotId, toplevel, slotTraits, slotOffset, value_kind, gen);
				if( tag & ATTR_metadata )
				{
					traits->setSlotMetadataPos(useSlotId, meta_pos);
				}
				break;
			}

			case TRAIT_Class: 
			{
				// compute the slot
				uint32 useSlotId = id;
                if( !earlySlotBinding ) useSlotId = 0;
				if (!useSlotId)
					useSlotId = slot_id++;
				else
					useSlotId--;

				// get the class type
				uint32 class_info = info;
				if (class_info >= classCount)
					toplevel->throwVerifyError(kClassInfoExceedsCountError, core->toErrorString(class_info), core->toErrorString(classCount));

				AbstractFunction* cinit = cinits[class_info];
				if (!cinit) 
					toplevel->throwVerifyError(kClassInfoOrderError, core->toErrorString(class_info));

				int slotOffset;
				#ifdef AVMPLUS_64BIT
				// 8-aligned, 8-byte field
				if (offset&7)
				{
					padoffset = offset;
					offset += 4;
				}
				slotOffset = offset;
				offset += 8;
				#else
				// 4-aligned, 4-byte field
				if (padoffset != -1)
				{
					slotOffset = padoffset;
					padoffset = -1;
				}
				else
				{
					slotOffset = offset;
					offset += 4;
				}
				#endif

				traits->setSlotInfo(0, useSlotId, toplevel, cinit->declaringTraits, slotOffset, CONSTANT_unused_0x00, gen);
				break;
			}

			case TRAIT_Method:
			{
				int earlyDispId = id;
                (void)earlyDispId;

				uint32 method_info = info;

				// method_info range already checked in AbcParser
				AvmAssert(method_info < methodCount);
				AbstractFunction *f = getMethodInfo(method_info);
				AvmAssert(f != NULL);

				// disp_id assigned by abcParser, this binding must exist already.
				Binding b = traits->get(name, ns);

				AvmAssert(AvmCore::isMethodBinding(b));
				int disp_id = AvmCore::bindingToMethodId(b);

				// !!@ Ed says there may be an earlier place in AbcParser to catch this
				if (traits->getMethod(disp_id) && traits->getOverride(ns,name,tag,toplevel) == BIND_NONE)
				{
					toplevel->throwVerifyError(kDuplicateDispIdError, core->toErrorString(traits->getMethod(disp_id)), core->toErrorString(disp_id));
				}
				traits->setMethod(disp_id, f);
				if( tag & ATTR_metadata )
				{
					traits->setMethodMetadataPos(disp_id, meta_pos);
				}
				break;
			}

			case TRAIT_Getter:
			case TRAIT_Setter:
			{
				int earlyDispId = id;
                (void)earlyDispId;

				uint32 method_info = info;
				
				// method_info already checked in AbcParser
				AvmAssert(method_info < methodCount);
				AbstractFunction* f = getMethodInfo(method_info);
				AvmAssert(f != NULL);

				Binding b = traits->get(name, ns);

				AvmAssert(b==BIND_NONE || AvmCore::isAccessorBinding(b));
				uint32 disp_id = kind == TRAIT_Getter ? AvmCore::bindingToGetterId(b) : AvmCore::bindingToSetterId(b);
				
				AvmAssert(disp_id < traits->methodCount);
				// !!@ Ed says there may be an earlier place in AbcParser to catch this
				if (traits->getMethod(disp_id))
				{
					Binding baseBinding = traits->getOverride(ns,name,tag,toplevel);
					if (kind == TRAIT_Getter && !AvmCore::hasGetterBinding(baseBinding) ||
						kind == TRAIT_Setter && !AvmCore::hasSetterBinding(baseBinding))
					{
						toplevel->throwVerifyError(kDuplicateDispIdError, core->toErrorString(traits->getMethod(disp_id)), core->toErrorString(disp_id));
					}
				}
				traits->setMethod(disp_id, f);
				if( tag & ATTR_metadata )
				{
					traits->setMethodMetadataPos(disp_id, meta_pos);
				}

				break;
			}

			default:
				// unsupported traits type
				toplevel->throwVerifyError(kUnsupportedTraitsKindError, core->toErrorString(kind));
			}

		}

		for (uint32 i=0, n=traits->slotCount; i < n; i++)
		{
			if (traits->getSlotOffset(i) == 0)
			{
				// sparse slot table.  make types default to *
				#ifdef AVMPLUS_VERBOSE
				if (verbose)
				{
					core->console << "WARNING: slot " << i+1 << " on " << traits << " not defined by compiler.  Using *\n";
				}
				#endif

				AvmAssert(0);
				int slotOffset;
				// 4-aligned, 4-byte field
				if (padoffset != -1)
				{
					slotOffset = padoffset;
					padoffset = -1;
				}
				else
				{
					slotOffset = offset;
					offset += 4;
				}
				
				traits->setSlotInfo(0, i, toplevel, NULL, slotOffset, CONSTANT_unused_0x00, gen);
			}
		}		

		traits->genInitBody(toplevel, gen);

		return offset;
	}
#endif // not AVMPLUS_TRAITS_CACHE

	void PoolObject::addPrivateNamedScript(Stringp name, Namespace* ns, AbstractFunction *script)
	{
		privateNamedScripts->add(name, ns, (Binding)script);
	}

	AbstractFunction* PoolObject::getNamedScript(const Multiname* multiname) const
	{
		AbstractFunction *f = domain->getNamedScript(multiname);
		if(!f)
		{
			f = (AbstractFunction*)privateNamedScripts->getMulti(multiname);
		}
		return f;
	}
	
#ifdef AVMPLUS_WORD_CODE
	PrecomputedMultinames::PrecomputedMultinames(MMgc::GC* gc, PoolObject* pool)
		: MMgc::GCRoot(gc)
		, nNames (0)
	{
		nNames = pool->constantMnCount;
		for ( uint32 i=1 ; i < nNames ; i++ ) {
			Multiname mn;
			pool->parseMultiname(mn, i);
			mn.IncrementRef();
			multinames[i] = mn;
		}
	}
	
	PrecomputedMultinames::~PrecomputedMultinames() {
		for ( uint32 i=1 ; i < nNames ; i++ ) 
			multinames[i].DecrementRef();
	}
#endif
	
}
