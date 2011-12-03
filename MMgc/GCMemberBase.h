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

#ifndef __GCMemberBase__
#define __GCMemberBase__

namespace MMgc
{
    //  Since GCFinalizedObject doesn't derive from GCObject, create a GCMemberBase
    //  class so that we don't have to copy/paste this in both inner class definitions.
    
    //  GCMemberBase class:
    //
    //  Separate definitons of GCMember for GCObject and GCFinalizedObject are necessary in order to
    //  restrict usage of GCMember only as member variables of GCObject or GCFinalizedObject.  We do not
    //  want to allow GCMember to be declared on a non-GCObject (except for GCRoots-- see definition in GCRoot::GCMember)
    //  The GCMemberBase class contains the shared functionality between GCObject::GCMember and GCFinalizedObject::GCMember.
    //
    
    template <class T>
    class GCMemberBase : public GCRef<T>
    {
        friend class GC;
    private:
        //  'set' is invoked whenever the garbage collected pointer value 't' changes
        void set(const T* tNew);
        T* value() const;
        T* const* location() const;

    protected:
        
        //  In order to keep the usage syntax uniform as "GCMember",
        //  Protect the constructors so that only "GCMember" subclasses are allowed to use this object.
        explicit GCMemberBase();
  
        template<class T2>
        explicit GCMemberBase(const GCRef<T2>& other);
 
        // copy constructor
        explicit GCMemberBase(const GCMemberBase<T>& other);

        ~GCMemberBase();

    public:
 
        GCMemberBase& operator=(const GCMemberBase& other);

        template<class T2>
        void operator=(const GCRef<T2>& other);

        //  Overload the T* assignment operator so that we can set GCMember's directly to NULL.
        void operator=(T* tNew);
        
    };
}

#endif /* __GCMemberBase__ */
