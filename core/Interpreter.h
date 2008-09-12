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
	/**
	 * interp32/N() is the main loop of the AVM+ interpreter.
	 *
	 * The native code compiler CodegenMIR is used by default
	 * for executing AVM+ bytecode, since it is faster by
	 * nature, but the AVM+ interpreter is used in some cases:
	 *
	 * - It is used to execute AVM+ code when the turbo flag is
	 *   set to false (-Dinterp in command-line shell)
	 * - It is also used when a debug session is in progress.
	 * - It is used when the target platform does not support
	 *   the native code compiler.
	 *
	 * @param methodEnv   The method to execute.
	 * @param argc number of args
	 * @param ap arg list
	 * @return The return value of the method that was executed.
	 * @throws Exception if the method throws an exception.
	 */
	Atom interp32(MethodEnv* method, int argc, uint32 *ap);
	double interpN(MethodEnv* method, int argc, uint32 *ap);
#ifdef AVMPLUS_DIRECT_THREADED
	void** interpGetOpcodeLabels();
#endif
#ifdef SUPERWORD_PROFILING
	void swprofStart();
	void swprofStop();
#endif
	
}

// FIXME: these should be defined in opcodes.tbl.
// Note that eg utils/peephole.as knows about these values.

#ifdef AVMPLUS_WORD_CODE

#  define OP_ext 0xFF                                  // Reserved in opcodes.tbl as the extension prefix for superwords

#  define OP_ext_pushbits           ((1<<8) | OP_ext)  // pushint, pushuint, pushshort, pushbyte
#  define OP_ext_push_doublebits    ((2<<8) | OP_ext)  // pushint, pushuint if value is outside atom range
#  define OP_ext_get2locals         ((3<<8) | OP_ext)  // this and all the following ones introduced by peephole optimization
#  define OP_ext_get3locals         ((4<<8) | OP_ext)
#  define OP_ext_get4locals         ((5<<8) | OP_ext)
#  define OP_ext_get5locals         ((6<<8) | OP_ext)
#  define OP_ext_storelocal         ((7<<8) | OP_ext)
#  define OP_ext_add_ll             ((8<<8) | OP_ext)
#  define OP_ext_add_set_lll        ((9<<8) | OP_ext)
#  define OP_ext_subtract_ll       ((10<<8) | OP_ext)
#  define OP_ext_multiply_ll       ((11<<8) | OP_ext)
#  define OP_ext_divide_ll         ((12<<8) | OP_ext)
#  define OP_ext_modulo_ll         ((13<<8) | OP_ext)
#  define OP_ext_bitand_ll         ((14<<8) | OP_ext)
#  define OP_ext_bitor_ll          ((15<<8) | OP_ext)
#  define OP_ext_bitxor_ll         ((16<<8) | OP_ext)
#  define OP_ext_add_lb            ((17<<8) | OP_ext)
#  define OP_ext_subtract_lb       ((18<<8) | OP_ext)
#  define OP_ext_multiply_lb       ((19<<8) | OP_ext)
#  define OP_ext_divide_lb         ((20<<8) | OP_ext)
#  define OP_ext_bitand_lb         ((21<<8) | OP_ext)
#  define OP_ext_bitor_lb          ((22<<8) | OP_ext)
#  define OP_ext_bitxor_lb         ((23<<8) | OP_ext)
#  define OP_ext_iflt_ll           ((24<<8) | OP_ext)
#  define OP_ext_ifnlt_ll          ((25<<8) | OP_ext)
#  define OP_ext_ifle_ll           ((26<<8) | OP_ext)
#  define OP_ext_ifnle_ll          ((27<<8) | OP_ext)
#  define OP_ext_ifgt_ll           ((28<<8) | OP_ext)
#  define OP_ext_ifngt_ll          ((29<<8) | OP_ext)
#  define OP_ext_ifge_ll           ((30<<8) | OP_ext)
#  define OP_ext_ifnge_ll          ((31<<8) | OP_ext)
#  define OP_ext_ifeq_ll           ((32<<8) | OP_ext)
#  define OP_ext_ifne_ll           ((33<<8) | OP_ext)
#  define OP_ext_ifstricteq_ll     ((34<<8) | OP_ext)
#  define OP_ext_ifstrictne_ll     ((35<<8) | OP_ext)
#  define OP_ext_iflt_lb           ((36<<8) | OP_ext)
#  define OP_ext_ifnlt_lb          ((37<<8) | OP_ext)
#  define OP_ext_ifle_lb           ((38<<8) | OP_ext)
#  define OP_ext_ifnle_lb          ((39<<8) | OP_ext)
#  define OP_ext_ifgt_lb           ((40<<8) | OP_ext)
#  define OP_ext_ifngt_lb          ((41<<8) | OP_ext)
#  define OP_ext_ifge_lb           ((42<<8) | OP_ext)
#  define OP_ext_ifnge_lb          ((43<<8) | OP_ext)
#  define OP_ext_ifeq_lb           ((44<<8) | OP_ext)
#  define OP_ext_ifne_lb           ((45<<8) | OP_ext)
#  define OP_ext_ifstricteq_lb     ((46<<8) | OP_ext)
#  define OP_ext_ifstrictne_lb     ((47<<8) | OP_ext)
#  define OP_ext_swap_pop          ((48<<8) | OP_ext)

#  define LAST_SUPERWORD_OPCODE    ((48<<8) | OP_ext)

#endif // AVMPLUS_WORD_CODE
#endif // __avmplus_Interpreter__
