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

import avmplus.*;

var TITLE =  "FLOAT TEST";
var VERSION = "AS3";

var STEP = "initial";
var floatTest:Array = [];
var ft_count:int = 0;

function   EQ(expected:float,actual:float):void{
   if(expected!=actual)
       AddTestCase(   STEP+ " !FAILED! ", expected, actual);
   else
       AddTestCase(   STEP, "", "");// just print it

   STEP=">> "+STEP;
}

function APPROX_EQ(expected:float,actual:float):void{
    var epsilon = 0.0001f;
   var result:float = expected>actual? expected - actual:actual-expected;
   if(result==0)
       AddTestCase(   STEP, "", "");
   else
   if(result<epsilon)
       AddTestCase(   STEP, "~", "~");
   else
       AddTestCase(   STEP+ " !FAILED! ", expected, actual);
   STEP=">> "+STEP;
}

function TestSection(section , initTests ){


   this.RUN = function(){
       SECTION = section;
       startTest();
       writeHeaderToLog( TITLE + ": " + SECTION );
       initTests();
       test();
   }
}

  interface IFloatOps {
    function add(value:float):float;
    function sub(value:float):float;
    function mul(value:float):float;
    function div(value:float):float;
    function mod(value:float):float;
    function uminus():float;
    function uplus():float;
   function gt(value:float):Boolean;
   function gte(value:float):Boolean;
   function lt(value:float):Boolean;
   function lte(value:float):Boolean;
   function eq(value:float):Boolean;
   function seq(value:float):Boolean;
   function neq(value:float):Boolean;
   function sneq(value:float):Boolean;
  }
  class FltAnyOps implements IFloatOps
 {
    var _val;
   public function FltAnyOps(v){ _val=v;};
    public function add(value:float):float { return _val+value;};
    public function sub(value:float):float { return value-_val;};
    public function mul(value:float):float { return _val*value;};
    public function div(value:float):float { return value/_val;};
    public function mod(value:float):float { return _val%value;};
    public function uminus():float         { return -_val;};
    public function uplus():float          { return +_val;};
   public function gt(value:float):Boolean  { return _val>value;};
   public function gte(value:float):Boolean { return value>=_val;};
   public function lt(value:float):Boolean  { return value<_val;};
   public function lte(value:float):Boolean { return _val<=value;};
   public function eq(value:float):Boolean  { return value==_val;};
   public function seq(value:float):Boolean { return _val===value;};
   public function neq(value:float):Boolean { return value!=_val;};
   public function sneq(value:float):Boolean{ return _val!==value;};
 };
  class FltFltOps implements IFloatOps
 {
    var _val:float;
   public function FltFltOps(v:float){ _val=v;}
    public function add(value:float):float { return value+_val;}
    public function sub(value:float):float { return _val-value;}
    public function mul(value:float):float { return value*_val;}
    public function div(value:float):float { return _val/value;}
    public function mod(value:float):float { return value%_val;}
    public function uminus():float         { return -_val;}
    public function uplus():float          { return +_val;}
   public function gt(value:float):Boolean  { return value>_val;}
   public function gte(value:float):Boolean { return _val>=value;}
   public function lt(value:float):Boolean  { return _val<value;}
   public function lte(value:float):Boolean { return value<=_val;}
   public function eq(value:float):Boolean  { return _val==value;}
   public function seq(value:float):Boolean { return value===_val;}
   public function neq(value:float):Boolean { return _val!=value;}
   public function sneq(value:float):Boolean{ return _val!==value;}
 };

  class FltNumOps implements IFloatOps
 {
    var _val:Number;
   public function FltNumOps(v:Number){ _val=v;}
    public function add(value:float):float { return _val+value;}
    public function sub(value:float):float { return value-_val;}
    public function mul(value:float):float { return _val*value;}
    public function div(value:float):float { return value/_val;}
    public function mod(value:float):float { return _val%value;}
    public function uminus():float         { return -_val;}
    public function uplus():float          { return +_val;}
   public function gt(value:float):Boolean  { return _val>value;}
   public function gte(value:float):Boolean { return value>=_val;}
   public function lt(value:float):Boolean  { return value<_val;}
   public function lte(value:float):Boolean { return _val<=value;}
   public function eq(value:float):Boolean  { return value==_val;}
   public function seq(value:float):Boolean { return _val===value;}
   public function neq(value:float):Boolean { return value!=_val;}
   public function sneq(value:float):Boolean{ return _val!==value;}
 };
  class FltIntOps implements IFloatOps
 {
    var _val:int;
   public function FltIntOps(v:int){ _val=v;}
    public function add(value:float):float { return value+_val;}
    public function sub(value:float):float { return _val-value;}
    public function mul(value:float):float { return value*_val;}
    public function div(value:float):float { return _val/value;}
    public function mod(value:float):float { return value%_val;}
    public function uminus():float         { return -_val;}
    public function uplus():float          { return +_val;}
   public function gt(value:float):Boolean  { return value>_val;}
   public function gte(value:float):Boolean { return _val>=value;}
   public function lt(value:float):Boolean  { return _val<value;}
   public function lte(value:float):Boolean { return value<=_val;}
   public function eq(value:float):Boolean  { return _val==value;}
   public function seq(value:float):Boolean { return value===_val;}
   public function neq(value:float):Boolean { return _val!=value;}
   public function sneq(value:float):Boolean{ return _val!==value;}
 };


function initFltAnyTests(){
   var obj:IFloatOps = new FltAnyOps(3.14f);
   STEP="ADD";   EQ(34.54f, obj.add(31.4f));
   STEP="SUB";   EQ(28.26f, obj.sub(31.4f));
   STEP="MUL";   EQ(98.596f, obj.mul(31.4f));
   STEP="DIV";   EQ(10f, obj.div(31.4f));
   STEP="MOD";   EQ(3.14f, obj.mod(31.4f));
   STEP="UMINUS";EQ(-3.14f, obj.uminus());
   STEP="UPLUS"; EQ(3.14f, obj.uplus());
   STEP="GT";    EQ(false, obj.gt(31.4f));EQ(false, obj.gt(3.14f));EQ(true, obj.gt(.314f));
   STEP="GTE";   EQ(true, obj.gte(31.4f));EQ(true, obj.gte(3.14f));EQ(false, obj.gte(.314f));
   STEP="LT";    EQ(false, obj.lt(31.4f));EQ(false, obj.lt(3.14f));EQ(true, obj.lt(.314f));
   STEP="LTE";   EQ(true, obj.lte(31.4f));EQ(true, obj.lte(3.14f));EQ(false, obj.lte(.314f));
   STEP="EQ";    EQ(false, obj.eq(31.4f));EQ(true, obj.eq(3.14f));
   STEP="SEQ";    EQ(false, obj.seq(31.4f));EQ(true, obj.seq(3.14f));
   STEP="NEQ";    EQ(true, obj.neq(31.4f));EQ(false, obj.neq(3.14f));
   STEP="sneq";   EQ(true, obj.sneq(31.4f));EQ(false, obj.sneq(3.14f));
}
function initFltFltTests(){
   var obj:IFloatOps = new FltFltOps(3.14f);
   STEP="ADD";   EQ(34.54f, obj.add(31.4f));
   STEP="SUB";   EQ(-28.26f, obj.sub(31.4f));
   STEP="MUL";   EQ(98.596f, obj.mul(31.4f));
   STEP="DIV";   EQ(0.1f, obj.div(31.4f));
   STEP="MOD";   EQ(3.13999867f, obj.mod(31.4f));
   STEP="UMINUS";EQ(-3.14f, obj.uminus());
   STEP="UPLUS"; EQ(3.14f, obj.uplus());
   STEP="GT";    EQ(true, obj.gt(31.4f));EQ(false, obj.gt(3.14f));EQ(false, obj.gt(.314f));
   STEP="GTE";   EQ(false, obj.gte(31.4f));EQ(true, obj.gte(3.14f));EQ(true, obj.gte(.314f));
   STEP="LT";    EQ(true, obj.lt(31.4f));EQ(false, obj.lt(3.14f));EQ(false, obj.lt(.314f));
   STEP="LTE";   EQ(false, obj.lte(31.4f));EQ(true, obj.lte(3.14f));EQ(true, obj.lte(.314f));
   STEP="EQ";    EQ(false, obj.eq(31.4f));EQ(true, obj.eq(3.14f));
   STEP="SEQ";    EQ(false, obj.seq(31.4f));EQ(true, obj.seq(3.14f));
   STEP="NEQ";    EQ(true, obj.neq(31.4f));EQ(false, obj.neq(3.14f));
   STEP="SNEQ";   EQ(true, obj.sneq(31.4f));EQ(false, obj.sneq(3.14f));
}

function initFltNumTests(){
   var obj:IFloatOps = new FltNumOps(3.14);
   STEP="ADD";   EQ(34.54f, obj.add(31.4f));
   STEP="SUB";   EQ(28.26f, obj.sub(31.4f));
   STEP="MUL";   EQ(98.596f, obj.mul(31.4f));
   STEP="DIV";   EQ(10f, obj.div(31.4f));
   STEP="MOD";   EQ(3.14f, obj.mod(31.4f));
   STEP="UMINUS";EQ(-3.14f, obj.uminus());
   STEP="UPLUS"; EQ(3.14f, obj.uplus());
   STEP="GT";    EQ(false, obj.gt(31.4f));EQ(false, obj.gt(3.14f));EQ(true, obj.gt(.314f));
   STEP="GTE";   EQ(true, obj.gte(31.4f));EQ(true, obj.gte(3.14f));EQ(false, obj.gte(.314f));
   STEP="LT";    EQ(false, obj.lt(31.4f));EQ(false, obj.lt(3.14f));EQ(true, obj.lt(.314f));
   STEP="LTE";   EQ(true, obj.lte(31.4f));EQ(true, obj.lte(3.14f));EQ(false, obj.lte(.314f));
   STEP="EQ";    EQ(false, obj.eq(31.4f));EQ(false, obj.eq(3.14f));
   STEP="SEQ";    EQ(false, obj.seq(31.4f));EQ(false, obj.seq(3.14f));
   STEP="NEQ";    EQ(true, obj.neq(31.4f));EQ(true, obj.neq(3.14f));
   STEP="SNEQ";   EQ(true, obj.sneq(31.4f));EQ(true, obj.sneq(3.14f));
}
function initFltAnyTests2(){
   var obj:IFloatOps = new FltAnyOps(3.14); /*NOTE: not float! */
   STEP="ADD";   EQ(34.54f, obj.add(31.4f));
   STEP="SUB";   EQ(28.26f, obj.sub(31.4f));
   STEP="MUL";   EQ(98.596f, obj.mul(31.4f));
   STEP="DIV";   EQ(10f, obj.div(31.4f));
   STEP="MOD";   EQ(3.14f, obj.mod(31.4f));
   STEP="UMINUS";EQ(-3.14f, obj.uminus());
   STEP="UPLUS"; EQ(3.14f, obj.uplus());
   STEP="GT";    EQ(false, obj.gt(31.4f));EQ(false, obj.gt(3.14f));EQ(true, obj.gt(.314f));
   STEP="GTE";   EQ(true, obj.gte(31.4f));EQ(true, obj.gte(3.14f));EQ(false, obj.gte(.314f));
   STEP="LT";    EQ(false, obj.lt(31.4f));EQ(false, obj.lt(3.14f));EQ(true, obj.lt(.314f));
   STEP="LTE";   EQ(true, obj.lte(31.4f));EQ(true, obj.lte(3.14f));EQ(false, obj.lte(.314f));
   STEP="EQ";    EQ(false, obj.eq(31.4f));EQ(false, obj.eq(3.14f));
   STEP="SEQ";    EQ(false, obj.seq(31.4f));EQ(false, obj.seq(3.14f));
   STEP="NEQ";    EQ(true, obj.neq(31.4f));EQ(true, obj.neq(3.14f));
   STEP="SNEQ";   EQ(true, obj.sneq(31.4f));EQ(true, obj.sneq(3.14f));
}


function initFltIntTests(){
   var result:float;
   var epsilon:float=0.0001f;
   var obj:IFloatOps = new FltIntOps(3);
   STEP="ADD";   EQ(34.4f, obj.add(31.4f));
   STEP="SUB";   EQ(-28.4f, obj.sub(31.4f));
   STEP="MUL";   EQ(94.2f,obj.mul(31.4f));
   STEP="DIV";   EQ(0.0955414013f, obj.div(31.4f));
   STEP="MOD";   result = 1.4f - obj.mod(31.4f);if(result<0) result=-result;
                EQ(true,result<epsilon);
   STEP="UMINUS";EQ(-3f, obj.uminus());
   STEP="UPLUS"; EQ(3f, obj.uplus());
   STEP="GT";    EQ(true, obj.gt(3.0001f));EQ(false, obj.gt(3f));EQ(false, obj.gt(2.999f));
   STEP="GTE";   EQ(false, obj.gte(3.0001f));EQ(true, obj.gte(3f));EQ(true, obj.gte(2.999f));
   STEP="LT";    EQ(true, obj.lt(3.0001f));EQ(false, obj.lt(3f));EQ(false, obj.lt(2.999f));
   STEP="LTE";   EQ(false, obj.lte(3.0001f));EQ(true, obj.lte(3f));EQ(true, obj.lte(2.999f));
   STEP="EQ";    EQ(false, obj.eq(3.0001f));EQ(true, obj.eq(3f));
   STEP="SEQ";    EQ(false, obj.seq(3.0001f));EQ(true, obj.seq(3f));
   STEP="NEQ";    EQ(true, obj.neq(3.0001f));EQ(false, obj.neq(3f));
   STEP="SNEQ";   EQ(true, obj.sneq(3.0001f));EQ(false, obj.sneq(3f));
}

function initFltAr(){
  STEP = "float-typed arithmetic with floats ";
  var x1:float, y1:float,z1:float;
  x1 = 3.1415f; y1=2.73f; z1=1.44f;
  x1 += y1*z1++; y1 -= (z1--)/(++x1);
  z1 = -x1---y1;
  x1 = x1 + z1 % +y1;

  APPROX_EQ(6.283240318f,x1);
  APPROX_EQ(2.427746773f,y1);
  APPROX_EQ(-10.50044727f,z1);

  var cmpres:String="FAIL";
  if(x1<y1)
      cmpres="x1<y1";
  else
  if(y1<=z1)
      cmpres="y1<=z1";
  else
  if(z1>x1)
      cmpres="z1>x1";
  else
  if(y1>=x1)
      cmpres="y1>=x1";
  else
  if(z1==y1)
      cmpres="z1==y1";
  else
  if(z1===x1)
      cmpres="z1===x1";
  else {
  x1 = y1++;
  z1 = --y1;
  if(z1!=x1)
      cmpres="x1!=z1";
  else
  if(x1!==z1)
      cmpres="x1!==z1";
  else
     cmpres="OK";
  }

  AddTestCase("float-typed comparisons with floats ", "OK",cmpres);

/*===========================================================================================================================*/

  STEP = "Any-typed arithmetic with floats ";
  var x2, y2,z2;
  x2 = 3.1415f; y2=2.73f; z2=1.44f;
  x2 += y2*z2++;   y2 -= (z2--)/(++x2);
  z2 = -x2---y2;
  x2 = x2 + z2 % +y2;

  APPROX_EQ(6.283240318f,x2);
  APPROX_EQ(2.427746773f,y2);
  APPROX_EQ(-10.50044727f,z2);

  AddTestCase("x2 type", "float",getQualifiedClassName(x2));
  AddTestCase("y2 type", "float",getQualifiedClassName(y2));
  AddTestCase("z2 type", "float",getQualifiedClassName(z2));

  cmpres"FAIL";
  if(x2<y2)
      cmpres="x2<y2";
  else
  if(y2<=z2)
      cmpres="y2<=z2";
  else
  if(z2>x2)
      cmpres="z2>x2";
  else
  if(y2>=x2)
      cmpres="y2>=x2";
  else
  if(z2==y2)
      cmpres="z2==y2";
  else
  if(z2===x2)
      cmpres="z2===x2";
  else {
  x2 = y2++;
  z2 = --y2;
  if(z2!=x2)
      cmpres="x2!=z2";
  else
  if(x2!==z2)
      cmpres="x2!==z2";
  else
     cmpres="OK";
  }

  AddTestCase("Any-typed comparisons with floats", "OK",cmpres);
/*===========================================================================================================================*/

  STEP = "Any-typed arithmetic with mixed types ";
  x2 = 3.1415; y2=2.73f; z2=1.44f;
  x2 += y2*z2++; y2 -= (z2--)/(++x2);
  z2 = -x2---y2;
  AddTestCase("x2 type", "Number",getQualifiedClassName(x2));
  AddTestCase("y2 type", "Number",getQualifiedClassName(y2));
  AddTestCase("z2 type", "Number",getQualifiedClassName(z2));
  /* convert to float */
  x1=x2;y1=y2;z1=z2;x2=x1;y2=y1;z2=z1;
  x2 = x2 + z2 % +y2;

  APPROX_EQ(6.283240318f,x2);
  APPROX_EQ(2.427746773f,y2);
  APPROX_EQ(-10.50044727f,z2);

  AddTestCase("x2 type", "float",getQualifiedClassName(x2));
  AddTestCase("y2 type", "float",getQualifiedClassName(y2));
  AddTestCase("z2 type", "float",getQualifiedClassName(z2));

  y2 = 2.427746773;
  cmpres"FAIL";
  if(x2<y2)
      cmpres="x2<y2";
  else
  if(y2<=z2)
      cmpres="y2<=z2";
  else
  if(z2>Number(x2))
      cmpres="z2>x2";
  else
  if(y2>=x2)
      cmpres="y2>=x2";
  else
  if(z2==y2)
      cmpres="z2==y2";
  else
  if(Number(z2)===x2)
      cmpres="z2===x2";
  else {
  x2 = float(y2++);
  z2 = float(--y2);
  if(z2!=Number(x2))
      cmpres="x2!=z2";
  else
  if(x2!==Number(z2) )
      cmpres="x2!==z2";
  else
     cmpres="OK";
  }

  AddTestCase("Any-typed comparisons with mixed types ", "OK",cmpres);


}

floatTest[ft_count++] = new TestSection("\n === float op Any (float) ===\n", initFltAnyTests);
floatTest[ft_count++] = new TestSection("\n === float op float ===\n", initFltFltTests);
floatTest[ft_count++] = new TestSection("\n === float op Number ===\n", initFltNumTests);
floatTest[ft_count++] = new TestSection("\n === float op Any (Number) ===\n", initFltAnyTests2);
floatTest[ft_count++] = new TestSection("\n === float op int ===\n", initFltIntTests);

floatTest[ft_count++] = new TestSection("\n === float arithmetic  ===\n", initFltAr);

trace("Starting tests...");
for(var i:int=0;i<ft_count;i++){
   floatTest[i].RUN();
}