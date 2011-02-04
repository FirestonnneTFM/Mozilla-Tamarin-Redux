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

#ifndef __avmplus_ScriptObject__
#define __avmplus_ScriptObject__


namespace avmplus
{
#define avmplus_ScriptObject_isExactInterlock 1

    /**
     * one actionscript object.  might or might not be a function.
     * Base class for all objects visible to script code.
     */
    class ScriptObject : public AvmPlusScriptableObject
    {
    protected:
        ScriptObject(VTable* vtable, ScriptObject* delegate);
        ScriptObject(VTable* vtable, ScriptObject* delegate, int htCapacity);

    public:
        REALLY_INLINE static ScriptObject* create(MMgc::GC* gc, VTable* vtable, ScriptObject* delegate);
        REALLY_INLINE static ScriptObject* create(MMgc::GC* gc, VTable* vtable, ScriptObject* delegate, int htCapacity);

        ~ScriptObject();

        virtual bool gcTrace(MMgc::GC* gc, size_t cursor);

        ScriptObject* getDelegate() const;
        void setDelegate(ScriptObject *d);
        Atom atom() const;
        virtual Atom toAtom() const;
        Traits* traits() const;
        AvmCore* core() const;
        MMgc::GC* gc() const;
        Toplevel* toplevel() const;
        InlineHashtable* getTable() const;
        InlineHashtable* getTableNoInit() const;

        Atom getSlotAtom(uint32_t slot);

        // like getSlotAtom, but assume the resulting Atom is a ScriptObject...
        // if it is not, return NULL. useful for callers that expect only
        // a ScriptObject and reject other types (eg callproperty). If the
        // slot in question is usually a ScriptObject, it's substantially faster
        // to call this (vs getSlotAtom).
        ScriptObject* getSlotObject(uint32_t slot);

        // NOTE, this now does the equivalent of Toplevel::coerce() internally;
        // it is not necessary to call coerce() prior to calling this!
        void coerceAndSetSlotAtom(uint32_t slot, Atom atom);

        virtual Atom getDescendants(const Multiname* name) const;

        // argv[0] = receiver
        virtual Atom callProperty(const Multiname* name, int argc, Atom* argv);
        virtual Atom constructProperty(const Multiname* name, int argc, Atom* argv);

        // common set/set/has/delete/etc virtual methods renamed to explicitly name the expected arg types,
        // to avoid potentially hidden virtual functions
        virtual Atom getAtomProperty(Atom name) const;
        virtual Atom getAtomPropertyFromProtoChain(Atom name, ScriptObject* protochain, Traits *origObjTraits) const;
        virtual void setAtomProperty(Atom name, Atom value);
        virtual bool deleteAtomProperty(Atom name);
        virtual bool hasAtomProperty(Atom name) const;
        virtual bool getAtomPropertyIsEnumerable(Atom name) const;
        virtual void setAtomPropertyIsEnumerable(Atom name, bool enumerable);

        virtual Atom getMultinameProperty(const Multiname* name) const;
        virtual void setMultinameProperty(const Multiname* name, Atom value);
        virtual bool deleteMultinameProperty(const Multiname* name);
        virtual bool hasMultinameProperty(const Multiname* name) const;

        virtual Atom getUintProperty(uint32_t i) const;
        virtual void setUintProperty(uint32_t i, Atom value);
        virtual bool delUintProperty(uint32_t i);
        virtual bool hasUintProperty(uint32_t i) const;

        // convenience wrappers for passing Stringp instead of Atom
        // inline, not virtual (should never need overriding)
        Atom getStringProperty(Stringp name) const;
        Atom getStringPropertyFromProtoChain(Stringp name, ScriptObject* protochain, Traits *origObjTraits) const;
        void setStringProperty(Stringp name, Atom value);
        bool deleteStringProperty(Stringp name);
        bool hasStringProperty(Stringp name) const;
        bool getStringPropertyIsEnumerable(Stringp name) const;
        void setStringPropertyIsEnumerable(Stringp name, bool enumerable);

        virtual Atom defaultValue();        // ECMA [[DefaultValue]]
        virtual Stringp toString();

        // argv[0] = receiver
        virtual Atom call(int argc, Atom* argv);

        /**
         * argv[0] = receiver(ignored)
         * arg1 = argv[1]
         * argN = argv[argc]
         *
         * called as constructor, as in new C().  for user classes this
         * invokes the implicit constructor followed by the user's constructor
         * if any.
         *
         * NOTE: The contents of the given argument list can be modified during
         *       invocation of the constructor without further warning.
         *       Do not reuse an argument list AS-IS for multiple constructor calls,
         *       unless you make sure to reinitialize the contents of the argument list after each call.
         *
         * NOTE: subclasses should never need to declare this method in their class;
         *       an override declaration will be provided for them iff
         *       customconstruct="true" is specified in their AS3 file.
         */
        virtual Atom construct(int argc, Atom* argv);

        // TODO make this const
        virtual Atom nextName(int index);

        // TODO make this const
        virtual Atom nextValue(int index);

        // TODO make this const
        virtual int nextNameIndex(int index);

        virtual Atom applyTypeArgs(int argc, Atom* argv);

        // This is a fast way to implement "istype(MethodClosure)"; it returns non-null if
        // this is an MethodClosure (or subclass thereof)
        virtual MethodClosure* toMethodClosure() const;
        bool isMethodClosure() const;

        // Create an instance of ScriptObject or a ScriptObject subclass.
        //
        // If createInstance is overridden in a subclass then the overriding method must
        // either /always/ return a new object of the subclass without reaching the base case
        // (where ScriptObject::createInstance calls newObject) or it must /always/
        // reach the base case.  The reason for this restriction is that createInstance
        // custom creation functions are computed based on whether createInstance is
        // overridden or not; see ScriptObject.cpp.
        virtual ScriptObject* createInstance(VTable* ivtable, ScriptObject* prototype);

        // The maximum integer key we can use with our ScriptObject
        // HashTable must fit within 28 bits.  Any integer larger
        // than 28 bits will use a string key.
        static const uint32_t MAX_INTEGER_MASK = 0xF0000000;

        // return true iff the object is a toplevel script init object.
        bool isGlobalObject() const;

        virtual Stringp implToString() const;

        // this really shouldn't exist here, but AIR currently plays some games with subclassing
        // "Function" that use C++ classes that don't descend from FunctionObject. Easier to fix
        // by rooting this method here than by fixing AIR at this time.
        virtual CodeContext* getFunctionCodeContext() const;

        static ScriptObject* genericCreateInstance(ClassClosure* cls, VTable* ivtable);
        static ScriptObject* fastCreateInstance(ClassClosure* cls, VTable* ivtable);
        static ScriptObject* slowCreateInstance(ClassClosure* cls, VTable* ivtable);

        // This is a fast way to implement "istype(ARRAY)"; it returns non-null if
        // this is an ArrayObject (or subclass thereof)
        virtual ArrayObject* toArrayObject();

        // This gets the property named "length" (if any) on the object, coerces it to a uint,
        // and returns the value. (Since uint(undefined) == 0, undefined length is zero.)
        virtual uint32_t getLengthProperty();

        // This sets the property named "length" to the given uint value. If this
        // is a nondynamic object, or there is a read-only length property, or uint
        // can't be coerced to the type of "length", an exception will be thrown.
        virtual void setLengthProperty(uint32_t newLen);

#ifdef AVMPLUS_VERBOSE
    public:
        virtual PrintWriter& print(PrintWriter& prw) const;
#endif

#ifdef DEBUGGER
    public:
        virtual uint64_t bytesUsed() const;
#endif
#if defined(DEBUGGER) || defined(VMCFG_AOT)
    public:
        virtual MethodEnv* getCallMethodEnv();
#endif

    protected:
        
        void throwWriteSealedError(Atom name);
        void throwWriteSealedError(const Multiname& name);
        void throwCantInstantiateError();

    private:
        void initHashtable(int capacity = InlineHashtable::kDefaultCapacity);

    // ------------------------ DATA SECTION BEGIN
    public:     VTable* const           vtable;
    private:    DRCWB(ScriptObject*)    delegate;     // __proto__ in AS2, archetype in semantics
    // ------------------------ DATA SECTION END
    };
}

#endif /* __avmplus_ScriptObject__ */
