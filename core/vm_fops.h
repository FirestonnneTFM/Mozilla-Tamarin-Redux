
#define I_I   (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<2)
#define I_D   (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_F<<2)
#define I_II  (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define D_II  (nanojit::ARGSIZE_F  | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_III (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<6 | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define D_III (nanojit::ARGSIZE_F  | nanojit::ARGSIZE_LO<<6 | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_I4  (nanojit::ARGSIZE_LO | \
    nanojit::ARGSIZE_LO<<8 | nanojit::ARGSIZE_LO<<6 |\
    nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define D_I4  (nanojit::ARGSIZE_F  | \
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

#define FUNCTION(f, sig, name) \
    INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,0,0,ABI_CDECL,/*ret*/,/*args*/,name)
#define CSEFUNCTION(f, sig, name) \
    INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,0,ABI_CDECL,/*ret*/,/*args*/,name)

#define METHOD(f, sig, name) \
    INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,0,0,ABI_THISCALL,/*ret*/,/*args*/,name)
#define CSEMETHOD(f, sig, name) \
    INTERP_FOPCODE_LIST_ENTRY_FUNCPRIM(f,sig,1,0,ABI_THISCALL,/*ret*/,/*args*/,name)

INTERP_FOPCODE_LIST_BEGIN

    FUNCTION(CALL_INDIRECT, I_III, calli)
    FUNCTION(FCALL_INDIRECT, D_III, fcalli)
    FUNCTION(CALL_IMT, I_I4, callimt)
    FUNCTION(FCALL_IMT, D_I4, fcallimt)
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
    METHOD(ENVADDR(MethodEnv::nextname), I_III, nextname)
    METHOD(ENVADDR(MethodEnv::nextvalue), I_III, nextvalue)
    METHOD(ENVADDR(MethodEnv::hasnext), I_III, hasnext)
    METHOD(COREADDR(AvmCore::coerce_s), I_II, coerce_s)
    METHOD(COREADDR(AvmCore::string), I_II, string)
    METHOD(TOPLEVELADDR(Toplevel::coerceobj), I_III, coerceobj)
    METHOD(ENVADDR(MethodEnv::coerceAtom2SO), I_III, coerceAtom2SO)
    CSEMETHOD(COREADDR(AvmCore::doubleToString), I_ID, doubleToString)
    CSEMETHOD(COREADDR(AvmCore::uintToString), I_II, uintToString) 
    CSEMETHOD(COREADDR(AvmCore::intToString), I_II, intToString) 
    FUNCTION(COREADDR(AvmCore::doubleToAtom), I_ID, doubleToAtom)
    CSEMETHOD(COREADDR(AvmCore::boolean), I_II, boolean)
    CSEMETHOD(COREADDR(AvmCore::toUInt32), I_II, toUInt32)
    CSEFUNCTION(FUNCADDR(AVMCORE_integer_d), I_D, integer_d)
    CSEFUNCTION(FUNCADDR(AvmCore::integer_d_sse2), I_D, integer_d_sse2)
    CSEMETHOD(COREADDR(AVMCORE_integer), I_II, integer)
    CSEMETHOD(COREADDR(AvmCore::number), D_II, number)
    CSEFUNCTION(FUNCADDR(CodegenLIR::coerce_o), I_I, coerce_o)

INTERP_FOPCODE_LIST_END

#undef I_I
#undef I_II
#undef I_III
#undef I_I4
#undef D_I4
#undef I_I5
#undef I_I6
#undef I_I7
#undef I_I8
#undef I_ID
#undef I_D
#undef D_I
#undef D_II
#undef D_III
#undef D_DD
#undef FUNCTION
#undef CSEFUNCTION
#undef METHOD
#undef CSEMETHOD
