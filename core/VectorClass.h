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


#ifndef __avmplus_VectorClass__
#define __avmplus_VectorClass__

namespace avmplus
{
    // ----------------------------

    class GC_AS3_EXACT(VectorClass, ClassClosure)
    {
    protected:
        VectorClass(VTable* vtable);
    public:
        REALLY_INLINE static VectorClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return MMgc::setExact(new (gc, cvtable->getExtraSize()) VectorClass(cvtable));
        }

        /**
        *  This unspecialized class cannot be instantiated.
        *  Ensure any attempt fails.
        *  @throw TypeError
        */
        virtual ScriptObject* createInstance(VTable* ivtable, ScriptObject* delegate);

        virtual Atom applyTypeArgs(int argc, Atom* argv);

        ClassClosure* getTypedVectorClass(ClassClosure* typeClass);

        static Stringp makeVectorClassName(AvmCore* core, Traits* t);

        // make a Vector of subtype Vector<typeClass>,
        // eg is typeClass == StringClass then return a new Vector<String>
        ObjectVectorObject* newVector(ClassClosure* typeClass, uint32_t length = 0);

    private:
        GC_NO_DATA(VectorClass)

        DECLARE_SLOTS_VectorClass;
    };

    // ----------------------------

    class GC_CPP_EXACT(TypedVectorClassBase, ClassClosure)
    {
    protected:
        explicit TypedVectorClassBase(VTable* vtable);

    public:
        Atom checkType(Atom a);

        // ClassClosure overrides
        virtual Atom call(int argc, Atom* argv);

        // AS3 native function implementations
        void _forEach(Atom thisAtom, ScriptObject* callback, Atom thisObject);
        bool _every(Atom thisAtom, ScriptObject* callback, Atom thisObject);
        bool _some(Atom thisAtom, ScriptObject* callback, Atom thisObject);
        Atom _sort(Atom thisAtom, ArrayObject* args); 

    protected:
        virtual Atom createAndInitVectorFromObject(ScriptObject* so, uint32_t len) = 0;

    protected:
        GC_DATA_BEGIN(TypedVectorClassBase)

        DWB(Traits*) GC_POINTER(m_typeTraits);

        GC_DATA_END(TypedVectorClassBase)
    };

    // ----------------------------

    template<class OBJ>
    class TypedVectorClass : public TypedVectorClassBase
    {
        friend class VectorClass;

    protected:
        explicit TypedVectorClass(VTable* vtable);

    public:
        // ClassClosure overrides
        virtual ScriptObject* createInstance(VTable* ivtable, ScriptObject* prototype);

        OBJ* newVector(uint32_t length = 0);

        virtual void gcTrace(MMgc::GC* gc)
        {
            TypedVectorClassBase::gcTrace(gc);
        }

    protected:
        virtual Atom createAndInitVectorFromObject(ScriptObject* so, uint32_t len);
    };


    // ----------------------------

    class GC_AS3_EXACT(IntVectorClass, TypedVectorClass<IntVectorObject>)
    {
    private:
        explicit IntVectorClass(VTable* vtable);
    public:
        REALLY_INLINE static IntVectorClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return MMgc::setExact(new (gc, cvtable->getExtraSize()) IntVectorClass(cvtable));
        }

        GC_NO_DATA(IntVectorClass)

        DECLARE_SLOTS_IntVectorClass;
    };

    // ----------------------------

    class GC_AS3_EXACT(UIntVectorClass, TypedVectorClass<UIntVectorObject>)
    {
    private:
        explicit UIntVectorClass(VTable* vtable);
    public:
        REALLY_INLINE static UIntVectorClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return MMgc::setExact(new (gc, cvtable->getExtraSize()) UIntVectorClass(cvtable));
        }

        GC_NO_DATA(UIntVectorClass)

        DECLARE_SLOTS_UIntVectorClass;
    };

    // ----------------------------

    class GC_AS3_EXACT(DoubleVectorClass, TypedVectorClass<DoubleVectorObject>)
    {
    private:
        explicit DoubleVectorClass(VTable* vtable);
    public:
        REALLY_INLINE static DoubleVectorClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return MMgc::setExact(new (gc, cvtable->getExtraSize()) DoubleVectorClass(cvtable));
        }

        GC_NO_DATA(DoubleVectorClass)

        DECLARE_SLOTS_DoubleVectorClass;
    };

    // ----------------------------

    class GC_AS3_EXACT(ObjectVectorClass, TypedVectorClass<ObjectVectorObject>)
    {
    private:
        explicit ObjectVectorClass(VTable* vtable);
    public:
        REALLY_INLINE static ObjectVectorClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return MMgc::setExact(new (gc, cvtable->getExtraSize()) ObjectVectorClass(cvtable));
        }

        GC_NO_DATA(ObjectVectorClass)

        DECLARE_SLOTS_ObjectVectorClass;
    };

    // ----------------------------

    struct VectorIndex
    {
        explicit VectorIndex(AvmCore* core, Atom name);

        uint32_t index;
        enum { kNotNumber, kInvalidNumber, kValidNumber } status;
    };

    // ----------------------------

    template<class T>
    struct TypedVectorConstants
    {
        static T nullValue();
        static T undefinedValue();
    };

    // ----------------------------

    class GC_CPP_EXACT(VectorBaseObject, ScriptObject)
    {
    protected:
        explicit VectorBaseObject(VTable* ivtable, 
                                  ScriptObject* delegate, 
                                  TypedVectorClassBase* vecClass);

    public:
        // AS3 native getter/setter implementations
        bool get_fixed() const;
        void set_fixed(bool fixed);

        // used by Flash code for AMF3
        ClassClosure* getType() const;

        // AIR needs to be able to get/set the length of an arbitrary
        // Vector without knowing its subclass; these simply forward into the
        // appropriate calls of the well-typed subclass.
        virtual uint32_t getLength() const = 0;
        virtual void setLength(uint32_t length) = 0;

    protected:
        
        Atom _mapImpl(ScriptObject* callback, Atom thisObject, VectorBaseObject* r, uint32_t len);
        Atom _filterImpl(ScriptObject* callback, Atom thisObject, VectorBaseObject* r, uint32_t len); 

        VectorBaseObject* _newVector();

        void checkFixed() const;
        void FASTCALL throwFixedError() const;

        void atomToValue(Atom atom, int32_t& value);
        Atom valueToAtom(const int32_t& value) const;

        void atomToValue(Atom atom, uint32_t& value);
        Atom valueToAtom(const uint32_t& value) const;

        void atomToValue(Atom atom, double& value);
        Atom valueToAtom(const double& value) const;

        void atomToValue(Atom atom, OpaqueAtom& value);
        Atom valueToAtom(const OpaqueAtom& value) const;

        enum VectorIndexStatus { kNotNumber, kInvalidNumber, kValidNumber };
        VectorIndexStatus getVectorIndex(Atom name, uint32_t& index) const;
    
        GC_DATA_BEGIN(VectorBaseObject)

        DRCWB(TypedVectorClassBase*)    GC_POINTER(m_vecClass);
        bool                            m_fixed;

        GC_DATA_END(VectorBaseObject)
    };

    // ----------------------------

    template<class TLIST>
    class TypedVectorObject : public VectorBaseObject
    {
        template<class OBJ> friend class TypedVectorClass;
        template<class TLISTVA> friend class VectorAccessor;

    public:
        typedef TLIST LIST;

    protected:
        explicit TypedVectorObject(VTable* ivtable, 
                                   ScriptObject* delegate, 
                                   MMgc::GC* gc, 
                                   TypedVectorClassBase* vecClass);

    public:
        // overrides 
        virtual uint32_t getLength() const;
        virtual void setLength(uint32_t length);

        // AS3 native getter/setter implementations
        uint32_t get_length() const;
        void set_length(uint32_t newLength);

        // AS3 native function implementations
        Atom _map(ScriptObject* callback, Atom thisObject);
        Atom _filter(ScriptObject* callback, Atom thisObject); 
        void _reverse();
        void _spliceHelper(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, Atom args, uint32_t offset);
        uint32_t AS3_push(Atom* argv, int argc);
        typename TLIST::TYPE AS3_pop();
        uint32_t AS3_unshift(Atom* argv, int argc);
        typename TLIST::TYPE AS3_shift();

        // ScriptObject method overrides
        virtual bool hasAtomProperty(Atom name) const;
        virtual Atom getAtomProperty(Atom name) const;
        virtual void setAtomProperty(Atom name, Atom value);
        virtual bool hasUintProperty(uint32_t index) const;
        virtual Atom getUintProperty(uint32_t index) const;
        virtual void setUintProperty(uint32_t index, Atom value);
        virtual Atom nextName(int index);
        virtual Atom nextValue(int index);
        virtual int nextNameIndex(int index);
        
        // "fast" methods that don't range-check in nondebug builds
        // and are inlined; for internal use by various bits of Flash glue code
        typename TLIST::TYPE getUintPropertyFast(uint32_t index) const;
        void setUintPropertyFast(uint32_t index, typename TLIST::TYPE value);

        // JIT helpers -- not for public use!
        // (declared public only to avoid a painful 'friend' declaration)
        typename TLIST::TYPE _getNativeIntProperty(int32_t index) const;
        void _setNativeIntProperty(int32_t index, typename TLIST::TYPE value);
        typename TLIST::TYPE _getNativeUintProperty(uint32_t index) const;
        void _setNativeUintProperty(uint32_t index, typename TLIST::TYPE value);
        bool _hasUintProperty(uint32_t index) const;
        Atom _getUintProperty(uint32_t index) const;
        void _setUintProperty(uint32_t index, Atom value);
        Atom _getIntProperty(int32_t index) const;
        void _setIntProperty(int32_t index, Atom value);

#ifdef DEBUGGER
        virtual uint64_t bytesUsed() const;
#endif

    private:

        void FASTCALL throwRangeError(uint32_t index) const;

        uint32_t checkReadIndex_u(uint32_t index) const;
        uint32_t checkWriteIndex_u(uint32_t index) const;

        // variant of _spliceHelper with explicit array of Atom.
        // (Not exposed to AS3.)
        // Note:
        //      _splice(0, 1, 0, &foo)           == Array.unshift(foo)
        //      _splice(this.length, 1, 0, &foo) == Array.push(foo)
        void _splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const Atom* argv);
        
        // _spliceHelper for when we already know that we have an object that is *not* of our Vector type.
        void _spliceHelper_so(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, ScriptObject* so_args, uint32_t offset);

    public:
        virtual void gcTrace(MMgc::GC* gc)
        {
            VectorBaseObject::gcTrace(gc);
            m_list.gcTrace(gc);
        }

    private:
        TLIST                           m_list;
    };

    // Some code internal to Flash/AIR needs to directly get/set the contents of Vectors;
    // this class provides an implicit lock/unlock mechanism. We guarantee that 
    // the value returned by addr() is valid for reading/writing for the lifespan of
    // the VectorAccessor (but only for entries 0...get_length()-1, of course).
    // length() is identical to VectorObject::get_length() but is provided here for symmetry.
    // This should obviously only be used in cases where performance is critical, or
    // other circumstances requires it (eg, to pass an array of numbers to a GPU
    // without intermediate copying). Note that it is explicitly legal to pass
    // a NULL VectorObject to the ctor (which will cause addr() to also return NULL
    // and length() to return 0). This class must be used only on the stack.
    template<class TLIST>
    class VectorAccessor
    {
    public:
        explicit VectorAccessor(TypedVectorObject<TLIST>* v);
        typename TLIST::TYPE* addr();
        uint32_t length();

    private:
        TypedVectorObject<TLIST>* m_vector;

    private:
        VectorAccessor<TLIST>& operator=(const VectorAccessor<TLIST>& other);   // unimplemented
        explicit VectorAccessor(const VectorAccessor<TLIST>& other);            // unimplemented
        void* operator new(size_t size);                                        // unimplemented
    };

    // ----------------------------

    class GC_AS3_EXACT(IntVectorObject, TypedVectorObject< DataList<int32_t> >)
    {
    protected:
        explicit IntVectorObject(VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass);

    public:
        REALLY_INLINE static IntVectorObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass)
        {
            return MMgc::setExact(new (gc, ivtable->getExtraSize()) IntVectorObject(ivtable, delegate, vecClass));
        }

        // AS3 native function implementations
        IntVectorObject* newThisType();

    // ------------------------ DATA SECTION BEGIN
    private:
        GC_NO_DATA(IntVectorObject)

        DECLARE_SLOTS_IntVectorObject;
    // ------------------------ DATA SECTION END
    };
    typedef VectorAccessor< DataList<int32_t> > IntVectorAccessor;

    // ----------------------------

    class GC_AS3_EXACT(UIntVectorObject, TypedVectorObject< DataList<uint32_t> >)
    {
    protected:
        explicit UIntVectorObject(VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase * vecClass);

    public:
        REALLY_INLINE static UIntVectorObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass)
        {
            return MMgc::setExact(new (gc, ivtable->getExtraSize()) UIntVectorObject(ivtable, delegate, vecClass));
        }

        // AS3 native function implementations
        UIntVectorObject* newThisType();

    // ------------------------ DATA SECTION BEGIN
    private:
        GC_NO_DATA(UIntVectorObject)

        DECLARE_SLOTS_UIntVectorObject;
    // ------------------------ DATA SECTION END
    };
    typedef VectorAccessor< DataList<uint32_t> > UIntVectorAccessor;

    // ----------------------------

    class GC_AS3_EXACT(DoubleVectorObject, TypedVectorObject< DataList<double> >)
    {
    protected:
        explicit DoubleVectorObject(VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass);

    public:
        REALLY_INLINE static DoubleVectorObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass)
        {
            return MMgc::setExact(new (gc, ivtable->getExtraSize()) DoubleVectorObject(ivtable, delegate, vecClass));
        }

        // AS3 native function implementations
        DoubleVectorObject* newThisType();

    // ------------------------ DATA SECTION BEGIN
    private:
        GC_NO_DATA(DoubleVectorObject)

        DECLARE_SLOTS_DoubleVectorObject;
    // ------------------------ DATA SECTION END
    };
    typedef VectorAccessor< DataList<double> > DoubleVectorAccessor;

    // ----------------------------

    class GC_AS3_EXACT(ObjectVectorObject, TypedVectorObject< AtomList >)
    {
    protected:
        explicit ObjectVectorObject(VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass);

    public:
        REALLY_INLINE static ObjectVectorObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass)
        {
            return MMgc::setExact(new (gc, ivtable->getExtraSize()) ObjectVectorObject(ivtable, delegate, vecClass));
        }
    
        // AS3 native function implementations
        ObjectVectorObject* newThisType();

    // ------------------------ DATA SECTION BEGIN
    private:
        GC_NO_DATA(ObjectVectorObject)

        DECLARE_SLOTS_ObjectVectorObject;
    // ------------------------ DATA SECTION END
    };
    // This is explicitly NOT provided, as 
    // (1) there's currently no need for it, and 
    // (2) it would require WB hackery on the part of the user, which is error-prone
    //typedef VectorAccessor<Atom> ObjectVectorAccessor;

    // ----------------------------
}

#endif /* __avmplus_VectorClass__ */
