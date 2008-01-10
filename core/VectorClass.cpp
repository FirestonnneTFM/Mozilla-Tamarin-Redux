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

using namespace MMgc;

namespace avmplus
{
	bool VectorBaseObject::hasAtomProperty(Atom name) const
	{
		return ScriptObject::hasAtomProperty(name) || getAtomProperty(name) != undefinedAtom;
	}
	
	void VectorBaseObject::setAtomProperty(Atom name, Atom value)
	{
		uint32 index;
		if (core()->getIndexFromAtom(name, &index))
		{
			setUintProperty(index, value);
		}
		else
		{
			ScriptObject::setAtomProperty(name, value);
		}
	}
	
	Atom VectorBaseObject::getAtomProperty(Atom name) const
	{
		uint32 index;
		if (core()->getIndexFromAtom(name, &index))
		{
			return getUintProperty(index);
		}
		else
		{
			return ScriptObject::getAtomProperty(name);
		}
	}

	uint32 VectorBaseObject::get_length()
	{
		return m_length;
	}
	
	void VectorBaseObject::set_length(uint32 newLength)
	{
		if( m_fixed )
			toplevel()->throwRangeError(kVectorFixedError); 
		if (newLength > m_capacity)
		{
			grow(newLength);
		}
		m_length = newLength;
	}

	bool VectorBaseObject::get_fixed()
	{
		return m_fixed;
	}

	void VectorBaseObject::set_fixed(bool fixed)
	{
		m_fixed = fixed;
	}

	// Iterator support - for in, for each
	Atom VectorBaseObject::nextName(int index)
	{
		AvmAssert(index > 0);
		if (((uint32)index) <= m_length)
		{
			AvmCore *core = this->core();
			return core->intToAtom(index-1);
		}
		else
		{
			return nullStringAtom;
		}
	}
	Atom VectorBaseObject::nextValue(int index)
	{
		AvmAssert(index > 0);
		if (((uint32)index) <= m_length)
		{
			return getUintProperty(index-1);
		}
		else
		{
			return undefinedAtom;
		}
	}
	int VectorBaseObject::nextNameIndex(int index)
	{
		if (((uint32)index) < m_length)
		{
			return index + 1;
		}
		else
		{
			return 0;
		}
	}

	Atom VectorBaseObject::map (ScriptObject *callback, Atom thisObject)
	{
		AvmCore* core = this->core();
		VectorBaseObject *r = newVector(m_length);

		if (!callback)
			return r->atom();

		ScriptObject *d = this;
		uint32 len = m_length;

		// If thisObject is null, the call function will substitute the global object 
		Atom args[4] = { thisObject, nullObjectAtom, nullObjectAtom, this->atom() };

		for (uint32 i = 0; i < len; i++)
		{
			args[1] = d->getUintProperty (i); // element
			args[2] = core->uintToAtom (i); // index

			Atom result = callback->call(3, args);

			r->setUintProperty (i, result);
		}

		return r->atom();
	}

	Atom VectorBaseObject::filter(ScriptObject *callback, Atom thisObject)
	{
		AvmCore* core = this->core();
		VectorBaseObject *r = newVector();

		if (!callback)
			return r->atom();

		ScriptObject *d = this;
		uint32 len = m_length;

		// If thisObject is null, the call function will substitute the global object 
		Atom args[4] = { thisObject, nullObjectAtom, nullObjectAtom, this->atom() };

		for (uint32 i = 0, k = 0; i < len; i++)
		{
			args[1] = d->getUintProperty (i); // element
			args[2] = core->uintToAtom (i); // index

			Atom result = callback->call(3, args);

			if (result == trueAtom)
			{
				r->setUintProperty (k++, args[1]);
			}
		}

		return r->atom();
	}

	uint32 VectorBaseObject::push(Atom *argv, int argc)
	{
		if( m_fixed )
			toplevel()->throwRangeError(kVectorFixedError);
		grow(m_length + argc);
		for (int i=0; i < argc; i++) {
			setUintProperty(m_length, argv[i]);
		}
		return m_length;
	}

	//
	// IntVectorClass
	//

	BEGIN_NATIVE_MAP(IntVectorClass)
		NATIVE_METHOD(Vector_int_length_get,        IntVectorObject::get_length)
		NATIVE_METHOD(Vector_int_length_set,        IntVectorObject::set_length)
		NATIVE_METHOD(Vector_int_fixed_get,			IntVectorObject::get_fixed)
		NATIVE_METHOD(Vector_int_fixed_set,			IntVectorObject::set_fixed)
		NATIVE_METHOD_FLAGS(Vector_int_AS3_pop,		IntVectorObject::pop, 0)
		NATIVE_METHOD_FLAGS(Vector_int_AS3_push,		IntVectorObject::push, 0)
		NATIVE_METHOD_FLAGS(Vector_int_private__reverse,		IntVectorObject::_reverse, 0)
		NATIVE_METHOD_FLAGS(Vector_int_private__spliceHelper,		IntVectorObject::_spliceHelper, 0)
		NATIVE_METHOD(Vector_int_private__forEach,	ArrayClass::forEach)
		NATIVE_METHOD(Vector_int_private__every,	ArrayClass::every)
		NATIVE_METHOD(Vector_int_private__some,		ArrayClass::some)
		NATIVE_METHOD(Vector_int_private__sort,		ArrayClass::sort)
		NATIVE_METHOD_FLAGS(Vector_int_private__map,		IntVectorObject::map, 0)
		NATIVE_METHOD_FLAGS(Vector_int_private__filter,		IntVectorObject::filter, 0)
	END_NATIVE_MAP()

	IntVectorClass::IntVectorClass(VTable *vtable)
		: ClassClosure(vtable)
    {
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* IntVectorClass::createInstance(VTable *ivtable,
												 ScriptObject *prototype)
    {
        return new (core()->GetGC(), ivtable->getExtraSize()) IntVectorObject(ivtable, prototype);
    }

	VectorBaseObject* IntVectorObject::newVector(uint32 length)
	{
		VTable* ivtable = this->vtable;
		IntVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			IntVectorObject(ivtable, getDelegate());
		v->set_length(length);
		return v;
	}

	//
	// UIntVectorClass
	//

	BEGIN_NATIVE_MAP(UIntVectorClass)
		NATIVE_METHOD(Vector_uint_length_get,        UIntVectorObject::get_length)
		NATIVE_METHOD(Vector_uint_length_set,        UIntVectorObject::set_length)
		NATIVE_METHOD(Vector_uint_fixed_get,        UIntVectorObject::get_fixed)
		NATIVE_METHOD(Vector_uint_fixed_set,        UIntVectorObject::set_fixed)
		NATIVE_METHOD_FLAGS(Vector_uint_AS3_pop,		UIntVectorObject::pop, 0)
		NATIVE_METHOD_FLAGS(Vector_uint_AS3_push,		UIntVectorObject::push, 0)
		NATIVE_METHOD_FLAGS(Vector_uint_private__reverse,		UIntVectorObject::_reverse, 0)
		NATIVE_METHOD_FLAGS(Vector_uint_private__spliceHelper,		UIntVectorObject::_spliceHelper, 0)
		NATIVE_METHOD(Vector_uint_private__forEach, ArrayClass::forEach)
		NATIVE_METHOD(Vector_uint_private__every,	ArrayClass::every)
		NATIVE_METHOD(Vector_uint_private__some,		ArrayClass::some)
		NATIVE_METHOD(Vector_uint_private__sort,		ArrayClass::sort)
		NATIVE_METHOD_FLAGS(Vector_uint_private__map,		UIntVectorObject::map, 0)
		NATIVE_METHOD_FLAGS(Vector_uint_private__filter,		UIntVectorObject::filter, 0)
	END_NATIVE_MAP()

	UIntVectorClass::UIntVectorClass(VTable *vtable)
		: ClassClosure(vtable)
    {
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* UIntVectorClass::createInstance(VTable *ivtable,
												 ScriptObject *prototype)
    {
        return new (core()->GetGC(), ivtable->getExtraSize()) UIntVectorObject(ivtable, prototype);
    }

	VectorBaseObject* UIntVectorObject::newVector(uint32 length)
	{
		VTable* ivtable = this->vtable;
		UIntVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			UIntVectorObject(ivtable, getDelegate());
		v->set_length(length);
		return v;
	}

	//
	// DoubleVectorClass
	//

	BEGIN_NATIVE_MAP(DoubleVectorClass)
		NATIVE_METHOD(Vector_double_length_get,        DoubleVectorObject::get_length)
		NATIVE_METHOD(Vector_double_length_set,        DoubleVectorObject::set_length)
		NATIVE_METHOD(Vector_double_fixed_get,        DoubleVectorObject::get_fixed)
		NATIVE_METHOD(Vector_double_fixed_set,        DoubleVectorObject::set_fixed)
		NATIVE_METHOD_FLAGS(Vector_double_AS3_pop,		DoubleVectorObject::pop, 0)
		NATIVE_METHOD_FLAGS(Vector_double_AS3_push,		DoubleVectorObject::push, 0)
		NATIVE_METHOD_FLAGS(Vector_double_private__reverse,		DoubleVectorObject::_reverse, 0)
		NATIVE_METHOD_FLAGS(Vector_double_private__spliceHelper,		DoubleVectorObject::_spliceHelper, 0)
		NATIVE_METHOD(Vector_double_private__forEach, ArrayClass::forEach)
		NATIVE_METHOD(Vector_double_private__every,	ArrayClass::every)
		NATIVE_METHOD(Vector_double_private__some,		ArrayClass::some)
		NATIVE_METHOD(Vector_double_private__sort,		ArrayClass::sort)
		NATIVE_METHOD_FLAGS(Vector_double_private__map,		DoubleVectorObject::map, 0)
		NATIVE_METHOD_FLAGS(Vector_double_private__filter,		DoubleVectorObject::filter, 0)
	END_NATIVE_MAP()

	DoubleVectorClass::DoubleVectorClass(VTable *vtable)
		: ClassClosure(vtable)
   { 
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* DoubleVectorClass::createInstance(VTable *ivtable,
												   ScriptObject *prototype)
    {
        return new (core()->GetGC(), ivtable->getExtraSize()) DoubleVectorObject(ivtable, prototype);
    }

	VectorBaseObject* DoubleVectorObject::newVector(uint32 length)
	{
		VTable* ivtable = this->vtable;
		DoubleVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			DoubleVectorObject(ivtable, getDelegate());
		v->set_length(length);
		return v;
	}

	//
	// ObjectVectorClass
	//

	BEGIN_NATIVE_MAP(ObjectVectorClass)
		NATIVE_METHOD_FLAGS(Vector_object_length_get,        ObjectVectorObject::get_length, 0)
		NATIVE_METHOD_FLAGS(Vector_object_length_set,        ObjectVectorObject::set_length, 0)
		NATIVE_METHOD_FLAGS(Vector_object_private_type_set,        ObjectVectorObject::set_type, 0)
		NATIVE_METHOD_FLAGS(Vector_object_private_type_get,        ObjectVectorObject::get_type, 0)
		NATIVE_METHOD_FLAGS(Vector_object_fixed_set,        ObjectVectorObject::set_fixed, 0)
		NATIVE_METHOD_FLAGS(Vector_object_fixed_get,        ObjectVectorObject::get_fixed, 0)
		NATIVE_METHOD_FLAGS(Vector_object_AS3_pop,		ObjectVectorObject::pop, 0)
		NATIVE_METHOD_FLAGS(Vector_object_AS3_push,		ObjectVectorObject::push, 0)
		NATIVE_METHOD_FLAGS(Vector_object_private__reverse,		ObjectVectorObject::_reverse, 0)
		NATIVE_METHOD_FLAGS(Vector_object_private__spliceHelper,		ObjectVectorObject::_spliceHelper, 0)
		NATIVE_METHOD(Vector_object_private__forEach, ArrayClass::forEach)
		NATIVE_METHOD(Vector_object_private__every,	ArrayClass::every)
		NATIVE_METHOD(Vector_object_private__some,		ArrayClass::some)
		NATIVE_METHOD(Vector_object_private__sort,		ArrayClass::sort)
		NATIVE_METHOD_FLAGS(Vector_object_private__map,		ObjectVectorObject::map, 0)
		NATIVE_METHOD_FLAGS(Vector_object_private__filter,		ObjectVectorObject::filter, 0)
	END_NATIVE_MAP()

	ObjectVectorClass::ObjectVectorClass(VTable *vtable)
		: ClassClosure(vtable)
    {
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* ObjectVectorClass::createInstance(VTable *ivtable,
												   ScriptObject *prototype)
    {
        return new (core()->GetGC(), ivtable->getExtraSize()) ObjectVectorObject(ivtable, prototype);
    }

	Atom ObjectVectorObject::getUintProperty(uint32 index) const
	{
		return _getUintProperty(index);
	}
	Atom ObjectVectorObject::_getUintProperty(uint32 index) const
	{
		if (m_length <= index)
		{
			toplevel()->throwRangeError(kOutOfRangeError, core()->uintToString(index), core()->uintToString(m_length));
		}
		else
		{
			return m_array[index];
		}
		return 0;
	}
	
	void ObjectVectorObject::setUintProperty(uint32 index, Atom value)
	{
		return _setUintProperty(index, value);
	}
	void ObjectVectorObject::_setUintProperty(uint32 index, Atom value)
	{
		if (m_length <= index)
		{
			if( index > m_length || m_fixed )
				toplevel()->throwRangeError(kOutOfRangeError, core()->uintToString(index), core()->uintToString(m_length));
			set_length(index+1);
		}
		WBATOM( MMgc::GC::GetGC(m_array), m_array, m_array + index, toplevel()->coerce(value, t->traits()->itraits));
	}			

	Atom ObjectVectorObject::_getIntProperty(int index) const
	{
		if (index >= 0) 
			return _getUintProperty(index);
		else 
			toplevel()->throwRangeError(kOutOfRangeError, core()->intToString(index), core()->uintToString(m_length));
		return 0;
	}

	void ObjectVectorObject::_setIntProperty(int index, Atom value)
	{
		if (index >= 0) 
			_setUintProperty(index, value);
		else 
			toplevel()->throwRangeError(kOutOfRangeError, core()->intToString(index), core()->uintToString(m_length));
	}

	void ObjectVectorObject::set_length(uint32 newLength)
	{
		if (newLength > m_length)
		{
			if( m_fixed )
				toplevel()->throwRangeError(kVectorFixedError);

			grow(newLength);
		}
		else if( newLength < m_length)
		{
			if( m_fixed )
				toplevel()->throwRangeError(kVectorFixedError);

			memset(m_array+newLength, 0, (m_length-newLength)*sizeof(Atom));
			//_spliceHelper (newLength, 0, (m_length - newLength), 0, 0);
		}
		m_length = newLength;
	}

	void ObjectVectorObject::set_type(Atom a)
	{
		this->t = AvmCore::atomToScriptObject(a);
	}

	Atom ObjectVectorObject::get_type()
	{
		return t->atom();
	}

	void ObjectVectorObject::grow(uint32 newCapacity)
	{
		if (newCapacity > m_capacity)
		{
			newCapacity = newCapacity + (newCapacity >>2);
			//newCapacity = ((newCapacity+kGrowthIncr)/kGrowthIncr)*kGrowthIncr;
			GC* gc = GC::GetGC(this);
			Atom* newArray = (Atom*) gc->Calloc(newCapacity, sizeof(Atom), GC::kContainsPointers|GC::kZero);
			Atom* oldAtoms = m_array;
			if (!newArray)
			{
				toplevel()->throwError(kOutOfMemoryError);
			}
			if (m_array)
			{
				memcpy(newArray, m_array, m_length * sizeof(Atom));
				memset(oldAtoms, 0, m_length*sizeof(Atom));
				gc->Free(oldAtoms);
			}
			m_array = newArray;
			m_capacity = newCapacity;
		}
	}

	VectorBaseObject* ObjectVectorObject::newVector(uint32 length)
	{
		VTable* ivtable = this->vtable;
		ObjectVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			ObjectVectorObject(ivtable, getDelegate());

		v->set_type(t->atom());
		v->set_length(length);

		return v;
	}

	void ObjectVectorObject::_spliceHelper(uint32 insertPoint, uint32 insertCount, uint32 deleteCount, Atom args, int offset)
	{
		long l_shiftAmount = (long)insertCount - (long) deleteCount; // long because result could be negative

		grow(m_length + l_shiftAmount);

		Atom *arr = m_array;

		ScriptObject* so_args = (args&7)==kObjectType ?  AvmCore::atomToScriptObject(args) : 0;
		ObjectVectorObject* vec_args = isVector(args);

		if (l_shiftAmount < 0) 
		{
			int numberBeingDeleted = -l_shiftAmount;

			// shift elements down
			int toMove = m_length - insertPoint - deleteCount;
			memmove (arr + insertPoint + insertCount, arr + insertPoint + deleteCount, toMove * sizeof(Atom));

			memset (arr + m_length - numberBeingDeleted, 0, numberBeingDeleted * sizeof(Atom));
		}
		else if (l_shiftAmount > 0)
		{
			memmove (arr + insertPoint + l_shiftAmount, arr + insertPoint, (m_length - insertPoint) * sizeof(Atom));
			//clear for gc purposes
			memset (arr + insertPoint, 0, l_shiftAmount * sizeof(Atom));
		}

		set_length(m_length + l_shiftAmount);

		// Add the items to insert
		if (insertCount)
		{
			if( vec_args && (offset+insertCount <= vec_args->m_length) )
			{
				Atom* a = vec_args->m_array;
				for (uint32 i=0; i<insertCount; i++)
				{
					_setUintProperty(insertPoint+i, a[i+offset]);
				}
			}
			else if( so_args )
			{
				for (uint32 i=0; i<insertCount; i++)
				{
					//setUintProperty(insertPoint+i, so_args->getUintProperty(i+offset));
					_setUintProperty(insertPoint+i, so_args->getUintProperty(i+offset));
				}
			}
		}

		return;
	}

	Atom ObjectVectorObject::pop()
	{
		if(m_fixed)
			toplevel()->throwRangeError(kVectorFixedError);
		if(m_length)
		{
			uint32 l = m_length-1;
			Atom r = m_array[l];
			set_length(m_length-1);
			return r;
		}
		return undefinedAtom;
	}
}
