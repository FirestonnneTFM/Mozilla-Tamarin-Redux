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

#ifndef __avmplus_ArrayObject_inlines__
#define __avmplus_ArrayObject_inlines__

namespace avmplus
{
    REALLY_INLINE Atom ArrayObject::pop()
    {
        return AS3_pop();
    }

    REALLY_INLINE uint32_t ArrayObject::push(Atom *args, int argc)
    {
        return AS3_push(args, argc);
    }

    REALLY_INLINE uint32_t ArrayObject::unshift(Atom *args, int argc)
    {
        return AS3_unshift(args, argc);
    }

    // Performance on some benchmarks (eg Euler.as) is highly sensitive to
    // ArrayObject::getUintProperty being fast; this exists in order to ensure
    // that the implementations of getUintProperty and _getUintProperty/_getIntProperty
    // (used by the JIT) contain inlined code rather than a tail-call.
    REALLY_INLINE Atom ArrayObject::getUintPropertyImpl(uint32_t index) const
    {
        // NB: we constrain the dense area to indices <= 0x7FFFFFFF,
        // so this test will always fail if the we are sealed or sparse,
        // due to IS_SEALED and IS_SPARSE being carefully chosen values.
        uint32_t const denseIdx = index - m_denseStart;
        if (denseIdx < m_denseArray.length())
        {
            Atom result = m_denseArray.get(denseIdx);
            if (result != atomNotFound)
                return result;
            // else, a hole in the dense area, must fall thru and search the hashtable/proto chain
        }

        Atom result = ScriptObject::getUintProperty(index);
        AvmAssert(result != atomNotFound);
        return result;
    }

    /*virtual*/
    REALLY_INLINE void ArrayObject::setUintProperty(uint32_t index, Atom value)
    {
        _setUintProperty(index, value);
    }

    /*virtual*/
    REALLY_INLINE Atom ArrayObject::getUintProperty(uint32_t index) const
    {
        return getUintPropertyImpl(index);
    }

    // Non-virtual members for ActionScript method implementation.
    // Always calls thru to the virtual method to allow subclasses to override in C++.
    REALLY_INLINE uint32_t ArrayObject::get_length() const
    {
        return getLength();
    }

    REALLY_INLINE void ArrayObject::set_length(uint32_t newLength)
    {
        setLength(newLength);
    }

} // namespace avmplus

#endif /* __avmplus_ArrayObject_inlines__ */
