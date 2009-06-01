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


#ifdef AVMSHELL_BUILD
#include "avmshell.h"
#else
// player
#include "platformbuild.h"
#include "avmplayer.h"
#include "DictionaryGlue.h"
#endif

using namespace MMgc;

namespace avmplus
{
	DictionaryClass::DictionaryClass(VTable *vtable)
	: ClassClosure(vtable)
	{		
		createVanillaPrototype();
		vtable->traits->itraits->isDictionary = true;
	}

	ScriptObject *DictionaryClass::createInstance(VTable *ivtable, ScriptObject* /*delegate*/)
	{
 		GCAssert(ivtable->traits->isDictionary == true);
		return new (core()->GetGC(), ivtable->getExtraSize()) DictionaryObject(ivtable, prototype);
	}
	
	DictionaryObject::DictionaryObject(VTable *vtable, ScriptObject *delegate)
		: ScriptObject(vtable, delegate)
	{
		GCAssert(vtable->traits->isDictionary == true);
	}

	void DictionaryObject::init(bool weakKeys)
	{
		GCAssert(vtable->traits->isDictionary == true);
		MMgc::GC* gc = this->gc();
		_table = weakKeys ? 
					new (gc) WeakKeyHashtable(gc) : 
					new (gc) HeapHashtable(gc);
	}

	Atom FASTCALL DictionaryObject::getKeyFromObject(Atom key) const
	{
		AvmAssert(AvmCore::isObject(key));
		ScriptObject* obj = AvmCore::atomToScriptObject(key);
		AvmAssert(Traits::getBuiltinType(obj->traits()) != BUILTIN_qName);
		AvmAssert(MMgc::GC::Size(obj) >= sizeof(ScriptObject));
		(void)obj;

		// FIXME: this doesn't work, need to convert back to an XMLObject
		// on the way out or intern XMLObject's somehow
		//if(AvmCore::isXML(key))
		//	key = AvmCore::genericObjectToAtom(AvmCore::atomToXML(key));
		
		return key;
	}

	Atom DictionaryObject::getAtomProperty(Atom key) const
	{
		if (AvmCore::isObject(key)) 
		{
			return _table->get(getKeyFromObject(key));
		} 

		return ScriptObject::getAtomProperty(key);
	}

	bool DictionaryObject::hasAtomProperty(Atom key) const
	{
		if (AvmCore::isObject(key)) 
		{
			return _table->contains(getKeyFromObject(key));
		}

		return ScriptObject::hasAtomProperty(key);
	}

	bool DictionaryObject::deleteAtomProperty(Atom key)
	{
		if (AvmCore::isObject(key)) 
		{
			_table->remove(getKeyFromObject(key));
			return true;
		}

		return ScriptObject::deleteAtomProperty(key);
	}

	void DictionaryObject::setAtomProperty(Atom key, Atom value)
	{
		if (AvmCore::isObject(key)) 
		{
			_table->add(getKeyFromObject(key), value);
			return;
		}
		
		ScriptObject::setAtomProperty(key, value);
	}

	Atom DictionaryObject::nextName(int index)
	{
		Atom k = ScriptObject::nextName(index);

		if (AvmCore::isGenericObject(k) && _table->weakKeys()) 
		{
			GCWeakRef* ref = (GCWeakRef*)AvmCore::atomToGenericObject(k);
			ScriptObject* key = ((ScriptObject*)ref->get());
			if (key) 
			{
				AvmAssert(key->traits() != NULL);
				return key->atom();
			}

			return undefinedAtom;
		}

		return k;
	}

	int DictionaryObject::nextNameIndex(int index)
	{
		AvmAssert(index >= 0);

		if (index != 0) 
		{
			index = index<<1;
		}

		// this can happen if you break in debugger in a subclasses constructor before super
		// has been called -- let's do it in all builds, it's better than crashing.
		if (!_table)
		{
			return 0;
		}

		// Advance to first non-empty slot.
		InlineHashtable* ht = _table->get_ht();
		const Atom* atoms = ht->getAtoms();
		int numAtoms = ht->getCapacity();
		while (index < numAtoms) 
		{
			Atom a = atoms[index];
			if (AvmCore::isGenericObject(a) && _table->weakKeys()) 
			{
				GCWeakRef *weakRef = (GCWeakRef*)AvmCore::atomToGenericObject(a);
				if(weakRef->get())
					return (index>>1)+1;
				else {
					ht->getAtoms()[index] = InlineHashtable::DELETED;
					ht->getAtoms()[index+1] = InlineHashtable::DELETED;
					ht->setHasDeletedItems();
				}
			} else if(a != 0 && a != InlineHashtable::DELETED) {
					return (index>>1)+1;
			}
			index += 2;
		}
		return 0;
	}
}	
