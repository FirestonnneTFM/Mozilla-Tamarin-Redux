/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import java.util.Iterator;
import java.util.Vector;

public class Nsset implements Comparable, Iterable<Namespace>
{
    java.util.Vector<Namespace> namespaces = new java.util.Vector<Namespace>();
    
    public Nsset()
    {
    }

    public Nsset(Namespace single_ns)
    {
        namespaces.add(single_ns);
    }
    
    public Nsset(Vector<Namespace> nss) 
    {
        namespaces.addAll(nss);
    }

    public int length()
    {
        return namespaces.size();
    }
    public int compareTo(Object o)
    {
        Nsset other = (Nsset)o;
        
        int result = this.namespaces.size() - other.namespaces.size();
        
        for ( int i = 0; i < this.namespaces.size() && 0 == result; i++ )
            result = this.namespaces.elementAt(i).compareTo(other.namespaces.elementAt(i));
        
        return result;
    }

    public Iterator<Namespace> iterator()
    {
        return namespaces.iterator();
    }
    
    public String toString()
    {
        StringBuffer result = new StringBuffer();
        
        result.append('{');
        for ( int i = 0; i < namespaces.size(); i++ )
        {
            if ( i > 0 )
                result.append(',');
            result.append(namespaces.elementAt(i));
        }
        result.append('}');
        return result.toString();
    }
}

