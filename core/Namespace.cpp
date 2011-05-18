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


#include "avmplus.h"

using namespace MMgc;

namespace avmplus
{
    // See E4X 13.2.2, pg 64
    Namespace::Namespace(Atom prefix, Stringp uri, NamespaceType flags, ApiVersion apiVersion) :
#ifdef DEBUGGER
        AvmPlusScriptableObject(sotNamespace()),
#endif // DEBUGGER
        m_prefix(prefix),
        m_apiVersion(apiVersion)
    {
        // verify our parameters are interned strings
        AvmAssert(uri->isInterned());
        // prefix can be an interned string, undefined, or null
        AvmAssert(AvmCore::isName(prefix) || AvmCore::isNullOrUndefined(prefix));
        // ensure that if the incoming Atom is a string, that it's interned
        AvmAssert(AvmCore::isString(prefix) ? (AvmCore::atomToString(prefix))->isInterned() : 1);
        setUri(uri, flags);
        // ApiVersion should be ALLVERSIONS for all Namespaces that are nonpublic.
        AvmAssert(flags != NS_Public ? apiVersion == kApiVersion_VM_ALLVERSIONS : true);
    }

#ifdef DRC_TRIVIAL_DESTRUCTOR
    Namespace::~Namespace()
    {
        setUri(NULL, NS_Public);
        *const_cast<ApiVersion*>(&m_apiVersion) = ApiVersion(0);
    }
#endif

    void Namespace::setUri(Stringp uri, NamespaceType flags)
    {
        WBRC(GC::GetGC(this), this, &m_uriAndType, (int32_t)flags | (uintptr_t) uri);
    }

    bool Namespace::hasPrefix() const
    {
        return AvmCore::isName(m_prefix) && AvmCore::atomToString(m_prefix)->length() > 0;
    }

    bool Namespace::isPublic() const
    {
        return getType() == Namespace::NS_Public && getURI()->isEmpty();
    }

    bool Namespace::EqualTo(const Namespace* other) const
    {
        if (isPrivate() || other->isPrivate())
        {
            // one of these namespaces is private, so compare using object identity
            return this == other;
        }
        else
        {
            // both are public, so compare using uri's.  they are intern'ed so we
            // can do a fast pointer compare.
            return m_uriAndType == other->m_uriAndType && m_apiVersion == other->m_apiVersion;
        }
    }

    // Iterator support - for in, for each
    Atom Namespace::nextName(const AvmCore *core, int index)
    {
        // first return "uri" then "prefix"
        if (index == 1)
            return core->kuri->atom();
        else if (index == 2)
            return core->kprefix->atom();
        else
            return nullStringAtom;
    }

    Atom Namespace::nextValue(int index)
    {
        // first return uri then prefix
        if (index == 1)
            return this->getURI()->atom();
        else if (index == 2)
            return this->m_prefix;
        else
        {
            return undefinedAtom;
        }
    }

    int Namespace::nextNameIndex(int index)
    {
        if (index < 2)
            return index + 1;
        else
            return 0;
    }

    PrintWriter& Namespace::print(PrintWriter& prw) const
    {
        return prw << getURI();
    }

#ifdef DEBUGGER
    uint64_t Namespace::bytesUsedDeep() const
    {
        uint64_t size = bytesUsed();

        Atom prefix = getPrefix();
        if (AvmCore::isString(prefix))
            size += AvmCore::atomToString(prefix)->bytesUsed();

        size += getURI()->bytesUsed();

        return size;
    }
#endif
}

