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
	
	class TranslatedCode : public GCObject
	{
	public:
		uint32 data[1];  // more follows
	};

#ifdef AVMPLUS_DIRECT_THREADED
	Translator::Translator(void** opcode_labels)
#else
	Translator::Translator()
#endif
		: backpatches(NULL)
		, labels(NULL)
		, exception_fixes(NULL)
		, buffers(NULL)
		, buffer_offset(0)
#ifdef AVMPLUS_DIRECT_THREADED
		, opcode_labels(opcode_labels)
#endif
	{
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
	}
	
	void Translator::refill(uint32 *&dest, uint32 *&dest_limit) 
	{
		if (buffers != NULL) {
			buffers->entries_used = dest - buffers->data;
			buffer_offset += buffers->entries_used;
		}
		buffer_info* b = new buffer_info;
		b->next = buffers;
		buffers = b;
		dest = b->data;
		dest_limit = dest + sizeof(b->data)/sizeof(b->data[0]);
	}
	
	void Translator::emitRelativeOffset(uint32 base_offset, uint32 *&dest, const byte *base_pc, const byte *code_start, int32 offset) 
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
		else {
			// Leave a backpatch for the target location.  Backpatches are sorted in
			// increasing address order always.
			backpatch_info* b = new backpatch_info;
			b->target_pc = base_pc + offset;
			b->patch_loc = dest;
			b->patch_offset = base_offset;
			backpatch_info* q = backpatches;
			backpatch_info* qq = NULL;
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
			*dest++ = (uint32)~0;
		}
	}
	
	void Translator::computeExceptionFixups(MethodInfo* info, const byte* code_start) 
	{
		AvmCore *core = info->core();
	
		if (info->exceptions == NULL)
			return;
		
		DELETE_LIST(catch_info, exception_fixes);
		
		ExceptionHandlerTable* old_table = info->exceptions;
		int exception_count = old_table->exception_count;
		size_t extra = sizeof(ExceptionHandler)*(exception_count - 1);
		ExceptionHandlerTable* new_table = new (core->GetGC(), extra) ExceptionHandlerTable(exception_count);
		
		// insert items in the exn list for from, to, and target, with the pc pointing
		// to the correct triggering instruction in the ABC and the updateloc
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
	}
	
	// Modify the MethodInfo's 'word_code' structure by translating the code and
	
    void Translator::translate(MethodEnv *env)
    {
		MethodInfo* info = (MethodInfo*)(AbstractFunction*) env->method;
		AvmCore *core = info->core();
	
		AvmAssert(info->word_code.body_pos == NULL);

		const byte* pos = info->body_pos;
		info->word_code.max_stack = AvmCore::readU30(pos);
		info->word_code.local_count = AvmCore::readU30(pos);
		info->word_code.init_scope_depth = AvmCore::readU30(pos);
		info->word_code.max_scope_depth = AvmCore::readU30(pos);
		uint32 code_length = AvmCore::readU30(pos);
		const byte* code_start = pos;
		const byte* pc = code_start;
		const byte* limit = pc + code_length;
		
		PoolObject *pool = info->pool;
		const List<int,LIST_NonGCObjects>& cpool_int = pool->cpool_int;
		const List<uint32,LIST_NonGCObjects>& cpool_uint = pool->cpool_uint;

		// FIXME: If info->exceptions is not NULL then copy into info->word_code.exceptions, 
		// but 'from', 'to', and 'target' fields must be updated.
		
		computeExceptionFixups(info, code_start);
		bool exceptions_consumed = false;
		
#ifdef _DEBUG
		if (exception_fixes != NULL) {
			catch_info* ee = exception_fixes;
			catch_info* e = ee->next;
			AvmAssert(ee->pc <= e->pc);
			ee = e;
			e = e->next;
		}
#endif
		
		uint32 *dest, *dest_limit;
		refill(dest, dest_limit);
		
#define CHECK(n) \
		if (dest+n > dest_limit) \
			refill(dest, dest_limit);

#ifdef AVMPLUS_DIRECT_THREADED
#  define NEW_OPCODE(opcode)  ((uint32)(opcode >= 255 ? opcode_labels[(opcode>>8) + 256] : opcode_labels[opcode])); AvmAssert(((uint32)(opcode >= 255 ? opcode_labels[(opcode>>8)+256] : opcode_labels[opcode])) != 0)
#else
#  ifdef _DEBUG
#    define NEW_OPCODE(opcode)  opcode | (opcode << 16)  // debugging...
#  else
#    define NEW_OPCODE(opcode)  opcode
#  endif
#endif
		
#ifdef _DEBUG
		uint32 prev_opcodes[4];
		for ( uint32 i=0 ; i < sizeof(prev_opcodes)/sizeof(prev_opcodes[0]) ; i++ )
			prev_opcodes[i] = ~0U;
#endif // _DEBUG
		while (pc < limit)
		{
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
				AvmAssert(*backpatches->patch_loc == ~0U);
				*backpatches->patch_loc = buffer_offset + (dest - buffers->data) - backpatches->patch_offset;
				backpatch_info* tmp = backpatches;
				backpatches = backpatches->next;
				delete tmp;
			}

			int opcode = *pc++;
			switch (opcode)
			{
				// More cases below, but catches errors here
				case OP_add_d:  // in JIT'ed code only, for the moment.  If we hit this case then it's 0xdededede...
				default:
					AvmAssert(false);
					return;

				// These take no arguments and disappear in the translation - unless the verifier needs them
				case OP_nop:
				case OP_timestamp:
					break;
					
				// These take no arguments
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
					CHECK(1);
					*dest++ = NEW_OPCODE(opcode);
					break;
					
				// These take one U30 argument
				case OP_applytype:
				case OP_astype:
				case OP_bkptline:
				case OP_call:
				case OP_coerce:
				case OP_construct:
				case OP_constructsuper:
				case OP_debugline:
				case OP_debugfile:
				case OP_declocal:
				case OP_declocal_i:
				case OP_deleteproperty:
				case OP_dxns:
				case OP_finddef:
				case OP_findproperty:
				case OP_findpropstrict:
				case OP_getdescendants:
				case OP_getglobalslot:
				case OP_getlex:
				case OP_getlocal:
				case OP_getouterscope:
				case OP_getproperty:
				case OP_getslot:
				case OP_getsuper:
				case OP_inclocal:
				case OP_inclocal_i:
				case OP_initproperty:
				case OP_istype:
				case OP_kill:
				case OP_newarray:
				case OP_newcatch:
				case OP_newclass:
				case OP_newfunction:
				case OP_newobject:
				case OP_pushdouble:
				case OP_pushnamespace:
				case OP_pushstring:
				case OP_setglobalslot:
				case OP_setlocal:
				case OP_setproperty:
				case OP_setslot:
				case OP_setsuper:
				{
					CHECK(2);
					*dest++ = NEW_OPCODE(opcode);
					*dest++ = AvmCore::readU30(pc);
					break;
				}
					
				// These take one S24 argument that is PC-relative.  If the offset is negative
				// then the target must be a LABEL instruction, and we can just look it up.
				// Otherwise, we enter the target offset into an ordered list with the current
				// transformed PC and the location to backpatch.
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
				{
					CHECK(2);
					int32 offset = AvmCore::readS24(pc);
					pc += 3;
					*dest++ = NEW_OPCODE(opcode);
					uint32 base_offset = buffer_offset + (dest - buffers->data) + 1;
					emitRelativeOffset(base_offset, dest, pc, code_start, offset);
					break;
				}
					
				// These take two U30 arguments
				case OP_hasnext2:
				case OP_callstatic:
				case OP_callmethod:
				case OP_callproperty:
				case OP_callproplex:
				case OP_callpropvoid:
				case OP_constructprop:
				case OP_callsuper:
				case OP_callsupervoid:
				{
					CHECK(3);
					*dest++ = NEW_OPCODE(opcode);
					*dest++ = AvmCore::readU30(pc);
					*dest++ = AvmCore::readU30(pc);
					break;
				}
				
				// Special cases
				case OP_label:
				{
					label_info* l = new label_info;
					l->old_offset = pc-1-code_start;
					l->new_offset = buffer_offset + (dest - buffers->data);
					l->next = labels;
					labels = l;
					break;
				}
					
				case OP_debug:
					// FIXME: shouldn't just skip it, probably
					pc += AvmCore::calculateInstructionWidth(pc-1) - 1;
					break;
					
				case OP_pushbyte:
					CHECK(2);
					*dest++ = NEW_OPCODE(OP_ext_pushbits);
					*dest++ = (((sint8)*pc++) << 3) | kIntegerType;
					break;
					
				case OP_pushint:
				{
					int32 value = cpool_int[AvmCore::readU30(pc)];
					if ((value & 0xF0000000U) == 0xF0000000U || (value & 0xF0000000U) == 0) {
						CHECK(2);
						*dest++ = NEW_OPCODE(OP_ext_pushbits);
						*dest++ = (value << 3) | kIntegerType;
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
					}
					break;
				}
					
				case OP_pushuint:
				{
					uint32 value = cpool_uint[AvmCore::readU30(pc)];
					if ((value & 0xF0000000U) == 0) {
						CHECK(2);
						*dest++ = NEW_OPCODE(OP_ext_pushbits);
						*dest++ = (value << 3) | kIntegerType;
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
					}
					break;
				}
					
				case OP_pushshort:
					CHECK(2);
					*dest++ = NEW_OPCODE(OP_ext_pushbits);
					*dest++ = ((signed short)AvmCore::readU30(pc) << 3) | kIntegerType;
					break;
					
				case OP_lookupswitch:
				{
					const byte* base_pc = pc - 1;
					uint32 base_offset = buffer_offset + (dest - buffers->data);
					int32 default_offset = AvmCore::readS24(pc);
					pc += 3;
					uint32 case_count = AvmCore::readU30(pc);
					CHECK(3);
					*dest++ = NEW_OPCODE(opcode);
					emitRelativeOffset(base_offset, dest, base_pc, code_start, default_offset);
					*dest++ = case_count;
					
					for ( uint32 i=0 ; i <= case_count ; i++ ) {
						int32 offset = AvmCore::readS24(pc);
						pc += 3;
						CHECK(1);
						emitRelativeOffset(base_offset, dest, base_pc, code_start, offset);
					}
					break;
				}
					
				case OP_getscopeobject:
				{
					CHECK(2);
					*dest++ = NEW_OPCODE(opcode);
					*dest++ = *pc++;
					break;
				}
					
				// 'OP_abs_jump' is an ABC-only construct, it boils away in the translation,
				// both here and to MIR/LIR.  It says: My first operand (one word in 32-bit
				// mode, two words in 64-bit mode) is a raw pointer into a buffer of ABC code.
				// My second operand is the number of bytes of code starting at that address.
				// Continue translating from that address as if it were a linear part
				// of the current code vector.  In other words, it's a forwarding pointer.

				case OP_abs_jump:
				{
					uint32 addr = AvmCore::readU30(pc);
#ifdef AVMPLUS_64BIT
					uint32 addr_hi = AvmCore::readU30(pc);
					const byte *new_pc = (const byte *) ((uintptr(addr_hi) << 32) | (uintptr)addr);
#else
					const byte *new_pc = (const byte *) addr;
#endif
					uint32 new_length = AvmCore::readU30(pc);

					pc = new_pc;
					code_start = new_pc;
					limit = pc + new_length;

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
					computeExceptionFixups(info, code_start);
					
					break;
				}
			}
#ifdef _DEBUG
			for ( uint32 i=0 ; i < sizeof(prev_opcodes)/sizeof(prev_opcodes[0])-1 ; i++ )
				prev_opcodes[i+1] = prev_opcodes[i];
			prev_opcodes[0] = opcode;
#endif
		}
		
		AvmAssert(backpatches == NULL);
		AvmAssert(exception_fixes == NULL);

		buffers->entries_used = dest - buffers->data;
		uint32 total_size = buffer_offset + buffers->entries_used;
		
		TranslatedCode* code_anchor = (TranslatedCode*)core->GetGC()->Alloc(sizeof(TranslatedCode) + (total_size - 1)*sizeof(uint32), GC::kZero);
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
		
		cleanup();
	}
#endif // AVMPLUS_WORD_CODE
}
