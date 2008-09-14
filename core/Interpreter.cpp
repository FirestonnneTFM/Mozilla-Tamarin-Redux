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


#include "avmplus.h"

#ifdef AVMPLUS_MAC
#ifndef __GNUC__
// inline_max_total_size() defaults to 10000.
// This module includes so many inline functions that we
// exceed this limit and we start getting compile warnings,
// so bump up the limit for this file. 
#pragma inline_max_total_size(26576)
#endif
#endif

// The macro AVMPLUS_WORD_CODE is true if the representation of ABC code is as an array of words and
// not an array of bytes.

namespace avmplus
{	

#define IS_INTEGER(v)        (((v) & 7) == kIntegerType)
#define IS_DOUBLE(v)         (((v) & 7) == kDoubleType)
#define IS_BOOLEAN(v)        (((v) & 7) == kBooleanType)
#define IS_STRING(v)		 (((v) & 7) == kStringType)
#define FITS_IN_INTEGER(v)   ((((int32)v << 3) >> 3) == v)
#define MAKE_INTEGER(v)      (((v) << 3) | kIntegerType)
#define INTEGER_VALUE(v)     ((int32)(v) >> 3)
#define DOUBLE_VALUE(v)		 (*(double*)((v) ^ kDoubleType))
#define IS_BOTH_INTEGER(a,b) ((((a ^ kIntegerType) | (b ^ kIntegerType)) & 7) == 0) // less control flow but more registers -- which is better?
//#define IS_BOTH_INTEGER(a,b) ((IS_INTEGER(a) && IS_INTEGER(b))
#define IS_BOTH_DOUBLE(a,b)  ((((a & kDoubleType) | (b ^ kDoubleType)) & 7) == 0)
	
#ifndef AVMPLUS_WORD_CODE
	inline int readS24(const byte *pc) {
		return AvmCore::readS24(pc);
	}
	
	inline int readU30(const byte *&pc) {
		return AvmCore::readU30(pc);
	}
#endif

// Direct threading in the interpreter.
//
// If you have gcc, direct threading should work out of the box and
// should provide a nice speedup with many platforms and compiler versions.
//
// If you are using Microsoft Visual C/C++ then you may turn on direct 
// threading, and you must select one of the two threading implementations
// below.  MSVC_X86_ASM_THREADING should "just work" but is likely
// to be slower than switch dispatch, unless you're using a compiler
// version with little or no optimization.  MSVC_X86_REWRITE_THREADING
// usually improves the performance over switch dispatch, but requires
// a fair amount of manual work if core/Interpreter.cpp has been modified
// since core/FastInterpreter.asm was generated.  The specific work
// needed to regenerate core/FastInterpreter.cpp is described in a comment
// at the head of utils/x86rewrite.as, which you will need to run.

#ifdef AVMPLUS_DIRECT_THREADED
#  ifndef AVMPLUS_WORD_CODE
#    error "Need word code enabled for this"
#  endif
#  if defined __GNUC__
#    define GNUC_THREADING
#    define DIRECT_DISPATCH
#  elif defined AVMPLUS_WIN32
	 // Pick one of the two following options
//#    define MSVC_X86_ASM_THREADING
#    define MSVC_X86_REWRITE_THREADING
#    ifdef MSVC_X86_ASM_THREADING
#      define DIRECT_DISPATCH
#    endif
#    ifdef MSVC_X86_REWRITE_THREADING
#      define SWITCH_DISPATCH
#    endif
#  else
#    error "Threaded code not supported for this platform/compiler"
#  endif
#else
#  define SWITCH_DISPATCH
#endif // compiler/platform vipers' nest

	Atom interp(MethodEnv* method, int argc, uint32 *ap);
	Atom* initMultiname(MethodEnv* env, Multiname &name, Atom* sp, bool isDelete=false);
	Traits* getTraits(Multiname* name, PoolObject* pool, Toplevel* toplevel, AvmCore* core);
#ifdef SUPERWORD_PROFILING
	void swprofCode(const uint32* start, const uint32* limit);
	void swprofPC(const uint32* pc);
#endif
#ifdef AVMPLUS_VERBOSE
	
	/**
	 * display contents of current stack frame only.
	 */
	void showState(MethodInfo* info, const byte *code_start, const byte *pc,
							Atom* framep, Atom *spp, int scopeDepth, Atom *scopebasep,
							int max_scope);
#endif

	Atom interp32(MethodEnv* env, int argc, uint32 *ap)
	{
		Atom a = interp(env, argc, ap);
		Traits* t = env->method->returnTraits();
		AvmCore* core = env->core();
		if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
			return a;
		if (t == INT_TYPE)
			return AvmCore::integer_i(a);
		if (t == UINT_TYPE)
			return AvmCore::integer_u(a);
		if (t == BOOLEAN_TYPE)
			return a>>3;
		return a & ~7; // possibly null pointer
	}

	double interpN(MethodEnv* env, int argc, uint32 * ap)
	{
		Atom a = interp(env, argc, ap);
		return AvmCore::number_d(a);
	}

#ifdef _MSC_VER
#  pragma warning(disable:4102)    // unreferenced label
#  ifdef MSVC_X86_ASM_THREADING
#    pragma warning(disable:4740)  // "inline assembler suppresses global optimization"
#  endif
#endif // _MSC_VER

#ifdef AVMPLUS_DIRECT_THREADED

	void** interpGetOpcodeLabels() {
		return (void**)interp(NULL, 0, NULL);
	}
	
#endif // AVMPLUS_DIRECT_THREADED

    /**
     * Interpret the AVM+ instruction set.
     * @return
     */
    Atom interp(MethodEnv *env, int argc, uint32 *ap)
    {
#ifdef AVMPLUS_DIRECT_THREADED
		
		// If env is NULL return the jump table.  Optionally initialize it here on those
		// platforms where compile-time initialization is not possible or practical.
		
		if (env == NULL) {
#  if defined GNUC_THREADING
#      define III(idx, lbl) &&lbl,
#      define XXX(idx) &&L_illegal_op,
			static void* opcode_labels[] = {
#  elif defined MSVC_X86_ASM_THREADING || defined MSVC_X86_REWRITE_THREADING
	    static void* opcode_labels[OP_INDEX(LAST_SUPERWORD_OPCODE)+1];
        if (opcode_labels[0] == 0) {
#    define XXX(idx) III(idx, L_illegal_op)
#    ifdef MSVC_X86_ASM_THREADING
#        define III(idx, lbl) __asm { \
	           __asm mov eax, offset opcode_labels \
	  	       __asm mov ebx, offset lbl \
		       __asm mov [eax+4*idx], ebx \
		     }
#     else
		  extern bool LLLLABEL(int);
#         define III(a,b) extern void LLLLABEL ## _ ## a ## _ ## b(); LLLLABEL ## _ ## a ## _ ## b();
#     endif
#  endif // threading discipline
			 XXX(0x00)
#  if defined DEBUGGER || !defined AVMPLUS_WORD_CODE
			 III(0x01, L_bkpt)
#  else
			 XXX(0x01) /* OP_bkpt */
#  endif
			 XXX(0x02) /* OP_nop */
			 III(0x03, L_throw)
			 III(0x04, L_getsuper)
			 III(0x05, L_setsuper)
			 III(0x06, L_dxns)
			 III(0x07, L_dxnslate)
			 XXX(0x08) /* OP_kill */
			 XXX(0x09) /* OP_label */
			 XXX(0x0A)
			 XXX(0x0B)
			 III(0x0C, L_ifnlt)
			 III(0x0D, L_ifnle)
			 III(0x0E, L_ifngt)
			 III(0x0F, L_ifnge)
			 III(0x10, L_jump)
			 III(0x11, L_iftrue)
			 III(0x12, L_iffalse)
			 III(0x13, L_ifeq)
			 III(0x14, L_ifne)
			 III(0x15, L_iflt)
			 III(0x16, L_ifle)
			 III(0x17, L_ifgt)
			 III(0x18, L_ifge)
			 III(0x19, L_ifstricteq)
			 III(0x1A, L_ifstrictne)
			 III(0x1B, L_lookupswitch)
			 III(0x1C, L_pushwith)
			 III(0x1D, L_popscope)
			 III(0x1E, L_nextname)
			 III(0x1F, L_hasnext)
			 III(0x20, L_pushnull)
			 III(0x21, L_pushundefined)
			 XXX(0x22)
			 III(0x23, L_nextvalue)
			 XXX(0x24) /* OP_pushbyte */
			 XXX(0x25) /* OP_pushshort */
			 III(0x26, L_pushtrue)
			 III(0x27, L_pushfalse)
			 III(0x28, L_pushnan)
			 III(0x29, L_pop)
			 III(0x2A, L_dup)
			 III(0x2B, L_swap)
			 III(0x2C, L_pushstring)
			 XXX(0x2D) /* OP_pushint */
			 XXX(0x2E) /* OP_pushuint */
			 III(0x2F, L_pushdouble)
			 III(0x30, L_pushscope)
			 III(0x31, L_pushnamespace)
			 III(0x32, L_hasnext2)
			 XXX(0x33)
			 XXX(0x34)
			 XXX(0x35)
			 XXX(0x36)
			 XXX(0x37)
			 XXX(0x38)
			 XXX(0x39)
			 XXX(0x3A)
			 XXX(0x3B)
			 XXX(0x3C)
			 XXX(0x3D)
			 XXX(0x3E)
			 XXX(0x3F)
			 III(0x40, L_newfunction)
			 III(0x41, L_call)
			 III(0x42, L_construct)
			 III(0x43, L_callmethod)
			 III(0x44, L_callstatic)
			 III(0x45, L_callsuper)
			 III(0x46, L_callproperty)
			 III(0x47, L_returnvoid)
			 III(0x48, L_returnvalue)
			 III(0x49, L_constructsuper)
			 III(0x4A, L_constructprop)
			 XXX(0x4B) /* OP_callsuperid */
			 III(0x4C, L_callproplex)
			 XXX(0x4D) /* OP_callinterface */
			 III(0x4E, L_callsupervoid)
			 III(0x4F, L_callpropvoid)
			 XXX(0x50)
			 XXX(0x51)
			 XXX(0x52)
			 III(0x53, L_applytype)
			 XXX(0x54)
			 III(0x55, L_newobject)
			 III(0x56, L_newarray)
			 III(0x57, L_newactivation)
			 III(0x58, L_newclass)
			 III(0x59, L_getdescendants)
			 III(0x5A, L_newcatch)
			 XXX(0x5B)
			 XXX(0x5C)
			 III(0x5D, L_findpropstrict)
			 III(0x5E, L_findproperty)
			 III(0x5F, L_finddef)
			 III(0x60, L_getlex)
			 III(0x61, L_setproperty)
			 III(0x62, L_getlocal)
			 III(0x63, L_setlocal)
			 III(0x64, L_getglobalscope)
			 III(0x65, L_getscopeobject)
			 III(0x66, L_getproperty)
			 III(0x67, L_getouterscope)
			 III(0x68, L_initproperty)
			 XXX(0x69)
			 III(0x6A, L_deleteproperty)
			 XXX(0x6B)
			 III(0x6C, L_getslot)
			 III(0x6D, L_setslot)
			 III(0x6E, L_getglobalslot)
			 III(0x6F, L_setglobalslot)
			 III(0x70, L_convert_s)
			 III(0x71, L_esc_xelem)
			 III(0x72, L_esc_xattr)
			 III(0x73, L_convert_i)
			 III(0x74, L_convert_u)
			 III(0x75, L_convert_d)
			 III(0x76, L_convert_b)
			 III(0x77, L_convert_o)
			 III(0x78, L_checkfilter)
			 XXX(0x79)
			 XXX(0x7A)
			 XXX(0x7B)
			 XXX(0x7C)
			 XXX(0x7D)
			 XXX(0x7E)
			 XXX(0x7F)
			 III(0x80, L_coerce)
			 III(0x81, L_coerce_b)
			 XXX(0x82) /* OP_coerce_a */
			 III(0x83, L_coerce_i)
			 III(0x84, L_coerce_d)
			 III(0x85, L_coerce_s)
			 III(0x86, L_astype)
			 III(0x87, L_astypelate)
			 III(0x88, L_coerce_u)
			 III(0x89, L_coerce_o)
			 XXX(0x8A)
			 XXX(0x8B)
			 XXX(0x8C)
			 XXX(0x8D)
			 XXX(0x8E)
			 XXX(0x8F)
			 III(0x90, L_negate)
			 III(0x91, L_increment)
			 III(0x92, L_inclocal)
			 III(0x93, L_decrement)
			 III(0x94, L_declocal)
			 III(0x95, L_typeof)
			 III(0x96, L_not)
			 III(0x97, L_bitnot)
			 XXX(0x98)
			 XXX(0x99)
			 XXX(0x9A) /* OP_concat */
			 XXX(0x9B) /* OP_add_d */
			 XXX(0x9C)
			 XXX(0x9D)
			 XXX(0x9E)
			 XXX(0x9F)
			 III(0xA0, L_add)
			 III(0xA1, L_subtract)
			 III(0xA2, L_multiply)
			 III(0xA3, L_divide)
			 III(0xA4, L_modulo)
			 III(0xA5, L_lshift)
			 III(0xA6, L_rshift)
			 III(0xA7, L_urshift)
			 III(0xA8, L_bitand)
			 III(0xA9, L_bitor)
			 III(0xAA, L_bitxor)
			 III(0xAB, L_equals)
			 III(0xAC, L_strictequals)
			 III(0xAD, L_lessthan)
			 III(0xAE, L_lessequals)
			 III(0xAF, L_greaterthan)
			 III(0xB0, L_greaterequals)
			 III(0xB1, L_instanceof)
			 III(0xB2, L_istype)
			 III(0xB3, L_istypelate)
			 III(0xB4, L_in)
			 XXX(0xB5)
			 XXX(0xB6)
			 XXX(0xB7)
			 XXX(0xB8)
			 XXX(0xB9)
			 XXX(0xBA)
			 XXX(0xBB)
			 XXX(0xBC)
			 XXX(0xBD)
			 XXX(0xBE)
			 XXX(0xBF)
			 III(0xC0, L_increment_i)
			 III(0xC1, L_decrement_i)
			 III(0xC2, L_inclocal_i)
			 III(0xC3, L_declocal_i)
			 III(0xC4, L_negate_i)
			 III(0xC5, L_add_i)
			 III(0xC6, L_subtract_i)
			 III(0xC7, L_multiply_i)
			 XXX(0xC8)
			 XXX(0xC9)
			 XXX(0xCA)
			 XXX(0xCB)
			 XXX(0xCC)
			 XXX(0xCD)
			 XXX(0xCE)
			 XXX(0xCF)
			 III(0xD0, L_getlocal0)
			 III(0xD1, L_getlocal1)
			 III(0xD2, L_getlocal2)
			 III(0xD3, L_getlocal3)
			 III(0xD4, L_setlocal0)
			 III(0xD5, L_setlocal1)
			 III(0xD6, L_setlocal2)
			 III(0xD7, L_setlocal3)
			 XXX(0xD8)
			 XXX(0xD9)
			 XXX(0xDA)
			 XXX(0xDB)
			 XXX(0xDC)
			 XXX(0xDD)
			 XXX(0xDE)
			 XXX(0xDF)
			 XXX(0xE0)
			 XXX(0xE1)
			 XXX(0xE2)
			 XXX(0xE3)
			 XXX(0xE4)
			 XXX(0xE5)
			 XXX(0xE6)
			 XXX(0xE7)
			 XXX(0xE8)
			 XXX(0xE9)
			 XXX(0xEA)
			 XXX(0xEB)
			 XXX(0xEC)
			 XXX(0xED)
			 XXX(0xEE) /* OP_abs_jump */
#  if defined DEBUGGER || !defined AVMPLUS_WORD_CODE
			 III(0xEF, L_debug)
			 III(0xF0, L_debugline)
			 III(0xF1, L_debugfile)
			 III(0xF2, L_bkptline)
#  else
 			 XXX(0xEF) /* OP_debug */
			 XXX(0xF0) /* L_debugline */
			 XXX(0xF1) /* L_debugfile */
			 XXX(0xF2) /* L_bkptline */
#  endif
	 		 XXX(0xF3)  /* OP_timestamp */
			 XXX(0xF4)
			 XXX(0xF5)
			 XXX(0xF6)
			 XXX(0xF7)
			 XXX(0xF8)
			 XXX(0xF9)
			 XXX(0xFA)
			 XXX(0xFB)
			 XXX(0xFC)
			 XXX(0xFD)
			 XXX(0xFE)
			 XXX(0xFF)  /* OP_ext */
			 XXX(0x100)
			 III(0x101, L_ext_pushbits)
			 III(0x102, L_ext_push_doublebits)
#  ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			 III(0x103, L_ext_get2locals)
			 III(0x104, L_ext_get3locals)
 			 III(0x105, L_ext_get4locals)
			 III(0x106, L_ext_get5locals)
			 III(0x107, L_ext_storelocal)
			 III(0x108, L_ext_add_ll)
			 III(0x109, L_ext_add_set_lll)
			 III(0x10A, L_ext_subtract_ll)
			 III(0x10B, L_ext_multiply_ll)
			 III(0x10C, L_ext_divide_ll)
			 III(0x10D, L_ext_modulo_ll)
			 III(0x10E, L_ext_bitand_ll)
			 III(0x10F, L_ext_bitor_ll)
			 III(0x110, L_ext_bitxor_ll)
			 III(0x111, L_ext_add_lb)
			 III(0x112, L_ext_subtract_lb)
			 III(0x113, L_ext_multiply_lb)
			 III(0x114, L_ext_divide_lb)
			 III(0x115, L_ext_bitand_lb)
			 III(0x116, L_ext_bitor_lb)
			 III(0x117, L_ext_bitxor_lb)
			 III(0x118, L_ext_iflt_ll)
			 III(0x119, L_ext_ifnlt_ll)
			 III(0x11A, L_ext_ifle_ll)
			 III(0x11B, L_ext_ifnle_ll)
			 III(0x11C, L_ext_ifgt_ll)
			 III(0x11D, L_ext_ifngt_ll)
			 III(0x11E, L_ext_ifge_ll)
			 III(0x11F, L_ext_ifnge_ll)
			 III(0x120, L_ext_ifeq_ll)
			 III(0x121, L_ext_ifne_ll)
			 III(0x122, L_ext_ifstricteq_ll)
			 III(0x123, L_ext_ifstrictne_ll)
			 III(0x124, L_ext_iflt_lb)
			 III(0x125, L_ext_ifnlt_lb)
			 III(0x126, L_ext_ifle_lb)
			 III(0x127, L_ext_ifnle_lb)
			 III(0x128, L_ext_ifgt_lb)
			 III(0x129, L_ext_ifngt_lb)
			 III(0x12A, L_ext_ifge_lb)
			 III(0x12B, L_ext_ifnge_lb)
			 III(0x12C, L_ext_ifeq_lb)
			 III(0x12D, L_ext_ifne_lb)
			 III(0x12E, L_ext_ifstricteq_lb)
			 III(0x12F, L_ext_ifstrictne_lb)
			 III(0x130, L_ext_swap_pop)
#  endif // AVMPLUS_PEEPHOLE_OPTIMIZER
#  if defined GNUC_THREADING
			};
			AvmAssert(opcode_labels[0x18] == &&L_ifge);
			AvmAssert(opcode_labels[0x97] == &&L_bitnot);
			AvmAssert(opcode_labels[257] == &&L_ext_pushbits);
#    ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			AvmAssert(opcode_labels[48 + 256] == &&L_ext_swap_pop);
#    endif
#  elif defined MSVC_X86_ASM_THREADING || defined MSVC_X86_REWRITE_THREADING
			} // conditional run-time initialization of jump table
#  endif // threading discipline
		return (Atom)opcode_labels;
		} // env == 0?
		
#endif  // !AVMPLUS_DIRECT_THREADED

		MethodInfo* info = (MethodInfo*)(AbstractFunction*) env->method;
		AvmCore *core = info->core();

		if (core->minstack)
		{
			// Take the address of a local variable to get
			// stack pointer
			uintptr sp = (uintptr)&core;
			if (sp < core->minstack)
			{
				env->vtable->traits->core->stackOverflow(env);
			}
		}

		#ifdef AVMPLUS_VERBOSE
		if (info->pool->verbose)
			core->console << "interp " << info << '\n';
		#endif

#ifdef AVMPLUS_WORD_CODE
		const uint32* pos = info->word_code.body_pos;
		const uint32* volatile code_start = pos;
		int max_stack = info->word_code.max_stack;
		int local_count = info->word_code.local_count;
		int init_scope_depth = info->word_code.init_scope_depth;
		int max_scope_depth = info->word_code.max_scope_depth;
#  ifdef SUPERWORD_PROFILING
#    ifdef AVMPLUS_DIRECT_THREADED
#       error "Superword profiling requires switch dispatch"
#    endif
		if (!info->word_code.dumped) {
			swprofCode(pos, info->word_code.body_end);
			info->word_code.dumped = true;
		}
#  endif
#else // !AVMPLUS_WORD_CODE
		const byte* pos = info->body_pos;
		int max_stack = AvmCore::readU30(pos);
		int local_count = AvmCore::readU30(pos);
		int init_scope_depth = AvmCore::readU30(pos);
		int max_scope_depth = AvmCore::readU30(pos);
		AvmCore::readU30(pos); // code_length
		const byte * volatile code_start = pos;
#endif // AVMPLUS_WORD_CODE
		int volatile max_scope = MethodInfo::maxScopeDepth(info, max_scope_depth - init_scope_depth);

		// these should have been checked in AbcParser
		AvmAssert(local_count+max_scope+max_stack > 0);
		Atom* framep = (Atom*)alloca(sizeof(Atom)*(local_count + max_scope + max_stack));
		Atom* scopeBase = framep + local_count;
		Atom* withBase = NULL;

		#ifdef DEBUGGER
		CallStackNode callStackNode(env, info, framep, 0, argc, ap, 0 /* later changed to 'pc' */);
		// don't allow entry into the debugger until we have setup the frame
#endif

		CodeContextAtom savedCodeContext = core->codeContextAtom;
		if (info->pool->domain->base != NULL) {
			core->codeContextAtom = (CodeContextAtom)env | CONTEXT_ENV;
		}

		Atom* atomv = (Atom*)ap;
		info->boxArgs(argc, ap, atomv);

		// 1. copy instance and args to local frame
		for (int i=0, n = argc < info->param_count ? argc : info->param_count; i <= n; i++)
		{
			framep[i] = atomv[i];
		}

		// Store original value of argc for createRest and createArguments.
		// argc may be changed by the optional parameter check below.
		int arguments_argc = argc;

		// set optional param values.  these not aliased to arguments[] since arguments[]
		// only present with traditional prototype functions (no optional args)
		if (info->flags & AbstractFunction::HAS_OPTIONAL)
		{
			if (argc < info->param_count)
			{
				// initialize default values
				for (int i=argc+1, o=argc + info->optional_count - info->param_count, n=info->param_count; i <= n; i++, o++)
				{
					framep[i] = info->getDefaultValue(o);
				}
				argc = info->param_count;
			}
		}

		// 4. set remaining locals to undefined.  Don't have to init scope or stack because
		// our conservative GC scan knows how to ignore garbage.
		for (Atom *p = framep + 1 + info->param_count; p < scopeBase; p++)
		{
			*p = undefinedAtom;
		}

		Toplevel *const toplevel = env->toplevel();

		// 2. capture arguments or rest array.
		if (info->flags & AbstractFunction::NEED_REST)
		{
			framep[info->param_count+1] = env->createRest(atomv,arguments_argc)->atom();
		}
		else if (info->flags & AbstractFunction::NEED_ARGUMENTS)
		{
			// create arguments using atomv[1..argc].
			// Even tho E3 says create an Object, E4 says create an Array so thats what we will do.
			framep[info->param_count+1] = env->createArguments(atomv, arguments_argc)->atom();
		}
		
		// 3. create the activation object, if necessary

		// init the scope chain by copying it from the captured scope
		ScopeChain* scope = env->vtable->scope;
		Namespace *dxns = scope->defaultXmlNamespace;
		Namespace **dxnsAddr;
		Namespace *const*dxnsAddrSave = NULL;

		if(info->setsDxns()) {
			dxnsAddrSave = core->dxnsAddr;
			dxnsAddr = &dxns;
		} else {
			dxnsAddr = scope->getDefaultNamespaceAddr();
		}

		int outer_depth = scope->getSize();
		int scopeDepth = 0;
	
		// make sure scope chain depth is right before entering.
		volatile int initialScopeDepth = scopeDepth;

		PoolObject *pool = info->pool;
		const List<Stringp>& cpool_string = pool->cpool_string;
#ifndef AVMPLUS_WORD_CODE
        const List<int>& cpool_int = pool->cpool_int;
        const List<uint32>& cpool_uint = pool->cpool_uint;
#endif // !AVMPLUS_WORD_CODE
        const List<double*, LIST_GCObjects>& cpool_double = pool->cpool_double;
		const List<Namespace*>& cpool_ns = pool->cpool_ns;

		Atom *sp = scopeBase + max_scope - 1;

		#ifdef DEBUGGER
		Debugger* debugger = core->debugger;
		if (core->callStack)
			core->callStack->framep = framep;

		// notify the debugger that we are entering a new frame.
		env->debugEnter(argc, ap, NULL, local_count, NULL, framep, 0);  // call it but make sure that callStackNode is not re-init'd
		#endif

#ifdef AVMPLUS_WORD_CODE
		const uint32* pc = code_start;
#else
		const byte* pc = code_start;
#endif
		sintptr volatile expc=0;

		#ifdef DEBUGGER
		callStackNode.eip = &expc;
		callStackNode.scopeDepth = &scopeDepth;
		#endif

		// Mask that can be XOR'd to flip a boolean atom
		const int booleanNotMask  = trueAtom^falseAtom;

		// whether this sequence is interruptable or not.
		bool interruptable = (info->flags & AbstractFunction::NON_INTERRUPTABLE) ? false : true;

		core->branchCheck(env, interruptable, -1);

		// in case a callee modified core->dxnsAddr, restore it
		#define restore_dxns() core->dxnsAddr = dxnsAddr

		// when we're leaving this call frame
		#define restore_caller_dxns() if(info->setsDxns()) core->dxnsAddr = dxnsAddrSave

		// NEXT dispatches the next instruction.
		//
		// U30ARG picks up a variable-length unsigned integer argument from the instruction
		// stream and advances the PC.
		//
		// U8ARG picks up a fixed-length unsigned byte argument from the instruction stream
		// and advances the PC.
		//
		// S24ARG picks up a fixed-length signed integer argument from the instruction stream
		// and advances the PC.
		//
		// SAVE_EXPC and variants saves the address of the current opcode in the local 'expc'.
		// Used in the case of exceptions.

#ifdef AVMPLUS_WORD_CODE

#  if defined AVMPLUS_DIRECT_THREADED
#    if defined GNUC_THREADING
#      define INSTR(op)       L_##op:
#      define NEXT            goto *(*pc++)
#    elif defined MSVC_X86_REWRITE_THREADING
#      define INSTR(op)       case OP_##op: L_ ## op: 
#      define NEXT            continue
#    elif defined MSVC_X86_ASM_THREADING
#      define INSTR(op)       L_ ## op: 
#      define NEXT __asm { \
				__asm mov ebx, pc \
				__asm mov eax, [ebx] \
				__asm add ebx, 4 \
				__asm mov pc, ebx \
				__asm jmp eax \
		   }
#    endif // threading discipline
#  else // AVMPLUS_DIRECT_THREADED
#    define INSTR(op)       case OP_##op:
#    define NEXT            continue
#  endif
		
#  define U30ARG          (*pc++)
#  define U8ARG           (*pc++)
#  define S24ARG          (int32)(*pc++)
#  define SAVE_EXPC       expc = pc-1-code_start
#  define SAVE_EXPC_U30   expc = pc-2-code_start  // only defined for word code
#  define SAVE_EXPC_S24   expc = pc-2-code_start

#else // !AVMPLUS_WORD_CODE

#  if defined AVMPLUS_VERBOSE
#    define INSTR(op) case OP_##op: \
                        if (pool->verbose) {\
							showState(info, code_start, pc-1,  framep, sp, scopeDepth, scopeBase, max_scope); \
						}
#  else
#    define INSTR(op) case OP_##op:
#  endif

#  define NEXT            continue
#  define U30ARG          (readU30(pc))
#  define U8ARG           (*pc++)
#  define S24ARG          (pc+=3, readS24(pc-3))
#  define SAVE_EXPC	      expc = pc-1-code_start
#  define SAVE_EXPC_S24   expc = pc-4-code_start

#endif // AVMPLUS_WORD_CODE
		
	MainLoop:
#ifdef AVMPLUS_WORD_CODE
		TRY_UNLESS(core, !info->word_code.exceptions, kCatchAction_SearchForActionScriptExceptionHandler) {
#else
		TRY_UNLESS(core, !info->exceptions, kCatchAction_SearchForActionScriptExceptionHandler) {
#endif
		
		restore_dxns();
		
		// the verifier ensures we don't fall off the end of a method.  so
		// we dont have to check the end pointer here.
#if defined DIRECT_DISPATCH

		NEXT;

#endif // DIRECT_DISPATCH

#if defined SWITCH_DISPATCH

		for (;;)
        {
#  if defined SUPERWORD_PROFILING
			swprofPC(pc);
#  endif
#  if defined AVMPLUS_WORD_CODE
			// See comments around INSTR(ext) below.
			AvmAssert((*pc & 65535) == ((*pc >> 16) & 65535));
			switch ((*pc++) & 255)
#  else
            switch (*pc++)
#  endif // AVMPLUS_WORD_CODE && !AVMPLUS_DIRECT_THREADING
            {

#endif // SWITCH_DISPATCH

#define RETURN_IMPL(val) \
	SAVE_EXPC; \
	core->codeContextAtom = savedCodeContext; \
	tempAtom = toplevel->coerce(val, info->returnTraits()); \
	restore_caller_dxns();

			INSTR(returnvoid) {
				Atom tempAtom;
#ifdef DEBUGGER
				env->debugExit(&callStackNode);
#endif				
				RETURN_IMPL(undefinedAtom);
#ifdef AVMPLUS_VERBOSE
				if (pool->verbose)
					core->console << "exit " << info << '\n';
#endif
				return tempAtom;
			}

            INSTR(returnvalue) {
				Atom tempAtom;
#ifdef DEBUGGER
				env->debugExit(&callStackNode);
#endif				
				RETURN_IMPL(*sp);
#ifdef AVMPLUS_VERBOSE
				if (pool->verbose)
					core->console << "exit " << info << '\n';
#endif
				return tempAtom;
			}

#ifndef AVMPLUS_WORD_CODE
            INSTR(nop) {
                NEXT;
			}
#endif
					
#ifndef AVMPLUS_WORD_CODE
            INSTR(label) {
                NEXT;
			}
#endif

#ifndef AVMPLUS_WORD_CODE
			INSTR(timestamp) {
                NEXT;
			}
#endif

#ifndef AVMPLUS_WORD_CODE
			INSTR(coerce_a) { // no-op since interpreter only uses atoms
                NEXT;
			}
#endif

#if defined DEBUGGER || !defined AVMPLUS_WORD_CODE
			INSTR(bkpt) {
				SAVE_EXPC;
#  ifdef DEBUGGER
				if (debugger)
					debugger->enterDebugger();
#  endif
				restore_dxns();
				NEXT;
			}
#endif
					
#if defined DEBUGGER || !defined AVMPLUS_WORD_CODE
			INSTR(debugline) {
				SAVE_EXPC;
				int line = U30ARG;
#  ifdef DEBUGGER
				if (debugger)
					debugger->debugLine(line);
#  else
				(void)line;
#  endif
				restore_dxns();
				NEXT;
			}
#endif
					
#if defined DEBUGGER || !defined AVMPLUS_WORD_CODE
			INSTR(bkptline) {
				SAVE_EXPC;
				int line = U30ARG;
#  ifdef DEBUGGER
				if (debugger)
				{
					debugger->debugLine(line);
					debugger->enterDebugger();
				}
#  else
				(void)line;
#  endif
				restore_dxns();
				NEXT;
			}
#endif
					
#if defined DEBUGGER || !defined AVMPLUS_WORD_CODE
			INSTR(debug) {
#  ifdef AVMPLUS_WORD_CODE
				pc += 4;
#  else
				pc += AvmCore::calculateInstructionWidth(pc-1) - 1;
#  endif
				NEXT;
			}
#endif

#if defined DEBUGGER || !defined AVMPLUS_WORD_CODE
			INSTR(debugfile) {
				SAVE_EXPC;
				int index = U30ARG;
#  ifdef DEBUGGER
				if (debugger)
					debugger->debugFile(pool->getString(index));
#  else
				(void)index;
#  endif
				restore_dxns();
				NEXT;
			}
#endif

			INSTR(jump) {
				int32 offset = S24ARG;
				if (offset < 0) {
					SAVE_EXPC_S24;
				    core->branchCheck(env, interruptable, offset);
					restore_dxns();
				}
				pc += offset;
                NEXT;
			}

            INSTR(pushnull) {
                *(++sp) = nullObjectAtom;
                NEXT;
			}

            INSTR(pushundefined) {
                *(++sp) = undefinedAtom;
                NEXT;
			}

            INSTR(pushstring) {
                *(++sp) = cpool_string[U30ARG]->atom();
                NEXT;
			}

#ifndef AVMPLUS_WORD_CODE
            INSTR(pushint) {
                *(++sp) = core->intToAtom(cpool_int[U30ARG]);
                NEXT;
			}
#endif
					
#ifndef AVMPLUS_WORD_CODE
            INSTR(pushuint) {
                *(++sp) = core->uintToAtom(cpool_uint[U30ARG]);
                NEXT;
			}
#endif
					
            INSTR(pushdouble) {
                *(++sp) = kDoubleType|(uintptr)cpool_double[U30ARG];
                NEXT;
			}

            INSTR(pushnamespace) {
                *(++sp) = cpool_ns[U30ARG]->atom();
                NEXT;
			}

            INSTR(getlocal) {
				*(++sp) = framep[U30ARG];
				NEXT;
			}

            INSTR(getlocal0) {
                *(++sp) = framep[0];
				NEXT;
			}

			INSTR(getlocal1) {
                *(++sp) = framep[1];
				NEXT;
			}
				
			INSTR(getlocal2) {
                *(++sp) = framep[2];
				NEXT;
			}

			INSTR(getlocal3) {
                *(++sp) = framep[3];
				NEXT;
			}

            INSTR(pushtrue) {
				*(++sp) = trueAtom;
                NEXT;
			}

            INSTR(pushfalse) {
                *(++sp) = falseAtom;
                NEXT;
			}

			INSTR(pushnan) {
				*(++sp) = core->kNaN;
				NEXT;
			}

            INSTR(pop) {
                sp--;
                NEXT;
			}

            INSTR(dup) {
				sp++;
				sp[0] = sp[-1];
                NEXT;
			}

            INSTR(swap) {
                Atom tempAtom = sp[0];
                sp[0] = sp[-1];
                sp[-1] = tempAtom;
                NEXT;
			}

            INSTR(convert_s) {
				if ((sp[0] & 7) != kStringType) {
					SAVE_EXPC;
				    sp[0] = core->string(sp[0])->atom();
					restore_dxns();
				}
                NEXT;
			}

			INSTR(esc_xelem) { // ToXMLString will call EscapeElementValue
				SAVE_EXPC;
				sp[0] = core->ToXMLString(sp[0])->atom();
				restore_dxns();
				NEXT;
			}

			INSTR(esc_xattr) {
				SAVE_EXPC;
				sp[0] = core->EscapeAttributeValue(sp[0])->atom();
				restore_dxns();
				NEXT;
			}

#define COERCE_D_IMPL() \
	if (!IS_DOUBLE(sp[0])) { \
		SAVE_EXPC; \
		sp[0] = core->numberAtom(sp[0]); \
		restore_dxns(); \
	}

            INSTR(coerce_d) {
				COERCE_D_IMPL();
				NEXT;
			}

            INSTR(convert_d) {
				COERCE_D_IMPL();
                NEXT;
			}

#define COERCE_B_IMPL() \
	Atom lhs = sp[0]; \
	if (IS_BOOLEAN(lhs)) \
		; \
	else if (IS_INTEGER(lhs)) \
		sp[0] = lhs == kIntegerType ? falseAtom : trueAtom; \
	else \
		sp[0] = core->booleanAtom(lhs);

            INSTR(convert_b) {
				COERCE_B_IMPL();
				NEXT;
			}

            INSTR(coerce_b) {
				COERCE_B_IMPL();
                NEXT;
			}

            INSTR(convert_o) {
				if (AvmCore::isNullOrUndefined(sp[0])) {
					SAVE_EXPC;
				    env->nullcheck(sp[0]);
				}
                NEXT;
			}

            INSTR(negate) {
				Atom val = sp[0];
				if (IS_INTEGER(val) && val != MAKE_INTEGER(0)) {
					int32 v = -(val >> 3);
					if (FITS_IN_INTEGER(v)) {
						sp[0] = MAKE_INTEGER(v);
						NEXT;
					}
				}
				SAVE_EXPC;
				sp[0] = core->doubleToAtom(-core->number(val));
				restore_dxns();
                NEXT;
			}

			INSTR(negate_i) {
				// OPTIMIZEME - negate_i
				SAVE_EXPC;
                sp[0] = core->intToAtom(-core->integer(sp[0]));
				restore_dxns();
                NEXT;
			}

#ifndef AVMPLUS_WORD_CODE
			INSTR(kill) {
				framep[U30ARG] = undefinedAtom;
				NEXT;
			}
#endif

            INSTR(typeof) {
				*sp = core->_typeof(*sp)->atom();
                NEXT;
			}

            INSTR(not) {
				Atom bval = sp[0];
				if (IS_BOOLEAN(bval))
					;
				else if (IS_INTEGER(bval))
					bval = bval == kIntegerType ? falseAtom : trueAtom;
				else
					bval = core->booleanAtom(bval);
                sp[0] = bval ^ booleanNotMask;
                NEXT;
			}

			INSTR(bitnot) {
				Atom val = sp[0];
				if (IS_INTEGER(val)) {
					sp[0] = ~val ^ 7;
					NEXT;
				}
				SAVE_EXPC;
				*sp = core->intToAtom(~core->integer(val));
				restore_dxns();
                NEXT;
			}

            INSTR(setlocal) {
                framep[U30ARG] = *(sp--);
                NEXT;
			}

            INSTR(setlocal0) {
                framep[0] = *(sp--);
				NEXT;
			}

            INSTR(setlocal1) {
                framep[1] = *(sp--);
				NEXT;
			}

            INSTR(setlocal2) {
                framep[2] = *(sp--);
				NEXT;
			}

            INSTR(setlocal3) {
                framep[3] = *(sp--);
                NEXT;
			}	

// Add lhs and rhs if they are both fixnums and computation does not overflow,
// or if they are both flonums.  On success, store the result in dest, and NEXT.

#define FAST_ADD_MAYBE(lhs,rhs,dest) \
	if (IS_BOTH_INTEGER(lhs, rhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType, rop = (uint32)rhs ^ kIntegerType; \
		uint32 result = lop + rop; \
		if ((int32)(lop ^ rop) < 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT; \
		} \
	} \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) + DOUBLE_VALUE(rhs)); \
		NEXT; \
	}

// Add 1 to lhs if it is a fixnum and computation does not overflow, or
// if lhs is a flonum.  On success, store the result in dest, and NEXT.
					
#define FAST_INC_MAYBE(lhs,dest) \
	if (IS_INTEGER(lhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType; \
		uint32 result = lop + (1 << 3); \
		if ((int32)lop < 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT; \
		} \
	} \
    else if (IS_DOUBLE(lhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) + 1.0); \
		NEXT; \
	}
					
// Subtract rhs from lhs if they are both fixnums and computation does not overflow.
// On success, store the result in dest, and NEXT.
#define FAST_SUB_MAYBE(lhs,rhs,dest) \
	if (IS_BOTH_INTEGER(lhs, rhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType, rop = (uint32)rhs ^ kIntegerType; \
		uint32 result = lop - rop; \
		if ((int32)(lop ^ rop) >= 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT; \
		} \
	} \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) + DOUBLE_VALUE(rhs)); \
		NEXT; \
	}

// Subtract 1 from lhs if lhs is a fixnum and computation does not overflow.
// On success, store the result in dest, and NEXT.
#define FAST_DEC_MAYBE(lhs,dest) \
	if (IS_INTEGER(lhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType; \
		uint32 result = lop - (1 << 3); \
		if ((int32)lop >= 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT; \
		} \
	} \
    else if (IS_DOUBLE(lhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) - 1.0); \
		NEXT; \
	}

#ifdef AVMPLUS_WORD_CODE
#  define WORD_CODE_ONLY(x)  x
#  define ABC_CODE_ONLY(x)   (void)0
#else
#  define WORD_CODE_ONLY(x)  (void)0
#  define ABC_CODE_ONLY(x)   x
#endif
					
			INSTR(increment) {
				Atom lhs = *sp;
				FAST_INC_MAYBE(lhs,sp[0]);
				SAVE_EXPC;
				*sp = core->numberAtom(lhs);
				core->increment_d(sp, 1);
				restore_dxns();
                NEXT;
			}

            INSTR(increment_i) {
				Atom lhs = *sp;
				FAST_INC_MAYBE(lhs,sp[0]);
				SAVE_EXPC;
				core->increment_i(sp, 1);
				restore_dxns();
                NEXT;
			}

			INSTR(inclocal) {
				ABC_CODE_ONLY( SAVE_EXPC );  // Because U30ARG prevents it from being done after FAST_INC_MAYBE.  
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_INC_MAYBE(lhs,*rp);
				WORD_CODE_ONLY( SAVE_EXPC_U30 );
				*rp = core->numberAtom(*rp);
				core->increment_d(rp, 1);
				restore_dxns();
				NEXT;
			}

            INSTR(inclocal_i) {
				ABC_CODE_ONLY( SAVE_EXPC );  // Because U30ARG prevents it from being done after FAST_INC_MAYBE.  
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_INC_MAYBE(lhs,*rp);
				WORD_CODE_ONLY( SAVE_EXPC_U30 );
				core->increment_i(rp, 1);
				restore_dxns();
				NEXT;
			}

            INSTR(decrement) {
				Atom lhs = *sp;
				FAST_DEC_MAYBE(lhs,sp[0]);
				SAVE_EXPC;
				*sp = core->numberAtom(*sp);
				core->increment_d(sp, -1);
				restore_dxns();
                NEXT;
			}

            INSTR(decrement_i) {
				Atom lhs = *sp;
				FAST_DEC_MAYBE(lhs,sp[0]);
				SAVE_EXPC;
				core->increment_i(sp, -1);
				restore_dxns();
                NEXT;
			}

			INSTR(declocal) {
				ABC_CODE_ONLY( SAVE_EXPC );  // Because U30ARG prevents it from being done after FAST_DEC_MAYBE.
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_DEC_MAYBE(lhs,*rp);
				WORD_CODE_ONLY( SAVE_EXPC_U30 );
				*rp = core->numberAtom(*rp);
				core->increment_d(rp, -1);
				restore_dxns();
				NEXT;
			}

			INSTR(declocal_i) {
				ABC_CODE_ONLY( SAVE_EXPC );  // Because U30ARG prevents it from being done after FAST_DEC_MAYBE.
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_DEC_MAYBE(lhs,*rp);
				WORD_CODE_ONLY( SAVE_EXPC_U30 );
				core->increment_i(rp, -1);
				restore_dxns();
                NEXT;
			}

#define ADD_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	FAST_ADD_MAYBE(lhs,rhs,dest); \
	SAVE_EXPC; \
	dest = toplevel->add2(lhs, rhs); \
	restore_dxns(); \
	NEXT
					
            INSTR(add) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				ADD_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

			INSTR(add_i) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_ADD_MAYBE(lhs,rhs,sp[0]);
				SAVE_EXPC;
				sp[0] = core->intToAtom(core->integer(lhs) + core->integer(rhs));
				restore_dxns();
                NEXT;
			}

#define SUB_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	FAST_SUB_MAYBE(lhs,rhs,dest); \
	SAVE_EXPC; \
	dest = core->doubleToAtom(core->number(lhs) - core->number(rhs)); \
	restore_dxns(); \
	NEXT
					
			INSTR(subtract) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				SUB_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

            INSTR(subtract_i) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_SUB_MAYBE(lhs,rhs,sp[0]);
				SAVE_EXPC;
				sp[0] = core->intToAtom(core->integer(lhs) - core->integer(lhs));
				restore_dxns();
                NEXT;
			}

// OPTIMIZEME - multiplication of small integers might be faster

#define MUL_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	if (IS_BOTH_DOUBLE(lhs, rhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) * DOUBLE_VALUE(rhs)); \
		NEXT; \
	} \
	SAVE_EXPC; \
	dest = core->doubleToAtom(core->number(lhs) * core->number(rhs)); \
	restore_dxns(); \
	NEXT
			
            INSTR(multiply) {
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				MUL_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

			INSTR(multiply_i) {
				// OPTIMIZEME - multiplication of small integers might be faster
				SAVE_EXPC;
                sp[-1] = core->intToAtom(core->integer(sp[-1]) * core->integer(sp[0]));
                sp--;
				restore_dxns();
                NEXT;
			}

// OPTIMIZEME - division of small integers might be faster, avoids boxing

#define DIV_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	if (IS_BOTH_DOUBLE(lhs, rhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) / DOUBLE_VALUE(rhs)); \
		NEXT; \
	} \
	SAVE_EXPC; \
	dest = core->doubleToAtom(core->number(lhs) / core->number(rhs)); \
	restore_dxns(); \
	NEXT

            INSTR(divide) {
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				DIV_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

// FIXME - dodgy optimization?
// Can the integer modulo overflow somehow?  Is it portable?
					
#define MOD_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	if (IS_BOTH_INTEGER(lhs, rhs) && rhs != kIntegerType) { \
		int result = (lhs >> 3) % (rhs >> 3); \
		if (FITS_IN_INTEGER(result)) { \
			dest = MAKE_INTEGER(result); \
			NEXT; \
		} \
	} \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) { \
		dest = core->doubleToAtom(MathUtils::mod(DOUBLE_VALUE(lhs), DOUBLE_VALUE(rhs))); \
		NEXT; \
	} \
	SAVE_EXPC; \
	dest = core->doubleToAtom(MathUtils::mod(core->number(lhs), core->number(rhs))); \
	restore_dxns(); \
	NEXT
			
            INSTR(modulo) {
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				MOD_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

#define LSHIFT_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	if (IS_BOTH_INTEGER(lhs,rhs)) { \
		int32 result = INTEGER_VALUE(lhs) << (INTEGER_VALUE(rhs) & 0x1F); \
		if (FITS_IN_INTEGER(result)) { \
			dest = MAKE_INTEGER(result); \
			NEXT; \
		} \
	} \
	SAVE_EXPC; \
	dest = core->intToAtom( core->integer(lhs) << (core->toUInt32(rhs)&0x1F) ); \
	restore_dxns(); \
	NEXT
			
            INSTR(lshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				LSHIFT_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

#define RSHIFT_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	if (IS_BOTH_INTEGER(lhs,rhs)) { \
		dest = MAKE_INTEGER(INTEGER_VALUE(lhs) >> (INTEGER_VALUE(rhs) & 0x1F)); \
		NEXT; \
	} \
	SAVE_EXPC; \
	dest = core->intToAtom( core->integer(lhs) >> (core->toUInt32(rhs)&0x1F) ); \
	restore_dxns(); \
	NEXT
			
            INSTR(rshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				RSHIFT_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

#define URSHIFT_TWO_VALUES_AND_NEXT(lhs, rhs, dest) \
	if (IS_BOTH_INTEGER(lhs,rhs)) { \
		uint32 result = ((uint32)INTEGER_VALUE(lhs) >> (INTEGER_VALUE(rhs) & 0x1F)); \
		if ((result & 0xF0000000U) == 0) { \
			dest = MAKE_INTEGER(result); \
			NEXT; \
		} \
	} \
	SAVE_EXPC; \
	dest = core->uintToAtom( core->toUInt32(lhs) >> (core->toUInt32(rhs)&0x1F) ); \
	NEXT
			
            INSTR(urshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				URSHIFT_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

// The OR with tag is only necessary for xor, which passes kIntegerType.  The
// others pass 0, and we assume the compiler optimizes the OR away.

#define BITOP_TWO_VALUES_AND_NEXT(op, lhs, rhs, dest, tag) \
	if (IS_BOTH_INTEGER(lhs,rhs)) { \
		dest = (lhs op rhs) | tag; \
		NEXT; \
	} \
	SAVE_EXPC; \
	dest = core->intToAtom(core->integer(lhs) op core->integer(rhs)); \
	restore_dxns(); \
	NEXT

#define BITAND_TWO_VALUES_AND_NEXT(lhs, rhs, dest) BITOP_TWO_VALUES_AND_NEXT(&, lhs, rhs, dest, 0)

            INSTR(bitand) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				BITAND_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

#define BITOR_TWO_VALUES_AND_NEXT(lhs, rhs, dest) BITOP_TWO_VALUES_AND_NEXT(|, lhs, rhs, dest, 0)
					
            INSTR(bitor) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				BITOR_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
#define BITXOR_TWO_VALUES_AND_NEXT(lhs, rhs, dest) BITOP_TWO_VALUES_AND_NEXT(^, lhs, rhs, dest, kIntegerType)
					
            INSTR(bitxor) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				BITXOR_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}

            INSTR(equals) {
				// OPTIMIZEME - equals on some classes of values?
				SAVE_EXPC;
				sp[-1] = core->equals(sp[-1], sp[0]);
                sp--;
				restore_dxns();
                NEXT;
			}

            INSTR(strictequals) {
				// OPTIMIZEME - strictequals on some classes of values?
                sp[-1] = core->stricteq(sp[-1], sp[0]);
                sp--;
                NEXT;
			}
				
			INSTR(lookupswitch) {
#ifdef AVMPLUS_WORD_CODE
				const uint32* base = pc-1;
				uint32 index = AvmCore::integer_u(*(sp--));
				uint32 default_offset = S24ARG;
				uint32 case_count = U30ARG;
				if (index <= case_count)
					pc = base + pc[index];
				else
					pc = base + default_offset;
#else
				const byte* base = pc-1;
				// safe to assume int since verifier checks for int
				uint32 index = AvmCore::integer_u(*(sp--));
				const byte* switch_pc = pc+3;
				uint32 case_count = readU30(switch_pc) + 1;
                pc = base+readS24( index < case_count ? (switch_pc + 3*index) : pc );
#endif
				NEXT;
			}

            INSTR(iftrue) {
				Atom bval = *(sp--);
				if (IS_BOOLEAN(bval))
					;
				else if (IS_INTEGER(bval))
					bval = bval == kIntegerType ? falseAtom : trueAtom;
				else
					bval = core->booleanAtom(bval);  // does not throw or change the XML namespace
				int offset = S24ARG;
				if (bval & booleanNotMask)
				{
					if (offset < 0) {
						SAVE_EXPC_S24;
						core->branchCheck(env, interruptable, offset);
					}
                    pc += offset;
				}
                NEXT;
			}

            INSTR(iffalse) {
				Atom bval = *(sp--);
				if (IS_BOOLEAN(bval))
					;
				else if (IS_INTEGER(bval))
					bval = bval == kIntegerType ? falseAtom : trueAtom;
				else
					bval = core->booleanAtom(bval);  // does not throw or change the XML namespace
				int offset = S24ARG;
				if (!(bval & booleanNotMask))
				{
					if (offset < 0) {
						SAVE_EXPC_S24;
						core->branchCheck(env, interruptable, offset);
					}
                    pc += offset;
				}
				NEXT;
			}

// Ick.  The user of this macro must save the EXPC before extracting the operands
// from the instruction stream.

#define IFEQ_TWO_VALUES(intcmp, comparator, truish, lhs, rhs, offset) \
	bool result; \
	if (IS_BOTH_INTEGER(lhs, rhs)) \
		result = lhs intcmp rhs; \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) \
		result = DOUBLE_VALUE(lhs) intcmp DOUBLE_VALUE(rhs); \
	else \
		result = core->comparator(lhs, rhs) == truish; \
	if (result) \
	{ \
		if (offset < 0) \
			core->branchCheck(env, interruptable, offset); \
		pc += offset; \
	} \
	restore_dxns();

#define IFEQ2(intcmp, comparator, truish) \
	SAVE_EXPC; \
	Atom lhs = sp[-1], rhs=sp[0]; \
    sp -= 2; \
	int offset = S24ARG; \
	IFEQ_TWO_VALUES(intcmp, comparator, truish, lhs, rhs, offset);

#define IFEQ(x) IFEQ2(x)

#define COMPARE_EQUAL  ==, equals, trueAtom
					
		   INSTR(ifeq) {
				IFEQ(COMPARE_EQUAL);
                NEXT;
			}

#define COMPARE_NOTEQUAL  !=, equals, falseAtom

			INSTR(ifne) {
				IFEQ(COMPARE_NOTEQUAL);
                NEXT;
			}

#define COMPARE_STRICTEQUAL  ==, stricteq, trueAtom
					
		    INSTR(ifstricteq) {
				IFEQ(COMPARE_STRICTEQUAL);
				NEXT;
			}
					
#define COMPARE_NOTSTRICTEQUAL  !=, stricteq, falseAtom

			INSTR(ifstrictne) {
				IFEQ(COMPARE_NOTSTRICTEQUAL);
				NEXT;
			}

// Ick.  The user of this macro must save the EXPC before extracting the operands
// from the instruction stream.
					
#define IFCMP_TWO_VALUES(numeric_cmp, generic_cmp, lhs, rhs, offset) \
		bool result; \
		if (IS_BOTH_INTEGER(lhs, rhs)) \
			result = lhs numeric_cmp rhs; \
		else if (IS_BOTH_DOUBLE(lhs, rhs)) \
			result = DOUBLE_VALUE(lhs) numeric_cmp DOUBLE_VALUE(rhs); \
		else \
			result = generic_cmp; \
		if (result) \
		{ \
			if (offset < 0) \
				core->branchCheck(env, interruptable, offset); \
			pc += offset; \
		} \
		restore_dxns()

#define IFCMP2(numeric_cmp, generic_cmp) \
		SAVE_EXPC; \
		Atom lhs = sp[-1], rhs=sp[0]; \
		sp -= 2; \
		int offset = S24ARG; \
		IFCMP_TWO_VALUES(numeric_cmp, generic_cmp, lhs, rhs, offset)

#define IFCMP(x)  IFCMP2(x)

#define COMPARE_LESS  <, core->compare(lhs,rhs) == trueAtom
					
			INSTR(iflt) {
				IFCMP(COMPARE_LESS);
                NEXT;
			}

#define COMPARE_NOTLESS  >=, core->compare(lhs, rhs) != trueAtom
					
			INSTR(ifnlt) {
				IFCMP(COMPARE_NOTLESS);
                NEXT;
			}

#define COMPARE_LESSEQUAL  <=, core->compare(rhs, lhs) == falseAtom
					
			INSTR(ifle) {
				IFCMP(COMPARE_LESSEQUAL);
                NEXT;
			}

#define COMPARE_NOTLESSEQUAL  >, core->compare(rhs, lhs) != falseAtom
					
			INSTR(ifnle) {
				IFCMP(COMPARE_NOTLESSEQUAL);
                NEXT;
			}

#define COMPARE_GREATER  >, core->compare(rhs, lhs) == trueAtom
					
			INSTR(ifgt) {
				IFCMP(COMPARE_GREATER);
                NEXT;
			}

#define COMPARE_NOTGREATER  <=, core->compare(rhs, lhs) != trueAtom
					
			INSTR(ifngt) {
				IFCMP(COMPARE_NOTGREATER);
                NEXT;
			}

#define COMPARE_GREATEREQUAL  >=, core->compare(lhs, rhs) == falseAtom
					
			INSTR(ifge) {
				IFCMP(COMPARE_GREATEREQUAL);
                NEXT;
			}
					
#define COMPARE_NOTGREATEREQUAL  <, core->compare(lhs, rhs) != falseAtom
			
			INSTR(ifnge) {
				IFCMP(COMPARE_NOTGREATEREQUAL);
                NEXT;
			}

#define CMP2(numeric_cmp, generic_cmp) \
	Atom lhs=sp[-1], rhs=sp[0]; \
	sp--; \
	if (IS_BOTH_INTEGER(lhs,rhs)) \
		sp[0] = lhs numeric_cmp rhs ? trueAtom : falseAtom; \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) \
		sp[0] = DOUBLE_VALUE(lhs) numeric_cmp DOUBLE_VALUE(rhs) ? trueAtom : falseAtom; \
	else { \
		SAVE_EXPC; \
		sp[0] = generic_cmp ? trueAtom : falseAtom; \
		restore_dxns(); \
	}

#define CMP(x)  CMP2(x)
					
            INSTR(lessthan) {
				CMP(COMPARE_LESS);
                NEXT;
			}

            INSTR(lessequals) {
				CMP(COMPARE_LESSEQUAL);
                NEXT;
			}

            INSTR(greaterthan) {
				CMP(COMPARE_GREATER);
                NEXT;
			}

            INSTR(greaterequals) {
				CMP(COMPARE_GREATEREQUAL);
                NEXT;
			}

            INSTR(newobject) {
				SAVE_EXPC;
                int32 argc = U30ARG;
                Atom tempAtom = env->op_newobject(sp, argc)->atom();
                *(sp -= 2*argc-1) = tempAtom;
				restore_dxns();
                NEXT;
			}

            INSTR(newarray) {
				SAVE_EXPC;
                int32 argc = U30ARG;
                Atom tempAtom = toplevel->arrayClass->newarray(sp-argc+1, argc)->atom();
                *(sp -= argc-1) = tempAtom;
				restore_dxns();
                NEXT;
			}

// OPTIMIZEME - multiname handling.
//
// Right now there's a lot of data copying going on.
// We can do better than this if, in the optimized case, 'name' is a "const Multiname&" or "const Multiname*" that
// points into the table.  The const-ness is crucial, we do not want anyone, anywhere, to modify the pointed-to
// structure.  Code that does modify it (like initMultiname) would make an explicit copy and work on that.  (Edwin
// even suggest that it would be better to keep the Multiname constant and variable parts separate, and that
// that's what they did in TT.)  But that change spreads "const" throughout the system; need to check with a 
// Higher Authority before doing that.

// OPTIMIZEME - isRuntime and isRtns are known at translation time.
// Using type information in the verifier it may be possible to determine
// that isDictionaryLookup is false, too.  Should specialize instructions to
// handle common cases.
//
// But does it matter? getproperty, findproperty are heavyweight operations, and
// opportunities for early binding are resolved during translation.  Still, it may
// make a small difference in connection with avoiding multiname copying, since
// most fields of the multiname data structure will not be accessed.

#ifdef AVMPLUS_WORD_CODE
#  define GET_MULTINAME(name, arg)  do { uint32 tmp=arg; name = pool->word_code.cpool_mn->multinames[tmp]; } while(0)
#else
#  define GET_MULTINAME(name, arg)  do { uint32 tmp=arg; pool->parseMultiname(name, tmp); } while(0)
#endif

			INSTR(getlex) {
				SAVE_EXPC;
				// findpropstrict + getproperty
				// stack in:  -
				// stack out: value
				Multiname name;
				GET_MULTINAME(name, U30ARG);
				// only non-runtime names are allowed.  but this still includes
				// wildcard and attribute names.
				Atom obj = env->findproperty(scope, scopeBase, scopeDepth, &name, true, withBase);
				*(++sp) = toplevel->getproperty(obj, &name, toplevel->toVTable(obj));
				restore_dxns();
				NEXT;
			}	

			// get a property using a multiname ref
            INSTR(getproperty) {
				SAVE_EXPC;
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				if (!multiname.isRuntime())
				{
					sp[0] = toplevel->getproperty(sp[0], &multiname, toplevel->toVTable(sp[0]));
				}
				else
				{
					if(multiname.isRtns() || !core->isDictionaryLookup(*sp, *(sp-1))) {
						sp = initMultiname(env, multiname, sp);
						*sp = toplevel->getproperty(*sp, &multiname, toplevel->toVTable(*sp));
					} else {
						Atom key = *(sp--);
						sp[0] = AvmCore::atomToScriptObject(sp[0])->getAtomProperty(key);
					}
				}
				restore_dxns();
				NEXT;
			}

			// set a property using a multiname ref
			INSTR(setproperty) {
				SAVE_EXPC;
				Multiname multiname; 
				GET_MULTINAME(multiname, U30ARG);
				Atom value = *(sp--);
				if (!multiname.isRuntime())
				{
					Atom obj = *(sp--);
					toplevel->setproperty(obj, &multiname, value, toplevel->toVTable(obj));
				}
				else
				{
					if(multiname.isRtns() || !core->isDictionaryLookup(*sp, *(sp-1))) {
						sp = initMultiname(env, multiname, sp);
						Atom obj = *(sp--);
						toplevel->setproperty(obj, &multiname, value, toplevel->toVTable(obj));
					} else {
						Atom key = *(sp--);
						Atom obj = *(sp--);
						AvmCore::atomToScriptObject(obj)->setAtomProperty(key, value);
					}
				}
				restore_dxns();
                NEXT;
			}

			INSTR(initproperty) {
				SAVE_EXPC;
				Multiname multiname; 
				GET_MULTINAME(multiname, U30ARG);
				Atom value = *(sp--);
				if (!multiname.isRuntime())
				{
					Atom obj = *(sp--);
					env->initproperty(obj, &multiname, value, toplevel->toVTable(obj));
				}
				else
				{
					sp = initMultiname(env, multiname, sp);
					Atom obj = *(sp--);
					env->initproperty(obj, &multiname, value, toplevel->toVTable(obj));
				}
				restore_dxns();
                NEXT;
			}

			INSTR(getdescendants) {
				SAVE_EXPC;
				Multiname name;
				GET_MULTINAME(name, U30ARG);
				if (!name.isRuntime())
				{
					sp[0] = env->getdescendants(sp[0], &name);
				}
				else
				{
					sp = initMultiname(env, name, sp);
					sp[0] = env->getdescendants(sp[0], &name);
				}
				restore_dxns();
				NEXT;
			}

			INSTR(checkfilter) {
				SAVE_EXPC;
				env->checkfilter(sp[0]);
				restore_dxns();
				NEXT;
			}

			// search the scope chain for a given property and return the object
			// that contains it.  the next instruction will usually be getpropname
			// or setpropname.
            INSTR(findpropstrict) {
				// stack in:  [ns [name]]
				// stack out: obj
				SAVE_EXPC;
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				if (multiname.isRuntime())
					sp = initMultiname(env, multiname, sp);
				*(++sp) = env->findproperty(scope, scopeBase, scopeDepth, &multiname, true, withBase);
				restore_dxns();
				NEXT;
			}

            INSTR(findproperty) {
				// stack in:  [ns [name]]
				// stack out: obj
				SAVE_EXPC;
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				if (multiname.isRuntime())
					sp = initMultiname(env, multiname, sp);
				*(++sp) = env->findproperty(scope, scopeBase, scopeDepth, &multiname, false, withBase);
				restore_dxns();
				NEXT;
			}

			INSTR(finddef) {
				// stack in: 
				// stack out: obj
				SAVE_EXPC;
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				*(++sp) = env->finddef(&multiname)->atom();
				restore_dxns();
				NEXT;
			}

			INSTR(nextname) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				// verifier checks for int
				sp[0] = env->nextname(lhs, AvmCore::integer_i(rhs));
				restore_dxns();
				NEXT;
			}

			INSTR(nextvalue) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				// verifier checks for int
				sp[0] = env->nextvalue(lhs, AvmCore::integer_i(rhs));
				restore_dxns();
				NEXT;
			}
				
			INSTR(hasnext) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				// verifier checks for int
				sp[0] = core->intToAtom(env->hasnext(lhs, AvmCore::integer_i(rhs)));
				restore_dxns();
				NEXT;
			}

			INSTR(hasnext2) {
				SAVE_EXPC;
				int objectReg = U30ARG;
				int indexReg  = U30ARG;
				Atom objAtom = framep[objectReg];
				int index = core->integer(framep[indexReg]);
				*(++sp) = env->hasnextproto(objAtom, index) ? trueAtom : falseAtom;
				framep[objectReg] = objAtom;
				framep[indexReg] = core->intToAtom(index);
				restore_dxns();
				NEXT;
			}

			// delete property using multiname
			INSTR(deleteproperty) {
				SAVE_EXPC;
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				if (!multiname.isRuntime())
				{
					sp[0] = env->delproperty(sp[0], &multiname);
				}
				else
				{
					if(multiname.isRtns() || !core->isDictionaryLookup(*sp, *(sp-1))) {
						sp = initMultiname(env, multiname, sp, true);
						sp[0] = env->delproperty(sp[0], &multiname);
					} else {
						Atom key = *(sp--);
						bool res = AvmCore::atomToScriptObject(sp[0])->deleteAtomProperty(key);
						sp[0] = res ? trueAtom : falseAtom;
					}
				}
				restore_dxns();
				NEXT;
			}

            INSTR(setslot) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp -= 2;
				env->nullcheck(lhs);
				int slot_id = U30ARG-1;
				ScriptObject* o = AvmCore::atomToScriptObject(lhs);
				o->setSlotAtom(slot_id, toplevel->coerce(rhs, o->traits()->getSlotTraits(slot_id)));
				restore_dxns();
				NEXT;
			}

			INSTR(getslot) {
				SAVE_EXPC;
				env->nullcheck(sp[0]);
				// OPTIMIZEME - cleanup after ABC interpreter defenestration.
				// Perform the -1 adjustment in the bytecode translator, not here every time.
				sp[0] = AvmCore::atomToScriptObject(sp[0])->getSlotAtom(U30ARG-1);
				restore_dxns();
				NEXT;
			}

			INSTR(setglobalslot) {
				SAVE_EXPC;
				// find the global activation scope (object at depth 0 on scope chain)
				ScriptObject *global;
				if (outer_depth == 0)
					global = AvmCore::atomToScriptObject(scopeBase[0]);
				else
					global = AvmCore::atomToScriptObject(scope->getScope(0));

				// OPTIMIZEME - cleanup after ABC interpreter defenestration.
				// Perform the -1 adjustment in the bytecode translator, not here every time.
				int slot_id = U30ARG-1;
				Atom op = sp[0];
				sp--;
				global->setSlotAtom(slot_id, toplevel->coerce(op, global->traits()->getSlotTraits(slot_id)));
				restore_dxns();
				NEXT;
			}

			INSTR(getglobalslot) {
				SAVE_EXPC;
				// find the global activation scope (object at depth 0 on scope chain)
				ScriptObject *global;
				if (outer_depth == 0)
					global = AvmCore::atomToScriptObject(scopeBase[0]);
				else
					global = AvmCore::atomToScriptObject(scope->getScope(0));

				// OPTIMIZMEME - cleanup after ABC interpreter defenestration.
				// Perform the -1 adjustment in the bytecode translator, not here every time.
				sp++;
				sp[0] = global->getSlotAtom(U30ARG-1);
				restore_dxns();
				NEXT;
			}

			// OPTIMIZEME - presumably there are many ways in which the call opcodes may be specialized 
			// to avoid the full function prologue?
	
			INSTR(call) {
				SAVE_EXPC;
                int32 argc = U30ARG;
                // stack in: function, receiver, arg1, ... argN
                // stack out: result
                Atom tempAtom = toplevel->op_call(sp[-argc-1]/*function*/, argc, sp-argc);
                *(sp = sp-argc-1) = tempAtom;
				restore_dxns();
                NEXT;
			}

			INSTR(construct) {
				SAVE_EXPC;
                int32 argc = U30ARG;
                // stack in: function, arg1, ..., argN
                // stack out: new instance
                Atom tempAtom = toplevel->op_construct(sp[-argc]/*function*/, argc, sp-argc);				
                *(sp = sp-argc) = tempAtom;
				restore_dxns();
                NEXT;
			}

            INSTR(newfunction) {
				SAVE_EXPC;
				sp++;
				AbstractFunction *body = pool->getMethodInfo(U30ARG);
				sp[0] = env->newfunction(body, scope, scopeBase)->atom();
				restore_dxns();
                NEXT;
            }

            INSTR(newclass) {
				SAVE_EXPC;
				int class_index = U30ARG;
				AbstractFunction *cinit = pool->cinits[class_index];
				ClassClosure* base = (ClassClosure*)(~7&toplevel->coerce(sp[0], CLASS_TYPE));
				sp[0] = env->newclass(cinit, base, scope, scopeBase)->atom();
				restore_dxns();
				NEXT;
			}
				
            INSTR(callstatic) {
				SAVE_EXPC;
				// stack in: receiver, arg1..N
				// stack out: result
				int method_id = U30ARG;
				int32 argc = U30ARG;
				env->nullcheck(sp[-argc]);
				// ISSUE if arg types were checked in verifier, this coerces again.
				MethodEnv* f = env->vtable->abcEnv->methods[method_id];
				Atom tempAtom = f->coerceEnter(argc, sp-argc);
				*(sp -= argc) = tempAtom;
				restore_dxns();
				NEXT;
			}

            INSTR(callmethod) {
				SAVE_EXPC;
				// stack in: receiver, arg1..N
				// stack out: result
				uint32 disp_id = U30ARG-1;
				int32 argc = U30ARG;
				// null check included in env->callmethod
				//tempAtom = env->callmethod(disp_id, argc, sp-argc);
				Atom* atomv = sp-argc;

				// must be a real class instance for this to be used.  primitives that have
				// methods will only have final bindings and no dispatch table.
				VTable* vtable = toplevel->toVTable(atomv[0]); // includes null check
				AvmAssert(disp_id < vtable->traits->methodCount);
				MethodEnv *f = vtable->methods[disp_id];
				// ISSUE if arg types were checked in verifier, this coerces again.
				Atom tempAtom = f->coerceEnter(argc, atomv);

				*(sp -= argc) = tempAtom;
				restore_dxns();
				NEXT;
			}

#define callprop_impl(atomv0) \
		SAVE_EXPC;\
		/* ( obj [ns [name]] arg1..N -- result ) */ \
		Multiname multiname;\
		GET_MULTINAME(multiname, U30ARG);\
		int32 argc = U30ARG;\
		Atom base;\
		Atom *atomv = sp - argc;\
		sp = multiname.isRuntime() ? initMultiname(env, multiname, atomv) : atomv;\
		base = *sp;\
		atomv[0] = atomv0;\
		*sp = toplevel->callproperty(base, &multiname, argc, atomv, toplevel->toVTable(base));\
		restore_dxns();
				
			INSTR(callproperty) {
				callprop_impl(base);
				NEXT;
			}

			INSTR(callproplex) {
				callprop_impl(nullObjectAtom);
				NEXT;
			}

			INSTR(callpropvoid) {
				callprop_impl(base);
				sp--;
				NEXT;
			}

			INSTR(constructprop) {
				SAVE_EXPC;
				// stack in: obj [ns [name]] arg1..N
				// stack out: result
				Multiname name;
				GET_MULTINAME(name, U30ARG);
				int32 argc = U30ARG;
				if (!name.isRuntime())
				{
					// np check in toVTable
					Atom tempAtom = toplevel->constructprop(&name, argc, sp-argc, toplevel->toVTable(sp[-argc]));
					*(sp -= argc) = tempAtom;
				}
				else
				{
					Atom* atomv = sp-argc;
					sp = initMultiname(env, name, sp-argc);
					atomv[0] = *sp;
					*sp = toplevel->constructprop(&name, argc, atomv, toplevel->toVTable(atomv[0]));
				}
				restore_dxns();
				NEXT;
			}

			INSTR(applytype) {
				SAVE_EXPC;
				int32 argc = U30ARG;
				// stack in: factory, arg1, ... argN
				// stack out: result
				Atom tempAtom = toplevel->op_applytype(sp[-argc]/*function*/, argc, sp-argc+1);				
				*(sp = sp-argc) = tempAtom;
				restore_dxns();
				NEXT;
			}

#define callsuper_impl() \
		SAVE_EXPC; \
		/* ( obj [ns [name]] arg1..N -- ) */ \
		Multiname name; \
		GET_MULTINAME(name, U30ARG); \
		int32 argc = U30ARG; \
		if (!name.isRuntime()) \
		{ \
			env->nullcheck(sp[-argc]); \
			Atom tempAtom = env->callsuper(&name, argc, sp-argc); \
			*(sp -= argc) = tempAtom; \
		} \
		else \
		{ \
			Atom* atomv = sp-argc; \
			sp = initMultiname(env, name, sp-argc); \
			atomv[0] = *sp; \
			env->nullcheck(atomv[0]); \
			*sp = env->callsuper(&name, argc, atomv); \
		}\
		restore_dxns()

			INSTR(callsuper) {
				callsuper_impl();
				NEXT;
			}

			INSTR(callsupervoid) {
				callsuper_impl();	
				sp--;
				NEXT;
			}

			INSTR(getsuper) {
				SAVE_EXPC;
				Multiname name;
				GET_MULTINAME(name, U30ARG);
				if (!name.isRuntime())
				{
					Atom objAtom = *sp;
					env->nullcheck(objAtom);//null check
					*sp = env->getsuper(objAtom, &name);
				}
				else
				{
					sp = initMultiname(env, name, sp);
					Atom objAtom = *sp;
					env->nullcheck(objAtom);//null check
					*sp = env->getsuper(objAtom, &name);
				}
				restore_dxns();
				NEXT;
			}

			INSTR(setsuper) {
				SAVE_EXPC;
				int index = U30ARG;
				Multiname name;
				GET_MULTINAME(name, index);
				Atom valueAtom = *(sp--);
				if (!name.isRuntime())
				{
					Atom objAtom = *(sp--);
					env->nullcheck(objAtom);
					env->setsuper(objAtom, &name, valueAtom);
				}
				else
				{
					sp = initMultiname(env, name, sp);
					Atom objAtom = *(sp--);
					env->nullcheck(objAtom);
					env->setsuper(objAtom, &name, valueAtom);
				}
				restore_dxns();
				NEXT;
			}

			// obj arg1 arg2
		    //           sp
			INSTR(constructsuper) {
				SAVE_EXPC;
				// stack in:  obj arg1..N
				// stack out: 
				int32 argc = U30ARG;
				env->nullcheck(sp[-argc]);
				env->vtable->base->init->coerceEnter(argc, sp-argc);
				sp -= argc+1;
				restore_dxns();
				NEXT;
			}
				
#ifndef AVMPLUS_WORD_CODE
            INSTR(pushshort) {
                // this just pushes an integer since we dont have short atoms
                *(++sp) = ((signed short)U30ARG)<<3|kIntegerType;
				NEXT;
			}
#endif

			INSTR(astype) {
				SAVE_EXPC;
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				sp[0] = env->astype(sp[0], getTraits(&multiname, pool, toplevel, core));
				restore_dxns();
				NEXT;
			}

			INSTR(astypelate) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = env->astype(lhs, env->toClassITraits(rhs));
				restore_dxns();
                NEXT;
			}

            INSTR(coerce) {
				SAVE_EXPC;
                // expects a CONSTANT_Multiname cpool index
				// this is the ES4 implicit coersion
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				sp[0] = toplevel->coerce(sp[0], getTraits(&multiname, pool, toplevel, core));
				restore_dxns();
                NEXT;
			}

			INSTR(coerce_o) {
				if (sp[0] == undefinedAtom)
					sp[0] = nullObjectAtom;
				NEXT;
			}

			INSTR(coerce_s) {
				Atom val = sp[0];
				if (!IS_STRING(val)) {
					SAVE_EXPC;
					sp[0] = AvmCore::isNullOrUndefined(val) ? nullStringAtom : core->string(val)->atom();
					restore_dxns();
				}
				NEXT;
			}

			// OPTIMIZEME - early binding for rhs of 'is'?
			// (or outright removal in the translator?)

			INSTR(istype) {
				SAVE_EXPC;
                // expects a CONSTANT_Multiname cpool index
				// used when operator "is" RHS is a compile-time type constant
				Multiname multiname;
				GET_MULTINAME(multiname, U30ARG);
				Traits* itraits = getTraits(&multiname, pool, toplevel, core);
				sp[0] = core->istypeAtom(sp[0], itraits);
				restore_dxns();
                NEXT;
			}

			INSTR(istypelate) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = core->istypeAtom(lhs, env->toClassITraits(rhs));
				restore_dxns();
                NEXT;
			}

#ifndef AVMPLUS_WORD_CODE
            INSTR(pushbyte) {
				*(++sp) = MAKE_INTEGER((sint8)U8ARG);
                NEXT;
			}
#endif

            INSTR(getscopeobject) {
				int scope_index = U8ARG;
				*(++sp) = scopeBase[scope_index];
				NEXT;
			}

            INSTR(getouterscope) {
                int scope_index = U30ARG;
				*(++sp) = scope->getScope(scope_index);
                NEXT;
            }

            INSTR(getglobalscope) {
				*(++sp) = (outer_depth > 0) ? scope->getScope(0) : scopeBase[0];
				NEXT;
			}

            INSTR(pushscope) {
				Atom s = sp[0];
				sp--;
				if (AvmCore::isNullOrUndefined(s)) {
					SAVE_EXPC;
					env->nullcheck(s);
				}
				scopeBase[scopeDepth++] = s;
				NEXT;
			}
			
            INSTR(pushwith) {
				Atom s = sp[0];
				sp--;
				if (AvmCore::isNullOrUndefined(s)) {
					SAVE_EXPC;
					env->nullcheck(s);
				}
				if (!withBase)
					withBase = scopeBase+scopeDepth;
				scopeBase[scopeDepth++] = s;
				NEXT;
			}

            INSTR(newactivation) {
				SAVE_EXPC;
				*(++sp) = core->newActivation(env->getActivation(), NULL)->atom();
				restore_dxns();
				NEXT;
			}

            INSTR(newcatch) {
				SAVE_EXPC;
				int catch_index = U30ARG;
#ifdef AVMPLUS_WORD_CODE
				Traits *t = info->word_code.exceptions->exceptions[catch_index].scopeTraits;
#else
				Traits *t = info->exceptions->exceptions[catch_index].scopeTraits;
#endif
				*(++sp) = env->newcatch(t)->atom();
				restore_dxns();
				NEXT;
			}

            INSTR(popscope) {
				scopeDepth--;
				if (withBase >= scopeBase+scopeDepth)
					withBase = NULL;
				NEXT;
			}

			INSTR(coerce_i) {
				Atom val = sp[0];
				if (!IS_INTEGER(val)) {
					SAVE_EXPC;
					sp[0] = core->intAtom(val);
					restore_dxns();
				}
				NEXT;
			}

            INSTR(convert_i) {
				Atom val = sp[0];
				if (!IS_INTEGER(val)) {
					SAVE_EXPC;
					sp[0] = core->intAtom(val);
					restore_dxns();
				}
                NEXT;
			}

			INSTR(coerce_u) {
				Atom val = sp[0];
				if (!IS_INTEGER(val) || val < 0) {
					SAVE_EXPC;
					sp[0] = core->uintAtom(val);
					restore_dxns();
				}
                NEXT;
			}

			INSTR(convert_u) {
				Atom val = sp[0];
				if (!IS_INTEGER(val) || val < 0) {
					SAVE_EXPC;
					sp[0] = core->uintAtom(val);
					restore_dxns();
				}
                NEXT;
			}

			INSTR(throw) {
				SAVE_EXPC;
				core->throwAtom(*sp--);
				// unreachable
				NEXT;
			}
				
            INSTR(instanceof) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = toplevel->instanceof(lhs, rhs);
				restore_dxns();
				NEXT;
			}

            INSTR(in) {
				SAVE_EXPC;
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = env->in(lhs, rhs);
				restore_dxns();
				NEXT;
			}

			INSTR(dxns) {
				SAVE_EXPC;
				dxns = core->newPublicNamespace(cpool_string[U30ARG]);
				restore_dxns();
				NEXT;
			}

			INSTR(dxnslate) {
				SAVE_EXPC;
				dxns = core->newPublicNamespace(core->intern(*sp));
				sp--;
				// this used to be after the switch
				restore_dxns();
				NEXT;
			}

			// 'OP_abs_jump' always boils away in the translation to word code, see
			// comments in Translator.cpp.
#ifndef AVMPLUS_WORD_CODE
					
			INSTR(abs_jump)	{
				if (interruptable && core->interrupted) {
					SAVE_EXPC;
					env->interrupt();
				}
#  ifdef AVMPLUS_64BIT
				uint32 base = AvmCore::readU30(pc);
				byte *target = (byte *) ((uintptr(AvmCore::readU30(pc)) << 32));
				target = (byte*)((uintptr)target | base);
				code_start = pc = (const byte*) target;
#  else // !AVMPLUS_64BIT
				const byte *target = (const byte *) U30ARG;
				code_start = pc = target;
#  endif // AVMPLUS_64BIT
				NEXT;
            }
					
#endif // !AVMPLUS_WORD_CODE

#if defined(AVMPLUS_WORD_CODE) && !defined(AVMPLUS_DIRECT_THREADED)
			// Fleshes out the dispatch table so that it's 0..255, allows
			// some compilers to generate better code for the switch at the
			// top, which switches on the low 8 bits.  (0 is an illegal
			// opcode; 255 is OP_ext, for which there's a case below.)
			case 0: {
				AvmAssert(false);
			}
#endif

#ifdef AVMPLUS_WORD_CODE
#  ifndef AVMPLUS_DIRECT_THREADED
			INSTR(ext) {
			// When using token threading, opcodes for introduced (rewritten) instructions are 
			// represented with the low byte being OP_ext (0xFF) and the second byte being one
			// of the OP_ext_ opcodes.  The main dispatch loop must mask off the higher bits
			// during initial dispatch; this incurs a slight cost but (a) the normal case is
			// that direct threading will be used and (b) the effect of the optimizations enabled
			// by the extended opcodes should make up for it.
#    ifdef _DEBUG
			switch (pc[-1] & 65535) {
#    else
			switch (pc[-1]) {
#    endif
			default:
				goto L_illegal_op;
#  endif // !AVMPLUS_DIRECT_THREADED
#  ifdef MSVC_X86_REWRITE_THREADING
			default:
				// Keep L_illegal_op and L_ext_push_doublebits alive...
				if ((int)pc > 0x100000)
					goto L_ext_push_doublebits;
				break;
#  endif

			INSTR(ext_pushbits) {
				*++sp = *pc++;
				NEXT;
			}

			// OPTIMIZEME - push_doublebits should probably not cons up a new atom every time,
			// it would be better to keep it in the constant pool.

			INSTR(ext_push_doublebits) {
				union {
					double d;
					uint32 bits[2];
				} u;
				u.bits[0] = *pc++;
				u.bits[1] = *pc++;
				*++sp = core->doubleToAtom(u.d);
				NEXT;
			}

#  ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			
			// Superwords not in the instruction set.  These are selected by a table
			// driven peephole optimizer, see comments and code in core/Translator.cpp.

			INSTR(ext_get2locals) {
				uint32 regs = *pc++;
				*(++sp) = framep[regs & 65535];
				*(++sp) = framep[regs >> 16];
				NEXT;
			}
					
			INSTR(ext_get3locals) {
				uint32 regs = *pc++;
				*(++sp) = framep[regs & 1023];
				regs >>= 10;
				*(++sp) = framep[regs & 1023];
				*(++sp) = framep[regs >> 10];
				NEXT;
			}
					
			INSTR(ext_get4locals) {
				uint32 regs = *pc++;
				*(++sp) = framep[regs & 255];
				regs >>= 8;
				*(++sp) = framep[regs & 255];
				regs >>= 8;
				*(++sp) = framep[regs & 255];
				*(++sp) = framep[regs >> 8];
				NEXT;
			}
					
			INSTR(ext_get5locals) {
				uint32 regs = *pc++;
				*(++sp) = framep[regs & 63];
				regs >>= 6;
				*(++sp) = framep[regs & 63];
				regs >>= 6;
				*(++sp) = framep[regs & 63];
				regs >>= 6;
				*(++sp) = framep[regs & 63];
				*(++sp) = framep[regs >> 6];
				NEXT;
			}
					
			INSTR(ext_storelocal) {
				framep[*pc++] = *sp;
				NEXT;
			}
					
			INSTR(ext_add_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				ADD_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_add_set_lll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 1023];
				regs >>= 10;
				Atom rhs=framep[regs & 1023];
				ADD_TWO_VALUES_AND_NEXT(lhs, rhs, framep[regs >> 10]);
			}
					
			INSTR(ext_subtract_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				SUB_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_multiply_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				MUL_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_divide_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				DIV_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_modulo_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				MOD_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_bitand_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				BITAND_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_bitor_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				BITOR_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_bitxor_ll) {
				uint32 regs = *pc++;
				Atom lhs=framep[regs & 65535];
				Atom rhs=framep[regs >> 16];
				++sp;
				BITXOR_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
			
			// OPTIMIZEME - redundant type check in superword.
			// As long as ext_pushbits is only used for integer data we know that
			// rhs is an int in the cases below, so the macros need not check.
					
			INSTR(ext_add_lb) {
				Atom lhs=framep[*pc++];
				Atom rhs=*pc++;
				++sp;
				ADD_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_subtract_lb) {
				Atom lhs=framep[*pc++];
				Atom rhs=*pc++;
				++sp;
				SUB_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_multiply_lb) {
				Atom lhs=framep[*pc++];
				Atom rhs=*pc++;
				++sp;
				MUL_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_divide_lb) {
				Atom lhs=framep[*pc++];
				Atom rhs=*pc++;
				++sp;
				DIV_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_bitand_lb) {
				Atom lhs=framep[*pc++];
				Atom rhs=*pc++;
				++sp;
				BITAND_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_bitor_lb) {
				Atom lhs=framep[*pc++];
				Atom rhs=*pc++;
				++sp;
				BITOR_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
			INSTR(ext_bitxor_lb) {
				Atom lhs=framep[*pc++];
				Atom rhs=*pc++;
				++sp;
				BITXOR_TWO_VALUES_AND_NEXT(lhs, rhs, sp[0]);
			}
					
#define IFCMP_LL2(numeric_cmp, generic_cmp) \
		SAVE_EXPC; \
		int32 offset = (int32)*pc++; \
		uint32 regs = *pc++; \
		Atom lhs = framep[regs & 65535]; \
		Atom rhs = framep[regs >> 16]; \
		IFCMP_TWO_VALUES(numeric_cmp, generic_cmp, lhs, rhs, offset)

#define IFCMP_LL(x) IFCMP_LL2(x)

			INSTR(ext_iflt_ll) {
				IFCMP_LL(COMPARE_LESS);
			    NEXT;
			}
					
			INSTR(ext_ifnlt_ll) {
				IFCMP_LL(COMPARE_NOTLESS);
			    NEXT;
			}
					
			INSTR(ext_ifle_ll) {
				IFCMP_LL(COMPARE_LESSEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifnle_ll) {
				IFCMP_LL(COMPARE_NOTLESSEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifgt_ll) {
				IFCMP_LL(COMPARE_GREATER);
			    NEXT;
			}
					
			INSTR(ext_ifngt_ll) {
				IFCMP_LL(COMPARE_NOTGREATER);
			    NEXT;
			}
					
			INSTR(ext_ifge_ll) {
				IFCMP_LL(COMPARE_GREATEREQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifnge_ll) {
				IFCMP_LL(COMPARE_NOTGREATEREQUAL);
			    NEXT;
			}
					
#define IFEQ_LL2(intcmp, comparator, truish) \
	SAVE_EXPC; \
	int32 offset = (int32)*pc++; \
	uint32 regs = *pc++; \
	Atom lhs = framep[regs & 65535]; \
	Atom rhs = framep[regs >> 16]; \
	IFEQ_TWO_VALUES(intcmp, comparator, truish, lhs, rhs, offset);

#define IFEQ_LL(x) IFEQ_LL2(x)
					
			INSTR(ext_ifeq_ll) {
				IFEQ_LL(COMPARE_EQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifne_ll) {
				IFEQ_LL(COMPARE_NOTEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifstricteq_ll) {
				IFEQ_LL(COMPARE_STRICTEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifstrictne_ll) {
				IFEQ_LL(COMPARE_NOTSTRICTEQUAL);
			    NEXT;
			}

#define IFCMP_LB2(numeric_cmp, generic_cmp) \
		SAVE_EXPC; \
		int32 offset = (int32)*pc++; \
		Atom lhs = framep[*pc++]; \
		Atom rhs = *pc++; \
		IFCMP_TWO_VALUES(numeric_cmp, generic_cmp, lhs, rhs, offset)

#define IFCMP_LB(x) IFCMP_LB2(x)

			INSTR(ext_iflt_lb) {
				IFCMP_LB(COMPARE_LESS);
			    NEXT;
			}
					
			INSTR(ext_ifnlt_lb) {
				IFCMP_LB(COMPARE_NOTLESS);
			    NEXT;
			}
					
			INSTR(ext_ifle_lb) {
				IFCMP_LB(COMPARE_LESSEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifnle_lb) {
				IFCMP_LB(COMPARE_NOTLESSEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifgt_lb) {
				IFCMP_LB(COMPARE_GREATER);
			    NEXT;
			}
					
			INSTR(ext_ifngt_lb) {
				IFCMP_LB(COMPARE_NOTGREATER);
			    NEXT;
			}
					
			INSTR(ext_ifge_lb) {
				IFCMP_LB(COMPARE_GREATEREQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifnge_lb) {
				IFCMP_LB(COMPARE_NOTGREATEREQUAL);
			    NEXT;
			}
					
#define IFEQ_LB2(intcmp, comparator, truish) \
	SAVE_EXPC; \
	int32 offset = (int32)*pc++; \
	Atom lhs = framep[*pc++]; \
	Atom rhs = *pc++; \
	IFEQ_TWO_VALUES(intcmp, comparator, truish, lhs, rhs, offset);

#define IFEQ_LB(x) IFEQ_LB2(x)
					
			INSTR(ext_ifeq_lb) {
				IFEQ_LB(COMPARE_EQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifne_lb) {
				IFEQ_LB(COMPARE_NOTEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifstricteq_lb) {
				IFEQ_LB(COMPARE_STRICTEQUAL);
			    NEXT;
			}
					
			INSTR(ext_ifstrictne_lb) {
				IFEQ_LB(COMPARE_NOTSTRICTEQUAL);
			    NEXT;
			}
					
			INSTR(ext_swap_pop) {
				sp[-1] = sp[0];
				--sp;
			    NEXT;
			}

#  endif // AVMPLUS_PEEPHOLE_OPTIMIZER
#  ifndef AVMPLUS_DIRECT_THREADED
			} // switch
			} // INSTR(ext)
#  endif

#endif
#if defined SWITCH_DISPATCH
			} // switch
			// illegal instruction or accidental break
			goto L_illegal_op;
		} // for
#else
			goto L_illegal_op;
#endif

		}  // TRY

		CATCH (Exception *exception)
		{
			restore_caller_dxns();
			// find handler; rethrow if no handler.
			ExceptionHandler *handler = core->findExceptionHandler(info, expc, exception);
			restore_dxns();
			// handler found in current method
			pc = code_start + handler->target;
			scopeDepth = initialScopeDepth; // ISSUE with() { try {} }
			sp = scopeBase + max_scope - 1;
			*(++sp) = exception->atom;
			goto MainLoop;
		}
		END_CATCH
		END_TRY 

		// Target of various error cases

		L_illegal_op:
			AvmAssert(!"Illegal operation!");
			goto MainLoop;
		//
		// we never get here. verifier doesn't allow code to fall off end.
		//
    }

	// OPTIMIZEME - avoid interning here if possible, see comments above OP_getlex above.
	// OPTIMIZEME - statically knowable if name isRtname or isRtns; exploit this somehow?
	// OPTIMIZEME - often knowable whether the TOS is an object or something simple; exploit this?

	Atom* initMultiname(MethodEnv* env, Multiname &name, Atom* sp, bool isDelete/*=false*/)
	{
		if (name.isRtname())
		{
			Atom index = *(sp--);
			AvmCore* core = env->core();

			// OPTIMIZEME - passing isDelete is not right.
			// It is passed for every multiname, but it is always false except
			// for statically determinable situations (the delete opcodes).
			if (isDelete)
			{
				if (core->isXMLList(index))
				{
					// Error according to E4X spec, section 11.3.1
					env->toplevel()->throwTypeError(kDeleteTypeError, core->toErrorString(env->toplevel()->toTraits(index)));
				}
			}
			
			// is it a qname?
			if (AvmCore::isObject(index))
			{
				ScriptObject* i = AvmCore::atomToScriptObject(index);
				if (i->traits() == core->traits.qName_itraits)
				{
					QNameObject* qname = (QNameObject*) i;
					bool attr = name.isAttr();
					qname->getMultiname(name);
					if (attr)
						name.setAttr(attr);

					// Discard runtime namespace if present
					if (name.isRtns())
						sp--;

					return sp;
				}
			}
					
			name.setName(core->intern(index));
		}

		if (name.isRtns())
			name.setNamespace(env->internRtns(*(sp--)));

		return sp;
	}

	Traits* getTraits(Multiname* name, PoolObject* pool, Toplevel* toplevel, AvmCore* core)
	{
		Traits* t = pool->getTraits(name, toplevel);
		if( name->isParameterizedType() )
		{
			Multiname param_name;
			GET_MULTINAME(param_name, name->getTypeParameter());

			Traits* param_traits = getTraits(&param_name, pool, toplevel, core);
			Stringp fullname = core->internString( core->concatStrings(t->name, 
				core->concatStrings(core->concatStrings(core->newString(".<"), param_traits->formatClassName()), core->newString(">")))->atom());

			Multiname newname;
			newname.setName(fullname);
			newname.setNamespace(t->ns);
			t = pool->getTraits(&newname, toplevel);
		}
		return t;
	}
			
#ifdef AVMPLUS_VERBOSE
	/**
     * display contents of current stack frame only.
     */
	void showState(MethodInfo* info, const byte *code_start, const byte *pc,
							Atom* framep, Atom *spp, int scopeDepth, Atom *scopebasep,
							int max_scope)
    {
		AbcOpcode opcode = (AbcOpcode) *pc;
		PoolObject* pool = info->pool;
		AvmCore* core = pool->core;
		int off = pc - code_start;
		int sp = spp - framep;
		int scopep = scopebasep + scopeDepth - 1 - framep;
		int scopeBase = scopebasep - framep;
		int stackBase = scopebasep + max_scope - framep;

		// stack
		core->console << "                        stack:";
		for (int i=stackBase; i <= sp; i++) {
			core->console << " " << core->format(framep[i]);
		}
		core->console << '\n';

        // scope chain
		core->console << "                        scope: ";
		for (int i=scopeBase; i <= scopep; i++) {
            core->console << core->format(framep[i]) << " ";
        }
		core->console << '\n';

        // locals
		core->console << "                         locals: ";
		for (int i=0; i < scopeBase; i++) {
            core->console << core->format(framep[i]) << " ";
        }
		core->console << '\n';

		// opcode
		core->console << "  ";
#ifdef DEBUGGER
		if (core->debugger && core->callStack && core->callStack->filename)
		{
			core->console << '[' << core->callStack->filename << ':' << (uint32)core->callStack->linenum << "] ";
		}
#endif
		core->console << off << ':';
		core->formatOpcode(core->console, pc, opcode, off, pool);
		core->console << '\n';
    }
#endif // AVMPLUS_VERBOSE
			
#ifdef SUPERWORD_PROFILING
	// 32-bit only

	static FILE *swprof_code_fp = NULL;
	static FILE *swprof_sample_fp = NULL;
#ifdef SUPERWORD_LIMIT
	static unsigned int sample_count = 0;
#endif

	void swprofStart()
	{
		swprof_code_fp = fopen("superwordprof_code.txt", "wb");
		if (swprof_code_fp == NULL)
			fprintf(stderr, "SUPERWORD PROFILING: COULD NOT OPEN CODE FILE.\n");
		else
		{
			unsigned int signature = 0xC0DEC0DE;
			fwrite(&signature, sizeof(uint32), 1, swprof_code_fp);
		}
		swprof_sample_fp = fopen("superwordprof_sample.txt", "wb");
		if (swprof_sample_fp == NULL)
			fprintf(stderr, "SUPERWORD PROFILING: COULD NOT OPEN SAMPLE FILE.\n");
		else
		{
			unsigned int signature = 0xDA1ADA1A;
			fwrite(&signature, sizeof(uint32), 1, swprof_sample_fp);
		}
	}
	
	void swprofStop() 
	{
		if (swprof_code_fp != NULL)	{ fclose(swprof_code_fp); swprof_code_fp = NULL; }
		if (swprof_sample_fp != NULL) { fclose(swprof_sample_fp); swprof_sample_fp = NULL; }
	}
			
	void swprofCode(const uint32* start, const uint32* limit)
	{
		if (swprof_code_fp != NULL) {
			fwrite(&start, sizeof(uint32*), 1, swprof_code_fp);
			fwrite(&limit, sizeof(uint32*), 1, swprof_code_fp);
			fwrite(start, sizeof(uint32), limit-start, swprof_code_fp);
			fflush(swprof_code_fp);
		}
	}

	void swprofPC(const uint32* pc)
	{
		if (swprof_sample_fp != NULL) {
			fwrite(&pc, sizeof(uint32*), 1, swprof_sample_fp);
#ifdef SUPERWORD_LIMIT
			if (++sample_count == SUPERWORD_LIMIT) {
				swprofStop();
				fprintf(stderr, "SAMPLING HALTED.\n");
			}
#endif
		}
	}
#endif  // SUPERWORD_PROFILING
			
}
