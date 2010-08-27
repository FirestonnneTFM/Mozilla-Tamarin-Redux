// See end of file for copyright notice and license terms.

These are actionscript microbenchmarks, focusing narrowly
on the performance of language features.

Each test is available as an .as file, which can be compiled with ASC.
The tests are meant to cover language features tested in ../jsmicro/
(or a superset thereof), but in an environment where:

  1. AS3 features such as type annotations can be included to improve
     measurement precision, and

  2. AS3 language/library features (and/or warts) can be tested and
     compared.  (This is the place to use non-ECMA-script idioms.)

Each test should be in a separate file; only one result should be
reported per test.

Each test in jsmicro/*.js should have an analogous .as file here;
this is the base test set.

There may be other files here that have no analogue in jsmicro; also,
since there may be different ways to type or otherwise port Javascript
to AS3, there can be >1 file for any one test in jsmicro.  Generally
though, most files in jsmicro should map to a single file with the
obvious type annotations.  (It is prudent to give additional files
with no correspondent in jsmicro fresh filename prefixes not appearing
in jsmicro.)

Type annotations are strictly optional, there's no compulsion to use
them.

NOTE that the default compilation mode when run with runtests.py is
-AS3 and that if public methods are meant to be accessed rather than
the AS3:: counterparts then compiler switch overrides must be
provided.

To see brief descriptions of the benchmarks, evaluate this:

  grep DESC *.as | sed -e 's/:[^"]*\"/ --- /g' -e 's/"[^"]*$//g'

or maybe even this:

  grep DESC *.as | \
    sed -e 's/:[^"]*\"/---/g' -e 's/"[^"]*$//g' | \
    awk -F--- \
      'BEGIN { max=0; k=0 } 
             { if (length($1) > max) max=length($1); f[k]=$1; d[k]=$2; k++ }
       END   { for ( i=0 ; i < k ; i++ ) 
                   print(sprintf("%-" (max+4) "s%s", f[i], d[i]))
             }'

To print all benchmarks missing a DESC definition (or confirm that
they all have one), evaluate this:

  for f in *-[0-9].as ; do if ! grep -q DESC $f; then echo $f; fi; done


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
