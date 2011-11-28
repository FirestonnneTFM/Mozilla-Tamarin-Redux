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
 * Portions created by the Initial Developer are Copyright (C) 2005-2011
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

// This test is a smaller model version of AccessorSpray, which
// attempts to catch cases of misidentifying user-provided
// getter/setter methods and confusing them with methods of builtins.
//
// If you see failures in both AccessorSpray and AccessorSpraySmall,
// then you should use AccessorSpraySmall for debugging your problem.

package AccessorSpraySmall {
    public class UntypedGetterSpray {

        public function get a1000() { return 1000; } public function get a1001() { return 1001; }
        public function get a1002() { return 1002; } public function get a1003() { return 1003; }
        public function get a1004() { return 1004; } public function get a1005() { return 1005; }
        public function get a1006() { return 1006; } public function get a1007() { return 1007; }
        public function get a1008() { return 1008; } public function get a1009() { return 1009; }

    }

    public class UintGetterSpray {

        public function get u1000():uint { return 1000; } public function get u1001():uint { return 1001; }
        public function get u1002():uint { return 1002; } public function get u1003():uint { return 1003; }
        public function get u1004():uint { return 1004; } public function get u1005():uint { return 1005; }
        public function get u1006():uint { return 1006; } public function get u1007():uint { return 1007; }
        public function get u1008():uint { return 1008; } public function get u1009():uint { return 1009; }

    }


    public class UntypedSetterSpray {
        public var a = 10;

        public function set a1000(x) { a = x+1000; } public function set a1001(x) { a = x+1001; }
        public function set a1002(x) { a = x+1002; } public function set a1003(x) { a = x+1003; }
        public function set a1004(x) { a = x+1004; } public function set a1005(x) { a = x+1005; }
        public function set a1006(x) { a = x+1006; } public function set a1007(x) { a = x+1007; }
        public function set a1008(x) { a = x+1008; } public function set a1009(x) { a = x+1009; }

    }

    public class UintSetterSpray {
        public var a = 10;

        public function set u1000(x:uint):void { a = x-1000; } public function set u1001(x:uint):void { a = x-1001; }
        public function set u1002(x:uint):void { a = x-1002; } public function set u1003(x:uint):void { a = x-1003; }
        public function set u1004(x:uint):void { a = x-1004; } public function set u1005(x:uint):void { a = x-1005; }
        public function set u1006(x:uint):void { a = x-1006; } public function set u1007(x:uint):void { a = x-1007; }
        public function set u1008(x:uint):void { a = x-1008; } public function set u1009(x:uint):void { a = x-1009; }

    }

}

import AccessorSpraySmall.UntypedGetterSpray
import AccessorSpraySmall.UintGetterSpray
import AccessorSpraySmall.UntypedSetterSpray
import AccessorSpraySmall.UintSetterSpray

var SECTION = "FunctionAccessors";
var VERSION = "AS3";
var TITLE   = "AccessorSpray small version";
var BUGNUMBER = "682280";

function AllUntypedGettersMatch() {
    var instance:UntypedGetterSpray  = new UntypedGetterSpray;
    var allMatch:Boolean = true;

    // This is deliberately *not* a dynamic construction of the
    // property name a la instance["a"+i]; that would disable likely
    // optimization via the JIT.  See Bugzilla 682280.
    do {

        if (instance.a1000 != 1000) { allMatch = false; break; } if (instance.a1001 != 1001) { allMatch = false; break; }
        if (instance.a1002 != 1002) { allMatch = false; break; } if (instance.a1003 != 1003) { allMatch = false; break; }
        if (instance.a1004 != 1004) { allMatch = false; break; } if (instance.a1005 != 1005) { allMatch = false; break; }
        if (instance.a1006 != 1006) { allMatch = false; break; } if (instance.a1007 != 1007) { allMatch = false; break; }
        if (instance.a1008 != 1008) { allMatch = false; break; } if (instance.a1009 != 1009) { allMatch = false; break; }

    } while (false);
    return allMatch;
}

function AllUintGettersMatch() {
    var instance:UintGetterSpray  = new UintGetterSpray;
    var allMatch:Boolean = true;

    // This is deliberately *not* a dynamic construction of the
    // property name a la instance["a"+i]; that would disable likely
    // optimization via the JIT.  See Bugzilla 682280.
    do {

        if (instance.u1000 != 1000) { allMatch = false; break; } if (instance.u1001 != 1001) { allMatch = false; break; }
        if (instance.u1002 != 1002) { allMatch = false; break; } if (instance.u1003 != 1003) { allMatch = false; break; }
        if (instance.u1004 != 1004) { allMatch = false; break; } if (instance.u1005 != 1005) { allMatch = false; break; }
        if (instance.u1006 != 1006) { allMatch = false; break; } if (instance.u1007 != 1007) { allMatch = false; break; }
        if (instance.u1008 != 1008) { allMatch = false; break; } if (instance.u1009 != 1009) { allMatch = false; break; }

    } while (false);
    return allMatch;
}

function AllUntypedSettersMatch() {
    var instance:UntypedSetterSpray  = new UntypedSetterSpray;
    var allMatch:Boolean = true;

    // This is deliberately *not* a dynamic construction of the
    // property name a la instance["a"+i]; that would disable likely
    // optimization via the JIT.  See Bugzilla 682280.
    do {

        instance.a = 10; instance.a1000 = -1000; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1001 = -1001; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1002 = -1002; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1003 = -1003; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1004 = -1004; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1005 = -1005; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1006 = -1006; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1007 = -1007; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1008 = -1008; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.a1009 = -1009; if (instance.a != 0) { allMatch = false; break; }

    } while (false);
    return allMatch;
}

function AllUintSettersMatch() {
    var instance:UintSetterSpray  = new UintSetterSpray;
    var allMatch:Boolean = true;

    // This is deliberately *not* a dynamic construction of the
    // property name a la instance["a"+i]; that would disable likely
    // optimization via the JIT.  See Bugzilla 682280.
    do {

        instance.a = 10; instance.u1000 = 1000; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1001 = 1001; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1002 = 1002; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1003 = 1003; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1004 = 1004; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1005 = 1005; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1006 = 1006; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1007 = 1007; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1008 = 1008; if (instance.a != 0) { allMatch = false; break; }
        instance.a = 10; instance.u1009 = 1009; if (instance.a != 0) { allMatch = false; break; }

    } while (false);
    return allMatch;
}

startTest();

AddTestCase("untyped getter spray", true, AllUntypedGettersMatch());
AddTestCase("uint getter spray", true, AllUintGettersMatch());
AddTestCase("untyped setter spray", true, AllUntypedSettersMatch());
AddTestCase("uint setter spray", true, AllUintSettersMatch());

test();
