/* -*- Mode: Java; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package abcasm;

import org.antlr.runtime.*;


import java.io.FileInputStream;

public class Main
{

    public static void main(String[] argv)
        throws Exception
    {
        AssemblerOptions options = new AssemblerOptions(argv);
        
        for ( String asmFile: options.asmFile )
        {
            assemble(asmFile, options);
        }
    }

    public static void assemble(String asmFile, AssemblerOptions options)
        throws Exception
    {
        if ( options.verbose )
            System.out.println("assembling " + asmFile );
        
        abcasmLexer lexer = new abcasmLexer(new ANTLRFileStream(asmFile));
        
        CommonTokenStream tokens = new CommonTokenStream();
        tokens.setTokenSource(lexer);
        abcasmParser parser = new abcasmParser(tokens);

        AssemblerCore core = new AssemblerCore(options);
        parser.asmCore = core;

        try
        {
            parser.translation_unit();
        }
        catch ( Throwable parser_fatal )
        {
            if ( options.expandedDiagnostics )
                parser_fatal.printStackTrace();
            core.syntaxErrors.add(parser_fatal.getMessage());
        }

        if ( core.syntaxErrors.size() > 0 )
        {
            System.err.println("Unable to assemble " + asmFile + " due to syntax errors:");
            for ( String s: core.syntaxErrors )
            {
                System.err.println(s);
            }

            return;
        }
        
        if ( options.dumpIl )
            core.dump(System.out);
        
        
        //  Parsing successful, do the results make sense?
        core.semanticAnalysis();
        
        if ( core.semanticErrors.size() > 0 )
        {
            System.err.println("Unable to assemble " + asmFile + " due to:");

            for ( String s: core.semanticErrors )
            {
                System.err.println(s);
            }

            return;
        }
        
        //  Emit the bytecode.
        try
        {
            String binary_file_name;
            int last_dot = asmFile.lastIndexOf(".");
            
            if ( last_dot == (asmFile.length() - 4) && asmFile.substring(last_dot).equalsIgnoreCase(".abs") )
                binary_file_name = asmFile.substring(0, last_dot) + ".abc";
            else
                binary_file_name = asmFile + ".abc";
            
            byte[] abc_binary = new AbcEmitter(core).emit();
            java.io.OutputStream output = new java.io.FileOutputStream(binary_file_name);
            output.write(abc_binary);
        }
        catch ( Exception ex )
        {
            System.err.println("Unable to emit due to: ");
            ex.printStackTrace();
            System.exit(1);
        }
    }
}
