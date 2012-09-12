/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
class OneOptArgFunctionClass{

    function returnString(s:String = "outside package inside class",... rest):String { return s; }
    function returnBoolean(b:Boolean = true,... rest):Boolean { return b; }
    function returnNumber(n:Number = 10,... rest):Number { return n; }

}


