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

#ifndef __avmplus_PromiseChannelGlue__
#define __avmplus_PromiseChannelGlue__

namespace avmplus
{

    class GC_AS3_EXACT(PromiseChannelClass, ClassClosure)
    {

        friend class PromiseChannelObject;
    protected:
        PromiseChannelClass(VTable* cvtable);
    private:
        GC_NO_DATA(PromiseChannelClass)
        DECLARE_SLOTS_PromiseChannelClass;
    };

    class GC_AS3_EXACT(PromiseChannelObject, ScriptObject)
    {
        friend class PromiseChannelClass;
        
        PromiseChannelObject(VTable* vtable, ScriptObject* prototype); 
    public:
        REALLY_INLINE static PromiseChannelObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* prototype)
        {
            return new (gc, MMgc::kExact, ivtable->getExtraSize()) PromiseChannelObject(ivtable, prototype);
        }
        void ctor(int32_t senderGid, int32_t receiverGid);
        void retargetSender(int32_t senderGiid);
        void retargetReceiver(int32_t receiverGiid);
        void initializeWithChannel(PromiseChannel* channel);
        void close();
        bool available();
        int32_t get_sender();
        int32_t get_receiver();
        double channelGuid(); // debugging
        bool isClosed();
        void throwError(const char* msg);
        void throwChannelClosedError();

    public: // FIXME public for WorkerObjectBase
        FixedHeapRef<PromiseChannel> m_channel; 

    private:
        GC_DATA_BEGIN(PromiseChannelObject)
        DECLARE_SLOTS_PromiseChannelObject;
        // FIXME state not needed in here any more, can refer to PromiseChannel, which will be always valid
        bool m_canSend;
        bool m_canRecv;
        GC_DATA_END(PromiseChannelObject)

    };

}

#endif /* __avmplus_PromiseChannelGlue__ */
