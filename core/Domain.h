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

#ifndef __avmplus_Domain__
#define __avmplus_Domain__

namespace avmplus
{
    class Domain : public MMgc::GCObject
    {
    private:
        Domain(AvmCore* core, Domain* base, uint32_t baseCount);

    public:
        static Domain* newDomain(AvmCore* core, Domain* base);

        // see note in newDomainEnv about why this is always valid, even if m_baseCount == 1
        REALLY_INLINE Domain* base() const { return m_bases[1]; }

        // returns NULL if the type doesn't exist yet.
        ClassClosure* getParameterizedType(ClassClosure* type);
        void addParameterizedType(ClassClosure* type, ClassClosure* parameterizedType);

    private:
        friend class DomainMgr;
        DWB(MultinameHashtable*)        m_namedTraits;
        DWB(MultinameHashtable*)        m_namedScriptsMap;
        GCList<MethodInfo*>             m_namedScriptsList;        // list of MethodInfo* for the scripts
        DWB(HeapHashtable*)             m_parameterizedTypes;
        // note that m_baseCount is actually the number of bases, plus one:
        // we always add ourself (!) to the front of the list, to simplify
        // processing in DomainMgr.
        uint32_t const                  m_baseCount; // number of entries in m_bases
        Domain*                         m_bases[1];  // lying: really [m_baseCount]
    };

}

#endif /* __avmplus_Domain__ */
