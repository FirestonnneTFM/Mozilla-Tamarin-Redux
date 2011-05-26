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

#ifndef __avmplus_ArrayObject__
#define __avmplus_ArrayObject__


namespace avmplus
{
    // When DEBUG_ARRAY_VERIFY is defined, we do extra verification that is very
    // slow, even in debug builds; thus normally this is disabled unless you
    // are running tests for Array-specific changes.
    #define NO_DEBUG_ARRAY_VERIFY

    /**
     * an instance of class Array.  constructed with "new Array" or
     * an array literal [...].   We need this class to support Array's
     * special "get" and "put" semantics and to maintain the virtual
     * "length" property.
     */
    class GC_AS3_EXACT(ArrayObject, ScriptObject)
    {
    private:
        // forcibly-inlined version used by various hot methods to ensure inlining;
        // see definition for more info.
        Atom getUintPropertyImpl(uint32_t index) const;

    protected:
        ArrayObject(VTable* ivtable, ScriptObject *delegate, uint32_t capacity=0);
        ArrayObject(VTable* ivtable, ScriptObject *delegate, Atom *argv, int argc);
#ifdef VMCFG_AOT
        template <typename ADT> ArrayObject(VTable* ivtable, ScriptObject *delegate, MethodEnv *env, ADT argDesc, uint32_t argc, va_list ap);
#endif

    public:
        REALLY_INLINE static ArrayObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate, uint32_t capacity = 0)
        {
            return new (gc, MMgc::kExact, ivtable->getExtraSize()) ArrayObject(ivtable, delegate, capacity);
        }

        REALLY_INLINE static ArrayObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate, Atom *argv, int argc)
        {
            return new (gc, MMgc::kExact, ivtable->getExtraSize()) ArrayObject(ivtable, delegate, argv, argc);
        }

#ifdef VMCFG_AOT
        template <typename ADT> static ArrayObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject *delegate, MethodEnv *env, ADT argDesc, uint32_t argc, va_list ap)
        {
            return new (gc, MMgc::kExact, ivtable->getExtraSize()) ArrayObject(ivtable, delegate, env, argDesc, argc, ap);
        }
#endif

        ~ArrayObject();

        virtual ArrayObject* toArrayObject() { return this; }

        // Non-virtual members for ActionScript method implementation
        uint32_t get_length() const;
        void set_length(uint32_t newLength);

        // Virtual members so Array subclasses can treat length differently (in both C++ and AS3)
        virtual uint32_t getLength() const;
        virtual void setLength(uint32_t newLength);
        
        // Virtual methods used (primarily) by ArrayClass generic methods;
        // the default implementations are adequate but we can improve speed by
        // overriding.
        virtual uint32_t getLengthProperty();
        virtual void setLengthProperty(uint32_t newLen);

        virtual Atom getAtomProperty(Atom name) const;
        virtual void setAtomProperty(Atom name, Atom value);
        virtual bool deleteAtomProperty(Atom name);
        virtual bool hasAtomProperty(Atom name) const;

        // Faster versions that takes direct indices
        virtual Atom getUintProperty(uint32_t index) const;
        virtual void setUintProperty(uint32_t index, Atom value);
        virtual bool delUintProperty(uint32_t index);
        virtual bool hasUintProperty(uint32_t i) const;

        virtual bool getAtomPropertyIsEnumerable(Atom name) const;

        // NB: These are only for use by CodegenLIR, and by ArrayObject itself.
        // They aren't declared private-with-friend-access because of the way
        // they are initialized, but in an ideal world, they would be.
        // Most code should call get/setUintProperty() instead.
        Atom _getUintProperty(uint32_t index) const;
        void _setUintProperty(uint32_t index, Atom value);
        Atom _getIntProperty(int32_t index) const;
        void _setIntProperty(int32_t index, Atom value);
        Atom _getDoubleProperty(double index) const;
        void _setDoubleProperty(double index, Atom value);
#ifdef VMCFG_FLOAT
        Atom _getFloatProperty(float index) const;
        void _setFloatProperty(float index, Atom value);
#endif
        
#ifdef VMCFG_AOT
        Atom *getDenseCopy() const;
        uint32_t getDenseLength() const;
#endif

        // Iterator support - for in, for each
        virtual Atom nextName(int index);
        virtual Atom nextValue(int index);
        virtual int nextNameIndex(int index);

        // native methods
        Atom AS3_pop(); // pop(...rest)
        uint32_t AS3_push(Atom* args, int argc); // push(...args):uint
        uint32_t AS3_unshift(Atom* args, int argc); // unshift(...args):

        Atom pop();
        uint32_t push(Atom *args, int argc);
        uint32_t unshift(Atom *args, int argc);

#ifdef DEBUGGER
        virtual uint64_t bytesUsed() const;
#endif

#ifdef AVMPLUS_VERBOSE
    public:
        PrintWriter& print(PrintWriter& prw) const;
#endif

    private:
        Atom indexToName(uint32_t index) const;

        void convertToSparse();

        bool delDenseUintProperty(uint32_t index);

        void verify() const;

        uint32_t calcDenseUsed() const;

    protected:
        // Helper methods used only by ArrayClass, as special-case
        // optimizations for various "generic" optimizations that
        // can be done on dense arrays. These optimizations used
        // to be done in ArrayClass directly, but have been moved
        // into ArrayObject so that all "special knowledge" about
        // how dense arrays are implemented can be concentrated here
        // rather than bleeding into other classes (even one as
        // friendly to us as our class).
        friend class ArrayClass;
        
        bool try_concat(ArrayObject* that);
        bool try_reverse();
        bool try_shift(Atom& result);
        virtual ArrayObject* try_splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const ArrayObject* that, uint32_t that_skip);
        bool try_unshift(ArrayObject* that);

    protected:
        void unseal() 
        { 
            AvmAssert(m_denseStart == IS_SEALED); 
            m_denseStart = 0; 
        }

    private:
        
        // These values are chosen such that (index - denseStart)
        // is always >= m_denseArray.length(), obviating the need
        // to have a separate runtime check for "is-dense" or not.
        static const uint32_t IS_SEALED = 0xfffffffe;
        static const uint32_t IS_SPARSE = 0xffffffff;
        bool isSparse() const;
        bool isDense() const;
        bool isDynamic() const;

    private:
        
    // ------------------------ DATA SECTION BEGIN
        GC_DATA_BEGIN(ArrayObject)

        AtomList GC_STRUCTURE(m_denseArray);
        uint32_t              m_denseStart;
        uint32_t              m_denseUsed;
        uint32_t              m_length;

        GC_DATA_END(ArrayObject)

    private:
        DECLARE_SLOTS_ArrayObject;
    // ------------------------ DATA SECTION END
    };

    // Special subclass used for "SemiSealed" Array subclasses
    // see https://bugzilla.mozilla.org/show_bug.cgi?id=654807
    class SemiSealedArrayObject : public ArrayObject
    {
    protected:
        REALLY_INLINE SemiSealedArrayObject(VTable* ivtable, ScriptObject* delegate)
            : ArrayObject(ivtable, delegate)
        {
            AvmAssert(!traits()->needsHashtable());
            unseal();
        }

    protected:
        friend class ClassClosure;
        static ScriptObject* FASTCALL createInstanceProc(ClassClosure* cls);

    public:
        virtual Atom getAtomProperty(Atom name) const;
        virtual void setAtomProperty(Atom name, Atom value);
        virtual bool deleteAtomProperty(Atom name);
        virtual bool hasAtomProperty(Atom name) const;

        // Faster versions that takes direct indices
        virtual Atom getUintProperty(uint32_t index) const;
        virtual void setUintProperty(uint32_t index, Atom value);
        virtual bool delUintProperty(uint32_t index);
        virtual bool hasUintProperty(uint32_t i) const;

        virtual bool getAtomPropertyIsEnumerable(Atom name) const;
        virtual void setAtomPropertyIsEnumerable(Atom name, bool enumerable);

        virtual void setLength(uint32_t newLen);

    protected:
        virtual ArrayObject* try_splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const ArrayObject* that, uint32_t that_skip);
    };
}

#endif /* __avmplus_ArrayObject__ */
