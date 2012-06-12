/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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

#ifndef __avmplus_Channels_inlines__
#define __avmplus_Channels_inlines__

namespace avmplus
{
        
    template<class BUFFER>
    BlockingChannel<BUFFER>::BlockingChannel() : eof(false)
    {
        buffer = new BUFFER();
    }
    
    template<class BUFFER>
    BlockingChannel<BUFFER>::~BlockingChannel()
    {
        delete buffer;
    }

    template<class BUFFER>
    void BlockingChannel<BUFFER>::close()
    {
        SCOPE_LOCK_NAMED(lk, m_monitor) {
            eof = true;
            lk.notifyAll();
        }
    }
    
    
    template<class BUFFER>
    bool BlockingChannel<BUFFER>::isClosed() 
    {
        SCOPE_LOCK(m_monitor) {
            return eof;
        }
        NOT_REACHED;
    }

    template<class BUFFER>
    bool BlockingChannel<BUFFER>::isEmpty() 
    {
        bool res;
        SCOPE_LOCK(m_monitor) {
            res =  buffer->isEmpty();
        }
        return res;
    }

    template<class BUFFER>
    bool BlockingChannel<BUFFER>::isFull() 
    { 
        bool res;
        SCOPE_LOCK(m_monitor) {
            res = buffer->isFull();
        }
        return res;
    }
    
    template<class BUFFER>
    uint32_t BlockingChannel<BUFFER>::numItemsInBuffer() 
    { 
        uint32_t res = 0;
        SCOPE_LOCK(m_monitor) {
            res = buffer->numItemsInBuffer();
        }
        return res;
    }

    template<class BUFFER>
    bool BlockingChannel<BUFFER>::available()
    {
        bool res = false;
        SCOPE_LOCK(m_monitor) {
            res = !buffer->isEmpty();
        }
        return res;
    }

    template<class BUFFER>
    bool BlockingChannel<BUFFER>::put(const ChannelItem* in)
    {
        SCOPE_LOCK_NAMED(lk, m_monitor) {
            while (!buffer->put(in)) {
                if (eof) {
                    return false;
                }
                lk.wait();
            }
            lk.notify();
            return true;
        }
        NOT_REACHED;
    }
        
    template<class BUFFER>
    bool BlockingChannel<BUFFER>::get(const ChannelItem** outp)
    {
        SCOPE_LOCK_NAMED(lk, m_monitor) {
            while (buffer->isEmpty() && !eof)
                lk.wait();
            if (!buffer->get(outp))
                return false;
            lk.notify();
            return true;
        }
        NOT_REACHED;
    }
        

    template<class BUFFER>
    NonBlockingChannel<BUFFER>::NonBlockingChannel(MMgc::GC* gc) : eof(false)
    {
        buffer = new BUFFER(gc);
    }
       
    template<class BUFFER>
    NonBlockingChannel<BUFFER>::~NonBlockingChannel()
    {
        delete buffer;
    }

    template<class BUFFER>
    void NonBlockingChannel<BUFFER>::close()
    {
        eof = true;
        VMPI_memoryBarrier();
    }
        
    template<class BUFFER>
    void NonBlockingChannel<BUFFER>::unregisterRoot() {
        buffer->unregisterRoot();
    }

    template<class BUFFER>
    bool NonBlockingChannel<BUFFER>::isClosed() 
    {
        VMPI_memoryBarrier();
        return eof;
    }

    template<class BUFFER>
    bool NonBlockingChannel<BUFFER>::isEmpty() 
    { 
        VMPI_memoryBarrier();
        return buffer->isEmpty();
    }

    template<class BUFFER>
    bool NonBlockingChannel<BUFFER>::isFull() 
    { 
        VMPI_memoryBarrier();
        return buffer->isFull();
    }

    template<class BUFFER>
    bool NonBlockingChannel<BUFFER>::available()
    {
        VMPI_memoryBarrier();
        return !buffer->isEmpty();
    }

    template<class BUFFER>
    bool NonBlockingChannel<BUFFER>::put(const Atom &in)
    {
        while (true) {
            if (buffer->put(in)) return true;
            if (eof) return false;
            VMPI_threadSleep(0);
        }
        NOT_REACHED;            
    }
        
    template<class BUFFER>
    bool NonBlockingChannel<BUFFER>::get(Atom *outp)
    {
        while (true) {
            if (buffer->get(outp)) return true;
            if (eof) return false;
            VMPI_threadSleep(0);
        }
        NOT_REACHED;            
    }
    
    template<class BUFFER>
    void NonBlockingChannel<BUFFER>::registerWithGC(MMgc::GC* gc)
    {
        buffer->registerWithGC(gc);
    }
    
    template<class BUFFER>
    MMgc::GC* NonBlockingChannel<BUFFER>::gc()
    {
        return buffer->gc();
    }

}
#endif
