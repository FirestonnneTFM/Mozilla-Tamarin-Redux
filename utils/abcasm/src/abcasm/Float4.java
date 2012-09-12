/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
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
       x = y = z = w = Float.NaN;    
    }
    public Float4(Float x, Float y, Float z, Float w)
    {
        this.x = x; this.y = y; this.z = z; this.w = w;
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
        if(x.compareTo(o.x) != 0) return x.compareTo(o.x);
        if(y.compareTo(o.y) != 0) return y.compareTo(o.y);
        if(z.compareTo(o.z) != 0) return z.compareTo(o.z);
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

