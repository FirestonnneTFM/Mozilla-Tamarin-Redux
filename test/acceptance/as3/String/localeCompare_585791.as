/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    import avmplus.System

    var SECTION = "String";
    var VERSION = "as3";
    startTest();
    var TITLE   = "bug 585791";

    writeHeaderToLog( SECTION + " "+ TITLE );

    function sign(n:int):int
    {
        if (n < 0) return -1;
        else if (n > 0) return 1;
        else return 0;
    }
    
    var r;
    
    if (System.swfVersion < 11) {
        r = sign("m".localeCompare(null));
        AddTestCase('Test "m".localeCompare(null) with SWF9 behavior',
          0,
          r);
    
        r = sign("null".localeCompare(null));
        AddTestCase('Test "null".localeCompare(null) with SWF9 behavior',
          0,
          r);
    
        r = sign("o".localeCompare(null));
        AddTestCase('Test "o".localeCompare(null) with SWF9 behavior',
          0,
          r);
    
        r = sign("".localeCompare(null));
        AddTestCase('Test "".localeCompare(null) with SWF9 behavior',
          1,
          r);
    
        r = sign("t".localeCompare(undefined));
        AddTestCase('Test "t".localeCompare(undefined) with SWF9 behavior',
          0,
          r);
    
        r = sign("undefined".localeCompare(undefined));
        AddTestCase('Test "undefined".localeCompare(undefined) with SWF9 behavior',
          0,
          r);
    
        r = sign("v".localeCompare(undefined));
        AddTestCase('Test "v".localeCompare(undefined) with SWF9 behavior',
          0,
          r);
    
        r = sign("".localeCompare(undefined));
        AddTestCase('Test "".localeCompare(undefined) with SWF9 behavior',
          1,
          r);
    
    } else {    // swf version 11+

        r = sign("m".localeCompare(null));
        AddTestCase('Test "m".localeCompare(null) with SWF11+ behavior',
          -1,
          r);
    
        r = sign("null".localeCompare(null));
        AddTestCase('Test "null".localeCompare(null) with SWF11+ behavior',
          0,
          r);
    
        r = sign("o".localeCompare(null));
        AddTestCase('Test "o".localeCompare(null) with SWF11+ behavior',
          1,
          r);
    
        r = sign("".localeCompare(null));
        AddTestCase('Test "".localeCompare(null) with SWF11+ behavior',
          -1,
          r);
    
        r = sign("t".localeCompare(undefined));
        AddTestCase('Test "t".localeCompare(undefined) with SWF11+ behavior',
          -1,
          r);
    
        r = sign("undefined".localeCompare(undefined));
        AddTestCase('Test "undefined".localeCompare(undefined) with SWF11+ behavior',
          0,
          r);
    
        r = sign("v".localeCompare(undefined));
        AddTestCase('Test "v".localeCompare(undefined) with SWF11+ behavior',
          1,
          r);
    
        r = sign("".localeCompare(undefined));
        AddTestCase('Test "".localeCompare(undefined) with SWF11+ behavior',
          -1,
          r);
    }

    test();