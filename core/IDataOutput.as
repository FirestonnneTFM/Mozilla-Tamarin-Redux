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
    
/**
* The IDataOutput interface provides a set of methods for writing binary data.
* This interface is the I/O counterpart to the IDataInput interface, which
* reads binary data. The IDataOutput interface is implemented by the FileStream, Socket
* and ByteArray classes.
* <p>All IDataInput and IDataOutput operations are "bigEndian" by default (the most significant
* byte in the sequence is stored at the lowest or first storage address),
* and are nonblocking. </p>
* <p>Sign extension matters only when you read data, not when you write it. Therefore, you do not need separate
* write methods to work with <code>IDataInput.readUnsignedByte()</code> and
* <code>IDataInput.readUnsignedShort()</code>. In other words:</p>
* <ul>
*   <li>Use <code>IDataOutput.writeByte()</code> with <code>IDataInput.readUnsignedByte()</code> and
*     <code>IDataInput.readByte()</code>.</li>
*   <li>Use <code>IDataOutput.writeShort()</code> with <code>IDataInput.readUnsignedShort()</code> and
*     <code>IDataInput.readShort()</code>.</li>
* </ul>
*
* @includeExample examples\DataOutputExample.as -noswf
*
* @see flash.utils.IDataInput IDataInput interface
* @see #endian
* @see flash.filesystem.FileStream FileStream class
* @see flash.net.Socket Socket class
* @see flash.net.URLStream URLStream class
* @see flash.utils.ByteArray ByteArray class
* @playerversion Flash 9
* @langversion 3.0
*
*  @playerversion Lite 4
*/
public interface IDataOutput
{
    /**
     * Writes a sequence of bytes from the
     * specified byte array, <code>bytes</code>,
     * starting at the byte specified by <code>offset</code>
     * (using a zero-based index)
     * with a length specified by <code>length</code>,
     * into the file stream, byte stream, or byte array.
     *
     * <p>If the <code>length</code> parameter is omitted, the default
     * length of 0 is used and the entire buffer starting at
     * <code>offset</code> is written.
     * If the <code>offset</code> parameter is also omitted, the entire buffer is
     * written. </p>
     *
     * <p>If the <code>offset</code> or <code>length</code> parameter
     * is out of range, they are clamped to the beginning and end
     * of the <code>bytes</code> array.</p>
     * @param bytes The byte array to write.
     * @param offset A zero-based index specifying the position into the array to begin writing.
     * @param length An unsigned integer specifying how far into the buffer to write.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeBytes(bytes:ByteArray,
                               offset:uint=0,
                               length:uint=0):void;

    /**
     * Writes a Boolean value. A single byte is written according to the <code>value</code> parameter,
     * either 1 if <code>true</code> or 0 if <code>false</code>.
     *
     * @param value A Boolean value determining which byte is written. If the parameter is <code>true</code>,
     * 1 is written; if <code>false</code>, 0 is written.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeBoolean(value:Boolean):void;


    /**
     * Writes a byte.
     * The low 8 bits of the
     * parameter are used; the high 24 bits are ignored.
     * @param value A byte value as an integer.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeByte(value:int):void;


    /**
     * Writes a 16-bit integer. The low 16 bits of the parameter are used;
     * the high 16 bits are ignored.
     * @param value A byte value as an integer.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeShort(value:int):void;


    /**
     * Writes a 32-bit signed integer.
     * @param value A byte value as a signed integer.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeInt(value:int):void;


    /**
     * Writes a 32-bit unsigned integer.
     * @param value A byte value as an unsigned integer.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeUnsignedInt(value:uint):void;


    /**
     * Writes an IEEE 754 single-precision (32-bit) floating point number.
     * @param value A single-precision (32-bit) floating point number.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeFloat(value:Number):void;


    /**
     * Writes an IEEE 754 double-precision (64-bit) floating point number.
     * @param value A double-precision (64-bit) floating point number.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeDouble(value:Number):void;


    /**
     * Writes a multibyte string to the file stream, byte stream, or byte array, using the specified character set.
     *
     * @param value The string value to be written.
     * @param charSet The string denoting the character set to use. Possible character set strings
     * include <code>"shift-jis"</code>, <code>"cn-gb"</code>, <code>"iso-8859-1"</code>, and others.
     * For a complete list, see <a href="../../charset-codes.html">Supported Character Sets</a>.
     * @playerversion Flash 9
     * @langversion 3.0
     * @helpid
     * @refpath
     * @keyword IDataOutput, IDataOutput.writeMultiByte, writeMultiByte
     *
     *  @playerversion Lite 4
     */
    function writeMultiByte(value:String, charSet:String):void;


    /**
     * Writes a UTF-8 string to the file stream, byte stream, or byte array. The length of the UTF-8 string in bytes
     * is written first, as a 16-bit integer, followed by the bytes representing the
     * characters of the string.
     * @param value The string value to be written.
     *
     * @throws RangeError If the length is larger than
     * 65535.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeUTF(value:String):void;


    /**
     * Writes a UTF-8 string. Similar to <code>writeUTF()</code>,
     * but does not prefix the string with a 16-bit length word.
     * @param value The string value to be written.
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeUTFBytes(value:String):void;


    /**
     * Writes an object to the file stream, byte stream, or byte array, in AMF serialized
     * format.
     * @param object The object to be serialized.
     *
     * @see #objectEncoding
     * @see ../../flash/net/package.html#registerClassAlias() flash.net.registerClassAlias()
     *
     * @internal throws IOError An I/O error occurred?
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function writeObject(object:*):void;


    /**
     * Used to determine whether the AMF3 or AMF0 format is used when writing or reading binary data using the
     * <code>writeObject()</code> method. The value is a constant from the ObjectEncoding class.
     *
     * @see IDataInput#readObject()
     * @see #writeObject()
     * @see flash.net.ObjectEncoding ObjectEncoding class
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function get objectEncoding():uint;
    function set objectEncoding(version:uint):void;


    /**
     * The byte order for the data, either the <code>BIG_ENDIAN</code> or <code>LITTLE_ENDIAN</code>
     * constant from the Endian class.
     *
     * @see flash.utils.Endian Endian class
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */
    function get endian():String;
    function set endian(type:String):void;
}

/*
 * [ggrossman 03/24/05] API SCRUB
 * - Created
 */

}
