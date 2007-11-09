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
 * The Original Code is [ActiveScripting implemented with Tamarin].
 *
 * The Initial Developer of the Original Code is Mozilla Corp.
 * Portions created by the Initial Developer are Copyright (C) 2007
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Mark Hammond
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

// hackery - for now, this file is "built" via:
// % java -ea -DAS3 -Xmx200m -DAVMPLUS -classpath ../utils/asc.jar macromedia.asc.embedding.ScriptCompiler -abcfuture -builtin -import ../core/builtin.abc -import ../esc/bin/parse.es.abc -import ../esc/bin/cogen.es.abc -out axtoplevel mscom.as Domain.as ../shell/ByteArray.as && move /y ..\shell\axtoplevel.* .

package axtam 
{
	// should possibly be private...
	public class System
	{
		public native static function getAvmplusVersion():String
		public native static function write(s:String):void
		public native static function trace(a:Array):void
		public native static function debugger():void
		public native static function isDebugger():Boolean
		public native static function nativeDebugBreak():void
	}
}

package 
{
	// a global 'print' statement...
	public function print(...s)
	{
		axtam.System.trace(s)
	}

}

package axtam.com {
	// Its not clear if we should subclass the standard 'Error', but given
	// it has its own concept of 'Message' and 'ID', it doesn't seem a good fit.
	// Maybe a new base-class should be introduced.
	public dynamic class Error
	{
		public static const E_NOTIMPL = 0x80004001
		public static const E_INVALIDARG = 0x80070057
		public static const E_UNEXPECTED = 0x8000ffff
		public static const E_FAIL = 0x80004005
		public static const E_NOINTERFACE = 0x80000004

		public var hresult: int
		function Error(hresult) {
			this.hresult = hresult;
			print('Error constructed')
		}

		prototype.toString = function():String
		{
			var e:axtam.com.Error = this
			return e.message !== "" ? e.name + ": " + e.message : e.name;
		}
		_setPropertyIsEnumerable(prototype, "toString", false);

		public native static function getErrorMessage(index:int):String;

		public static function throwError(hresult:int, ... rest)
		{
			// todo: rich error support?
			//throw new axtam.com.Error(hresult);
		}

	}
	// constants go directly in the axtam.com package.
	public const SCRIPTINFO_IUNKNOWN = 0x00000001
	public const SCRIPTINFO_ITYPEINFO = 0x00000002

	public const SCRIPTITEM_ISVISIBLE = 0x00000002
	public const SCRIPTITEM_ISSOURCE = 0x00000004
	public const SCRIPTITEM_GLOBALMEMBERS = 0x00000008
	public const SCRIPTITEM_ISPERSISTENT = 0x00000040
	public const SCRIPTITEM_CODEONLY = 0x00000200
	public const SCRIPTITEM_NOCODE = 0x00000400
	
}

package axtam.com.adaptors.consumer {
	// scripting interfaces we consume in AS (ie, implemented externally)
	// Each method listed here corresponds to a native method in the engine, 
	// which inturn delegates to the real COM object.
	// Note that some of these classes have no scriptable methods, but they
	// are used internally
	public class IUnknown
	{
	}

	// XXX - technically the rest of these 'derive' from IUnknown...
	public class IDispatch
	{
	}

	public class ITypeInfo
	{
	}

	public class IActiveScriptSite
	{
		// somewhat like GetItemInfo() - but gets both IDispatch and ITypelib,
		// and wraps them in a ScriptObject which can be used from script.
		public native function GetItemInfo(name:String, flags:uint):Array
		public native function GetDocVersionString(): String
	}
}

package {

    import flash.utils.*; // for our ByteArray clone - either it should die, or we rename the package in our clone!


    public function execString(str, domain)
    {
        import Parse.*;
        var top = []
        var parser = new Parse.Parser(str,top);
        var prog = parser.program();
        var ts = prog[0]
        var nd = prog[1]
        var bytes = Gen::cg(nd).getBytes();

        var b = new ByteArray();
        b.endian = "littleEndian";

        for (var i = 0, len = bytes.length; i<len; ++i) {
            b.writeByte(uint(bytes[i]));
        }
        domain.loadBytes(b);
    }

   }

package {

	class ScriptEngine {
			public var globalDomain:axtam.Domain;
			public var objectDomains; // A hashtable of named objects to their domains.
			public var state:int;
			public function ScriptEngine() {
			}
			public function InitNew() {
				//domain = Domain.currentDomain
				globalDomain = new axtam.Domain(null, null)
				objectDomains = {}
			}
			public function ParseScriptText(code:String, itemName:String, context:Object, delim:String, sourceCookie:int, lineNumber:int, flags:int) {
				print('ParseScriptText')
				print(code)
				// XXX - this is wrong - we should only do the parse and generation
				// of bytecode here.  We should execute all such blocks at 
				// SetScriptState(SCRIPTSTATE_RUNNING) time.
				var domain = objectDomains[itemName]
				if (!domain)
					domain = globalDomain
				execString(code, domain)

			}
			// This function is called as a 'named item' is added to the environment.
			// Examples include IE's 'window' object.
			public function AddNamedItem(name:String, flags:uint):void
			{
				print('AddNamedItem(', name, flags)
				var site = new axtam.com.adaptors.consumer.IActiveScriptSite()
				// MS docs say we should avoid grabbing typeinfo unless we
				// really need it.  At this stage, we need it if the item is
				// "global", and later will need it if it sources events
				var gii_flags:uint = axtam.com.SCRIPTINFO_IUNKNOWN
				if (flags & axtam.com.SCRIPTITEM_GLOBALMEMBERS)
					gii_flags |= axtam.com.SCRIPTINFO_ITYPEINFO

				var items = site.GetItemInfo(name, gii_flags)
				var dispatch = items[0]
				var typeinfo = items[1]
				globalDomain.global[name] = dispatch
				// but we also need to tell the VM exactly what 'scope'
				// provides this object.
				globalDomain.addNamedScriptObject(name)
				// if its global, we enumerate items and make them public - all 
				// this is done inside exposeGlobalMembers
				//if (flags & axtam.com.SCRIPTITEM_GLOBALMEMBERS && typeinfo != null) {
				//	domain.exposeGlobalMembers(dispatch, typeinfo)
				//}
				// create a new domain for the object with the IDispatch as its global.
				var obDomain =  new axtam.Domain(globalDomain, dispatch)
				objectDomains[name] = obDomain
			}

			public function GetScriptState(): uint
			{
				return state;
			}

			public function SetScriptState(new_state:uint): void
			{
				// don't allow new state transitions once we are closed.
				axtam.com.Error.throwError(axtam.com.Error.E_INVALIDARG)
			}

	}

	public var engine = new ScriptEngine()
	// and magically methods will be called on 'engine'
}
