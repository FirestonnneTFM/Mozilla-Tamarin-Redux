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

#ifndef __avmplus_Namespace__
#define __avmplus_Namespace__


namespace avmplus
{
    /**
     * a namespace is a primitive value in the system, similar to String
     */
    class Namespace : public AvmPlusScriptableObject
    {
    private:
        friend class AvmCore;
        template <class VALUE_TYPE, class VALUE_WRITER> friend class MultinameHashtable;
        template <class VALUE_TYPE> friend class Quad;

    private:
        AtomWB              m_prefix;
        uintptr_t           m_uriAndType;          // Uses 3 bits for flags, but otherwise is really a Stringp
        ApiVersion  const   m_apiVersion;

    public:
        enum NamespaceType
        {
            NS_Public = 0,
            NS_Protected = 1,
            NS_PackageInternal = 2,
            NS_Private = 3,
            NS_Explicit = 4,
            NS_StaticProtected = 5
        };
        
    private:
        Namespace(Atom prefix, Stringp uri, NamespaceType type, ApiVersion apiVersion);
        
    public:
        static REALLY_INLINE Namespace* create(MMgc::GC* gc, Atom prefix, Stringp uri, NamespaceType type, ApiVersion apiVersion)
        {
            return new (gc, MMgc::kExact) Namespace(prefix, uri, type, apiVersion);
        }

        ~Namespace();

        virtual bool gcTrace(MMgc::GC* gc, size_t cursor);

        // AS3 native functions
        REALLY_INLINE Atom get_prefix() const { return m_prefix; }
        REALLY_INLINE Stringp get_uri() const { return (Stringp)atomPtr(m_uriAndType); }

        REALLY_INLINE Atom getPrefix() const { return get_prefix(); }
        REALLY_INLINE Stringp getURI() const { return get_uri(); }
        REALLY_INLINE ApiVersion getApiVersion() { return m_apiVersion; }

        Atom  atom() const { return AtomConstants::kNamespaceType | (Atom)this; }

        /**
         * virtual version of atom():
         */
        virtual Atom toAtom() const { return atom(); }

        bool hasPrefix () const;

        bool isPublic() const;

        bool EqualTo(const Namespace* other) const;

        REALLY_INLINE bool isPrivate() const
        {
            return ISNULL(m_prefix);
        }

        REALLY_INLINE NamespaceType getType() const
        {
            return (NamespaceType)(m_uriAndType & 7);
        }

        // Iterator support - for in, for each
        Atom nextName(const AvmCore *core, int index);
        Atom nextValue(int index);
        int nextNameIndex(int index);

#ifdef DEBUGGER
        uint64_t bytesUsed() const { return sizeof(Namespace); }

        // Like bytesUsed(), but also includes memory taken by the
        // prefix and the uri.
        uint64_t bytesUsedDeep() const;
#endif

//#ifdef AVMPLUS_VERBOSE
    public:
        PrintWriter& print(PrintWriter& prw) const;
//#endif
    private:
        void setUri(Stringp uri, NamespaceType flags);
    };
}

#endif /* __avmplus_Namespace__ */

