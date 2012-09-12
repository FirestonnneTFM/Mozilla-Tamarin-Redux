/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import java.util.Vector;
import static abcasm.AbcConstants.*;

class Traits extends Vector<Trait>
{
    /**
     *  @see Serializable
     */
    private static final long serialVersionUID = -3691060424629191999L;
    private Integer explicitCount;

    public int getTraitCount()
    {
        if ( explicitCount != null )
            return explicitCount;
        else
            return size();
    }
    
    public Integer getSlotId(String slot_name)
    {
        for ( Trait t: this)
        {
            if ( TRAIT_Var == t.getKind() && ((Name)t.getAttr("name")).baseName.equals(slot_name) )
            {
                return (Integer)t.getAttr("slot_id");
            }
        }
        
        return null;
    }
}
