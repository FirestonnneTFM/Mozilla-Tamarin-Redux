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
 *   leon.sha@sun.com
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

#ifndef __GCMemberBase_inlines__
#define __GCMemberBase_inlines__

namespace MMgc
{    
    template<class T>
    REALLY_INLINE void GCMemberBase<T>::set(const T* tNew)
    {
        T::WriteBarrier((void**)&(this->t), (void*)tNew);
    }

    template<class T>
    REALLY_INLINE T* GCMemberBase<T>::value() const
    {
        return this->t;
    }
    
    template<class T>
    REALLY_INLINE T** GCMemberBase<T>::location() const
    {
        return &(this->t);
    }
    
    template<class T>
    REALLY_INLINE GCMemberBase<T>::GCMemberBase() 
        : GCRef<T>()
    {
#ifdef DEBUG
        GC::TracePointerCheck(&(this->t));
#endif
    }
    
    template<class T>
    template<class T2>
    REALLY_INLINE GCMemberBase<T>::GCMemberBase(const GCRef<T2>& other) 
        : GCRef<T>()
    {
#ifdef DEBUG
        GC::TracePointerCheck(&(this->t));
#endif
        set(ProtectedGetOtherRawPtr(other));
    }

    // copy constructor
    template<class T>
    REALLY_INLINE GCMemberBase<T>::GCMemberBase(const GCMemberBase<T>& other) 
        : GCRef<T>()
    {
#ifdef DEBUG
        GC::TracePointerCheck(&(this->t));
#endif
        set(ProtectedGetOtherRawPtr(other));
    }

    template<class T>
    REALLY_INLINE GCMemberBase<T>::~GCMemberBase()
    {
        T::WriteBarrier_dtor((void**)&(this->t));
    }

    template<class T>
    REALLY_INLINE GCMemberBase<T>& GCMemberBase<T>::operator=(const GCMemberBase& other)
    {
        set(ProtectedGetOtherRawPtr(other));
        return *this;
    }

    template<class T>
    template<class T2>
    REALLY_INLINE void GCMemberBase<T>::operator=(const GCRef<T2>& other) 
    {
        set(ProtectedGetOtherRawPtr(other));
    }	

    template<class T>
    REALLY_INLINE void GCMemberBase<T>::operator=(T* tNew)
    {
        set(tNew);
    }

}

#endif /* __GCMemberBase_inlines__ */
