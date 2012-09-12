/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.7 - XML.settings");

// xmlDoc

var settings = XML.settings();

AddTestCase( "XML.settings().ignoreComments; ", true, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", true, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", true, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

XML.ignoreComments = false;
AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", true, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", true, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

XML.ignoreProcessingInstructions = false;
AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", true, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

XML.ignoreWhitespace = false;
AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", false, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", true, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

XML.prettyPrinting = false;
AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", false, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", false, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 2, (XML.settings().prettyIndent) );

XML.prettyIndent = 4;
AddTestCase( "XML.settings().ignoreComments; ", false, (XML.settings().ignoreComments) );
AddTestCase( "XML.settings().ignoreProcessingInstructions; ", false, (XML.settings().ignoreProcessingInstructions) );
AddTestCase( "XML.settings().ignoreWhitespace; ", false, (XML.settings().ignoreWhitespace) );
AddTestCase( "XML.settings().prettyPrinting; ", false, (XML.settings().prettyPrinting) );
AddTestCase( "XML.settings().prettyIndent; ", 4, (XML.settings().prettyIndent) );

END();
