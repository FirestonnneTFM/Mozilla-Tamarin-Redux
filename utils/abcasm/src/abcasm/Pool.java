/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

/**
 * Abstract representation of an ABC pool,
 * which can be sorted according to some
 * criterion (e.g., most used elements to
 * lowest positions).
 *
 * @param <T>
 */
public class Pool<T extends Comparable>
{
    Map<T,Integer> refs = new TreeMap<T,Integer>();
    ArrayList<T> values = new ArrayList<T>();
    int countFrom;
    
    public Pool(int countFrom)
    {
        this.countFrom = countFrom;
    }
    
    public int add(T e)
    {
        if ( !refs.containsKey(e) )
        {
            values.add(e);
            refs.put(e, size());
        }

        return refs.get(e);
    }
    
    public ArrayList<T> getValues()
    {
        return values;
    }
    
    public int id(T e)
    {
        if ( !refs.containsKey(e))
            throw new IllegalArgumentException("Unknown pool item \"" + e.toString() + "\"");
        return refs.get(e);
    }
    
    public String toString()
    {
        return String.valueOf(refs);
    }
    
    public int size()
    {
        return countFrom + refs.size();
    }
}

