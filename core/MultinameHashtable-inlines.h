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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

namespace avmplus
{

template <class VALUE_TYPE>
REALLY_INLINE bool Quad<VALUE_TYPE>::matchNS(Namespacep ns) const
{
    AvmAssert(ns->getURI()->isInterned());
    AvmAssert(this->ns != NULL);

    // Avoid loading m_uriAndType if possible.
    if (this->ns == ns)
        return true;

    uintptr_t const u1 = this->ns->m_uriAndType;
    uintptr_t const u2 = ns->m_uriAndType;
    return  u1 == u2 && 
            (u1 & 7) == Namespace::NS_Public && // implies both are public, since u1 == u2
            this->apiVersion() <= ns->getApiVersion();
}

template <class VALUE_TYPE, class VALUE_WRITER>
REALLY_INLINE VALUE_TYPE MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::get(Stringp name, NamespaceSetp nsset) const
{
    return getNSSet(name, nsset)->value;
}

template <class VALUE_TYPE, class VALUE_WRITER>
REALLY_INLINE VALUE_TYPE MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::getMulti(const Multiname& name) const
{
    return getMulti(&name);
}

template <class VALUE_TYPE, class VALUE_WRITER>
REALLY_INLINE Stringp MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::keyAt(int index) const
{
    AvmAssert(m_quads->quads[index-1].name != NULL); return m_quads->quads[index-1].name;
}

template <class VALUE_TYPE, class VALUE_WRITER>
REALLY_INLINE Namespacep MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::nsAt(int index) const
{
    return m_quads->quads[index-1].ns;
}

template <class VALUE_TYPE, class VALUE_WRITER>
REALLY_INLINE VALUE_TYPE MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::valueAt(int index) const
{
    return m_quads->quads[index-1].value;
}

template <class VALUE_TYPE, class VALUE_WRITER>
REALLY_INLINE size_t MultinameHashtable<VALUE_TYPE, VALUE_WRITER>::allocatedSize() const
{
    return numQuads * sizeof(Quad<VALUE_TYPE>);
}

REALLY_INLINE StMNHTIterator::StMNHTIterator(MultinameBindingHashtable* mnht) :
    m_mnht(mnht),
    m_cur(mnht->m_quads->quads - 1),
    m_end(mnht->m_quads->quads + mnht->numQuads)
{ }

REALLY_INLINE bool StMNHTIterator::next()
{
    return ++m_cur < m_end;
}

REALLY_INLINE Stringp StMNHTIterator::key() const
{
    AvmAssert(m_cur < m_end);
    return m_cur->name;
}

REALLY_INLINE Namespacep StMNHTIterator::ns() const
{
    return m_cur->ns;
}

REALLY_INLINE Binding StMNHTIterator::value() const
{
    return m_cur->value;
}

REALLY_INLINE ApiVersion StMNHTIterator::apiVersion() const
{
    return m_cur->apiVersion();
}

/*static*/
REALLY_INLINE void BindingType::store(MMgc::GC* gc, void *, void **addr, void *value)
{
    // In theory, this assert can fire if a binding index happens to
    // point to GC memory, highly unlikely and it is worth keeping us
    // honest in Binding usage by doing this.
    (void)gc;
    AvmAssert(!gc->IsPointerToGCPage(value));
    *addr = value;
}

/*static*/
REALLY_INLINE void GCObjectType::store(MMgc::GC* gc, void *container, void **addr, void *value)
{
    WB(gc, container, addr, value);
}
} // namespace avmplus
