// Generated from ST_mmgc_mmfx_array.st
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

#include "avmshell.h"
#ifdef VMCFG_SELFTEST
namespace avmplus {
class ST_mmgc_mmfx_array : public Selftest {
public:
ST_mmgc_mmfx_array(AvmCore* core);
virtual void run(int n);
private:
static const char* ST_names[];
static const bool ST_explicits[];
void test0();
void test1();
void test2();
};
ST_mmgc_mmfx_array::ST_mmgc_mmfx_array(AvmCore* core)
    : Selftest(core, "mmgc", "mmfx_array", ST_mmgc_mmfx_array::ST_names,ST_mmgc_mmfx_array::ST_explicits)
{}
const char* ST_mmgc_mmfx_array::ST_names[] = {"mmfx_new_array_oom","mmfx_new_array_opts_canFail","mmfx_new_array_opts_oom", NULL };
const bool ST_mmgc_mmfx_array::ST_explicits[] = {true,true,true, false };
void ST_mmgc_mmfx_array::run(int n) {
switch(n) {
case 0: test0(); return;
case 1: test1(); return;
case 2: test2(); return;
}
}
using namespace MMgc;

// There are different failure modes.
// 1) if you call mmfx_new_array() it can OOM:
//     -> it should OOM and shutdown
// 2) if you call mmfx_new_array_opts(canFail) and it OOMs:
//     -> it should return NULL and NOT OOM
// 3) if you call mmfx_new_aray_opts() without the canFail flag:
//     -> it should OOM and shutdown


void ST_mmgc_mmfx_array::test0() {
    // This will cause an OOM abort and exit, run with -memlimit 1024
    int* m_ints = mmfx_new_array(int, 1048576);
    mmfx_delete_array(m_ints);
    m_ints = NULL;
#line 60 "ST_mmgc_mmfx_array.st"
verifyPass(false, "false", __FILE__, __LINE__);

}
void ST_mmgc_mmfx_array::test1() {
    // This should fail and return NULL, run with -memlimit 1024
    int* m_ints = mmfx_new_array_opt(int, 1048576, MMgc::kCanFail);
#line 65 "ST_mmgc_mmfx_array.st"
verifyPass(m_ints == NULL, "m_ints == NULL", __FILE__, __LINE__);
    mmfx_delete_array(m_ints);
    m_ints = NULL;

}
void ST_mmgc_mmfx_array::test2() {
    // This will cause an OOM abort and exit, run with -memlimit 1024
    int* m_ints = mmfx_new_array_opt(int, 1048576, MMgc::kZero);
    mmfx_delete_array(m_ints);
    m_ints = NULL;
#line 74 "ST_mmgc_mmfx_array.st"
verifyPass(false, "false", __FILE__, __LINE__);



}
void create_mmgc_mmfx_array(AvmCore* core) { new ST_mmgc_mmfx_array(core); }
}
#endif
