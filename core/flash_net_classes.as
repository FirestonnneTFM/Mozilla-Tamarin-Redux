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
     * Preserves the class (type) of an object when the object is encoded in Action Message Format (AMF).
     * When you encode an object into AMF, this function saves the alias for its class, so that you can
     * recover the class when decoding the object.
     * If the encoding context did not register an alias for an object's class, the object
     * is encoded as an anonymous object. Similarly, if the decoding context does not have the same
     * alias registered, an anonymous object is created for the decoded data.
     *
     * <p>LocalConnection, ByteArray, SharedObject, NetConnection and NetStream are all examples
     * of classes that encode objects in AMF.</p>
     *
     * <p>The encoding and decoding contexts do not need to use the same class for an alias;
     * they can intentionally change classes, provided that the destination class contains all of the members
     * that the source class serializes.</p>
     *
     * @param aliasName The alias to use.
     * @param classObject The class associated with the given alias.
     *
     * @throws TypeError If either parameter is <code>null</code>.
     *
     * @playerversion Flash 9
     * @langversion 3.0
     * @includeExample examples\RegisterClassAliasExample.as -noswf
     * @see flash.net.ObjectEncoding ObjectEncoding class
     *
     *  @playerversion Lite 4
     */
    [native("Toplevel::registerClassAlias")]
    public native function registerClassAlias(aliasName:String, classObject:Class):void;


    /**
     * Looks up a class that previously had an alias registered through a call to the <code>registerClassAlias()</code>
     * method.
     * <p>This method does not interact with the <code>flash.utils.getDefinitionByName()</code>
     * method.</p>
     *
     * @param aliasName The alias to find.
     *
     * @return The class associated with the given alias. If not found, an exception will be thrown.
     *
     * @throws ReferenceError The alias was not registered.
     *
     * @playerversion Flash 9
     * @langversion 3.0
     * @see flash.net#registerClassAlias() registerClassAlias()
     * @internal includeExample examples\GetClassByAliasExample.as -noswf
     *
     *  @playerversion Lite 4
     */
    [native("Toplevel::getClassByAlias")]
    public native function getClassByAlias(aliasName:String):Class;
}

