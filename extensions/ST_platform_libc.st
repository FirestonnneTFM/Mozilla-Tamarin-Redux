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

%%component platform
%%category libc

%%decls

union {
  char buf[200];
  char biggerBuf[400];
};
int ret;
int n;

%%test snprintf

// Using multiple arguments increases the chance of finding bugs in
// size-specific variable argument parsing.

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%d,%d-", -10, 20);
%%verify VMPI_strcmp(buf, "--10,20-") == 0
%%verify ret == 8

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%i,%i-", -10, 20);
%%verify VMPI_strcmp(buf, "--10,20-") == 0
%%verify ret == 8

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%li,%d-", (long)-10,37);
%%verify VMPI_strcmp(buf, "--10,37-") == 0
%%verify ret == 8

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%ld,%d-", (long)-10,37);
%%verify VMPI_strcmp(buf, "--10,37-") == 0
%%verify ret == 8

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%u,%d-", 10, 37);
%%verify VMPI_strcmp(buf, "-10,37-") == 0
%%verify ret == 7

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%lu,%d-", (unsigned long)10, 37);
%%verify VMPI_strcmp(buf, "-10,37-") == 0
%%verify ret == 7

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%x,%x-", 1023, 2047);
%%verify VMPI_strcmp(buf, "-3ff,7ff-") == 0
%%verify ret == 9

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%X,%X-", 1023, 2047);
%%verify VMPI_strcmp(buf, "-3FF,7FF-") == 0
%%verify ret == 9

  // The VC++ _sprintf that underlies VMPI_snprintf uses three digits
  // in the exponent, which is OK according to the spec (which says
  // "at least two").  Other platforms may have similar issues.

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%e,%f,%g-", 1.0, 2.5, 3.25e10);
%%verify VMPI_strcmp(buf, "-1.000000e+00,2.500000,3.25e+10-") == 0 || VMPI_strcmp(buf, "-1.000000e+000,2.500000,3.25e+010-") == 0
%%verify ret == 32 || ret == 34

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%E,%F,%G-", 1.0, 2.5, 3.25e10);
%%verify VMPI_strcmp(buf, "-1.000000E+00,2.500000,3.25E+10-") == 0 || VMPI_strcmp(buf, "-1.000000E+000,2.500000,3.25E+010-") == 0
%%verify ret == 32 || ret == 34

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%c%c%c-", 'f','o','o');
%%verify VMPI_strcmp(buf, "-foo-") == 0
%%verify ret == 5

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%s%s-", "foo", "bar");
%%verify VMPI_strcmp(buf, "-foobar-") == 0
%%verify ret == 8

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "-%%%%-");
%%verify VMPI_strcmp(buf, "-%%-") == 0
%%verify ret == 4

ret = VMPI_snprintf(buf, ARRAY_SIZE(buf), "%p%c%p", &buf, 0, &buf);
%%verify buf[0] == '0' && buf[1] == 'x'
%%verify VMPI_strcmp(buf, buf+VMPI_strlen(buf)+1) == 0

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
%%verify ret == 252
%%verify buf[ARRAY_SIZE(buf)-1] == 0
%%verify buf[ARRAY_SIZE(buf)-2] == 'x'
%%verify biggerBuf[ARRAY_SIZE(buf)] == 'z'

// Number too long
VMPI_memset(biggerBuf, 'z', ARRAY_SIZE(biggerBuf));
ret = VMPI_snprintf(buf, 3, "%d", 102);
%%verify ret == 3
%%verify VMPI_strcmp(buf,"10") == 0
%%verify buf[3] == 'z'

// No output at all
VMPI_memset(biggerBuf, 'z', ARRAY_SIZE(biggerBuf));
ret = VMPI_snprintf(buf, 0, "%d", 102);
%%verify ret == 3
%%verify *buf == 'z'
