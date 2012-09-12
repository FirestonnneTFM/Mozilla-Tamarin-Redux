/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
var TITLE   = "Variable";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


    // <empty> Identifier = <empty>
    //id; // runtime error

    // <empty> Identifier = AssignmentExpression
    idAssignExpr = true;

    // <empty> VariableBindingList, Identifier = <empty>
    //id1, id2, id3; // runtime errors

    // var VariableBindingList, Identifier = AssignmentExpression
    id1AssignExpr = true, id2AssignExpr = false, id3AssignExpr = true;
    //id1AssignExprB, id2AssignExprB, id3AssignExprB = true; // runtime errors



AddTestCase( "Variable Definition <empty> defined inside class", 1, 1);

AddTestCase( "var Identifier = <empty>", "id", (id = "id", id));
AddTestCase( "var Identifier = AssignmentExpression", true, idAssignExpr);
AddTestCase( "var VariableBindingList, Identifier = <empty> [1]", true, (id1 = true, id1));
AddTestCase( "var VariableBindingList, Identifier = <empty> [2]", true, (id2 = true, id2));
AddTestCase( "var VariableBindingList, Identifier = <empty> [3]", true, (id3 = true, id3));
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [1]", true, id1AssignExpr);
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [2]", false, id2AssignExpr);
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [3]", true, id3AssignExpr);
//AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [4]", undefined, id1AssignExprB);
//AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [5]", undefined, id2AssignExprB);
//AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [6]", true, id3AssignExprB);


test();       // leave this alone.  this executes the test cases and
              // displays results.
