/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import java.util.Vector;

class ScriptInfo
{
    Object init_id = new Integer(0);

    Traits traits = new Traits();
    
    void setInit(Object i)
    {
        init_id = i;
    }
    
    int getInitId()
    {
        if ( this.init_id instanceof Integer )
        {
            return (Integer)this.init_id;
        }
        else
            throw new IllegalArgumentException("Unknown function " + init_id.toString());
    }
    
    void addTrait(Trait t)
    {
        traits.add(t);
    }
    
    Traits getTraits()
    {
        return traits;
    }
}
