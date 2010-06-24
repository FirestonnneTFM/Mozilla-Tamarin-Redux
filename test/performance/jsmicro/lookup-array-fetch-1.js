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

var DESC = "Check index prop present in array via operator[], compare to 'in'";

// Bugzilla 555982
// Keep all of following in sync:
// lookup-object-fetch-1.as, lookup-object-in-1.as,
//  lookup-array-fetch-1.as,  lookup-array-in-1.as
//
// The "object" variants are timing lookup on constructions via object literals;
// and "array" via array literals.
//
// The "in" variants are timing lookup via the in operator;
// and "fetch" via operator[] (yields undefined if key absent).

function fresh_store() {
    return [];
}

var entry_count = 100000;
var sparse_factor = 107;
function populate_dense(store) {
    for (var i = 0; i < entry_count; i++) {
        store[i] = "d.constant"
    }
    return store;
}

function populate_sparse(store) {
    for (var i = 0; i < entry_count*sparse_factor; i += sparse_factor) {
        store[i] = "s.constant"
    }
    return store;
}

function iterate_lookup(store) {
    var hits = 0;
    for (var i = 0; i < 5; i++) {
        for (var j = 0; j < 100000; j += 50) {
            if (store[j] !== undefined) {
                hits += 1;
            }
        }
    }
    return hits;
}

var D = fresh_store();
var S = fresh_store();

D = populate_dense(D);
S = populate_sparse(S);

function do_lookup_both() {
    iterate_lookup(D);
    iterate_lookup(S);
}
function do_lookup_dense() {
    iterate_lookup(D);
}
function do_lookup_sparse() {
    iterate_lookup(S);
}

TEST(do_lookup_both, "lookup-array-fetch-1");
// TEST(do_lookup_dense,  "lookup-array-fetch-1:dense");
// TEST(do_lookup_sparse, "lookup-array-fetch-1:sparse");
