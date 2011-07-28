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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

#ifndef __avmplus_InvokerCompiler__
#define __avmplus_InvokerCompiler__

namespace avmplus
{
    using namespace nanojit;

    /**
     * compiles MethodEnv::coerceEnter, specialized for the method being
     * called, where the expected arg count and argument types are known.  This
     * allows all the arg coersion to be unrolled and specialized.
     *
     * Native methods and JIT methods are compiled in this way.  Interpreted
     * methods do not gain enough from compilation since the method bodies are
     * interpreted, and since arguments only need to be coerced, not unboxed.
     *
     * Compilation occurs on the second invocation.
     */
    class InvokerCompiler: public LirHelper {
    public:
        // true if we are able to compile an invoker for this method
        static bool canCompileInvoker(MethodInfo* info);

        // main compiler driver
        static AtomMethodProc compile(MethodInfo* info);

    private:
        // sets up compiler pipeline
        InvokerCompiler(MethodInfo*);

        // compiler front end; generates LIR
        void generate_lir();

        // compiler back end; generates native code from LIR
        void* assemble();

        // generates argc check
        void emit_argc_check(LIns* argc_param);

        // downcast and unbox (and optionally copy) each arg
        void downcast_args(LIns* env_param, LIns* argc_param, LIns* args_param);

        // downcast and unbox one arg
        void downcast_arg(int arg, int offset, LIns* env_param, LIns* args_param);

        // downcast and unbox the value for the given type.
        LIns* downcast_expr(LIns* val, Traits* t, LIns* env);

        // generate code to call the underlying method directly
        void call_method(LIns* env_param, LIns* argc_param);

        // is verbose-mode enabled?
        bool verbose();

        // should unmodified args be copied?  true if we are not coercing in-place
        bool copyArgs(); // true if un-modified args must be copied anyway

    private:
        MethodInfo* method;     // MethodInfo for method that we will call
        MethodSignaturep ms;    // the signature for same
        LIns* maxargs_br;       // branch that tests for too many args
        LIns* minargs_br;       // branch that tests for not enough args
        LIns* args_out;         // separate allocation for outgoing args (optional, NULL if unused)
    };
}
#endif /* __avmplus_InvokerCompiler__ */
