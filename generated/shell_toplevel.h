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
    class ByteArrayObject; // flash.utils::ByteArray
    class CTestClass; // avmplus::CTest$
    class CTestObject; // avmplus::CTest
    class CapabilitiesClass; // flash.system::Capabilities$
    class CapabilitiesObject; // flash.system::Capabilities
    class ClassClosure; // Class
    class ClassFactoryClass; // flash.sampler::ClassFactory$
    class ClassFactoryObject; // flash.sampler::ClassFactory
    class DeleteObjectSampleClass; // flash.sampler::DeleteObjectSample$
    class DeleteObjectSampleObject; // flash.sampler::DeleteObjectSample
    class DictionaryObject; // flash.utils::Dictionary
    class DomainClass; // avmplus::Domain$
    class DomainObject; // avmplus::Domain
    class EndianClass; // flash.utils::Endian$
    class EndianObject; // flash.utils::Endian
    class FileObject; // avmplus::File
    class ITestClass; // avmplus::ITest$
    class ITestInterface; // avmplus::ITest
    class NativeBaseAS3Class; // avmshell::NativeBaseAS3$
    class NativeBaseAS3Object; // avmshell::NativeBaseAS3
    class NativeBaseExtender1Class; // avmshell::NativeBaseExtender1$
    class NativeBaseExtender1Object; // avmshell::NativeBaseExtender1
    class NativeBaseExtender2Class; // avmshell::NativeBaseExtender2$
    class NativeBaseExtender2Object; // avmshell::NativeBaseExtender2
    class NewObjectSampleClass; // flash.sampler::NewObjectSample$
    class NewObjectSampleObject; // flash.sampler::NewObjectSample
    class ObjectVectorObject; // __AS3__.vec::Vector$object
    class PromiseChannelObject; // flash.system::PromiseChannel
    class PromiseClass; // flash.system::Promise$
    class PromiseHelperClass; // flash.system::PromiseHelper$
    class PromiseHelperObject; // flash.system::PromiseHelper
    class PromiseObject; // flash.system::Promise
    class PromiseStateClass; // flash.system::PromiseState$
    class PromiseStateObject; // flash.system::PromiseState
    class RemoteProxyClass; // flash.system::RemoteProxy$
    class RemoteProxyObject; // flash.system::RemoteProxy
    class SampleClass; // flash.sampler::Sample$
    class SampleObject; // flash.sampler::Sample
    class ShellCoreFriend1Class; // avmshell::ShellCoreFriend1$
    class ShellCoreFriend1Object; // avmshell::ShellCoreFriend1
    class ShellCoreFriend2Class; // avmshell::ShellCoreFriend2$
    class ShellCoreFriend2Object; // avmshell::ShellCoreFriend2
    class StackFrameClass; // flash.sampler::StackFrame$
    class StackFrameObject; // flash.sampler::StackFrame
    class String; // String
    class SubclassOfAbstractBaseClass; // avmshell::SubclassOfAbstractBase$
    class SubclassOfAbstractBaseObject; // avmshell::SubclassOfAbstractBase
    class SubclassOfAbstractRestrictedBaseClass; // avmshell::SubclassOfAbstractRestrictedBase$
    class SubclassOfAbstractRestrictedBaseObject; // avmshell::SubclassOfAbstractRestrictedBase
    class SubclassOfRestrictedBaseClass; // avmshell::SubclassOfRestrictedBase$
    class SubclassOfRestrictedBaseObject; // avmshell::SubclassOfRestrictedBase
    class SystemObject; // avmplus::System
    class TraceClass; // flash.trace::Trace$
    class TraceObject; // flash.trace::Trace
    class WorkerEventClass; // flash.system::WorkerEvent$
    class WorkerEventObject; // flash.system::WorkerEvent
    class WorkerStateClass; // flash.system::WorkerState$
    class WorkerStateObject; // flash.system::WorkerState
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
    class public_interfaceClass; // avmshell::public_interface$
    class public_interfaceInterface; // avmshell::public_interface
    class public_interface_AIR_1_0Class; // avmshell::public_interface_AIR_1_0$
    class public_interface_AIR_1_0Interface; // avmshell::public_interface_AIR_1_0
    class public_interface_AIR_1_0_FP_10_0Class; // avmshell::public_interface_AIR_1_0_FP_10_0$
    class public_interface_AIR_1_0_FP_10_0Interface; // avmshell::public_interface_AIR_1_0_FP_10_0
    class public_interface_AIR_1_5Class; // avmshell::public_interface_AIR_1_5$
    class public_interface_AIR_1_5Interface; // avmshell::public_interface_AIR_1_5
    class public_interface_AIR_1_5_1Class; // avmshell::public_interface_AIR_1_5_1$
    class public_interface_AIR_1_5_1Interface; // avmshell::public_interface_AIR_1_5_1
    class public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2Class; // avmshell::public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2$
    class public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2Interface; // avmshell::public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2
    class public_interface_AIR_1_5_2Class; // avmshell::public_interface_AIR_1_5_2$
    class public_interface_AIR_1_5_2Interface; // avmshell::public_interface_AIR_1_5_2
    class public_interface_FP_10_0Class; // avmshell::public_interface_FP_10_0$
    class public_interface_FP_10_0Interface; // avmshell::public_interface_FP_10_0
    class public_interface_FP_10_0_32Class; // avmshell::public_interface_FP_10_0_32$
    class public_interface_FP_10_0_32Interface; // avmshell::public_interface_FP_10_0_32
    class public_interface_FP_10_0_32_AIR_1_0_FP_10_0Class; // avmshell::public_interface_FP_10_0_32_AIR_1_0_FP_10_0$
    class public_interface_FP_10_0_32_AIR_1_0_FP_10_0Interface; // avmshell::public_interface_FP_10_0_32_AIR_1_0_FP_10_0
}

namespace avmshell {
    class AbstractBaseClass; // avmshell::AbstractBase$
    class AbstractBaseObject; // avmshell::AbstractBase
    class AbstractRestrictedBaseClass; // avmshell::AbstractRestrictedBase$
    class AbstractRestrictedBaseObject; // avmshell::AbstractRestrictedBase
    class CheckBaseClass; // avmshell::CheckBase$
    class CheckBaseObject; // avmshell::CheckBase
    class EnvelopeClass; // flash.system::Envelope$
    class EnvelopeObject; // flash.system::Envelope
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
    class ShellWorkerClass; // flash.system::Worker$
    class ShellWorkerDomainClass; // flash.system::WorkerDomain$
    class ShellWorkerDomainObject; // flash.system::WorkerDomain
    class ShellWorkerObject; // flash.system::Worker
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
const uint32_t abcclass_avmshell_ShellCoreFriend1 = 11;
const uint32_t abcclass_avmshell_ShellCoreFriend2 = 12;
const uint32_t abcclass_flash_system_Capabilities = 13;
const uint32_t abcclass_avmshell_public_class = 14;
const uint32_t abcclass_avmshell_public_class_AIR_1_0 = 15;
const uint32_t abcclass_avmshell_public_class_FP_10_0 = 16;
const uint32_t abcclass_avmshell_public_class_AIR_1_5 = 17;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1 = 18;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32 = 19;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_2 = 20;
const uint32_t abcclass_avmshell_public_class_AIR_1_0_FP_10_0 = 21;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 22;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32_AIR_1_0_FP_10_0 = 23;
const uint32_t abcclass_avmshell_public_interface = 24;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0 = 25;
const uint32_t abcclass_avmshell_public_interface_FP_10_0 = 26;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5 = 27;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1 = 28;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32 = 29;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_2 = 30;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0_FP_10_0 = 31;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 32;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32_AIR_1_0_FP_10_0 = 33;
const uint32_t abcclass_avmshell_NativeSubclassOfAbstractBase = 34;
const uint32_t abcclass_avmshell_SubclassOfAbstractBase = 35;
const uint32_t abcclass_avmshell_NativeSubclassOfRestrictedBase = 36;
const uint32_t abcclass_avmshell_SubclassOfRestrictedBase = 37;
const uint32_t abcclass_avmshell_NativeSubclassOfAbstractRestrictedBase = 38;
const uint32_t abcclass_avmshell_SubclassOfAbstractRestrictedBase = 39;
const uint32_t abcclass_avmshell_NativeBaseExtender1 = 40;
const uint32_t abcclass_avmshell_NativeBaseExtender2 = 41;
const uint32_t abcclass_avmplus_Domain = 42;
const uint32_t abcclass_flash_sampler_StackFrame = 43;
const uint32_t abcclass_flash_sampler_Sample = 44;
const uint32_t abcclass_flash_sampler_ClassFactory = 45;
const uint32_t abcclass_flash_sampler_NewObjectSample = 46;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 47;
const uint32_t abcclass_flash_trace_Trace = 48;
const uint32_t abcclass_flash_utils_Endian = 49;
const uint32_t abcclass_flash_system_WorkerState = 50;
const uint32_t abcclass_flash_system_Worker = 51;
const uint32_t abcclass_flash_system_WorkerEvent = 52;
const uint32_t abcclass_flash_system_WorkerDomain = 53;
const uint32_t abcclass_flash_system_PromiseState = 54;
const uint32_t abcclass_flash_system_PromiseHelper = 55;
const uint32_t abcclass_flash_system_Promise = 56;
const uint32_t abcclass_flash_system_RemoteProxy = 57;
const uint32_t abcclass_flash_system_Envelope = 58;

/* methods */
const uint32_t avmplus_ITest_avmplus_ITest_test = 38; // abc
const uint32_t avmplus_CTest_test = 41; // abc
const uint32_t avmplus_MI_plus = 44; // native
const uint32_t avmplus_System_exit = 47; // native
const uint32_t avmplus_System_exec = 48; // native
const uint32_t avmplus_System_sleep = 49; // native
const uint32_t avmplus_System_getAvmplusVersion = 50; // native
const uint32_t avmplus_System_getFeatures = 51; // native
const uint32_t avmplus_System_getRunmode = 52; // native
const uint32_t avmplus_System_trace = 53; // native
const uint32_t avmplus_System_write = 54; // native
const uint32_t avmplus_System_debugger = 55; // native
const uint32_t avmplus_System_isDebugger = 56; // native
const uint32_t avmplus_System_getNanosecondTimer = 57; // native
const uint32_t avmplus_System_getTimer = 58; // native
const uint32_t avmplus_System_private_getArgv = 59; // native
const uint32_t avmplus_System_readLine = 60; // native
const uint32_t avmplus_System_totalMemory_get = 61; // native
const uint32_t avmplus_System_freeMemory_get = 62; // native
const uint32_t avmplus_System_privateMemory_get = 63; // native
const uint32_t avmplus_System_forceFullCollection = 64; // native
const uint32_t avmplus_System_queueCollection = 65; // native
const uint32_t avmplus_System_ns_example_nstest = 66; // native
const uint32_t avmplus_System_isGlobal = 67; // native
const uint32_t avmplus_System_swfVersion_get = 68; // native
const uint32_t avmplus_System_apiVersion_get = 69; // native
const uint32_t avmplus_System_disposeXML = 70; // native
const uint32_t avmplus_System_deopt = 71; // native
const uint32_t avmplus_System_pauseForGCIfCollectionImminent = 72; // native
const uint32_t avmplus_System_is64bit = 73; // native
const uint32_t avmplus_System_copy = 74; // native
const uint32_t avmplus_System_isIntptr = 75; // native
const uint32_t avmplus_System_runInSafepoint = 76; // native
const uint32_t avmplus_System_canonicalizeNumber = 77; // native
const uint32_t avmplus_File_exists = 80; // native
const uint32_t avmplus_File_read = 81; // native
const uint32_t avmplus_File_write = 82; // native
const uint32_t avmplus_File_readByteArray = 83; // native
const uint32_t avmplus_File_writeByteArray = 84; // native
const uint32_t flash_system_Capabilities_playerType_get = 103; // abc
const uint32_t flash_system_Capabilities_isDebugger_get = 104; // abc
const uint32_t avmshell_public_class_public_function = 107; // abc
const uint32_t avmshell_public_class_public_function_AIR_1_0 = 108; // abc
const uint32_t avmshell_public_class_public_function_FP_10_0 = 109; // abc
const uint32_t avmshell_public_class_public_function_AIR_1_5 = 110; // abc
const uint32_t avmshell_public_class_public_function_AIR_1_5_1 = 111; // abc
const uint32_t avmshell_public_class_public_function_FP_10_0_32 = 112; // abc
const uint32_t avmshell_public_class_public_function_AIR_1_5_2 = 113; // abc
const uint32_t avmshell_public_class_public_function_AIR_1_0_FP_10_0 = 114; // abc
const uint32_t avmshell_public_class_public_function_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 115; // abc
const uint32_t avmshell_public_class_public_function_FP_10_0_32_AIR_1_0_FP_10_0 = 116; // abc
const uint32_t avmshell_public_class_public_getset_get = 117; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_0_get = 118; // abc
const uint32_t avmshell_public_class_public_getset_FP_10_0_get = 119; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_get = 120; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_1_get = 121; // abc
const uint32_t avmshell_public_class_public_getset_FP_10_0_32_get = 122; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_2_get = 123; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_0_FP_10_0_get = 124; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2_get = 125; // abc
const uint32_t avmshell_public_class_public_getset_FP_10_0_32_AIR_1_0_FP_10_0_get = 126; // abc
const uint32_t avmshell_public_class_public_getset_set = 127; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_0_set = 128; // abc
const uint32_t avmshell_public_class_public_getset_FP_10_0_set = 129; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_set = 130; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_1_set = 131; // abc
const uint32_t avmshell_public_class_public_getset_FP_10_0_32_set = 132; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_2_set = 133; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_0_FP_10_0_set = 134; // abc
const uint32_t avmshell_public_class_public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2_set = 135; // abc
const uint32_t avmshell_public_class_public_getset_FP_10_0_32_AIR_1_0_FP_10_0_set = 136; // abc
const uint32_t avmplus_Domain_currentDomain_get = 194; // native
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 195; // native
const uint32_t avmplus_Domain_private_init = 196; // native
const uint32_t avmplus_Domain_loadBytes = 198; // native
const uint32_t avmplus_Domain_getClass = 199; // native
const uint32_t avmplus_Domain_load = 200; // abc
const uint32_t avmplus_Domain_domainMemory_get = 201; // native
const uint32_t avmplus_Domain_domainMemory_set = 202; // native
const uint32_t native_script_function_flash_sampler_getMasterString = 204; // native
const uint32_t native_script_function_flash_sampler_getSavedThis = 205; // native
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 206; // native
const uint32_t native_script_function_flash_sampler_isGetterSetter = 207; // native
const uint32_t native_script_function_flash_sampler__getInvocationCount = 208; // native
const uint32_t native_script_function_flash_sampler_getSampleCount = 212; // native
const uint32_t native_script_function_flash_sampler__getSamples = 213; // native
const uint32_t native_script_function_flash_sampler_getMemberNames = 215; // native
const uint32_t native_script_function_flash_sampler_getSize = 216; // native
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 217; // native
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 220; // native
const uint32_t native_script_function_flash_sampler_pauseSampling = 221; // native
const uint32_t native_script_function_flash_sampler_stopSampling = 222; // native
const uint32_t native_script_function_flash_sampler_startSampling = 223; // native
const uint32_t native_script_function_flash_sampler_clearSamples = 224; // native
const uint32_t flash_sampler_StackFrame_toString = 226; // abc
const uint32_t flash_sampler_NewObjectSample_object_get = 233; // native
const uint32_t flash_sampler_NewObjectSample_size_get = 234; // native
const uint32_t flash_trace_Trace_setLevel = 240; // native
const uint32_t flash_trace_Trace_getLevel = 241; // native
const uint32_t flash_trace_Trace_setListener = 242; // native
const uint32_t flash_trace_Trace_getListener = 243; // native
const uint32_t flash_system_WorkerState_code = 250; // abc
const uint32_t flash_system_Worker_current_get = 253; // abc
const uint32_t flash_system_Worker_handleLifecycleEvents = 254; // abc
const uint32_t flash_system_Worker_pr = 255; // native
const uint32_t flash_system_Worker_state_get = 257; // native
const uint32_t flash_system_Worker_startWithChannels = 258; // native
const uint32_t flash_system_Worker_start = 259; // abc
const uint32_t flash_system_Worker_private_startInternal = 260; // native
const uint32_t flash_system_Worker_isParentOf = 261; // native
const uint32_t flash_system_Worker_isPrimordial_get = 262; // native
const uint32_t flash_system_Worker_private_newEventChannel = 263; // native
const uint32_t flash_system_Worker_setSharedProperty = 264; // native
const uint32_t flash_system_Worker_getSharedProperty = 265; // native
const uint32_t flash_system_Worker_terminate = 266; // native
const uint32_t flash_system_Worker_addEventListener = 267; // abc
const uint32_t flash_system_Worker_private_dispatchEvent = 268; // abc
const uint32_t flash_system_Worker_descriptor_get = 269; // native
const uint32_t flash_system_WorkerEvent_currentState_get = 272; // abc
const uint32_t flash_system_WorkerEvent_previousState_get = 273; // abc
const uint32_t flash_system_WorkerEvent_target_get = 274; // abc
const uint32_t flash_system_WorkerDomain_current_get = 277; // abc
const uint32_t flash_system_WorkerDomain_createWorkerFromByteArray = 279; // abc
const uint32_t flash_system_WorkerDomain_createWorkerFromPrimordial = 280; // abc
const uint32_t flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal = 281; // native
const uint32_t flash_system_WorkerDomain_listWorkers = 282; // native
const uint32_t flash_system_PromiseHelper_currentGiid_get = 287; // native
const uint32_t flash_system_PromiseHelper_getPromiseOwnerGiid = 288; // native
const uint32_t flash_system_PromiseHelper_setPromiseOwnerGiid = 289; // native
const uint32_t flash_system_PromiseHelper_getPromiseGid = 290; // native
const uint32_t flash_system_PromiseHelper_setPromiseGid = 291; // native
const uint32_t flash_system_PromiseHelper_isPromiseEmpty = 292; // native
const uint32_t flash_system_PromiseHelper_schedulePromiseCollection = 293; // native
const uint32_t flash_system_PromiseHelper_retargetIncChannel = 294; // native
const uint32_t flash_system_PromiseHelper_retargetOutChannel = 295; // native
const uint32_t flash_system_PromiseHelper_isPromiseCreatedLocally = 296; // abc
const uint32_t flash_system_PromiseHelper_flash_system_waitForAnySend = 297; // native
const uint32_t flash_system_PromiseHelper_pr = 298; // native
const uint32_t flash_system_PromiseHelper_praddr = 299; // native
const uint32_t flash_system_PromiseHelper_breakOn = 300; // native
const uint32_t flash_system_Promise_wrap = 303; // abc
const uint32_t flash_system_Promise_empty = 304; // abc
const uint32_t flash_system_Promise_private_resolveLocal = 305; // abc
const uint32_t flash_system_Promise_registerEmptyPromise = 306; // native
const uint32_t flash_system_Promise_private_printEmptyPromises = 307; // native
const uint32_t flash_system_Promise_private_create = 308; // native
const uint32_t flash_system_Promise_private_createLocal = 309; // native
const uint32_t flash_system_Promise_notifyOwner = 310; // native
const uint32_t flash_system_Promise_private_notifyEmptyOwners = 311; // native
const uint32_t flash_system_Promise_isOwnedLocally = 312; // native
const uint32_t flash_system_Promise_private_callProperty = 313; // abc
const uint32_t flash_system_Promise_private_getProperty = 314; // abc
const uint32_t flash_system_Promise_async_get = 315; // abc
const uint32_t flash_system_Promise_resolve = 316; // abc
const uint32_t flash_system_Promise_when = 319; // abc
const uint32_t flash_system_Promise_receive = 320; // abc
const uint32_t flash_system_Promise_delayCollection = 321; // native
const uint32_t flash_system_Promise_state_get = 322; // abc
const uint32_t flash_system_Promise_getPID = 323; // abc
const uint32_t flash_system_RemoteProxy_create = 326; // native
const uint32_t flash_system_RemoteProxy_m_workerClass_get = 327; // native
const uint32_t flash_system_RemoteProxy_callProp = 328; // native
const uint32_t flash_system_RemoteProxy_getProp = 329; // native
const uint32_t flash_system_RemoteProxy_checkForCallRequestsConditional = 330; // abc
const uint32_t flash_system_RemoteProxy_checkForCallRequests = 331; // abc
const uint32_t flash_system_RemoteProxy_triggerDelayedCollection = 332; // native
const uint32_t flash_system_RemoteProxy_handleResolution = 333; // abc
const uint32_t flash_system_RemoteProxy_handleCallback = 334; // abc
const uint32_t flash_system_RemoteProxy_private_flattenPromise = 335; // abc
const uint32_t flash_system_RemoteProxy_handleCall = 336; // abc
const uint32_t flash_system_RemoteProxy_handleGetProp = 337; // abc
const uint32_t flash_system_Envelope_name_get = 341; // native

extern avmplus::Atom avmplus_Domain_currentDomain_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_currentDomain_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_private_init_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_loadBytes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_getClass_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_domainMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_domainMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_Domain_domainMemory_set_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_sampler_NewObjectSample_object_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_sampler_NewObjectSample_object_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double flash_sampler_NewObjectSample_size_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double flash_sampler_NewObjectSample_size_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_clearSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_clearSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_startSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_startSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_stopSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_stopSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_pauseSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_pauseSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSize_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMemberNames_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__getSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSampleCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSampleCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler__getInvocationCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_isGetterSetter_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getSavedThis_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMasterString_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_pr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_pr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_state_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_state_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_startWithChannels_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_startWithChannels_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_private_startInternal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_private_startInternal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isParentOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isParentOf_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isPrimordial_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isPrimordial_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_private_newEventChannel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_private_newEventChannel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_setSharedProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_setSharedProperty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_getSharedProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_getSharedProperty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_terminate_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_terminate_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_descriptor_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_descriptor_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_listWorkers_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_listWorkers_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_currentGiid_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_currentGiid_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_getPromiseOwnerGiid_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_getPromiseOwnerGiid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_setPromiseOwnerGiid_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_setPromiseOwnerGiid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_getPromiseGid_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_getPromiseGid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_setPromiseGid_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_setPromiseGid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_isPromiseEmpty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_isPromiseEmpty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_schedulePromiseCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_schedulePromiseCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_retargetIncChannel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_retargetIncChannel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_retargetOutChannel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_retargetOutChannel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_flash_system_waitForAnySend_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_flash_system_waitForAnySend_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_pr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_pr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_praddr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_praddr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_breakOn_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_PromiseHelper_breakOn_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_registerEmptyPromise_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_registerEmptyPromise_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_printEmptyPromises_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_printEmptyPromises_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_create_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_createLocal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_createLocal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_notifyOwner_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_notifyOwner_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_notifyEmptyOwners_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_private_notifyEmptyOwners_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_isOwnedLocally_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_isOwnedLocally_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_delayCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Promise_delayCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_create_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_m_workerClass_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_m_workerClass_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_callProp_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_callProp_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_getProp_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_getProp_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_triggerDelayedCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_RemoteProxy_triggerDelayedCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Envelope_name_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Envelope_name_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_MI_plus_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_MI_plus_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_exit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_exec_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_sleep_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_sleep_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getAvmplusVersion_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getAvmplusVersion_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getFeatures_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getFeatures_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getRunmode_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getRunmode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_trace_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_debugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_debugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isDebugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isDebugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_getNanosecondTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_getNanosecondTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_getTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_private_getArgv_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_private_getArgv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_readLine_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_readLine_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_totalMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_totalMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_freeMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_freeMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_privateMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double avmplus_System_privateMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_forceFullCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_forceFullCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_queueCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_queueCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_ns_example_nstest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_ns_example_nstest_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isGlobal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_swfVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_swfVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_apiVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_apiVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_disposeXML_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_deopt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_deopt_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_pauseForGCIfCollectionImminent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_pauseForGCIfCollectionImminent_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_is64bit_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_is64bit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_copy_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_copy_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isIntptr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_isIntptr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_runInSafepoint_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_runInSafepoint_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_canonicalizeNumber_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_System_canonicalizeNumber_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_exists_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_read_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_readByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom avmplus_File_writeByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
class SlotOffsetsAndAsserts;
//-----------------------------------------------------------
// avmplus::CTest$
//-----------------------------------------------------------
class avmplus_CTestClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CTestClass;
#define GC_TRIVIAL_TRACER_CTestClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::CTest
//-----------------------------------------------------------
class avmplus_CTestObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CTestObject;
#define GC_TRIVIAL_TRACER_CTestObject
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
        inline GCRef<avmshell::MIObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::MIObject>((avmshell::MIObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::MIObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::MIObject>((avmshell::MIObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::MIObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::MIObject>((avmshell::MIObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::MIObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::MIObject>((avmshell::MIObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::MIObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::MIObject>((avmshell::MIObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_argv;
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
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::SystemObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SystemObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SystemObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SystemObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::ArrayObject* get_argv() const { return m_slots_SystemClass.m_argv; } \
        REALLY_INLINE void setconst_argv(avmplus::ArrayObject* newVal) { m_slots_SystemClass.m_argv = newVal; } \
    private: \
        avmplus::NativeID::avmshell_SystemClassSlots m_slots_SystemClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::System
//-----------------------------------------------------------
class avmplus_SystemObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SystemObject;
#define GC_TRIVIAL_TRACER_SystemObject
};
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
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::FileObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::FileObject>((avmplus::FileObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FileObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::FileObject>((avmplus::FileObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FileObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::FileObject>((avmplus::FileObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FileObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::FileObject>((avmplus::FileObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// avmplus::File
//-----------------------------------------------------------
class avmplus_FileObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::FileObject;
#define GC_TRIVIAL_TRACER_FileObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::AbstractBase$
//-----------------------------------------------------------
class avmshell_AbstractBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::AbstractBaseClass;
#define GC_TRIVIAL_TRACER_AbstractBaseClass
};
#define DECLARE_SLOTS_AbstractBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::AbstractBaseObject>((avmshell::AbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::AbstractBaseObject>((avmshell::AbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::AbstractBaseObject>((avmshell::AbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::AbstractBaseObject>((avmshell::AbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
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
#define GC_TRIVIAL_TRACER_AbstractBaseObject
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
#define GC_TRIVIAL_TRACER_RestrictedBaseClass
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
        inline GCRef<avmshell::RestrictedBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::RestrictedBaseObject>((avmshell::RestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::RestrictedBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::RestrictedBaseObject>((avmshell::RestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::RestrictedBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::RestrictedBaseObject>((avmshell::RestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::RestrictedBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::RestrictedBaseObject>((avmshell::RestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::RestrictedBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::RestrictedBaseObject>((avmshell::RestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
#define GC_TRIVIAL_TRACER_RestrictedBaseObject
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
#define GC_TRIVIAL_TRACER_AbstractRestrictedBaseClass
};
#define DECLARE_SLOTS_AbstractRestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractRestrictedBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::AbstractRestrictedBaseObject>((avmshell::AbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractRestrictedBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::AbstractRestrictedBaseObject>((avmshell::AbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractRestrictedBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::AbstractRestrictedBaseObject>((avmshell::AbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::AbstractRestrictedBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::AbstractRestrictedBaseObject>((avmshell::AbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
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
#define GC_TRIVIAL_TRACER_AbstractRestrictedBaseObject
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
#define GC_TRIVIAL_TRACER_CheckBaseClass
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
        inline GCRef<avmshell::CheckBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::CheckBaseObject>((avmshell::CheckBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::CheckBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::CheckBaseObject>((avmshell::CheckBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::CheckBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::CheckBaseObject>((avmshell::CheckBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::CheckBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::CheckBaseObject>((avmshell::CheckBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::CheckBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::CheckBaseObject>((avmshell::CheckBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
#define GC_TRIVIAL_TRACER_CheckBaseObject
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
#define GC_TRIVIAL_TRACER_NativeBaseClass
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
        inline GCRef<avmshell::NativeBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct_native(avmshell::NativeBaseClass::createInstanceProc, 0, args); \
            return GCRef<avmshell::NativeBaseObject>((avmshell::NativeBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::NativeBaseObject>((avmshell::NativeBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeBaseObject>((avmshell::NativeBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::NativeBaseObject>((avmshell::NativeBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeBaseObject>((avmshell::NativeBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
#define GC_TRIVIAL_TRACER_NativeBaseObject
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
#define GC_TRIVIAL_TRACER_NativeBaseAS3Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBaseAS3
//-----------------------------------------------------------
class avmplus_NativeBaseAS3ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NativeBaseAS3Object;
#define GC_TRIVIAL_TRACER_NativeBaseAS3Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::ShellCoreFriend1$
//-----------------------------------------------------------
class avmplus_ShellCoreFriend1ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ShellCoreFriend1Class;
private:
    int32_t m_private_foo;
#define GC_TRIVIAL_TRACER_ShellCoreFriend1Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::ShellCoreFriend1
//-----------------------------------------------------------
class avmplus_ShellCoreFriend1ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ShellCoreFriend1Object;
#define GC_TRIVIAL_TRACER_ShellCoreFriend1Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::ShellCoreFriend2$
//-----------------------------------------------------------
class avmplus_ShellCoreFriend2ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ShellCoreFriend2Class;
private:
    int32_t m_private_bar;
#define GC_TRIVIAL_TRACER_ShellCoreFriend2Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::ShellCoreFriend2
//-----------------------------------------------------------
class avmplus_ShellCoreFriend2ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ShellCoreFriend2Object;
#define GC_TRIVIAL_TRACER_ShellCoreFriend2Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Capabilities$
//-----------------------------------------------------------
class avmplus_CapabilitiesClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CapabilitiesClass;
#define GC_TRIVIAL_TRACER_CapabilitiesClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Capabilities
//-----------------------------------------------------------
class avmplus_CapabilitiesObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CapabilitiesObject;
#define GC_TRIVIAL_TRACER_CapabilitiesObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class$
//-----------------------------------------------------------
class avmplus_public_classClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_classClass;
#define GC_TRIVIAL_TRACER_public_classClass
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
    avmplus::bool32 m_public_var;
    avmplus::bool32 m_public_var_AIR_1_0;
    avmplus::bool32 m_public_var_FP_10_0;
    avmplus::bool32 m_public_var_AIR_1_5;
    avmplus::bool32 m_public_var_AIR_1_5_1;
    avmplus::bool32 m_public_var_FP_10_0_32;
    avmplus::bool32 m_public_var_AIR_1_5_2;
    avmplus::bool32 m_public_var_AIR_1_0_FP_10_0;
    avmplus::bool32 m_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2;
    avmplus::bool32 m_public_var_FP_10_0_32_AIR_1_0_FP_10_0;
    avmplus::bool32 m_public_const;
    avmplus::bool32 m_public_const_AIR_1_0;
    avmplus::bool32 m_public_const_FP_10_0;
    avmplus::bool32 m_public_const_AIR_1_5;
    avmplus::bool32 m_public_const_AIR_1_5_1;
    avmplus::bool32 m_public_const_FP_10_0_32;
    avmplus::bool32 m_public_const_AIR_1_5_2;
    avmplus::bool32 m_public_const_AIR_1_0_FP_10_0;
    avmplus::bool32 m_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2;
    avmplus::bool32 m_public_const_FP_10_0_32_AIR_1_0_FP_10_0;
#define GC_TRIVIAL_TRACER_public_classObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0Class;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_0Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0Object;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_0Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0$
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0Class;
#define GC_TRIVIAL_TRACER_public_class_FP_10_0Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0Object;
#define GC_TRIVIAL_TRACER_public_class_FP_10_0Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5Class;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5Object;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1Class;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5_1Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1Object;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5_1Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32$
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32Class;
#define GC_TRIVIAL_TRACER_public_class_FP_10_0_32Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32Object;
#define GC_TRIVIAL_TRACER_public_class_FP_10_0_32Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_2$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_2ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_2Class;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5_2Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_2
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_2ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_2Object;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5_2Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0_FP_10_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0_FP_10_0Class;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_0_FP_10_0Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_0_FP_10_0
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_0_FP_10_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_0_FP_10_0Object;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_0_FP_10_0Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2$
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2
//-----------------------------------------------------------
class avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object;
#define GC_TRIVIAL_TRACER_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0$
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class;
#define GC_TRIVIAL_TRACER_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::public_class_FP_10_0_32_AIR_1_0_FP_10_0
//-----------------------------------------------------------
class avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object;
#define GC_TRIVIAL_TRACER_public_class_FP_10_0_32_AIR_1_0_FP_10_0Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfAbstractBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfAbstractBaseClass;
#define GC_TRIVIAL_TRACER_NativeSubclassOfAbstractBaseClass
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
        inline GCRef<avmshell::NativeSubclassOfAbstractBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::NativeSubclassOfAbstractBaseObject>((avmshell::NativeSubclassOfAbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::NativeSubclassOfAbstractBaseObject>((avmshell::NativeSubclassOfAbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeSubclassOfAbstractBaseObject>((avmshell::NativeSubclassOfAbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::NativeSubclassOfAbstractBaseObject>((avmshell::NativeSubclassOfAbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeSubclassOfAbstractBaseObject>((avmshell::NativeSubclassOfAbstractBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
#define GC_TRIVIAL_TRACER_NativeSubclassOfAbstractBaseObject
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
#define GC_TRIVIAL_TRACER_SubclassOfAbstractBaseClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractBase
//-----------------------------------------------------------
class avmplus_SubclassOfAbstractBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfAbstractBaseObject;
#define GC_TRIVIAL_TRACER_SubclassOfAbstractBaseObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfRestrictedBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfRestrictedBaseClass;
#define GC_TRIVIAL_TRACER_NativeSubclassOfRestrictedBaseClass
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
        inline GCRef<avmshell::NativeSubclassOfRestrictedBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::NativeSubclassOfRestrictedBaseObject>((avmshell::NativeSubclassOfRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfRestrictedBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::NativeSubclassOfRestrictedBaseObject>((avmshell::NativeSubclassOfRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfRestrictedBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeSubclassOfRestrictedBaseObject>((avmshell::NativeSubclassOfRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfRestrictedBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::NativeSubclassOfRestrictedBaseObject>((avmshell::NativeSubclassOfRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfRestrictedBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeSubclassOfRestrictedBaseObject>((avmshell::NativeSubclassOfRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
#define GC_TRIVIAL_TRACER_NativeSubclassOfRestrictedBaseObject
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
#define GC_TRIVIAL_TRACER_SubclassOfRestrictedBaseClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfRestrictedBase
//-----------------------------------------------------------
class avmplus_SubclassOfRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfRestrictedBaseObject;
#define GC_TRIVIAL_TRACER_SubclassOfRestrictedBaseObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeSubclassOfAbstractRestrictedBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::NativeSubclassOfAbstractRestrictedBaseClass;
#define GC_TRIVIAL_TRACER_NativeSubclassOfAbstractRestrictedBaseClass
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
        inline GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject>((avmshell::NativeSubclassOfAbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject>((avmshell::NativeSubclassOfAbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject>((avmshell::NativeSubclassOfAbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject>((avmshell::NativeSubclassOfAbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseObject>((avmshell::NativeSubclassOfAbstractRestrictedBaseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
#define GC_TRIVIAL_TRACER_NativeSubclassOfAbstractRestrictedBaseObject
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
#define GC_TRIVIAL_TRACER_SubclassOfAbstractRestrictedBaseClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::SubclassOfAbstractRestrictedBase
//-----------------------------------------------------------
class avmplus_SubclassOfAbstractRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SubclassOfAbstractRestrictedBaseObject;
#define GC_TRIVIAL_TRACER_SubclassOfAbstractRestrictedBaseObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBaseExtender1$
//-----------------------------------------------------------
class avmplus_NativeBaseExtender1ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NativeBaseExtender1Class;
#define GC_TRIVIAL_TRACER_NativeBaseExtender1Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBaseExtender1
//-----------------------------------------------------------
class avmplus_NativeBaseExtender1ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NativeBaseExtender1Object;
private:
    int32_t m_private_foo;
#define GC_TRIVIAL_TRACER_NativeBaseExtender1Object
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBaseExtender2$
//-----------------------------------------------------------
class avmplus_NativeBaseExtender2ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NativeBaseExtender2Class;
#define GC_TRIVIAL_TRACER_NativeBaseExtender2Class
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// avmshell::NativeBaseExtender2
//-----------------------------------------------------------
class avmplus_NativeBaseExtender2ObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NativeBaseExtender2Object;
private:
    int32_t m_private_foo;
    int32_t m_private_foo1;
    int32_t m_private_foo2;
#define GC_TRIVIAL_TRACER_NativeBaseExtender2Object
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
        inline GCRef<avmplus::DomainObject> constructObject(GCRef<avmplus::DomainObject> arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
#define GC_TRIVIAL_TRACER_StackFrameClass
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
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_name;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_file;
    double m_scriptID;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_name);
        gc->TraceLocation(&m_file);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::Sample$
//-----------------------------------------------------------
class avmplus_SampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SampleClass;
#define GC_TRIVIAL_TRACER_SampleClass
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
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_stack;
    double m_time;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_stack);
    }
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
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_StackFrameClass;
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_SampleClass;
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_DeleteObjectSampleClass;
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_NewObjectSampleClass;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_StackFrameClass);
        gc->TraceLocation(&m_SampleClass);
        gc->TraceLocation(&m_DeleteObjectSampleClass);
        gc->TraceLocation(&m_NewObjectSampleClass);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::ClassFactory
//-----------------------------------------------------------
class avmplus_ClassFactoryObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ClassFactoryObject;
#define GC_TRIVIAL_TRACER_ClassFactoryObject
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
        inline GCRef<avmplus::NewObjectSampleObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
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
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_type;
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
#define GC_TRIVIAL_TRACER_DeleteObjectSampleClass
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
#define GC_TRIVIAL_TRACER_DeleteObjectSampleObject
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
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
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
// flash.trace::Trace
//-----------------------------------------------------------
class avmplus_TraceObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::TraceObject;
#define GC_TRIVIAL_TRACER_TraceObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Endian$
//-----------------------------------------------------------
class avmplus_EndianClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EndianClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_BIG_ENDIAN;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_LITTLE_ENDIAN;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_BIG_ENDIAN);
        gc->TraceLocation(&m_LITTLE_ENDIAN);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Endian
//-----------------------------------------------------------
class avmplus_EndianObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EndianObject;
#define GC_TRIVIAL_TRACER_EndianObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerState$
//-----------------------------------------------------------
class avmplus_WorkerStateClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerStateClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_NEW;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_RUNNING;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_TERMINATED;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_FAILED;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_ABORTED;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_EXCEPTION;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_NEW);
        gc->TraceLocation(&m_RUNNING);
        gc->TraceLocation(&m_TERMINATED);
        gc->TraceLocation(&m_FAILED);
        gc->TraceLocation(&m_ABORTED);
        gc->TraceLocation(&m_EXCEPTION);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerState
//-----------------------------------------------------------
class avmplus_WorkerStateObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerStateObject;
#define GC_TRIVIAL_TRACER_WorkerStateObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Worker$
//-----------------------------------------------------------
class avmshell_ShellWorkerClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerClass;
private:
    MMgc::GCTraceableObject::GCMember<avmshell::ShellWorkerObject> m_private_m_current;
    MMgc::GCTraceableObject::GCMember<avmplus::DictionaryObject> m_private_m_eventChannels;
};
#define DECLARE_SLOTS_ShellWorkerClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmshell::ShellWorkerObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct_native(avmshell::ShellWorkerClass::createInstanceProc, 0, args); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmshell::ShellWorkerObject* get_m_current() const { return m_slots_ShellWorkerClass.m_private_m_current; } \
        REALLY_INLINE void set_m_current(avmshell::ShellWorkerObject* newVal) { m_slots_ShellWorkerClass.m_private_m_current = newVal; } \
    protected: \
        REALLY_INLINE avmplus::DictionaryObject* get_m_eventChannels() const { return m_slots_ShellWorkerClass.m_private_m_eventChannels; } \
        REALLY_INLINE void set_m_eventChannels(avmplus::DictionaryObject* newVal) { m_slots_ShellWorkerClass.m_private_m_eventChannels = newVal; } \
    private: \
        avmplus::NativeID::avmshell_ShellWorkerClassSlots m_slots_ShellWorkerClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Worker
//-----------------------------------------------------------
class avmshell_ShellWorkerObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::ByteArrayObject> m_private_m_byteCode;
    MMgc::GCTraceableObject::GCMember<avmplus::PromiseChannelObject> m_private_m_eventChannel;
    MMgc::GCTraceableObject::GCMember<avmplus::ObjectVectorObject> m_private_m_listeners;
};
#define DECLARE_SLOTS_ShellWorkerObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::ByteArrayObject* get_m_byteCode() const { return m_slots_ShellWorkerObject.m_private_m_byteCode; } \
        REALLY_INLINE void set_m_byteCode(avmplus::ByteArrayObject* newVal) { m_slots_ShellWorkerObject.m_private_m_byteCode = newVal; } \
    protected: \
        REALLY_INLINE avmplus::PromiseChannelObject* get_m_eventChannel() const { return m_slots_ShellWorkerObject.m_private_m_eventChannel; } \
        REALLY_INLINE void set_m_eventChannel(avmplus::PromiseChannelObject* newVal) { m_slots_ShellWorkerObject.m_private_m_eventChannel = newVal; } \
    protected: \
        REALLY_INLINE avmplus::ObjectVectorObject* get_m_listeners() const { return m_slots_ShellWorkerObject.m_private_m_listeners; } \
        REALLY_INLINE void set_m_listeners(avmplus::ObjectVectorObject* newVal) { m_slots_ShellWorkerObject.m_private_m_listeners = newVal; } \
    private: \
        avmplus::NativeID::avmshell_ShellWorkerObjectSlots m_slots_ShellWorkerObject \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerEvent$
//-----------------------------------------------------------
class avmplus_WorkerEventClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerEventClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_WORKER_STATE;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_WORKER_STATE);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerEvent
//-----------------------------------------------------------
class avmplus_WorkerEventObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerEventObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_private_m_previousState;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_private_m_currentState;
    avmplus::AtomWB m_flash_system_m_target;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_private_m_previousState);
        gc->TraceLocation(&m_private_m_currentState);
        gc->TraceAtom(&m_flash_system_m_target);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerDomain$
//-----------------------------------------------------------
class avmshell_ShellWorkerDomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerDomainClass;
private:
    MMgc::GCTraceableObject::GCMember<avmshell::ShellWorkerDomainObject> m_private_m_current;
};
#define DECLARE_SLOTS_ShellWorkerDomainClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmshell::ShellWorkerDomainObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmshell::ShellWorkerDomainObject* get_m_current() const { return m_slots_ShellWorkerDomainClass.m_private_m_current; } \
        REALLY_INLINE void set_m_current(avmshell::ShellWorkerDomainObject* newVal) { m_slots_ShellWorkerDomainClass.m_private_m_current = newVal; } \
    private: \
        avmplus::NativeID::avmshell_ShellWorkerDomainClassSlots m_slots_ShellWorkerDomainClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerDomain
//-----------------------------------------------------------
class avmshell_ShellWorkerDomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerDomainObject;
};
#define DECLARE_SLOTS_ShellWorkerDomainObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::PromiseState$
//-----------------------------------------------------------
class avmplus_PromiseStateClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::PromiseStateClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_NEW;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_RECEIVED;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_BROKEN;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_EXCEPTION;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_NEW);
        gc->TraceLocation(&m_RECEIVED);
        gc->TraceLocation(&m_BROKEN);
        gc->TraceLocation(&m_EXCEPTION);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::PromiseState
//-----------------------------------------------------------
class avmplus_PromiseStateObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::PromiseStateObject;
#define GC_TRIVIAL_TRACER_PromiseStateObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::PromiseHelper$
//-----------------------------------------------------------
class avmplus_PromiseHelperClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::PromiseHelperClass;
private:
    uint32_t m_CALL_REQUEST;
    uint32_t m_RESOLUTION_REQUEST;
    uint32_t m_CALLBACK_REQUEST;
    uint32_t m_GETPROP_REQUEST;
    uint32_t m_DESTROY_REQUEST;
    uint32_t m_DESTROY_DELAYED_REQUEST;
    uint32_t m_SUCCESS_RESPONSE;
    uint32_t m_EXCEPTION_RESPONSE;
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_m_empty_promises;
    MMgc::GCTraceableObject::GCMember<avmplus::ObjectVectorObject> m_m_local_requests;
    MMgc::GCTraceableObject::GCMember<avmplus::ObjectVectorObject> m_m_delayed_requests;
};
#define DECLARE_SLOTS_PromiseHelperClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::PromiseHelperObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::PromiseHelperObject>((avmplus::PromiseHelperObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseHelperObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::PromiseHelperObject>((avmplus::PromiseHelperObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseHelperObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::PromiseHelperObject>((avmplus::PromiseHelperObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseHelperObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::PromiseHelperObject>((avmplus::PromiseHelperObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseHelperObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::PromiseHelperObject>((avmplus::PromiseHelperObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE uint32_t get_CALL_REQUEST() const { return m_slots_PromiseHelperClass.m_CALL_REQUEST; } \
        REALLY_INLINE void setconst_CALL_REQUEST(uint32_t newVal) { m_slots_PromiseHelperClass.m_CALL_REQUEST = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_RESOLUTION_REQUEST() const { return m_slots_PromiseHelperClass.m_RESOLUTION_REQUEST; } \
        REALLY_INLINE void setconst_RESOLUTION_REQUEST(uint32_t newVal) { m_slots_PromiseHelperClass.m_RESOLUTION_REQUEST = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_CALLBACK_REQUEST() const { return m_slots_PromiseHelperClass.m_CALLBACK_REQUEST; } \
        REALLY_INLINE void setconst_CALLBACK_REQUEST(uint32_t newVal) { m_slots_PromiseHelperClass.m_CALLBACK_REQUEST = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_GETPROP_REQUEST() const { return m_slots_PromiseHelperClass.m_GETPROP_REQUEST; } \
        REALLY_INLINE void setconst_GETPROP_REQUEST(uint32_t newVal) { m_slots_PromiseHelperClass.m_GETPROP_REQUEST = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_DESTROY_REQUEST() const { return m_slots_PromiseHelperClass.m_DESTROY_REQUEST; } \
        REALLY_INLINE void setconst_DESTROY_REQUEST(uint32_t newVal) { m_slots_PromiseHelperClass.m_DESTROY_REQUEST = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_DESTROY_DELAYED_REQUEST() const { return m_slots_PromiseHelperClass.m_DESTROY_DELAYED_REQUEST; } \
        REALLY_INLINE void setconst_DESTROY_DELAYED_REQUEST(uint32_t newVal) { m_slots_PromiseHelperClass.m_DESTROY_DELAYED_REQUEST = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_SUCCESS_RESPONSE() const { return m_slots_PromiseHelperClass.m_SUCCESS_RESPONSE; } \
        REALLY_INLINE void setconst_SUCCESS_RESPONSE(uint32_t newVal) { m_slots_PromiseHelperClass.m_SUCCESS_RESPONSE = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_EXCEPTION_RESPONSE() const { return m_slots_PromiseHelperClass.m_EXCEPTION_RESPONSE; } \
        REALLY_INLINE void setconst_EXCEPTION_RESPONSE(uint32_t newVal) { m_slots_PromiseHelperClass.m_EXCEPTION_RESPONSE = newVal; } \
    public: \
        REALLY_INLINE avmplus::ArrayObject* get_m_empty_promises() const { return m_slots_PromiseHelperClass.m_m_empty_promises; } \
        REALLY_INLINE void set_m_empty_promises(avmplus::ArrayObject* newVal) { m_slots_PromiseHelperClass.m_m_empty_promises = newVal; } \
    public: \
        REALLY_INLINE avmplus::ObjectVectorObject* get_m_local_requests() const { return m_slots_PromiseHelperClass.m_m_local_requests; } \
        REALLY_INLINE void set_m_local_requests(avmplus::ObjectVectorObject* newVal) { m_slots_PromiseHelperClass.m_m_local_requests = newVal; } \
    public: \
        REALLY_INLINE avmplus::ObjectVectorObject* get_m_delayed_requests() const { return m_slots_PromiseHelperClass.m_m_delayed_requests; } \
        REALLY_INLINE void set_m_delayed_requests(avmplus::ObjectVectorObject* newVal) { m_slots_PromiseHelperClass.m_m_delayed_requests = newVal; } \
    private: \
        avmplus::NativeID::avmplus_PromiseHelperClassSlots m_slots_PromiseHelperClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::PromiseHelper
//-----------------------------------------------------------
class avmplus_PromiseHelperObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::PromiseHelperObject;
#define GC_TRIVIAL_TRACER_PromiseHelperObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Promise$
//-----------------------------------------------------------
class avmplus_PromiseClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::PromiseClass;
private:
    uint32_t m_NEW;
    uint32_t m_RECEIVED;
    uint32_t m_BROKEN;
    uint32_t m_EXCEPTION;
    uint32_t m_private_DESTROY_REQUEST;
    uint32_t m_private_DESTROY_DELAYED_REQUEST;
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_private_m_empty_requests;
};
#define DECLARE_SLOTS_PromiseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::PromiseObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct_native(avmplus::PromiseClass::createInstanceProc, 0, args); \
            return GCRef<avmplus::PromiseObject>((avmplus::PromiseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::PromiseObject>((avmplus::PromiseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::PromiseObject>((avmplus::PromiseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::PromiseObject>((avmplus::PromiseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::PromiseObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::PromiseObject>((avmplus::PromiseObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE uint32_t get_NEW() const { return m_slots_PromiseClass.m_NEW; } \
        REALLY_INLINE void setconst_NEW(uint32_t newVal) { m_slots_PromiseClass.m_NEW = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_RECEIVED() const { return m_slots_PromiseClass.m_RECEIVED; } \
        REALLY_INLINE void setconst_RECEIVED(uint32_t newVal) { m_slots_PromiseClass.m_RECEIVED = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_BROKEN() const { return m_slots_PromiseClass.m_BROKEN; } \
        REALLY_INLINE void setconst_BROKEN(uint32_t newVal) { m_slots_PromiseClass.m_BROKEN = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_EXCEPTION() const { return m_slots_PromiseClass.m_EXCEPTION; } \
        REALLY_INLINE void setconst_EXCEPTION(uint32_t newVal) { m_slots_PromiseClass.m_EXCEPTION = newVal; } \
    protected: \
        REALLY_INLINE uint32_t get_DESTROY_REQUEST() const { return m_slots_PromiseClass.m_private_DESTROY_REQUEST; } \
        REALLY_INLINE void setconst_DESTROY_REQUEST(uint32_t newVal) { m_slots_PromiseClass.m_private_DESTROY_REQUEST = newVal; } \
    protected: \
        REALLY_INLINE uint32_t get_DESTROY_DELAYED_REQUEST() const { return m_slots_PromiseClass.m_private_DESTROY_DELAYED_REQUEST; } \
        REALLY_INLINE void setconst_DESTROY_DELAYED_REQUEST(uint32_t newVal) { m_slots_PromiseClass.m_private_DESTROY_DELAYED_REQUEST = newVal; } \
    protected: \
        REALLY_INLINE avmplus::ArrayObject* get_m_empty_requests() const { return m_slots_PromiseClass.m_private_m_empty_requests; } \
        REALLY_INLINE void set_m_empty_requests(avmplus::ArrayObject* newVal) { m_slots_PromiseClass.m_private_m_empty_requests = newVal; } \
    private: \
        avmplus::NativeID::avmplus_PromiseClassSlots m_slots_PromiseClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Promise
//-----------------------------------------------------------
class avmplus_PromiseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::PromiseObject;
private:
    avmplus::bool32 m_private_m_global;
    uint32_t m_flash_system_intern_m_state;
    avmplus::bool32 m_private_m_empty;
    MMgc::GCTraceableObject::GCMember<avmplus::PromiseChannelObject> m_flash_system_m_out;
    MMgc::GCTraceableObject::GCMember<avmplus::PromiseChannelObject> m_flash_system_m_inc;
    avmplus::AtomWB m_flash_system_intern_m_resolved;
    MMgc::GCTraceableObject::GCMember<avmplus::PromiseObject> m_private_m_async;
};
#define DECLARE_SLOTS_PromiseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE bool get_m_global() const { return m_slots_PromiseObject.m_private_m_global != 0; } \
        REALLY_INLINE void set_m_global(avmplus::bool32 newVal) { m_slots_PromiseObject.m_private_m_global = newVal; } \
    protected: \
        REALLY_INLINE uint32_t get_m_state() const { return m_slots_PromiseObject.m_flash_system_intern_m_state; } \
        REALLY_INLINE void set_m_state(uint32_t newVal) { m_slots_PromiseObject.m_flash_system_intern_m_state = newVal; } \
    protected: \
        REALLY_INLINE bool get_m_empty() const { return m_slots_PromiseObject.m_private_m_empty != 0; } \
        REALLY_INLINE void set_m_empty(avmplus::bool32 newVal) { m_slots_PromiseObject.m_private_m_empty = newVal; } \
    protected: \
        REALLY_INLINE avmplus::PromiseChannelObject* get_m_out() const { return m_slots_PromiseObject.m_flash_system_m_out; } \
        REALLY_INLINE void set_m_out(avmplus::PromiseChannelObject* newVal) { m_slots_PromiseObject.m_flash_system_m_out = newVal; } \
    protected: \
        REALLY_INLINE avmplus::PromiseChannelObject* get_m_inc() const { return m_slots_PromiseObject.m_flash_system_m_inc; } \
        REALLY_INLINE void set_m_inc(avmplus::PromiseChannelObject* newVal) { m_slots_PromiseObject.m_flash_system_m_inc = newVal; } \
    protected: \
        REALLY_INLINE avmplus::Atom get_m_resolved() const { return m_slots_PromiseObject.m_flash_system_intern_m_resolved; } \
        REALLY_INLINE void set_m_resolved(avmplus::Atom newVal) { m_slots_PromiseObject.m_flash_system_intern_m_resolved = newVal; } \
    protected: \
        REALLY_INLINE avmplus::PromiseObject* get_m_async() const { return m_slots_PromiseObject.m_private_m_async; } \
        REALLY_INLINE void set_m_async(avmplus::PromiseObject* newVal) { m_slots_PromiseObject.m_private_m_async = newVal; } \
    private: \
        avmplus::NativeID::avmplus_PromiseObjectSlots m_slots_PromiseObject \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::RemoteProxy$
//-----------------------------------------------------------
class avmplus_RemoteProxyClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::RemoteProxyClass;
private:
    uint32_t m_NEW;
    uint32_t m_RECEIVED;
    uint32_t m_BROKEN;
    uint32_t m_EXCEPTION;
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_m_remote_proxies;
};
#define DECLARE_SLOTS_RemoteProxyClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::RemoteProxyObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct_native(avmplus::RemoteProxyClass::createInstanceProc, 0, args); \
            return GCRef<avmplus::RemoteProxyObject>((avmplus::RemoteProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::RemoteProxyObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::RemoteProxyObject>((avmplus::RemoteProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RemoteProxyObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::RemoteProxyObject>((avmplus::RemoteProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RemoteProxyObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::RemoteProxyObject>((avmplus::RemoteProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RemoteProxyObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::RemoteProxyObject>((avmplus::RemoteProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE uint32_t get_NEW() const { return m_slots_RemoteProxyClass.m_NEW; } \
        REALLY_INLINE void setconst_NEW(uint32_t newVal) { m_slots_RemoteProxyClass.m_NEW = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_RECEIVED() const { return m_slots_RemoteProxyClass.m_RECEIVED; } \
        REALLY_INLINE void setconst_RECEIVED(uint32_t newVal) { m_slots_RemoteProxyClass.m_RECEIVED = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_BROKEN() const { return m_slots_RemoteProxyClass.m_BROKEN; } \
        REALLY_INLINE void setconst_BROKEN(uint32_t newVal) { m_slots_RemoteProxyClass.m_BROKEN = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_EXCEPTION() const { return m_slots_RemoteProxyClass.m_EXCEPTION; } \
        REALLY_INLINE void setconst_EXCEPTION(uint32_t newVal) { m_slots_RemoteProxyClass.m_EXCEPTION = newVal; } \
    public: \
        REALLY_INLINE avmplus::ArrayObject* get_m_remote_proxies() const { return m_slots_RemoteProxyClass.m_m_remote_proxies; } \
        REALLY_INLINE void set_m_remote_proxies(avmplus::ArrayObject* newVal) { m_slots_RemoteProxyClass.m_m_remote_proxies = newVal; } \
    private: \
        avmplus::NativeID::avmplus_RemoteProxyClassSlots m_slots_RemoteProxyClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::RemoteProxy
//-----------------------------------------------------------
class avmplus_RemoteProxyObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::RemoteProxyObject;
private:
    uint32_t m_m_gpid;
    avmplus::bool32 m_m_global;
    uint32_t m_m_state;
    MMgc::GCTraceableObject::GCMember<avmplus::PromiseChannelObject> m_m_out;
    MMgc::GCTraceableObject::GCMember<avmplus::PromiseChannelObject> m_m_inc;
    avmplus::AtomWB m_m_resolved;
};
#define DECLARE_SLOTS_RemoteProxyObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE uint32_t get_m_gpid() const { return m_slots_RemoteProxyObject.m_m_gpid; } \
        REALLY_INLINE void set_m_gpid(uint32_t newVal) { m_slots_RemoteProxyObject.m_m_gpid = newVal; } \
    public: \
        REALLY_INLINE bool get_m_global() const { return m_slots_RemoteProxyObject.m_m_global != 0; } \
        REALLY_INLINE void set_m_global(avmplus::bool32 newVal) { m_slots_RemoteProxyObject.m_m_global = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_m_state() const { return m_slots_RemoteProxyObject.m_m_state; } \
        REALLY_INLINE void set_m_state(uint32_t newVal) { m_slots_RemoteProxyObject.m_m_state = newVal; } \
    public: \
        REALLY_INLINE avmplus::PromiseChannelObject* get_m_out() const { return m_slots_RemoteProxyObject.m_m_out; } \
        REALLY_INLINE void set_m_out(avmplus::PromiseChannelObject* newVal) { m_slots_RemoteProxyObject.m_m_out = newVal; } \
    public: \
        REALLY_INLINE avmplus::PromiseChannelObject* get_m_inc() const { return m_slots_RemoteProxyObject.m_m_inc; } \
        REALLY_INLINE void set_m_inc(avmplus::PromiseChannelObject* newVal) { m_slots_RemoteProxyObject.m_m_inc = newVal; } \
    public: \
        REALLY_INLINE avmplus::Atom get_m_resolved() const { return m_slots_RemoteProxyObject.m_m_resolved; } \
        REALLY_INLINE void set_m_resolved(avmplus::Atom newVal) { m_slots_RemoteProxyObject.m_m_resolved = newVal; } \
    private: \
        avmplus::NativeID::avmplus_RemoteProxyObjectSlots m_slots_RemoteProxyObject \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Envelope$
//-----------------------------------------------------------
class avmshell_EnvelopeClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::EnvelopeClass;
};
#define DECLARE_SLOTS_EnvelopeClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmshell::EnvelopeObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmshell::EnvelopeObject>((avmshell::EnvelopeObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::EnvelopeObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::EnvelopeObject>((avmshell::EnvelopeObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::EnvelopeObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::EnvelopeObject>((avmshell::EnvelopeObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::EnvelopeObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::EnvelopeObject>((avmshell::EnvelopeObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::EnvelopeObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::EnvelopeObject>((avmshell::EnvelopeObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Envelope
//-----------------------------------------------------------
class avmshell_EnvelopeObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::EnvelopeObject;
};
#define DECLARE_SLOTS_EnvelopeObject \
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
    FLOAT_ONLY(friend class avmplus::FloatVectorClass;)
    FLOAT_ONLY(friend class avmplus::Float4VectorClass;)
    friend class avmplus::DoubleVectorClass;
    friend class avmplus::ObjectVectorClass;
private:
    REALLY_INLINE shell_toplevelClassManifest(avmplus::ScriptEnv* e) : ClassManifestBase(59, e) { }
    REALLY_INLINE static shell_toplevelClassManifest* create(avmplus::ScriptEnv* e) { return new (MMgc::GC::GetGC(e), MMgc::kExact, sizeof(ClassClosure*)*58) shell_toplevelClassManifest(e); }
public:
    REALLY_INLINE GCRef<avmshell::AbstractBaseClass> get_AbstractBaseClass() { return (avmshell::AbstractBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_AbstractBase)); }
    REALLY_INLINE GCRef<avmshell::AbstractRestrictedBaseClass> get_AbstractRestrictedBaseClass() { return (avmshell::AbstractRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_AbstractRestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::CTestClass> get_CTestClass() { return (avmplus::CTestClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_CTest)); }
    REALLY_INLINE GCRef<avmplus::CapabilitiesClass> get_CapabilitiesClass() { return (avmplus::CapabilitiesClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_Capabilities)); }
    REALLY_INLINE GCRef<avmshell::CheckBaseClass> get_CheckBaseClass() { return (avmshell::CheckBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_CheckBase)); }
    REALLY_INLINE GCRef<avmplus::ClassFactoryClass> get_ClassFactoryClass() { return (avmplus::ClassFactoryClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_ClassFactory)); }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleClass> get_DeleteObjectSampleClass() { return (avmplus::DeleteObjectSampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_DeleteObjectSample)); }
    REALLY_INLINE GCRef<avmplus::DomainClass> get_DomainClass() { return (avmplus::DomainClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_Domain)); }
    REALLY_INLINE GCRef<avmplus::EndianClass> get_EndianClass() { return (avmplus::EndianClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_Endian)); }
    REALLY_INLINE GCRef<avmshell::EnvelopeClass> get_EnvelopeClass() { return (avmshell::EnvelopeClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_Envelope)); }
    REALLY_INLINE GCRef<avmshell::FileClass> get_FileClass() { return (avmshell::FileClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_File)); }
    REALLY_INLINE GCRef<avmplus::ITestClass> get_ITestClass() { return (avmplus::ITestClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_ITest)); }
    REALLY_INLINE GCRef<avmshell::MIClass> get_MIClass() { return (avmshell::MIClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_MI)); }
    REALLY_INLINE GCRef<avmplus::NativeBaseAS3Class> get_NativeBaseAS3Class() { return (avmplus::NativeBaseAS3Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeBaseAS3)); }
    REALLY_INLINE GCRef<avmshell::NativeBaseClass> get_NativeBaseClass() { return (avmshell::NativeBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeBase)); }
    REALLY_INLINE GCRef<avmplus::NativeBaseExtender1Class> get_NativeBaseExtender1Class() { return (avmplus::NativeBaseExtender1Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeBaseExtender1)); }
    REALLY_INLINE GCRef<avmplus::NativeBaseExtender2Class> get_NativeBaseExtender2Class() { return (avmplus::NativeBaseExtender2Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeBaseExtender2)); }
    REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractBaseClass> get_NativeSubclassOfAbstractBaseClass() { return (avmshell::NativeSubclassOfAbstractBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeSubclassOfAbstractBase)); }
    REALLY_INLINE GCRef<avmshell::NativeSubclassOfAbstractRestrictedBaseClass> get_NativeSubclassOfAbstractRestrictedBaseClass() { return (avmshell::NativeSubclassOfAbstractRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeSubclassOfAbstractRestrictedBase)); }
    REALLY_INLINE GCRef<avmshell::NativeSubclassOfRestrictedBaseClass> get_NativeSubclassOfRestrictedBaseClass() { return (avmshell::NativeSubclassOfRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_NativeSubclassOfRestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::NewObjectSampleClass> get_NewObjectSampleClass() { return (avmplus::NewObjectSampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_NewObjectSample)); }
    REALLY_INLINE GCRef<avmplus::PromiseClass> get_PromiseClass() { return (avmplus::PromiseClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_Promise)); }
    REALLY_INLINE GCRef<avmplus::PromiseHelperClass> get_PromiseHelperClass() { return (avmplus::PromiseHelperClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_PromiseHelper)); }
    REALLY_INLINE GCRef<avmplus::PromiseStateClass> get_PromiseStateClass() { return (avmplus::PromiseStateClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_PromiseState)); }
    REALLY_INLINE GCRef<avmplus::RemoteProxyClass> get_RemoteProxyClass() { return (avmplus::RemoteProxyClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_RemoteProxy)); }
    REALLY_INLINE GCRef<avmshell::RestrictedBaseClass> get_RestrictedBaseClass() { return (avmshell::RestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_RestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::SampleClass> get_SampleClass() { return (avmplus::SampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_Sample)); }
    REALLY_INLINE GCRef<avmplus::ShellCoreFriend1Class> get_ShellCoreFriend1Class() { return (avmplus::ShellCoreFriend1Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_ShellCoreFriend1)); }
    REALLY_INLINE GCRef<avmplus::ShellCoreFriend2Class> get_ShellCoreFriend2Class() { return (avmplus::ShellCoreFriend2Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_ShellCoreFriend2)); }
    REALLY_INLINE GCRef<avmplus::StackFrameClass> get_StackFrameClass() { return (avmplus::StackFrameClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_StackFrame)); }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractBaseClass> get_SubclassOfAbstractBaseClass() { return (avmplus::SubclassOfAbstractBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_SubclassOfAbstractBase)); }
    REALLY_INLINE GCRef<avmplus::SubclassOfAbstractRestrictedBaseClass> get_SubclassOfAbstractRestrictedBaseClass() { return (avmplus::SubclassOfAbstractRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_SubclassOfAbstractRestrictedBase)); }
    REALLY_INLINE GCRef<avmplus::SubclassOfRestrictedBaseClass> get_SubclassOfRestrictedBaseClass() { return (avmplus::SubclassOfRestrictedBaseClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_SubclassOfRestrictedBase)); }
    REALLY_INLINE GCRef<avmshell::SystemClass> get_SystemClass() { return (avmshell::SystemClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmplus_System)); }
    REALLY_INLINE GCRef<avmplus::TraceClass> get_TraceClass() { return (avmplus::TraceClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_trace_Trace)); }
    REALLY_INLINE GCRef<avmshell::ShellWorkerClass> get_WorkerClass() { return (avmshell::ShellWorkerClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_Worker)); }
    REALLY_INLINE GCRef<avmshell::ShellWorkerDomainClass> get_WorkerDomainClass() { return (avmshell::ShellWorkerDomainClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_WorkerDomain)); }
    REALLY_INLINE GCRef<avmplus::WorkerEventClass> get_WorkerEventClass() { return (avmplus::WorkerEventClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_WorkerEvent)); }
    REALLY_INLINE GCRef<avmplus::WorkerStateClass> get_WorkerStateClass() { return (avmplus::WorkerStateClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_WorkerState)); }
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
    REALLY_INLINE GCRef<avmplus::public_interfaceClass> get_public_interfaceClass() { return (avmplus::public_interfaceClass*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface)); }
    REALLY_INLINE GCRef<avmplus::public_interface_AIR_1_0Class> get_public_interface_AIR_1_0Class() { return (avmplus::public_interface_AIR_1_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_0)); }
    REALLY_INLINE GCRef<avmplus::public_interface_AIR_1_0_FP_10_0Class> get_public_interface_AIR_1_0_FP_10_0Class() { return (avmplus::public_interface_AIR_1_0_FP_10_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_0_FP_10_0)); }
    REALLY_INLINE GCRef<avmplus::public_interface_AIR_1_5Class> get_public_interface_AIR_1_5Class() { return (avmplus::public_interface_AIR_1_5Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5)); }
    REALLY_INLINE GCRef<avmplus::public_interface_AIR_1_5_1Class> get_public_interface_AIR_1_5_1Class() { return (avmplus::public_interface_AIR_1_5_1Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5_1)); }
    REALLY_INLINE GCRef<avmplus::public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2Class> get_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2Class() { return (avmplus::public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2)); }
    REALLY_INLINE GCRef<avmplus::public_interface_AIR_1_5_2Class> get_public_interface_AIR_1_5_2Class() { return (avmplus::public_interface_AIR_1_5_2Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_AIR_1_5_2)); }
    REALLY_INLINE GCRef<avmplus::public_interface_FP_10_0Class> get_public_interface_FP_10_0Class() { return (avmplus::public_interface_FP_10_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_FP_10_0)); }
    REALLY_INLINE GCRef<avmplus::public_interface_FP_10_0_32Class> get_public_interface_FP_10_0_32Class() { return (avmplus::public_interface_FP_10_0_32Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_FP_10_0_32)); }
    REALLY_INLINE GCRef<avmplus::public_interface_FP_10_0_32_AIR_1_0_FP_10_0Class> get_public_interface_FP_10_0_32_AIR_1_0_FP_10_0Class() { return (avmplus::public_interface_FP_10_0_32_AIR_1_0_FP_10_0Class*)(lazyInitClass(avmplus::NativeID::abcclass_avmshell_public_interface_FP_10_0_32_AIR_1_0_FP_10_0)); }
};
}
#endif // _H_nativegen_header_shell_toplevel
