/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

class ExceptionInfo
{
    Label   from;
    Label   to;
    Label   target;
    
    Integer exc_type;
    Integer name_id;
    
    void validateSemantics()
    {
        if ( null == from )
            throw new IllegalArgumentException(".exception must specify from label");
        if ( null == to )
            throw new IllegalArgumentException(".exception must specify to label");
        if ( null == target )
            throw new IllegalArgumentException(".exception must specify target label");
        
        //  Default the entries that have useful defaults.
        if ( null == exc_type )
            exc_type = new Integer(0);
        if ( null == name_id )
            name_id = new Integer(0);
    }
}
