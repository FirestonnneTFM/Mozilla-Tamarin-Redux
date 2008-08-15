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
	
	inline int readS24(const byte *pc) {
		return AvmCore::readS24(pc);
	}
	inline int readU30(const byte *&pc) {
		return AvmCore::readU30(pc);
	}

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

		const byte* pos = info->body_pos;
		int max_stack = AvmCore::readU30(pos);
		int local_count = AvmCore::readU30(pos);
		int init_scope_depth = AvmCore::readU30(pos);
		int max_scope_depth = AvmCore::readU30(pos);
		int volatile max_scope = MethodInfo::maxScopeDepth(info, max_scope_depth - init_scope_depth);
		AvmCore::readU30(pos); // code_length
		const byte * volatile code_start = pos;
		
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
        const List<int,LIST_NonGCObjects>& cpool_int = pool->cpool_int;
        const List<uint32,LIST_NonGCObjects>& cpool_uint = pool->cpool_uint;
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

		const byte* pc = code_start;
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

		// in case the next op throws, mark where we are
		#define save_expc()		 expc = pc-1-code_start

		#ifdef AVMPLUS_VERBOSE
			#define INSTR(op) case OP_##op: \
					if (pool->verbose) {\
						showState(info, code_start, pc-1,  framep, sp, scopeDepth, scopeBase, max_scope); \
					}
		#else
			#define INSTR(op) case OP_##op:
		#endif

		#define NEXT() continue

	  MainLoop:
		TRY_UNLESS(core, !info->exceptions, kCatchAction_SearchForActionScriptExceptionHandler) {

		restore_dxns();
		
		// the verifier ensures we don't fall off the end of a method.  so
		// we dont have to check the end pointer here.
        for (;;)
        {
            switch (*pc++)
            {

	#define return_impl(val) \
            {\
				save_expc();\
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

            INSTR(nop) {
				// FIXME: In the direct threaded translation these should probably
				// not be in the instruction stream at all.
                NEXT();
			}

            INSTR(label) {
				// FIXME: In the direct threaded translation these should probably
				// not be in the instruction stream at all.
                NEXT();
			}

			INSTR(timestamp) {
				// FIXME: In the direct threaded translation these should probably
				// not be in the instruction stream at all.
                NEXT();
			}

			INSTR(coerce_a) { // no-op since interpreter only uses atoms
                NEXT();
			}

			INSTR(bkpt) {
				save_expc();
				#ifdef DEBUGGER
				if (debugger)
				{
					debugger->enterDebugger();
				}
				#endif
				restore_dxns();
				NEXT();
			}

			INSTR(debugline) {
				save_expc();
			    #ifdef DEBUGGER
				int line = readU30(pc);
				if (debugger)
				{
					debugger->debugLine(line);
				}
				#else
				readU30(pc);
				#endif
				restore_dxns();
				NEXT();
			}

			INSTR(bkptline) {
				save_expc();
			    #ifdef DEBUGGER
				int line = readU30(pc);
				if (debugger)
				{
					debugger->debugLine(line);
					debugger->enterDebugger();
				}
				#else
				readU30(pc);
				#endif
				restore_dxns();
				NEXT();
			}

			INSTR(debug) {
				pc += AvmCore::calculateInstructionWidth(pc-1) - 1;
				NEXT();
			}

			INSTR(debugfile) {
				save_expc();
				#ifdef DEBUGGER
				int index = readU30(pc);
				if (debugger)
				{
					debugger->debugFile(pool->getString(index));
				}
				#else
				readU30(pc);
				#endif
				restore_dxns();
				NEXT();
			}

			INSTR(jump) {
				int j = readS24(pc);
				if (j < 0) {
					save_expc();
				    core->branchCheck(env, interruptable, j);
					restore_dxns();
				}
				pc += 3+j;
                NEXT();
			}

            INSTR(pushnull) {
				sp++;
                sp[0] = nullObjectAtom;
                NEXT();
			}

            INSTR(pushundefined) {
				sp++;
                sp[0] = undefinedAtom;
                NEXT();
			}

            INSTR(pushstring) {
				sp++;
                sp[0] = cpool_string[readU30(pc)]->atom();
                NEXT();
			}

            INSTR(pushint) {
				// FIXME
				// Here we want the translator to direct threaded code
				// to specialize the operation into a plain 'pushword' that
				// simply pushes the following word (it could be tagged
				// already) or a 'pushdouble'
				sp++;
                sp[0] = core->intToAtom(cpool_int[readU30(pc)]);
                NEXT();
			}

            INSTR(pushuint) {
				// FIXME
				// Here we want the translator to direct threaded code
				// to specialize the operation into a plain 'pushword' that
				// simply pushes the following word (it could be tagged
				// already) or a 'pushdouble'
				sp++;
                sp[0] = core->uintToAtom(cpool_uint[readU30(pc)]);
                NEXT();
			}

            INSTR(pushdouble) {
				sp++;
                sp[0] = kDoubleType|(uintptr)cpool_double[readU30(pc)];
                NEXT();
			}

            INSTR(pushnamespace) {
                sp++;
                sp[0] = cpool_ns[readU30(pc)]->atom();
                NEXT();
			}

            INSTR(getlocal) {
                sp++;
				sp[0] = framep[readU30(pc)];
				NEXT();
			}

            INSTR(getlocal0) {
                *(++sp) = framep[0];
				NEXT();
			}

			INSTR(getlocal1) {
                *(++sp) = framep[1];
				NEXT();
			}
				
			INSTR(getlocal2) {
                *(++sp) = framep[2];
				NEXT();
			}

			INSTR(getlocal3) {
                *(++sp) = framep[3];
				NEXT();
			}

            INSTR(pushtrue) {
                sp++;
				sp[0] = trueAtom;
                NEXT();
			}

            INSTR(pushfalse) {
				sp++;
                sp[0] = falseAtom;
                NEXT();
			}

			INSTR(pushnan) {
				sp++;
				sp[0] = core->kNaN;
				NEXT();
			}

            INSTR(pop) {
                sp--;
                NEXT();
			}

            INSTR(dup) {
				sp++;
				sp[0] = sp[-1];
                NEXT();
			}

            INSTR(swap) {
                Atom tempAtom = sp[0];
                sp[0] = sp[-1];
                sp[-1] = tempAtom;
                NEXT();
			}

            INSTR(convert_s) {
				if ((sp[0] & 7) != kStringType) {
					save_expc();
				    sp[0] = core->string(sp[0])->atom();
					restore_dxns();
				}
                NEXT();
			}

			INSTR(esc_xelem) { // ToXMLString will call EscapeElementValue
				save_expc();
				sp[0] = core->ToXMLString(sp[0])->atom();
				restore_dxns();
				NEXT();
			}

			INSTR(esc_xattr) {
				save_expc();
				sp[0] = core->EscapeAttributeValue(sp[0])->atom();
				restore_dxns();
				NEXT();
			}

#define coerce_d_impl() \
	if (!IS_DOUBLE(sp[0])) { \
		save_expc(); \
		sp[0] = core->numberAtom(sp[0]); \
		restore_dxns(); \
	}

            INSTR(coerce_d) {
				coerce_d_impl();
				NEXT();
			}

            INSTR(convert_d) {
				coerce_d_impl();
                NEXT();
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
				NEXT();
			}

            INSTR(coerce_b) {
				coerce_b_impl();
                NEXT();
			}

            INSTR(convert_o) {
				if (AvmCore::isNullOrUndefined(sp[0])) {
					save_expc();
				    env->nullcheck(sp[0]);
				}
                NEXT();
			}

            INSTR(negate) {
				Atom val = sp[0];
				if (IS_INTEGER(val) && val != MAKE_INTEGER(0)) {
					int32 v = -(val >> 3);
					if (FITS_IN_INTEGER(v)) {
						sp[0] = MAKE_INTEGER(v);
						NEXT();
					}
				}
				save_expc();
				sp[0] = core->doubleToAtom(-core->number(val));
				restore_dxns();
                NEXT();
			}

			INSTR(negate_i) {
				save_expc();
                sp[0] = core->intToAtom(-core->integer(sp[0]));
				restore_dxns();
                NEXT();
			}

			INSTR(kill) {
				framep[readU30(pc)] = undefinedAtom;
				NEXT();
			}

            INSTR(typeof) {
				*sp = core->_typeof(*sp)->atom();
                NEXT();
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
                NEXT();
			}

			INSTR(bitnot) {
				// OPTIMIZEME
				save_expc();
				*sp = core->intToAtom(~core->integer(*sp));
				restore_dxns();
                NEXT();
			}

            INSTR(setlocal) {
                framep[readU30(pc)] = *(sp--);
                NEXT();
			}

            INSTR(setlocal0) {
                framep[0] = *(sp--);
				NEXT();
			}

            INSTR(setlocal1) {
                framep[1] = *(sp--);
				NEXT();
			}

            INSTR(setlocal2) {
                framep[2] = *(sp--);
				NEXT();
			}

            INSTR(setlocal3) {
                framep[3] = *(sp--);
                NEXT();
			}	

// Add lhs and rhs if they are both fixnums and computation does not overflow,
// or if they are both flonums.  On success, store the result in dest, and NEXT.

#define FAST_ADD_MAYBE(lhs,rhs,dest) \
	if (IS_BOTH_INTEGER(lhs, rhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType, rop = (uint32)rhs ^ kIntegerType; \
		uint32 result = lop + rop; \
		if ((int32)(lop ^ rop) < 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT(); \
		} \
	} \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) + DOUBLE_VALUE(rhs)); \
		NEXT(); \
	}

// Add 1 to lhs if it is a fixnum and computation does not overflow, or
// if lhs is a flonum.  On success, store the result in dest, and NEXT.
					
#define FAST_INC_MAYBE(lhs,dest) \
	if (IS_INTEGER(lhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType; \
		uint32 result = lop + (1 << 3); \
		if ((int32)lop < 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT(); \
		} \
	} \
    else if (IS_DOUBLE(lhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) + 1.0); \
		NEXT(); \
	}
					
// Subtract rhs from lhs if they are both fixnums and computation does not overflow.
// On success, store the result in dest, and NEXT.
#define FAST_SUB_MAYBE(lhs,rhs,dest) \
	if (IS_BOTH_INTEGER(lhs, rhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType, rop = (uint32)rhs ^ kIntegerType; \
		uint32 result = lop - rop; \
		if ((int32)(lop ^ rop) >= 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT(); \
		} \
	} \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) + DOUBLE_VALUE(rhs)); \
		NEXT(); \
	}

// Subtract 1 from lhs if lhs is a fixnum and computation does not overflow.
// On success, store the result in dest, and NEXT.
#define FAST_DEC_MAYBE(lhs,dest) \
	if (IS_INTEGER(lhs)) { \
		uint32 lop = (uint32)lhs ^ kIntegerType; \
		uint32 result = lop - (1 << 3); \
		if ((int32)lop >= 0 || (int32)(result ^ lop) >= 0) { \
			dest = result | kIntegerType; \
			NEXT(); \
		} \
	} \
    else if (IS_DOUBLE(lhs)) { \
		dest = core->doubleToAtom(DOUBLE_VALUE(lhs) - 1.0); \
		NEXT(); \
	}

            INSTR(increment) {
				Atom lhs = *sp;
				FAST_INC_MAYBE(lhs,sp[0]);
				save_expc();
				*sp = core->numberAtom(lhs);
				core->increment_d(sp, 1);
				restore_dxns();
                NEXT();
			}

            INSTR(increment_i) {
				Atom lhs = *sp;
				FAST_INC_MAYBE(lhs,sp[0]);
				save_expc();
				core->increment_i(sp, 1);
				restore_dxns();
                NEXT();
			}

			INSTR(inclocal) {
				Atom* rp = framep+readU30(pc);
				Atom lhs = *rp;
				FAST_INC_MAYBE(lhs,*rp);
				save_expc();
				*rp = core->numberAtom(*rp);
				core->increment_d(rp, 1);
				restore_dxns();
				NEXT();
			}

            INSTR(inclocal_i) {
				Atom* rp = framep+readU30(pc);
				Atom lhs = *rp;
				FAST_INC_MAYBE(lhs,*rp);
				save_expc();
				core->increment_i(rp, 1);
				restore_dxns();
				NEXT();
			}

            INSTR(decrement) {
				Atom lhs = *sp;
				FAST_DEC_MAYBE(lhs,sp[0]);
				save_expc();
				*sp = core->numberAtom(*sp);
				core->increment_d(sp, -1);
				restore_dxns();
                NEXT();
			}

            INSTR(decrement_i) {
				Atom lhs = *sp;
				FAST_DEC_MAYBE(lhs,sp[0]);
				save_expc();
				core->increment_i(sp, -1);
				restore_dxns();
                NEXT();
			}

			INSTR(declocal) {
				Atom* rp = framep+readU30(pc);
				Atom lhs = *rp;
				FAST_DEC_MAYBE(lhs,*rp);
				save_expc();
				*rp = core->numberAtom(*rp);
				core->increment_d(rp, -1);
				restore_dxns();
				NEXT();
			}

			INSTR(declocal_i) {
				Atom* rp = framep+readU30(pc);
				Atom lhs = *rp;
				FAST_DEC_MAYBE(lhs,*rp);
				save_expc();
				core->increment_i(rp, -1);
				restore_dxns();
                NEXT();
			}

            INSTR(add) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_ADD_MAYBE(lhs,rhs,sp[0]);
				save_expc();
                sp[0] = toplevel->add2(lhs, rhs);
				restore_dxns();
                NEXT();
			}

			INSTR(add_i) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_ADD_MAYBE(lhs,rhs,sp[0]);
				save_expc();
				sp[0] = core->intToAtom(core->integer(lhs) + core->integer(rhs));
				restore_dxns();
                NEXT();
			}

            INSTR(subtract) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_SUB_MAYBE(lhs,rhs,sp[0]);
				save_expc();
                sp[0] = core->doubleToAtom(core->number(lhs) - core->number(rhs));
				restore_dxns();
                NEXT();
			}

            INSTR(subtract_i) {
				Atom lhs = sp[-1], rhs=sp[0];
				sp--;
				FAST_SUB_MAYBE(lhs,rhs,sp[0]);
				save_expc();
				sp[0] = core->intToAtom(core->integer(lhs) - core->integer(lhs));
				restore_dxns();
                NEXT();
			}

            INSTR(multiply) {
				// OPTIMIZEME? for small integer
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				if (IS_BOTH_DOUBLE(lhs, rhs)) {
					sp[0] = core->doubleToAtom(DOUBLE_VALUE(lhs) * DOUBLE_VALUE(rhs));
					NEXT();
				}
				save_expc();
                sp[0] = core->doubleToAtom(core->number(lhs) * core->number(rhs));
				restore_dxns();
                NEXT();
			}

			INSTR(multiply_i) {
				// OPTIMIZEME? for small integer
				save_expc();
                sp[-1] = core->intToAtom(core->integer(sp[-1]) * core->integer(sp[0]));
                sp--;
				restore_dxns();
                NEXT();
			}

            INSTR(divide) {
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				if (IS_BOTH_DOUBLE(lhs, rhs)) {
					sp[0] = core->doubleToAtom(DOUBLE_VALUE(lhs) / DOUBLE_VALUE(rhs));
					NEXT();
				}
				save_expc();
				sp[0] = core->doubleToAtom(core->number(lhs) / core->number(rhs));
				restore_dxns();
                NEXT();
			}

            INSTR(modulo) {
				Atom lhs = sp[-1], rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs, rhs) && rhs != kIntegerType) {
					int result = (lhs >> 3) % (rhs >> 3);  // can this overflow somehow? 
					if (FITS_IN_INTEGER(result)) {
						sp[0] = MAKE_INTEGER(result);
						NEXT();
					}
				}
				else if (IS_BOTH_DOUBLE(lhs, rhs)) {
					sp[0] = core->doubleToAtom(MathUtils::mod(DOUBLE_VALUE(lhs), DOUBLE_VALUE(rhs)));
					NEXT();
				}
				save_expc();
				sp[0] = core->doubleToAtom(MathUtils::mod(core->number(lhs), core->number(rhs)));
				restore_dxns();
				NEXT();
			}

            INSTR(lshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					int32 result = INTEGER_VALUE(lhs) << (INTEGER_VALUE(rhs) & 0x1F);
					if (FITS_IN_INTEGER(result)) {
						sp[0] = MAKE_INTEGER(result);
						NEXT();
					}
				}
				save_expc();
				sp[0] = core->intToAtom( core->integer(lhs) << (core->toUInt32(rhs)&0x1F) );
				restore_dxns();
                NEXT();
			}

            INSTR(rshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = MAKE_INTEGER(INTEGER_VALUE(lhs) >> (INTEGER_VALUE(rhs) & 0x1F));
					NEXT();
				}
				save_expc();
				sp[0] = core->intToAtom( core->integer(lhs) >> (core->toUInt32(rhs)&0x1F) );
				restore_dxns();
                NEXT();
			}

            INSTR(urshift) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					uint32 result = ((uint32)INTEGER_VALUE(lhs) >> (INTEGER_VALUE(rhs) & 0x1F));
					if ((result & 0xF0000000U) == 0) {
						sp[0] = MAKE_INTEGER(result);
						NEXT();
					}
				}
				save_expc();
                sp[0] = core->uintToAtom( core->toUInt32(lhs) >> (core->toUInt32(rhs)&0x1F) );
                NEXT();
			}

            INSTR(bitand) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = lhs & rhs;
					NEXT();
				}
				save_expc();
				sp[0] = core->intToAtom(core->integer(lhs) & core->integer(rhs));
				restore_dxns();
				NEXT();
			}

            INSTR(bitor) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = lhs | rhs;
					NEXT();
				}
				save_expc();
                sp[0] = core->intToAtom(core->integer(lhs) | core->integer(rhs));
				restore_dxns();
                NEXT();
			}

            INSTR(bitxor) {
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				if (IS_BOTH_INTEGER(lhs,rhs)) {
					sp[0] = (lhs ^ rhs) | kIntegerType;
					NEXT();
				}
				save_expc();
				sp[0] = core->intToAtom(core->integer(lhs) ^ core->integer(rhs));
				restore_dxns();
                NEXT();
			}

            INSTR(equals) {
				// OPTIMIZEME?
				save_expc();
				sp[-1] = core->eq(sp[-1], sp[0]);
                sp--;
				restore_dxns();
                NEXT();
			}

            INSTR(strictequals) {
				// OPTIMIZEME?
                sp[-1] = core->stricteq(sp[-1], sp[0]);
                sp--;
                NEXT();
			}
				
			INSTR(lookupswitch) {
				const byte* base = pc-1;
				// safe to assume int since verifier checks for int
				uint32 index = AvmCore::integer_u(*(sp--));
				const byte* switch_pc = pc+3;
				uint32 case_count = readU30(switch_pc) + 1;
                pc = base+readS24( index < case_count ? (switch_pc + 3*index) : pc );
				NEXT();
			}

            INSTR(iftrue) {
				Atom bval = *(sp--);
				if (IS_BOOLEAN(bval))
					;
				else if (IS_INTEGER(bval))
					bval = bval == kIntegerType ? falseAtom : trueAtom;
				else
					bval = core->booleanAtom(bval);  // does not throw or change the XML namespace
				if (bval & booleanNotMask)
				{
					int j = readS24(pc);
					if (j < 0) {
						save_expc();
						core->branchCheck(env, interruptable, j);
					}
                    pc += 3+j;
				}
				else
                    pc += 3;
                NEXT();
			}

            INSTR(iffalse) {
				Atom bval = *(sp--);
				if (IS_BOOLEAN(bval))
					;
				else if (IS_INTEGER(bval))
					bval = bval == kIntegerType ? falseAtom : trueAtom;
				else
					bval = core->booleanAtom(bval);  // does not throw or change the XML namespace
				if (!(bval & booleanNotMask))
				{
					int j = readS24(pc);
					if (j < 0) {
						save_expc();
						core->branchCheck(env, interruptable, j);
					}
                    pc += 3+j;
				}
				else
                    pc += 3;
				NEXT();
			}

#define IFEQ(intcmp, comparator, truish) \
	do { \
		save_expc(); \
		Atom lhs = sp[-1], rhs=sp[0]; \
		bool result; \
		if (IS_BOTH_INTEGER(lhs, rhs)) \
			result = lhs intcmp rhs; \
		else if (IS_BOTH_DOUBLE(lhs, rhs)) \
			result = DOUBLE_VALUE(lhs) intcmp DOUBLE_VALUE(rhs); \
		else \
			result = core->comparator(lhs, rhs) == truish; \
		sp -= 2; \
		if (result) \
		{ \
			int j = readS24(pc); \
			if (j < 0) \
				core->branchCheck(env, interruptable, j); \
			pc += j; \
		} \
		pc += 3; \
		restore_dxns(); \
	} while(0)
	
		   INSTR(ifeq) {
				IFEQ(==, eq, trueAtom);
                NEXT();
			}
					
			INSTR(ifne) {
				IFEQ(!=, eq, falseAtom);
                NEXT();
			}

		    INSTR(ifstricteq) {
				IFEQ(==, stricteq, trueAtom);
				NEXT();
			}

			INSTR(ifstrictne) {
				IFEQ(!=, stricteq, falseAtom);
				NEXT();
			}

#define IFCMP(numeric_cmp, generic_cmp) \
		save_expc(); \
		Atom lhs = sp[-1], rhs=sp[0]; \
		sp -= 2; \
		bool result; \
		if (IS_BOTH_INTEGER(lhs, rhs)) \
			result = lhs numeric_cmp rhs; \
		else if (IS_BOTH_DOUBLE(lhs, rhs)) \
			result = DOUBLE_VALUE(lhs) numeric_cmp DOUBLE_VALUE(rhs); \
		else \
			result = generic_cmp; \
		if (result) \
		{ \
			int j = readS24(pc); \
			if (j < 0) \
				core->branchCheck(env, interruptable, j); \
			pc += j; \
		} \
		pc += 3; \
		restore_dxns();

			INSTR(iflt) {
				IFCMP(<, core->compare(lhs,rhs) == trueAtom);
                NEXT();
			}

			INSTR(ifnlt) {
				IFCMP(>=, core->compare(lhs, rhs) != trueAtom);
                NEXT();
			}

			INSTR(ifle) {
				IFCMP(<=, core->compare(rhs, lhs) == falseAtom);
                NEXT();
			}

			INSTR(ifnle) {
				IFCMP(>, core->compare(rhs, lhs) != falseAtom);
                NEXT();
			}

			INSTR(ifgt) {
				IFCMP(>, core->compare(rhs, lhs) == trueAtom);
                NEXT();
			}

			INSTR(ifngt) {
				IFCMP(<=, core->compare(rhs, lhs) != trueAtom);
                NEXT();
			}
			
			INSTR(ifge) {
				IFCMP(>=, core->compare(lhs, rhs) == falseAtom);
                NEXT();
			}

			INSTR(ifnge) {
				IFCMP(<, core->compare(lhs, rhs) != falseAtom);
                NEXT();
			}

#define CMP(numeric_cmp, generic_cmp) \
	Atom lhs=sp[-1], rhs=sp[0]; \
	sp--; \
	if (IS_BOTH_INTEGER(lhs,rhs)) \
		sp[0] = lhs numeric_cmp rhs ? trueAtom : falseAtom; \
	else if (IS_BOTH_DOUBLE(lhs, rhs)) \
		sp[0] = DOUBLE_VALUE(lhs) numeric_cmp DOUBLE_VALUE(rhs) ? trueAtom : falseAtom; \
	else { \
		save_expc(); \
		sp[0] = generic_cmp ? trueAtom : falseAtom; \
		restore_dxns(); \
	}
					
            INSTR(lessthan) {
				CMP(<, core->compare(lhs, rhs) == trueAtom);
                NEXT();
			}

            INSTR(lessequals) {
				CMP(<=, core->compare(rhs,lhs) == falseAtom);
                NEXT();
			}

            INSTR(greaterthan) {
				CMP(>, core->compare(rhs, lhs) == trueAtom);
                NEXT();
			}
					
            INSTR(greaterequals) {
				CMP(>=, core->compare(lhs, rhs) == falseAtom);
                NEXT();
			}
					
            INSTR(newobject) {
				save_expc();
                int32 argc = readU30(pc);
                Atom tempAtom = env->op_newobject(sp, argc)->atom();
                *(sp -= 2*argc-1) = tempAtom;
				restore_dxns();
                NEXT();
			}

            INSTR(newarray) {
				save_expc();
                int32 argc = readU30(pc);
                Atom tempAtom = toplevel->arrayClass->newarray(sp-argc+1, argc)->atom();
                *(sp -= argc-1) = tempAtom;
				restore_dxns();
                NEXT();
			}

			INSTR(getlex) {
				save_expc();
				// findpropstrict + getproperty
				// stack in:  -
				// stack out: value
				Multiname name;
				pool->parseMultiname(name, readU30(pc));

				// only non-runtime names are allowed.  but this still includes
				// wildcard and attribute names.
				Atom obj = env->findproperty(scope, scopeBase, scopeDepth, &name, true, withBase);
				*(++sp) = toplevel->getproperty(obj, &name, toplevel->toVTable(obj));
				restore_dxns();
				NEXT();
			}	

			// get a property using a multiname ref
            INSTR(getproperty) {
				save_expc();
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
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
				NEXT();
			}

			// set a property using a multiname ref
			INSTR(setproperty) {
				save_expc();
				Multiname multiname; 
				pool->parseMultiname(multiname, readU30(pc));
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
                NEXT();
			}

			INSTR(initproperty) {
				save_expc();
				Multiname multiname; 
				pool->parseMultiname(multiname, readU30(pc));
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
                NEXT();
			}

			INSTR(getdescendants) {
				save_expc();
				Multiname name;
				pool->parseMultiname(name, readU30(pc));
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
				NEXT();
			}

			INSTR(checkfilter) {
				save_expc();
				env->checkfilter(sp[0]);
				restore_dxns();
				NEXT();
			}

			// search the scope chain for a given property and return the object
			// that contains it.  the next instruction will usually be getpropname
			// or setpropname.
            INSTR(findpropstrict) {
				// stack in:  [ns [name]]
				// stack out: obj
				save_expc();
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
				if (multiname.isRuntime())
					sp = initMultiname(env, multiname, sp);
				*(++sp) = env->findproperty(scope, scopeBase, scopeDepth, &multiname, true, withBase);
				restore_dxns();
				NEXT();
			}

            INSTR(findproperty) {
				// stack in:  [ns [name]]
				// stack out: obj
				save_expc();
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
				if (multiname.isRuntime())
					sp = initMultiname(env, multiname, sp);
				*(++sp) = env->findproperty(scope, scopeBase, scopeDepth, &multiname, false, withBase);
				restore_dxns();
				NEXT();
			}

			INSTR(finddef) {
				// stack in: 
				// stack out: obj
				save_expc();
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
				*(++sp) = env->finddef(&multiname)->atom();
				restore_dxns();
				NEXT();
			}

			INSTR(nextname) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				// verifier checks for int
				sp[0] = env->nextname(lhs, AvmCore::integer_i(rhs));
				restore_dxns();
				NEXT();
			}

			INSTR(nextvalue) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				// verifier checks for int
				sp[0] = env->nextvalue(lhs, AvmCore::integer_i(rhs));
				restore_dxns();
				NEXT();
			}
				
			INSTR(hasnext) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				// verifier checks for int
				sp[0] = core->intToAtom(env->hasnext(lhs, AvmCore::integer_i(rhs)));
				restore_dxns();
				NEXT();
			}

			INSTR(hasnext2) {
				save_expc();
				int objectReg = readU30(pc);
				int indexReg  = readU30(pc);
				Atom objAtom = framep[objectReg];
				int index = core->integer(framep[indexReg]);
				*(++sp) = env->hasnextproto(objAtom, index) ? trueAtom : falseAtom;
				framep[objectReg] = objAtom;
				framep[indexReg] = core->intToAtom(index);
				restore_dxns();
				NEXT();
			}

			// delete property using multiname
			INSTR(deleteproperty) {
				save_expc();
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
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
				NEXT();
			}

            INSTR(setslot) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp -= 2;
				env->nullcheck(lhs);
				int slot_id = readU30(pc)-1;
				ScriptObject* o = AvmCore::atomToScriptObject(lhs);
				o->setSlotAtom(slot_id, toplevel->coerce(rhs, o->traits()->getSlotTraits(slot_id)));
				restore_dxns();
				NEXT();
			}

			INSTR(getslot) {
				save_expc();
				env->nullcheck(sp[0]);
				sp[0] = AvmCore::atomToScriptObject(sp[0])->getSlotAtom(readU30(pc)-1);
				restore_dxns();
				NEXT();
			}

			INSTR(setglobalslot) {
				save_expc();
				// find the global activation scope (object at depth 0 on scope chain)
				ScriptObject *global;
				if (outer_depth == 0)
				{
					global = AvmCore::atomToScriptObject(scopeBase[0]);
				}
				else
				{
					global = AvmCore::atomToScriptObject(scope->getScope(0));
				}

				int slot_id = readU30(pc)-1;
				Atom op = sp[0];
				sp--;
				global->setSlotAtom(slot_id, toplevel->coerce(op, global->traits()->getSlotTraits(slot_id)));
				restore_dxns();
				NEXT();
			}

			INSTR(getglobalslot) {
				save_expc();
				// find the global activation scope (object at depth 0 on scope chain)
				ScriptObject *global;
				if (outer_depth == 0)
				{
					global = AvmCore::atomToScriptObject(scopeBase[0]);
				}
				else
				{
					global = AvmCore::atomToScriptObject(scope->getScope(0));
				}

				sp++;
				sp[0] = global->getSlotAtom(readU30(pc)-1);
				restore_dxns();
				NEXT();
			}

			INSTR(call) {
				save_expc();
                int32 argc = readU30(pc);
                // stack in: function, receiver, arg1, ... argN
                // stack out: result
                Atom tempAtom = toplevel->op_call(sp[-argc-1]/*function*/, argc, sp-argc);
                *(sp = sp-argc-1) = tempAtom;
				restore_dxns();
                NEXT();
			}

			INSTR(construct) {
				save_expc();
                int32 argc = readU30(pc);
                // stack in: function, arg1, ..., argN
                // stack out: new instance
                Atom tempAtom = toplevel->op_construct(sp[-argc]/*function*/, argc, sp-argc);				
                *(sp = sp-argc) = tempAtom;
				restore_dxns();
                NEXT();
			}

            INSTR(newfunction) {
				save_expc();
				sp++;
				AbstractFunction *body = pool->getMethodInfo(readU30(pc));
				sp[0] = env->newfunction(body, scope, scopeBase)->atom();
				restore_dxns();
                NEXT();
            }

            INSTR(newclass) {
				save_expc();
				int class_index = readU30(pc);
				AbstractFunction *cinit = pool->cinits[class_index];
				ClassClosure* base = (ClassClosure*)(~7&toplevel->coerce(sp[0], CLASS_TYPE));
				sp[0] = env->newclass(cinit, base, scope, scopeBase)->atom();
				restore_dxns();
				NEXT();
			}
				
            INSTR(callstatic) {
				save_expc();
				// stack in: receiver, arg1..N
				// stack out: result
				int method_id = readU30(pc);
				int32 argc = readU30(pc);
				env->nullcheck(sp[-argc]);
				// ISSUE if arg types were checked in verifier, this coerces again.
				MethodEnv* f = env->vtable->abcEnv->methods[method_id];
				Atom tempAtom = f->coerceEnter(argc, sp-argc);
				*(sp -= argc) = tempAtom;
				restore_dxns();
				NEXT();
			}

            INSTR(callmethod) {
				save_expc();
				// stack in: receiver, arg1..N
				// stack out: result
				uint32 disp_id = readU30(pc)-1;
				int32 argc = readU30(pc);
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
				NEXT();
			}

	#define callprop_impl(atomv0) \
            {\
				save_expc();\
				/* ( obj [ns [name]] arg1..N -- result ) */ \
				Multiname multiname;\
				pool->parseMultiname(multiname, readU30(pc));\
				int32 argc = readU30(pc);\
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
				NEXT();
			}

			INSTR(callproplex) {
				callprop_impl(nullObjectAtom);
				NEXT();
			}

			INSTR(callpropvoid) {
				callprop_impl(base);
				sp--;
				NEXT();
			}

			INSTR(constructprop) {
				save_expc();
				// stack in: obj [ns [name]] arg1..N
				// stack out: result
				Multiname name;
				pool->parseMultiname(name, readU30(pc));
				int32 argc = readU30(pc);
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
				NEXT();
			}

			INSTR(applytype) {
				save_expc();
				int32 argc = readU30(pc);
				// stack in: factory, arg1, ... argN
				// stack out: result
				Atom tempAtom = toplevel->op_applytype(sp[-argc]/*function*/, argc, sp-argc+1);				
				*(sp = sp-argc) = tempAtom;
				restore_dxns();
				NEXT();
			}

	#define callsuper_impl() \
			{\
				save_expc(); \
				/* ( obj [ns [name]] arg1..N -- ) */ \
				Multiname name; \
				pool->parseMultiname(name, readU30(pc)); \
				int32 argc = readU30(pc); \
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
				NEXT();
			}

			INSTR(callsupervoid) {
				callsuper_impl();	
				sp--;
				NEXT();
			}

			INSTR(getsuper) {
				save_expc();
				Multiname name;
				pool->parseMultiname(name, readU30(pc));
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
				NEXT();
			}

			INSTR(setsuper) {
				save_expc();
				int index = readU30(pc);
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
				NEXT();
			}

			// obj arg1 arg2
		    //           sp
			INSTR(constructsuper) {
				save_expc();
				// stack in:  obj arg1..N
				// stack out: 
				int32 argc = readU30(pc);
				env->nullcheck(sp[-argc]);
				env->vtable->base->init->coerceEnter(argc, sp-argc);
				sp -= argc+1;
				restore_dxns();
				NEXT();
			}
				
            INSTR(pushshort) {
                // this just pushes an integer since we dont have short atoms
                *(++sp) = ((signed short)readU30(pc))<<3|kIntegerType;
				NEXT();
			}

			INSTR(astype) {
				save_expc();
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
				sp[0] = env->astype(sp[0], getTraits(&multiname, pool, toplevel, core));
				// this used to be after the switch
				restore_dxns();
				NEXT();
			}

			INSTR(astypelate) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = env->astype(lhs, env->toClassITraits(rhs));
				restore_dxns();
                NEXT();
			}

            INSTR(coerce) {
				save_expc();
                // expects a CONSTANT_Multiname cpool index
				// this is the ES4 implicit coersion
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
				sp[0] = toplevel->coerce(sp[0], getTraits(&multiname, pool, toplevel, core));
				restore_dxns();
                NEXT();
			}

			INSTR(coerce_o) {
				if (sp[0] == undefinedAtom)
					sp[0] = nullObjectAtom;
				NEXT();
			}

			INSTR(coerce_s) {
				Atom val = sp[0];
				if (!IS_STRING(val)) {
					save_expc();
					sp[0] = AvmCore::isNullOrUndefined(val) ? nullStringAtom : core->string(val)->atom();
					restore_dxns();
				}
				NEXT();
			}

			INSTR(istype) {
				save_expc();
                // expects a CONSTANT_Multiname cpool index
				// used when operator "is" RHS is a compile-time type constant
				Multiname multiname;
				pool->parseMultiname(multiname, readU30(pc));
				Traits* itraits = getTraits(&multiname, pool, toplevel, core);
				sp[0] = core->istypeAtom(sp[0], itraits);
				restore_dxns();
                NEXT();
			}

			INSTR(istypelate) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = core->istypeAtom(lhs, env->toClassITraits(rhs));
				restore_dxns();
                NEXT();
			}

            INSTR(pushbyte) {
				sp++;
                sp[0] = MAKE_INTEGER((sint8)*pc++);
                NEXT();
			}

            INSTR(getscopeobject) {
				int scope_index = *pc++;
				sp++;
				sp[0] = scopeBase[scope_index];
				NEXT();
			}

            INSTR(getouterscope) {
                int scope_index = readU30(pc);
				sp++;
                sp[0] = scope->getScope(scope_index);
                NEXT();
            }

            INSTR(getglobalscope) {
				sp++;
				sp[0] = (outer_depth > 0) ? scope->getScope(0) : scopeBase[0];
				NEXT();
			}

            INSTR(pushscope) {
				Atom s = sp[0];
				sp--;
				if (AvmCore::isNullOrUndefined(s)) {
					save_expc();
					env->nullcheck(s);
				}
				scopeBase[scopeDepth++] = s;
				NEXT();
			}
			
            INSTR(pushwith) {
				Atom s = sp[0];
				sp--;
				if (AvmCore::isNullOrUndefined(s)) {
					save_expc();
					env->nullcheck(s);
				}
				if (!withBase)
					withBase = scopeBase+scopeDepth;
				scopeBase[scopeDepth++] = s;
				NEXT();
			}

            INSTR(newactivation) {
				save_expc();
				sp++;
				sp[0] = core->newActivation(env->getActivation(), NULL)->atom();
				restore_dxns();
				NEXT();
			}

            INSTR(newcatch) {
				save_expc();
				int catch_index = readU30(pc);
				Traits *t = info->exceptions->exceptions[catch_index].scopeTraits;
				sp++;
				sp[0] = env->newcatch(t)->atom();
				restore_dxns();
				NEXT();
			}

            INSTR(popscope) {
				scopeDepth--;
				if (withBase >= scopeBase+scopeDepth)
					withBase = NULL;
				NEXT();
			}

			INSTR(coerce_i) {
				Atom val = sp[0];
				if (!IS_INTEGER(val)) {
					save_expc();
					sp[0] = core->intAtom(val);
					restore_dxns();
				}
				NEXT();
			}

            INSTR(convert_i) {
				Atom val = sp[0];
				if (!IS_INTEGER(val)) {
					save_expc();
					sp[0] = core->intAtom(val);
					restore_dxns();
				}
                NEXT();
			}

			INSTR(coerce_u) {
				Atom val = sp[0];
				if (!IS_INTEGER(val) || val < 0) {
					save_expc();
					sp[0] = core->uintAtom(val);
					restore_dxns();
				}
                NEXT();
			}

			INSTR(convert_u) {
				Atom val = sp[0];
				if (!IS_INTEGER(val) || val < 0) {
					save_expc();
					sp[0] = core->uintAtom(val);
					restore_dxns();
				}
                NEXT();
			}

			INSTR(throw) {
				save_expc();
				core->throwAtom(*sp--);
				// unreachable
				NEXT();
			}
				
            INSTR(instanceof) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = toplevel->instanceof(lhs, rhs);
				restore_dxns();
				NEXT();
			}

            INSTR(in) {
				save_expc();
				Atom lhs = sp[-1];
				Atom rhs = sp[0];
				sp--;
				sp[0] = env->in(lhs, rhs);
				restore_dxns();
				NEXT();
			}

			INSTR(dxns) {
				save_expc();
				dxns = core->newPublicNamespace(cpool_string[readU30(pc)]);
				restore_dxns();
				NEXT();
			}

			INSTR(dxnslate) {
				save_expc();
				dxns = core->newPublicNamespace(core->intern(*sp));
				sp--;
				// this used to be after the switch
				restore_dxns();
				NEXT();
			}

			INSTR(abs_jump)
			{
				if (interruptable && core->interrupted) {
					save_expc();
					env->interrupt();
				}
				#ifdef AVMPLUS_64BIT
				uint32 base = AvmCore::readU30(pc);
				byte *target = (byte *) ((uintptr(AvmCore::readU30(pc)) << 32));
				target = (byte*)((uintptr)target | base);
				#else
				const byte *target = (const byte *) AvmCore::readU30(pc);
				#endif
				code_start = pc = (const byte*) target;
				NEXT();
            }
			}
			// illegal instruction or accidental break
			AvmAssert(false);
		}

		}

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
