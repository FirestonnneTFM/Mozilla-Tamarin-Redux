
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
#define I_I6  (nanojit::ARGSIZE_LO | \
    nanojit::ARGSIZE_LO<<12 | nanojit::ARGSIZE_LO<<10 | \
    nanojit::ARGSIZE_LO<<8 | nanojit::ARGSIZE_LO<<6 | \
    nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_I7  (nanojit::ARGSIZE_LO | \
    nanojit::ARGSIZE_LO<<14 |\
    nanojit::ARGSIZE_LO<<12 | nanojit::ARGSIZE_LO<<10 | \
    nanojit::ARGSIZE_LO<<8 | nanojit::ARGSIZE_LO<<6 | \
    nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_I8  (nanojit::ARGSIZE_LO | \
    nanojit::ARGSIZE_LO<<16 | nanojit::ARGSIZE_LO<<14 | \
    nanojit::ARGSIZE_LO<<12 | nanojit::ARGSIZE_LO<<10 | \
    nanojit::ARGSIZE_LO<<8 | nanojit::ARGSIZE_LO<<6 | \
    nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_ID  (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_F<<2)
#define D_I   (nanojit::ARGSIZE_F | nanojit::ARGSIZE_LO<<2)
#define D_DD  (nanojit::ARGSIZE_F | nanojit::ARGSIZE_F<<4 | nanojit::ARGSIZE_F<<2)

#define CSEFUNCTION(f, sig, name) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,0,/*abi*/0,/*ret*/,/*args*/,name)
#define PURE_FUNCTION(f, sig, name) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,1,/*abi*/0,/*ret*/,/*args*/,name)
#define FUNCTION(f, sig, name) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,0,0,ABI_CDECL,/*ret*/,/*args*/,name)
#define METHOD(f, sig, name) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,0,0,ABI_THISCALL,/*ret*/,/*args*/,name)
#define CSEMETHOD(f, sig, name) INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,0,ABI_THISCALL,/*ret*/,/*args*/,name)

INTERP_FOPCODE_LIST_BEGIN

    METHOD(ENVADDR(MethodEnv::debugEnter), I_I8, debugEnter)
    METHOD(ENVADDR(MethodEnv::debugExit), I_II, debugExit)
    METHOD(ENVADDR(MethodEnv::getActivation), I_I, getActivation)
    METHOD(COREADDR(AvmCore::newActivation), I_III, newActivation)
    METHOD(ENVADDR(MethodEnv::newcatch), I_II, newCatch)
    METHOD(ENVADDR(MethodEnv::newfunction), I_I4, newfunction)
    METHOD(TOPLEVELADDR(Toplevel::op_call), I_I4, op_call)
    METHOD(TOPLEVELADDR(Toplevel::callproperty), I_I6, callproperty)
    METHOD(EFADDR(ExceptionFrame::endTry), I_I, endTry)
    CSEMETHOD(TOPLEVELADDR(Toplevel::coerce), I_III, coerce)
    METHOD(ENVADDR(MethodEnv::npe), I_I, npe)
    METHOD(ENVADDR(MethodEnv::interrupt), I_I, interrupt)
    
    FUNCTION(COREADDR(AvmCore::doubleToAtom), I_ID, doubleToAtom)

INTERP_FOPCODE_LIST_END

#undef I_I
#undef I_II
#undef I_III
#undef I_I4
#undef I_I5
#undef I_I6
#undef I_I7
#undef I_I8
#undef I_ID
#undef D_I
#undef D_DD
#undef NOFOLD_FUNCTION
#undef PURE_FUNCTION
#undef FUNCTION
