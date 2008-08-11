
#define I_I   (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<2)
#define I_II  (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_III (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<6 | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
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

#define NOFOLD_METHOD(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,0,/*ret*/,/*args*/)
#define PURE_METHOD(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,1,/*ret*/,/*args*/)
#define METHOD(f, sig) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,0,0,/*ret*/,/*args*/)

INTERP_FOPCODE_LIST_BEGIN

    NOFOLD_METHOD(doubleToAtom, I_ID)
    PURE_METHOD(avmcore_integer_i, I_I)
    METHOD(debugenter, I_I7)
    NOFOLD_METHOD(createRestHelper, I_III)
    NOFOLD_METHOD(createArgumentsHelper, I_III)
    METHOD(beginTry, I_II)
    METHOD(lirsetjmp, I_II)
    METHOD(beginCatch, I_I5)
    PURE_METHOD(number_d, D_I)
    PURE_METHOD(integer_u, I_I)

INTERP_FOPCODE_LIST_END

#undef I_II
#undef I_ID
#undef NOFOLD_METHOD
#undef PURE_METHOD
#undef METHOD
