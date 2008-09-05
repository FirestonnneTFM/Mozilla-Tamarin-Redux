/* -*- java-mode -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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

/* Generate peephole optimization state tables from a description.

     peepspec ::= peep*
     peep     ::= pattern guard? action
     pattern  ::= "pattern" ident (";" ident)* eol
     guard    ::= expr
     action   ::= expr (";" expr)
     expr     ::= token+
     token    ::= any C++ token valid in an expression
                | $integer.integer
     ident    ::= C++ identifier
     eol      ::= newline or end-of-file

   The idea is that the identifiers in the pattern are opcode values that
   are resolved at compile time and which drive the peephole optimizer
   state machine.  The guard is evaluated in case there are side conditions
   apart from the opcode values; it must be a C++ expression.  The action
   represents individual instruction words that replace the instructions
   matched by the pattern.

   The syntax $n.m refers to the m'th word of the n'th matched instruction.

   The guard will normally be evaluated zero or one times, but it would
   be good not to depend on that.

   For example (this one has only one instruction in the action)

     pattern  OP_getlocal ; OP_getlocal ; OP_getlocal
     guard    $0.1 < 1024 && $1.1 < 1024 && $2.1 < 1024
     action   OP_get2locals ; (($2.1 << 20) | ($1.1 << 10) | $0.1)

   Continuation lines are allowed, they start with '*' in the first column.

   Comment lines start with //.  Comment lines and blank lines are ignored
   everywhere before continuation lines are resolved.

   Restrictions:

   - The action cannot introduce more words than the instruction originally
     occupied  (it would not be hard to lift this restriction). 

   - Lookupswitch may not appear in these patterns

   - Any PC-relative branch instruction must be the last in the pattern as
     well as in the replacement code

 */
   
package peephole 
{
    import avmplus.*;

    class Pattern
    {
	var P, G, A;
	function Pattern(P, G, A) {
	    this.P = P;
	    this.G = G;
	    this.A = A;
	}
    }

    function assert(cond) {
        if (!cond)
            throw new Error("Assertion failed");
    }

    function cleanup(lines) {
	var j = 0;
	var first = true;
	for ( var i=0, limit=lines.length ; i < limit ; i++ ) {
	    if (/^\s*$/.test(lines[i]))
		continue;
	    if (/^\s*\/\//.test(lines[i]))
		continue;
	    assert(/^(\*|pattern\s+|guard\s+|action\s+)/.test(lines[i]));
	    if (lines[i].charAt(0) == '*') {
		assert(!first);
		lines[j] += lines[i].substring(1);
		continue;
	    }
	    lines[j++] = lines[i];
	    first = false;
	}
	lines.length = j;
	return lines;
    }

    function patterns(lines) {
	var output = [];
	var P = null;
	var G = null;
	var A = null;
	var res;
	for ( var i=0, limit=lines.length ; i < limit ; i++ ) {
	    var L = lines[i];
	    if (P == null) {
		res = /^pattern\s+(.*)$/.exec(L);
		assert(res != null);
		P = res[1].split(/\s*;\s*/);
		continue;
	    }

	    if (G == null) {
		res = /^guard\s+(.*)$/.exec(L);
		if (res != null) {
		    G = res[1];
		    continue;
		}
	    }

	    if (A == null) {
		res = /^action\s+(.*)$/.exec(L);
		assert(res != null);
		A = res[1].split(/\s*;\s*/);
	    }

	    assert( P != null && A != null );
	    output.push(new Pattern(P, G, A));
	    P = G = A = null;
	} 
	return output;
    }

    function printT(x) {
	var s = "{";
	for ( var i in x ) {
	    if (i == "toString") continue;
	    s += i + ": " + x[i] + ", ";
	}
	s += "}";
	return s;
    }

    function build(patterns) {
	var T = { toString: function () { return printT(this); } };
	for ( var i=0, ilimit=patterns.length ; i < ilimit ; i++ ) {
	    var p = patterns[i];
	    var container = T;
	    for ( var j=0, jlimit=p.P.length ; j < jlimit ; j++ ) {
		if (!(p.P[j] in container))
		    container[p.P[j]] = { toString: function () { return printT(this); } };
		container = container[p.P[j]];
	    }
	    if (!("actions" in container))
		container.actions = [];
	    container.actions.push(p);
	}
	return T;
    }

    function generate(toplevel) {
	var initial = [];
	for ( var n in toplevel ) {
	    if (n == "actions" || n == "toString")
		continue;
	    initial.push({name: n, state: expand(toplevel[n])});
	}
	return initial;
    }

    function display(container, sofar) {
	if (container.actions) {
	    var s = "";
	    for ( var p=sofar ; p != null ; p=p.next )
		s = s + p.name + " ";
	    print(s);
	}
	for (var n in container) {
	    if (n == "actions" || n == "toString")
		continue;
	    display(container[n], { name: n, next: sofar });
	}
    }

    if (System.argv.length != 2) {
        print("Usage: peephole inputfile outputfile");
        System.exit(1);
    }

    var T = build(patterns(cleanup(File.read(System.argv[0]).split("\n"))));
    print(String(T));
    display(T, null);
}
