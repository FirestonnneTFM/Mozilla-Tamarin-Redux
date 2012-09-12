/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("10.2.1.1 - EscapeElementValue(s)");

AddTestCase( "EscapeElementValue('&')   :", "<x>4 &amp; 5</x>",  (x1 = new XML("<x>4 & 5</x>"), x1.toXMLString())   );
AddTestCase( "EscapeElementValue('&amp')   :", "<x>4 &amp; 5</x>",  (x1 = new XML("<x>4 &amp; 5</x>"), x1.toXMLString())   );
AddTestCase( "EscapeElementValue('&lt;')   :", "<x>4 &lt; 5</x>",  (x1 = new XML("<x>4 &lt; 5</x>"), x1.toXMLString())   );
AddTestCase( "EscapeElementValue('&gt;')   :", "<x>5 &gt; 4</x>",  (x1 = new XML("<x>5 &gt; 4</x>"), x1.toXMLString())   );

END();
