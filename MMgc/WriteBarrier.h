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

//
// GCWriteBarrier
//

#ifndef _WRITE_BARRIER_H_
#define _WRITE_BARRIER_H_

// inline write barrier
#define WB(gc, container, addr, value) gc->privateWriteBarrier(container, addr, (const void *) (value))

// fast manual RC write barrier
#define WBRC(gc, container, addr, value) gc->privateWriteBarrierRC(container, addr, (const void *) (value))

// fast-path versions for writing NULL (useful in dtors)

inline void write_null(void* p) { *(uintptr_t*)(p) = 0; }
#define WB_NULL(addr) write_null((void*)addr)

#define WBRC_NULL(addr) MMgc::GC::WriteBarrierRC_dtor(addr)

// This is used in places where the mutator has convinced itself the
// barrier isn't necessary.  FIXME: The idea is to check this in DEBUG
// builds.
#define WB_SKIP(gc, container, addr, value) *(addr) = value

#ifdef MMGC_POLICY_PROFILING
    #define POLICY_PROFILING_ONLY(x) x
#else
    #define POLICY_PROFILING_ONLY(x)
#endif

namespace MMgc
{
    // This is intended to be subclassed by avmplus::AtomWB /only/.  It provides the
    // minimum of functionality required by exact tracing of AtomWB smart pointers.

    class AtomWBCore
    {
        friend class GC;
        
    public:
        /** @return the Atom value held by the pointer. */
        avmplus::Atom value() const { return m_atom; }
        
    protected:
        explicit AtomWBCore(avmplus::Atom a);
        explicit AtomWBCore();
        
        avmplus::Atom m_atom;
        
    private:
        explicit AtomWBCore(const AtomWBCore& toCopy);  // unimplemented
        void operator=(const AtomWBCore& wb);           // unimplemented
        
        /**
         * @return the location of the Atom slot.  Used by GC::TraceAtom(AtomWBCore*)
         * to implement MMGC_HEAP_GRAPH.
         */
        avmplus::Atom* location() { return &m_atom; }
    };
}

#endif // _WRITE_BARRIER_H_
