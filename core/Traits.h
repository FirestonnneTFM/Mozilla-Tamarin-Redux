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

#ifndef __avmplus_Traits__
#define __avmplus_Traits__


namespace avmplus
{
	// Note: we rely on being able to store this in 3 bits. 
	enum TraitsPosType
	{
		TRAITSTYPE_INSTANCE_FROM_ABC		= 0,	
		TRAITSTYPE_CLASS_FROM_ABC			= 1,
		TRAITSTYPE_SCRIPT_FROM_ABC			= 2,
		TRAITSTYPE_CATCH					= 3,
		TRAITSTYPE_ACTIVATION				= 4,
		TRAITSTYPE_NVA						= 5,		// null/void/any -- traitsPos will always be null
		TRAITSTYPE_RT						= 6			// Traits defined at runtime, e.g. instantiated parameterized types
		//TRAITSTYPE_unused					= 7
	};
	
	const uint32_t NOT_DERIVED_OR_XML_MASK = 
// commented out, why?
//		(1<<BUILTIN_array) |
//		(1<<BUILTIN_date) |
//		(1<<BUILTIN_regexp) |
		(1<<BUILTIN_boolean) |
		(1<<BUILTIN_class) |
		(1<<BUILTIN_function) |
		(1<<BUILTIN_int) |
		(1<<BUILTIN_methodClosure) |
		(1<<BUILTIN_namespace) |
		(1<<BUILTIN_null) |
		(1<<BUILTIN_number) |
		(1<<BUILTIN_object) |
		(1<<BUILTIN_qName) |
		(1<<BUILTIN_string) |
		(1<<BUILTIN_uint) |
		(1<<BUILTIN_void) |
		(1<<BUILTIN_xmlList) |
		(1<<BUILTIN_xml);

	const uint32_t MACHINE_TYPE_MASK = (1<<BUILTIN_object) | (1<<BUILTIN_void) | (1<<BUILTIN_int) | (1<<BUILTIN_uint) | (1<<BUILTIN_boolean) | (1<<BUILTIN_number);
	const uint32_t NUMERIC_TYPE_MASK = (1<<BUILTIN_int) | (1<<BUILTIN_uint) | (1<<BUILTIN_number);
	const uint32_t XML_TYPE_MASK = (1<<BUILTIN_xml) | (1<<BUILTIN_xmlList);

	typedef const uint8_t* TraitsPosPtr;

	// Note: we rely on this being <= 8 entries.
	enum SlotStorageType
	{
		// we rely on these 4 being first, so we can do <= SST_scriptobject in isAtomOrRCObjectSlot.
		// SST_atom is most frequently encountered, so value of zero is best
		SST_atom,
		SST_string,
		SST_namespace,
		SST_scriptobject,
		
		SST_int32,
		SST_uint32,
		SST_bool32,
		SST_double
	};
	bool isAtomOrRCObjectSlot(SlotStorageType sst);
	
	class TraitsBindings : public QCachedItem
	{
		friend class Traits;
		friend class StTraitsBindingsIterator;
	
	private:
		struct SlotInfo
		{
			Traitsp type;	
			uint32_t offsetAndSST;	// lower 3 bits: SlotStorageType, upper 29 bits: offset div 4
			#ifdef AVMPLUS_64BIT
			uint32_t padding;	// alignment to power-of-two boundary is a Good Thing here
			#endif
			SlotStorageType sst() const;	// get just the storage type of this slot
			uint32_t offset() const;		// get just the offset of this slot
		};

		struct BindingMethodInfo
		{
			MethodInfo* f;
		};
		
		struct InterfaceInfo
		{
			Traits* t;
		};
		
	private:
		TraitsBindings(Traits* _owner, 
							TraitsBindingsp _base, 
							MultinameHashtable* _bindings,
							uint32_t _slotCount, 
							uint32_t _methodCount, 
							uint32_t _interfaceCapacity);

	public:
		static const uint32_t MAX_SLOT_OFFSET = (1U << 31) - 1;

	public:
		
		static TraitsBindings* alloc(MMgc::GC* gc, Traits* _owner, TraitsBindingsp _base, MultinameHashtable* _bindings, uint32_t slotCount, uint32_t methodCount, uint32_t interfaceCount);

		void buildSlotDestroyInfo(MMgc::GC* gc, FixedBitSet& slotDestroyInfo) const;

		Traitsp getSlotTraits(uint32_t i) const;
		uint32_t getSlotOffset(uint32_t i) const;
		// if you need SST you probably want offset too
		SlotStorageType calcSlotAddrAndSST(uint32_t i, void* pin, void*& pout) const;
		Traitsp getInterface(uint32 i) const;
		MethodInfo* getMethod(uint32_t i) const;
		bool FASTCALL containsInterface(Traitsp t) const;
		Binding findBinding(Stringp key) const;
		Binding findBinding(Stringp name, Namespacep ns) const;
		Binding findBinding(Stringp name, NamespaceSetp nsset) const;
		Binding findBindingAndDeclarer(const Multiname& mn, Traitsp& declarer) const;

		// note: if you are just doing a single iteration thru a single TraitsBindings,
		// it's more efficient (and easier) to use StTraitsBindingsIterator instead.
		int32_t next(int32_t index) const;
		Stringp keyAt(int32_t index) const;
		Namespacep nsAt(int32_t index) const;
		Binding valueAt(int32_t index) const;

	private:
		SlotInfo* getSlots();
		const SlotInfo* getSlots() const;

		InterfaceInfo* getInterfaces();
		const InterfaceInfo* getInterfaces() const;

		BindingMethodInfo* getMethods();
		const BindingMethodInfo* getMethods() const;

		void setSlotInfo(uint32_t i, Traits* t, SlotStorageType sst, uint32_t offset);

		void setMethodInfo(uint32_t i, MethodInfo* f);

		bool addOneInterface(Traitsp intf);
		bool checkOverride(AvmCore* core, MethodInfo* virt, MethodInfo* over) const;
		bool checkLegalInterfaces(AvmCore* core) const;
		void fixOneInterfaceBindings(Traitsp ifc, const Toplevel* toplevel);
		
	// ------------------------ DATA SECTION BEGIN
		public:		const Traitsp					owner;
		public:		const TraitsBindingsp			base; 
		private:	MultinameHashtable* const		m_bindings;
		public:		const uint32_t					slotCount;			// including slots in our base classes
		public:		const uint32_t					methodCount;		// including methods in our base classes
		public:		const uint32_t					interfaceCapacity;	// cap, not count: will contain null entries
		private:	uint32_t						m_slotSize;			// size of slot area in bytes, including base classes
		// plus extra at end
	// ------------------------ DATA SECTION END

	};
	
	// NOTE: caller must check for null key, eg,
	//
	//		StTraitsBindingsIterator iter(mnht);
	//		while (iter.next()) {
	//			if (!iter.key()) continue;
	//			.. rest of loop ..
	//		}
	//
	class StTraitsBindingsIterator : public StMNHTIterator
	{
	private:
		TraitsBindingsp const volatile _tb;	// kept just to ensure it doesn't get collected -- must be volatile!
	public:
		StTraitsBindingsIterator(TraitsBindingsp tb);
	};

	class TraitsMetadata : public QCachedItem
	{
		friend class Traits;

	public:
		typedef const uint8_t* MetadataPtr;

	private:
		TraitsMetadata(TraitsMetadatap _base, PoolObject* _residingPool, MetadataPtr _metadata_pos, uint32_t _slotCount, uint32_t _methodCount);

	public:
		MetadataPtr getMetadataPos(PoolObject*& residingPool) const;
		MetadataPtr getSlotMetadataPos(uint32_t i, PoolObject*& residingPool) const;
		MetadataPtr getMethodMetadataPos(uint32_t i, PoolObject*& residingPool) const;

	// ------------------------ DATA SECTION BEGIN
		public:		const TraitsMetadatap			base; 
		private:	PoolObject* const				residingPool;
		public:		const uint32_t					slotCount;			// including slots in our base classes
		public:		const uint32_t					methodCount;		// including methods in our base classes
		private:	MetadataPtr						metadataPos;
		private:	MetadataPtr*					slotMetadataPos;
		private:	MetadataPtr*					methodMetadataPos;
	// ------------------------ DATA SECTION END
	};

	typedef ClassClosure* (*CreateClassClosureProc)(VTable*);
	
	/**
	 * Traits objects describe the layout of objects.  Traits are
	 * used to describe a variety of things in the VM, such as
	 * classes, global objects, and activation objects.
	 *
	 * A Traits object contains a hash table with the names of
	 * all properties and methods.  Each name maps to a binding.
	 *
	 * There are several types of binding: binding to a slot,
	 * binding to an accessor, binding to a virtual function,
	 * binding to a final function.
	 */
	class Traits : public MMgc::GCObject 
	{
		friend class TraitsBindings;	// for m_sizeofInstance
		#if defined FEATURE_NANOJIT
		friend class CodegenLIR;
		#endif

	public:

		uint32_t getSizeOfInstance() const;
		uint32_t getHashtableOffset() const;
		uint32_t getTotalSize() const;

		// in bytes. includes size for all base classes too.
		uint32_t getSlotAreaSize() const;
		uint32_t getSlotAreaStart() const;

		// in bytes. includes size for all base classes too.
		uint32_t getExtraSize() const;

		// sadly, it's still more efficient to stash this in Traits itself, as it's nontrivial to recover when
		// we rebuild the TraitMethodInfo. 
		void setMetadataPos(const byte* pos);

	private:
		void buildBindings(TraitsBindingsp basetb, 
							MultinameHashtable* bindings, 
							uint32_t& slotCount, 
							uint32_t& methodCount,
							const Toplevel* toplevel) const;
		uint32_t finishSlotsAndMethods(TraitsBindingsp basetb, 
									TraitsBindings* tb, 
									const Toplevel* toplevel,
									AbcGen* abcGen) const;
		TraitsBindings* _buildTraitsBindings(const Toplevel* toplevel, AbcGen* abcGen);

		TraitsMetadata* _buildTraitsMetadata();

		TraitsPosPtr traitsPosStart() const;
		TraitsPosPtr skipToInstanceInitPos(TraitsPosPtr pos) const;
		void countInterfaces(const Toplevel* toplevel, List<Traitsp, LIST_GCObjects>& seen);
		bool addInterfaces(TraitsBindings* tb, const Toplevel* toplevel);
		Binding getOverride(TraitsBindingsp basetb, Namespacep ns, Stringp name, int tag, const Toplevel *toplevel) const;

		void addVersionedBindings(MultinameHashtable* bindings,
								  Stringp name,
								  NamespaceSetp compat_nss,
								  Binding binding) const;

	private:

		/**
		 * Constructor for traits.  base != NULL means inheritance.
		 */
		Traits(PoolObject* pool,
			   Traits* base,
			   uint32_t sizeofInstance,
			   TraitsPosPtr traitsPos,
			   TraitsPosType posType);

		Traits* _newParameterizedTraits(Stringp name, Namespacep ns, Traits* _base);

	public:
		/**
		 * traits with base traits (inheritance)
		 */
		static Traits* newTraits(PoolObject* pool,
			   Traits *base,
				uint32_t sizeofInstance,
				TraitsPosPtr traitsPos,
				TraitsPosType posType);
		
		static Traits* newCatchTraits(const Toplevel* toplevel, PoolObject* pool, TraitsPosPtr traitsPos, Stringp name, Namespacep ns);
		Traits* newParameterizedITraits(Stringp name, Namespacep ns);
		Traits* newParameterizedCTraits(Stringp name, Namespacep ns);

	public:
		bool allowEarlyBinding() const;

	private:
		TraitsBindings* FASTCALL _getTraitsBindings();
		TraitsMetadata* FASTCALL _getTraitsMetadata();

	public:
		TraitsBindingsp getTraitsBindings();
		TraitsMetadatap getTraitsMetadata();
		bool containsInterface(Traitsp t);
		
	public:
		void genDefaultValue(uint32_t value_index, uint32_t slot_id, const Toplevel* toplevel, Traits* slotType, CPoolKind kind, AbcGen& gen) const;
		void genInitBody(const Toplevel* toplevel, AbcGen& gen);
		
		void resolveSignatures(const Toplevel* toplevel);

		// convenient wrapper to check for null (returns "BUILTIN_any")
		static BuiltinType getBuiltinType(const Traitsp t);

		bool notDerivedObjectOrXML() const;
		bool isMachineType() const;
		bool isNumeric() const;
		bool isXMLType() const;

		TraitsPosType posType() const;
		bool isResolved() const;
		bool isActivationTraits() const;

		bool needsHashtable() const;
		void set_needsHashtable(bool v);

		static bool isMachineCompatible(const Traits* a, const Traits* b);

		void setCreateClassClosureProc(CreateClassClosureProc p);
		CreateClassClosureProc getCreateClassClosureProc() const;

		Stringp formatClassName();

		void destroyInstance(ScriptObject *obj) const;

	public:
#if VMCFG_METHOD_NAMES
		Stringp format(AvmCore* core, bool includeAllNamespaces = false) const;
#endif
		
		// call init_declaringScope for each method that we own. this should be
		// called exactly once per Traits, *after* the Traits has been resolved.
		void init_declaringScopes(const ScopeTypeChain* stc);
		
		Namespacep ns() const;
		Stringp name() const;
		void set_names(Namespacep p_ns, Stringp p_name);
		
		// this returns true iff we implement an interface that is not implemented by our parent.
		// essential for efficient building of IMT thunks.
		bool implementsNewInterfaces() const;

	// ------------------------ DATA SECTION BEGIN
	public:		AvmCore* const			core;		// @todo remove, can get from pool->core
	public:		Traits* const			base;		// Pointer to the base traits; that is, the traits of the base class
	public:		PoolObject* const		pool;		// The constant pool owning this definition. never null.
	public:		Traits*					itraits;	// if this type is a factory, itraits is non-null and points to the type created by this factory.
	private:	DRCWB(Namespacep)		_ns;			// The namespace of the class described by this traits object
	private:	DRCWB(Stringp)			_name;		// The name of the class described by this traits object
	public:		DRCWB(Namespacep)		protectedNamespace;	// protected namespace, if any
	public:		DWB(MethodInfo*)		init;				// not a call/init union b/c smart pointers and union's don't mix
	private:	CreateClassClosureProc	m_createClassClosure;
	private:	const TraitsPosPtr		m_traitsPos;		// ptr into our ABC definition, depending on m_posType
	private:	const byte*				metadata_pos;
	private:	FixedBitSet				m_slotDestroyInfo;	
	private:	DWB(MMgc::GCWeakRef*)	m_tbref;				// our TraitsBindings 
	private:	DWB(MMgc::GCWeakRef*)	m_tmref;				// our TraitsMetadata
#ifdef VMCFG_CACHE_GQCN
	private:	DRCWB(Stringp)			_fullname;		// value returned by formatClassName
#endif
// @todo -- we should be able to store m_sizeofInstance in 16 bits but JIT doesn't have a convenient way to do a 16-bit load. Leaving at 32 for now.
// @todo -- what prevents an instance being >64K?
	private:	uint32_t				m_sizeofInstance;	// sizeof implementation class, e.g. ScriptObject, etc. < 64k. Not counting extra room for slots.
	private:	uint32_t				m_hashTableOffset;	// offset to our hashtable (or 0 if none)
	private:	uint32_t				m_totalSize;		// total size, including sizeofInstance + slots + hashtable
	public:		uint8_t					builtinType;				// BuiltinType enumeration -- only need 5 bits but stored in byte for faster access
	private:	const uint8_t			m_posType;					// TraitsPosType enumeration -- only need 3 bits but stored in byte for faster access
	private:	uint8_t					m_bindingCapLog2;			// if nonzero, log2 of the cap needed for bindings
	private:	uint8_t					m_interfaceCapLog2;			// if nonzero, log2 of the cap needed for interfaces
	// 8 bits follow
	private:	uint32_t				m_needsHashtable:1;			// If true, the class needs a hash table. Typically true for dynamic classes, but will be false for XML
	private:	uint32_t				linked:1;					// set once signature types have been resolved */
	public:		uint32_t				final:1;					// set when the class cannot be extended */
	public:		uint32_t				isInterface:1;				// true for types that are interfaces */
	public:		uint32_t				commonBase:1;				// used for Verify::findCommonBase */
	public:		uint32_t				isDictionary:1;				// how we implement dictionary or strict style lookups
							// If hasCustomConstruct is false, the JIT will early bind to the AS defined constructor. 
	public:		uint32_t				hasCustomConstruct:1;		// does this type use the default ClassClosure::construct method or not?
							// If the traits are for a type that implements its own construct method, m_immplementsNewInterfaces must be set to true.  
	private:	uint32_t				m_implementsNewInterfaces:1; // does this type implement interfaces not implemented by its base?
	// ------------------------ DATA SECTION END
	};
}

#endif /* __avmplus_Traits__ */
