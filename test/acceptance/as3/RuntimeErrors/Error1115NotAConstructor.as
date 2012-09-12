/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import avmplus.System;

var CODE_OLD = 1115; // _ is not a constructor.
var CODE_NEW = 1007; // Instantiation attempted on a non-constructor.

var CODE;

if (System.swfVersion >= 11) {
     CODE = CODE_NEW;
} else {
    if ((playerType == 'AVMPlus') && (System.getRunmode().indexOf('jit') != -1)) {
        CODE = CODE_NEW;
    } else {
        CODE = CODE_OLD;
    }
}

//-----------------------------------------------------------
startTest();
//-----------------------------------------------------------

try {
        var z = "no error";
        var OBJECT = new Object();
        var o = new OBJECT();
} catch (err) {
        z = err.toString();
} finally {
        AddTestCase("[Object] Runtime Error", "TypeError: Error #" + CODE, typeError(z));
}

try {
        var z = "no error";
        var OBJECT = null;
        var o = new OBJECT();
} catch (err) {
        z = err.toString();
} finally {
        AddTestCase("[null] Runtime Error", "TypeError: Error #" + CODE, typeError(z));
}

try {
        var z = "no error";
        var OBJECT;
        var o = new OBJECT();
} catch (err) {
        z = err.toString();
} finally {
        AddTestCase("[undefined] Runtime Error", "TypeError: Error #" + CODE, typeError(z));
}

//-----------------------------------------------------------
test();
//-----------------------------------------------------------
