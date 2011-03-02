// Generated from ST_mmgc_basics.st
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
// Portions created by the Initial Developer are Copyright (C) 2004-2006
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

#include "avmshell.h"
#ifdef VMCFG_SELFTEST
namespace avmplus {
class ST_mmgc_basics : public Selftest {
public:
ST_mmgc_basics(AvmCore* core);
virtual void run(int n);
virtual void prologue();
virtual void epilogue();
private:
static const char* ST_names[];
static const bool ST_explicits[];
void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void test11();
void test12();
void test13();
void test14();
void test15();
private:
    MMgc::GC *gc;
    MMgc::FixedAlloc *fa;
    MMgc::FixedMalloc *fm;

};
ST_mmgc_basics::ST_mmgc_basics(AvmCore* core)
    : Selftest(core, "mmgc", "basics", ST_mmgc_basics::ST_names,ST_mmgc_basics::ST_explicits)
{}
const char* ST_mmgc_basics::ST_names[] = {"create_gc_instance","create_gc_object","get_bytesinuse","collect","getgcheap","fixedAlloc","fixedMalloc","gcheap","gcheapAlign","gcmethods","finalizerAlloc","finalizerDelete","nestedGCs","collectDormantGC","lockObject","regression_551169", NULL };
const bool ST_mmgc_basics::ST_explicits[] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false, false };
void ST_mmgc_basics::run(int n) {
switch(n) {
case 0: test0(); return;
case 1: test1(); return;
case 2: test2(); return;
case 3: test3(); return;
case 4: test4(); return;
case 5: test5(); return;
case 6: test6(); return;
case 7: test7(); return;
case 8: test8(); return;
case 9: test9(); return;
case 10: test10(); return;
case 11: test11(); return;
case 12: test12(); return;
case 13: test13(); return;
case 14: test14(); return;
case 15: test15(); return;
}
}
void ST_mmgc_basics::prologue() {
    gc=new MMgc::GC(MMgc::GCHeap::GetGCHeap(), MMgc::GC::kIncrementalGC);
    if (gc==NULL) {
        MMgc::GCHeap::Init();
        gc=new MMgc::GC(MMgc::GCHeap::GetGCHeap(), MMgc::GC::kIncrementalGC);
    }

}
void ST_mmgc_basics::epilogue() {
delete gc;

}
using namespace MMgc;
class DeleteInFinalizer : public GCFinalizedObject {
 public:
  // note "small" is a reserved identifier in Visual C++ for Windows Mobile (#defined to be 'char')
  DeleteInFinalizer(GCFinalizedObject *big, GCFinalizedObject *small_) : big(big), small_(small_) {};
  ~DeleteInFinalizer() { delete big; delete small_; }
 private:
  GCFinalizedObject *big;
  GCFinalizedObject *small_;
};

// Any small object would do
class AllocInFinalizer2 : public GCObject {
public:
    void* dummy;
};

class AllocInFinalizer : public GCFinalizedObject {
public:
    AllocInFinalizer() {}
    ~AllocInFinalizer() { new (GC::GetGC(this)) AllocInFinalizer2(); }
};

class LockableObject : public GCFinalizedObject {
public:
    LockableObject(int* counter) : counter(counter) {}
    virtual ~LockableObject() {
        *counter = *counter + 1;
    }
    int * const counter;
};

class LockerAndUnlocker
{
public:   
    static const int numlocked = 100;
    static GCObjectLock* lock[numlocked];
    static GCObjectLock* lock2[numlocked];
    static int counter;
    
    static bool createAndLockObjects(GC* gc) {
        counter = 0;
        for ( int i=0 ; i < numlocked ; i++ )
            lock[i] = gc->LockObject(new (gc) LockableObject(&counter));
        return true;
    }

    static bool lockLevel2(GC* gc) {
        for ( int i=0 ; i < numlocked ; i++ )
            lock2[i] = gc->LockObject(gc->GetLockedObject(lock[i]));
        return true;
    }

    static bool testLocksHeld(GC* gc, int level) {
        if (counter != 0)
            return false;

        int held = 0;
        for ( int i=0 ; i < numlocked ; i++ )
            held += bool(gc->GetLockedObject(lock[i]) != NULL);
        if (level > 1)
            for ( int i=0 ; i < numlocked ; i++ )
                held += bool(gc->GetLockedObject(lock2[i]) != NULL);

        if (held != level*numlocked)
            return false;
            
        return true;
    }
    
    static bool testLocksNotHeld(GC*) {
        // At least some of the destructors should have run...
        if (counter < numlocked/2)
            return false;
        return true;
    }

    static bool unlockLevel2(GC* gc) {
        for ( int i=0 ; i < numlocked ; i++ )
            gc->UnlockObject(lock2[i]);
        return true;
    }

    static bool unlockLevel1(GC* gc) {
        for ( int i=0 ; i < numlocked ; i++ ) {
#ifdef MMGC_HEAP_GRAPH
            gc->addToBlacklist(gc->GetLockedObject(lock[i]));
#endif
            gc->UnlockObject(lock[i]);
        }
        return true;
    }
};

GCObjectLock* LockerAndUnlocker::lock[numlocked];
GCObjectLock* LockerAndUnlocker::lock2[numlocked];
int LockerAndUnlocker::counter = 0;

void ST_mmgc_basics::test0() {
#line 160 "ST_mmgc_basics.st"
verifyPass(gc != NULL, "gc != NULL", __FILE__, __LINE__);

}
void ST_mmgc_basics::test1() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
#line 166 "ST_mmgc_basics.st"
verifyPass(mygcobject!=NULL, "mygcobject!=NULL", __FILE__, __LINE__);
    mygcobject->i=10;
#line 168 "ST_mmgc_basics.st"
verifyPass(mygcobject->i==10, "mygcobject->i==10", __FILE__, __LINE__);

}
void ST_mmgc_basics::test2() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    int inuse=(int)gc->GetBytesInUse();
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
//    AvmLog("bytes in use before %d after %d\n",inuse,(int)gc->GetBytesInUse());
#line 176 "ST_mmgc_basics.st"
verifyPass(gc->GetBytesInUse()==inuse + sizeof(MyGCObject) + DebugSize(), "gc->GetBytesInUse()==inuse + sizeof(MyGCObject) + DebugSize()", __FILE__, __LINE__);
    delete mygcobject;

}
void ST_mmgc_basics::test3() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    int inuse=(int)gc->GetBytesInUse();
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
#line 184 "ST_mmgc_basics.st"
verifyPass((int)gc->GetBytesInUse()>inuse, "(int)gc->GetBytesInUse()>inuse", __FILE__, __LINE__);
    delete mygcobject;
//    AvmLog("collect: inuse=%d current=%d\n",inuse,(int)gc->GetBytesInUse());
    gc->Collect();
//    AvmLog("collect: inuse=%d current=%d\n",inuse,(int)gc->GetBytesInUse());
#line 189 "ST_mmgc_basics.st"
verifyPass((int)gc->GetBytesInUse()<=inuse, "(int)gc->GetBytesInUse()<=inuse", __FILE__, __LINE__);

}
void ST_mmgc_basics::test4() {
#line 192 "ST_mmgc_basics.st"
verifyPass(gc->GetGCHeap()!=NULL, "gc->GetGCHeap()!=NULL", __FILE__, __LINE__);

}
void ST_mmgc_basics::test5() {
    MMgc::FixedAlloc *fa;
    fa=new MMgc::FixedAlloc(2048,MMgc::GCHeap::GetGCHeap());
#line 197 "ST_mmgc_basics.st"
verifyPass((int)fa->GetMaxAlloc()==0, "(int)fa->GetMaxAlloc()==0", __FILE__, __LINE__);
#line 198 "ST_mmgc_basics.st"
verifyPass((int)fa->GetNumBlocks()==0, "(int)fa->GetNumBlocks()==0", __FILE__, __LINE__);
    void *data1=fa->Alloc(2048);
#line 200 "ST_mmgc_basics.st"
verifyPass(MMgc::FixedAlloc::GetFixedAlloc(data1)==fa, "MMgc::FixedAlloc::GetFixedAlloc(data1)==fa", __FILE__, __LINE__);
#line 201 "ST_mmgc_basics.st"
verifyPass(fa->GetBytesInUse()==DebugSize()+2048, "fa->GetBytesInUse()==DebugSize()+2048", __FILE__, __LINE__);
#line 202 "ST_mmgc_basics.st"
verifyPass(fa->GetItemSize()==2048, "fa->GetItemSize()==2048", __FILE__, __LINE__);
    void *data2=fa->Alloc(2048);
#line 204 "ST_mmgc_basics.st"
verifyPass(MMgc::FixedAlloc::GetFixedAlloc(data2)==fa, "MMgc::FixedAlloc::GetFixedAlloc(data2)==fa", __FILE__, __LINE__);
//    AvmLog("fa->GetItemSize=%d\n",(int)fa->GetItemSize());
#line 206 "ST_mmgc_basics.st"
verifyPass((int)fa->GetItemSize()==2048, "(int)fa->GetItemSize()==2048", __FILE__, __LINE__);
    fa->Free(data1);
#line 208 "ST_mmgc_basics.st"
verifyPass((int)fa->GetItemSize()==2048, "(int)fa->GetItemSize()==2048", __FILE__, __LINE__);
#line 209 "ST_mmgc_basics.st"
verifyPass((int)fa->GetMaxAlloc()==1, "(int)fa->GetMaxAlloc()==1", __FILE__, __LINE__);
#line 210 "ST_mmgc_basics.st"
verifyPass((int)fa->GetNumBlocks()==1, "(int)fa->GetNumBlocks()==1", __FILE__, __LINE__);
    fa->Free(data2);
    delete fa;

}
void ST_mmgc_basics::test6() {
    fm=MMgc::FixedMalloc::GetFixedMalloc();
    int start=(int)fm->GetBytesInUse();
    int starttotal=(int)fm->GetTotalSize();
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
#line 219 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()==start, "(int)fm->GetBytesInUse()==start", __FILE__, __LINE__);
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
#line 221 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal, "(int)fm->GetTotalSize()==starttotal", __FILE__, __LINE__);
    void *obj=fm->Alloc(8192);
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
//    %%verify fm->GetBytesInUse()==start + 8192 + MMgc::DebugSize()
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
//    %%verify (int)fm->GetTotalSize()==starttotal+2
    fm->Free(obj);
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
#line 229 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()==start, "(int)fm->GetBytesInUse()==start", __FILE__, __LINE__);
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
#line 231 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal, "(int)fm->GetTotalSize()==starttotal", __FILE__, __LINE__);
    obj=fm->Calloc(1024,10);
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
// FixedMalloc is currently (as of redux 3229) tracking large allocs using a list of
// small objects, in some debug modes.  So we can't have a precise test here.
#line 236 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()>=start+1024*12 && (int)fm->GetBytesInUse()<=start+1024*12+64, "(int)fm->GetBytesInUse()>=start+1024*12 && (int)fm->GetBytesInUse()<=start+1024*12+64", __FILE__, __LINE__);
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
#line 238 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal+3, "(int)fm->GetTotalSize()==starttotal+3", __FILE__, __LINE__);
    fm->Free(obj);
#line 240 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()==start, "(int)fm->GetBytesInUse()==start", __FILE__, __LINE__);
#line 241 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal, "(int)fm->GetTotalSize()==starttotal", __FILE__, __LINE__);

}
void ST_mmgc_basics::test7() {
    MMgc::GCHeap *gh=MMgc::GCHeap::GetGCHeap();
    int startfreeheap=(int)gh->GetFreeHeapSize();
//    %%verify (int)gh->GetTotalHeapSize()==128
//    AvmLog("gh->GetFreeHeapSize()=%d\n",(int)gh->GetFreeHeapSize());
#line 248 "ST_mmgc_basics.st"
verifyPass((int)gh->GetFreeHeapSize()==startfreeheap, "(int)gh->GetFreeHeapSize()==startfreeheap", __FILE__, __LINE__);
//gh->Config().heapLimit = 1024;
//    %%verify (int)gh->GetTotalHeapSize()==128
//    AvmLog("gh->GetFreeHeapSize()=%d\n",(int)gh->GetFreeHeapSize());
#line 252 "ST_mmgc_basics.st"
verifyPass((int)gh->GetFreeHeapSize()==startfreeheap, "(int)gh->GetFreeHeapSize()==startfreeheap", __FILE__, __LINE__);
       void *data = gh->Alloc(10,MMgc::GCHeap::kExpand | MMgc::GCHeap::kZero);
#line 254 "ST_mmgc_basics.st"
verifyPass((int)gh->GetTotalHeapSize()>startfreeheap, "(int)gh->GetTotalHeapSize()>startfreeheap", __FILE__, __LINE__);
//    AvmLog("gh->GetFreeHeapSize()=%d\n",(int)gh->GetFreeHeapSize());
	   gh->FreeNoProfile(data);
       
}
void ST_mmgc_basics::test8() {
    MMgc::GCHeap *gh=MMgc::GCHeap::GetGCHeap();

    // Tricky: try to provoke some internal asserts
    void *d[1000];
    for ( unsigned i=0 ; i < ARRAY_SIZE(d) ; i++ ) {
        d[i] = gh->Alloc(1);
        void *data = gh->Alloc(10,MMgc::GCHeap::flags_Alloc, 4);
        gh->Free(data);
    }
    for ( unsigned i=0 ; i < ARRAY_SIZE(d) ; i++ )
        gh->Free(d[i]);

    // 
    for ( size_t k=2 ; k <= 256 ; k *= 2 ) {
        void *data = gh->Alloc(10,MMgc::GCHeap::flags_Alloc, k);
#line 274 "ST_mmgc_basics.st"
verifyPass(((uintptr_t)data & (k*MMgc::GCHeap::kBlockSize - 1)) == 0, "((uintptr_t)data & (k*MMgc::GCHeap::kBlockSize - 1)) == 0", __FILE__, __LINE__);
#line 275 "ST_mmgc_basics.st"
verifyPass(gh->Size(data) == 10, "gh->Size(data) == 10", __FILE__, __LINE__);
        gh->Free(data);
    }

}
void ST_mmgc_basics::test9() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
#line 283 "ST_mmgc_basics.st"
verifyPass((MyGCObject *)gc->FindBeginningGuarded(mygcobject)==mygcobject, "(MyGCObject *)gc->FindBeginningGuarded(mygcobject)==mygcobject", __FILE__, __LINE__);
#line 284 "ST_mmgc_basics.st"
verifyPass((MyGCObject *)gc->FindBeginningFast(mygcobject)==mygcobject, "(MyGCObject *)gc->FindBeginningFast(mygcobject)==mygcobject", __FILE__, __LINE__);

// Bugzilla 542529 - in debug mode we would assert here due to logic flaws in the allocatr
}
void ST_mmgc_basics::test10() {
    MMGC_GCENTER(gc);
    new (gc) AllocInFinalizer();
    gc->Collect(false);
#line 291 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);

}
void ST_mmgc_basics::test11() {
    MMGC_GCENTER(gc);
    new (gc) DeleteInFinalizer(new (gc, 100) GCFinalizedObject(), new (gc) GCFinalizedObject());
    //delete m; delete m; // this verifies we crash, it does
    gc->Collect(false);
#line 298 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);
    GCFinalizedObject *gcfo = new (gc) GCFinalizedObject();
    gcfo->~GCFinalizedObject();
    gcfo->~GCFinalizedObject(); // this used to be a deleteing dtor and would crash, not anymore



}
void ST_mmgc_basics::test12() {
    GC *gcb = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);
    MMGC_GCENTER(gc);
    void *a = gc->Alloc(8);
    {
        MMGC_GCENTER(gcb);
        a = gcb->Alloc(8);
        {
            MMGC_GCENTER(gc);
            a = gc->Alloc(8);
        }
        a = gcb->Alloc(8);
    }
    a = gc->Alloc(8);
    // just fishing for asserts/hangs/crashes
#line 320 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);
    delete gcb;

}
void ST_mmgc_basics::test13() {
    {
        GC *gcb = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);
        {
            MMGC_GCENTER(gcb);
            gcb->Alloc(8);
        }

        // this will cause a Collection in gcb
        GCHeap::SignalExternalFreeMemory();
        delete gcb;

        // just fishing for asserts/hangs/crashes
#line 336 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);
    }

}
void ST_mmgc_basics::test14() {
    {
        GC *gc = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);
        MMGC_GCENTER(gc);

#line 344 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::createAndLockObjects(gc), "LockerAndUnlocker::createAndLockObjects(gc)", __FILE__, __LINE__);
        gc->Collect();
        gc->Collect();
#line 347 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::testLocksHeld(gc, 1), "LockerAndUnlocker::testLocksHeld(gc, 1)", __FILE__, __LINE__);
        gc->Collect();
        gc->Collect();
#line 350 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::lockLevel2(gc), "LockerAndUnlocker::lockLevel2(gc)", __FILE__, __LINE__);
        gc->Collect();
        gc->Collect();
#line 353 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::testLocksHeld(gc, 2), "LockerAndUnlocker::testLocksHeld(gc, 2)", __FILE__, __LINE__);
        gc->Collect();
        gc->Collect();
#line 356 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::unlockLevel2(gc), "LockerAndUnlocker::unlockLevel2(gc)", __FILE__, __LINE__);
        gc->Collect();
        gc->Collect();
#line 359 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::testLocksHeld(gc, 1), "LockerAndUnlocker::testLocksHeld(gc, 1)", __FILE__, __LINE__);
        gc->Collect();
        gc->Collect();
#line 362 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::unlockLevel1(gc), "LockerAndUnlocker::unlockLevel1(gc)", __FILE__, __LINE__);

        // Bug 637695: be aware: conservative retention may foil verify below
        gc->Collect();
        gc->Collect();
#line 367 "ST_mmgc_basics.st"
verifyPass(LockerAndUnlocker::testLocksNotHeld(gc), "LockerAndUnlocker::testLocksNotHeld(gc)", __FILE__, __LINE__);

        delete gc;
    }

}
void ST_mmgc_basics::test15() {
    {
        GC *testGC = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);
        {
            MMGC_GCENTER(testGC);
            testGC->StartIncrementalMark();
            // self test for tricky GCRoot deletion logic
            // do this a bunch, idea is to try to hit GetItemAbove border edge cases
            //GCMarkStack& ms = testGC->m_incrementalWork;
            for(int i=0;i<10000;i++) {
                //GCRoot *fauxRoot = new GCRoot(testGC, new char[GC::kMarkItemSplitThreshold*2], GC::kMarkItemSplitThreshold*2);
                //testGC->MarkAllRoots();
                // tail of fauxRoot is on stack
                //uintptr_t sentinel = fauxRoot->GetMarkStackSentinelPointer();
                //if(sentinel) {
                //    const void* ptr;
                //    ms.Read_RootProtector(sentinel, ptr);
                //    %%verify ptr == fauxRoot
                //    uintptr_t tail = ms.GetItemAbove(sentinel);
                //    %%verify ms.GetEndAt(tail) == fauxRoot->End()
                //    %%verify sentinel != 0
                //}
                //delete [] (char*)fauxRoot->Get();
                //delete fauxRoot;
                //if(sentinel) {
                //    %%verify ms.P(sentinel) == GCMarkStack::kDeadItem
                //    %%verify ms.GetSentinel1TypeAt(ms.GetItemAbove(sentinel)) == GCMarkStack::kDeadItem
                //}
#line 400 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);
            }
            testGC->Mark();
            testGC->ClearMarkStack();
            testGC->ClearMarks();
        }
        delete testGC;
    }

}
void create_mmgc_basics(AvmCore* core) { new ST_mmgc_basics(core); }
}
#endif
