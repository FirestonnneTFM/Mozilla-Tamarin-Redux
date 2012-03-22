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

#ifndef __avmplus_Interpreter__
#define __avmplus_Interpreter__

namespace avmplus
{
    // main interpreter method.  Signature should correspond to AtomMethodProc to allow tail
    // calls to here
    Atom interpBoxed(MethodEnv* method, int argc, Atom* ap);

    void** interpGetOpcodeLabels();

    /**
     * callback interface used by interpreter to set up deoptimized frame.
     */
    class FramePopulator {
    public:
        virtual void populate(Atom* framep, int *scope_depth, int *stack_depth) = 0;
        virtual ~FramePopulator() {}
    };

    /**
     * Interpret from the given location, initializing the Atom stack frame
     * from the given values.  This is called by Mason's speculation bailout
     * code in halfmoon.
     */
    Atom interpBoxedAtLocation(int abc_pc, Atom* locals, Atom* operand_stack,
                               Atom* scope_stack, int sp, int scope_height,
                               MethodEnv* env);

    /**
     * Interpreter entry point to begin execution of deoptimized frame.
     * Called by deoptimization trampolines, but not related to speculation
     * bailouts.
     */
    Atom interpBoxedAtLocation(MethodEnv* env, int abc_pc,
                               FramePopulator& populator);

}

//#  define LAST_SUPERWORD_OPCODE    ((50<<8) | OP_ext)

#endif // __avmplus_Interpreter__
