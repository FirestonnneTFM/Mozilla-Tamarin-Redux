/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package LengthSpoofing
{
    public dynamic class SpoofingArray extends Array
    {
        var is_spoofing:Boolean;
        var spoofed_length:uint = 100;

        public function SpoofingArray()
        {
            super();
            is_spoofing = false;
        }

        override public function get length():uint
        {
            return ( this.is_spoofing )? spoofed_length: super.length;
        }

        public function set Spoofing(b:Boolean):void
        {
            this.is_spoofing = b;
        }

        public function set spoofedLength(x:uint):void
        {
            this.spoofedLength = x;
        }
    }
}


    var SECTION = "regress";
    var VERSION = "as3";
    startTest();
    var TITLE   = "test splice assumes length is correct bug";

    writeHeaderToLog( SECTION + " "+ TITLE );


//print("concat");
    var foo = new LengthSpoofing.SpoofingArray();
    foo.push(1);
    foo.push(2);
    foo.push(3);
    foo.Spoofing = true;
    AddTestCase(
      "test concat spoofing=true",
      "1,2,3,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,4,5,6",
      foo.concat([4,5,6]).toString()
      );
    foo.Spoofing = false;
    AddTestCase(
      "test concat spoofing=false",
      "1,2,3,4,5,6",
      foo.concat([4,5,6]).toString()
      );


//print("pop");
    foo = new LengthSpoofing.SpoofingArray();
    foo.push(1);
    foo.push(2);
    foo.push(3);
    foo.Spoofing = true;
    foo.pop();
    AddTestCase(
      "test pop spoofing=true",
      100,
      foo.length
      );
    foo.Spoofing = false;
    AddTestCase(
      "test pop spoofing=false",
      foo.length,
      2
      );

//print("reverse");
    foo = new LengthSpoofing.SpoofingArray();
    foo.push(1);
    foo.push(2);
    foo.push(3);

    foo.Spoofing = true;
    foo.reverse();
    AddTestCase(
      "test reverse spoofing=true",
      100,
      foo.length
      );
    foo.Spoofing = false;
    AddTestCase(
      "test reverse spoofing=false",
      3,
      foo.length
      );

//print("shift");
    foo = new LengthSpoofing.SpoofingArray();

    foo.Spoofing = true;
    foo.shift();
    AddTestCase(
      "test shift spoofing=true",
      ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,",
      foo.toString()
      );

    foo = new LengthSpoofing.SpoofingArray();
    foo.push(1);
    foo.push(2);
    foo.push(3);
    foo.Spoofing = false;
    foo.shift();
    AddTestCase(
      "test shift spoofing=false",
      "2,3",
      foo.toString()
      );

//  splice: fails
//print("splice");
    foo = new LengthSpoofing.SpoofingArray();

    foo.Spoofing = true;
    foo.splice(90,0,1,2,3,4,5);
    AddTestCase(
      "test splice spoofing=true",
      ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,1,2,3,4,5,,,,,",
      foo.toString()
      );
    foo.Spoofing = false;
    AddTestCase(
      "test splice spoofing=false",
      ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,1,2,3,4,5,,,,,,,,,,",
      foo.toString()
      );
    
    test();