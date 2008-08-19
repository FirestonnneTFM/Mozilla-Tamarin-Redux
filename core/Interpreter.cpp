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

	Atom interp(MethodEnv* method, int argc, uint32 *ap);
	Atom* initMultiname(MethodEnv* env, Multiname &name, Atom* sp, bool isDelete=false);
	Traits* getTraits(Multiname* name, PoolObject* pool, Toplevel* toplevel, AvmCore* core);

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

    /**
     * Interpret the AVM+ instruction set.
     * @return
     */
    Atom interp(MethodEnv *env, int argc, uint32 *ap)
    {
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
		if (pos == NULL) {
#  ifdef AVMPLUS_DIRECT_THREADED
#    define XXX &&L_illegal_op
			static void* opcode_labels[] = 
			{   /* 0x00 */ XXX, 
			    /* 0x01 */ &&L_bkpt,
			    /* 0x02 */ XXX, /* OP_nop */
				/* 0x03 */ &&L_throw,
				/* 0x04 */ &&L_getsuper,
				/* 0x05 */ &&L_setsuper,
				/* 0x06 */ &&L_dxns,
				/* 0x07 */ &&L_dxnslate,
				/* 0x08 */ &&L_kill,
				/* 0x09 */ XXX, /* OP_label */
				/* 0x0A */ XXX,
				/* 0x0B */ XXX,
				/* 0x0C */ &&L_ifnlt,
				/* 0x0D */ &&L_ifnle,
				/* 0x0E */ &&L_ifngt,
				/* 0x0F */ &&L_ifnge,
				/* 0x10 */ &&L_jump,
				/* 0x11 */ &&L_iftrue,
				/* 0x12 */ &&L_iffalse,
				/* 0x13 */ &&L_ifeq,
				/* 0x14 */ &&L_ifne,
				/* 0x15 */ &&L_iflt,
				/* 0x16 */ &&L_ifle,
				/* 0x17 */ &&L_ifgt,
				/* 0x18 */ &&L_ifge,
				/* 0x19 */ &&L_ifstricteq,
				/* 0x1A */ &&L_ifstrictne,
				/* 0x1B */ &&L_lookupswitch,
				/* 0x1C */ &&L_pushwith,
				/* 0x1D */ &&L_popscope,
				/* 0x1E */ &&L_nextname,
				/* 0x1F */ &&L_hasnext,
				/* 0x20 */ &&L_pushnull,
				/* 0x21 */ &&L_pushundefined,
				/* 0x22 */ XXX,
				/* 0x23 */ &&L_nextvalue,
				/* 0x24 */ XXX, /* OP_pushbyte */
				/* 0x25 */ XXX, /* OP_pushshort */
				/* 0x26 */ &&L_pushtrue,
				/* 0x27 */ &&L_pushfalse,
				/* 0x28 */ &&L_pushnan,
				/* 0x29 */ &&L_pop,
				/* 0x2A */ &&L_dup,
				/* 0x2B */ &&L_swap,
				/* 0x2C */ &&L_pushstring,
				/* 0x2D */ XXX, /* OP_pushint */
				/* 0x2E */ XXX, /* OP_pushuint */
				/* 0x2F */ &&L_pushdouble,
				/* 0x30 */ &&L_pushscope,
				/* 0x31 */ &&L_pushnamespace,
				/* 0x32 */ &&L_hasnext2,
				/* 0x33 */ XXX,
				/* 0x34 */ XXX,
				/* 0x35 */ XXX,
				/* 0x36 */ XXX,
				/* 0x37 */ XXX,
				/* 0x38 */ XXX,
				/* 0x39 */ XXX,
				/* 0x3A */ XXX,
				/* 0x3B */ XXX,
				/* 0x3C */ XXX,
				/* 0x3D */ XXX,
				/* 0x3E */ XXX,
				/* 0x3F */ XXX,
				/* 0x40 */ &&L_newfunction,
				/* 0x41 */ &&L_call,
				/* 0x42 */ &&L_construct,
				/* 0x43 */ &&L_callmethod,
				/* 0x44 */ &&L_callstatic,
				/* 0x45 */ &&L_callsuper,
				/* 0x46 */ &&L_callproperty,
				/* 0x47 */ &&L_returnvoid,
				/* 0x48 */ &&L_returnvalue,
				/* 0x49 */ &&L_constructsuper,
				/* 0x4A */ &&L_constructprop,
				/* 0x4B */ XXX, /* OP_callsuperid */
				/* 0x4C */ &&L_callproplex,
				/* 0x4D */ XXX, /* OP_callinterface */
				/* 0x4E */ &&L_callsupervoid,
				/* 0x4F */ &&L_callpropvoid,
				/* 0x50 */ XXX,
				/* 0x51 */ XXX,
				/* 0x52 */ XXX,
				/* 0x53 */ &&L_applytype,
				/* 0x54 */ XXX,
				/* 0x55 */ &&L_newobject,
				/* 0x56 */ &&L_newarray,
				/* 0x57 */ &&L_newactivation,
				/* 0x58 */ &&L_newclass,
				/* 0x59 */ &&L_getdescendants,
				/* 0x5A */ &&L_newcatch,
				/* 0x5B */ XXX,
				/* 0x5C */ XXX,
				/* 0x5D */ &&L_findpropstrict,
				/* 0x5E */ &&L_findproperty,
				/* 0x5F */ &&L_finddef,
				/* 0x60 */ &&L_getlex,
				/* 0x61 */ &&L_setproperty,
				/* 0x62 */ &&L_getlocal,
				/* 0x63 */ &&L_setlocal,
				/* 0x64 */ &&L_getglobalscope,
				/* 0x65 */ &&L_getscopeobject,
				/* 0x66 */ &&L_getproperty,
				/* 0x67 */ &&L_getouterscope,
				/* 0x68 */ &&L_initproperty,
				/* 0x69 */ XXX,
				/* 0x6A */ &&L_deleteproperty,
				/* 0x6B */ XXX,
				/* 0x6C */ &&L_getslot,
				/* 0x6D */ &&L_setslot,
				/* 0x6E */ &&L_getglobalslot,
				/* 0x6F */ &&L_setglobalslot,
				/* 0x70 */ &&L_convert_s,
				/* 0x71 */ &&L_esc_xelem,
				/* 0x72 */ &&L_esc_xattr,
				/* 0x73 */ &&L_convert_i,
				/* 0x74 */ &&L_convert_u,
				/* 0x75 */ &&L_convert_d,
				/* 0x76 */ &&L_convert_b,
				/* 0x77 */ &&L_convert_o,
				/* 0x78 */ &&L_checkfilter,
				/* 0x79 */ XXX,
				/* 0x7A */ XXX,
				/* 0x7B */ XXX,
				/* 0x7C */ XXX,
				/* 0x7D */ XXX,
				/* 0x7E */ XXX,
				/* 0x7F */ XXX,
				/* 0x80 */ &&L_coerce,
				/* 0x81 */ &&L_coerce_b,
				/* 0x82 */ &&L_coerce_a,
				/* 0x83 */ &&L_coerce_i,
				/* 0x84 */ &&L_coerce_d,
				/* 0x85 */ &&L_coerce_s,
				/* 0x86 */ &&L_astype,
				/* 0x87 */ &&L_astypelate,
				/* 0x88 */ &&L_coerce_u,
				/* 0x89 */ &&L_coerce_o,
				/* 0x8A */ XXX,
				/* 0x8B */ XXX,
				/* 0x8C */ XXX,
				/* 0x8D */ XXX,
				/* 0x8E */ XXX,
				/* 0x8F */ XXX,
				/* 0x90 */ &&L_negate,
				/* 0x91 */ &&L_increment,
				/* 0x92 */ &&L_inclocal,
				/* 0x93 */ &&L_decrement,
				/* 0x94 */ &&L_declocal,
				/* 0x95 */ &&L_typeof,
				/* 0x96 */ &&L_not,
				/* 0x97 */ &&L_bitnot,
				/* 0x98 */ XXX,
				/* 0x99 */ XXX,
				/* 0x9A */ XXX, /* OP_concat */
				/* 0x9B */ XXX, /* OP_add_d */
				/* 0x9C */ XXX,
				/* 0x9D */ XXX,
				/* 0x9E */ XXX,
				/* 0x9F */ XXX,
				/* 0xA0 */ &&L_add,
				/* 0xA1 */ &&L_subtract,
				/* 0xA2 */ &&L_multiply,
				/* 0xA3 */ &&L_divide,
				/* 0xA4 */ &&L_modulo,
				/* 0xA5 */ &&L_lshift,
				/* 0xA6 */ &&L_rshift,
				/* 0xA7 */ &&L_urshift,
				/* 0xA8 */ &&L_bitand,
				/* 0xA9 */ &&L_bitor,
				/* 0xAA */ &&L_bitxor,
				/* 0xAB */ &&L_equals,
				/* 0xAC */ &&L_strictequals,
				/* 0xAD */ &&L_lessthan,
				/* 0xAE */ &&L_lessequals,
				/* 0xAF */ &&L_greaterthan,
				/* 0xB0 */ &&L_greaterequals,
				/* 0xB1 */ &&L_instanceof,
				/* 0xB2 */ &&L_istype,
				/* 0xB3 */ &&L_istypelate,
				/* 0xB4 */ &&L_in,
				/* 0xB5 */ XXX,
				/* 0xB6 */ XXX,
				/* 0xB7 */ XXX,
				/* 0xB8 */ XXX,
				/* 0xB9 */ XXX,
				/* 0xBA */ XXX,
				/* 0xBB */ XXX,
				/* 0xBC */ XXX,
				/* 0xBD */ XXX,
				/* 0xBE */ XXX,
				/* 0xBF */ XXX,
				/* 0xC0 */ &&L_increment_i,
				/* 0xC1 */ &&L_decrement_i,
				/* 0xC2 */ &&L_inclocal_i,
				/* 0xC3 */ &&L_declocal_i,
				/* 0xC4 */ &&L_negate_i,
				/* 0xC5 */ &&L_add_i,
				/* 0xC6 */ &&L_subtract_i,
				/* 0xC7 */ &&L_multiply_i,
				/* 0xC8 */ XXX,
				/* 0xC9 */ XXX,
				/* 0xCA */ XXX,
				/* 0xCB */ XXX,
				/* 0xCC */ XXX,
				/* 0xCD */ XXX,
				/* 0xCE */ XXX,
				/* 0xCF */ XXX,
				/* 0xD0 */ &&L_getlocal0,
				/* 0xD1 */ &&L_getlocal1,
				/* 0xD2 */ &&L_getlocal2,
				/* 0xD3 */ &&L_getlocal3,
				/* 0xD4 */ &&L_setlocal0,
				/* 0xD5 */ &&L_setlocal1,
				/* 0xD6 */ &&L_setlocal2,
				/* 0xD7 */ &&L_setlocal3,
				/* 0xD8 */ XXX,
				/* 0xD9 */ XXX,
				/* 0xDA */ XXX,
				/* 0xDB */ XXX,
				/* 0xDC */ XXX,
				/* 0xDD */ XXX,
				/* 0xDE */ XXX,
				/* 0xDF */ XXX,
				/* 0xE0 */ XXX,
				/* 0xE1 */ XXX,
				/* 0xE2 */ XXX,
				/* 0xE3 */ XXX,
				/* 0xE4 */ XXX,
				/* 0xE5 */ XXX,
				/* 0xE6 */ XXX,
				/* 0xE7 */ XXX,
				/* 0xE8 */ XXX,
				/* 0xE9 */ XXX,
				/* 0xEA */ XXX,
				/* 0xEB */ XXX,
				/* 0xEC */ XXX,
				/* 0xED */ XXX,
				/* 0xEE */ XXX, /* OP_abs_jump */
				/* 0xEF */ XXX, /* OP_debug */
				/* 0xF0 */ &&L_debugline,
				/* 0xF1 */ &&L_debugfile,
				/* 0xF2 */ &&L_bkptline,
				/* 0xF3 */ XXX,  /* OP_timestamp */
				/* 0xF4 */ XXX,
				/* 0xF5 */ XXX,
				/* 0xF6 */ XXX,
				/* 0xF7 */ XXX,
				/* 0xF8 */ XXX,
				/* 0xF9 */ XXX,
				/* 0xFA */ XXX,
				/* 0xFB */ XXX,
				/* 0xFC */ XXX,
				/* 0xFD */ XXX,
				/* 0xFE */ XXX,
				/* 0xFF */ XXX,  /* OP_ext */
				/* 0xFF 0x00 */ XXX,
				/* 0xFF 0x01 */ &&L_ext_pushbits,
				/* 0xFF 0x02 */ &&L_ext_push_doublebits
			};
			AvmAssert(opcode_labels[0x18] == &&L_ifge);
			AvmAssert(opcode_labels[0x97] == &&L_bitnot);
			AvmAssert(opcode_labels[0xF0] == &&L_debugline);
			AvmAssert(opcode_labels[257] == &&L_ext_pushbits);
			Translator *t = new Translator(opcode_labels);
#  else  // !AVMPLUS_DIRECT_THREADED
			Translator *t = new Translator();
#  endif // AVMPLUS_DIRECT_THREADED
			
			t->translate(env);
			delete t;
			pos = info->word_code.body_pos;
			AvmAssert(pos != NULL);
		}
		const uint32* volatile code_start = pos;
		int max_stack = info->word_code.max_stack;
		int local_count = info->word_code.local_count;
		int init_scope_depth = info->word_code.init_scope_depth;
		int max_scope_depth = info->word_code.max_scope_depth;
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
		env->invocationCount++;
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
		const List<Stringp, LIST_RCObjects>& cpool_string = pool->cpool_string;
#ifndef AVMPLUS_WORD_CODE
        const List<int,LIST_NonGCObjects>& cpool_int = pool->cpool_int;
        const List<uint32,LIST_NonGCObjects>& cpool_uint = pool->cpool_uint;
#endif // !AVMPLUS_WORD_CODE
        const List<double*, LIST_GCObjects>& cpool_double = pool->cpool_double;
		const List<Namespace*, LIST_RCObjects>& cpool_ns = pool->cpool_ns;

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

#  ifdef AVMPLUS_DIRECT_THREADED
#    define INSTR(op)       L_##op:
#    define NEXT            goto *(*pc++)
#    define FIRST			NEXT
#  else
#    define INSTR(op)       case OP_##op:
#    define NEXT            continue
#  endif
		
#  define U30ARG          (*pc++)
#  define U8ARG           (*pc++)
#  define S24ARG          (int32)(*pc++)
#  define SAVE_EXPC       expc = pc-1-code_start
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
#ifdef AVMPLUS_DIRECT_THREADED

		FIRST;

		L_illegal_op:
			AvmAssert(!"Illegal operation!");
			return falseAtom;
			
#else	// AVMPLUS_DIRECT_THREADED
			
        for (;;)
        {
#  ifdef AVMPLUS_WORD_CODE
			// See comments around INSTR(ext) below.
			AvmAssert((*pc & 65535) == ((*pc >> 16) & 65535));
			switch ((*pc++) & 255)
#  else
            switch (*pc++)
#  endif // AVMPLUS_WORD_CODE
            {

#endif // AVMPLUS_DIRECT_THREADED

	#define return_impl(val) \
            {\
				SAVE_EXPC;\
				core->codeContextAtom = savedCodeContext;\
				tempAtom = toplevel->coerce(val, info->returnTraits());\
				restore_caller_dxns();\
			}

			INSTR(returnvoid) {
				Atom tempAtom;
				#ifdef DEBUGGER
				env->debugExit(&callStackNode);
				#endif				
				return_impl(undefinedAtom);
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
				return_impl(*sp);
				#ifdef AVMPLUS_VERBOSE
				if (pool->verbose)
					core->console << "exit " << info << '\n';
				#endif
				return tempAtom;
			}

#ifndef AVMPLUS_WORD_CODE
            INSTR(nop) {
				// FIXME: In the direct threaded translation these should probably
				// not be in the instruction stream at all.
                NEXT;
			}
#endif
					
#ifndef AVMPLUS_WORD_CODE
            INSTR(label) {
				// FIXME: In the direct threaded translation these should probably
				// not be in the instruction stream at all.
                NEXT;
			}
#endif
					
#ifndef AVMPLUS_WORD_CODE
			INSTR(timestamp) {
				// FIXME: In the direct threaded translation these should probably
				// not be in the instruction stream at all.
                NEXT;
			}
#endif
					
			INSTR(coerce_a) { // no-op since interpreter only uses atoms
                NEXT;
			}

			INSTR(bkpt) {
				SAVE_EXPC;
				#ifdef DEBUGGER
				if (debugger)
				{
					debugger->enterDebugger();
				}
				#endif
				restore_dxns();
				NEXT;
			}

			INSTR(debugline) {
				SAVE_EXPC;
				int line = U30ARG;
			    #ifdef DEBUGGER
				if (debugger)
				{
					debugger->debugLine(line);
				}
				#else
				(void)line;
				#endif
				restore_dxns();
				NEXT;
			}

			INSTR(bkptline) {
				SAVE_EXPC;
				int line = U30ARG;
			    #ifdef DEBUGGER
				if (debugger)
				{
					debugger->debugLine(line);
					debugger->enterDebugger();
				}
				#else
				(void)line;
				#endif
				restore_dxns();
				NEXT;
			}

#ifndef AVMPLUS_WORD_CODE
			INSTR(debug) {
				pc += AvmCore::calculateInstructionWidth(pc-1) - 1;
				NEXT;
			}
#endif

			INSTR(debugfile) {
				SAVE_EXPC;
				int index = U30ARG;
				#ifdef DEBUGGER
				if (debugger)
				{
					debugger->debugFile(pool->getString(index));
				}
				#else
				(void)index;
				#endif
				restore_dxns();
				NEXT;
			}

			INSTR(jump) {
				int offset = S24ARG;
				if (offset < 0) {
					SAVE_EXPC_S24;
				    core->branchCheck(env, interruptable, offset);
					restore_dxns();
				}
				pc += offset;
                NEXT;
			}

            INSTR(pushnull) {
				sp++;
                sp[0] = nullObjectAtom;
                NEXT;
			}

            INSTR(pushundefined) {
				sp++;
                sp[0] = undefinedAtom;
                NEXT;
			}

            INSTR(pushstring) {
				sp++;
                sp[0] = cpool_string[U30ARG]->atom();
                NEXT;
			}

#ifndef AVMPLUS_WORD_CODE
            INSTR(pushint) {
				// FIXME
				// Here we want the translator to direct threaded code
				// to specialize the operation into a plain 'pushword' that
				// simply pushes the following word (it could be tagged
				// already) or a 'pushdouble'
				sp++;
                sp[0] = core->intToAtom(cpool_int[U30ARG]);
                NEXT;
			}
#endif
					
#ifndef AVMPLUS_WORD_CODE
            INSTR(pushuint) {
				// FIXME
				// Here we want the translator to direct threaded code
				// to specialize the operation into a plain 'pushword' that
				// simply pushes the following word (it could be tagged
				// already) or a 'pushdouble'
				sp++;
                sp[0] = core->uintToAtom(cpool_uint[U30ARG]);
                NEXT;
			}
#endif
					
            INSTR(pushdouble) {
				sp++;
                sp[0] = kDoubleType|(uintptr)cpool_double[U30ARG];
                NEXT;
			}

            INSTR(pushnamespace) {
                sp++;
                sp[0] = cpool_ns[U30ARG]->atom();
                NEXT;
			}

            INSTR(getlocal) {
                sp++;
				sp[0] = framep[U30ARG];
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
                sp++;
				sp[0] = trueAtom;
                NEXT;
			}

            INSTR(pushfalse) {
				sp++;
                sp[0] = falseAtom;
                NEXT;
			}

			INSTR(pushnan) {
				sp++;
				sp[0] = core->kNaN;
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

#define coerce_d_impl() \
	if (!IS_DOUBLE(sp[0])) { \
		SAVE_EXPC; \
		sp[0] = core->numberAtom(sp[0]); \
		restore_dxns(); \
	}

            INSTR(coerce_d) {
				coerce_d_impl();
				NEXT;
			}

            INSTR(convert_d) {
				coerce_d_impl();
                NEXT;
			}

#define coerce_b_impl() \
	Atom lhs = sp[0]; \
	if (IS_BOOLEAN(lhs)) \
		; \
	else if (IS_INTEGER(lhs)) \
		sp[0] = lhs == kIntegerType ? falseAtom : trueAtom; \
	else \
		sp[0] = core->booleanAtom(lhs);

            INSTR(convert_b) {
				coerce_b_impl();
				NEXT;
			}

            INSTR(coerce_b) {
				coerce_b_impl();
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
				SAVE_EXPC;
                sp[0] = core->intToAtom(-core->integer(sp[0]));
				restore_dxns();
                NEXT;
			}

			INSTR(kill) {
				framep[U30ARG] = undefinedAtom;
				NEXT;
			}

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
				// OPTIMIZEME
				SAVE_EXPC;
				*sp = core->intToAtom(~core->integer(*sp));
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
				SAVE_EXPC;  // because U30ARG prevents it from being done after FAST_INC_MAYBE.  Clean up for threaded code.
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_INC_MAYBE(lhs,*rp);
				*rp = core->numberAtom(*rp);
				core->increment_d(rp, 1);
				restore_dxns();
				NEXT;
			}

            INSTR(inclocal_i) {
				SAVE_EXPC;  // because U30ARG prevents it from being done after FAST_INC_MAYBE.  Clean up for threaded code.
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_INC_MAYBE(lhs,*rp);
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
				SAVE_EXPC;  // because U30ARG prevents it from being done after FAST_DEC_MAYBE.  Clean up for threaded code.
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_DEC_MAYBE(lhs,*rp);
				*rp = core->numberAtom(*rp);
				core->increment_d(rp, -1);
				restore_dxns();
				NEXT;
			}

			INSTR(declocal_i) {
				SAVE_EXPC;  // because U30ARG prevents it from being done after FAST_DEC_MAYBE.  Clean up for threaded code.
				Atom* rp = framep+U30ARG;
				Atom lhs = *rp;
				FAST_DEC_MAYBE(lhs,*rp);
				core->increment_i(rp, -1);
				restore_dxns();
                NEXT;
			}

            INSTR(add) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_ADD_MAYBE(lhs,rhs,sp[0]);
				SAVE_EXPC;
                sp[0] = toplevel->add2(lhs, rhs);
				restore_dxns();
                NEXT;
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

            INSTR(subtract) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_SUB_MAYBE(lhs,rhs,sp[0]);
				SAVE_EXPC;
                sp[0] = core->doubleToAtom(core->number(lhs) - core->number(rhs));
				restore_dxns();
                NEXT;
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

            INSTR(multiply) {
				// OPTIMIZEME? for small integer
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				if (IS_BOTH_DOUBLE(lhs, rhs)) {
					sp[0] = core->doubleToAtom(DOUBLE_VALUE(lhs) * DOUBLE_VALUE(rhs));
					NEXT;
				}
				SAVE_EXPC;
                sp[0] = core->doubleToAtom(core->number(lhs) * core->number(rhs));
				restore_dxns();
                NEXT;
			}

			INSTR(multiply_i) {
				// OPTIMIZEME? for small integer
				SAVE_EXPC;
                sp[-1] = core->intToAtom(core->integer(sp[-1]) * core->integer(sp[0]));
                sp--;
				restore_dxns();
                NEXT;
			}

            INSTR(divide) {
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				if (IS_BOTH_DOUBLE(lhs, rhs)) {
					sp[0] = core->doubleToAtom(DOUBLE_VALUE(lhs) / DOUBLE_VALUE(rhs));
					NEXT;
				}
				SAVE_EXPC;
				sp[0] = core->doubleToAtom(core->number(lhs) / core->number(rhs));
				restore_dxns();
                NEXT;
			}

            INSTR(modulo) {
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs, rhs) && rhs != kIntegerType) {
					int result = (lhs >> 3) % (rhs >> 3);  // can this overflow somehow? 
					if (FITS_IN_INTEGER(result)) {
						sp[0] = MAKE_INTEGER(result);
						NEXT;
					}
				}
				else if (IS_BOTH_DOUBLE(lhs, rhs)) {
					sp[0] = core->doubleToAtom(MathUtils::mod(DOUBLE_VALUE(lhs), DOUBLE_VALUE(rhs)));
					NEXT;
				}
				SAVE_EXPC;
				sp[0] = core->doubleToAtom(MathUtils::mod(core->number(lhs), core->number(rhs)));
				restore_dxns();
				NEXT;
			}

            INSTR(lshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					int32 result = INTEGER_VALUE(lhs) << (INTEGER_VALUE(rhs) & 0x1F);
					if (FITS_IN_INTEGER(result)) {
						sp[0] = MAKE_INTEGER(result);
						NEXT;
					}
				}
				SAVE_EXPC;
				sp[0] = core->intToAtom( core->integer(lhs) << (core->toUInt32(rhs)&0x1F) );
				restore_dxns();
                NEXT;
			}

            INSTR(rshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = MAKE_INTEGER(INTEGER_VALUE(lhs) >> (INTEGER_VALUE(rhs) & 0x1F));
					NEXT;
				}
				SAVE_EXPC;
				sp[0] = core->intToAtom( core->integer(lhs) >> (core->toUInt32(rhs)&0x1F) );
				restore_dxns();
                NEXT;
			}

            INSTR(urshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					uint32 result = ((uint32)INTEGER_VALUE(lhs) >> (INTEGER_VALUE(rhs) & 0x1F));
					if ((result & 0xF0000000U) == 0) {
						sp[0] = MAKE_INTEGER(result);
						NEXT;
					}
				}
				SAVE_EXPC;
                sp[0] = core->uintToAtom( core->toUInt32(lhs) >> (core->toUInt32(rhs)&0x1F) );
                NEXT;
			}

            INSTR(bitand) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = lhs & rhs;
					NEXT;
				}
				SAVE_EXPC;
				sp[0] = core->intToAtom(core->integer(lhs) & core->integer(rhs));
				restore_dxns();
				NEXT;
			}

            INSTR(bitor) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = lhs | rhs;
					NEXT;
				}
				SAVE_EXPC;
                sp[0] = core->intToAtom(core->integer(lhs) | core->integer(rhs));
				restore_dxns();
                NEXT;
			}

            INSTR(bitxor) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = (lhs ^ rhs) | kIntegerType;
					NEXT;
				}
				SAVE_EXPC;
				sp[0] = core->intToAtom(core->integer(lhs) ^ core->integer(rhs));
				restore_dxns();
                NEXT;
			}

            INSTR(equals) {
				// OPTIMIZEME?
				SAVE_EXPC;
				sp[-1] = core->equals(sp[-1], sp[0]);
                sp--;
				restore_dxns();
                NEXT;
			}

            INSTR(strictequals) {
				// OPTIMIZEME?
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

#define IFEQ(intcmp, comparator, truish) \
	do { \
		SAVE_EXPC; \
		Atom lhs = sp[-1], rhs=sp[0]; \
		bool result; \
		if (IS_BOTH_INTEGER(lhs, rhs)) \
			result = lhs intcmp rhs; \
		else if (IS_BOTH_DOUBLE(lhs, rhs)) \
			result = DOUBLE_VALUE(lhs) intcmp DOUBLE_VALUE(rhs); \
		else \
			result = core->comparator(lhs, rhs) == truish; \
		sp -= 2; \
		int offset = S24ARG; \
		if (result) \
		{ \
			if (offset < 0) \
				core->branchCheck(env, interruptable, offset); \
			pc += offset; \
		} \
		restore_dxns(); \
	} while(0)
	
		   INSTR(ifeq) {
				IFEQ(==, equals, trueAtom);
                NEXT;
			}
					
			INSTR(ifne) {
				IFEQ(!=, equals, falseAtom);
                NEXT;
			}

		    INSTR(ifstricteq) {
				IFEQ(==, stricteq, trueAtom);
				NEXT;
			}

			INSTR(ifstrictne) {
				IFEQ(!=, stricteq, falseAtom);
				NEXT;
			}

#define IFCMP(numeric_cmp, generic_cmp) \
		SAVE_EXPC; \
		Atom lhs = sp[-1], rhs=sp[0]; \
		sp -= 2; \
		bool result; \
		if (IS_BOTH_INTEGER(lhs, rhs)) \
			result = lhs numeric_cmp rhs; \
		else if (IS_BOTH_DOUBLE(lhs, rhs)) \
			result = DOUBLE_VALUE(lhs) numeric_cmp DOUBLE_VALUE(rhs); \
		else \
			result = generic_cmp; \
		int offset = S24ARG; \
		if (result) \
		{ \
			if (offset < 0) \
				core->branchCheck(env, interruptable, offset); \
			pc += offset; \
		} \
		restore_dxns();

			INSTR(iflt) {
				IFCMP(<, core->compare(lhs,rhs) == trueAtom);
                NEXT;
			}

			INSTR(ifnlt) {
				IFCMP(>=, core->compare(lhs, rhs) != trueAtom);
                NEXT;
			}

			INSTR(ifle) {
				IFCMP(<=, core->compare(rhs, lhs) == falseAtom);
                NEXT;
			}

			INSTR(ifnle) {
				IFCMP(>, core->compare(rhs, lhs) != falseAtom);
                NEXT;
			}

			INSTR(ifgt) {
				IFCMP(>, core->compare(rhs, lhs) == trueAtom);
                NEXT;
			}

			INSTR(ifngt) {
				IFCMP(<=, core->compare(rhs, lhs) != trueAtom);
                NEXT;
			}
			
			INSTR(ifge) {
				IFCMP(>=, core->compare(lhs, rhs) == falseAtom);
                NEXT;
			}

			INSTR(ifnge) {
				IFCMP(<, core->compare(lhs, rhs) != falseAtom);
                NEXT;
			}

#define CMP(numeric_cmp, generic_cmp) \
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
					
            INSTR(lessthan) {
				CMP(<, core->compare(lhs, rhs) == trueAtom);
                NEXT;
			}

            INSTR(lessequals) {
				CMP(<=, core->compare(rhs,lhs) == falseAtom);
                NEXT;
			}

            INSTR(greaterthan) {
				CMP(>, core->compare(rhs, lhs) == trueAtom);
                NEXT;
			}
					
            INSTR(greaterequals) {
				CMP(>=, core->compare(lhs, rhs) == falseAtom);
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

			INSTR(getlex) {
				SAVE_EXPC;
				// findpropstrict + getproperty
				// stack in:  -
				// stack out: value
				Multiname name;
				pool->parseMultiname(name, U30ARG);

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
				pool->parseMultiname(multiname, U30ARG);
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
				pool->parseMultiname(multiname, U30ARG);
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
				pool->parseMultiname(multiname, U30ARG);
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
				pool->parseMultiname(name, U30ARG);
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
				pool->parseMultiname(multiname, U30ARG);
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
				pool->parseMultiname(multiname, U30ARG);
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
				pool->parseMultiname(multiname, U30ARG);
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
				pool->parseMultiname(multiname, U30ARG);
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

				sp++;
				sp[0] = global->getSlotAtom(U30ARG-1);
				restore_dxns();
				NEXT;
			}

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
            {\
				SAVE_EXPC;\
				/* ( obj [ns [name]] arg1..N -- result ) */ \
				Multiname multiname;\
				pool->parseMultiname(multiname, U30ARG);\
				int32 argc = U30ARG;\
				Atom base;\
				Atom *atomv = sp - argc;\
				sp = multiname.isRuntime() ? initMultiname(env, multiname, atomv) : atomv;\
				base = *sp;\
				atomv[0] = atomv0;\
				*sp = toplevel->callproperty(base, &multiname, argc, atomv, toplevel->toVTable(base));\
			}\
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
				pool->parseMultiname(name, U30ARG);
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
			{\
				SAVE_EXPC; \
				/* ( obj [ns [name]] arg1..N -- ) */ \
				Multiname name; \
				pool->parseMultiname(name, U30ARG); \
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
				pool->parseMultiname(name, U30ARG);
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
				pool->parseMultiname(name, index);
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
				pool->parseMultiname(multiname, U30ARG);
				sp[0] = env->astype(sp[0], getTraits(&multiname, pool, toplevel, core));
				// this used to be after the switch
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
				pool->parseMultiname(multiname, U30ARG);
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

			INSTR(istype) {
				SAVE_EXPC;
                // expects a CONSTANT_Multiname cpool index
				// used when operator "is" RHS is a compile-time type constant
				Multiname multiname;
				pool->parseMultiname(multiname, U30ARG);
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
				sp++;
                sp[0] = MAKE_INTEGER((sint8)U8ARG);
                NEXT;
			}
#endif
					
            INSTR(getscopeobject) {
				int scope_index = U8ARG;
				sp++;
				sp[0] = scopeBase[scope_index];
				NEXT;
			}

            INSTR(getouterscope) {
                int scope_index = U30ARG;
				sp++;
                sp[0] = scope->getScope(scope_index);
                NEXT;
            }

            INSTR(getglobalscope) {
				sp++;
				sp[0] = (outer_depth > 0) ? scope->getScope(0) : scopeBase[0];
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
				sp++;
				sp[0] = core->newActivation(env->getActivation(), NULL)->atom();
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
				sp++;
				sp[0] = env->newcatch(t)->atom();
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
					
#ifdef AVMPLUS_WORD_CODE
#  ifndef AVMPLUS_DIRECT_THREADED
			// When using token threading, opcodes for introduced (rewritten) instructions are 
			// represented with the low byte being OP_ext (0xFF) and the second byte being one
			// of the OP_ext_ opcodes.  The main dispatch loop must mask off the higher bits
			// during initial dispatch; this incurs a slight cost but (a) the normal case is
			// that direct threading will be used and (b) the effect of the optimizations enabled
			// by the extended opcodes should make up for it.
			INSTR(ext) {
#    ifdef _DEBUG
			switch (pc[-1] & 65535) {
#    else
			switch (pc[-1]) {
#    endif
#  endif
			INSTR(ext_pushbits) {
				*++sp = *pc++;
				NEXT;
			}
					
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
#  ifndef AVMPLUS_DIRECT_THREADED
			} // switch
			} // INSTR(ext)
#  endif
#endif
#ifndef AVMPLUS_DIRECT_THREADED
			} // switch
			// illegal instruction or accidental break
			AvmAssert(false);
		} // for
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

		//
		// we never get here. verifier doesn't allow code to fall off end.
		//
    }

	Atom* initMultiname(MethodEnv* env, Multiname &name, Atom* sp, bool isDelete/*=false*/)
	{
		if (name.isRtname())
		{
			Atom index = *(sp--);
			AvmCore* core = env->core();

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
			pool->parseMultiname(param_name, name->getTypeParameter());

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
#endif
}
