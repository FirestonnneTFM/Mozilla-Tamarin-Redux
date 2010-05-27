// See end of file for copyright notice and license terms.

These are javascript / ecmascript microbenchmarks, focusing narrowly
on the performance of language features.

Each test is available as an .as file (which includes the .js file) or
as an .html file (which also includes the .js file).  The former can
be compiled with ASC and run in the VM shell or -- we hope -- in the
Flash Player; the latter can be run in any web browser.

The .as and .html files also include common test drivers.

The .as and .html files are *generated* by generate-drivers.as, see
comments in the file for how to run it.  You only have to write the
.js file.

Each test should be in a separate file; only one result should be
reported per test.

Each test should be very specific; no attempt should be made to make
it "realistic" or to disable compiler optimizations by making results
appear to be used, other than by assigning the results to variables.
These tests are not real programs, they represent only themselves.

Under ABSOLUTELY NO CIRCUMSTANCES may any of the .js files use
non-ECMAScript idioms.  Stick to ECMAScript 3 until ES5 is implemented
in the major browsers.

As the AVM+ is incompatible with the ECMAScript spec in corner cases
(start at https://bugzilla.mozilla.org/show_bug.cgi?id=472863 and
drill down) the .js files should avoid tickling those
incompatibilities.

Brief description of benchmarks (eventually we want to extract these
from the DESC values of each benchmark but not all benchmarks have
DESC values yet):

alloc-1.js             Object allocation, one int property
alloc-2.js             Object allocation, five int properties
alloc-3.js             Object allocation, four int properties, one self-reference
alloc-4.js             Array allocation, one int property by initializer
alloc-5.js             Array allocation, ten int properties by initializer
alloc-6.js             simple String allocation, accumulating short/medium-length strings (~250 chars)
alloc-7.js             JS-style constructor function, one int property
alloc-8.js             Closure creation, no free variables
alloc-9.js             Closure creation, one free variable
alloc-10.js            Closure creation, deep environment and many free variables
alloc-11.js            Array allocation, ten int properties, but by assignment not initializer
alloc-12.js            Array allocation, ten int properties by assignment, not starting at 0
alloc-13.js            String allocation, accumulating medium/long-length strings (~2500 chars)
alloc-14.js            String allocation, accumulating long strings (~25000 chars)
array-1.js             Sequential reading of array
array-2.js             Sequential writing of array with non-pointer data
array-push-1.js        Array.prototype.push single value into array of length 0..9
array-pop-1.js         Array.prototype.pop from array of length 10..1
array-shift-1.js       Array.prototype.shift from array of length 10..1
array-slice-1.js       Array.prototype.slice a subarray of length 8 from an array of length 10
array-sort-1.js        Array.prototype.sort on arrays of length 10, integer values, default predicate
array-sort-2.js        Array.prototype.sort on arrays of length 1000, integer values (but may be boxed), default predicate
array-sort-3.js        Array.prototype.sort on arrays of length 1000, string values, default predicate
array-sort-4.js        Array.prototype.sort on arrays of length 1000, string values, custom predicate
array-unshift-1.js     Array.prototype.unshift single value into array of length 0..9
do-1.js                'do' loop, comparable to 'for-1' and 'while-1'.
for-1.js               'for' loop, comparable to 'do-1' and 'while-1'
for-2.js               'for' loop over Number values with int bound, update
for-3.js               'for' loop over Number values with Number bound, update
for-in-1.js            'for-in' loop over dense array
for-in-2.js            'for-in' loop but only every other element defined
funcall-1.js           Empty function call with no args
funcall-2.js           Empty function call with three args
funcall-3.js           Empty function call with three args to function expecting seven
funcall-4.js           Call with many arguments to a function referencing, but not touching, 'arguments'
isNaN-1.js             <global>.isNaN on Math.PI
number-toString-1.js   <type>.prototype.toString on 3.14159
number-toString-2.js   <type>.prototype.toString on 37
oop-1.js               Object-oriented programming using prototype methods
parseFloat-1.js        <global>.parseFloat on "3.14159"
parseInt-1.js          <global>.parseInt on "37"
string-casechange-1.js String.prototype.toUpperCase/toLowerCase on a string of 10 ASCII chars
string-casechange-2.js String.prototype.toUpperCase/toLowerCase on a string of 9 non-8-bit chars and one ASCII
string-charAt-1.js     String.prototype.charAt, characters are all ASCII
string-charAt-2.js     String.prototype.charAt, characters are all outside the 8-bit range
string-charCodeAt-1.js String.prototype.charCodeAt, characters are all ASCII
string-charCodeAt-2.js String.prototype.charCodeAt, characters are all outside the 8-bit range
string-fromCharCode-1.js  String.fromCharCode, one ASCII value
string-fromCharCode-2.js  String.fromCharCode, one non-8-bit value
string-indexOf-1.js    String.prototype.indexOf, finding character at the start of a string
string-indexOf-2.js    String.prototype.indexOf, finding character at the end of a long string
string-indexOf-3.js    String.prototype.indexOf, finding moderate substring at the end of a long string
string-lastIndexOf-1.js String.prototype.lastIndexOf, finding character at the end of a string
string-lastIndexOf-2.js String.prototype.lastIndexOf, finding character at the beginning of a long string
string-lastIndexOf-3.js String.prototype.lastIndexOf, finding moderate substring at the beginning of a long string
string-slice-1.js      String.prototype.slice a substring of length 8 from an string of length 10
string-split-1.js      String.prototype.split a string into 10 pieces, single character separator
string-split-2.js      String.prototype.split a string into 10 pieces, multi-character separator"
string-substring-1.js  String.prototype.substring a substring of length 8 from an string of length 10
switch-1.js            Switch on int value, keys
switch-2.js            Switch on char value, keys
switch-3.js            Switch on char value, string keys
try-1.js               'try-catch', no exceptions thrown
try-2.js               'try-catch', exception thrown
try-3.js               'try-catch-finally', return past 'finally'
while-1.js             'while' loop, comparable to 'do-1' and 'for-1'.


// What we need:

Operators of particular interest:

  - computation over arrays of numbers - well behaved but no static type information in the source
  - global-environment lookup, if we're able to isolate it
  - String comparison
  - "in"
  - "instanceof"

Important library functions first (and now we should test in AS3 mode
too), but eventually all of them.

  - new <builtin type>, for every type
  - Object.hasOwnProperty
  - Array.length access
  - Function.apply, call
  - Number.PI access, maybe others
  - Math.<all of them>
  - Date.toString, valueOf

// Marginal?

Array: "generic" array functions applied to other kinds of objects
E4X, compare with Firefox?
JS1.6, etc, compare with Firefox?


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
