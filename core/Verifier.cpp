/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
/* vi: set ts=4 sw=4: */
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
#include <limits.h> // for SIZE_MAX, UINT_MAX

#if defined AVMPLUS_MIR
    #include "../codegen/CodegenMIR.h"
    #define JIT_ONLY(x) x
    #define MIR_ONLY(x) x
    #define LIR_ONLY(x)
#elif defined FEATURE_NANOJIT
    #include "../codegen/CodegenLIR.h"
    #define JIT_ONLY(x) x
    #define MIR_ONLY(x) 
    #define LIR_ONLY(x) x
#else
    #define JIT_ONLY(x) 
    #define MIR_ONLY(x) 
    #define LIR_ONLY(x) 
#endif

#include "FrameState.h"

#ifdef AVMPLUS_WORD_CODE
    #define XLAT_ONLY(x) x
#else
    #define XLAT_ONLY(x)
#endif


namespace avmplus
{
#undef DEBUG_EARLY_BINDING

#ifdef AVMPLUS_WORD_CODE
    inline WordOpcode wordCode(AbcOpcode opcode) {
        return (WordOpcode)opcodeInfo[opcode].wordCode;
    }
#endif
    
    Verifier::Verifier(MethodInfo* info, Toplevel* toplevel
#ifdef AVMPLUS_VERBOSE
        , bool secondTry
#endif
        )
    {
#ifdef AVMPLUS_VERBOSE
        this->secondTry = secondTry;
#endif
        this->info   = info;
		this->core   = info->pool->core;
        this->pool   = info->pool;
        this->toplevel = toplevel;
#ifdef AVMPLUS_WORD_CODE
        this->translator = NULL;
#endif

        #if defined FEATURE_BUFFER_GUARD && defined AVMPLUS_MIR
        this->growthGuard = 0;
        #endif /* FEATURE_BUFFER_GUARD && AVMPLUS_MIR */

        #ifdef AVMPLUS_VERBOSE
        this->verbose = pool->verbose || (info->flags & AbstractFunction::VERBOSE_VERIFY);
        #endif

        const byte* pos = info->body_pos;
        max_stack = AvmCore::readU30(pos);
        local_count = AvmCore::readU30(pos);
        int init_scope_depth = AvmCore::readU30(pos);
        int max_scope_depth = AvmCore::readU30(pos);
        max_scope = max_scope_depth - init_scope_depth;

        stackBase = scopeBase + max_scope;
        frameSize = stackBase + max_stack;

        if ((init_scope_depth < 0) || (max_scope_depth < 0) || (max_stack < 0) || 
            (max_scope < 0) || (local_count < 0) || (frameSize < 0) || (stackBase < 0))
            verifyFailed(kCorruptABCError);

        code_length = AvmCore::readU30(pos);

        code_pos = pos;

        pos += code_length;
        
        exceptions_pos = pos;

        blockStates = NULL;
        state       = NULL;
        labelCount = 0;

        if (info->declaringTraits == NULL)
        {
            // scope hasn't been captured yet.
            verifyFailed(kCannotVerifyUntilReferencedError);
        }
    }

    Verifier::~Verifier()
    {
        if (blockStates)
        {
            MMgc::GC* gc = core->GetGC();
            for(int i=0, n=blockStates->size(); i<n; i++)
            {
                FrameState* state = blockStates->at(i);
                if (state)
                {
                    gc->Free(state);
                }
            }
            blockStates->clear();
            delete blockStates;
        }

		// FIXME need mm policy
        if (teeWriter) delete teeWriter;
#if 0
		if (cfgWriter) delete cfgWriter;
#endif
    }

    /**
     * (done) branches stay in code block
     * (done) branches end on even instr boundaries
     * (done) all local var operands stay inside [0..max_locals-1]
     * (done) no illegal opcodes
     * (done) cpool refs are inside [1..cpool_size-1]
     * (done) converging paths have same stack depth
     * (done) operand stack stays inside [0..max_stack-1]
     * (done) locals defined before use
     * (done) scope stack stays bounded
     * (done) getScopeObject never exceeds [0..info->maxScopeDepth()-1]
     * (done) global slots limits obeyed [0..var_count-1]
     * (done) callstatic method limits obeyed [0..method_count-1]
     * (done) cpool refs are correct type
     * (done) make sure we don't fall off end of function
     * (done) slot based ops are ok (slot must be legal)
      * (done) propref ops are ok: usage on actual type compatible with ref type.
     * dynamic lookup ops are ok (type must not have that binding & must be dynamic)
     * dont access superclass state in ctor until super ctor called.
     * @param pool
     * @param info
     */
#if defined AVMPLUS_MIR
    void Verifier::verify(CodegenMIR * volatile jit)
#elif defined FEATURE_NANOJIT
    void Verifier::verify(CodegenLIR * volatile jit)
#else
    void Verifier::verify()
#endif
    {
      //printf("begin verify\n");
        SAMPLE_FRAME("[verify]", core);

        #ifdef AVMPLUS_VERBOSE
        if (verbose)
            core->console << "verify " << info << '\n';
        secondTry = false;
        #endif

        info->localCount = local_count;
        info->maxScopeDepth = max_scope;
#ifdef AVMPLUS_64BIT
        info->frameSize = frameSize;
#else
        // The interpreter wants this to be padded to a doubleword boundary because
        // it allocates two objects in a single alloca() request - the frame and
        // auxiliary storage, in that order - and wants the second object to be
        // doubleword aligned.
        info->frameSize = (frameSize + 1) & ~1;
#endif
#ifndef AVMPLUS_WORD_CODE
        // For word code, it is set by the WordcodeTranslator epilogue
        info->codeStart = code_pos;
#endif

#ifdef AVMPLUS_WORD_CODE
       // If MIR generation fails due to OOM then we must translate anyhow,
       // FIXME - logic for that looks unclear.
       // Also unclear if any of the existing logic is working, since none
       // of it can really handle running out of memory anyhow.
       // FIXME - if MIR generation doesn't fail, then we've translated for
       // no good reason.
#    ifdef AVMPLUS_DIRECT_THREADED
        this->translator = new WordcodeEmitter(info, interpGetOpcodeLabels());
#    else
        // the jit can fail, and we dont want to have to re-run the verifier
        // until we know it's safe to do so, so run jit & translator concurrently.
        //this->translator = jit ? 0 : new WordcodeEmitter(info);
        this->translator = new WordcodeEmitter(info);
#    endif
        WordcodeTranslator *translator = this->translator;
#endif
		// keep reference here for memory management
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		this->teeWriter = new TeeWriter (NULL, translator, jit);
		this->coder = this->teeWriter;
#else
		this->teeWriter = NULL;
		this->coder = this->translator;
#endif

        JIT_ONLY( this->jit = jit; )
        if ( (state = newFrameState()) == 0 ){
            verifyFailed(kCorruptABCError);
        }
        for (int i=0, n=frameSize; i < n; i++)
            state->setType(i, NULL);

        if (info->flags & AbstractFunction::NEED_REST)
        {
            // param_count+1 <= max_reg
            checkLocal(info->param_count+1);

            state->setType(info->param_count+1, ARRAY_TYPE, true);

            #ifdef AVMPLUS_VERBOSE
            if (verbose && (info->flags & AbstractFunction::NEED_ARGUMENTS))
            {
                // warning, NEED_ARGUMENTS wins
                core->console << "WARNING, NEED_REST overrides NEED_ARGUMENTS when both are set\n";
            }
            #endif
        }
        else if (info->flags & AbstractFunction::NEED_ARGUMENTS)
        {
            // param_count+1 <= max_reg
            checkLocal(info->param_count+1);

            // E3 style arguments array is an Object, E4 says Array, E4 wins...
            state->setType(info->param_count+1, ARRAY_TYPE, true);
        }
        else
        {
            // param_count <= max_reg
            checkLocal(info->param_count);
        }

        // initialize method param types.
        // We already verified param_count is a legal register so
        // don't checkLocal(i) inside the loop.
        // AbstractFunction::verify takes care of resolving param&return type
        // names to Traits pointers, and resolving optional param default values.
        for (int i=0, n=info->param_count; i <= n; i++)
        {
            bool notNull = (i==0); // this is not null, but other params could be
            state->setType(i, info->paramTraits(i), notNull);
        }

        // initial scope chain types 
        int outer_depth = 0;

        ScopeTypeChain* scope = info->declaringTraits->scope;
        if (!scope && info->declaringTraits->init != info)
        {
            // this can occur when an activation scope inside a class instance method
            // contains a nested getter, setter, or method.  In that case the scope 
            // is not captured when the containing function is verified.  This isn't a
            // bug because such nested functions aren't suppported by AS3.  This
            // verify error is how we don't let those constructs run.
            verifyFailed(kNoScopeError, core->toErrorString(info));
        }

        state->scopeDepth = outer_depth;

        // resolve catch block types
        parseExceptionHandlers();
        XLAT_ONLY( if (translator) translator->computeExceptionFixups() );

        // Save initial state
        FrameState* initialState = newFrameState();
        if( !initialState->init(state) ) 
            verifyFailed(kCorruptABCError);

        int actualCount = 0;
        blockEnd = false;    // extended basic block ending

        // always load the entry state, no merge on second pass
    	state->init(initialState);

#ifdef FEATURE_BUFFER_GUARD
		#ifdef AVMPLUS_MIR
		// allow the jit buffer to grow dynamically
		GrowthGuard guard(jit ? jit->mirBuffer : NULL);
		this->growthGuard = &guard;
		#endif //AVMPLUS_MIR
#endif /* FEATURE_BUFFER_GUARD */

		TRY(core, kCatchAction_Rethrow) {

#if 0
		coder->writePrologue(state);
#else   // FIXME lars says we should just fail if we start but can't finish jitting
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit)
		{
			if( !jit->prologue(state) ) 
			{
				if (!jit->overflow)
					verifyFailed(kCorruptABCError);

				// we're out of code memory so try to carry on with interpreter
				jit = 0;
				this->jit = 0;
				// FIXME need to zero out reference in TeeWriter too!
			}
		}
		#endif
#endif
#if defined DEBUGGER && defined AVMPLUS_WORD_CODE
		XLAT_ONLY( if (translator && core->debugger()) translator->emitOp0(code_pos, WOP_debugenter); )
#endif

        PERFM_NVPROF("abc-bytes", code_length);

		int size;
		for (const byte* pc = code_pos, *code_end=code_pos+code_length; pc < code_end; pc += size)
		{
			SAMPLE_CHECK();
            PERFM_NVPROF("abc-verify", 1);

			// FIXME just give up in this case
		    JIT_ONLY(if (jit && jit->overflow) {
				jit = 0;
				this->jit = 0;
				// FIXME need to zero out reference in TeeWriter too!
			})
			
			XLAT_ONLY( if (translator) translator->fixExceptionsAndLabels(pc); )
			
			AbcOpcode opcode = (AbcOpcode) *pc;
			if (opcodeInfo[opcode].operandCount == -1)
				verifyFailed(kIllegalOpcodeError, core->toErrorString(info), core->toErrorString(opcode), core->toErrorString((int)(pc-code_pos)));

			if (opcode == OP_label)
			{
				// insert a label here
			    // FIXME not necessarily the target of a backward edge. maybe the abc parser 
			    //       should erase labels that are not sinks of back edges.
				getFrameState((int)(pc-code_pos))->targetOfBackwardsBranch = true;
			}

			bool unreachable = false;
			FrameState* blockState;
			if ( blockStates && (blockState = blockStates->get((uintptr)pc)) != 0 )
			{
				// send a bbend prior to the merge
				JIT_ONLY( if (jit) jit->emitBlockEnd(state); )

				if (!blockEnd || !blockState->initialized)
				{
					checkTarget(pc); 
				}

				#ifdef AVMPLUS_VERBOSE
				if (verbose)
					core->console << "B" << (pc - code_pos) << ":\n";
				#endif

				// now load the merged state
				state->init(blockState);
				state->targetOfBackwardsBranch = blockState->targetOfBackwardsBranch;
				state->pc = pc - code_pos;

				// found the start of a new basic block
				JIT_ONLY( if (jit) jit->emitBlockStart(state); )

				state->targetOfBackwardsBranch = false;

				actualCount++;
				blockEnd = false;

				if (!blockState->targetOfBackwardsBranch)
				{
                    #ifdef FEATURE_NANOJIT
                        // fixme: CodegenLIR wants to do all patching in epilog() so we cannot
                        // free the block early.
                        if (!jit) {
					        blockStates->remove((uintptr)pc);
					        core->GetGC()->Free(blockState);
                        }
                    #else
                        // jit and translator are okay with this
						blockStates->remove((uintptr)pc);
						core->GetGC()->Free(blockState);
                    #endif
				}
			}
			else
			{
				if (blockEnd)
				{
					// the next instruction is not reachable because it comes after
					// a jump, throw, or return, and there are no branch targets
					// inbetween the branch/jump/return and this instruction.
					// So, don't verify it.
					unreachable = true;
				}
			}

			state->pc = pc - code_pos;
			int sp = state->sp();

			if (info->exceptions)
			{
				JIT_ONLY( bool mirSavedState = false; )
				for (int i=0, n=info->exceptions->exception_count; i < n; i++)
				{
					ExceptionHandler* handler = &info->exceptions->exceptions[i];
					if (pc >= code_pos + handler->from && pc <= code_pos + handler->to)
					{
						// Set the insideTryBlock flag, so the codegen can
						// react appropriately.
						state->insideTryBlock = true;

						// If this instruction can throw exceptions, add an edge to
						// the catch handler.
						if (opcodeInfo[opcode].canThrow || pc == code_pos + handler->from)
						{
							// TODO check stack is empty because catch handlers assume so.
							int saveStackDepth = state->stackDepth;
							int saveScopeDepth = state->scopeDepth;
							state->stackDepth = 0;
							state->scopeDepth = outer_depth;
							Value stackEntryZero = state->stackValue(0);

							JIT_ONLY(if (jit && !mirSavedState) {
								jit->emitBlockEnd(state);
								mirSavedState = true;
							})

							// add edge from try statement to catch block
							const byte* target = code_pos + handler->target;
							// atom received as *, will coerce to correct type in catch handler.
							state->push(NULL);

                            MIR_ONLY(if (jit) jit->localSet(stackBase, jit->exAtom);)

							checkTarget(target);
 							state->pop();

							state->stackDepth = saveStackDepth;
							state->scopeDepth = saveScopeDepth;
							state->stackValue(0) = stackEntryZero;

							// Search forward for OP_killreg in the try block
							// Set these registers to killed in the catch state
							if (pc == code_pos + handler->from)
							{
								FrameState *catchState = blockStates->get((uintptr)target);
								AvmAssert(catchState != 0);

                                for (const byte *temp = pc; temp <= code_pos + handler->to; )
								{
                                    if( *temp == OP_lookupswitch )
                                    {
                                        // Variable length instruction
										const byte *temp2 = temp+4;
                                        const int case_count = toplevel->readU30(temp2)+1;
										temp += AvmCore::calculateInstructionWidth(temp) + 3*case_count;
                                    }
									else
									{
										// If this instruction is OP_killreg, kill the register
										// in the catch block state too
										if (*temp == OP_kill)
										{
											const byte* temp2 = temp+1;
											int local = toplevel->readU30(temp2);
											if (local >= local_count)
												verifyFailed(kInvalidRegisterError, core->toErrorString(local));
											Value& v = catchState->value(local);
											v.notNull = false;
											v.traits = NULL;
											v.killed = true;
										}
										temp += AvmCore::calculateInstructionWidth(temp);
									}
								}
							}
						}							
					}
					
					if (pc == code_pos + handler->target)
					{
						emitCoerce(handler->traits, sp);
					}
				}
			}
			unsigned int imm30=0, imm30b=0;
			int imm8=0, imm24=0;

			const byte* nextpc = pc;
            AvmCore::readOperands(nextpc, imm30, imm24, imm30b, imm8);
			// make sure U30 operands are within bounds.
			if (opcode != OP_pushshort && ((imm30|imm30b) & 0xc0000000))
			{
				// don't report error if first operand of abs_jump (pc) is large.
				if (opcode != OP_abs_jump || (imm30b & 0xc0000000))
				{
					verifyFailed(kCorruptABCError);
				}
			}
			size = int(nextpc-pc);
			if (pc+size > code_end)
				verifyFailed(kLastInstExceedsCodeSizeError);

			#ifdef AVMPLUS_VERBOSE
			if (verbose) 
			{
				showState(state, pc, unreachable);
			}
			#endif

			if (unreachable)
			{
				// Even if unreachable, we have to properly advance
				// past the variable-sized OP_lookupswitch
				if (opcode == OP_lookupswitch)
					size += 3*(imm30b+1);

				continue;
			}

			switch (opcode)
			{
			case OP_iflt:
			case OP_ifle:
			case OP_ifnlt:
			case OP_ifnle:
			case OP_ifgt:
			case OP_ifge:
			case OP_ifngt:
			case OP_ifnge:
			case OP_ifeq:
			case OP_ifstricteq:
			case OP_ifne:
			case OP_ifstrictne:
			    checkStack(2,0);
				coder->writeOp1(state, pc, opcode, imm24);
				state->pop(2);
				checkTarget(nextpc+imm24);
				break;

			case OP_iftrue:
			case OP_iffalse:
			    checkStack(1,0);
				coder->writeOp1(state, pc, opcode, imm24);
				state->pop();
				checkTarget(nextpc+imm24);
				break;

			case OP_jump:
			    //checkStack(0,0)
				coder->writeOp1(state, pc, opcode, imm24);
			    checkTarget(nextpc+imm24);	// target block;
				blockEnd = true;
				break;

			case OP_lookupswitch: 
			{
				checkStack(1,0);
				peekType(INT_TYPE);
				coder->write(state, pc, opcode);
				state->pop();
				checkTarget(pc+imm24);
				uint32_t case_count = 1 + imm30b;
				if (pc + size + 3*case_count > code_end) 
				    verifyFailed(kLastInstExceedsCodeSizeError);
				for (uint32_t i=0; i < case_count; i++) 
				{
				    int off = AvmCore::readS24(pc+size);
					checkTarget(pc+off);
					size += 3;
				}
				blockEnd = true;
				break;
			}

			case OP_throw:
			case OP_returnvalue:
			    checkStack(1,0);
				coder->write(state, pc, opcode);
				state->pop();
				blockEnd = true;
				break;

			case OP_returnvoid: 
				//checkStack(0,0)
			    coder->write(state, pc, opcode);
				blockEnd = true;
				break;

			case OP_pushnull:
				checkStack(0,1);
			    coder->write(state, pc, opcode);
				state->push(NULL_TYPE);
				break;

			case OP_pushundefined:
				checkStack(0,1);
			    coder->write(state, pc, opcode);
				state->push(VOID_TYPE);
				break;

			case OP_pushtrue:
				checkStack(0,1);
				coder->write(state, pc, opcode);
				state->push(BOOLEAN_TYPE, true);
				break;

			case OP_pushfalse:
				checkStack(0,1);
				coder->write(state, pc, opcode);
				state->push(BOOLEAN_TYPE, true);
				break;

			case OP_pushnan:
				checkStack(0,1);
				coder->write(state, pc, opcode);
				state->push(NUMBER_TYPE, true);
				break;

			case OP_pushshort:
				checkStack(0,1);
				coder->write(state, pc, opcode);
				state->push(INT_TYPE, true);
				break;

			case OP_pushbyte:
				checkStack(0,1);
				coder->write(state, pc, opcode);
				state->push(INT_TYPE, true);
				break;

			case OP_debugfile:
				//checkStack(0,0)
                #if defined(DEBUGGER) || defined(VTUNE)
				checkCpoolOperand(imm30, kStringType);
                #endif
				coder->write(state, pc, opcode);
				break;

			case OP_dxns:
				//checkStack(0,0)
				if (!info->isFlagSet(AbstractFunction::SETS_DXNS))
					verifyFailed(kIllegalSetDxns, core->toErrorString(info));
				checkCpoolOperand(imm30, kStringType);
				coder->write(state, pc, opcode);
				break;

			case OP_dxnslate:
				checkStack(1,0);
				if (!info->isFlagSet(AbstractFunction::SETS_DXNS))
					verifyFailed(kIllegalSetDxns, core->toErrorString(info));
				// codgen will call intern on the input atom.
				coder->write(state, pc, opcode);
				state->pop();
				break;

			case OP_pushstring:
				checkStack(0,1);
				if (imm30 == 0 || imm30 >= pool->constantStringCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(imm30), core->toErrorString(pool->constantStringCount));
				coder->write(state, pc, opcode);
				state->push(STRING_TYPE, pool->cpool_string[imm30] != NULL);
				break;

			case OP_pushint: 
				checkStack(0,1);
				if (imm30 == 0 || imm30 >= pool->constantIntCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(imm30), core->toErrorString(pool->constantIntCount));
				coder->write(state, pc, opcode);
				state->push(INT_TYPE,true);
				break;

			case OP_pushuint: 
				checkStack(0,1);
				if (imm30 == 0 || imm30 >= pool->constantUIntCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(imm30), core->toErrorString(pool->constantUIntCount));
				coder->write(state, pc, opcode);
				state->push(UINT_TYPE,true);
				break;

			case OP_pushdouble: 
				checkStack(0,1);
				if (imm30 == 0 || imm30 >= pool->constantDoubleCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(imm30), core->toErrorString(pool->constantDoubleCount));
				coder->write(state, pc, opcode);
				state->push(NUMBER_TYPE, true);
				break;

			case OP_pushnamespace: 
				checkStack(0,1);
				if (imm30 == 0 || imm30 >= pool->constantNsCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(imm30), core->toErrorString(pool->constantNsCount));
				coder->write(state, pc, opcode);
				state->push(NAMESPACE_TYPE, pool->cpool_ns[imm30] != NULL);
				break;

			case OP_setlocal:
			{
				checkStack(1,0);
				checkLocal(imm30);
				coder->write(state, pc, opcode);
				Value &v = state->stackTop();
				state->setType(imm30, v.traits, v.notNull);
				state->pop();
				break;
			}

			case OP_setlocal0:
			case OP_setlocal1:
			case OP_setlocal2:
			case OP_setlocal3:				
			{
				checkStack(1,0);
				int index = opcode-OP_setlocal0;
				checkLocal(index);
				coder->write(state, pc, opcode);
				Value &v = state->stackTop();
				state->setType(index, v.traits, v.notNull);
				state->pop();
				break;
			}
			case OP_getlocal:
				checkStack(0,1);
				coder->write(state, pc, opcode);
				state->push(checkLocal(imm30));
				break;

			case OP_getlocal0:
			case OP_getlocal1:
			case OP_getlocal2:
			case OP_getlocal3:
				checkStack(0,1);
				coder->write(state, pc, opcode);
				state->push(checkLocal(opcode-OP_getlocal0));
				break;
			
			case OP_kill:
			{
				//checkStack(0,0)
			    Value &v = checkLocal(imm30);
				coder->write(state, pc, opcode);
				v.notNull = false;
				v.traits = NULL;
				break;
			}

			case OP_inclocal:
			case OP_declocal:
			    //checkStack(0,0);
				checkLocal(imm30);
				emitCoerce(NUMBER_TYPE, imm30);
				coder->write(state, pc, opcode);
				break;

			case OP_inclocal_i:
			case OP_declocal_i:
				//checkStack(0,0);
				checkLocal(imm30);
				emitCoerce(INT_TYPE, imm30);
				coder->write(state, pc, opcode);
				break;

			case OP_newfunction: 
			{
				checkStack(0,1);
				AbstractFunction* f = checkMethodInfo(imm30);
				// Duplicate function definitions can happen with well formed ABC data.  We need
				// to clear out data on AbstractionFunction so it can correctly be re-initialized.
				// If our old function is ever used incorrectly, we throw an verify error in 
				// MethodEnv::coerceEnter.
				if (f->declaringTraits)
				{
				    f->flags &= ~AbstractFunction::LINKED;
					f->declaringTraits = NULL;
				}
				f->setParamType(0, NULL);
				f->makeIntoPrototypeFunction(toplevel);
				Traits* ftraits = f->declaringTraits;
				// make sure the traits of the base vtable matches the base traits
				// This is also caught by an assert in VTable.cpp, however that turns
				// out to be too late and may cause crashes
				if (toplevel->functionClass != 0 &&
                    ftraits->base != toplevel->functionClass->ivtable()->traits )
				{
					AvmAssertMsg(0, "Verify failed:OP_newfunction");
 					if (toplevel->verifyErrorClass() != NULL)
 						verifyFailed(kInvalidBaseClassError);
				}
				int extraScopes = state->scopeDepth;
				ftraits->scope = ScopeTypeChain::create(core->GetGC(), scope, extraScopes);
				for (int i=0,j=scope->size, n=state->scopeDepth; i < n; i++, j++)
				{
					ftraits->scope->setScopeAt(j, state->scopeValue(i).traits, state->scopeValue(i).isWith);
				}
				if (f->activationTraits)
				{
					// ISSUE - if nested functions, need to capture scope, not make a copy
					f->activationTraits->scope = ftraits->scope;
				}
#ifdef AVMPLUS_VERIFYALL
				core->enqFunction(f);
#endif
				coder->write(state, pc, opcode);
				state->push(ftraits, true);
				break;
			}

			case OP_getlex:
			{
				if (state->scopeDepth + scope->size == 0)
					verifyFailed(kFindVarWithNoScopeError);
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(0, 1, &multiname);
				if (multiname.isRuntime())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(opcode), core->toErrorString(&multiname));
				emitFindProperty(OP_findpropstrict, multiname, imm30, pc);
				emitGetProperty(multiname, 1, imm30, pc);
				break;
			}

			case OP_findpropstrict:
			case OP_findproperty:
			{
				if (state->scopeDepth + scope->size == 0)
					verifyFailed(kFindVarWithNoScopeError);
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(0, 1, &multiname);
				emitFindProperty(opcode, multiname, imm30, pc);
				break;
			}

			case OP_newclass: 
			{
				checkStack(1, 1);
				// must be a CONSTANT_Multiname
				Traits* ctraits = checkClassInfo(imm30);
				// the actual result type will be the static traits of the new class.				
				// make sure the traits came from this pool.  they have to because
				// the class_index operand is resolved from the current pool.
				AvmAssert(ctraits->pool == pool);
				Traits *itraits = ctraits->itraits;
				int captureScopes = state->scopeDepth;
				ScopeTypeChain* cscope = ScopeTypeChain::create(core->GetGC(), scope, captureScopes, 1);
				int j=scope->size;
				for (int i=0, n=state->scopeDepth; i < n; i++, j++)
				{
					cscope->setScopeAt(j, state->scopeValue(i).traits, state->scopeValue(i).isWith);
				}

				// add a type constraint for the "this" scope of static methods
				cscope->setScopeAt(state->scopeDepth, ctraits, false);

				if (state->scopeDepth > 0)
				{
					// innermost scope must be the base class object or else createInstance()
					// will malfunction because it will use the wrong [base] class object to
					// construct the instance.  See ScriptObject::createInstance()
					Traits* baseCTraits = state->scopeValue(state->scopeDepth-1).traits;
					if (!baseCTraits || baseCTraits->itraits != itraits->base)
						verifyFailed(kCorruptABCError);
				}

				ScopeTypeChain* iscope = ScopeTypeChain::create(core->GetGC(), cscope, 1, 1);
				iscope->setScopeAt(iscope->size-1, ctraits, false);

				// add a type constraint for the "this" scope of instance methods
				iscope->setScopeAt(iscope->size, itraits, false);

				ctraits->scope = cscope;
				itraits->scope = iscope;

				ctraits->resolveSignatures(toplevel);
				itraits->resolveSignatures(toplevel);

				#ifdef AVMPLUS_VERIFYALL
				core->enqTraits(ctraits);
				core->enqTraits(itraits);
				#endif

				emitCoerce(CLASS_TYPE, state->sp()); // make sure base class is really a class
				coder->write(state, pc, opcode);
				state->pop_push(1, ctraits, true);
				break;
			}

			case OP_finddef:
			{
				// must be a CONSTANT_Multiname.
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(0, 1, &multiname);
				if (!multiname.isBinding())
				{
					// error, def name must be CT constant, regular name
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(opcode), core->toErrorString(&multiname));
				}
				coder->write(state, pc, opcode);
				AbstractFunction* script = (AbstractFunction*)pool->getNamedScript(&multiname);
				if (script != (AbstractFunction*)BIND_NONE && script != (AbstractFunction*)BIND_AMBIGUOUS)
				{
					// found a single matching traits
					state->push(script->declaringTraits, true);
				}
				else
				{
					// no traits, or ambiguous reference.  use Object, anticipating
					// a runtime exception
					state->push(OBJECT_TYPE, true);
				}
				break;
			}

			case OP_setproperty:
			case OP_initproperty:
			{
			    // FIXME use pipeline
				// stack in: object [ns] [name] value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname); // CONSTANT_Multiname
				checkStackMulti(2, 0, &multiname);

				uint32_t n=2;
				checkPropertyMultiname(n, multiname);
				Value& obj = state->peek(n);
				emitCheckNull(sp-(n-1));

				Binding b = toplevel->getBinding(obj.traits, &multiname);
				bool needsSetContext = true;
				Traits* propTraits = readBinding(obj.traits, b);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT || defined AVMPLUS_WORD_CODE
				if (AvmCore::isSlotBinding(b) && /*jit &&*/
					// it's a var, or a const being set from the init function
					(!AvmCore::isConstBinding(b) || 
						obj.traits->init == info && opcode == OP_initproperty))
				{
					emitCoerce(propTraits, state->sp());
					coder->writeOp2(state, pc, OP_setslot, (uint32_t)AvmCore::bindingToSlotId(b), sp-(n-1), propTraits);
					//MIR_ONLY( if (jit) jit->emit(state, OP_setslot, AvmCore::bindingToSlotId(b), sp-(n-1), propTraits); );
					state->pop(n);
					break;
				}
				// else: setting const from illegal context, fall through
				#else
				(void)propTraits;
				#endif
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				// If it's an accessor that we can early bind, do so.
				// Note that this cannot be done on String or Namespace,
				// since those are represented by non-ScriptObjects
				if (jit && AvmCore::hasSetterBinding(b))
				{
					// early bind to the setter
					int disp_id = AvmCore::bindingToSetterId(b);
					const TraitsBindingsp objtd = obj.traits->getTraitsBindings();
					AbstractFunction *f = objtd->getMethod(disp_id);
					AvmAssert(f != NULL);
					emitCoerceArgs(f, 1);
					jit->emitSetContext(state, f);
					Traits* result = f->returnTraits();
					if (!obj.traits->isInterface)
					    jit->writeOp2(state, pc, OP_callmethod, disp_id, 1, result);
					else
					    jit->emitCall(state, OP_callinterface, f->iid(), 1, result);
					XLAT_ONLY( if (translator) translator->emitOp1(pc, wordCode(opcode)) );
					state->pop(n);
					break;
				}
				#endif

				#ifdef DEBUG_EARLY_BINDING
				core->console << "verify setproperty " << obj.traits << " " << &multiname->getName() << " from within " << info << "\n";
				#endif

				if( obj.traits == VECTORINT_TYPE  || obj.traits == VECTORUINT_TYPE ||
					obj.traits == VECTORDOUBLE_TYPE )
				{
					bool attr = multiname.isAttr();
					Traits* indexType = state->value(state->sp()-1).traits;

					bool maybeIntegerIndex = !attr && multiname.isRtname() && multiname.contains(core->publicNamespace);

					if( maybeIntegerIndex && (indexType == UINT_TYPE || indexType == INT_TYPE) )
					{
						needsSetContext = false;
						if(obj.traits == VECTORINT_TYPE)
							emitCoerce(INT_TYPE, state->sp());
						else if(obj.traits == VECTORUINT_TYPE)
							emitCoerce(UINT_TYPE, state->sp());
						else if(obj.traits == VECTORDOUBLE_TYPE)
							emitCoerce(NUMBER_TYPE, state->sp());
					}
				}

				// not a var binding or early bindable accessor
				coder->write(state, pc, opcode);
				state->pop(n);
				break;
			}

			case OP_getproperty:
			{
				// stack in: object [ns [name]]
				// stack out: value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname); // CONSTANT_Multiname
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);
				emitGetProperty(multiname, n, imm30, pc);
				break;
			}

			case OP_getdescendants:
			{
				// stack in: object [ns] [name]
				// stack out: value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);
				emitCheckNull(sp-(n-1));
				coder->write(state, pc, opcode);
				state->pop_push(n, NULL);
				break;
			}

			case OP_checkfilter:
				checkStack(1, 1);
				emitCheckNull(sp);
				coder->write(state, pc, opcode);
				break;

			case OP_deleteproperty:
			{
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);
				emitCheckNull(sp-(n-1));
				coder->write(state, pc, opcode);
				state->pop_push(n, BOOLEAN_TYPE);
				break;
			}

			case OP_astype:
			{
				checkStack(1, 1);
				// resolve operand into a traits, and push that type.
				Traits *t = checkTypeName(imm30); // CONSTANT_Multiname
				int index = sp;
				Traits* rhs = state->value(index).traits;
				if (!canAssign(t, rhs) || !Traits::isMachineCompatible(t, rhs))
				{
					Traits* resultType = t;
					// result is typed value or null, so if type can't hold null,
					// then result type is Object. 
					if (t && t->isMachineType())
						resultType = OBJECT_TYPE;
					coder->write(state, pc, opcode);
					state->pop_push(1, t);
				}
				break;
			}

			case OP_astypelate:
			{
				checkStack(2,1);
				Value& classValue = state->peek(1); // rhs - class
				Traits* ct = classValue.traits;
				Traits* t = NULL;
				if (ct && (t=ct->itraits) != 0)
					if (t->isMachineType())
						t = OBJECT_TYPE;
				coder->write(state, pc, opcode);
				state->pop_push(2, t);
				break;
			}

			case OP_coerce:
			{
				checkStack(1,1);
				coder->write(state, pc, opcode);
				Traits* type = checkTypeName(imm30);
				Value &v = state->value(sp);
				state->setType(sp, type, v.notNull);
				break;
			}

			case OP_convert_b:
			case OP_coerce_b:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, BOOLEAN_TYPE, state->value(sp).notNull);
				break;

			case OP_coerce_o:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, OBJECT_TYPE, state->value(sp).notNull);
				break;

			case OP_coerce_a:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, NULL, state->value(sp).notNull);
				break;

			case OP_convert_i:
			case OP_coerce_i:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, INT_TYPE, state->value(sp).notNull);
				break;

			case OP_convert_u:
			case OP_coerce_u:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, UINT_TYPE, state->value(sp).notNull);
				break;

			case OP_convert_d:
			case OP_coerce_d:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, NUMBER_TYPE, state->value(sp).notNull);
				break;

			case OP_coerce_s:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, STRING_TYPE, state->value(sp).notNull);
				break;

			case OP_istype: 
				checkStack(1,1);
				// resolve operand into a traits, and test if value is that type
				checkTypeName(imm30); // CONSTANT_Multiname
				coder->write(state, pc, opcode);
				state->pop(2);
				state->push(OBJECT_TYPE);
				state->push(INT_TYPE);
				break;

			case OP_istypelate: 
				checkStack(2,1);
				coder->write(state, pc, opcode);
				// TODO if the only common base type of lhs,rhs is Object, then result is always false
				state->pop_push(2, BOOLEAN_TYPE);
				break;

			case OP_convert_o:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				// ISSUE should result be Object, laundering the type?
				// ToObject throws an exception on null and undefined, so after this runs we
				// know the value is safe to dereference.
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				setNotNull(sp);
#endif
				break;

			case OP_convert_s: 
			case OP_esc_xelem: 
			case OP_esc_xattr:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				// this is the ECMA ToString and ToXMLString operators, so the result must not be null
				// (ToXMLString is split into two variants - escaping elements and attributes)
				state->setType(sp, STRING_TYPE, true);				
				break;

			case OP_callstatic: 
			{
				AbstractFunction* m = checkMethodInfo(imm30);
				const uint32_t argc = imm30b;
				checkStack(argc+1, 1);
				if (!m->paramTraits(0))
				{
					verifyFailed(kDanglingFunctionError, core->toErrorString(m), core->toErrorString(info));
				}
				emitCoerceArgs(m, argc);
				int method_id = m->method_id;
				Traits* resultType = m->returnTraits();
				coder->writeOp2(state, pc, OP_callstatic, (uint32_t)method_id, argc, resultType);
				state->pop_push(argc+1, resultType);
				break;
			}

			case OP_call:
			{
				const uint32_t argc = imm30;
				checkStack(argc+2, 1);
				// don't need null check, AvmCore::call() uses toFunction() for null check.
				
				/* 
					TODO optimizations
					    - if this is a class closure for a non-native type, call == coerce
						- if this is a function closure, try early binding using the traits->call sig
						- optimize simple cases of casts to builtin types
				*/

				coder->writeOp1(state, pc, opcode, argc);
				state->pop_push(argc+2, NULL);
				break;
			}

			case OP_construct: 
			{
				const uint32_t argc = imm30;
				checkStack(argc+1, 1);
				coder->writeOp1(state, pc, opcode, argc);
				Traits* ctraits = state->peek(argc+1).traits;
				// don't need null check, AvmCore::construct() uses toFunction() for null check.
				Traits* itraits = ctraits ? ctraits->itraits : NULL;
				state->pop_push(argc+1, itraits, true);
				break;
			}

			case OP_callmethod: 
			{
				/*
					OP_callmethod will always throw a verify error.  that's on purpose, it's a 
					last minute change before we shipped FP9 and was necessary when we added methods to class Object.
					 
					since then we realized that OP_callmethod need only have failed when used outside
					of the builtin abc, but it's a moot point now.  We dont have to worry about it.
					 
					code has since been simplified but existing failure modes preserved.
				*/
				const uint32_t argc = imm30b;
				const int disp_id = imm30-1;
				checkStack(argc+1,1);
				if (disp_id >= 0)
				{
					Value& obj = state->peek(argc+1);
					if( !obj.traits ) 
						verifyFailed(kCorruptABCError);
					else
						verifyFailed(kIllegalEarlyBindingError, core->toErrorString(obj.traits));
				}
				else
				{
					verifyFailed(kZeroDispIdError);
				}
				break;
			}

			case OP_callproperty: 
			case OP_callproplex: 
			case OP_callpropvoid:
			{
				// stack in: obj [ns [name]] args
				// stack out: result
				const uint32_t argc = imm30b;
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(argc+1, 1, &multiname);
				checkCallMultiname(opcode, &multiname);
				uint32_t n = argc+1; // index of receiver
				checkPropertyMultiname(n, multiname);
				emitCallproperty(opcode, sp, multiname, imm30, imm30b, pc);
				break;
			}

			case OP_constructprop: 
			{
			    // FIXME use pipeline
				// stack in: obj [ns [name]] args
				const uint32_t argc = imm30b;
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(argc+1, 1, &multiname);
				checkCallMultiname(opcode, &multiname);
				uint32_t n = argc+1; // index of receiver
				checkPropertyMultiname(n, multiname);
				Value& obj = state->peek(n); // make sure object is there
				emitCheckNull(sp-(n-1));
				#ifdef DEBUG_EARLY_BINDING
				//core->console << "verify constructprop " << t << " " << multiname->getName() << " from within " << info << "\n";
				#endif

				Binding b = toplevel->getBinding(obj.traits, &multiname);
				if (AvmCore::isSlotBinding(b))
				{
					JIT_ONLY( int slot_id = AvmCore::bindingToSlotId(b); )
					Traits* ctraits = readBinding(obj.traits, b);
					MIR_ONLY( if (jit) jit->emit(state, OP_getslot, slot_id, sp-(n-1), ctraits); )
					LIR_ONLY( if (jit) jit->emitGetslot(state, slot_id, sp-(n-1), ctraits); )
					obj.notNull = false;
					obj.traits = ctraits;
					Traits* itraits = ctraits ? ctraits->itraits : NULL;
					#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					if (jit)
					{
						jit->emitSetContext(state, NULL);
						if( itraits && !itraits->hasCustomConstruct && itraits->init->argcOk(argc))
						{
							emitCheckNull(sp-(n-1));
							emitCoerceArgs(itraits->init, argc, true);
							jit->emitCall(state, OP_construct, 0, argc, itraits);
						}
						else
						{
							jit->emit(state, OP_construct, argc, 0, itraits);
						}
					}
					#endif
					state->pop_push(argc+1, itraits, true);
					XLAT_ONLY( if (translator) translator->emitOp2(pc, WOP_constructprop) );
				}
				else
				{
				    // don't know the binding now, resolve at runtime
				    coder->write(state, pc, opcode);
					state->pop_push(n, NULL);
				}
				break;
			}

			case OP_applytype:
			{
				// in: factory arg1..N
				// out: type
				const uint32_t argc = imm30;
				checkStack(argc+1, 1);
				coder->write(state, pc, opcode);
				state->pop_push(argc+1, NULL, true);
				break;
			}

			case OP_callsuper:
			case OP_callsupervoid:
			{
			    // FIXME use pipeline
				// stack in: obj [ns [name]] args
				const uint32_t argc = imm30b;
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(argc+1, 1, &multiname);

				if (multiname.isAttr())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(&multiname));
				
				uint32_t n = argc+1; // index of receiver
				checkPropertyMultiname(n, multiname);

				emitCheckNull(sp-(n-1));
				Traits* base = emitCoerceSuper(sp-(n-1));
				const TraitsBindingsp basetd = base->getTraitsBindings();

				Binding b = toplevel->getBinding(base, &multiname);
				if (AvmCore::isMethodBinding(b))
				{
					int disp_id = AvmCore::bindingToMethodId(b);
					AbstractFunction* m = basetd->getMethod(disp_id);
					if( !m ) verifyFailed(kCorruptABCError);
					emitCoerceArgs(m, argc);
					Traits* resultType = m->returnTraits();
					#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					if (jit) 
					{
						jit->emitSetContext(state, m);
						jit->emitCall(state, OP_callsuperid, disp_id, argc, resultType);
					}
					#endif
					state->pop_push(n, resultType);
					if (opcode == OP_callsupervoid)
						state->pop();
					goto callsuper_end;
				}

				#ifdef DEBUG_EARLY_BINDING
				core->console << "verify callsuper " << base << " " << multiname.getName() << " from within " << info << "\n";
				#endif

				// TODO optimize other cases
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname, argc, NULL);
				}
				#endif
				state->pop_push(n, NULL);
				if (opcode == OP_callsupervoid)
					state->pop();
			callsuper_end:
				XLAT_ONLY( if (translator) translator->emitOp2(pc, wordCode(opcode)) );
				break;
			}

			case OP_getsuper:
			{
			    // FIXME use pipeline
				// stack in: obj [ns [name]]
				// stack out: value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);

				if (multiname.isAttr())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(&multiname));

				Traits* base = emitCoerceSuper(sp-(n-1));

				Binding b = toplevel->getBinding(base, &multiname);
				Traits* propType = readBinding(base, b);
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp-(n-1));

					if (AvmCore::isSlotBinding(b))
					{
						int slot_id = AvmCore::bindingToSlotId(b);
						MIR_ONLY(if (jit) jit->emit(state, OP_getslot, slot_id, sp-(n-1), propType);)
						LIR_ONLY(if (jit) jit->emitGetslot(state, slot_id, sp-(n-1), propType);)
						state->pop_push(n, propType);
						goto getsuper_end;
					}

					if (AvmCore::hasGetterBinding(b))
					{
						// Invoke the getter
						int disp_id = AvmCore::bindingToGetterId(b);
						const TraitsBindingsp basetd = base->getTraitsBindings();
						AbstractFunction *f = basetd->getMethod(disp_id);
						AvmAssert(f != NULL);
						emitCoerceArgs(f, 0);
						Traits* resultType = f->returnTraits();
						if (jit) 
						{
							jit->emitSetContext(state, f);
							jit->emitCall(state, OP_callsuperid, disp_id, 0, resultType);
						}
						state->pop_push(n, resultType);
						goto getsuper_end;
					}
				}
				#endif // AVMPLUS_MIR || FEATURE_NANOJIT

				#ifdef DEBUG_EARLY_BINDING
				core->console << "verify getsuper " << base << " " << multiname.getName() << " from within " << info << "\n";
				#endif
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit) 
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname, 0, propType);
				}
				#endif
				state->pop_push(n, propType);
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			getsuper_end:
#endif
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_getsuper) );
				break;
			}

			case OP_setsuper:
			{
			    // FIXME use pipeline
				// stack in: obj [ns [name]] value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(2, 0, &multiname);
				uint32_t n=2;
				checkPropertyMultiname(n, multiname);

				if (multiname.isAttr())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(&multiname));

				JIT_ONLY( Traits* base = ) emitCoerceSuper(sp-(n-1));
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp-(n-1));

					const TraitsBindingsp basetd = base->getTraitsBindings();
					Binding b = toplevel->getBinding(base, &multiname);
					Traits* propType = readBinding(base, b);

					if (AvmCore::isSlotBinding(b))
					{
						if (AvmCore::isVarBinding(b))
						{
							int slot_id = AvmCore::bindingToSlotId(b);
							emitCoerce(propType, sp);
							MIR_ONLY(jit->emit(state, OP_setslot, slot_id, sp-(n-1));)
							LIR_ONLY(jit->emitSetslot(state, OP_setslot, slot_id, sp-(n-1));)
						}
						// else, it's a readonly slot so ignore
						state->pop(n);
						goto setsuper_end;
					}

					if (AvmCore::isAccessorBinding(b))
					{
						if (AvmCore::hasSetterBinding(b))
						{
							// Invoke the setter
							int disp_id = AvmCore::bindingToSetterId(b);
							AbstractFunction *f = basetd->getMethod(disp_id);
							AvmAssert(f != NULL);
							emitCoerceArgs(f, 1);
							jit->emitSetContext(state, f);
							jit->emitCall(state, OP_callsuperid, disp_id, 1, f->returnTraits());
						}
						// else, ignore write to readonly accessor
						state->pop(n);
						goto setsuper_end;
					}

					#ifdef DEBUG_EARLY_BINDING
					core->console << "verify setsuper " << base << " " << multiname.getName() << " from within " << info << "\n";
					#endif

					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname);
				}
				#endif // AVMPLUS_MIR || FEATURE_NANOJIT

				state->pop(n);
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			setsuper_end:
#endif
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_setsuper) );
				break;
			}

			case OP_constructsuper:
			{
			    // FIXME use pipeline
				// stack in: obj, args ...
				const uint32_t argc = imm30;
				checkStack(argc+1, 0);

				int ptrIndex = sp-argc;
				Traits* baseTraits = emitCoerceSuper(ptrIndex); // check receiver

				AbstractFunction *f = baseTraits->init;
				AvmAssert(f != NULL);

				emitCoerceArgs(f, argc);
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					jit->emitSetContext(state, f);
					emitCheckNull(ptrIndex);
					jit->emitCall(state, opcode, 0, argc, VOID_TYPE);
				}
				#endif

				state->pop(argc+1);
				// this is a true void call, no result to push.
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_constructsuper) );
				break;
			}

			case OP_newobject: 
			{
				uint32_t argc = imm30;
				checkStack(2*argc, 1);
				int n=0;
				while (argc-- > 0)
				{
					n += 2;
					peekType(STRING_TYPE, n); // name; will call intern on it 
				}
				coder->write(state, pc, opcode);
				state->pop_push(n, OBJECT_TYPE, true);
				break;
			}

		    case OP_newarray:
				checkStack(imm30, 1);
				coder->write(state, pc, opcode);
				state->pop_push(imm30, ARRAY_TYPE, true);
				break;

			case OP_pushscope: 
			{
			    // FIXME use pipeline
				checkStack(1,0);
				Traits* scopeTraits = state->peek().traits;				
				if (state->scopeDepth+1 > max_scope) 
					verifyFailed(kScopeStackOverflowError);
				if (scope->fullsize > (scope->size+state->scopeDepth))
				{
					// extra constraints on type of pushscope allowed
					Traits* requiredType = scope->getScopeTraitsAt(scope->size+state->scopeDepth);
					if (!scopeTraits || !scopeTraits->containsInterface(requiredType))
					{
						verifyFailed(kIllegalOperandTypeError, core->toErrorString(scopeTraits), core->toErrorString(requiredType));
					}
				}
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp);
					jit->emitCopy(state, sp, scopeBase+state->scopeDepth);
				}
				#endif
				state->pop();
				state->setType(scopeBase+state->scopeDepth, scopeTraits, true, false);
				state->scopeDepth++;
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushscope) );
				break;
			}

			case OP_pushwith: 
			{
			    // FIXME use pipeline
				checkStack(1,0);
				Traits* scopeTraits = state->peek().traits;
				
				if (state->scopeDepth+1 > max_scope) 
					verifyFailed(kScopeStackOverflowError);

				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp);
					jit->emitCopy(state, sp, scopeBase+state->scopeDepth);
				}
				#endif
				state->pop();
				state->setType(scopeBase+state->scopeDepth, scopeTraits, true, true);

				if (state->withBase == -1)
				{
					state->withBase = state->scopeDepth;
				}
					
				state->scopeDepth++;
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushwith) );
				break;
			}

			case OP_newactivation: 
				checkStack(0, 1);
				if (!(info->flags & AbstractFunction::NEED_ACTIVATION))
					verifyFailed(kInvalidNewActivationError);
				info->activationTraits->resolveSignatures(toplevel);
				coder->write(state, pc, opcode);
				state->push(info->activationTraits, true);
			#ifdef AVMPLUS_VERIFYALL
				core->enqTraits(info->activationTraits);
			#endif
				break;

			case OP_newcatch: 
			{
				checkStack(0, 1);
				if (!info->exceptions || imm30 >= (uint32_t)info->exceptions->exception_count)
					verifyFailed(kInvalidNewActivationError);
					// FIXME better error msg
				ExceptionHandler* handler = &info->exceptions->exceptions[imm30];
				coder->write(state, pc, opcode);
				state->push(handler->scopeTraits, true);
				break;
			}
			case OP_popscope:
				//checkStack(0,0)
				if (state->scopeDepth-- <= outer_depth)
					verifyFailed(kScopeStackUnderflowError);
				coder->write(state, pc, opcode);
				if (state->withBase >= state->scopeDepth)
					state->withBase = -1;
				break;

			case OP_getscopeobject:
				checkStack(0,1);
				// local scope
				if (imm8 >= state->scopeDepth)
					verifyFailed(kGetScopeObjectBoundsError, core->toErrorString(imm8));
				coder->writeOp1(state, pc, opcode, imm8);
				// this will copy type and all attributes too
				state->push(state->scopeValue(imm8));
				break;

            case OP_getouterscope:
            {
				checkStack(0,1);
				ScopeTypeChain* scope = info->declaringTraits->scope;
				int captured_depth = scope->size;
				if (captured_depth > 0)
				{
				    // enclosing scope
				    state->push(scope->getScopeTraitsAt(imm30), true);
				}
				else
				{
                    #ifdef _DEBUG
					if (pool->isBuiltin)
					  core->console << "getouterscope >= depth (" << imm30 << " >= " << state->scopeDepth << ")\n";
                    #endif
					verifyFailed(kGetScopeObjectBoundsError, core->toErrorString(0));
				}
				coder->write(state, pc, opcode);
                break;
            }

			case OP_getglobalscope:
				checkStack(0,1);
				coder->write(state, pc, OP_getglobalscope);
				checkGetGlobalScope(); // after codegen because mutates stack that codgen depends on
				break;
			
			case OP_getglobalslot: 
			{
				checkStack(0,1);
				Value& obj = state->peek();
				uint32_t index = imm30-1;
				checkGetGlobalScope();
				checkEarlySlotBinding(obj.traits);
				Traits* slotTraits = checkSlot(obj.traits, index);
				coder->writeOp1(state, pc, OP_getglobalslot, index);
				state->pop_push(1, slotTraits);
				break;
			}

			case OP_setglobalslot: 
			{
			    // FIXME need test case
				if (!state->scopeDepth && !scope->size)
					verifyFailed(kNoGlobalScopeError);
				Traits *globalTraits = scope->size > 0 ? scope->getScopeTraitsAt(0) : state->scopeValue(0).traits;
				checkStack(1,0);
				checkEarlySlotBinding(globalTraits);
				Traits* slotTraits = checkSlot(globalTraits, imm30-1);
				coder->writeOp1(state, pc, opcode, imm30-1, slotTraits);
				state->pop();
			    break;
			}
			
			case OP_getslot:
			{
				checkStack(1,1);
				Value& obj = state->peek();
				checkEarlySlotBinding(obj.traits);
				Traits* slotTraits = checkSlot(obj.traits, imm30-1);
				coder->write(state, pc, opcode);
				state->setType(sp, slotTraits, obj.notNull);
				break;
			}

			case OP_setslot: 
			{
				checkStack(2,0);
			    Value& obj = state->peek(2); // object
				// if code isn't in pool, its our generated init function which we always
				// allow early binding on
				if(pool->isCodePointer(info->body_pos))
				    checkEarlySlotBinding(obj.traits);
				checkSlot(obj.traits, imm30-1);
				coder->write(state, pc, opcode); 
				state->pop(2);
				break;
			}

			case OP_pop:
				checkStack(1,0);
				coder->write(state, pc, opcode);
				state->pop();
				break;

			case OP_dup: 
			{
				checkStack(1, 2);
				Value& v = state->peek();
				coder->write(state, pc, opcode);
				state->push(v);
				break;
			}

			case OP_swap: 
			{
				checkStack(2,2);
				Value v1 = state->peek(1);
				Value v2 = state->peek(2);
				coder->write(state, pc, opcode);
				state->pop(2);
				state->push(v1);
				state->push(v2);
				break;
			}

			case OP_lessthan:
			case OP_greaterthan:
			case OP_lessequals:
			case OP_greaterequals:
				checkStack(2,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, BOOLEAN_TYPE);
				break;

			case OP_equals:
			case OP_strictequals:
			case OP_instanceof:
			case OP_in:
				checkStack(2,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, BOOLEAN_TYPE);
				break;

			case OP_not:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->pop_push(1, BOOLEAN_TYPE);
				break;

			case OP_add:
			{
				checkStack(2,1);
				Value& rhs = state->peek(1);
				Value& lhs = state->peek(2);
				Traits* lhst = lhs.traits;
				Traits* rhst = rhs.traits;
				coder->write(state, pc, opcode);
				if (lhst == STRING_TYPE && lhs.notNull || rhst == STRING_TYPE && rhs.notNull)
					state->pop_push(2, STRING_TYPE, true);
				else if (lhst && lhst->isNumeric() && rhst && rhst->isNumeric())
					state->pop_push(2, NUMBER_TYPE);
				else
					state->pop_push(2,OBJECT_TYPE, true);
				break;
			}

			case OP_modulo:
			case OP_subtract:
			case OP_divide:
			case OP_multiply:
				checkStack(2,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, NUMBER_TYPE);
				break;

			case OP_negate:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, NUMBER_TYPE, state->value(sp).notNull);
				break;

			case OP_increment:
			case OP_decrement:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, NUMBER_TYPE, state->value(sp).notNull);
				break;

			case OP_increment_i:
			case OP_decrement_i:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, INT_TYPE, state->value(sp).notNull);
				break;

			case OP_add_i:
			case OP_subtract_i:
			case OP_multiply_i:
				checkStack(2,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, INT_TYPE);
				break;

			case OP_negate_i:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, INT_TYPE, state->value(sp).notNull);
				break;

			case OP_bitand:
			case OP_bitor:
			case OP_bitxor:
				checkStack(2,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, INT_TYPE);
				break;

			// ISSUE do we care if shift amount is signed or not?  we mask 
			// the result so maybe it doesn't matter.
			// CN says see tests e11.7.2, 11.7.3, 9.6
			case OP_lshift:
			case OP_rshift:
				checkStack(2,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, INT_TYPE);
				break;

			case OP_urshift:
				checkStack(2,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, UINT_TYPE);
				break;

			case OP_bitnot:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->setType(sp, INT_TYPE, state->value(sp).notNull);
				break;

			case OP_typeof:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->pop_push(1, STRING_TYPE, true);
				break;

			case OP_nop:
			    coder->write(state, pc, opcode);
				break;

			case OP_debug:
			    coder->write(state, pc, opcode);
				break;
					
			case OP_label:
			    coder->write(state, pc, opcode);
				break;

			case OP_debugline:
			    coder->write(state, pc, opcode);
				break;

			case OP_nextvalue:
			case OP_nextname:
				checkStack(2,1);
				peekType(INT_TYPE, 1);
				coder->write(state, pc, opcode);
				state->pop_push(2, NULL);
				break;

			case OP_hasnext:
				checkStack(2,1);
				peekType(INT_TYPE,1);
				coder->write(state, pc, opcode);
				state->pop_push(2, INT_TYPE);
				break;

			case OP_hasnext2:
			{
				checkStack(0,1);
				checkLocal(imm30);
				Value& v = checkLocal(imm30b);
				if (imm30 == imm30b)
					verifyFailed(kInvalidHasNextError);
				if (v.traits != INT_TYPE)
					verifyFailed(kIllegalOperandTypeError, core->toErrorString(v.traits), core->toErrorString(INT_TYPE));
				coder->write(state, pc, opcode);
				state->setType(imm30, NULL, false);
				state->push(BOOLEAN_TYPE);
				break;
			}

#ifdef AVMPLUS_MOPS
			// sign extends
			case OP_sxi1:
			case OP_sxi8:
			case OP_sxi16:
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->pop_push(1, INT_TYPE);
				break;

			// loads
			case OP_li8:
			case OP_li16:
			case OP_li32:
			case OP_lf32:
			case OP_lf64:
			{
				Traits* result = (opcode == OP_lf32 || opcode == OP_lf64) ? NUMBER_TYPE : INT_TYPE;
				checkStack(1,1);
				coder->write(state, pc, opcode);
				state->pop_push(1, result);
				break;
			}

			// stores
			case OP_si8:
			case OP_si16:
			case OP_si32:
			case OP_sf32:
			case OP_sf64:
				checkStack(2,0);
				coder->write(state, pc, opcode);
				state->pop(2);
				break;
#endif // AVMPLUS_MOPS

			case OP_abs_jump:
			{
				// first ensure the executing code isn't user code (only VM generated abc can use this op)
				if(pool->isCodePointer(pc))
				{
					verifyFailed(kIllegalOpcodeError, core->toErrorString(info), core->toErrorString(OP_abs_jump), core->toErrorString((int)(pc-code_pos)));
				}

				#ifdef AVMPLUS_64BIT
				const byte* new_pc = (const byte *) (uintptr(imm30) | (((uintptr) imm30b) << 32));
				const byte* new_code_end = new_pc + AvmCore::readU30 (nextpc);
				#else
				const byte* new_pc = (const byte*) imm30;
				const byte* new_code_end = new_pc + imm30b;
				#endif

				// now ensure target points to within pool's script buffer
				if(!pool->isCodePointer(new_pc))
				{
					verifyFailed(kIllegalOpcodeError, core->toErrorString(info), core->toErrorString(OP_abs_jump), core->toErrorString((int)(pc-code_pos)));
				}

				// FIXME: what other verification steps should we do here?

				const byte* old_pc = pc;
				pc = code_pos = new_pc;
				code_end = new_code_end;
				size = 0;
				
				exceptions_pos = code_end;
				code_length = int(code_end - pc);
				parseExceptionHandlers();

				coder->writeOp2(state, old_pc, opcode, imm30, imm30b);
				break;
			}
			default:
				// size was nonzero, but no case handled the opcode.  someone asleep at the wheel!
				AvmAssert(false);
			}
			
			JIT_ONLY( if (jit) jit->opcodeVerified(opcode, state); )
		}
		
		if (!blockEnd)
		{
			verifyFailed(kCannotFallOffMethodError);
		}
		if (blockStates && actualCount != labelCount) 
		{
			verifyFailed(kInvalidBranchTargetError);
		}

		coder->writeEpilogue(state);

#ifdef AVMPLUS_WORD_CODE
		if (translator) {
			delete translator;
		}
#endif
			
		#ifdef FEATURE_BUFFER_GUARD
		#ifdef AVMPLUS_MIR
		growthGuard = NULL;
		#endif
		#endif

		} CATCH (Exception *exception) {

			// clean up growthGuard
#ifdef FEATURE_BUFFER_GUARD
#ifdef AVMPLUS_MIR
		    // Make sure the GrowthGuard is unregistered
			if (growthGuard)
			{
					growthGuard->~GrowthGuard();
//					growthGuard = NULL;
			}
#endif
#endif
		XLAT_ONLY( if (translator) delete translator; )
			// re-throw exception
			core->throwException(exception);
		}
		END_CATCH
		END_TRY
		  //printf("end verify\n");
	}

	void Verifier::checkPropertyMultiname(uint32_t &depth, Multiname &multiname)
	{
		if (multiname.isRtname())
		{
			if (multiname.isQName())
			{
				// a.ns::@[name] or a.ns::[name]
				peekType(STRING_TYPE, depth++);
			}
			else
			{
				// a.@[name] or a[name]
				depth++;
			}
		}

		if (multiname.isRtns())
		{
			peekType(NAMESPACE_TYPE, depth++);
		}
	}

	void Verifier::emitCallproperty(AbcOpcode opcode, int& sp, Multiname& multiname, uint32_t multiname_index, uint32_t argc, const byte* pc)
	{
		uint32_t n = argc+1;
		checkPropertyMultiname(n, multiname);
		Traits* t = state->peek(n).traits;
		
		Binding b = toplevel->getBinding(t, &multiname);
		if (t)
			t->resolveSignatures(toplevel);

		emitCheckNull(sp-(n-1));
		
		if (emitCallpropertyMethod(opcode, t, b, multiname, multiname_index, argc, pc))
			goto callproperty_done;
		
		if (emitCallpropertySlot(opcode, sp, t, b, argc, pc))
			goto callproperty_done;

		coder->writeOp2(state, pc, opcode, multiname_index, argc);
		
		// If early binding then the state will have been updated, so this will be skipped
		state->pop_push(n, NULL);
		if (opcode == OP_callpropvoid)
			state->pop();
		
	callproperty_done:
		;
#ifdef DEBUG_EARLY_BINDING
		core->console << "verify callproperty " << t << " " << multiname->getName() << " from within " << info << "\n";
#endif
	}

	bool Verifier::emitCallpropertyMethod(AbcOpcode opcode, Traits* t, Binding b, Multiname& multiname, 
										  uint32_t multiname_index, uint32_t argc, const byte* pc) 
	{
#ifndef AVMPLUS_WORD_CODE
		(void)multiname_index;
#endif
		if (!AvmCore::isMethodBinding(b))
			return false;

		uint32_t n = argc+1;
		
		const TraitsBindingsp tb = t->getTraitsBindings();

		if (t == core->traits.math_ctraits)
			b = findMathFunction(tb, multiname, b, argc);
		else if (t == core->traits.string_itraits)
			b = findStringFunction(tb, multiname, b, argc);
		
		int disp_id = AvmCore::bindingToMethodId(b);
		AbstractFunction* m = tb->getMethod(disp_id);
		
		if (!m->argcOk(argc))
			return false;
		
		Traits* resultType = m->returnTraits();

#if defined AVMPLUS_WORD_CODE	
		if (translator)
		{
			if (t->isInterface) 
			{
				// OPTIMIZEME - early-bind OP_callinterface for the interpreter
				// The interpreter currently does not handle OP_callinterface at all.
				
				// We model the effect of returning 'false' from the present
				// method.  We can't just return 'false' here because we must
				// emit good code for the JIT (below).  So do what must be done 
				// and then return 'true'.

			    translator->writeOp2(state, pc, opcode, multiname_index, argc);

				// OK to keep the resultType here, even if we don't exploit it.
				// Actually it's necessary - type modeling must not depend on the
				// execution engine, so we can't set it to NULL.
			}
			else
			{
			    translator->writeOp2(state, pc, OP_callmethod, (uint32_t)disp_id+1, argc);
				if (opcode == OP_callpropvoid)
					translator->write(state, pc, OP_pop);
			}
		}
#endif
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit)
		{
			emitCoerceArgs(m, argc);
			jit->emitSetContext(state, m);
			if (!t->isInterface)
				jit->writeOp2(state, pc, OP_callmethod, disp_id, argc, resultType);
			else
                jit->emitCall(state, OP_callinterface, m->iid(), argc, resultType);
		}
#endif
		state->pop_push(n, resultType);
		if (opcode == OP_callpropvoid)
			state->pop();
		return true;
	}
	
	bool Verifier::emitCallpropertySlot(AbcOpcode opcode, int& sp, Traits* t, Binding b, uint32_t argc, const byte *pc) 
	{
		if (!AvmCore::isSlotBinding(b) || argc != 1)
			return false;
		
		const TraitsBindingsp tb = t->getTraitsBindings();

		int slot_id = AvmCore::bindingToSlotId(b);
		Traits* slotType = tb->getSlotTraits(slot_id);
		
		if (slotType == core->traits.int_ctraits)
		{
		    coder->write(state, pc, OP_convert_i);
			state->setType(sp, INT_TYPE, true); 
			goto fast_path;
		}
		if (slotType == core->traits.uint_ctraits)
		{
		    coder->write(state, pc, OP_convert_u);
			state->setType(sp, UINT_TYPE, true);
			goto fast_path;
		}
		if (slotType == core->traits.number_ctraits)
		{
		    coder->write(state, pc, OP_convert_d);
			state->setType(sp, NUMBER_TYPE, true);
			goto fast_path;
		}
		if (slotType == core->traits.boolean_ctraits)
		{
		    coder->write(state, pc, OP_convert_b);
			state->setType(sp, BOOLEAN_TYPE, true); 
			goto fast_path;
		}
		if (slotType == core->traits.string_ctraits)
		{
		    coder->write(state, pc, OP_convert_s);
			state->setType(sp, STRING_TYPE, true); 
			goto fast_path;
		}
#if	defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit && slotType && slotType->base == CLASS_TYPE && slotType->getCreateClassClosureProc() == NULL)
		{
			// is this a user defined class?  A(1+ args) means coerce to A
			AvmAssert(slotType->itraits != NULL);
			emitCoerce(slotType->itraits, state->sp());
			goto fast_path; // goto fast_path2:
		}
#endif
		return false;

	fast_path:

		if (opcode == OP_callpropvoid)
		{
		    coder->write(state, pc, OP_pop);
			coder->write(state, pc, OP_pop);
		}
		else
		{
		    coder->write(state, pc, OP_swap);
			coder->write(state, pc, OP_pop);
		}

        Value v = state->stackTop();
        state->pop(2);
        state->push(v);
		if (opcode == OP_callpropvoid)
			state->pop();
		return true;
	}

	void Verifier::emitFindProperty(AbcOpcode opcode, Multiname& multiname, uint32_t imm30, const byte *pc)
	{
		XLAT_ONLY(bool no_translate = false);
		ScopeTypeChain* scope = info->declaringTraits->scope;
		if (multiname.isBinding())
		{
			int index = scopeBase + state->scopeDepth - 1;
			int base = scopeBase;
			if (scope->size == 0)
			{
				// if scope->size = 0, then global is a local
				// scope, and we dont want to early bind to global.
				base++;
			}
			for (; index >= base; index--)
			{
				Value& v = state->value(index);
				Binding b = toplevel->getBinding(v.traits, &multiname);
				if (b != BIND_NONE)
				{
				    coder->writeOp1(state, pc, OP_getscopeobject, index-scopeBase);
					state->push(v);
					return;
				}
				if (v.isWith)
					break;  // with scope could have dynamic property
			}
			if (index < base)
			{
				// look at captured scope types
				for (index = scope->size-1; index > 0; index--)
				{
					Traits* t = scope->getScopeTraitsAt(index);
					Binding b = toplevel->getBinding(t, &multiname);
					if (b != BIND_NONE)
					{
					    coder->writeOp1(state, pc, OP_getouterscope, index);
						state->push(t, true);
						return;
					}
					if (scope->getScopeIsWithAt(index))
						break;  // with scope could have dynamic property
				}
				if (index <= 0)
				{
					// look at import table for a suitable script
					AbstractFunction* script = (AbstractFunction*)pool->getNamedScript(&multiname);
					if (script != (AbstractFunction*)BIND_NONE && script != (AbstractFunction*)BIND_AMBIGUOUS)
					{
						#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
						if (jit)
						{
							if (script == info)
							{
								// ISSUE what if there is an ambiguity at runtime? is VT too early to bind?
								// its defined here, use getscopeobject 0
								if (scope->size > 0)
									jit->emitGetscope(state, 0, state->sp()+1);
								else
									jit->emitCopy(state, scopeBase, state->sp()+1);
							}
							else // found a single matching traits
								jit->emit(state, OP_finddef, (uintptr)&multiname, state->sp()+1, script->declaringTraits);
						}
						#else
						(void)opcode;
						#endif
						state->push(script->declaringTraits, true);

						// OPTIMIZEME - more early binding for interpreter on findproperty!
						XLAT_ONLY(if (translator) translator->emitOp1(wordCode(opcode), imm30));

						return;
					}
#if defined AVMPLUS_WORD_CODE
					else {
						if (translator) {
							switch (opcode) {
								case OP_findproperty: 
									translator->writeOp1(state, pc, OP_findpropglobal, imm30);
								    break;
								case OP_findpropstrict:
									translator->writeOp1(state, pc, OP_findpropglobalstrict, imm30);
								    break;
								default:
									translator->emitOp1(wordCode(opcode), imm30);
									break;
							}
							XLAT_ONLY( no_translate = true );
						}
					}
#endif
				}
			}
		}

		uint32_t n=1;
		checkPropertyMultiname(n, multiname);
		JIT_ONLY( if (jit) jit->emit(state, opcode, (uintptr)&multiname, 0, OBJECT_TYPE); )
		state->pop_push(n-1, OBJECT_TYPE, true);
		XLAT_ONLY( if (translator && !no_translate) translator->emitOp1(wordCode(opcode), imm30) );
	}

	void Verifier::emitGetProperty(Multiname &multiname, int n, uint32_t imm30, const byte *pc)
	{
		Value& obj = state->peek(n); // object
		emitCheckNull(state->sp()-(n-1));
		Binding b = toplevel->getBinding(obj.traits, &multiname);
		Traits* propType = readBinding(obj.traits, b);

		// early bind slot
		if (AvmCore::isSlotBinding(b))
		{
			coder->writeOp1(state, pc, OP_getslot, AvmCore::bindingToSlotId(b), propType);
			state->pop_push(n, propType);
			return;
		}

		// early bind accessor
		if (AvmCore::hasGetterBinding(b))
		{
			// Invoke the getter
			int disp_id = AvmCore::bindingToGetterId(b);
			const TraitsBindingsp objtd = obj.traits->getTraitsBindings();
			AbstractFunction *f = objtd->getMethod(disp_id);
			AvmAssert(f != NULL);

			#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			emitCoerceArgs(f, 0);
			if (jit)
			{
				jit->emitSetContext(state, f);
				if (!obj.traits->isInterface)
				    jit->writeOp2(state, pc, OP_callmethod, disp_id, 0, propType);
				else
				    jit->emitCall(state, OP_callinterface, f->iid(), 0, propType);
			}
			#else
			(void)f;
			#endif
			AvmAssert(propType == f->returnTraits());
			XLAT_ONLY( if (translator) translator->emitOp1(WOP_getproperty, imm30) );
			state->pop_push(n, propType);
			return;
		}

		#ifdef DEBUG_EARLY_BINDING
		core->console << "verify getproperty " << obj.traits << " " << multiname->getName() << " from within " << info << "\n";
		#endif

		bool needsSetContext = true;
		if( !propType )
		{
			if( obj.traits == VECTORINT_TYPE  || obj.traits == VECTORUINT_TYPE ||
				obj.traits == VECTORDOUBLE_TYPE )
			{
				bool attr = multiname.isAttr();
				Traits* indexType = state->value(state->sp()).traits;

				bool maybeIntegerIndex = !attr && multiname.isRtname() && multiname.contains(core->publicNamespace);

				if( maybeIntegerIndex && (indexType == UINT_TYPE || indexType == INT_TYPE) )
				{
					needsSetContext = false;
					if(obj.traits == VECTORINT_TYPE)
						propType = INT_TYPE;
					else if(obj.traits == VECTORUINT_TYPE)
						propType = UINT_TYPE;
					else if(obj.traits == VECTORDOUBLE_TYPE)
						propType = NUMBER_TYPE;
				}
			}
		}
		// default - do getproperty at runtime
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit)
		{
			if (needsSetContext)
				jit->emitSetContext(state, NULL);
		}
		#endif
		
		coder->writeOp1(state, pc, OP_getproperty, imm30, propType);
		state->pop_push(n, propType);
	}

	void Verifier::checkGetGlobalScope()
	{
		ScopeTypeChain* scope = info->declaringTraits->scope;
		int captured_depth = scope->size;
		if (captured_depth > 0)
		{
			// enclosing scope
			state->push(scope->getScopeTraitsAt(0), true);
		}
		else
		{
			// local scope
			if (state->scopeDepth > 0)
			{
				// this will copy type and all attributes too
				state->push(state->scopeValue(0));
			}
			else
			{
				#ifdef _DEBUG
				if (pool->isBuiltin)
					core->console << "getglobalscope >= depth (0) "<< state->scopeDepth << "\n";
				#endif
				verifyFailed(kGetScopeObjectBoundsError, core->toErrorString(0));
			}
		}
	}

	FrameState *Verifier::getFrameState(sintptr targetpc)
	{
		const byte *target = code_pos + targetpc;
		FrameState *targetState;
		// get state for target address or create a new one if none exists
		if (!blockStates)
		{
			blockStates = new (core->GetGC()) SortedIntMap<FrameState*>(core->GetGC(), 128);
		}
		if ( (targetState = blockStates->get((uintptr)target)) == 0 ) 
		{
			targetState = newFrameState();
			targetState->pc = target - code_pos;
			blockStates->put((uintptr)target, targetState);
			labelCount++;
		}
		return targetState;
	}
	
	void Verifier::emitToString(AbcOpcode opcode, int i)
	{
		Traits *st = STRING_TYPE;
		Value& value = state->value(i);
		Traits *in = value.traits;
		if (in != st || !value.notNull || opcode != OP_convert_s)
		{
			#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			if (jit)
			{
				if (opcode == OP_convert_s && in && 
					(value.notNull || in->isNumeric() || in == BOOLEAN_TYPE))
				{
					jit->emitCoerce(state, i, st);
				}
				else
				{
					jit->emit(state, opcode, i, 0, st);
				}
			}
			#endif
			value.traits = st;
			value.notNull = true;
		}
	}

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
    // FIXME does this belong in FrameState like setType?
	void Verifier::setNotNull(int i)
	{
		Value& value = state->value(i);
		if (!value.notNull)
		{
			for (int j=0, n = frameSize; j < n; j++) 
			{
				// also mark all copies of value.ins as non-null
				Value &v2 = state->value(j);
				if (v2.ins == value.ins)
					v2.notNull = true;
			}
		}
	}

	void Verifier::emitCheckNull(int i)
	{
	    if (!jit) return;
		Value& value = state->value(i);
		if (!value.notNull)
		{
			jit->emitCheckNull(state, i);
			for (int j=0, n = frameSize; j < n; j++) 
			{
				// also mark all copies of value.ins as non-null
				Value &v2 = state->value(j);
				if (v2.ins == value.ins)
					v2.notNull = true;
			}
		}
	}
#else
    inline void Verifier::emitCheckNull(int i) { (void) i; }
#endif

	void Verifier::checkCallMultiname(AbcOpcode /*opcode*/, Multiname* name) const
	{
		if (name->isAttr())
		{
			verifyFailed(kIllegalOpMultinameError, core->toErrorString(name));
		}
	}

	Traits* Verifier::emitCoerceSuper(int index)
	{
		Traits* base = info->declaringTraits->base;
		if (base != NULL)
		{
			JIT_ONLY( if (jit) emitCoerce(base, index); )
		}
		else
		{
			verifyFailed(kIllegalSuperCallError, core->toErrorString(info));
		}
		(void)index;
		return base;
	}

	void Verifier::emitCoerce(Traits* target, int index)
	{
		Value &v = state->value(index);
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
        if (jit) {
    		Traits* rhs = v.traits;
		    if ((!canAssign(target, rhs) || !Traits::isMachineCompatible(target, rhs)))
    			jit->emitCoerce(state, index, target);
        }
		#endif

		state->setType(index, target, v.notNull);
	}

	void Verifier::emitExplicitCoerce(Traits* target, int index, const byte* pc)
	{
		Value &v = state->value(index);
		Traits* rhs = v.traits;
		if ((!canAssign(target, rhs) || !Traits::isMachineCompatible(target, rhs)))
		    coder->write(state, pc, OP_coerce);
		state->setType(index, target, v.notNull);
	}

	Traits* Verifier::peekType(Traits* requiredType, int n)
	{
		Traits* t = state->peek(n).traits;
		if (t != requiredType)
		{
			verifyFailed(kIllegalOperandTypeError, core->toErrorString(t), core->toErrorString(requiredType));
		}
		return t;
	}

	void Verifier::checkEarlySlotBinding(Traits* t)
	{
		if (!t->allowEarlyBinding())
			verifyFailed(kIllegalEarlyBindingError, core->toErrorString(t));
	}

	void Verifier::emitCoerceArgs(AbstractFunction* m, int argc, bool isctor)
	{
		if (!m->argcOk(argc))
		{
			verifyFailed(kWrongArgumentCountError, core->toErrorString(m), core->toErrorString(m->requiredParamCount()), core->toErrorString(argc));
		}

		m->resolveSignature(toplevel);
	
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		// coerce parameter types
		int n=1;
		while (argc > 0) 
		{
			if (jit)
			{
				Traits* target = (argc <= m->param_count) ? m->paramTraits(argc) : NULL;
				emitCoerce(target, state->sp()-(n-1));
			}
			argc--;
			n++;
		}

		// coerce receiver type
		if (jit && !isctor)  // don't coerce if this is for a ctor, since the ctor will be on the stack instead of the new object
			emitCoerce(m->paramTraits(0), state->sp()-(n-1));
		#else
		(void)isctor;
		#endif
	}

	bool Verifier::canAssign(Traits* lhs, Traits* rhs) const
	{
		if (!Traits::isMachineCompatible(lhs,rhs))
		{
			// no machine type is compatible with any other 
			return false;
		}

		if (!lhs)
			return true;

		// type on right must be same class or subclass of type on left.
		Traits* t = rhs;
		while (t != lhs && t != NULL)
			t = t->base;
		return t != NULL;
	}

	void Verifier::checkStack(uint32_t pop, uint32_t push)
	{
		if (uint32_t(state->stackDepth) < pop)
			verifyFailed(kStackUnderflowError);
		if (state->stackDepth-pop+push > uint32_t(max_stack))
			verifyFailed(kStackOverflowError);
	}

	void Verifier::checkStackMulti(uint32_t pop, uint32_t push, Multiname* m)
	{
		if (m->isRtname()) pop++;
		if (m->isRtns()) pop++;
		checkStack(pop,push);
	}

	Value& Verifier::checkLocal(int local)
	{
		if (local < 0 || local >= local_count)
			verifyFailed(kInvalidRegisterError, core->toErrorString(local));
		return state->value(local);
	}
	
	Traits* Verifier::checkSlot(Traits *traits, int imm30)
	{
        uint32_t slot = imm30;
		if (traits)
			traits->resolveSignatures(toplevel);
		TraitsBindingsp td = traits ? traits->getTraitsBindings() : NULL;
		const uint32_t count = td ? td->slotCount : 0;
        if (!traits || slot >= count)
		{
			verifyFailed(kSlotExceedsCountError, core->toErrorString(slot+1), core->toErrorString(count), core->toErrorString(traits));
		}
		return td->getSlotTraits(slot);
	}

	Traits* Verifier::readBinding(Traits* traits, Binding b)
	{
		if (traits)
			traits->resolveSignatures(toplevel);
		switch (AvmCore::bindingKind(b))
		{
		default:
			AvmAssert(false); // internal error - illegal binding type
		case BKIND_GET:
		case BKIND_GETSET:
		{
			int m = AvmCore::bindingToGetterId(b);
			AbstractFunction *f = traits->getTraitsBindings()->getMethod(m);
			return f->returnTraits();
		}
		case BKIND_SET:
			// TODO lookup type here. get/set must have same type.
		case BKIND_NONE:
			// dont know what this is
			// fall through
		case BKIND_METHOD:
			// extracted method or dynamic data, don't know which
			return NULL;
		case BKIND_VAR:
		case BKIND_CONST:
			return traits->getTraitsBindings()->getSlotTraits(AvmCore::bindingToSlotId(b));
		}
	}

	AbstractFunction* Verifier::checkMethodInfo(uint32_t id)
	{
		if (id >= pool->methodCount)
		{
            verifyFailed(kMethodInfoExceedsCountError, core->toErrorString(id), core->toErrorString(pool->methodCount));
			return NULL;
		}
		else
		{
			return pool->methods[id];
		}
	}

	Traits* Verifier::checkClassInfo(uint32_t id)
	{
		if (id >= pool->classCount)
		{
            verifyFailed(kClassInfoExceedsCountError, core->toErrorString(id), core->toErrorString(pool->classCount));
			return NULL;
		}
		else
		{
			return pool->cinits[id]->declaringTraits;
		}
	}

	Traits* Verifier::checkTypeName(uint32_t index)
	{
		Multiname name;
		checkConstantMultiname(index, name); // CONSTANT_Multiname
		Traits *t = pool->getTraits(name, toplevel);
		if (t == NULL)
			verifyFailed(kClassNotFoundError, core->toErrorString(&name));
		else
			if( name.isParameterizedType() )
			{
				Traits* param_traits = name.getTypeParameter() ? checkTypeName(name.getTypeParameter()) : NULL ;
				t = pool->resolveParameterizedType(toplevel, t, param_traits);
			}
		return t;
	}

    AbstractFunction* Verifier::checkDispId(Traits* traits, uint32_t disp_id)
    {
		TraitsBindingsp td = traits->getTraitsBindings();
        if (disp_id > td->methodCount)
		{
            verifyFailed(kDispIdExceedsCountError, core->toErrorString(disp_id), core->toErrorString(td->methodCount), core->toErrorString(traits));
		}
		AbstractFunction* m = td->getMethod(disp_id);
		if (!m) 
		{
			verifyFailed(kDispIdUndefinedError, core->toErrorString(disp_id), core->toErrorString(traits));
		}
		return m;
    }

    void Verifier::verifyFailed(int errorID, Stringp arg1, Stringp arg2, Stringp arg3) const
    {
#ifdef FEATURE_BUFFER_GUARD
#ifdef AVMPLUS_MIR
		// Make sure the GrowthGuard is unregistered
		if (growthGuard)
		{
			growthGuard->~GrowthGuard();
		}
#endif
#endif

#ifdef AVMPLUS_VERBOSE
		if (!secondTry && !verbose)
		{
			// capture the verify trace even if verbose is false.
			Verifier v2(info, toplevel, true);
			v2.verbose = true;
			#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			v2.verify(NULL);
			#else
			v2.verify();
			#endif
		}
#endif
		core->throwErrorV(toplevel->verifyErrorClass(), errorID, arg1, arg2, arg3);

		// This function throws, and should never return.
		AvmAssert(false);
    }

    void Verifier::checkTarget(const byte* target)
    {
		FrameState *targetState = getFrameState(target-code_pos);
		AvmAssert(targetState != 0);
		if (!targetState->initialized)
		{
			//if (verbose)
			//	core->console << "merge first target=" << targetState->pc << "\n";
            // first time visiting target block
			targetState->init(state);
			targetState->initialized = true;

			// if this label is a loop header then clear the notNull flag for
			// any state entry that might become null in the loop body.  this
			// prevents us from needing to re-verify the loop, at a cost of a
			// few more null pointer checks. 
			if (targetState->targetOfBackwardsBranch)
			{
				// null check on all locals
				for (int i=0, n=local_count; i < n; i++)
					targetState->value(i).notNull = false;

				// and all stack entries
				for (int i=stackBase, n=i+state->stackDepth; i < n; i++)
					targetState->value(i).notNull = false;

				// we don't have to clear notNull on scope stack entries because we
				// check for null in op_pushscope/pushwith
			}
			
			//if (verbose)
			//	showState(targetState, targetState->pc+code_pos, false);
        }
        else
        {
			/*if (verbose)
			{
				core->console << "merge current=" << (int)state->pc << "\n";
				showState(state, code_pos+state->pc, false);
				core->console << "merge target=" << (int)targetState->pc << "\n";
				showState(targetState, code_pos+targetState->pc, false);
			}*/

			// check matching stack depth
            if (state->stackDepth != targetState->stackDepth) 
			{
				verifyFailed(kStackDepthUnbalancedError, core->toErrorString((int)state->stackDepth), core->toErrorString((int)targetState->stackDepth));
			}

			// check matching scope chain depth
            if (state->scopeDepth != targetState->scopeDepth)
			{
				verifyFailed(kScopeDepthUnbalancedError, core->toErrorString(state->scopeDepth), core->toErrorString(targetState->scopeDepth));
			}

			// merge types of locals, scopes, and operands
			// ISSUE merge should preserve common interfaces even when
			// common supertype does not:
			//    class A implements I {}
			//    class B implements I {}
			//    var i:I = b ? new A : new B

			const int scopeTop  = scopeBase + targetState->scopeDepth;
			const int stackTop  = stackBase + targetState->stackDepth;
			Value* targetValues = &targetState->value(0);
			Value* curValues = &state->value(0);
			for (int i=0, n=stackTop; i < n; i++)
			{
				if (i >= scopeTop && i < stackBase) 
				{
					// invalid location, ignore it.
					continue;
				}

				Value& curValue = curValues[i];
				Value& targetValue = targetValues[i];
				if (curValue.killed || targetValue.killed) 
				{
					// this reg has been killed in one or both states;
					// ignore it.
					continue;
				}

				Traits* t1 = targetValue.traits;
				Traits* t2 = curValue.traits;
				bool isWith = curValue.isWith;

				if (isWith != targetValue.isWith) 
				{
					// failure: pushwith on one edge, pushscope on other edge, cannot merge.
					verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t2));
				}

				Traits* t3 = (t1 == t2) ? t1 : findCommonBase(t1, t2);
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
					jit->merge(i, curValue, targetValue);
				#endif // AVMPLUS_MIR || FEATURE_NANOJIT

				bool notNull = targetValue.notNull && curValue.notNull;
				if (targetState->pc < state->pc && 
					(t3 != t1 || t1 && !t1->isNumeric() && notNull != targetValue.notNull))
				{
					// failure: merge on back-edge
					verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t3));
				}

				// if we're targeting a label we can't propagate notNull since we don't yet know 
				// the state of all the other possible branches.  Another possible fix would be to 
				// enforce a null check at each branch to the target.
				if (targetState->targetOfBackwardsBranch)
					notNull = false;

				targetState->setType(i, t3, notNull, isWith);
			}

			/*if (verbose) {
				core->console << "after merge\n";
				showState(targetState, code_pos+targetState->pc, false);
			}*/
        }
    }

	/**
	 * find common base class of these two types
	 */
	Traits* Verifier::findCommonBase(Traits* t1, Traits* t2)
	{
		AvmAssert(t1 != t2);

		if (t1 == NULL) {
			// assume t1 is always non-null
			Traits *temp = t1;
			t1 = t2;
			t2 = temp;
		}

		if (!Traits::isMachineCompatible(t1,t2))
		{
			// these two types are incompatible machine types that require
			// coersions before the join node.
			verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t2));
		}

		if (t1 == NULL_TYPE && t2 && !t2->isMachineType())
		{
			// okay to merge null with pointer type
			return t2;
		}
		if (t2 == NULL_TYPE && t1 && !t1->isMachineType())
		{
			// okay to merge null with pointer type
			return t1;
		}

		// all commonBase flags start out false.  set the cb bits on 
		// t1 and its ancestors.
		Traits* t = t1;
		do t->commonBase = true;
		while ((t = t->base) != NULL);

		// now search t2 and its ancestors looking for the first cb=true
		t = t2;
		while (t != NULL && !t->commonBase) 
			t = t->base;

		Traits* common = t;

		// finally reset the cb bits to false for next time
		t = t1;
		do t->commonBase = false;
		while ((t = t->base) != NULL);

		// found common base, possibly *
		if (!Traits::isMachineCompatible(t1,common) || !Traits::isMachineCompatible(t2,common))
		{
			// these two types are incompatible types that require
			// coersions before the join node.
			verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t2));
		}
		return common;
	}

    Atom Verifier::checkCpoolOperand(uint32_t index, int requiredAtomType)
    {
		switch( requiredAtomType )
		{
		case kStringType:
			if( !index || index >= pool->constantStringCount )
			{
				verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantStringCount));
				return undefinedAtom;
			}
			return pool->cpool_string[index]->atom();

		case kObjectType:
			if( !index || index >= pool->constantMnCount )
			{
				verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantMnCount));
				return undefinedAtom;
			}
			return pool->cpool_mn[index];

		default:
			verifyFailed(kCpoolEntryWrongTypeError, core->toErrorString(index));
			return undefinedAtom;
		}
    }

	void Verifier::checkConstantMultiname(uint32_t index, Multiname& m)
	{
		checkCpoolOperand(index, kObjectType);
		pool->parseMultiname(m, index);
	}

	Binding Verifier::findMathFunction(TraitsBindingsp math, const Multiname& multiname, Binding b, int argc)
	{
		Stringp newname = core->internString(core->concatStrings(core->internConstantStringLatin1("_"), multiname.getName()));
		Binding newb = math->findBinding(newname);
		if (AvmCore::isMethodBinding(newb))
		{
			int disp_id = AvmCore::bindingToMethodId(newb);
			AbstractFunction* newf = math->getMethod(disp_id);
			if (argc == newf->param_count)
			{
				for (int i=state->stackDepth-argc, n=state->stackDepth; i < n; i++)
				{
					Traits* t = state->stackValue(i).traits;
					if (!t || !t->isNumeric())
						return b;
				}
				b = newb;
			}
		}
		return b;
	}

	Binding Verifier::findStringFunction(TraitsBindingsp str, const Multiname& multiname, Binding b, int argc)
	{
		Stringp newname = core->internString(core->concatStrings(core->internConstantStringLatin1("_"), multiname.getName()));
		Binding newb = str->findBinding(newname);
		if (AvmCore::isMethodBinding(newb))
		{
			int disp_id = AvmCore::bindingToMethodId(newb);
			AbstractFunction* newf = str->getMethod(disp_id);
			// We have all required parameters but not more than required.
			if ((argc >= (newf->param_count - newf->optional_count)) && (argc <= newf->param_count))
			{
				for (int i=state->stackDepth-argc, k = 1, n=state->stackDepth; i < n; i++, k++)
				{
					Traits* t = state->stackValue(i).traits;
					if (t != newf->paramTraits(k))
						return b;
				}
				b = newb;
			}
		}
		return b;
	}

#ifndef SIZE_T_MAX
#  ifdef SIZE_MAX
#    define SIZE_T_MAX SIZE_MAX 
#  else
#    define SIZE_T_MAX UINT_MAX
#  endif
#endif

	void Verifier::parseExceptionHandlers()
	{
		const byte* pos = exceptions_pos;
		int exception_count = toplevel->readU30(pos);	// will be nonnegative and less than 0xC0000000

		if (exception_count != 0) 
		{
			if (exception_count == 0 || (size_t)(exception_count-1) > SIZE_T_MAX / sizeof(ExceptionHandler))
				verifyFailed(kIllegalExceptionHandlerError);

			size_t extra = sizeof(ExceptionHandler)*(exception_count-1);
			ExceptionHandlerTable* table = new (core->GetGC(), extra) ExceptionHandlerTable(exception_count);
			ExceptionHandler *handler = table->exceptions;
			for (int i=0; i<exception_count; i++) 
			{
				handler->from = toplevel->readU30(pos);
				handler->to = toplevel->readU30(pos);
				handler->target = toplevel->readU30(pos);

				const uint8_t* const scopePosInPool = pos;

				int type_index = toplevel->readU30(pos);
				Traits* t = type_index ? checkTypeName(type_index) : NULL;

				Multiname qn;
				int name_index = (pool->version != (46<<16|15)) ? toplevel->readU30(pos) : 0;
				if (name_index != 0)
				{
					pool->parseMultiname(qn, name_index);
				}

				#ifdef AVMPLUS_VERBOSE
				if (verbose)
				{
					core->console << "            exception["<<i<<"] from="<< handler->from
						<< " to=" << handler->to
						<< " target=" << (uint64_t)handler->target 
						<< " type=" << t
						<< " name=";
					if (name_index != 0)
					    core->console << qn;
					else
						core->console << "(none)";
					core->console << "\n";
				}
				#endif

				if (handler->from < 0 ||
					handler->to < handler->from ||
					handler->target < handler->to || 
					handler->target > code_length)
				{
					// illegal range in handler record
					verifyFailed(kIllegalExceptionHandlerError);
				}

				// handler->traits = t
				WB(core->GetGC(), table, &handler->traits, t);

				Traits* scopeTraits;
				
				if (name_index == 0)
				{
					scopeTraits = OBJECT_TYPE;
				}
				else
				{
					scopeTraits = Traits::newCatchTraits(toplevel, pool, scopePosInPool, qn.getName(), qn.getNamespace());
				}
				
				// handler->scopeTraits = scopeTraits
				WB(core->GetGC(), table, &handler->scopeTraits, scopeTraits);

				
				getFrameState(handler->target)->targetOfBackwardsBranch = true;

				handler++;
			}

			//info->exceptions = table;
			WB(core->GetGC(), info, &info->exceptions, table);
		}
		else
		{
			info->exceptions = NULL;
		}
	}

#ifdef AVMPLUS_VERBOSE
	/**
     * display contents of current stack frame only.
     */
    void Verifier::showState(FrameState *state, const byte* pc, bool unreachable)
    {
		// stack
		core->console << "                        stack:";
		for (int i=stackBase, n=state->sp(); i <= n; i++) {
			core->console << " ";
			printValue(state->value(i));
		}
		core->console << '\n';

        // scope chain
		core->console << "                        scope: ";
		if (info->declaringTraits->scope && info->declaringTraits->scope->size > 0)
		{
			core->console << "[";
			for (int i=0, n=info->declaringTraits->scope->size; i < n; i++)
			{
				Value v;
				v.traits = info->declaringTraits->scope->getScopeTraitsAt(i);
				v.isWith = info->declaringTraits->scope->getScopeIsWithAt(i);
				v.killed = false;
				v.notNull = true;
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				v.ins = 0;
				#endif
				printValue(v);
				if (i+1 < n)
					core->console << " ";
			}
			core->console << "] ";
		}
		for (int i=scopeBase, n=stackBase; i < n; i++) 
		{
            if (i-scopeBase < state->scopeDepth)
                printValue(state->value(i));
            else
                core->console << "~";
			core->console << " ";
        }
		core->console << '\n';

        // locals
		core->console << "                         locals: ";
		for (int i=0, n=scopeBase; i < n; i++) {
            printValue(state->value(i));
			core->console << " ";
        }
		core->console << '\n';

		// opcode
		if (unreachable)
			core->console << "- ";
		else
			core->console << "  ";
		core->console << (uint64_t)state->pc << ':';
        core->formatOpcode(core->console, pc, (AbcOpcode)*pc, (int)(state->pc), pool);
		core->console << '\n';
    }

	void Verifier::printValue(Value& v)
	{
		Traits* t = v.traits;
		if (!t)
		{
			core->console << "*";
		}
		else
		{
			core->console << t->format(core);
			if (!t->isNumeric() && !v.notNull && t != BOOLEAN_TYPE && t != NULL_TYPE)
				core->console << "?";
		}
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit && v.ins)
			jit->formatOperand(core->console, v.ins);
#endif
	}

#endif /* AVMPLUS_VERBOSE */

	FrameState* Verifier::newFrameState()
	{
		size_t extra = (frameSize-1)*sizeof(Value);
		return new (core->GetGC(), extra) FrameState(this);
	}

#if defined FEATURE_CFGWRITER
    CFGWriter::CFGWriter (CoderContext *ctx, CodeWriter* coder) 
	    : CodeWriter(ctx), coder(coder), label(0), edge(0) {
	    this->blocks = new (ctx->core->GetGC()) SortedIntMap<Block*>(ctx->core->GetGC(), 128);
	    this->edges = new (ctx->core->GetGC()) SortedIntMap<Edge*>(ctx->core->GetGC(), 128);
		blocks->put(0, new (ctx->core->GetGC())Block(ctx, label++, 0));
		current = blocks->at(0);
		current->pred_count = -1;
    }

	CFGWriter::~CFGWriter () 
	{
	    Block* b;
		ctx->core->console << "\n";
		for (int i = 0; i < blocks->size(); i++) {
		  b = blocks->at(i);
		  ctx->core->console << "B" << b->label << " @"; // << (int)b->begin << ", @" << (int)b->end;
		  ctx->core->console << " preds=[";
		  for (uint32_t j = 0; j < b->preds->size(); j++) {
			if(j!=0) ctx->core->console << ",";
			ctx->core->console << "B" << b->preds->get(j);
		  }
		  ctx->core->console << "] succs=[";
		  for (uint32_t j = 0; j < b->succs->size(); j++) {
			if(j!=0) ctx->core->console << ",";
			ctx->core->console << "B" << b->succs->get(j);
		  }
		  ctx->core->console << "]\n";
		}
		Edge* e;
		for (int i = 0; i < edges->size(); i++) {
		  e = edges->at(i);
		  ctx->core->console << "E" << i << ": " << "B" << e->src << " --> " << "B" << e->snk << "\n";
		}
	}

	void CFGWriter::writePrologue(FrameState* state)
	{
		(void)state;
	}

	void CFGWriter::writeEpilogue(FrameState* state)
	{
		(void)state;
	}

	void CFGWriter::write(FrameState* state, const byte* pc, AbcOpcode opcode)
	{
	  //printf ("%i: %s\n", state->pc, opcodeInfo[opcode].name);
	  Block* b = blocks->get(state->pc);
	  if (b) {
		current = b;
	  }

	  switch (opcode) {
	  case OP_label:
	  {
	    //ctx->core->console << "  " << (uint32_t)state->pc << ":" << opcodeInfo[opcode].name << "\n";
		//ctx->core->console << "label @ " << (uint32_t)state->pc << "\n";
		Block *b = blocks->get(state->pc);
		// if there isn't a block for the current pc, then create one
		if (!b) {
		  b = new (ctx->core->GetGC()) Block(ctx, label++, state->pc);
		  //b->pred_count++;
		  blocks->put(state->pc, b);
		  current = b;
		}
		break;
	  }
	  case OP_returnvoid:
		current->end = state->pc+1;
		break;
	  default:
		break;
	  }

		if (coder) coder->write(state, pc, opcode);
	}

	void CFGWriter::writeOp1(FrameState* state, const byte *pc, AbcOpcode opcode, uint32_t opd1, Traits *type)
	{
	  //printf ("%i: %s\n", state->pc, opcodeInfo[opcode].name);
	  Block* b=blocks->get(state->pc);
	  if (b) {
		current = b;
	  }

	  //printf ("%i: %s %i\n", state->pc, opcodeInfo[opcode].name, opd1);
		switch (opcode) {
		case OP_iflt:
		case OP_ifle:
		case OP_ifnlt:
		case OP_ifnle:
		case OP_ifgt:
		case OP_ifge:
		case OP_ifngt:
		case OP_ifnge:
		case OP_ifeq:
		case OP_ifstricteq:
		case OP_ifne:
		case OP_ifstrictne:
		case OP_iftrue:
		case OP_iffalse:
		case OP_jump:
		{
		  //ctx->core->console << "  " << (uint32_t)state->pc << ":" << opcodeInfo[opcode].name;
		  //ctx->core->console << " " << (uint32_t)state->pc+opd1+4 << "\n";
		  Block *b = blocks->get(state->pc+4);

		  // if there isn't a block for the next pc, then create one
		  if (!b) {
			b = new (ctx->core->GetGC()) Block(ctx, label++, state->pc+4);
			blocks->put(state->pc+4, b);
		  }
		  if (opcode != OP_jump) {
			  b->pred_count++;
			  b->preds->add(current->label);
			  current->succs->add(b->label);
			  edges->put(edge++, new (ctx->core->GetGC()) Edge(current->label, b->label));
		  }
			  

		  // if there isn't a block for target then create one
		  b = blocks->get(state->pc+4+opd1);
		  if (!b) {
			b = new (ctx->core->GetGC()) Block(ctx, label++, state->pc+4+opd1);
			blocks->put(state->pc+4+opd1, b);
		  }

		  if ((int)opd1>0) 
		  {
			  b->pred_count++;
		  }
		  else
		  { 
			  b->pred_count = -1;
		  }
		  b->preds->add(current->label);
		  current->succs->add(b->label);
		  current->end = state->pc+4;
		  edges->put(edge++, new (ctx->core->GetGC()) Edge(current->label, b->label));

		  //ctx->core->console << "label " << (uint32_t)state->pc+opd1+4 << "\n";
		  //ctx->core->console << "    edge " << (uint32_t)state->pc << " -> " << (uint32_t)state->pc+opd1+4 << "\n";
		    break;
		}
        default:
		  //ctx->core->console << " " << (int)opd1 << "\n";
		    break;
        }
		if (coder) coder->writeOp1(state, pc, opcode, opd1, type);

	}

	void CFGWriter::writeOp2(FrameState* state, const byte *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits* type)
	{
	  //printf ("%i: %s\n", state->pc, opcodeInfo[opcode].name);
	  Block* b=blocks->get(state->pc);
	  if (b) {
		current = b;
	  }

	  //printf ("%i: %s %i %i\n", state->pc, opcodeInfo[opcode].name, opd1, opd2);
	  //ctx->core->console << "  " << (uint32_t)state->pc << ":" << opcodeInfo[opcode].name << " " << opd1 << " " << opd2 << "\n";
		if (coder) coder->writeOp2 (state, pc, opcode, opd1, opd2, type);
	}
#endif // FEATURE_CFGWRITER
}
