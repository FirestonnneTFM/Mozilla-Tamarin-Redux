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
	Domain::Domain(AvmCore *_core, Domain* base) : base(base)
		  , core(_core)
		  , _globalMemoryBase(m_gmInfo.globalMemoryScratch)
		  , _globalMemorySize(sizeof(m_gmInfo.globalMemoryScratch))
	{
		//m_gmInfo.globalMemory = NULL; -- not necessary, null is default
		// should be able to contain largest read or write (currently double)
		AvmAssert(sizeof(m_gmInfo.globalMemoryScratch) >= sizeof(double));
		namedTraits  = new (_core->GetGC()) MultinameHashtable();
		namedScripts = new (_core->GetGC()) MultinameHashtable();
	}

	Traits* Domain::getNamedTraits(Stringp name, Namespacep ns, bool recursive/*=true*/) const
	{
		Traits *traits = NULL;
		if (recursive && base) {
			traits = base->getNamedTraits(name, ns, true);
		}
		if (!traits) {
			traits = (Traits*) namedTraits->get(name, ns);
		}
		return traits;
	}

	Traits* Domain::getNamedTraits(const Multiname *multiname, bool recursive/*=true*/) const
	{
		Traits *traits = NULL;
		if (recursive && base) {
			traits = base->getNamedTraits(multiname, true);
		}
		if (!traits) {
			traits = (Traits*) namedTraits->getMulti(multiname);
		}
		return traits;
	}
	
	MethodInfo* Domain::getNamedScript(Stringp name, Namespacep ns) const
	{
		MethodInfo* f = NULL;
		if (base) {
			f = base->getNamedScript(name, ns);
		}
		if (!f) {
			f = (MethodInfo*)namedScripts->get(name, ns);
		}
		return f;
	}

	MethodInfo* Domain::getNamedScript(const Multiname *multiname) const
	{
		MethodInfo* f = NULL;
		if (base) {
			f = base->getNamedScript(multiname);
		}
		if (!f) {
			f = (MethodInfo*)namedScripts->getMulti(multiname);
		}
		return f;
	}

	bool Domain::setGlobalMemory(ScriptObject *mem) const
	{
		if(!mem)
		{
			// null obj -- use scratch
			if(m_gmInfo.globalMemory) // unsubscribe from current if any
				globalMemoryUnsubscribe(m_gmInfo.globalMemory);
			// remember NULL obj
			m_gmInfo.globalMemory = NULL;
			// point at scratch mem
			notifyGlobalMemoryChanged(m_gmInfo.globalMemoryScratch, sizeof(m_gmInfo.globalMemoryScratch));
		}
		else if(!globalMemorySubscribe(mem))
		{
			// failed... do nothing
			return false;
		}
		else
		{
			// success on globalMemorySubscribe would have led to notifyGlobalMemoryChanged
			// success... unsubscribe from original
			if(m_gmInfo.globalMemory)
				globalMemoryUnsubscribe(m_gmInfo.globalMemory);
			// remember the new one
			m_gmInfo.globalMemory = mem;
		}
		return true;
	}

	// record that this uint8_t** refers to a pointer to the
	// global memory backing store
	void Domain::addGlobalMemoryBaseRef(uint8_t** baseRef) const
	{
		AvmAssert(baseRef != NULL);

		// find the not slot in a given chunk
		int mod = m_gmInfo.globalMemoryBaseRefNum % GMInfo::REFS_PER_CHUNK;

		GMInfo::BaseRefChunk *refs;

		// if the slot is zero, we need a new chunk
		if(!mod)
		{
			refs = new (core->GetGC()) GMInfo::BaseRefChunk();
			refs->next = m_gmInfo.globalMemoryBaseRefs;
			m_gmInfo.globalMemoryBaseRefs = refs;
		}
		else
			refs = m_gmInfo.globalMemoryBaseRefs;
		// put it in the right slot
		refs->refs[mod] = baseRef;
		// and remember we added one
		m_gmInfo.globalMemoryBaseRefNum++;
	}

	// same as addGlobalMemoryBaseRef but for references to the
	// size of the global memory object
	void Domain::addGlobalMemorySizeRef(uint32_t* sizeRef) const
	{
		AvmAssert(sizeRef != NULL);

		int mod = m_gmInfo.globalMemorySizeRefNum % GMInfo::REFS_PER_CHUNK;

		GMInfo::SizeRefChunk *refs;

		if(!mod)
		{
			refs = new (core->GetGC()) GMInfo::SizeRefChunk();
			refs->next = m_gmInfo.globalMemorySizeRefs;
			m_gmInfo.globalMemorySizeRefs = refs;
		}
		else
			refs = m_gmInfo.globalMemorySizeRefs;
		refs->refs[mod] = sizeRef;
		m_gmInfo.globalMemorySizeRefNum++;
	}

	// memory changed so go through and update all reference to both the base
	// and the size of the global memory
	void Domain::notifyGlobalMemoryChanged(uint8_t* newBase, uint32_t newSize) const
	{
		AvmAssert(newBase != NULL); // real base address
		AvmAssert(newSize >= GLOBAL_MEMORY_MIN_SIZE); // big enough

		// ensure a real change happened...
		if(newBase != _globalMemoryBase || newSize != _globalMemorySize)
		{
			// if a real change happened to backing store base address...
			if(newBase != _globalMemoryBase)
			{
				GMInfo::BaseRefChunk *baseRefs = m_gmInfo.globalMemoryBaseRefs;

				// go through each reference
				for(uint32_t n = 0; n < m_gmInfo.globalMemoryBaseRefNum; n++)
				{
					// get the slot
					int mod = n % GMInfo::REFS_PER_CHUNK;

					// if it's zero, get the NEXT slot
					// this means we start with the SECOND chunk
					if(!mod)
					{
						baseRefs = baseRefs->next;
						// and when we get to the end, THEN do the first chunk
						if(!baseRefs)
							baseRefs = m_gmInfo.globalMemoryBaseRefs;
					}
					uint8_t** p = (baseRefs->refs[mod]);
					// and do a difference instead of a simple write
					// as it may be offset from the base
                    // printf("update base %p: %p -> %p\n",p,*p,*p - _globalMemoryBase + newBase);
					*p = *p - _globalMemoryBase + newBase;
				}
			}

			// same as above but for size
			if(newSize != _globalMemorySize)
			{
				GMInfo::SizeRefChunk* sizeRefs = m_gmInfo.globalMemorySizeRefs;

				for(uint32_t n = 0; n < m_gmInfo.globalMemorySizeRefNum; n++)
				{
					int mod = n % GMInfo::REFS_PER_CHUNK;

					if(!mod) // start with SECOND chunk
					{
						sizeRefs = sizeRefs->next;
						// and when we get to the end, THEN do the first chunk
						if(!sizeRefs)
							sizeRefs = m_gmInfo.globalMemorySizeRefs;
					}
					uint32_t* p = (sizeRefs->refs[mod]);
                    // printf("update size %p: %d -> %d\n",p,*p,*p - _globalMemorySize + newSize);
					*p = *p - _globalMemorySize + newSize;
				}
			}

			// record the new base and size
			_globalMemoryBase = newBase;
			_globalMemorySize = newSize;
		}
	}
}


