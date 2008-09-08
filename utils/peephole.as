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

   Identifiers in the pattern must be opcode names; these are resolved at 
   compile time and the peephole optimizer state machine uses them to
   transition from one state to another.  The guard is evaluated in case 
   there are side conditions apart from the opcode values; the guard must 
   be a C++ expression.  The action represents individual instruction
   words that replace the instructions matched by the pattern; each word
   should be a C++ expression.

   The syntax $n.m refers to the m'th word of the n'th matched instruction.
   It can be used in the guard and action.

   The guard will be evaluated zero or one times per match.  (The current
   implementation only invokes a guard after longer matches have failed,
   so zero times is typical - you can't track state machine progress by
   having side effects in the guard.)

   For example (this one has only one instruction in the action):

     pattern  OP_getlocal ; OP_getlocal ; OP_getlocal
     guard    $0.1 < 1024 && $1.1 < 1024 && $2.1 < 1024
     action   OP_get3locals ; ($2.1 << 20) | ($1.1 << 10) | $0.1

   Continuation lines are allowed, they start with '*' in the first column.
   The continuation line, less its '*', is pasted onto the end of the
   preceding line.

   Comment lines start with // (possibly preceded by blanks).  Comment lines
   and blank lines are ignored everywhere before continuation lines are 
   resolved.  Comments can't follow patterns, guards, or actions on the 
   same line.

   Restrictions (not checked by this program):

   - The action cannot introduce more words than the instruction originally
     occupied  (it would not be hard to lift this restriction). 

   - Lookupswitch must not appear in these patterns.

   - Any PC-relative branch instruction must be the last in the pattern or
     in the replacement code.

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

    function preprocess(lines) {
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

    function parse(lines) {
	var output = [];
	var P = null;
	var G = null;
	var A = null;
	var res;
	for ( var i=0, limit=lines.length ; i < limit ; i++ ) {
	    var L = lines[i].replace(/\$([0-9]+)\.([0-9]+)/g, "I[$1][$2]");
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

    function build(patterns) {
	var T = {};
	for ( var i=0, ilimit=patterns.length ; i < ilimit ; i++ ) {
	    var p = patterns[i];
	    var container = T;
	    for ( var j=0, jlimit=p.P.length ; j < jlimit ; j++ ) {
		if (!(p.P[j] in container))
		    container[p.P[j]] = {};
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

    var T = build(parse(preprocess(File.read(System.argv[0]).split("\n"))));
    display(T, null);
}
