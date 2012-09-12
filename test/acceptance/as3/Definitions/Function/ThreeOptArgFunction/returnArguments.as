/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package ThreeOptArgFunction {

    function returnArgumentsInner(s:String = "Str2", b:Boolean = false, n:Number = 20, ... rest) {
    
        str = s;
        bool = b;
        num = n;
    }
    
    
    public function returnArguments() { returnArgumentsInner("Str2",false,20,true); }

}

