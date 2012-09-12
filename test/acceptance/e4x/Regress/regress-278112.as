/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START('setNamespace() should not affect namespaceDeclarations()');
BUG('278112');

var xhtml1NS = new Namespace('http://www.w3.org/1999/xhtml');
var xhtml = <html />;

TEST(0, 0, xhtml.namespaceDeclarations().length);

xhtml.setNamespace(xhtml1NS);

TEST(1, 0, xhtml.namespaceDeclarations().length);

TEST(2, xhtml1NS, myGetNamespace(xhtml));

END();
