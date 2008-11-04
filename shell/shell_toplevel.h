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
#define AVMTHUNK_VERSION 3
const uint32_t shell_toplevel_abc_class_count = 16;
const uint32_t shell_toplevel_abc_script_count = 9;
const uint32_t shell_toplevel_abc_method_count = 159;
const uint32_t shell_toplevel_abc_length = 6524;
extern const uint8_t shell_toplevel_abc_data[6524];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(shell_toplevel, shell_toplevel)
/* classes */
const uint32_t abcclass_avmplus_ITest = 0;
const uint32_t abcclass_avmplus_CTest = 1;
const uint32_t abcclass_avmplus_System = 2;
const uint32_t abcclass_avmplus_File = 3;
const uint32_t abcclass_flash_system_Capabilities = 4;
const uint32_t abcclass_avmplus_Domain = 5;
const uint32_t abcclass_avmplus_StringBuilder = 6;
const uint32_t abcclass_flash_utils_ByteArray = 7;
const uint32_t abcclass_flash_sampler_StackFrame = 8;
const uint32_t abcclass_flash_sampler_Sample = 9;
const uint32_t abcclass_flash_sampler_NewObjectSample = 10;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 11;
const uint32_t abcclass_flash_trace_Trace = 12;
const uint32_t abcclass_flash_utils_Dictionary = 13;
const uint32_t abcclass_flash_utils_Endian = 14;
const uint32_t abcclass_avmplus_JObject = 15;
/* methods */
/* const uint32_t readLine = 0; */
/* const uint32_t getTimer = 1; */
/* const uint32_t trace = 2; */
/* const uint32_t print = 3; */
/* const uint32_t getClassByName = 4; */
/* const uint32_t avmplus_debugger = 5; */
/* const uint32_t avmplus_ITest_avmplus_ITest_test = 7; */
/* const uint32_t avmplus_CTest_test = 10; */
const uint32_t avmplus_System_exit = 13;
const uint32_t avmplus_System_exec = 14;
const uint32_t avmplus_System_getAvmplusVersion = 15;
const uint32_t avmplus_System_trace = 16;
const uint32_t avmplus_System_write = 17;
const uint32_t avmplus_System_debugger = 18;
const uint32_t avmplus_System_isDebugger = 19;
const uint32_t avmplus_System_getTimer = 20;
const uint32_t avmplus_System_private_getArgv = 21;
const uint32_t avmplus_System_readLine = 22;
const uint32_t avmplus_System_totalMemory_get = 23;
const uint32_t avmplus_System_freeMemory_get = 24;
const uint32_t avmplus_System_privateMemory_get = 25;
const uint32_t avmplus_System_ns_example_nstest = 26;
const uint32_t avmplus_File_exists = 29;
const uint32_t avmplus_File_read = 30;
const uint32_t avmplus_File_write = 31;
/* const uint32_t avmplus_File_fileToByteArray = 32; */
/* const uint32_t avmplus_File_writeByteArray = 33; */
/* const uint32_t flash_system_Capabilities_playerType = 36; */
/* const uint32_t flash_system_Capabilities_isDebugger = 37; */
const uint32_t avmplus_Domain_currentDomain_get = 41;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 42;
const uint32_t avmplus_Domain_Domain = 43;
const uint32_t avmplus_Domain_loadBytes = 44;
const uint32_t avmplus_Domain_getClass = 45;
/* const uint32_t avmplus_Domain_load = 46; */
const uint32_t avmplus_Domain_domainMemory_get = 47;
const uint32_t avmplus_Domain_domainMemory_set = 48;
const uint32_t avmplus_StringBuilder_append = 52;
const uint32_t avmplus_StringBuilder_capacity_get = 53;
const uint32_t avmplus_StringBuilder_charAt = 54;
const uint32_t avmplus_StringBuilder_charCodeAt = 55;
const uint32_t avmplus_StringBuilder_ensureCapacity = 56;
const uint32_t avmplus_StringBuilder_indexOf = 57;
const uint32_t avmplus_StringBuilder_insert = 58;
const uint32_t avmplus_StringBuilder_lastIndexOf = 59;
const uint32_t avmplus_StringBuilder_length_get = 60;
const uint32_t avmplus_StringBuilder_length_set = 61;
const uint32_t avmplus_StringBuilder_remove = 62;
const uint32_t avmplus_StringBuilder_removeCharAt = 63;
const uint32_t avmplus_StringBuilder_replace = 64;
const uint32_t avmplus_StringBuilder_reverse = 65;
const uint32_t avmplus_StringBuilder_setCharAt = 66;
const uint32_t avmplus_StringBuilder_substring = 67;
const uint32_t avmplus_StringBuilder_toString = 68;
const uint32_t avmplus_StringBuilder_trimToSize = 69;
const uint32_t flash_utils_ByteArray_readFile = 72;
const uint32_t flash_utils_ByteArray_writeFile = 73;
const uint32_t flash_utils_ByteArray_readBytes = 74;
const uint32_t flash_utils_ByteArray_writeBytes = 75;
const uint32_t flash_utils_ByteArray_writeBoolean = 76;
const uint32_t flash_utils_ByteArray_writeByte = 77;
const uint32_t flash_utils_ByteArray_writeShort = 78;
const uint32_t flash_utils_ByteArray_writeInt = 79;
const uint32_t flash_utils_ByteArray_writeUnsignedInt = 80;
const uint32_t flash_utils_ByteArray_writeFloat = 81;
const uint32_t flash_utils_ByteArray_writeDouble = 82;
const uint32_t flash_utils_ByteArray_writeUTF = 83;
const uint32_t flash_utils_ByteArray_writeUTFBytes = 84;
const uint32_t flash_utils_ByteArray_readBoolean = 85;
const uint32_t flash_utils_ByteArray_readByte = 86;
const uint32_t flash_utils_ByteArray_readUnsignedByte = 87;
const uint32_t flash_utils_ByteArray_readShort = 88;
const uint32_t flash_utils_ByteArray_readUnsignedShort = 89;
const uint32_t flash_utils_ByteArray_readInt = 90;
const uint32_t flash_utils_ByteArray_readUnsignedInt = 91;
const uint32_t flash_utils_ByteArray_readFloat = 92;
const uint32_t flash_utils_ByteArray_readDouble = 93;
const uint32_t flash_utils_ByteArray_readUTF = 94;
const uint32_t flash_utils_ByteArray_readUTFBytes = 95;
const uint32_t flash_utils_ByteArray_length_get = 96;
const uint32_t flash_utils_ByteArray_length_set = 97;
const uint32_t flash_utils_ByteArray_private_zlib_compress = 98;
/* const uint32_t flash_utils_ByteArray_compress = 99; */
const uint32_t flash_utils_ByteArray_private_zlib_uncompress = 100;
/* const uint32_t flash_utils_ByteArray_uncompress = 101; */
const uint32_t flash_utils_ByteArray_toString = 102;
const uint32_t flash_utils_ByteArray_bytesAvailable_get = 103;
const uint32_t flash_utils_ByteArray_position_get = 104;
const uint32_t flash_utils_ByteArray_position_set = 105;
const uint32_t flash_utils_ByteArray_endian_get = 106;
const uint32_t flash_utils_ByteArray_endian_set = 107;
const uint32_t flash_sampler_isGetterSetter = 110;
const uint32_t flash_sampler__getInvocationCount = 111;
/* const uint32_t flash_sampler_getGetterInvocationCount = 112; */
/* const uint32_t flash_sampler_getSetterInvocationCount = 113; */
/* const uint32_t flash_sampler_getInvocationCount = 114; */
const uint32_t flash_sampler_getSampleCount = 115;
const uint32_t flash_sampler_getSamples = 116;
const uint32_t flash_sampler_getMemberNames = 117;
const uint32_t flash_sampler_getSize = 118;
const uint32_t flash_sampler_setSamplerCallback = 119;
const uint32_t flash_sampler_sampleInternalAllocs = 120;
const uint32_t flash_sampler_pauseSampling = 121;
const uint32_t flash_sampler_stopSampling = 122;
const uint32_t flash_sampler_startSampling = 123;
const uint32_t flash_sampler_clearSamples = 124;
/* const uint32_t flash_sampler_StackFrame_toString = 126; */
const uint32_t flash_sampler_NewObjectSample_object_get = 131;
const uint32_t flash_sampler_NewObjectSample_size_get = 132;
const uint32_t flash_trace_Trace_setLevel = 138;
const uint32_t flash_trace_Trace_getLevel = 139;
const uint32_t flash_trace_Trace_setListener = 140;
const uint32_t flash_trace_Trace_getListener = 141;
const uint32_t flash_utils_Dictionary_Dictionary = 145;
const uint32_t avmplus_JObject_create = 151;
const uint32_t avmplus_JObject_createArray = 152;
const uint32_t avmplus_JObject_toArray = 153;
const uint32_t avmplus_JObject_constructorSignature = 154;
const uint32_t avmplus_JObject_methodSignature = 155;
const uint32_t avmplus_JObject_fieldSignature = 156;

/* thunks (42 unique) */
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_JObject_methodSignature_thunk  shell_toplevel_s2a_oos_rest_thunk
#define avmplus_JObject_methodSignature_thunkc shell_toplevel_s2a_oos_rest_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_sampler_NewObjectSample_size_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_sampler_NewObjectSample_size_get_thunkc shell_toplevel_d2d_o_thunkc
#define avmplus_System_freeMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_freeMemory_get_thunkc shell_toplevel_d2d_o_thunkc
#define avmplus_System_privateMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_privateMemory_get_thunkc shell_toplevel_d2d_o_thunkc
#define flash_sampler_getSampleCount_thunk  shell_toplevel_d2d_o_thunk
#define flash_sampler_getSampleCount_thunkc shell_toplevel_d2d_o_thunkc
#define flash_utils_ByteArray_readFloat_thunk  shell_toplevel_d2d_o_thunk
#define flash_utils_ByteArray_readFloat_thunkc shell_toplevel_d2d_o_thunkc
#define avmplus_System_totalMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_totalMemory_get_thunkc shell_toplevel_d2d_o_thunkc
#define flash_utils_ByteArray_readDouble_thunk  shell_toplevel_d2d_o_thunk
#define flash_utils_ByteArray_readDouble_thunkc shell_toplevel_d2d_o_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oouu_opti0_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oouu_opti0_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_writeBytes_thunk  shell_toplevel_v2a_oouu_opti0_opti0_thunk
#define flash_utils_ByteArray_writeBytes_thunkc shell_toplevel_v2a_oouu_opti0_opti0_thunkc
#define flash_utils_ByteArray_readBytes_thunk  shell_toplevel_v2a_oouu_opti0_opti0_thunk
#define flash_utils_ByteArray_readBytes_thunkc shell_toplevel_v2a_oouu_opti0_opti0_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_readFile_thunk  shell_toplevel_a2a_os_thunk
#define flash_utils_ByteArray_readFile_thunkc shell_toplevel_a2a_os_thunkc
#define avmplus_Domain_getClass_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_Domain_getClass_thunkc shell_toplevel_a2a_os_thunkc

extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_charCodeAt_thunk  shell_toplevel_u2a_ou_thunk
#define avmplus_StringBuilder_charCodeAt_thunkc shell_toplevel_u2a_ou_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_length_set_thunk  shell_toplevel_a2a_ou_thunk
#define avmplus_StringBuilder_length_set_thunkc shell_toplevel_a2a_ou_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oi_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_writeByte_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeByte_thunkc shell_toplevel_v2a_oi_thunkc
#define avmplus_System_exit_thunk  shell_toplevel_v2a_oi_thunk
#define avmplus_System_exit_thunkc shell_toplevel_v2a_oi_thunkc
#define flash_utils_ByteArray_writeInt_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeInt_thunkc shell_toplevel_v2a_oi_thunkc
#define flash_utils_ByteArray_writeShort_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeShort_thunkc shell_toplevel_v2a_oi_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_System_readLine_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_readLine_thunkc shell_toplevel_s2a_o_thunkc
#define flash_utils_ByteArray_toString_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_toString_thunkc shell_toplevel_s2a_o_thunkc
#define flash_utils_ByteArray_endian_get_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_endian_get_thunkc shell_toplevel_s2a_o_thunkc
#define flash_utils_ByteArray_readUTF_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_readUTF_thunkc shell_toplevel_s2a_o_thunkc
#define avmplus_System_getAvmplusVersion_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getAvmplusVersion_thunkc shell_toplevel_s2a_o_thunkc
#define avmplus_StringBuilder_toString_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_StringBuilder_toString_thunkc shell_toplevel_s2a_o_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ob_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ob_optbfalse_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_Dictionary_Dictionary_thunk  shell_toplevel_a2a_ob_optbfalse_thunk
#define flash_utils_Dictionary_Dictionary_thunkc shell_toplevel_a2a_ob_optbfalse_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oss_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_File_write_thunk  shell_toplevel_v2a_oss_thunk
#define avmplus_File_write_thunkc shell_toplevel_v2a_oss_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_oao_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_sampler_isGetterSetter_thunk  shell_toplevel_b2a_oao_thunk
#define flash_sampler_isGetterSetter_thunkc shell_toplevel_b2a_oao_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_oi_opti2_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_trace_Trace_getLevel_thunk  shell_toplevel_i2a_oi_opti2_thunk
#define flash_trace_Trace_getLevel_thunkc shell_toplevel_i2a_oi_opti2_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ous_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ous_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_setCharAt_thunk  shell_toplevel_v2a_ous_thunk
#define avmplus_StringBuilder_setCharAt_thunkc shell_toplevel_v2a_ous_thunkc

extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE shell_toplevel_u2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_readUnsignedShort_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedShort_thunkc shell_toplevel_u2a_o_thunkc
#define flash_utils_ByteArray_bytesAvailable_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_bytesAvailable_get_thunkc shell_toplevel_u2a_o_thunkc
#define flash_utils_ByteArray_length_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_length_get_thunkc shell_toplevel_u2a_o_thunkc
#define avmplus_StringBuilder_length_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_StringBuilder_length_get_thunkc shell_toplevel_u2a_o_thunkc
#define flash_utils_ByteArray_readUnsignedInt_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedInt_thunkc shell_toplevel_u2a_o_thunkc
#define flash_utils_ByteArray_readUnsignedByte_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedByte_thunkc shell_toplevel_u2a_o_thunkc
#define avmplus_System_getTimer_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_System_getTimer_thunkc shell_toplevel_u2a_o_thunkc
#define avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunkc shell_toplevel_u2a_o_thunkc
#define avmplus_StringBuilder_capacity_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_StringBuilder_capacity_get_thunkc shell_toplevel_u2a_o_thunkc
#define flash_utils_ByteArray_position_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_position_get_thunkc shell_toplevel_u2a_o_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouu_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouu_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_remove_thunk  shell_toplevel_v2a_ouu_thunk
#define avmplus_StringBuilder_remove_thunkc shell_toplevel_v2a_ouu_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_ooio_optakAvmThunkNull_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_JObject_createArray_thunk  shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk
#define avmplus_JObject_createArray_thunkc shell_toplevel_a2a_ooio_optakAvmThunkNull_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_JObject_constructorSignature_thunk  shell_toplevel_s2a_os_rest_thunk
#define avmplus_JObject_constructorSignature_thunkc shell_toplevel_s2a_os_rest_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_readInt_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readInt_thunkc shell_toplevel_i2a_o_thunkc
#define flash_utils_ByteArray_readShort_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readShort_thunkc shell_toplevel_i2a_o_thunkc
#define flash_utils_ByteArray_readByte_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readByte_thunkc shell_toplevel_i2a_o_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oua_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oua_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_insert_thunk  shell_toplevel_v2a_oua_thunk
#define avmplus_StringBuilder_insert_thunkc shell_toplevel_v2a_oua_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_oos_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_JObject_fieldSignature_thunk  shell_toplevel_s2a_oos_thunk
#define avmplus_JObject_fieldSignature_thunkc shell_toplevel_s2a_oos_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouus_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ouus_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_replace_thunk  shell_toplevel_v2a_ouus_thunk
#define avmplus_StringBuilder_replace_thunkc shell_toplevel_v2a_ouus_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_System_exec_thunk  shell_toplevel_i2a_os_thunk
#define avmplus_System_exec_thunkc shell_toplevel_i2a_os_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_File_exists_thunk  shell_toplevel_s2a_os_thunk
#define avmplus_File_exists_thunkc shell_toplevel_s2a_os_thunkc
#define avmplus_File_read_thunk  shell_toplevel_s2a_os_thunk
#define avmplus_File_read_thunkc shell_toplevel_s2a_os_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_charAt_thunk  shell_toplevel_s2a_ou_thunk
#define avmplus_StringBuilder_charAt_thunkc shell_toplevel_s2a_ou_thunkc
#define flash_utils_ByteArray_readUTFBytes_thunk  shell_toplevel_s2a_ou_thunk
#define flash_utils_ByteArray_readUTFBytes_thunkc shell_toplevel_s2a_ou_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_os_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_JObject_create_thunk  shell_toplevel_a2a_os_rest_thunk
#define avmplus_JObject_create_thunkc shell_toplevel_a2a_os_rest_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE shell_toplevel_b2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_readBoolean_thunk  shell_toplevel_b2a_o_thunk
#define flash_utils_ByteArray_readBoolean_thunkc shell_toplevel_b2a_o_thunkc
#define avmplus_System_isDebugger_thunk  shell_toplevel_b2a_o_thunk
#define avmplus_System_isDebugger_thunkc shell_toplevel_b2a_o_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_sampler_getSamples_thunk  shell_toplevel_a2a_o_thunk
#define flash_sampler_getSamples_thunkc shell_toplevel_a2a_o_thunkc
#define avmplus_Domain_currentDomain_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_currentDomain_get_thunkc shell_toplevel_a2a_o_thunkc
#define avmplus_System_private_getArgv_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_System_private_getArgv_thunkc shell_toplevel_a2a_o_thunkc
#define flash_trace_Trace_getListener_thunk  shell_toplevel_a2a_o_thunk
#define flash_trace_Trace_getListener_thunkc shell_toplevel_a2a_o_thunkc
#define flash_sampler_NewObjectSample_object_get_thunk  shell_toplevel_a2a_o_thunk
#define flash_sampler_NewObjectSample_object_get_thunkc shell_toplevel_a2a_o_thunkc
#define avmplus_Domain_domainMemory_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_domainMemory_get_thunkc shell_toplevel_a2a_o_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oaou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_sampler__getInvocationCount_thunk  shell_toplevel_d2d_oaou_thunk
#define flash_sampler__getInvocationCount_thunkc shell_toplevel_d2d_oaou_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_optu4294967295U_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_lastIndexOf_thunk  shell_toplevel_i2a_osu_optu4294967295U_thunk
#define avmplus_StringBuilder_lastIndexOf_thunkc shell_toplevel_i2a_osu_optu4294967295U_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_od_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_od_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_writeFloat_thunk  shell_toplevel_v2a_od_thunk
#define flash_utils_ByteArray_writeFloat_thunkc shell_toplevel_v2a_od_thunkc
#define flash_utils_ByteArray_writeDouble_thunk  shell_toplevel_v2a_od_thunk
#define flash_utils_ByteArray_writeDouble_thunkc shell_toplevel_v2a_od_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ouu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE shell_toplevel_s2a_ouu_optu4294967295U_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_substring_thunk  shell_toplevel_s2a_ouu_optu4294967295U_thunk
#define avmplus_StringBuilder_substring_thunkc shell_toplevel_s2a_ouu_optu4294967295U_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ob_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_writeBoolean_thunk  shell_toplevel_v2a_ob_thunk
#define flash_utils_ByteArray_writeBoolean_thunkc shell_toplevel_v2a_ob_thunkc
#define flash_sampler_sampleInternalAllocs_thunk  shell_toplevel_v2a_ob_thunk
#define flash_sampler_sampleInternalAllocs_thunkc shell_toplevel_v2a_ob_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_append_thunk  shell_toplevel_v2a_oa_thunk
#define avmplus_StringBuilder_append_thunkc shell_toplevel_v2a_oa_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE shell_toplevel_d2d_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_sampler_getSize_thunk  shell_toplevel_d2d_oa_thunk
#define flash_sampler_getSize_thunkc shell_toplevel_d2d_oa_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_oo_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_System_trace_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_trace_thunkc shell_toplevel_v2a_oo_thunkc
#define flash_sampler_setSamplerCallback_thunk  shell_toplevel_v2a_oo_thunk
#define flash_sampler_setSamplerCallback_thunkc shell_toplevel_v2a_oo_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE shell_toplevel_i2a_osu_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_indexOf_thunk  shell_toplevel_i2a_osu_opti0_thunk
#define avmplus_StringBuilder_indexOf_thunkc shell_toplevel_i2a_osu_opti0_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_sampler_startSampling_thunk  shell_toplevel_v2a_o_thunk
#define flash_sampler_startSampling_thunkc shell_toplevel_v2a_o_thunkc
#define flash_utils_ByteArray_private_zlib_compress_thunk  shell_toplevel_v2a_o_thunk
#define flash_utils_ByteArray_private_zlib_compress_thunkc shell_toplevel_v2a_o_thunkc
#define flash_sampler_pauseSampling_thunk  shell_toplevel_v2a_o_thunk
#define flash_sampler_pauseSampling_thunkc shell_toplevel_v2a_o_thunkc
#define flash_sampler_clearSamples_thunk  shell_toplevel_v2a_o_thunk
#define flash_sampler_clearSamples_thunkc shell_toplevel_v2a_o_thunkc
#define flash_sampler_stopSampling_thunk  shell_toplevel_v2a_o_thunk
#define flash_sampler_stopSampling_thunkc shell_toplevel_v2a_o_thunkc
#define avmplus_System_ns_example_nstest_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_ns_example_nstest_thunkc shell_toplevel_v2a_o_thunkc
#define avmplus_System_debugger_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_debugger_thunkc shell_toplevel_v2a_o_thunkc
#define avmplus_StringBuilder_trimToSize_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_StringBuilder_trimToSize_thunkc shell_toplevel_v2a_o_thunkc
#define flash_utils_ByteArray_private_zlib_uncompress_thunk  shell_toplevel_v2a_o_thunk
#define flash_utils_ByteArray_private_zlib_uncompress_thunkc shell_toplevel_v2a_o_thunkc
#define avmplus_StringBuilder_reverse_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_StringBuilder_reverse_thunkc shell_toplevel_v2a_o_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oii_opti2_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_trace_Trace_setLevel_thunk  shell_toplevel_a2a_oii_opti2_thunk
#define flash_trace_Trace_setLevel_thunkc shell_toplevel_a2a_oii_opti2_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_StringBuilder_ensureCapacity_thunk  shell_toplevel_v2a_ou_thunk
#define avmplus_StringBuilder_ensureCapacity_thunkc shell_toplevel_v2a_ou_thunkc
#define flash_utils_ByteArray_position_set_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_position_set_thunkc shell_toplevel_v2a_ou_thunkc
#define avmplus_StringBuilder_removeCharAt_thunk  shell_toplevel_v2a_ou_thunk
#define avmplus_StringBuilder_removeCharAt_thunkc shell_toplevel_v2a_ou_thunkc
#define flash_utils_ByteArray_writeUnsignedInt_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_writeUnsignedInt_thunkc shell_toplevel_v2a_ou_thunkc
#define flash_utils_ByteArray_length_set_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_length_set_thunkc shell_toplevel_v2a_ou_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE shell_toplevel_v2a_os_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_utils_ByteArray_writeUTF_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeUTF_thunkc shell_toplevel_v2a_os_thunkc
#define flash_utils_ByteArray_endian_set_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_endian_set_thunkc shell_toplevel_v2a_os_thunkc
#define flash_utils_ByteArray_writeFile_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeFile_thunkc shell_toplevel_v2a_os_thunkc
#define avmplus_System_write_thunk  shell_toplevel_v2a_os_thunk
#define avmplus_System_write_thunkc shell_toplevel_v2a_os_thunkc
#define flash_utils_ByteArray_writeUTFBytes_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeUTFBytes_thunkc shell_toplevel_v2a_os_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oab_optbfalse_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define flash_sampler_getMemberNames_thunk  shell_toplevel_a2a_oab_optbfalse_thunk
#define flash_sampler_getMemberNames_thunkc shell_toplevel_a2a_oab_optbfalse_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE shell_toplevel_a2a_oo_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define avmplus_JObject_toArray_thunk  shell_toplevel_a2a_oo_thunk
#define avmplus_JObject_toArray_thunkc shell_toplevel_a2a_oo_thunkc
#define avmplus_Domain_loadBytes_thunk  shell_toplevel_a2a_oo_thunk
#define avmplus_Domain_loadBytes_thunkc shell_toplevel_a2a_oo_thunkc
#define avmplus_Domain_domainMemory_set_thunk  shell_toplevel_a2a_oo_thunk
#define avmplus_Domain_domainMemory_set_thunkc shell_toplevel_a2a_oo_thunkc
#define avmplus_Domain_Domain_thunk  shell_toplevel_a2a_oo_thunk
#define avmplus_Domain_Domain_thunkc shell_toplevel_a2a_oo_thunkc
#define flash_trace_Trace_setListener_thunk  shell_toplevel_a2a_oo_thunk
#define flash_trace_Trace_setListener_thunkc shell_toplevel_a2a_oo_thunkc

