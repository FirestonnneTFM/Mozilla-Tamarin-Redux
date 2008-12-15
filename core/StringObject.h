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
 * Portions created by the Initial Developer are Copyright (C) 2008
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Michael Daumling
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

#ifndef __avmplus_NewString__
#define __avmplus_NewString__

namespace avmplus 
{
	class UTF8String;
	class UTF16String;
	class ByteArray;

	/// The utf8_t data type expressively means UTF-8 data.
	typedef uint8_t utf8_t;
	/// The utf32_t data type expressively means UTF-32 data.
	typedef uint32_t utf32_t;

	/**
	A String can have many faces, dependent on the way the string data is stored. 
	The most common is the kDirect type, meaning that the string data follows the
	instance data. The kStatic type has the string instance point to a static buffer.
	This buffer must exist as long as the string exists; character constants are
	ideal candidates for this type. The kDependent type is a string that points
	into another string; this type is created in a substring or concatenation operation. 
	Strings cannot be deleted directly, because they may be referenced be dependent strings.
	<p>
	String concatenation attempts first to use additional memory that the memory 
	allocator has left behind when a kDirect string was allocated. If the right-hand
	string fits into that buffer, the data is appended, and a dependent string is returned,
	pointing to the new, larger buffer(the original string keeps its initial length
	and thus does not know about the additional data). If the data does not fit, a new
	kDirect string is allocated with some extra bytes at the end, assuming that there may
	be more characters to append. The minimum of extra characters is 32, then it is twice 
	the new length, up to a platform-dependent maximum(usually 64K). This value can be 
	tweaked for platforms with memory constraints in favor of more copying operations.
	<p>
	Strings exist in 8, 16, and 32-bit flavors. The 8-bit flavor only holds the first
	256 Unicode characters. All widths ignore Unicode surrogate pairs, treating them
	as ordinary characters. Use the createUTFxx() methods to deal with surrogate pairs and 
	UTF-8 encoding. If the kAuto type is used during creation, a quick scan is made to
	see if a string would fit into a narrower width than the buffer suggests, i.e. if
	a 16-bit buffer only contains 8-bit characters. UTF-32 support needs to be enabled
	by defining the value FEATURE_UTF32_SUPPORT in avmbuild.h.
	<p>
	Strings cannot be deleted, since the create() methods may choose to return standard
	string constants, or interned strings, or other strings that other code depends on.
	*/
	class String : public AvmPlusScriptableObject
	{
	public:

#ifdef FEATURE_UTF32_SUPPORT
		typedef utf32_t CharAtType;
#else
		typedef wchar CharAtType;
#endif

		/// String type constants.
		enum Type
		{
			kDirect				= 0,	// data follows instance (m_direct)
			kStatic				= 1,	// buffer is static (m_static)
			kDependent			= 2		// string points into master string (m_dependent)
		};
		/// String width constants.
		enum Width
		{
#ifdef FEATURE_UTF32_SUPPORT
			kAuto	= 0,	// only used in APIs
			k8		= 1,
			k16		= 2,
			k32		= 4
#else
			kAuto	= 0,	// only used in APIs
			k8		= 1,
			k16		= 2
#endif		
		};
		/**
		Use this constant to define the default width for this system. If you use anything
		else but kAuto, this would create strings of that width. This is not recommended.
		*/
		static	const Width kDefaultWidth = kAuto;
		/**
		This is a union of three different pointers. To use it, call getData() and assign
		the result to a Pointers member.
		*/
		struct Pointers
		{
			union
			{
				void*			pv;
				char*			p8;
				wchar*			p16;
				utf32_t*		p32;
			};
		};

		/**
		Create a string using Latin-1 data. Characters are just widened and copied.
		To create an UTF-8 string, use createUTF8().
		@param	core				the AvmCore instance to use
		@param	buffer				the character buffer. may not be null.
		@param	len					the size in characters. If < 0, assume null termination and calculate.
		@param	desiredWidth		the desired width; use kAuto to get a string as narrow as possible
		@param	staticBuf			if true, the buffer is static, and may be used by the string
		@return						the String instance, or NULL on out-of-memory
		*/
		static	Stringp				createLatin1(AvmCore* core, const char* buffer, int32_t len = -1, Width desiredWidth = kDefaultWidth, bool staticBuf = false);

		/**
		Create a string using UTF-8 data.
		@param	avm					the AvmCore instance to use
		@param	buffer				the UTF-8 buffer. may not be null.
		@param	len					the size in bytes. If < 0, assume null termination and calculate.
		@param	desiredWidth		the desired width; use kAuto to get a string as narrow as possible
		@param	staticBuf			if true, the buffer is static, and may be used by the string
		@return						the String instance, or NULL on out-of-memory, or bad characters
		*/
		static	Stringp				createUTF8(AvmCore* core, const utf8_t* buffer, int32_t len = -1, 
												String::Width desiredWidth = String::kDefaultWidth, bool staticBuf = false);
		/**
		Create a string using UTF-16 data. If the width is k32, and there are surrogate pairs, they
		will be resolved. If this is not desired, use String::create() instead (only present if
		FEATURE_UTF32_SUPPORT is defined). If the desired width is too small to fit the source data, 
		return NULL.
		@param	avm					the AvmCore instance to use
		@param	buffer				the UTF-16 buffer. may not be null.
		@param	len					the size in characters. If < 0, assume null termination and calculate.
		@param	desiredWidth		the desired width; use kAuto to get a string as narrow as possible
		@param	staticBuf			if true, the buffer is static, and may be used by the string
		@return						the String instance, or NULL on out-of-memory, or characters too wide
		*/
		static	Stringp				createUTF16(AvmCore* core, const wchar* buffer, int32_t len = -1, 
												 String::Width desiredWidth = String::kDefaultWidth, bool staticBuf = false);

#ifdef FEATURE_UTF32_SUPPORT
		/**
		Create a string using UTF-32 data. Characters > 0xFFFF are encoded into UTF-16 surrogate
		pairs if the desired width is k16. Note that UTF-32 characters > 0x10FFFF are rejected
		because of a possible integer overrun during comparisons. If the desired width is too 
		small to fit the source data, return NULL.
		@param	avm					the AvmCore instance to use
		@param	buffer				the UTF-32 buffer
		@param	len					the size in characters. If < 0, assume null termination and calculate.
		@param	desiredWidth		the desired width; use kAuto to get a string as narrow as possible
		@param	staticBuf			if true, the buffer is static, and may be used by the string
		@return						the String instance,  or NULL on out-of-memory, or characters too wide
		*/
		static	Stringp				createUTF32(AvmCore* core, const utf32_t* buffer, int32_t len = -1, 
												 String::Width desiredWidth = String::kDefaultWidth, bool staticBuf = false);
#endif
		virtual						~String();

		/**
		Create a string out of an ABC string pool stored in the given ByteArray.
		Returns NULL on out-of-memory, or on bad UTF-8 data.
		@param	core				the AvmCore instance to use
		@param	buff				the ByteArray containing the string
		@param	offset				the offset of the string
		@param	len					the string length
		@param	desiredWidth		the desired string width
		@return						the String instance, or NULL on out-of-memory
		static Stringp				newPoolString(AvmCore* core, const ByteArray *buff, uint32_t offset, uint32_t len, Width desiredWidth = kAuto);
		*/
		/**
		Create a string with a given width out of this string. If the width is equal to the current
		width, return this instance. If the desired width is too narrow to fit, or kAuto is passed
		in, or there is no memory left, return NULL.
		@param	w					the width of the new string(kAuto is not supported)
		@return						the String instance, or NULL on kAuto, string too wide, or out-of-memory
		*/
				Stringp	FASTCALL	getFixedWidthString(Width w) const;

		/**
		Check this string for being a dependent string; if so, create and return
		a copy. The AvmCore uses this method to ensure that interned strings are
		never dependent; if dependent strings could be interned, this would keep
		the master string from being released, which, with a large master string,
		may be a huge waste of memory.
		*/
				Stringp	FASTCALL	getIndependentString() const;
		/**
		Returns the Atom equivalent of this String.  This is
		done by or'ing the proper type bits into the pointer.
		*/
		inline	Atom				atom() const { return Atom(AtomConstants::kStringType | uintptr_t(this)); }
		/**
		virtual version of atom():
		*/
		virtual Atom				toAtom() const { return atom(); }
		/**
		If this string is a static string, make it dynamic so the static data can be released.
		Returns false if the string is not kStatic.
		*/
				bool				makeDynamic();
		/**
		Produce a has code of this string.
		*/
				uint32_t FASTCALL	hashCode() const;
		/**
		Use the same algorithm to produce a hash code for UTF-8 data.
		*/
		static	uint32_t FASTCALL	hashCodeUTF8(const utf8_t* buf, int32_t len);
		/**
		Use the same algorithm to produce a hash code for UTF-16 data.
		*/
		static	uint32_t FASTCALL	hashCodeUTF16(const wchar* buf, int32_t len);
		/// Return the length in characters.
		inline	int32_t				length() const { return m_length; }
		// overload used by AS3 glue code.
				int					get_length() const { return m_length; }
		/// Is this string empty?
		inline	bool isEmpty()		const { return m_length == 0; }
		/// Return the width constant.
		inline	Width				getWidth() const { return Width(m_bitsAndFlags & TSTR_WIDTH_MASK); }
		/// Return the string typex.
		inline	int32_t				getType() const { return ((m_bitsAndFlags & TSTR_TYPE_MASK) >> TSTR_TYPE_SHIFT); }
		/// Is this an interned string?
		inline	bool				isInterned() const { return 0 != (m_bitsAndFlags & TSTR_FLAG_INTERNED); }
		/// Mark this string as interned.
		inline	void				setInterned() { m_bitsAndFlags |= TSTR_FLAG_INTERNED; }
		/**
		Return the character at the given position. No index checks!
		@param	index				the index
		@return						the character at the index
		*/
				CharAtType FASTCALL	charAt(int32_t index) const;

		/**
		Compare the String with toCompare. If the length is > 0, compare
		the other string up to the given length.
		@param	other				the string to compare with
		@param	start				the starting position
		@param	length				the length to compare(if > 0)
		@return = 0 if the strings are identical,
		        < 0 if this string is less than toCompare,
		        > 0 if this string is greater than toCompare
		 */
				int32_t FASTCALL	Compare(String& other, int32_t start = 0, int32_t length = 0) const;
		/**
		Compare this string with a ASCII string.
		*/
				bool	FASTCALL	Equals(const char* p) const;
		/**
		Compare this string with a UTF-16 string.
		*/
				bool	FASTCALL	Equals(const wchar* p, int32_t len) const;
		///
		inline	bool				FastEquals(const wchar* p, int32_t len) const { return Equals(p, len); }
		/**
		Localized compare - maps to compare().
		*/
				int32_t FASTCALL	localeCompare(Stringp other, const Atom* argv, int32_t argc);
		/*@{*/
		/**
		 * Compares s1 and s2.
		 * @return = 0 if the strings are identical.
		 *         < 0 if s1 is less than s2
		 *         > 0 if s1 is greater than s2
		 */		
		static	int32_t	FASTCALL	Compare(const wchar *s1, int32_t len1, const wchar *s2, int32_t len2);
		///
		static	int32_t	FASTCALL	Compare(const wchar *s1, const char *s2, int32_t len);
		/*@}*/

		/*@{*/
		/**
		 * Returns the length of str, in # of characters.
		 */
		static int32_t	FASTCALL	Length(const wchar *str);
		static int32_t	FASTCALL	Length(const char *str);
		/*@}*/
		/**
		Compare the String with an UTF-8 buffer. On a bad UTF-8 character sequence,
		return false. This method is used for hash table lookups.
		*/
				bool FASTCALL		equalsUTF8(const utf8_t* buf, int32_t bytes) const;
		/**
		Implements String.indexOf().
		*/
				int32_t	FASTCALL	indexOf(Stringp s, int32_t offset = 0) const;
		/**
		Convenience method: indexOf() for a Latin-1 string within a given range.
		@param	p					the character string to compare; NULL returns -1
		@param	len					the number of characters to compare; if < 0, call Length()
		@param	start				the starting position
		@param	end					the ending position
		@return						the index of the found position, or -1 if no match
		*/
				int32_t FASTCALL	indexOf(const char* p, int32_t len = -1, int32_t start = 0, int32_t end = 0x7FFFFFFF) const;
		/**
		Convenience method: Does a Latin-1 string match at the current position?
		@param	p					the character string to compare; NULL returns false
		@param	len					the number of characters to compare; if < 0, call Length()
		@param	pos					the position to match
		@param	caseless			true for a caseless match
		@return						true if the string matches
		*/
				bool	 FASTCALL	matches(const char* p, int32_t len, int32_t pos, bool caseless = false);
		/**
		Implements String.lastIndexOf().
		*/
				int32_t	FASTCALL	lastIndexOf(Stringp s, int32_t offset = 0x7fffffff) const;
		/**
		Concatenate two strings, and return the result. If the right string fits into the buffer
		end of the left string, append the data and return a new dependent string pointing
		to that buffer. If it does not fit, create a kDirect string containing the entire
		buffer, with extra padding at the end to support in-place concatenation.
		@param	left				the left string; may be NULL
		@param	right				the right string; may be NULL, although not meaningful
		@return						the concatenated string
		*/
		static	Stringp	FASTCALL	concatStrings(Stringp leftStr, Stringp rightStr);
		/**
		Append a String instance.
		@param	src					the string to append
		@return						the concatenated string
		*/
				Stringp	FASTCALL	append(const String* str);
		/**
		Append a character buffer with a given size and width. Of course, the width kAuto is
		not allowed here - the character width should be supplied correctly!
		@param	src					the source buffer
		@param	numChars			the number of characters in that buffer
		@param	width				the width of the buffer characters
		@return						the concatenated string
		*/
				Stringp	FASTCALL	append(const void* buffer, int32_t numChars, Width charWidth);
		/*
		Append a 8-bit-wide string. For Unicode, strings should be Latin1, not UTF8.
		*/
		inline	Stringp				appendLatin1(const char* p) { return append(p, Length(p), k8); }
		inline	Stringp				appendLatin1(const char* p, int32_t len) { return append(p, len, k8); }
		/*
		Append a 16-bit-wide string. For Unicode, strings should be UTF16, but this is not enforced
		by this method: indeed, several callers expect to be able to create "illegal" UTF16 sequences
		via this call, for backwards compatibility. Thus, this is a dangerous call and should be used with
		caution (and is also the reason it is not named "appendUTF16").
		*/
		inline	Stringp				append16(const wchar* p) { return append(p, Length(p), k16); }
		inline	Stringp				append16(const wchar* p, int32_t len) { return append(p, len, k16); }
		/**
		Implement String.substr(). The resulting String object points into the original string, 
		and holds a reference to the original string.
		*/
				Stringp	FASTCALL	substr(int32_t start, int32_t len);
		/**
		Implement String.substring(). The resulting String object points into the original string, 
		and holds a reference to the original string.
		*/
				Stringp	FASTCALL	substring(int32_t start, int32_t end);
		/**
		Implement String.slice(). The resulting String object points into the original string, 
		and holds a reference to the original string.
		*/
				Stringp	FASTCALL	slice(int32_t start, int32_t end);
		/**
		This routine is a very specific parser to generate a positive integer from a string.
		The following are supported:
		"0" - one single digit for zero - NOT "00" or any other form of zero
		[1-9]+[0-9]* up to 2^32-2(4294967294)
		2^32-1(4294967295) is not supported(see ECMA quote below).
		The ECMA that we're supporting with this routine is...
		cn:  the ES3 test for a valid array index is 
		 "A property name P(in the form of a string value) is an array index if and 
		 only if ToString(ToUint32(P)) is equal to P and ToUint32(P) is not equal to 2^32-1."
		Don't support 000000 as 0.
		We don't support 0x1234 as 1234 in hex since string(1234) doesn't equal '0x1234')
		No leading zeros are supported
		*/
				bool	FASTCALL	parseIndex(uint32_t& result) const;
		/**
		Returns a new string object which is a copy of this string object, with all 
		characters in the string converted to uppercase. 
		Unicode character classes for uppercase and lowercase are used. The conversion 
		behavior is compliant with the String.toUpperCase method. The method returns
		this instance if no changes were detected.
		@return						the resulting string or NULL
		*/
				Stringp FASTCALL	toUpperCase();
		/**
		Returns a new string object which is a copy of this string object, with all 
		characters in the string converted to lowercase. 
		Unicode character classes for uppercase and lowercase are used. The conversion 
		behavior is compliant with the String.toUpperCase method. The method returns
		this instance if no changes were detected.
		@return						the resulting string or NULL
		*/
				Stringp FASTCALL	toLowerCase();
		/**
		Change the case of a string according to the case mapper supplied.
		If no changes were detected, return this instance, otherwise, return
		a new instance. Returns NULL on out-of-memory.
		@param	unimapper			the mapping function to call
		@return						the changed string or NULL on out-of-memory
		*/
				Stringp	FASTCALL	caseChange(uint32_t(*unimapper)(uint32_t));
		/**
		Returns a kIntegerAtom Atom if the string holds an integer that fits into
		such an atom. For use in our ScriptObject HashTable implementation.  If we 
		have a valid integer equivalent, it will never be zero since kIntegerType tag != 0.
		*/
				Atom	FASTCALL	getIntAtom() const;
		/**
		This conversion handles hex, octal, base 10 integer, float, and "Infinity"/"-Infinity".
		*/
				double				toNumber();
		/**
		Create a 0-terminated UTF-8 string out of this string.
		*/
				UTF8String*			toUTF8String() const;
		/**
		Create a 0-terminated UTF-16 string out of this string.
		If this is a 32-bit string, characters > 0xFFFF are
		converted to surrogate pairs.
		*/
				UTF16String*		toUTF16String() const;
		/**
		Check if this character is a valid space character.
		*/
		static	bool				isSpace(wchar ch);
		/**
		Is this string all whitespace?
		*/
				bool				isWhitespace() const;

		/// Native functions, used by StringClass.cpp
				int					_indexOf(Stringp s, int i=0);
				int					AS3_indexOf(Stringp s, double i=0);

				int					_lastIndexOf(Stringp s, int i=0x7fffffff);
				int					AS3_lastIndexOf(Stringp s, double i=0x7fffffff);

				Stringp				_charAt(int i=0); 
				Stringp				AS3_charAt(double i=0); 

				double				_charCodeAt(int i); // returns NaN for out-of-bounds
				double				AS3_charCodeAt(double i); // returns NaN for out-of-bounds

				int					AS3_localeCompare(Stringp other);

				Stringp				_substring(int i_start, int i_end);
				Stringp				AS3_substring(double d_start, double d_end);

				Stringp				_slice(int dStart, int dEnd);
				Stringp				AS3_slice(double dStart, double dEnd);

				Stringp				_substr(int dStart, int dEnd);
				Stringp				AS3_substr(double dStart, double dEnd);

				Stringp				AS3_toUpperCase();
				Stringp				AS3_toLowerCase();

		// Useful utilities used by the core code.
		static	wchar				wCharToUpper(wchar ch) { return (wchar) unicharToUpper((utf32_t) ch); }
		static	wchar				wCharToLower(wchar ch) { return (wchar) unicharToLower((utf32_t) ch); }
		static	utf32_t				unicharToUpper(utf32_t ch);
		static	utf32_t				unicharToLower(utf32_t ch);
#ifdef DEBUGGER
		virtual uint64				size() const;
#endif

	private:
		friend class StringIndexer;
		friend class UTF8String;
		friend class UTF16String;
		friend class PrintWriter;

								String(int32_t length, uint32_t bits);
		inline	void			operator delete(void*) {}	// Strings cannot be deleted, therefore private

				int32_t			m_length;					// length in characters
		mutable	uint32_t		m_bitsAndFlags;				// various bits and flags, see below(must be unsigned)
				enum {
					TSTR_WIDTH_MASK			= 0x00000007,	// string width(right-aligned for fast access)
					TSTR_FLAG_INTERNED		= 0x00000008,	// this string is interned
					TSTR_TYPE_MASK			= 0x000000F0,	// type index, 4 bits
					TSTR_TYPE_SHIFT			= 4,
					TSTR_NOINT_FLAG			= 0x00000100,	// set in getIntAtom() if the string is not an 28-bit integer
					TSTR_NOUINT_FLAG		= 0x00000200,	// set in parseIndex() if the string is not an unsigned integer
					TSTR_DYNAMIC_FLAG		= 0x00000400,	// data buffer needs deletion(if kStatic)
					TSTR_CHARSLEFT_MASK		= 0xFFFFF000,	// characters left in buffer field(for inplace concat)
					TSTR_CHARSLEFT_SHIFT	= 12
				};
		inline	void			setType(char index)			{ m_bitsAndFlags = (m_bitsAndFlags & ~TSTR_TYPE_MASK) |(index << TSTR_TYPE_SHIFT); }
		inline	int32_t			getCharsLeft() const		{ return (m_bitsAndFlags & TSTR_CHARSLEFT_MASK) >> TSTR_CHARSLEFT_SHIFT; }
		inline	void			setCharsLeft(int32_t n)		{ m_bitsAndFlags = (m_bitsAndFlags & ~TSTR_CHARSLEFT_MASK) |(n << TSTR_CHARSLEFT_SHIFT); }

		union _direct
			{
				char c8[1]; // actual size varies
				wchar c16[1];
				utf32_t	c32[1];
		};

		struct _dependent
		{
			Stringp			master;
			Pointers		p;
		};

		union
		{
			// Characters follow the instance; this is the case for
			// all strings created directly.
			union _direct			m_direct;

			// External, static buffer.
			Pointers				m_static;

			// A dependent string is the result of an in-place concat,
			// or a substr. Its buffer pointer points into the master's
			// buffer, and the master member holds a refcounted pointer
			// to the master string.
			struct _dependent		m_dependent;
		};
		// Create a string with no buffer.
		static	Stringp	FASTCALL	createDependent(GC* gc, Stringp master, int32_t start, int32_t len);
		// Create a string with a direct buffer.
		static	Stringp	FASTCALL	createDirect(GC* gc, const void* data, int32_t len, Width w, int32_t extra=0);
		// Create a string with a static buffer.
		static	Stringp	FASTCALL	createExternal(GC* gc, const void* data, int32_t len, Width w);
		// Redefine new for in-place construction.
		inline	void*				operator new(size_t, Stringp p) { return p; }
		// Calculate the hash code.
				uint32_t FASTCALL	_hashCode();
		// Do a raw buffer compare.
		static	int32_t	FASTCALL	compare(const Pointers& r1, Width w1, const Pointers& r2, Width w2, int32_t len);
		// Return the raw pointer to the string data.
		const	void*	FASTCALL	getData() const;
		/**
		Use a Pointers instance to quickly access a character given the Pointers
		instance containing the buffer start, and the string width. No index checks!
		*/
				CharAtType FASTCALL	charAt(const Pointers& r, int32_t index) const;
	};

	// Compare helpers
	inline bool operator==(String& s1, String& s2)
	{ 
		return s1.Compare(s2) == 0;
	}
	inline bool operator!=(String& s1, String& s2)
	{
		return s1.Compare(s2) != 0;
	}
	inline bool operator<(String& s1, String& s2)
	{ 
		return s2.Compare(s1) < 0; 
	}
	inline bool operator>(String& s1, String& s2)
	{ 
		return s2.Compare(s1) > 0;
	}
	inline bool operator<=(String& s1, String& s2)
	{ 
		return s2.Compare(s1) <= 0;
	}
	inline bool operator>=(String& s1, String& s2)
	{ 
		return s2.Compare(s1) >= 0; 
	}

	/**
	The StringIndexer class provides quick access to single characters by index.
	Use an instance of this class on the stack if multiple index access is required.
	This class does not need to call getData() for each index access, which charAt()
	without a Pointers argument does internally.
	*/

	class StringIndexer
	{
	public:
		/// The constructor takes the string to index.
		inline						StringIndexer(Stringp s) : m_str(s) { m_ptrs.pv = (void*) s->getData(); }
		inline						~StringIndexer() { m_str = NULL; m_ptrs.pv = NULL; }
		/// Return the embedded string.
		inline	Stringp				operator->() const { return m_str; }
		/// Quick index operator.
		inline	String::CharAtType	operator[](int index) const { return m_str->charAt(m_ptrs, index); }

	private:
		// do not create on the heap
		inline	void*		operator new(size_t) throw() { return NULL; }
		inline	void		operator delete(void*) {}
		Stringp				m_str;
		String::Pointers	m_ptrs;
	};

	/**
	The UTF8String class is simply a data buffer containing 0-terminated
	UTF-8 data. Use String::toUTF8String() to create such a string.
	Note that the length() function returns the length not including the 0-terminator.
	Also note that the string might contain interior NULL characters (if the original
	String did) and thus String::Length, strlen, etc might return misleading values.
	*/

	class UTF8String : public MMgc::GCObject
	{
	public:
		/**
		Convert a string index to an UTF-8 index. 
		Return the original index if out of range.
		*/
				int32_t FASTCALL	toUtf8Index(int32_t pos);
		/**
		Convert an UTF-8 index to a string index.
		Return the original index if < 0.
		*/
				int32_t FASTCALL	toIndex(int32_t uf8Pos);
		///
		inline	const char*			c_str() const { return m_buffer; }
		///
		inline	int32_t				length() const { return m_length; }
	private:
				int32_t				m_lastPos;
				int32_t				m_lastUtf8Pos;
				int32_t				m_length;
				char				m_buffer[1];
				friend class		String;
									UTF8String(int32_t len);
		static	UTF8String*			create8 (const String* s);
		static	UTF8String*			create16(const String* s);
		static	UTF8String*			create32(const String* s);
	};

	/**
	The UTF16String class is simply a data buffer containing 0-terminated
	UTF-16 data. Use String::toUTF16String() to create such a string.
	Note that the length() function returns the length not including the 0-terminator.
	Also note that the string might contain interior NULL characters (if the original
	String did) and thus String::Length, strlen, etc might return misleading values.
	*/

	class UTF16String : public MMgc::GCObject
	{
	public:
		///
		inline	const wchar*	c_str() const { return m_buffer; }
		///
		inline	int32_t			length() const { return m_length; }
	private:
				int32_t			m_length;
				wchar			m_buffer[1];
				friend class	String;
		inline					UTF16String(int32_t len) : m_length(len) {}
	};
	
	// deleting UTF16String and UTF8String immediately hurts performance, but saves memory.
	// If you need a UTF8String or UTF16String temporarily, use these accessor classes:
	// they will delete (or not) the temporary in the dtor, allowing the embedder to 
	// prefer memory vs performance.
	
	// if embedder doesn't define this, assume we prefer performance
	// (note that the test is on value)
	#ifndef FEATURE_PREFER_STRING_PERFORMANCE
		#define FEATURE_PREFER_STRING_PERFORMANCE 1
	#endif
	
	class StUTF8String
	{
	private:
		UTF8String* str;
	public:
		inline explicit StUTF8String(Stringp s) : str(s ? s->toUTF8String() : NULL) {}
		inline ~StUTF8String() 
		{ 
			#if FEATURE_PREFER_STRING_PERFORMANCE
			// allow it to be collected
			str = NULL; 
			#else
			// delete right away
			delete str;
			#endif
		}
		inline UTF8String* operator->() const { return str; }
		inline operator UTF8String*() { return str; }
		inline operator UTF8String&() { return *str; }
	private:
		// do not create on the heap
		inline	void*		operator new(size_t) throw() { return NULL; }
		inline	void		operator delete(void*) {}		
	};

	class StUTF16String
	{
	private:
		UTF16String* str;
	public:
		inline explicit StUTF16String(Stringp s) : str(s ? s->toUTF16String() : NULL) {}
		inline ~StUTF16String() 
		{ 
			#if FEATURE_PREFER_STRING_PERFORMANCE
			// allow it to be collected
			str = NULL; 
			#else
			// delete right away
			delete str;
			#endif
		}
		inline UTF16String* operator->() const { return str; }
		inline operator UTF16String*() { return str; }
		inline operator UTF16String&() { return *str; }
	private:
		// do not create on the heap
		inline	void*		operator new(size_t) throw() { return NULL; }
		inline	void		operator delete(void*) {}		
	};
	
}

#endif	// __avmplus_NewString__
