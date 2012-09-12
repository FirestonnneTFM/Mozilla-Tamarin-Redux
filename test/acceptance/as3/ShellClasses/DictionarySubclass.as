/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    import flash.utils.Dictionary

    var SECTION = "DictionarySubclass";
    var VERSION = "as3";
    startTest();
    var TITLE   = "test non-dynamic subclass of Dictionary class";

    writeHeaderToLog( SECTION + " "+ TITLE );

    // test constructors

    class SealedDictionary extends Dictionary
    {
        public function SealedDictionary(weakKeys:Boolean=false)
        {
            super(weakKeys);
        }
    };

    var dict:SealedDictionary=new SealedDictionary();
    AddTestCase(
      "SealedDictionary constructor no args",
      true,
      dict!=null
      );

    var dict_notweak:SealedDictionary=new SealedDictionary(false);
    AddTestCase(
      "SealedDictionary constructor weakKeys=false",
      true,
      dict_notweak!=null
      );

    var dict_weak:SealedDictionary=new SealedDictionary(true);
    AddTestCase(
      "SealedDictionary constructor weakKeys=true",
      true,
      dict_weak!=null
      );

    // test get/set keys and values

    AddTestCase(
      "empty SealedDictionary toString",
      "[object SealedDictionary]",
      dict.toString()
      );

    var tmp;
    
    tmp = void 0;
    try { tmp = dict_notweak['notfound']; }
    catch(e) { tmp = grabError(e, e.toString()); }

    AddTestCase(
      "SealedDictionary key lookup fails",
      "Error #1069",
      tmp
      );

    tmp = void 0;
    try { tmp = dict_weak['notfound']; }
    catch(e) { tmp = grabError(e, e.toString()); }

    AddTestCase(
      "weak SealedDictionary key lookup fails",
      "Error #1069",
      tmp
      );

    tmp = void 0;
    try { dict_notweak["one"]="one_value"; tmp = dict_notweak["one"]; }
    catch(e) { tmp = grabError(e, e.toString()); }
    
    AddTestCase(
      "SealedDictionary key is literal",
      "Error #1056",
      tmp
      );

    tmp = void 0;
    try { dict_weak["one"]="one_value"; tmp = dict_weak["one"]; }
    catch(e) { tmp = grabError(e, e.toString()); }
    
    AddTestCase(
      "weak SealedDictionary key is literal",
      "Error #1056",
      tmp
    );

    var obj1:Object=new Object();
    obj1.toString = function() { return "obj1" }

    // sadly, sealed subclasses of Dictionary should probably
    // throw the same error for Object keys, but they don't
    // (ie they are sealed for normal keys but not Object keys)
    // this is arguably a bug, but one that can't be fixed without
    // versioning
    tmp = void 0;
    try { dict_notweak[obj1]="obj1_value"; tmp = dict_notweak[obj1]; }
    catch(e) { tmp = grabError(e, e.toString()); }
    
    AddTestCase(
      "SealedDictionary key is object",
      "obj1_value",
      tmp
      );

    tmp = void 0;
    try { dict_weak[obj1]="obj1_value"; tmp = dict_weak[obj1]; }
    catch(e) { tmp = grabError(e, e.toString()); }
    
    AddTestCase(
      "weak SealedDictionary key is object",
      "obj1_value",
      tmp
    );

    // test in (hasAtomProperty)
    
    AddTestCase(
      "literal in SealedDictionary key",
      false,
      ("one" in dict_notweak)
    );
    // see above: Object keys ignore sealed-ness
    AddTestCase(
      "object in SealedDictionary key",
      true,
      obj1 in dict_notweak
    );
    AddTestCase(
      "literal in weak SealedDictionary key",
      false,
      "one" in dict_weak
    );
    AddTestCase(
      "object in weak SealedDictionary key",
      true,
      obj1 in dict_weak
    );

    var a;
    var out1=new Array();
    for (a in dict_notweak) {
        out1.push(a.toString());
    }
    out1.sort();
    AddTestCase(
     "for in SealedDictionary",
     "obj1",
     out1.toString());

    var out2=new Array(0);
    for (a in dict_weak) {
        out2.push(a.toString());
    }
    out2.sort();
    AddTestCase(
     "for in weak SealedDictionary",
     "obj1",
     out2.toString());

    var out3=new Array();
    for each (a in dict_notweak) {
        out3.push(a.toString());
    }
    out3.sort();
    AddTestCase(
     "for each in SealedDictionary",
     "obj1_value",
     out3.toString());

    var out4=new Array();
    for each (a in dict_weak) {
        out4.push(a.toString());
    }
    out4.sort();
    AddTestCase(
     "for each in weak SealedDictionary",
     "obj1_value",
     out4.toString());

// test delete

    // see above: Object keys ignore sealed-ness
    tmp = delete dict_notweak['one'];
    AddTestCase(
     "delete literal key from SealedDictionary",
     false,
     tmp);

    tmp = delete dict_notweak[obj1];
    AddTestCase(
     "delete object key from SealedDictionary",
     true,
     tmp);

    // see above: Object keys ignore sealed-ness
    tmp = delete dict_weak['one'];
    AddTestCase(
     "delete literal key from weak SealedDictionary",
     false,
     tmp);

    tmp = delete dict_weak[obj1];
    AddTestCase(
     "delete object key from weak SealedDictionary",
     true,
     tmp);

    test();

