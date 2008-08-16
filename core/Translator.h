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
	class Translator 
	{
	public:
		Translator();
		~Translator();
		
		// Update MethodEnv in place by adding a translation to it.
		void translate(MethodEnv* method);
		
	private:
		// 'backpatches' represent target addresses of jumps in the original code, along
		// with locations in the translated code that must be patched when the target
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
		
		class backpatch_info 
		{
		public:
			const byte* target_pc;		// the instruction in the old code that is the target of a forward control transfer
			uint32* patch_loc;			// location in the new code into which to write the new offset
			uint32 patch_offset;		// value to subtract from offset of translated pc
			backpatch_info* next;
		};
	
		class label_info 
		{
		public:
			uint32 old_offset;
			uint32 new_offset;
			label_info* next;
		};
	
		class catch_info
		{
		public:
			const byte* pc;			// address in ABC code to trigger use of this structure
			void *fixup_loc;		// points to a location to update
			bool is_target;			// The 'target' field is a sintptr, not an int (sigh).
			catch_info* next;
		};
		
		class buffer_info
		{
		public:
			uint32 data[100];
			int entries_used;
			buffer_info* next;
		};
		
		backpatch_info* backpatches;	 // in address order
		label_info* labels;				 // in reverse offset order
		catch_info* exception_fixes; // in address order
		buffer_info* buffers;			 // newest buffer first
		uint32 buffer_offset;			 // offset of first word of current buffer
		
		void cleanup();
		void refill(uint32 *&dest, uint32 *&dest_limit);
		void emitRelativeOffset(uint32 base_offset, uint32 *&dest, const byte *pc, const byte *code_start, int32 offset);
		void computeExceptionFixups(MethodInfo* info, const byte* code_start);
	};
#endif // AVMPUS_WORD_CODE
}
