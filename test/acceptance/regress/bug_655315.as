/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package{
var SECTION = "Regression Tests";
var VERSION = "AS3";
var TITLE   = "Bug 655315";
var bug = "655315";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

class Foo
{
    private function pp(data:Object):* {
        var text:*;
        try {
            text = data.bar;
        }
        catch (e:Error) {}
        try {
            text = text || data.foo;
        }
        catch (e:Error) {}
        text = "??";

        return "" + text;
    }

    public function bar() {
        trace(pp(null));
    }
}

var o = new Foo();
o.bar();

AddTestCase("Completed", true, true);

test();

}