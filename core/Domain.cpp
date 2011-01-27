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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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

namespace avmplus
{
    Domain::Domain(AvmCore* core, Domain* base, uint32_t baseCount)
        : m_namedTraits(MultinameTraitsHashtable::create(core->GetGC()))
        , m_namedScriptsMap(MultinameBindingHashtable::create(core->GetGC()))
        , m_namedScriptsList(core->GetGC(), 0)
        , m_parameterizedTypes(new (core->GetGC()) WeakKeyHashtable(core->GetGC()))
        , m_baseCount(baseCount)
    {
        WB(core->GetGC(), this, &m_bases[0], this);
        for (uint32_t i = 1; i < baseCount; ++i)
        {
            WB(core->GetGC(), this, &this->m_bases[i], base->m_bases[i-1]);
        }
    }

    Domain* Domain::newDomain(AvmCore* core, Domain* base)
    {
        uint32_t baseCount = (base ? base->m_baseCount : 0) + 1;
        // Note that we deliberately overallocate by one here (the proper
        // amount is baseCount-1) so that we always have one, zeroed-out
        // entry at the end. This allows us to always use "m_bases[1]"
        // to get our immediate base, even if our base is NULL, thus
        // avoiding a check in the implementation of base().
        uint32_t extra = baseCount * sizeof(Domain*);
        return new (core->GetGC(), MMgc::kExact, extra) Domain(core, base, baseCount);
    }

    ClassClosure* Domain::getParameterizedType(ClassClosure* type)
    {
        AvmAssert(type != NULL);
        Atom a = type ? m_parameterizedTypes->get(type->atom()) : nullObjectAtom;
        return AvmCore::isObject(a) ? (ClassClosure*)AvmCore::atomToScriptObject(a) : NULL;
    }

    void Domain::addParameterizedType(ClassClosure* type, ClassClosure* parameterizedType)
    {
        AvmAssert(type && parameterizedType);
        if (type && parameterizedType)
        {
            AvmAssert(!m_parameterizedTypes->contains(type->atom()));
            m_parameterizedTypes->add(type->atom(), parameterizedType->atom());
        }
    }
}


