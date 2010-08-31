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
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
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

package {
    import avmplus.System

    var SECTION = "Vector";
    var VERSION = "as3";
    startTest();
    var TITLE   = "bug 504525";

    writeHeaderToLog( SECTION + " "+ TITLE );

    public function vtest()
    {
        var v1 = new Vector.<int>(); v1.push( 1 );
        var v2 = new Vector.<int>(); v2.push( 2 );
        var v3 = new Vector.<int>(); v3.push( 3 );
        var v4 = new Vector.<int>(); v4.push( 4 );

        return v1.concat( v2, v3, v4 );
    }

    var result = vtest();
    
    if (System.swfVersion < 11) {
        AddTestCase("Test Vector.concat with SWF 9 or 10 behavior",
          "1,4,3,2",
          result.toString());
    } else { // swf 11+
        AddTestCase("Test Vector.concat with Latest behavior",
          "1,2,3,4",
          result.toString());
    }

    test();

}