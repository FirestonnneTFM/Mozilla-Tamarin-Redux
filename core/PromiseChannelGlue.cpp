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
#include "avmplus.h"

namespace avmplus {

    PromiseChannelClass::PromiseChannelClass(VTable* cvtable)
        : ClassClosure(cvtable) 
    {
        createVanillaPrototype();
    }
    
    void PromiseChannelObject::throwError(const char* msgz)
    {
        Atom error_args[3] = { nullObjectAtom, core()->newStringUTF8(msgz)->atom(), core()->intToAtom(0) }; 
        core()->throwAtom(toplevel()->errorClass()->construct(2, error_args));
    }

    void PromiseChannelObject::throwChannelClosedError()
    {
        AvmAssert(m_channel == NULL);
        Isolate* current = core()->getIsolate(); 
        if (!current->isPrimordial() && current->isMemoryManagementShutDown()) {
            // the primordial check shouldn't be necessary, isMemoryManagementShutDown() in FlashRuntimeIsolate checks
            // the m_player reference but it's uninitialized in the primordial isolate. 
            // FIXME: correct player code

            // No GC to make an exception.
            return;
        }
        char buf[64];
        if (m_channel) {
            VMPI_snprintf(buf, 64, "channel %lld closed in worker %d", (long long int)m_channel->channelGuid, current->desc);
        } else {
            VMPI_snprintf(buf, 64, "channel closed in worker %d", current->desc);
        }
        Stringp msg = core()->newStringLatin1(buf);
        Atom error_args[3] = { nullObjectAtom, msg->atom(), core()->intToAtom(0) }; 
        core()->throwAtom(toplevel()->ioErrorClass()->construct(2, error_args));
    }

    PromiseChannelObject::PromiseChannelObject(VTable* vtable, ScriptObject* prototype)
        : ScriptObject(vtable, prototype)
        , m_channel(NULL)
    {
    }

    void PromiseChannelObject::retargetSender(int32_t senderGiid) {
        m_channel->sender = senderGiid;
    }

    void PromiseChannelObject::retargetReceiver(int32_t receiverGiid) {
        m_channel->receiver = receiverGiid;
    }

    void PromiseChannelObject::initializeWithChannel(PromiseChannel* channel) {
        int32_t current_giid = core()->getIsolate()->desc;
        this->m_channel = channel;
        this->m_canSend = (channel->sender == current_giid);
        this->m_canRecv = (channel->receiver == current_giid);
    }

    void PromiseChannelObject::ctor(int32_t senderGiid, int32_t receiverGiid) {
        Aggregate* aggregate = core()->getIsolate()->getAggregate();
        FixedHeapRef<PromiseChannel> channel = aggregate->allocatePromiseChannel(senderGiid, receiverGiid);
        if (channel == NULL)
            throwError("Failed to allocate message channel");
        initializeWithChannel(channel);
    }
    
    double PromiseChannelObject::channelGuid()
    {
        return (double)this->m_channel->channelGuid;
    }

    bool PromiseChannelObject::available()
    {
        if (!m_canRecv)
            throwError("not a receiver");
        if (isClosed()) {
            throwChannelClosedError();
            return false;
        }
        // In the meantime m_channel could be closed, e.g., by
        // Aggregate::closeChannelsWithEndpoint()
        // so it's possible to return true while the channel impl is already closed
        return m_channel->available();
    }


    void PromiseChannelObject::close()
    {
        Isolate* isolate = core()->getIsolate();
        Aggregate* aggregate = isolate->getAggregate();
        aggregate->closePromiseChannel(m_channel, isolate->desc);
        m_channel = NULL;
    }

    bool PromiseChannelObject::isClosed() // isLocallyClosed()?
    {
        // best effort, may return true while the other end is closing
        if (m_channel == NULL) {
            return true;
        } else {
            if (m_channel->isClosed()) {
                m_channel = NULL;
                return true;
            } else
                return false;
        }
    }

    int32_t PromiseChannelObject::get_sender()
    {
        if (isClosed())
            throwChannelClosedError();
        return m_channel->sender;
    }

    int32_t PromiseChannelObject::get_receiver()
    {
        if (isClosed()) 
            throwChannelClosedError();
        return m_channel->receiver;
    }

}
