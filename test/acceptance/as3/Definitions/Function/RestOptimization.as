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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

/* Acceptance test for rest array optimization.  We measure two
   programs, one where the analysis must definitely succeed and one
   where it ought to fail.  The ratio of the scores of the optimized
   program to those of the unoptimized program should be at least
   five.

   This acceptance test may start failing if:

    - the analysis gets broken
    - the analysis improves so much that the unoptimized program becomes optimized,
      this is not likely
    - allocation and object initialization speeds improve so much that
      rest array allocation starts to become affordable

   The test does not apply to builds with an installed debugger - the analysis
   is disabled if the debugger is present.
*/

var SECTION = "Function";           // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";                // Version of ECMAScript or ActionScript
var TITLE   = "rest optimiztation"; // Provide ECMA section title or a description
var BUGNUMBER = "569321";           // bugzilla.mozilla.org

startTest();

class C {
    function push(...v):void {
        y = v.length;
    x = v[0];
    }
    function get length(): uint { return 0 }
    function set length(n: uint): void { }
    var x:*;
    var y:*;
}

function pushloopC():uint {
    var a:C = new C;
    for ( var i:int=0 ; i < 100000 ; i+=10 ) {
    a.length = 0;
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    }
    return a.length;
}

class D {
    function push(...v):void {
        w = v;
    x = w[0];
    }
    function get length(): uint { return 0 }
    function set length(n: uint): void { }
    var x:*;
    var w:*;
}

function pushloopD():uint {
    var a:D = new D;
    for ( var i:int=0 ; i < 100000 ; i+=10 ) {
    a.length = 0;
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    a.push(i);
    }
    return a.length;
}

function TEST(run:Function): Number {
    var then:Date = new Date();
    var iterations:int = 0;
    for (;;) {
    var now:Date = new Date();
    if (now.getTime() - then.getTime() > 1000.0)
        break;
    iterations++;
    run();
    }
    return iterations*(now.getTime()-then.getTime());
}

var m1 = TEST(pushloopC);
var m2 = TEST(pushloopD);

AddTestCase( "Rest array optimization (not enabled with the debugger!)", true, (m1/m2 > 5.0));

test();
