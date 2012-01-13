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

// Bug 603411 - SECURITY: AvmCore dtor needs to clear CallStackNode chain

%%component mmgc
%%category bugzilla_603411
%%ifdef DEBUGGER

%%prefix

class MyDebugger : public Debugger
{
public:
    MyDebugger(AvmCore *core, avmplus::Debugger::TraceLevel tracelevel) : Debugger(core, tracelevel) {}
    ~MyDebugger() {}

    virtual void enterDebugger() {}
    virtual bool filterException(avmplus::Exception*, bool) { return false; }
    virtual bool hitWatchpoint() {return false; }
};


class MyAvmCore : public avmplus::AvmCore
{
public:
    MyAvmCore(MMgc::GC* gc) : AvmCore(gc, kApiVersionSeries_FP) { initBuiltinPool(1); }
    ~MyAvmCore() {}

    virtual void interrupt(Toplevel*, InterruptReason) { }
    virtual void stackOverflow(Toplevel*) { }
    virtual avmplus::String* readFileForEval(avmplus::String*, avmplus::String*) { return NULL; }
    virtual avmplus::ApiVersion getDefaultAPI() { return kApiVersion_VM_INTERNAL; }
    Debugger* createDebugger(int tracelevel) { return new (this->gc) MyDebugger(this, (avmplus::Debugger::_TraceLevel)tracelevel); }
};


class MyTestClass
{
public:
    MyTestClass(MyAvmCore* core) : m_core(core)
    {
        (void)core;
    }

    void testAvmCoreDelete()
    {
        // create CallStackNode
        CallStackNode csn(m_core, "Date");

        // delete core
        delete m_core;
    }
private:
    MyAvmCore* m_core;
};

%%decls
private:
    MyTestClass* testClass;
    MyAvmCore*   testCore;
%%prologue

%%epilogue
    testClass = NULL;
    testCore = NULL;

%%test test1
    // create our own core
    testCore = new MyAvmCore(core->gc);
    testClass = new MyTestClass(testCore);
    testClass->testAvmCoreDelete();

    %%verify true
