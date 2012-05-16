// -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
// vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
// Portions created by the Initial Developer are Copyright (C) 2012
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

%%component workers
%%category Channels

%%prefix
typedef NonBlockingChannel<NoSyncSingleItemBuffer> MessageChannelImpl1;
typedef BlockingChannel<NoSyncSingleItemBuffer> MessageChannelImpl2;
class MessageChannel1 : public MessageChannelImpl1
{
    public:
    MessageChannel1(MMgc::GC* gc) : MessageChannelImpl1(gc)
    {
    }
    void destroy() {
    }
};
class MessageChannel2 : public MessageChannelImpl2
{
    public:
    MessageChannel2(MMgc::GC* gc) : MessageChannelImpl2(gc)
    {
    }
    void destroy() {
    }
};
class MessageChannel3 : public MessageChannelImpl
{
    public:
    MMgc::GC* gc1;
    MessageChannel3(MMgc::GC* gc) : MessageChannelImpl(gc)
    {
        gc1=gc;
    }
    void destroy() {
    }
};

%%decls
    MMgc::GC *gc;
    MessageChannel1 *messagechannel1;
    MessageChannel2 *messagechannel2;
    MessageChannel3 *messagechannel3;
    Atom *atom;

%%prologue
    gc=core->GetGC();
    atom=(Atom *)malloc(100);
    messagechannel1=new MessageChannel1(gc);
    messagechannel2=new MessageChannel2(gc);
    messagechannel3=new MessageChannel3(gc);

%%epilogue
    delete messagechannel1;
    delete messagechannel2;
    delete messagechannel3;
    free(atom);

%%test NonBlockingChannelConstructor
    %%verify messagechannel1!=NULL

%%test NonBlockingChannelPut
    %%verify !messagechannel1->available()
    %%verify messagechannel1->put(String::createLatin1(core,"test string")->atom())
    %%verify messagechannel1->available()
    %%verify messagechannel1->get(atom)
    %%verify !messagechannel1->available()

%%test NonBlockingChannelClose
    %%verify !messagechannel1->isClosed()
    messagechannel1->close();
    %%verify messagechannel1->isClosed()
    %%verify messagechannel1->put(String::createLatin1(core,"test string")->atom())
    %%verify !messagechannel1->put(String::createLatin1(core,"test string")->atom())
    %%verify messagechannel1->get(atom)
    %%verify !messagechannel1->get(atom)

%%test BlockingChannelConstructor
    %%verify messagechannel2!=NULL

%%test BlockingChannelPut
    %%verify !messagechannel2->available()
    %%verify messagechannel2->put(String::createLatin1(core,"test string")->atom())
    %%verify messagechannel2->available()
    %%verify messagechannel2->get(atom)
    %%verify !messagechannel2->available()

%%test BlockingChannelClose
    %%verify !messagechannel2->isClosed()
    messagechannel2->close();
    %%verify messagechannel2->isClosed()
    %%verify messagechannel2->put(String::createLatin1(core,"test string")->atom())
    %%verify !messagechannel2->put(String::createLatin1(core,"test string")->atom())
    %%verify messagechannel2->get(atom)
    %%verify !messagechannel2->get(atom)

%%test MostlyNonBlockingChannelConstructor
    %%verify messagechannel3!=NULL

%%test MostlyNonBlockingChannelPut
    %%verify !messagechannel3->available()
    %%verify messagechannel3->isEmpty()
    %%verify !messagechannel3->isFull()
    for (int i=0;i<14;i++) {
        %%verify messagechannel3->put(String::createLatin1(core,"test string")->atom())
        %%verify messagechannel3->available()
        %%verify !messagechannel3->isEmpty()
        %%verify !messagechannel3->isFull()
    }
    %%verify messagechannel3->put(String::createLatin1(core,"test string")->atom())
    %%verify messagechannel3->available()
    %%verify !messagechannel3->isEmpty()
    %%verify messagechannel3->isFull()
    for (int i=0;i<14;i++) {
        %%verify messagechannel3->get(atom)
        %%verify messagechannel3->available()
        %%verify !messagechannel3->isEmpty()
        %%verify !messagechannel3->isFull()
    }
    %%verify messagechannel3->get(atom)
    %%verify !messagechannel3->available()
    %%verify messagechannel3->isEmpty()
    %%verify !messagechannel3->isFull()

%%test MostlyNonBlockingChannelClose
    %%verify !messagechannel3->isClosed()
    messagechannel3->close();
    %%verify messagechannel3->isClosed()
    %%verify !messagechannel3->put(String::createLatin1(core,"test string")->atom())
    %%verify !messagechannel3->get(atom)
