/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2009
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
package abcasm;


/**
 * Helper class that holds a Float4 value, needed since Java 
 * doesn't have a builtin float4 type
 *
 */
public class Float4 implements Comparable
{
    public Float x,y,z,w;
    
    public Float4(){
       x=y=z=w=Float.NaN;    
    }
    public Float4(Float x, Float y, Float z, Float w)
    {
        this.x=x; this.y=y; this.z = z; this.w = w;
    }
    
    public String toString()
    {
        return x.toString()+","+y.toString()+","+z.toString()+","+w.toString();
    }

     public int compareTo(Object anotherF4) throws ClassCastException 
     {
        if (!(anotherF4 instanceof Float4))
          throw new ClassCastException("A Float4 object expected.");

        Float4 o = (Float4) anotherF4;
        if(x.compareTo(o.x)!=0) return x.compareTo(o.x);
        if(y.compareTo(o.y)!=0) return y.compareTo(o.y);
        if(z.compareTo(o.z)!=0) return z.compareTo(o.z);
        return w.compareTo(o.w);
      }    

     public boolean equals(Object anotherF4) 
     {
        if (!(anotherF4 instanceof Float4)) return false;
        return compareTo(anotherF4) == 0;
     }
     
     public int hashCode()
     {
         int result = Float.floatToIntBits(x);
         result = result * 37 + Float.floatToIntBits(y);
         result = result * 37 + Float.floatToIntBits(z);
         result = result * 37 + Float.floatToIntBits(w);
         return result;
     }

}

