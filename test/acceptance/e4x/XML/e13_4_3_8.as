/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.8 - XML.setSettings(settings)");

// a) called with a settings object
var settings = XML.settings();

settings.ignoreComments = false;
settings.ignoreProcessingInstructions = false;
settings.ignoreWhitespace = false;
settings.prettyPrinting = false;
settings.prettyIndent = 4;

AddTestCase( "XML.settings().ignoreComments; ", true, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", true, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", true, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

XML.setSettings (settings);

AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", false, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", false, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 4, (XML.settings().prettyIndent) );

// setting null restores defaults
XML.setSettings (null);

AddTestCase( "XML.settings(null); XML.settings().ignoreComments; ", true, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings(null); XML.settings().ignoreProcessingInstructions; ", true, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings(null); XML.settings().ignoreWhitespace; ", true, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings(null); XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings(null); XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

XML.setSettings (settings);
// does setting a bogus value restore defaults? No.
XML.setSettings ([1, 2, 3, 4]);

AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", false, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", false, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 4, (XML.settings().prettyIndent) );

// does setting a bogus value restore defaults? No.
XML.setSettings (5);

AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", false, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", false, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 4, (XML.settings().prettyIndent) );

// does setting a bogus value restore defaults? No.
XML.setSettings ("");

AddTestCase( "XML.setSettings (\"\"); XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.setSettings (\"\"); XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.setSettings (\"\"); XML.settings().ignoreWhitespace; ", false, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.setSettings (\"\"); XML.settings().prettyPrinting; ", false, (XML.settings().prettyPrinting) );
AddTestCase( "XML.setSettings (\"\"); XML.settings().prettyIndent; ", 4, (XML.settings().prettyIndent) );

// this restores defaults
XML.setSettings (undefined);

AddTestCase( "XML.setSettings (undefined); XML.settings().ignoreComments; ", true, (XML.settings().ignoreComments) );
AddTestCase( "XML.setSettings (undefined); XML.settings().ignoreProcessingInstructions; ", true, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.setSettings (undefined); XML.settings().ignoreWhitespace; ", true, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.setSettings (undefined); XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.setSettings (undefined); XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

// this restore defaults
XML.setSettings (settings);
XML.setSettings ();

AddTestCase( "XML.setSettings (); XML.settings().ignoreComments; ", true, (XML.settings().ignoreComments) );
AddTestCase( "XML.setSettings (); XML.settings().ignoreProcessingInstructions; ", true, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.setSettings (); XML.settings().ignoreWhitespace; ", true, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.setSettings (); XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.setSettings (); XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

END();
