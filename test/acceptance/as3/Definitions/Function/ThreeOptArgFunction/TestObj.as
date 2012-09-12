/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package ThreeOptArgFunction {

    class TestObjInner{
        
      function returnArgumentsInner(s:String = "Str1", b:Boolean = true, n:Number = 10, ... rest) {
        str = s;
        bool = b;
        num = n;
      }
        
    }

    public class TestObj extends TestObjInner {
        
        public function returnArguments() { returnArgumentsInner("Str1", true, 10, 12); }
        
    }

}

