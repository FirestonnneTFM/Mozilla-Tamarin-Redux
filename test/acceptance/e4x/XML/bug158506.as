/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("bug158506");


var x:XML =
<order>
<author name="Contino Chuck" sign="Virgo" /> </order>
for each( var node:XML in x..author )
{ var name:String = node.@name;
var sign:String = node.@sign;
TEST(1, "Contino Chuck", name);
}




END();
