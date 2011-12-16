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
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
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

import flash.net.IDynamicPropertyWriter;
import flash.net.IDynamicPropertyOutput;
import flash.utils.IExternalizable;
import flash.utils.IDataInput;
import flash.utils.IDataOutput;
import flash.utils.ByteArray;
import flash.utils.Dictionary;
import flash.net.*;
import flash.utils.ObjectEncoding;
import avmplus.File;

var SECTION = "AMFSerialization";
var VERSION = "as3";
startTest();
var TITLE   = "test AMF Serialization";

writeHeaderToLog( SECTION + " "+ TITLE );

class CustomDynamicPropertyWriter implements IDynamicPropertyWriter {

	public function CustomDynamicPropertyWriter() {
		// constructor code
	}
	
	public function writeDynamicProperties(obj:Object, output:IDynamicPropertyOutput):void
	{
		for(var prop:* in obj)
		{
			if(prop != "notforserializing") {
				output.writeDynamicProperty(prop, obj[prop]);
			}
		}
	}

}

class SimpleIExternalizable implements IExternalizable {

		public var stringtest:String = "Sample";
	
		 public function writeExternal(output:IDataOutput):void {
				 output.writeObject("IExternalizable String");
		}
		 public function readExternal(input:IDataInput):void {
				stringtest = input.readObject();
	}
}

dynamic class UDefDynClassWithDynamicAttrs {

	public var obj_DynamicVar:Object;
	public function UDefDynClassWithDynamicAttrs() {
		// constructor code
		obj_DynamicVar = new Object();
	}

}

class UserDefClassAllTypes {
	
	//Null
	public var null_Obj;
	//Boolean - True
	public var bool_True_Obj:Boolean;
	//Boolean - False
	public var bool_False_Obj:Boolean;
	//Integer - Positive
	public var int_Positive_type:int;
	//Unsigned Integer - Value
	public var uint_Value_type:uint;
	//Number - Positive Value
	public var num_Positive_Obj:Number;
	//Number - Min Value
	public var num_Min_Obj:Number;
	//String - title case
	public var str_Title_Obj:String;
	//Date - 18/07/2011 9:10:01:10 AM
	public var dt_Fixed_Obj:Date;
	//Array - Index : int Value: String
	public var arr_IntStr_Obj:Array;
	//Array - Index : Mixed Value: Mixed
	public var arr_MixMix_Obj:Array;
	//XML
	public var xml_Obj:XML;
	//Vector int typed
	public var vct_int_Obj:Vector.<int>;
	//Vector object typed
	public var obj_Test3:Object;
	public var obj_Test4:Object;
	public var vct_obj_Obj:Vector.<Object>;
	public var dict_StrStr_Obj:Dictionary 
	//ByteArray - Empty
	public var ba_Empty_Obj:ByteArray;
	//ByteArray - String
	public var ba_Str_Obj:ByteArray;
	//float
	public var flt_Float:float;
	//float4
	public var flt_Float4:float4;
	

	public function UserDefClassAllTypes() {
		// constructor code
	}

	public function Init():void {
		//Null
		null_Obj = null;
		//Boolean - True
		bool_True_Obj = true;
		//Boolean - False
		bool_False_Obj = false;
		//Integer - Positive
		int_Positive_type = 100;
		//Unsigned Integer - Value
		uint_Value_type = 2000;
		//Number - Positive Value
		num_Positive_Obj = new Number(100);
		//Number - Min Value
		num_Min_Obj = new Number(Number.MIN_VALUE);
		//String - title case
		str_Title_Obj = new String("A Quick Brown Fox Jumps Over A Lazy Dog");
		//Date - 18/07/2011 9:10:01:10 AM
		dt_Fixed_Obj = new Date(2011,07,18,9,10,01,10);
		//Array - Index : int Value: String
		arr_IntStr_Obj = new Array("TEST1", "TEST2", "TEST3", "TEST4");
		//Array - Index : Mixed Value: Mixed
		arr_MixMix_Obj = new Array();
		arr_MixMix_Obj["TEST1"] = 1;
		arr_MixMix_Obj[2] = "Search Engine 2";
		arr_MixMix_Obj[3] = "Search Engine 3";
		arr_MixMix_Obj["TEST2"] = 4;
		//XML
		xml_Obj = <employee><name>XANDER</name><id>xan007</id><address>#5, Salarpuria Infinity, Bannerghatta Road, Bangalore</address></employee>;
		//Vector int typed
		vct_int_Obj = new <int>[-1,100, 200, -200, 0, int.MIN_VALUE, int.MAX_VALUE];
		//Vector object typed
		obj_Test3 = new Object();
		obj_Test3.value = "VALUE 1";
		obj_Test4 = new Object();
		obj_Test4.value = "VALUE 2";
		vct_obj_Obj = new <Object>[obj_Test3, obj_Test4]
		//Vector object
		dict_StrStr_Obj= new Dictionary();
		dict_StrStr_Obj["key1"] = "value1";
		dict_StrStr_Obj["key2"] = "value2";
		//ByteArray - String
		ba_Str_Obj = new ByteArray();
		ba_Str_Obj.writeObject("BYTE ARRAY TEST");
		flt_Float = -12.375f;
		flt_Float4 = float4(-1.111f, 1.1f, 2.2f, 3.122f);
	}

}

dynamic class UserDefinedDynamicClass {

	public var strPubString:String;
	private var strPrivString:String;
	protected var strProtString:String;
	public const strPubConstString:String = new String("User Defined Dynamic Class Public Constant Variable");

	
	public function UserDefinedDynamicClass() {
		strPubString = new String("User Defined Dynamic Class Public Variable");
		strPrivString = new String("User Defined Dynamic Class Private Variable");
		strProtString = new String("User Defined Dynamic Class Protected Variable"); 
	}
	
	public function getPrivString()
	{
		return strPrivString;
	}
	
	public function getProtString()
	{
		return strProtString;
	}
	
	public function setPrivString(str:String)
	{
		strPrivString = str;
	}
	
	public function setProtString(str:String)
	{
		strProtString = str;
	}
}


final class UserDefinedFinalClass {
	
	public var strPubString:String;
	private var strPrivString:String;
	protected var strProtString:String;
	public const strPubConstString:String = new String("User Defined Final Class Public Constant Variable");
	
	public function UserDefinedFinalClass() {
		// constructor code
		strPubString = new String("User Defined Final Class Public Variable");
		strPrivString = new String("User Defined Final Class Private Variable");
		strProtString = new String("User Defined Final Class Protected Variable"); 
	}
	
	public function getPrivString()
	{
		return strPrivString;
	}
	
	public function getProtString()
	{
		return strProtString;
	}
	
	public function setPrivString(str:String)
	{
		strPrivString = str;
	}
	
	public function setProtString(str:String)
	{
		strProtString = str;
	}

}

//Register User Defined Classes
flash.net.registerClassAlias("UserDefClassAllTypes", UserDefClassAllTypes);
flash.net.registerClassAlias("UserDefinedFinalClass", UserDefinedFinalClass);
flash.net.registerClassAlias("UserDefinedDynamicClass", UserDefinedDynamicClass);
flash.net.registerClassAlias("UDefDynClassWithDynamicAttrs", UDefDynClassWithDynamicAttrs);
flash.net.registerClassAlias("SimpleIExternalizable", SimpleIExternalizable);

var userdef_Obj:UserDefClassAllTypes = new UserDefClassAllTypes();
userdef_Obj.Init();

//Null
var null_Obj = null;
buildBAnCallAddTC("null test " , null_Obj);

//Boolean - True
var bool_True_Obj:Boolean = true;
buildBAnCallAddTC("bool true " , bool_True_Obj);

//Boolean - False
var bool_False_Obj:Boolean = false;
buildBAnCallAddTC("bool false " , bool_False_Obj);

//Integer - Positive
var int_Positive_type:int = 1234567890;
buildBAnCallAddTC("int positive" , int_Positive_type);
//Integer - Negative
var int_Negative_type:int = -1234567890;
buildBAnCallAddTC("int negative" , int_Negative_type);
//Unsigned Integer - Value
var uint_Value_type:uint = 21234567890;
buildBAnCallAddTC("uint value" , uint_Value_type);

//Number - Positive Value
var num_Positive_Obj:Number = new Number(1234567890);
buildBAnCallAddTC("Num Positive" , num_Positive_Obj);
//Number - Negative Value
var num_Negative_Obj:Number = new Number(-1234567890);
buildBAnCallAddTC("Num Negative" , num_Negative_Obj);

//String - title case
var str_Title_Obj:String = new String("A Quick Brown Fox Jumps Over A Lazy Dog");
buildBAnCallAddTC("String Mixed case characters" , str_Title_Obj);

//Date - 18/07/2011 9:10:01:10 AM
var dt_Obj:Date = new Date(2011,07,18,9,10,01,10);
testDate("Date FIXED" , dt_Obj);

//Array - Index : Mixed Value: Mixed (WithObject)
var arr_MixMixObj_Obj:Array = new Array();
arr_MixMixObj_Obj["TRIANGLE"] = 1;
arr_MixMixObj_Obj[0] = "Shape 2";
arr_MixMixObj_Obj[1] = "Shape 3";
arr_MixMixObj_Obj["HEXAGON"] = 4;
arr_MixMixObj_Obj[2] = userdef_Obj;
arr_MixMixObj_Obj[2.222] = 5.555;
arr_MixMixObj_Obj[3.14] = "pi";
arr_MixMixObj_Obj[3.14f] = 3.114f;
arr_MixMixObj_Obj["float4"] = float4(-1.111f, 1.1f, 2.2f, 3.122f);
testArrayTypes("Array Index:Mixed Value:Mixed" , arr_MixMixObj_Obj);

//XML With Comment and CDATA
var xml_CmntCDATA_Obj:XML = <testfunc><![CDATA[function printAlert(a,b){alert "hello";}]]> <!-- name --> <name> SQUARE!!!!! </name></testfunc>
testXMLTypes("XML with Comments and CDATA", xml_CmntCDATA_Obj);

//Vector int typed
var vct_int_Obj:Vector.<int> = new <int>[-1,100, 200, -200, 0, int.MIN_VALUE, int.MAX_VALUE];
testVectorTypesInt("Typed Vector type: Int", vct_int_Obj);

//Vector uint typed
var vct_uint_Obj:Vector.<uint> = new <uint>[100, 200, 0, uint.MIN_VALUE, uint.MAX_VALUE];
testVectorTypesUInt("Typed Vector type: Uint", vct_uint_Obj);

//Vector double typed
var vct_double_Obj:Vector.<Number> = new <Number>[-1, 100, 200, -200, 0, Number.MAX_VALUE, Number.MIN_VALUE, Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY];
testVectorTypesNumber("Typed Vector type: Double", vct_double_Obj);

//Vector object typed
var obj_Test3:Object = new Object();
obj_Test3.value = "VALUE 1";
var obj_Test4:Object = new Object();
obj_Test4.value = "VALUE 2";
var vct_obj_Obj:Vector.<Object> = new <Object>[obj_Test3, obj_Test4, "Test Value", 11];
testVectorTypesObject("Typed Vector type: Object", vct_obj_Obj);

//Dictionary Key: String - Value: String
var dict_StrStr_Obj:Dictionary = new Dictionary();
dict_StrStr_Obj["key1"] = "value1";
dict_StrStr_Obj["key2"] = "value2";
dict_StrStr_Obj[3] = "value3";
dict_StrStr_Obj[4] = "value4";
dict_StrStr_Obj[4.22f] = "value4";
dict_StrStr_Obj[124.22f] = float.MAX_VALUE;
dict_StrStr_Obj["float4"] = float4(-1.111f, 1.1f, 2.2f, 3.122f);
testDictionaryTypes("Dictionary Value: String", dict_StrStr_Obj);

//ByteArray - String
var ba_Str_Obj:ByteArray = new ByteArray();
ba_Str_Obj.writeObject("BYTE ARRAY TEST");
testByteArrayTypes(" Byte Array : String ", ba_Str_Obj);

//User Defined Final Class
var udfc_Obj:UserDefinedFinalClass = new UserDefinedFinalClass();
udfc_Obj.setPrivString("My private string");
udfc_Obj.setProtString("My protected string");
//Testing User Defined Final Class - Starts
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(udfc_Obj);
ba_TestObject.position = 0;
var udfc_Read_Obj:UserDefinedFinalClass = ba_TestObject.readObject();
AddTestCase("User Defined Final Class - Const ", udfc_Obj.strPubConstString, udfc_Read_Obj.strPubConstString);
AddTestCase("User Defined Final Class - Public String ", udfc_Obj.strPubString, udfc_Read_Obj.strPubString);
AddTestCase("User Defined Final Class - Private String", "User Defined Final Class Private Variable", udfc_Read_Obj.getPrivString());
AddTestCase("User Defined Final Class - Protected String", "User Defined Final Class Protected Variable", udfc_Read_Obj.getProtString());
//Testing User Defined Final Class - Ends

//User Defined Dynamic Class
var uddc_Obj:UserDefinedDynamicClass = new UserDefinedDynamicClass();
uddc_Obj.setPrivString("My private string");
uddc_Obj.setProtString("My protected string");
//Testing User Defined Dynamic Class - Starts
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(uddc_Obj);
ba_TestObject.position = 0;
var uddc_Read_Obj:UserDefinedDynamicClass = ba_TestObject.readObject();
AddTestCase("User Defined Dynamic Class - Const ", uddc_Obj.strPubConstString, uddc_Read_Obj.strPubConstString);
AddTestCase("User Defined Dynamic Class - Public String ", uddc_Obj.strPubString, uddc_Read_Obj.strPubString);
AddTestCase("User Defined Dynamic Class - Private String ", "User Defined Dynamic Class Private Variable", uddc_Read_Obj.getPrivString());
AddTestCase("User Defined Dynamic Class - Protected String ", "User Defined Dynamic Class Protected Variable", uddc_Read_Obj.getProtString());
//Testing User Defined Dynamic Class - Ends

//User Defined Dynamic Class with Dynamic Member
uddc_Obj.testvalue = "TEST VALUE";
//Testing User Defined Dynamic Class With Dynamic Member- Starts
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(uddc_Obj);
ba_TestObject.position = 0;
uddc_Read_Obj = ba_TestObject.readObject();
AddTestCase("User Defined Dynamic Class With Dynamic Member - Dynamic Member", uddc_Obj.testvalue, uddc_Read_Obj.testvalue);

//User Defined Dynamic Class with Dynamic Members having Dynamic Members
var uddcwd_Obj:UDefDynClassWithDynamicAttrs = new UDefDynClassWithDynamicAttrs();
uddcwd_Obj.obj_DynamicVar.testvalue = "TEST VALUE";
//Testing User Defined Dynamic Class with Dynamic Members having Dynamic Members - Starts
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(uddcwd_Obj);
ba_TestObject.position = 0;
var uddcwd_Read_Obj:UDefDynClassWithDynamicAttrs = ba_TestObject.readObject();
AddTestCase("User Defined Dynamic Class with Dynamic Members having Dynamic Members", uddcwd_Obj.obj_DynamicVar.testvalue, uddcwd_Read_Obj.obj_DynamicVar.testvalue);
//Testing User Defined Dynamic Class with Dynamic Members having Dynamic Members - Ends

//Objects with Circular Reference
var obj_drcheck_Obj:Object = new Object();
var obj_drcheck1_Obj:Object = new Object();
obj_drcheck_Obj.refobject = obj_drcheck1_Obj;
obj_drcheck_Obj.othervalue = 5;
obj_drcheck1_Obj.refobject = obj_drcheck_Obj;
obj_drcheck1_Obj.othervalue = "TEST VALUE";
//Testing Objects with Circular Reference - Starts
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(obj_drcheck_Obj);
ba_TestObject.writeObject(obj_drcheck1_Obj);
ba_TestObject.position = 0;
var obj_drcheck_Read_Obj:Object = ba_TestObject.readObject();
var obj_drcheck1_Read_Obj:Object = ba_TestObject.readObject();
AddTestCase("Object with Circular Reference A to B", obj_drcheck_Obj.refobject.othervalue, obj_drcheck_Read_Obj.refobject.othervalue);
AddTestCase("Object with Circular Reference B to A", obj_drcheck1_Obj.refobject.othervalue, obj_drcheck1_Read_Obj.refobject.othervalue);
//Testing Objects with Circular Reference - Ends

//Object with dynamic properties
var obj_dyn_Obj:Object = new Object();
var obj_level2_Obj:Object = new Object();
obj_level2_Obj.testvalue = " TEST VALUE";
obj_dyn_Obj.testvalue1="TEST VALUE 1";
obj_dyn_Obj.testvalue2="TEST VALUE 2";
obj_dyn_Obj.testvalue3= obj_level2_Obj;
obj_dyn_Obj.testvalue4="TEST VALUE 3";
//Testing Objects with Dynamic Properties- Starts
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(obj_dyn_Obj);
ba_TestObject.position = 0;
var obj_Read_dyn_Obj:Object = ba_TestObject.readObject();
AddTestCase("Object with Dynamic Properties: Prop 1", obj_dyn_Obj.testvalue1, obj_Read_dyn_Obj.testvalue1);
AddTestCase("Object with Dynamic Properties : Prop 2", obj_dyn_Obj.testvalue2, obj_Read_dyn_Obj.testvalue2);
AddTestCase("Object with Dynamic Properties : Prop 3", obj_dyn_Obj.testvalue4, obj_Read_dyn_Obj.testvalue4);
AddTestCase("Object with Dynamic Properties : Prop 3 (1)", obj_dyn_Obj.testvalue3.testvalue, obj_Read_dyn_Obj.testvalue3.testvalue);
//Testing Objects with Dynamic Properties- Ends

//Undefined Value
var obj_Undefined = undefined;
//Testing Undefined - Starts 
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(obj_Undefined);
ba_TestObject.position = 0;
AddTestCase("Undefined", obj_Undefined, ba_TestObject.readObject());
//Testing Undefined - Ends

//Custom Dynamic Property Writer
ObjectEncoding.dynamicPropertyWriter = new CustomDynamicPropertyWriter();
var obj_dyn_Custom_Obj:Object = new Object();
obj_dyn_Custom_Obj.notforserializing = "Don't Serialize";
obj_dyn_Custom_Obj.testvalue = "TEST VALUE";
//Testing Custom Dynamic Property Writer - Starts
var ba_TestObject3:ByteArray = new ByteArray();
ba_TestObject3.writeObject(obj_dyn_Custom_Obj);
ba_TestObject3.position = 0;
var obj_Read_dyn_Custom_Obj:Object= ba_TestObject3.readObject();
AddTestCase("Custom Encoding: Prop notforserialzing", undefined, obj_Read_dyn_Custom_Obj.notforserializing);
AddTestCase("Custom Encoding: Prop testvalue", obj_dyn_Custom_Obj.testvalue, obj_Read_dyn_Custom_Obj.testvalue);
ObjectEncoding.dynamicPropertyWriter=null;
//Testing Custom Dynamic Property Writer - Ends

//IExternalizable
var obj_sie:SimpleIExternalizable = new SimpleIExternalizable();
//Testing IExternalizable - Starts
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(obj_sie);
ba_TestObject.position = 0;
var obj_sie1:SimpleIExternalizable = ba_TestObject.readObject();
AddTestCase("IExternalizable", "IExternalizable String", obj_sie1.stringtest);
//Testing IExternalizable - Ends

//Testing String Reference Tables
var arr_Rednt_Obj:Array = new Array("Adobe", "Adobe", "Test Adobe", "Test Adobe");
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(arr_Rednt_Obj);
ba_TestObject.position = 0;
compareArrays("Array: Redundant Values" , arr_Rednt_Obj, ba_TestObject.readObject());
var vct_Rednt:Vector.<Object> = new <Object>["Adobe", "Adobe", "Test Adobe", "Test Adobe"];
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(vct_Rednt);
ba_TestObject.position = 0;
compareVectorsObject("Vector: Redundant Values" , vct_Rednt, ba_TestObject.readObject());
var dict_Rednt:Dictionary  = new Dictionary();
dict_Rednt["key1"] = "Adobe";
dict_Rednt["key2"] = "Adobe";
dict_Rednt["key3"] = "Adobe";
dict_Rednt["Adobe"] = "key2";
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(dict_Rednt);
ba_TestObject.position = 0;
compareDictionary("Dictionary: Redundant Values" , dict_Rednt, ba_TestObject.readObject());
var obj_Rednt:Object = new Dictionary();
obj_Rednt.testvalue = "TEST VALUE";
obj_Rednt.testvalue1 = "TEST VALUE";
obj_Rednt.testvalue2 = "TEST VALUE";
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(obj_Rednt);
ba_TestObject.position = 0;
compareObjects("Objects: Redundant Values" , obj_Rednt, ba_TestObject.readObject());
//Checking User Defined Object
ba_TestObject = new ByteArray();
ba_TestObject.writeObject(userdef_Obj);
ba_TestObject.position = 0;
compareUserDefTypes("User Defined Class", userdef_Obj, ba_TestObject.readObject());



var result:float = float();
buildBAnCallAddTC("Float constructor with no args", result);

var null_float:float = null;
buildBAnCallAddTC("Float constructor, with 'null' arg", null_float);

var boolean_float:float = true;
buildBAnCallAddTC("Float constructor, with 'boolean' arg", boolean_float);

var dble_float:float = 3.14;
buildBAnCallAddTC("Float constructor, with 'double' arg", dble_float);

var int_float:float = new float(3);
buildBAnCallAddTC("Float constructor, with 'int' arg", int_float);

var string_float:float = new float("3.14");
buildBAnCallAddTC("Float constructor, with 'String' arg", string_float);

var literal_float:float = new float(3.14f);
buildBAnCallAddTC("Float constructor, with 'FloatLiteral' arg", literal_float);

buildBAnCallAddTC("Float Max Value", float.MAX_VALUE);
buildBAnCallAddTC("Float Min Value", float.MIN_VALUE);
testNaN("Float NaN", float.NaN);
buildBAnCallAddTC("Float Positive Infinity", float.POSITIVE_INFINITY);
buildBAnCallAddTC("Float Negative Infinity", float.NEGATIVE_INFINITY);
buildBAnCallAddTC("Float base of natural logarithms", float.E);
buildBAnCallAddTC("Float base of natural logarithm of 10", float.LN10);
buildBAnCallAddTC("Float base of natural logarithms of 2", float.LN2);
buildBAnCallAddTC("Float base of natural logarithms of e to the base 2", float.LOG2E);
buildBAnCallAddTC("Float PI", float.PI);
buildBAnCallAddTC("Float square root of 1/2", float.SQRT1_2);
buildBAnCallAddTC("Float square root of 2", float.SQRT2);


var f1:float = 3.1415f;
var f2:float = float.MAX_VALUE;
var f3:float = -0.00032f;
var f4:float = -12.375f;

var vecFlt:Vector.<float> = new Vector.<float>();
vecFlt.push(f1);
vecFlt.push(f2);
vecFlt.push(f3);
vecFlt.push(f4);
testVectorTypesFloat("Float Vector ", vecFlt);



var result_float4:float4 = float4();
buildBAnCallAddTC("Float4 with no args",result_float4);

var null_float4:float4 = float4(null);
buildBAnCallAddTC("Float4 as constructor, with 'null' arg",null_float4);

var boolean_float4:float4 = float4(true);
buildBAnCallAddTC("Float4 as constructor, with 'boolean' arg",boolean_float4);

var dble_float4:float4 = float4(3.14);
buildBAnCallAddTC("Float4 as constructor, with 'double' arg",dble_float4);

var int_float4:float4 = float4(3);
buildBAnCallAddTC("Float4 as constructor, with 'int' arg",int_float4);

var string_float4:float4 = new float4("3.14");
buildBAnCallAddTC("Float4 as constructor, with 'String' arg",string_float4);

var literal_float4:float4 = float4(3.14f);
buildBAnCallAddTC("Float4 as constructor, with 'FloatLiteral' arg",literal_float4);

var flt4:float4 = float4(-0.00032f, -0.002012f, -0.1232f, 12445.1234f);
buildBAnCallAddTC("Float4 as a constructor with float4 arg",flt4);

buildBAnCallAddTC("Float4 Max Value", float4.MAX_VALUE);
buildBAnCallAddTC("Float4 Min Value", float4.MIN_VALUE);
testNaN("Float NaN", float.NaN);
buildBAnCallAddTC("Float4 Positive Infinity", float4.POSITIVE_INFINITY);
buildBAnCallAddTC("Float4 Negative Infinity", float4.NEGATIVE_INFINITY);
buildBAnCallAddTC("Float4 base of natural logarithms", float4.E);
buildBAnCallAddTC("Float4 base of natural logarithm of 10", float4.LN10);
buildBAnCallAddTC("Float4 base of natural logarithms of 2", float4.LN2);
buildBAnCallAddTC("Float4 base of natural logarithms of e to the base 2", float4.LOG2E);
buildBAnCallAddTC("Float4 base of natural logarithms of e to the base 10", float4.LOG10E);
buildBAnCallAddTC("Float4 PI", float4.PI);
buildBAnCallAddTC("Float4 square root of 1/2", float4.SQRT1_2);
buildBAnCallAddTC("Float4 square root of 2", float4.SQRT2);

var flt4_1:float4 = float4(-1f, 1f, 1f, 1f);
var flt4_2:float4 = float4(-1f, 1.1f, 2.2f, 3.13f);
var flt4_3:float4 = float4(-1.111f, 1.1f, 2.2f, 3.122f);
var flt4_4:float4 = float4(9999.596f,1298.296f,-128.596f,-112.596f)
var flt4_4:float4 = float4(201.334f,123.2236f,-101.111f,-102.121f)


var vecFlt_flt4:Vector.<float4> = new Vector.<float4>();
vecFlt_flt4.push(flt4_1);
vecFlt_flt4.push(flt4_2);
vecFlt_flt4.push(flt4_3);
vecFlt_flt4.push(flt4_4);
testVectorTypesFloat4("Float Vector ", vecFlt_flt4);


function buildBAnCallAddTC(strTitle:String, input:*)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	AddTestCase(strTitle, input, ba_test_Obj.readObject());
}

function testNaN(strTitle:String, input:Number)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	
	AddTestCase(strTitle, isNaN(input), isNaN(ba_test_Obj.readObject()));
}

function testDate(strTitle:String, input:Date)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareDates(strTitle, input, ba_test_Obj.readObject());
}

function compareDates(strTitle:String, input:Date, actual:Date)
{
	AddTestCase(strTitle, input.getTime(), actual.getTime());
}

function testArrayTypes(strTitle:String, input:Array)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	var actual:Array = ba_test_Obj.readObject();
	compareArrays(strTitle, input, actual);
}

function compareArrays(strTitle:String, input:Array, actual:Array)
{
	var propInput:Array = new Array();
	for (var p:* in input) {
		propInput.push(p);
	}
	propInput = propInput.sort();


	var propActual:Array = new Array();
	for (var p1:* in input) {
		propActual.push(p1);
	}
	propActual = propActual.sort();


	for each (var prop:* in propInput)
	{
		if(input[prop] is UserDefClassAllTypes && actual[prop] is UserDefClassAllTypes)
		{
			compareUserDefTypes(strTitle, input[prop], actual[prop]);
		}
		else
		{
			AddTestCase(strTitle + " value check EXP vs ACT: " + prop, input[prop], actual[prop]);
		}
	}
	for each (var prop1:* in propActual)
	{
		if(input[prop1] is UserDefClassAllTypes && actual[prop1] is UserDefClassAllTypes)
		{
			compareUserDefTypes(strTitle, input[prop1], actual[prop1]);
		}
		else
		{
			AddTestCase(strTitle + " value check ACT vs EXP: " + prop1, actual[prop1], input[prop1]);
		}
	}
}

function testXMLTypes(strTitle:String, input:XML)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareXMLS(strTitle, input, ba_test_Obj.readObject());
}

function compareXMLS(strTitle:String, input:XML, actual:XML)
{
	AddTestCase(strTitle, input.toString(), actual.toString());
}

function compareObjects(strTitle:String, input:Object, actual:Object)
{
	var propInput:Array = new Array();
	var propActual:Array = new Array();
	for (var p:* in input)
	{
		propInput.push(p);
	}

	propInput = propInput.sort();

	for (var p1:* in actual)
	{
		propActual.push(p1); 
	}

	propActual = propActual.sort();

	for each (var prop:* in propInput)
	{
		AddTestCase(strTitle, input[prop], actual[prop]);
	}
	for each (var prop1:* in propActual)
	{
		AddTestCase(strTitle, actual[prop1], input[prop1]);
	}
	
}

function testVectorTypesInt(strTitle:String, input:Vector.<int>)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareVectorsInt(strTitle, input, ba_test_Obj.readObject());
}

function compareVectorsInt(strTitle:String, input:Vector.<int>, actual:Vector.<int>)
{
	var inputlen:int = input.length;
	var actuallen:int = actual.length;
	
	AddTestCase(strTitle + " Vector Len ", inputlen, actuallen);
	if(inputlen == actuallen)
	{
		for (var i:int; i < inputlen; i++)
		{
			AddTestCase(strTitle, input[i], actual[i]);
		}
	}
}

function testVectorTypesUInt(strTitle:String, input:Vector.<uint>)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareVectorsUInt(strTitle, input, ba_test_Obj.readObject());
}

function compareVectorsUInt(strTitle:String, input:Vector.<uint>, actual:Vector.<uint>)
{
	var inputlen:int = input.length;
	var actuallen:int = actual.length;
	
	AddTestCase(strTitle + " Vector Len ", inputlen, actuallen);
	if(inputlen == actuallen)
	{
		for (var i:int; i < inputlen; i++)
		{
			AddTestCase(strTitle, input[i], actual[i]);
			
		}
	}
}

function testVectorTypesNumber(strTitle:String, input:Vector.<Number>)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareVectorsNumber(strTitle, input, ba_test_Obj.readObject());
}

function compareVectorsNumber(strTitle:String, input:Vector.<Number>, actual:Vector.<Number>)
{
	var inputlen:int = input.length;
	var actuallen:int = actual.length;
	
	AddTestCase(strTitle + " Vector Len ", inputlen, actuallen);
	if(inputlen == actuallen)
	{
		for (var i:int; i < inputlen; i++)
		{
			AddTestCase(strTitle, input[i], actual[i]);
		}
	}
}


function testVectorTypesFloat(strTitle:String, input:Vector.<float>)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareVectorsFloat(strTitle, input, ba_test_Obj.readObject());
}

function compareVectorsFloat(strTitle:String, input:Vector.<float>, actual:Vector.<float>)
{
	var inputlen:int = input.length;
	var actuallen:int = actual.length;
	AddTestCase(strTitle + " Vector Len ", inputlen, actuallen);
	if(inputlen == actuallen)
	{
		for (var i:int; i < inputlen; i++)
		{
			AddTestCase(strTitle, input[i], actual[i]);
		}
	}
}


function testVectorTypesFloat4(strTitle:String, input:Vector.<float4>)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareVectorsFloat4(strTitle, input, ba_test_Obj.readObject());
}

function compareVectorsFloat4(strTitle:String, input:Vector.<float4>, actual:Vector.<float4>)
{
	var inputlen:int = input.length;
	var actuallen:int = actual.length;
	
	AddTestCase(strTitle + " Vector Len ", inputlen, actuallen);
	if(inputlen == actuallen)
	{
		for (var i:int; i < inputlen; i++)
		{
			AddTestCase(strTitle, input[i], actual[i]);
		}
	}
}

function testVectorTypesObject(strTitle:String, input:Vector.<Object>)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareVectorsObject(strTitle, input, ba_test_Obj.readObject());
}

function compareVectorsObject(strTitle:String, input:Vector.<Object>, actual:Vector.<Object>)
{
	var inputlen:int = input.length;
	var actuallen:int = actual.length;
	
	AddTestCase(strTitle + " Vector Len ", inputlen, actuallen);
	if(inputlen == actuallen)
	{
		for (var i:int; i < inputlen; i++)
		{
			if (input[i] is String && actual[i] is String)
			{
				AddTestCase(strTitle, input[i], actual[i]);
			}
			else if (input[i] is int && actual[i] is int)
			{
				AddTestCase(strTitle, input[i], actual[i]);
			}
			else
			{
				compareObjects(strTitle, input[i], actual[i]);
			}
			
		}
	}
}

function testVectorTypesUDef(strTitle:String, input:Vector.<UserDefClassAllTypes>)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareVectorsUDef(strTitle, input, ba_test_Obj.readObject());
}

function compareVectorsUDef(strTitle:String, input:Vector.<UserDefClassAllTypes>, actual:Vector.<UserDefClassAllTypes>)
{
	var inputlen:int = input.length;
	var actuallen:int = actual.length;
	AddTestCase(strTitle + " Vector Len ", inputlen, actuallen);
	if(inputlen == actuallen)
	{
		for (var i:int; i < inputlen; i++)
		{
			compareUserDefTypes(strTitle, input[i], actual[i]);
		}
	}
}


function testByteArrayTypes(strTitle:String, input:ByteArray)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareByteArray(strTitle, input, ba_test_Obj.readObject());
}

function compareByteArray(strTitle:String, input:ByteArray, actual:ByteArray)
{
	input.position = 0;	
	actual.position = 0;
	AddTestCase(strTitle, input.readObject(), actual.readObject());
}

function testDictionaryTypes(strTitle:String, input:Dictionary)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareDictionary(strTitle, input, ba_test_Obj.readObject());
}

function compareDictionary(strTitle:String, input:Dictionary, actual:Dictionary)
{

	var propInput:Array = new Array();
	for (var p:* in input)
	{
		propInput.push(p);
	}

	propInput = propInput.sort();

	for each (var prop:* in propInput)
	{
		if ( input[prop] is UserDefClassAllTypes)
		{
			compareUserDefTypes(strTitle + " User Defined ", input[prop], actual[prop]);
		}
		else if (input [prop] is Array)
		{
			compareArrays(strTitle + " Array ", input[prop], actual[prop]);
		}
		else if (input[prop] is Vector.<Number>)
		{
			compareVectorsNumber(strTitle + " Vector ", input[prop], actual[prop]);			
		}
		else if (input[prop] is XML)
		{
			compareXMLS(strTitle + " XML ", input[prop], actual[prop]);			
		}
		else if (input[prop] is Date)
		{
			compareDates(strTitle + " Dates ", input[prop], actual[prop]);
		}
		else if (input[prop] is Boolean)
		{
			AddTestCase(strTitle + " Boolean ", input[prop], actual[prop]);			
		}
		else if (input[prop] is  String)
		{
			AddTestCase(strTitle + " String ", input[prop], actual[prop]);
		}
		else if (input[prop] is int)
		{
			AddTestCase(strTitle + " int ", input[prop], actual[prop]);
		}
		else if (input[prop] is uint)
		{
			AddTestCase(strTitle + " uint ", input[prop], actual[prop]);
		}
		else if (input[prop] is Number)
		{
			AddTestCase(strTitle + " Number ", input[prop], actual[prop]);
		}
		else if (input[prop] is float)
		{
			AddTestCase(strTitle + " Number ", input[prop], actual[prop]);
		}		
		else if (input[prop] is float4)
		{
			AddTestCase(strTitle + " Number ", input[prop], actual[prop]);
		}		
		else if (input[prop] is ByteArray)
		{
			compareByteArray(strTitle + " Byte Array ", input[prop], actual[prop]);
		}
		else
		{
			AddTestCase(strTitle + " Object ", input[prop], actual[prop]);
		}
	}
}


function testUserDefTypes(strTitle:String, input:UserDefClassAllTypes)
{
	var ba_test_Obj:ByteArray = new ByteArray();
	ba_test_Obj.writeObject(input);
	ba_test_Obj.position = 0;
	compareUserDefTypes(strTitle, input, ba_test_Obj.readObject());
}

function compareUserDefTypes(strTitle:String, input:UserDefClassAllTypes, actual:UserDefClassAllTypes)
{
	AddTestCase(strTitle  + " User Defined null ", input.null_Obj, actual.null_Obj);
	AddTestCase(strTitle  + " User Defined boolean True ", input.bool_True_Obj, actual.bool_True_Obj);
	AddTestCase(strTitle  + " User Defined boolean False " , input.bool_False_Obj, actual.bool_False_Obj);
	AddTestCase(strTitle  + " User Defined int" , input.int_Positive_type, actual.int_Positive_type);
	AddTestCase(strTitle  + " User Defined uint" , input.uint_Value_type, actual.uint_Value_type);
	AddTestCase(strTitle  + " User Defined  Number min" , input.num_Min_Obj, actual.num_Min_Obj);
	AddTestCase(strTitle  + " User Defined  Number Positive" , input.num_Positive_Obj, actual.num_Positive_Obj);
	AddTestCase(strTitle  + " User Defined  Number Positive" , input.num_Positive_Obj, actual.num_Positive_Obj);
	AddTestCase(strTitle  + " User Defined String " , input.str_Title_Obj, actual.str_Title_Obj);
	compareDates(strTitle  + " User Defined Date " , input.dt_Fixed_Obj, actual.dt_Fixed_Obj);
	compareArrays(strTitle  + " User Defined Array Index:Int Value:String", input.arr_IntStr_Obj, actual.arr_IntStr_Obj);
	compareArrays(strTitle  + " User Defined Array Index:Mixed Value:Mixed", input.arr_MixMix_Obj, actual.arr_MixMix_Obj);
	compareObjects(strTitle + " User Defined Object " , input.obj_Test3, actual.obj_Test3);
	compareObjects(strTitle + " User Defined Object " , input.obj_Test4, actual.obj_Test4);
	compareVectorsInt(strTitle + " User Defined Vector ", input.vct_int_Obj,	actual.vct_int_Obj);
	compareDictionary(strTitle + " User Defined Dictionary", input.dict_StrStr_Obj,	actual.dict_StrStr_Obj);
	compareByteArray(strTitle + " User Defined ByteArray (String)", input.ba_Str_Obj, actual.ba_Str_Obj);
	AddTestCase(strTitle  + " User Defined Float " , input.flt_Float, actual.flt_Float);
	AddTestCase(strTitle  + " User Defined Float4 " , input.flt_Float4, actual.flt_Float4);
}

test();
