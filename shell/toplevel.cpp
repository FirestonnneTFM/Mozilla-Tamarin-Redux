/* machine generated file -- do not edit */
// 42 unique thunks

// avmplus_JObject_create
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , const AvmBox*, (argc <= 1 ? NULL : argv + argoffV)        
        , uint32_t, (argc <= 1 ? 0 : argc - 1)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_os_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_4(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , const AvmBox*, (argc <= 1 ? NULL : argv + argoffV)        
        , uint32_t, (argc <= 1 ? 0 : argc - 1)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// flash_utils_ByteArray_readShort
// flash_utils_ByteArray_readInt
// flash_utils_ByteArray_readByte
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}

// avmplus_Domain_currentDomain_get
// avmplus_System_private_getArgv
// flash_trace_Trace_getListener
// flash_sampler_getSamples
// flash_sampler_NewObjectSample_object_get
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// avmplus_File_read
// avmplus_File_exists
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}

// avmplus_File_write
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmString;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oss_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmString;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_utils_ByteArray_readBytes
// flash_utils_ByteArray_writeBytes
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oouu_opti0_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_uint32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , uint32_t, (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))        
        , uint32_t, (argc < 3 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff3]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oouu_opti0_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_uint32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_4(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , uint32_t, (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))        
        , uint32_t, (argc < 3 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff3]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_trace_Trace_setLevel
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_int32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AvmThunkUnbox_int32_t(argv[argoff1])        
        , int32_t, (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_oii_opti2_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_int32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , int32_t, AvmThunkUnbox_int32_t(argv[argoff1])        
        , int32_t, (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// avmplus_JObject_createArray
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_int32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , int32_t, AvmThunkUnbox_int32_t(argv[argoff2])        
        , AvmObject, (argc < 3 ? AvmThunkCoerce_AvmBox_AvmObject(kAvmThunkNull) : AvmThunkUnbox_AvmObject(argv[argoff3]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_ooio_optakAvmThunkNull_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_int32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_4(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , int32_t, AvmThunkUnbox_int32_t(argv[argoff2])        
        , AvmObject, (argc < 3 ? AvmThunkCoerce_AvmBox_AvmObject(kAvmThunkNull) : AvmThunkUnbox_AvmObject(argv[argoff3]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// avmplus_StringBuilder_remove
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ouu_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ouu_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_utils_ByteArray_readFloat
// flash_utils_ByteArray_readDouble
// flash_sampler_getSampleCount
AvmThunkRetType_double AVMTHUNK_CALLTYPE toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const double ret = AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), double    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_double(ret);    
}
AvmThunkRetType_double AVMTHUNK_CALLTYPE toplevel_d2d_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const double ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), double    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_double(ret);    
}

// avmplus_JObject_constructorSignature
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , const AvmBox*, (argc <= 1 ? NULL : argv + argoffV)        
        , uint32_t, (argc <= 1 ? 0 : argc - 1)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_os_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_4(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , const AvmBox*, (argc <= 1 ? NULL : argv + argoffV)        
        , uint32_t, (argc <= 1 ? 0 : argc - 1)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}

// flash_trace_Trace_getLevel
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_oi_opti2_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , int32_t, (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}

// avmplus_StringBuilder_indexOf
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_osu_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , uint32_t, (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_osu_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , uint32_t, (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}

// avmplus_StringBuilder_replace
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ouus_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff2])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff3])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ouus_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_4(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff2])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff3])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_utils_Dictionary_Dictionary
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_ob_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , bool, (argc < 1 ? false : AvmThunkUnbox_bool(argv[argoff1]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_ob_optbfalse_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , bool, (argc < 1 ? false : AvmThunkUnbox_bool(argv[argoff1]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// avmplus_StringBuilder_lastIndexOf
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_osu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , uint32_t, (argc < 2 ? 4294967295U : AvmThunkUnbox_uint32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_osu_optu4294967295U_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
        , uint32_t, (argc < 2 ? 4294967295U : AvmThunkUnbox_uint32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}

// flash_utils_ByteArray_writeDouble
// flash_utils_ByteArray_writeFloat
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_od_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , double, AvmThunkUnbox_double(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_od_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , double, AvmThunkUnbox_double(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_sampler_isGetterSetter
AvmThunkRetType_bool AVMTHUNK_CALLTYPE toplevel_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const bool ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), bool    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_bool(ret);    
}
AvmThunkRetType_bool AVMTHUNK_CALLTYPE toplevel_b2a_oao_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const bool ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), bool    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_bool(ret);    
}

// avmplus_StringBuilder_length_set
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// avmplus_StringBuilder_setCharAt
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ous_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ous_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_utils_ByteArray_toString
// avmplus_StringBuilder_toString
// flash_utils_ByteArray_endian_get
// flash_utils_ByteArray_readUTF
// avmplus_System_getAvmplusVersion
// avmplus_System_readLine
// avmplus_JObject_toString
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}

// flash_utils_ByteArray_readUnsignedByte
// flash_utils_ByteArray_position_get
// avmplus_System_getTimer
// flash_utils_ByteArray_readUnsignedShort
// avmplus_StringBuilder_length_get
// avmplus_StringBuilder_capacity_get
// flash_utils_ByteArray_length_get
// flash_utils_ByteArray_bytesAvailable_get
// flash_utils_ByteArray_readUnsignedInt
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const uint32_t ret = AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), uint32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_uint32_t(ret);    
}
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE toplevel_u2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const uint32_t ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), uint32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_uint32_t(ret);    
}

// avmplus_System_trace
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oo_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_sampler_pauseSampling
// flash_sampler_stopSampling
// flash_utils_ByteArray_uncompress
// avmplus_StringBuilder_reverse
// flash_utils_ByteArray_compress
// flash_sampler_startSampling
// flash_sampler_clearSamples
// avmplus_StringBuilder_trimToSize
// avmplus_System_debugger
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// avmplus_System_isDebugger
// flash_utils_ByteArray_readBoolean
AvmThunkRetType_bool AVMTHUNK_CALLTYPE toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const bool ret = AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), bool    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_bool(ret);    
}
AvmThunkRetType_bool AVMTHUNK_CALLTYPE toplevel_b2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const bool ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), bool    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_bool(ret);    
}

// flash_sampler__getInvocationCount
AvmThunkRetType_double AVMTHUNK_CALLTYPE toplevel_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const double ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), double    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff2])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff3])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_double(ret);    
}
AvmThunkRetType_double AVMTHUNK_CALLTYPE toplevel_d2d_oaou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;    
    const uint32_t argoff3 = argoff2 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const double ret = AVMTHUNK_CALL_FUNCTION_4(AVMTHUNK_GET_HANDLER(env), double    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff2])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff3])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_double(ret);    
}

// avmplus_JObject_fieldSignature
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_oos_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}

// avmplus_JObject_methodSignature
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_4(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
        , const AvmBox*, (argc <= 2 ? NULL : argv + argoffV)        
        , uint32_t, (argc <= 2 ? 0 : argc - 2)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_oos_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_AvmString;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_5(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff2])        
        , const AvmBox*, (argc <= 2 ? NULL : argv + argoffV)        
        , uint32_t, (argc <= 2 ? 0 : argc - 2)        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}

// flash_utils_ByteArray_writeInt
// avmplus_System_exit
// flash_utils_ByteArray_writeShort
// flash_utils_ByteArray_writeByte
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AvmThunkUnbox_int32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oi_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , int32_t, AvmThunkUnbox_int32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// avmplus_StringBuilder_append
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_utils_ByteArray_writeFile
// flash_utils_ByteArray_writeUTFBytes
// flash_utils_ByteArray_endian_set
// flash_utils_ByteArray_writeUTF
// avmplus_System_write
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// avmplus_StringBuilder_substring
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_ouu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , uint32_t, (argc < 2 ? 4294967295U : AvmThunkUnbox_uint32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_ouu_optu4294967295U_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , uint32_t, (argc < 2 ? 4294967295U : AvmThunkUnbox_uint32_t(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}

// flash_utils_ByteArray_readFile
// avmplus_Domain_getClass
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// avmplus_StringBuilder_charCodeAt
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE toplevel_u2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const uint32_t ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), uint32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_uint32_t(ret);    
}
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE toplevel_u2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const uint32_t ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), uint32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_uint32_t(ret);    
}

// flash_utils_ByteArray_writeBoolean
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , bool, AvmThunkUnbox_bool(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ob_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , bool, AvmThunkUnbox_bool(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// avmplus_JObject_toArray
// flash_trace_Trace_setListener
// avmplus_Domain_loadBytes
// avmplus_Domain_Domain
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_oo_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// flash_sampler_getSize
AvmThunkRetType_double AVMTHUNK_CALLTYPE toplevel_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const double ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), double    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_double(ret);    
}
AvmThunkRetType_double AVMTHUNK_CALLTYPE toplevel_d2d_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const double ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), double    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_double(ret);    
}

// flash_sampler_getMemberNames
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
        , bool, (argc < 2 ? false : AvmThunkUnbox_bool(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE toplevel_a2a_oab_optbfalse_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmBox    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])        
        , bool, (argc < 2 ? false : AvmThunkUnbox_bool(argv[argoff2]))        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmBox(ret);    
}

// avmplus_System_exec
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE toplevel_i2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const int32_t ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), int32_t    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_int32_t(ret);    
}

// flash_utils_ByteArray_writeUnsignedInt
// avmplus_StringBuilder_removeCharAt
// flash_utils_ByteArray_position_set
// flash_utils_ByteArray_length_set
// avmplus_StringBuilder_ensureCapacity
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}

// flash_utils_ByteArray_readUTFBytes
// avmplus_StringBuilder_charAt
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE toplevel_s2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    const AvmString ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmString    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_AvmString(ret);    
}

// avmplus_StringBuilder_insert
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oua_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE toplevel_v2a_oua_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;    
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;    
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_uint32_t;    
    (void)argc;    
    AVMTHUNK_DEBUG_ENTER(env)    
    AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), void    
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])        
        , int32_t, AVMTHUNK_GET_COOKIE(env)        
        , uint32_t, AvmThunkUnbox_uint32_t(argv[argoff1])        
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff2])        
    );    
    AVMTHUNK_DEBUG_EXIT(env)    
    return AvmToRetType_void(ret);    
}
const uint8_t toplevel_abc_data[5338] = {
 16,   0,  46,   0,   6,   0,   2,   4,   3,   1,   0,   2,   0,   0, 224, 255, 
255, 255, 239,  65, 171,   1,   6,  83, 121, 115, 116, 101, 109,  13, 116, 111, 
112, 108, 101, 118, 101, 108,  46,  97, 115,  36,  49,   0,   7,  97, 118, 109, 
112, 108, 117, 115,   8, 114, 101,  97, 100,  76, 105, 110, 101,   6,  83, 116, 
114, 105, 110, 103,   8, 103, 101, 116,  84, 105, 109, 101, 114,   4, 117, 105, 
110, 116,   5, 116, 114,  97,  99, 101,   6,  68, 111, 109,  97, 105, 110,  13, 
 99, 117, 114, 114, 101, 110, 116,  68, 111, 109,  97, 105, 110,   8, 103, 101, 
116,  67, 108,  97, 115, 115,   5,  67, 108,  97, 115, 115,   8, 100, 101,  98, 
117, 103, 103, 101, 114,  14,  97, 118, 109, 112, 108, 117, 115,  58,  83, 121, 
115, 116, 101, 109,   4,  97, 114, 103, 118,   7, 103, 101, 116,  65, 114, 103, 
118,   6,  79,  98, 106, 101,  99, 116,   4, 118, 111, 105, 100,   3, 105, 110, 
116,   5,  65, 114, 114,  97, 121,   7,  66, 111, 111, 108, 101,  97, 110,  10, 
105, 115,  68, 101,  98, 117, 103, 103, 101, 114,   4, 101, 120, 101,  99,  17, 
103, 101, 116,  65, 118, 109, 112, 108, 117, 115,  86, 101, 114, 115, 105, 111, 
110,   4, 101, 120, 105, 116,   5, 119, 114, 105, 116, 101,  12,  97, 118, 109, 
112, 108, 117, 115,  58,  70, 105, 108, 101,   9,  66, 121, 116, 101,  65, 114, 
114,  97, 121,  11, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,   8, 
114, 101,  97, 100,  70, 105, 108, 101,   9, 119, 114, 105, 116, 101,  70, 105, 
108, 101,  15, 102, 105, 108, 101,  84, 111,  66, 121, 116, 101,  65, 114, 114, 
 97, 121,  14, 119, 114, 105, 116, 101,  66, 121, 116, 101,  65, 114, 114,  97, 
121,   6, 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100,   4,  70, 105, 
108, 101,  25, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58, 
 67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,   7,  65,  86,  77, 
 80, 108, 117, 115,  12, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 
109,  10, 112, 108,  97, 121, 101, 114,  84, 121, 112, 101,  12,  67,  97, 112, 
 97,  98, 105, 108, 105, 116, 105, 101, 115,   5, 112, 114, 105, 110, 116,  14, 
103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,  97, 109, 101,  14,  97, 
118, 109, 112, 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,  11,  68, 111, 
109,  97, 105, 110,  46,  97, 115,  36,  50,   9, 108, 111,  97, 100,  66, 121, 
116, 101, 115,   4, 108, 111,  97, 100,  21,  97, 118, 109, 112, 108, 117, 115, 
 58,  83, 116, 114, 105, 110, 103,  66, 117, 105, 108, 100, 101, 114,   6,  97, 
112, 112, 101, 110, 100,  18,  83, 116, 114, 105, 110, 103,  66, 117, 105, 108, 
100, 101, 114,  46,  97, 115,  36,  51,   9, 115, 117,  98, 115, 116, 114, 105, 
110, 103,   8,  99,  97, 112,  97,  99, 105, 116, 121,   6, 114, 101, 109, 111, 
118, 101,   6, 108, 101, 110, 103, 116, 104,   7, 105, 110, 100, 101, 120,  79, 
102,   9, 115, 101, 116,  67, 104,  97, 114,  65, 116,  12, 114, 101, 109, 111, 
118, 101,  67, 104,  97, 114,  65, 116,   6,  99, 104,  97, 114,  65, 116,   7, 
114, 101, 118, 101, 114, 115, 101,  11, 108,  97, 115, 116,  73, 110, 100, 101, 
120,  79, 102,   7, 114, 101, 112, 108,  97,  99, 101,  10,  99, 104,  97, 114, 
 67, 111, 100, 101,  65, 116,  14, 101, 110, 115, 117, 114, 101,  67,  97, 112, 
 97,  99, 105, 116, 121,   6, 105, 110, 115, 101, 114, 116,   8, 116, 111,  83, 
116, 114, 105, 110, 103,  10, 116, 114, 105, 109,  84, 111,  83, 105, 122, 101, 
 13,  83, 116, 114, 105, 110, 103,  66, 117, 105, 108, 100, 101, 114,  21, 102, 
108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  66, 121, 116, 101,  65, 
114, 114,  97, 121,   6,  78, 117, 109,  98, 101, 114,  10, 117, 110,  99, 111, 
109, 112, 114, 101, 115, 115,  13, 119, 114, 105, 116, 101,  85,  84,  70,  66, 
121, 116, 101, 115,  15, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 101, 
100,  73, 110, 116,   9, 114, 101,  97, 100,  83, 104, 111, 114, 116,   9, 119, 
114, 105, 116, 101,  66, 121, 116, 101,   8, 119, 114, 105, 116, 101,  85,  84, 
 70,  12, 119, 114, 105, 116, 101,  66, 111, 111, 108, 101,  97, 110,  10, 114, 
101,  97, 100,  68, 111, 117,  98, 108, 101,   8, 119, 114, 105, 116, 101,  73, 
110, 116,  17, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 101, 100,  83, 
104, 111, 114, 116,   8, 112, 111, 115, 105, 116, 105, 111, 110,  10, 119, 114, 
105, 116, 101,  66, 121, 116, 101, 115,  11, 119, 114, 105, 116, 101,  68, 111, 
117,  98, 108, 101,  16, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 101, 
100,  66, 121, 116, 101,  16, 119, 114, 105, 116, 101,  85, 110, 115, 105, 103, 
110, 101, 100,  73, 110, 116,  10, 119, 114, 105, 116, 101,  83, 104, 111, 114, 
116,  14,  98, 121, 116, 101, 115,  65, 118,  97, 105, 108,  97,  98, 108, 101, 
  8,  99, 111, 109, 112, 114, 101, 115, 115,   9, 114, 101,  97, 100,  70, 108, 
111,  97, 116,   6, 101, 110, 100, 105,  97, 110,   7, 114, 101,  97, 100,  85, 
 84,  70,  11, 114, 101,  97, 100,  66, 111, 111, 108, 101,  97, 110,   9, 114, 
101,  97, 100,  66, 121, 116, 101, 115,   7, 114, 101,  97, 100,  73, 110, 116, 
 12, 114, 101,  97, 100,  85,  84,  70,  66, 121, 116, 101, 115,  10, 119, 114, 
105, 116, 101,  70, 108, 111,  97, 116,   8, 114, 101,  97, 100,  66, 121, 116, 
101,  14,  66, 121, 116, 101,  65, 114, 114,  97, 121,  46,  97, 115,  36,  52, 
  5,  81,  78,  97, 109, 101,  19,  95, 103, 101, 116,  73, 110, 118, 111,  99, 
 97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  12,  83,  97, 109, 112, 108, 
101, 114,  46,  97, 115,  36,  53,  13, 102, 108,  97, 115, 104,  46, 115,  97, 
109, 112, 108, 101, 114,  24, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 
108, 101, 114,  58,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,   4, 110, 
 97, 109, 101,   2,  40,  41,   4, 102, 105, 108, 101,   1,  91,   1,  58,   4, 
108, 105, 110, 101,   1,  93,  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 
101,  20, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58, 
 83,  97, 109, 112, 108, 101,   5, 115, 116,  97,  99, 107,   4, 116, 105, 109, 
101,   6,  83,  97, 109, 112, 108, 101,  29, 102, 108,  97, 115, 104,  46, 115, 
 97, 109, 112, 108, 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,  99, 116, 
 83,  97, 109, 112, 108, 101,   4, 116, 121, 112, 101,   2, 105, 100,   6, 111, 
 98, 106, 101,  99, 116,  15,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83, 
 97, 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 
108, 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116, 
 83,  97, 109, 112, 108, 101,   4, 115, 105, 122, 101,  18,  68, 101, 108, 101, 
116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  12, 115, 
116, 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,  24, 103, 101, 116,  71, 
101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 
111, 117, 110, 116,  18, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 
111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  83, 101, 116, 116, 101, 
114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116, 
 14, 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,   7, 
103, 101, 116,  83, 105, 122, 101,  13, 115, 116,  97, 114, 116,  83,  97, 109, 
112, 108, 105, 110, 103,  14, 103, 101, 116,  77, 101, 109,  98, 101, 114,  78, 
 97, 109, 101, 115,  14, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 
116, 101, 114,  10, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  12,  99, 
108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13, 112,  97, 117, 115, 
101,  83,  97, 109, 112, 108, 105, 110, 103,  17, 102, 108,  97, 115, 104,  46, 
116, 114,  97,  99, 101,  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,   7, 
 77,  69,  84,  72,  79,  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95, 
 87,  73,  84,  72,  95,  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,  68, 
 83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,  72, 
 79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,  73, 
 84,  72,  95,  65,  82,  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,  83, 
 84,  69,  78,  69,  82,   8,  70, 117, 110,  99, 116, 105, 111, 110,  11, 103, 
101, 116,  76, 105, 115, 116, 101, 110, 101, 114,   8, 103, 101, 116,  76, 101, 
118, 101, 108,   8, 115, 101, 116,  76, 101, 118, 101, 108,  11, 115, 101, 116, 
 76, 105, 115, 116, 101, 110, 101, 114,  11, 102, 108,  97, 115, 104,  46, 116, 
114,  97,  99, 101,   5,  84, 114,  97,  99, 101,  10,  84, 114,  97,  99, 101, 
 46,  97, 115,  36,  54,  22, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 
115,  58,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  10,  68, 105,  99, 
116, 105, 111, 110,  97, 114, 121,  15,  68, 105,  99, 116, 105, 111, 110,  97, 
114, 121,  46,  97, 115,  36,  55,  18, 102, 108,  97, 115, 104,  46, 117, 116, 
105, 108, 115,  58,  69, 110, 100, 105,  97, 110,  10,  66,  73,  71,  95,  69, 
 78,  68,  73,  65,  78,   9,  98, 105, 103,  69, 110, 100, 105,  97, 110,  13, 
 76,  73,  84,  84,  76,  69,  95,  69,  78,  68,  73,  65,  78,  12, 108, 105, 
116, 116, 108, 101,  69, 110, 100, 105,  97, 110,   6,  69, 110, 100, 105,  97, 
110,  11,  69, 110, 100, 105,  97, 110,  46,  97, 115,  36,  56,  15,  97, 118, 
109, 112, 108, 117, 115,  58,  74,  79,  98, 106, 101,  99, 116,   7,  74,  79, 
 98, 106, 101,  99, 116,   7, 116, 111,  65, 114, 114,  97, 121,  14, 102, 105, 
101, 108, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,  15, 109, 101, 116, 
104, 111, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,   6,  99, 114, 101, 
 97, 116, 101,  11,  99, 114, 101,  97, 116, 101,  65, 114, 114,  97, 121,  20, 
 99, 111, 110, 115, 116, 114, 117,  99, 116, 111, 114,  83, 105, 103, 110,  97, 
116, 117, 114, 101,   9,  74,  97, 118,  97,  46,  97, 115,  36,  57,  57,   5, 
  2,  22,   3,  23,   3,  22,   4,  23,   4,   5,  15,  24,  15,  26,  15,  26, 
 18,   5,  28,  24,  28,  26,  28,  22,  30,   5,  38,  22,  40,  23,  40,  24, 
 38,  26,  38,   5,  45,   5,  46,  24,  45,  26,  45,   5,  49,   5,  51,  24, 
 49,  26,  49,   5,  69,  24,  69,   5,  98,  23,  30,   5, 101,  22, 102,  23, 
102,   5, 103,  24, 103,  26, 103,   5, 112,  24, 112,   5, 116,  24, 116,   5, 
121,  24, 121,   5, 136,   1,  22, 149,   1,  24, 136,   1,   5, 151,   1,  23, 
149,   1,   5, 152,   1,  24, 152,   1,   5, 154,   1,   5, 155,   1,  24, 155, 
  1,   5, 161,   1,   5, 162,   1,  24, 162,   1,   5, 170,   1,  23,   4,   1, 
  2,   3,   4,   4,   1,   2,   4,   5,   8,   1,   2,   4,   5,   6,   7,   8, 
  9,   9,   1,   2,   4,   5,   9,  10,  11,  12,  13,   8,   1,   2,   4,   5, 
  9,  10,  11,  12,   9,   1,   2,   4,   9,  14,  15,  16,  17,  18,   1,   4, 
  1,  15,   5,   1,   2,   4,  15,  16,   9,   2,   4,   5,   9,  13,  19,  20, 
 21,  22,   8,   2,   4,   5,   9,  19,  20,  21,  22,   4,   2,   4,   5,  20, 
  8,   2,   4,   5,   9,  23,  24,  25,  26,   4,   2,   4,   5,  24,   1,  13, 
  4,   2,  13,  29,  30,   4,   2,  31,  32,  33,   8,   2,   9,  31,  32,  33, 
 34,  35,  36,   4,   2,  44,  46,  47,   4,   2,  13,  30,  50,   4,   2,  13, 
 30,  53,   4,   2,   4,   5,  56, 174,   1,   9,   1,   1,   9,   5,   1,   7, 
  2,   6,   9,   7,   1,   7,   2,   8,   9,   9,   1,   9,  10,   1,   9,  11, 
  1,   9,  12,   1,   7,   2,  13,   9,   1,   2,   9,  14,   2,   7,   2,  16, 
  9,  17,   3,   7,   2,  19,   7,   2,  20,   7,   2,  21,   7,   2,  22,   7, 
  2,  14,   7,   2,   9,   7,   2,   5,   7,   2,  23,   7,   2,   7,   7,   2, 
 24,   7,   6,  17,   7,   2,  25,   7,   2,  26,   7,   2,  27,   7,   4,   1, 
  7,   2,  18,   9,  29,   4,   9,  31,   5,   7,  13,  29,   9,  32,   5,   7, 
  2,  33,   7,   2,  34,   7,   2,  35,   7,   2,  36,   7,   4,  37,   9,   1, 
  6,   9,  23,   6,   7,   2,  41,   7,  15,  42,   9,   1,   7,   9,  18,   2, 
  9,  37,   7,   9,  42,   8,   9,  18,   9,   7,   4,  14,   7,   2,  43,   7, 
  2,  44,   7,   4,  10,   9,  29,  10,   9,  31,  11,   9,  47,  11,   7,   2, 
 11,   7,   2,  12,   7,   2,  47,   7,   2,  48,   9,  10,   7,   9,  18,  12, 
  9,  50,  13,   7,   2,  52,   7,   2,  53,   7,   2,  54,   7,   2,  55,   7, 
  2,  56,   7,   2,  57,   7,   2,  58,   7,   2,  59,   7,   2,  60,   7,   2, 
 61,   7,   2,  62,   7,   2,  63,   7,   2,  64,   7,   2,  65,   7,   2,  50, 
  7,   2,  66,   7,   2,  67,   7,   4,  68,   9,  18,  14,   7,   2,  70,   7, 
  2,  31,   7,   2,  71,   7,   2,  72,   7,   2,  73,   7,   2,  74,   7,   2, 
 75,   7,   2,  76,   7,   2,  77,   7,   2,  78,   7,   2,  79,   7,   2,  80, 
  7,   2,  81,   7,   2,  82,   7,   2,  83,   7,   2,  84,   7,   2,  85,   7, 
  2,  86,   7,   2,  87,   7,   2,  88,   7,   2,  89,   7,   2,  90,   7,   2, 
 91,   7,   2,  92,   7,   2,  93,   7,   2,  94,   7,   2,  95,   7,   2,  32, 
  7,   2,  96,   7,   2,  97,   9,  29,  15,   9,  18,  16,   7,   2,  99,   9, 
100,  17,   9, 104,  18,   9, 106,  18,   9, 109,  18,   7,   2, 109,   7,   2, 
104,   7,   2, 106,   7,  32, 111,   7,   2, 113,   7,   2, 114,   7,  32, 115, 
  7,   2, 117,   7,   2, 118,   7,   2, 119,   7,  32, 120,   7,   2, 122,   7, 
 32, 123,   9,  18,  17,   7,  32, 124,   7,  32, 125,   7,  32, 126,   7,  32, 
127,   7,  32, 128,   1,   7,  32, 129,   1,   7,  32, 130,   1,   7,  32, 131, 
  1,   7,  32, 132,   1,   7,  33, 100,   7,  32, 133,   1,   7,  32, 134,   1, 
  7,  32, 135,   1,   7,   2, 137,   1,   7,   2, 138,   1,   7,   2, 139,   1, 
  7,   2, 140,   1,   7,   2, 141,   1,   7,   2, 142,   1,   7,   2, 143,   1, 
  7,   2, 144,   1,   7,   2, 145,   1,   7,   2, 146,   1,   7,   2, 147,   1, 
  7,   2, 148,   1,   7,  44, 150,   1,   9,  18,  19,   7,  13, 153,   1,   9, 
 18,  20,   7,   2, 156,   1,   7,   2, 158,   1,   7,  13, 160,   1,   9,  18, 
 21,   7,   4, 163,   1,   7,   2, 164,   1,   7,   2, 165,   1,   7,   2, 166, 
  1,   7,   2, 167,   1,   7,   2, 168,   1,   7,   2, 169,   1,   9,  18,  22, 
142,   1,   0,   3,   3,   0,   0,   5,   3,   0,   0,   0,   3,   4,   0,   0, 
  3,   4,   1,  10,   3,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   1, 
 15,  16,   3,  32,   1,  16,   3,   3,  32,   0,   3,   3,  32,   1,  15,  17, 
  3,  32,   1,  15,   3,   3,  32,   0,  15,   3,  32,   0,  18,   3,  32,   0, 
  5,   3,  32,   0,  17,   3,  32,   0,   3,   3,  32,   0,   0,   3,   0,   0, 
  0,   3,   0,   1,   3,   3,   3,  32,   1,   3,   3,   3,  32,   2,  15,   3, 
  3,   3,  32,   2,  33,   3,  18,   3,   0,   2,  18,   3,  33,   3,   0,   0, 
  0,   3,   0,   0,   0,   3,   0,   0,   3,   3,   0,   0,  18,   3,   0,   0, 
  0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,  52,   3,  32,   1, 
  0,  52,   3,  32,   1,   0,  33,   3,  32,   1,  10,   3,   3,  32,   1,   0, 
  3,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   1,   0,   3,   3,   8, 
  1,  12,  12,   1,  15,   0,   3,  32,   0,   5,   3,  32,   1,   3,   5,   3, 
 32,   1,   5,   5,   3,  32,   1,  15,   5,   3,  32,   2,  16,   3,   5,   3, 
 40,   1,   1,   3,   2,  15,   5,   0,   3,  32,   2,  16,   3,   5,   3,  40, 
  1,   1,   6,   0,   5,   3,  32,   1,   0,   5,   3,  32,   2,  15,   5,   5, 
  3,  32,   1,  15,   5,   3,  32,   3,  15,   5,   5,   3,   3,  32,   0,  15, 
  3,  32,   2,  15,   5,   3,   3,  32,   2,   3,   5,   5,   3,  40,   1,   1, 
  6,   0,   3,   3,  32,   0,  15,   3,  32,   0,   0,   3,   0,   0,   0,   3, 
  0,   1,  33,   3,   3,  32,   1,  15,   3,   3,  32,   3,  15,  33,   5,   5, 
  3,  40,   2,   1,   3,   1,   3,   3,  15,  33,   5,   5,   3,  40,   2,   1, 
  3,   1,   3,   1,  15,  18,   3,  32,   1,  15,  16,   3,  32,   1,  15,  16, 
  3,  32,   1,  15,  16,   3,  32,   1,  15,   5,   3,  32,   1,  15,  82,   3, 
 32,   1,  15,  82,   3,  32,   1,  15,   3,   3,  32,   1,  15,   3,   3,  32, 
  0,  18,   3,  32,   0,  16,   3,  32,   0,   5,   3,  32,   0,  16,   3,  32, 
  0,   5,   3,  32,   0,  16,   3,  32,   0,   5,   3,  32,   0,  82,   3,  32, 
  0,  82,   3,  32,   0,   3,   3,  32,   1,   3,   5,   3,  32,   0,   5,   3, 
 32,   1,  15,   5,   3,  32,   0,  15,   3,  32,   0,  15,   3,  32,   0,   3, 
  3,  32,   0,   5,   3,  32,   0,   5,   3,  32,   1,  15,   5,   3,  32,   0, 
  3,   3,  32,   1,  15,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0, 
  2,  18,  30, 114,   3,  32,   3,  82,  30, 114,   5,   3,  32,   2,  82,  30, 
114,   3,   0,   2,  82,  30, 114,   3,   0,   2,  82,  30, 114,   3,   0,   0, 
 82,   3,  32,   0,  30,   3,  32,   2,  30,  30,  18,   3,  40,   1,  10,  10, 
  1,  82,   0,   3,  32,   0,  15,   3,  32,   0,  15,   3,  32,   0,  15,   3, 
 32,   0,  15,   3,  32,   0,   0,   3,   0,   0,   3,   3,   0,   0,   0,   3, 
  0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3, 
 32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3, 
  0,   0,   0,   3,   0,   2,   0,  16,  16,   3,  40,   1,   2,   3,   1,  16, 
 16,   3,  40,   1,   2,   3,   1,   0, 153,   1,   3,  32,   0, 153,   1,   3, 
 32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   1,   0,  18, 
  3,  40,   1,  10,  10,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3, 
  0,   0,   0,   3,   0,   0,   0,   3,   0,   1, 166,   1,   3,   3,  36,   3, 
166,   1, 166,   1,  16,  17,   3,  40,   1,  12,  12,   1,  17, 166,   1,   3, 
 32,   1,   3,   3,   3,  36,   2,   3, 166,   1,   3,   3,  36,   2,   3, 166, 
  1,   3,   3,  32,   0,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0, 
  0,  14,  29,  30,   9,   7,   0,  17,   0,  39,  30,   9,  11,   0,  24,   0, 
 43,  30,  11,  17,   0,  28,   0,  52,  30,   9,  21,   0,  32,   3,  57,   1, 
  0,  34,  58,   1,   0,  33,  59,   1,   0,  35,  80,  30,   9,  25,   0,  38, 
 18,  63,   1,   0,  54,  64,   2,   0,  40,  65,   1,   0,  49,  66,   2,   0, 
 47,  67,   1,   0,  44,  68,   1,   0,  53,  66,   3,   0,  48,  69,   1,   0, 
 50,  70,   1,   0,  41,  71,   1,   0,  52,  72,   1,   0,  46,  73,   1,   0, 
 51,  74,   1,   0,  42,  75,   1,   0,  43,  76,   1,   0,  45,  77,   1,   0, 
 39,  78,   1,   0,  55,  79,   1,   0,  56,  33,  30,   9,  28,   0,  93,  33, 
 84,   1,   0,  86,  85,   1,   0,  71,  86,   1,   0,  78,  87,   1,   0,  75, 
 88,   1,   0,  64,  89,   1,   0,  70,  90,   1,   0,  63,  66,   3,   0,  84, 
 91,   1,   0,  80,  92,   1,   0,  66,  93,   1,   0,  76,  94,   3,   0,  90, 
 95,   1,   0,  62,  96,   1,   0,  69,  97,   1,   0,  74,  98,   1,   0,  67, 
 99,   1,   0,  65, 100,   2,   0,  88, 101,   1,   0,  85, 102,   1,   0,  79, 
 94,   2,   0,  89, 103,   2,   0,  91,  78,   1,   0,  87,  66,   2,   0,  83, 
104,   1,   0,  81, 105,   1,   0,  72, 106,   1,   0,  61, 103,   3,   0,  92, 
107,   1,   0,  77, 108,   1,   0,  82, 109,   1,   0,  60, 110,   1,   0,  68, 
111,   1,   0,  73, 122,  30,  11,  35,   0, 110,   4,  78,   1,   0, 109, 119, 
  6,   0,   5,   0, 120,   6,   0,   3,   0, 121,   6,   0,   3,   0, 125,  30, 
  9,  38,   0, 112,   2, 123,   6,   0,  17,   0, 124,   6,   0,  82,   0, 129, 
  1, 125,  11,  40,   0, 115,   3, 126,   6,   0,  10,   0, 127,   6,   0,  82, 
  0, 128,   1,   2,   0, 114, 131,   1, 125,  11,  42,   0, 117,   2, 130,   1, 
  6,   0,  82,   0, 127,   6,   0,  82,   0, 158,   1,  30,   9,  45,   0, 124, 
  0, 160,   1,  30,   8,  49,   0, 127,   0, 164,   1,  30,   9,  52,   0, 130, 
  1,   0, 166,   1,  30,   9,  55,   0, 140,   1,   1,  78,   1,   0, 139,   1, 
  6,  11,  13,   6,   1,  17,   0,  19,  17,   8,  12,  20,  17,   6,  10,  21, 
 17,  12,  16,  22,  17,   9,  13,  23,  17,  10,  14,  24,  17,   4,   8,  25, 
 17,  11,  15,  26,  17,   5,   9,  27,  17,   3,   7,  28,  17,   7,  11,  18, 
  5,  35,  17,   6,  22,  36,  17,   7,  23,  37,  17,   3,  19,  38,  17,   4, 
 20,  28,  17,   5,  21,  25,   2,  42,  18,   3,  26,  22,  18,   4,  27,  30, 
  1,  56,  18,   3,  31,  37,   0,  58,   1,  83,  17,   3,  59, 108,   0, 111, 
  0, 113,   0, 116,   0, 119,  11, 150,   1,   6,   5,  16,   3,   3, 149,   1, 
  6,   4,  16,   4,   3, 154,   1,  17,   6, 123, 155,   1,  17,   4, 121, 146, 
  1,   6,   1,  16,   1,   3, 148,   1,   6,   3,  16,   2,   3, 156,   1,  17, 
  3, 120, 147,   1,   6,   2,  16,   5,   3, 157,   1,  17,   5, 122, 152,   1, 
  6,   7,   0,   2,   3, 151,   1,   6,   6,   0,   5,   3, 126,   0, 129,   1, 
  2, 162,   1,   6,   1,   3, 157,   1,   1, 163,   1,   6,   2,   3, 159,   1, 
  1, 132,   1,   6, 167,   1,  17,   5, 135,   1, 168,   1,  17,   8, 138,   1, 
169,   1,  17,   7, 137,   1, 170,   1,  17,   3, 133,   1, 171,   1,  17,   4, 
134,   1, 172,   1,  17,   6, 136,   1,   9,  36,   1,  52,   4,   0,   3,  57, 
  1,  80,   4,   1,   4,  94,   1,  33,   4,   0,   5, 118,  17, 133,   1,   1, 
  9, 105, 134,   1,   1,  17,  97, 135,   1,   1,  15,  99, 136,   1,   1,  16, 
 98, 131,   1,   4,   4,   9, 137,   1,   1,  14, 100, 129,   1,   4,   3,   8, 
138,   1,   1,  11, 103, 139,   1,   1,   8, 106, 140,   1,   1,  12, 102, 141, 
  1,   1,  19,  95, 142,   1,   1,  18,  96, 125,   4,   2,   7, 143,   1,   1, 
 13, 101, 122,   4,   1,   6, 144,   1,   1,   7, 107, 145,   1,   1,  10, 104, 
125,   1, 158,   1,   4,   1,  10, 128,   1,   1, 160,   1,   4,   1,  11, 131, 
  1,   1, 164,   1,   4,   1,  12, 141,   1,   1, 166,   1,   4,   1,  13,  29, 
  9,  49,   1,   1,   5,  20,   1,   4,   2,  29,   4,   0,   0,  23,   1,   5, 
  1,  39,   4,   0,   1,  21,   1,   6,   0,  50,   1,   3,   3,  43,   4,   0, 
  2,  51,   1,   2,   4,  50,   0,   1,   1,   1,   2,  10, 208,  48,  93,   1, 
102,   1,  70,   2,   0,  72,   0,   0,   1,   1,   1,   1,   2,  10, 208,  48, 
 93,   1, 102,   1,  70,   4,   0,  72,   0,   0,   2,   2,   2,   1,   2,  12, 
208,  48,  93,   1, 102,   1, 209,  70,   6,   1,  41,  71,   0,   0,   3,   2, 
  2,   1,   2,  12, 208,  48,  93,   1, 102,   1, 209,  70,   6,   1,  41,  71, 
  0,   0,   4,   2,   2,   1,   2,  13, 208,  48,  93,   7, 102,   7, 102,   8, 
209,  70,   9,   1,  72,   0,   0,   5,   1,   1,   1,   2,  11, 208,  48,  93, 
 11, 102,  11,  70,  12,   0,  41,  71,   0,   0,   6,   2,   1,   3,   4,  12, 
208,  48,  94,  13,  93,  14,  70,  14,   0, 104,  13,  71,   0,   0,  17,   1, 
  1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  18,   1,   1,   3, 
  4,   3, 208,  48,  71,   0,   0,  22,   2,   3,   3,   4,  11, 208,  48,  93, 
 31, 102,  31, 209,  70,  32,   1,  72,   0,   0,  23,   2,   3,   3,   4,  10, 
208,  48, 210, 209,  70,  34,   1,  41,  38,  72,   0,   0,  24,   1,   1,   4, 
  5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  25,   1,   1,   3,   4,   3, 
208,  48,  71,   0,   0,  26,   1,   1,   3,   4,   5, 208,  48,  44,  39,  72, 
  0,   0,  27,   1,   1,   3,   4,  10, 208,  48,  93,  40, 102,  40,  70,  41, 
  0,  72,   0,   0,  28,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71, 
  0,   0,  29,   2,   1,   1,   3,  51, 208,  48,  93,  44,  93,  30, 102,  30, 
 48,  93,  45, 102,  45,  88,   0,  29, 104,  29,  93,  46,  93,  30, 102,  30, 
 48,  93,  45, 102,  45,  88,   1,  29, 104,  39,  93,  47,  93,  30, 102,  30, 
 48,  93,  48, 102,  48,  88,   2,  29, 104,  43,  71,   0,   0,  30,   1,   1, 
  3,   4,   3, 208,  48,  71,   0,   0,  35,   3,   2,   4,   5,  15, 208,  48, 
208,  93,  53, 102,  53, 209,  70,  54,   1,  70,  55,   1,  72,   0,   0,  36, 
  2,   1,   1,   3,  19, 208,  48,  93,  60,  93,  30, 102,  30,  48,  93,  61, 
102,  61,  88,   3,  29, 104,  52,  71,   0,   0,  37,   1,   1,   3,   4,   3, 
208,  48,  71,   0,   0,  38,   2,   2,   4,   5,  18, 208,  48, 208,  73,   0, 
209,  32,  19,   6,   0,   0, 208, 209,  70,  62,   1,  41,  71,   0,   0,  57, 
  2,   1,   1,   3,  19, 208,  48, 101,   0,  93,  30, 102,  30,  48,  93,  81, 
102,  81,  88,   4,  29, 104,  80,  71,   0,   0,  58,   1,   1,   3,   4,   3, 
208,  48,  71,   0,   0,  93,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0, 
 71,   0,   0,  94,   2,   1,   1,   3,  19, 208,  48,  93, 112,  93,  30, 102, 
 30,  48,  93, 113, 102, 113,  88,   5,  29, 104,  33,  71,   0,   0,  97,   4, 
  3,   1,   2,  12, 208,  48,  93, 115, 209, 210,  36,   1,  70, 115,   3,  72, 
  0,   0,  98,   4,   3,   1,   2,  12, 208,  48,  93, 115, 209, 210,  36,   2, 
 70, 115,   3,  72,   0,   0,  99,   4,   3,   1,   2,  12, 208,  48,  93, 115, 
209, 210,  36,   0,  70, 115,   3,  72,   0,   0, 108,   1,   1,   3,   4,   3, 
208,  48,  71,   0,   0, 109,   3,   1,   4,   5,  42, 208,  48, 208, 102, 116, 
 44, 105, 160, 208, 102, 117, 118,  18,  21,   0,   0,  44, 107, 208, 102, 117, 
160,  44, 108, 160, 208, 102, 118, 160,  44, 110, 160, 130,  16,   3,   0,   0, 
 44,   3, 130, 160,  72,   0,   0, 110,   1,   1,   4,   5,   6, 208,  48, 208, 
 73,   0,  71,   0,   0, 111,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 
112,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 113,   1, 
  1,   4,   5,   3, 208,  48,  71,   0,   0, 115,   1,   1,   5,   6,   6, 208, 
 48, 208,  73,   0,  71,   0,   0, 116,   1,   1,   4,   5,   3, 208,  48,  71, 
  0,   0, 117,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 
118,   2,   1,   1,   4,  83, 208,  48, 101,   0,  93,  30, 102,  30,  48,  93, 
132,   1, 102, 132,   1,  88,   6,  29, 104, 122, 101,   0,  93,  30, 102,  30, 
 48,  93, 132,   1, 102, 132,   1,  88,   7,  29, 104, 125, 101,   0,  93,  30, 
102,  30,  48,  93, 125, 102, 125,  48, 100, 108,   2,  88,   8,  29,  29, 104, 
129,   1, 101,   0,  93,  30, 102,  30,  48,  93, 125, 102, 125,  48, 100, 108, 
  2,  88,   9,  29,  29, 104, 131,   1,  71,   0,   0, 119,   2,   1,   3,   4, 
 59, 208,  48,  94, 146,   1,  36,   0, 104, 146,   1,  94, 147,   1,  36,   1, 
104, 147,   1,  94, 148,   1,  36,   2, 104, 148,   1,  94, 149,   1,  36,   3, 
104, 149,   1,  94, 150,   1,  36,   4, 104, 150,   1,  94, 151,   1,  36,   1, 
104, 151,   1,  94, 152,   1,  36,   2, 104, 152,   1,  71,   0,   0, 124,   1, 
  1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 125,   2,   1,   1, 
  3,  22, 208,  48, 101,   0,  93,  30, 102,  30,  48,  93, 159,   1, 102, 159, 
  1,  88,  10,  29, 104, 158,   1,  71,   0,   0, 126,   1,   1,   3,   4,   3, 
208,  48,  71,   0,   0, 128,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0, 
 93,  30, 102,  30,  48,  93, 161,   1, 102, 161,   1,  88,  11,  29, 104, 160, 
  1,  71,   0,   0, 129,   1,   2,   1,   3,   4,  21, 208,  48,  94, 162,   1, 
 44, 157,   1, 104, 162,   1,  94, 163,   1,  44, 159,   1, 104, 163,   1,  71, 
  0,   0, 130,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0, 
  0, 131,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  30, 102,  30, 
 48,  93, 165,   1, 102, 165,   1,  88,  12,  29, 104, 164,   1,  71,   0,   0, 
132,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 140,   1,   1,   1, 
  4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 141,   1,   2,   1,   1, 
  3,  22, 208,  48, 101,   0,  93,  30, 102,  30,  48,  93, 173,   1, 102, 173, 
  1,  88,  13,  29, 104, 166,   1,  71,   0,   0};
