/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import java.util.HashMap;

class Trait 
{
    int kind_byte;
    
    HashMap<String,Object> attrs = new HashMap<String,Object>();
    
    Trait(int kind)
    {
        this.kind_byte = kind;
    }

    void addAttr(String key, Object value)
    {
        if ( attrs.containsKey(key) )
        {
            throw new IllegalArgumentException("Trait attribute " + key + " cannot be specified twice." );
        }

        attrs.put(key, value);
    }

    void validate()
    {
        verifyContains("name", null);
    }

    public int getKind()
    {
        return kind_byte & 0x0F;
    }
    
    public void setAttr(String attr_name, Object attr_value)
    {
        attrs.put(attr_name, attr_value);
    }

    public boolean hasAttr(String attr_name)
    {
        return attrs.containsKey(attr_name);
    }

    public Object getAttr(String attr_name)
    {
        verifyContains(attr_name, null);
        return attrs.get(attr_name);
    }

    public int getIntAttr(String attr_name)
    {
        verifyContains(attr_name, Integer.class);
        return (Integer)attrs.get(attr_name);
    }
    
    public Name getNameAttr(String attr_name)
    {
        verifyContains(attr_name, Name.class);
        return (Name)attrs.get(attr_name);
    }
    
    void verifyContains(String attr_name, Class clazz)
    {
        if ( !attrs.containsKey(attr_name) )
            throw new IllegalArgumentException("Required attribute " + attr_name + " not found.");
        if ( ! ( null == clazz ||  attrs.get(attr_name).getClass().equals(clazz) ) )
        {
            throw new IllegalArgumentException("Attribute " + attr_name + " must be type " + clazz.getSimpleName() );
        }
    }
}
