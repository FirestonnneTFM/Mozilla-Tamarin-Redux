/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "8.6.1 Constructor Methods";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Super Property Access";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  
import SuperProps.*

var thisError;
var result;

var spb = new SuperBase();
AddTestCase( "sanity check base object 1", "base::staticY", spb.baseProp );
AddTestCase( "sanity check base object 2", "base::dynamicX", spb.getBaseVal("x") );
// currently fails - finds undefined dynamic property instead of fixed property:
AddTestCase( "sanity check base object 3", "base::staticY", spb.getBaseVal("y") );
spb.setBaseVal("dynamicProp","base::dynamicProp");
AddTestCase( "sanity check base object 4", "base::dynamicProp", spb.getBaseVal("dynamicProp") );

var sp = new SuperProps();
AddTestCase( "sanity check derived object 1", "base::staticY", sp.inheritedProp );
AddTestCase( "sanity check derived object 2", "base::staticY", sp.superPropDot );
// superPropIndex returns X because we cannot test for it returning Y at the moment:
AddTestCase( "sanity check derived object 3", "base::dynamicX", sp.superPropIndex );
AddTestCase( "sanity check derived object 4", "base::dynamicX", sp.getDerivedVal("x") );
AddTestCase( "sanity check derived object 5", "base::dynamicX", sp.getSuperVal("x") );
AddTestCase( "sanity check derived object 6", "base::dynamicX", sp.getBaseVal("x") );
// currently fails - finds undefined dynamic property instead of fixed property:
AddTestCase( "sanity check derived object 7", "base::staticY", sp.getDerivedVal("y") );
// currently fails - throws exception instead of finding fixed property:
try {
    result = sp.getSuperVal("y");   // super["y"] *should* find base::staticY
} catch (e) {
    result = referenceError( e.toString() );
} finally {
    AddTestCase( "sanity check derived object 8", "base::staticY", result );
}
// currently fails - finds undefined dynamic property instead of fixed property:
AddTestCase( "sanity check derived object 9", "base::staticY", sp.getBaseVal("y") );
sp.setDerivedVal("x","derived::x");
AddTestCase( "check modified property 1", "base::staticY", sp.inheritedProp );
AddTestCase( "check modified property 2", "derived::x", sp.getDerivedVal("x") );
AddTestCase( "check base property 1", "base::staticY", sp.superPropDot );
AddTestCase( "check base property 2", "derived::x", sp.superPropIndex );
AddTestCase( "check base property 3", "derived::x", sp.getSuperVal("x") );
AddTestCase( "check base property 4", "derived::x", sp.getBaseVal("x") );

// Test setting super values.  Tests rely on getters functioning properly.
sp.superPropDot = "new dot property value";
AddTestCase("Set super value via . property", "new dot property value", sp.superPropDot);

sp.superPropIndex = "new index property value";
AddTestCase("Set super value via index property", "new index property value", sp.superPropIndex);

//
////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
