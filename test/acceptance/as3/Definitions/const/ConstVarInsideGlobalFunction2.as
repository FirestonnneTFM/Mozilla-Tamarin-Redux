/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions\const";                  // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";           // Version of JavaScript or ECMA
var TITLE   = "const inside a global function with multiple arguments";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();

function constMultiArgs( arg1, arg2, arg3 ) {

    const localVar = arg1 + arg2 + arg3;
    return localVar;

}

constMultiArgs( 10, -20, 30 );

AddTestCase( "Calling a global multi-arg function which declares a local const variable", 20, constMultiArgs( 10, -20, 30 ));

test();
