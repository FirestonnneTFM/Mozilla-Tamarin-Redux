/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.9 - XML.defaultSettings()");

AddTestCase( "settings = XML.defaultSettings(), settings.ignoreComments", true,
             (settings = XML.defaultSettings(), settings.ignoreComments) );
AddTestCase( "settings = XML.defaultSettings(), settings.ignoreProcessingInstructions", true,
             (settings = XML.defaultSettings(), settings.ignoreProcessingInstructions) );
AddTestCase( "settings = XML.defaultSettings(), settings.ignoreWhitespace", true,
             (settings = XML.defaultSettings(), settings.ignoreWhitespace) );
AddTestCase( "settings = XML.defaultSettings(), settings.prettyPrinting", true,
             (settings = XML.defaultSettings(), settings.prettyPrinting) );
AddTestCase( "settings = XML.defaultSettings(), settings.prettyIndent", 2,
             (settings = XML.defaultSettings(), settings.prettyIndent) );

var tempSettings = XML.settings();
tempSettings.ignoreComments = false;
tempSettings.ignoreProcessingInstructions = false;
tempSettings.ignoreWhitespace = false;
tempSettings.prettyPrinting = false;
tempSettings.prettyIndent = 4;

AddTestCase( "XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.ignoreComments", true,
             (XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.ignoreComments) );
AddTestCase( "XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.ignoreProcessingInstructions", true,
             (XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.ignoreProcessingInstructions) );
AddTestCase( "XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.ignoreWhitespace", true,
             (XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.ignoreWhitespace) );
AddTestCase( "XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.prettyPrinting", true,
             (XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.prettyPrinting) );
AddTestCase( "XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.prettyIndent", 2,
             (XML.setSettings(tempSettings), XML.setSettings(XML.defaultSettings()), XML.prettyIndent) );

END();
