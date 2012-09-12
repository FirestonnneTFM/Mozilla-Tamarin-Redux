/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("10.2.1.2 - EscapeAttributeValue(s)");

AddTestCase( "EscapeElementValue('\"')       :", "<x attr=\"I said &quot;hi&quot;\">hi</x>", (x1 = <x attr='I said "hi"'>hi</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('<')        :", "<x attr=\"4 &lt; 5\">b</x>", (x1 = <x attr='4 &lt; 5'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('>')        :", "<x attr=\"10 > 9\">b</x>", (x1 = <x attr='10 &gt; 9'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('&')        :", "<x attr=\"Tom &amp; Jerry\">b</x>", (x1 = <x attr='Tom &amp; Jerry'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('&#x9')        :", "<x attr=\"&#x9;\">b</x>", (x1 = <x attr='&#x9;'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('&#xA')        :", "<x attr=\"&#xA;\">b</x>", (x1 = <x attr='&#xA;'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('&#xD')        :", "<x attr=\"&#xD;\">b</x>", (x1 = <x attr='&#xD;'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('\u0009')        :", "<x attr=\"&#x9;\">b</x>", (x1 = <x attr='\u0009'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('\u000A')        :", "<x attr=\"&#xA;\">b</x>", (x1 = <x attr='\u000A'>b</x>, x1.toXMLString()) );
AddTestCase( "EscapeElementValue('\u000D')        :", "<x attr=\"&#xD;\">b</x>", (x1 = <x attr='\u000D'>b</x>, x1.toXMLString()) );

END();
