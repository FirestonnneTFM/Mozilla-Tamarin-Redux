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
// % java -ea -DAS3 -Xmx200m -DAVMPLUS -classpath ../utils/asc.jar macromedia.asc.embedding.ScriptCompiler -abcfuture -builtin -import ../core/builtin.abc -import ../esc/bin/parse.es.abc -import ../esc/bin/cogen.es.abc -out axtoplevel mscom.as ../shell/Domain.as ../shell/ByteArray.as && move /y ..\shell\axtoplevel.* .

package axtam 
{
	// should possibly be private...
	public class System
	{
		public native static function getAvmplusVersion():String
		public native static function write(s:String):void
		public native static function debugger():void
		public native static function isDebugger():Boolean
	}
}

package axtam.com {
	public class constants {
		public static const E_NOTIMPL = 0x80004001
	}

	// Its not clear if we should subclass the standard 'Error', but given
	// it has its own concept of 'Message' and 'ID', it doesn't seem a good fit.
	// Maybe a new base-class should be introduced.
	public dynamic class Error
	{
		function Error(hresult) {
			this.hresult = hresult;
		}

		public native static function getErrorMessage(index:int):String;
	}

	public class MSCom
	{
		// this is a native class that manages the 'dynamic' properties
		// hiding behind a COM IDispatch/IDispatchEx interfaces.
		// It can only be created by native code.
	}
}

package axtam.com.adaptors.consumer {
	// scripting interfaces we consume in AS (ie, implemented externally)
	// Each method listed here corresponds to a native method in the engine, 
	// which inturn delegates to the IActiveScriptSite COM object.
	public class ScriptSite
	{
		public native function GetItemInfo(name:String, flag:int):Object
		public native function GetDocVersionString(): String
	}
}

package {

    import avmplus.*; // for our Domain clone - either it should die, or we rename the package in our clone!
    import flash.utils.*; // for our ByteArray clone - either it should die, or we rename the package in our clone!


    public function execString(str)
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
        Domain.currentDomain.loadBytes(b);
    }

   }

package {

	class ScriptEngine {
			public function ParseScriptText(code:String, itemName:String, context:Object, delim:String, sourceCookie:int, lineNumber:int, flags:int) {
				axtam.System.write('ParseScriptText\n')
				axtam.System.write(code)
				// XXX - this is wrong - we should only do the parse and generation
				// of bytecode here.  We should execute all such blocks at 
				// SetScriptState(SCRIPTSTATE_RUNNING) time.
				execString(code)

			}
			// This function is called as a 'named item' is added to the environment.
			// Examples include IE's 'window' object.
			public function AddNamedItem(name:String, flags:int):void
			{
				axtam.System.write('AddNamedItem(' + name + ',' + flags + ')\n')
				var site = new axtam.com.adaptors.consumer.ScriptSite()
				var info = site.GetItemInfo(name, 0)
				//axtam.System.write(info)
				engine_env[name] = info
			}
	}

	public var engine = new ScriptEngine()
	// This kinda sucks, but will do for now - it holds the 'named items'
	public var engine_env = new Object; // I want a Dictionary()!

	// and magically methods will be called on 'engine'
}
