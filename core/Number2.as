/* ***** BEGIN LICENSE BLOCK ***** 
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1 
 *
 * The contents of this file are subject to the Mozilla Public License Version 1.1 (the 
 * "License"); you may not use this file except in compliance with the License. You may obtain 
 * a copy of the License at http://www.mozilla.org/MPL/ 
 * 
 * Software distributed under the License is distributed on an "AS IS" basis, WITHOUT 
 * WARRANTY OF ANY KIND, either express or implied. See the License for the specific 
 * language governing rights and limitations under the License. 
 * 
 * The Original Code is [Open Source Virtual Machine.] 
 * 
 * The Initial Developer of the Original Code is Adobe System Incorporated.  Portions created 
 * by the Initial Developer are Copyright (C)[ 2004-2006 ] Adobe Systems Incorporated. All Rights 
 * Reserved. 
 * 
 * Contributor(s): Adobe AS3 Team
 * 
 * Alternatively, the contents of this file may be used under the terms of either the GNU 
 * General Public License Version 2 or later (the "GPL"), or the GNU Lesser General Public 
 * License Version 2.1 or later (the "LGPL"), in which case the provisions of the GPL or the 
 * LGPL are applicable instead of those above. If you wish to allow use of your version of this 
 * file only under the terms of either the GPL or the LGPL, and not to allow others to use your 
 * version of this file under the terms of the MPL, indicate your decision by deleting provisions 
 * above and replace them with the notice and other provisions required by the GPL or the 
 * LGPL. If you do not delete the provisions above, a recipient may use your version of this file 
 * under the terms of any one of the MPL, the GPL or the LGPL. 
 * 
 ***** END LICENSE BLOCK ***** */


package
{
	public final class double 
	{
		// Number.length = 1 per ES3
		// E262 {ReadOnly, DontDelete, DontEnum }
		public static const length:int = 1

		// E262 {DontEnum, DontDelete, ReadOnly}

		public static const NaN               :double = 0/0
		public static const NEGATIVE_INFINITY :double = -1/0
		public static const POSITIVE_INFINITY :double = 1/0
		public static const MIN_VALUE         :double = 4.9e-324 
		public static const MAX_VALUE         :double = 1.7976931348623158e+308


		// not used, thus commented out for now to save code size (srj)
 		//private static native function _toString(n:double, radix:int):String; // doesn't get used

		AS3 function toString(radix=10):String {
			return Number(this).AS3::toString(radix);
		}
		AS3 function valueOf():double { return this }
		
		prototype.toLocaleString = 
		prototype.toString = function (radix=10):String
		{
			if (this === prototype) return "0"
			
			if (!(this is double))
				Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "double.prototype.toString" );
				
			return Number(this).toString(radix);
		}

		prototype.valueOf = function()
		{
			if (this === prototype)	return 0
			if (!(this is double))
				Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "double.prototype.valueOf" );
			return this;
		}

		AS3 function toExponential(p=0):String
		{
			return Number(this).AS3::toExponential(p)
		}
		prototype.toExponential = function(p=0):String
		{
			return Number(this).AS3::toExponential(p)
		}

		AS3 function toPrecision(p=0):String
		{
			return Number(this).AS3::toPrecision(p)
		}
		prototype.toPrecision = function(p=0):String
		{
			return Number(this).AS3::toPrecision(p)
		}

		AS3 function toFixed(p=0):String
		{
			return Number(this).AS3::toFixed(p)
		}
		prototype.toFixed = function(p=0):String
		{
			return Number(this).AS3::toFixed(p)
		}

        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in DoubleClass::construct in the avmplus
        public function double(value = 0)
        {}

		_dontEnumPrototype(prototype);
	}

	public final class decimal
	{
		// based on Number: E262 {ReadOnly, DontDelete, DontEnum}
        //uncomment when can compile with decimal knowledgable compiler
        //public static const MIN_VALUE:decimal = 1E-6176m;
        //public static const MAX_VALUE:decimal = 9.999999999999999999999999999999999E+6144m;
        //public static const PI = 3.141592653589793238462643383279503m; 
		//public static const NaN               :decimal = 0m/0m;
		//public static const NEGATIVE_INFINITY :decimal = -1m/0m;
		//public static const POSITIVE_INFINITY :decimal = 1m/0m;

		private static const DTOSTR_FIXED:int = 1
		private static const DTOSTR_PRECISION:int = 2
		private static const DTOSTR_EXPONENTIAL:int = 3

        // these must match the constants in decContext.h
		public static const ROUND_CEILING:int = 0;
		public static const ROUND_UP:int = 1;
		public static const ROUND_HALF_UP:int = 2;
		public static const ROUND_HALF_EVEN:int = 3;
		public static const ROUND_HALF_DOWN:int = 4;
		public static const ROUND_DOWN:int = 5;
		public static const ROUND_FLOOR:int = 6;

		// Number.length = 1 per ES3
		// E262 {ReadOnly, DontDelete, DontEnum}
		public static const length:int = 1

		AS3 function valueOf():decimal { return this }

		private static native function _toString(n:decimal, radix:int):String
		private static native function _convert(n:decimal, precision:int, mode:int):String

		AS3 function toString(radix=10):String {
			return _toString(this,radix)
		}
		prototype.toLocaleString =
		prototype.toString = function toString(radix=10):String
		{
			if (this === prototype) return "0"
			if (!(this is decimal))
				Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "decimal.prototype.toString" );
			return _toString(this, radix)
		}

		prototype.valueOf = function()
		{
			if (this === prototype) return 0
			if (!(this is decimal))
				Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "decimal.prototype.valueOf" );
			return this
		}

		AS3 function toExponential(p=0):String
		{
			return _convert(this, int(p), DTOSTR_EXPONENTIAL);
		}
		prototype.toExponential = function(p=0):String
		{
			return _convert(decimal(this), int(p), DTOSTR_EXPONENTIAL);
		}

		AS3 function toPrecision(p=0):String
		{
			if (p == undefined)
				return this.toString();

			return _convert(this, int(p), DTOSTR_PRECISION)
		}
		prototype.toPrecision = function(p=0):String
		{
			if (p == undefined)
				return this.toString();
			
			return _convert(decimal(this), int(p), DTOSTR_PRECISION)
		}


		AS3 function toFixed(p=0):String
		{
			return _convert(this, int(p), DTOSTR_FIXED)
		}
		prototype.toFixed = function(p=0):String
		{
			return _convert(decimal(this), int(p), DTOSTR_FIXED)
		}


        /* many of the functions that are in Math.as, but taking and returning decimals
         */



	// min and max with 2 args are so common we overload these
        native private static function _min    (x:decimal, y:decimal):decimal;
        native private static function _max    (x:decimal, y:decimal):decimal;
	
	// wrappers for the above math methods.  these do automatic
	// conversion of their arguments.
	
 public native static function abs	(x:decimal)   :decimal;
 public native static function ceil	(x:decimal)   :decimal;
 public native static function exp	(x:decimal)   :decimal;
 public native static function floor	(x:decimal)   :decimal;
 public native static function log	(x:decimal)   :decimal;
 public native static function log10	(x:decimal)   :decimal;
 public native static function round	(x:decimal, rounding:int)   :decimal;
 public native static function sqrt	(x:decimal)   :decimal;

 public native static function pow	(x:decimal, y:decimal)	:decimal;
	
 public native static function max    (x:decimal = void 0, y:decimal = void 0, ... rest):decimal;
 public native static function min    (x:decimal = void 0, y:decimal = void 0, ... rest):decimal;


        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in DecimalClass::construct in the avmplus
        public function decimal(value = 0)
        {}

		_dontEnumPrototype(prototype);
	}
}
