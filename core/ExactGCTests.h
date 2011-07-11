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

// Test cases for the exact-gc tracer generator script.
//
// The file is compiled and compilation errors will be signaled for various kinds of
// problems.  Additionally, visual inspection of the generated tracing code is recommended.
// That is not ideal, but it's better than nothing.
//
// These tests are for corner cases / hard cases, not for mainstream cases - those
// are tested well enough by all the Tamarin and Flash Player code that's annotated

#ifndef __avmplus_exactgcTests__
#define __avmplus_exactgcTests__

namespace avmplus
{
#ifdef DEBUG
    // This class must never be instantiated.

    class GC_CPP_EXACT(ExactGCTest, ScriptObject)
    {
    public:
        ExactGCTest() : ScriptObject(NULL,NULL) {}

        GC_DATA_BEGIN(ExactGCTest)

        // Testing if, elif, else.  When compiling, we'll hit the third case, !CASE3NEG.
        // For more elaborate testing we could set up something that hits each of the arms
        // in separate compilations (or through multiple inclusions of this file with different
        // type names, maybe)

#if CASE1
        ScriptObject* GC_POINTER(case1_x);
        ScriptObject* GC_POINTER(case1_w);
        ScriptObject* GC_POINTER(case1_and_3_w);  // Reused below, too
#elif CASE2
        ScriptObject* GC_POINTER(case2_x);
        ScriptObject* GC_POINTER(case2_z);
#elif !CASE3NEG
        ScriptObject* GC_POINTER(case3_z);
        ScriptObject* GC_POINTER(case1_and_3_w);  // From above; we allow dupes in different arms of the switch
#else
        ScriptObject* GC_POINTER(else_r);
#endif

        GC_DATA_END(ExactGCTest)

        // These reference all the variables above, if ifdefs aren't emitted
        // correctly we should get a compilation error.
        
#if CASE1
        void someFunction() {
            case1_x = NULL;
            case1_w = NULL;
            case1_and_3_w = NULL;
        }
#elif CASE2
        void someFunction() {
            case2_x = NULL;
            case2_z = NULL;
        }
#elif !CASE3NEG
        void someFunction() {
            case3_z = NULL;
            case1_and_3_w = NULL;
        }
#else
        void someFunction() {
            else_r = NULL;
        }
#endif

        void someFunction2() {
            someFunction();     // Make sure at least one of them is defined
        }
    };
#endif
}

#endif // __avmplus_exactgcTests__
