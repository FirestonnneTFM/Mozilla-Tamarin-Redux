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

#ifndef _H_nativegen_header_shell_toplevel
#define _H_nativegen_header_shell_toplevel

namespace avmplus {
    class ArrayObject; // Array
    class CTestClass; // avmplus::CTest$
    class CTestObject; // avmplus::CTest
    class CapabilitiesClass; // flash.system::Capabilities$
    class CapabilitiesObject; // flash.system::Capabilities
    class ClassClosure; // Class
    class ClassFactoryClass; // flash.sampler::ClassFactory$
    class ClassFactoryObject; // flash.sampler::ClassFactory
    class DeleteObjectSampleClass; // flash.sampler::DeleteObjectSample$
    class DeleteObjectSampleObject; // flash.sampler::DeleteObjectSample
    class DictionaryClass; // flash.utils::Dictionary$
    class DictionaryObject; // flash.utils::Dictionary
    class DomainClass; // avmplus::Domain$
    class DomainObject; // avmplus::Domain
    class EndianClass; // flash.utils::Endian$
    class EndianObject; // flash.utils::Endian
    class JObject; // avmplus::JObject
    class JObjectClass; // avmplus::JObject$
    class NativeBaseAS3Class; // avmshell::NativeBaseAS3$
    class NativeBaseAS3Object; // avmshell::NativeBaseAS3
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
    class SubclassOfAbstractBaseClass; // avmshell::SubclassOfAbstractBase$
    class SubclassOfAbstractBaseObject; // avmshell::SubclassOfAbstractBase
    class SubclassOfAbstractRestrictedBaseClass; // avmshell::SubclassOfAbstractRestrictedBase$
    class SubclassOfAbstractRestrictedBaseObject; // avmshell::SubclassOfAbstractRestrictedBase
    class SubclassOfRestrictedBaseClass; // avmshell::SubclassOfRestrictedBase$
    class SubclassOfRestrictedBaseObject; // avmshell::SubclassOfRestrictedBase
    class TraceClass; // flash.trace::Trace$
    class public_classClass; // avmshell::public_class$
    class public_classObject; // avmshell::public_class
    class public_class_AIR_1_0Class; // avmshell::public_class_AIR_1_0$
    class public_class_AIR_1_0Object; // avmshell::public_class_AIR_1_0
    class public_class_AIR_1_0_FP_10_0Class; // avmshell::public_class_AIR_1_0_FP_10_0$
    class public_class_AIR_1_0_FP_10_0Object; // avmshell::public_class_AIR_1_0_FP_10_0
    class public_class_AIR_1_5Class; // avmshell::public_class_AIR_1_5$
    class public_class_AIR_1_5Object; // avmshell::public_class_AIR_1_5
    class public_class_AIR_1_5_1Class; // avmshell::public_class_AIR_1_5_1$
    class public_class_AIR_1_5_1Object; // avmshell::public_class_AIR_1_5_1
    class public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class; // avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2$
    class public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object; // avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2
    class public_class_AIR_1_5_2Class; // avmshell::public_class_AIR_1_5_2$
    class public_class_AIR_1_5_2Object; // avmshell::public_class_AIR_1_5_2
    class public_class_FP_10_0Class; // avmshell::public_class_FP_10_0$
    class public_class_FP_10_0Object; // avmshell::public_class_FP_10_0
    class public_class_FP_10_0_32Class; // avmshell::public_class_FP_10_0_32$
    class public_class_FP_10_0_32Object; // avmshell::public_class_FP_10_0_32
    class public_class_FP_10_0_32_AIR_1_0_FP_10_0Class; // avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0$
    class public_class_FP_10_0_32_AIR_1_0_FP_10_0Object; // avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0
}

namespace avmshell {
    class AbstractBaseClass; // avmshell::AbstractBase$
    class AbstractBaseObject; // avmshell::AbstractBase
    class AbstractRestrictedBaseClass; // avmshell::AbstractRestrictedBase$
    class AbstractRestrictedBaseObject; // avmshell::AbstractRestrictedBase
    class CheckBaseClass; // avmshell::CheckBase$
    class CheckBaseObject; // avmshell::CheckBase
    class FileClass; // avmplus::File$
    class MIClass; // avmplus::MI$
    class MIObject; // avmplus::MI
    class NativeBaseClass; // avmshell::NativeBase$
    class NativeBaseObject; // avmshell::NativeBase
    class NativeSubclassOfAbstractBaseClass; // avmshell::NativeSubclassOfAbstractBase$
    class NativeSubclassOfAbstractBaseObject; // avmshell::NativeSubclassOfAbstractBase
    class NativeSubclassOfAbstractRestrictedBaseClass; // avmshell::NativeSubclassOfAbstractRestrictedBase$
    class NativeSubclassOfAbstractRestrictedBaseObject; // avmshell::NativeSubclassOfAbstractRestrictedBase
    class NativeSubclassOfRestrictedBaseClass; // avmshell::NativeSubclassOfRestrictedBase$
    class NativeSubclassOfRestrictedBaseObject; // avmshell::NativeSubclassOfRestrictedBase
    class RestrictedBaseClass; // avmshell::RestrictedBase$
    class RestrictedBaseObject; // avmshell::RestrictedBase
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
const uint32_t abcclass_avmshell_AbstractBase = 5;
const uint32_t abcclass_avmshell_RestrictedBase = 6;
const uint32_t abcclass_avmshell_AbstractRestrictedBase = 7;
const uint32_t abcclass_avmshell_CheckBase = 8;
const uint32_t abcclass_avmshell_NativeBase = 9;
const uint32_t abcclass_avmshell_NativeBaseAS3 = 10;
const uint32_t abcclass_flash_system_Capabilities = 11;
const uint32_t abcclass_avmshell_public_class = 12;
const uint32_t abcclass_avmshell_public_class_AIR_1_0 = 13;
const uint32_t abcclass_avmshell_public_class_FP_10_0 = 14;
const uint32_t abcclass_avmshell_public_class_AIR_1_5 = 15;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1 = 16;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32 = 17;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_2 = 18;
const uint32_t abcclass_avmshell_public_class_AIR_1_0_FP_10_0 = 19;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 20;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32_AIR_1_0_FP_10_0 = 21;
const uint32_t abcclass_avmshell_public_interface = 22;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0 = 23;
const uint32_t abcclass_avmshell_public_interface_FP_10_0 = 24;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5 = 25;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1 = 26;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32 = 27;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_2 = 28;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0_FP_10_0 = 29;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 30;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32_AIR_1_0_FP_10_0 = 31;
const uint32_t abcclass_avmshell_NativeSubclassOfAbstractBase = 32;
const uint32_t abcclass_avmshell_SubclassOfAbstractBase = 33;
const uint32_t abcclass_avmshell_NativeSubclassOfRestrictedBase = 34;
const uint32_t abcclass_avmshell_SubclassOfRestrictedBase = 35;
const uint32_t abcclass_avmshell_NativeSubclassOfAbstractRestrictedBase = 36;
const uint32_t abcclass_avmshell_SubclassOfAbstractRestrictedBase = 37;
const uint32_t abcclass_avmplus_Domain = 38;
const uint32_t abcclass_flash_sampler_StackFrame = 39;
const uint32_t abcclass_flash_sampler_Sample = 40;
const uint32_t abcclass_flash_sampler_ClassFactory = 41;
const uint32_t abcclass_flash_sampler_NewObjectSample = 42;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 43;
const uint32_t abcclass_flash_trace_Trace = 44;
const uint32_t abcclass_flash_utils_Dictionary = 45;
const uint32_t abcclass_flash_utils_Endian = 46;
const uint32_t abcclass_avmplus_JObject = 47;

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
const uint32_t avmplus_Domain_currentDomain_get = 176;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 177;
const uint32_t avmplus_Domain_private_init = 178;
const uint32_t avmplus_Domain_loadBytes = 180;
const uint32_t avmplus_Domain_getClass = 181;
const uint32_t avmplus_Domain_domainMemory_get = 183;
const uint32_t avmplus_Domain_domainMemory_set = 184;
const uint32_t native_script_function_flash_sampler_getMasterString = 186;
const uint32_t native_script_function_flash_sampler_getSavedThis = 187;
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 188;
const uint32_t native_script_function_flash_sampler_isGetterSetter = 189;
const uint32_t native_script_function_flash_sampler__getInvocationCount = 190;
const uint32_t native_script_function_flash_sampler_getSampleCount = 194;
const uint32_t native_script_function_flash_sampler__getSamples = 195;
const uint32_t native_script_function_flash_sampler_getMemberNames = 197;
const uint32_t native_script_function_flash_sampler_getSize = 198;
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 199;
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 202;
const uint32_t native_script_function_flash_sampler_pauseSampling = 203;
const uint32_t native_script_function_flash_sampler_stopSampling = 204;
const uint32_t native_script_function_flash_sampler_startSampling = 205;
const uint32_t native_script_function_flash_sampler_clearSamples = 206;
const uint32_t flash_sampler_NewObjectSample_object_get = 215;
const uint32_t flash_sampler_NewObjectSample_size_get = 216;
const uint32_t flash_trace_Trace_setLevel = 222;
const uint32_t flash_trace_Trace_getLevel = 223;
const uint32_t flash_trace_Trace_setListener = 224;
const uint32_t flash_trace_Trace_getListener = 225;
const uint32_t flash_utils_Dictionary_private_init = 229;
const uint32_t avmplus_JObject_create = 236;
const uint32_t avmplus_JObject_createArray = 237;
const uint32_t avmplus_JObject_toArray = 238;
const uint32_t avmplus_JObject_constructorSignature = 239;
const uint32_t avmplus_JObject_methodSignature = 240;
const uint32_t avmplus_JObject_fieldSignature = 241;

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
extern avmplus::Atom native_script_function_flash_sampler__getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
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
class SlotOffsetsAndAsserts;
//-----------------------------------------------------------
// avmplus::CTest$
//-----------------------------------------------------------
class avmplus_CTestClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CTestClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::CTest
//-----------------------------------------------------------
class avmplus_CTestObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CTestObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::MI$
//-----------------------------------------------------------
class avmshell_MIClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::MIClass;
};
#define DECLARE_SLOTS_MIClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmshell::MIObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::MIObject>((avmshell::MIObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::MI
//-----------------------------------------------------------
class avmshell_MIObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::MIObject;
};
#define DECLARE_SLOTS_MIObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::System$
//-----------------------------------------------------------
class avmshell_SystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::SystemClass;
private:
    DRCWB(avmplus::ArrayObject*) m_argv;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_argv);
    }
};
#define DECLARE_SLOTS_SystemClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::ArrayObject* get_argv() const { return m_slots_SystemClass.m_argv; } \
        REALLY_INLINE void setconst_argv(avmplus::ArrayObject* newVal) { m_slots_SystemClass.m_argv = newVal; } \
    private: \
        avmplus::NativeID::avmshell_SystemClassSlots m_slots_SystemClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::File$
//-----------------------------------------------------------
class avmshell_FileClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::FileClass;
};
#define DECLARE_SLOTS_FileClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::AbstractBase$
//-----------------------------------------------------------
class avmshell_AbstractBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::AbstractBaseClass;
};
#define DECLARE_SLOTS_AbstractBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::AbstractBase
//-----------------------------------------------------------
class avmshell_AbstractBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::AbstractBaseObject;
};
#define DECLARE_SLOTS_AbstractBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::RestrictedBase$
//-----------------------------------------------------------
class avmshell_RestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::RestrictedBaseClass;
};
#define DECLARE_SLOTS_RestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmshell::RestrictedBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::RestrictedBaseObject>((avmshell::RestrictedBaseObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::RestrictedBase
//-----------------------------------------------------------
class avmshell_RestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::RestrictedBaseObject;
};
#define DECLARE_SLOTS_RestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::AbstractRestrictedBase$
//-----------------------------------------------------------
class avmshell_AbstractRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::AbstractRestrictedBaseClass;
};
#define DECLARE_SLOTS_AbstractRestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::AbstractRestrictedBase
//-----------------------------------------------------------
class avmshell_AbstractRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::AbstractRestrictedBaseObject;
};
#define DECLARE_SLOTS_AbstractRestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::CheckBase$
//-----------------------------------------------------------
class avmshell_CheckBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CheckBaseClass;
};
#define DECLARE_SLOTS_CheckBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static void FASTCALL preCreateInstanceCheck(avmplus::ClassClosure*); \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmshell::CheckBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::CheckBaseObject>((avmshell::CheckBaseObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::CheckBase
//-----------------------------------------------------------
class avmshell_CheckBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CheckBaseObject;
};
#define DECLARE_SLOTS_CheckBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBase$
//-----------------------------------------------------------
class avmshell_NativeBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeBaseClass;
};
#define DECLARE_SLOTS_NativeBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmshell::NativeBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct_native(avmshell::NativeBaseClass::createInstanceProc, 0, args); \
            return GCRef<avmshell::NativeBaseObject>((avmshell::NativeBaseObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBase
//-----------------------------------------------------------
class avmshell_NativeBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeBaseObject;
};
#define DECLARE_SLOTS_NativeBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBaseAS3$
//-----------------------------------------------------------
class avmplus_NativeBaseAS3ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NativeBaseAS3Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBaseAS3
//-----------------------------------------------------------
class avmplus_NativeBaseAS3ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NativeBaseAS3Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Capabilities$
//-----------------------------------------------------------
class avmplus_CapabilitiesClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CapabilitiesClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Capabilities
//-----------------------------------------------------------
class avmplus_CapabilitiesObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CapabilitiesObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class$
//-----------------------------------------------------------
class avmplus_public_classClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_classClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class
//-----------------------------------------------------------
class avmplus_public_classObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_classObject;
private:
    bool32 m_public_var;
    bool32 m_public_var_AIR_1_0;
    bool32 m_public_var_FP_10_0;
    bool32 m_public_var_AIR_1_5;
    bool32 m_public_var_AIR_1_5_1;
    bool32 m_public_var_FP_10_0_32;
    bool32 m_public_var_AIR_1_5_2;
    bool32 m_public_var_AIR_1_0_FP_10_0;
    bool32 m_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2;
    bool32 m_public_var_FP_10_0_32_AIR_1_0_FP_10_0;
    bool32 m_public_const;
    bool32 m_public_const_AIR_1_0;
    bool32 m_public_const_FP_10_0;
    bool32 m_public_const_AIR_1_5;
    bool32 m_public_const_AIR_1_5_1;
    bool32 m_public_const_FP_10_0_32;
    bool32 m_public_const_AIR_1_5_2;
    bool32 m_public_const_AIR_1_0_FP_10_0;
    bool32 m_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2;
    bool32 m_public_const_FP_10_0_32_AIR_1_0_FP_10_0;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0$
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32$
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_2$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_2ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_2Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_2
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_2ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_2Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0_FP_10_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0_FP_10_0Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0_FP_10_0
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0_FP_10_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0_FP_10_0Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfAbstractBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfAbstractBaseClass;
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::NativeSubclassOfAbstractBaseObject>((avmshell::NativeSubclassOfAbstractBaseObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfAbstractBase
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfAbstractBaseObject;
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractBase$
//-----------------------------------------------------------
class avmplus_SubclassOfAbstractBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfAbstractBaseClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractBase
//-----------------------------------------------------------
class avmplus_SubclassOfAbstractBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfAbstractBaseObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfRestrictedBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfRestrictedBaseClass;
};
#define DECLARE_SLOTS_NativeSubclassOfRestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfRestrictedBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::NativeSubclassOfRestrictedBaseObject>((avmshell::NativeSubclassOfRestrictedBaseObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfRestrictedBase
//-----------------------------------------------------------
class avmshell_NativeSubclassOfRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfRestrictedBaseObject;
};
#define DECLARE_SLOTS_NativeSubclassOfRestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfRestrictedBase$
//-----------------------------------------------------------
class avmplus_SubclassOfRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfRestrictedBaseClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfRestrictedBase
//-----------------------------------------------------------
class avmplus_SubclassOfRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfRestrictedBaseObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfAbstractRestrictedBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfAbstractRestrictedBaseClass;
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractRestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject>((avmshell::NativeSubclassOfAbstractRestrictedBaseObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfAbstractRestrictedBase
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfAbstractRestrictedBaseObject;
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractRestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractRestrictedBase$
//-----------------------------------------------------------
class avmplus_SubclassOfAbstractRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfAbstractRestrictedBaseClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractRestrictedBase
//-----------------------------------------------------------
class avmplus_SubclassOfAbstractRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfAbstractRestrictedBaseObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::Domain$
//-----------------------------------------------------------
class avmplus_DomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DomainClass;
#define GC_TRIVIAL_TRACER_DomainClass
};
#define DECLARE_SLOTS_DomainClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmplus::DomainObject> constructObject(GCRef<avmplus::DomainObject> arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::Domain
//-----------------------------------------------------------
class avmplus_DomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DomainObject;
#define GC_TRIVIAL_TRACER_DomainObject
};
#define DECLARE_SLOTS_DomainObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::StackFrame$
//-----------------------------------------------------------
class avmplus_StackFrameClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::StackFrameClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::StackFrame
//-----------------------------------------------------------
class avmplus_StackFrameObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::StackFrameObject;
private:
    uint32_t m_line;
    DRCWB(avmplus::String*) m_name;
    DRCWB(avmplus::String*) m_file;
    double m_scriptID;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::Sample$
//-----------------------------------------------------------
class avmplus_SampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SampleClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::Sample
//-----------------------------------------------------------
class avmplus_SampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SampleObject;
private:
    DRCWB(avmplus::ArrayObject*) m_stack;
    double m_time;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::ClassFactory$
//-----------------------------------------------------------
class avmplus_ClassFactoryClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ClassFactoryClass;
private:
    DRCWB(avmplus::ClassClosure*) m_StackFrameClass;
    DRCWB(avmplus::ClassClosure*) m_SampleClass;
    DRCWB(avmplus::ClassClosure*) m_DeleteObjectSampleClass;
    DRCWB(avmplus::ClassClosure*) m_NewObjectSampleClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::ClassFactory
//-----------------------------------------------------------
class avmplus_ClassFactoryObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ClassFactoryObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::NewObjectSample$
//-----------------------------------------------------------
class avmplus_NewObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NewObjectSampleClass;
};
#define DECLARE_SLOTS_NewObjectSampleClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::NewObjectSample
//-----------------------------------------------------------
class avmplus_NewObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NewObjectSampleObject;
private:
    DRCWB(avmplus::ClassClosure*) m_type;
    double m_id;
};
#define DECLARE_SLOTS_NewObjectSampleObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::ClassClosure* get_type() const { return m_slots_NewObjectSampleObject.m_type; } \
        REALLY_INLINE void setconst_type(avmplus::ClassClosure* newVal) { m_slots_NewObjectSampleObject.m_type = newVal; } \
    public: \
        REALLY_INLINE double get_id() const { return m_slots_NewObjectSampleObject.m_id; } \
        REALLY_INLINE void setconst_id(double newVal) { m_slots_NewObjectSampleObject.m_id = newVal; } \
    private: \
        avmplus::NativeID::avmplus_NewObjectSampleObjectSlots m_slots_NewObjectSampleObject \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample$
//-----------------------------------------------------------
class avmplus_DeleteObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DeleteObjectSampleClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample
//-----------------------------------------------------------
class avmplus_DeleteObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DeleteObjectSampleObject;
private:
    double m_id;
    double m_size;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.trace::Trace$
//-----------------------------------------------------------
class avmplus_TraceClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::TraceClass;
private:
    int32_t m_OFF;
    int32_t m_METHODS;
    int32_t m_METHODS_WITH_ARGS;
    int32_t m_METHODS_AND_LINES;
    int32_t m_METHODS_AND_LINES_WITH_ARGS;
    avmplus::AtomWB m_FILE;
    avmplus::AtomWB m_LISTENER;
};
#define DECLARE_SLOTS_TraceClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_OFF() const { return m_slots_TraceClass.m_OFF; } \
        REALLY_INLINE void setconst_OFF(int32_t newVal) { m_slots_TraceClass.m_OFF = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS() const { return m_slots_TraceClass.m_METHODS; } \
        REALLY_INLINE void setconst_METHODS(int32_t newVal) { m_slots_TraceClass.m_METHODS = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS_WITH_ARGS() const { return m_slots_TraceClass.m_METHODS_WITH_ARGS; } \
        REALLY_INLINE void setconst_METHODS_WITH_ARGS(int32_t newVal) { m_slots_TraceClass.m_METHODS_WITH_ARGS = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS_AND_LINES() const { return m_slots_TraceClass.m_METHODS_AND_LINES; } \
        REALLY_INLINE void setconst_METHODS_AND_LINES(int32_t newVal) { m_slots_TraceClass.m_METHODS_AND_LINES = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS_AND_LINES_WITH_ARGS() const { return m_slots_TraceClass.m_METHODS_AND_LINES_WITH_ARGS; } \
        REALLY_INLINE void setconst_METHODS_AND_LINES_WITH_ARGS(int32_t newVal) { m_slots_TraceClass.m_METHODS_AND_LINES_WITH_ARGS = newVal; } \
    public: \
        REALLY_INLINE avmplus::Atom get_FILE() const { return m_slots_TraceClass.m_FILE; } \
        REALLY_INLINE void setconst_FILE(avmplus::Atom newVal) { m_slots_TraceClass.m_FILE = newVal; } \
    public: \
        REALLY_INLINE avmplus::Atom get_LISTENER() const { return m_slots_TraceClass.m_LISTENER; } \
        REALLY_INLINE void setconst_LISTENER(avmplus::Atom newVal) { m_slots_TraceClass.m_LISTENER = newVal; } \
    private: \
        avmplus::NativeID::avmplus_TraceClassSlots m_slots_TraceClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Dictionary$
//-----------------------------------------------------------
class avmplus_DictionaryClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DictionaryClass;
#define GC_TRIVIAL_TRACER_DictionaryClass
};
#define DECLARE_SLOTS_DictionaryClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmplus::DictionaryObject> constructObject(bool arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), ((arg1) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DictionaryObject>((avmplus::DictionaryObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DictionaryObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::DictionaryObject>((avmplus::DictionaryObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Dictionary
//-----------------------------------------------------------
class avmplus_DictionaryObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DictionaryObject;
#define GC_TRIVIAL_TRACER_DictionaryObject
};
#define DECLARE_SLOTS_DictionaryObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Endian$
//-----------------------------------------------------------
class avmplus_EndianClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EndianClass;
private:
    DRCWB(avmplus::String*) m_BIG_ENDIAN;
    DRCWB(avmplus::String*) m_LITTLE_ENDIAN;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Endian
//-----------------------------------------------------------
class avmplus_EndianObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EndianObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::JObject$
//-----------------------------------------------------------
class avmplus_JObjectClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::JObjectClass;
};
#define DECLARE_SLOTS_JObjectClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmplus::JObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::JObject>((avmplus::JObject*)(AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::JObject
//-----------------------------------------------------------
class avmplus_JObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::JObject;
};
#define DECLARE_SLOTS_JObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

} }
namespace avmplus {

class shell_toplevelClassManifest : public avmplus::ClassManifestBase
{
    friend class avmplus::AvmCore;
    friend class avmplus::IntVectorClass;
    friend class avmplus::UIntVectorClass;
    friend class avmplus::DoubleVectorClass;
    friend class avmplus::ObjectVectorClass;
private:
    REALLY_INLINE shell_toplevelClassManifest(avmplus::ScriptEnv* e) : ClassManifestBase(48, e) { }
    REALLY_INLINE static shell_toplevelClassManifest* create(avmplus::ScriptEnv* e) { return new (MMgc::GC::GetGC(e), MMgc::kExact, sizeof(ClassClosure*)*47) shell_toplevelClassManifest(e); }
public:
    REALLY_INLINE GCRef<avmshell::AbstractBaseClass> get_AbstractBaseClass() { return (avmshell::AbstractBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_AbstractBase)); }
    REALLY_INLINE GCRef<avmshell::AbstractRestrictedBaseClass> get_AbstractRestrictedBaseClass() { return (avmshell::AbstractRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_AbstractRestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::CTestClass> get_CTestClass() { return (avmplus::CTestClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_CTest)); }
    REALLY_INLINE GCRef<avmplus::CapabilitiesClass> get_CapabilitiesClass() { return (avmplus::CapabilitiesClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_Capabilities)); }
    REALLY_INLINE GCRef<avmshell::CheckBaseClass> get_CheckBaseClass() { return (avmshell::CheckBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_CheckBase)); }
    REALLY_INLINE GCRef<avmplus::ClassFactoryClass> get_ClassFactoryClass() { return (avmplus::ClassFactoryClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_ClassFactory)); }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleClass> get_DeleteObjectSampleClass() { return (avmplus::DeleteObjectSampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_DeleteObjectSample)); }
    REALLY_INLINE GCRef<avmplus::DictionaryClass> get_DictionaryClass() { return (avmplus::DictionaryClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_Dictionary)); }
    REALLY_INLINE GCRef<avmplus::DomainClass> get_DomainClass() { return (avmplus::DomainClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_Domain)); }
    REALLY_INLINE GCRef<avmplus::EndianClass> get_EndianClass() { return (avmplus::EndianClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_Endian)); }
    REALLY_INLINE GCRef<avmshell::FileClass> get_FileClass() { return (avmshell::FileClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_File)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_ITestClass() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_ITest)); }
    REALLY_INLINE GCRef<avmplus::JObjectClass> get_JObjectClass() { return (avmplus::JObjectClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_JObject)); }
    REALLY_INLINE GCRef<avmshell::MIClass> get_MIClass() { return (avmshell::MIClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_MI)); }
    REALLY_INLINE GCRef<avmplus::NativeBaseAS3Class> get_NativeBaseAS3Class() { return (avmplus::NativeBaseAS3Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeBaseAS3)); }
    REALLY_INLINE GCRef<avmshell::NativeBaseClass> get_NativeBaseClass() { return (avmshell::NativeBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeBase)); }
    REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractBaseClass> get_NativeSubclassOfAbstractBaseClass() { return (avmshell::NativeSubclassOfAbstractBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeSubclassOfAbstractBase)); }
    REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseClass> get_NativeSubclassOfAbstractRestrictedBaseClass() { return (avmshell::NativeSubclassOfAbstractRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeSubclassOfAbstractRestrictedBase)); }
    REALLY_INLINE GCRef<avmshell::NativeSubclassOfRestrictedBaseClass> get_NativeSubclassOfRestrictedBaseClass() { return (avmshell::NativeSubclassOfRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeSubclassOfRestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::NewObjectSampleClass> get_NewObjectSampleClass() { return (avmplus::NewObjectSampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_NewObjectSample)); }
    REALLY_INLINE GCRef<avmshell::RestrictedBaseClass> get_RestrictedBaseClass() { return (avmshell::RestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_RestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::SampleClass> get_SampleClass() { return (avmplus::SampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_Sample)); }
    REALLY_INLINE GCRef<avmplus::StackFrameClass> get_StackFrameClass() { return (avmplus::StackFrameClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_StackFrame)); }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractBaseClass> get_SubclassOfAbstractBaseClass() { return (avmplus::SubclassOfAbstractBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_SubclassOfAbstractBase)); }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractRestrictedBaseClass> get_SubclassOfAbstractRestrictedBaseClass() { return (avmplus::SubclassOfAbstractRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_SubclassOfAbstractRestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::SubclassOfRestrictedBaseClass> get_SubclassOfRestrictedBaseClass() { return (avmplus::SubclassOfRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_SubclassOfRestrictedBase)); }
    REALLY_INLINE GCRef<avmshell::SystemClass> get_SystemClass() { return (avmshell::SystemClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_System)); }
    REALLY_INLINE GCRef<avmplus::TraceClass> get_TraceClass() { return (avmplus::TraceClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_trace_Trace)); }
    REALLY_INLINE GCRef<avmplus::public_classClass> get_public_classClass() { return (avmplus::public_classClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class)); }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0Class> get_public_class_AIR_1_0Class() { return (avmplus::public_class_AIR_1_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_AIR_1_0)); }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_0_FP_10_0Class> get_public_class_AIR_1_0_FP_10_0Class() { return (avmplus::public_class_AIR_1_0_FP_10_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_AIR_1_0_FP_10_0)); }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5Class> get_public_class_AIR_1_5Class() { return (avmplus::public_class_AIR_1_5Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_AIR_1_5)); }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1Class> get_public_class_AIR_1_5_1Class() { return (avmplus::public_class_AIR_1_5_1Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_AIR_1_5_1)); }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class> get_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class() { return (avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2)); }
    REALLY_INLINE GCRef<avmplus::public_class_AIR_1_5_2Class> get_public_class_AIR_1_5_2Class() { return (avmplus::public_class_AIR_1_5_2Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_AIR_1_5_2)); }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0Class> get_public_class_FP_10_0Class() { return (avmplus::public_class_FP_10_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_FP_10_0)); }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32Class> get_public_class_FP_10_0_32Class() { return (avmplus::public_class_FP_10_0_32Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_FP_10_0_32)); }
    REALLY_INLINE GCRef<avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class> get_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class() { return (avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_class_FP_10_0_32_AIR_1_0_FP_10_0)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interfaceClass() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_AIR_1_0Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_0)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_AIR_1_0_FP_10_0Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_0_FP_10_0)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_AIR_1_5Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_AIR_1_5_1Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5_1)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_AIR_1_5_2Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5_2)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_FP_10_0Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_FP_10_0)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_FP_10_0_32Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_FP_10_0_32)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_public_interface_FP_10_0_32_AIR_1_0_FP_10_0Class() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_FP_10_0_32_AIR_1_0_FP_10_0)); }
};
}
#endif // _H_nativegen_header_shell_toplevel
