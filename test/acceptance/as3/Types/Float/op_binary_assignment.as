/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
package
{
    public class MyFloatClass
    {
        public static var pubclassvar1:float = 1;
        public static var pubclassvar2:float = 1f;
        public static var pubclassvar4:float = 1.25e-1f;
        public static var pubclassvar5:float = 0x00000400;
        public static var pubclassvar6:float = float.MAX_VALUE;
        public static var pubclassvar7:float = new float(1);
        public static var pubclassvar8:float = float(1);


        public var pubinstancevar1:float = 1;
        public var pubinstancevar2:float = 1f;
        public var pubinstancevar4:float = 1.25e-1f;
        public var pubinstancevar5:float = 0x00000400;
        public var pubinstancevar6:float = float.MAX_VALUE;
        public var pubinstancevar7:float = new float(1);
        public var pubinstancevar8:float = float(1);
    }
}

include "floatUtil.as";

var SECTION = "6.12";
var VERSION = "AS3";
var TITLE   = "The assignment operators augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddStrictTestCase("static class float 1", 1f, MyFloatClass.pubclassvar1);
AddStrictTestCase("static class float 1f", 1f, MyFloatClass.pubclassvar2);
AddStrictTestCase("static class float 1.25e-1f", 0.125f, MyFloatClass.pubclassvar4);
AddStrictTestCase("static class float 0x00000400", 1024f, MyFloatClass.pubclassvar5);
AddStrictTestCase("static class float float.MAX_VALUE", float.MAX_VALUE, MyFloatClass.pubclassvar6);
AddStrictTestCase("static class float new float(1)", 1f, MyFloatClass.pubclassvar7);
AddStrictTestCase("static class float float(1)", 1f, MyFloatClass.pubclassvar8);

var myFloatClass:MyFloatClass = new MyFloatClass();
AddStrictTestCase("public instance float 1", 1f, myFloatClass.pubinstancevar1);
AddStrictTestCase("public instance float 1f", 1f, myFloatClass.pubinstancevar2);
AddStrictTestCase("public instance float 1.25e-1f", 0.125f, myFloatClass.pubinstancevar4);
AddStrictTestCase("public instance float 0x00000400", 1024f, myFloatClass.pubinstancevar5);
AddStrictTestCase("public instance float float.MAX_VALUE", float.MAX_VALUE, myFloatClass.pubinstancevar6);
AddStrictTestCase("public instance float new float(1)", 1f, myFloatClass.pubinstancevar7);
AddStrictTestCase("public instance float float(1)", 1f, myFloatClass.pubinstancevar8);

var var1:float = 1;
var var2:float = 1f;
var var4:float = 1.25e-1f;
var var5:float = 0x00000400;
var var6:float = float.MAX_VALUE;
var var7:float = new float(1);
var var8:float = float(1);
AddStrictTestCase("global var float 1", 1f, var1);
AddStrictTestCase("global var float 1f", 1f, var2);
AddStrictTestCase("global var float 1.25e-1f", 0.125f, var4);
AddStrictTestCase("global var float 0x00000400", 1024f, var5);
AddStrictTestCase("global var float float.MAX_VALUE", float.MAX_VALUE, var6);
AddStrictTestCase("global var float new float(1)", 1f, var7);
AddStrictTestCase("global var float float(1)", 1f, var8);
var var9 = var1;
AddStrictTestCase("float var set as another float var", 1f, var9);




test();
