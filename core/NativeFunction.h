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


#ifndef __avmplus_NativeFunction__
#define __avmplus_NativeFunction__

namespace avmplus
{

#ifdef AVMTHUNK_VERSION

	#define kAvmThunkNull		nullObjectAtom
	#define kAvmThunkUndefined	undefinedAtom

	#define kAvmThunkInfinity		(MathUtils::infinity())
	#define kAvmThunkNegInfinity	(MathUtils::neg_infinity())
	#define kAvmThunkNaN			(MathUtils::nan())
	
	#define AvmToRetType_AvmObject(r)		(error ??? illegal)
	#define AvmToRetType_AvmBoolArg(r)		AvmBox(r)
	#define AvmToRetType_int32_t(r)			AvmBox(r)
	#define AvmToRetType_uint32_t(r)		AvmBox(r)
	#define AvmToRetType_AvmNamespace(r)	AvmBox(r)
	#define AvmToRetType_AvmBox(r)			AvmBox(r)
	#define AvmToRetType_AvmString(r)		AvmBox(r)
	#define AvmToRetType_void(r)			(kAvmThunkUndefined)
	#define AvmToRetType_double(r)			(r)

	typedef AvmObject		AvmRetType_AvmObject;
	typedef bool			AvmRetType_AvmBoolArg;	// bools are passed in as int32, but returned as bool, for historic reasons
	typedef int32_t			AvmRetType_int32_t;
	typedef uint32_t		AvmRetType_uint32_t;
	typedef AvmNamespace	AvmRetType_AvmNamespace;
	typedef AvmBox			AvmRetType_AvmBox;
	typedef AvmString		AvmRetType_AvmString;
	typedef void			AvmRetType_void;
	typedef double			AvmRetType_double;

	typedef avmplus::ScriptObject AvmObjectT;
	typedef avmplus::String AvmStringT;
	typedef avmplus::Namespace AvmNamespaceT;

	// yuck. could probably get around this with variadic macros, but it's not clear if every target compiler
	// we need to support will support them fully.
	#define AVMTHUNK_CALL_FUNCTION_0(func, ret, argt0, argv0) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)())(func)))())

	#define AVMTHUNK_CALL_FUNCTION_1(func, ret, argt0, argv0, argt1, argv1) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1))(func)))(argv1))

	#define AVMTHUNK_CALL_FUNCTION_2(func, ret, argt0, argv0, argt1, argv1, argt2, argv2) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2))(func)))(argv1, argv2))

	#define AVMTHUNK_CALL_FUNCTION_3(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3))(func)))(argv1, argv2, argv3))

	#define AVMTHUNK_CALL_FUNCTION_4(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3, argt4, argv4) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3, argt4))(func)))(argv1, argv2, argv3, argv4))

	#define AVMTHUNK_CALL_FUNCTION_5(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3, argt4, argv4, argt5, argv5) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3, argt4, argt5))(func)))(argv1, argv2, argv3, argv4, argv5))

	#define AVMTHUNK_CALL_FUNCTION_6(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3, argt4, argv4, argt5, argv5, argt6, argv6) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3, argt4, argt5, argt6))(func)))(argv1, argv2, argv3, argv4, argv5, argv6))

	#define AVMTHUNK_CALL_FUNCTION_7(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3, argt4, argv4, argt5, argv5, argt6, argv6, argt7, argv7) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3, argt4, argt5, argt6, argt7))(func)))(argv1, argv2, argv3, argv4, argv5, argv6, argv7))

	#define AVMTHUNK_CALL_FUNCTION_8(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3, argt4, argv4, argt5, argv5, argt6, argv6, argt7, argv7, argt8, argv8) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3, argt4, argt5, argt6, argt7, argt8))(func)))(argv1, argv2, argv3, argv4, argv5, argv6, argv7, argv8))

	#define AVMTHUNK_CALL_FUNCTION_9(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3, argt4, argv4, argt5, argv5, argt6, argv6, argt7, argv7, argt8, argv8, argt9, argv9) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3, argt4, argt5, argt6, argt7, argt8, argt9))(func)))(argv1, argv2, argv3, argv4, argv5, argv6, argv7, argv8, argv9))

	#define AVMTHUNK_CALL_FUNCTION_10(func, ret, argt0, argv0, argt1, argv1, argt2, argv2, argt3, argv3, argt4, argv4, argt5, argv5, argt6, argv6, argt7, argv7, argt8, argv8, argt9, argv9, argt10, argv10) \
		((*(argv0).*((AvmRetType_##ret (argt0##T::*)(argt1, argt2, argt3, argt4, argt5, argt6, argt7, argt8, argt9, argt10))(func)))(argv1, argv2, argv3, argv4, argv5, argv6, argv7, argv8, argv9, argv10))
	
	// add more as needed, 10 args is not a hard limit
	
	#define AvmThunkUnbox_AvmObject(r)		((ScriptObject*)(r))
	#define AvmThunkUnbox_AvmBoolArg(r)		((r) != 0)
	#define AvmThunkUnbox_int32_t(r)		int32_t(r)
	#define AvmThunkUnbox_uint32_t(r)		uint32_t(r)
	#define AvmThunkUnbox_AvmNamespace(r)	((Namespace*)(r))
	#define AvmThunkUnbox_AvmBox(r)			(r)
	#define AvmThunkUnbox_AvmString(r)		((String*)(r))
	#define AvmThunkUnbox_void(r)			(error ??? illegal)
	#define AvmThunkUnbox_double(r)			AvmThunkUnbox_double_impl(&(r))

	#define AvmThunkArgSize_AvmObject		1
	#define AvmThunkArgSize_AvmBoolArg		1
	#define AvmThunkArgSize_int32_t			1
	#define AvmThunkArgSize_uint32_t		1
	#define AvmThunkArgSize_AvmNamespace	1
	#define AvmThunkArgSize_AvmBox			1
	#define AvmThunkArgSize_AvmString		1
	#define AvmThunkArgSize_void			(error ??? illegal)
#ifdef AVMPLUS_64BIT
	#define AvmThunkArgSize_double			1
#else
	#define AvmThunkArgSize_double			2
#endif
	
	inline double AvmThunkUnbox_double_impl(const AvmBox* b)
	{
	#if defined(AVMPLUS_64BIT)
		AvmAssert(sizeof(AvmBox) == sizeof(double));
		return *(const double*)b;
	#elif defined(AVMPLUS_UNALIGNED_ACCESS)
		AvmAssert(sizeof(AvmBox)*2 == sizeof(double));
		return *(const double*)b;
	#else
		AvmAssert(sizeof(AvmBox)*2 == sizeof(double));
		union {
			double d;
			AvmBox b[2];
		} u;
		// @todo, does this need endian attention?
		u.b[0] = b[0];
		u.b[1] = b[1];
		return u.d;
	#endif
	}

	// trick, since values are compile-time known we usually don't need to call intToAtom, can statically transform them
	// good for ints and ints currently
	#define AvmThunkCanBeSmallIntAtom(v)	(!((v) & 0xF0000000))
	#define AvmThunkSmallIntAtom(v)			((((Atom)(v))<<3) | kIntegerType)
		
	// note, this isn't complete -- only the ones currently needed are defined.
	// expand as necessary. macros to take advantage of the fact that most
	// args are compile-time constants.
	#define AvmThunkCoerce_int32_t_double(v)	double(v)
	#define AvmThunkCoerce_int32_t_uint32_t(v)	uint32_t(v)
	#define AvmThunkCoerce_int32_t_AvmBox(v)	(AvmThunkCanBeSmallIntAtom(v) ? AvmThunkSmallIntAtom(v) : env->core()->intAtom(v))

	#define AvmThunkCoerce_uint32_t_double(v)	double(v)
	#define AvmThunkCoerce_uint32_t_int32_t(v)	int32_t(v)
	#define AvmThunkCoerce_uint32_t_AvmBox(v)	(AvmThunkCanBeSmallIntAtom(v) ? AvmThunkSmallIntAtom(v) : env->core()->intAtom(v))

	#define AvmThunkCoerce_AvmBoolArg_AvmBox(v)	((v) ? trueAtom : falseAtom)

#ifdef _DEBUG
	inline double AvmThunkCoerce_AvmBox_double(AvmBox v) { AvmAssert((v) == kAvmThunkUndefined); (void)v; return kAvmThunkNaN; }
	inline AvmString AvmThunkCoerce_AvmBox_AvmString(AvmBox v) { AvmAssert((v) == kAvmThunkUndefined || (v) == kAvmThunkNull); (void)v; return NULL; }
	inline AvmObject AvmThunkCoerce_AvmBox_AvmObject(AvmBox v) { AvmAssert((v) == kAvmThunkUndefined || (v) == kAvmThunkNull); (void)v; return NULL; }
#else
	#define AvmThunkCoerce_AvmBox_double(v)		(kAvmThunkNaN)
	#define AvmThunkCoerce_AvmBox_AvmString(v)	(NULL)
	#define AvmThunkCoerce_AvmBox_AvmObject(v)	(NULL)
#endif

	#define AvmThunkCoerce_AvmString_AvmBox(v)	((v) ? (v)->atom() : nullStringAtom)

	#define AvmThunkConstant_AvmString(v)		(env->method->pool->cpool_string[v])
	
	typedef void (ScriptObject::*AvmThunkNativeHandler)();

	#define AVMTHUNK_GET_HANDLER(env)	(static_cast<NativeMethod*>((env)->method)->nte.handler)
	#define AVMTHUNK_GET_COOKIE(env)	(static_cast<NativeMethod*>((env)->method)->nte.cookie)

#ifdef DEBUGGER
	#define AVMTHUNK_DEBUG_ENTER(env)	CallStackNode csn(0); (env)->debugEnter(argc, (uint32_t*)argv, 0, 0, &csn, 0, 0); 
	#define AVMTHUNK_DEBUG_EXIT(env)	(env)->debugExit(&csn);
#else
	#define AVMTHUNK_DEBUG_ENTER(env)	
	#define AVMTHUNK_DEBUG_EXIT(env)	
#endif

#endif

	/**
	 * The NativeMethod class is a wrapper to bind a native C++ function
	 * to a class method surfaced into the ActionScript world.
	 * The class method must be defined with the "native" attribute.
	 *
	 * NativeMethod uses C++ calling conventions when calling the
	 * native C++ code.  Incoming parameters are coerced to the
	 * proper type before the call as follows:
	 *
	 * AS type         C++ type
	 * -------         --------
	 * Void            Atom, if parameter, void if return type
	 * Object          Atom
	 * Boolean         bool
	 * Number          double
	 * String          Stringp (String *)
	 * Class           ClassClosure*
	 * MovieClip       MovieClipObject*   (similar for any other class)
	 */
	class NativeMethod : public AbstractFunction
	{
	public:
#ifdef AVMTHUNK_VERSION
		NativeMethod(const NativeTableEntry& nte);
#else
		typedef void (ScriptObject::*Handler)();
		NativeMethod(int flags, Handler handler, int cookie);
#endif
		
		// we have virtual functions, so we probably need a virtual dtor
		virtual ~NativeMethod() {}

		static Atom verifyEnter(MethodEnv* env, int argc, uint32 *ap);

		virtual void verify(Toplevel* toplevel);

	// ------------------------ DATA SECTION BEGIN
	public:
#ifdef AVMTHUNK_VERSION
		const NativeTableEntry& nte;
#else
		union {
			Handler m_handler;
			uintptr m_handler_addr;
		};
		int m_cookie;
#endif
	// ------------------------ DATA SECTION END
	};

	/**
	 * NativeTableEntry is an internal structure used for native
	 * method tables.  It is wrapped by the NATIVE_METHOD() macros
	 * below.
	 */
	struct NativeTableEntry
	{
	// ------------------------ DATA SECTION BEGIN
	public:
#ifdef AVMTHUNK_VERSION
		AvmThunkNativeThunker thunker;
		AvmThunkNativeHandler handler;
#else
		typedef void (ScriptObject::*Handler)();
		Handler handler;
#endif
		int32_t method_id;
		int32_t cookie;
		int32_t flags;
	// ------------------------ DATA SECTION END
	};

	/**
	 * Macros for declaring native methods
	 */
	#define BEGIN_NATIVE_MAP(_Class) \
		NativeTableEntry _Class::natives[] = {
			
	#define DECLARE_NATIVE_MAP(_Class) \
		static ClassClosure* createClassClosure(VTable* cvtable) \
		{ return new (cvtable->gc(), cvtable->getExtraSize()) _Class(cvtable); } \
		static NativeTableEntry natives[];

	#define DECLARE_NATIVE_SCRIPT(_Script) \
		static ScriptObject* createGlobalObject(VTable* vtable, ScriptObject* delegate) \
		{ return new (vtable->gc(), vtable->getExtraSize()) _Script(vtable, delegate); } \
		static NativeTableEntry natives[];

#ifdef AVMTHUNK_VERSION
	
	#define NATIVE_METHOD(method_id, handler) \
		{ (AvmThunkNativeThunker)avmplus::NativeID::method_id##_thunk, (AvmThunkNativeHandler)&handler, avmplus::NativeID::method_id, 0, AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS },
		
	#define NATIVE_METHOD_FLAGS(method_id, handler, fl) \
		{ (AvmThunkNativeThunker)avmplus::NativeID::method_id##_thunk, (AvmThunkNativeHandler)&handler, avmplus::NativeID::method_id, 0, fl | AbstractFunction::NATIVE_COOKIE },

	#define NATIVE_METHOD1(method_id, handler, cookie) \
		{ (AvmThunkNativeThunker)avmplus::NativeID::method_id##_thunkc, (AvmThunkNativeHandler)&handler, avmplus::NativeID::method_id, cookie, AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS | AbstractFunction::NATIVE_COOKIE },
		
	#define NATIVE_METHOD1_FLAGS(method_id, handler, cookie, fl) \
		{ (AvmThunkNativeThunker)avmplus::NativeID::method_id##_thunkc, (AvmThunkNativeHandler)&handler, avmplus::NativeID::method_id, cookie, fl | AbstractFunction::NATIVE_COOKIE },

	#define END_NATIVE_MAP() \
		{ NULL, NULL, -1, 0, 0 } };
#else
	#define NATIVE_METHOD(method_id, handler) \
		{ (NativeTableEntry::Handler)&handler, avmplus::NativeID::method_id, 0, AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS },
		
	#define NATIVE_METHOD_FLAGS(method_id, handler, fl) \
		{ (NativeTableEntry::Handler)&handler, avmplus::NativeID::method_id, 0, fl },

	#define NATIVE_METHOD1(method_id, handler, cookie) \
		{ (NativeTableEntry::Handler)&handler, avmplus::NativeID::method_id, cookie, AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS | AbstractFunction::NATIVE_COOKIE },
		
	#define NATIVE_METHOD1_FLAGS(method_id, handler, cookie, fl) \
		{ (NativeTableEntry::Handler)&handler, avmplus::NativeID::method_id, cookie, fl | AbstractFunction::NATIVE_COOKIE },

	#define END_NATIVE_MAP() \
		{ NULL, -1, 0, 0 } };
#endif

    /**
	 * NativeScriptInfo is an internal structure used for
	 * native script tables.  It is wrapped by the
	 * NATIVE_SCRIPT() macro.
	 */
    struct NativeScriptInfo
	{
		typedef ScriptObject* (*Handler)(VTable*, ScriptObject*);

	// ------------------------ DATA SECTION BEGIN
	public:
		Handler handler;
		NativeTableEntryp nativeMap;
		int32_t script_id;
		uint32_t sizeofInstance;
	// ------------------------ DATA SECTION END
	};

	/**
	 * NativeClassInfo is an internal structure used for native
	 * method tables.  It is wrapped by the NATIVE_CLASS() macro.
	 */
	struct NativeClassInfo
	{
		typedef ClassClosure* (*Handler)(VTable*);

	// ------------------------ DATA SECTION BEGIN
	public:
		Handler handler;
		NativeTableEntryp nativeMap;
		int32_t class_id;
		uint32_t sizeofClass;
		uint32_t sizeofInstance;
	// ------------------------ DATA SECTION END
	};
}	

#endif /* __avmplus_NativeFunction__ */
