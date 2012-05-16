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
%%category FixedHeap

%%prefix
    typedef FixedHeapRef<String> StringFixedHeapRef;
    typedef FixedHeapArray<uint32_t> UintFixedHeapArray;


%%test FixedHeapRefDefaultConstructor
    StringFixedHeapRef *heap=new StringFixedHeapRef();
    %%verify heap!=NULL
    (*heap)=String::createLatin1(core,"test string");
    %%verify (*heap)!=NULL
    delete heap;

%%test FixedHeapRefValueConstructor
    String *s1=String::createLatin1(core,"test string");
    StringFixedHeapRef *heap1=new StringFixedHeapRef(s1);
    %%verify heap1!=NULL
    StringFixedHeapRef *heap2=new StringFixedHeapRef(*heap1);
    %%verify heap2!=NULL
    %%verify *heap1== *heap2
    StringFixedHeapRef heap3;
    heap3=*heap2;
    %%verify heap3!=NULL
    delete heap1;
    delete heap2;

%%test FixedHeapArrayEmpty
    UintFixedHeapArray *fixedheaparray=new UintFixedHeapArray();
    %%verify fixedheaparray-> length == 0
    fixedheaparray->deallocate();
    %%verify fixedheaparray-> length == 0
    fixedheaparray->resize(5);
    %%verify fixedheaparray-> length == 5
    fixedheaparray->deallocate();
    %%verify fixedheaparray-> length == 0
    delete fixedheaparray;

%%test FixedHeapArrayUint
    uint32_t array[5]={0,1,2,3,4};
    UintFixedHeapArray *fixedheaparray=new UintFixedHeapArray();
    %%verify fixedheaparray->length == 0
    fixedheaparray->allocate(5);
    fixedheaparray->initialize(array);
    %%verify fixedheaparray->length == 5
    fixedheaparray->resize(7);
    %%verify fixedheaparray->length == 7
    fixedheaparray->deallocate();
    %%verify fixedheaparray->length == 0
    delete fixedheaparray;

%%test FixedHeapArrayUintConstructor
    uint32_t array[5]={0,1,2,3,4};
    UintFixedHeapArray *fixedheaparray=new UintFixedHeapArray(array,5);
    %%verify fixedheaparray->length == 5
    delete fixedheaparray;

%%test FixedHeapHashTableEmpty
    FixedHeapHashTable<int32_t,int32_t> *table;
    table=new(FixedHeapHashTable<int32_t,int32_t>)();
    %%verify table->GetNumItems()==0
    %%verify table->InsertItem(1,1)
    int item;
    %%verify table->LookupItem(1,&item)
    %%verify item == 1
    %%verify table->RemoveItem(1)
    %%verify !table->LookupItem(1,&item)
    for (int i=0;i<10;i++) {
        %%verify table->InsertItem(i,i)
    }
    %%verify table->GetNumItems()==10
    %%verify table->LookupItem(8,&item)
    %%verify item == 8
    table->Clear();
    %%verify table->GetNumItems()==0
    %%verify table->InsertItem(5,5)
    %%verify table->GetNumItems()==1
	table->Clear();
    delete table;

%%test FixedHeapHashTable
    FixedHeapHashTable<int32_t,int32_t> *table;
    table=new(FixedHeapHashTable<int32_t,int32_t>)(10);
    %%verify table->GetNumItems()==0
    %%verify table->InsertItem(1,1)
    int item;
    %%verify table->LookupItem(1,&item)
    %%verify item == 1
    %%verify table->RemoveItem(1)
    %%verify !table->LookupItem(1,&item)
    for (int i=0;i<10;i++) {
        %%verify table->InsertItem(i,i)
    }
    %%verify table->GetNumItems()==10
    %%verify table->LookupItem(8,&item)
    %%verify item == 8
    table->Clear();
    %%verify table->GetNumItems()==0
    %%verify table->InsertItem(5,5)
    %%verify table->GetNumItems()==1
	table->Clear();
    delete table; 
