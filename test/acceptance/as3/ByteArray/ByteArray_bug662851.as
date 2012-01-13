/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
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

    import flash.utils.ByteArray
    import avmplus.* ;      // System class in the avmshell

    var SECTION = "ByteArray";
    var VERSION = "as3";
    startTest();
    var TITLE   = "test ByteArray class exceeding MMgc::GCHeap::kMaxObjectSize";

    writeHeaderToLog( SECTION + " "+ TITLE );

    /* bz: Bug 662851 - Make EnsureWritableCapacity take uint32_t instead of uint64_t since all callers pass uint32_t
       First 2 testcases will produce an error via mmfx_new_array_opt() returning null WHEN  run on 32bit platform,
       however on 64bit platforms this will succeed to allocate a lot of memory, so do not run these on 64bit
           http://hg.mozilla.org/tamarin-redux/annotate/47d6d75afd61/core/ByteArrayGlue.cpp#l147
       Last 2 testcases will produce an error via the minimumCapacity check
           http://hg.mozilla.org/tamarin-redux/annotate/47d6d75afd61/core/ByteArrayGlue.cpp#l132
    */

    var is32bit:Boolean = (System.getFeatures().indexOf("AVMSYSTEM_32BIT") != -1);
    var i:Number;
    if (is32bit) {
	i=0xFFFFC000;
    } else {
	i=0xFFFFE000;
    }

    for(;i<0x100000000;i+=4096)
    {
	var expected:String = "Error #1000";
        var result:String = "no error";
	try {
	    new ByteArray().length = i;
	} catch(err) {
	    result = grabError(err, err.toString());
	}
	AddTestCase("ByteArray.length "+ i, expected, result);
    }

    test();


