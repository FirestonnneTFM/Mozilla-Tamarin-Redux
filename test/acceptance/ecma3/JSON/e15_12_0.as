/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package {

    var SECTION = "15.2";
    var VERSION = "ECMA_3";
    startTest();
    var TITLE   = "JSON ecma-262 testcases";

    writeHeaderToLog( SECTION + " "+ TITLE);

    startTest();

    AddTestCase("15.12-0-1: JSON must be a built-in object","object",typeof(JSON));

    // 15.12-0-2: JSON must not support the [[Construct]] method
    var constructorException="no exception";
    try {
        var j = new JSON();
    } catch(e) {
        constructorException=e.toString();
        constructorException=removeExceptionDetail(constructorException);
    }
    AddTestCase("15.12-0-2: JSON must not support the [[Construct]] method","ArgumentError: Error #2012",constructorException);

    // 15.12-0-3: JSON must not support the [[Call] method
    var callException="no exception";
    try {
        var k = JSON();
    } catch(e) {
        callException=e.toString();
        callException=removeExceptionDetail(callException);
    }
    AddTestCase("15.12-0-3: JSON must not support the [[Call]] method","ArgumentError: Error #1112",callException);
    
    // 15.12-0-4: JSON object properties must be non enumerable
    var i=0;
    for (var p in JSON) {
        i++;
    }
    AddTestCase("15.12-0-4: JSON object properties must be non enumerable",0,i);

    test();

}
