/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import ImplTwoInterfacesSameMethod.*;

startTest();

var OBJ = new C();

AddTestCase( "Interface name does not disambiguate method definitions",
             "{A,B} function sameName",
             OBJ.A::sameName() );
AddTestCase( "Interface name does not disambiguate method definitions",
             "{A,B} function sameName",
             OBJ.B::sameName() );


test();


