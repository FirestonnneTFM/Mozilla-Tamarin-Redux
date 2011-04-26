// Generated from ST_avmplus_builtins.st
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
#if !defined VMCFG_ARM
namespace avmplus {
class ST_avmplus_builtins : public Selftest {
public:
ST_avmplus_builtins(AvmCore* core);
virtual void run(int n);
private:
static const char* ST_names[];
static const bool ST_explicits[];
void test0();
};
ST_avmplus_builtins::ST_avmplus_builtins(AvmCore* core)
    : Selftest(core, "avmplus", "builtins", ST_avmplus_builtins::ST_names,ST_avmplus_builtins::ST_explicits)
{}
const char* ST_avmplus_builtins::ST_names[] = {"WeakValueHashTable", NULL };
const bool ST_avmplus_builtins::ST_explicits[] = {false, false };
void ST_avmplus_builtins::run(int n) {
switch(n) {
case 0: test0(); return;
}
}
void ST_avmplus_builtins::test0() {
    WeakValueHashtable* tbl = WeakValueHashtable::create(core->gc);
    String* fhtagn = String::createLatin1(core, "Fhtagn!");
    for ( int i=0 ; i < 500 ; i++ ) {
        tbl->add(atomFromIntptrValue(i), (i & 1) ? String::createLatin1(core, "Cthulhu!")->atom() : fhtagn->atom());
    }
    core->gc->Collect();
    core->gc->Collect();
    int sum = 0;
    for ( int i=0 ; i < 500 ; i++ ) {
        Atom a = tbl->get(atomFromIntptrValue(i));
        if (a != AtomConstants::undefinedAtom)
            sum++;
    }

// Retain at least 250, but it would be unreasonable to retain more than 300
#line 61 "ST_avmplus_builtins.st"
verifyPass(sum >= 250 && sum <= 300, "sum >= 250 && sum <= 300", __FILE__, __LINE__);

}
void create_avmplus_builtins(AvmCore* core) { new ST_avmplus_builtins(core); }
}
#endif
#endif
