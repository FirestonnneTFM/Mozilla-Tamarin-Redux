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

namespace avmplus
{
#ifdef AVMPLUS_WORD_CODE
	using namespace MMgc;
	
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
	Translator::peep_attr_t Translator::attrs[OP_INDEX(LAST_SUPERWORD_OPCODE)+1];
#endif
	
	class TranslatedCode : public GCObject
	{
	public:
		uint32 data[1];  // more follows
	};

#ifdef AVMPLUS_DIRECT_THREADED
	Translator::Translator(MethodInfo* info, void** opcode_labels)
#else
	Translator::Translator(MethodInfo* info)
#endif
		: info(info)
		, backpatches(NULL)
		, labels(NULL)
		, exception_fixes(NULL)
		, buffers(NULL)
		, buffer_offset(0)
		, spare_buffer(NULL)
#ifdef AVMPLUS_DIRECT_THREADED
		, opcode_labels(opcode_labels)
#endif
		, exceptions_consumed(false)
		, dest(NULL)
		, dest_limit(NULL)
		, pool(NULL)
		, code_start(NULL)
	{
		AvmCore *core = info->core();
		
		const byte* pos = info->body_pos;
		info->word_code.max_stack = AvmCore::readU30(pos);
		info->word_code.local_count = AvmCore::readU30(pos);
		info->word_code.init_scope_depth = AvmCore::readU30(pos);
		info->word_code.max_scope_depth = AvmCore::readU30(pos);
		AvmCore::readU30(pos);  // code_length
		code_start = pos;
		pool = info->pool;
		
		if (pool->word_code.cpool_mn == NULL)
			pool->word_code.cpool_mn = new (sizeof(PrecomputedMultinames) + (pool->constantMnCount - 1)*sizeof(Multiname)) PrecomputedMultinames(core->GetGC(), pool);
		
		computeExceptionFixups();
		
		refill();
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peepInit();
#endif
	}

	Translator::~Translator()
	{
		cleanup();
	}

#define DELETE_LIST(T, v) \
	do { \
		T* tmp1 = v; \
		while (tmp1 != NULL) { \
			T* tmp2 = tmp1; \
			tmp1 = tmp1->next; \
			delete tmp2; \
		} \
		v = NULL; \
	} while (0)
	
	void Translator::cleanup() 
	{
		DELETE_LIST(backpatch_info, backpatches);
		DELETE_LIST(label_info, labels);
		DELETE_LIST(catch_info, exception_fixes);
		DELETE_LIST(buffer_info, buffers);
		if (spare_buffer) {
			delete spare_buffer;
			spare_buffer = NULL;
		}
	}
	
	void Translator::refill() 
	{
		if (buffers != NULL) {
			buffers->entries_used = dest - buffers->data;
			buffer_offset += buffers->entries_used;
		}
		buffer_info* b;
		if (spare_buffer != NULL) {
			b = spare_buffer;
			spare_buffer = NULL;
		}
		else
			b = new buffer_info;
		b->next = buffers;
		buffers = b;
		dest = b->data;
		dest_limit = dest + sizeof(b->data)/sizeof(b->data[0]);
	}
	
	void Translator::emitRelativeOffset(uint32 base_offset, const byte *base_pc, int32 offset) 
	{
		if (offset < 0) {
			// There must be a label for the target location
			uint32 old_offset = (base_pc - code_start) + offset;
			label_info* l = labels;
			while (l != NULL && l->old_offset != old_offset)
				l = l->next;
			AvmAssert(l != NULL);
			*dest++ = l->new_offset - base_offset;
		}
		else
			makeAndInsertBackpatch(base_pc + offset, base_offset);
	}
	
	void Translator::makeAndInsertBackpatch(const byte* target_pc, uint32 patch_offset)
	{
		// Leave a backpatch for the target location.  Backpatches are sorted in
		// increasing address order always.
		backpatch_info* b = new backpatch_info;
		b->target_pc = target_pc;
		b->patch_loc = dest;
		b->patch_offset = patch_offset;
		backpatch_info* q = backpatches;
		backpatch_info* qq = NULL;
#ifdef _DEBUG
		while (q != NULL) {
			AvmAssert(q->patch_offset != patch_offset);
			q = q->next;
		}
		q = backpatches;
#endif
		while (q != NULL && q->target_pc < b->target_pc) {
			qq = q;
			q = q->next;
		}
		if (qq == NULL) {
			b->next = backpatches;
			backpatches = b;
		}
		else {
			b->next = q;
			qq->next = b;
		}
		*dest++ = 0x80000000U;
	}
	
	void Translator::computeExceptionFixups() 
	{
		AvmCore *core = info->core();
	
		if (info->exceptions == NULL)
			return;
		
		DELETE_LIST(catch_info, exception_fixes);
		
		ExceptionHandlerTable* old_table = info->exceptions;
		int exception_count = old_table->exception_count;
		size_t extra = sizeof(ExceptionHandler)*(exception_count - 1);
		ExceptionHandlerTable* new_table = new (core->GetGC(), extra) ExceptionHandlerTable(exception_count);
		
		// Insert items in the exn list for from, to, and target, with the pc pointing
		// to the correct triggering instruction in the ABC and the update loc
		// pointing to the location to be patched; and a flag is_int_offset (if false
		// it's a sintptr).
		
		for ( int i=0 ; i < exception_count ; i++ ) {
			
			new_table->exceptions[i].traits = old_table->exceptions[i].traits;
			new_table->exceptions[i].scopeTraits = old_table->exceptions[i].scopeTraits;
			
			catch_info* p[3];
			
			p[0] = new catch_info;
			p[0]->pc = code_start + info->exceptions->exceptions[i].from;
			p[0]->is_target = false;
			p[0]->fixup_loc = (void*)&(new_table->exceptions[i].from);
			
			p[1] = new catch_info;
			p[1]->pc = code_start + info->exceptions->exceptions[i].to;
			p[1]->is_target = false;
			p[1]->fixup_loc = (void*)&(new_table->exceptions[i].to);
			
			p[2] = new catch_info;
			p[2]->pc = code_start + info->exceptions->exceptions[i].target;
			p[2]->is_target = true;
			p[2]->fixup_loc = (void*)&(new_table->exceptions[i].target);
			
			if (p[0]->pc > p[1]->pc) {
				catch_info* tmp = p[0];
				p[0] = p[1];
				p[1] = tmp;
			}
			if (p[1]->pc > p[2]->pc) {
				catch_info* tmp = p[1];
				p[1] = p[2];
				p[2] = tmp;
			}
			if (p[0]->pc > p[1]->pc) {
				catch_info* tmp = p[0];
				p[0] = p[1];
				p[1] = tmp;
			}
			
			int j=0;
			catch_info* e = exception_fixes;
			catch_info* ee = NULL;
			while (j < 3 && e != NULL) {
				if (e->pc > p[j]->pc) {
					if (ee == NULL) 
						exception_fixes = p[j];
					else 
						ee->next = p[j];
					p[j]->next = e;
					e = p[j];
					j++;
				}
				else {
					ee = e;
					e = e->next;
				}
			}
			while (j < 3) {
				if (ee == NULL) 
					exception_fixes = p[j];
				else 
					ee->next = p[j];
				p[j]->next = e;
				ee = p[j];
				j++;
			}
		}
		
		WB(core->GetGC(), info, &info->word_code.exceptions, new_table);
		
#ifdef _DEBUG
		if (exception_fixes != NULL) {
			catch_info* ee = exception_fixes;
			catch_info* e = ee->next;
			AvmAssert(ee->pc <= e->pc);
			ee = e;
			e = e->next;
		}
#endif
	}

	void Translator::fixExceptionsAndLabels(const byte *pc) 
	{
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// Do not optimize across control flow targets, so flush the peephole window here
		if (exception_fixes != NULL && exception_fixes->pc == pc || backpatches != NULL && backpatches->target_pc == pc)
			peepFlush();
#endif

		while (exception_fixes != NULL && exception_fixes->pc <= pc) {
			AvmAssert(exception_fixes->pc == pc);
			exceptions_consumed = true;
			if (exception_fixes->is_target)
				*(sintptr*)(exception_fixes->fixup_loc) = (sintptr)(buffer_offset + (dest - buffers->data));
			else
				*(int*)(exception_fixes->fixup_loc) = (int)(buffer_offset + (dest - buffers->data));
			catch_info* tmp = exception_fixes;
			exception_fixes = exception_fixes->next;
			delete tmp;
		}
		
		while (backpatches != NULL && backpatches->target_pc <= pc) {
			AvmAssert(backpatches->target_pc == pc);
			AvmAssert(*backpatches->patch_loc == 0x80000000U);
			*backpatches->patch_loc = buffer_offset + (dest - buffers->data) - backpatches->patch_offset;
			backpatch_info* tmp = backpatches;
			backpatches = backpatches->next;
			delete tmp;
		}
	}
	
#define CHECK(n) \
		if (dest+n > dest_limit) refill();

	// These take no arguments
	void Translator::emitOp0(const byte *pc, int opcode) {
#ifdef _DEBUG
		switch (opcode) {
			case OP_add:
			case OP_add_i:
			case OP_astypelate:
			case OP_bitand:
			case OP_bitnot:
			case OP_bitor:
			case OP_bitxor:
			case OP_bkpt:
			case OP_checkfilter:
			case OP_coerce_b:
			case OP_coerce_a:
			case OP_coerce_d:
			case OP_coerce_i:
			case OP_coerce_o:
			case OP_coerce_s:
			case OP_coerce_u:
			case OP_convert_b:
			case OP_convert_d:
			case OP_convert_i:
			case OP_convert_o:
			case OP_convert_s:
			case OP_convert_u:
			case OP_decrement:
			case OP_decrement_i:
			case OP_divide:
			case OP_dup:
			case OP_dxnslate:
			case OP_equals:
			case OP_esc_xelem:
			case OP_esc_xattr:
			case OP_getglobalscope:
			case OP_getlocal0:
			case OP_getlocal1:
			case OP_getlocal2:
			case OP_getlocal3:
			case OP_greaterequals:
			case OP_greaterthan:
			case OP_hasnext:
			case OP_increment:
			case OP_increment_i:
			case OP_in:
			case OP_instanceof:
			case OP_istypelate:
			case OP_lessequals:
			case OP_lessthan:
			case OP_lshift:
			case OP_modulo:
			case OP_multiply:
			case OP_multiply_i:
			case OP_negate:
			case OP_negate_i:
			case OP_newactivation:
			case OP_nextname:
			case OP_nextvalue:
			case OP_not:
			case OP_pop:
			case OP_popscope:
			case OP_pushfalse:
			case OP_pushnan:
			case OP_pushnull:
			case OP_pushscope:
			case OP_pushtrue:
			case OP_pushwith:
			case OP_pushundefined:
			case OP_returnvalue:
			case OP_returnvoid:
			case OP_rshift:
			case OP_setlocal0:
			case OP_setlocal1:
			case OP_setlocal2:
			case OP_setlocal3:
			case OP_strictequals:
			case OP_subtract:
			case OP_subtract_i:
			case OP_swap:
			case OP_throw:
			case OP_typeof:
			case OP_urshift:
				break;
			default:
				AvmAssert(!"Unknown OP0");
		}
#endif // _DEBUG
		(void)pc;
		CHECK(1);
		*dest++ = NEW_OPCODE(opcode);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-1);
#endif
	}

#ifdef _DEBUG
#  define CHECK_OP1(opcode, tag) \
	switch (opcode) { \
		case OP_applytype: \
		case OP_astype: \
		case OP_bkptline: \
		case OP_call: \
		case OP_coerce: \
		case OP_construct: \
		case OP_constructsuper: \
		case OP_debugline: \
		case OP_debugfile: \
		case OP_declocal: \
		case OP_declocal_i: \
		case OP_deleteproperty: \
		case OP_dxns: \
		case OP_finddef: \
		case OP_findproperty: \
		case OP_findpropstrict: \
		case OP_getdescendants: \
		case OP_getglobalslot: \
		case OP_getlex: \
		case OP_getlocal: \
		case OP_getouterscope: \
		case OP_getproperty: \
		case OP_getslot: \
		case OP_getsuper: \
		case OP_inclocal: \
		case OP_inclocal_i: \
		case OP_initproperty: \
		case OP_istype: \
		case OP_kill: \
		case OP_newarray: \
		case OP_newcatch: \
		case OP_newclass: \
		case OP_newfunction: \
		case OP_newobject: \
		case OP_pushdouble: \
		case OP_pushnamespace: \
		case OP_pushstring: \
		case OP_setglobalslot: \
 		case OP_setlocal: \
		case OP_setproperty: \
		case OP_setslot: \
		case OP_setsuper: \
		case OP_ext_findpropglobal: \
		case OP_ext_findpropglobalstrict: \
			break; \
		default: \
			AvmAssert(!"Unknown " tag); \
	}
#else
#  define CHECK_OP1(opcode, tag)
#endif
	
	// These take one U30 argument
	void Translator::emitOp1(const byte *pc, int opcode)
	{
		CHECK_OP1(opcode, "OP1")
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = AvmCore::readU30(pc);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-2);
#endif
	}
	
	// These take one U30 argument, and the argument is explicitly passed here (result of optimization)
	void Translator::emitOp1(int opcode, uint32 operand)
	{
#ifdef _DEBUG
		switch (opcode) {
			case OP_getscopeobject:
			case OP_ext_get2locals:
			case OP_ext_get3locals:
			case OP_ext_storelocal:
				break;
			default:
				CHECK_OP1(opcode, "OP1/imm")
		}
#endif // _DEBUG
		CHECK(2);
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = operand;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-2);
#endif
	}
	
#ifdef _DEBUG
#  define CHECK_OP2(opcode, tag) \
	switch (opcode) { \
		case OP_hasnext2: \
		case OP_callstatic: \
		case OP_callmethod: \
		case OP_callproperty: \
		case OP_callproplex: \
		case OP_callpropvoid: \
		case OP_constructprop: \
		case OP_callsuper: \
		case OP_callsupervoid: \
			break; \
		default: \
			AvmAssert(!"Unknown " tag); \
		}
#else
#  define CHECK_OP2(opcode, tag)	
#endif // _DEBUG

	// These take two U30 arguments
	void Translator::emitOp2(const byte *pc, int opcode)
	{
		CHECK_OP2(opcode, "OP2")
		CHECK(3);
		pc++;
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = AvmCore::readU30(pc);
		*dest++ = AvmCore::readU30(pc);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-3);
#endif
	}
	
	void Translator::emitOp2(int opcode, uint32 op1, uint32 op2)
	{
		CHECK_OP2(opcode, "OP2/imm");
		CHECK(3);
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = op1;
		*dest++ = op2;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-3);
#endif
	}

	
	// These take one S24 argument that is PC-relative.  If the offset is negative
	// then the target must be a LABEL instruction, and we can just look it up.
	// Otherwise, we enter the target offset into an ordered list with the current
	// transformed PC and the location to backpatch.
	void Translator::emitRelativeJump(const byte *pc, int opcode)
	{
#ifdef _DEBUG
		switch (opcode) {
			case OP_jump:
			case OP_iftrue:
			case OP_iffalse:
			case OP_ifeq:
			case OP_ifne:
			case OP_ifstricteq:
			case OP_ifstrictne:
			case OP_iflt:
			case OP_ifnlt:
			case OP_ifgt:
			case OP_ifngt:
			case OP_ifle:
			case OP_ifnle:
			case OP_ifge:
			case OP_ifnge:
				break;
			default:
				AvmAssert(!"Unknown relative jump opcode");
		}
#endif // _DEBUG
		CHECK(2);
		pc++;
		int32 offset = AvmCore::readS24(pc);
		pc += 3;
		*dest++ = NEW_OPCODE(opcode);
		uint32 base_offset = buffer_offset + (dest - buffers->data) + 1;
		emitRelativeOffset(base_offset, pc, offset);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-2);
		AvmAssert(state == 0);		// Never allow a jump instruction to be in the middle of a match
#endif
	}
	
	void Translator::emitLabel(const byte *pc) 
	{
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// Do not optimize across control control flow targets, so flush the peephole window here.
		peepFlush();
#endif
		label_info* l = new label_info;
		l->old_offset = pc-code_start;
		l->new_offset = buffer_offset + (dest - buffers->data);
		l->next = labels;
		labels = l;
	}

#ifdef DEBUGGER
	void Translator::emitDebug(const byte *pc) 
	{
		CHECK(5);
		pc++;
		byte debug_type = *pc++;
		uint32 index = AvmCore::readU30(pc);
		byte reg = *pc++;
		uint32 extra = AvmCore::readU30(pc);
		// 4 separate operands to match the value in the operand count table,
		// though obviously we could pack debug_type and reg into one word and
		// we could also omit extra.
		*dest++ = NEW_OPCODE(OP_debug);
		*dest++ = debug_type;
		*dest++ = index;
		*dest++ = reg;
		*dest++ = extra;
	}
#endif
	
	void Translator::emitPushbyte(const byte *pc) 
	{
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(OP_ext_pushbits);
		*dest++ = (((sint8)*pc++) << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(OP_ext_pushbits, dest-2);
#endif
	}
	
	void Translator::emitPushshort(const byte *pc) 
	{
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(OP_ext_pushbits);
		*dest++ = ((signed short)AvmCore::readU30(pc) << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(OP_ext_pushbits, dest-2);
#endif
	}
	
	void Translator::emitGetscopeobject(const byte *pc) 
	{
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(OP_getscopeobject);
		*dest++ = *pc++;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(OP_getscopeobject, dest-2);
#endif
	}
	
	void Translator::emitPushint(const byte *pc)
	{
		pc++;
		int32 value = pool->cpool_int[AvmCore::readU30(pc)];
		if ((value & 0xF0000000U) == 0xF0000000U || (value & 0xF0000000U) == 0) {
			CHECK(2);
			*dest++ = NEW_OPCODE(OP_ext_pushbits);
			*dest++ = (value << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(OP_ext_pushbits, dest-2);
#endif
		}
		else {
			union {
				double d;
				uint32 bits[2];
			} v;
			v.d = (double)value;
			CHECK(3);
			*dest++ = NEW_OPCODE(OP_ext_push_doublebits);
			*dest++ = v.bits[0];
			*dest++ = v.bits[1];
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(OP_ext_push_doublebits, dest-3);
#endif
		}
	}

	void Translator::emitPushuint(const byte *pc)
	{
		pc++;
		uint32 value = pool->cpool_uint[AvmCore::readU30(pc)];
		if ((value & 0xF0000000U) == 0) {
			CHECK(2);
			*dest++ = NEW_OPCODE(OP_ext_pushbits);
			*dest++ = (value << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(OP_ext_pushbits, dest-2);
#endif
		}
		else {
			union {
				double d;
				uint32 bits[2];
			} v;
			v.d = (double)value;
			CHECK(3);
			*dest++ = NEW_OPCODE(OP_ext_push_doublebits);
			*dest++ = v.bits[0];
			*dest++ = v.bits[1];
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(OP_ext_push_doublebits, dest-3);
#endif
		}
	}
	
	void Translator::emitLookupswitch(const byte *pc)
	{
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// Avoid a lot of hair by flushing before LOOKUPSWITCH and not peepholing after.
		peepFlush();
#endif
		const byte* base_pc = pc;
		pc++;
		uint32 base_offset = buffer_offset + (dest - buffers->data);
		int32 default_offset = AvmCore::readS24(pc);
		pc += 3;
		uint32 case_count = AvmCore::readU30(pc);
		CHECK(3);
		*dest++ = NEW_OPCODE(OP_lookupswitch);
		emitRelativeOffset(base_offset, base_pc, default_offset);
		*dest++ = case_count;
		
		for ( uint32 i=0 ; i <= case_count ; i++ ) {
			int32 offset = AvmCore::readS24(pc);
			pc += 3;
			CHECK(1);
			emitRelativeOffset(base_offset, base_pc, offset);
		}
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// need a forward declaration for toplevel.
//		AvmAssert(toplevel[OP_lookupswitch] == 0);
#endif
	}
	
	// 'OP_abs_jump' is an ABC-only construct, it boils away in the translation,
	// both here and to MIR/LIR.  It says: My first operand (one word in 32-bit
	// mode, two words in 64-bit mode) is a raw pointer into a buffer of ABC code.
	// My second operand is the number of bytes of code starting at that address.
	// Continue translating from that address as if it were a linear part
	// of the current code vector.  In other words, it's a forwarding pointer.
	
	void Translator::emitAbsJump(const byte *new_pc)
	{
		code_start = new_pc;
		
		// When performing a jump:
		//  - require that backpatches and labels no longer reference the old
		//    code vector; those sets must both be empty.  (We could clear out
		//    labels, alternatively, but that appears not to be required.)
		//  - recompute all the exception information, and require that none of it
		//    has been consumed -- this is the only thing that makes sense, and appears
		//    to be the view the verifier sanctions.  (A full definition for the
		//    semantics of abs_jump is sorely needed.)
		
		AvmAssert(!exceptions_consumed);
		AvmAssert(backpatches == NULL);
		AvmAssert(labels == NULL);
		computeExceptionFixups();
	}
	
	void Translator::epilogue() 
	{
		AvmAssert(backpatches == NULL);
		AvmAssert(exception_fixes == NULL);
		
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peepFlush();
#endif

		buffers->entries_used = dest - buffers->data;
		uint32 total_size = buffer_offset + buffers->entries_used;
		
		TranslatedCode* code_anchor = (TranslatedCode*)info->core()->GetGC()->Alloc(sizeof(TranslatedCode) + (total_size - 1)*sizeof(uint32), GC::kZero);
		uint32* code = code_anchor->data;
		
		// reverse the list of buffers
		buffer_info* first = buffers;
		buffer_info* next = first->next;
		first->next = NULL;
		while (next != NULL) {
			buffer_info* tmp = next->next;
			next->next = first;
			first = next;
			next = tmp;
		}
		buffers = first;
		
		// move the data
		uint32* ptr = code;
		while (first != NULL) {
			memcpy(ptr, first->data, first->entries_used*sizeof(uint32));
			ptr += first->entries_used;
			first = first->next;
		}
		AvmAssert(ptr == code + total_size);
		
		info->word_code.code_anchor = code_anchor;
		info->word_code.body_pos = code;
#ifdef SUPERWORD_PROFILING
		info->word_code.body_end = ptr;
		info->word_code.dumped = false;
#endif

		cleanup();
	}

#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
	
	// Peephole optimization.
	//
	//
	// DESCRIPTION.  This is a deterministic state machine driven peephole optimizer.  The  
	// machine attempts to match a set of patterns against a prefix of the instruction 
	// stream, replacing matched patterns by new strings of instructions (usually shorter
	// or faster ones) -- a "reduction".  A reduction is possible when the machine enters
	// a final state.  However, the machine is greedy and may leave the final state 
	// looking for a longer match.  As the longer match may fail, the machine maintains
	// a stack of final states it may backtrack to.  A match may fail in two ways, either
	// because a state is reached from which there is no move to a final state on the
	// actual input, or if a final state is reached but the guard condition for the
	// state is not satisfied.  The guard is only tested when the machine is ready to
	// commit; for that reason, a stack of backtrack states is required (instead of a
	// single backtrack state).  The guard is mixed in with the commit code in order to
	// keep code size down, though it probably does not matter much.
	//
	// Instructions inserted by reductions are not subject to repeated matching (though
	// they could be).
	//
	// In order to handle patterns that are subpatterns but not prefixes of other patterns,
	// a special failure transition is encoded in each state and used if the matcher fails
	// at that state.
	//
	// The peephole optimizer function peep() /must/ be called every time an instruction 
	// has been emitted to the instruction stream, as the state machine in the peephole
	// optimizer tracks the emitted instruction stream (it does not inspect it repeatedly).
	// The operands to peep() are the symbolic opcode that was just emitted and the address
	// at which that opcode was emitted.  The function peep() drives the state machine.
	//
	// If optimization must not cross some instruction boundary (for example it must not
	// merge the instruction at a control flow target with the previous instruction)
	// then peepFlush() must be called before instructions are emitted for the point beyond
	// the boundary.  This must also be called at the end of the instruction stream, and for
	// instructions that must not appear in the peephole window (currently only LOOKUPSWITCH).
	//
	// The tables 'states', 'transitions', and 'toplevel' are generated by the program 
	// utils/peephole.as based on the patterns described in core/peephole.tbl, which are
	// in turn hand-selected with aid of the dynamic instruction profiling infrastructure
	// built into Tamarin - see comments in utils/superwordprof.c for help on how to use that.
	//
	// It is possible to optimize the entry to peep(), the in-line test is 
	//
	//     state==0 && toplevel[toplevel_index] == 0
	//
	// where toplevel_index is computed from the opcode, maybe worth simplifying that in 
	// order to make this test faster.  Anyhow, if the test is true then peep() need 
	// not be called as there will not be a state transition.  This factoid may be useful
	// if emitOp0, emitOp1, and emitOp2 are in-lined into the verifier.
	//
	//
	// OPTIMALITY.  We wish to establish that if there is a stream of instructions s1, s2, ...
	// and patterns p1, p2, ... then (a) if some p matches a prefix of the stream then
	// the algorithm finds the match; (b) if several p match a prefix of the stream then
	// (one of) the longest p is chosen, subject to guard evaluation; (c) the
	// properties (a) and (b) hold for the remainder of the stream when the instructions
	// matching the pattern are removed from the stream; and (d) the properties (a) and (b)
	// hold for the remainder of the stream if no patterns match the prefix and the first
	// instruction is removed from the stream.
	//
	// Note that the optimality result - if established - does not imply that the "best"
	// match (the one that produces the fewest instructions, or the one that minimizes
	// stack pointer updates, or maximizes intra-instruction optimization in the C compiler,
	// or is best according to any criteria like that) is found, since a best match can
	// sometimes be obtained by choosing a shorter match against a prefix in order
	// to make a longer match possible subsequently.  It only implies that we do as well
	// as we can with a greedy matching strategy.
	//
	// Sketch of proof of optimality:
	//
	// To establish (a) and (b), note that the automaton tracks the prefix of the instruction
	// stream and stacks all accepting states.  If it reaches a state without a successor
	// (whether it's successor-less or the input has no transition from the current state) 
	// then the stacked states are tried in longest-first (reverse) order, and the longest
	// match wins.  (The failure state is not visited if there are accepting stacked states,
	// and does not interfere.)
	// 
	// To establish (c), note that the automaton consumes exactly the instructions that
	// were matched, then sets state=0 and re-emits the non-matched instructions, running
	// the automaton by calling peep() for each non-matched instruction.  If this succeeds 
	// then (a) and (b) apply; if it fails, (d) applies.  Either way the automaton
	// eventually consumes all of the originally non-matching instructions, after which it
	// is once again driven by instructions pushed into the peephole window.
	//
	// To establish (d), note that the automaton makes a failure transition if no match
	// could be made, and that the failure transition by construction (see utils/peephole.as)
	// discards the fewest possible instructions from the prefix of the stream: those that 
	// will not match any pattern, given that the present pattern failed.  Thus matching
	// will start at the earlies possible point, and (a), (b), (c), or (d) apply.
	//
	// Then, observe that peepFlush() commits to the longest match possible at the time
	// it is called, and then skips the remaining instructions.  By definition, the
	// skipped instructions cannot be matched (or they would have been part of the "longest
	// match possible").  Thus peepFlush() preserve (a) and (b).
	//
	// Finally, observe that peepFlush() is called following the last instruction emitted
	// in order to commit to the longest prefix of the instructions still in the peephole
	// window.
	
	void Translator::peepInit()
	{
		state = 0;
		
		// Initialize the instruction attribute table.
		//
		// FIXME: optimize for code size
		//
		// Silly to do this work here, there needs to be a constant table, but
		// it needs to incorporate the tables in opcodes.h / opcodes.cpp as well
		// so for the moment this will do.
		//
		// Could also hold flags for whether something is op0, op1, etc, so that
		// the big switch statements below are not needed.
		
		if (attrs[OP_dup].width > 0)
			return;
		
		for ( int i=0 ; i < 255 ; i++ )
			attrs[i].width = opOperandCount[i] + 1;
				
		attrs[OP_INDEX(OP_ext_swap_pop)].width = 1;
		
		attrs[OP_INDEX(OP_ext_pushbits)].width = 2;
		attrs[OP_INDEX(OP_ext_get2locals)].width = 2;
		attrs[OP_INDEX(OP_ext_get3locals)].width = 2;
		attrs[OP_INDEX(OP_ext_get4locals)].width = 2;
		attrs[OP_INDEX(OP_ext_get5locals)].width = 2;
		attrs[OP_INDEX(OP_ext_storelocal)].width = 2;
		attrs[OP_INDEX(OP_ext_add_ll)].width = 2;
		attrs[OP_INDEX(OP_ext_add_set_lll)].width = 2;
		attrs[OP_INDEX(OP_ext_subtract_ll)].width = 2;
		attrs[OP_INDEX(OP_ext_multiply_ll)].width = 2;
		attrs[OP_INDEX(OP_ext_divide_ll)].width = 2;
		attrs[OP_INDEX(OP_ext_modulo_ll)].width = 2;
		attrs[OP_INDEX(OP_ext_bitand_ll)].width = 2;
		attrs[OP_INDEX(OP_ext_bitor_ll)].width = 2;
		attrs[OP_INDEX(OP_ext_bitxor_ll)].width = 2;
		
		attrs[OP_INDEX(OP_ext_push_doublebits)].width = 3;
		attrs[OP_INDEX(OP_ext_add_lb)].width = 3;
		attrs[OP_INDEX(OP_ext_subtract_lb)].width = 3;
		attrs[OP_INDEX(OP_ext_multiply_lb)].width = 3;
		attrs[OP_INDEX(OP_ext_divide_lb)].width = 3;
		attrs[OP_INDEX(OP_ext_bitand_lb)].width = 3;
		attrs[OP_INDEX(OP_ext_bitor_lb)].width = 3;
		attrs[OP_INDEX(OP_ext_bitxor_lb)].width = 3;
		attrs[OP_INDEX(OP_ext_iflt_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifnlt_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifle_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifnle_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifgt_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifngt_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifge_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifnge_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifeq_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifne_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifstricteq_ll)].width = 3;
		attrs[OP_INDEX(OP_ext_ifstrictne_ll)].width = 3;
		
		attrs[OP_INDEX(OP_ext_iflt_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifnlt_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifle_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifnle_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifgt_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifngt_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifge_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifnge_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifeq_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifne_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifstricteq_lb)].width = 4;
		attrs[OP_INDEX(OP_ext_ifstrictne_lb)].width = 4;
		
		attrs[OP_INDEX(OP_ext_findpropglobal)].width = 2;  // will change 
		attrs[OP_INDEX(OP_ext_findpropglobalstrict)].width = 2;  // will change 
		
		attrs[OP_INDEX(OP_jump)].jumps = 1;
		attrs[OP_INDEX(OP_iftrue)].jumps = 1;
		attrs[OP_INDEX(OP_iffalse)].jumps = 1;
		attrs[OP_INDEX(OP_ifeq)].jumps = 1;
		attrs[OP_INDEX(OP_ifne)].jumps = 1;
		attrs[OP_INDEX(OP_ifstricteq)].jumps = 1;
		attrs[OP_INDEX(OP_ifstrictne)].jumps = 1;
		attrs[OP_INDEX(OP_iflt)].jumps = 1;
		attrs[OP_INDEX(OP_ifnlt)].jumps = 1;
		attrs[OP_INDEX(OP_ifgt)].jumps = 1;
		attrs[OP_INDEX(OP_ifngt)].jumps = 1;
		attrs[OP_INDEX(OP_ifle)].jumps = 1;
		attrs[OP_INDEX(OP_ifnle)].jumps = 1;
		attrs[OP_INDEX(OP_ifge)].jumps = 1;
		attrs[OP_INDEX(OP_ifnge)].jumps = 1;
		attrs[OP_INDEX(OP_ext_iflt_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifnlt_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifle_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifnle_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifgt_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifngt_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifge_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifnge_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifeq_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifne_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifstricteq_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifstrictne_ll)].jumps = 1;
		attrs[OP_INDEX(OP_ext_iflt_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifnlt_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifle_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifnle_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifgt_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifngt_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifge_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifnge_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifeq_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifne_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifstricteq_lb)].jumps = 1;
		attrs[OP_INDEX(OP_ext_ifstrictne_lb)].jumps = 1;
	}
	
	// Replace old instructions with new words of code.  This is tail called from the 
	// generated commit() function (see peephole.cpp).
	//
	// Invariants here:
	//
	//   - Lookupswitch never appears in the peephole window (reduces complexity
	//     and guarantees we won't ever have more than one buffer boundary crossing)
	//
	//   - Relative branch instructions only ever appear as the last instruction in 
	//     the window.  At that point, if it is a forward branch, then the backpatch
	//     may not be the first backpatch in the list, but it will usually be near
	//     the beginning (most branches are short).  Backpatches are uniquely 
	//     identified by the patch location they point to so it's always safe to
	//     remove one if we're squashing a branch instruction.
	//
	//     That means that if the peephole optimizer processes a branch instruction
	//     then it /must/ reduce at that point, it can't wait until the next
	//     instruction even if the current state is a final state.
	//
	//   - If the optimizer inserts a branch then the address in the branch must
	//     be absolute.  If the branch is backward it must be the negative of the
	//     absolute word offset of the target.  If the branch is forward it must
	//     be the positive absolute ABC byte offset of the branch target; a backpatch
	//     structure will be created in the latter case.
	
	bool Translator::replace(uint32 old_instr, uint32 new_words, bool jump_has_been_translated) 
	{
		// Undo any relative offsets in the last instruction, if that wasn't done by
		// the commit code.

		if (isJumpInstruction(O[nextI - 1]) && !jump_has_been_translated)
			undoRelativeOffsetInJump();
		
		// Catenate unconsumed instructions onto R (it's easier than struggling with
		// moving instructions across buffer boundaries)

		uint32 k = new_words;
		for ( uint32 n=old_instr ; n < nextI ; n++ ) {
			uint32 len = calculateInstructionWidth(O[n]);
			S[k] = O[n];
			for ( uint32 j=0 ; j < len ; j++ )
				R[k++] = I[n][j];
		}
		
		// Unlink the last buffer segment if we took everything from it, push it onto
		// a reserve (there can only ever be one free).  We know I[nextI-1] points into the
		// current buffer, so check if I[0] is between the start of the buffer and
		// the last instruction.
		
		if (!(buffers->data <= I[0] && I[0] <= I[nextI-1])) {
			spare_buffer = buffers;
			buffers = buffers->next;
			spare_buffer->next = NULL;
			dest_limit = buffers->data + sizeof(buffers->data)/sizeof(buffers->data[0]);
			buffer_offset -= buffers->entries_used;
		}
		dest = I[0];
		
		// Emit the various instructions from new_data, handling branches specially.
		//
		// At this point the instance variables state, I, O, nextI, backtrack_stack,
		// and backtrack_idx are dead, and all the data we need for emitting the
		// instructions are in S and R.  In addition, dest has been rolled back and
		// points to the address of the first instruction in the peephole window, and
		// nothing is live in the code buffer beyond that point.  It's as if we are
		// in a context where we're just emitting instructions.
		//
		// Consequently, we set state to 0 and start emitting instructions from S/R
		// normally, calling peep() after each instruction that was not replaced by
		// the current action.  This works without having local copies of S and R
		// because peephole optimization cannot insert a replacement sequence that is 
		// longer than the matched sequence; so the segments of S and R used by any
		// recursive match will not affect what we're doing here.  Furthermore, 'dest'
		// is shared between this match and recursive matches, so if a recursive match
		// shortens the instruction sequence the correct value of dest will be used
		// when we get back to the present invocation of replace().

		// Reset the machine.
		
		state = 0;
		
		uint32 i=0;
		while (i < k) {
			uint32 op = S[i];
			if (isJumpInstruction(op)) {
				uint32 w = calculateInstructionWidth(op);
				CHECK(w);
				*dest++ = R[i++];
				int32 offset = (int32)R[i++];
				if (offset >= 0) {
					// Forward jump
					// Install a new backpatch structure
					makeAndInsertBackpatch(code_start + offset, buffer_offset + (dest + (w - 1) - buffers->data));
				}
				else {
					// Backward jump
					// Compute new jump offset
					*dest = -int32(buffer_offset + (dest + (w - 1) - buffers->data) + offset);
					dest++;
				}
				if (w >= 3)
					*dest++ = R[i++];
				if (w >= 4)
					*dest++ = R[i++];
				AvmAssert(w <= 4);
				if (i-w >= new_words)
					peep(op, dest-w);
			}
			else {
				switch (calculateInstructionWidth(op)) {
					default:
						AvmAssert(!"Can't happen");
					case 1:
						CHECK(1);
						*dest++ = R[i++];
						if (i-1 >= new_words)
							peep(op, dest-1);
						break;
					case 2:
						CHECK(2);
						*dest++ = R[i++];
						*dest++ = R[i++];
						if (i-2 >= new_words)
							peep(op, dest-2);
						break;
					case 3:
						CHECK(3);
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						if (i-3 >= new_words)
							peep(op, dest-3);
						break;
					case 5:  // OP_debug
						CHECK(5);
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						peepFlush();
						break;
				}
			}
		}
		
		return true;  // always
	}

	void Translator::undoRelativeOffsetInJump()
	{
		AvmAssert(isJumpInstruction(O[nextI - 1]));
		AvmAssert(I[nextI - 1] + 2 == dest);
		
		uint32 offset = I[nextI - 1][1];
		if (offset == 0x80000000U) {
			// Forward branch, must find and nuke the backpatch
			backpatch_info *b = backpatches;
			backpatch_info *b2 = NULL;
			while (b != NULL && b->patch_loc != &I[nextI - 1][1])
				b2 = b, b = b->next;
			AvmAssert(b != NULL);
			if (b2 == NULL)
				backpatches = b->next;
			else
				b2->next = b->next;
			// b is unlinked
			// Install the ABC byte offset from the backpatch structure (will be positive)
			I[nextI - 1][1] = b->target_pc - code_start;
			delete b;
		}
		else {
			// Backward branch
			AvmAssert((int32)I[nextI - 1][1] < 0);
			// Install the negative of the absolute word offset of the target
			I[nextI - 1][1] = -int32(buffer_offset + (dest - buffers->data) + (int32)I[nextI - 1][1]);
		}
	}

	void Translator::peep(uint32 opcode, uint32* loc)
	{
		peep_state_t *s;
		uint32 limit, next_state, toplevel_index;
		
		AvmAssert(opcode != OP_lookupswitch);

		if (state == 0) 
			goto initial_state;
		
		if (opcode == 0) {
			s = &states[state];
			goto accept;
		}
		
		// Search for a transition from the current state to a next
		// state on input 'opcode'.
		
		O[nextI] = opcode;
		I[nextI] = loc;
		nextI++;
		s = &states[state];
		limit = s->numTransitions;
		
		// The transition lists can get quite long for popular instructions like GETLOCAL;
		// binary search if it that might be profitable.
		
		if (limit > 4) {
			int32 lo = s->transitionPtr;
			int32 hi = lo + limit - 1;
			while (lo <= hi) {
				uint32 mid = (unsigned)(lo + hi) / 2;
				uint32 probe = transitions[mid].opcode;
				if (probe == opcode) {
					next_state = transitions[mid].next_state;
					break;
				}
				if (opcode < probe)
					hi = mid-1;
				else
					lo = mid+1;
			}
			next_state = 0;
		}
		else {
			peep_transition_t* t = &transitions[s->transitionPtr];
			uint32 i = 0;
			while (i < limit && t->opcode != opcode) 
				i++, t++;
			
			next_state = (i == limit) ? 0 : t->next_state;
		}
		
		if (next_state != 0) {

			// Advance
			//
			// There is a next state, so push the current state on the backtrack
			// stack if it is final, and move to the next state.  If that state has
			// successor states then return, as the search continues.  Otherwise, the
			// next state must be final and we try to accept.
			//
			// (The shortcut of checking the successors is necessary for correctness,
			// as otherwise the peephole window could contain a branch in the non-final
			// position.)
			
			if (s->guardAndAction != 0)
				backtrack_stack[backtrack_idx++] = state;

		advance:
			state = next_state;
			s = &states[state];
			if (s->numTransitions > 0)
				return;
			
			next_state = 0;
			AvmAssert(s->guardAndAction != 0);
		}

		// Accept
		//
		// The next state is 0.  Commit to 'state' if it is final; otherwise to 
		// successive backtrack states.  Committing means checking the guard
		// (which may fail, forcing further backtracking) and if the guard passes
		// then performing the transformation.  The commit function is generated,
		// see above; the replace logic is in the function replace() above.
		
	accept:
		if (s->guardAndAction && commit(s->guardAndAction)) 
			return;
		
		for ( int bi=backtrack_idx-1 ; bi >= 0 ; bi-- ) {
			peep_state_t *b = &states[backtrack_stack[bi]];
			AvmAssert(b->guardAndAction != 0);
			if (commit(b->guardAndAction)) 
				return;
		}
		
		// If we could not accept or backtrack because of failing guards then
		// try the failure state, if defined.  We discard anything not relevant
		// to the failure state by shifting the window, so relevant instructions
		// always begin in offset 0 of the window.
		
		if (s->fail != 0) {
			next_state = s->fail;
			uint32 shift = s->failShift;
			for ( uint32 i=0, limit=nextI-shift ; i < limit ; i++ ) {
				I[i] = I[i+shift];
				O[i] = O[i+shift];
			}
			nextI -= shift;
			goto advance;
		}

		// If we failed to find an accepting state then fall through to initial_state
		// to reset the machine.

	initial_state:
		toplevel_index = opcode < 255 ? opcode : 256 + (opcode >> 8);
		//AvmAssert(toplevel_index < sizeof(toplevel)/sizeof(toplevel[0]));

		state = toplevel[toplevel_index];  // may remain 0
		nextI = 0;
		backtrack_idx = 0;
		if (state != 0) {
			O[nextI] = opcode;
			I[nextI] = loc;
			nextI++;
		}
	}
	
	void Translator::peepFlush()
	{
		peep(0, NULL);		// commits, but may start another match
		state = 0;			// ignore any partial match
	}

#endif  // AVMPLUS_PEEPHOLE_OPTIMIZER

#endif // AVMPLUS_WORD_CODE
}
