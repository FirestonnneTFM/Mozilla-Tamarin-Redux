// -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
// vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
//
// ***** BEGIN LICENSE BLOCK *****
// Version: MPL 1.1/GPL 2.0/LGPL 2.1
//
// The contents of this file are subject to the Mozilla Public License Version
// 1.1 (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
// http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
// for the specific language governing rights and limitations under the
// License.
//
// The Original Code is [Open Source Virtual Machine.].
//
// The Initial Developer of the Original Code is
// Adobe System Incorporated.
// Portions created by the Initial Developer are Copyright (C) 2004-2006
// the Initial Developer. All Rights Reserved.
//
// Contributor(s):
//   Adobe AS3 Team
//
// Alternatively, the contents of this file may be used under the terms of
// either the GNU General Public License Version 2 or later (the "GPL"), or
// the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
// in which case the provisions of the GPL or the LGPL are applicable instead
// of those above. If you wish to allow use of your version of this file only
// under the terms of either the GPL or the LGPL, and not to allow others to
// use your version of this file under the terms of the MPL, indicate your
// decision by deleting the provisions above and replace them with the notice
// and other provisions required by the GPL or the LGPL. If you do not delete
// the provisions above, a recipient may use your version of this file under
// the terms of any one of the MPL, the GPL or the LGPL.
//
// ***** END LICENSE BLOCK ***** */

// Bugzilla 637993: rehashing a GCHashtable in the midst of iteration
// is unsound; here we check that we are guarding against it.

%%component mmgc
%%category bugzilla_637993

%%decls

const static size_t elem_count = 1000;
int32_t *elems;
MMgc::GCHashtable m_table;

void add_first_half() {
    for (size_t i=0; i < elem_count/2; i++)
        m_table.put(&elems[i], &elems[i+1]);
}

void add_second_half() {
    for (size_t i=elem_count/2; i < elem_count; i++)
        m_table.put(&elems[i], &elems[i+1]);
}

%%test delete_during_iteration_okay_if_norehash
    elems = new int32_t[elem_count];
    add_first_half();
    {
        MMgc::GCHashtable::Iterator it(&m_table);
        while (it.nextKey()) {
            m_table.remove(it.value(), /*allowrehash=*/false);
        }
    }
    m_table.clear();
    delete elems;
    %%verify true
         ;

%%explicit delete_during_iteration_asserts_if_rehash
    elems = new int32_t[elem_count];
    add_first_half();
    {
        MMgc::GCHashtable::Iterator it(&m_table);
        while (it.nextKey()) {
            m_table.remove(it.value());
        }
    }
    m_table.clear();
    delete elems;
    %%verify false
         ;

// This test is a trivial success; it is meant to be compared against
// the cases that *fail* below, in order to make it clear what is
// wrong with the intentionally asserting cases.
%%test rehash_after_iteration_succeeds
    elems = new int32_t[elem_count];
    add_first_half();
    {
        MMgc::GCHashtable::Iterator it(&m_table);
        it.nextKey();
        it.nextKey();
    }
    add_second_half(); // rule satisfied; (Iterator is out of scope).
    m_table.clear();
    delete elems;
    %%verify true
         ;

  // (This test should definitely assert.)
%%explicit rehash_during_iteration_assert_fails_1
    elems = new int32_t[elem_count];
    add_first_half();
    {
        MMgc::GCHashtable::Iterator it(&m_table);
        it.nextKey();
        add_second_half(); // this is where we break the rule
        it.nextKey();
    }

    m_table.clear();
    delete elems;
    // we should never get here, the assertion should happen up above.
    %%verify false
          ;

// This test will assert even though the iteration is "done",
// because the rule is that we cannot modify the hashtable while
// any iterator is still "in scope"
%%explicit rehash_during_iteration_assert_fails_2
    elems = new int32_t[elem_count];
    add_first_half();
    {
        MMgc::GCHashtable::Iterator it(&m_table);
        it.nextKey();
        it.nextKey();
        add_second_half(); // this is where we break the rule
    }

    m_table.clear();
    delete elems;
    // we should never get here, the assertion should happen up above.
    %%verify false
          ;
