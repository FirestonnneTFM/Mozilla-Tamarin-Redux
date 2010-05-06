/* DO NOT EDIT THIS FILE!  It was generated by utils/apivergen.abc. */

/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License+"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL+"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

/*
[0,player,full]=660:FP_9_0
[0,air,full]=661:AIR_1_0
[1,player,full]=662:FP_10_0
[1,air,full]=663:AIR_1_5
[2,air,full]=664:AIR_1_5_1
[3,player,full]=665:FP_10_0_32
[3,air,full]=666:AIR_1_5_2
[4,player,full]=667:FP_10_1
[4,player,system]=669:FP_SYS
[4,air,full]=668:AIR_2_0
[4,air,system]=670:AIR_SYS
*/

static const uint32_t _min_version_num = 660;
static const uint32_t _max_version_num = 670;
static const uint32_t _versions_count[] = {11, 6, 9, 5, 4, 6, 3, 4, 2, 2, 1, };

static const uint32_t _versions [][11] = {
  {660, 661, 662, 663, 664, 665, 666, 667, 669, 668, 670, },
  {661, 663, 664, 666, 668, 670, },
  {662, 663, 664, 665, 666, 667, 669, 668, 670, },
  {663, 664, 666, 668, 670, },
  {664, 666, 668, 670, },
  {665, 666, 667, 669, 668, 670, },
  {666, 668, 670, },
  {667, 669, 668, 670, },
  {668, 670, },
  {669, 670, },
  {670, },
};
static const uint32_t _uris_count = 34;
static const char* _uris [] = {
  "",
  "__AS3__.vec",
  "adobe.utils",
  "avmplus",
  "flash.accessibility",
  "flash.automation",
  "flash.data",
  "flash.debugger",
  "flash.desktop",
  "flash.display",
  "flash.errors",
  "flash.events",
  "flash.external",
  "flash.filesystem",
  "flash.filters",
  "flash.geom",
  "flash.globalization",
  "flash.html",
  "flash.html.script",
  "flash.media",
  "flash.net",
  "flash.net.dns",
  "flash.net.drm",
  "flash.printing",
  "flash.profiler",
  "flash.sampler",
  "flash.security",
  "flash.system",
  "flash.text",
  "flash.text.engine",
  "flash.text.ime",
  "flash.ui",
  "flash.utils",
  "flash.xml",
};
static const int32_t _api_compat [] = {0x7ff, 0x55a, 0x7fc, 0x558, 0x550, 0x7e0, 0x540, 0x780, 0x500, 0x600, 0x400, };
static const uint32_t _max_nonsys_version_num = 668;
