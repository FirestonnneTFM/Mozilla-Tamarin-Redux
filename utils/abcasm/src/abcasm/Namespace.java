/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

public class Namespace implements Comparable
{
    int kind;
    String name;
    
    Namespace(int kind)
    {
        this(kind, new String());
    }
    
    Namespace(int kind, String name)
    {
        this.kind = kind;
        this.name = name;
    }
    
    public int compareTo(Object o)
    {
        Namespace other = (Namespace)o;
        
        int result = kind - other.kind;
        
        if ( 0 == result )
            result = name.compareTo(other.name);
        
        return result;
    }
    
    public String toString()
    {
        if ( name.length() > 0 )
            return name;
        else
            return "0x" + Integer.toHexString(kind);
    }
}
