/* -*- indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

// exactgc.as generates exact tracing code from annotated classes.  It
// is usually run by builtin-tracers.py, shell_toplevel-tracers.py,
// and similar scripts, and occasionally cooperates with nativegen.py.
//
// The <a href="doc/mmgc/exactgc-cookbook.html">cookbook</a> provides a gentle
// introduction to annotations; most people need look no further.
//
// The <a href="doc/mmgc/exactgc-manual.html">manual</a> provides a complete
// reference manual for exact GC and describes every facility provided
// by exactgc.as and more.
//
//
// Usage & options.
//
// exactgc.as extracts native attributes from ".as" and ".h" files and
// generates C++ code.  Little is assumed about the structure of the
// files; indeed the script looks only for annotations, never for C++
// or AS3 phrases, and you can blindly feed a lot of files to it and
// expect the right thing to happen.
//
// Typical usage:
//
//    avm exactgc.abc -- -b avmplus-as3-gc.h -n avmplus-cpp-gc.h -i avmplus-gc-interlock.h *.h *.as
//    
// Options:
//
//    filename       A file to process
//    @filename      A file from which to read more file names
//    -x filename    A file to process (useful if the filename starts with '@' or '-')
//    -n filename    Emit tracers for GC_CPP_EXACT ("natives") to this file
//    -b filename    Emit tracers for GC_AS3_EXACT ("builtins") to this file
//    -i filename    Emit interlock definitons to this file
//    -ns namespace  The C++ namespace to wrap around the output, default global
//
//
// Performance notes.
//
// The script has been tuned quite a bit, and there's a built-in profiling option
// to help us tune more (search for 'var profiling' below).  Even so, about
// 90% of the time is still spent in reading input and extracting annotations, so
// obvious things to do if further performance improvements are needed would be:
//
//   - cache intermediate data (eg, save extracted lines + file's path and mtime)
//   - don't split the file into individual lines (splitting takes some time).
//
// The design is currently line-based because I would like to expand it later to
// include various kinds of error checking that goes hand-in-hand with SafeGC, eg,
// if GCMember appears on a line then there should be a GC annotation too.  So
// it would be good to try caching first.

import avmplus.*;

// For [native] annotations on AS3 class definitions that have "gc",
// "clsgc", or "instancegc" annotations.
class AS3Class
{
    function AS3Class(ns, cls) {
        // This is for dealing with the "::avmshell::" prefix in some native annotations,
        // though there is probably a better way.
        var s = "::" + ns + "::";
        if (cls.indexOf(s) == 0)
            cls = cls.substring(s.length);
        this.cls = cls;
    }

    public function toString() { return printProps(this, ["cls"]) }

    const cls;
}


// For GC_AS3_EXACT and GC_CPP_EXACT annotations on C++ class
// definitions, also for the _WITH_HOOK variants.  Note
// _WITH_HOOK_{IF,IFDEF,IFNDEF} means we can have both hooks
// and conditional compilation.

class GCClass
{
    function GCClass(tag, attr) {
        cls = getAttr(attr, 0);
        base = getAttr(attr, 1);
        hook = tag.match("_WITH_HOOK") != null;
        ifdef = tag.match("_IFDEF") != null ? getAttr(attr,2) : false;
        ifndef = tag.match("_IFNDEF") != null ? getAttr(attr,2) : false;
        if_ = !ifdef && !ifndef && tag.match("_IF") != null ? getAttr(attr,2) : false;
    }

    public function toString() { return printProps(this, ["cls","base","hook","ifdef"]) }

    public function fullName() { return fullClassPrefix + cls; }

    const cls;
    const base;
    const hook;
    const ifdef;
    const ifndef;
    const if_;

    var fullClassPrefix=""; // for nested classes
    var out = new Printer(1);
    var next = null;
    var fieldList = [];              // sorted by property name
    var fieldMap = {};
    var variable_length_field = null;  // does not appear in the 'fields' list
    var probablyLarge = false;
    var hint = null;
}

class GCCppExact extends GCClass { function GCCppExact(tag,attr) { super(tag,attr) } }
class GCAS3Exact extends GCClass { function GCAS3Exact(tag,attr) { super(tag,attr) } }


// For GC_DATA_BEGIN and GC_DATA_END annotations in C++ classes.
class GCDataSection
{
    function GCDataSection(tag, attr) {
        cls = getAttr(attr, 0);
    }

    public function toString() { return printProps(this, ["cls"]) }

    const cls;
}

class GCDataBegin extends GCDataSection { function GCDataBegin(tag, attr) { super(tag,attr) } }
class GCDataEnd extends GCDataSection { function GCDataEnd(tag, attr) { super(tag,attr) } }
class GCNoData extends GCDataSection { function GCNoData(tag, attr) { super(tag,attr) } }

// For the various field annotations in C++ classes.
//
// The cls attribute is implicitly present in the C++ source code and
// is inserted at the beginning of the attribute array by the code
// that constructs GCField instances.
//
// Any condition on the field is considered part of the field's name,
// to support typical cases like these:
//
// #ifdef BLAH
//   Bletch* GC_POINTER_IFDEF(p, BLAH)
// #else
//   Blotch* GC_POINTER_IFNDEF(p, BLAH)
// #endif

class GCField 
{
    function GCField(tag, attr) {
        cls = getAttr(attr, 0);
        name = getAttr(attr, 1);
        ifdef = tag.match("_IFDEF") != null ? getAttr(attr,2) : false;
        ifndef = tag.match("_IFNDEF") != null ? getAttr(attr,2) : false;
        if_ = !ifdef && !ifndef && tag.match("_IF") != null ? getAttr(attr,2) : false;
    }

    public function toString() { return printProps(this, ["cls","name","ifdef", "if_"]) }

    const cls;
    const name;
    const ifdef;
    const ifndef;
    const if_;
}

class GCPointer extends GCField { function GCPointer(tag, attr) { super(tag, attr) } }
class GCAtom extends GCField { function GCAtom(tag, attr) { super(tag, attr) } }
class GCStructure extends GCField { function GCStructure(tag, attr) { super(tag, attr) } }
class GCConservative extends GCField { function GCConservative(tag, attr) { super(tag, attr) } }

class GCPointers extends GCField
{
    function GCPointers(tag, attr) {
        splitFieldAndSize(attr, 1);
        super(tag,attr);
        declCount = getAttr(attr, 2);
        count = getAttr(attr, 3);
        hint = tag.match("_SMALL") != null ? "small" : null;
    }

    override public function toString() { return printProps(this, ["cls","name","ifdef","hint"]) }

    const declCount;
    const count;
    const hint;
}

class GCAtoms extends GCField
{
    function GCAtoms(tag, attr) {
        splitFieldAndSize(attr, 1);
        super(tag,attr);
        declCount = getAttr(attr, 2);
        count = getAttr(attr, 3);
        hint = tag.match("_SMALL") != null ? "small" : null;
    }

    override public function toString() { return printProps(this, ["cls","name","ifdef","hint"]) }

    const declCount;
    const count;
    const hint;
}

class GCStructures extends GCField
{
    function GCStructures(tag, attr) {
        splitFieldAndSize(attr, 1);
        super(tag,attr);
        declCount = getAttr(attr, 2);
        count = getAttr(attr, 3);
        hint = tag.match("_SMALL") != null ? "small" : null;
    }

    override public function toString() { return printProps(this, ["cls","name","ifdef","hint"]) }

    const declCount;
    const count;
    const hint;
}

class Printer
{
    function Printer(_indent=0) {
        for ( var i=0 ; i < _indent ; i++ )
            IN();
    }

    function IN() {
        indent+=4;
        if (indent > indentString.length)
            indentString += "    ";
        return this;
    }

    function OUT() {
        indent-=4;
        return this;
    }

    function PR(s) {
        if (s == null)
            return;
        if (s.charAt(0) != "#")
            output += indentString.substring(0,indent);
        while (s.length > 0 && s.charAt(s.length-1) == "\n")
            s = s.substring(0,s.length-1);
        output += s;
        output += "\n";
        return this;
    }

    function DO(f) {
        f(this);
        return this;
    }

    function NL() {
        return PR("");
    }

    function get() {
        return output;
    }

    var indent = 0;
    var indentString = "";
    var output = "";
}

const constructors =
{ "GC_CPP_EXACT":           GCCppExact,
  "GC_CPP_EXACT_IFDEF":     GCCppExact,
  "GC_CPP_EXACT_WITH_HOOK": GCCppExact,
  "GC_CPP_EXACT_WITH_HOOK_IFDEF": GCCppExact,
  "GC_CPP_EXACT_WITH_HOOK_IFNDEF": GCCppExact,
  "GC_CPP_EXACT_WITH_HOOK_IF": GCCppExact,
  "GC_AS3_EXACT":           GCAS3Exact,
  "GC_AS3_EXACT_IFDEF":     GCAS3Exact,
  "GC_AS3_EXACT_WITH_HOOK": GCAS3Exact,
  "GC_AS3_EXACT_WITH_HOOK_IFDEF": GCAS3Exact,
  "GC_AS3_EXACT_WITH_HOOK_IFNDEF": GCAS3Exact,
  "GC_AS3_EXACT_WITH_HOOK_IF": GCAS3Exact,
  "GC_DATA_BEGIN":          GCDataBegin,
  "GC_DATA_END":            GCDataEnd,
  "GC_NO_DATA":             GCNoData,
  "GC_ATOM":                GCAtom,
  "GC_ATOM_IF":             GCAtom,
  "GC_ATOM_IFDEF":          GCAtom,
  "GC_ATOM_IFNDEF":         GCAtom,
  "GC_POINTER":             GCPointer,
  "GC_POINTER_IF":          GCPointer,
  "GC_POINTER_IFDEF":       GCPointer,
  "GC_POINTER_IFNDEF":      GCPointer,
  "GC_CONSERVATIVE":        GCConservative,
  "GC_CONSERVATIVE_IF":     GCConservative,
  "GC_CONSERVATIVE_IFDEF":  GCConservative,
  "GC_CONSERVATIVE_IFNDEF": GCConservative,
  "GC_STRUCTURE":           GCStructure,
  "GC_STRUCTURE_IF":        GCStructure, 
  "GC_STRUCTURE_IFDEF":     GCStructure,
  "GC_STRUCTURE_IFNDEF":    GCStructure,
  "GC_ATOMS":               GCAtoms,
  "GC_ATOMS_SMALL":         GCAtoms,
  "GC_POINTERS":            GCPointers,
  "GC_POINTERS_SMALL":      GCPointers,
  "GC_STRUCTURES":          GCStructures,
  "GC_STRUCTURES_SMALL":    GCStructures
};

// Configuration etc
var debug = false;               // print useful debugging info
var profiling = false;           // profile at a function level for selected functions
var errorContext = "top level";  // for error messages, updated as we go
const largeObjectCutoff = 2000;  // more arbitrary than not, "close" to large object limit in MMgc

// Options
var builtinOutputFile = null;         // null == don't output, otherwise file name
var nativeOutputFile = null;          // null == don't output, otherwise file name
var interlockOutputFile = null;       // null == don't output (and don't do interlock checking), otherwise file name
var cppNamespace = "";                // wrap this namespace around the emitted code if not empty string

// Used during parsing and some initial processing
var specs = [];                // intermediate list of all metadata during parsing and field/class collection

// Created during processing
var cppClassList = [];         // all C++ classes ordered by class name
var as3ClassList = [];         // all AS3 classes ordered by class name
var cppClassMap = {};          // maps C++ class name to GCClass
var as3ClassMap = {};          // maps AS3 class name to GCClass

// Occasionally useful during debugging to print the attribute maps
Object.prototype.toString = 
function() { 
    var s=[];
    for ( var i in this ) 
        if (this.hasOwnProperty(i))
            s.push(i + ": " + this[i]); 
    return "{" + s.join(", ") + "}";
};

Array.prototype.toString = 
function() {
    return "[" + this.join(",") + "]";
};

function printProps(obj, attrs) {
    var s = [];
    for ( var i=0 ; i < attrs.length ; i++ )
        s.push(attrs[i] + ": " + obj[attrs[i]]);
    return "{" + s.join(", ") + "}";
}

const LICENSE = 
    ("/* ***** BEGIN LICENSE BLOCK *****\n" + 
     " * Version: MPL 1.1/GPL 2.0/LGPL 2.1\n" +
     " *\n" +
     " * The contents of this file are subject to the Mozilla Public License Version\n" +
     " * 1.1 (the \"License\"); you may not use this file except in compliance with\n" +
     " * the License. You may obtain a copy of the License at\n" +
     " * http://www.mozilla.org/MPL/\n" +
     " *\n" +
     " * Software distributed under the License is distributed on an \"AS IS\" basis,\n" +
     " * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License\n" +
     " * for the specific language governing rights and limitations under the\n" +
     " * License.\n" +
     " *\n" +
     " * The Original Code is [Open Source Virtual Machine.].\n" +
     " *\n" +
     " * The Initial Developer of the Original Code is\n" +
     " * Adobe System Incorporated.\n" +
     " * Portions created by the Initial Developer are Copyright (C) 2010\n" +
     " * the Initial Developer. All Rights Reserved.\n" +
     " *\n" +
     " * Contributor(s):\n" +
     " *   Adobe AS3 Team\n" +
     " *\n" +
     " * Alternatively, the contents of this file may be used under the terms of\n" +
     " * either the GNU General Public License Version 2 or later (the \"GPL\"), or\n" +
     " * the GNU Lesser General Public License Version 2.1 or later (the \"LGPL\"),\n" +
     " * in which case the provisions of the GPL or the LGPL are applicable instead\n" +
     " * of those above. If you wish to allow use of your version of this file only\n" +
     " * under the terms of either the GPL or the LGPL, and not to allow others to\n" +
     " * use your version of this file under the terms of the MPL, indicate your\n" +
     " * decision by deleting the provisions above and replace them with the notice\n" +
     " * and other provisions required by the GPL or the LGPL. If you do not delete\n" +
     " * the provisions above, a recipient may use your version of this file under\n" +
     " * the terms of any one of the MPL, the GPL or the LGPL.\n" +
     " *\n" +
     " * ***** END LICENSE BLOCK ***** */\n");

// Read an attribute with range checking from the attribute array
function getAttr(attr, n)
{
    if (n >= attr.length)
        fail("Out-of-range attribute reference: " + attr + " " + n);
    return attr[n];
}

// attr[n] has text of the form "<something1>[<something2>]" with no embedded commas.
// Break them apart, and leave <something1> in position n and insert <something2> in
// position n+1.

function splitFieldAndSize(attr, n)
{
    if (n >= attr.length)
        fail("Out-of-range attribute reference: " + attr + " " + n);
    var v = attr[n];
    var result = (/^\s*([^\]]*)\s*\[([^\]]*)\]\s*$/).exec(v);
    if (result == null || result.length != 3)
        fail("Incorrect format for array field, expected name[size]: " + n);
    for ( var k=attr.length ; k > n+1 ; k-- )
        attr[k] = attr[k-1];
    attr[n] = result[1];
    attr[n+1] = result[2];
}

// Fail with an error message, never return
function fail(s) 
{
    throw new Error(errorContext + ": " + s);
}

// Compare two strings and return -1, 0, or 1
function strcmp(a,b)
{
    if (a < b) return -1;
    if (b < a) return 1;
    return 0;
}

// The following function is about 20x faster than the obvious one-liner
//    return File.read(filename).split(/\r\n|\r|\n/);
//
// Using single regular expressions in place of the disjunction gave us
// a factor of five; switching to strings for the splitting another
// factor of four.  (Reorganizing the code further, to use knowledge
// of the absence of \r to avoid scanning for \r\n, say, has yielded 
// nothing.)

function readLines(filename) {
    var text = File.read(filename);
    if (text.indexOf("\r\n") != -1)
        return text.split("\r\n");

    if (text.indexOf("\r") != -1)
        return text.split("\r");

    return text.split("\n");
}

// Look for and record any options, return array of file names.  Skip
// files named 'GC.h' because MMgc/GC.h includes the macros for the
// annotations and cannot be processed.
function processOptionsAndFindFiles(args)
{
    var files = [];

    errorContext = "Processing options";
    processArgs(args);
    return files;

    function processArgs(args) {
        var i=0;
        var limit=args.length;

        function strip(s) {
            var result = (/^\s*(.*)\s*$/).exec(s);
            if (result == null) // shouldn't happen
                return s;
            return result[1];
        }

        function getArg(opt) {
            if (i == limit)
                fail("Missing argument for " + opt);
            return args[i++];
        }

        while (i < limit) {
            var s = args[i++];
            if (s == "-b") 
                builtinOutputFile = getArg(s);
            else if (s == "-n")
                nativeOutputFile = getArg(s);
            else if (s == "-i")
                interlockOutputFile = getArg(s);
            else if (s == "-ns") 
                cppNamespace = getArg(s);
            else if (s == "-x")
                files.push(getArg(s));
            else if (s.match(/GC\.h$/))
                ;
            else if (s.charAt(0) == "@") // indirection file
                files.push.apply(files, readLines(s.substring(1)).map(strip));
            else
                files.push(s);
        }
    }
}

// Read files, accumulate all metadata in order in 'specs'.
//
// Syntactic side conditions:
//
//   GC_DATA_BEGIN must follow a GC class spec with the same name.
//   GC_DATA_END pops both stacks, so there can only be one data
//   section per class.
//
//   At the end of a file, both stacks must be empty.

function readFiles(files)
{
    // For profiling
    var readingTime = 0;
    var processingTime = 0;
    var splittingTime = 0;

    var cppClassStack = [];       // tracks GC_CPP_EXACT, etc
    var cppDataStack = [];        // tracks GC_DATA_BEGIN / GC_DATA_END

    // TODO: factor regular expressions to avoid duplication?

    const attrStringRegex:RegExp = /^\s*\"([^\"]*)\"\s*$/;
    const attrMiscRegex:RegExp =   /^\s*((?:<\s+|\s+>|[a-zA-Z0-9_:<>])+)\s*$/;
    const attrNumberRegex:RegExp = /^\s*([0-9]+(?:\.[0-9]+)?)\s*$/;
    const attrArraydefRegex:RegExp = /^\s*([a-zA-Z0-9_]+\[[^\]]*\])\s*$/;

    function parseAttrValue(s) {
        var result;
        if ((result = attrStringRegex.exec(s)) != null ||
            (result = attrMiscRegex.exec(s)) != null ||
            (result = attrNumberRegex.exec(s)) != null ||
            (result = attrArraydefRegex.exec(s)) != null) {
            return result[1];
        }
        else
            fail("Bogus name-value pair: " + s);
    }

    // We can't simply split by "," here because the value can
    // contain a comma, for example, in "count" attributes the
    // expression frequently uses offsetof(a,b).

    const spacesStartRegex:RegExp =      /^(\s+)/;
    const spacesEndRegex:RegExp =        /(\s+)$/;
    const commaSpacesStartRegex:RegExp = /^(,\s*)/;
    const nameValuePairRegex:RegExp =    /^([a-zA-Z0-9_]+)\s*=\s*(\"[^\"]*\"|true|false)/;
    const valueRegex:RegExp =            /^\"[^\"]*\"|[a-zA-Z0-9_]+\[[^\]]*\]|(?:[0-9]+(?:\.[0-9]+)?)|(?:<\s+|\s+>|[a-zA-Z0-9_:<>])+/;

    function splitAttrs(s, paren=null) {
        var then = new Date();
        var xs = [];
        var result;
        for (;;) {
            // strip leading and trailing spaces
            if ((result = spacesStartRegex.exec(s)) != null)
                s = s.substring(result[1].length);
            if ((result = spacesEndRegex.exec(s)) != null)
                s = s.substring(0,s.length-result[1].length);

            if (paren != null) {
                if (s == "")
                    fail("Missing closing parenthesis: '" + paren + "'");
                if (s.charAt(0) == paren)
                    break;
            }
            else if (s == "")
                break;

            // strip leading comma and any spaces following it
            if (xs.length > 0) {
                if ((result = commaSpacesStartRegex.exec(s)) == null)
                    fail("Incorrect attribute string: missing comma in " + s);
                s = s.substring(result[1].length);
            }
            if (s == "")
                break;
            // simple-identifier=(string|boolean), string, number, qualified-identifier
            if ((result = nameValuePairRegex.exec(s)) != null)
                xs.push([result[1], parseAttrValue(result[2])]);
            else if ((result = valueRegex.exec(s)) != null)
                xs.push(parseAttrValue(result[0]));
            else 
                fail("Incorrect attribute string: bad value or name/value pair: " + s);
            s = s.substring(result[0].length)
        }
        if (debug)
            print(xs);
        splittingTime += (new Date() - then);
        return xs;
    }

    function positionalAttrs(tag, s, paren, cls) {
        var attr = splitAttrs(s, paren);
        for ( var i=0 ; i < attr.length ; i++ ) {
            if (attr[i] is Array)
                fail("Named attributes not allowed here: " + attr[i]);
        }
        if (cls != null)
            attr.unshift(cls);
        return new constructors[tag](tag,attr);
    }

    function parseNamedAttrs(s) {
        var attr = splitAttrs(s);
        for ( var i=0 ; i < attr.length ; i++ ) {
            if (!(attr[i] is Array || i ==0 && attr[i] is String && attr.length == 1))
                fail("Named attributes required here: " + attr[i]);
        }
        return attr;
    }

    function reportMatch(line) {
        if (debug)
            print(line);
    }

    function currentClassName() {
        if (cppDataStack.length == 0)
            fail("No active GC_DATA_BEGIN");
        return cppDataStack[cppDataStack.length-1];
    }

    // Does not match the trailing right paren.  $1 is the tag, $2 the
    // rest of the text starting just right of the left paren for the
    // argument list.

    const cppMetaTag = 
        new RegExp("^(" +
                   ["GC_CPP_EXACT_WITH_HOOK_IFDEF",
                    "GC_CPP_EXACT_WITH_HOOK_IFNDEF",
                    "GC_CPP_EXACT_WITH_HOOK_IF",
                    "GC_CPP_EXACT_WITH_HOOK",
                    "GC_CPP_EXACT_WITH_HOOK",
                    "GC_CPP_EXACT_WITH_HOOK",
                    "GC_CPP_EXACT_IFDEF",
                    "GC_CPP_EXACT_IFNDEF",
                    "GC_CPP_EXACT_IF",
                    "GC_CPP_EXACT",
                    "GC_AS3_EXACT_WITH_HOOK_IFDEF",
                    "GC_AS3_EXACT_WITH_HOOK_IFNDEF",
                    "GC_AS3_EXACT_WITH_HOOK_IF",
                    "GC_AS3_EXACT_WITH_HOOK",
                    "GC_AS3_EXACT_WITH_HOOK",
                    "GC_AS3_EXACT_WITH_HOOK",
                    "GC_AS3_EXACT_IFDEF",
                    "GC_AS3_EXACT_IFNDEF",
                    "GC_AS3_EXACT_IF",
                    "GC_AS3_EXACT",
                    "GC_NO_DATA",
                    "GC_DATA_BEGIN",
                    "GC_DATA_END"].join("|") +
                   ")\\s*\\((.*)");

    function matchCppMetaTag(line, where) {
        return cppMetaTag.exec(line.substring(where));
    }

    // Does not match the trailing right paren.  $1 is the tag, $2 the
    // rest of the text starting just right of the left paren for the
    // argument list.

    const cppFieldTag = 
        new RegExp("^(" +
                   ["GC_POINTERS",
                    "GC_POINTERS_SMALL",
                    "GC_STRUCTURES",
                    "GC_STRUCTURES_SMALL",
                    "GC_ATOMS",
                    "GC_ATOMS_SMALL",
                    "GC_STRUCTURE",
                    "GC_STRUCTURE_IFDEF",
                    "GC_STRUCTURE_IFNDEF",
                    "GC_STRUCTURE_IF",
                    "GC_POINTER",
                    "GC_POINTER_IFDEF",
                    "GC_POINTER_IFNDEF",
                    "GC_POINTER_IF",
                    "GC_ATOM",
                    "GC_ATOM_IFDEF",
                    "GC_ATOM_IFNDEF",
                    "GC_ATOM_IF",
                    "GC_CONSERVATIVE",
                    "GC_CONSERVATIVE_IFDEF",
                    "GC_CONSERVATIVE_IFNDEF",
                    "GC_CONSERVATIVE_IF"].join("|") +
                   ")\\s*\\((.*)");

    function matchCppFieldTag(line, where) {
        return cppFieldTag.exec(line.substring(where));
    }

    function stackToCppPrefix() {
        var pfx="";
        for ( var i=0; i < cppClassStack.length; i++)
            pfx += cppClassStack[i] + "::";
        return pfx;
    }

    const nativeAnnotationRegex:RegExp = /^\[native\s*\((.*)\)\s*\]/;

    // FIXME: Additional error checking we could add here:
    //  - only one data section per class, globally

    function processFile(filename) {
        cppDataStack.length = 0;
        cppClassStack.length = 0;

        const beforeReadLines = new Date();
        const text = readLines(filename);
        const afterReadLines = new Date();

        const beforeProcessing = new Date();
        const cppfile = Boolean(filename.match(/\.(h|cpp)$/));
        const as3file = Boolean(filename.match(/\.as$/));
        var lineno = 0;

        for ( var i=0 ; i < text.length ; i++ ) {
            var line = text[i];
            var result;

            lineno++;

            // Quick precomputation to filter out lines that we don't
            // need to examine any further with regular expressions.  The
            // regex search will start at the known good location.

            var gcIndex = -1;
            var nativeIndex = -1;
            if (!as3file)
                gcIndex = line.indexOf("GC_");
            if (!cppfile)
                nativeIndex = line.indexOf("[native");
            if (gcIndex == -1 && nativeIndex == -1)
                continue;

            errorContext = "On " + filename + " line " + lineno;

            // For line matching we match only at the start of the
            // line after taking the substring starting at the
            // known-good index.  This yields the same performance as
            // using a global regex and setting lastIndex to indicate
            // where we want to start matching.

            if (gcIndex >= 0) {
                // C++ annotations.

                if ((result = matchCppMetaTag(line, gcIndex)) != null) {
                    reportMatch(line);
                    var v = positionalAttrs(result[1], result[2], ")", null);
                    if (v is GCDataBegin || v is GCNoData) {
                        if (cppClassStack.length == 0 || cppClassStack[cppClassStack.length-1] != v.cls)
                            fail("Mismatched " + result[1] + " here: " + v.cls);
                        cppDataStack.push(v.cls);
                    }
                    if (v is GCDataEnd || v is GCNoData) {
                        var top = currentClassName();
                        if (v.cls != top)
                            fail(result[1] + " for " + v.cls + " but " + top + " is on the stack top");
                        cppDataStack.pop();
                        cppClassStack.pop();
                    }
                    if (!(v is GCDataSection)) {
                        if (v is GCClass) {
                            v.fullClassPrefix = stackToCppPrefix();
                            cppClassStack.push(v.cls);
                        }
                        specs.push(v);
                    }
                }
                else if ((result = matchCppFieldTag(line, gcIndex)) != null) {
                    reportMatch(line);
                    var v = positionalAttrs(result[1], result[2], ")", currentClassName());
                    specs.push(v);
                }
            }

            if (nativeIndex >= 0) {
                // AS3 annotations.
                //
                // For AS3 annotations we collect C++ class names if the [native] spec says
                // that the C++ class should be exactly traced.

                if ((result = nativeAnnotationRegex.exec(line.substring(nativeIndex))) != null) {
                    reportMatch(line);
                    var attr = parseNamedAttrs(result[1]);
                    var flags = {};
                    for ( var j=0 ; j < attr.length ; j++ ) {
                        if (attr[j] is Array)
                            flags[attr[j][0]] = attr[j][1];
                    }
                    if ("cls" in flags && ("classgc" in flags || "gc" in flags))
                        specs.push(new AS3Class(cppNamespace, flags["cls"]));
                    if ("instance" in flags && ("instancegc" in flags || "gc" in flags))
                        specs.push(new AS3Class(cppNamespace, flags["instance"]));
                }
            }
        }

        if (cppDataStack.length != 0)
            fail("Missing GC_DATA_END for " + currentClassName());

        if (cppClassStack.length != 0)
            fail("Missing GC_DATA_BEGIN/GC_DATA_END for these: " + cppClassStack);

        const afterProcessing = new Date();

        readingTime += (afterReadLines - beforeReadLines);
        processingTime += (afterProcessing - beforeProcessing);
    }

    for ( var i=0 ; i < files.length ; i++ )
        processFile(files[i]);

    if (profiling) {
        print("  reading time = " + readingTime/1000 + "s");
        print("  processing time = " + processingTime/1000 + "s");
        print("    splitting time = " + splittingTime/1000 + "s");
    }
}

function isVariableLength(t) {
    return t is GCPointers || t is GCAtoms || t is GCStructures;
}

// Populate as3ClassList, as3ClassMap, cppClassList, and cppClassMap.
// Sort the lists.

function collectClasses() 
{
    errorContext = "Collecting classes";

    for ( var i=0, limit=specs.length ; i < limit ; i++ ) {
        var s = specs[i];
        if (s is GCAS3Exact || s is GCCppExact) {
            var clsname = s.cls;
            if (cppClassMap.hasOwnProperty(clsname)) 
                fail("Duplicate " + (s is GCAS3Exact ? "GC_AS3_EXACT" : "GC_CPP_EXACT") + " spec: " + clsname);
            cppClassList.push(s);
            cppClassMap[clsname] = s;
        }
        else if (s is AS3Class) {
            var clsname = s.cls;
            if (as3ClassMap.hasOwnProperty(clsname)) {
                // Completely gross hack in the vector code - the instance for VectorClass and ObjectVectorClass
                // are both ObjectVectorObject.  Just work around it for now with this gross hack.
                if (clsname == "ObjectVectorObject")
                    continue;
                fail("Duplicate AS3 native spec: " + clsname);
            }
            as3ClassList.push(s);
            as3ClassMap[clsname] = s;
        }
    }

    as3ClassList.sort(function (a,b) { return strcmp(a.cls,b.cls) });
    cppClassList.sort(function (a,b) { return strcmp(a.cls,b.cls) });

    if (debug) {
        print("C++ class map: " + cppClassMap);
        print("AS3 class map: " + as3ClassMap);
    }
}

// Check that the sets of classes correspond: every AS3 class must be
// a C++ GC_AS3_EXACT class, and vice versa.  GC_CPP_EXACT classes must
// not have AS3 counterparts.

function checkClasses()
{
    errorContext = "Checking class correspondence";

    for ( var i=0 ; i < cppClassList.length ; i++ ) {
        var c = cppClassList[i];
        var n = c.cls;
        var probe = as3ClassMap.hasOwnProperty(n);
        if (c is GCCppExact) {
            if (probe)
                fail("AS3 side may not be defined for GC_CPP_EXACT " + n);
            continue;
        }
        if (!probe)
            fail("AS3 side is missing annotation for " + n);
    }

    for ( var i=0 ; i < as3ClassList.length ; i++ ) {
        var c = as3ClassList[i];
        var n = c.cls;
        if (!cppClassMap.hasOwnProperty(n))
            fail("C++ side is missing annotation for " + n);
        if (!(cppClassMap[n] is GCAS3Exact))
            fail("C++ side is not a GC_AS3_EXACT class for " + n);
    }
}

// Add fields to classes, check for errors in class names, duplicates, etc.
// Sort the fields by name.

function collectFields()
{
    errorContext = "Collecting fields";

    for ( var i=0 ; i < specs.length ; i++ ) {
        var s = specs[i];
        if (s is GCClass || s is AS3Class)
            continue;
        if (!cppClassMap.hasOwnProperty(s.cls))
            fail("Bad field annotation - unknown class: " + s.cls + " in " + s);
        var c = cppClassMap[s.cls];
        var fieldname = s.name;
        if (s.if_) fieldname += "!if!" + s.if_;
        if (s.ifdef) fieldname += "!ifdef!" + s.ifdef;
        if (s.ifndef) fieldname += "!ifndef!" + s.ifndef;
        if (isVariableLength(s)) {
            // FIXME: It would be good to loosen the following restriction up; it 
            // would be sufficient to decree that only one of the arrays can be 
            // large.  It is rarely the case that pointers or atom arrays are anything
            // but trailing (and then there's only one), but eg MethodInfo has 
            // an inline fixed-size pointer array for the lookup cache, and if it 
            // were to have a trailing array as well then we'd run into this restriction.
            if (c.variable_length_field != null)
                fail("Arbitrary restriction: More than one variable length field on " + c);
            if (c.fieldMap.hasOwnProperty(fieldname))
                fail("Duplicate field name: " + s.name + "; canonically " + fieldname);
            c.variable_length_field = s;
        }
        else {
            if (c.fieldMap.hasOwnProperty(fieldname) || (c.variable_length_field != null && c.variable_length_field.name == fieldname))
                fail("Duplicate field name: " + s.name + "; canonically " + fieldname);
            c.fieldMap[fieldname] = s;
            c.fieldList.push(s);
        }
    }

    for ( var i=0 ; i < cppClassList.length ; i++ )
        cppClassList[i].fieldList.sort(function (a,b) { return strcmp(a.name,b.name) });
}

// For each class compute whether it's likely to be large or small,
// this will influence how we generate code.  
// A manifestly large number of fixed fields overrides any "small" hint.
// A pointer array will make us assume the object is large unless
// the hint is that it's small.

function computeLargeOrSmall()
{
    for ( var i=0 ; i < cppClassList.length ; i++ ) {
        var c = cppClassList[i];
        if (c.fieldList.length >= largeObjectCutoff/4) // "4" is a proxy for word size, not correct on 64-bit systems but OK for this purpose
            c.probablyLarge = true;
        else if (c is GCCppExact && c.variable_length_field != null) {
            c.hint = c.variable_length_field.hint;
            c.probablyLarge = (c.hint != "small")
        }
    }
}

// If a class is large it could be because it has a pointer array or
// because it has many fixed fields or both.  It is pretty much never
// going to be the case that it has many fixed fields so we always
// trace the fixed fields for cursor==0, technically that's suboptimal
// for incrementality but not a problem for correctness.

function constructTracerBodies()
{
    function traceField(out, field) {
        if (field.ifdef)
            out.PR("#ifdef " + field.ifdef);

        if (field.ifndef)
            out.PR("#ifndef " + field.ifndef);

        if (field.if_)
            out.PR("#if " + field.if_);

        try {
            throw field;
        }
        catch (f: GCPointer)      { out.PR("gc->TraceLocation(&" + field.name + ");") }
        catch (f: GCConservative) { out.PR("gc->TraceConservativeLocation(&" + field.name + ");") }
        catch (f: GCStructure)    { out.PR(field.name + ".gcTrace(gc);") }
        catch (f: GCAtom)         { out.PR("gc->TraceAtom(&" + field.name + ");") }
        catch (f: *) {
            fail("Unknown type to trace: " + field);
        }

        if (field.ifdef || field.ifndef || field.if_)
            out.PR("#endif");
    }

    // Here we can do better: we can collect the fields that have the
    // same pointer attribute and the same ifdef attribute, and then
    // emit each group in a chunk.  That will allow us to use the
    // multi-argument tracing functions when they're available.

    function emitFixedFields(c) {
        for ( var j=0 ; j < c.fieldList.length ; j++ ) {
            var f = c.fieldList[j];
            if (isVariableLength(f))
                fail("Invariant failure: there should be no variable length field among the fixed fields: " + f);
            traceField(c.out, f);
        }
    }

    function emitChunk(out, f, start, len) {
        try { 
            throw f;
        }
        catch (f:GCPointers)   { c.out.PR("gc->TraceLocations((" + f.name + "+" + start + "), " + len + ");"); }
        catch (f:GCAtoms)      { c.out.PR("gc->TraceAtoms((" + f.name + "+" + start + "), " + len + ");"); }
        catch (f:GCStructures) {
            c.out.
                PR("for ( size_t _xact_iter=0 ; _xact_iter < " + len + "; _xact_iter++ )").
                IN().
                PR(f.name + "[+_xact_iter+" + start + "].gcTrace(gc);").
                OUT();
        }
        catch (f:*) {
            fail("Unknown variable length field type: " + f);
        }
    }

    // Important that the names introduced here do not shadow the ones
    // in the class so we prefix locals with _xact_.

    function emitArrayChunked(c) {
        c.out.
            PR("const size_t _xact_work_increment = " + largeObjectCutoff + "/sizeof(void*);").
            PR("const size_t _xact_work_count = " + c.variable_length_field.count + ";").
            PR("if (_xact_cursor * _xact_work_increment >= _xact_work_count)").
            IN().
            PR("return false;").
            OUT().
            PR("size_t _xact_work = _xact_work_increment;").
            PR("bool _xact_more = true;").
            PR("if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)").
            PR("{").
            IN().
            PR("_xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);").
            PR("_xact_more = false;").
            OUT().
            PR("}");
        emitChunk(c.out, c.variable_length_field, "(_xact_cursor * _xact_work_increment)", "_xact_work");
        c.out.PR("return _xact_more;");
    }

    function emitArrayUnchunked(c) {
        emitChunk(c.out, c.variable_length_field, "0", c.variable_length_field.count);
    }

    // FIXME: Not currently using this, but we could use it - probably elsewhere - to flag
    // probably-incorrect code.

    function noCredibleTracer(n) {
        switch (n) {
        case "MMgc::GCObject":
        case "GCObject":
            return true;
        default:
            return false;
        }
    }

    function noUsefulTracer(n) {
        switch (n) {
        case "MMgc::GCFinalizedObject":
        case "GCFinalizedObject":
        case "MMgc::GCTraceableObject":
        case "GCTraceableObject":
        case "MMgc::RCObject":
        case "RCObject":
            return true;
        default:
            return false;
        }
    }

    function cleanupNs(name) {
        // If the name has a namespace, keep it
        // Otherwise prepend the current output namespace
        if (name.match("::"))
            name = name.replace(/::/g, "_");
        else
            name = cppNamespace + "_" + name;
        // Brockets appear in template expansions: Fnord<A>
        // Spaces appear in nested template expressions: Fnord< A<B> >
        return name.replace(/ /g, "").replace(/<|>/g, "X");
    }

    errorContext = "Accumulating bodies";

    for ( var i=0 ; i < cppClassList.length ; i++ ) {
        var c = cppClassList[i];

        // The interlock is just a #define with that name emitted at
        // the beginning of the output, we'll get a compilation error
        // if it's not defined.  This way we ensure that every exactly
        // traced class has an exactly traced base class.

        if (c.base != null && !noUsefulTracer(c.base)) {
            c.out.PR(c.base + "::gcTrace(gc, 0);");
            if (interlockOutputFile != null)
                c.out.PR("(void)(" + cleanupNs(c.base) + "_isExactInterlock != 0);");
        }

        if (c.hook)
            c.out.PR("gcTraceHook_" + c.cls + "(gc);");

        if (c.probablyLarge) {
            if (c.fieldList.length > 0) {
                c.out.
                    PR("if (_xact_cursor == 0) {").
                    IN();
                emitFixedFields(c);
                c.out.
                    OUT().
                    PR("}");
            }
            if (c is GCClass && c.variable_length_field != null)
                emitArrayChunked(c);
        }
        else {
            emitFixedFields(c);
            if (c is GCClass && c.variable_length_field != null)
                emitArrayUnchunked(c);
        }
    }
}

function constructAndPrintTracers()
{
    var interlocks = interlockOutputFile ? new Printer() : null;
    var builtins = builtinOutputFile ? new Printer() : null;
    var natives = nativeOutputFile ? new Printer() : null;

    function emitInterlock(c) {
        if (interlocks)
            interlocks.PR("#define " + cppNamespace + "_" + c.cls + "_isExactInterlock 1");
    }

    function emitTracers()
    {
        for ( var i=0 ; i < cppClassList.length ; i++ ) {
            var c = cppClassList[i];
            var output = null;
            if (c is GCCppExact) {
                if (!natives)
                    continue;
                output = natives;
            }
            else {
                if (!builtins)
                    continue;
                output = builtins;
            }

            emitInterlock(c);
            if (c.ifdef)
                output.
                    PR("#ifdef " + c.ifdef).
                    NL();
            else if (c.ifndef)
                output.
                    PR("#ifndef " + c.ifndef).
                    NL();
            else if (c.if_)
                output.
                    PR("#if " + c.if_).
                    NL();
            if (c.probablyLarge) {
                output.
                    PR("bool " + c.fullName() + "::gcTrace(MMgc::GC* gc, size_t _xact_cursor)").
                    PR("{").
                    DO(function (output) {
                            if (output === builtins) {
                                output.
                                    IN().
                                    PR("#ifndef GC_TRIVIAL_TRACER_" + c.cls).
                                    PR("if (_xact_cursor == 0)").
                                    PR("{").
                                    IN().
                                    PR("m_slots_" + c.cls + ".gcTracePrivateProperties(gc);").
                                    OUT().
                                    PR("}").
                                    PR("#endif").
                                    OUT();
                            }
                        }).
                    PR(c.out.get()).
                    PR("}").
                    NL();
            }
            else {
                output.
                    PR("bool " + c.fullName() + "::gcTrace(MMgc::GC* gc, size_t _xact_cursor)").
                    PR("{").
                    IN().
                    PR("(void)gc;").
                    PR("(void)_xact_cursor;").
                    DO(function (output) {
                            if (output === builtins) {
                                output.
                                    PR("#ifndef GC_TRIVIAL_TRACER_" + c.cls).
                                    PR("m_slots_" + c.cls + ".gcTracePrivateProperties(gc);").
                                    PR("#endif");
                            }
                        }).
                    OUT().
                    PR(c.out.get()).
                    IN().
                    PR("return false;").
                    OUT().
                    PR("}").
                    NL();
            }
            if (c.ifdef || c.ifndef || c.if_) 
                output.
                    PR("#endif // " + (c.ifdef || c.ifndef || c.if_)).
                    NL();
        }
    }

    function emitDelegates()
    {
        var output = "";
        for ( var i=0 ; i < cppClassList.length ; i++ ) {
            var c = cppClassList[i];
            if (c.base != null && c.base != "")
                output += ("#define GCDELEGATE_" + c.cls + " " + c.base + "\n");
        }
        return output;
    }

    function printToFile(fn, txt) {
        File.write(fn, txt);
    }

    function nsOpen()
    {
        if(cppNamespace == "")
            return "\n";
        else
            return "namespace " + cppNamespace +"\n{\n";
    }

    function nsClose()
    {
        if(cppNamespace == "")
            return "\n";
        else
            return "}\n";
    }

    errorContext = "Emitting code";

    emitTracers();

    const doNotEdit = "\n/* machine generated file via utils/exactgc.as -- do not edit */\n\n";

    if (builtinOutputFile) 
        printToFile(builtinOutputFile, 
                    (LICENSE + 
                     doNotEdit +
                     nsOpen() +
                     builtins.get() + 
                     (nativeOutputFile == builtinOutputFile ? natives.get() : "") +
                     nsClose()));

    if (nativeOutputFile && nativeOutputFile != builtinOutputFile)
        printToFile(nativeOutputFile,
                    (LICENSE + 
                     doNotEdit +
                     nsOpen() +
                     natives.get() + 
                     nsClose()));

    if (interlockOutputFile)
        printToFile(interlockOutputFile,
                    (LICENSE + 
                     doNotEdit +
                     interlocks.get() + "\n"));
}

function profile(what, thunk)
{
    var then = new Date();
    var result = thunk();
    var now = new Date();
    if (profiling)
        print(what + ": " + (now - then)/1000 + "s");
    return result;
}

function main()
{
    profile("readFiles", function() { readFiles(processOptionsAndFindFiles(System.argv)) });
    profile("collectClasses", collectClasses);
    profile("checkClasses", checkClasses);
    profile("collectFields", collectFields);
    profile("computeLargeOrSmall", computeLargeOrSmall);
    profile("constructTracerBodies",constructTracerBodies);
    profile("constructAndPrintTracers",constructAndPrintTracers);
}

profile("main", main);
