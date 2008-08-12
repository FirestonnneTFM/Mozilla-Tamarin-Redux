
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

#define NOFOLD_FUNCTION(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,0,/*ret*/,/*args*/)
#define PURE_FUNCTION(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,1,/*ret*/,/*args*/)
#define FUNCTION(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,0,0,/*ret*/,/*args*/)

INTERP_FOPCODE_LIST_BEGIN

    NOFOLD_FUNCTION(doubleToAtom, I_ID)
    NOFOLD_FUNCTION(doubleToAtom_sse2, I_ID)
    NOFOLD_FUNCTION(intToAtom, I_II)
    NOFOLD_FUNCTION(uintToAtom, I_II)
    PURE_FUNCTION(avmcore_integer_i, I_I)
    FUNCTION(debugenter, I_I7)
    FUNCTION(debugexit, I_II)
    NOFOLD_FUNCTION(createRestHelper, I_III)
    NOFOLD_FUNCTION(createArgumentsHelper, I_III)
    FUNCTION(beginTry, I_II)
    FUNCTION(lirsetjmp, I_II)
    FUNCTION(beginCatch, I_I5)
    PURE_FUNCTION(number_d, D_I)
    PURE_FUNCTION(integer_u, I_I)
    FUNCTION(wbrc, I_I4)
    FUNCTION(wbatom, I_I4)
    FUNCTION(endtry, I_I)
    NOFOLD_FUNCTION(coerce, I_III)
    PURE_FUNCTION(mod, D_DD)
    FUNCTION(throwatom, I_II)
    FUNCTION(typeof, I_II)
    FUNCTION(getsuper, I_III)
    FUNCTION(setsuper, I_I4)
    FUNCTION(nextname, I_III)
    FUNCTION(nextvalue, I_III)
    FUNCTION(hasnext, I_III)
    FUNCTION(hasnext2, I_III)
    NOFOLD_FUNCTION(intern_ns, I_II)
    FUNCTION(initname_late, I_III)
    FUNCTION(initname_late_del, I_III)

INTERP_FOPCODE_LIST_END

#undef I_II
#undef I_ID
#undef NOFOLD_FUNCTION
#undef PURE_FUNCTION
#undef FUNCTION
