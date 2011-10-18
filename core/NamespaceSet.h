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

#ifndef __avmplus_NamespaceSet__
#define __avmplus_NamespaceSet__


namespace avmplus
{
    class NamespaceSetIterator
    {
    private:
        const NamespaceSet* const nsset;
        uint32_t i;
    public:
        NamespaceSetIterator(const NamespaceSet* n);
        bool hasNext() const;
        Namespacep next();
    };

    /**
     * NamespaceSet is a reference to 0 or more namespaces.  It consists
     * of a list of namespaces.
     */
    class GC_CPP_EXACT(NamespaceSet, MMgc::GCTraceableObject)
    {
        friend class AbcParser;
        friend class AvmCore;
        friend class Toplevel;

        GC_DATA_BEGIN(NamespaceSet)
        
    private:
        // hi 31 bits: count
        // lo bit: containsAnyPublic flag
        uint32_t _countAndFlags;
        Namespacep GC_POINTERS_SMALL(_namespaces[1], "count()");

        GC_DATA_END(NamespaceSet)
        
    private:
        NamespaceSet();

        // these are only for use by friends
        static NamespaceSet* _create(MMgc::GC* gc, uint32_t count);
        void _initNsAt(uint32_t i, Namespacep ns);

    public:
        static const NamespaceSet* create(MMgc::GC* gc, Namespacep ns);
        bool contains(Namespace* ns) const;
        bool containsAnyPublicNamespace() const;
        uint32_t count() const;
        Namespacep nsAt(uint32_t i) const;

//#ifdef AVMPLUS_VERBOSE
    public:
        PrintWriter& print(PrintWriter& prw) const;
//#endif
    };
}

#endif /* __avmplus_NamespaceSet__ */
