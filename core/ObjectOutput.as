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
 * When an object being serialized has implemented the IExternalizable Interface,
 * native code in the player will construct an ObjectOutput to use as the parameter to:
 *      function writeExternal(output:IDataOutput):void;
 *
 * ObjectOutput's native code will redirect each of the below methods to
 * the same method on the real object being written to.
 */
    
[native(cls="ObjectOutputClass", gc="exact", instance="ObjectOutputObject", methods="auto")]
internal class ObjectOutput implements IDataOutput
{
    public native function writeBytes(bytes:ByteArray, offset:uint=0, length:uint=0):void;
    public native function writeBoolean(value:Boolean):void;
    public native function writeByte(value:int):void;
    public native function writeShort(value:int):void;
    public native function writeInt(value:int):void;
    public native function writeUnsignedInt(value:uint):void;
    public native function writeFloat(value:Number):void;
    public native function writeDouble(value:Number):void;
    public native function writeMultiByte(value:String, charSet:String):void;
    public native function writeUTF(value:String):void;
    public native function writeUTFBytes(value:String):void;
    public native function writeObject(object:*):void;

    public native function get objectEncoding():uint;
    public native function set objectEncoding(version:uint):void;

    public native function get endian():String;
    public native function set endian(type:String):void;
}


}
