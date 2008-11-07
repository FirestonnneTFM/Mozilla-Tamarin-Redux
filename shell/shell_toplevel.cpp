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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
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
/* machine generated file -- do not edit */

/* thunks (43 unique) */
// avmplus_JObject_methodSignature
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_sampler_NewObjectSample_size_get
// avmplus_System_freeMemory_get
// avmplus_System_privateMemory_get
// flash_sampler_getSampleCount
// flash_utils_ByteArray_readFloat
// avmplus_System_totalMemory_get
// flash_utils_ByteArray_readDouble
AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_writeBytes
// flash_utils_ByteArray_readBytes
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oouu_opti0_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oouu_opti0_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_readFile
// avmplus_Domain_getClass
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_length_set
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_writeByte
// avmplus_System_exit
// flash_utils_ByteArray_writeInt
// flash_utils_ByteArray_writeShort
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oi_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_System_readLine
// flash_utils_ByteArray_toString
// flash_utils_ByteArray_endian_get
// flash_utils_ByteArray_readUTF
// avmplus_System_getAvmplusVersion
// avmplus_StringBuilder_toString
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_Dictionary_Dictionary
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ob_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBox
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , AvmBoolArg, (argc < 1 ? false : AvmThunkUnbox_AvmBoolArg(argv[argoff1]))
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBox(ret);
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ob_optbfalse_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , int32_t, AVMTHUNK_GET_COOKIE(env)
        , AvmBoolArg, (argc < 1 ? false : AvmThunkUnbox_AvmBoolArg(argv[argoff1]))
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBox(ret);
}
// avmplus_File_write
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oss_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_sampler_isGetterSetter
AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBoolArg ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBoolArg
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBoolArg(ret);
}
AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_oao_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBoolArg ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmBoolArg
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , int32_t, AVMTHUNK_GET_COOKIE(env)
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBoolArg(ret);
}
// flash_trace_Trace_getLevel
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_oi_opti2_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_setCharAt
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ous_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ous_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_readUnsignedShort
// flash_utils_ByteArray_bytesAvailable_get
// flash_utils_ByteArray_length_get
// avmplus_StringBuilder_length_get
// flash_utils_ByteArray_readUnsignedInt
// flash_utils_ByteArray_readUnsignedByte
// avmplus_System_getTimer
// avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get
// avmplus_StringBuilder_capacity_get
// flash_utils_ByteArray_position_get
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_remove
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouu_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouu_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_JObject_createArray
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ooio_optakAvmThunkNull_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_JObject_constructorSignature
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_readInt
// flash_utils_ByteArray_readShort
// flash_utils_ByteArray_readByte
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_insert
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oua_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oua_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_JObject_fieldSignature
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_replace
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouus_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouus_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_System_exec
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_File_read
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_charAt
// flash_utils_ByteArray_readUTFBytes
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_JObject_create
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_readBoolean
// avmplus_System_isDebugger
AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBoolArg ret = AVMTHUNK_CALL_FUNCTION_0(AVMTHUNK_GET_HANDLER(env), AvmBoolArg
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBoolArg(ret);
}
AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBoolArg ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBoolArg
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , int32_t, AVMTHUNK_GET_COOKIE(env)
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBoolArg(ret);
}
// avmplus_File_exists
AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBoolArg ret = AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), AvmBoolArg
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBoolArg(ret);
}
AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBoolArg ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBoolArg
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , int32_t, AVMTHUNK_GET_COOKIE(env)
        , AvmString, AvmThunkUnbox_AvmString(argv[argoff1])
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBoolArg(ret);
}
// flash_sampler_getSamples
// avmplus_Domain_currentDomain_get
// avmplus_System_private_getArgv
// flash_trace_Trace_getListener
// flash_sampler_NewObjectSample_object_get
// avmplus_Domain_domainMemory_get
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_sampler__getInvocationCount
AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oaou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_lastIndexOf
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_optu4294967295U_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_writeFloat
// flash_utils_ByteArray_writeDouble
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_od_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_od_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_substring
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ouu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ouu_optu4294967295U_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_writeBoolean
// flash_sampler_sampleInternalAllocs
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    AVMTHUNK_CALL_FUNCTION_1(AVMTHUNK_GET_HANDLER(env), void
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , AvmBoolArg, AvmThunkUnbox_AvmBoolArg(argv[argoff1])
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_void(ret);
}
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ob_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    (void)argc;
    AVMTHUNK_DEBUG_ENTER(env)
    AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), void
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , int32_t, AVMTHUNK_GET_COOKIE(env)
        , AvmBoolArg, AvmThunkUnbox_AvmBoolArg(argv[argoff1])
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_void(ret);
}
// avmplus_StringBuilder_append
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_sampler_getSize
AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_System_trace
// flash_sampler_setSamplerCallback
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oo_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_indexOf
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_sampler_startSampling
// flash_utils_ByteArray_private_zlib_compress
// flash_sampler_pauseSampling
// flash_sampler_clearSamples
// flash_sampler_stopSampling
// avmplus_System_ns_example_nstest
// avmplus_System_debugger
// avmplus_StringBuilder_trimToSize
// flash_utils_ByteArray_private_zlib_uncompress
// avmplus_StringBuilder_reverse
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_trace_Trace_setLevel
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oii_opti2_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// avmplus_StringBuilder_ensureCapacity
// flash_utils_ByteArray_position_set
// avmplus_StringBuilder_removeCharAt
// flash_utils_ByteArray_writeUnsignedInt
// flash_utils_ByteArray_length_set
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_utils_ByteArray_writeUTF
// flash_utils_ByteArray_endian_set
// flash_utils_ByteArray_writeFile
// avmplus_System_write
// flash_utils_ByteArray_writeUTFBytes
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
// flash_sampler_getMemberNames
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_2(AVMTHUNK_GET_HANDLER(env), AvmBox
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])
        , AvmBoolArg, (argc < 2 ? false : AvmThunkUnbox_AvmBoolArg(argv[argoff2]))
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBox(ret);
}
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oab_optbfalse_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
{
    const uint32_t argoff0 = 0;
    const uint32_t argoff1 = argoff0 + AvmThunkArgSize_AvmObject;
    const uint32_t argoff2 = argoff1 + AvmThunkArgSize_AvmBox;
    AVMTHUNK_DEBUG_ENTER(env)
    const AvmBox ret = AVMTHUNK_CALL_FUNCTION_3(AVMTHUNK_GET_HANDLER(env), AvmBox
        , AvmObject, AvmThunkUnbox_AvmObject(argv[argoff0])
        , int32_t, AVMTHUNK_GET_COOKIE(env)
        , AvmBox, AvmThunkUnbox_AvmBox(argv[argoff1])
        , AvmBoolArg, (argc < 2 ? false : AvmThunkUnbox_AvmBoolArg(argv[argoff2]))
    );
    AVMTHUNK_DEBUG_EXIT(env)
    return AvmToRetType_AvmBox(ret);
}
// avmplus_JObject_toArray
// avmplus_Domain_loadBytes
// avmplus_Domain_domainMemory_set
// avmplus_Domain_Domain
// flash_trace_Trace_setListener
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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
AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oo_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv)
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

/* methods */

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(SystemClass)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_debugger, SystemClass::debugger)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_privateMemory_get, SystemClass::get_privateMemory)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_trace, SystemClass::trace)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_readLine, SystemClass::readLine)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_isDebugger, SystemClass::isDebugger)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_totalMemory_get, SystemClass::get_totalMemory)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_freeMemory_get, SystemClass::get_freeMemory)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_getTimer, SystemClass::getTimer)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_exec, SystemClass::exec)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_private_getArgv, SystemClass::getArgv)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_ns_example_nstest, SystemClass::ns_example_nstest)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_getAvmplusVersion, SystemClass::getAvmplusVersion)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_exit, SystemClass::exit)
    AVMTHUNK_NATIVE_METHOD(avmplus_System_write, SystemClass::write)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(FileClass)
    AVMTHUNK_NATIVE_METHOD(avmplus_File_exists, FileClass::exists)
    AVMTHUNK_NATIVE_METHOD(avmplus_File_read, FileClass::read)
    AVMTHUNK_NATIVE_METHOD(avmplus_File_write, FileClass::write)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(DomainClass)
    AVMTHUNK_NATIVE_METHOD(avmplus_Domain_currentDomain_get, DomainClass::get_currentDomain)
    AVMTHUNK_NATIVE_METHOD(avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get, DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH)
    AVMTHUNK_NATIVE_METHOD(avmplus_Domain_Domain, DomainObject::constructDomainObject)
    AVMTHUNK_NATIVE_METHOD(avmplus_Domain_getClass, DomainObject::getClass)
    AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_get, DomainObject::get_domainMemory)
    AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_set, DomainObject::set_domainMemory)
    AVMTHUNK_NATIVE_METHOD(avmplus_Domain_loadBytes, DomainObject::loadBytes)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(StringBuilderClass)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_substring, StringBuilderObject::substring)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_capacity_get, StringBuilderObject::get_capacity)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_remove, StringBuilderObject::remove)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_length_get, StringBuilderObject::get_length)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_indexOf, StringBuilderObject::indexOf)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_setCharAt, StringBuilderObject::setCharAt)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_length_set, StringBuilderObject::set_length)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_removeCharAt, StringBuilderObject::removeCharAt)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_charAt, StringBuilderObject::charAt)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_reverse, StringBuilderObject::reverse)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_lastIndexOf, StringBuilderObject::lastIndexOf)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_replace, StringBuilderObject::replace)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_charCodeAt, StringBuilderObject::charCodeAt)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_ensureCapacity, StringBuilderObject::ensureCapacity)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_insert, StringBuilderObject::insert)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_append, StringBuilderObject::append)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_toString, StringBuilderObject::toString)
    AVMTHUNK_NATIVE_METHOD(avmplus_StringBuilder_trimToSize, StringBuilderObject::trimToSize)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(ByteArrayClass)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readFile, ByteArrayClass::readFile)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeUTFBytes, ByteArrayObject::writeUTFBytes)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUnsignedInt, ByteArrayObject::readUnsignedInt)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readShort, ByteArrayObject::readShort)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeByte, ByteArrayObject::writeByte)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeUTF, ByteArrayObject::writeUTF)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeBoolean, ByteArrayObject::writeBoolean)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_length_set, ByteArrayObject::set_length)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readDouble, ByteArrayObject::readDouble)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeInt, ByteArrayObject::writeInt)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUnsignedShort, ByteArrayObject::readUnsignedShort)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_position_set, ByteArrayObject::set_position)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeBytes, ByteArrayObject::writeBytes)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_private_zlib_compress, ByteArrayObject::zlib_compress)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeDouble, ByteArrayObject::writeDouble)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUnsignedByte, ByteArrayObject::readUnsignedByte)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeUnsignedInt, ByteArrayObject::writeUnsignedInt)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeShort, ByteArrayObject::writeShort)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_bytesAvailable_get, ByteArrayObject::get_bytesAvailable)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readFloat, ByteArrayObject::readFloat)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_position_get, ByteArrayObject::get_position)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_endian_get, ByteArrayObject::get_endian)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_toString, ByteArrayObject::toString)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_length_get, ByteArrayObject::get_length)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_private_zlib_uncompress, ByteArrayObject::zlib_uncompress)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUTF, ByteArrayObject::readUTF)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readBoolean, ByteArrayObject::readBoolean)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readBytes, ByteArrayObject::readBytes)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_endian_set, ByteArrayObject::set_endian)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readInt, ByteArrayObject::readInt)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUTFBytes, ByteArrayObject::readUTFBytes)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeFile, ByteArrayObject::writeFile)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeFloat, ByteArrayObject::writeFloat)
    AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readByte, ByteArrayObject::readByte)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(SampleClass)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(NewObjectSampleClass)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_size_get, NewObjectSampleObject::get_size)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_object_get, NewObjectSampleObject::get_object)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(DeleteObjectSampleClass)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(TraceClass)
    AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getListener, TraceClass::getListener)
    AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getLevel, TraceClass::getLevel)
    AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setLevel, TraceClass::setLevel)
    AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setListener, TraceClass::setListener)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(DictionaryClass)
    AVMTHUNK_NATIVE_METHOD(flash_utils_Dictionary_Dictionary, DictionaryObject::constructDictionaryObject)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_CLASS_NATIVE_METHOD_MAP(JObjectClass)
    AVMTHUNK_NATIVE_METHOD(avmplus_JObject_toArray, JObjectClass::toArray)
    AVMTHUNK_NATIVE_METHOD(avmplus_JObject_fieldSignature, JObjectClass::fieldSignature)
    AVMTHUNK_NATIVE_METHOD(avmplus_JObject_methodSignature, JObjectClass::methodSignature)
    AVMTHUNK_NATIVE_METHOD(avmplus_JObject_create, JObjectClass::create)
    AVMTHUNK_NATIVE_METHOD(avmplus_JObject_createArray, JObjectClass::createArray)
    AVMTHUNK_NATIVE_METHOD(avmplus_JObject_constructorSignature, JObjectClass::constructorSignature)
AVMTHUNK_END_NATIVE_METHOD_MAP()

AVMTHUNK_BEGIN_SCRIPT_NATIVE_METHOD_MAP(SamplerScript)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_stopSampling, SamplerScript::stopSampling)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_sampleInternalAllocs, SamplerScript::sampleInternalAllocs)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_getSampleCount, SamplerScript::getSampleCount)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_startSampling, SamplerScript::startSampling)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_getSize, SamplerScript::getSize)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_getMemberNames, SamplerScript::getMemberNames)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_setSamplerCallback, SamplerScript::setSamplerCallback)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_isGetterSetter, SamplerScript::isGetterSetter)
    AVMTHUNK_NATIVE_METHOD(flash_sampler__getInvocationCount, SamplerScript::_getInvocationCount)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_getSamples, SamplerScript::getSamples)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_clearSamples, SamplerScript::clearSamples)
    AVMTHUNK_NATIVE_METHOD(flash_sampler_pauseSampling, SamplerScript::pauseSampling)
AVMTHUNK_END_NATIVE_METHOD_MAP()

/* scripts */
AVMTHUNK_BEGIN_NATIVE_SCRIPTS(shell_toplevel)
    AVMTHUNK_NATIVE_SCRIPT(3, SamplerScript)
AVMTHUNK_END_NATIVE_SCRIPTS()

/* classes */
AVMTHUNK_BEGIN_NATIVE_CLASSES(shell_toplevel)
    AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_System, SystemClass, ScriptObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_File, FileClass, ScriptObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, DomainObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_StringBuilder, StringBuilderClass, StringBuilderObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_ByteArray, ByteArrayClass, ByteArrayObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, SampleObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, NewObjectSampleObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, DeleteObjectSampleObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, ScriptObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Dictionary, DictionaryClass, DictionaryObject)
    AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, JObject)
AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel, shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[6524] = {
 16,   0,  46,   0,   6,   0,   2,   4,   3,   1,   0,   2,   0,   0, 224, 255, 
255, 255, 239,  65, 217,   1,   6,  83, 121, 115, 116, 101, 109,  19, 115, 104, 
101, 108, 108,  95, 116, 111, 112, 108, 101, 118, 101, 108,  46,  97, 115,  36, 
 49,   0,   7,  97, 118, 109, 112, 108, 117, 115,   8, 114, 101,  97, 100,  76, 
105, 110, 101,   6,  83, 116, 114, 105, 110, 103,   8, 103, 101, 116,  84, 105, 
109, 101, 114,   4, 117, 105, 110, 116,   5, 116, 114,  97,  99, 101,   6,  68, 
111, 109,  97, 105, 110,  13,  99, 117, 114, 114, 101, 110, 116,  68, 111, 109, 
 97, 105, 110,   8, 103, 101, 116,  67, 108,  97, 115, 115,   5,  67, 108,  97, 
115, 115,   8, 100, 101,  98, 117, 103, 103, 101, 114,  13,  97, 118, 109, 112, 
108, 117, 115,  58,  73,  84, 101, 115, 116,   4, 116, 101, 115, 116,   5,  73, 
 84, 101, 115, 116,  13,  97, 118, 109, 112, 108, 117, 115,  58,  67,  84, 101, 
115, 116,   5,  67,  84, 101, 115, 116,   6,  79,  98, 106, 101,  99, 116,  14, 
 97, 118, 109, 112, 108, 117, 115,  58,  83, 121, 115, 116, 101, 109,   4,  97, 
114, 103, 118,   7, 103, 101, 116,  65, 114, 103, 118,   4, 118, 111, 105, 100, 
  3, 105, 110, 116,   5,  65, 114, 114,  97, 121,   7,  66, 111, 111, 108, 101, 
 97, 110,   6,  78, 117, 109,  98, 101, 114,  13, 112, 114, 105, 118,  97, 116, 
101,  77, 101, 109, 111, 114, 121,  10, 105, 115,  68, 101,  98, 117, 103, 103, 
101, 114,  11, 116, 111, 116,  97, 108,  77, 101, 109, 111, 114, 121,  10, 102, 
114, 101, 101,  77, 101, 109, 111, 114, 121,   4, 101, 120, 101,  99,   3,  98, 
 97, 114,   4,  97, 116, 116, 114,   8, 119, 104,  97, 116, 101, 118, 101, 114, 
 22, 104, 116, 116, 112,  58,  47,  47, 119, 119, 119,  46, 101, 120,  97, 109, 
112, 108, 101,  46,  99, 111, 109,   6, 110, 115, 116, 101, 115, 116,  17, 103, 
101, 116,  65, 118, 109, 112, 108, 117, 115,  86, 101, 114, 115, 105, 111, 110, 
  4, 101, 120, 105, 116,   3, 102, 111, 111,   5, 119, 114, 105, 116, 101,  12, 
 97, 118, 109, 112, 108, 117, 115,  58,  70, 105, 108, 101,   9,  66, 121, 116, 
101,  65, 114, 114,  97, 121,  11, 102, 108,  97, 115, 104,  46, 117, 116, 105, 
108, 115,   8, 114, 101,  97, 100,  70, 105, 108, 101,   9, 119, 114, 105, 116, 
101,  70, 105, 108, 101,  15, 102, 105, 108, 101,  84, 111,  66, 121, 116, 101, 
 65, 114, 114,  97, 121,  14, 119, 114, 105, 116, 101,  66, 121, 116, 101,  65, 
114, 114,  97, 121,   6, 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100, 
  4,  70, 105, 108, 101,  25, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 
101, 109,  58,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,   7, 
 65,  86,  77,  80, 108, 117, 115,  12, 102, 108,  97, 115, 104,  46, 115, 121, 
115, 116, 101, 109,  10, 112, 108,  97, 121, 101, 114,  84, 121, 112, 101,  12, 
 67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,   6, 110,  97, 116, 
105, 118, 101,   3,  99, 108, 115,  11,  83, 121, 115, 116, 101, 109,  67, 108, 
 97, 115, 115,   7, 109, 101, 116, 104, 111, 100, 115,   4,  97, 117, 116, 111, 
  9,  70, 105, 108, 101,  67, 108,  97, 115, 115,   5, 112, 114, 105, 110, 116, 
 14, 103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,  97, 109, 101,  10, 
110, 115,  95, 101, 120,  97, 109, 112, 108, 101,  14,  97, 118, 109, 112, 108, 
117, 115,  58,  68, 111, 109,  97, 105, 110,  11,  68, 111, 109,  97, 105, 110, 
 46,  97, 115,  36,  50,   9, 108, 111,  97, 100,  66, 121, 116, 101, 115,  24, 
 77,  73,  78,  95,  68,  79,  77,  65,  73,  78,  95,  77,  69,  77,  79,  82, 
 89,  95,  76,  69,  78,  71,  84,  72,  12, 100, 111, 109,  97, 105, 110,  77, 
101, 109, 111, 114, 121,   4, 108, 111,  97, 100,  11,  68, 111, 109,  97, 105, 
110,  67, 108,  97, 115, 115,   8, 105, 110, 115, 116,  97, 110,  99, 101,  12, 
 68, 111, 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,  21,  97, 118, 109, 
112, 108, 117, 115,  58,  83, 116, 114, 105, 110, 103,  66, 117, 105, 108, 100, 
101, 114,   6,  97, 112, 112, 101, 110, 100,  18,  83, 116, 114, 105, 110, 103, 
 66, 117, 105, 108, 100, 101, 114,  46,  97, 115,  36,  51,   9, 115, 117,  98, 
115, 116, 114, 105, 110, 103,   8,  99,  97, 112,  97,  99, 105, 116, 121,   6, 
114, 101, 109, 111, 118, 101,   6, 108, 101, 110, 103, 116, 104,   7, 105, 110, 
100, 101, 120,  79, 102,   9, 115, 101, 116,  67, 104,  97, 114,  65, 116,  12, 
114, 101, 109, 111, 118, 101,  67, 104,  97, 114,  65, 116,   6,  99, 104,  97, 
114,  65, 116,   7, 114, 101, 118, 101, 114, 115, 101,  11, 108,  97, 115, 116, 
 73, 110, 100, 101, 120,  79, 102,   7, 114, 101, 112, 108,  97,  99, 101,  10, 
 99, 104,  97, 114,  67, 111, 100, 101,  65, 116,  14, 101, 110, 115, 117, 114, 
101,  67,  97, 112,  97,  99, 105, 116, 121,   6, 105, 110, 115, 101, 114, 116, 
  8, 116, 111,  83, 116, 114, 105, 110, 103,  10, 116, 114, 105, 109,  84, 111, 
 83, 105, 122, 101,  13,  83, 116, 114, 105, 110, 103,  66, 117, 105, 108, 100, 
101, 114,  18,  83, 116, 114, 105, 110, 103,  66, 117, 105, 108, 100, 101, 114, 
 67, 108,  97, 115, 115,  19,  83, 116, 114, 105, 110, 103,  66, 117, 105, 108, 
100, 101, 114,  79,  98, 106, 101,  99, 116,  21, 102, 108,  97, 115, 104,  46, 
117, 116, 105, 108, 115,  58,  66, 121, 116, 101,  65, 114, 114,  97, 121,  13, 
122, 108, 105,  98,  95,  99, 111, 109, 112, 114, 101, 115, 115,  14,  66, 121, 
116, 101,  65, 114, 114,  97, 121,  46,  97, 115,  36,  52,  15, 122, 108, 105, 
 98,  95, 117, 110,  99, 111, 109, 112, 114, 101, 115, 115,  10, 117, 110,  99, 
111, 109, 112, 114, 101, 115, 115,  13, 119, 114, 105, 116, 101,  85,  84,  70, 
 66, 121, 116, 101, 115,  15, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 
101, 100,  73, 110, 116,   9, 114, 101,  97, 100,  83, 104, 111, 114, 116,   9, 
119, 114, 105, 116, 101,  66, 121, 116, 101,   8, 119, 114, 105, 116, 101,  85, 
 84,  70,  12, 119, 114, 105, 116, 101,  66, 111, 111, 108, 101,  97, 110,  10, 
114, 101,  97, 100,  68, 111, 117,  98, 108, 101,   8, 119, 114, 105, 116, 101, 
 73, 110, 116,  17, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 101, 100, 
 83, 104, 111, 114, 116,   8, 112, 111, 115, 105, 116, 105, 111, 110,  10, 119, 
114, 105, 116, 101,  66, 121, 116, 101, 115,  11, 119, 114, 105, 116, 101,  68, 
111, 117,  98, 108, 101,  16, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 
101, 100,  66, 121, 116, 101,  16, 119, 114, 105, 116, 101,  85, 110, 115, 105, 
103, 110, 101, 100,  73, 110, 116,  10, 119, 114, 105, 116, 101,  83, 104, 111, 
114, 116,  14,  98, 121, 116, 101, 115,  65, 118,  97, 105, 108,  97,  98, 108, 
101,   8,  99, 111, 109, 112, 114, 101, 115, 115,   9, 114, 101,  97, 100,  70, 
108, 111,  97, 116,   6, 101, 110, 100, 105,  97, 110,   7, 114, 101,  97, 100, 
 85,  84,  70,  11, 114, 101,  97, 100,  66, 111, 111, 108, 101,  97, 110,   9, 
114, 101,  97, 100,  66, 121, 116, 101, 115,   7, 114, 101,  97, 100,  73, 110, 
116,  12, 114, 101,  97, 100,  85,  84,  70,  66, 121, 116, 101, 115,  10, 119, 
114, 105, 116, 101,  70, 108, 111,  97, 116,   8, 114, 101,  97, 100,  66, 121, 
116, 101,  14,  66, 121, 116, 101,  65, 114, 114,  97, 121,  67, 108,  97, 115, 
115,  15,  66, 121, 116, 101,  65, 114, 114,  97, 121,  79,  98, 106, 101,  99, 
116,   5,  81,  78,  97, 109, 101,  19,  95, 103, 101, 116,  73, 110, 118, 111, 
 99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  12,  83,  97, 109, 112, 
108, 101, 114,  46,  97, 115,  36,  53,  13, 102, 108,  97, 115, 104,  46, 115, 
 97, 109, 112, 108, 101, 114,   8,  70, 117, 110,  99, 116, 105, 111, 110,  24, 
102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83, 116, 
 97,  99, 107,  70, 114,  97, 109, 101,   4, 110,  97, 109, 101,   2,  40,  41, 
  4, 102, 105, 108, 101,   1,  91,   1,  58,   4, 108, 105, 110, 101,   1,  93, 
 10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  20, 102, 108,  97, 115, 
104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,  97, 109, 112, 108, 101, 
  5, 115, 116,  97,  99, 107,   4, 116, 105, 109, 101,   6,  83,  97, 109, 112, 
108, 101,  29, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114, 
 58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101, 
  4, 115, 105, 122, 101,   4, 116, 121, 112, 101,   2, 105, 100,   6, 111,  98, 
106, 101,  99, 116,  15,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 
109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 
101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83, 
 97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101, 
 99, 116,  83,  97, 109, 112, 108, 101,  12, 115, 116, 111, 112,  83,  97, 109, 
112, 108, 105, 110, 103,  24, 103, 101, 116,  71, 101, 116, 116, 101, 114,  73, 
110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  18, 103, 
101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 
116,  24, 103, 101, 116,  83, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99, 
 97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  23,  68, 101, 108, 101, 116, 
101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 
115, 115,  24,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83, 
 97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  20, 115,  97, 109, 112, 
108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99, 115, 
 14, 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  13, 
115, 116,  97, 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,   7, 103, 101, 
116,  83, 105, 122, 101,  20,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83, 
 97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  21,  78, 101, 119,  79,  98, 
106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116, 
 14, 103, 101, 116,  77, 101, 109,  98, 101, 114,  78,  97, 109, 101, 115,  18, 
115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97, 
 99, 107,  14, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 
114,   6, 115,  99, 114, 105, 112, 116,  13,  83,  97, 109, 112, 108, 101, 114, 
 83,  99, 114, 105, 112, 116,  11,  83,  97, 109, 112, 108, 101,  67, 108,  97, 
115, 115,  12,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  10, 
103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  12,  99, 108, 101,  97, 114, 
 83,  97, 109, 112, 108, 101, 115,  13, 112,  97, 117, 115, 101,  83,  97, 109, 
112, 108, 105, 110, 103,  17, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 
101,  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,  77,  69,  84,  72, 
 79,  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  87,  73,  84,  72, 
 95,  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  65,  78, 
 68,  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,  79,  68,  83,  95, 
 65,  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,  84,  72,  95,  65, 
 82,  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,  84,  69,  78,  69, 
 82,  11, 103, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,   8, 103, 101, 
116,  76, 101, 118, 101, 108,   8, 115, 101, 116,  76, 101, 118, 101, 108,  11, 
115, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 102, 108,  97, 115, 
104,  46, 116, 114,  97,  99, 101,   5,  84, 114,  97,  99, 101,  10,  84, 114, 
 97,  99, 101,  46,  97, 115,  36,  54,  10,  84, 114,  97,  99, 101,  67, 108, 
 97, 115, 115,  22, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58, 
 68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  10,  68, 105,  99, 116, 105, 
111, 110,  97, 114, 121,  15,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121, 
 46,  97, 115,  36,  55,  15,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121, 
 67, 108,  97, 115, 115,  16,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121, 
 79,  98, 106, 101,  99, 116,  18, 102, 108,  97, 115, 104,  46, 117, 116, 105, 
108, 115,  58,  69, 110, 100, 105,  97, 110,  10,  66,  73,  71,  95,  69,  78, 
 68,  73,  65,  78,   9,  98, 105, 103,  69, 110, 100, 105,  97, 110,  13,  76, 
 73,  84,  84,  76,  69,  95,  69,  78,  68,  73,  65,  78,  12, 108, 105, 116, 
116, 108, 101,  69, 110, 100, 105,  97, 110,   6,  69, 110, 100, 105,  97, 110, 
 11,  69, 110, 100, 105,  97, 110,  46,  97, 115,  36,  56,  15,  97, 118, 109, 
112, 108, 117, 115,  58,  74,  79,  98, 106, 101,  99, 116,   7,  74,  79,  98, 
106, 101,  99, 116,   7, 116, 111,  65, 114, 114,  97, 121,  14, 102, 105, 101, 
108, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,  15, 109, 101, 116, 104, 
111, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,   6,  99, 114, 101,  97, 
116, 101,  11,  99, 114, 101,  97, 116, 101,  65, 114, 114,  97, 121,  20,  99, 
111, 110, 115, 116, 114, 117,  99, 116, 111, 114,  83, 105, 103, 110,  97, 116, 
117, 114, 101,   9,  74,  97, 118,  97,  46,  97, 115,  36,  57,  12,  74,  79, 
 98, 106, 101,  99, 116,  67, 108,  97, 115, 115,  62,   5,   2,  22,   3,  23, 
  3,  22,   4,  23,   4,   8,  15,   5,  18,  24,  18,   5,  21,  24,  21,  26, 
 21,  26,  20,   8,  37,   5,  43,  24,  43,  26,  43,  22,  45,   5,  53,  22, 
 55,  23,  55,  24,  53,  26,  53,   5,  67,   5,  68,  24,  67,  26,  67,   5, 
 76,   5,  78,  24,  76,  26,  76,   5,  98,   5, 100,  23,  45,  24,  98,  26, 
 98,   5, 133,   1,  22, 134,   1,  23, 134,   1,   5, 136,   1,  24, 136,   1, 
 26, 136,   1,   5, 145,   1,  24, 145,   1,   5, 149,   1,  24, 149,   1,   5, 
155,   1,  24, 155,   1,   5, 179,   1,  22, 191,   1,  24, 179,   1,   5, 193, 
  1,  23, 191,   1,   5, 195,   1,  24, 195,   1,   5, 197,   1,   5, 200,   1, 
 24, 200,   1,   5, 206,   1,   5, 207,   1,  24, 207,   1,   5, 215,   1,  25, 
  4,   1,   2,   3,   4,   4,   1,   2,   4,   5,   8,   1,   2,   4,   5,   9, 
 10,  11,  12,   9,   1,   2,   4,   5,  12,  14,  15,  16,  17,   8,   1,   2, 
  4,   5,  12,  14,  15,  16,   9,   1,   2,   4,  12,  18,  19,  20,  21,  22, 
  1,   5,   1,   4,   1,  19,   5,   1,   2,   4,  19,  20,   9,   2,   4,   5, 
 12,  17,  23,  24,  25,  26,   8,   2,   4,   5,  12,  23,  24,  25,  26,   4, 
  2,   4,   5,  24,   8,   2,   4,   5,  12,  27,  28,  29,  30,   4,   2,   4, 
  5,  28,   8,   2,  12,  17,  31,  32,  33,  34,  35,   1,  17,   4,   2,  17, 
 32,  33,   4,   2,  36,  37,  38,   8,   2,  12,  36,  37,  38,  39,  40,  41, 
  4,   2,  49,  51,  52,   4,   2,  17,  33,  55,   4,   2,  17,  33,  58,   4, 
  2,   4,   5,  61, 193,   1,   9,   1,   1,   9,   5,   1,   7,   2,   6,   9, 
  7,   1,   7,   2,   8,   9,   9,   1,   9,  10,   1,   9,  11,   1,   9,  12, 
  1,   7,   2,  13,   9,   1,   2,   9,  14,   2,   7,   6,  16,   7,   5,  17, 
  7,   2,  16,   7,   5,  19,   7,   2,  20,   7,   2,  22,   9,  23,   3,   7, 
  2,  24,   7,   2,  25,   7,   2,  26,   7,   2,  27,   7,   2,  28,   7,   2, 
 14,   7,   2,  29,   7,   2,   9,   7,   2,   5,   7,   2,  30,   7,   2,  31, 
  7,   2,  32,   7,   2,   7,   7,   2,  33,   7,   9,  23,   7,  13,  38,   7, 
  2,  39,   7,   2,  40,   7,   2,  42,   7,   4,   1,   9,  44,   4,   9,  46, 
  5,   7,  17,  44,   9,  47,   5,   7,   2,  48,   7,   2,  49,   7,   2,  50, 
  7,   2,  51,   7,   4,  52,   9,   1,   6,   9,  30,   6,   7,   2,  56,   7, 
 19,  57,   9,  17,   7,   9,  19,   7,   9,  20,   2,   9,   1,   8,   9,  52, 
  8,   9,  57,   9,   9,  20,  10,   7,   4,  14,   7,   2,  64,   7,   2,  65, 
  7,   5,  66,   7,   4,  10,   9,  44,  11,   9,  46,  12,   9,  69,  12,   7, 
  2,  11,   7,   2,  70,   7,   2,  12,   7,   2,  71,   7,   2,  72,   7,   2, 
 69,   9,  10,   8,   9,  20,  13,   9,  77,  14,   7,   2,  79,   7,   2,  80, 
  7,   2,  81,   7,   2,  82,   7,   2,  83,   7,   2,  84,   7,   2,  85,   7, 
  2,  86,   7,   2,  87,   7,   2,  88,   7,   2,  89,   7,   2,  90,   7,   2, 
 91,   7,   2,  92,   7,   2,  77,   7,   2,  93,   7,   2,  94,   7,   4,  95, 
  9,  20,  15,   9,  99,  16,   9, 101,  16,   7,   2,  46,   7,   2, 102,   7, 
  2, 103,   7,   2, 104,   7,   2, 105,   7,   2, 106,   7,   2, 107,   7,   2, 
108,   7,   2, 109,   7,   2, 110,   7,   2, 111,   7,   2, 112,   7,   2, 113, 
  7,  31,  99,   7,   2, 114,   7,   2, 115,   7,   2, 116,   7,   2, 117,   7, 
  2, 118,   7,   2, 119,   7,   2, 120,   7,   2, 121,   7,  31, 101,   7,   2, 
122,   7,   2, 123,   7,   2, 124,   7,   2, 125,   7,   2, 126,   7,   2,  47, 
  7,   2, 127,   7,   2, 128,   1,   9,  44,  17,   9,  20,  18,   7,   2, 131, 
  1,   9, 132,   1,  19,   7,   2, 135,   1,   9, 137,   1,  20,   9, 139,   1, 
 20,   9, 142,   1,  20,   7,   2, 142,   1,   7,   2, 137,   1,   7,   2, 139, 
  1,   7,  37, 144,   1,   7,   2, 146,   1,   7,   2, 147,   1,   7,  37, 148, 
  1,   7,   2, 150,   1,   7,   2, 151,   1,   7,   2, 152,   1,   7,   2, 153, 
  1,   7,  37, 154,   1,   7,  37, 156,   1,   9,  20,  19,   7,  37, 157,   1, 
  7,  37, 158,   1,   7,  37, 159,   1,   7,  37, 160,   1,   7,  37, 163,   1, 
  7,  37, 164,   1,   7,  37, 165,   1,   7,  37, 166,   1,   7,  37, 169,   1, 
  7,  37, 170,   1,   7,  37, 171,   1,   7,  38, 132,   1,   7,  37, 176,   1, 
  7,  37, 177,   1,   7,  37, 178,   1,   7,   2, 180,   1,   7,   2, 181,   1, 
  7,   2, 182,   1,   7,   2, 183,   1,   7,   2, 184,   1,   7,   2, 185,   1, 
  7,   2, 186,   1,   7,   2, 187,   1,   7,   2, 188,   1,   7,   2, 189,   1, 
  7,   2, 190,   1,   7,  49, 192,   1,   9,  20,  21,   7,  17, 196,   1,   9, 
 20,  22,   7,   2, 201,   1,   7,   2, 203,   1,   7,  17, 205,   1,   9,  20, 
 23,   7,   4, 208,   1,   7,   2, 209,   1,   7,   2, 210,   1,   7,   2, 211, 
  1,   7,   2, 212,   1,   7,   2, 213,   1,   7,   2, 214,   1,   9,  20,  24, 
159,   1,   0,   3,   3,   0,   0,   5,   3,   0,   0,   0,   3,   4,   0,   0, 
  3,   4,   1,  10,   3,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0, 
  0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0, 
  0,   3,   0,   0,   0,   3,   0,   1,  20,  21,   3,  32,   1,  21,   3,   3, 
 32,   0,   3,   3,  32,   1,  20,  22,   3,  32,   1,  20,   3,   3,  32,   0, 
 20,   3,  32,   0,  23,   3,  32,   0,   5,   3,  32,   0,  22,   3,  32,   0, 
  3,   3,  32,   0,  24,   3,  32,   0,  24,   3,  32,   0,  24,   3,  32,   0, 
 20,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,  23,   3,   3,  32, 
  1,   3,   3,   3,  32,   2,  20,   3,   3,   3,  32,   2,  42,   3,  23,   3, 
  0,   2,  23,   3,  42,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0, 
  3,   3,   0,   0,  23,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0, 
  0,   3,   0,   0,  64,   3,  32,   0,   5,   3,  32,   1,   0,  64,   3,  32, 
  1,   0,  42,   3,  32,   1,  10,   3,   3,  32,   1,   0,   3,   3,   0,   0, 
 42,   3,  32,   1,   0,  42,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0, 
  1,   0,   3,   3,   8,   1,  12,  12,   1,  20,   0,   3,  32,   0,   5,   3, 
 32,   1,   3,   5,   3,  32,   1,   5,   5,   3,  32,   1,  20,   5,   3,  32, 
  2,  21,   3,   5,   3,  40,   1,   1,   3,   2,  20,   5,   0,   3,  32,   2, 
 21,   3,   5,   3,  40,   1,   1,   6,   0,   5,   3,  32,   1,   0,   5,   3, 
 32,   2,  20,   5,   5,   3,  32,   1,  20,   5,   3,  32,   3,  20,   5,   5, 
  3,   3,  32,   0,  20,   3,  32,   2,  20,   5,   3,   3,  32,   2,   3,   5, 
  5,   3,  40,   1,   1,   6,   0,   3,   3,  32,   0,  20,   3,  32,   0,   0, 
  3,   0,   0,   0,   3,   0,   1,  42,   3,   3,  32,   1,  20,   3,   3,  32, 
  3,  20,  42,   5,   5,   3,  40,   2,   1,   3,   1,   3,   3,  20,  42,   5, 
  5,   3,  40,   2,   1,   3,   1,   3,   1,  20,  23,   3,  32,   1,  20,  21, 
  3,  32,   1,  20,  21,   3,  32,   1,  20,  21,   3,  32,   1,  20,   5,   3, 
 32,   1,  20,  24,   3,  32,   1,  20,  24,   3,  32,   1,  20,   3,   3,  32, 
  1,  20,   3,   3,  32,   0,  23,   3,  32,   0,  21,   3,  32,   0,   5,   3, 
 32,   0,  21,   3,  32,   0,   5,   3,  32,   0,  21,   3,  32,   0,   5,   3, 
 32,   0,  24,   3,  32,   0,  24,   3,  32,   0,   3,   3,  32,   1,   3,   5, 
  3,  32,   0,   5,   3,  32,   1,  20,   5,   3,  32,   0,  20,   3,  32,   0, 
 20,   3,   0,   0,  20,   3,  32,   0,  20,   3,   0,   0,   3,   3,  32,   0, 
  5,   3,  32,   0,   5,   3,  32,   1,  20,   5,   3,  32,   0,   3,   3,  32, 
  1,  20,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   2,  23,  17, 
131,   1,   3,  32,   3,  24,  17, 131,   1,   5,   3,  32,   2,  24,  17, 131, 
  1,   3,   0,   2,  24,  17, 131,   1,   3,   0,   2,  24,  17, 131,   1,   3, 
  0,   0,  24,   3,  32,   0,  17,   3,  32,   2,  17,  17,  23,   3,  40,   1, 
 10,  10,   1,  24,   0,   3,  32,   1,  20, 133,   1,   3,  32,   1,  20,  23, 
  3,  32,   0,  20,   3,  32,   0,  20,   3,  32,   0,  20,   3,  32,   0,  20, 
  3,  32,   0,   0,   3,   0,   0,   3,   3,   0,   0,   0,   3,   0,   0,   0, 
  3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,  32,   0,  24, 
  3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0, 
  3,   0,   0,   0,   3,   0,   2,   0,  21,  21,   3,  40,   1,   2,   3,   1, 
 21,  21,   3,  40,   1,   2,   3,   1,   0, 133,   1,   3,  32,   0, 133,   1, 
  3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   1,   0, 
 23,   3,  40,   1,  10,  10,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0, 
  3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   1, 185,   1,   3,   3,  36, 
  3, 185,   1, 185,   1,  21,  22,   3,  40,   1,  12,  12,   1,  22, 185,   1, 
  3,  32,   1,   3,   3,   3,  36,   2,   3, 185,   1,   3,   3,  36,   2,   3, 
185,   1,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,  14,  34,   1, 
 35,  36,  41,   0,  58,   2,  59,  61,  60,  62,  58,   2,  59,  61,  63,  62, 
 58,   3,  59,  74,  61,  73,  75,  62,  58,   3,  59,  74,  61,  96,  97,  62, 
 58,   3,  59,  74,  61, 129,   1, 130,   1,  62,  58,   3,  59,  74,  61, 161, 
  1, 162,   1,  62,  58,   3,  59,  74,  61, 167,   1, 168,   1,  62,  58,   2, 
172,   1,  61, 173,   1,  62,  58,   3,  59,  74,  61, 174,   1, 175,   1,  62, 
 58,   2,  59,  61, 194,   1,  62,  58,   3,  59,  74,  61, 198,   1, 199,   1, 
 62,  58,   3,  59,  74,  61, 216,   1, 208,   1,  62,  16,  14,   0,   5,   0, 
  8,   1,  13,   1,   0,   7,  16,  17,   9,   8,   0,  11,   1,  15,   1,   0, 
 10,  39,  17,   9,  10,   0,  27,   0,  48,  17,   9,  15,   0,  34,   0,  52, 
 17,  11,  21,   0,  38,   0,  64,  17,   9,  25,   0,  43,   5,  70,   1,   0, 
 45,  71,   2,   0,  47,  72,   1,   0,  46,  71,   3,   0,  48,  73,   1,   0, 
 44,  94,  17,   9,  29,   0,  51,  18,  77,   1,   0,  67,  78,   2,   0,  53, 
 79,   1,   0,  62,  80,   2,   0,  60,  81,   1,   0,  57,  82,   1,   0,  66, 
 80,   3,   0,  61,  83,   1,   0,  63,  84,   1,   0,  54,  85,   1,   0,  65, 
 86,   1,   0,  59,  87,   1,   0,  64,  88,   1,   0,  55,  89,   1,   0,  56, 
 90,   1,   0,  58,  91,   1,   0,  52,  92,   1,   0,  68,  93,   1,   0,  69, 
 42,  17,   9,  34,   0, 108,  35,  99,   1,   0, 101, 100,   1,   0,  84, 101, 
  1,   0,  91, 102,   1,   0,  88, 103,   1,   0,  77, 104,   1,   0,  83, 105, 
  1,   0,  76,  80,   3,   0,  97, 106,   1,   0,  93, 107,   1,   0,  79, 108, 
  1,   0,  89, 109,   3,   0, 105, 110,   1,   0,  75, 111,   1,   0,  98, 112, 
  1,   0,  82, 113,   1,   0,  87, 114,   1,   0,  80, 115,   1,   0,  78, 116, 
  2,   0, 103, 117,   1,   0,  99, 118,   1,   0,  92, 109,   2,   0, 104, 119, 
  2,   0, 106,  92,   1,   0, 102,  80,   2,   0,  96, 120,   1,   0, 100, 121, 
  1,   0,  94, 122,   1,   0,  85, 123,   1,   0,  74, 119,   3,   0, 107, 124, 
  1,   0,  90, 125,   1,   0,  95, 126,   1,   0,  73, 127,   1,   0,  81, 128, 
  1,   1,   0,  86, 140,   1,  17,  11,  40,   0, 127,   4,  92,   1,   0, 126, 
137,   1,   6,   0,   5,   0, 138,   1,   6,   0,   3,   0, 139,   1,   6,   0, 
  3,   0, 143,   1,  17,   9,  43,   0, 129,   1,   2, 141,   1,   6,   0,  22, 
  0, 142,   1,   6,   0,  24,   0, 148,   1, 143,   1,  11,  45,   0, 133,   1, 
  4, 144,   1,   2,   0, 132,   1, 145,   1,   6,   0,  10,   0, 146,   1,   6, 
  0,  24,   0, 147,   1,   2,   0, 131,   1, 149,   1, 143,   1,  11,  47,   0, 
135,   1,   2, 144,   1,   6,   0,  24,   0, 146,   1,   6,   0,  24,   0, 177, 
  1,  17,   9,  50,   0, 142,   1,   0, 179,   1,  17,   8,  54,   0, 145,   1, 
  0, 183,   1,  17,   9,  57,   0, 148,   1,   0, 185,   1,  17,   9,  60,   0, 
157,   1,   0,   6,   0,   9,   0,  12,  15,  18,   6,   1,  22,   0,  25,  17, 
  8,  18,  26,  18,  15,  25,  27,  17,   6,  16,  28,  17,  12,  22,  29,  17, 
  9,  19,  30,  18,  13,  23,  31,  18,  14,  24,  32,  17,  10,  20,  33,  81, 
  4,  14,   1,   0,  34,  17,  11,  21,  35,  17,  16,  26,  36,  17,   5,  15, 
 37,  81,   3,  13,   1,   1,  38,  17,   7,  17,  28,   5,  44,  17,   6,  32, 
 45,  17,   7,  33,  46,  17,   3,  29,  47,  17,   4,  30,  38,  17,   5,  31, 
 35,   2,  51,  18,   3,  36,  29,  18,   4,  37,  40,   2,  68,  18,   3,  41, 
 69,  18,   4,  42,  50,   0,  71,   1,  98,  17,   3,  72, 125,   0, 128,   1, 
  0, 130,   1,   0, 134,   1,   0, 137,   1,  11, 170,   1,   6,   5,  21,   3, 
  3, 169,   1,   6,   4,  21,   4,   3, 173,   1,  17,   6, 141,   1, 174,   1, 
 17,   4, 139,   1, 166,   1,   6,   1,  21,   1,   3, 168,   1,   6,   3,  21, 
  2,   3, 175,   1,  17,   3, 138,   1, 167,   1,   6,   2,  21,   5,   3, 176, 
  1,  17,   5, 140,   1, 172,   1,   6,   7,   0,   2,   3, 171,   1,   6,   6, 
  0,   5,   3, 144,   1,   0, 147,   1,   2, 181,   1,   6,   1,   3, 202,   1, 
  1, 182,   1,   6,   2,   3, 204,   1,   1, 150,   1,   6, 186,   1,  17,   5, 
153,   1, 187,   1,  17,   8, 156,   1, 188,   1,  17,   7, 155,   1, 189,   1, 
 17,   3, 151,   1, 190,   1,  17,   4, 152,   1, 191,   1,  17,   6, 154,   1, 
  9,  49,   1,  64,  68,   0,   5,   1,   4,  70,   1,  94,  68,   1,   6,   1, 
  5, 109,   1,  42,  68,   0,   7,   1,   6, 136,   1,  19, 151,   1,   1,   9, 
122, 152,   1,   1,  19, 112, 153,   1,   1,  17, 114, 154,   1,   1,  18, 113, 
149,   1,  68,   4,  11,   1,   7, 155,   1,   1,  11, 120, 156,   1,   1,  16, 
115, 157,   1,   1,   8, 123, 158,   1,   1,  13, 118, 148,   1,  68,   3,  10, 
  1,   8, 159,   1,   1,  14, 117, 160,   1,   1,  12, 119, 161,   1,  65,  21, 
110,   1,   9, 162,   1,   1,  20, 111, 143,   1,  68,   2,   9,   1,  10, 163, 
  1,   1,  15, 116, 140,   1,   4,   1,   8, 164,   1,   1,   7, 124, 165,   1, 
  1,  10, 121, 143,   1,   1, 177,   1,  68,   1,  12,   1,  11, 146,   1,   1, 
179,   1,  68,   1,  13,   1,  12, 149,   1,   1, 183,   1,   4,   1,  14, 158, 
  1,   1, 185,   1,  68,   1,  15,   1,  13,  39,  12,  60,   1,   1,   5,  27, 
  1,   4,   2,  39,  68,   0,   2,   1,   2,  16,   4,   0,   1,  14,   4,   0, 
  0,  32,   1,   5,   1,  48,  68,   0,   3,   1,   3,  28,   1,   6,   0,  61, 
  1,   3,   3,  52,   4,   0,   4,  62,   1,   2,   4,  63,   6,   0,   0,  13, 
  8,  56,   0,   1,   1,   1,   2,  10, 208,  48,  93,   1, 102,   1,  70,   2, 
  0,  72,   0,   0,   1,   1,   1,   1,   2,  10, 208,  48,  93,   1, 102,   1, 
 70,   4,   0,  72,   0,   0,   2,   2,   2,   1,   2,  12, 208,  48,  93,   1, 
102,   1, 209,  70,   6,   1,  41,  71,   0,   0,   3,   2,   2,   1,   2,  12, 
208,  48,  93,   1, 102,   1, 209,  70,   6,   1,  41,  71,   0,   0,   4,   2, 
  2,   1,   2,  13, 208,  48,  93,   7, 102,   7, 102,   8, 209,  70,   9,   1, 
 72,   0,   0,   5,   1,   1,   1,   2,  11, 208,  48,  93,  11, 102,  11,  70, 
 12,   0,  41,  71,   0,   0,   6,   0,   1,   3,   3,   1,  71,   0,   0,   9, 
  1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  10,   1,   1,   4,   5,   3, 
208,  48,  71,   0,   0,  11,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0, 
 71,   0,   0,  12,   2,   1,   3,   4,  12, 208,  48,  94,  18,  93,  19,  70, 
 19,   0, 104,  18,  71,   0,   0,  27,   1,   1,   4,   5,   6, 208,  48, 208, 
 73,   0,  71,   0,   0,  28,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 
 32,   2,   3,   3,   4,  11, 208,  48,  93,  40, 102,  40, 209,  70,  41,   1, 
 72,   0,   0,  33,   2,   3,   3,   4,  10, 208,  48, 210, 209,  70,  43,   1, 
 41,  38,  72,   0,   0,  34,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0, 
 71,   0,   0,  35,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  36,   1, 
  1,   3,   4,   5, 208,  48,  44,  54,  72,   0,   0,  37,   1,   1,   3,   4, 
 10, 208,  48,  93,  49, 102,  49,  70,  50,   0,  72,   0,   0,  38,   1,   1, 
  4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  39,   2,   1,   1,   3, 
 74, 208,  48,  93,  53,  32,  88,   0, 104,  14,  93,  54,  93,  17, 102,  17, 
 48,  93,  55, 102,  55,  88,   1,  29, 104,  16,  93,  56,  93,  17, 102,  17, 
 48,  93,  55, 102,  55,  88,   2,  29, 104,  39,  93,  57,  93,  17, 102,  17, 
 48,  93,  55, 102,  55,  88,   3,  29, 104,  48,  93,  58,  93,  17, 102,  17, 
 48,  93,  59, 102,  59,  88,   4,  29, 104,  52,  71,   0,   0,  40,   1,   1, 
  3,   4,   3, 208,  48,  71,   0,   0,  46,   3,   2,   4,   5,  15, 208,  48, 
208,  93,  65, 102,  65, 209,  70,  66,   1,  70,  67,   1,  72,   0,   0,  49, 
  2,   1,   1,   3,  19, 208,  48,  93,  74,  93,  17, 102,  17,  48,  93,  75, 
102,  75,  88,   5,  29, 104,  64,  71,   0,   0,  50,   1,   1,   3,   4,   3, 
208,  48,  71,   0,   0,  51,   2,   2,   4,   5,  18, 208,  48, 208,  73,   0, 
209,  32,  19,   6,   0,   0, 208, 209,  70,  76,   1,  41,  71,   0,   0,  70, 
  2,   1,   1,   3,  19, 208,  48, 101,   0,  93,  17, 102,  17,  48,  93,  95, 
102,  95,  88,   6,  29, 104,  94,  71,   0,   0,  71,   1,   1,   3,   4,   3, 
208,  48,  71,   0,   0,  99,   1,   1,   4,   5,   8, 208,  48, 208,  70,  96, 
  0,  41,  71,   0,   0, 101,   1,   1,   4,   5,   8, 208,  48, 208,  70,  97, 
  0,  41,  71,   0,   0, 108,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0, 
 71,   0,   0, 109,   2,   1,   1,   3,  22, 208,  48,  93, 129,   1,  93,  17, 
102,  17,  48,  93, 130,   1, 102, 130,   1,  88,   7,  29, 104,  42,  71,   0, 
  0, 112,   4,   3,   1,   2,  14, 208,  48,  93, 132,   1, 209, 210,  36,   1, 
 70, 132,   1,   3,  72,   0,   0, 113,   4,   3,   1,   2,  14, 208,  48,  93, 
132,   1, 209, 210,  36,   2,  70, 132,   1,   3,  72,   0,   0, 114,   4,   3, 
  1,   2,  14, 208,  48,  93, 132,   1, 209, 210,  36,   0,  70, 132,   1,   3, 
 72,   0,   0, 125,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 126,   3, 
  1,   4,   5,  50, 208,  48, 208, 102, 134,   1,  44, 138,   1, 160, 208, 102, 
135,   1, 118,  18,  26,   0,   0,  44, 140,   1, 208, 102, 135,   1, 160,  44, 
141,   1, 160, 208, 102, 136,   1, 160,  44, 143,   1, 160, 130,  16,   3,   0, 
  0,  44,   3, 130, 160,  72,   0,   0, 127,   1,   1,   4,   5,   6, 208,  48, 
208,  73,   0,  71,   0,   0, 128,   1,   1,   1,   3,   4,   3, 208,  48,  71, 
  0,   0, 129,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0, 
  0, 130,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 133,   1,   1, 
  1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 134,   1,   1,   1, 
  4,   5,   3, 208,  48,  71,   0,   0, 135,   1,   1,   1,   5,   6,   6, 208, 
 48, 208,  73,   0,  71,   0,   0, 136,   1,   2,   1,   1,   4,  89, 208,  48, 
101,   0,  93,  17, 102,  17,  48,  93, 150,   1, 102, 150,   1,  88,   8,  29, 
104, 140,   1, 101,   0,  93,  17, 102,  17,  48,  93, 150,   1, 102, 150,   1, 
 88,   9,  29, 104, 143,   1, 101,   0,  93,  17, 102,  17,  48,  93, 143,   1, 
102, 143,   1,  48, 100, 108,   2,  88,  10,  29,  29, 104, 148,   1, 101,   0, 
 93,  17, 102,  17,  48,  93, 143,   1, 102, 143,   1,  48, 100, 108,   2,  88, 
 11,  29,  29, 104, 149,   1,  71,   0,   0, 137,   1,   2,   1,   3,   4,  59, 
208,  48,  94, 166,   1,  36,   0, 104, 166,   1,  94, 167,   1,  36,   1, 104, 
167,   1,  94, 168,   1,  36,   2, 104, 168,   1,  94, 169,   1,  36,   3, 104, 
169,   1,  94, 170,   1,  36,   4, 104, 170,   1,  94, 171,   1,  36,   1, 104, 
171,   1,  94, 172,   1,  36,   2, 104, 172,   1,  71,   0,   0, 142,   1,   1, 
  1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 143,   1,   2,   1, 
  1,   3,  22, 208,  48, 101,   0,  93,  17, 102,  17,  48,  93, 178,   1, 102, 
178,   1,  88,  12,  29, 104, 177,   1,  71,   0,   0, 144,   1,   1,   1,   3, 
  4,   3, 208,  48,  71,   0,   0, 146,   1,   2,   1,   1,   3,  22, 208,  48, 
101,   0,  93,  17, 102,  17,  48,  93, 180,   1, 102, 180,   1,  88,  13,  29, 
104, 179,   1,  71,   0,   0, 147,   1,   2,   1,   3,   4,  21, 208,  48,  94, 
181,   1,  44, 202,   1, 104, 181,   1,  94, 182,   1,  44, 204,   1, 104, 182, 
  1,  71,   0,   0, 148,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0, 
 71,   0,   0, 149,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  17, 
102,  17,  48,  93, 184,   1, 102, 184,   1,  88,  14,  29, 104, 183,   1,  71, 
  0,   0, 150,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 157,   1, 
  1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 158,   1,   2, 
  1,   1,   3,  22, 208,  48, 101,   0,  93,  17, 102,  17,  48,  93, 192,   1, 
102, 192,   1,  88,  15,  29, 104, 185,   1,  71,   0,   0};
