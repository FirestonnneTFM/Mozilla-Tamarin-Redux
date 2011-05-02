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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

// This class overrides all the basic functionality of Proxy
package{
    import flash.utils.*;
    import avmplus.*;
    
    public class ProxyAdvanced extends Proxy
    {
        private var target:*;
    
        public function ProxyAdvanced(obj:*)
        {
            target = obj;
        }
        
        override flash_proxy function getProperty(name:*):* 
        {
            if (target[name])
            {
                return target[name]; 
            }
            else
            {
                return "property not found";
            }
        }
        
        override flash_proxy function setProperty(name:*, value:*):void
        {
            target[name] = value;
        }
        override flash_proxy function deleteProperty(name:*):Boolean 
        {
            delete target[name] ;
        };
    
        override flash_proxy function hasProperty(name:*):Boolean
        {
            trace("hasProperty called");
            //return target.hasOwnProperty(name);
            return true;
        }
        
        // Handle all functions with more than 1 argument
        public function myFunction(name:*):String
        {
            return ("Method " + name + " was called");
        }
        
        override flash_proxy function callProperty(name:*, ...rest):* 
        {
            // test that if a function has more than 2 arguments, just call the default function myFunction
            if(rest[2] != undefined)
            {
                //trace("more than 2 args");
                return this.myFunction(name);
            }
            // test that a call to a function with 2 arguments can be redirected properly
            else if(rest[1] != undefined)
            {
                //trace("2 args");
                return target[name](rest[0], rest[1]);
            }
            // test that a call to a function with 1 argument can be redirected properly
            else if(rest[0] != undefined)
            {
                //trace("1 arg");
                return target[name](rest[0]);
            }
            // test that a call to a function with 0 arguments can be redirected properly
            else
            {
                //trace("0 args");
                return target[name]();
            }
        }
        
        
        override flash_proxy function getDescendants (name:*):*
        {
            trace("getDescendants called for name " + name);
            return target.descendents(name);
            //return "Hello, Michael Morris!";
        }
        /* Not supported right now
        override flash_proxy function delDescendants (name:*):void {
            delete target.descendents(name)
        }
        */
        override flash_proxy function isAttribute(name:*):Boolean
        {
            trace("isAttribute called for name " + name);
            //return target.isAttribute(name)
            return true;
        }
    
    }

}