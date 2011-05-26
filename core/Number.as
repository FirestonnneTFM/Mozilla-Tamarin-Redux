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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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
    // No instancegc, value is primitive.

    [native(cls="NumberClass", classgc="exact", instance="double", methods="auto", construct="override")]
    public final class Number
    {
        // Number.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1

        // E262 {DontEnum, DontDelete, ReadOnly}
        public static const NaN               :Number = 0/0
        public static const NEGATIVE_INFINITY :Number = -1/0
        public static const POSITIVE_INFINITY :Number = 1/0
        public static const MIN_VALUE         :Number = _minValue() // typically: 4.9e-324
        public static const MAX_VALUE         :Number = 1.7976931348623158e+308

        // these must match the same constants in MathUtils
        private static const DTOSTR_FIXED:int = 1
        private static const DTOSTR_PRECISION:int = 2
        private static const DTOSTR_EXPONENTIAL:int = 3

        private static native function _numberToString(n:Number, radix:int):String
        private static native function _convert(n:Number, precision:int, mode:int):String
        private static native function _minValue():Number

        AS3 function toString(radix=10):String {
            return _numberToString(this,radix)
        }
        AS3 function valueOf():Number { return this }

        prototype.toLocaleString =
        prototype.toString = function (radix=10):String
        {
            if (this === prototype) return "0"

            if (!(this is Number))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "Number.prototype.toString" );

            return _numberToString(this, radix)
        }

        prototype.valueOf = function()
        {
            if (this === prototype) return 0
            if (!(this is Number))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "Number.prototype.valueOf" );
            return this;
        }

        AS3 function toExponential(p=0):String
        {
            return _convert(this, int(p), DTOSTR_EXPONENTIAL)
        }
        prototype.toExponential = function(p=0):String
        {
            return _convert(Number(this), int(p), DTOSTR_EXPONENTIAL)
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

            return _convert(Number(this), int(p), DTOSTR_PRECISION)
        }

        AS3 function toFixed(p=0):String
        {
            return _convert(this, int(p), DTOSTR_FIXED)
        }
        prototype.toFixed = function(p=0):String
        {
            return _convert(Number(this), int(p), DTOSTR_FIXED)
        }

        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in NumberClass::construct in the avmplus
        public function Number(value = 0)
        {}

        _dontEnumPrototype(prototype);
    }

    // No instancegc, value is primitive.

    [native(cls="FloatClass", classgc="exact", instance="float", methods="auto", construct="override")]
    [API(CONFIG::SWF_16)]
    CONFIG::VMCFG_FLOAT
    public final class float
    {
        // E262 {DontEnum, DontDelete, ReadOnly}
        public static const NaN               :float = float(0/0)
        public static const NEGATIVE_INFINITY :float = float(-1/0)
        public static const POSITIVE_INFINITY :float = float(1/0)
        public static const MIN_VALUE         :float = _minValue() // 1.175494351e-38 
        public static const MAX_VALUE         :float = float(3.4028235e+38); // exact value: 340282346638528859811704183484516925440, bit pattern: 0x7f7fffff
        public static const E                 :float = float(2.7182818);
        public static const LN10              :float = float(2.30258509);
        public static const LN2               :float = float(0.693147181);
        public static const LOG2E             :float = float(1.44269504);
        public static const PI                :float = float(3.1415927);
        public static const SQRT1_2           :float = float(7.0710677e-1);
        public static const SQRT2             :float = float(1.4142135);
        // these must match the same constants in MathUtils
        private static const DTOSTR_FIXED:int = 1
        private static const DTOSTR_PRECISION:int = 2
        private static const DTOSTR_EXPONENTIAL:int = 3

        // float.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1



        public static        function abs        (x:float)        :float  { return float( Math.abs(x) );     }
        public static        function acos       (x:float)        :float  { return float( Math.acos(x) );    }
        public static        function asin       (x:float)        :float  { return float( Math.asin(x) );    }
        public static        function atan       (x:float)        :float  { return float( Math.atan(x) );    }
        public static        function atan2      (y:float,x:float):float  { return float( Math.atan2(y,x) ); }
        public static        function ceil       (x:float)        :float  { return float( Math.ceil(x) );    }
        public static        function cos        (x:float)        :float  { return float( Math.cos(x) );     }
        public static        function exp        (x:float)        :float  { return float( Math.exp(x) );     }
        public static        function floor      (x:float)        :float  { return float( Math.floor(x) );   }
        public static        function log        (x:float)        :float  { return float( Math.log(x) );     }
        public static        function pow        (x:float,y:float):float  { return float( Math.pow(x,y) );   }
        public static        function random     ()               :float  { return float( Math.random() );   }
        public static        function round      (x:float)        :float  { return float( Math.round(x) );   }
        public static        function sin        (x:float)        :float  { return float( Math.sin(x) );     }
        public static        function sqrt       (x:float)        :float  { return float( Math.sqrt(x) );    }
        public static        function tan        (x:float)        :float  { return float( Math.tan(x) );     }
        public static native function reciprocal (arg:float)      :float;
        public static native function rsqrt      (arg:float)      :float;

        public static function max( ...xs ) : float  
        {
            var result:float = NEGATIVE_INFINITY;
            for(var i:int = 0; i<xs.length; i++)
            {
                var p: float = float(xs[i]);
                if(isNaN(p)) return p;
                if(p > result) result = p;
                else if( p == result && p == 0 && (1/result)<0 ) result = p; // replace "-0" with "+0". 
            }
            return result;
        }

        public static function min( ...xs ) : float  
        {
            var result:float = POSITIVE_INFINITY;
            for(var i:int = 0; i<xs.length; i++)
            {
                var p: float = float(xs[i]);
                if(isNaN(p)) return p;
                if(p < result) result = p;
                else if( p == result && p == 0 && (1/result)>0 ) result = p; // replace "+0" with "-0". 
            }
            return result;
        }

        private static native function _minValue ():float
        private static native function _floatToString(n:float, radix:int):String
        private static native function _convert(n:float, precision:int, mode:int):String

        AS3 function toString(radix=10):String
        {
            return _floatToString(this, radix)
        }
        AS3 function valueOf():float { return this }

        prototype.toLocaleString =
        prototype.toString = function (radix=10):String
        {
            if (this === prototype) return "0"

            if (!(this is float))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "float.prototype.toString" );

            return _floatToString(this, radix)
        }

        prototype.valueOf = function()
        {
            if (this === prototype) return 0
            if (!(this is float))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "float.prototype.valueOf" );
            return this
        }

        AS3 function toExponential(p=0):String
        {
            return _convert(this, int(p), DTOSTR_EXPONENTIAL);
        }
        prototype.toExponential = function(p=0):String
        {
            return _convert(float(this), int(p), DTOSTR_EXPONENTIAL); 
        }


        AS3 function toPrecision(p=0):String
        {
            return _convert(this, int(p), DTOSTR_PRECISION);
        }
        prototype.toPrecision = function(p=0):String
        {
            return _convert(float(this), int(p), DTOSTR_PRECISION); 
        }

        AS3 function toFixed(p=0):String
        {
            return _convert(this, int(p), DTOSTR_FIXED);
        }
        prototype.toFixed = function(p=0):String
        {
            return _convert(float(this), int(p), DTOSTR_FIXED); 
        }

        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in FloatClass::construct in the avmplus
        public function float(value = 0)
        {}

        _dontEnumPrototype(prototype);
    }


   // No instancegc, value is primitive.
   
    [native(cls="IntClass", classgc="exact", instance="int32_t", methods="auto", construct="override")]
    public final class int
    {
        // based on Number: E262 {ReadOnly, DontDelete, DontEnum}
        public static const MIN_VALUE:int = -0x80000000;
        public static const MAX_VALUE:int =  0x7fffffff;

        // Number.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1

        AS3 function toString(radix=10):String {
            return Number(this).AS3::toString(radix)
        }
        AS3 function valueOf():int { return this }

        prototype.toLocaleString =
        prototype.toString = function toString(radix=10):String
        {
            if (this === prototype) return "0"
            if (!(this is int))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "int.prototype.toString" );
            return Number(this).toString(radix)
        }

        prototype.valueOf = function()
        {
            if (this === prototype) return 0
            if (!(this is int))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "int.prototype.valueOf" );
            return this
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
        // The code for the actual ctor is in IntClass::construct in the avmplus
        public function int(value = 0)
        {}

        _dontEnumPrototype(prototype);
    }

    // No instancegc, value is primitive.

    [native(cls="UIntClass", classgc="exact", instance="uint32_t", methods="auto", construct="override")]
    public final class uint
    {
        // based on Number: E262 {ReadOnly, DontDelete, DontEnum}
        public static const MIN_VALUE:uint = 0;
        public static const MAX_VALUE:uint = 0xffffffff;

        // Number.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum}
        public static const length:int = 1

        AS3 function toString(radix=10):String {
            return Number(this).AS3::toString(radix)
        }
        AS3 function valueOf():uint { return this }

        prototype.toLocaleString =
        prototype.toString = function toString(radix=10):String
        {
            if (this === prototype) return "0"
            if (!(this is Number))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "uint.prototype.toString" );
            return Number(this).toString(radix)
        }

        prototype.valueOf = function()
        {
            if (this === prototype) return 0
            if (!(this is uint))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "uint.prototype.valueOf" );
            return this
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
        // The code for the actual ctor is in UIntClass::construct in the avmplus
        public function uint(value = 0)
        {}

        _dontEnumPrototype(prototype);
    }
}
