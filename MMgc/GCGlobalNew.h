/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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

#ifndef __GCGLOBALNEW__
#define __GCGLOBALNEW__

#ifdef MMGC_ENABLE_CPP_EXCEPTIONS
  #define MMGC_NEW_THROWS_CLAUSE throw (std::bad_alloc)
  #define MMGC_DELETE_THROWS_CLAUSE throw ()
#else
  #define MMGC_NEW_THROWS_CLAUSE 
  #define MMGC_DELETE_THROWS_CLAUSE 
#endif

namespace MMgc
{
	void *AllocCall(size_t, FixedMallocOpts opts=kNone);
	void DeleteCall(void *);

#ifdef MMGC_USE_SYSTEM_MALLOC
	/**
	 * Allocate memory from the system heap using VMPI_alloc, with options.
	 * @param size  the size in bytes of the request
	 * @param opts  an options bit vector
	 * @return      a pointer to a suitable memory area.  NULL only if kCanFail is part of
	 *              opts.  The memory is zeroed only of kZero is part of opts.
	 * @note If memory cannot be allocated and kCanFail is not part of opts then the regular
	 *       OOM handling is run, in the hope that this will free some memory on the system
	 *       heap as well.  If memory is not available on a second allocation attempt then
	 *       the system will enter the abort state.
	 */
	void *SystemNew(size_t size, FixedMallocOpts opts);
	
	/**
	 * Free memory allocated with SystemNew.  p may be NULL.
	 */
	void SystemDelete(void* p);
#endif

	REALLY_INLINE void *AllocCallInline(size_t size, FixedMallocOpts opts=kNone)
	{
#ifdef MMGC_USE_SYSTEM_MALLOC
		return SystemNew(size, opts);
#else
		return FixedMalloc::GetFixedMalloc()->OutOfLineAlloc(size, opts);
#endif
	}

	REALLY_INLINE void DeleteCallInline(void *p)
	{
#ifdef MMGC_USE_SYSTEM_MALLOC
		SystemDelete(p);
#else
		FixedMalloc::GetFixedMalloc()->OutOfLineFree(p);
#endif
	}
};

#ifdef MMGC_OVERRIDE_GLOBAL_NEW

// Global operator new and delete implementations to allocate/free from FixedMalloc.
// Using these may create a problem if compiled with system (OS) headers that also use the default
// new & delete. This happens for example in ATL of the Windows ActiveX builds. Also, out of memory 
// handling will release everything allocated with FixedMalloc when abort due to OOM occurs. If
// things in the system headers/plugin interface/platform globals are allocated with these, it will
// result most likely in a crash. By using the GCAllocObject you can try to go around some of these
// issues, but atleast to system headers may pose a problem.


// User-defined operator new.
REALLY_INLINE void *operator new(size_t size) MMGC_NEW_THROWS_CLAUSE 
{ 
#ifdef MMGC_USE_SYSTEM_MALLOC
	return MMgc::SystemNew(size, MMgc::kNone);
#else
	return MMgc::FixedMalloc::GetFixedMalloc()->OutOfLineAlloc(size, MMgc::kNone);
#endif
}

REALLY_INLINE void *operator new(size_t size, MMgc::FixedMallocOpts opts) MMGC_NEW_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	return MMgc::SystemNew(size, opts);
#else
	return MMgc::FixedMalloc::GetFixedMalloc()->OutOfLineAlloc(size, opts);
#endif	
}

REALLY_INLINE void *operator new[](size_t size) MMGC_NEW_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	return MMgc::SystemNew(size, MMgc::kNone);
#else
	return MMgc::FixedMalloc::GetFixedMalloc()->OutOfLineAlloc(size, MMgc::kNone);
#endif
}

REALLY_INLINE void *operator new[](size_t size, MMgc::FixedMallocOpts opts) MMGC_NEW_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	return MMgc::SystemNew(size, opts);
#else
	return MMgc::FixedMalloc::GetFixedMalloc()->OutOfLineAlloc(size, opts);
#endif		
}

// User-defined operator delete.
REALLY_INLINE void operator delete( void *p) MMGC_DELETE_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	MMgc::SystemDelete(p);
#else
	MMgc::FixedMalloc::GetFixedMalloc()->OutOfLineFree(p);
#endif	
}

REALLY_INLINE void operator delete[]( void *p ) MMGC_DELETE_THROWS_CLAUSE
{
#ifdef MMGC_USE_SYSTEM_MALLOC
	MMgc::SystemDelete(p);
#else
	MMgc::FixedMalloc::GetFixedMalloc()->OutOfLineFree(p);
#endif	
}

// map these to nothingness
#define MMGC_DECLARE_OPERATOR_DELETES_FOR_CLASS 
#define MMGC_DECLARE_SPECIALIZED_DESTRUCTORCALL_TEMPLATES( TYPE )
#define MMGC_DECLARE_GLOBAL_DELETE_FNCS_AS_FRIEND( TYPE )
#define MMGC_USING_DELETE_OPERATOR( TYPE )

#else /* MMGC_OVERRIDE_GLOBAL_NEW */

// Defines allocation and deallocation functions used by allocation and deallocation macros.
// operator new and new[] have a specialized signature by having an ignored MMgc::kUseFixedMalloc parameter.
// Specialized operator delete and delete[] are provided to get rid of compiler warnings.

void* operator new(size_t size, MMgc::NewDummyOperand /*ignored*/) MMGC_NEW_THROWS_CLAUSE;
void *operator new(size_t size, MMgc::NewDummyOperand /*ignored*/, MMgc::FixedMallocOpts opts) MMGC_NEW_THROWS_CLAUSE;

// Empty deletes to get rid of warnings
// has impl for solaris (maybe solaris is generating C++ exception based delete calls?)
REALLY_INLINE void operator delete(void *, MMgc::NewDummyOperand /* ignored */) MMGC_DELETE_THROWS_CLAUSE { GCAssert(false); }

// b/c we need to use the fancy template routines for new[] these arent used
//void* operator new[](size_t size, size_t arraySize, MMgc::NewDummyOperand /*ignored*/) MMGC_NEW_THROWS_CLAUSE;
//void* operator new[](size_t size, size_t arraySize, MMgc::NewDummyOperand /*ignored*/, MMgc::FixedMallocOpts opts) NEW_THROWS_CLAUSE;
//void operator delete[](void *p, MMgc::NewDummyOperand /* ignored */) MMGC_DELETE_THROWS_CLAUSE;

namespace MMgc
{

#ifdef MMGC_DELETE_DEBUGGING
	// Helper functions to check whether we are releasing a pointer with the right delete.
	void VerifyScalarDelete(void* p);
	void VerifyVectorDelete(void* p, bool primitive);
#define mmgc_debug_only(_x) _x
#else
#define mmgc_debug_only(_x) 
#endif //MMGC_DELETE_DEBUGGING

	// The operator new is defined also in a library code and they inline this implementation to be the function body.
	REALLY_INLINE void* NewCall(size_t size, FixedMallocOpts opts=kNone);

	void* NewArrayCalloc(size_t size, size_t count, FixedMallocOpts opts, bool isPrimitive);

	void DeleteFunc(void *);
	void DeleteArrayFunc(void *);

	void SimpleDestructorCall(void* p);
	void SimpleDestructorArrayCall(void* p, bool primitive);
};

	template <class T>
	T *MMgcNewArrayCall(T* /*dummy template arg*/, size_t count, MMgc::FixedMallocOpts opts)
	{
		size_t *p = (size_t*) MMgc::NewArrayCalloc(sizeof(T), count, opts, false /* !isPrimitive */);
		if(!p && (opts & MMgc::kCanFail) != 0)
			return NULL;
		*p = count;
		p++;
		T *tp = (T*)p;
		for(size_t i=count; i>0; i--, tp++) {
			new ((void*)tp) T;
		}	
		return (T*)p;
	}

#define DECLARE_PRIM_ARRAY_NEW(_x)										\
	template <> REALLY_INLINE _x *MMgcNewArrayCall(_x*, size_t count, MMgc::FixedMallocOpts opts) \
	{ return (_x*)MMgc::NewArrayCalloc(sizeof(_x), count, opts, true /* isPrimitive */); }

	// Scalar delete mechanism. First calls the destructor and then deletefunc to release the memory.
	template <typename T> REALLY_INLINE void MMgcDestructorCall( T* mem )
	{
		if( mem )
		{
			mmgc_debug_only(MMgc::VerifyScalarDelete(mem);)
			//	Call destructor first and then release memory
			mem->~T();
			MMgc::DeleteFunc( mem );
		}
	}

	//	Vector delete mechanism
	template <typename T> REALLY_INLINE void MMgcDestructorArrayCall( T* mem )
	{
		if( mem )
		{
			mmgc_debug_only(MMgc::VerifyVectorDelete(mem, false);)

			// We need to check whether compiler added its own cookie. If we go back 4 bytes and find our guard there
			// compiler did not add any cookie. Otherwise it added a cookie. The cookie is the sizeof(size_t).
			size_t* w = (size_t*)mem;

			w--;

			size_t numObj = *(size_t*)w;

			register T* p = mem;
			p += numObj;

			while ( p > mem )
			{
				p--;
				p->~T();
			}
			MMgc::DeleteArrayFunc( mem );
		}
	}

#define DECLARE_PRIM_ARRAY_DELETE(_x)									\
	template <> REALLY_INLINE void MMgcDestructorArrayCall( _x* mem )		\
	{ MMgc::SimpleDestructorArrayCall( mem, true ); }							\
	template <> REALLY_INLINE void MMgcDestructorCall(_x *mem) { MMgc::SimpleDestructorCall(mem); }


#define DECLARE_PRIM_ARRAY(_x)					\
	DECLARE_PRIM_ARRAY_NEW(_x)					\
	DECLARE_PRIM_ARRAY_DELETE(_x)				\

	//	Specialized function templates, for built-in types so that we
	//	don't call destructor and add extra overhead
	DECLARE_PRIM_ARRAY(uint8_t)
	DECLARE_PRIM_ARRAY(int8_t)
#ifdef __GNUC__
	// msvc correctly treats char and uint8_t as the same but gcc doesn't
	DECLARE_PRIM_ARRAY(char)
#endif		
	DECLARE_PRIM_ARRAY(uint16_t)		
	DECLARE_PRIM_ARRAY(int16_t)		
	DECLARE_PRIM_ARRAY(uint32_t)		
	DECLARE_PRIM_ARRAY(int32_t)		
	DECLARE_PRIM_ARRAY(uint64_t)		
	DECLARE_PRIM_ARRAY(int64_t)	
	DECLARE_PRIM_ARRAY(void*)	
	DECLARE_PRIM_ARRAY(void**)

	template <> REALLY_INLINE void *MMgcNewArrayCall(void*, size_t count, MMgc::FixedMallocOpts opts) \
	{ return (void*)MMgc::NewArrayCalloc(sizeof(void*), count, opts, true /* isPrimitive */); }
	DECLARE_PRIM_ARRAY_DELETE(void)

#undef DECLARE_PRIM_ARRAY_NEW
#undef DECLARE_PRIM_ARRAY_DELETE
#undef DECLARE_PRIM_ARRAY

#ifdef __GNUC__
	// G++ pukes on the ::, MSC requires them

// If a class has private destructor adding this macro will allow the delete mechanisms to call that.
#define MMGC_DECLARE_GLOBAL_DELETE_FNCS_AS_FRIEND( TYPE )	\
	friend void MMgcDestructorCall<>( TYPE* );			\
	friend void MMgcDestructorArrayCall<>( TYPE* );

#else

// If a class has private destructor adding this macro will allow the delete mechanisms to call that.
#define MMGC_DECLARE_GLOBAL_DELETE_FNCS_AS_FRIEND( TYPE )	\
	friend void ::MMgcDestructorCall<>( TYPE* );			\
	friend void ::MMgcDestructorArrayCall<>( TYPE* );

#endif

// this is necessary for the friend calls above to resolve properly w GCC
//using namespace MMgc;

// If a class is a base class for multiple inheritance or virtual inheritance, it may need to define 
// these macros (MMGC_DECLARE_OPERATOR_DELETES_FOR_CLASS) inside the class definition to create a class specific delete, 
// and MMGC_DECLARE_SPECIALIZED_DESTRUCTORCALL_TEMPLATES outside the class definition to have specialized function 
// template for the destructor.
// This is done in cases where the pointer to be destructed is actually the pointer of a non-first base class. 
#define MMGC_DECLARE_SPECIALIZED_DESTRUCTORCALL_TEMPLATES( TYPE ) \
	MMGC_DECLARE_SPECIALIZED_DESTRUCTORCALL_TEMPLATE( TYPE ) \
	MMGC_DECLARE_SPECIALIZED_DESTRUCTORARRAYCALL_TEMPLATE( TYPE )

#define MMGC_DECLARE_SPECIALIZED_DESTRUCTORCALL_TEMPLATE( TYPE )		\
	template <> REALLY_INLINE void MMgcDestructorCall( TYPE* mem ) { if(mem) delete mem; } 

#define MMGC_DECLARE_SPECIALIZED_DESTRUCTORARRAYCALL_TEMPLATE( TYPE )	\
	template <> REALLY_INLINE void MMgcDestructorArrayCall( TYPE* mem ) { if(mem) delete[] mem; }

// These dont need to call destructors as the operator delete will do that automatically for us.
#define MMGC_DECLARE_OPERATOR_DELETES_FOR_CLASS \
	MMGC_DECLARE_SCALAR_DELETE_FOR_CLASS \
	MMGC_DECLARE_VECTOR_DELETE_FOR_CLASS

#define MMGC_DECLARE_SCALAR_DELETE_FOR_CLASS \
	void operator delete(void* p) { MMgc::SimpleDestructorCall(p); }

#define MMGC_DECLARE_VECTOR_DELETE_FOR_CLASS \
	void operator delete[](void* p) { MMgc::SimpleDestructorArrayCall(p, false); }

// If a class derives from multiple baseclasses that define delete operator, this can be used to
// select with one to use. 
#define MMGC_USING_DELETE_OPERATOR( TYPE ) \
	using TYPE::operator delete

#ifndef MMGC_OVERRIDE_NEWDELETE_DEBUGGING
//#define MMGC_OVERRIDE_NEWDELETE_DEBUGGING
#endif 

#ifdef MMGC_OVERRIDE_NEWDELETE_DEBUGGING
// These help to track where global operator new/delete/new[]/delete[] are used in compile time in MSVC.
// If you compile the project with /EHsc /Ob1 /W4 flags and compile. This will generate C4714 warnings 
// (forceinline failed) for places where these operators are used. So far the try catch seems to be the
// way to do this, but for loops are supposed to generate that as well. May not be turned on on builds that 
// are to be executed. 
REALLY_INLINE void *operator new(size_t size) MMGC_NEW_THROWS_CLAUSE
{
	(void)size;	GCAssert(false);

	/*
	try
	{
	}
	catch (...)
	{
	}*/
	return (void*)-1;
}

REALLY_INLINE void *operator new[](size_t size) MMGC_NEW_THROWS_CLAUSE
{
	(void)size;GCAssert(false);
	/*
	try
	{
	}
	catch (...)
	{
	}*/
	return (void*)-1;
}

// User-defined operator delete.
REALLY_INLINE void operator delete( void *p) MMGC_DELETE_THROWS_CLAUSE
{
	(void)p;
	GCAssert(false); /*
					 try
					 {
					 }
					 catch (...)
					 {
					 }*/
}

REALLY_INLINE void operator delete[]( void *p ) MMGC_DELETE_THROWS_CLAUSE
{
	(void)p;
	GCAssert(false);/*
					try
					{
					}
					catch (...)
					{
					}*/
}
#endif // MMGC_OVERRIDE_NEWDELETE_DEBUGGING

#endif /* MMGC_OVERRIDE_GLOBAL_NEW */

#endif // __GCGLOBALNEW__
