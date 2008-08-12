
#define I_I   (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<2)
#define I_II  (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_III (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<6 | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_I4  (nanojit::ARGSIZE_LO | \
    nanojit::ARGSIZE_LO<<8 | nanojit::ARGSIZE_LO<<6 |\
    nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_I5  (nanojit::ARGSIZE_LO | \
    nanojit::ARGSIZE_LO<<10 |\
    nanojit::ARGSIZE_LO<<8 | nanojit::ARGSIZE_LO<<6 | \
    nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_I7  (nanojit::ARGSIZE_LO | \
    nanojit::ARGSIZE_LO<<14 |\
    nanojit::ARGSIZE_LO<<12 | nanojit::ARGSIZE_LO<<10 | \
    nanojit::ARGSIZE_LO<<8 | nanojit::ARGSIZE_LO<<6 | \
    nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_ID  (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_F<<2)
#define D_I   (nanojit::ARGSIZE_F | nanojit::ARGSIZE_LO<<2)
#define D_DD  (nanojit::ARGSIZE_F | nanojit::ARGSIZE_F<<4 | nanojit::ARGSIZE_F<<2)

#define NOFOLD_FUNCTION(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,0,/*abi*/0,/*ret*/,/*args*/)
#define PURE_FUNCTION(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,1,/*abi*/0,/*ret*/,/*args*/)
#define FUNCTION(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,0,0,ABI_CDECL,/*ret*/,/*args*/)

INTERP_FOPCODE_LIST_BEGIN

FUNCTION(COREADDR(AvmCore::doubleToAtom), I_ID)

INTERP_FOPCODE_LIST_END

#undef I_I
#undef I_II
#undef I_III
#undef I_I4
#undef I_I5
#undef I_I7
#undef I_ID
#undef D_I
#undef D_DD
#undef NOFOLD_FUNCTION
#undef PURE_FUNCTION
#undef FUNCTION
