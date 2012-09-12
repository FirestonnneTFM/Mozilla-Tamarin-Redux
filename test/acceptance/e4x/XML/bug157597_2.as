/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("bug157597 - XML insertChildBefore()");



var example:XML = <example>
<two>2</two>
</example>;

correct =
<example>
<one>1</one>
<two>2</two>
</example>;

example.insertChildBefore(example.two, <one>1</one>);

TEST(2, correct, example);



END();
