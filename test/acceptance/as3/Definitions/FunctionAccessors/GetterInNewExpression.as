/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import GetterInNewExpression.*;

var SECTION = "FunctionAccessors";
var VERSION = "AS3";
var TITLE   = "Function Accessors";
var BUGNUMBER = "";

startTest();



function get someClass2():GetterInNewExpression{ return GetterInNewExpression; }



var result:String="no exception";

try {
    var b:GetterInNewExpression= new someClass2();
    
} catch (e1:TypeError) {
    result = e1.toString();
}


AddTestCase("Getter in new expression with strong typing", "TypeError: Error #1034", typeError(result));

result = "no exception";
try {
    var c = new someClass2();
    
} catch (e2:TypeError) {
    result = e2.toString();;
}
AddTestCase("Getter in new expression without strong typing", "TypeError: Error #1034", typeError(result));
AddTestCase("Getter in new expression without strong typing", false, (c is Object));

test();

