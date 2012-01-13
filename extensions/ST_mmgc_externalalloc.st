// -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
//
// ***** BEGIN LICENSE BLOCK *****
// Version: MPL 1.1/GPL 2.0/LGPL 2.1
//
// The contents of this file are subject to the Mozilla Public License Version
// 1.1 (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
// http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
// for the specific language governing rights and limitations under the
// License.
//
// The Original Code is [Open Source Virtual Machine.].
//
// The Initial Developer of the Original Code is
// Adobe System Incorporated.
// Portions created by the Initial Developer are Copyright (C) 2011
// the Initial Developer. All Rights Reserved.
//
// Contributor(s):
//   Adobe AS3 Team
//
// Alternatively, the contents of this file may be used under the terms of
// either the GNU General Public License Version 2 or later (the "GPL"), or
// the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
// in which case the provisions of the GPL or the LGPL are applicable instead
// of those above. If you wish to allow use of your version of this file only
// under the terms of either the GPL or the LGPL, and not to allow others to
// use your version of this file under the terms of the MPL, indicate your
// decision by deleting the provisions above and replace them with the notice
// and other provisions required by the GPL or the LGPL. If you do not delete
// the provisions above, a recipient may use your version of this file under
// the terms of any one of the MPL, the GPL or the LGPL.
//
// ***** END LICENSE BLOCK ***** */

%%component mmgc
%%category externalalloc

%%prefix
using namespace MMgc;
class MyCallback : public MMgc::OOMCallback
{
public:
    MMgc::MemoryStatus status;

    MyCallback()
    {
        status = MMgc::GCHeap::GetGCHeap()->GetStatus();
        MMgc::GCHeap::GetGCHeap()->AddOOMCallback(this);
    }

    void memoryStatusChange(MMgc::MemoryStatus /*oldStatus*/, MMgc::MemoryStatus newStatus)
    {
        status = newStatus;
    }
};

%%decls
private:
    MyCallback *cb;

%%prologue
    cb = new MyCallback();

%%epilogue
    cb = NULL;

%%test externalAllocation
    MMGC_GCENTER(core->gc);
    size_t softlimit = GCHeap::GetGCHeap()->Config().heapSoftLimit;
    // Remove the heapSoftLimit, this should ensure that we are not in a MMgc::kMemSoftLimit state,
    // and hopefully we are in a kMemNormal state otherwise we are in a kMemAbort state and all bets are off.
    GCHeap::GetGCHeap()->Config().heapSoftLimit = 0;
    %%verify cb->status==MMgc::kMemNormal
    GCHeap::GetGCHeap()->Config().heapSoftLimit = GCHeap::GetGCHeap()->GetTotalHeapSize();
    MMgc::GCHeap::SignalExternalAllocation(1024*1024);
    %%verify cb->status==MMgc::kMemSoftLimit
    MMgc::GCHeap::SignalExternalDeallocation(1024*1024);
    %%verify cb->status==MMgc::kMemNormal
    GCHeap::GetGCHeap()->Config().heapSoftLimit = softlimit;
    softlimit = 0;


