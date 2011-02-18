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
    class AbstractBaseClass; // avmshell::AbstractBase$
    class AbstractBaseObject; // avmshell::AbstractBase
    class AbstractRestrictedBaseClass; // avmshell::AbstractRestrictedBase$
    class AbstractRestrictedBaseObject; // avmshell::AbstractRestrictedBase
    class CheckBaseClass; // avmshell::CheckBase$
    class CheckBaseObject; // avmshell::CheckBase
    class FileClass; // avmplus::File$
    class MIClass; // avmplus::MI$
    class MIObject; // avmplus::MI
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
const uint32_t abcclass_flash_system_Capabilities = 9;
const uint32_t abcclass_avmshell_public_class = 10;
const uint32_t abcclass_avmshell_public_class_AIR_1_0 = 11;
const uint32_t abcclass_avmshell_public_class_FP_10_0 = 12;
const uint32_t abcclass_avmshell_public_class_AIR_1_5 = 13;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1 = 14;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32 = 15;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_2 = 16;
const uint32_t abcclass_avmshell_public_class_AIR_1_0_FP_10_0 = 17;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 18;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32_AIR_1_0_FP_10_0 = 19;
const uint32_t abcclass_avmshell_public_interface = 20;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0 = 21;
const uint32_t abcclass_avmshell_public_interface_FP_10_0 = 22;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5 = 23;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1 = 24;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32 = 25;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_2 = 26;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0_FP_10_0 = 27;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 28;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32_AIR_1_0_FP_10_0 = 29;
const uint32_t abcclass_avmshell_NativeSubclassOfAbstractBase = 30;
const uint32_t abcclass_avmshell_SubclassOfAbstractBase = 31;
const uint32_t abcclass_avmshell_NativeSubclassOfRestrictedBase = 32;
const uint32_t abcclass_avmshell_SubclassOfRestrictedBase = 33;
const uint32_t abcclass_avmshell_NativeSubclassOfAbstractRestrictedBase = 34;
const uint32_t abcclass_avmshell_SubclassOfAbstractRestrictedBase = 35;
const uint32_t abcclass_avmplus_Domain = 36;
const uint32_t abcclass_flash_sampler_StackFrame = 37;
const uint32_t abcclass_flash_sampler_Sample = 38;
const uint32_t abcclass_flash_sampler_NewObjectSample = 39;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 40;
const uint32_t abcclass_flash_trace_Trace = 41;
const uint32_t abcclass_flash_utils_Dictionary = 42;
const uint32_t abcclass_flash_utils_Endian = 43;
const uint32_t abcclass_avmplus_JObject = 44;

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
const uint32_t avmplus_Domain_currentDomain_get = 172;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 173;
const uint32_t avmplus_Domain_private_init = 174;
const uint32_t avmplus_Domain_loadBytes = 176;
const uint32_t avmplus_Domain_getClass = 177;
const uint32_t avmplus_Domain_domainMemory_get = 179;
const uint32_t avmplus_Domain_domainMemory_set = 180;
const uint32_t native_script_function_flash_sampler_getMasterString = 182;
const uint32_t native_script_function_flash_sampler_getSavedThis = 183;
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 184;
const uint32_t native_script_function_flash_sampler_isGetterSetter = 185;
const uint32_t native_script_function_flash_sampler__getInvocationCount = 186;
const uint32_t native_script_function_flash_sampler_getSampleCount = 190;
const uint32_t native_script_function_flash_sampler_getSamples = 191;
const uint32_t native_script_function_flash_sampler_getMemberNames = 192;
const uint32_t native_script_function_flash_sampler_getSize = 193;
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 194;
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 197;
const uint32_t native_script_function_flash_sampler_pauseSampling = 198;
const uint32_t native_script_function_flash_sampler_stopSampling = 199;
const uint32_t native_script_function_flash_sampler_startSampling = 200;
const uint32_t native_script_function_flash_sampler_clearSamples = 201;
const uint32_t flash_sampler_NewObjectSample_object_get = 208;
const uint32_t flash_sampler_NewObjectSample_size_get = 209;
const uint32_t flash_trace_Trace_setLevel = 215;
const uint32_t flash_trace_Trace_getLevel = 216;
const uint32_t flash_trace_Trace_setListener = 217;
const uint32_t flash_trace_Trace_getListener = 218;
const uint32_t flash_utils_Dictionary_private_init = 222;
const uint32_t avmplus_JObject_create = 229;
const uint32_t avmplus_JObject_createArray = 230;
const uint32_t avmplus_JObject_toArray = 231;
const uint32_t avmplus_JObject_constructorSignature = 232;
const uint32_t avmplus_JObject_methodSignature = 233;
const uint32_t avmplus_JObject_fieldSignature = 234;

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
class SlotOffsetsAndAsserts;
// avmplus::MI$
//-----------------------------------------------------------
class avmshell_MIClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_MIClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmplus::MI
//-----------------------------------------------------------
class avmshell_MIObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_MIObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmplus::System$
//-----------------------------------------------------------
class avmshell_SystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ArrayObject* get_argv() const { return m_argv; }
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
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::ArrayObject* get_argv() const { return m_slots_SystemClass.get_argv(); } \
    private: \
        avmplus::NativeID::avmshell_SystemClassSlots m_slots_SystemClass \

//-----------------------------------------------------------

// avmplus::File$
//-----------------------------------------------------------
class avmshell_FileClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_FileClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::AbstractBase$
//-----------------------------------------------------------
class avmshell_AbstractBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_AbstractBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::AbstractBase
//-----------------------------------------------------------
class avmshell_AbstractBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_AbstractBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::RestrictedBase$
//-----------------------------------------------------------
class avmshell_RestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_RestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::RestrictedBase
//-----------------------------------------------------------
class avmshell_RestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_RestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::AbstractRestrictedBase$
//-----------------------------------------------------------
class avmshell_AbstractRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_AbstractRestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::AbstractRestrictedBase
//-----------------------------------------------------------
class avmshell_AbstractRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_AbstractRestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::CheckBase$
//-----------------------------------------------------------
class avmshell_CheckBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_CheckBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static void FASTCALL preCreateInstanceCheck(avmplus::ClassClosure*); \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::CheckBase
//-----------------------------------------------------------
class avmshell_CheckBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_CheckBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::NativeSubclassOfAbstractBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::NativeSubclassOfAbstractBase
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::NativeSubclassOfRestrictedBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NativeSubclassOfRestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::NativeSubclassOfRestrictedBase
//-----------------------------------------------------------
class avmshell_NativeSubclassOfRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NativeSubclassOfRestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::NativeSubclassOfAbstractRestrictedBase$
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractRestrictedBaseClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractRestrictedBaseClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmshell::NativeSubclassOfAbstractRestrictedBase
//-----------------------------------------------------------
class avmshell_NativeSubclassOfAbstractRestrictedBaseObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NativeSubclassOfAbstractRestrictedBaseObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmplus::Domain$
//-----------------------------------------------------------
class avmplus_DomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DomainClass
};
#define DECLARE_SLOTS_DomainClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmplus::Domain
//-----------------------------------------------------------
class avmplus_DomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
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

// flash.sampler::StackFrame$
//-----------------------------------------------------------
class avmplus_StackFrameClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_StackFrameClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// flash.sampler::StackFrame
//-----------------------------------------------------------
class avmplus_StackFrameObjectSlots
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
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
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
        avmplus::NativeID::avmplus_StackFrameObjectSlots m_slots_StackFrameObject \

//-----------------------------------------------------------

// flash.sampler::Sample$
//-----------------------------------------------------------
class avmplus_SampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_SampleClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// flash.sampler::Sample
//-----------------------------------------------------------
class avmplus_SampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ArrayObject* get_stack() const { return m_stack; }
    REALLY_INLINE void set_stack(avmplus::ArrayObject* newVal) { m_stack = newVal; }
    REALLY_INLINE double get_time() const { return m_time; }
    REALLY_INLINE void set_time(double newVal) { m_time = newVal; }
private:
    DRCWB(avmplus::ArrayObject*) m_stack;
    double m_time;
};
#define DECLARE_SLOTS_SampleObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::ArrayObject* get_stack() const { return m_slots_SampleObject.get_stack(); } \
        REALLY_INLINE void set_stack(avmplus::ArrayObject* newVal) { m_slots_SampleObject.set_stack(newVal); } \
        REALLY_INLINE double get_time() const { return m_slots_SampleObject.get_time(); } \
        REALLY_INLINE void set_time(double newVal) { m_slots_SampleObject.set_time(newVal); } \
    private: \
        avmplus::NativeID::avmplus_SampleObjectSlots m_slots_SampleObject \

//-----------------------------------------------------------

// flash.sampler::NewObjectSample$
//-----------------------------------------------------------
class avmplus_NewObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NewObjectSampleClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// flash.sampler::NewObjectSample
//-----------------------------------------------------------
class avmplus_NewObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ClassClosure* get_type() const { return m_type; }
    REALLY_INLINE void set_type(avmplus::ClassClosure* newVal) { m_type = newVal; }
    REALLY_INLINE double get_id() const { return m_id; }
    REALLY_INLINE void set_id(double newVal) { m_id = newVal; }
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
    protected: \
        REALLY_INLINE avmplus::ClassClosure* get_type() const { return m_slots_NewObjectSampleObject.get_type(); } \
        REALLY_INLINE void set_type(avmplus::ClassClosure* newVal) { m_slots_NewObjectSampleObject.set_type(newVal); } \
        REALLY_INLINE double get_id() const { return m_slots_NewObjectSampleObject.get_id(); } \
        REALLY_INLINE void set_id(double newVal) { m_slots_NewObjectSampleObject.set_id(newVal); } \
    private: \
        avmplus::NativeID::avmplus_NewObjectSampleObjectSlots m_slots_NewObjectSampleObject \

//-----------------------------------------------------------

// flash.sampler::DeleteObjectSample$
//-----------------------------------------------------------
class avmplus_DeleteObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_DeleteObjectSampleClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// flash.sampler::DeleteObjectSample
//-----------------------------------------------------------
class avmplus_DeleteObjectSampleObjectSlots
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
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE double get_id() const { return m_slots_DeleteObjectSampleObject.get_id(); } \
        REALLY_INLINE void set_id(double newVal) { m_slots_DeleteObjectSampleObject.set_id(newVal); } \
        REALLY_INLINE double get_size() const { return m_slots_DeleteObjectSampleObject.get_size(); } \
        REALLY_INLINE void set_size(double newVal) { m_slots_DeleteObjectSampleObject.set_size(newVal); } \
    private: \
        avmplus::NativeID::avmplus_DeleteObjectSampleObjectSlots m_slots_DeleteObjectSampleObject \

//-----------------------------------------------------------

// flash.trace::Trace$
//-----------------------------------------------------------
class avmplus_TraceClassSlots
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
    avmplus::AtomWB m_FILE;
    avmplus::AtomWB m_LISTENER;
};
#define DECLARE_SLOTS_TraceClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
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
        avmplus::NativeID::avmplus_TraceClassSlots m_slots_TraceClass \

//-----------------------------------------------------------

// flash.utils::Dictionary$
//-----------------------------------------------------------
class avmplus_DictionaryClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DictionaryClass
};
#define DECLARE_SLOTS_DictionaryClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// flash.utils::Dictionary
//-----------------------------------------------------------
class avmplus_DictionaryObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
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

// avmplus::JObject$
//-----------------------------------------------------------
class avmplus_JObjectClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_JObjectClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

// avmplus::JObject
//-----------------------------------------------------------
class avmplus_JObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
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
