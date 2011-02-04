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

#ifndef __avmplus_ClassClosure__
#define __avmplus_ClassClosure__


namespace avmplus
{
    /**
     * a user defined class, ie class MyClass
     */
    class GC_AS3_EXACT(ClassClosure, ScriptObject)
    {
    protected:
        ClassClosure(VTable *cvtable);

    public:
        REALLY_INLINE static ClassClosure* create(MMgc::GC* gc, VTable* cvtable)
        {
            return new (gc, MMgc::kExact, cvtable->getExtraSize()) ClassClosure(cvtable);
        }

        REALLY_INLINE static ClassClosure* create(MMgc::GC* gc, size_t extraSize, VTable* cvtable)
        {
            return new (gc, MMgc::kExact, extraSize) ClassClosure(cvtable);
        }
        
        Atom get_prototype();
        void set_prototype(Atom p);

        ScriptObject* prototypePtr();
        void setPrototypePtr(ScriptObject* p);

        void createVanillaPrototype();

        ScriptObject* newInstance();

        /**
         * called as function, as in C().  For user classes, this is the
         * the explicit coersion function.  For user functions, we
         * invoke m_call.
         *
         * NOTE: The contents of the given argument list can be modified during
         *       invocation of the function without further warning.
         *       Do not reuse an argument list AS-IS for multiple function calls,
         *       unless you make sure to reinitialize the contents of the argument list after each call.
         */
        virtual Atom call(int argc, Atom* argv);

        VTable* ivtable() const;

#ifdef DEBUGGER
        virtual uint64_t bytesUsed() const;
#endif

        virtual Stringp implToString() const;

#ifdef AVMPLUS_VERBOSE
    public:
        PrintWriter& print(PrintWriter& prw) const;
#endif
    // ------------------------ DATA SECTION BEGIN
        GC_DATA_BEGIN(ClassClosure)

    private:
        DRCWB(ScriptObject*)  GC_POINTER(m_prototype);

        GC_DATA_END(ClassClosure)

        DECLARE_SLOTS_ClassClosure;
    // ------------------------ DATA SECTION END
    };
}

#endif /* __avmplus_ClassClosure__ */
