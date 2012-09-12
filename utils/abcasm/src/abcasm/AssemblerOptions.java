/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import java.util.Vector;

class AssemblerOptions
{
    boolean dumpIl = false;
    boolean verbose = false;
    boolean expandedDiagnostics = false;

    java.util.Vector<String> asmFile = new java.util.Vector<String>();
    
    AssemblerOptions(String[] args)
    {
        for ( String option: args)
        {
            if ( option.equalsIgnoreCase("-dump"))
                dumpIl = true;
            else if ( option.equalsIgnoreCase("-verbose"))
                verbose = true;
            else if ( option.equalsIgnoreCase("-debug_assembler"))
                expandedDiagnostics = true;
            else
                asmFile.add(option);
        }
    }
}
