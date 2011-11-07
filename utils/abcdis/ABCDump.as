/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package
{
import avmplus.System
import avmplus.File
import avmplus.describeType;
import avmplus.FLASH10_FLAGS;

import flash.utils.ByteArray

import abc.Reader
import abc.DOTWriter
import abc.XMLWriter
import abc.AbcFormatWriter
import abc.AbcDumpWriter
import abc.AbcAsmWriter
import abc.Verifier
import abc.Types.ABCFile
import abc.AbcAPIWriter

public class ABCDump
{

    private function dumpABC(abcfile : ABCFile, abcFormatPrinter : IPrinter, abcDumpPrinter : IPrinter, dumpXML : Boolean, dumpDOT : Boolean, dumpABCASM : Boolean, dumpAPI : Boolean, dir : String, name : String) : void
    {
        Verifier.verify(abcfile)
        AbcFormatWriter.print(abcfile,  abcFormatPrinter)
        AbcDumpWriter.print(abcfile, abcDumpPrinter)
        if (dumpXML)
            XMLWriter.writeFile(abcfile,        dir + name + ".xml")
        if (dumpDOT)
            DOTWriter.writeFile(abcfile,       dir + name)
        if (dumpABCASM)
            AbcAsmWriter.writeFile(abcfile, dir + name + ".abs")
        if (dumpAPI)
            AbcAPIWriter.writeFile(abcfile, dir + name + ".api.txt")
    }

    public function ABCDump()
    {
        
    }
    
    public static function abcDump() : void
    {
        var dumper : ABCDump = new ABCDump();
        var cmdLine : CmdLine = CmdLine.parse(System.argv);

        var abcs:Array = Reader.readFile(cmdLine.inputFileName)

        var baseName : String = cmdLine.inputFileName.substring(cmdLine.inputFileName.lastIndexOf(pathSep));
        var abcFormatBytes : ByteArray = new ByteArray();
        var abcFormatPrinter : IPrinter = new ByteArrayPrinter(abcFormatBytes);
        var abcDumpBytes : ByteArray = new ByteArray();
        var abcDumpPrinter : IPrinter = new ByteArrayPrinter(abcDumpBytes)
        
        if (abcs.length == 1)
        {
            dumper.dumpABC(abcs[0], abcFormatPrinter, abcDumpPrinter, cmdLine.dumpXML, cmdLine.dumpDOT, cmdLine.dumpABCASM, cmdLine.dumpAPI, cmdLine.outputDirectory, baseName);
        }
        else
        {
            var i : uint = 0;
            for each ( var abcfile : ABCFile in abcs )
            {
                abcFormatPrinter.println("// abc " + " " + i + (abcfile.abcName != null ? " " + abcfile.abcName : ""));
                dumper.dumpABC(abcfile, abcFormatPrinter, abcDumpPrinter, cmdLine.dumpXML, cmdLine.dumpDOT, cmdLine.dumpABCASM, cmdLine.dumpAPI, cmdLine.outputDirectory, baseName + "-" + i);
                abcFormatPrinter.println("");
                abcFormatPrinter.println("");
                abcDumpPrinter.println("");
                abcDumpPrinter.println("");
                i++;
            }
        }
        File.writeByteArray(cmdLine.outputDirectory + baseName + ".dump", abcFormatBytes);
        File.writeByteArray(cmdLine.outputDirectory + baseName + ".txt", abcDumpBytes);
    }
}

}

const pathSep : String = "/";

class CmdLine
{
    public var inputFileName : String;
    public var outputDirectory : String;
    public var dumpXML : Boolean;
    public var dumpDOT : Boolean;
    public var dumpABCASM : Boolean;
    public var dumpAPI : Boolean;
    
    private static var usageStr : String = <x><![CDATA[
[-xml] [-dot] [-abcasm] [-api] inputFileName outputDirectory
]]></x>.text()[0]
    
    private static function usage(msg : String) : void
    {
        throw new Error(msg + "\n" + usageStr);
    }
    
    public function toString() : String
    {
        return [inputFileName, outputDirectory, dumpXML.toString(), dumpDOT.toString()].join(", ");
    }
    
    public static function parse(argv : Array) : CmdLine
    {
        var result : CmdLine = new CmdLine();
        var parsingOpts : Boolean = true;
        
        for each (var arg : String in argv) {
            if (parsingOpts) {
                if (arg.charAt(0) == "-") {
                    switch (arg)
                    {
                    case "-xml":
                        result.dumpXML = true;
                        break;
                    case "-dot":
                        result.dumpDOT = true;
                        break;
                    case "-abcasm":
                        result.dumpABCASM = true;
                        break;
                    case "-api":
                        result.dumpAPI = true;
                        break;
                    default:
                        usage("Invalid option:" + arg);
                    }
                    continue;
                }
            }
            parsingOpts = false;
            
            if (result.inputFileName == null) {
                result.inputFileName = arg;
            }
            else if (result.outputDirectory == null) {
                if (arg.charAt(arg.length - 1) != pathSep)
                    arg += pathSep;
                result.outputDirectory = arg;
            }
            else {
                usage("Too many arguments");
            }
        }
        
        if ((result.inputFileName == null) || (result.outputDirectory == null))
            usage("Too few arguments");
        return result;
    }
}

