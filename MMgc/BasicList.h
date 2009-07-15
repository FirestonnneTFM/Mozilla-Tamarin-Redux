/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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

#ifndef __BasicList__
#define __BasicList__

namespace MMgc
{	
	template<typename T, int growthIncrement=4>
	class BasicList
	{
	public:
		BasicList() : count(0), capacity(0), items(NULL) 
		{
		}
		
		~BasicList()
		{
			Destroy();
		}
		
		void Destroy()
		{
			if ( items )
			{
				delete [] items;
				items = NULL;
			}
			count = capacity = 0;
		}
		
		void Add(T item)
		{
			if(count == capacity)
			{
				capacity += growthIncrement;
				T* newItems = new T[ capacity ];
				if(items)
					VMPI_memcpy(newItems, items, count * sizeof(T));
				delete [] items;
				items = newItems;
			}
			items[count] = item;
			count++;
		}
		
		void Remove(T item)
		{
			uint32_t i=0;
			while (i < count && items[i] != item)
				i++;
			if (i == count) {
				GCAssertMsg(false, "Bug: should not try to remove something that's not in the list");
				return;
			}
			while (i < count-1) {
				items[i] = items[i+1];
				i++;
			}
			count--;
		}
		
		T Get(uint32_t i) const
		{ 
			GCAssertMsg(i < count, "Index out of bounds");
			return items[i]; 
		}
		
		uint32_t Count() const { return count; }
		
	protected:
		// no impl
		BasicList(const BasicList& other);
		BasicList& operator=(const BasicList& other);

	private:
		uint32_t count, capacity;
		T *items;
	};

	template<typename T>
	class BasicListIterator
	{
	public:
		BasicListIterator(const BasicList<T>& bl) : index(0), bl(bl) {}
		T next() { return index < bl.Count() ? bl.Get(index++) : NULL; }
		T next(vmpi_spin_lock_t& lock) 
		{
			MMGC_LOCK(lock);
			return next();
		}
	private:
		uint32_t index;
		const BasicList<T> &bl;
	};
}

#endif /* __GCStack__ */
