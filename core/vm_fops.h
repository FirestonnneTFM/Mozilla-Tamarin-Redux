
#define I_I   (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<2)
#define I_D   (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_F<<2)
#define I_II  (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define D_II  (nanojit::ARGSIZE_F  | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_III (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<6 | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_LO<<2)
#define I_IID (nanojit::ARGSIZE_LO | nanojit::ARGSIZE_LO<<6 | nanojit::ARGSIZE_LO<<4 | nanojit::ARGSIZE_F<<2)
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
    METHOD(DEBUGGERADDR(Debugger::debugFile), I_II, debugFile)
    METHOD(DEBUGGERADDR(Debugger::debugLine), I_II, debugLine)

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
    CSEFUNCTION(COREADDR(AvmCore::doubleToAtom), I_ID, doubleToAtom)
    CSEFUNCTION(COREADDR(AvmCore::doubleToAtom_sse2), I_ID, doubleToAtom_sse2)
    CSEMETHOD(COREADDR(AvmCore::boolean), I_II, boolean)
    CSEMETHOD(COREADDR(AvmCore::toUInt32), I_II, toUInt32)
    CSEFUNCTION(FUNCADDR(AVMCORE_integer_d), I_D, integer_d)
    CSEFUNCTION(FUNCADDR(AvmCore::integer_d_sse2), I_D, integer_d_sse2)
    CSEMETHOD(COREADDR(AVMCORE_integer), I_II, integer)
    CSEMETHOD(COREADDR(AvmCore::number), D_II, number)
    CSEFUNCTION(FUNCADDR(CodegenLIR::coerce_o), I_I, coerce_o)
    METHOD(ENVADDR(MethodEnv::hasnext2), I_III, hasnext2)
    METHOD(COREADDR(AvmCore::sampleCheck), I_I, sampleCheck)
    METHOD(ENVADDR(MethodEnv::nullcheck), I_II, nullcheck)
    CSEMETHOD(TOPLEVELADDR(Toplevel::toVTable), I_II, toVTable)
    METHOD(TOPLEVELADDR(Toplevel::setproperty), I_I5, setproperty)
    METHOD(ENVADDR(MethodEnv::initproperty), I_I5, initproperty)
    METHOD(COREADDR(AvmCore::newPublicNamespace), I_II, newPublicNamespace)
    METHOD(COREADDR(AvmCore::intern), I_II, intern)
    METHOD(COREADDR(AvmCore::istypeAtom), I_III, istypeAtom)
    CSEMETHOD(ENVADDR(MethodEnv::toClassITraits), I_II, toClassITraits)
    METHOD(ENVADDR(MethodEnv::in), I_III, in)
    METHOD(TOPLEVELADDR(Toplevel::instanceof), I_III, instanceof)
    METHOD(COREADDR(AvmCore::stricteq), I_III, stricteq)
    METHOD(COREADDR(AvmCore::eq), I_III, eq)
    CSEMETHOD(COREADDR(AvmCore::concatStrings), I_III, concatStrings)
    METHOD(TOPLEVELADDR(Toplevel::add2), I_III, add2)
    METHOD(ENVADDR(MethodEnv::astype), I_III, astype)
    CSEMETHOD(COREADDR(AvmCore::EscapeAttributeValue), I_II, EscapeAttributeValue)
    CSEMETHOD(COREADDR(AvmCore::ToXMLString), I_II, ToXMLString)
    METHOD(ENVADDR(MethodEnv::delpropertyHelper), I_I4, delpropertyHelper)
    METHOD(ENVADDR(MethodEnv::internRtns), I_II, internRtns)
    METHOD(ENVADDR(MethodEnv::delproperty), I_III, delproperty)
    METHOD(ENVADDR(MethodEnv::setpropertyHelper), I_I6, setpropertyHelper)
    METHOD(ENVADDR(MethodEnv::initpropertyHelper), I_I6, initpropertyHelper)
    METHOD(ENVADDR(MethodEnv::setpropertylate_u), I_I4, setpropertylate_u)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setUintProperty), I_III, DoubleVectorObject::_setUintProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeUintProperty), I_IID, DoubleVectorObject::_setNativeUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setUintProperty), I_III, IntVectorObject::_setUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setUintProperty), I_III, UIntVectorObject::_setUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setNativeUintProperty), I_III, IntVectorObject::_setNativeUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty), I_III, UIntVectorObject::_setNativeUintProperty)
    METHOD(ARRAYADDR(ArrayObject::_setUintProperty), I_III, ArrayObject::_setUintProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_setUintProperty), I_III, ObjectVectorObject::_setUintProperty)
    METHOD(ENVADDR(MethodEnv::setpropertylate_i), I_I4, setpropertylate_i)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setIntProperty), I_III, DoubleVectorObject::_setIntProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeIntProperty), I_IID, DoubleVectorObject::_setNativeIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setIntProperty), I_III, IntVectorObject::_setIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setIntProperty), I_III, UIntVectorObject::_setIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setNativeIntProperty), I_III, IntVectorObject::_setNativeIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty), I_III, UIntVectorObject::_setNativeIntProperty)
    METHOD(ARRAYADDR(ArrayObject::_setIntProperty), I_III, ArrayObject::_setIntProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_setIntProperty), I_III, ObjectVectorObject::_setIntProperty)
    METHOD(TOPLEVELADDR(Toplevel::getproperty), I_I4, getproperty)
    METHOD(ENVADDR(MethodEnv::getpropertyHelper), I_I5, getpropertyHelper)
    METHOD(ENVADDR(MethodEnv::getpropertylate_u), I_III, getpropertylate_u)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getUintProperty), I_II, DoubleVectorObject::_getUintProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeUintProperty), D_II, DoubleVectorObject::_getNativeUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getUintProperty), I_II, IntVectorObject::_getUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getUintProperty), I_II, UIntVectorObject::_getUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getNativeUintProperty), I_II, IntVectorObject::_getNativeUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getNativeUintProperty), I_II, UIntVectorObject::_getNativeUintProperty)
    METHOD(ARRAYADDR(ArrayObject::_getUintProperty), I_II, ArrayObject::_getUintProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_getUintProperty), I_II, ObjectVectorObject::_getUintProperty)
    METHOD(ENVADDR(MethodEnv::getpropertylate_i), I_III, getpropertylate_i)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getIntProperty), I_II, DoubleVectorObject::_getIntProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeIntProperty), D_II, DoubleVectorObject::_getNativeIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getIntProperty), I_II, IntVectorObject::_getIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getIntProperty), I_II, UIntVectorObject::_getIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getNativeIntProperty), I_II, IntVectorObject::_getNativeIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getNativeIntProperty), I_II, UIntVectorObject::_getNativeIntProperty)
    METHOD(ARRAYADDR(ArrayObject::_getIntProperty), I_II, ArrayObject::_getIntProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_getIntProperty), I_II, ObjectVectorObject::_getIntProperty)
    CSEMETHOD(ENVADDR(MethodEnv::finddefNs), I_III, finddefNs)
    CSEMETHOD(ENVADDR(MethodEnv::finddefNsset), I_III, finddefNsset)
    METHOD(ENVADDR(MethodEnv::findproperty), I_I7, findproperty)
    METHOD(ENVADDR(MethodEnv::checkfilter), I_II, checkfilter)
    METHOD(ENVADDR(MethodEnv::getdescendants), I_III, getdescendants)
    METHOD(ENVADDR(MethodEnv::newclass), I_I5, newclass)
    METHOD(SCRIPTADDR(ArrayClass::newarray), I_III, newarray)
    METHOD(ENVADDR(MethodEnv::op_newobject), I_III, op_newobject)
    METHOD(TOPLEVELADDR(Toplevel::op_applytype), I_I4, op_applytype)
    METHOD(TOPLEVELADDR(Toplevel::op_construct), I_I4, op_construct)
    METHOD(ENVADDR(MethodEnv::callsuper), I_I4, callsuper)
    METHOD(TOPLEVELADDR(Toplevel::constructprop), I_I5, constructprop)
    METHOD(ENVADDR(MethodEnv::setsuper), I_I4, setsuper)
    METHOD(ENVADDR(MethodEnv::getsuper), I_III, getsuper)
    METHOD(COREADDR(AvmCore::throwAtom), I_II, throwAtom)
    METHOD(FUNCADDR(MathUtils::mod), D_DD, mod)
    METHOD(COREADDR(AvmCore::_typeof), I_II, _typeof)
    FUNCTION(FUNCADDR(AvmCore::atomWriteBarrier), I_I4, atomWriteBarrier)
    METHOD(GCADDR(GC::writeBarrierRC), I_I4, writeBarrierRC)
    CSEMETHOD(COREADDR(AvmCore::uintToAtom), I_II, uintToAtom)
    CSEMETHOD(COREADDR(AvmCore::intToAtom), I_II, intToAtom)
    METHOD(COREADDR(AvmCore::compare), I_III, compare)
    CSEMETHOD(ENVADDR(MethodEnv::createRestHelper), I_III, createRestHelper)
    CSEMETHOD(ENVADDR(MethodEnv::createArgumentsHelper), I_III, createArgumentsHelper)

INTERP_FOPCODE_LIST_END

#undef I_I
#undef I_II
#undef I_III
#undef I_IID
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
