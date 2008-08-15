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
 *   leon.sha@sun.com
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

namespace avmplus
{
	using namespace MMgc;

#ifdef AVMPLUS_SPARC
#ifdef AVMPLUS_VERBOSE
	const char *CodegenMIR::gpregNames[] = {
		"r0",
		"r1",
		"r2",
		"r3",
		"r4",
		"r5",
		"r6",
		"r7",
		"r8",
		"r9",
		"r10",
		"r11",
		"r12",
		"r13",
		"r14",
		"r15",
		"r16",
		"r17",
		"r18",
		"r19",
		"r20",
		"r21",
		"r22",
		"r23",
		"r24",
		"r25",
		"r26",
		"r27",
		"r28",
		"r29",
		"r30",
		"r31"
	};

	const char *CodegenMIR::fpregNames[] = {
		"f0",		
		"f1",
		"f2",
		"f3",
		"f4",
		"f5",
		"f6",
		"f7",
		"f8",
		"f9",
		"f10",
		"f11",
		"f12",
		"f13",
		"f14",
		"f15",
		"f16",
		"f17",
		"f18",
		"f19",
		"f20",
		"f21",
		"f22",
		"f23",
		"f24",
		"f25",
		"f26",
		"f27",
		"f28",
		"f29",
		"f30",
		"f31"
	};

#endif

	bool CodegenMIR::canImmFold(OP *ins, OP *imm) const
	{
		if (imm->code != MIR_imm)
			return false;
		switch (ins->code)
		{
		case MIR_lsh:
		case MIR_rsh:
		case MIR_ush:
		case MIR_or:
		case MIR_xor:
		case MIR_and:
		case MIR_ucmp:
		case MIR_icmp:
		case MIR_add:
		case MIR_sub:
		case MIR_imul:
			// must be 13-bit immediate
			return isIMM13(imm->imm);
		default:
			return false;
		}
	}

#ifndef MAX
#define MAX(x,y) ( (x)>(y)?(x):(y) )
#endif /* MAX */

	void CodegenMIR::emitNativeThunk(NativeMethod *info)
	{
#ifdef DEBUGGER
		const int kLocalVarSize = sizeof(CallStackNode);
		const int kMinCalledParamCount = 8;
#else
		const int kLocalVarSize = 0;
		const int kMinCalledParamCount = 0;
#endif

		// Should be some comments here.
		Register AP = L7;
		Register ARGC = L6;
#ifdef DEBUGGER
		const Register ENV = L5;
#endif
		const int kMaxPRIndex = 6;
		int PRIndex = 1;
		const int kArgumentOffset = 68;
		int in_arg_offset = 0;
    
		if (!pool)
			core->console << "no pool " << info << "\n";

		code = getMDBuffer(pool);
		mip = (MDInstruction*)code;
		if (!code)
		{
			overflow = true;
			return;
		}

#ifdef FEATURE_BUFFER_GUARD
		GrowthGuard guard(pool->codeBuffer);
#else
		if (!ensureMDBufferCapacity(pool, md_native_thunk_size))
			return;
#endif /* FEATURE_BUFFER_GUARD */

		uint32 *double_ip = mip;
		int first_optional = 1+info->param_count-info->optional_count;
		for (int i=first_optional; i <= info->param_count; i++)
		{
			Traits* type = info->paramTraits(i);
			if (type == NUMBER_TYPE) {
				Atom arg = info->getDefaultValue(i-first_optional);
				double d = AvmCore::number_d(arg);
				int *dp = (int*)&d;
				*mip++ = dp[0];
				*mip++ = dp[1];
			}
		}


		mipStart = mip;

		// prologue
		// save callee-saved registers
		uint32 *patch_save = mip;
		SAVEI(SP, 0, SP);

		OR(I1, G0, ARGC);
		OR(I2, G0, AP);
#ifdef DEBUGGER
		OR(I0, G0, ENV);
#endif


#ifdef DEBUGGER
		OR(ENV, G0, O0);
		OR(ARGC, G0, O1);
		OR(AP, G0, O2);
		OR(G0, G0, O3);
		OR(G0, G0, O4);
		uint32 *patch_addi = mip;
		ADDI(SP, 0, O5); // CallStackNode
		STWI(G0, kArgumentOffset+6*4, SP);
		STWI(G0, kArgumentOffset+7*4, SP);
    thincall(ENVADDR(MethodEnv::debugEnter));
#endif

		LDSWI(AP, 0, O0);

		in_arg_offset += 4;
		
		bool need_rest = ((info->flags & AbstractFunction::NEED_REST) != 0);

		if (info->flags & AbstractFunction::NATIVE_COOKIE)
		{
			SET32(info->m_cookie, O1);
			PRIndex++;
		}

		// push args left to right
		for (int i=1; i <= info->param_count; i++)
		{
			// param 0 is receiver, real params start at 1
			Traits* type = info->paramTraits(i);
			AvmAssert(type != VOID_TYPE);

			// the arguments have already been coerced to the right type
			// by the caller.  We do not do type conversions here.
			uint32* patch_b = NULL;
			

			if (i >= first_optional) {
				// emit code to check whether argument
				// was specified

				SUBCCI (ARGC, i, G0);
				uint32* patch_bge = mip;
				BGE(1, 0);
				NOP();
				// emit code to push the default value
				Atom arg = info->getDefaultValue(i-first_optional);

				// the arguments have already been coerced to the right type
				// by the caller.  We do not do type conversions here.

				if (!type || type == OBJECT_TYPE)
				{
					// push Atom
					if (PRIndex < kMaxPRIndex) {
						SET32 (arg, (Register)(O0+PRIndex));
					} else {
						SET32 (arg, L0);
						STWI (L0, kArgumentOffset+PRIndex*4, SP);
					}
				}
				else if (type == BOOLEAN_TYPE)
				{
					// push bool
					int b = arg>>3;
					if (PRIndex < kMaxPRIndex) {
						ORI (G0, b, (Register)(O0+PRIndex));
					} else {
						ORI (G0, b, L0);
						STWI (L0, kArgumentOffset+PRIndex*4, SP);
					}
				}
				else if (type == INT_TYPE)
				{
					int i = AvmCore::integer_i(arg);
					if (PRIndex < kMaxPRIndex) {
						SET32 (i, (Register)(O0+PRIndex));
					} else {
						SET32 (i, L0);
						STWI (L0, kArgumentOffset+PRIndex*4, SP);
					}
				}
				else if (type == UINT_TYPE)
				{
					uint32 i = AvmCore::integer_u(arg);
					if (PRIndex < kMaxPRIndex) {
						SET32 (i, (Register)(O0+PRIndex));
					} else {
						SET32 (i, L0);
						STWI (L0, kArgumentOffset+PRIndex*4, SP);
					}
				}
				else if (type == NUMBER_TYPE)
				{
					if (PRIndex < kMaxPRIndex - 1) {
						SET32(double_ip[0], (Register)(O0+PRIndex));
						SET32(double_ip[1], (Register)(O0+PRIndex+1));
					} else if (PRIndex == kMaxPRIndex - 1) {
						SET32(double_ip[0], (Register)(O0+PRIndex));
						SET32((int)double_ip, L1);
						LDDF32(L1, 0, F0);
						STDF32(F0, kArgumentOffset+PRIndex*4, SP);	
					} else {
						SET32((int)double_ip, L1);
						LDDF32(L1, 0, F0);
						STDF32(F0, kArgumentOffset+PRIndex*4, SP);	
					}
					double_ip += 2;
				}
				else
				{
					// push pointer type
					// this case includes kStringType, kObjectType, and kNamespaceType
					int p = AvmCore::isNullOrUndefined(arg) ? 0 : arg & ~7;
					if (PRIndex < kMaxPRIndex) {
						SET32 (p, (Register)(O0+PRIndex));
					} else {
						SET32 (p, L0);
						STWI (L0, kArgumentOffset+PRIndex*4, SP);
					}
				}

				// Insert a B instruction here to skip to
				// the next argument
				patch_b = mip;
				BA(1, 0);
				NOP();
				// Patch the BGE instruction to jump here,
				// which is where the non-optional code will
				// go.
				patchRelativeBranch(patch_bge, mip);
			}

			// Generate the code for the non-optional case.
			// these args will already be converted to native form by the caller
			
			if (type == NUMBER_TYPE)
			{
				// push Atom
				if (PRIndex < kMaxPRIndex - 1) {
					LDSWI(AP, in_arg_offset, (Register)(O0+PRIndex));
					LDSWI(AP, in_arg_offset+4, (Register)(O0+PRIndex+1));
				} else if (PRIndex == kMaxPRIndex - 1) {
					LDSWI(AP, in_arg_offset, (Register)(O0+PRIndex));
					LDDF32(AP, in_arg_offset, F0);
					STDF32(F0, kArgumentOffset+PRIndex*4, SP);	
				} else {
					LDDF32(AP, in_arg_offset, F0);
					STDF32(F0, kArgumentOffset+PRIndex*4, SP);	
				}

				in_arg_offset += 8;
				PRIndex += 2;
			}
			else
			{
				// push general type
				// this case includes everything except Number/double
				if (PRIndex < kMaxPRIndex) {
					LDSWI(AP, in_arg_offset, (Register)(O0+PRIndex));
				} else {
					LDSWI(AP, in_arg_offset, L0);
					STWI (L0, kArgumentOffset+PRIndex*4, SP);
				}
				in_arg_offset += 4;
				PRIndex++;
			}
				
			// Patch the JMP instruction, if applicable,
			// to jump to here.
			if (patch_b) {
				patchRelativeBranch(patch_b, mip);
			}
		}

		if (need_rest) {
			// If the method signature ends with "...",
			// deliver any arguments after the explicitly
			// specified ones as (Atom *argv, int argc)

			// rest_count = argc-param_count

			SUBCCI (ARGC, info->param_count, G0);
			uint32* patch_bge = mip;
			BGE(1, 0);
			NOP();
			// rest_count<0, push argc=0, argv=NULL

			// push argc
			if (PRIndex < kMaxPRIndex) {
				ORI(G0, 0, (Register)(O0+PRIndex));
			} else {
				ORI(G0, 0, L0);
				STWI(L0, kArgumentOffset+4*PRIndex, SP);
			}

			// push argv
			if (PRIndex < kMaxPRIndex) {
				ORI(G0, 0, (Register)(O0+PRIndex+1));
			} else {
				ORI(G0, 0, L0);
				STWI(L0, kArgumentOffset+4*(PRIndex+1), SP);
			}
			
			uint32* patch_b = mip;
			BA(1, 0);
			NOP();
			patchRelativeBranch(patch_bge, mip);

			// rest_count>=0
			// push rest_count
			// push rest_argv = argv+param_count

			// push argv
			if (PRIndex < kMaxPRIndex) {
				ADDI(AP, info->restOffset, (Register)(O0+PRIndex));
			} else {
				ADDI(AP, info->restOffset, L0);
				STWI(L0, kArgumentOffset+4*PRIndex, SP);
			}
			PRIndex++;
			
			// push argc
			if (PRIndex < kMaxPRIndex) {
				SUBI(ARGC, info->param_count, (Register)(O0+PRIndex));
			} else {
				SUBI(ARGC, info->param_count, L0);
				STWI(L0, kArgumentOffset+4*PRIndex, SP);
			}
			PRIndex++;

			patchRelativeBranch(patch_b, mip);
		}

		// all args have been pushed, now call function using thiscall calling conventions
		Traits* type = info->returnTraits();

		union {
			int handler_addr;
			NativeMethod::Handler handler;
		};
		handler = info->m_handler;

		thincall(handler_addr);

#ifdef DEBUGGER
		// ARGC uses L6, but we don't use ARGC after this
		// point of the code, so reuse L6 for SAVE_RETURN.
		const Register SAVE_RETURN = L6;

		if (type == NUMBER_TYPE)
		{
			// result is in F0. Store it away.
			FMOVD(F0, F2);
		}
		else
		{
			// result is in O0. Store it in SAVE_RETURN.
			OR(O0, G0, SAVE_RETURN);
		}

		int nodePos = kArgumentOffset + 4* MAX(PRIndex, kMinCalledParamCount);  // GPRIndex MUST not change beyond this line
		
		OR(ENV, G0, O0);
		ADDI(SP, nodePos, O1); // CallStackNode
		thincall(ENVADDR(MethodEnv::debugExit));

		if (type == NUMBER_TYPE)
		{
			FMOVD(F2, F0);
		}
		else
		{
			// move return value back to R3.
			OR(SAVE_RETURN, G0, O0);
		}
#endif

		if (type != NUMBER_TYPE)
		{
			// result in R3
			if (type == BOOLEAN_TYPE)
			{
				// return value already in R3
				// bool is just a byte, so mask it off
				ANDI (O0, 0xFF, I0);
			}
			else if (type == VOID_TYPE)
			{
				 ORI(G0, undefinedAtom, I0);
			}
			else {
				OR(O0, G0, I0);
			}
		}
		// else, result in FPU register F0
				
		// epilogue
		JMPLI(I7, 8, G0); //ret
		RESTORE(G0, G0, G0); //restore

		// Patch up the frame size.
		// For each arg, we need 4 bytes in the called parameter
		// area.  We also leave a little cushion in the called
		// parameter area, since there are a few other function
		// calls the thunk makes (intToAtom, doubleToAtom)
		int frameSize = kArgumentOffset + 
										kLocalVarSize + 
										4 * MAX(MAX(kMaxPRIndex, PRIndex), kMinCalledParamCount);
		frameSize = BIT_ROUND_UP(frameSize, 8);
						 
		*patch_save |= (-frameSize & 0x1FFF);

#ifdef DEBUGGER
		*patch_addi |= nodePos;
#endif /* DEBUGGER */

		bindMethod(info);

#ifndef AVMPLUS_JIT_READONLY
		// Tell the OS that this buffer contains executable code.
		// This is required since machines like the G4 have dual
		// cache designs.
		MakeDataExecutable(mipStart, (int)mip-(int)mipStart);
#endif /* AVMPLUS_JIT_READONLY */

#ifdef AVMPLUS_JIT_READONLY
		makeCodeExecutable();
#endif /* AVMPLUS_JIT_READONLY */

	}

	void* CodegenMIR::emitImtThunk(ImtBuilder::ImtEntry *e)
	{
		mip = mipStart = (MDInstruction*)getMDBuffer(pool);

#ifdef FEATURE_BUFFER_GUARD
		GrowthGuard guard(pool->codeBuffer);
#else
		if (!ensureMDBufferCapacity(pool, md_native_thunk_size))
			return NULL;
#endif /* FEATURE_BUFFER_GUARD */

		// the generated thunk does not call any helper methods, so we are
		// free to use eax, ecx, edx as scratch regs without touchning the
		// stack.
		
		// in: R6 = iid
		//     R3 = MethodEnv
		//     R4 = argc
		//     R5 = ap
		//     0(ap)  = ScriptObject (concrete instance of class)
		
		// local register allocation:
		// R7 = iid parameter
		// R8 = vtable of receiver obj
		// R9 = temp

#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << "imt thunk\n";
		}
#endif

		LDSWI(O2, 0, G1);
		LDSWI(G1, offsetof(ScriptObject, vtable), G2);
		AvmAssert(e->next != NULL); // must have 2 or more entries

		while (e->next)
		{
			ImtBuilder::ImtEntry *next = e->next;

			#ifdef AVMPLUS_VERBOSE
			if (pool->verbose)
			{
				core->console << "              disp_id="<< e->disp_id << " " << e->virt << "\n";
			}
			#endif
			int iid = e->virt->iid();
			if (isIMM13(iid))
			{
				SUBCCI(O3, iid, G0);
			}
			else
			{
				SET32(iid, G3);
				SUBCC(O3, G3, G0);
			}

			MDInstruction* patchip = mip;
			BNE(1, 0);
			NOP();
			LDSWI(G2, offsetof(VTable,methods)+4*e->disp_id, O0);
			LDSWI(O0, offsetof(MethodEnv, impl32), G4);
			JMPL(G0, G4, G0);
			NOP();
			patchRelativeBranch(patchip, mip);

			pool->core->gc->Free(e);
			e = next;
		}

		// last one is unconditional
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << "              disp_id="<< e->disp_id << " " << e->virt << "\n";
		}
		#endif
		LDSWI(G2, offsetof(VTable,methods)+4*e->disp_id, O0);
		LDSWI(O0, offsetof(MethodEnv, impl32), G4);
		JMPL(G0, G4, G0);
		NOP();

		MDInstruction *retval;
		
		retval = mipStart;

#ifndef AVMPLUS_JIT_READONLY
		// Tell the OS that this buffer contains executable code.
		// This is required since machines like the G4 have dual
		// cache designs.
		MakeDataExecutable(mipStart, (int)mip-(int)mipStart);
#endif /* AVMPLUS_JIT_READONLY */
		
#ifdef AVMPLUS_JIT_READONLY
		makeCodeExecutable();
#endif /* AVMPLUS_JIT_READONLY */
		
		// lock in the next available location in the buffer (16B aligned)
		pool->codeBuffer->setPos((byte*) ( (size_t)mip+15 & ~15 ));

		return retval;
	}

	void CodegenMIR::CALL(int offset)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  call %d\n", mip, offset >> 2);
		#endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x40000000 | ((offset >> 2) & 0x3FFFFFFF);
	}

	void CodegenMIR::Format_2_1(Register rd, int op2, int imm22)
	{
		*mip++ = rd << 25 | op2 << 22 | (imm22 & 0x3FFFFF);
	}

	void CodegenMIR::Format_2_2(int a, int cond, int op2, int disp22)
	{
		Format_2_1((a & 0x1) << 4 | (cond & 0xF), op2, disp22);
	}

	void CodegenMIR::Format_2_3(int a, int cond, int op2, int cc1, int cc0, int p, int disp19)
	{
		Format_2_2(a, cond, op2, (cc1 & 0x1) << 21 | (cc0 & 0x1) << 20 | (p & 0x1) << 19 | (disp19 & 0x7FFFF));
	}

	void CodegenMIR::Format_2_4(int a, int rcond, int op2, int d16hi, int p, Register rs1, int d16lo)
	{
		Format_2_2(a, (rcond & 0x7), op2, (d16hi & 0x3) << 20 | (p & 0x1) << 19 | rs1 << 14 | (d16lo & 0x3FFF));
	}

	void CodegenMIR::Format_3(int op1, Register rd, int op3, int bits19)
	{
		*mip++ = op1 << 30 | rd << 25 | op3 << 19 | (bits19 & 0x7FFFF);
	}

	void CodegenMIR::Format_3_1(int op1, Register rd, int op3, Register rs1, int bit8, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (bit8 & 0xFF) << 5 | rs2);
	}

	void CodegenMIR::Format_3_1I(int op1, Register rd, int op3, Register rs1, int simm13)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (simm13 & 0x1FFF));
	}

	void CodegenMIR::Format_3_2(int op1, Register rd, int op3, Register rs1, int rcond, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (rcond & 0x3) << 10 | rs2);
	}

	void CodegenMIR::Format_3_2I(int op1, Register rd, int op3, Register rs1, int rcond, int simm10)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (rcond & 0x3) << 10 | (simm10 & 0x1FFF));
	}

	void CodegenMIR::Format_3_3(int op1, Register rd, int op3, Register rs1, int cmask, int mmask)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (cmask & 0x7) << 5 | (mmask & 0xF));
	}

	void CodegenMIR::Format_3_4(int op1, Register rd, int op3, int bits19)
	{
		Format_3(op1, rd, op3, bits19);
	}

	void CodegenMIR::Format_3_5(int op1, Register rd, int op3, Register rs1, int x, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (x & 0x1) << 12 | rs2);
	}

	void CodegenMIR::Format_3_6(int op1, Register rd, int op3, Register rs1, int shcnt32)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (shcnt32 & 0x3F));
	}

	void CodegenMIR::Format_3_7(int op1, Register rd, int op3, Register rs1, int shcnt64)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | 1 << 12 | (shcnt64 & 0x7F));
	}

	void CodegenMIR::Format_3_8(int op1, Register rd, int op3, Register rs1, int bits9, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (bits9 & 0x1FF) << 5 | rs2);
	}

	void CodegenMIR::Format_3_9(int op1, int cc1, int cc0, int op3, Register rs1, int bits9, Register rs2)
	{
		Format_3(op1, (cc1 & 0x1) << 1 | (cc0 & 0x1), op3, rs1 << 14 | (bits9 & 0x1FF) << 5 | rs2);
	}

	void CodegenMIR::Format_4_1(Register rd, int op3, Register rs1, int cc1, int cc0, Register rs2)
	{
		Format_3(2, rd, op3, rs1 << 14 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | rs2);
	}

	void CodegenMIR::Format_4_1I(Register rd, int op3, Register rs1, int cc1, int cc0, int simm11)
	{
		Format_3(2, rd, op3, rs1 << 14 | (cc1 & 0x1) << 12 | 1 << 13 |(cc0 & 0x1) << 11 | (simm11 & 0x7FF));
	}

	void CodegenMIR::Format_4_2(Register rd, int op3, int cc2, int cond, int cc1, int cc0, Register rs2)
	{
		Format_3(2, rd, op3, (cc2 & 0x1) << 18 | (cond & 0xF) << 14 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | rs2);
	}

	void CodegenMIR::Format_4_2I(Register rd, int op3, int cc2, int cond, int cc1, int cc0, int simm11)
	{
		Format_3(2, rd, op3, (cc2 & 0x1) << 18 | (cond & 0xF) << 14 | 1 << 13 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | (simm11 & 0x7FF));
	}

	void CodegenMIR::Format_4_3(Register rd, int op3, Register rs1, int cc1, int cc0, int swap_trap)
	{
		Format_3(2, rd, op3, rs1 << 14 | 1 << 13 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | (swap_trap & 0x7F));
	}

	void CodegenMIR::Format_4_4(Register rd, int op3, Register rs1, int rcond, int opf_low, Register rs2)
	{
		Format_3(2, rd, op3, rs1 << 14 | (rcond & 0x7) << 10 | (opf_low & 0x1F) << 5 | rs2);
	}

	void CodegenMIR::Format_4_5(Register rd, int op3, int cond, int opf_cc, int opf_low, Register rs2)
	{
		Format_3(2, rd, op3, (cond & 0xF) << 14 | (opf_cc & 0x7) << 11 | (opf_low & 0x3F) << 5 | rs2);
	}

	void CodegenMIR::ADD(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0, rs1, 0, rs2);
	}

	void CodegenMIR::ADDI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0, rs1, simm13);
	}

	void CodegenMIR::AND(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x1, rs1, 0, rs2);
	}

	void CodegenMIR::ANDI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x1, rs1, simm13);
	}

	void CodegenMIR::BA(int a, int dsp22)
	{
		Format_2_2(a, 0x8, 0x2, dsp22);
	}

	void CodegenMIR::BE(int a, int dsp22)
	{
		Format_2_2(a, 0x1, 0x2, dsp22);
	}

	void CodegenMIR::BG(int a, int dsp22)
	{
		Format_2_2(a, 0xA, 0x2, dsp22);
	}

	void CodegenMIR::BGU(int a, int dsp22)
	{
		Format_2_2(a, 0xC, 0x2, dsp22);
	}

	void CodegenMIR::BGE(int a, int dsp22)
	{
		Format_2_2(a, 0xB, 0x2, dsp22);
	}

	void CodegenMIR::BGEU(int a, int dsp22)
	{
		Format_2_2(a, 0xD, 0x2, dsp22);
	}

	void CodegenMIR::BL(int a, int dsp22)
	{
		Format_2_2(a, 0x3, 0x2, dsp22);
	}

	void CodegenMIR::BLU(int a, int dsp22)
	{
		Format_2_2(a, 0x5, 0x2, dsp22);
	}

	void CodegenMIR::BLE(int a, int dsp22)
	{
		Format_2_2(a, 0x2, 0x2, dsp22);
	}

	void CodegenMIR::BLEU(int a, int dsp22)
	{
		Format_2_2(a, 0x4, 0x2, dsp22);
	}

	void CodegenMIR::BNE(int a, int dsp22)
	{
		Format_2_2(a, 0x9, 0x2, dsp22);
	}

	void CodegenMIR::FABSS(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0x9, rs2);
	}

	void CodegenMIR::FADDD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x42, rs2);
	}

	void CodegenMIR::FBE(int a, int dsp22)
	{
		Format_2_2(a, 0x9, 0x6, dsp22);
	}

	void CodegenMIR::FBNE(int a, int dsp22)
	{
		Format_2_2(a, 0x1, 0x6, dsp22);
	}

	void CodegenMIR::FBUE(int a, int dsp22)
	{
		Format_2_2(a, 0xA, 0x6, dsp22);
	}

	void CodegenMIR::FBG(int a, int dsp22)
	{
		Format_2_2(a, 0x6, 0x6, dsp22);
	}

	void CodegenMIR::FBUG(int a, int dsp22)
	{
		Format_2_2(a, 0x5, 0x6, dsp22);
	}

	void CodegenMIR::FBGE(int a, int dsp22)
	{
		Format_2_2(a, 0xB, 0x6, dsp22);
	}

	void CodegenMIR::FBUGE(int a, int dsp22)
	{
		Format_2_2(a, 0xC, 0x6, dsp22);
	}

	void CodegenMIR::FBL(int a, int dsp22)
	{
		Format_2_2(a, 0x4, 0x6, dsp22);
	}

	void CodegenMIR::FBLE(int a, int dsp22)
	{
		Format_2_2(a, 0xD, 0x6, dsp22);
	}

	void CodegenMIR::FCMPD(Register rs1, Register rs2)
	{
		Format_3_9(2, 0, 0, 0x35, rs1, 0x52, rs2);
	}

	void CodegenMIR::FSUBD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x46, rs2);
	}

	void CodegenMIR::FMULD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x4a, rs2);
	}

	void CodegenMIR::FDIVD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x4e, rs2);
	}

	void CodegenMIR::FMOVD(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0x2, rs2);
	}

	void CodegenMIR::FNEGD(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0x6, rs2);
	}

	void CodegenMIR::FITOD(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0xc8, rs2);
	}

	void CodegenMIR::JMPL(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x38, rs1, 0, rs2);
	}

	void CodegenMIR::JMPLI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x38, rs1, simm13);
	}

	void CodegenMIR::LDF(Register rs1, Register rs2, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x20, rs1, 0, rs2);
	}

	void CodegenMIR::LDFI(Register rs1, int simm13, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x20, rs1, simm13);
	}

	void CodegenMIR::LDSW(Register rs1, Register rs2, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x8, rs1, 0, rs2);
	}

	void CodegenMIR::LDSWI(Register rs1, int simm13, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x8, rs1, simm13);
	}

	void CodegenMIR::MULX(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x9, rs1, 0, rs2);
	}

	void CodegenMIR::MULXI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x9, rs1, simm13);
	}

	void CodegenMIR::NOP()
	{
		Format_2_1(0, 0x4, 0);
	}

	void CodegenMIR::OR(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x2, rs1, 0, rs2);
	}

	void CodegenMIR::ORI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x2, rs1, simm13);
	}

	void CodegenMIR::RD(Register rs1, Register rd)
	{
		Format_3_1(2, rd, 0x28, rs1, 0, 0);
	}

	void CodegenMIR::RESTORE(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x3D, rs1, 0, rs2);
	}

	void CodegenMIR::SAVEI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x3C, rs1, simm13);
	}

	void CodegenMIR::SETHI(int imm22, Register rd)
	{
		Format_2_1(rd, 0x4, (imm22 >> 10));
	}

	void CodegenMIR::SLL(Register rs1, Register rs2, Register rd)
	{
		Format_3_5(2, rd, 0x25, rs1, 0, rs2);
	}

	void CodegenMIR::SLLI(Register rs1, int shcnt32, Register rd)
	{
		Format_3_6(2, rd, 0x25, rs1, shcnt32);
	}

	void CodegenMIR::SRA(Register rs1, Register rs2, Register rd)
	{
		Format_3_5(2, rd, 0x27, rs1, 0, rs2);
	}

	void CodegenMIR::SRAI(Register rs1, int shcnt32, Register rd)
	{
		Format_3_6(2, rd, 0x27, rs1, shcnt32);
	}

	void CodegenMIR::SRL(Register rs1, Register rs2, Register rd)
	{
		Format_3_5(2, rd, 0x26, rs1, 0, rs2);
	}

	void CodegenMIR::SRLI(Register rs1, int shcnt32, Register rd)
	{
		Format_3_6(2, rd, 0x26, rs1, shcnt32);
	}

	void CodegenMIR::STF(Register rd, Register rs1, Register rs2)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x24, rs1, 0, rs2);
	}

	void CodegenMIR::STFI(Register rd, int simm13, Register rs1)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x24, rs1, simm13);
	}

	void CodegenMIR::STW(Register rd, Register rs2, Register rs1)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x4, rs1, 0, rs2);
	}

	void CodegenMIR::STWI(Register rd, int simm13, Register rs1)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x4, rs1, simm13);
	}

	void CodegenMIR::SUBCC(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x14, rs1, 0, rs2);
	}

	void CodegenMIR::SUBCCI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x14, rs1, simm13);
	}

	void CodegenMIR::SUB(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x4, rs1, 0, rs2);
	}

	void CodegenMIR::SUBI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x4, rs1, simm13);
	}

	void CodegenMIR::XOR(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x3, rs1, 0, rs2);
	}

	void CodegenMIR::XORI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x3, rs1, simm13);
	}

#endif //AVMPLUS_SPARC
}
