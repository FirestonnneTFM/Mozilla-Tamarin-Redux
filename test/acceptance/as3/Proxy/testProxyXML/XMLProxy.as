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

package{
    import flash.utils.*;
    import avmplus.*;
    
    use namespace flash_proxy;
    
    public class XMLProxy extends Proxy
    {
        protected var target:*;
        protected var myXML:XML;
    
        
        public function XMLProxy(obj:*)
        {
            target = obj;
            myXML = obj;
        }
        
        override flash_proxy function getProperty(variableName:*):*
        {
            //trace("getProperty with " + variableName);
            
            var isAttr = "";
    
            if(isAttribute(variableName))
            {
                //trace(variableName + " is an attribute");
                isAttr = "isAttribute=true";
                if(myXML..@[variableName] != undefined)
                {
                    return isAttr + " -- " + myXML..@[variableName];
                }
            }
            else
            {
                //trace(variableName + " is not an attribute");
                isAttr = "isAttribute=false";
                if(myXML.descendants(variableName) != undefined)
                {
                return isAttr + " -- " + myXML.descendants(variableName).toXMLString();
                }
            }
            
            // add 'isAttribute=true/false' in front of the property so we can make sure isAttribute worked correctly
            if(target[variableName] != undefined)
            {
                return isAttr + " -- " + target[variableName];
            }
            else
            {
                return isAttr + " -- " + variableName + " does not exist";
            }
        }
    
        
        
        override flash_proxy function setProperty(name:*, value:*):void {
            trace('setProperty('+name+', '+value+')');
            target[name] = value;
        }
        
        override flash_proxy function deleteProperty(variableName:*):Boolean {
            trace("calling delete " + variableName);
            //delete myXML.@[variableName] ;
            //delete myXML.@b;
            //delete myXML..@[variableName];
            if(isAttribute(variableName))
            {
                trace(variableName + " is an attribute -- attempting to delete");
            }
            else
            {
                trace(variableName + " is NOT an attribute -- attempting to delete");
            }
            var deleteStatus:Boolean = delete myXML[variableName];
            return deleteStatus;
            //delete myXML[variableName];
        };
        
        override flash_proxy function callProperty(name:*, ...rest):* {
            //trace("callProperty with name " + name + " and argument " + rest[0]);
    
            trace("callProperty with name " + name );//+ " and argument " + rest[0]);
    
            if(rest != undefined)
            {
                trace("and argument " + rest[0]);
            }
    
            if(name == "attributes")
            {
                // handle attributes
                return myXML..@[rest[0]];
            }
            else if (name == "descendants")
            {
                // handle descendants
    
                return myXML.descendants(rest[0]);
            }
            
            else if(name == "toString")
            {
                return myXML.toString();
            }
    
            else if(name == "toXMLString")
            {
                return myXML.toXMLString();
            }
    
            else
            {
                //return "Error in callProperty with name " + name + " and argument " + rest[0];
                return "Error in callProperty with name " + name;
            }
        };
        
        override flash_proxy function getDescendants (name:*):*
        {
            trace("getDescendants called with name " + name);
            //return target[name];
            
            if(isAttribute(name))
            {
                trace(name + " is an attribute");
            }
            else
            {
                trace(name + " is not an attribute");
            }
            
            if(myXML.descendants(name) == undefined)
            {
                trace("descendants is undefined for " + name);
                return "descendants is undefined for " + name;
            }
            else if (myXML.descendants(name) == "")
            {
                trace("empty string");
                return "empty string";
            }
            else
            {
                trace("getting descendants for " + name + " " + myXML.descendants(name));
                return myXML.descendants(name);
            }
            
        }
    }
}