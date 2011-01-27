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

#ifndef __avmplus_ErrorClass__
#define __avmplus_ErrorClass__


namespace avmplus
{
    /**
     * class Error
     */
    class GC_AS3_EXACT(ErrorClass, ClassClosure)
    {
    protected:
        ErrorClass(VTable* cvtable);
        
    public:
        REALLY_INLINE static ErrorClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return new (gc, MMgc::kExact, cvtable->getExtraSize()) ErrorClass(cvtable);
        }

        Atom call(int argc, Atom* argv)
        {
            return construct(argc, argv);
        }

        ScriptObject *createInstance(VTable *ivtable, ScriptObject *delegate);

        /**
         * throwError is a convenience function for throwing
         * an exception with a formatted error message,
         * printf-style
         */
        void throwError(int errorID, Stringp arg1=0, Stringp arg2=0, Stringp arg3=0);

        /** @name static methods */
        /*@{*/
        Stringp getErrorMessage(int errorID) const;
#ifdef DEBUGGER
        Atom getStackTrace(Atom thisAtom,
                           Atom *argv,
                           int argc);
#endif /* DEBUGGER */

    // ------------------------ DATA SECTION BEGIN
        GC_NO_DATA(ErrorClass)

    private:
        DECLARE_SLOTS_ErrorClass;
    // ------------------------ DATA SECTION END
    };

    /**
     * The ErrorObject class is the C++ implementation of the
     * Error class in the ECMA-262 Specification.
     *
     * The main difference between an ErrorObject and a regular
     * ScriptObject is the presence of the stack trace, which
     * can be retrieved with the getStackTrace method.
     */
    class GC_AS3_EXACT(ErrorObject,ScriptObject)
    {
    protected:
        ErrorObject(VTable *vtable, ScriptObject *delegate);

    public:
        REALLY_INLINE static ErrorObject* create(MMgc::GC* gc, VTable *ivtable, ScriptObject *prototype)
        {
            return new (gc, MMgc::kExact, ivtable->getExtraSize()) ErrorObject(ivtable, prototype);
        }

        ~ErrorObject() {
#ifdef DEBUGGER
            stackTrace = NULL;
#endif
        }

        Stringp getStackTrace() const;
#ifdef DEBUGGER
        StackTrace* getStackTraceObject() const { return stackTrace; }
#endif
        
    // ------------------------ DATA SECTION BEGIN
        GC_DATA_BEGIN(ErrorObject)

    private:
#ifdef DEBUGGER
        StackTrace* GC_POINTER_IFDEF(stackTrace,DEBUGGER);
#endif /* DEBUGGER */

        GC_DATA_END(ErrorObject)

        DECLARE_SLOTS_ErrorObject;
    // ------------------------ DATA SECTION END
    };

    /**
     * NativeErrorClass
     *
     * This class exists to override the [[Call]] entry point
     * to the class closure, so that it constructs an error object
     * instead of attempting a coercion.
     */
    class GC_CPP_EXACT(NativeErrorClass, ClassClosure)
    {
    protected:
        NativeErrorClass(VTable* cvtable);

    public:
        Atom call(int argc, Atom* argv)
        {
            return construct(argc, argv);
        }

        GC_NO_DATA(NativeErrorClass)
    };

    #define DECLARE_NATIVE_ERROR_CLASS(cls, obj)                                                \
        class obj : public ErrorObject                                                    \
        {                                                                                       \
        protected:                                                                              \
            REALLY_INLINE obj(VTable *vtable, ScriptObject *delegate)                           \
                : ErrorObject(vtable, delegate) {}                                              \
        public:                                                                                 \
            REALLY_INLINE static obj* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate) { \
                return new (gc, MMgc::kExact, ivtable->getExtraSize()) obj(ivtable, delegate); \
            }                                                                                   \
        private:                                                                                \
            virtual bool gcTrace(MMgc::GC* gc, size_t cursor); \
            DECLARE_SLOTS_##obj;                                                                \
        };                                                                                      \
                                                                                                \
        class cls : public NativeErrorClass                                                     \
        {                                                                                       \
        protected:                                                                              \
            REALLY_INLINE cls(VTable* cvtable)                                                  \
                : NativeErrorClass(cvtable) {}                                                  \
        public:                                                                                 \
            REALLY_INLINE static cls* create(MMgc::GC* gc, VTable* cvtable)                     \
            {                                                                                   \
                return new (gc, MMgc::kExact, cvtable->getExtraSize()) cls(cvtable);            \
            }                                                                                   \
            ScriptObject *createInstance(VTable *ivtable, ScriptObject *delegate)               \
            {                                                                                   \
                return obj::create(ivtable->gc(), ivtable, delegate);                           \
            }                                                                                   \
            virtual bool gcTrace(MMgc::GC* gc, size_t cursor); \
            DECLARE_SLOTS_##cls;                                                                \
        };

    // This is a hack that's required because the tracer generator really needs
    // to examine the output of the DECLARE_NATIVE_ERROR_CLASS macro expansions
    // (or actually the partial macro expansions - stopping before GC_AS3_EXACT
    // is expanded), but as things stand it will examine the macros themselves.
    //
    // It's probably the case that the macros don't pay for themselves.

#if 0
      GC_AS3_EXACT(DefinitionErrorClass, NativeErrorClass)
      GC_NO_DATA(DefinitionErrorClass)
      GC_AS3_EXACT(DefinitionErrorObject, ErrorObject)
      GC_NO_DATA(DefinitionErrorObject)
      
      GC_AS3_EXACT(EvalErrorClass, NativeErrorClass)
      GC_NO_DATA(EvalErrorClass)
      GC_AS3_EXACT(EvalErrorObject, ErrorObject)
      GC_NO_DATA(EvalErrorObject)

      GC_AS3_EXACT(RangeErrorClass, NativeErrorClass)
      GC_NO_DATA(RangeErrorClass)
      GC_AS3_EXACT(RangeErrorObject, ErrorObject)
      GC_NO_DATA(RangeErrorObject)
      
      GC_AS3_EXACT(ReferenceErrorClass, NativeErrorClass)
      GC_NO_DATA(ReferenceErrorClass)
      GC_AS3_EXACT(ReferenceErrorObject, ErrorObject)
      GC_NO_DATA(ReferenceErrorObject)

      GC_AS3_EXACT(SecurityErrorClass, NativeErrorClass)
      GC_NO_DATA(SecurityErrorClass)
      GC_AS3_EXACT(SecurityErrorObject, ErrorObject)
      GC_NO_DATA(SecurityErrorObject)

      GC_AS3_EXACT(SyntaxErrorClass, NativeErrorClass)
      GC_NO_DATA(SyntaxErrorClass)
      GC_AS3_EXACT(SyntaxErrorObject, ErrorObject)
      GC_NO_DATA(SyntaxErrorObject)

      GC_AS3_EXACT(TypeErrorClass, NativeErrorClass)
      GC_NO_DATA(TypeErrorClass)
      GC_AS3_EXACT(TypeErrorObject, ErrorObject)
      GC_NO_DATA(TypeErrorObject)

      GC_AS3_EXACT(URIErrorClass, NativeErrorClass)
      GC_NO_DATA(URIErrorClass)
      GC_AS3_EXACT(URIErrorObject, ErrorObject)
      GC_NO_DATA(URIErrorObject)

      GC_AS3_EXACT(VerifyErrorClass, NativeErrorClass)
      GC_NO_DATA(VerifyErrorClass)
      GC_AS3_EXACT(VerifyErrorObject, ErrorObject)
      GC_NO_DATA(VerifyErrorObject)

      GC_AS3_EXACT(UninitializedErrorClass, NativeErrorClass)
      GC_NO_DATA(UninitializedErrorClass)
      GC_AS3_EXACT(UninitializedErrorObject, ErrorObject)
      GC_NO_DATA(UninitializedErrorObject)

      GC_AS3_EXACT(ArgumentErrorClass, NativeErrorClass)
      GC_NO_DATA(ArgumentErrorClass)
      GC_AS3_EXACT(ArgumentErrorObject, ErrorObject)
      GC_NO_DATA(ArgumentErrorObject)
#endif

    DECLARE_NATIVE_ERROR_CLASS(DefinitionErrorClass, DefinitionErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(EvalErrorClass, EvalErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(RangeErrorClass, RangeErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(ReferenceErrorClass, ReferenceErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(SecurityErrorClass, SecurityErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(SyntaxErrorClass, SyntaxErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(TypeErrorClass, TypeErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(URIErrorClass, URIErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(VerifyErrorClass, VerifyErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(UninitializedErrorClass, UninitializedErrorObject)
    DECLARE_NATIVE_ERROR_CLASS(ArgumentErrorClass, ArgumentErrorObject)
}

#endif /* __avmplus_ErrorClass__ */
