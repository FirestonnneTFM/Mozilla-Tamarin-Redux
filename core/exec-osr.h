/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2007
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

#ifndef __avmplus_OSR__
#define __avmplus_OSR__

namespace avmplus
{
    /**
     * "On-Stack_Replacement" of interpreter methods with equivalent
     * JIT compiled versions.
     *
     * This is triggered at backwards branches when having looped "often enough"
     * to make amortization of the compilation effort likely.
     *
     * We don't actually *replace* the interpreter frame in question,
     * but simply stack an extra JIT frame on top of it
     * and return from both frames when the method returns.
     * But we call it OSR nevertheless, since that captures the general intent.
     */
    class OSR {
    private:
        static void unboxSlot(FrameState*, MethodEnv*,
                Atom* interpFramePtr, FramePtr jitFramePtr,
                uint8_t* jitFrameTags, int index);

        static bool countInvoke(MethodEnv*);

        // DATA SECTION

        const uint8_t* const osr_pc;        // ABC location of loop label.
        Atom *interp_frame;                 // Interpreter stack frame.
        class FrameState *jit_frame_state;  // FrameState at JIT loop label.

        // END DATA SECTION

    public:
        /** Create a new on-stack-replacement record. */
        OSR(const uint8_t* osr_pc, Atom* interp_frame);

        /** Save loop-entry frame state; called by JIT during compilation. */
        void setFrameState(FrameState* fs);

        const uint8_t* osrPc() const;

        /**
         * Parse an OSR configuration string, return the osr_threshold value,
         * or -1 if the string is invalid.
         */
        static int32_t parseConfig(const char *str);

        /** Return true if we can do OSR for this function, false otherwise. */
        static bool isSupported(const AbcEnv*, const MethodInfo*, MethodSignaturep);

        /** Called by the interpreter to trigger OSR. */
        static bool countEdge(const MethodEnv* env, MethodInfo* m, MethodSignaturep ms);

        /**
         * Called by the interpreter to perform OSR and continue execution in
         * JIT-compiled code.
         */
        static bool execute(MethodEnv *env, Atom *interp_frame,
                            MethodSignaturep ms, const uint8_t* osr_pc, Atom* result);

        /**
         * Called by OSR-instrumented JIT-generated code to test whether to
         * jump into a loop, and populate the JIT stack frame with values
         * from the interpreter stack frame.
         */
        static int32_t adjustFrame(MethodFrame*, CallStackNode*,
                FramePtr jitFramePointer, uint8_t *jitFrameTags);

        #ifdef DEBUG
        // Verify that currentBugCompatibility() is as OSR expected when method is called.
        static void checkBugCompatibility(MethodEnv* env);
        #endif

        // Trampolines, referenced by setInterp():
        static uintptr_t osrInterpGPR(MethodEnv* method, int argc, uint32_t *ap);
        static double osrInterpFPR(MethodEnv* method, int argc, uint32_t *ap);
#ifdef VMCFG_FLOAT
        static float4_t osrInterpVECR(MethodEnv* method, int argc, uint32_t *ap);
#endif
        static Atom osrInvokeInterp(MethodEnv* env, int32_t argc, Atom* argv);

        // Three more trampolines to handle the init variants:
        static uintptr_t osrInitInterpGPR(MethodEnv* method, int argc, uint32_t *ap);
        static double osrInitInterpFPR(MethodEnv* method, int argc, uint32_t *ap);
#ifdef VMCFG_FLOAT
        static float4_t osrInitInterpVECR(MethodEnv* method, int argc, uint32_t *ap);
#endif
        static Atom osrInitInvokeInterp(MethodEnv* env, int32_t argc, Atom* argv);
    };
}

#endif // __avmplus_OSR__
