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

#define AVMTHUNK_VERSION 5

namespace avmplus {
    class ArrayObject; // Array
    class ClassClosure; // Class
    class DeleteObjectSampleClass; // flash.sampler::DeleteObjectSample$
    class DeleteObjectSampleObject; // flash.sampler::DeleteObjectSample
    class DictionaryClass; // flash.utils::Dictionary$
    class DictionaryObject; // flash.utils::Dictionary
    class DomainClass; // avmplus::Domain$
    class DomainObject; // avmplus::Domain
    class JObject; // avmplus::JObject
    class JObjectClass; // avmplus::JObject$
    class NewObjectSampleClass; // flash.sampler::NewObjectSample$
    class NewObjectSampleObject; // flash.sampler::NewObjectSample
    class SampleClass; // flash.sampler::Sample$
    class SampleObject; // flash.sampler::Sample
    class ScriptObject; // avmplus::System
    class ScriptObject; // avmplus::File
    class ScriptObject; // flash.trace::Trace
    class StackFrameClass; // flash.sampler::StackFrame$
    class StackFrameObject; // flash.sampler::StackFrame
    class String; // String
    class TraceClass; // flash.trace::Trace$
}

namespace avmshell {
    class FileClass; // avmplus::File$
    class MIClass; // avmplus::MI$
    class MIObject; // avmplus::MI
    class SystemClass; // avmplus::System$
}

namespace avmplus { namespace NativeID {

extern const uint32_t shell_toplevel_abc_class_count;
extern const uint32_t shell_toplevel_abc_script_count;
extern const uint32_t shell_toplevel_abc_method_count;
extern const uint32_t shell_toplevel_abc_length;
extern const uint8_t shell_toplevel_abc_data[];
extern const char* const shell_toplevel_versioned_uris[];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(shell_toplevel)

/* classes */
const uint32_t abcclass_avmplus_ITest = 0;
const uint32_t abcclass_avmplus_CTest = 1;
const uint32_t abcclass_avmplus_MI = 2;
const uint32_t abcclass_avmplus_System = 3;
const uint32_t abcclass_avmplus_File = 4;
const uint32_t abcclass_flash_system_Capabilities = 5;
const uint32_t abcclass_avmshell_public_class = 6;
const uint32_t abcclass_avmshell_public_class_AIR_1_0 = 7;
const uint32_t abcclass_avmshell_public_class_FP_10_0 = 8;
const uint32_t abcclass_avmshell_public_class_AIR_1_5 = 9;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1 = 10;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32 = 11;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_2 = 12;
const uint32_t abcclass_avmshell_public_class_AIR_1_0_FP_10_0 = 13;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 14;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32_AIR_1_0_FP_10_0 = 15;
const uint32_t abcclass_avmshell_public_interface = 16;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0 = 17;
const uint32_t abcclass_avmshell_public_interface_FP_10_0 = 18;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5 = 19;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1 = 20;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32 = 21;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_2 = 22;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0_FP_10_0 = 23;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 24;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32_AIR_1_0_FP_10_0 = 25;
const uint32_t abcclass_avmplus_Domain = 26;
const uint32_t abcclass_flash_sampler_StackFrame = 27;
const uint32_t abcclass_flash_sampler_Sample = 28;
const uint32_t abcclass_flash_sampler_NewObjectSample = 29;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 30;
const uint32_t abcclass_flash_trace_Trace = 31;
const uint32_t abcclass_flash_utils_Dictionary = 32;
const uint32_t abcclass_flash_utils_Endian = 33;
const uint32_t abcclass_avmplus_JObject = 34;

/* methods */
const uint32_t avmplus_MI_plus = 43;
const uint32_t avmplus_System_exit = 46;
const uint32_t avmplus_System_exec = 47;
const uint32_t avmplus_System_getAvmplusVersion = 48;
const uint32_t avmplus_System_getFeatures = 49;
const uint32_t avmplus_System_getRunmode = 50;
const uint32_t avmplus_System_trace = 51;
const uint32_t avmplus_System_write = 52;
const uint32_t avmplus_System_debugger = 53;
const uint32_t avmplus_System_isDebugger = 54;
const uint32_t avmplus_System_getTimer = 55;
const uint32_t avmplus_System_private_getArgv = 56;
const uint32_t avmplus_System_readLine = 57;
const uint32_t avmplus_System_totalMemory_get = 58;
const uint32_t avmplus_System_freeMemory_get = 59;
const uint32_t avmplus_System_privateMemory_get = 60;
const uint32_t avmplus_System_forceFullCollection = 61;
const uint32_t avmplus_System_queueCollection = 62;
const uint32_t avmplus_System_ns_example_nstest = 63;
const uint32_t avmplus_System_isGlobal = 64;
const uint32_t avmplus_System_swfVersion_get = 65;
const uint32_t avmplus_System_apiVersion_get = 66;
const uint32_t avmplus_System_disposeXML = 67;
const uint32_t avmplus_File_exists = 70;
const uint32_t avmplus_File_read = 71;
const uint32_t avmplus_File_write = 72;
const uint32_t avmplus_File_readByteArray = 73;
const uint32_t avmplus_File_writeByteArray = 74;
const uint32_t avmplus_Domain_currentDomain_get = 152;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 153;
const uint32_t avmplus_Domain_private_init = 154;
const uint32_t avmplus_Domain_loadBytes = 156;
const uint32_t avmplus_Domain_getClass = 157;
const uint32_t avmplus_Domain_domainMemory_get = 159;
const uint32_t avmplus_Domain_domainMemory_set = 160;
const uint32_t native_script_function_flash_sampler_getMasterString = 162;
const uint32_t native_script_function_flash_sampler_getSavedThis = 163;
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 164;
const uint32_t native_script_function_flash_sampler_isGetterSetter = 165;
const uint32_t native_script_function_flash_sampler__getInvocationCount = 166;
const uint32_t native_script_function_flash_sampler_getSampleCount = 170;
const uint32_t native_script_function_flash_sampler_getSamples = 171;
const uint32_t native_script_function_flash_sampler_getMemberNames = 172;
const uint32_t native_script_function_flash_sampler_getSize = 173;
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 174;
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 177;
const uint32_t native_script_function_flash_sampler_pauseSampling = 178;
const uint32_t native_script_function_flash_sampler_stopSampling = 179;
const uint32_t native_script_function_flash_sampler_startSampling = 180;
const uint32_t native_script_function_flash_sampler_clearSamples = 181;
const uint32_t flash_sampler_NewObjectSample_object_get = 188;
const uint32_t flash_sampler_NewObjectSample_size_get = 189;
const uint32_t flash_trace_Trace_setLevel = 195;
const uint32_t flash_trace_Trace_getLevel = 196;
const uint32_t flash_trace_Trace_setListener = 197;
const uint32_t flash_trace_Trace_getListener = 198;
const uint32_t flash_utils_Dictionary_private_init = 202;
const uint32_t avmplus_JObject_create = 209;
const uint32_t avmplus_JObject_createArray = 210;
const uint32_t avmplus_JObject_toArray = 211;
const uint32_t avmplus_JObject_constructorSignature = 212;
const uint32_t avmplus_JObject_methodSignature = 213;
const uint32_t avmplus_JObject_fieldSignature = 214;

extern avmplus::Atom avmplus_Domain_currentDomain_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_domainMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_sampler_NewObjectSample_object_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double flash_sampler_NewObjectSample_size_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_clearSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_startSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_stopSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_pauseSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSampleCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_Dictionary_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_JObject_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_JObject_createArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_JObject_toArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_JObject_constructorSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_JObject_methodSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_JObject_fieldSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_MI_plus_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getAvmplusVersion_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getFeatures_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getRunmode_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_debugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isDebugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_private_getArgv_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_readLine_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_totalMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_freeMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_privateMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_forceFullCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_queueCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_ns_example_nstest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_swfVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_apiVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS

extern avmplus::Atom shell_toplevel_s2a_oos_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_JObject_methodSignature_thunk  shell_toplevel_s2a_oos_rest_thunk

extern avmplus::Atom shell_toplevel_func_s2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_getMasterString_thunk  shell_toplevel_func_s2a_os_thunk

extern avmplus::Atom shell_toplevel_func_v2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler__setSamplerCallback_thunk  shell_toplevel_func_v2a_oo_thunk

extern double shell_toplevel_d2d_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_freeMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_privateMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_totalMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_sampler_NewObjectSample_size_get_thunk  shell_toplevel_d2d_o_thunk

extern avmplus::Atom shell_toplevel_a2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_Domain_getClass_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_File_readByteArray_thunk  shell_toplevel_a2a_os_thunk

extern avmplus::Atom shell_toplevel_func_b2a_oao_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_isGetterSetter_thunk  shell_toplevel_func_b2a_oao_thunk

extern avmplus::Atom shell_toplevel_a2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_JObject_toArray_thunk  shell_toplevel_a2a_oo_thunk
#define flash_trace_Trace_setListener_thunk  shell_toplevel_a2a_oo_thunk

extern avmplus::Atom shell_toplevel_s2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_getAvmplusVersion_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getFeatures_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getRunmode_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_readLine_thunk  shell_toplevel_s2a_o_thunk

extern avmplus::Atom shell_toplevel_func_v2a_ob_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_sampleInternalAllocs_thunk  shell_toplevel_func_v2a_ob_thunk

extern avmplus::Atom shell_toplevel_v2a_oss_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_File_write_thunk  shell_toplevel_v2a_oss_thunk

extern double shell_toplevel_func_d2d_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_getSize_thunk  shell_toplevel_func_d2d_oa_thunk

extern avmplus::Atom shell_toplevel_func_v2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_clearSamples_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_pauseSampling_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_startSampling_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_stopSampling_thunk  shell_toplevel_func_v2a_o_thunk

extern avmplus::Atom shell_toplevel_u2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_System_getTimer_thunk  shell_toplevel_u2a_o_thunk

extern avmplus::Atom shell_toplevel_s2a_os_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_JObject_constructorSignature_thunk  shell_toplevel_s2a_os_rest_thunk

extern double shell_toplevel_func_d2d_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_getSampleCount_thunk  shell_toplevel_func_d2d_o_thunk

extern avmplus::Atom shell_toplevel_i2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_apiVersion_get_thunk  shell_toplevel_i2a_o_thunk
#define avmplus_System_swfVersion_get_thunk  shell_toplevel_i2a_o_thunk

extern avmplus::Atom shell_toplevel_s2a_oos_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_JObject_fieldSignature_thunk  shell_toplevel_s2a_oos_thunk

extern avmplus::Atom shell_toplevel_i2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_exec_thunk  shell_toplevel_i2a_os_thunk

extern avmplus::Atom shell_toplevel_b2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_isGlobal_thunk  shell_toplevel_b2a_oa_thunk

extern avmplus::Atom shell_toplevel_s2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_File_read_thunk  shell_toplevel_s2a_os_thunk

extern avmplus::Atom shell_toplevel_func_a2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_getSamples_thunk  shell_toplevel_func_a2a_o_thunk

extern avmplus::Atom shell_toplevel_a2a_os_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_JObject_create_thunk  shell_toplevel_a2a_os_rest_thunk

extern avmplus::Atom shell_toplevel_a2a_ooio_optanullObjectAtom_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_JObject_createArray_thunk  shell_toplevel_a2a_ooio_optanullObjectAtom_thunk

extern avmplus::Atom shell_toplevel_func_a2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_getLexicalScopes_thunk  shell_toplevel_func_a2a_oo_thunk
#define native_script_function_flash_sampler_getSavedThis_thunk  shell_toplevel_func_a2a_oo_thunk

extern avmplus::Atom shell_toplevel_b2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_File_exists_thunk  shell_toplevel_b2a_os_thunk

extern avmplus::Atom shell_toplevel_a2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_Domain_currentDomain_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_domainMemory_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_System_private_getArgv_thunk  shell_toplevel_a2a_o_thunk
#define flash_sampler_NewObjectSample_object_get_thunk  shell_toplevel_a2a_o_thunk
#define flash_trace_Trace_getListener_thunk  shell_toplevel_a2a_o_thunk

extern avmplus::Atom shell_toplevel_a2a_oou_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_Domain_loadBytes_thunk  shell_toplevel_a2a_oou_opti0_thunk

extern avmplus::Atom shell_toplevel_v2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_debugger_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_forceFullCollection_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_ns_example_nstest_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_queueCollection_thunk  shell_toplevel_v2a_o_thunk

extern double shell_toplevel_d2d_od_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_MI_plus_thunk  shell_toplevel_d2d_od_thunk

extern avmplus::Atom shell_toplevel_v2a_ob_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_utils_Dictionary_private_init_thunk  shell_toplevel_v2a_ob_thunk

extern avmplus::Atom shell_toplevel_i2a_oi_opti2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_trace_Trace_getLevel_thunk  shell_toplevel_i2a_oi_opti2_thunk

extern avmplus::Atom shell_toplevel_a2a_oii_opti2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_trace_Trace_setLevel_thunk  shell_toplevel_a2a_oii_opti2_thunk

extern avmplus::Atom shell_toplevel_b2a_oso_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_File_writeByteArray_thunk  shell_toplevel_b2a_oso_thunk

extern avmplus::Atom shell_toplevel_v2a_oi_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_exit_thunk  shell_toplevel_v2a_oi_thunk

extern avmplus::Atom shell_toplevel_v2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_Domain_domainMemory_set_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_Domain_private_init_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_disposeXML_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_trace_thunk  shell_toplevel_v2a_oo_thunk

extern avmplus::Atom shell_toplevel_b2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_isDebugger_thunk  shell_toplevel_b2a_o_thunk

extern avmplus::Atom shell_toplevel_v2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define avmplus_System_write_thunk  shell_toplevel_v2a_os_thunk

extern double shell_toplevel_func_d2d_oaou_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler__getInvocationCount_thunk  shell_toplevel_func_d2d_oaou_thunk

extern avmplus::Atom shell_toplevel_func_a2a_oab_optbfalse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_flash_sampler_getMemberNames_thunk  shell_toplevel_func_a2a_oab_optbfalse_thunk

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts;
// avmplus::MI$
//-----------------------------------------------------------
class _avmshell_MIClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_MIClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_MIClassSlots EmptySlotsStruct_MIClass
//-----------------------------------------------------------

// avmplus::MI
//-----------------------------------------------------------
class _avmshell_MIObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_MIObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_MIObjectSlots EmptySlotsStruct_MIObject
//-----------------------------------------------------------

// avmplus::System$
//-----------------------------------------------------------
class _avmshell_SystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ArrayObject* get_argv() const { return m_argv; }
private:
    DRCWB(ArrayObject*) m_argv;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_argv);
    }
};
#define DECLARE_SLOTS_SystemClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_argv() const { return m_slots_SystemClass.get_argv(); } \
    private: \
        avmplus::NativeID::_avmshell_SystemClassSlots m_slots_SystemClass
//-----------------------------------------------------------

// avmplus::File$
//-----------------------------------------------------------
class _avmshell_FileClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_FileClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_FileClassSlots EmptySlotsStruct_FileClass
//-----------------------------------------------------------

// avmplus::Domain$
//-----------------------------------------------------------
class DomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DomainClass
};
#define DECLARE_SLOTS_DomainClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DomainClassSlots EmptySlotsStruct_DomainClass
//-----------------------------------------------------------

// avmplus::Domain
//-----------------------------------------------------------
class DomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DomainObject
};
#define DECLARE_SLOTS_DomainObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DomainObjectSlots EmptySlotsStruct_DomainObject
//-----------------------------------------------------------

// flash.sampler::StackFrame$
//-----------------------------------------------------------
class StackFrameClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_StackFrameClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::StackFrameClassSlots EmptySlotsStruct_StackFrameClass
//-----------------------------------------------------------

// flash.sampler::StackFrame
//-----------------------------------------------------------
class StackFrameObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_line() const { return m_line; }
    REALLY_INLINE void set_line(uint32_t newVal) { m_line = newVal; }
    REALLY_INLINE avmplus::String* get_name() const { return m_name; }
    REALLY_INLINE void set_name(avmplus::String* newVal) { m_name = newVal; }
    REALLY_INLINE avmplus::String* get_file() const { return m_file; }
    REALLY_INLINE void set_file(avmplus::String* newVal) { m_file = newVal; }
    REALLY_INLINE double get_scriptID() const { return m_scriptID; }
    REALLY_INLINE void set_scriptID(double newVal) { m_scriptID = newVal; }
private:
    uint32_t m_line;
    DRCWB(avmplus::String*) m_name;
    DRCWB(avmplus::String*) m_file;
    double m_scriptID;
};
#define DECLARE_SLOTS_StackFrameObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE uint32_t get_line() const { return m_slots_StackFrameObject.get_line(); } \
        REALLY_INLINE void set_line(uint32_t newVal) { m_slots_StackFrameObject.set_line(newVal); } \
        REALLY_INLINE avmplus::String* get_name() const { return m_slots_StackFrameObject.get_name(); } \
        REALLY_INLINE void set_name(avmplus::String* newVal) { m_slots_StackFrameObject.set_name(newVal); } \
        REALLY_INLINE avmplus::String* get_file() const { return m_slots_StackFrameObject.get_file(); } \
        REALLY_INLINE void set_file(avmplus::String* newVal) { m_slots_StackFrameObject.set_file(newVal); } \
        REALLY_INLINE double get_scriptID() const { return m_slots_StackFrameObject.get_scriptID(); } \
        REALLY_INLINE void set_scriptID(double newVal) { m_slots_StackFrameObject.set_scriptID(newVal); } \
    private: \
        avmplus::NativeID::StackFrameObjectSlots m_slots_StackFrameObject
//-----------------------------------------------------------

// flash.sampler::Sample$
//-----------------------------------------------------------
class SampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_SampleClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::SampleClassSlots EmptySlotsStruct_SampleClass
//-----------------------------------------------------------

// flash.sampler::Sample
//-----------------------------------------------------------
class SampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ArrayObject* get_stack() const { return m_stack; }
    REALLY_INLINE void set_stack(ArrayObject* newVal) { m_stack = newVal; }
    REALLY_INLINE double get_time() const { return m_time; }
    REALLY_INLINE void set_time(double newVal) { m_time = newVal; }
private:
    DRCWB(ArrayObject*) m_stack;
    double m_time;
};
#define DECLARE_SLOTS_SampleObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_stack() const { return m_slots_SampleObject.get_stack(); } \
        REALLY_INLINE void set_stack(ArrayObject* newVal) { m_slots_SampleObject.set_stack(newVal); } \
        REALLY_INLINE double get_time() const { return m_slots_SampleObject.get_time(); } \
        REALLY_INLINE void set_time(double newVal) { m_slots_SampleObject.set_time(newVal); } \
    private: \
        avmplus::NativeID::SampleObjectSlots m_slots_SampleObject
//-----------------------------------------------------------

// flash.sampler::NewObjectSample$
//-----------------------------------------------------------
class NewObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NewObjectSampleClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::NewObjectSampleClassSlots EmptySlotsStruct_NewObjectSampleClass
//-----------------------------------------------------------

// flash.sampler::NewObjectSample
//-----------------------------------------------------------
class NewObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ClassClosure* get_type() const { return m_type; }
    REALLY_INLINE void set_type(ClassClosure* newVal) { m_type = newVal; }
    REALLY_INLINE double get_id() const { return m_id; }
    REALLY_INLINE void set_id(double newVal) { m_id = newVal; }
private:
    DRCWB(ClassClosure*) m_type;
    double m_id;
};
#define DECLARE_SLOTS_NewObjectSampleObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ClassClosure* get_type() const { return m_slots_NewObjectSampleObject.get_type(); } \
        REALLY_INLINE void set_type(ClassClosure* newVal) { m_slots_NewObjectSampleObject.set_type(newVal); } \
        REALLY_INLINE double get_id() const { return m_slots_NewObjectSampleObject.get_id(); } \
        REALLY_INLINE void set_id(double newVal) { m_slots_NewObjectSampleObject.set_id(newVal); } \
    private: \
        avmplus::NativeID::NewObjectSampleObjectSlots m_slots_NewObjectSampleObject
//-----------------------------------------------------------

// flash.sampler::DeleteObjectSample$
//-----------------------------------------------------------
class DeleteObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_DeleteObjectSampleClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DeleteObjectSampleClassSlots EmptySlotsStruct_DeleteObjectSampleClass
//-----------------------------------------------------------

// flash.sampler::DeleteObjectSample
//-----------------------------------------------------------
class DeleteObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE double get_id() const { return m_id; }
    REALLY_INLINE void set_id(double newVal) { m_id = newVal; }
    REALLY_INLINE double get_size() const { return m_size; }
    REALLY_INLINE void set_size(double newVal) { m_size = newVal; }
private:
    double m_id;
    double m_size;
};
#define DECLARE_SLOTS_DeleteObjectSampleObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE double get_id() const { return m_slots_DeleteObjectSampleObject.get_id(); } \
        REALLY_INLINE void set_id(double newVal) { m_slots_DeleteObjectSampleObject.set_id(newVal); } \
        REALLY_INLINE double get_size() const { return m_slots_DeleteObjectSampleObject.get_size(); } \
        REALLY_INLINE void set_size(double newVal) { m_slots_DeleteObjectSampleObject.set_size(newVal); } \
    private: \
        avmplus::NativeID::DeleteObjectSampleObjectSlots m_slots_DeleteObjectSampleObject
//-----------------------------------------------------------

// flash.trace::Trace$
//-----------------------------------------------------------
class TraceClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_OFF() const { return m_OFF; }
    REALLY_INLINE int32_t get_METHODS() const { return m_METHODS; }
    REALLY_INLINE int32_t get_METHODS_WITH_ARGS() const { return m_METHODS_WITH_ARGS; }
    REALLY_INLINE int32_t get_METHODS_AND_LINES() const { return m_METHODS_AND_LINES; }
    REALLY_INLINE int32_t get_METHODS_AND_LINES_WITH_ARGS() const { return m_METHODS_AND_LINES_WITH_ARGS; }
    REALLY_INLINE avmplus::Atom get_FILE() const { return m_FILE; }
    REALLY_INLINE avmplus::Atom get_LISTENER() const { return m_LISTENER; }
private:
    int32_t m_OFF;
    int32_t m_METHODS;
    int32_t m_METHODS_WITH_ARGS;
    int32_t m_METHODS_AND_LINES;
    int32_t m_METHODS_AND_LINES_WITH_ARGS;
    ATOM_WB m_FILE;
    ATOM_WB m_LISTENER;
};
#define DECLARE_SLOTS_TraceClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_OFF() const { return m_slots_TraceClass.get_OFF(); } \
        REALLY_INLINE int32_t get_METHODS() const { return m_slots_TraceClass.get_METHODS(); } \
        REALLY_INLINE int32_t get_METHODS_WITH_ARGS() const { return m_slots_TraceClass.get_METHODS_WITH_ARGS(); } \
        REALLY_INLINE int32_t get_METHODS_AND_LINES() const { return m_slots_TraceClass.get_METHODS_AND_LINES(); } \
        REALLY_INLINE int32_t get_METHODS_AND_LINES_WITH_ARGS() const { return m_slots_TraceClass.get_METHODS_AND_LINES_WITH_ARGS(); } \
        REALLY_INLINE avmplus::Atom get_FILE() const { return m_slots_TraceClass.get_FILE(); } \
        REALLY_INLINE avmplus::Atom get_LISTENER() const { return m_slots_TraceClass.get_LISTENER(); } \
    private: \
        avmplus::NativeID::TraceClassSlots m_slots_TraceClass
//-----------------------------------------------------------

// flash.utils::Dictionary$
//-----------------------------------------------------------
class DictionaryClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DictionaryClass
};
#define DECLARE_SLOTS_DictionaryClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DictionaryClassSlots EmptySlotsStruct_DictionaryClass
//-----------------------------------------------------------

// flash.utils::Dictionary
//-----------------------------------------------------------
class DictionaryObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DictionaryObject
};
#define DECLARE_SLOTS_DictionaryObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DictionaryObjectSlots EmptySlotsStruct_DictionaryObject
//-----------------------------------------------------------

// avmplus::JObject$
//-----------------------------------------------------------
class JObjectClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_JObjectClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::JObjectClassSlots EmptySlotsStruct_JObjectClass
//-----------------------------------------------------------

// avmplus::JObject
//-----------------------------------------------------------
class JObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_JObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::JObjectSlots EmptySlotsStruct_JObject
//-----------------------------------------------------------

} }
