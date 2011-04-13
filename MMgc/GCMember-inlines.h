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

#ifndef __GCMember_inlines__
#define __GCMember_inlines__

#include "GCMemberBase-inlines.h"

namespace MMgc
{    
    // -----------------------------------------
    // GCRoot::GCMember
    // -----------------------------------------
    
    template<class T>
    REALLY_INLINE void GCRoot::GCMember<T>::set(T* tNew)
    {
        if (valid())
        {
            //  This is NOOP for GCObject and GCFinalizedObject
            this->t->DecrementRef();
        }
        this->t = tNew;
        if (valid())
        {
            //  This is NOOP for GCObject and GCFinalizedObject
            this->t->IncrementRef();
        }
    }
    
    template<class T>
    REALLY_INLINE bool GCRoot::GCMember<T>::valid()
    { 
        return (uintptr_t)(this->t) > 1; 
    }

    template<class T>
    REALLY_INLINE GCRoot::GCMember<T>::GCMember() 
        : GCRef<T>()
    { 
    }

    template<class T>
    REALLY_INLINE GCRoot::GCMember<T>::GCMember(const GCMember<T>& other) 
        : GCRef<T>()
    { 
        set(ProtectedGetOtherRawPtr(other));
    }

    template<class T>
    template<class T2>
    REALLY_INLINE GCRoot::GCMember<T>::GCMember(const GCRef<T2>& other) 
        : GCRef<T>()
    { 
        set(ProtectedGetOtherRawPtr(other));
    }

    template<class T>
    REALLY_INLINE GCRoot::GCMember<T>::GCMember(T* valuePtr) 
        : GCRef<T>()
    { 
        set(valuePtr);
    }

    template<class T>
    REALLY_INLINE GCRoot::GCMember<T>::~GCMember() 
    { 
        set(NULL);
    }
            
    template<class T>
    template<class T2>
    REALLY_INLINE void GCRoot::GCMember<T>::operator=(const GCRef<T2>& other) 
    { 
        set(ProtectedGetOtherRawPtr(other));
    }

    template<class T>
    REALLY_INLINE void GCRoot::GCMember<T>::operator=(T* tNew) 
    { 
        set(tNew);
    }

    template<class T>
    REALLY_INLINE GCRoot::GCMember<T>& GCRoot::GCMember<T>::operator=(const GCMember& other) 
    { 
        set(ProtectedGetOtherRawPtr(other));
        return *this;
    }

    // -----------------------------------------
    // GCInlineObject::GCMember
    // -----------------------------------------

    template<class T>
    template<class T2>
    REALLY_INLINE void GCInlineObject::GCMember<T>::operator=(const GCRef<T2>& other) 
    { 
        GCMemberBase<T>::operator=(other);
    }

    template<class T>
    REALLY_INLINE void GCInlineObject::GCMember<T>::operator=(T* tNew) 
    { 
        GCMemberBase<T>::operator=(tNew);
    }

    template<class T>
    REALLY_INLINE GCInlineObject::GCMember<T>::GCMember() 
    { 
    }

    template<class T>
    template<class T2>
    REALLY_INLINE GCInlineObject::GCMember<T>::GCMember(const GCRef<T2>& other) 
        : GCMemberBase<T>(other)
    { 
    }

    template<class T>
    REALLY_INLINE GCInlineObject::GCMember<T>::GCMember(T* valuePtr) 
    { 
        GCMemberBase<T>::operator=(valuePtr);
    }

    template<class T>
    REALLY_INLINE GCInlineObject::GCMember<T>::GCMember(const GCMember<T>& other) 
        : GCMemberBase<T>(other)
    { 
    }

    // -----------------------------------------
    // GCObject::GCMember
    // -----------------------------------------

    template<class T>
    template<class T2>
    REALLY_INLINE void GCObject::GCMember<T>::operator=(const GCRef<T2>& other) 
    { 
        GCMemberBase<T>::operator=(other);
    }

    template<class T>
    REALLY_INLINE void GCObject::GCMember<T>::operator=(T* tNew) 
    { 
        GCMemberBase<T>::operator=(tNew);
    }

    template<class T>
    REALLY_INLINE GCObject::GCMember<T>::GCMember() 
    { 
    }

    template<class T>
    template<class T2>
    REALLY_INLINE GCObject::GCMember<T>::GCMember(const GCRef<T2>& other) 
        : GCMemberBase<T>(other)
    { 
    }

    template<class T>
    REALLY_INLINE GCObject::GCMember<T>::GCMember(T* valuePtr) 
    { 
        GCMemberBase<T>::operator=(valuePtr);
    }

    template<class T>
    REALLY_INLINE GCObject::GCMember<T>::GCMember(const GCMember<T>& other) 
        : GCMemberBase<T>(other)
    { 
    }
    
    // -----------------------------------------
    // GCTraceableBase::GCMember
    // -----------------------------------------

    template<class T>
    template<class T2>
    REALLY_INLINE void GCTraceableBase::GCMember<T>::operator=(const GCRef<T2>& other) 
    { 
        GCMemberBase<T>::operator=(other);
    }

    template<class T>
    REALLY_INLINE void GCTraceableBase::GCMember<T>::operator=(T* tNew) 
    { 
        GCMemberBase<T>::operator=(tNew);
    }

    template<class T>
    REALLY_INLINE GCTraceableBase::GCMember<T>::GCMember() 
    { 
    }

    template<class T>
    template<class T2>
    REALLY_INLINE GCTraceableBase::GCMember<T>::GCMember(const GCRef<T2>& other) 
        : GCMemberBase<T>(other)
    { 
    }

    template<class T>
    REALLY_INLINE GCTraceableBase::GCMember<T>::GCMember(T* valuePtr) 
    { 
        GCMemberBase<T>::operator=(valuePtr);
    }

    template<class T>
    REALLY_INLINE GCTraceableBase::GCMember<T>::GCMember(const GCMember<T>& other) 
        : GCMemberBase<T>(other)
    { 
    }
}

#endif /* __GCMemberBase_inlines__ */
