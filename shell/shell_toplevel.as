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

package avmplus 
{
    import flash.utils.ByteArray

	// this namespace exists solely so that nativegen.py will encounter them during shell building,
	// thus giving us a test case for parsing methods with custom namespaces in nativegen.py
	namespace ns_example = "http://www.example.com"

	// this interface exists solely so that nativegen.py will encounter them during shell building,
	// thus giving us a test case for interface parsing in nativegen.py
	interface ITest
	{
		function test();
	}
	class CTest //implements ITest
	{
		public function test() { }
	}

	// this class exists solely to test native classes that use MI.
	[native(cls="MIClass", instance="MIObject", methods="MIObjectImpl")]
	internal class MI
	{
		public native function plus(i:Number):Number;
	}

	[native(cls="SystemClass", methods="auto")]
	public class System
	{
		// this metadata exists solely so that nativegen.py will encounter it during shell building,
		// thus giving us a test case for metadata parsing in nativegen.py
		[foo]
		public native static function exit(status:int):void

		// this metadata exists solely so that nativegen.py will encounter it during shell building,
		// thus giving us a test case for metadata parsing in nativegen.py
		[bar(attr="whatever")]
		public native static function exec(command:String):int

		public native static function getAvmplusVersion():String
		public native static function trace(a:Array):void
		public native static function write(s:String):void
		public native static function debugger():void
		public native static function isDebugger():Boolean
		public native static function getTimer():uint
		private native static function getArgv():Array
		public static const argv:Array = getArgv();
		public native static function readLine():String;

		// Amount of real memory we've aqcuired from the OS
		public native static function get totalMemory():Number;

		// Part of totalMemory we aren't using
		public native static function get freeMemory():Number;

		// process wide size of resident private memory 
		public native static function get privateMemory():Number;

        // Initiate a garbage collection; future versions will not return before completed.
        public native static function forceFullCollection():void;

        // Queue a garbage collection request.
        public native static function queueCollection():void;

		// function exists solely to test native-methods with custom namespaces
		ns_example native static function nstest():void;

		// function exists solely to test ScriptObject::isGlobalObject
		public native static function isGlobal(o:Object):Boolean;
	}
	
	[native(cls="FileClass", methods="auto")]
	public class File
	{
		public native static function exists(filename:String):Boolean;
		public native static function read(filename:String):String;
		public native static function write(filename:String, data:String):void;

		public static function fileToByteArray(filename:String, readOnly:Boolean):ByteArray
		{
			return ByteArray.readFile(filename)
		}

		public static function writeByteArray(filename:String, bytes:ByteArray):Boolean
		{
			bytes.writeFile(filename)
			return true
		}
	}

	public function debugger()
	{
		System.debugger()
	}
}

// The flash.system package is present so identical ATS test media can be used
// in the command-line VM and the Player
package flash.system
{
	import avmplus.*;
	
	public final class Capabilities
	{
		public static function get playerType():String { return "AVMPlus"; }
		public static function get isDebugger():Boolean { return System.isDebugger(); }
	}
}
		
package {

	import avmplus.*

	public function getClassByName(name:String):Class
	{
		return Domain.currentDomain.getClass(name);
	}
		
	// nonstandard extensions to ECMAScript
	public function print(...s)
	{
		System.trace(s)
	}

	// nonstandard Flash Player extensions
	public function trace(...s)
	{
		System.trace(s)
	}

	public function getTimer():uint
	{
		return System.getTimer()
	}

	public function readLine():String
	{
		return System.readLine()
	}
}

// test library code

/*
[0,player,full]=660:FP_9_0
[0,air,full]=661:AIR_1_0
[1,player,full]=662:FP_10_0
[1,air,full]=663:AIR_1_5
[2,air,full]=664:AIR_1_5_1
[3,player,full]=665:FP_10_1
[3,air,mobile]=667:AIR_ZEPHYR
[3,air,full]=666:AIR_ATHENA

static const uint32_t _min_version_num = 660;
static const uint32_t _max_version_num = 667;
static const uint32_t _versions_count[] = {7, 4, 5, 3, 2, 2, 1, 2, };

static const uint32_t _versions [][8] = {
  {660, 661, 662, 663, 664, 665, 666, },
  {661, 663, 664, 666, },
  {662, 663, 664, 665, 666, },
  {663, 664, 666, },
  {664, 666, },
  {665, 666, },
  {666, },
  {667, 666, },
};
*/
/*
 tests
 - unversioned names: are in all versions, as though version 0
 - versioned names: are not visible to smaller versions (bindings, not number)
 - multiple versioned names: are visible to all compatible versions
 - class, interface, method, accessor, slot, static names
 - running multiple active versions
*/
/*
package avmplus {
[API(660)] public var x0 = true;
[API(661)] public var x1 = true;
[API(662)] public var x2 = true;
[API(663)] public var x3 = true;
[API(664)] public var x4 = true;
[API(665)] public var x5 = true;
[API(661,662)] public var x12 = true;
[API(662,663)] public var x23 = true;


public class A {
    public function m () {
        return 10;
    }

    [API(661)] public var x = 10;


    [API(661,662)] public function n () {
        return 20;
	}

	[API(661,662)] public function p () {
	    return 30;
    }
}

[API(665)] public class B extends A {
    override public function m() { return 50 }
}

public class C {
    public static function m() { return new B().m() }
}
}
*/