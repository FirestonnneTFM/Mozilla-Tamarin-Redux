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
%%category Buffers

%%decls
    MMgc::GC *gc;
    NoSyncSingleItemBuffer *singleItemBuffer;
    NoSyncMultiItemBuffer *multiItemBuffer;
    NonBlockingMultiItemBuffer *nonBlockMultiItemBuffer;
    Atom *atom;
 
%%prologue
    MMgc::GCConfig config;
    gc = new MMgc::GC(MMgc::GCHeap::GetGCHeap(), config);
	//gc=core->GetGC();
    atom=(Atom *)malloc(100);
    singleItemBuffer=new NoSyncSingleItemBuffer(gc);
    multiItemBuffer=new NoSyncMultiItemBuffer(gc);
    nonBlockMultiItemBuffer=new NonBlockingMultiItemBuffer(gc);

%%epilogue
    delete singleItemBuffer;
    delete multiItemBuffer;
    delete nonBlockMultiItemBuffer;
	delete gc;
    free(atom);

%%test NonBlockMultiItemConstructor
    %%verify nonBlockMultiItemBuffer!=NULL

%%test NonBlockMultiItemEmptyBuffer
    %%verify nonBlockMultiItemBuffer->isEmpty()
    %%verify !nonBlockMultiItemBuffer->isFull()
    %%verify !nonBlockMultiItemBuffer->get(atom)

%%test NonBlockMultiItemFullBuffer
    bool result;
    for (int i=0;i<14;i++) {
        result=nonBlockMultiItemBuffer->put(String::createLatin1(core,"test string")->atom());
        %%verify result
        %%verify !nonBlockMultiItemBuffer->isEmpty()
        %%verify !nonBlockMultiItemBuffer->isFull()
    }
    result=nonBlockMultiItemBuffer->put(String::createLatin1(core,"test string")->atom());
    %%verify result
    %%verify !nonBlockMultiItemBuffer->isEmpty()
    %%verify nonBlockMultiItemBuffer->isFull()

    result=nonBlockMultiItemBuffer->put(String::createLatin1(core,"test string")->atom());
    %%verify !result
    %%verify !nonBlockMultiItemBuffer->isEmpty()
    %%verify nonBlockMultiItemBuffer->isFull()

    for (int i=0;i<14;i++) {
        %%verify nonBlockMultiItemBuffer->get(atom)
        %%verify !nonBlockMultiItemBuffer->isEmpty()
        %%verify !nonBlockMultiItemBuffer->isFull()
    }
    %%verify nonBlockMultiItemBuffer->get(atom)
    %%verify nonBlockMultiItemBuffer->isEmpty()
    %%verify !nonBlockMultiItemBuffer->isFull()

    %%verify !nonBlockMultiItemBuffer->get(atom)
    %%verify nonBlockMultiItemBuffer->isEmpty()
    %%verify !nonBlockMultiItemBuffer->isFull()

%%test SingleConstructor
    %%verify singleItemBuffer!=NULL

%%test SingleEmptyBuffer
    %%verify singleItemBuffer->isEmpty()
    %%verify !singleItemBuffer->isFull()
    %%verify !singleItemBuffer->get(atom)

%%test SingleFullBuffer
    bool result;
    result=singleItemBuffer->put(String::createLatin1(core,"test string")->atom());
    %%verify result
    %%verify !singleItemBuffer->isEmpty()
    %%verify singleItemBuffer->isFull()
    result=singleItemBuffer->put(String::createLatin1(core,"test string")->atom());
    %%verify !result
    %%verify singleItemBuffer->get(atom)
    %%verify singleItemBuffer->isEmpty()
    %%verify !singleItemBuffer->isFull()

%%test MultiConstructor
    %%verify multiItemBuffer!=NULL

%%test MultiEmptyBuffer
    %%verify singleItemBuffer->isEmpty()
    %%verify !singleItemBuffer->isFull()
    %%verify !singleItemBuffer->get(atom)

%%test MultiFullBuffer
    bool result;
    for (int i=0;i<15;i++) {
        result=multiItemBuffer->put(String::createLatin1(core,"test string")->atom());
        %%verify result
        %%verify !multiItemBuffer->isEmpty()
        %%verify !multiItemBuffer->isFull()
    }
    result=multiItemBuffer->put(String::createLatin1(core,"test string")->atom());
    %%verify result
    %%verify !multiItemBuffer->isEmpty()
    %%verify multiItemBuffer->isFull()

    result=multiItemBuffer->put(String::createLatin1(core,"test string")->atom());
    %%verify !result
    %%verify !multiItemBuffer->isEmpty()
    %%verify multiItemBuffer->isFull()

    for (int i=0;i<15;i++) {
        %%verify multiItemBuffer->get(atom)
        %%verify !multiItemBuffer->isEmpty()
        %%verify !multiItemBuffer->isFull()
    }
    %%verify multiItemBuffer->get(atom)
    %%verify multiItemBuffer->isEmpty()
    %%verify !multiItemBuffer->isFull()

    %%verify !multiItemBuffer->get(atom)
    %%verify multiItemBuffer->isEmpty()
    %%verify !multiItemBuffer->isFull()
