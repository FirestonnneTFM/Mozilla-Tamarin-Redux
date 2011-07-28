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

import flash.errors.IllegalOperationError;

public namespace flash_proxy = "http://www.adobe.com/2006/actionscript/flash/proxy";

//
// Proxy
//

[native(cls="ProxyClass", gc="exact", instance="ProxyObject", methods="auto")]
public class Proxy
{
    flash_proxy function getProperty(name:*):*
    {
        Error.throwError(IllegalOperationError, 2088  /* kProxyGetPropertyError */);
        return null; // compiler doesn't realize this is unreachable (strict mode)
    }

    flash_proxy function setProperty(name:*, value:*):void
    {
        Error.throwError(IllegalOperationError, 2089  /* kProxySetPropertyError */);
    }

    flash_proxy function callProperty(name:*, ...rest):*
    {
        Error.throwError(IllegalOperationError, 2090 /* kProxyCallPropertyError */);
        return null; // unreachable
    }

    flash_proxy function hasProperty(name:*):Boolean
    {
        Error.throwError(IllegalOperationError, 2091 /* kProxyHasPropertyError */);
        return null; // unreachable
    }

    flash_proxy function deleteProperty(name:*):Boolean
    {
        Error.throwError(IllegalOperationError, 2092 /* kProxyDeletePropertyError */);
        return null; // unreachable
    }
    
    flash_proxy function getDescendants(name:*):*
    {
        Error.throwError(IllegalOperationError, 2093 /* kProxyGetDescendantsError */);
        return null; // unreachable
    }

    flash_proxy function nextNameIndex(index:int):int
    {
        Error.throwError(IllegalOperationError, 2105 /* kProxyNextNameIndexError */);
        return null; // unreachable
    }

    flash_proxy function nextName(index:int):String
    {
        Error.throwError(IllegalOperationError, 2106 /* kProxyNextNameError */);
        return null; // unreachable
    }

    flash_proxy function nextValue(index:int):*
    {
        Error.throwError(IllegalOperationError, 2107 /* kProxyNextValueError */);
        return null; // unreachable
    }

    flash_proxy native function isAttribute(name:*):Boolean;
}

}
