/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
var TITLE   = "Private Static Variable Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


import VarDefPrivateStatic.*;
 
var VARDEFEMPTY = new VarDefPrivateStaticClass();
AddTestCase( "Private Static Variable Definition defined inside class", 1, 1);

AddTestCase( "var Identifier = <empty>", "id", (VARDEFEMPTY.setid("id"), VARDEFEMPTY.getid()));
AddTestCase( "var Identifier : TypeExpression = <empty>", true, (VARDEFEMPTY.setidTypeExpr(true),
                                                                 VARDEFEMPTY.getidTypeExpr()));
AddTestCase( "var Identifier = AssignmentExpression", true, VARDEFEMPTY.getidAssignExpr());
AddTestCase( "var Identifier : TypeExpression = AssignmentExpression", true, VARDEFEMPTY.getidTypeExprAssignExpr());
AddTestCase( "var VariableBindingList, Identifier = <empty> [1]", true, (VARDEFEMPTY.setid1(true),
                                                                         VARDEFEMPTY.getid1()));
AddTestCase( "var VariableBindingList, Identifier = <empty> [2]", true, (VARDEFEMPTY.setid2(true),
                                                                         VARDEFEMPTY.getid2()));
AddTestCase( "var VariableBindingList, Identifier = <empty> [3]", true, (VARDEFEMPTY.setid3(true),
                                                                         VARDEFEMPTY.getid3()));
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = <empty> [1]", true, (VARDEFEMPTY.setid1TypeExpr(true),
                                                                                          VARDEFEMPTY.getid1TypeExpr()));
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = <empty> [2]", true, (VARDEFEMPTY.setid2TypeExpr(true),
                                                                                          VARDEFEMPTY.getid2TypeExpr()));
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = <empty> [3]", true, (VARDEFEMPTY.setid3TypeExpr(true),
                                                                                          VARDEFEMPTY.getid3TypeExpr()));
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [1]", true, VARDEFEMPTY.getid1AssignExpr());
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [2]", false, VARDEFEMPTY.getid2AssignExpr());
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [3]", true, VARDEFEMPTY.getid3AssignExpr());
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [4]", undefined, VARDEFEMPTY.getid1AssignExprB());
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [5]", undefined, VARDEFEMPTY.getid2AssignExprB());
AddTestCase( "var VariableBindingList, Identifier = AssignmentExpression [6]", true, VARDEFEMPTY.getid3AssignExprB());
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = AssignmentExpression [1]", true, VARDEFEMPTY.getid1TypeExprAssignExpr());
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = AssignmentExpression [2]", false, VARDEFEMPTY.getid2TypeExprAssignExpr());
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = AssignmentExpression [3]", true, VARDEFEMPTY.getid3TypeExprAssignExpr());
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = AssignmentExpression [4]", false, VARDEFEMPTY.getid1TypeExprAssignExprB());
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = AssignmentExpression [5]", false, VARDEFEMPTY.getid2TypeExprAssignExprB());
AddTestCase( "var VariableBindingList, Identifier : TypeExpression = AssignmentExpression [6]", true, VARDEFEMPTY.getid3TypeExprAssignExprB());
AddTestCase( "var Identifier, Identifier : TypeExpression = <empty> [1]", true, (VARDEFEMPTY.setidA(true),
                                                                                 VARDEFEMPTY.getidA()));
AddTestCase( "var Identifier, Identifier : TypeExpression = <empty> [2]", true, (VARDEFEMPTY.setidB(true),
                                                                                 VARDEFEMPTY.getidB()));
AddTestCase( "var Identifier, Identifier : TypeExpression = AssignmentExpression [1]", false, VARDEFEMPTY.getidAAssign() )
AddTestCase( "var Identifier, Identifier : TypeExpression = AssignmentExpression [2]", true, VARDEFEMPTY.getidBAssign() )
AddTestCase( "var Identifier, Identifier : TypeExpression = AssignmentExpression [3]", undefined, VARDEFEMPTY.getidAAssignB() )
AddTestCase( "var Identifier, Identifier : TypeExpression = AssignmentExpression [4]", true, VARDEFEMPTY.getidBAssignB() )
var arr = new Array(1,2,3);
AddTestCase( "var Identifier : TypeExpressionA, Identifier : TypeExpressionB = <empty> [1]", arr, (VARDEFEMPTY.setidTypeExprA(arr),
                                                                                                   VARDEFEMPTY.getidTypeExprA()) );
AddTestCase( "var Identifier : TypeExpressionA, Identifier : TypeExpressionB = <empty> [2]", false, (VARDEFEMPTY.setidTypeExprB(false),
                                                                                                     VARDEFEMPTY.getidTypeExprB()) );
AddTestCase( "var Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [1]", arr.toString(), VARDEFEMPTY.getidTypeExprAAssign().toString())
AddTestCase( "var Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [2]", true, VARDEFEMPTY.getidTypeExprBAssign() )
AddTestCase( "var Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [3]", null, VARDEFEMPTY.getidTypeExprAAssignB())
AddTestCase( "var Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [4]", true, VARDEFEMPTY.getidTypeExprBAssignB() )
AddTestCase( "var Identifier, Identifier : TypeExpressionA, Identifier : TypeExpressionB = <empty> [1]", true, (VARDEFEMPTY.setidId(true),
                                                                                                                VARDEFEMPTY.getidId()) );
AddTestCase( "var Identifier, Identifier : TypeExpressionA, Identifier : TypeExpressionB = <empty> [2]", arr, (VARDEFEMPTY.setidIdTypeExprA(arr),
                                                                                                               VARDEFEMPTY.getidIdTypeExprA()) );
AddTestCase( "var Identifier, Identifier : TypeExpressionA, Identifier : TypeExpressionB = <empty> [3]", false, (VARDEFEMPTY.setidIdTypeExprB(false),
                                                                                                               VARDEFEMPTY.getidIdTypeExprB()) );
AddTestCase( "var Identififer, Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [1]", false, VARDEFEMPTY.getidIdAssign());
AddTestCase( "var Identififer, Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [2]", arr.toString(), VARDEFEMPTY.getidIdTypeExprAAssign().toString());
AddTestCase( "var Identififer, Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [3]", true, VARDEFEMPTY.getidIdTypeExprBAssign());
AddTestCase( "var Identififer, Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [4]", undefined, VARDEFEMPTY.getidIdAssignB());
AddTestCase( "var Identififer, Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [5]", null, VARDEFEMPTY.getidIdTypeExprAAssignB());
AddTestCase( "var Identififer, Identifier : TypeExpressionA, Identifier : TypeExpressionB = AssignmentExpression [6]", true, VARDEFEMPTY.getidIdTypeExprBAssignB());



test();       // leave this alone.  this executes the test cases and
              // displays results.
