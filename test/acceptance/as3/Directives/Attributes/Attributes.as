/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package Attrs {

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
var TITLE   = "Extend Default Class";       // Provide ECMA section title or a description
//var BUGNUMBER = "";

startTest();                // leave this alone


/*===========================================================================*/

var ATTRS = new Attrs();
// Variables
AddTestCase("var, empty         :", "var, empty         ", ATTRS.emptyVar);
AddTestCase("var, public        :", "var, public        ", ATTRS.pubVar);
var privateVarErr="no error"; try { ATTRS.privVar } catch (e) { privateVarErr=e.toString(); }
AddTestCase("var, private       :", "ReferenceError: Error #1069", privateVarErr.substr(0,27));
//AddTestCase("var, private       :", "var, private       ", ATTRS.privVar);
AddTestCase("var, static        :", "var, static        ", ATTRS.getStatVar());
AddTestCase("var, public static :", "var, public static ", ATTRS.getPubStatVar());
AddTestCase("var, private static:", "var, private static", ATTRS.getPrivStatVar());
AddTestCase("var, static public :", "var, static public ", ATTRS.getStatPubVar());
AddTestCase("var, static private:", "var, static private", ATTRS.getStatPrivVar());

// Functions
AddTestCase("func, empty         :", "func, empty         ", ATTRS.emptyFunc());
AddTestCase("func, public        :", "func, public        ", ATTRS.pubFunc());
var privFunc="no error"; try { ATTRS.privFunc(); } catch (e) { privFunc=e.toString(); }
AddTestCase("func, private       :", "ReferenceError: Error #1069", privateVarErr.substr(0,27));
//AddTestCase("func, private       :", "func, private       ", ATTRS.privFunc());
AddTestCase("func, static        :", "func, static        ", ATTRS.getStatFunc());
AddTestCase("func, public static :", "func, public static ", ATTRS.getPubStatFunc());
AddTestCase("func, private static:", "func, private static", ATTRS.getPrivStatFunc());
AddTestCase("func, static public :", "func, static public ", ATTRS.getStatPubFunc());
AddTestCase("func, static private:", "func, static private", ATTRS.getStatPrivFunc());

// Classes
//var c = new ClassEmpty();
//AddTestCase("class, empty         :", "class, empty         ", c.fn());

//var cpub = new ClassPub();
//AddTestCase("class, public        :", "class, public        ", cpub.fn());

/* The class with 'private' access specifiers are commented */
/*
var cpriv = new ClassPriv();
AddTestCase("class, private       :", "class, private       ", cpriv.fn());
*/

//var cstat = new ClassStat();
//AddTestCase("class, static        :", "class, static        ", cstat.fn());

//var cpubstat = new ClassPubStat();
//AddTestCase("class, public static :", "class, public static ", cpubsat.fn());

/*
var cprivstat = new ClassPrivStat();
AddTestCase("class, private static:", "class, private static", cpriv.fn());
*/

//var cstatpub = new ClassStatPub();
//AddTestCase("class, static public :", "class, static public ", cstatpub.fn());

/*
var cstatpriv = new ClassStatPriv();
AddTestCase("class, static private:", "class, static private", cstatpriv.fn());
*/

// Interfaces
//var i = new IfEmpty_();
//AddTestCase("interface, empty         :", "interface, empty         ", i.fn());

//var ipub = new IfPub_();
//AddTestCase("interface, public        :", "interface, public        ", ipub.fn());

/*
var ipriv = new IfPriv_();
AddTestCase("interface, private       :", "interface, private       ", ipriv.fn());
*/

//var istat = new IfStat_();
//AddTestCase("interface, static        :", "interface, static        ", istat.fn());

//var ipubstat = new IfPubStat_();
//AddTestCase("interface, public static :", "interface, public static ", ipubstat.fn());

/*
var iprivstat = new IfPrivStat_();
AddTestCase("interface, private static:", "interface, private static", iprivstat.fn());
*/

//import Directives.Attributes.IfStatPub_;
//var istatpub = new IfStatPub_();
//AddTestCase("interface, static public :", "interface, static public ", istatpub.fn());

/*
var istatpriv = new IfStatPriv_();
AddTestCase("interface, static private:", "interface, static private", istatpriv.fn());
*/

/*===========================================================================*/

test();       // leave this alone.  this executes the test cases and
              // displays results.
}