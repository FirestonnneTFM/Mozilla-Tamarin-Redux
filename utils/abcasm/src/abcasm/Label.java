/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

/**
 *  This simple Label class wraps
 *  string literal labels in a typed class.
 */
public class Label implements Comparable
{
    private String labelText;

    Label(String label_text)
    {
        this.labelText = label_text;
    }

    public int compareTo(Object o)
    {
        return ((Label)o).labelText.compareTo(this.labelText);
    }
    
    public String toString()
    {
        return labelText;
    }
}
