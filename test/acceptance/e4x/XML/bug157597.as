/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("bug157597 - XML insertChildAfter()");

//TEST(1, true, XML.prototype.hasOwnProperty("insertChildAfter"));

var example:XML = <example>
<two>2</two>
</example>;

correct =
<example>
<two>2</two>
<three>3</three>
</example>;

example.insertChildAfter(example.two, <three>3</three>);

TEST(2, correct, example);



END();
