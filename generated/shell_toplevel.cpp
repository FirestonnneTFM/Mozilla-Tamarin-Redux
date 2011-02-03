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

namespace avmplus { namespace NativeID {

const uint32_t shell_toplevel_abc_class_count = 35;
const uint32_t shell_toplevel_abc_script_count = 7;
const uint32_t shell_toplevel_abc_method_count = 217;
const uint32_t shell_toplevel_abc_length = 12779;

/* thunks (39 unique signatures, 63 total) */

#ifndef VMCFG_INDIRECT_NATIVE_THUNKS

Atom avmplus_Domain_currentDomain_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainClass* const obj = (DomainClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    DomainObject* const ret = obj->get_currentDomain();
    return (Atom) ret;
}
Atom avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainClass* const obj = (DomainClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    uint32_t const ret = obj->get_MIN_DOMAIN_MEMORY_LENGTH();
    return (Atom) ret;
}
Atom avmplus_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->init(
        (DomainObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return undefinedAtom;
}
Atom avmplus_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
    };
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (Atom) ret;
}
Atom avmplus_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    ClassClosure* const ret = obj->getClass(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}
Atom avmplus_Domain_domainMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    ByteArrayObject* const ret = obj->get_domainMemory();
    return (Atom) ret;
}
Atom avmplus_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->set_domainMemory(
        (ByteArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return undefinedAtom;
}
Atom flash_sampler_NewObjectSample_object_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = obj->get_object();
    return (Atom) ret;
}
double flash_sampler_NewObjectSample_size_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = obj->get_size();
    return ret;
}
Atom native_script_function_flash_sampler_clearSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::clearSamples(obj);
    return undefinedAtom;
}
Atom native_script_function_flash_sampler_startSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::startSampling(obj);
    return undefinedAtom;
}
Atom native_script_function_flash_sampler_stopSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::stopSampling(obj);
    return undefinedAtom;
}
Atom native_script_function_flash_sampler_pauseSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::pauseSampling(obj);
    return undefinedAtom;
}
Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_bool32(argv[argoff1])
    );
    return undefinedAtom;
}
Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return undefinedAtom;
}
double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
    );
    return ret;
}
Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_Atom
    };
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_bool32(argv[argoff2]))
    );
    return (Atom) ret;
}
Atom native_script_function_flash_sampler_getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = SamplerScript::getSamples(obj);
    return (Atom) ret;
}
double native_script_function_flash_sampler_getSampleCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}
double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_Atom
        , argoff3 = argoff2 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_ScriptObject(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}
Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_Atom
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_ScriptObject(argv[argoff2])
    );
    return (Atom) ret;
}
Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    ArrayObject* const ret = SamplerScript::getLexicalScopes(obj
        , (FunctionObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return (Atom) ret;
}
Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = SamplerScript::getSavedThis(obj
        , (FunctionObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return (Atom) ret;
}
Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}
Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (Atom) ret;
}
Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (Atom) ret;
}
Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = obj->setListener(
        (FunctionObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return (Atom) ret;
}
Atom flash_trace_Trace_getListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    FunctionObject* const ret = obj->getListener();
    return (Atom) ret;
}
Atom flash_utils_Dictionary_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_bool32(argv[argoff1])
    );
    return undefinedAtom;
}
Atom avmplus_JObject_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_String;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_String(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (Atom) ret;
}
Atom avmplus_JObject_createArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_Atom_ScriptObject(nullObjectAtom) : (ArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff3]))
    );
    return (Atom) ret;
}
Atom avmplus_JObject_toArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    ArrayObject* const ret = obj->toArray(
        (JObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return (Atom) ret;
}
Atom avmplus_JObject_constructorSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_String;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->constructorSignature(
        AvmThunkUnbox_String(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (Atom) ret;
}
Atom avmplus_JObject_methodSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_String;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , AvmThunkUnbox_String(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (Atom) ret;
}
Atom avmplus_JObject_fieldSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , AvmThunkUnbox_String(argv[argoff2])
    );
    return (Atom) ret;
}
double avmplus_MI_plus_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
}
Atom avmplus_System_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return undefinedAtom;
}
Atom avmplus_System_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}
Atom avmplus_System_getAvmplusVersion_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->getAvmplusVersion();
    return (Atom) ret;
}
Atom avmplus_System_getFeatures_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->getFeatures();
    return (Atom) ret;
}
Atom avmplus_System_getRunmode_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->getRunmode();
    return (Atom) ret;
}
Atom avmplus_System_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->trace(
        (ArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return undefinedAtom;
}
Atom avmplus_System_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return undefinedAtom;
}
Atom avmplus_System_debugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->debugger();
    return undefinedAtom;
}
Atom avmplus_System_isDebugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->isDebugger();
    return (Atom) ret;
}
Atom avmplus_System_getTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    uint32_t const ret = obj->getTimer();
    return (Atom) ret;
}
Atom avmplus_System_private_getArgv_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    ArrayObject* const ret = obj->getArgv();
    return (Atom) ret;
}
Atom avmplus_System_readLine_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->readLine();
    return (Atom) ret;
}
double avmplus_System_totalMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = obj->get_totalMemory();
    return ret;
}
double avmplus_System_freeMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = obj->get_freeMemory();
    return ret;
}
double avmplus_System_privateMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = obj->get_privateMemory();
    return ret;
}
Atom avmplus_System_forceFullCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->forceFullCollection();
    return undefinedAtom;
}
Atom avmplus_System_queueCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->queueCollection();
    return undefinedAtom;
}
Atom avmplus_System_ns_example_nstest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->ns_example_nstest();
    return undefinedAtom;
}
Atom avmplus_System_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->isGlobal(
        AvmThunkUnbox_Atom(argv[argoff1])
    );
    return (Atom) ret;
}
Atom avmplus_System_swfVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->get_swfVersion();
    return (Atom) ret;
}
Atom avmplus_System_apiVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->get_apiVersion();
    return (Atom) ret;
}
Atom avmplus_System_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->disposeXML(
        (XMLObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return undefinedAtom;
}
Atom avmplus_File_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->exists(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}
Atom avmplus_File_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->read(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}
Atom avmplus_File_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_String
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_String(argv[argoff1])
        , AvmThunkUnbox_String(argv[argoff2])
    );
    return undefinedAtom;
}
Atom avmplus_File_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    ByteArrayObject* const ret = obj->readByteArray(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}
Atom avmplus_File_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_String
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->writeByteArray(
        AvmThunkUnbox_String(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff2])
    );
    return (Atom) ret;
}

#else // VMCFG_INDIRECT_NATIVE_THUNKS

// avmplus_JObject_methodSignature
Atom shell_toplevel_s2a_oos_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_String;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , AvmThunkUnbox_String(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler_getMasterString
Atom shell_toplevel_func_s2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler__setSamplerCallback
Atom shell_toplevel_func_v2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return undefinedAtom;
}

// avmplus_System_freeMemory_get
// avmplus_System_privateMemory_get
// avmplus_System_totalMemory_get
// flash_sampler_NewObjectSample_size_get
double shell_toplevel_d2d_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef double (ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_Domain_getClass
// avmplus_File_readByteArray
Atom shell_toplevel_a2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    typedef ByteArrayObject* (ScriptObject::*FuncType)(String*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
        AvmThunkUnbox_String(argv[argoff1])
    );
}

// native_script_function_flash_sampler_isGetterSetter
Atom shell_toplevel_func_b2a_oao_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_Atom
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_ScriptObject(argv[argoff2])
    );
    return (Atom) ret;
}

// avmplus_JObject_toArray
// flash_trace_Trace_setListener
Atom shell_toplevel_a2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    typedef Atom (ScriptObject::*FuncType)(ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
        AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
}

// avmplus_System_getAvmplusVersion
// avmplus_System_getFeatures
// avmplus_System_getRunmode
// avmplus_System_readLine
Atom shell_toplevel_s2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef String* (ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
    );
}

// native_script_function_flash_sampler_sampleInternalAllocs
Atom shell_toplevel_func_v2a_ob_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_bool32(argv[argoff1])
    );
    return undefinedAtom;
}

// avmplus_File_write
Atom shell_toplevel_v2a_oss_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_String
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_String(argv[argoff1])
        , AvmThunkUnbox_String(argv[argoff2])
    );
    return undefinedAtom;
}

// native_script_function_flash_sampler_getSize
double shell_toplevel_func_d2d_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
    );
    return ret;
}

// native_script_function_flash_sampler_clearSamples
// native_script_function_flash_sampler_pauseSampling
// native_script_function_flash_sampler_startSampling
// native_script_function_flash_sampler_stopSampling
Atom shell_toplevel_func_v2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef void (*FuncType)(ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    (*func)(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])
    );
    return undefinedAtom;
}

// avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get
// avmplus_System_getTimer
Atom shell_toplevel_u2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef uint32_t (ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_JObject_constructorSignature
Atom shell_toplevel_s2a_os_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_String;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->constructorSignature(
        AvmThunkUnbox_String(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler_getSampleCount
double shell_toplevel_func_d2d_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}

// avmplus_System_apiVersion_get
// avmplus_System_swfVersion_get
Atom shell_toplevel_i2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef int32_t (ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_JObject_fieldSignature
Atom shell_toplevel_s2a_oos_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , AvmThunkUnbox_String(argv[argoff2])
    );
    return (Atom) ret;
}

// avmplus_System_exec
Atom shell_toplevel_i2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}

// avmplus_System_isGlobal
Atom shell_toplevel_b2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->isGlobal(
        AvmThunkUnbox_Atom(argv[argoff1])
    );
    return (Atom) ret;
}

// avmplus_File_read
Atom shell_toplevel_s2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    String* const ret = obj->read(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler_getSamples
Atom shell_toplevel_func_a2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = SamplerScript::getSamples(obj);
    return (Atom) ret;
}

// avmplus_JObject_create
Atom shell_toplevel_a2a_os_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_String;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_String(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (Atom) ret;
}

// avmplus_JObject_createArray
Atom shell_toplevel_a2a_ooio_optanullObjectAtom_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_Atom_ScriptObject(nullObjectAtom) : (ArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff3]))
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler_getLexicalScopes
// native_script_function_flash_sampler_getSavedThis
Atom shell_toplevel_func_a2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    typedef Atom (*FuncType)(ScriptObject*, ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    return (Atom)(*func)(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])
        , AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
}

// avmplus_File_exists
Atom shell_toplevel_b2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->exists(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return (Atom) ret;
}

// avmplus_Domain_currentDomain_get
// avmplus_Domain_domainMemory_get
// avmplus_System_private_getArgv
// flash_sampler_NewObjectSample_object_get
// flash_trace_Trace_getListener
Atom shell_toplevel_a2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef FunctionObject* (ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_Domain_loadBytes
Atom shell_toplevel_a2a_oou_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_ScriptObject
    };
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (Atom) ret;
}

// avmplus_System_debugger
// avmplus_System_forceFullCollection
// avmplus_System_ns_example_nstest
// avmplus_System_queueCollection
Atom shell_toplevel_v2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef void (ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
    );
    return undefinedAtom;
}

// avmplus_MI_plus
double shell_toplevel_d2d_od_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
}

// flash_utils_Dictionary_private_init
Atom shell_toplevel_v2a_ob_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_bool32(argv[argoff1])
    );
    return undefinedAtom;
}

// flash_trace_Trace_getLevel
Atom shell_toplevel_i2a_oi_opti2_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (Atom) ret;
}

// flash_trace_Trace_setLevel
Atom shell_toplevel_a2a_oii_opti2_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (Atom) ret;
}

// avmplus_File_writeByteArray
Atom shell_toplevel_b2a_oso_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_String
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->writeByteArray(
        AvmThunkUnbox_String(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox_ScriptObject(argv[argoff2])
    );
    return (Atom) ret;
}

// avmplus_System_exit
Atom shell_toplevel_v2a_oi_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return undefinedAtom;
}

// avmplus_Domain_domainMemory_set
// avmplus_Domain_private_init
// avmplus_System_disposeXML
// avmplus_System_trace
Atom shell_toplevel_v2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    typedef void (ScriptObject::*FuncType)(ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0])).*(func))(
        AvmThunkUnbox_ScriptObject(argv[argoff1])
    );
    return undefinedAtom;
}

// avmplus_System_isDebugger
Atom shell_toplevel_b2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    bool const ret = obj->isDebugger();
    return (Atom) ret;
}

// avmplus_System_write
Atom shell_toplevel_v2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_String(argv[argoff1])
    );
    return undefinedAtom;
}

// native_script_function_flash_sampler__getInvocationCount
double shell_toplevel_func_d2d_oaou_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_Atom
        , argoff3 = argoff2 + AvmThunkArgSize_ScriptObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_ScriptObject(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}

// native_script_function_flash_sampler_getMemberNames
Atom shell_toplevel_func_a2a_oab_optbfalse_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_ScriptObject
        , argoff2 = argoff1 + AvmThunkArgSize_Atom
    };
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(ScriptObject*, argv[argoff0]);
    Atom const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_Atom(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_bool32(argv[argoff2]))
    );
    return (Atom) ret;
}

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts
{
private:
    static uint32_t getSlotOffset(Traits* t, int nameId);
public:
    // This exists solely to silence a warning (generally GCC 4.4+):
    // "all member functions in class SlotOffsetsAndAsserts are private"
    static inline void do_nothing();
    static const uint16_t s_slotsOffsetMIClass = 0;
    static const uint16_t s_slotsOffsetMIObject = 0;
    #ifdef DEBUG
    static void doMIClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetSystemClass = offsetof(::avmshell::SystemClass, m_slots_SystemClass);
    static const uint16_t s_slotsOffsetScriptObject = 0;
    #ifdef DEBUG
    static void doSystemClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetFileClass = 0;
    #ifdef DEBUG
    static void doFileClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetDomainClass = 0;
    static const uint16_t s_slotsOffsetDomainObject = 0;
    #ifdef DEBUG
    static void doDomainClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetStackFrameClass = 0;
    static const uint16_t s_slotsOffsetStackFrameObject = offsetof(StackFrameObject, m_slots_StackFrameObject);
    #ifdef DEBUG
    static void doStackFrameClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetSampleClass = 0;
    static const uint16_t s_slotsOffsetSampleObject = offsetof(SampleObject, m_slots_SampleObject);
    #ifdef DEBUG
    static void doSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetNewObjectSampleClass = 0;
    static const uint16_t s_slotsOffsetNewObjectSampleObject = offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject);
    #ifdef DEBUG
    static void doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetDeleteObjectSampleClass = 0;
    static const uint16_t s_slotsOffsetDeleteObjectSampleObject = offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject);
    #ifdef DEBUG
    static void doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetTraceClass = offsetof(TraceClass, m_slots_TraceClass);
    #ifdef DEBUG
    static void doTraceClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetDictionaryClass = 0;
    static const uint16_t s_slotsOffsetDictionaryObject = 0;
    #ifdef DEBUG
    static void doDictionaryClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetJObjectClass = 0;
    static const uint16_t s_slotsOffsetJObject = 0;
    #ifdef DEBUG
    static void doJObjectClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
};
#ifdef DEBUG
REALLY_INLINE void SlotOffsetsAndAsserts::doMIClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::MIClass::EmptySlotsStruct_MIClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::MIObject::EmptySlotsStruct_MIObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSystemClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) == s_slotsOffsetSystemClass);
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(::avmshell::SystemClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 39) == (offsetof(::avmshell::SystemClass, m_slots_SystemClass) + offsetof(_avmshell_SystemClassSlots, m_argv)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doFileClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::FileClass::EmptySlotsStruct_FileClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDomainClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DomainClass::EmptySlotsStruct_DomainClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(DomainObject::EmptySlotsStruct_DomainObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doStackFrameClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(StackFrameClass::EmptySlotsStruct_StackFrameClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) == s_slotsOffsetStackFrameObject);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(StackFrameObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 303) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(iTraits, 304) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(iTraits, 305) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(iTraits, 306) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_scriptID)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(SampleClass::EmptySlotsStruct_SampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) == s_slotsOffsetSampleObject);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 309) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(iTraits, 310) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(NewObjectSampleClass::EmptySlotsStruct_NewObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) == s_slotsOffsetNewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 312) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 313) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_type)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleClass::EmptySlotsStruct_DeleteObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == s_slotsOffsetDeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 312) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 315) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doTraceClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) == s_slotsOffsetTraceClass);
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 349) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(cTraits, 350) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(cTraits, 351) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 352) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(cTraits, 353) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 354) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(cTraits, 355) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_LISTENER)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDictionaryClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DictionaryClass::EmptySlotsStruct_DictionaryClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(DictionaryObject::EmptySlotsStruct_DictionaryObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doJObjectClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(JObjectClass::EmptySlotsStruct_JObjectClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(JObject::EmptySlotsStruct_JObject) >= 0);
}
#endif // DEBUG

AVMTHUNK_NATIVE_CLASS_GLUE(MIClass, ::avmshell::MIClass, SlotOffsetsAndAsserts::doMIClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::doSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::doFileClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DomainClass, DomainClass, SlotOffsetsAndAsserts::doDomainClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::doStackFrameClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(SampleClass, SampleClass, SlotOffsetsAndAsserts::doSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(TraceClass, TraceClass, SlotOffsetsAndAsserts::doTraceClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::doDictionaryClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(JObjectClass, JObjectClass, SlotOffsetsAndAsserts::doJObjectClassAsserts)

AVMTHUNK_BEGIN_NATIVE_TABLES(shell_toplevel)

    AVMTHUNK_BEGIN_NATIVE_METHODS(shell_toplevel)
        AVMTHUNK_NATIVE_METHOD(avmplus_MI_plus, ::avmshell::MIObjectImpl::plus)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exit, ::avmshell::SystemClass::exit)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exec, ::avmshell::SystemClass::exec)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getAvmplusVersion, ::avmshell::SystemClass::getAvmplusVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getFeatures, ::avmshell::SystemClass::getFeatures)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getRunmode, ::avmshell::SystemClass::getRunmode)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_trace, ::avmshell::SystemClass::trace)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_write, ::avmshell::SystemClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_debugger, ::avmshell::SystemClass::debugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isDebugger, ::avmshell::SystemClass::isDebugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getTimer, ::avmshell::SystemClass::getTimer)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_private_getArgv, ::avmshell::SystemClass::getArgv)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_readLine, ::avmshell::SystemClass::readLine)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_totalMemory_get, ::avmshell::SystemClass::get_totalMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_freeMemory_get, ::avmshell::SystemClass::get_freeMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_privateMemory_get, ::avmshell::SystemClass::get_privateMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_forceFullCollection, ::avmshell::SystemClass::forceFullCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_queueCollection, ::avmshell::SystemClass::queueCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_ns_example_nstest, ::avmshell::SystemClass::ns_example_nstest)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isGlobal, ::avmshell::SystemClass::isGlobal)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_swfVersion_get, ::avmshell::SystemClass::get_swfVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_apiVersion_get, ::avmshell::SystemClass::get_apiVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_disposeXML, ::avmshell::SystemClass::disposeXML)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_exists, ::avmshell::FileClass::exists)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_read, ::avmshell::FileClass::read)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_write, ::avmshell::FileClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_readByteArray, ::avmshell::FileClass::readByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_writeByteArray, ::avmshell::FileClass::writeByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_currentDomain_get, DomainClass::get_currentDomain)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get, DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_private_init, DomainObject::init)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_loadBytes, DomainObject::loadBytes)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_getClass, DomainObject::getClass)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_get, DomainObject::get_domainMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_set, DomainObject::set_domainMemory)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMasterString, SamplerScript::getMasterString)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSavedThis, SamplerScript::getSavedThis)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getLexicalScopes, SamplerScript::getLexicalScopes)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_isGetterSetter, SamplerScript::isGetterSetter)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__getInvocationCount, SamplerScript::_getInvocationCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSampleCount, SamplerScript::getSampleCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSamples, SamplerScript::getSamples)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMemberNames, SamplerScript::getMemberNames)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSize, SamplerScript::getSize)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__setSamplerCallback, SamplerScript::_setSamplerCallback)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_sampleInternalAllocs, SamplerScript::sampleInternalAllocs)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_pauseSampling, SamplerScript::pauseSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_stopSampling, SamplerScript::stopSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_startSampling, SamplerScript::startSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_clearSamples, SamplerScript::clearSamples)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_object_get, NewObjectSampleObject::get_object)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_size_get, NewObjectSampleObject::get_size)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setLevel, TraceClass::setLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getLevel, TraceClass::getLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setListener, TraceClass::setListener)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getListener, TraceClass::getListener)
        AVMTHUNK_NATIVE_METHOD(flash_utils_Dictionary_private_init, DictionaryObject::init)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_create, JObjectClass::create)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_createArray, JObjectClass::createArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_toArray, JObjectClass::toArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_constructorSignature, JObjectClass::constructorSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_methodSignature, JObjectClass::methodSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_fieldSignature, JObjectClass::fieldSignature)
    AVMTHUNK_END_NATIVE_METHODS()

    AVMTHUNK_BEGIN_NATIVE_CLASSES(shell_toplevel)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_MI, MIClass, ::avmshell::MIClass, SlotOffsetsAndAsserts::s_slotsOffsetMIClass, ::avmshell::MIObject, SlotOffsetsAndAsserts::s_slotsOffsetMIObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_System, SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::s_slotsOffsetSystemClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_File, FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::s_slotsOffsetFileClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, DomainClass, SlotOffsetsAndAsserts::s_slotsOffsetDomainClass, DomainObject, SlotOffsetsAndAsserts::s_slotsOffsetDomainObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameClass, StackFrameObject, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, SampleClass, SlotOffsetsAndAsserts::s_slotsOffsetSampleClass, SampleObject, SlotOffsetsAndAsserts::s_slotsOffsetSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleClass, NewObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleClass, DeleteObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, TraceClass, SlotOffsetsAndAsserts::s_slotsOffsetTraceClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Dictionary, DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryClass, DictionaryObject, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, JObjectClass, SlotOffsetsAndAsserts::s_slotsOffsetJObjectClass, JObject, SlotOffsetsAndAsserts::s_slotsOffsetJObject, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[12779] = {
  16,   0,  46,   0,   6,   0,   2,   1,   3,   4,   0,   7,   0,   0,   0,   0,
   0,   0, 240,  63,   0,   0,   0,   0,   0,   0,   0,  64,   0,   0,   0,   0,
   0,   0,   8,  64,   0,   0,   0,   0,   0,   0,  16,  64,   0,   0,   0,   0,
   0,   0,  20,  64,   0,   0,   0,   0,   0,   0,  24,  64, 181,   2,   0,   4,
 118, 111, 105, 100,   7,  66, 111, 111, 108, 101,  97, 110,   6,  83, 121, 115,
 116, 101, 109,  19, 115, 104, 101, 108, 108,  95, 116, 111, 112, 108, 101, 118,
 101, 108,  46,  97, 115,  36,  49,   7,  97, 118, 109, 112, 108, 117, 115,   8,
 114, 101,  97, 100,  76, 105, 110, 101,   6,  83, 116, 114, 105, 110, 103,   8,
 103, 101, 116,  84, 105, 109, 101, 114,   4, 117, 105, 110, 116,   5, 116, 114,
  97,  99, 101,   6,  68, 111, 109,  97, 105, 110,  13,  99, 117, 114, 114, 101,
 110, 116,  68, 111, 109,  97, 105, 110,   8, 103, 101, 116,  67, 108,  97, 115,
 115,   5,  67, 108,  97, 115, 115,   8, 100, 101,  98, 117, 103, 103, 101, 114,
  13,  97, 118, 109, 112, 108, 117, 115,  58,  73,  84, 101, 115, 116,   4, 116,
 101, 115, 116,   5,  73,  84, 101, 115, 116,  13,  97, 118, 109, 112, 108, 117,
 115,  58,  67,  84, 101, 115, 116,   3, 238, 138, 148,   5,  67,  84, 101, 115,
 116,   6,  79,  98, 106, 101,  99, 116,  10,  97, 118, 109, 112, 108, 117, 115,
  58,  77,  73,   6,  78, 117, 109,  98, 101, 114,   4, 112, 108, 117, 115,   2,
  77,  73,  14,  97, 118, 109, 112, 108, 117, 115,  58,  83, 121, 115, 116, 101,
 109,   4,  97, 114, 103, 118,   7, 103, 101, 116,  65, 114, 103, 118,   3, 105,
 110, 116,   5,  65, 114, 114,  97, 121,   3,  88,  77,  76,   4, 101, 120, 105,
 116,   3, 102, 111, 111,   4, 101, 120, 101,  99,   3,  98,  97, 114,   4,  97,
 116, 116, 114,   8, 119, 104,  97, 116, 101, 118, 101, 114,  17, 103, 101, 116,
  65, 118, 109, 112, 108, 117, 115,  86, 101, 114, 115, 105, 111, 110,  11, 103,
 101, 116,  70, 101,  97, 116, 117, 114, 101, 115,  10, 103, 101, 116,  82, 117,
 110, 109, 111, 100, 101,   5, 119, 114, 105, 116, 101,  10, 105, 115,  68, 101,
  98, 117, 103, 103, 101, 114,  11, 116, 111, 116,  97, 108,  77, 101, 109, 111,
 114, 121,  10, 102, 114, 101, 101,  77, 101, 109, 111, 114, 121,  13, 112, 114,
 105, 118,  97, 116, 101,  77, 101, 109, 111, 114, 121,  19, 102, 111, 114,  99,
 101,  70, 117, 108, 108,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  15,
 113, 117, 101, 117, 101,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  22,
 104, 116, 116, 112,  58,  47,  47, 119, 119, 119,  46, 101, 120,  97, 109, 112,
 108, 101,  46,  99, 111, 109,   6, 110, 115, 116, 101, 115, 116,   8, 105, 115,
  71, 108, 111,  98,  97, 108,  10, 115, 119, 102,  86, 101, 114, 115, 105, 111,
 110,  10,  97, 112, 105,  86, 101, 114, 115, 105, 111, 110,  10, 100, 105, 115,
 112, 111, 115, 101,  88,  77,  76,  12,  97, 118, 109, 112, 108, 117, 115,  58,
  70, 105, 108, 101,  11, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,
   9,  66, 121, 116, 101,  65, 114, 114,  97, 121,   6, 101, 120, 105, 115, 116,
 115,   4, 114, 101,  97, 100,  13, 114, 101,  97, 100,  66, 121, 116, 101,  65,
 114, 114,  97, 121,  14, 119, 114, 105, 116, 101,  66, 121, 116, 101,  65, 114,
 114,  97, 121,   4,  70, 105, 108, 101,  25, 102, 108,  97, 115, 104,  46, 115,
 121, 115, 116, 101, 109,  58,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105,
 101, 115,   7,  65,  86,  77,  80, 108, 117, 115,  12, 102, 108,  97, 115, 104,
  46, 115, 121, 115, 116, 101, 109,  10, 112, 108,  97, 121, 101, 114,  84, 121,
 112, 101,  12,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,  21,
  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,
  99, 108,  97, 115, 115,  10, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,
   3, 238, 138, 149,  18, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,
  65,  73,  82,  95,  49,  95,  48,   3,  65,  80,  73,   3,  54,  54,  49,   3,
 238, 138, 150,  18, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  70,
  80,  95,  49,  48,  95,  48,   3,  54,  54,  50,   3, 238, 138, 151,  18, 112,
 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,
  53,   3,  54,  54,  51,   3, 238, 138, 152,  20, 112, 117,  98, 108, 105,  99,
  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,   3,  54,
  54,  52,   3, 238, 138, 153,  21, 112, 117,  98, 108, 105,  99,  95, 118,  97,
 114,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,   3,  54,  54,  53,
   3, 238, 138, 154,  20, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  50,   3,  54,  54,  54,  26, 112, 117,
  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  48,
  95,  70,  80,  95,  49,  48,  95,  48,  38, 112, 117,  98, 108, 105,  99,  95,
 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,
  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  37,
 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,
  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,
  95,  49,  48,  95,  48,  12, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110,
 115, 116,  20, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,
  65,  73,  82,  95,  49,  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99,
 111, 110, 115, 116,  95,  70,  80,  95,  49,  48,  95,  48,  20, 112, 117,  98,
 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,
  53,  22, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  49,  23, 112, 117,  98, 108, 105,  99,  95,
  99, 111, 110, 115, 116,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,
  22, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  50,  28, 112, 117,  98, 108, 105,  99,  95,  99,
 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,
  49,  48,  95,  48,  40, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115,
 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,
  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  39, 112, 117,
  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  70,  80,  95,  49,  48,
  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,
  95,  49,  48,  95,  48,  15, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,
  99, 116, 105, 111, 110,  23, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,
  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  48,  23, 112, 117,
  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  70,  80,
  95,  49,  48,  95,  48,  23, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,
  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  25, 112, 117,
  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  49,  26, 112, 117,  98, 108, 105,  99,  95, 102,
 117, 110,  99, 116, 105, 111, 110,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  51,  50,  25, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  31, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,
  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  43, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  50,  42, 112, 117,  98, 108, 105,  99,  95,
 102, 117, 110,  99, 116, 105, 111, 110,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,
  48,  95,  48,  13, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101,
 116,  21, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,
  65,  73,  82,  95,  49,  95,  48,  21, 112, 117,  98, 108, 105,  99,  95, 103,
 101, 116, 115, 101, 116,  95,  70,  80,  95,  49,  48,  95,  48,  21, 112, 117,
  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,
  49,  95,  53,  23, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101,
 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  24, 112, 117,  98, 108,
 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,  95,  49,  48,  95,
  48,  95,  51,  50,  23, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115,
 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  29, 112, 117,  98,
 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,
  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  41, 112, 117,  98, 108, 105,
  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  50,  40, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115,
 101, 116,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,
  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,   8,  97, 118,
 109, 115, 104, 101, 108, 108,  12, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,
  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,
  73,  82,  95,  49,  95,  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,
  49,  48,  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  95,  70,  80,  95,  49,  48,  95,  48,  29,  97, 118, 109, 115, 104, 101,
 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  65,  73,  82,  95,  49,  95,  53,  20, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  31,  97, 118, 109,
 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  22, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  49,  32,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,
  48,  95,  51,  50,  23, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  31,  97, 118, 109,
 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  22, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  50,  37,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,
  48,  95,  70,  80,  95,  49,  48,  95,  48,  28, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,
  80,  95,  49,  48,  95,  48,  49,  97, 118, 109, 115, 104, 101, 108, 108,  58,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  50,  40, 112, 117,  98, 108, 105,  99,  95,
  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  50,  48,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,
  95,  48,  39, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,
  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  16, 112, 117,  98, 108, 105,
  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  24, 112, 117,  98, 108,
 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,
  95,  49,  95,  48,  24, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101,
 114, 102,  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  24, 112, 117,
  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,
  73,  82,  95,  49,  95,  53,  26, 112, 117,  98, 108, 105,  99,  95, 105, 110,
 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  49,  27, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,
  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  26, 112, 117,
  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  50,  32, 112, 117,  98, 108, 105,  99,  95,
 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,
  48,  95,  70,  80,  95,  49,  48,  95,  48,  44, 112, 117,  98, 108, 105,  99,
  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  43, 112, 117,  98, 108, 105,  99,  95, 105, 110,
 116, 101, 114, 102,  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,
  95,  48,  11,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  48,  11,  65,
  80,  73,  95,  70,  80,  95,  49,  48,  95,  48,  11,  65,  80,  73,  95,  65,
  73,  82,  95,  49,  95,  53,  13,  65,  80,  73,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  49,  14,  65,  80,  73,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  51,  50,  13,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  50,  10, 110, 115,  95, 101, 120,  97, 109, 112, 108, 101,   6, 110,  97, 116,
 105, 118, 101,   3,  99, 108, 115,  19,  58,  58,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  58,  77,  73,  67, 108,  97, 115, 115,   8, 105, 110, 115, 116,
  97, 110,  99, 101,  20,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  77,  73,  79,  98, 106, 101,  99, 116,   7, 109, 101, 116, 104, 111, 100,
 115,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,
  79,  98, 106, 101,  99, 116,  73, 109, 112, 108,  10,  97, 118, 109, 112, 108,
 117, 115, 238, 138, 148,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  83, 121, 115, 116, 101, 109,  67, 108,  97, 115, 115,   7,  99, 108,
  97, 115, 115, 103,  99,   5, 101, 120,  97,  99, 116,   4,  97, 117, 116, 111,
  21,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  70, 105, 108,
 101,  67, 108,  97, 115, 115,  15, 102, 108,  97, 115, 104,  46, 115, 121, 115,
 116, 101, 109, 238, 138, 148,  14, 103, 101, 116,  67, 108,  97, 115, 115,  66,
 121,  78,  97, 109, 101,   5, 112, 114, 105, 110, 116,  11,  97, 118, 109, 115,
 104, 101, 108, 108, 238, 138, 148,  11,  97, 118, 109, 115, 104, 101, 108, 108,
 238, 138, 149,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 150,  11,
  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 151,  11,  97, 118, 109, 115,
 104, 101, 108, 108, 238, 138, 152,  11,  97, 118, 109, 115, 104, 101, 108, 108,
 238, 138, 153,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 154,  14,
  97, 118, 109, 112, 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,   4, 105,
 110, 105, 116,  11,  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,  50,   9,
 108, 111,  97, 100,  66, 121, 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,
  77,  65,  73,  78,  95,  77,  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,
  84,  72,   4, 108, 111,  97, 100,  12, 100, 111, 109,  97, 105, 110,  77, 101,
 109, 111, 114, 121,  11,  68, 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,
   2, 103,  99,  12,  68, 111, 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,
   8,  70, 117, 110,  99, 116, 105, 111, 110,   5,  81,  78,  97, 109, 101,  19,
  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  12,  83,  97, 109, 112, 108, 101, 114,  46,  97, 115,  36,  51,
  13, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,   1, 102,
   1, 101,   3, 114, 101, 116,  19,  95, 115, 101, 116,  83,  97, 109, 112, 108,
 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 119, 114,  97, 112, 112,
 101, 114,  24, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,
  58,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,   4, 110,  97, 109, 101,
   2,  40,  41,   4, 102, 105, 108, 101,   1,  91,   1,  58,   4, 108, 105, 110,
 101,   1,  93,   8, 115,  99, 114, 105, 112, 116,  73,  68,   8, 116, 111,  83,
 116, 114, 105, 110, 103,  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,
  20, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,
  97, 109, 112, 108, 101,   4, 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,
   6,  83,  97, 109, 112, 108, 101,  29, 102, 108,  97, 115, 104,  46, 115,  97,
 109, 112, 108, 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,
  97, 109, 112, 108, 101,   2, 105, 100,   4, 116, 121, 112, 101,   6, 111,  98,
 106, 101,  99, 116,   4, 115, 105, 122, 101,  15,  78, 101, 119,  79,  98, 106,
 101,  99, 116,  83,  97, 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46,
 115,  97, 109, 112, 108, 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116,
 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  16, 102, 108,
  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114, 238, 138, 148,  15,  83,
 116,  97,  99, 107,  70, 114,  97, 109, 101,  67, 108,  97, 115, 115,  16,  83,
 116,  97,  99, 107,  70, 114,  97, 109, 101,  79,  98, 106, 101,  99, 116,  12,
  99, 111, 110, 115, 116, 115, 101, 116, 116, 101, 114, 115,   4, 116, 114, 117,
 101,  11,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  12,  83,  97,
 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  20,  78, 101, 119,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  21,
  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,
  98, 106, 101,  99, 116,  23,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,
  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  24,  68, 101,
 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,
  79,  98, 106, 101,  99, 116,  12,  99, 108, 101,  97, 114,  83,  97, 109, 112,
 108, 101, 115,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13,
 115, 116,  97, 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115, 116,  97,
 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,
  97, 109, 112, 108, 105, 110, 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 115, 116, 111, 112,  83,  97, 109, 112, 108,
 105, 110, 103,  13, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110,
 103,  28,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,
  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108,
 111,  99, 115,  35,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58, 115,  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97,
 108,  65, 108, 108, 111,  99, 115,  18, 115, 101, 116,  83,  97, 109, 112, 108,
 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,  34,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 115, 101, 116,  83,  97,
 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 103, 101,
 116,  83, 105, 122, 101,  22,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58, 103, 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,
  77, 101, 109,  98, 101, 114,  78,  97, 109, 101, 115,  29,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77, 101,
 109,  98, 101, 114,  78,  97, 109, 101, 115,  10, 103, 101, 116,  83,  97, 109,
 112, 108, 101, 115,  25,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  14, 103,
 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  29,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,
  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  18, 103, 101, 116,  73,
 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103,
 101, 116,  83, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105,
 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  71, 101, 116, 116, 101,
 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,
  34,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  14, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116,
 101, 114,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,
  16, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101,
 115,  31,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101,
 115,  12, 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101,
 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  15, 103, 101, 116,  77,  97,
 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,  30,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77,  97, 115,
 116, 101, 114,  83, 116, 114, 105, 110, 103,  17, 102, 108,  97, 115, 104,  46,
 116, 114,  97,  99, 101,  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,
  77,  69,  84,  72,  79,  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,
  87,  73,  84,  72,  95,  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,
  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,
  79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,
  84,  72,  95,  65,  82,  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,
  84,  69,  78,  69,  82,   8, 115, 101, 116,  76, 101, 118, 101, 108,   8, 103,
 101, 116,  76, 101, 118, 101, 108,  11, 115, 101, 116,  76, 105, 115, 116, 101,
 110, 101, 114,  11, 103, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11,
 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,   5,  84, 114,  97,  99,
 101,  10,  84, 114,  97,  99, 101,  46,  97, 115,  36,  52,  14, 102, 108,  97,
 115, 104,  46, 116, 114,  97,  99, 101, 238, 138, 148,  10,  84, 114,  97,  99,
 101,  67, 108,  97, 115, 115,  22, 102, 108,  97, 115, 104,  46, 117, 116, 105,
 108, 115,  58,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  15,  68, 105,
  99, 116, 105, 111, 110,  97, 114, 121,  46,  97, 115,  36,  53,  10,  68, 105,
  99, 116, 105, 111, 110,  97, 114, 121,  14, 102, 108,  97, 115, 104,  46, 117,
 116, 105, 108, 115, 238, 138, 148,  15,  68, 105,  99, 116, 105, 111, 110,  97,
 114, 121,  67, 108,  97, 115, 115,  16,  68, 105,  99, 116, 105, 111, 110,  97,
 114, 121,  79,  98, 106, 101,  99, 116,  18, 102, 108,  97, 115, 104,  46, 117,
 116, 105, 108, 115,  58,  69, 110, 100, 105,  97, 110,  10,  66,  73,  71,  95,
  69,  78,  68,  73,  65,  78,   9,  98, 105, 103,  69, 110, 100, 105,  97, 110,
  13,  76,  73,  84,  84,  76,  69,  95,  69,  78,  68,  73,  65,  78,  12, 108,
 105, 116, 116, 108, 101,  69, 110, 100, 105,  97, 110,   6,  69, 110, 100, 105,
  97, 110,  11,  69, 110, 100, 105,  97, 110,  46,  97, 115,  36,  54,  15,  97,
 118, 109, 112, 108, 117, 115,  58,  74,  79,  98, 106, 101,  99, 116,   7,  74,
  79,  98, 106, 101,  99, 116,   6,  99, 114, 101,  97, 116, 101,  11,  99, 114,
 101,  97, 116, 101,  65, 114, 114,  97, 121,   7, 116, 111,  65, 114, 114,  97,
 121,  20,  99, 111, 110, 115, 116, 114, 117,  99, 116, 111, 114,  83, 105, 103,
 110,  97, 116, 117, 114, 101,  15, 109, 101, 116, 104, 111, 100,  83, 105, 103,
 110,  97, 116, 117, 114, 101,  14, 102, 105, 101, 108, 100,  83, 105, 103, 110,
  97, 116, 117, 114, 101,   9,  74,  97, 118,  97,  46,  97, 115,  36,  55,  12,
  74,  79,  98, 106, 101,  99, 116,  67, 108,  97, 115, 115,  97,  22,   1,   5,
   5,  23,   1,  22,   6,  23,   6,   8,  17,   5,  20,  22,  21,  24,  20,   5,
  24,  24,  24,   5,  28,  24,  28,  26,  28,  26,  23,   8,  50,   5,  56,  22,
  57,  24,  56,   5,  64,  22,  66,  23,  66,  24,  64,  26,  64,   5,  69,  22,
  71,  22,  75,  22,  78,  22,  81,  22,  84,  22,  87,  22, 123,  24,  69,   5,
 125,  24, 125,   5, 127,  24, 127,   5, 129,   1,  24, 129,   1,   5, 131,   1,
  24, 131,   1,   5, 133,   1,  24, 133,   1,   5, 135,   1,  24, 135,   1,   5,
 137,   1,  24, 137,   1,   5, 139,   1,  24, 139,   1,   5, 141,   1,  24, 141,
   1,  23, 123,  22, 167,   1,  22, 173,   1,  22, 176,   1,  22, 177,   1,  22,
 178,   1,  22, 179,   1,  22, 180,   1,  22, 181,   1,  22, 182,   1,   5, 183,
   1,   5, 185,   1,  24, 183,   1,  26, 183,   1,   5, 196,   1,  22, 197,   1,
  23, 197,   1,   5, 203,   1,  24, 203,   1,  26, 203,   1,   5, 214,   1,  24,
 214,   1,   5, 218,   1,  24, 218,   1,   5, 224,   1,  24, 224,   1,  22, 226,
   1,   5, 141,   2,  22, 153,   2,  24, 141,   2,   5, 155,   2,  23, 153,   2,
  22, 156,   2,   5, 158,   2,   5, 159,   2,  23,  57,  24, 158,   2,  26, 158,
   2,  22, 161,   2,   5, 164,   2,  24, 164,   2,   5, 170,   2,   5, 171,   2,
  24, 171,   2,   5, 179,   2,  51,   4,   1,   2,   3,   4,   4,   1,   2,   4,
   5,   1,   6,   1,   8,   8,   1,   2,   4,   5,  12,  13,  14,  15,   1,  12,
   1,  16,   9,   1,   2,   4,  15,  20,  21,  22,  23,  24,   1,  26,   1,  27,
   1,  28,   1,  29,   1,  30,   1,  31,   2,  26,  27,   3,  27,  29,  31,   3,
  26,  27,  30,   1,   5,   1,   4,   1,  21,   5,   1,   2,   4,  21,  22,   1,
  32,   4,   1,   2,  32,  52,   1,  53,   1,  54,   1,  55,   1,  56,   1,  57,
   1,  58,   1,  59,   1,  60,   1,  61,   2,  56,  57,   3,  57,  59,  61,   3,
  56,  57,  60,   8,   1,   4,   5,  15,  62,  63,  64,  65,   1,  62,   4,   1,
   4,   5,  63,   4,   1,  66,  67,  68,   1,  68,   8,   1,  15,  66,  67,  68,
  69,  70,  71,   1,  78,   4,   1,  80,  82,  83,   1,  84,   8,   1,  15,  18,
  85,  86,  87,  88,  89,   1,  85,   4,   1,  18,  86,  87,   1,  90,   4,   1,
  18,  87,  93,   4,   1,   4,   5,  96, 128,   3,   7,   1,   2,   7,   1,   3,
   9,   4,   1,   9,   7,   1,   7,   1,   8,   9,   9,   1,   7,   1,  10,   9,
  11,   1,   9,  12,   1,   9,  13,   1,   9,  14,   1,   7,   1,  15,   9,   4,
   2,   9,  16,   2,   9,  18,   3,   7,   5,  19,   9,  18,   4,   7,   5,  22,
   7,   1,  23,   7,   1,  25,   9,  26,   4,   7,   5,  27,   7,   1,  29,   9,
  30,   5,   7,   1,  31,   7,   1,  32,   7,   1,  33,   9,  34,   4,   9,  36,
   4,   9,  40,   4,   9,  41,   4,   9,  42,   4,   9,  11,   4,   9,  43,   4,
   9,  16,   4,   9,  44,   4,   9,   9,   4,   9,  30,   6,   9,  29,   4,   9,
   7,   4,   9,  45,   4,   9,  46,   4,   9,  47,   4,   9,  48,   4,   9,  49,
   4,   9,  51,   7,   9,  52,   4,   9,  53,   4,   9,  54,   4,   9,  55,   4,
   7,   4,   4,   7,  18,  58,   9,  59,   4,   9,  60,   4,   9,  61,   4,   9,
  62,   4,   7,   4,  63,   9,   4,   8,   9,  44,   8,   9,  67,   4,   7,  21,
  68,   9,  70,   4,   9,  72,   9,   9,  76,  10,   9,  79,  11,   9,  82,  12,
   9,  85,  13,   9,  88,  14,   9,  90,  15,   9,  91,  16,   9,  92,  17,   9,
  93,   4,   9,  94,   9,   9,  95,  10,   9,  96,  11,   9,  97,  12,   9,  98,
  13,   9,  99,  14,   9, 100,  15,   9, 101,  16,   9, 102,  17,   9, 103,   4,
   9, 104,   9,   9, 105,  10,   9, 106,  11,   9, 107,  12,   9, 108,  13,   9,
 109,  14,   9, 110,  15,   9, 111,  16,   9, 112,  17,   9, 113,   4,   9, 114,
   9,   9, 115,  10,   9, 116,  11,   9, 117,  12,   9, 118,  13,   9, 119,  14,
   9, 120,  15,   9, 121,  16,   9, 122,  17,   7,  32, 124,   7,  32, 126,   7,
  32, 128,   1,   7,  32, 130,   1,   7,  32, 132,   1,   7,  32, 134,   1,   7,
  32, 136,   1,   7,  32, 138,   1,   7,  32, 140,   1,   7,  32, 142,   1,   7,
  32, 143,   1,   7,  32, 144,   1,   7,  32, 145,   1,   7,  32, 146,   1,   7,
  32, 147,   1,   7,  32, 148,   1,   7,  32, 149,   1,   7,  32, 150,   1,   7,
  32, 151,   1,   7,  32, 152,   1,   9,  19,  18,   9,  22,  18,   9,  23,   2,
   9,  27,  18,   9,   4,  19,   9,  63,  19,   9,  68,  20,   9,  23,  21,   9,
 124,  22,   9,  23,  23,   9, 126,  22,   9, 128,   1,  22,   9, 130,   1,  22,
   9, 132,   1,  22,   9, 134,   1,  22,   9, 136,   1,  22,   9, 138,   1,  22,
   9, 140,   1,  22,   9, 142,   1,  22,   9, 143,   1,  22,   9, 144,   1,  22,
   9, 145,   1,  22,   9, 146,   1,  22,   9, 147,   1,  22,   9, 148,   1,  22,
   9, 149,   1,  22,   9, 150,   1,  22,   9, 151,   1,  22,   9, 152,   1,  22,
   9, 153,   1,  22,   7,  32, 153,   1,   9, 154,   1,  22,   7,  32, 154,   1,
   9, 155,   1,  22,   7,  32, 155,   1,   9, 156,   1,  22,   7,  32, 156,   1,
   9, 157,   1,  22,   7,  32, 157,   1,   9, 158,   1,  22,   7,  32, 158,   1,
   9,  70,  22,   7,  32,  70,   9,  72,  22,   7,  32,  72,   9,  76,  22,   7,
  32,  76,   9,  79,  22,   7,  32,  79,   9,  82,  22,   7,  32,  82,   9,  85,
  22,   7,  32,  85,   9,  88,  22,   7,  32,  88,   9,  90,  22,   7,  32,  90,
   9,  91,  22,   7,  32,  91,   9,  92,  22,   7,  32,  92,   9,  93,  22,   7,
  32,  93,   9,  94,  22,   7,  32,  94,   9,  95,  22,   7,  32,  95,   9,  96,
  22,   7,  32,  96,   9,  97,  22,   7,  32,  97,   9,  98,  22,   7,  32,  98,
   9,  99,  22,   7,  32,  99,   9, 100,  22,   7,  32, 100,   9, 101,  22,   7,
  32, 101,   9, 102,  22,   7,  32, 102,   9, 159,   1,  18,   9,   4,  24,   9,
  63,  24,   9,  16,  24,   9,  68,  25,   9, 174,   1,   4,   9, 175,   1,   4,
   9, 153,   1,  26,   9, 154,   1,  26,   9, 155,   1,  26,   9, 156,   1,  26,
   9, 157,   1,  26,   9, 158,   1,  26,   9,  70,  26,   9,  72,  27,   9,  76,
  28,   9,  79,  29,   9,  82,  30,   9,  85,  31,   9,  88,  32,   9,  90,  33,
   9,  91,  34,   9,  92,  35,   9,  93,  26,   9,  94,  27,   9,  95,  28,   9,
  96,  29,   9,  97,  30,   9,  98,  31,   9,  99,  32,   9, 100,  33,   9, 101,
  34,   9, 102,  35,   9, 103,  26,   9, 104,  27,   9, 105,  28,   9, 106,  29,
   9, 107,  30,   9, 108,  31,   9, 109,  32,   9, 110,  33,   9, 111,  34,   9,
 112,  35,   9, 113,  26,   9, 114,  27,   9, 115,  28,   9, 116,  29,   9, 117,
  30,   9, 118,  31,   9, 119,  32,   9, 120,  33,   9, 121,  34,   9, 122,  35,
   9, 124,  26,   9, 126,  27,   9, 128,   1,  28,   9, 130,   1,  29,   9, 132,
   1,  30,   9, 134,   1,  31,   9, 136,   1,  32,   9, 138,   1,  33,   9, 140,
   1,  34,   9, 142,   1,  35,   9, 143,   1,  26,   9, 144,   1,  27,   9, 145,
   1,  28,   9, 146,   1,  29,   9, 147,   1,  30,   9, 148,   1,  31,   9, 149,
   1,  32,   9, 150,   1,  33,   9, 151,   1,  34,   9, 152,   1,  35,   7,   4,
  12,   9, 184,   1,  36,   9,  63,  36,   9,  61,  36,   9, 186,   1,  36,   9,
  13,   4,   9, 187,   1,   4,   9, 184,   1,  37,   9, 186,   1,   4,   9,  14,
   4,   9, 188,   1,   4,   9, 189,   1,   4,   9,  12,  19,   9,  23,  38,   9,
  12,  24,   7,   1, 193,   1,   7,   1, 194,   1,   9, 195,   1,  39,   9, 198,
   1,  39,   7,   1, 199,   1,   9, 200,   1,  40,   9, 201,   1,  39,   9, 198,
   1,  40,   9, 202,   1,  40,   9, 204,   1,  41,   9, 206,   1,  41,   9, 209,
   1,  41,   9, 204,   1,   4,   9, 206,   1,   4,   9, 209,   1,   4,   9, 211,
   1,   4,   9, 212,   1,   4,   7,  67, 213,   1,   9, 215,   1,   4,   9, 216,
   1,   4,   7,  67, 217,   1,   9, 219,   1,   4,   9, 220,   1,   4,   9, 221,
   1,   4,   9, 222,   1,   4,   7,  67, 223,   1,   7,  67, 225,   1,   9,  23,
  39,   9, 213,   1,  42,   9, 217,   1,  42,   9, 223,   1,  42,   9, 225,   1,
  42,   9, 237,   1,  42,   9, 239,   1,  42,   9, 241,   1,  42,   9, 243,   1,
  42,   9, 245,   1,  42,   9, 247,   1,  42,   9, 201,   1,  40,   9, 249,   1,
  42,   9, 251,   1,  42,   9, 253,   1,  42,   9, 255,   1,  42,   9, 129,   2,
  42,   9, 130,   2,  42,   9, 131,   2,  42,   9, 195,   1,  40,   9, 133,   2,
  42,   9, 135,   2,  42,   9, 137,   2,  42,   9, 139,   2,  42,   7,   1, 142,
   2,   7,   1, 143,   2,   7,   1, 144,   2,   7,   1, 145,   2,   7,   1, 146,
   2,   7,   1, 147,   2,   7,   1, 148,   2,   9, 142,   2,   4,   9, 143,   2,
   4,   9, 144,   2,   4,   9, 145,   2,   4,   9, 146,   2,   4,   9, 147,   2,
   4,   9, 148,   2,   4,   9, 149,   2,   4,   9, 150,   2,   4,   9, 151,   2,
   4,   9, 152,   2,   4,   7,  80, 154,   2,   9,  23,  43,   9, 154,   2,  44,
   9, 184,   1,  45,   9, 184,   1,  46,   7,  18, 160,   2,   9,  23,  47,   9,
 160,   2,  48,   7,   1, 165,   2,   7,   1, 167,   2,   9, 165,   2,   4,   9,
 167,   2,   4,   7,  18, 169,   2,   9,  23,  49,   9, 169,   2,  48,   7,   4,
 172,   2,   9, 173,   2,   4,   9, 174,   2,   4,   9, 175,   2,   4,   9, 176,
   2,   4,   9, 177,   2,   4,   9, 178,   2,   4,   9,  23,  50,   9, 172,   2,
  24, 217,   1,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,
   1,   1,   0,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   5,   1,   0,   0,   7,   1,   0,   0,   0,   1,
   4,   0,   0,   1,   4,   1,  12,   5,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1,  20,  20,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   1,   1,  25,   1,  32,   1,  25,   5,   1,
  32,   0,   5,   1,  32,   0,   5,   1,  32,   0,   5,   1,  32,   1,   1,  26,
   1,  32,   1,   1,   5,   1,  32,   0,   1,   1,  32,   0,   2,   1,  32,   0,
   7,   1,  32,   0,  26,   1,  32,   0,   5,   1,  32,   0,  20,   1,  32,   0,
  20,   1,  32,   0,  20,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,
   1,   1,  32,   1,   2,  19,   1,  32,   0,  25,   1,  32,   0,  25,   1,  32,
   1,   1,  27,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   1,   2,   5,
   1,  32,   1,   5,   5,   1,  32,   2,   1,   5,   5,   1,  32,   1,  52,   5,
   1,  32,   2,   2,   5,  52,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   5,   1,   0,   0,   2,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,
   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,
   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0, 148,   2,   1,  32,   0,   7,   1,  32,   1,
   1, 148,   2,   1,  32,   1,   0, 148,   2,   1,   0,   2,   0,  52,   7,   1,
  40,   1,   1,   3,   1,  12,   5,   1,  32,   2,   0,   5,   7,   1,   8,   1,
   1,   3,   0,  52,   1,  32,   1,   0,  52,   1,  32,   0,   0,   1,   0,   1,
   5,   5,   1,  32,   1,  19, 163,   2,   1,  32,   1,  26, 163,   2,   1,  32,
   2,   2,  19, 164,   2,   1,  32,   3,  20,  19, 164,   2,   7,   1,  32,   2,
  20,  19, 164,   2,   1,   0,   2,  20,  19, 164,   2,   1,   0,   2,  20,  19,
 164,   2,   1,   0,   0,  20,   1,  32,   0,  19,   1,  32,   2,  19,  19,   2,
   1,  40,   1,  10,  10,   1,  20,   0,   1,  32,   1,   1, 163,   2,   1,  32,
   0,   0,   1,   2,   1,   1, 163,   2,   1,   2,   1,   1,   2,   1,  32,   0,
   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,
   0,   1,   0,   0,   5,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,  32,   0,  20,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   2,   0,  25,  25,   1,  40,   1,   2,   3,   1,  25,  25,   1,
  40,   1,   2,   3,   1,   0, 163,   2,   1,  32,   0, 163,   2,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1,   1,   2,   1,  32,
   1,   0,   2,   1,   8,   1,  10,  10,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1, 247,   2,   5,
   1,  36,   3, 247,   2, 247,   2,  25,  26,   1,  40,   1,  12,  12,   1,  26,
 247,   2,   1,  32,   1,   5,   5,   1,  36,   2,   5, 247,   2,   5,   1,  36,
   2,   5, 247,   2,   5,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,  37,
  35,   0,  37,   1,  38,  39,  73,   1,   0,  74,  73,   1,   0,  77,  73,   1,
   0,  80,  73,   1,   0,  83,  73,   1,   0,  86,  73,   1,   0,  89,  73,   2,
   0,   0,  74,  77,  73,   3,   0,   0,   0,  83,  77,  89,  73,   3,   0,   0,
   0,  86,  74,  77, 160,   1,   3, 161,   1, 163,   1, 165,   1, 162,   1, 164,
   1, 166,   1, 160,   1,   3, 161,   1, 169,   1, 165,   1, 168,   1, 170,   1,
 171,   1, 160,   1,   2, 161,   1, 165,   1, 172,   1, 171,   1, 160,   1,   4,
 161,   1, 191,   1, 163,   1, 165,   1, 190,   1, 170,   1, 192,   1, 171,   1,
 160,   1,   4, 161,   1, 163,   1, 165,   1, 229,   1, 227,   1, 228,   1, 171,
   1, 230,   1, 160,   1,   4, 161,   1, 163,   1, 165,   1, 229,   1, 231,   1,
 232,   1, 171,   1, 230,   1, 160,   1,   4, 161,   1, 163,   1, 165,   1, 229,
   1, 233,   1, 234,   1, 171,   1, 230,   1, 160,   1,   4, 161,   1, 163,   1,
 165,   1, 229,   1, 235,   1, 236,   1, 171,   1, 230,   1, 160,   1,   1,   0,
 238,   1, 160,   1,   1,   0, 240,   1, 160,   1,   1,   0, 242,   1, 160,   1,
   1,   0, 244,   1, 160,   1,   1,   0, 246,   1, 160,   1,   1,   0, 248,   1,
 160,   1,   1,   0, 250,   1, 160,   1,   1,   0, 252,   1, 160,   1,   1,   0,
 254,   1, 160,   1,   1,   0, 128,   2, 160,   1,   1,   0, 132,   2, 160,   1,
   1,   0, 134,   2, 160,   1,   1,   0, 136,   2, 160,   1,   1,   0, 138,   2,
 160,   1,   1,   0, 140,   2, 160,   1,   2, 161,   1, 165,   1, 157,   2, 171,
   1, 160,   1,   4, 161,   1, 191,   1, 163,   1, 165,   1, 162,   2, 170,   1,
 163,   2, 171,   1, 160,   1,   3, 161,   1, 163,   1, 165,   1, 180,   2, 172,
   2, 171,   1,  35,  16,   0,   5,   0,  38,   1,  15,   1,   0,  37,  18,  19,
   9,   9,   0,  41,   1,  17,   1,   0,  40,  22,  19,   9,  11,   0,  44,   1,
  21,   1,   0,  43,  51,  19,   9,  13,   0,  68,   0,  57,  19,   9,  19,   0,
  75,   0,  61,  19,  11,  23,   0,  79,   0, 102,  19,   9,  33,   0, 111,  50,
  62,   0,   0,   2,  11,  11,  63,  64,   0,   2,  11,  11,   1,   2,  64,  64,
   0,   2,  11,  11,   1,   3,  65,  64,   0,   2,  11,  11,   1,   4,  66,  64,
   0,   2,  11,  11,   1,   5,  67,  64,   0,   2,  11,  11,   1,   6,  68,  64,
   0,   2,  11,  11,   1,   7,  69,  64,   0,   2,  11,  11,   1,   8,  70,  64,
   0,   2,  11,  11,   1,   9,  71,  64,   0,   2,  11,  11,   1,  10,  72,   6,
   0,   2,  11,  11,  73,  70,   0,   2,  11,  11,   1,   2,  74,  70,   0,   2,
  11,  11,   1,   3,  75,  70,   0,   2,  11,  11,   1,   4,  76,  70,   0,   2,
  11,  11,   1,   5,  77,  70,   0,   2,  11,  11,   1,   6,  78,  70,   0,   2,
  11,  11,   1,   7,  79,  70,   0,   2,  11,  11,   1,   8,  80,  70,   0,   2,
  11,  11,   1,   9,  81,  70,   0,   2,  11,  11,   1,  10,  82,   1,   0,  81,
  83,  65,   0,  82,   1,   2,  84,  65,   0,  83,   1,   3,  85,  65,   0,  84,
   1,   4,  86,  65,   0,  85,   1,   5,  87,  65,   0,  86,   1,   6,  88,  65,
   0,  87,   1,   7,  89,  65,   0,  88,   1,   8,  90,  65,   0,  89,   1,   9,
  91,  65,   0,  90,   1,  10,  92,   2,   0,  91,  93,  66,   0,  92,   1,   2,
  94,  66,   0,  93,   1,   3,  95,  66,   0,  94,   1,   4,  96,  66,   0,  95,
   1,   5,  97,  66,   0,  96,   1,   6,  98,  66,   0,  97,   1,   7,  99,  66,
   0,  98,   1,   8, 100,  66,   0,  99,   1,   9, 101,  66,   0, 100,   1,  10,
  92,   3,   0, 101,  93,  67,   0, 102,   1,   2,  94,  67,   0, 103,   1,   3,
  95,  67,   0, 104,   1,   4,  96,  67,   0, 105,   1,   5,  97,  67,   0, 106,
   1,   6,  98,  67,   0, 107,   1,   7,  99,  67,   0, 108,   1,   8, 100,  67,
   0, 109,   1,   9, 101,  67,   0, 110,   1,  10, 103,  19,   9,  35,   0, 113,
   0, 104,  19,   9,  37,   0, 115,   0, 105,  19,   9,  39,   0, 117,   0, 106,
  19,   9,  41,   0, 119,   0, 107,  19,   9,  43,   0, 121,   0, 108,  19,   9,
  45,   0, 123,   0, 109,  19,   9,  47,   0, 125,   0, 110,  19,   9,  49,   0,
 127,   0, 111,  19,   9,  51,   0, 129,   1,   0, 112,   0,   5,   0, 131,   1,
   0, 113,   0,   5,   0, 133,   1,   0, 114,   0,   5,   0, 135,   1,   0, 115,
   0,   5,   0, 137,   1,   0, 116,   0,   5,   0, 139,   1,   0, 117,   0,   5,
   0, 141,   1,   0, 118,   0,   5,   0, 143,   1,   0, 119,   0,   5,   0, 145,
   1,   0, 120,   0,   5,   0, 147,   1,   0, 121,   0,   5,   0, 149,   1,   0,
 148,   2,  19,   9,  64,   0, 155,   1,   6, 155,   2,   1,   0, 154,   1, 156,
   2,   1,   0, 156,   1, 157,   2,   1,   0, 157,   1, 158,   2,   1,   0, 158,
   1, 159,   2,   2,   0, 159,   1, 159,   2,   3,   0, 160,   1, 180,   2,  19,
  11,  70,   0, 184,   1,   5, 175,   2,   6,   0,   5,   0, 176,   2,   6,   0,
   5,   0, 177,   2,   6,   0,   7,   0, 178,   2,   6,   0,  20,   0, 179,   2,
   1,   0, 183,   1, 183,   2,  19,   9,  73,   0, 186,   1,   2, 181,   2,   6,
   0,  20,   0, 182,   2,   6,   0,  26,   0, 188,   2, 183,   2,  11,  75,   0,
 190,   1,   4, 184,   2,   6,   0,  20,   0, 185,   2,   6,   0,  12,   0, 186,
   2,   2,   0, 188,   1, 187,   2,   2,   0, 189,   1, 189,   2, 183,   2,  11,
  77,   0, 192,   1,   2, 184,   2,   6,   0,  20,   0, 187,   2,   6,   0,  20,
   0, 232,   2,  19,   9,  81,   0, 199,   1,   0, 237,   2,  19,   8,  88,   0,
 203,   1,   1, 236,   2,   1,   0, 202,   1, 244,   2,  19,   9,  92,   0, 206,
   1,   0, 247,   2,  19,   9,  95,   0, 215,   1,   0,  36,   0,  39,   0,  42,
   0,  45,  23,  28,  81,   3,  46,   1,   0,  29,  81,   4,  47,   1,   1,  30,
  17,   5,  48,  31,  17,   6,  49,  32,  17,   7,  50,  33,  17,   8,  51,  34,
  17,   9,  52,  35,  17,  10,  53,  36,  17,  11,  54,  37,  17,  12,  55,  38,
  17,  13,  56,  39,   6,   1,  26,   0,  40,  17,  14,  57,  41,  18,  15,  58,
  42,  18,  16,  59,  43,  18,  17,  60,  44,  17,  18,  61,  45,  17,  19,  62,
  46,  17,  20,  63,  47,  17,  21,  64,  48,  18,  22,  65,  49,  18,  23,  66,
  50,  17,  24,  67,  69,   5,  53,  17,   3,  70,  54,  17,   4,  71,  34,  17,
   5,  72,  55,  17,   6,  73,  56,  17,   7,  74,  76,   2,  60,  18,   3,  77,
  36,  18,   4,  78,  80,   0, 112,   0, 114,   0, 116,   0, 118,   0, 120,   0,
 122,   0, 124,   0, 126,   0, 128,   1,   0, 130,   1,   0, 132,   1,   0, 134,
   1,   0, 136,   1,   0, 138,   1,   0, 140,   1,   0, 142,   1,   0, 144,   1,
   0, 146,   1,   0, 148,   1,   0, 151,   1,   2, 153,   2,  18,   3, 152,   1,
 154,   2,  18,   4, 153,   1, 182,   1,   0, 185,   1,   0, 187,   1,   0, 191,
   1,   0, 194,   1,  11, 221,   2,   6,   1,  25,   1,   3, 222,   2,   6,   2,
  25,   3,   3, 223,   2,   6,   3,  25,   2,   3, 224,   2,   6,   4,  25,   4,
   3, 225,   2,   6,   5,  25,   5,   3, 226,   2,   6,   6,   0,   3,   3, 227,
   2,   6,   7,   0,   2,   3, 228,   2,  17,   3, 195,   1, 229,   2,  17,   4,
 196,   1, 230,   2,  17,   5, 197,   1, 231,   2,  17,   6, 198,   1, 201,   1,
   0, 205,   1,   2, 242,   2,   6,   1,   5, 166,   2,   1, 243,   2,   6,   2,
   5, 168,   2,   1, 208,   1,   6, 248,   2,  17,   3, 209,   1, 249,   2,  17,
   4, 210,   1, 250,   2,  17,   5, 211,   1, 251,   2,  17,   6, 212,   1, 252,
   2,  17,   7, 213,   1, 253,   2,  17,   8, 214,   1,   7, 161,   1,   1, 162,
   2,  68,   0,  26,   1,  14, 193,   1,  23, 191,   2,  68,   1,  27,   1,  15,
 192,   2,  68,   2,  28,   1,  16, 193,   2,  68,   3,  29,   1,  17, 194,   2,
  68,   4,  30,   1,  18, 195,   2,  65,  37, 181,   1,   1,  19, 196,   2,  65,
  38, 180,   1,   1,  20, 197,   2,  65,  39, 179,   1,   1,  21, 198,   2,  65,
  40, 178,   1,   1,  22, 199,   2,  65,  41, 177,   1,   1,  23, 200,   2,   1,
  42, 176,   1, 201,   2,  65,  43, 174,   1,   1,  24, 202,   2,  65,  44, 173,
   1,   1,  25, 203,   2,  65,  45, 172,   1,   1,  26, 204,   2,  65,  46, 171,
   1,   1,  27, 205,   2,  65,  47, 170,   1,   1,  28, 206,   2,   1,  48, 169,
   1, 207,   2,   1,  49, 168,   1, 208,   2,   1,  50, 167,   1, 209,   2,  65,
  51, 166,   1,   1,  29, 210,   2,  65,  52, 165,   1,   1,  30, 211,   2,  65,
  53, 164,   1,   1,  31, 212,   2,  65,  54, 163,   1,   1,  32, 213,   2,  65,
  55, 162,   1,   1,  33, 200,   1,   1, 234,   2,  68,   1,  31,   1,  34, 204,
   1,   1, 239,   2,  68,   1,  32,   1,  35, 207,   1,   1, 246,   2,   4,   1,
  33, 216,   1,   1, 255,   2,  68,   1,  34,   1,  36, 150,   1,  89, 203,   1,
   6,   0,   0,  16,   8, 122,   4,   0,   0, 123,   4,   0,   1, 125,  68,   0,
   2,   1,  11, 204,   1,  68,   0,   3,   1,  12, 205,   1,  68,   0,   4,   1,
  13, 206,   1,   1,   1,  35, 207,   1,   4,   0,   5, 208,   1,   1,   2,  34,
 209,   1,   1,   3,  33,  33,   1,   4,  32,  37,   1,   5,  31,  40,   1,   6,
  30, 210,   1,   6,   0,   0,   1,   6, 211,   1,   6,   0,   0,   2,   6, 212,
   1,   6,   0,   0,   3,   6, 213,   1,   6,   0,   0,   4,   6, 214,   1,   6,
   0,   0,   5,   6, 215,   1,   6,   0,   0,   6,   6, 216,   1,   0,   0,   2,
   0, 217,   1,  64,   0,   2,   0,   1,   2, 218,   1,  64,   0,   2,   0,   1,
   3, 219,   1,  64,   0,   2,   0,   1,   4, 220,   1,  64,   0,   2,   0,   1,
   5, 221,   1,  64,   0,   2,   0,   1,   6, 222,   1,  64,   0,   2,   0,   1,
   7, 223,   1,  64,   0,   2,   0,   1,   8, 224,   1,  64,   0,   2,   0,   1,
   9, 225,   1,  64,   0,   2,   0,   1,  10, 226,   1,   6,   0,   2,  11,  11,
 227,   1,  70,   0,   2,  11,  11,   1,   2, 228,   1,  70,   0,   2,  11,  11,
   1,   3, 229,   1,  70,   0,   2,  11,  11,   1,   4, 230,   1,  70,   0,   2,
  11,  11,   1,   5, 231,   1,  70,   0,   2,  11,  11,   1,   6, 232,   1,  70,
   0,   2,  11,  11,   1,   7, 233,   1,  70,   0,   2,  11,  11,   1,   8, 234,
   1,  70,   0,   2,  11,  11,   1,   9, 235,   1,  70,   0,   2,  11,  11,   1,
  10, 236,   1,   1,   7,  29, 237,   1,  65,   8,  28,   1,   2, 238,   1,  65,
   9,  27,   1,   3, 239,   1,  65,  10,  26,   1,   4, 240,   1,  65,  11,  25,
   1,   5, 241,   1,  65,  12,  24,   1,   6, 242,   1,  65,  13,  23,   1,   7,
 243,   1,  65,  14,  22,   1,   8, 244,   1,  65,  15,  21,   1,   9, 245,   1,
  65,  16,  20,   1,  10, 246,   1,   2,  17,  19, 247,   1,  66,  18,  18,   1,
   2, 248,   1,  66,  19,  17,   1,   3, 249,   1,  66,  20,  16,   1,   4, 250,
   1,  66,  21,  15,   1,   5, 251,   1,  66,  22,  14,   1,   6, 252,   1,  66,
  23,  13,   1,   7, 253,   1,  66,  24,  12,   1,   8, 254,   1,  66,  25,  11,
   1,   9, 255,   1,  66,  26,  10,   1,  10, 246,   1,   3,  27,   9, 247,   1,
  67,  28,   8,   1,   2, 248,   1,  67,  29,   7,   1,   3, 249,   1,  67,  30,
   6,   1,   4, 250,   1,  67,  31,   5,   1,   5, 251,   1,  67,  32,   4,   1,
   6, 252,   1,  67,  33,   3,   1,   7, 253,   1,  67,  34,   2,   1,   8, 254,
   1,  67,  35,   1,   1,   9, 255,   1,  67,  36,   0,   1,  10, 128,   2,   4,
   0,   6, 129,   2,  68,   0,   7,   1,   2, 130,   2,  68,   0,   8,   1,   3,
 131,   2,  68,   0,   9,   1,   4, 132,   2,  68,   0,  10,   1,   5, 133,   2,
  68,   0,  11,   1,   6, 134,   2,  68,   0,  12,   1,   7, 135,   2,  68,   0,
  13,   1,   8, 136,   2,  68,   0,  14,   1,   9, 137,   2,  68,   0,  15,   1,
  10, 138,   2,   4,   0,  16, 139,   2,  68,   0,  17,   1,   2, 140,   2,  68,
   0,  18,   1,   3, 141,   2,  68,   0,  19,   1,   4, 142,   2,  68,   0,  20,
   1,   5, 143,   2,  68,   0,  21,   1,   6, 144,   2,  68,   0,  22,   1,   7,
 145,   2,  68,   0,  23,   1,   8, 146,   2,  68,   0,  24,   1,   9, 147,   2,
  68,   0,  25,   1,  10, 142,   1,   0,   1,   2,   1,   2,   3, 208,  48,  71,
   0,   0,   1,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   2,   1,   2,
   1,   2,   3, 208,  48,  71,   0,   0,   3,   1,   2,   1,   2,   3, 208,  48,
  71,   0,   0,   4,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   5,   1,
   2,   1,   2,   3, 208,  48,  71,   0,   0,   6,   1,   2,   1,   2,   3, 208,
  48,  71,   0,   0,   7,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   8,
   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   9,   1,   2,   1,   2,   3,
 208,  48,  71,   0,   0,  10,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,
   0,  11,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  12,   1,   1,
   1,   2,   4, 208,  48,  38,  72,   0,   0,  13,   1,   1,   1,   2,   4, 208,
  48,  38,  72,   0,   0,  14,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,
   0,  15,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  16,   1,   1,
   1,   2,   4, 208,  48,  38,  72,   0,   0,  17,   1,   1,   1,   2,   4, 208,
  48,  38,  72,   0,   0,  18,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,
   0,  19,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  20,   1,   1,
   1,   2,   4, 208,  48,  38,  72,   0,   0,  21,   1,   1,   1,   2,   4, 208,
  48,  38,  72,   0,   0,  22,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,
   0,  23,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  24,   1,   1,
   1,   2,   4, 208,  48,  38,  72,   0,   0,  25,   1,   1,   1,   2,   4, 208,
  48,  38,  72,   0,   0,  26,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,
   0,  27,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  28,   1,   1,
   1,   2,   4, 208,  48,  38,  72,   0,   0,  29,   1,   1,   1,   2,   4, 208,
  48,  38,  72,   0,   0,  30,   1,   1,   1,   2,  10, 208,  48,  93,   3, 102,
   3,  70,   4,   0,  72,   0,   0,  31,   1,   1,   1,   2,  10, 208,  48,  93,
   3, 102,   3,  70,   6,   0,  72,   0,   0,  32,   2,   2,   1,   2,  12, 208,
  48,  93,   3, 102,   3, 209,  70,   8,   1,  41,  71,   0,   0,  33,   2,   2,
   1,   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   8,   1,  41,  71,   0,
   0,  34,   2,   2,   1,   2,  13, 208,  48,  93,   9, 102,   9, 102,  10, 209,
  70,  11,   1,  72,   0,   0,  35,   1,   1,   1,   2,  11, 208,  48,  93,  13,
 102,  13,  70,  14,   0,  41,  71,   0,   0,  36,   0,   1,   3,   3,   1,  71,
   0,   0,  39,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  40,   1,   1,
   4,   5,   3, 208,  48,  71,   0,   0,  41,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0,  42,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0,  44,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  45,
   2,   1,   3,   4,  12, 208,  48,  94,  23,  93,  24,  70,  24,   0, 104,  23,
  71,   0,   0,  68,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0,  69,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  75,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  76,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0,  77,   1,   1,   3,   4,   5, 208,  48,  44,  65,  72,
   0,   0,  78,   1,   1,   3,   4,  10, 208,  48,  93,  58, 102,  58,  70,  59,
   0,  72,   0,   0,  79,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0,  80,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  81,   1,   1,
   4,   5,   4, 208,  48,  38,  72,   0,   0,  82,   1,   1,   4,   5,   4, 208,
  48,  38,  72,   0,   0,  83,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,
   0,  84,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  85,   1,   1,
   4,   5,   4, 208,  48,  38,  72,   0,   0,  86,   1,   1,   4,   5,   4, 208,
  48,  38,  72,   0,   0,  87,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,
   0,  88,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  89,   1,   1,
   4,   5,   4, 208,  48,  38,  72,   0,   0,  90,   1,   1,   4,   5,   4, 208,
  48,  38,  72,   0,   0,  91,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,
   0,  92,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  93,   1,   1,
   4,   5,   4, 208,  48,  38,  72,   0,   0,  94,   1,   1,   4,   5,   4, 208,
  48,  38,  72,   0,   0,  95,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,
   0,  96,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  97,   1,   1,
   4,   5,   4, 208,  48,  38,  72,   0,   0,  98,   1,   1,   4,   5,   4, 208,
  48,  38,  72,   0,   0,  99,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,
   0, 100,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 101,   1,   2,
   4,   5,   3, 208,  48,  71,   0,   0, 102,   1,   2,   4,   5,   3, 208,  48,
  71,   0,   0, 103,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 104,   1,
   2,   4,   5,   3, 208,  48,  71,   0,   0, 105,   1,   2,   4,   5,   3, 208,
  48,  71,   0,   0, 106,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 107,
   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 108,   1,   2,   4,   5,   3,
 208,  48,  71,   0,   0, 109,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0,
 110,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 111,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 112,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 113,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 114,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 115,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 116,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 117,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 118,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 119,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 120,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 121,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 122,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 123,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 124,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 125,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 126,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 127,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 128,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 129,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 130,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 132,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 134,   1,   0,   1,   3,   3,   1,  71,   0,   0, 136,   1,   0,   1,   3,   3,
   1,  71,   0,   0, 138,   1,   0,   1,   3,   3,   1,  71,   0,   0, 140,   1,
   0,   1,   3,   3,   1,  71,   0,   0, 142,   1,   0,   1,   3,   3,   1,  71,
   0,   0, 144,   1,   0,   1,   3,   3,   1,  71,   0,   0, 146,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 148,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 150,   1,   3,   1,   1,   3, 197,   4, 208,  48,  93, 122,  32,  88,   0, 104,
  16,  93, 123,  93,  19, 102,  19,  48,  93, 124, 102, 124,  88,   1,  29, 104,
  18,  93, 125,  93,  19, 102,  19,  48,  93, 124, 102, 124,  88,   2,  29, 104,
  22,  93, 126,  93,  19, 102,  19,  48,  93, 124, 102, 124,  88,   3,  29, 104,
  51,  93, 127,  93,  19, 102,  19,  48,  93, 124, 102, 124,  88,   4,  29, 104,
  57,  93, 128,   1,  93,  19, 102,  19,  48,  93, 129,   1, 102, 129,   1,  88,
   5,  29, 104,  61,  93, 130,   1,  93,  19, 102,  19,  48,  93, 131,   1, 102,
 131,   1,  88,   6,  29, 104, 102,  93, 132,   1,  93,  19, 102,  19,  48,  93,
 131,   1, 102, 131,   1,  88,   7,  29, 104, 103,  93, 133,   1,  93,  19, 102,
  19,  48,  93, 131,   1, 102, 131,   1,  88,   8,  29, 104, 104,  93, 134,   1,
  93,  19, 102,  19,  48,  93, 131,   1, 102, 131,   1,  88,   9,  29, 104, 105,
  93, 135,   1,  93,  19, 102,  19,  48,  93, 131,   1, 102, 131,   1,  88,  10,
  29, 104, 106,  93, 136,   1,  93,  19, 102,  19,  48,  93, 131,   1, 102, 131,
   1,  88,  11,  29, 104, 107,  93, 137,   1,  93,  19, 102,  19,  48,  93, 131,
   1, 102, 131,   1,  88,  12,  29, 104, 108,  93, 138,   1,  93,  19, 102,  19,
  48,  93, 131,   1, 102, 131,   1,  88,  13,  29, 104, 109,  93, 139,   1,  93,
  19, 102,  19,  48,  93, 131,   1, 102, 131,   1,  88,  14,  29, 104, 110,  93,
 140,   1,  93,  19, 102,  19,  48,  93, 131,   1, 102, 131,   1,  88,  15,  29,
 104, 111,  93, 141,   1,  32,  88,  16, 104, 112,  93, 142,   1,  32,  88,  17,
 104, 113,  93, 143,   1,  32,  88,  18, 104, 114,  93, 144,   1,  32,  88,  19,
 104, 115,  93, 145,   1,  32,  88,  20, 104, 116,  93, 146,   1,  32,  88,  21,
 104, 117,  93, 147,   1,  32,  88,  22, 104, 118,  93, 148,   1,  32,  88,  23,
 104, 119,  93, 149,   1,  32,  88,  24, 104, 120,  93, 150,   1,  32,  88,  25,
 104, 121,  93, 151,   1,  37, 149,   5,  37, 148,   5, 161, 104, 152,   1,  93,
 153,   1,  37, 150,   5,  37, 148,   5, 161, 104, 154,   1,  93, 155,   1,  37,
 151,   5,  37, 148,   5, 161, 104, 156,   1,  93, 157,   1,  37, 152,   5,  37,
 148,   5, 161, 104, 158,   1,  93, 159,   1,  37, 153,   5,  37, 148,   5, 161,
 104, 160,   1,  93, 161,   1,  37, 154,   5,  37, 148,   5, 161, 104, 162,   1,
  93, 163,   1,  38,  97, 164,   1,  93, 165,   1,  38,  97, 166,   1,  93, 167,
   1,  38,  97, 168,   1,  93, 169,   1,  38,  97, 170,   1,  93, 171,   1,  38,
  97, 172,   1,  93, 173,   1,  38,  97, 174,   1,  93, 175,   1,  38,  97, 176,
   1,  93, 177,   1,  38,  97, 178,   1,  93, 179,   1,  38,  97, 180,   1,  93,
 181,   1,  38,  97, 182,   1,  93, 183,   1,  38, 104, 184,   1,  93, 185,   1,
  38, 104, 186,   1,  93, 187,   1,  38, 104, 188,   1,  93, 189,   1,  38, 104,
 190,   1,  93, 191,   1,  38, 104, 192,   1,  93, 193,   1,  38, 104, 194,   1,
  93, 195,   1,  38, 104, 196,   1,  93, 197,   1,  38, 104, 198,   1,  93, 199,
   1,  38, 104, 200,   1,  93, 201,   1,  38, 104, 202,   1,  71,   0,   0, 151,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 155,   1,   2,   2,   4,
   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 149,   2,   1,  41,  71,   0,
   0, 158,   1,   3,   3,   4,   5,  20, 208,  48, 208,  93, 150,   2, 102, 150,
   2, 209,  70, 151,   2,   1, 210,  70, 152,   2,   2,  72,   0,   0, 161,   1,
   2,   1,   1,   3,  23, 208,  48,  93, 160,   2,  93,  19, 102,  19,  48,  93,
 161,   2, 102, 161,   2,  88,  26,  29, 104, 148,   2,  71,   0,   0, 167,   1,
   4,   3,   1,   2,  14, 208,  48,  93, 165,   2, 209, 210,  36,   1,  70, 165,
   2,   3,  72,   0,   0, 168,   1,   4,   3,   1,   2,  14, 208,  48,  93, 165,
   2, 209, 210,  36,   2,  70, 165,   2,   3,  72,   0,   0, 169,   1,   4,   3,
   1,   2,  14, 208,  48,  93, 165,   2, 209, 210,  36,   0,  70, 165,   2,   3,
  72,   0,   0, 175,   1,   3,   3,   3,   6,  47,  87,  42, 213,  48, 101,   0,
  38, 118, 109,   1,  93, 166,   2,  76, 166,   2,   0,  41,  16,  20,   0,   0,
 209,  48,  90,   0,  42, 214,  42,  48,  43, 109,   1, 101,   0,  39, 118, 109,
   1,  29,   8,   2, 101,   0, 108,   1,  72,   1,  10,  18,  22,   0, 167,   2,
   1, 168,   2,   0,   1,   2,   0, 176,   1,   2,   3,   2,   4,  60, 208,  48,
  87,  42, 214,  48, 101,   1,  33, 130, 109,   2, 101,   1, 209, 109,   1, 101,
   1, 108,   1,  32,  19,  24,   0,   0, 101,   1,  64, 175,   1, 130, 109,   2,
  93, 169,   2, 101,   1, 108,   2,  70, 169,   2,   1,  41,  16,   9,   0,   0,
  93, 169,   2,  32,  70, 169,   2,   1,  41,  71,   0,   2, 170,   2,   0,   1,
 163,   2,   0, 171,   2,   0,   2,   0,   0, 182,   1,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0, 183,   1,   3,   1,   4,   5,  50, 208,  48, 208, 102,
 172,   2,  44, 205,   1, 160, 208, 102, 173,   2, 118,  18,  26,   0,   0,  44,
 207,   1, 208, 102, 173,   2, 160,  44, 208,   1, 160, 208, 102, 174,   2, 160,
  44, 210,   1, 160, 130,  16,   3,   0,   0,  44,   1, 130, 160,  72,   0,   0,
 184,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 185,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 186,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 187,   1,   1,   1,   4,   5,
   3, 208,  48,  71,   0,   0, 190,   1,   1,   1,   5,   6,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 191,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 192,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 193,   1,   2,   1,   1,   4,  89, 208,  48, 101,   0,  93,  19, 102,  19,  48,
  93, 190,   2, 102, 190,   2,  88,  27,  29, 104, 180,   2, 101,   0,  93,  19,
 102,  19,  48,  93, 190,   2, 102, 190,   2,  88,  28,  29, 104, 183,   2, 101,
   0,  93,  19, 102,  19,  48,  93, 183,   2, 102, 183,   2,  48, 100, 108,   2,
  88,  29,  29,  29, 104, 188,   2, 101,   0,  93,  19, 102,  19,  48,  93, 183,
   2, 102, 183,   2,  48, 100, 108,   2,  88,  30,  29,  29, 104, 189,   2,  71,
   0,   0, 194,   1,   2,   1,   3,   4,  59, 208,  48,  94, 214,   2,  36,   0,
 104, 214,   2,  94, 215,   2,  36,   1, 104, 215,   2,  94, 216,   2,  36,   2,
 104, 216,   2,  94, 217,   2,  36,   3, 104, 217,   2,  94, 218,   2,  36,   4,
 104, 218,   2,  94, 219,   2,  36,   1, 104, 219,   2,  94, 220,   2,  36,   2,
 104, 220,   2,  71,   0,   0, 199,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 200,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,
  93,  19, 102,  19,  48,  93, 233,   2, 102, 233,   2,  88,  31,  29, 104, 232,
   2,  71,   0,   0, 201,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 203,   1,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 235,
   2,   1,  41,  71,   0,   0, 204,   1,   2,   1,   1,   3,  22, 208,  48, 101,
   0,  93,  19, 102,  19,  48,  93, 238,   2, 102, 238,   2,  88,  32,  29, 104,
 237,   2,  71,   0,   0, 205,   1,   2,   1,   3,   4,  21, 208,  48,  94, 240,
   2,  44, 166,   2, 104, 240,   2,  94, 241,   2,  44, 168,   2, 104, 241,   2,
  71,   0,   0, 206,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 207,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,
  19,  48,  93, 245,   2, 102, 245,   2,  88,  33,  29, 104, 244,   2,  71,   0,
   0, 208,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 215,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 216,   1,   2,   1,
   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 254,   2, 102,
 254,   2,  88,  34,  29, 104, 247,   2,  71,   0,   0};


/* versioned_uris */
const char* const shell_toplevel_versioned_uris[] = {
    "__AS3__.vec", // [660]
    "avmplus", // [660]
    "avmshell", // [660, 661, 662, 663, 664, 665, 666]
    "flash.errors", // [660]
    "flash.sampler", // [660]
    "flash.system", // [660]
    "flash.trace", // [660]
    "flash.utils", // [660]
    NULL
};

#ifdef VMCFG_AOT
extern "C" const struct {
    const char* const n_0; ::avmshell::FileClass* const m_0;
    const char* const n_1; ::avmshell::MIClass* const m_1;
    const char* const n_2; ::avmshell::MIObject* const m_2;
    const char* const n_3; ::avmshell::SystemClass* const m_3;
    const char* const n_4; DeleteObjectSampleClass* const m_4;
    const char* const n_5; DeleteObjectSampleObject* const m_5;
    const char* const n_6; DictionaryClass* const m_6;
    const char* const n_7; DictionaryObject* const m_7;
    const char* const n_8; DomainClass* const m_8;
    const char* const n_9; DomainObject* const m_9;
    const char* const n_10; JObject* const m_10;
    const char* const n_11; JObjectClass* const m_11;
    const char* const n_12; NewObjectSampleClass* const m_12;
    const char* const n_13; NewObjectSampleObject* const m_13;
    const char* const n_14; SampleClass* const m_14;
    const char* const n_15; SampleObject* const m_15;
    const char* const n_16; ScriptObject* const m_16;
    const char* const n_17; StackFrameClass* const m_17;
    const char* const n_18; StackFrameObject* const m_18;
    const char* const n_19; TraceClass* const m_19;
} aotABCTypes_shell_toplevel = {
    "::avmshell::FileClass", 0,
    "::avmshell::MIClass", 0,
    "::avmshell::MIObject", 0,
    "::avmshell::SystemClass", 0,
    "DeleteObjectSampleClass", 0,
    "DeleteObjectSampleObject", 0,
    "DictionaryClass", 0,
    "DictionaryObject", 0,
    "DomainClass", 0,
    "DomainObject", 0,
    "JObject", 0,
    "JObjectClass", 0,
    "NewObjectSampleClass", 0,
    "NewObjectSampleObject", 0,
    "SampleClass", 0,
    "SampleObject", 0,
    "ScriptObject", 0,
    "StackFrameClass", 0,
    "StackFrameObject", 0,
    "TraceClass", 0,
};
#endif
} }
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::MIClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::MIObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::SystemClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::FileClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DictionaryClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DictionaryObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::JObjectClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::JObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
