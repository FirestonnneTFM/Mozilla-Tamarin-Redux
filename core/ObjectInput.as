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

package flash.utils
{

/*
 * This class is internal to flash.utils, so it does not require ASDoc's
 *
 * When an object being deserialized has implemented the IExternalizable Interface,
 * native code in the player will construct an ObjectInput to use as the parameter to:
 *      function readExternal(output:IDataOutput):void;
 *
 * ObjectInput's native code will redirect each of the below methods to
 * the same method on the real object being read from.
 */
    
    
[native(cls="ObjectInputClass", gc="exact", instance="ObjectInputObject", methods="auto")]
internal class ObjectInput implements IDataInput
{
    public native function readBytes(bytes:ByteArray, offset:uint=0, length:uint=0):void;
    public native function readBoolean():Boolean;
    public native function readByte():int;
    public native function readUnsignedByte():uint;
    public native function readShort():int;
    public native function readUnsignedShort():uint;
    public native function readInt():int;
    public native function readUnsignedInt():uint;
    public native function readFloat():Number;
    public native function readDouble():Number;
    public native function readMultiByte(length:uint, charSet:String):String;
    public native function readUTF():String;
    public native function readUTFBytes(length:uint):String;
    public native function get bytesAvailable():uint;
    public native function readObject():*;

    public native function get objectEncoding():uint;
    public native function set objectEncoding(version:uint):void;

    public native function get endian():String;
    public native function set endian(type:String):void;
}

}
