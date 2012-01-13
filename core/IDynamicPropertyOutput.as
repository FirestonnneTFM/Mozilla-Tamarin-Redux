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

package flash.net
{

    /**
     * This interface controls the serialization of dynamic properties of dynamic objects.
     * You use this interface with the IDynamicPropertyWriter interface
     * and the <code>ObjectEncoding.dynamicPropertyWriter</code> property.
     *
     * @see IDynamicPropertyWriter
     * @see ObjectEncoding#dynamicPropertyWriter
     * @playerversion Flash 9
     * @langversion 3.0
     *
     *  @playerversion Lite 4
     */

    public interface IDynamicPropertyOutput
    {
        /**
         * Adds a dynamic property to the binary output of a serialized object.
         * When the object is subsequently read (using a method such as
         * <code>readObject</code>), it contains the new property.
         * You can use this method
         * to exclude properties of dynamic objects from serialization; to write values
         * to properties of dynamic objects; or to create new properties
         * for dynamic objects.
         *
         * @param name The name of the property. You can use this parameter either to specify
         *        the name of an existing property of the dynamic object or to create a
         *        new property.
         *
         * @param value The value to write to the specified property.
         *
         * @see IDynamicPropertyWriter
         * @see ObjectEncoding#dynamicPropertyWriter
         * @playerversion Flash 9
         * @langversion 3.0
         *
         *  @playerversion Lite 4
         */
        function writeDynamicProperty(name:String, value:*):void;
    }

}
