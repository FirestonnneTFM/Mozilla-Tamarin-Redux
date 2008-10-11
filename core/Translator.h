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

#  ifdef AVMPLUS_DIRECT_THREADED
#    define NEW_OPCODE(n)         ((uint32_t)opcode_labels[n])
#  else
#    ifdef _DEBUG
#      define NEW_OPCODE(opcode)  ((opcode) | ((opcode) << 16))  // aids debugging
#    else
#      define NEW_OPCODE(opcode)  opcode
#    endif
#  endif
	
	class Translator 
	{
	public:
#  ifdef AVMPLUS_DIRECT_THREADED
		Translator(MethodInfo* info, void** opcode_labels);
#    ifdef AVMPLUS_SELFTEST
		Translator(AvmCore* core, byte* code_start, void** opcode_labels);
#    endif
#  else
		Translator(MethodInfo* info);
#    ifdef AVMPLUS_SELFTEST
		Translator(AvmCore* core, byte* code_start);
#    endif
#  endif
		~Translator();
		
		// In all cases below, pc points to the opcode.
		
		void computeExceptionFixups();

		// Call before every instruction to handle exception range translation and
		// fix up branches to this address
		void fixExceptionsAndLabels(const byte *pc);
		
		// Paste up the translated code and install it in info.  Return the number
		// of words and install a pointer to the first word in 'code' if not NULL
		uint32 epilogue(uint32** code=NULL);
		
		// Handle specific instructions or instruction classes
		void emitOp0(const byte *pc, WordOpcode opcode);
		void emitOp0(WordOpcode opcode) { emitOp0(NULL, opcode); }
		void emitOp1(const byte *pc, WordOpcode opcode);
		void emitOp1(WordOpcode opcode, uint32_t operand);
		void emitOp2(const byte *pc, WordOpcode opcode);
		void emitOp2(WordOpcode opcode, uint32_t op1, uint32_t op2);
#ifdef DEBUGGER
		void emitDebug(const byte *pc);
#endif
		void emitRelativeJump(const byte *pc, WordOpcode opcode);
		void emitLookupswitch(const byte *pc);
		void emitLabel(const byte *pc);
		void emitPushbyte(const byte *pc);
		void emitPushshort(const byte *pc);
		void emitPushint(const byte *pc);
		void emitPushuint(const byte *pc);
		void emitGetscopeobject(const byte *pc);

		// In this case, new_pc is the pc being jumped to
		void emitAbsJump(const byte *new_pc);

	private:
		// 'backpatches' represent target addresses of forward jumps in the original code,
		// along with locations in the translated code that must be patched when the target
		// address in the new code is known.  There can be multiple backpatch structures
		// per target, one for each location that must be patched.  The backpatches are
		// sorted in address order: lowest address first.  Once a backpatch has been
		// consumed it can be deleted; when we're done, the list of backpatches should
		// be empty or there's an error.  Backpatch objects are managed by new/delete.
		//
		// 'labels' are sorted in address order: highest address first.  The list of
		// labels can be freed only at the end.  The labels are searched for every
		// backward branch, but the assumption is that most targets sought are
		// close by and that few probes are needed on the average.  That needs to be
		// verified.  Label objects are managed by new/delete.
		//
		// 'exception_fixes' represent addresses in the original code, along with locations
		// to be updated with corresponding offsets in the translated code.
		// The exception fixes are sorted in address order: lowest address first.  Once an
		// exception fix has been consumed it can be deleted; when we're done, the list of
		// exception fixes should be empty.  Exception fix objects are managed by new/delete.
		//
		// 'buffers' are sorted in reverse creation order: current buffer segment first.
		// The list of buffers is merged into a collectable object at the end of
		// translation, at which point buffers can be freed.  Buffer objects are managed
		// by new/delete.
		
		struct backpatch_info 
		{
			const byte* target_pc;		// the instruction in the old code that is the target of a forward control transfer
			uint32_t* patch_loc;			// location in the new code into which to write the new offset
			uint32_t patch_offset;		// value to subtract from offset of translated pc
			backpatch_info* next;
		};
	
		struct label_info 
		{
			uint32_t old_offset;
			uint32_t new_offset;
			label_info* next;
		};
	
		struct catch_info
		{
			const byte* pc;			// address in ABC code to trigger use of this structure
			void *fixup_loc;		// points to a location to update
			bool is_target;			// The 'target' field is a intptr_t, not an int (sigh).
			catch_info* next;
		};
		
		struct buffer_info
		{
			uint32_t data[100];
			int entries_used;
			buffer_info* next;
		};
		
		MethodInfo* info;
		AvmCore* core;
		backpatch_info* backpatches;	 // in address order
		label_info* labels;				 // in reverse offset order
		catch_info* exception_fixes; // in address order
		buffer_info* buffers;			 // newest buffer first
		uint32_t buffer_offset;			 // offset of first word of current buffer
		buffer_info* spare_buffer;		// may be populated during peephole optimization; reused by refill
#ifdef AVMPLUS_DIRECT_THREADED
		void** opcode_labels;
#endif
		PoolObject *pool;
		const byte* code_start;
		
		bool exceptions_consumed;
		uint32_t *dest;
		uint32_t *dest_limit;

		void cleanup();
		void refill();
		void emitRelativeOffset(uint32_t base_offset, const byte *pc, int32_t offset);
		void makeAndInsertBackpatch(const byte* target_pc, uint32_t patch_offset);
		void boot();

#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		
		// The structures are laid out so as to improve packing and conserve space.  The
		// included initialization code below knows the order of fields.
		
		struct peep_state_t
		{
			uint8  numTransitions;				// Number of consecutive in the transitions[] array starting at transitionPtr
			uint8  failShift;					// Initial tokens to discard on a failure transition
			uint16 transitionPtr;				// Location in transitions[] for our transitions, sorted in increasing token order
			uint16 guardAndAction;				// 0 if this is not a final state, otherwise an identifier for a case in 'commit()'
			uint16 fail;						// 0 if there is no failure transition, otherwise a state number
		};
		
		struct peep_transition_t
		{
			uint16 opcode;						// on this opcode
			uint16 next_state;					//   move to this state (never 0)
		};
		
		static uint16 toplevel[];               // Transition table for initial state
		static peep_state_t states[];           // State 0 is not used
		static peep_transition_t transitions[]; // Compact transition representation
		
		uint32_t  state;							// current state in the matcher, or 0
		uint32_t  backtrack_stack[10];			// commit candidates (state numbers)
		uint32_t  backtrack_idx;					// next slot in backtrack_state
		uint32_t* I[10];							// longest window 10 instructions, not a problem now, generator can generate constant later
		uint32_t  O[10];							// symbolic opcodes for each I entry
		uint32_t  nextI;							// next slot in I and O
		uint32_t  R[30];							// replacement data
		uint32_t  S[30];							// symbolic opcode for some R entries
		
		void peepInit();
		void peep(uint32_t opcode, uint32_t* loc);
		void peepFlush();
		bool commit(uint32_t action);
		bool replace(uint32_t old_instr, uint32_t new_words, bool jump_has_been_translated=false);
		void undoRelativeOffsetInJump();
		
		bool isJumpInstruction(uint32_t opcode) {
			return wopAttrs[opcode].jumps;
		}
		
		uint32_t calculateInstructionWidth(uint32_t opcode) {
			return wopAttrs[opcode].width;
		}
#endif	// AVMPLUS_PEEPHOLE_OPTIMIZER

	};
#endif // AVMPUS_WORD_CODE
}
