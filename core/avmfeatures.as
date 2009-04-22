/* -*- tab-width: 4 -*-
   vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5)

   ***** BEGIN LICENSE BLOCK *****
   Version: MPL 1.1/GPL 2.0/LGPL 2.1
 
   The contents of this file are subject to the Mozilla Public License Version
   1.1 (the "License"); you may not use this file except in compliance with
   the License. You may obtain a copy of the License at
   http://www.mozilla.org/MPL/
 
   Software distributed under the License is distributed on an "AS IS" basis,
   WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
   for the specific language governing rights and limitations under the
   License.
 
   The Original Code is [Open Source Virtual Machine.].
 
   The Initial Developer of the Original Code is
   Adobe System Incorporated.
   Portions created by the Initial Developer are Copyright (C) 1993-2006
   the Initial Developer. All Rights Reserved.
 
   Contributor(s):
     Adobe AS3 Team
 
   Alternatively, the contents of this file may be used under the terms of
   either the GNU General Public License Version 2 or later (the "GPL"), or
   the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
   in which case the provisions of the GPL or the LGPL are applicable instead
   of those above. If you wish to allow use of your version of this file only
   under the terms of either the GPL or the LGPL, and not to allow others to
   use your version of this file under the terms of the MPL, indicate your
   decision by deleting the provisions above and replace them with the notice
   and other provisions required by the GPL or the LGPL. If you do not delete
   the provisions above, a recipient may use your version of this file under
   the terms of any one of the MPL, the GPL or the LGPL.
   ***** END LICENSE BLOCK *****


   This file defines the feature set for avmplus.

   It is also a program to transform the feature definition into three files:

     * a C++ header file, avmfeatures.h
     * a C++ source file, avmfeatures.cpp
     * a Python file, ../build/avmfeatures.py


   The feature set is defined as an XML (really E4X) datum, see below.

   Grammar for feature definitions.

       features           ::= "<features>" feature* at-least-one* at-most-one* exactly-one* "</features>"
       feature            ::= "<feature>" desc name defines+ precludes* requires* "</feature>"
	   desc				  ::= "<desc>" TEXT "</desc>"
       name               ::= "<name>" TEXT "</name>"
       defines            ::= "<defines>" TEXT "</defines>"
       precludes          ::= "<precludes>" TEXT "</precludes>"
       requires           ::= "<requires>" TEXT | at-most-one | at-least-one | exactly-one "</requires>"
       at-least-one       ::= "<at-least-one>" name+ "</at-least-one>"
       at-most-one        ::= "<at-most-one>" name+ "</at-most-one>"
       exactly-one        ::= "<exactly-one>" name+ "</exactly-one>"
       TEXT               ::= space* [a-zA-Z][a-zA-Z0-9_]* space*

       Clause ordering is not significant anywhere and xml comments are
	   allowed everywhere.  Leading and trailing whitespace in each element
	   is ignored.

   Semantics:

       Features are compile time constraints that select and deselect
       aspects of the virtual machine code.  At compile time, a value
       (off or on) must be provided for every feature, there are no
       default values.

       A FEATURE clause defines a named feature, named by its NAME clause
	   and described in human terms by its DESC clause.  
	   
	     NOTE: A good description is absolutely essential.  It should
		 state what the feature does, but also what the implications of
		 selecting or deselecting it might be.

       No two FEATUREs may name the same feature.

       Feature names named by PRECLUDES, REQUIRES, AT-LEAST-ONE, and
       AT-MOST-ONE clauses must be defined by some FEATURE.

       A PRECLUDES clause in a FEATURE adds a constraint that the
       precluded feature cannot be turned on if the feature defined by
       the present FEATURE is turned on.

       A REQUIRES clause in a FEATURE adds a constraint that the
       required feature must be turned on if the feature defined by
       the present FEATURE is turned on.

       A DEFINES clause in an FEATURE names a preprocessor macro that is
       defined (with a simple "#define X") if the FEATURE is turned on.
       This seems redundant until you consider that a FEATURE can define
       multiple macros; this allows discrimination internally in the
       module to be organized differently than feature definition
       externally.

       An AT-LEAST-ONE clause adds a constraint that at least one of
       the features has been turned on.

       An AT-MOST-ONE clause adds a constraint that at most one of the
       features has been turned on.  (The same can be expressed by
       PRECLUDES clauses but that would be more error-prone.)

       EXACTLY-ONE is an abbreviation for AT-LEAST-ONE and AT-MOST-ONE.

   This program processes the feature definition below to check static
   constraints and produce the C++ header file core/avmfeatures.h; that
   header file checks compile-time constraints and defines preprocessor
   macros as appropriate.
     
   The product's feature settings are imported through VMPI.h; see comments
   in that file for how to provide the settings.

   This program also produces a C++ compilation unit (.cpp file) that 
   contains a single string that lists the features that were enabled at
   build time; it is used by the AVM shell for debugging purposes.

   This program also produces a Python file that is used by the cross-platform
   build system to handle configuration switches; see ../configure.py.

*/
	
/****************************************************************************
 ***** Start of feature definition ******************************************
 ****************************************************************************/

var FEATURES = 
<features>

  <!-- Basic system characteristics -->

  <feature>
    <desc> Selects a 32-bit architecture </desc>

    <name>      AVMSYSTEM_32BIT </name>
	<precludes> AVMSYSTEM_64BIT </precludes>
	<defines>   VMCFG_32BIT </defines>
  </feature>
  
  <feature>
    <desc> Selects a 64-bit architecture </desc>

    <name>      AVMSYSTEM_64BIT </name>
	<precludes> AVMSYSTEM_32BIT </precludes>
	<defines>   VMCFG_64BIT </defines>
	<defines>   MMGC_64BIT </defines>
	<defines>   AVMPLUS_64BIT </defines>	<!-- FIXME: legacy name -->
  </feature>

  <feature>
    <desc> Selects a big-endian architecture: the most significant byte of a word
	       is stored at the lowest byte address of the word </desc>
		   
    <name>      AVMSYSTEM_BIG_ENDIAN </name>
	<precludes> AVMSYSTEM_LITTLE_ENDIAN </precludes>
	<defines>   VMCFG_BIG_ENDIAN </defines>
	<defines>   AVMPLUS_BIG_ENDIAN </defines>  <!-- FIXME: legacy name -->
  </feature>
  
  <feature>
    <desc> Selects a little-endian architecture: the least significant byte of a word
	       is stored at the lowest byte address of the word </desc>

    <name>      AVMSYSTEM_LITTLE_ENDIAN </name>
	<precludes> AVMSYSTEM_BIG_ENDIAN </precludes>
	<defines>   VMCFG_LITTLE_ENDIAN </defines>
	<defines>   AVMPLUS_LITTLE_ENDIAN </defines>  <!-- FIXME: legacy name -->
  </feature>


  <!-- CPU architectures, one of these is required for the JIT -->

  <feature>
    <desc> Selects the x86-32 architecture </desc>
	
	<name>      AVMSYSTEM_IA32 </name>
	<precludes> AVMSYSTEM_64BIT </precludes>
	<defines>   VMCFG_IA32 </defines>
	<defines>   MMGC_IA32 </defines>
	<defines>   AVMPLUS_IA32 </defines>  <!-- FIXME: legacy name -->
  </feature>
  
  <feature>
    <desc> Selects the x86-64 architecture </desc>
	
	<name>     AVMSYSTEM_AMD64 </name>
	<requires> AVMSYSTEM_64BIT </requires>
	<defines>  VMCFG_AMD64 </defines>
	<defines>  MMGC_AMD64 </defines>
	<defines>  AVMPLUS_AMD64 </defines>  <!-- FIXME: legacy name -->
  </feature>

  <feature>
    <desc> Selects the ARM architecture (version left unspecified for now). </desc>
	
	<name>      AVMSYSTEM_ARM </name>
	<precludes> AVMSYSTEM_64BIT </precludes>
	<defines>   VMCFG_ARM </defines>
	<defines>   MMGC_ARM </defines>
	<defines>   AVMPLUS_ARM </defines>  <!-- FIXME: legacy name -->
  </feature>
  
  <feature>
    <desc> Selects the PowerPC / Power architecture.  Whether it's the 32-bit or the 
		   64-bit version of the architecture is controlled independently. </desc>
		   
	<name>     AVMSYSTEM_PPC </name>
	<defines>  VMCFG_PPC </defines>
	<defines>  MMGC_PPC </defines>
	<defines>  AVMPLUS_PPC </defines>  <!-- FIXME: legacy name -->
  </feature>
  
  <feature>
    <desc> Selects the 32-bit SPARC architecture. </desc>
	
	<name>      AVMSYSTEM_SPARC </name>
	<precludes> AVMSYSTEM_64BIT </precludes>
	<defines>   VMCFG_SPARC </defines>
	<defines>   MMGC_SPARC </defines>
	<defines>   AVMPLUS_SPARC </defines>  <!-- FIXME: legacy name -->
  </feature>
  
  <at-most-one>
    <!-- architectures are all mutually exclusive, but there can be "none", I believe (need to verify) -->
	<name> AVMSYSTEM_IA32 </name>
	<name> AVMSYSTEM_AMD64 </name>
	<name> AVMSYSTEM_ARM </name>
	<name> AVMSYSTEM_PPC </name>
	<name> AVMSYSTEM_SPARC </name>
  </at-most-one>


  <!-- operating systems.
       We might want more of these, I bet the code has a bunch of implied operating
	   systems (eg WIN32 && ARM usually means Windows Mobile...)  -->
	   
  <feature>
    <desc> Selects Unix / Linux (but not MacOS) </desc>
	<name> AVMSYSTEM_UNIX </name>
	<defines> AVMPLUS_UNIX </defines>
  </feature>
  
  <feature>
    <desc> Selects MacOS X </desc>
	<name> AVMSYSTEM_MAC </name>
	<defines> AVMPLUS_MAC </defines>
	<defines> MMGC_MAC </defines>
  </feature>
  
  <feature>
    <desc> Selects Win32, Win64, Windows Mobile </desc>
	<name> AVMSYSTEM_WIN32 </name>
	<defines> AVMPLUS_WIN32 </defines>
  </feature>
  
  <exactly-one>
	<name> AVMSYSTEM_UNIX </name>
	<name> AVMSYSTEM_MAC </name>
	<name> AVMSYSTEM_WIN32 </name>
  </exactly-one>


  <!-- VM facilities: AVMFEATURE_* -->
  
  <feature>
    <desc>	Selects the AVM debugger API, including retaining debug information at run-time.
			
			There is a slight performance penalty to enabling this; clients that want
			maximal execution performance and don't care about debugging should disable it. </desc>

    <name>     AVMFEATURE_DEBUGGER  </name>
    <defines>  VMCFG_DEBUGGER  </defines>
	<defines>  VMCFG_VERIFYALL </defines>
	<defines>  DEBUGGER </defines>           <!-- FIXME: legacy name -->
	<defines>  AVMPLUS_VERIFYALL </defines>  <!-- FIXME: legacy name -->
  </feature>

  <feature>
    <desc> Selects vtune profiling.  FIXME more here ... </desc>

    <name>     AVMFEATURE_VTUNE  </name>
    <defines>  VMCFG_VTUNE</defines>
  </feature>

  <feature>
    <desc> Enables the just-in-time compiler.  This will typically increase performance
	       significantly but may result in significantly higher memory consumption. </desc>

    <name> AVMFEATURE_JIT  </name>
	<requires>
	 <exactly-one> 
	  <name> AVMSYSTEM_IA32 </name>
	  <name> AVMSYSTEM_AMD64 </name>
	  <name> AVMSYSTEM_ARM </name>
	  <name> AVMSYSTEM_PPC </name>
	  <name> AVMSYSTEM_SPARC </name>
	 </exactly-one>
	</requires>
    <defines> VMCFG_NANOJIT  </defines>
    <defines> FEATURE_NANOJIT </defines>  <!-- FIXME: legacy name -->
  </feature>

  <feature>
    <desc> Selects the ABC interpreter.  Appropriate for platforms that run 
	       the interpreter only for initialization code and for 
           platforms that are exceptionally memory-constrained. </desc>

    <name>       AVMFEATURE_ABC_INTERP  </name>
    <defines>    VMCFG_INTERPRETER  </defines>
  </feature>


  <feature>
    <desc> Selects the wordcode interpreter.  Appropriate for platforms that run the
	       interpreter for some or all methods and are not exceptionally memory-constrained. </desc>

    <name>       AVMFEATURE_WORDCODE_INTERP  </name>
    <defines>    VMCFG_INTERPRETER  </defines>
    <defines>    VMCFG_WORDCODE  </defines>
    <defines>    VMCFG_WORDCODE_PEEPHOLE  </defines>
	<defines>    AVMPLUS_WORD_CODE </defines>  <!-- FIXME: legacy name -->
	<defines>    AVMPLUS_PEEPHOLE_OPTIMIZER </defines>  <!-- FIXME: legacy name -->
  </feature>

  <feature>
    <desc> Selects the faster, direct threaded wordcode interpreter.
           This is appropriate only for C++ compilers that support GCC-style computed
           "goto".  It is believed that RCVT, Intel's C++ compiler, and the Sunpro
           compiler all do.  </desc>

     <name>      AVMFEATURE_THREADED_INTERP </name>
     <requires>  AVMFEATURE_WORDCODE_INTERP </requires>
     <defines>   VMCFG_WORDCODE_THREADED </defines>
	 <defines>   AVMPLUS_DIRECT_THREADED </defines>  <!-- FIXME: legacy name -->
  </feature>

  <exactly-one>
    <!-- Though it is believed that it is possible to run avmplus with just a JIT,
         doing so is not supported at this time.  -->
		 
    <name>  AVMFEATURE_WORDCODE_INTERP  </name>
    <name>  AVMFEATURE_ABC_INTERP  </name>
  </exactly-one>

  <feature>
   <desc> AVMFEATURE_SELFTEST enables the built-in selftests.  These can be run by -Dselftest
		  at the shell or by calling the global function avmplus::selftests(), see extensions/Selftest.h.
		  Mostly they are useful for AVM development, not for embedders.
    
          Apart from code size considerations this can be enabled for release builds.  </desc>

   <name>     AVMFEATURE_SELFTEST </name>
   <defines>  VMCFG_SELFTEST </defines>
   <defines>  AVMPLUS_SELFTEST </defines> <!-- FIXME: legacy name -->
  </feature>

  <feature>
    <desc> Select support for 32 bit strings. If disabled, only 8 and 16 bits strings are supported. 
	       If enabled, string can be 32 bits internally, and the String method createUTF32() is defined, 
		   which also takes care of surrogate pairs, and createUTF16() converts surrogate pairs to UTF-32 
           if the desired string width is 32 bits.  </desc>

    <name> AVMFEATURE_UTF32 </name>
	<defines> VMCFG_UTF32 </defines>
	<defines> FEATURE_UTF32_SUPPORT </defines>  <!-- FIXME: legacy name -->
  </feature>

  <feature>
    <desc> Select support for the AS3 run-time compiler.  NOT RECOMMENDED.  The run-time compiler
           is still undergoing development.  </desc>

    <name> AVMFEATURE_EVAL </name>
    <defines> VMCFG_EVAL </defines>
  </feature>

  <feature>
    <desc> Makes JIT code buffers read-only to reduce the probability of heap overflow attacks.
	       If you select this then the MMgc platform layer must be able to set the protection
		   on the pages containing JIT code.  </desc>
	<name> AVMFEATURE_PROTECT_JITMEM </name>
	<defines> AVMPLUS_JIT_READONLY </defines>
  </feature>

  <feature>
    <desc> Selects locking around calls to the memory block manager (GCHeap), allowing multiple
	       threads to share the block manager.  Any client with more than one thread that uses
		   MMgc either for garbage collected or manually managed memory wants this; the Flash
		   Player requires it.  </desc>
	<name> AVMFEATURE_SHARED_GCHEAP </name>
	<defines> MMGC_LOCKING </defines>
  </feature>

  <feature>
    <desc> Make MMgc's overridden global new and delete operators delegate allocation and
	       deallocation to VMPI_alloc and VMPI_free instead of going to FixedMalloc.
		   
		   Whether you want this or not probably depends on the performance of the
		   underlying malloc and might depend on memory consumption patterns.  On desktop
		   systems you probably want this to be disabled.  </desc>
    <name> AVMFEATURE_USE_SYSTEM_MALLOC </name>
    <defines> MMGC_USE_SYSTEM_MALLOC </defines>
  </feature>
  
  <feature>
    <desc> Support C++ exceptions in the MMgc API.  At the time of writing (Apr 2009) 
	       this means decorating the global new and delete operator with appropriate 'throw'
		   clauses.  It is unlikely to mean anything more, as AVM+ and MMgc do not use and
		   do not generally support C++ exceptions.  
		   
		   FixedMalloc never throws an exception for a failed allocation. </desc>
		   
	<name> AVMFEATURE_CPP_EXCEPTIONS </name>
	<defines> MMGC_ENABLE_CPP_EXCEPTIONS </defines>
	<requires> AVMFEATURE_USE_SYSTEM_MALLOC </requires>
  </feature>
  
  <feature>
    <desc> Recognize a pointer or pointer-like value into anywhere in an object as referencing
	       that object during marking in the garbage collector.
		   
		   Enabling this tends to be increase GC cost but it can be a useful debugging aid. </desc>
	<name> AVMFEATURE_INTERIOR_POINTERS </name>
	<defines> MMGC_INTERIOR_PTRS </defines>
  </feature>
  
</features>;

/****************************************************************************
 ***** End of feature definition ********************************************
 ****************************************************************************/

import avmplus.*;
import flash.utils.*;

var allnames = {};

main();

function main() {

	// Generate avmfeatures.h

    var s = newString();
    var feature;
    var x;
	s += "\n";
	for each ( feature in FEATURES.feature )
		s += undefDefines(feature);
	s += "\n";
    for each ( feature in FEATURES.feature )
        s += testDefined(feature);
    s += "\n";
    for each ( feature in FEATURES.feature )
        s += checkRequirements(feature);
    s += "\n";
    for each ( x in FEATURES["at-least-one"] )
        s += atLeastOne(x);
    s += "\n";
    for each ( x in FEATURES["at-most-one"] )
        s += atMostOne(x);
    s += "\n";
	for each ( x in FEATURES["exactly-one"] )
		s += exactlyOne(x);
	s += "\n";
    for each ( feature in FEATURES.feature )
        s += defineResults(feature);
	s += "\n";
    s += "#ifdef AVMSHELL_BUILD\n";
    s += "extern const char * const avmfeatures;\n";
    s += "#endif\n\n";
	File.write("avmfeatures.h", s);

    // Generate avmfeatures.cpp

	s = newString();
	s += "\n\n";
	s += "#include \"avmplus.h\"\n\n";
	s += "#ifdef AVMSHELL_BUILD\n\n";
	s += "// The string avmfeatures contains the names of all features that were enabled\n";
	s += "// when the program was compiled.  Each feature name is terminated by a semicolon.\n";
    s += "const char * const avmfeatures = \"\"\n" 
	for each ( feature in FEATURES.feature )
        s += showFeature(feature);
    s += ";\n\n"
    s += "#endif // AVMSHELL_BUILD\n";
	File.write("avmfeatures.cpp", s);

    // Generate ../build/avmfeatures.py

    s = newString("#");
	s += "\n\n";
	s += "def featureSettings(o):\n";
	s += "    args = \"\"\n";
	for each ( feature in FEATURES.feature )
		s += configureFeature(feature);
	s += "    return args\n";

	File.write("../build/avmfeatures.py", s);
}

function newString(prefix="//") {
    var s = ["                     DO NOT EDIT THIS FILE",
			 " ",
			 "  This file has been generated by the script core/avmfeatures.as,",
			 "  from a set of configuration parameters in that file.",
			 " ",
			 "  If you feel you need to make changes below, instead edit the configuration",
			 "  file and rerun it to get a new version of this file.",
			 " ",
			 "  ***** BEGIN LICENSE BLOCK *****",
			 "  Version: MPL 1.1/GPL 2.0/LGPL 2.1",
			 " ",
			 "  The contents of this file are subject to the Mozilla Public License Version",
			 "  1.1 (the \"License\"); you may not use this file except in compliance with",
			 "  the License. You may obtain a copy of the License at",
			 "  http://www.mozilla.org/MPL/",
			 " ",
			 "  Software distributed under the License is distributed on an \"AS IS\" basis,",
			 "  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License",
			 "  for the specific language governing rights and limitations under the",
			 "  License.",
			 " ",
			 "  The Original Code is [Open Source Virtual Machine.].",
			 " ",
			 "  The Initial Developer of the Original Code is",
			 "  Adobe System Incorporated.",
			 "  Portions created by the Initial Developer are Copyright (C) 2009",
			 "  the Initial Developer. All Rights Reserved.",
			 " ",
			 "  Contributor(s):",
			 "    Adobe AS3 Team",
			 " ",
			 "  Alternatively, the contents of this file may be used under the terms of",
			 "  either the GNU General Public License Version 2 or later (the \"GPL\"), or",
			 "  the GNU Lesser General Public License Version 2.1 or later (the \"LGPL\"),",
			 "  in which case the provisions of the GPL or the LGPL are applicable instead",
			 "  of those above. If you wish to allow use of your version of this file only",
			 "  under the terms of either the GPL or the LGPL, and not to allow others to",
			 "  use your version of this file under the terms of the MPL, indicate your",
			 "  decision by deleting the provisions above and replace them with the notice",
			 "  and other provisions required by the GPL or the LGPL. If you do not delete",
			 "  the provisions above, a recipient may use your version of this file under",
			 "  the terms of any one of the MPL, the GPL or the LGPL.",
			 " ",
			 "  ***** END LICENSE BLOCK ****"
	].map(function(x) { return prefix + x }).join("\n");
    return s;
}

// Undefine all names that are going to be defined so that predefined values
// do not pollute the results.

function undefDefines(feature) {
	var s = [];
	var d;
	for each ( d in feature.defines )
		s.push("#undef " + d);
	return s.join("\n") + "\n";
}

// Emit a description and a test of definedness and correct value for every feature;
// the description is located with this test because it will typically be this test
// that fails, so this is where the user will look.

function testDefined(feature) {
    var name = feature.name;
    var s = [];

    if (!name)
        fail("Feature with missing name");

    if (allnames.hasOwnProperty(name))
        fail("Duplicate name: " + name);
    allnames[name] = true;

	s.push("");
	s.push("");
	s.push("/* " + name + "\n *\n" + formatFeature(feature) + "\n */");
    s.push("#if !defined " + name + " || " + name + " != 0 && " + name + " != 1");
    s.push("#  error \"" + name + " must be defined and 0 or 1 (only).\"");
    s.push("#endif");
    return s.join("\n") + "\n";
}

function formatFeature(feature) {
	return feature.desc.toString().replace(/^[ \t]*/gm, " * ");
}

function checkRequirements(feature) {
    var name = feature.name;
    var requires = feature.requires;
    var precludes = feature.precludes;
    var s = [];
	var items;
	
    if (requires.length() + precludes.length() > 0)
        s.push("#if " + name);

	for each ( var req in requires ) {
		if ((items = req["at-most-one"]).length() > 0)
			s.push(atMostOne(items));
		else if ((items = req["at-least-one"]).length() > 0)
			s.push(atLeastOne(items));
		else if ((items = req["exactly-one"]).length() > 0)
			s.push(exactlyOne(items));
		else {
			if (!allnames.hasOwnProperty(req))
				fail("Name used in REQUIRES not defined: " + req);
			s.push("#  if !" + req);
			s.push("#    error \"" + req + " is required for " + name + "\"");
			s.push("#  endif");
		}
	}

	for each ( var pre in precludes ) {
		if (!allnames.hasOwnProperty(pre))
			fail("Name used in PRECLUDES not defined: " + pre);
		s.push("#  if " + pre);
		s.push("#    error \"" + pre + " is precluded for " + name + "\"");
		s.push("#  endif");
	}
	
    if (requires.length() + precludes.length() > 0)
        s.push("#endif");
    return s.join("\n") + "\n";
}

function defineResults(feature) {
    var name = feature.name;
    var defines = feature.defines;
    var s = [];

    if (!defines)
        fail(name + ": missing 'defines' clause");

    for each ( var def in defines ) {
        s.push("#if " + name);
        s.push("#  define " + def);
        s.push("#endif");
    }
    return s.join("\n") + "\n";
}

function showFeature(feature) {
    return ("  #if " + feature.name + "\n" +
            "    \"" + feature.name + ";\"\n" +
            "  #endif\n");
}

// We ignore AVMSYSTEM_ settings as they're always autodetected

function configureFeature(feature) {
	// Public service: if a feature is exclusive with others, disable the others 
	// if the one is set
    function complement(feature_name, candidates) {
        var res = "";
		for each (var x in candidates) {
            var mustDo = false;
            var s = "";
		    for each (var n in x.name) {
		        if (n == feature_name)
				    mustDo = true;
				else
					s += "-D" + n + "=0 ";
			}
			if (mustDo)
			   res += s;
        }
		return res;
    }

    if (feature.name.indexOf("AVMFEATURE_") == 0) {
	    var f = "-D" + feature.name + "=1 ";
		f += complement(feature.name, FEATURES["at-most-one"]);
		f += complement(feature.name, FEATURES["exactly-one"]);
        return ("    if o.getBoolArg(\"" + feature.name.substring(11).toLowerCase().replace("_","-") + "\"):\n" +
		        "        args += \"" + f + "\"\n");
    }
    return "";
}

function groupConstraint(x, tagname, condition, english_condition) {
    var names = [];
    for each ( var name in x.name ) {
        if (!allnames.hasOwnProperty(name))
            fail("Name used in \"" + tagname + "\" not defined: " + name);
        names.push(name);
    }
    return "#if " + names.join("+") + " " + condition + " 1\n#  error \"" + english_condition + " one of " + names.join(",") + " must be defined.\"\n#endif\n";
}

function atLeastOne(x) {
    return groupConstraint(x, "at-least-one", "<", "At least");
}

function atMostOne(x) {
	return groupConstraint(x, "at-most-one", ">", "At most");
}

function exactlyOne(x) {
	return groupConstraint(x, "exactly-one", "!=", "Exactly");
}

function fail(msg) {
    print("Error: " + msg);
    System.exit(1);
}
