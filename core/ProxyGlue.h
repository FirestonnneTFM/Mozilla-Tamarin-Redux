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

#ifndef PROXYGLUE_INCLUDED
#define PROXYGLUE_INCLUDED

namespace avmplus
{
    //
    // ProxyClass
    //

    class GC_AS3_EXACT(ProxyClass, ClassClosure)
    {
        friend class ProxyObject;
    public:
        ProxyClass(VTable* vtable);

    private:
        Binding initOneBinding(GCRef<Namespace> ns, const char* nm);

    private:
        GC_DATA_BEGIN(ProxyClass);

        Binding m_getProperty;
        Binding m_setProperty;
        Binding m_hasProperty;
        Binding m_deleteProperty;

        Binding m_callProperty;

        Binding m_getDescendants;

        Binding m_nextNameIndex;
        Binding m_nextName;
        Binding m_nextValue;
        
        GC_DATA_END(ProxyClass);
        
        DECLARE_SLOTS_ProxyClass;
    };

    //
    // ProxyObject
    //

    class GC_AS3_EXACT(ProxyObject, ScriptObject)
    {
        friend class ProxyClass;
    protected:
        ProxyObject(VTable* ivtable, ScriptObject* delegate)
            : ScriptObject(ivtable, delegate)
        {
        }

    public:
        bool flash_proxy_isAttribute(Atom name);

        // overrides from ScriptObject
        virtual Atom getAtomProperty(Atom name) const;
        virtual void setAtomProperty(Atom name, Atom value);
        virtual bool deleteAtomProperty(Atom name);
        virtual bool hasAtomProperty(Atom name) const;

        virtual Atom getMultinameProperty(const Multiname* name) const;
        virtual void setMultinameProperty(const Multiname* name, Atom value);
        virtual bool deleteMultinameProperty(const Multiname* name);
        virtual bool hasMultinameProperty(const Multiname* name) const;

        virtual Atom getUintProperty(uint32_t i) const;
        virtual void setUintProperty(uint32_t i, Atom value);
        virtual bool delUintProperty(uint32_t i);
        virtual bool hasUintProperty(uint32_t i) const;

        virtual Atom callProperty(const Multiname* multiname, int argc, Atom* argv);

        virtual Atom getDescendants(const Multiname* name) const;

        virtual Atom nextName(int index);
        virtual Atom nextValue(int index);
        virtual int nextNameIndex(int index);
        
    private:
        GC_NO_DATA(ProxyObject);
        DECLARE_SLOTS_ProxyObject;
    };
}

#endif /* PROXYGLUE_INCLUDED */
