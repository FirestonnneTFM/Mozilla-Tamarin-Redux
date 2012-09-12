/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("Qualified names specifying all names in no namespace should only match names without namespaces");
BUG(263935);

var ns1 = new Namespace("http://www.ns1.com");
var ns2 = new Namespace("http://www.ns2.com");
var none = new Namespace();

var x1 = <x/>
x1.foo = "one";
x1.ns1::foo = "two";
x1.ns2::foo = "three";
x1.bar = "four";

var actual = x1.none::*;

var expected =
<>
  <foo>one</foo>
  <bar>four</bar>
</>

TEST(1, expected, actual);

END();
