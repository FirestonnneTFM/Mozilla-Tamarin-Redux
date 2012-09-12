/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import static abcasm.AbcConstants.*;


class Name implements java.lang.Comparable
{
    int kind;
    String baseName;   // May be "" but is never null
    Nsset qualifiers;  // May be null

    // Always a QName, even if 'qualifiers' is represented as a set
    Name(String unqualifiedName)
    {
        baseName = unqualifiedName;
        kind = CONSTANT_Qname;
        qualifiers = new Nsset( new Namespace(CONSTANT_PackageNs));
    }

    // Always a QName, even if 'qualifiers' is represented as a set
    Name(String ns, String unqualifiedName)
    {
        baseName = unqualifiedName;
        kind = CONSTANT_Qname;
        qualifiers = new Nsset( new Namespace(CONSTANT_Namespace, ns));
    }
    
    // All other cases, pass null for missing parts
    Name(Nsset multiname_qualifiers, String _baseName)
    {
        baseName = (_baseName == null) ? "" : _baseName;
        qualifiers = multiname_qualifiers == null ? new Nsset() : multiname_qualifiers;
        if (multiname_qualifiers == null)
        {
            if (_baseName == null)
                kind = CONSTANT_RTQnameL;
            else
                kind = CONSTANT_RTQname;
        }
        else
        {
            if (_baseName == null)
                kind = CONSTANT_MultinameL;
            else
                kind = CONSTANT_Multiname;
        }
    }

    public String toString()
    {
        StringBuffer result = new StringBuffer();

        if ( qualifiers != null )
        {
            result.append(qualifiers.toString());
        }
        result.append("::");
        result.append(baseName);

        return result.toString();
    }

    public int compareTo(Object o)
    {
        if ( !(o instanceof Name ))
        {
            return -1;
        }

        int result = 0;

        Name other = (Name)o;

        if ( this.qualifiers != null )
        {
            if ( other.qualifiers != null )
            {
                result =  this.qualifiers.compareTo(other.qualifiers);
            }
            else
            {
                result = 1;
            }
        }
        else if ( other.qualifiers != null )
        {
            result = -1;
        }

        if ( 0 == result )
            result = baseName.compareTo(other.baseName);

        return result;
    }

    Namespace getSingleQualifier()
    {
        assert(this.qualifiers.namespaces.size() == 1);
        return this.qualifiers.namespaces.elementAt(0);
    }
}
