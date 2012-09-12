/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package abcasm;

class SymbolicReference
{
    public static final int function_id = 1;
    public static final int slot_id = 2;

    int kind;
    String symbolicReference;

    SymbolicReference(int kind, String reference)
    {
        this.kind = kind;
        this.symbolicReference = reference;
    }
    
    public String toString()
    {
        StringBuffer result = new StringBuffer();

        if ( function_id == kind )
            result.append(".function_id(");
        else if ( slot_id == kind )
            result.append(".slot_id(");
        else
            result.append("symref(");
        result.append(symbolicReference);
        result.append(")");
        return result.toString();
    }
}
