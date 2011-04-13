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

// Input is a bunch of file names and/or names of files from which to read file names.
//
// Output is a tree of classes derived from a root class (default GCFinalizedObject),
// with an annotation about whether it has an explicit destructor or not (line 
// prefixed with "*").  Each class is printed with the file and line on which the 
// definition starts.
//
// Assumes names are globally unique (namespaces don't matter).  Is tricked by macro
// definitions like in the Error objects, and by the use of the bitwise not operator
// in some cases:   "exception->flags &= ~Exception::SEEN_BY_DEBUGGER;"
//
// Furtermore there will be generated destructors for classes that have substructures,
// and those destructors won't be visible here.
//
// Usage:
//
//    avmshell gcClasses.abc -- [options] file ...
//
// Options:
//
//    --base classname  Specify the base class name, default GCFinalizedObject.
//               Useful values are GCObject, GCTraceableObject, and RCObject.
//
// Example:
//
//    find . -name '*.cpp' -o -name '*.h' > allfiles.txt
//    avmshell gcClasses.abc -- @allfiles.txt
//
// Example: (for TR, though not the player)
//
//    avmshell utils/gcClasses.abc -- $(find . -name '*.h' -o -name '*.cpp')
//
// Note the list of "excluded" paths below; those could be command line arguments but
// that's for later.

import avmplus.*;

// The root class could be a command line argument.

var rootclass = "GCFinalizedObject";

// Classes defined in files whose names match these regexes will not
// be printed, but will participate in the computation.

const ignorePaths =
    [ new RegExp("^.*/shell/.*$"),
     new RegExp("^.*/extensions/ST_.*$"),
     new RegExp("^.*/extensions/JavaGlue.*$"),
     new RegExp("^.*/MMgc/GCTests.*$")];

class LineInfo
{
    function LineInfo(_derived, _base, _filename, _lineno) {
        derived = _derived;
        base = _base;
        filename = _filename;
        lineno = _lineno;
    }
    var derived;            // name of the class being defined
    var base;               // name of its base class
    var filename;           // file where we found the definition of 'derived'
    var lineno;             // line where we found the definition of 'derived'
    var baseref = null;     // reference to the LineInfo for the base class
    var subrefs = [];       // list of known subclasses
    var destructor = false; // true if we believe this has a destructor
}

main(System.argv);

function main(args) {
    if (args.length > 0 && args[0] == "--base") {
        if (args.length > 1) {
            rootclass = args[1];
            args.shift();
            args.shift();
        }
        else
            throw new Error("Missing class name to --base");
    }
    printClasses(processQueue(readFiles(args)));
}

function readFiles(argv) {
    var filenames_dict = {};
    var probable_destructors = {};
    var all_lines = [];
    var re1 = new RegExp("class\\s+([A-Za-z_][A-Za-z0-9_]*)\\s*:.*(?:public|private|virtual)\\s*([A-Za-z0-9_:]+)");
    var re2 = new RegExp("class\\s+GC_(?:AS3|CPP)_EXACT(?:[A-Z_]+)?\\(([^,\\)]+)\\s*,\\s*([^,\\)]+)");
    var red = new RegExp("~\s*([A-Za-z_][A-Za-z0-9_]*)");

    compute(argv,false);
    annotateDestructors();
    return all_lines;

    function annotateDestructors() {
        for ( var i=0 ; i < all_lines.length ; i++ ) {
            var ln = all_lines[i];
            ln.destructor = probable_destructors.hasOwnProperty(ln.derived);
        }
    }

    function compute(argv) {
        for ( var i=0 ; i < argv.length ; i++ ) {
            var arg=argv[i];
            if (arg.charAt(0) == '@')
                compute(readFile(arg.substring(1)));
            else if (newFile(arg))
                filterFile(arg);
        }
    }

    function newFile(fn) {
        return File.exists(fn) && !filenames_dict.hasOwnProperty(fn);
    }

    function filterFile(fn) {
        var lines = readFile(fn);
        var ignore = false;
        var ignorelevel = 0;
        for ( var i=0 ; i < lines.length ; i++ ) {
            var l = lines[i];
            var result;
            // Faster to filter by indexOf and then do regex matching than just regex matching.
            if (l.indexOf("#") != -1) {
                // Preprocessor macro?
                // We need to know the regions commented out by #ifdef DRC_TRIVIAL_DESTRUCTOR .. #endif
                // but we must track nested regions too.
                if (l.match(/^\s*#\s*(?:ifdef|ifndef|if|elif)/)) {
                    if (l.match(/^\s*#\s*ifdef\s+DRC_TRIVIAL_DESTRUCTOR/))
                        ignore = true;
                    if (ignore)
                        ignorelevel++;
                }
                else if (l.match(/^\s*#\s*endif/)) {
                    if (ignore) {
                        --ignorelevel;
                        if (ignorelevel == 0)
                            ignore = false;
                    }
                }
            }
            if (l.indexOf("class") != -1) {
                if ((result = l.match(re1)) || (result = l.match(re2))) {
                    var derived = result[1];
                    var base = stripNamespaces(result[2]);
                    all_lines.push(new LineInfo(derived,base,fn,i+1));
                }
            }
            else if (!ignore && l.indexOf("~") != -1) {
                if (result = l.match(red)) {
                    probable_destructors[result[1]] = true;
                }
            }
        }

        filenames_dict[fn] = true;
    }

    function stripNamespaces(name) {
        var x = name.lastIndexOf(":");
        return (x >= 0) ? name.substring(x+1) : name;
    }
}

function readFile(fn) {
    try {
        return File.read(fn).split("\n");
    }
    catch (e) {
        print("Can't open file \"" + "\"\n" + e);
        return [];
    }
}

function processQueue(lines) {
    var queue = [];     // Queue of classes to process
    var classes = {};   // Map of classes processed or in queue to their LineInfo

    queue.push(rootclass);
    classes[rootclass] = new LineInfo(rootclass, "", "(internal)", 0); // synthetic

    while (queue.length > 0) {
        var cls = queue.shift();
        for ( var l=0 ; l < lines.length ; l++ ) {
            var ln = lines[l];
            if (classes.hasOwnProperty(ln.base) && !classes.hasOwnProperty(ln.derived)) {
                var basecls = classes[ln.base];
                ln.baseref = basecls;
                basecls.subrefs.push(ln);
                classes[ln.derived] = ln;
                queue.push(ln.derived);
            }
        }
    }

    return classes;
}

function printClasses(classes) {
    printCls(classes[rootclass], 0);

    function printCls(cls, indent) {
        if (!ignoreIt(cls)) {
            var d = cls.destructor ? " * " : "   ";
            print(d + padTo50(spaces(indent) + cls.derived) + " " + cls.filename + ":" + cls.lineno);
        }
        cls.subrefs.sort(function (a,b) { return strcmp(a.derived, b.derived); })
        for ( var i=0 ; i < cls.subrefs.length ; i++ ) {
            var c = cls.subrefs[i];
            printCls(c, indent+2);
        }
    }

    function ignoreIt(cls) {
        for ( var i=0 ; i < ignorePaths.length ; i++ ) {
            if (cls.filename.match(ignorePaths[i]))
                return true;
        }
        return false;
    }

    function padTo50(s) {
        return (s.length >= 50) ? s : padTo50(s + " ");
    }

    function spaces(n) {
        return (n == 0) ? "" : " " + spaces(n-1);
    }

    function strcmp(a,b) {
        if (a < b) return -1;
        if (b < a) return 1;
        return 0;
    }
}

