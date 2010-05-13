// Generated from ST_platform_libc.st
// -*- mode: c -*-
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
class ST_platform_libc : public Selftest {
public:
ST_platform_libc(AvmCore* core);
virtual void run(int n);
private:
static const char* ST_names[];
void test0();

union {
  char buf[200];
  char biggerBuf[400];
};
int ret;
int n;

};
ST_platform_libc::ST_platform_libc(AvmCore* core)
    : Selftest(core, "platform", "libc", ST_platform_libc::ST_names)
{}
const char* ST_platform_libc::ST_names[] = {"snprintf", NULL };
void ST_platform_libc::run(int n) {
switch(n) {
case 0: test0(); return;
}
}
void ST_platform_libc::test0() {

// Using multiple arguments increases the chance of finding bugs in
// size-specific variable argument parsing.

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%d,%d-", -10, 20);
#line 58 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "--10,20-") == 0, "VMPI_strcmp(buf, \"--10,20-\") == 0", __FILE__, __LINE__);
#line 59 "ST_platform_libc.st"
verifyPass(ret == 8, "ret == 8", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%i,%i-", -10, 20);
#line 62 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "--10,20-") == 0, "VMPI_strcmp(buf, \"--10,20-\") == 0", __FILE__, __LINE__);
#line 63 "ST_platform_libc.st"
verifyPass(ret == 8, "ret == 8", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%li,%d-", (long)-10,37);
#line 66 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "--10,37-") == 0, "VMPI_strcmp(buf, \"--10,37-\") == 0", __FILE__, __LINE__);
#line 67 "ST_platform_libc.st"
verifyPass(ret == 8, "ret == 8", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%ld,%d-", (long)-10,37);
#line 70 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "--10,37-") == 0, "VMPI_strcmp(buf, \"--10,37-\") == 0", __FILE__, __LINE__);
#line 71 "ST_platform_libc.st"
verifyPass(ret == 8, "ret == 8", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%u,%d-", 10, 37);
#line 74 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-10,37-") == 0, "VMPI_strcmp(buf, \"-10,37-\") == 0", __FILE__, __LINE__);
#line 75 "ST_platform_libc.st"
verifyPass(ret == 7, "ret == 7", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%lu,%d-", (unsigned long)10, 37);
#line 78 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-10,37-") == 0, "VMPI_strcmp(buf, \"-10,37-\") == 0", __FILE__, __LINE__);
#line 79 "ST_platform_libc.st"
verifyPass(ret == 7, "ret == 7", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%x,%x-", 1023, 2047);
#line 82 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-3ff,7ff-") == 0, "VMPI_strcmp(buf, \"-3ff,7ff-\") == 0", __FILE__, __LINE__);
#line 83 "ST_platform_libc.st"
verifyPass(ret == 9, "ret == 9", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%X,%X-", 1023, 2047);
#line 86 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-3FF,7FF-") == 0, "VMPI_strcmp(buf, \"-3FF,7FF-\") == 0", __FILE__, __LINE__);
#line 87 "ST_platform_libc.st"
verifyPass(ret == 9, "ret == 9", __FILE__, __LINE__);

  // The VC++ _sprintf that underlies VMPI_snprintf uses three digits
  // in the exponent, which is OK according to the spec (which says
  // "at least two").  Other platforms may have similar issues.

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%e,%f,%g-", 1.0, 2.5, 3.25e10);
#line 94 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-1.000000e+00,2.500000,3.25e+10-") == 0 || VMPI_strcmp(buf, "-1.000000e+000,2.500000,3.25e+010-") == 0, "VMPI_strcmp(buf, \"-1.000000e+00,2.500000,3.25e+10-\") == 0 || VMPI_strcmp(buf, \"-1.000000e+000,2.500000,3.25e+010-\") == 0", __FILE__, __LINE__);
#line 95 "ST_platform_libc.st"
verifyPass(ret == 32 || ret == 34, "ret == 32 || ret == 34", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%E,%F,%G-", 1.0, 2.5, 3.25e10);
#line 98 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-1.000000E+00,2.500000,3.25E+10-") == 0 || VMPI_strcmp(buf, "-1.000000E+000,2.500000,3.25E+010-") == 0, "VMPI_strcmp(buf, \"-1.000000E+00,2.500000,3.25E+10-\") == 0 || VMPI_strcmp(buf, \"-1.000000E+000,2.500000,3.25E+010-\") == 0", __FILE__, __LINE__);
#line 99 "ST_platform_libc.st"
verifyPass(ret == 32 || ret == 34, "ret == 32 || ret == 34", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%c%c%c-", 'f','o','o');
#line 102 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-foo-") == 0, "VMPI_strcmp(buf, \"-foo-\") == 0", __FILE__, __LINE__);
#line 103 "ST_platform_libc.st"
verifyPass(ret == 5, "ret == 5", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%s%s-", "foo", "bar");
#line 106 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-foobar-") == 0, "VMPI_strcmp(buf, \"-foobar-\") == 0", __FILE__, __LINE__);
#line 107 "ST_platform_libc.st"
verifyPass(ret == 8, "ret == 8", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%%%%-");
#line 110 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, "-%%-") == 0, "VMPI_strcmp(buf, \"-%%-\") == 0", __FILE__, __LINE__);
#line 111 "ST_platform_libc.st"
verifyPass(ret == 4, "ret == 4", __FILE__, __LINE__);

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "%p%c%p", &buf, 0, &buf);
#line 114 "ST_platform_libc.st"
verifyPass(buf[0] == '0' && buf[1] == 'x', "buf[0] == '0' && buf[1] == 'x'", __FILE__, __LINE__);
#line 115 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf, buf+VMPI_strlen(buf)+1) == 0, "VMPI_strcmp(buf, buf+VMPI_strlen(buf)+1) == 0", __FILE__, __LINE__);

// String too long
VMPI_memset(biggerBuf, 'z', ARRAY_SIZE(biggerBuf));
ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "%s%n--",
		    "abcdefghijklmnopqrstuvwxy" // 25 chars
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy"
		    "abcdefghijklmnopqrstuvwxy",
		    &n);
#line 131 "ST_platform_libc.st"
verifyPass(ret == 252, "ret == 252", __FILE__, __LINE__);
#line 132 "ST_platform_libc.st"
verifyPass(buf[ARRAY_SIZE(buf)-1] == 0, "buf[ARRAY_SIZE(buf)-1] == 0", __FILE__, __LINE__);
#line 133 "ST_platform_libc.st"
verifyPass(buf[ARRAY_SIZE(buf)-2] == 'x', "buf[ARRAY_SIZE(buf)-2] == 'x'", __FILE__, __LINE__);
#line 134 "ST_platform_libc.st"
verifyPass(biggerBuf[ARRAY_SIZE(buf)] == 'z', "biggerBuf[ARRAY_SIZE(buf)] == 'z'", __FILE__, __LINE__);

// Number too long
VMPI_memset(biggerBuf, 'z', ARRAY_SIZE(biggerBuf));
ret = VMPI_snprintf(buf, 3, "%d", 102);
#line 139 "ST_platform_libc.st"
verifyPass(ret == 3, "ret == 3", __FILE__, __LINE__);
#line 140 "ST_platform_libc.st"
verifyPass(VMPI_strcmp(buf,"10") == 0, "VMPI_strcmp(buf,\"10\") == 0", __FILE__, __LINE__);
#line 141 "ST_platform_libc.st"
verifyPass(buf[3] == 'z', "buf[3] == 'z'", __FILE__, __LINE__);

// No output at all
VMPI_memset(biggerBuf, 'z', ARRAY_SIZE(biggerBuf));
ret = VMPI_snprintf(buf, 0, "%d", 102);
#line 146 "ST_platform_libc.st"
verifyPass(ret == 3, "ret == 3", __FILE__, __LINE__);
#line 147 "ST_platform_libc.st"
verifyPass(*buf == 'z', "*buf == 'z'", __FILE__, __LINE__);

}
void create_platform_libc(AvmCore* core) { new ST_platform_libc(core); }
}
#endif
