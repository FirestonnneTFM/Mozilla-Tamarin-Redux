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

const uint32_t shell_toplevel_abc_class_count = 45;
const uint32_t shell_toplevel_abc_script_count = 7;
const uint32_t shell_toplevel_abc_method_count = 237;
const uint32_t shell_toplevel_abc_length = 15071;

/* thunks (39 unique signatures, 63 total) */

#ifndef VMCFG_INDIRECT_NATIVE_THUNKS

avmplus::Atom avmplus_Domain_currentDomain_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainClass* const obj = (DomainClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    DomainObject* const ret = obj->get_currentDomain();
    return (Atom) ret;
}
avmplus::Atom avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainClass* const obj = (DomainClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    uint32_t const ret = obj->get_MIN_DOMAIN_MEMORY_LENGTH();
    return (Atom) ret;
}
avmplus::Atom avmplus_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->init(
        (DomainObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    ClassClosure* const ret = obj->getClass(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_Domain_domainMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    ByteArrayObject* const ret = obj->get_domainMemory();
    return (Atom) ret;
}
avmplus::Atom avmplus_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->set_domainMemory(
        (ByteArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom flash_sampler_NewObjectSample_object_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->get_object();
    return (Atom) ret;
}
double flash_sampler_NewObjectSample_size_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = obj->get_size();
    return ret;
}
avmplus::Atom native_script_function_flash_sampler_clearSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::clearSamples(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_startSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::startSampling(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_stopSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::stopSampling(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_pauseSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::pauseSampling(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_avmplus_bool32(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return undefinedAtom;
}
double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
    );
    return ret;
}
avmplus::Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_Atom
    };
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_avmplus_bool32(argv[argoff2]))
    );
    return (Atom) ret;
}
avmplus::Atom native_script_function_flash_sampler_getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getSamples(obj);
    return (Atom) ret;
}
double native_script_function_flash_sampler_getSampleCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}
double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_Atom
        , argoff3 = argoff2 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}
avmplus::Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_Atom
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff2])
    );
    return (Atom) ret;
}
avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    ArrayObject* const ret = SamplerScript::getLexicalScopes(obj
        , (FunctionObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getSavedThis(obj
        , (FunctionObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (Atom) ret;
}
avmplus::Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (Atom) ret;
}
avmplus::Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->setListener(
        (FunctionObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom flash_trace_Trace_getListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    FunctionObject* const ret = obj->getListener();
    return (Atom) ret;
}
avmplus::Atom flash_utils_Dictionary_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_avmplus_bool32(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_JObject_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_avmplus_String_;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_JObject_createArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_avmplus_Atom__avmplus_ScriptObject_(nullObjectAtom) : (ArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff3]))
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_JObject_toArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    ArrayObject* const ret = obj->toArray(
        (JObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_JObject_constructorSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_avmplus_String_;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->constructorSignature(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_JObject_methodSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_avmplus_String_;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , AvmThunkUnbox_avmplus_String_(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_JObject_fieldSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , AvmThunkUnbox_avmplus_String_(argv[argoff2])
    );
    return (Atom) ret;
}
double avmplus_MI_plus_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
}
avmplus::Atom avmplus_System_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_System_getAvmplusVersion_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->getAvmplusVersion();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_getFeatures_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->getFeatures();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_getRunmode_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->getRunmode();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->trace(
        (ArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_debugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->debugger();
    return undefinedAtom;
}
avmplus::Atom avmplus_System_isDebugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->isDebugger();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_getTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    uint32_t const ret = obj->getTimer();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_private_getArgv_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    ArrayObject* const ret = obj->getArgv();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_readLine_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->readLine();
    return (Atom) ret;
}
double avmplus_System_totalMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
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
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
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
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = obj->get_privateMemory();
    return ret;
}
avmplus::Atom avmplus_System_forceFullCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->forceFullCollection();
    return undefinedAtom;
}
avmplus::Atom avmplus_System_queueCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->queueCollection();
    return undefinedAtom;
}
avmplus::Atom avmplus_System_ns_example_nstest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->ns_example_nstest();
    return undefinedAtom;
}
avmplus::Atom avmplus_System_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->isGlobal(
        AvmThunkUnbox_avmplus_Atom(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_System_swfVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->get_swfVersion();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_apiVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->get_apiVersion();
    return (Atom) ret;
}
avmplus::Atom avmplus_System_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->disposeXML(
        (XMLObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_File_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->exists(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_File_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->read(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_File_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_String_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
        , AvmThunkUnbox_avmplus_String_(argv[argoff2])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_File_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    ByteArrayObject* const ret = obj->readByteArray(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}
avmplus::Atom avmplus_File_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_String_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->writeByteArray(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff2])
    );
    return (Atom) ret;
}

#else // VMCFG_INDIRECT_NATIVE_THUNKS

// avmplus_JObject_methodSignature
avmplus::Atom shell_toplevel_s2a_oos_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_avmplus_String_;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , AvmThunkUnbox_avmplus_String_(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler_getMasterString
avmplus::Atom shell_toplevel_func_s2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler__setSamplerCallback
avmplus::Atom shell_toplevel_func_v2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
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
    typedef double (::avmplus::ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_Domain_getClass
// avmplus_File_readByteArray
avmplus::Atom shell_toplevel_a2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    typedef ByteArrayObject* (::avmplus::ScriptObject::*FuncType)(avmplus::String*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
}

// native_script_function_flash_sampler_isGetterSetter
avmplus::Atom shell_toplevel_func_b2a_oao_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_Atom
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff2])
    );
    return (Atom) ret;
}

// avmplus_JObject_toArray
// flash_trace_Trace_setListener
avmplus::Atom shell_toplevel_a2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    typedef avmplus::Atom (::avmplus::ScriptObject::*FuncType)(::avmplus::ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
        AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
}

// avmplus_System_getAvmplusVersion
// avmplus_System_getFeatures
// avmplus_System_getRunmode
// avmplus_System_readLine
avmplus::Atom shell_toplevel_s2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef avmplus::String* (::avmplus::ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
    );
}

// native_script_function_flash_sampler_sampleInternalAllocs
avmplus::Atom shell_toplevel_func_v2a_ob_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_avmplus_bool32(argv[argoff1])
    );
    return undefinedAtom;
}

// avmplus_File_write
avmplus::Atom shell_toplevel_v2a_oss_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_String_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
        , AvmThunkUnbox_avmplus_String_(argv[argoff2])
    );
    return undefinedAtom;
}

// native_script_function_flash_sampler_getSize
double shell_toplevel_func_d2d_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
    );
    return ret;
}

// native_script_function_flash_sampler_clearSamples
// native_script_function_flash_sampler_pauseSampling
// native_script_function_flash_sampler_startSampling
// native_script_function_flash_sampler_stopSampling
avmplus::Atom shell_toplevel_func_v2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef void (*FuncType)(::avmplus::ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    (*func)(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])
    );
    return undefinedAtom;
}

// avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get
// avmplus_System_getTimer
avmplus::Atom shell_toplevel_u2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef uint32_t (::avmplus::ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_JObject_constructorSignature
avmplus::Atom shell_toplevel_s2a_os_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_avmplus_String_;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->constructorSignature(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
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
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}

// avmplus_System_apiVersion_get
// avmplus_System_swfVersion_get
avmplus::Atom shell_toplevel_i2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef int32_t (::avmplus::ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_JObject_fieldSignature
avmplus::Atom shell_toplevel_s2a_oos_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , AvmThunkUnbox_avmplus_String_(argv[argoff2])
    );
    return (Atom) ret;
}

// avmplus_System_exec
avmplus::Atom shell_toplevel_i2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}

// avmplus_System_isGlobal
avmplus::Atom shell_toplevel_b2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->isGlobal(
        AvmThunkUnbox_avmplus_Atom(argv[argoff1])
    );
    return (Atom) ret;
}

// avmplus_File_read
avmplus::Atom shell_toplevel_s2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = obj->read(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler_getSamples
avmplus::Atom shell_toplevel_func_a2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getSamples(obj);
    return (Atom) ret;
}

// avmplus_JObject_create
avmplus::Atom shell_toplevel_a2a_os_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_avmplus_String_;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (Atom) ret;
}

// avmplus_JObject_createArray
avmplus::Atom shell_toplevel_a2a_ooio_optanullObjectAtom_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_avmplus_Atom__avmplus_ScriptObject_(nullObjectAtom) : (ArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff3]))
    );
    return (Atom) ret;
}

// native_script_function_flash_sampler_getLexicalScopes
// native_script_function_flash_sampler_getSavedThis
avmplus::Atom shell_toplevel_func_a2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    typedef avmplus::Atom (*FuncType)(::avmplus::ScriptObject*, ::avmplus::ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    return (Atom)(*func)(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])
        , AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
}

// avmplus_File_exists
avmplus::Atom shell_toplevel_b2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->exists(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return (Atom) ret;
}

// avmplus_Domain_currentDomain_get
// avmplus_Domain_domainMemory_get
// avmplus_System_private_getArgv
// flash_sampler_NewObjectSample_object_get
// flash_trace_Trace_getListener
avmplus::Atom shell_toplevel_a2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef FunctionObject* (::avmplus::ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (Atom)(*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
    );
}

// avmplus_Domain_loadBytes
avmplus::Atom shell_toplevel_a2a_oou_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (Atom) ret;
}

// avmplus_System_debugger
// avmplus_System_forceFullCollection
// avmplus_System_ns_example_nstest
// avmplus_System_queueCollection
avmplus::Atom shell_toplevel_v2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef void (::avmplus::ScriptObject::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
    );
    return undefinedAtom;
}

// avmplus_MI_plus
double shell_toplevel_d2d_od_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
}

// flash_utils_Dictionary_private_init
avmplus::Atom shell_toplevel_v2a_ob_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_avmplus_bool32(argv[argoff1])
    );
    return undefinedAtom;
}

// flash_trace_Trace_getLevel
avmplus::Atom shell_toplevel_i2a_oi_opti2_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (Atom) ret;
}

// flash_trace_Trace_setLevel
avmplus::Atom shell_toplevel_a2a_oii_opti2_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (Atom) ret;
}

// avmplus_File_writeByteArray
avmplus::Atom shell_toplevel_b2a_oso_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_String_
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->writeByteArray(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff2])
    );
    return (Atom) ret;
}

// avmplus_System_exit
avmplus::Atom shell_toplevel_v2a_oi_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return undefinedAtom;
}

// avmplus_Domain_domainMemory_set
// avmplus_Domain_private_init
// avmplus_System_disposeXML
// avmplus_System_trace
avmplus::Atom shell_toplevel_v2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    typedef void (::avmplus::ScriptObject::*FuncType)(::avmplus::ScriptObject*);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0])).*(func))(
        AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff1])
    );
    return undefinedAtom;
}

// avmplus_System_isDebugger
avmplus::Atom shell_toplevel_b2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = obj->isDebugger();
    return (Atom) ret;
}

// avmplus_System_write
avmplus::Atom shell_toplevel_v2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_avmplus_String_(argv[argoff1])
    );
    return undefinedAtom;
}

// native_script_function_flash_sampler__getInvocationCount
double shell_toplevel_func_d2d_oaou_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_Atom
        , argoff3 = argoff2 + AvmThunkArgSize__avmplus_ScriptObject_
    };
    (void)argc;
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox__avmplus_ScriptObject_(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}

// native_script_function_flash_sampler_getMemberNames
avmplus::Atom shell_toplevel_func_a2a_oab_optbfalse_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize__avmplus_ScriptObject_
        , argoff2 = argoff1 + AvmThunkArgSize_avmplus_Atom
    };
    (void)env;
    ::avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(::avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_avmplus_Atom(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_avmplus_bool32(argv[argoff2]))
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
    static const uint16_t s_slotsOffsetAbstractBaseClass = 0;
    static const uint16_t s_slotsOffsetAbstractBaseObject = 0;
    #ifdef DEBUG
    static void doAbstractBaseClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetRestrictedBaseClass = 0;
    static const uint16_t s_slotsOffsetRestrictedBaseObject = 0;
    #ifdef DEBUG
    static void doRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetAbstractRestrictedBaseClass = 0;
    static const uint16_t s_slotsOffsetAbstractRestrictedBaseObject = 0;
    #ifdef DEBUG
    static void doAbstractRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetCheckBaseClass = 0;
    static const uint16_t s_slotsOffsetCheckBaseObject = 0;
    #ifdef DEBUG
    static void doCheckBaseClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetNativeSubclassOfAbstractBaseClass = 0;
    static const uint16_t s_slotsOffsetNativeSubclassOfAbstractBaseObject = 0;
    #ifdef DEBUG
    static void doNativeSubclassOfAbstractBaseClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetNativeSubclassOfRestrictedBaseClass = 0;
    static const uint16_t s_slotsOffsetNativeSubclassOfRestrictedBaseObject = 0;
    #ifdef DEBUG
    static void doNativeSubclassOfRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetNativeSubclassOfAbstractRestrictedBaseClass = 0;
    static const uint16_t s_slotsOffsetNativeSubclassOfAbstractRestrictedBaseObject = 0;
    #ifdef DEBUG
    static void doNativeSubclassOfAbstractRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits);
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
REALLY_INLINE void SlotOffsetsAndAsserts::doAbstractBaseClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::AbstractBaseClass::EmptySlotsStruct_AbstractBaseClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::AbstractBaseObject::EmptySlotsStruct_AbstractBaseObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::RestrictedBaseClass::EmptySlotsStruct_RestrictedBaseClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::RestrictedBaseObject::EmptySlotsStruct_RestrictedBaseObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doAbstractRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::AbstractRestrictedBaseClass::EmptySlotsStruct_AbstractRestrictedBaseClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::AbstractRestrictedBaseObject::EmptySlotsStruct_AbstractRestrictedBaseObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doCheckBaseClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::CheckBaseClass::EmptySlotsStruct_CheckBaseClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::CheckBaseObject::EmptySlotsStruct_CheckBaseObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNativeSubclassOfAbstractBaseClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::NativeSubclassOfAbstractBaseClass::EmptySlotsStruct_NativeSubclassOfAbstractBaseClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::NativeSubclassOfAbstractBaseObject::EmptySlotsStruct_NativeSubclassOfAbstractBaseObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNativeSubclassOfRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::NativeSubclassOfRestrictedBaseClass::EmptySlotsStruct_NativeSubclassOfRestrictedBaseClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::NativeSubclassOfRestrictedBaseObject::EmptySlotsStruct_NativeSubclassOfRestrictedBaseObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNativeSubclassOfAbstractRestrictedBaseClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::NativeSubclassOfAbstractRestrictedBaseClass::EmptySlotsStruct_NativeSubclassOfAbstractRestrictedBaseClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::NativeSubclassOfAbstractRestrictedBaseObject::EmptySlotsStruct_NativeSubclassOfAbstractRestrictedBaseObject) >= 0);
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
    AvmAssert(getSlotOffset(iTraits, 336) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(iTraits, 337) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(iTraits, 338) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(iTraits, 339) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_scriptID)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(SampleClass::EmptySlotsStruct_SampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) == s_slotsOffsetSampleObject);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 342) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(iTraits, 343) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(NewObjectSampleClass::EmptySlotsStruct_NewObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) == s_slotsOffsetNewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 345) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 346) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_type)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleClass::EmptySlotsStruct_DeleteObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == s_slotsOffsetDeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 345) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 348) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doTraceClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) == s_slotsOffsetTraceClass);
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 382) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(cTraits, 383) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(cTraits, 384) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 385) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(cTraits, 386) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 387) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(cTraits, 388) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_LISTENER)));
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

AVMTHUNK_NATIVE_CLASS_GLUE(MIClass, ::avmshell::MIClass, avmshell::MIClass::createInstanceProc, SlotOffsetsAndAsserts::doMIClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(SystemClass, ::avmshell::SystemClass, ClassClosure::cantInstantiateCreateInstanceProc, SlotOffsetsAndAsserts::doSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(FileClass, ::avmshell::FileClass, ClassClosure::cantInstantiateCreateInstanceProc, SlotOffsetsAndAsserts::doFileClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(AbstractBaseClass, ::avmshell::AbstractBaseClass, ClassClosure::abstractBaseClassCreateInstanceProc, SlotOffsetsAndAsserts::doAbstractBaseClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(RestrictedBaseClass, ::avmshell::RestrictedBaseClass, avmshell::RestrictedBaseClass::createInstanceProc, SlotOffsetsAndAsserts::doRestrictedBaseClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(AbstractRestrictedBaseClass, ::avmshell::AbstractRestrictedBaseClass, ClassClosure::abstractBaseClassCreateInstanceProc, SlotOffsetsAndAsserts::doAbstractRestrictedBaseClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(CheckBaseClass, ::avmshell::CheckBaseClass, avmshell::CheckBaseClass::createInstanceProc, SlotOffsetsAndAsserts::doCheckBaseClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NativeSubclassOfAbstractBaseClass, ::avmshell::NativeSubclassOfAbstractBaseClass, avmshell::NativeSubclassOfAbstractBaseClass::createInstanceProc, SlotOffsetsAndAsserts::doNativeSubclassOfAbstractBaseClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NativeSubclassOfRestrictedBaseClass, ::avmshell::NativeSubclassOfRestrictedBaseClass, avmshell::NativeSubclassOfRestrictedBaseClass::createInstanceProc, SlotOffsetsAndAsserts::doNativeSubclassOfRestrictedBaseClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NativeSubclassOfAbstractRestrictedBaseClass, ::avmshell::NativeSubclassOfAbstractRestrictedBaseClass, avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createInstanceProc, SlotOffsetsAndAsserts::doNativeSubclassOfAbstractRestrictedBaseClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DomainClass, DomainClass, avmplus::DomainClass::createInstanceProc, SlotOffsetsAndAsserts::doDomainClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StackFrameClass, StackFrameClass, avmplus::StackFrameClass::createInstanceProc, SlotOffsetsAndAsserts::doStackFrameClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(SampleClass, SampleClass, avmplus::SampleClass::createInstanceProc, SlotOffsetsAndAsserts::doSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NewObjectSampleClass, NewObjectSampleClass, avmplus::NewObjectSampleClass::createInstanceProc, SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DeleteObjectSampleClass, DeleteObjectSampleClass, avmplus::DeleteObjectSampleClass::createInstanceProc, SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(TraceClass, TraceClass, ClassClosure::cantInstantiateCreateInstanceProc, SlotOffsetsAndAsserts::doTraceClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DictionaryClass, DictionaryClass, avmplus::DictionaryClass::createInstanceProc, SlotOffsetsAndAsserts::doDictionaryClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(JObjectClass, JObjectClass, avmplus::JObjectClass::createInstanceProc, SlotOffsetsAndAsserts::doJObjectClassAsserts)

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
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_MI, MIClass, ::avmshell::MIClass, SlotOffsetsAndAsserts::s_slotsOffsetMIClass, ::avmshell::MIObject, SlotOffsetsAndAsserts::s_slotsOffsetMIObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_System, SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::s_slotsOffsetSystemClass, ::avmplus::ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_File, FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::s_slotsOffsetFileClass, ::avmplus::ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_AbstractBase, AbstractBaseClass, ::avmshell::AbstractBaseClass, SlotOffsetsAndAsserts::s_slotsOffsetAbstractBaseClass, ::avmshell::AbstractBaseObject, SlotOffsetsAndAsserts::s_slotsOffsetAbstractBaseObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_RestrictedBase, RestrictedBaseClass, ::avmshell::RestrictedBaseClass, SlotOffsetsAndAsserts::s_slotsOffsetRestrictedBaseClass, ::avmshell::RestrictedBaseObject, SlotOffsetsAndAsserts::s_slotsOffsetRestrictedBaseObject, false, true)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_AbstractRestrictedBase, AbstractRestrictedBaseClass, ::avmshell::AbstractRestrictedBaseClass, SlotOffsetsAndAsserts::s_slotsOffsetAbstractRestrictedBaseClass, ::avmshell::AbstractRestrictedBaseObject, SlotOffsetsAndAsserts::s_slotsOffsetAbstractRestrictedBaseObject, false, true)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_CheckBase, CheckBaseClass, ::avmshell::CheckBaseClass, SlotOffsetsAndAsserts::s_slotsOffsetCheckBaseClass, ::avmshell::CheckBaseObject, SlotOffsetsAndAsserts::s_slotsOffsetCheckBaseObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeSubclassOfAbstractBase, NativeSubclassOfAbstractBaseClass, ::avmshell::NativeSubclassOfAbstractBaseClass, SlotOffsetsAndAsserts::s_slotsOffsetNativeSubclassOfAbstractBaseClass, ::avmshell::NativeSubclassOfAbstractBaseObject, SlotOffsetsAndAsserts::s_slotsOffsetNativeSubclassOfAbstractBaseObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeSubclassOfRestrictedBase, NativeSubclassOfRestrictedBaseClass, ::avmshell::NativeSubclassOfRestrictedBaseClass, SlotOffsetsAndAsserts::s_slotsOffsetNativeSubclassOfRestrictedBaseClass, ::avmshell::NativeSubclassOfRestrictedBaseObject, SlotOffsetsAndAsserts::s_slotsOffsetNativeSubclassOfRestrictedBaseObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeSubclassOfAbstractRestrictedBase, NativeSubclassOfAbstractRestrictedBaseClass, ::avmshell::NativeSubclassOfAbstractRestrictedBaseClass, SlotOffsetsAndAsserts::s_slotsOffsetNativeSubclassOfAbstractRestrictedBaseClass, ::avmshell::NativeSubclassOfAbstractRestrictedBaseObject, SlotOffsetsAndAsserts::s_slotsOffsetNativeSubclassOfAbstractRestrictedBaseObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, DomainClass, SlotOffsetsAndAsserts::s_slotsOffsetDomainClass, DomainObject, SlotOffsetsAndAsserts::s_slotsOffsetDomainObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameClass, StackFrameObject, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, SampleClass, SlotOffsetsAndAsserts::s_slotsOffsetSampleClass, SampleObject, SlotOffsetsAndAsserts::s_slotsOffsetSampleObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleClass, NewObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleClass, DeleteObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, TraceClass, SlotOffsetsAndAsserts::s_slotsOffsetTraceClass, ::avmplus::ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Dictionary, DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryClass, DictionaryObject, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryObject, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, JObjectClass, SlotOffsetsAndAsserts::s_slotsOffsetJObjectClass, JObject, SlotOffsetsAndAsserts::s_slotsOffsetJObject, false, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[15071] = {
  16,   0,  46,   0,   6,   0,   2,   1,   3,   4,   0,   7,   0,   0,   0,   0,
   0,   0, 240,  63,   0,   0,   0,   0,   0,   0,   0,  64,   0,   0,   0,   0,
   0,   0,   8,  64,   0,   0,   0,   0,   0,   0,  16,  64,   0,   0,   0,   0,
   0,   0,  20,  64,   0,   0,   0,   0,   0,   0,  24,  64, 221,   2,   0,   4,
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
 114,  97, 121,   4,  70, 105, 108, 101,  21,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,   8,  97,
 118, 109, 115, 104, 101, 108, 108,  12,  65,  98, 115, 116, 114,  97,  99, 116,
  66,  97, 115, 101,  23,  97, 118, 109, 115, 104, 101, 108, 108,  58,  82, 101,
 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  14,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  31,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  22,  65,  98, 115, 116,
 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97,
 115, 101,  18,  97, 118, 109, 115, 104, 101, 108, 108,  58,  67, 104, 101,  99,
 107,  66,  97, 115, 101,   9,  67, 104, 101,  99, 107,  66,  97, 115, 101,  25,
 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  67,  97, 112,
  97,  98, 105, 108, 105, 116, 105, 101, 115,   7,  65,  86,  77,  80, 108, 117,
 115,  12, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  10, 112,
 108,  97, 121, 101, 114,  84, 121, 112, 101,  12,  67,  97, 112,  97,  98, 105,
 108, 105, 116, 105, 101, 115,  21,  97, 118, 109, 115, 104, 101, 108, 108,  58,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  10, 112, 117,  98,
 108, 105,  99,  95, 118,  97, 114,   3, 238, 138, 149,  18, 112, 117,  98, 108,
 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  48,   3,  65,
  80,  73,   3,  54,  54,  49,   3, 238, 138, 150,  18, 112, 117,  98, 108, 105,
  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,   3,  54,  54,
  50,   3, 238, 138, 151,  18, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,
  95,  65,  73,  82,  95,  49,  95,  53,   3,  54,  54,  51,   3, 238, 138, 152,
  20, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  49,   3,  54,  54,  52,   3, 238, 138, 153,  21, 112, 117,
  98, 108, 105,  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  51,  50,   3,  54,  54,  53,   3, 238, 138, 154,  20, 112, 117,  98, 108,
 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,
   3,  54,  54,  54,  26, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,
  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  38,
 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  37, 112, 117,  98, 108, 105,  99,  95, 118,  97,
 114,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,
  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  12, 112, 117,  98,
 108, 105,  99,  95,  99, 111, 110, 115, 116,  20, 112, 117,  98, 108, 105,  99,
  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  48,  20, 112,
 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  70,  80,  95,  49,
  48,  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,
  95,  65,  73,  82,  95,  49,  95,  53,  22, 112, 117,  98, 108, 105,  99,  95,
  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  23,
 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  51,  50,  22, 112, 117,  98, 108, 105,  99,  95,  99,
 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  28, 112,
 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,
  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  40, 112, 117,  98, 108,
 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  50,  39, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115,
 116,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,
  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  15, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  23, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,
  95,  49,  95,  48,  23, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99,
 116, 105, 111, 110,  95,  70,  80,  95,  49,  48,  95,  48,  23, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,
  95,  49,  95,  53,  25, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99,
 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  26, 112,
 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  70,
  80,  95,  49,  48,  95,  48,  95,  51,  50,  25, 112, 117,  98, 108, 105,  99,
  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  50,  31, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116,
 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,
  48,  95,  48,  43, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116,
 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,
  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  42,
 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,
  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  13, 112, 117,  98, 108, 105,
  99,  95, 103, 101, 116, 115, 101, 116,  21, 112, 117,  98, 108, 105,  99,  95,
 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  48,  21, 112,
 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,  95,
  49,  48,  95,  48,  21, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115,
 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,  23, 112, 117,  98, 108, 105,
  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  49,  24, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  23, 112, 117,  98, 108,
 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  50,  29, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101,
 116,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,
  48,  41, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,
  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  40, 112, 117,  98, 108,
 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,  95,  49,  48,  95,
  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,
  49,  48,  95,  48,  12, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  20,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,
  95,  49,  95,  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,
  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  70,  80,  95,  49,  48,  95,  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,
  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,
  82,  95,  49,  95,  53,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  31,  97, 118, 109, 115, 104,
 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,
  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  22, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  49,  32,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  51,  50,  23, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  31,  97, 118, 109, 115, 104,
 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,
  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  22, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  50,  37,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,
  70,  80,  95,  49,  48,  95,  48,  28, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,
  49,  48,  95,  48,  49,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  40, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,
  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  48,
  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,
  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,
  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,
  39, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,
  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,
  95,  70,  80,  95,  49,  48,  95,  48,  16, 112, 117,  98, 108, 105,  99,  95,
 105, 110, 116, 101, 114, 102,  97,  99, 101,  24, 112, 117,  98, 108, 105,  99,
  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,
  95,  48,  24, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,
  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  24, 112, 117,  98, 108,
 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,
  95,  49,  95,  53,  26, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101,
 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  27,
 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  26, 112, 117,  98, 108,
 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  32, 112, 117,  98, 108, 105,  99,  95, 105, 110,
 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  48,  95,
  70,  80,  95,  49,  48,  95,  48,  44, 112, 117,  98, 108, 105,  99,  95, 105,
 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  50,  43, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101,
 114, 102,  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,
  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,
  37,  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,
  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,
  99, 116,  66,  97, 115, 101,  28,  78,  97, 116, 105, 118, 101,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  66,
  97, 115, 101,  31,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  66,
  97, 115, 101,  22,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98,
 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  39,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97,
 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97,
 115, 101,  30,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115,
 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115,
 101,  33,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 117,  98,  99, 108,
  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,
  97, 115, 101,  24,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  82, 101,
 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  47,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99,
 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101,
 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  38,  78,  97, 116,
 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115,
 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,
  97, 115, 101,  41,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82,
 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  32,  83, 117,
  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,
  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  11,  65,
  80,  73,  95,  65,  73,  82,  95,  49,  95,  48,  11,  65,  80,  73,  95,  70,
  80,  95,  49,  48,  95,  48,  11,  65,  80,  73,  95,  65,  73,  82,  95,  49,
  95,  53,  13,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,
  14,  65,  80,  73,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  13,
  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  10, 110, 115,
  95, 101, 120,  97, 109, 112, 108, 101,   6, 110,  97, 116, 105, 118, 101,   3,
  99, 108, 115,  19,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  77,  73,  67, 108,  97, 115, 115,   8, 105, 110, 115, 116,  97, 110,  99, 101,
  20,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,
  98, 106, 101,  99, 116,   7, 109, 101, 116, 104, 111, 100, 115,  24,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,  98, 106, 101,
  99, 116,  73, 109, 112, 108,  10,  97, 118, 109, 112, 108, 117, 115, 238, 138,
 148,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 121,
 115, 116, 101, 109,  67, 108,  97, 115, 115,   7,  99, 108,  97, 115, 115, 103,
  99,   5, 101, 120,  97,  99, 116,   4,  97, 117, 116, 111,   9,  99, 111, 110,
 115, 116, 114, 117,  99, 116,   4, 110, 111, 110, 101,  21,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  70, 105, 108, 101,  67, 108,  97, 115,
 115,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 148,  29,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,
  99, 116,  66,  97, 115, 101,  67, 108,  97, 115, 115,  30,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,
  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,   8,  97,  98, 115, 116, 114,
  97,  99, 116,  45,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,
  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  67, 108,  97, 115,
 115,  46,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97,
 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98,
 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,
  31,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,
  32,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99,
 116,  10, 114, 101, 115, 116, 114, 105,  99, 116, 101, 100,  47,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83,
 117,  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99,
 116, 101, 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  48,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83,
 117,  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99,
 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  39,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,
  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,
  67, 108,  97, 115, 115,  40,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,
  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  19,  97,
  98, 115, 116, 114,  97,  99, 116,  45, 114, 101, 115, 116, 114, 105,  99, 116,
 101, 100,  55,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,
  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,
  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101,
 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  56,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82,
 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106,
 101,  99, 116,  26,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  67, 104, 101,  99, 107,  66,  97, 115, 101,  67, 108,  97, 115, 115,  27,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67, 104, 101,  99, 107,
  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,   5,  99, 104, 101,  99, 107,
  15, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109, 238, 138, 148,
  14, 103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,  97, 109, 101,   5,
 112, 114, 105, 110, 116,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138,
 149,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 150,  11,  97, 118,
 109, 115, 104, 101, 108, 108, 238, 138, 151,  11,  97, 118, 109, 115, 104, 101,
 108, 108, 238, 138, 152,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138,
 153,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 154,  14,  97, 118,
 109, 112, 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,   4, 105, 110, 105,
 116,  11,  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,  50,   9, 108, 111,
  97, 100,  66, 121, 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,  77,  65,
  73,  78,  95,  77,  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,  84,  72,
   4, 108, 111,  97, 100,  12, 100, 111, 109,  97, 105, 110,  77, 101, 109, 111,
 114, 121,  11,  68, 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,   2, 103,
  99,  12,  68, 111, 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,   8,  70,
 117, 110,  99, 116, 105, 111, 110,   5,  81,  78,  97, 109, 101,  19,  95, 103,
 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110,
 116,  12,  83,  97, 109, 112, 108, 101, 114,  46,  97, 115,  36,  51,  13, 102,
 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,   1, 102,   1, 101,
   3, 114, 101, 116,  19,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,
  67,  97, 108, 108,  98,  97,  99, 107,   7, 119, 114,  97, 112, 112, 101, 114,
  24, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,
 116,  97,  99, 107,  70, 114,  97, 109, 101,   4, 110,  97, 109, 101,   2,  40,
  41,   4, 102, 105, 108, 101,   1,  91,   1,  58,   4, 108, 105, 110, 101,   1,
  93,   8, 115,  99, 114, 105, 112, 116,  73,  68,   8, 116, 111,  83, 116, 114,
 105, 110, 103,  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  20, 102,
 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,  97, 109,
 112, 108, 101,   4, 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,   6,  83,
  97, 109, 112, 108, 101,  29, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112,
 108, 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109,
 112, 108, 101,   2, 105, 100,   4, 116, 121, 112, 101,   6, 111,  98, 106, 101,
  99, 116,   4, 115, 105, 122, 101,  15,  78, 101, 119,  79,  98, 106, 101,  99,
 116,  83,  97, 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46, 115,  97,
 109, 112, 108, 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,
  99, 116,  83,  97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116, 101,  79,
  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  16, 102, 108,  97, 115,
 104,  46, 115,  97, 109, 112, 108, 101, 114, 238, 138, 148,  15,  83, 116,  97,
  99, 107,  70, 114,  97, 109, 101,  67, 108,  97, 115, 115,  16,  83, 116,  97,
  99, 107,  70, 114,  97, 109, 101,  79,  98, 106, 101,  99, 116,  12,  99, 111,
 110, 115, 116, 115, 101, 116, 116, 101, 114, 115,   4, 116, 114, 117, 101,  11,
  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  12,  83,  97, 109, 112,
 108, 101,  79,  98, 106, 101,  99, 116,  20,  78, 101, 119,  79,  98, 106, 101,
  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  21,  78, 101,
 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106,
 101,  99, 116,  23,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,
  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  24,  68, 101, 108, 101,
 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98,
 106, 101,  99, 116,  12,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101,
 115,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13, 115, 116,
  97, 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115, 116,  97, 114, 116,
  83,  97, 109, 112, 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,  97, 109,
 112, 108, 105, 110, 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110,
 103,  13, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  28,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 112,
  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,  97, 109,
 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99,
 115,  35,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 115,  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65,
 108, 108, 111,  99, 115,  18, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,
  67,  97, 108, 108,  98,  97,  99, 107,  34,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58,  95, 115, 101, 116,  83,  97, 109, 112,
 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 103, 101, 116,  83,
 105, 122, 101,  22,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58, 103, 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,  77, 101,
 109,  98, 101, 114,  78,  97, 109, 101, 115,  29,  83,  97, 109, 112, 108, 101,
 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77, 101, 109,  98,
 101, 114,  78,  97, 109, 101, 115,  10, 103, 101, 116,  83,  97, 109, 112, 108,
 101, 115,  25,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  14, 103, 101, 116,
  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  29,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97,
 109, 112, 108, 101,  67, 111, 117, 110, 116,  18, 103, 101, 116,  73, 110, 118,
 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,
  83, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,
  67, 111, 117, 110, 116,  24, 103, 101, 116,  71, 101, 116, 116, 101, 114,  73,
 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  34,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 103,
 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110,
 116,  14, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,
  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  16, 103,
 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  31,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103,
 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  12,
 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,
  97, 118, 101, 100,  84, 104, 105, 115,  15, 103, 101, 116,  77,  97, 115, 116,
 101, 114,  83, 116, 114, 105, 110, 103,  30,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77,  97, 115, 116, 101,
 114,  83, 116, 114, 105, 110, 103,  17, 102, 108,  97, 115, 104,  46, 116, 114,
  97,  99, 101,  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,  77,  69,
  84,  72,  79,  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  87,  73,
  84,  72,  95,  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,
  65,  78,  68,  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,  79,  68,
  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,  84,  72,
  95,  65,  82,  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,  84,  69,
  78,  69,  82,   8, 115, 101, 116,  76, 101, 118, 101, 108,   8, 103, 101, 116,
  76, 101, 118, 101, 108,  11, 115, 101, 116,  76, 105, 115, 116, 101, 110, 101,
 114,  11, 103, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 102, 108,
  97, 115, 104,  46, 116, 114,  97,  99, 101,   5,  84, 114,  97,  99, 101,  10,
  84, 114,  97,  99, 101,  46,  97, 115,  36,  52,  14, 102, 108,  97, 115, 104,
  46, 116, 114,  97,  99, 101, 238, 138, 148,  10,  84, 114,  97,  99, 101,  67,
 108,  97, 115, 115,  22, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,
  58,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  15,  68, 105,  99, 116,
 105, 111, 110,  97, 114, 121,  46,  97, 115,  36,  53,  10,  68, 105,  99, 116,
 105, 111, 110,  97, 114, 121,  14, 102, 108,  97, 115, 104,  46, 117, 116, 105,
 108, 115, 238, 138, 148,  15,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,
  67, 108,  97, 115, 115,  16,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,
  79,  98, 106, 101,  99, 116,  18, 102, 108,  97, 115, 104,  46, 117, 116, 105,
 108, 115,  58,  69, 110, 100, 105,  97, 110,  10,  66,  73,  71,  95,  69,  78,
  68,  73,  65,  78,   9,  98, 105, 103,  69, 110, 100, 105,  97, 110,  13,  76,
  73,  84,  84,  76,  69,  95,  69,  78,  68,  73,  65,  78,  12, 108, 105, 116,
 116, 108, 101,  69, 110, 100, 105,  97, 110,   6,  69, 110, 100, 105,  97, 110,
  11,  69, 110, 100, 105,  97, 110,  46,  97, 115,  36,  54,  15,  97, 118, 109,
 112, 108, 117, 115,  58,  74,  79,  98, 106, 101,  99, 116,   7,  74,  79,  98,
 106, 101,  99, 116,   6,  99, 114, 101,  97, 116, 101,  11,  99, 114, 101,  97,
 116, 101,  65, 114, 114,  97, 121,   7, 116, 111,  65, 114, 114,  97, 121,  20,
  99, 111, 110, 115, 116, 114, 117,  99, 116, 111, 114,  83, 105, 103, 110,  97,
 116, 117, 114, 101,  15, 109, 101, 116, 104, 111, 100,  83, 105, 103, 110,  97,
 116, 117, 114, 101,  14, 102, 105, 101, 108, 100,  83, 105, 103, 110,  97, 116,
 117, 114, 101,   9,  74,  97, 118,  97,  46,  97, 115,  36,  55,  12,  74,  79,
  98, 106, 101,  99, 116,  67, 108,  97, 115, 115, 117,  22,   1,   5,   5,  23,
   1,  22,   6,  23,   6,   8,  17,   5,  20,  22,  21,  24,  20,   5,  24,  24,
  24,   5,  28,  24,  28,  26,  28,  26,  23,   8,  50,   5,  56,  22,  57,  24,
  56,   5,  64,  22,  65,  24,  64,   5,  67,  24,  67,   5,  69,  24,  69,   5,
  71,  24,  71,   5,  73,  22,  75,  23,  75,  24,  73,  26,  73,   5,  78,  22,
  80,  22,  84,  22,  87,  22,  90,  22,  93,  22,  96,  24,  78,   5, 133,   1,
  24, 133,   1,   5, 135,   1,  24, 135,   1,   5, 137,   1,  24, 137,   1,   5,
 139,   1,  24, 139,   1,   5, 141,   1,  24, 141,   1,   5, 143,   1,  24, 143,
   1,   5, 145,   1,  24, 145,   1,   5, 147,   1,  24, 147,   1,   5, 149,   1,
  24, 149,   1,   5, 161,   1,  24, 161,   1,   5, 163,   1,  24, 163,   1,   5,
 165,   1,  24, 165,   1,   5, 167,   1,  24, 167,   1,   5, 169,   1,  24, 169,
   1,   5, 171,   1,  24, 171,   1,  23,  65,  22, 187,   1,  22, 195,   1,  22,
 214,   1,  22, 217,   1,  22, 218,   1,  22, 219,   1,  22, 220,   1,  22, 221,
   1,  22, 222,   1,   5, 223,   1,   5, 225,   1,  24, 223,   1,  26, 223,   1,
   5, 236,   1,  22, 237,   1,  23, 237,   1,   5, 243,   1,  24, 243,   1,  26,
 243,   1,   5, 254,   1,  24, 254,   1,   5, 130,   2,  24, 130,   2,   5, 136,
   2,  24, 136,   2,  22, 138,   2,   5, 181,   2,  22, 193,   2,  24, 181,   2,
   5, 195,   2,  23, 193,   2,  22, 196,   2,   5, 198,   2,   5, 199,   2,  23,
  57,  24, 198,   2,  26, 198,   2,  22, 201,   2,   5, 204,   2,  24, 204,   2,
   5, 210,   2,   5, 211,   2,  24, 211,   2,   5, 219,   2,  51,   4,   1,   2,
   3,   4,   4,   1,   2,   4,   5,   1,   6,   1,   8,   8,   1,   2,   4,   5,
  12,  13,  14,  15,   1,  12,   1,  16,   9,   1,   2,   4,  15,  29,  30,  31,
  32,  33,   1,  35,   1,  36,   1,  37,   1,  38,   1,  39,   1,  40,   2,  35,
  36,   3,  36,  38,  40,   3,  35,  36,  39,   1,   5,   1,   4,   1,  21,   4,
   1,   2,  21,  72,   1,  30,   5,   1,   2,   4,  30,  31,   1,  73,   1,  74,
   1,  75,   1,  76,   1,  77,   1,  78,   1,  79,   1,  80,   1,  81,   2,  76,
  77,   3,  77,  79,  81,   3,  76,  77,  80,   8,   1,   4,   5,  15,  82,  83,
  84,  85,   1,  82,   4,   1,   4,   5,  83,   4,   1,  86,  87,  88,   1,  88,
   8,   1,  15,  86,  87,  88,  89,  90,  91,   1,  98,   4,   1, 100, 102, 103,
   1, 104,   8,   1,  15,  18, 105, 106, 107, 108, 109,   1, 105,   4,   1,  18,
 106, 107,   1, 110,   4,   1,  18, 107, 113,   4,   1,   4,   5, 116, 161,   3,
   7,   1,   2,   7,   1,   3,   9,   4,   1,   9,   7,   1,   7,   1,   8,   9,
   9,   1,   7,   1,  10,   9,  11,   1,   9,  12,   1,   9,  13,   1,   9,  14,
   1,   7,   1,  15,   9,   4,   2,   9,  16,   2,   9,  18,   3,   7,   5,  19,
   9,  18,   4,   7,   5,  22,   7,   1,  23,   7,   1,  25,   9,  26,   4,   7,
   5,  27,   7,   1,  29,   9,  30,   5,   7,   1,  31,   7,   1,  32,   7,   1,
  33,   9,  34,   4,   9,  36,   4,   9,  40,   4,   9,  41,   4,   9,  42,   4,
   9,  11,   4,   9,  43,   4,   9,  16,   4,   9,  44,   4,   9,   9,   4,   9,
  30,   6,   9,  29,   4,   9,   7,   4,   9,  45,   4,   9,  46,   4,   9,  47,
   4,   9,  48,   4,   9,  49,   4,   9,  51,   7,   9,  52,   4,   9,  53,   4,
   9,  54,   4,   9,  55,   4,   7,   4,   4,   7,  18,  58,   9,  59,   4,   9,
  60,   4,   9,  61,   4,   9,  62,   4,   7,   4,  63,   7,  21,  66,   7,  21,
  68,   7,  21,  70,   7,  21,  72,   9,   4,   8,   9,  44,   8,   9,  76,   4,
   7,  30,  77,   9,  79,   4,   9,  81,   9,   9,  85,  10,   9,  88,  11,   9,
  91,  12,   9,  94,  13,   9,  97,  14,   9,  99,  15,   9, 100,  16,   9, 101,
  17,   9, 102,   4,   9, 103,   9,   9, 104,  10,   9, 105,  11,   9, 106,  12,
   9, 107,  13,   9, 108,  14,   9, 109,  15,   9, 110,  16,   9, 111,  17,   9,
 112,   4,   9, 113,   9,   9, 114,  10,   9, 115,  11,   9, 116,  12,   9, 117,
  13,   9, 118,  14,   9, 119,  15,   9, 120,  16,   9, 121,  17,   9, 122,   4,
   9, 123,   9,   9, 124,  10,   9, 125,  11,   9, 126,  12,   9, 127,  13,   9,
 128,   1,  14,   9, 129,   1,  15,   9, 130,   1,  16,   9, 131,   1,  17,   7,
  21, 132,   1,   7,  21, 134,   1,   7,  21, 136,   1,   7,  21, 138,   1,   7,
  21, 140,   1,   7,  21, 142,   1,   7,  21, 144,   1,   7,  21, 146,   1,   7,
  21, 148,   1,   7,  21, 150,   1,   7,  21, 151,   1,   7,  21, 152,   1,   7,
  21, 153,   1,   7,  21, 154,   1,   7,  21, 155,   1,   7,  21, 156,   1,   7,
  21, 157,   1,   7,  21, 158,   1,   7,  21, 159,   1,   7,  21, 160,   1,   7,
  21, 162,   1,   7,  21, 164,   1,   7,  21, 166,   1,   7,  21, 168,   1,   7,
  21, 170,   1,   7,  21, 172,   1,   9,  19,  18,   9,  22,  18,   9,  23,   2,
   9,  27,  18,   9,   4,  19,   9,  63,  19,   9,  66,  20,   9,  23,  21,   9,
 162,   1,  20,   9,  66,  21,   9, 164,   1,  20,   9,  68,  20,   9, 166,   1,
  20,   9,  68,  21,   9, 168,   1,  20,   9,  70,  20,   9, 170,   1,  20,   9,
  70,  21,   9, 172,   1,  20,   9,  72,  20,   9,  77,  22,   9,  23,  23,   9,
 132,   1,  20,   9, 134,   1,  20,   9, 136,   1,  20,   9, 138,   1,  20,   9,
 140,   1,  20,   9, 142,   1,  20,   9, 144,   1,  20,   9, 146,   1,  20,   9,
 148,   1,  20,   9, 150,   1,  20,   9, 151,   1,  20,   9, 152,   1,  20,   9,
 153,   1,  20,   9, 154,   1,  20,   9, 155,   1,  20,   9, 156,   1,  20,   9,
 157,   1,  20,   9, 158,   1,  20,   9, 159,   1,  20,   9, 160,   1,  20,   9,
 173,   1,  20,   7,  21, 173,   1,   9, 174,   1,  20,   7,  21, 174,   1,   9,
 175,   1,  20,   7,  21, 175,   1,   9, 176,   1,  20,   7,  21, 176,   1,   9,
 177,   1,  20,   7,  21, 177,   1,   9, 178,   1,  20,   7,  21, 178,   1,   9,
  79,  20,   7,  21,  79,   9,  81,  20,   7,  21,  81,   9,  85,  20,   7,  21,
  85,   9,  88,  20,   7,  21,  88,   9,  91,  20,   7,  21,  91,   9,  94,  20,
   7,  21,  94,   9,  97,  20,   7,  21,  97,   9,  99,  20,   7,  21,  99,   9,
 100,  20,   7,  21, 100,   9, 101,  20,   7,  21, 101,   9, 102,  20,   7,  21,
 102,   9, 103,  20,   7,  21, 103,   9, 104,  20,   7,  21, 104,   9, 105,  20,
   7,  21, 105,   9, 106,  20,   7,  21, 106,   9, 107,  20,   7,  21, 107,   9,
 108,  20,   7,  21, 108,   9, 109,  20,   7,  21, 109,   9, 110,  20,   7,  21,
 110,   9, 111,  20,   7,  21, 111,   9, 179,   1,  18,   9,   4,  24,   9,  63,
  24,   9,  16,  24,   9,  66,  25,   9, 162,   1,  25,   9, 164,   1,  25,   9,
  68,  25,   9, 166,   1,  25,   9, 168,   1,  25,   9,  70,  25,   9, 170,   1,
  25,   9, 172,   1,  25,   9,  72,  25,   9,  77,  26,   9, 215,   1,   4,   9,
 216,   1,   4,   9, 173,   1,  25,   9, 174,   1,  25,   9, 175,   1,  25,   9,
 176,   1,  25,   9, 177,   1,  25,   9, 178,   1,  25,   9,  79,  25,   9,  81,
  27,   9,  85,  28,   9,  88,  29,   9,  91,  30,   9,  94,  31,   9,  97,  32,
   9,  99,  33,   9, 100,  34,   9, 101,  35,   9, 102,  25,   9, 103,  27,   9,
 104,  28,   9, 105,  29,   9, 106,  30,   9, 107,  31,   9, 108,  32,   9, 109,
  33,   9, 110,  34,   9, 111,  35,   9, 112,  25,   9, 113,  27,   9, 114,  28,
   9, 115,  29,   9, 116,  30,   9, 117,  31,   9, 118,  32,   9, 119,  33,   9,
 120,  34,   9, 121,  35,   9, 122,  25,   9, 123,  27,   9, 124,  28,   9, 125,
  29,   9, 126,  30,   9, 127,  31,   9, 128,   1,  32,   9, 129,   1,  33,   9,
 130,   1,  34,   9, 131,   1,  35,   9, 132,   1,  25,   9, 134,   1,  27,   9,
 136,   1,  28,   9, 138,   1,  29,   9, 140,   1,  30,   9, 142,   1,  31,   9,
 144,   1,  32,   9, 146,   1,  33,   9, 148,   1,  34,   9, 150,   1,  35,   9,
 151,   1,  25,   9, 152,   1,  27,   9, 153,   1,  28,   9, 154,   1,  29,   9,
 155,   1,  30,   9, 156,   1,  31,   9, 157,   1,  32,   9, 158,   1,  33,   9,
 159,   1,  34,   9, 160,   1,  35,   7,   4,  12,   9, 224,   1,  36,   9,  63,
  36,   9,  61,  36,   9, 226,   1,  36,   9,  13,   4,   9, 227,   1,   4,   9,
 224,   1,  37,   9, 226,   1,   4,   9,  14,   4,   9, 228,   1,   4,   9, 229,
   1,   4,   9,  12,  19,   9,  23,  38,   9,  12,  24,   7,   1, 233,   1,   7,
   1, 234,   1,   9, 235,   1,  39,   9, 238,   1,  39,   7,   1, 239,   1,   9,
 240,   1,  40,   9, 241,   1,  39,   9, 238,   1,  40,   9, 242,   1,  40,   9,
 244,   1,  41,   9, 246,   1,  41,   9, 249,   1,  41,   9, 244,   1,   4,   9,
 246,   1,   4,   9, 249,   1,   4,   9, 251,   1,   4,   9, 252,   1,   4,   7,
  87, 253,   1,   9, 255,   1,   4,   9, 128,   2,   4,   7,  87, 129,   2,   9,
 131,   2,   4,   9, 132,   2,   4,   9, 133,   2,   4,   9, 134,   2,   4,   7,
  87, 135,   2,   7,  87, 137,   2,   9,  23,  39,   9, 253,   1,  42,   9, 129,
   2,  42,   9, 135,   2,  42,   9, 137,   2,  42,   9, 149,   2,  42,   9, 151,
   2,  42,   9, 153,   2,  42,   9, 155,   2,  42,   9, 157,   2,  42,   9, 159,
   2,  42,   9, 241,   1,  40,   9, 161,   2,  42,   9, 163,   2,  42,   9, 165,
   2,  42,   9, 167,   2,  42,   9, 169,   2,  42,   9, 170,   2,  42,   9, 171,
   2,  42,   9, 235,   1,  40,   9, 173,   2,  42,   9, 175,   2,  42,   9, 177,
   2,  42,   9, 179,   2,  42,   7,   1, 182,   2,   7,   1, 183,   2,   7,   1,
 184,   2,   7,   1, 185,   2,   7,   1, 186,   2,   7,   1, 187,   2,   7,   1,
 188,   2,   9, 182,   2,   4,   9, 183,   2,   4,   9, 184,   2,   4,   9, 185,
   2,   4,   9, 186,   2,   4,   9, 187,   2,   4,   9, 188,   2,   4,   9, 189,
   2,   4,   9, 190,   2,   4,   9, 191,   2,   4,   9, 192,   2,   4,   7, 100,
 194,   2,   9,  23,  43,   9, 194,   2,  44,   9, 224,   1,  45,   9, 224,   1,
  46,   7,  18, 200,   2,   9,  23,  47,   9, 200,   2,  48,   7,   1, 205,   2,
   7,   1, 207,   2,   9, 205,   2,   4,   9, 207,   2,   4,   7,  18, 209,   2,
   9,  23,  49,   9, 209,   2,  48,   7,   4, 212,   2,   9, 213,   2,   4,   9,
 214,   2,   4,   9, 215,   2,   4,   9, 216,   2,   4,   9, 217,   2,   4,   9,
 218,   2,   4,   9,  23,  50,   9, 212,   2,  24, 237,   1,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,
   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,
   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   5,
   1,   0,   0,   7,   1,   0,   0,   0,   1,   4,   0,   0,   1,   4,   1,  12,
   5,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   1,  20,  20,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   1,   1,  25,   1,  32,   1,  25,   5,   1,  32,   0,   5,   1,  32,   0,   5,
   1,  32,   0,   5,   1,  32,   1,   1,  26,   1,  32,   1,   1,   5,   1,  32,
   0,   1,   1,  32,   0,   2,   1,  32,   0,   7,   1,  32,   0,  26,   1,  32,
   0,   5,   1,  32,   0,  20,   1,  32,   0,  20,   1,  32,   0,  20,   1,  32,
   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   1,   2,  19,   1,
  32,   0,  25,   1,  32,   0,  25,   1,  32,   1,   1,  27,   1,  32,   0,   0,
   1,   0,   0,   0,   1,   0,   1,   2,   5,   1,  32,   1,   5,   5,   1,  32,
   2,   1,   5,   5,   1,  32,   1,  52,   5,   1,  32,   2,   2,   5,  52,   1,
  32,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   5,   1,   0,   0,   2,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   1,   1,   0,   1,   0,   1,   1,
   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
 181,   2,   1,  32,   0,   7,   1,  32,   1,   1, 181,   2,   1,  32,   1,   0,
 181,   2,   1,   0,   2,   0,  52,   7,   1,  40,   1,   1,   3,   1,  12,   5,
   1,  32,   2,   0,   5,   7,   1,   8,   1,   1,   3,   0,  52,   1,  32,   1,
   0,  52,   1,  32,   0,   0,   1,   0,   1,   5,   5,   1,  32,   1,  19, 196,
   2,   1,  32,   1,  26, 196,   2,   1,  32,   2,   2,  19, 197,   2,   1,  32,
   3,  20,  19, 197,   2,   7,   1,  32,   2,  20,  19, 197,   2,   1,   0,   2,
  20,  19, 197,   2,   1,   0,   2,  20,  19, 197,   2,   1,   0,   0,  20,   1,
  32,   0,  19,   1,  32,   2,  19,  19,   2,   1,  40,   1,  10,  10,   1,  20,
   0,   1,  32,   1,   1, 196,   2,   1,  32,   0,   0,   1,   2,   1,   1, 196,
   2,   1,   2,   1,   1,   2,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,
   0,   1,   1,  32,   0,   1,   1,  32,   0,   0,   1,   0,   0,   5,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,  32,   0,  20,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   2,   0,  25,  25,
   1,  40,   1,   2,   3,   1,  25,  25,   1,  40,   1,   2,   3,   1,   0, 196,
   2,   1,  32,   0, 196,   2,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   1,   1,   2,   1,  32,   1,   0,   2,   1,   8,   1,  10,
  10,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   1, 152,   3,   5,   1,  36,   3, 152,   3, 152,   3,
  25,  26,   1,  40,   1,  12,  12,   1,  26, 152,   3,   1,  32,   1,   5,   5,
   1,  36,   2,   5, 152,   3,   5,   1,  36,   2,   5, 152,   3,   5,   1,  32,
   0,   0,   1,   0,   0,   0,   1,   0,  44,  35,   0,  37,   1,  38,  39,  82,
   1,   0,  83,  82,   1,   0,  86,  82,   1,   0,  89,  82,   1,   0,  92,  82,
   1,   0,  95,  82,   1,   0,  98,  82,   2,   0,   0,  83,  86,  82,   3,   0,
   0,   0,  92,  86,  98,  82,   3,   0,   0,   0,  95,  83,  86, 180,   1,   3,
 181,   1, 183,   1, 185,   1, 182,   1, 184,   1, 186,   1, 180,   1,   4, 181,
   1, 189,   1, 185,   1, 192,   1, 188,   1, 190,   1, 191,   1, 193,   1, 180,
   1,   3, 181,   1, 185,   1, 192,   1, 194,   1, 191,   1, 193,   1, 180,   1,
   4, 181,   1, 183,   1, 185,   1, 192,   1, 196,   1, 197,   1, 191,   1, 198,
   1, 180,   1,   3, 181,   1, 183,   1, 185,   1, 199,   1, 200,   1, 191,   1,
 180,   1,   4, 181,   1, 183,   1, 185,   1, 192,   1, 201,   1, 202,   1, 191,
   1, 203,   1, 180,   1,   3, 181,   1, 183,   1, 185,   1, 204,   1, 205,   1,
 191,   1, 180,   1,   4, 181,   1, 183,   1, 185,   1, 192,   1, 206,   1, 207,
   1, 191,   1, 208,   1, 180,   1,   3, 181,   1, 183,   1, 185,   1, 209,   1,
 210,   1, 191,   1, 180,   1,   4, 181,   1, 183,   1, 185,   1, 192,   1, 211,
   1, 212,   1, 191,   1, 213,   1, 180,   1,   4, 181,   1, 231,   1, 183,   1,
 185,   1, 230,   1, 190,   1, 232,   1, 191,   1, 180,   1,   4, 181,   1, 183,
   1, 185,   1, 141,   2, 139,   2, 140,   2, 191,   1, 142,   2, 180,   1,   4,
 181,   1, 183,   1, 185,   1, 141,   2, 143,   2, 144,   2, 191,   1, 142,   2,
 180,   1,   4, 181,   1, 183,   1, 185,   1, 141,   2, 145,   2, 146,   2, 191,
   1, 142,   2, 180,   1,   4, 181,   1, 183,   1, 185,   1, 141,   2, 147,   2,
 148,   2, 191,   1, 142,   2, 180,   1,   1,   0, 150,   2, 180,   1,   1,   0,
 152,   2, 180,   1,   1,   0, 154,   2, 180,   1,   1,   0, 156,   2, 180,   1,
   1,   0, 158,   2, 180,   1,   1,   0, 160,   2, 180,   1,   1,   0, 162,   2,
 180,   1,   1,   0, 164,   2, 180,   1,   1,   0, 166,   2, 180,   1,   1,   0,
 168,   2, 180,   1,   1,   0, 172,   2, 180,   1,   1,   0, 174,   2, 180,   1,
   1,   0, 176,   2, 180,   1,   1,   0, 178,   2, 180,   1,   1,   0, 180,   2,
 180,   1,   3, 181,   1, 185,   1, 192,   1, 197,   2, 191,   1, 193,   1, 180,
   1,   4, 181,   1, 231,   1, 183,   1, 185,   1, 202,   2, 190,   1, 203,   2,
 191,   1, 180,   1,   3, 181,   1, 183,   1, 185,   1, 220,   2, 212,   2, 191,
   1,  45,  16,   0,   5,   0,  38,   1,  15,   1,   0,  37,  18,  19,   9,   9,
   0,  41,   1,  17,   1,   0,  40,  22,  19,   9,  11,   0,  44,   1,  21,   1,
   0,  43,  51,  19,   9,  13,   0,  68,   0,  57,  19,   9,  19,   0,  75,   0,
  58,  19,   9,  22,   0,  77,   0,  59,  19,   9,  24,   0,  79,   0,  60,  19,
   9,  26,   0,  81,   0,  61,  19,   9,  28,   0,  83,   0,  65,  19,  11,  32,
   0,  87,   0, 106,  19,   9,  41,   0, 119,  50,  66,   0,   0,   2,  11,  11,
  67,  64,   0,   2,  11,  11,   1,   2,  68,  64,   0,   2,  11,  11,   1,   3,
  69,  64,   0,   2,  11,  11,   1,   4,  70,  64,   0,   2,  11,  11,   1,   5,
  71,  64,   0,   2,  11,  11,   1,   6,  72,  64,   0,   2,  11,  11,   1,   7,
  73,  64,   0,   2,  11,  11,   1,   8,  74,  64,   0,   2,  11,  11,   1,   9,
  75,  64,   0,   2,  11,  11,   1,  10,  76,   6,   0,   2,  11,  11,  77,  70,
   0,   2,  11,  11,   1,   2,  78,  70,   0,   2,  11,  11,   1,   3,  79,  70,
   0,   2,  11,  11,   1,   4,  80,  70,   0,   2,  11,  11,   1,   5,  81,  70,
   0,   2,  11,  11,   1,   6,  82,  70,   0,   2,  11,  11,   1,   7,  83,  70,
   0,   2,  11,  11,   1,   8,  84,  70,   0,   2,  11,  11,   1,   9,  85,  70,
   0,   2,  11,  11,   1,  10,  86,   1,   0,  89,  87,  65,   0,  90,   1,   2,
  88,  65,   0,  91,   1,   3,  89,  65,   0,  92,   1,   4,  90,  65,   0,  93,
   1,   5,  91,  65,   0,  94,   1,   6,  92,  65,   0,  95,   1,   7,  93,  65,
   0,  96,   1,   8,  94,  65,   0,  97,   1,   9,  95,  65,   0,  98,   1,  10,
  96,   2,   0,  99,  97,  66,   0, 100,   1,   2,  98,  66,   0, 101,   1,   3,
  99,  66,   0, 102,   1,   4, 100,  66,   0, 103,   1,   5, 101,  66,   0, 104,
   1,   6, 102,  66,   0, 105,   1,   7, 103,  66,   0, 106,   1,   8, 104,  66,
   0, 107,   1,   9, 105,  66,   0, 108,   1,  10,  96,   3,   0, 109,  97,  67,
   0, 110,   1,   2,  98,  67,   0, 111,   1,   3,  99,  67,   0, 112,   1,   4,
 100,  67,   0, 113,   1,   5, 101,  67,   0, 114,   1,   6, 102,  67,   0, 115,
   1,   7, 103,  67,   0, 116,   1,   8, 104,  67,   0, 117,   1,   9, 105,  67,
   0, 118,   1,  10, 107,  19,   9,  43,   0, 121,   0, 108,  19,   9,  45,   0,
 123,   0, 109,  19,   9,  47,   0, 125,   0, 110,  19,   9,  49,   0, 127,   0,
 111,  19,   9,  51,   0, 129,   1,   0, 112,  19,   9,  53,   0, 131,   1,   0,
 113,  19,   9,  55,   0, 133,   1,   0, 114,  19,   9,  57,   0, 135,   1,   0,
 115,  19,   9,  59,   0, 137,   1,   0, 116,   0,   5,   0, 139,   1,   0, 117,
   0,   5,   0, 141,   1,   0, 118,   0,   5,   0, 143,   1,   0, 119,   0,   5,
   0, 145,   1,   0, 120,   0,   5,   0, 147,   1,   0, 121,   0,   5,   0, 149,
   1,   0, 122,   0,   5,   0, 151,   1,   0, 123,   0,   5,   0, 153,   1,   0,
 124,   0,   5,   0, 155,   1,   0, 125,   0,   5,   0, 157,   1,   0, 126,  58,
   9,  61,   0, 159,   1,   0, 127,  58,   9,  63,   0, 161,   1,   0, 128,   1,
  59,   9,  65,   0, 163,   1,   0, 129,   1,  59,   9,  67,   0, 165,   1,   0,
 130,   1,  60,   9,  69,   0, 167,   1,   0, 131,   1,  60,   9,  71,   0, 169,
   1,   0, 181,   2,  19,   9,  84,   0, 175,   1,   6, 188,   2,   1,   0, 174,
   1, 189,   2,   1,   0, 176,   1, 190,   2,   1,   0, 177,   1, 191,   2,   1,
   0, 178,   1, 192,   2,   2,   0, 179,   1, 192,   2,   3,   0, 180,   1, 213,
   2,  19,  11,  90,   0, 204,   1,   5, 208,   2,   6,   0,   5,   0, 209,   2,
   6,   0,   5,   0, 210,   2,   6,   0,   7,   0, 211,   2,   6,   0,  20,   0,
 212,   2,   1,   0, 203,   1, 216,   2,  19,   9,  93,   0, 206,   1,   2, 214,
   2,   6,   0,  20,   0, 215,   2,   6,   0,  26,   0, 221,   2, 216,   2,  11,
  95,   0, 210,   1,   4, 217,   2,   6,   0,  20,   0, 218,   2,   6,   0,  12,
   0, 219,   2,   2,   0, 208,   1, 220,   2,   2,   0, 209,   1, 222,   2, 216,
   2,  11,  97,   0, 212,   1,   2, 217,   2,   6,   0,  20,   0, 220,   2,   6,
   0,  20,   0, 137,   3,  19,   9, 101,   0, 219,   1,   0, 142,   3,  19,   8,
 108,   0, 223,   1,   1, 141,   3,   1,   0, 222,   1, 149,   3,  19,   9, 112,
   0, 226,   1,   0, 152,   3,  19,   9, 115,   0, 235,   1,   0,  36,   0,  39,
   0,  42,   0,  45,  23,  28,  81,   3,  46,   1,   0,  29,  81,   4,  47,   1,
   1,  30,  17,   5,  48,  31,  17,   6,  49,  32,  17,   7,  50,  33,  17,   8,
  51,  34,  17,   9,  52,  35,  17,  10,  53,  36,  17,  11,  54,  37,  17,  12,
  55,  38,  17,  13,  56,  39,   6,   1,  26,   0,  40,  17,  14,  57,  41,  18,
  15,  58,  42,  18,  16,  59,  43,  18,  17,  60,  44,  17,  18,  61,  45,  17,
  19,  62,  46,  17,  20,  63,  47,  17,  21,  64,  48,  18,  22,  65,  49,  18,
  23,  66,  50,  17,  24,  67,  69,   5,  53,  17,   3,  70,  54,  17,   4,  71,
  34,  17,   5,  72,  55,  17,   6,  73,  56,  17,   7,  74,  76,   0,  78,   0,
  80,   0,  82,   0,  84,   2,  64,  18,   3,  85,  36,  18,   4,  86,  88,   0,
 120,   0, 122,   0, 124,   0, 126,   0, 128,   1,   0, 130,   1,   0, 132,   1,
   0, 134,   1,   0, 136,   1,   0, 138,   1,   0, 140,   1,   0, 142,   1,   0,
 144,   1,   0, 146,   1,   0, 148,   1,   0, 150,   1,   0, 152,   1,   0, 154,
   1,   0, 156,   1,   0, 158,   1,   0, 160,   1,   0, 162,   1,   0, 164,   1,
   0, 166,   1,   0, 168,   1,   0, 171,   1,   2, 186,   2,  18,   3, 172,   1,
 187,   2,  18,   4, 173,   1, 202,   1,   0, 205,   1,   0, 207,   1,   0, 211,
   1,   0, 214,   1,  11, 254,   2,   6,   1,  25,   1,   3, 255,   2,   6,   2,
  25,   3,   3, 128,   3,   6,   3,  25,   2,   3, 129,   3,   6,   4,  25,   4,
   3, 130,   3,   6,   5,  25,   5,   3, 131,   3,   6,   6,   0,   3,   3, 132,
   3,   6,   7,   0,   2,   3, 133,   3,  17,   3, 215,   1, 134,   3,  17,   4,
 216,   1, 135,   3,  17,   5, 217,   1, 136,   3,  17,   6, 218,   1, 221,   1,
   0, 225,   1,   2, 147,   3,   6,   1,   5, 206,   2,   1, 148,   3,   6,   2,
   5, 208,   2,   1, 228,   1,   6, 153,   3,  17,   3, 229,   1, 154,   3,  17,
   4, 230,   1, 155,   3,  17,   5, 231,   1, 156,   3,  17,   6, 232,   1, 157,
   3,  17,   7, 233,   1, 158,   3,  17,   8, 234,   1,   7, 181,   1,   1, 195,
   2,  68,   0,  36,   1,  21, 213,   1,  23, 224,   2,  68,   1,  37,   1,  22,
 225,   2,  68,   2,  38,   1,  23, 226,   2,  68,   3,  39,   1,  24, 227,   2,
  68,   4,  40,   1,  25, 228,   2,  65,  37, 201,   1,   1,  26, 229,   2,  65,
  38, 200,   1,   1,  27, 230,   2,  65,  39, 199,   1,   1,  28, 231,   2,  65,
  40, 198,   1,   1,  29, 232,   2,  65,  41, 197,   1,   1,  30, 233,   2,   1,
  42, 196,   1, 234,   2,  65,  43, 194,   1,   1,  31, 235,   2,  65,  44, 193,
   1,   1,  32, 236,   2,  65,  45, 192,   1,   1,  33, 237,   2,  65,  46, 191,
   1,   1,  34, 238,   2,  65,  47, 190,   1,   1,  35, 239,   2,   1,  48, 189,
   1, 240,   2,   1,  49, 188,   1, 241,   2,   1,  50, 187,   1, 242,   2,  65,
  51, 186,   1,   1,  36, 243,   2,  65,  52, 185,   1,   1,  37, 244,   2,  65,
  53, 184,   1,   1,  38, 245,   2,  65,  54, 183,   1,   1,  39, 246,   2,  65,
  55, 182,   1,   1,  40, 220,   1,   1, 139,   3,  68,   1,  41,   1,  41, 224,
   1,   1, 144,   3,  68,   1,  42,   1,  42, 227,   1,   1, 151,   3,   4,   1,
  43, 236,   1,   1, 160,   3,  68,   1,  44,   1,  43, 170,   1,  99, 226,   1,
   6,   0,   0,  16,   8, 132,   1,   4,   0,   0, 133,   1,   4,   0,   1, 135,
   1,  68,   0,   2,   1,  11, 227,   1,  68,   0,   3,   1,  12, 228,   1,  68,
   0,   4,   1,  13, 229,   1,   1,   1,  35, 230,   1,  68,   0,   5,   1,  14,
 231,   1,  68,   0,  30,   1,  15, 232,   1,   4,   0,  31, 233,   1,  68,   0,
   6,   1,  16, 234,   1,  68,   0,  32,   1,  17, 235,   1,   4,   0,  33, 236,
   1,  68,   0,   7,   1,  18, 237,   1,  68,   0,  34,   1,  19, 238,   1,   4,
   0,  35, 239,   1,  68,   0,   8,   1,  20, 240,   1,   4,   0,   9, 241,   1,
   1,   2,  34, 242,   1,   1,   3,  33,  33,   1,   4,  32,  37,   1,   5,  31,
  40,   1,   6,  30, 243,   1,   6,   0,   0,   1,   6, 244,   1,   6,   0,   0,
   2,   6, 245,   1,   6,   0,   0,   3,   6, 246,   1,   6,   0,   0,   4,   6,
 247,   1,   6,   0,   0,   5,   6, 248,   1,   6,   0,   0,   6,   6, 249,   1,
   0,   0,   2,   0, 250,   1,  64,   0,   2,   0,   1,   2, 251,   1,  64,   0,
   2,   0,   1,   3, 252,   1,  64,   0,   2,   0,   1,   4, 253,   1,  64,   0,
   2,   0,   1,   5, 254,   1,  64,   0,   2,   0,   1,   6, 255,   1,  64,   0,
   2,   0,   1,   7, 128,   2,  64,   0,   2,   0,   1,   8, 129,   2,  64,   0,
   2,   0,   1,   9, 130,   2,  64,   0,   2,   0,   1,  10, 131,   2,   6,   0,
   2,  11,  11, 132,   2,  70,   0,   2,  11,  11,   1,   2, 133,   2,  70,   0,
   2,  11,  11,   1,   3, 134,   2,  70,   0,   2,  11,  11,   1,   4, 135,   2,
  70,   0,   2,  11,  11,   1,   5, 136,   2,  70,   0,   2,  11,  11,   1,   6,
 137,   2,  70,   0,   2,  11,  11,   1,   7, 138,   2,  70,   0,   2,  11,  11,
   1,   8, 139,   2,  70,   0,   2,  11,  11,   1,   9, 140,   2,  70,   0,   2,
  11,  11,   1,  10, 141,   2,   1,   7,  29, 142,   2,  65,   8,  28,   1,   2,
 143,   2,  65,   9,  27,   1,   3, 144,   2,  65,  10,  26,   1,   4, 145,   2,
  65,  11,  25,   1,   5, 146,   2,  65,  12,  24,   1,   6, 147,   2,  65,  13,
  23,   1,   7, 148,   2,  65,  14,  22,   1,   8, 149,   2,  65,  15,  21,   1,
   9, 150,   2,  65,  16,  20,   1,  10, 151,   2,   2,  17,  19, 152,   2,  66,
  18,  18,   1,   2, 153,   2,  66,  19,  17,   1,   3, 154,   2,  66,  20,  16,
   1,   4, 155,   2,  66,  21,  15,   1,   5, 156,   2,  66,  22,  14,   1,   6,
 157,   2,  66,  23,  13,   1,   7, 158,   2,  66,  24,  12,   1,   8, 159,   2,
  66,  25,  11,   1,   9, 160,   2,  66,  26,  10,   1,  10, 151,   2,   3,  27,
   9, 152,   2,  67,  28,   8,   1,   2, 153,   2,  67,  29,   7,   1,   3, 154,
   2,  67,  30,   6,   1,   4, 155,   2,  67,  31,   5,   1,   5, 156,   2,  67,
  32,   4,   1,   6, 157,   2,  67,  33,   3,   1,   7, 158,   2,  67,  34,   2,
   1,   8, 159,   2,  67,  35,   1,   1,   9, 160,   2,  67,  36,   0,   1,  10,
 161,   2,   4,   0,  10, 162,   2,  68,   0,  11,   1,   2, 163,   2,  68,   0,
  12,   1,   3, 164,   2,  68,   0,  13,   1,   4, 165,   2,  68,   0,  14,   1,
   5, 166,   2,  68,   0,  15,   1,   6, 167,   2,  68,   0,  16,   1,   7, 168,
   2,  68,   0,  17,   1,   8, 169,   2,  68,   0,  18,   1,   9, 170,   2,  68,
   0,  19,   1,  10, 171,   2,   4,   0,  20, 172,   2,  68,   0,  21,   1,   2,
 173,   2,  68,   0,  22,   1,   3, 174,   2,  68,   0,  23,   1,   4, 175,   2,
  68,   0,  24,   1,   5, 176,   2,  68,   0,  25,   1,   6, 177,   2,  68,   0,
  26,   1,   7, 178,   2,  68,   0,  27,   1,   8, 179,   2,  68,   0,  28,   1,
   9, 180,   2,  68,   0,  29,   1,  10, 162,   1,   0,   1,   2,   1,   2,   3,
 208,  48,  71,   0,   0,   1,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,
   2,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   3,   1,   2,   1,   2,
   3, 208,  48,  71,   0,   0,   4,   1,   2,   1,   2,   3, 208,  48,  71,   0,
   0,   5,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   6,   1,   2,   1,
   2,   3, 208,  48,  71,   0,   0,   7,   1,   2,   1,   2,   3, 208,  48,  71,
   0,   0,   8,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   9,   1,   2,
   1,   2,   3, 208,  48,  71,   0,   0,  10,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  11,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  12,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  13,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  14,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  15,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  16,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  17,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  18,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  19,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  20,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  21,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  22,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  23,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  24,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  25,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  26,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  27,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  28,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  29,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  30,   1,   1,   1,   2,  10, 208,  48,
  93,   3, 102,   3,  70,   4,   0,  72,   0,   0,  31,   1,   1,   1,   2,  10,
 208,  48,  93,   3, 102,   3,  70,   6,   0,  72,   0,   0,  32,   2,   2,   1,
   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   8,   1,  41,  71,   0,   0,
  33,   2,   2,   1,   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   8,   1,
  41,  71,   0,   0,  34,   2,   2,   1,   2,  13, 208,  48,  93,   9, 102,   9,
 102,  10, 209,  70,  11,   1,  72,   0,   0,  35,   1,   1,   1,   2,  11, 208,
  48,  93,  13, 102,  13,  70,  14,   0,  41,  71,   0,   0,  36,   0,   1,   3,
   3,   1,  71,   0,   0,  39,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
  40,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0,  41,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0,  42,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0,  44,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0,  45,   2,   1,   3,   4,  12, 208,  48,  94,  23,  93,  24,  70,  24,
   0, 104,  23,  71,   0,   0,  68,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0,  69,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  75,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  76,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0,  77,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0,  78,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0,  79,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  80,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  81,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0,  82,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0,  83,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0,  84,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  85,   1,   1,   3,
   4,   5, 208,  48,  44,  74,  72,   0,   0,  86,   1,   1,   3,   4,  10, 208,
  48,  93,  62, 102,  62,  70,  63,   0,  72,   0,   0,  87,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0,  88,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0,  89,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
  90,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  91,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0,  92,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0,  93,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
  94,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  95,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0,  96,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0,  97,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
  98,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  99,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 100,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 101,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 102,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 103,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 104,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 105,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 106,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 107,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 108,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 109,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 110,
   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 111,   1,   2,   4,   5,   3,
 208,  48,  71,   0,   0, 112,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0,
 113,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 114,   1,   2,   4,   5,
   3, 208,  48,  71,   0,   0, 115,   1,   2,   4,   5,   3, 208,  48,  71,   0,
   0, 116,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 117,   1,   2,   4,
   5,   3, 208,  48,  71,   0,   0, 118,   1,   2,   4,   5,   3, 208,  48,  71,
   0,   0, 119,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 120,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 121,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 122,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 123,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 124,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 125,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 126,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 127,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 128,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 129,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 130,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 131,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 132,   1,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 133,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 134,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 135,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 136,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 137,   1,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 138,   1,   0,   1,   3,
   3,   1,  71,   0,   0, 140,   1,   0,   1,   3,   3,   1,  71,   0,   0, 142,
   1,   0,   1,   3,   3,   1,  71,   0,   0, 144,   1,   0,   1,   3,   3,   1,
  71,   0,   0, 146,   1,   0,   1,   3,   3,   1,  71,   0,   0, 148,   1,   0,
   1,   3,   3,   1,  71,   0,   0, 150,   1,   0,   1,   3,   3,   1,  71,   0,
   0, 152,   1,   0,   1,   3,   3,   1,  71,   0,   0, 154,   1,   0,   1,   3,
   3,   1,  71,   0,   0, 156,   1,   0,   1,   3,   3,   1,  71,   0,   0, 158,
   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 159,   1,   1,   1,   5,
   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 160,   1,   1,   1,   4,   5,
   3, 208,  48,  71,   0,   0, 161,   1,   1,   1,   5,   6,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 162,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 163,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 164,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 165,   1,   1,   1,
   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 166,   1,   1,   1,   4,
   5,   3, 208,  48,  71,   0,   0, 167,   1,   1,   1,   5,   6,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 168,   1,   1,   1,   4,   5,   3, 208,  48,  71,
   0,   0, 169,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 170,   1,   3,   1,   1,   4, 184,   6, 208,  48,  93, 132,   1,  32,  88,
   0, 104,  16,  93, 133,   1,  93,  19, 102,  19,  48,  93, 134,   1, 102, 134,
   1,  88,   1,  29, 104,  18,  93, 135,   1,  93,  19, 102,  19,  48,  93, 134,
   1, 102, 134,   1,  88,   2,  29, 104,  22,  93, 136,   1,  93,  19, 102,  19,
  48,  93, 134,   1, 102, 134,   1,  88,   3,  29, 104,  51,  93, 137,   1,  93,
  19, 102,  19,  48,  93, 134,   1, 102, 134,   1,  88,   4,  29, 104,  57,  93,
 138,   1,  93,  19, 102,  19,  48,  93, 139,   1, 102, 139,   1,  88,   5,  29,
 104,  58,  93, 140,   1,  93,  19, 102,  19,  48,  93,  58, 102,  58,  48,  93,
 141,   1, 102, 141,   1,  88,  30,  29,  29, 104, 126,  93, 142,   1,  93,  19,
 102,  19,  48,  93,  58, 102,  58,  48,  93, 141,   1, 102, 141,   1,  88,  31,
  29,  29, 104, 127,  93, 143,   1,  93,  19, 102,  19,  48,  93, 139,   1, 102,
 139,   1,  88,   6,  29, 104,  59,  93, 144,   1,  93,  19, 102,  19,  48,  93,
  59, 102,  59,  48,  93, 145,   1, 102, 145,   1,  88,  32,  29,  29, 104, 128,
   1,  93, 146,   1,  93,  19, 102,  19,  48,  93,  59, 102,  59,  48,  93, 145,
   1, 102, 145,   1,  88,  33,  29,  29, 104, 129,   1,  93, 147,   1,  93,  19,
 102,  19,  48,  93, 139,   1, 102, 139,   1,  88,   7,  29, 104,  60,  93, 148,
   1,  93,  19, 102,  19,  48,  93,  60, 102,  60,  48,  93, 149,   1, 102, 149,
   1,  88,  34,  29,  29, 104, 130,   1,  93, 150,   1,  93,  19, 102,  19,  48,
  93,  60, 102,  60,  48,  93, 149,   1, 102, 149,   1,  88,  35,  29,  29, 104,
 131,   1,  93, 151,   1,  93,  19, 102,  19,  48,  93, 139,   1, 102, 139,   1,
  88,   8,  29, 104,  61,  93, 152,   1,  93,  19, 102,  19,  48,  93, 153,   1,
 102, 153,   1,  88,   9,  29, 104,  65,  93, 154,   1,  93,  19, 102,  19,  48,
  93, 139,   1, 102, 139,   1,  88,  10,  29, 104, 106,  93, 155,   1,  93,  19,
 102,  19,  48,  93, 139,   1, 102, 139,   1,  88,  11,  29, 104, 107,  93, 156,
   1,  93,  19, 102,  19,  48,  93, 139,   1, 102, 139,   1,  88,  12,  29, 104,
 108,  93, 157,   1,  93,  19, 102,  19,  48,  93, 139,   1, 102, 139,   1,  88,
  13,  29, 104, 109,  93, 158,   1,  93,  19, 102,  19,  48,  93, 139,   1, 102,
 139,   1,  88,  14,  29, 104, 110,  93, 159,   1,  93,  19, 102,  19,  48,  93,
 139,   1, 102, 139,   1,  88,  15,  29, 104, 111,  93, 160,   1,  93,  19, 102,
  19,  48,  93, 139,   1, 102, 139,   1,  88,  16,  29, 104, 112,  93, 161,   1,
  93,  19, 102,  19,  48,  93, 139,   1, 102, 139,   1,  88,  17,  29, 104, 113,
  93, 162,   1,  93,  19, 102,  19,  48,  93, 139,   1, 102, 139,   1,  88,  18,
  29, 104, 114,  93, 163,   1,  93,  19, 102,  19,  48,  93, 139,   1, 102, 139,
   1,  88,  19,  29, 104, 115,  93, 164,   1,  32,  88,  20, 104, 116,  93, 165,
   1,  32,  88,  21, 104, 117,  93, 166,   1,  32,  88,  22, 104, 118,  93, 167,
   1,  32,  88,  23, 104, 119,  93, 168,   1,  32,  88,  24, 104, 120,  93, 169,
   1,  32,  88,  25, 104, 121,  93, 170,   1,  32,  88,  26, 104, 122,  93, 171,
   1,  32,  88,  27, 104, 123,  93, 172,   1,  32,  88,  28, 104, 124,  93, 173,
   1,  32,  88,  29, 104, 125,  93, 174,   1,  37, 149,   5,  37, 148,   5, 161,
 104, 175,   1,  93, 176,   1,  37, 150,   5,  37, 148,   5, 161, 104, 177,   1,
  93, 178,   1,  37, 151,   5,  37, 148,   5, 161, 104, 179,   1,  93, 180,   1,
  37, 152,   5,  37, 148,   5, 161, 104, 181,   1,  93, 182,   1,  37, 153,   5,
  37, 148,   5, 161, 104, 183,   1,  93, 184,   1,  37, 154,   5,  37, 148,   5,
 161, 104, 185,   1,  93, 186,   1,  38,  97, 187,   1,  93, 188,   1,  38,  97,
 189,   1,  93, 190,   1,  38,  97, 191,   1,  93, 192,   1,  38,  97, 193,   1,
  93, 194,   1,  38,  97, 195,   1,  93, 196,   1,  38,  97, 197,   1,  93, 198,
   1,  38,  97, 199,   1,  93, 200,   1,  38,  97, 201,   1,  93, 202,   1,  38,
  97, 203,   1,  93, 204,   1,  38,  97, 205,   1,  93, 206,   1,  38, 104, 207,
   1,  93, 208,   1,  38, 104, 209,   1,  93, 210,   1,  38, 104, 211,   1,  93,
 212,   1,  38, 104, 213,   1,  93, 214,   1,  38, 104, 215,   1,  93, 216,   1,
  38, 104, 217,   1,  93, 218,   1,  38, 104, 219,   1,  93, 220,   1,  38, 104,
 221,   1,  93, 222,   1,  38, 104, 223,   1,  93, 224,   1,  38, 104, 225,   1,
  71,   0,   0, 171,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 175,
   1,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 182,   2,
   1,  41,  71,   0,   0, 178,   1,   3,   3,   4,   5,  20, 208,  48, 208,  93,
 183,   2, 102, 183,   2, 209,  70, 184,   2,   1, 210,  70, 185,   2,   2,  72,
   0,   0, 181,   1,   2,   1,   1,   3,  23, 208,  48,  93, 193,   2,  93,  19,
 102,  19,  48,  93, 194,   2, 102, 194,   2,  88,  36,  29, 104, 181,   2,  71,
   0,   0, 187,   1,   4,   3,   1,   2,  14, 208,  48,  93, 198,   2, 209, 210,
  36,   1,  70, 198,   2,   3,  72,   0,   0, 188,   1,   4,   3,   1,   2,  14,
 208,  48,  93, 198,   2, 209, 210,  36,   2,  70, 198,   2,   3,  72,   0,   0,
 189,   1,   4,   3,   1,   2,  14, 208,  48,  93, 198,   2, 209, 210,  36,   0,
  70, 198,   2,   3,  72,   0,   0, 195,   1,   3,   3,   3,   6,  47,  87,  42,
 213,  48, 101,   0,  38, 118, 109,   1,  93, 199,   2,  76, 199,   2,   0,  41,
  16,  20,   0,   0, 209,  48,  90,   0,  42, 214,  42,  48,  43, 109,   1, 101,
   0,  39, 118, 109,   1,  29,   8,   2, 101,   0, 108,   1,  72,   1,  10,  18,
  22,   0, 200,   2,   1, 201,   2,   0,   1,   2,   0, 196,   1,   2,   3,   2,
   4,  60, 208,  48,  87,  42, 214,  48, 101,   1,  33, 130, 109,   2, 101,   1,
 209, 109,   1, 101,   1, 108,   1,  32,  19,  24,   0,   0, 101,   1,  64, 195,
   1, 130, 109,   2,  93, 202,   2, 101,   1, 108,   2,  70, 202,   2,   1,  41,
  16,   9,   0,   0,  93, 202,   2,  32,  70, 202,   2,   1,  41,  71,   0,   2,
 203,   2,   0,   1, 196,   2,   0, 204,   2,   0,   2,   0,   0, 202,   1,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0, 203,   1,   3,   1,   4,   5,  50,
 208,  48, 208, 102, 205,   2,  44, 245,   1, 160, 208, 102, 206,   2, 118,  18,
  26,   0,   0,  44, 247,   1, 208, 102, 206,   2, 160,  44, 248,   1, 160, 208,
 102, 207,   2, 160,  44, 250,   1, 160, 130,  16,   3,   0,   0,  44,   1, 130,
 160,  72,   0,   0, 204,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 205,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 206,
   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 207,   1,
   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 210,   1,   1,   1,   5,   6,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 211,   1,   1,   1,   4,   5,   3,
 208,  48,  71,   0,   0, 212,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 213,   1,   2,   1,   1,   4,  89, 208,  48, 101,   0,  93,
  19, 102,  19,  48,  93, 223,   2, 102, 223,   2,  88,  37,  29, 104, 213,   2,
 101,   0,  93,  19, 102,  19,  48,  93, 223,   2, 102, 223,   2,  88,  38,  29,
 104, 216,   2, 101,   0,  93,  19, 102,  19,  48,  93, 216,   2, 102, 216,   2,
  48, 100, 108,   2,  88,  39,  29,  29, 104, 221,   2, 101,   0,  93,  19, 102,
  19,  48,  93, 216,   2, 102, 216,   2,  48, 100, 108,   2,  88,  40,  29,  29,
 104, 222,   2,  71,   0,   0, 214,   1,   2,   1,   3,   4,  59, 208,  48,  94,
 247,   2,  36,   0, 104, 247,   2,  94, 248,   2,  36,   1, 104, 248,   2,  94,
 249,   2,  36,   2, 104, 249,   2,  94, 250,   2,  36,   3, 104, 250,   2,  94,
 251,   2,  36,   4, 104, 251,   2,  94, 252,   2,  36,   1, 104, 252,   2,  94,
 253,   2,  36,   2, 104, 253,   2,  71,   0,   0, 219,   1,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 220,   1,   2,   1,   1,   3,  22,
 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 138,   3, 102, 138,   3,  88,
  41,  29, 104, 137,   3,  71,   0,   0, 221,   1,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 223,   1,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0,
 208, 209,  70, 140,   3,   1,  41,  71,   0,   0, 224,   1,   2,   1,   1,   3,
  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 143,   3, 102, 143,   3,
  88,  42,  29, 104, 142,   3,  71,   0,   0, 225,   1,   2,   1,   3,   4,  21,
 208,  48,  94, 145,   3,  44, 206,   2, 104, 145,   3,  94, 146,   3,  44, 208,
   2, 104, 146,   3,  71,   0,   0, 226,   1,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 227,   1,   2,   1,   1,   3,  22, 208,  48, 101,
   0,  93,  19, 102,  19,  48,  93, 150,   3, 102, 150,   3,  88,  43,  29, 104,
 149,   3,  71,   0,   0, 228,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 235,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 236,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,
  93, 159,   3, 102, 159,   3,  88,  44,  29, 104, 152,   3,  71,   0,   0};


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
    const char* const n_0; ::avmplus::ScriptObject* const m_0;
    const char* const n_1; ::avmshell::AbstractBaseClass* const m_1;
    const char* const n_2; ::avmshell::AbstractBaseObject* const m_2;
    const char* const n_3; ::avmshell::AbstractRestrictedBaseClass* const m_3;
    const char* const n_4; ::avmshell::AbstractRestrictedBaseObject* const m_4;
    const char* const n_5; ::avmshell::CheckBaseClass* const m_5;
    const char* const n_6; ::avmshell::CheckBaseObject* const m_6;
    const char* const n_7; ::avmshell::FileClass* const m_7;
    const char* const n_8; ::avmshell::MIClass* const m_8;
    const char* const n_9; ::avmshell::MIObject* const m_9;
    const char* const n_10; ::avmshell::NativeSubclassOfAbstractBaseClass* const m_10;
    const char* const n_11; ::avmshell::NativeSubclassOfAbstractBaseObject* const m_11;
    const char* const n_12; ::avmshell::NativeSubclassOfAbstractRestrictedBaseClass* const m_12;
    const char* const n_13; ::avmshell::NativeSubclassOfAbstractRestrictedBaseObject* const m_13;
    const char* const n_14; ::avmshell::NativeSubclassOfRestrictedBaseClass* const m_14;
    const char* const n_15; ::avmshell::NativeSubclassOfRestrictedBaseObject* const m_15;
    const char* const n_16; ::avmshell::RestrictedBaseClass* const m_16;
    const char* const n_17; ::avmshell::RestrictedBaseObject* const m_17;
    const char* const n_18; ::avmshell::SystemClass* const m_18;
    const char* const n_19; DeleteObjectSampleClass* const m_19;
    const char* const n_20; DeleteObjectSampleObject* const m_20;
    const char* const n_21; DictionaryClass* const m_21;
    const char* const n_22; DictionaryObject* const m_22;
    const char* const n_23; DomainClass* const m_23;
    const char* const n_24; DomainObject* const m_24;
    const char* const n_25; JObject* const m_25;
    const char* const n_26; JObjectClass* const m_26;
    const char* const n_27; NewObjectSampleClass* const m_27;
    const char* const n_28; NewObjectSampleObject* const m_28;
    const char* const n_29; SampleClass* const m_29;
    const char* const n_30; SampleObject* const m_30;
    const char* const n_31; StackFrameClass* const m_31;
    const char* const n_32; StackFrameObject* const m_32;
    const char* const n_33; TraceClass* const m_33;
} aotABCTypes_shell_toplevel = {
    "::avmplus::ScriptObject", 0,
    "::avmshell::AbstractBaseClass", 0,
    "::avmshell::AbstractBaseObject", 0,
    "::avmshell::AbstractRestrictedBaseClass", 0,
    "::avmshell::AbstractRestrictedBaseObject", 0,
    "::avmshell::CheckBaseClass", 0,
    "::avmshell::CheckBaseObject", 0,
    "::avmshell::FileClass", 0,
    "::avmshell::MIClass", 0,
    "::avmshell::MIObject", 0,
    "::avmshell::NativeSubclassOfAbstractBaseClass", 0,
    "::avmshell::NativeSubclassOfAbstractBaseObject", 0,
    "::avmshell::NativeSubclassOfAbstractRestrictedBaseClass", 0,
    "::avmshell::NativeSubclassOfAbstractRestrictedBaseObject", 0,
    "::avmshell::NativeSubclassOfRestrictedBaseClass", 0,
    "::avmshell::NativeSubclassOfRestrictedBaseObject", 0,
    "::avmshell::RestrictedBaseClass", 0,
    "::avmshell::RestrictedBaseObject", 0,
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
    "StackFrameClass", 0,
    "StackFrameObject", 0,
    "TraceClass", 0,
};
#endif
} }
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::MIClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::MIClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmshell::MIObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::MIObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::SystemClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::FileClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::RestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::RestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmshell::RestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::RestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CheckBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::CheckBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    avmshell::CheckBaseClass::preCreateInstanceCheck(cls);
    return new(cls->gc(), cls->getExtraSize()) avmshell::CheckBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CheckBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfAbstractBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmshell::NativeSubclassOfAbstractBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractBaseObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmshell::NativeSubclassOfRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::RestrictedBaseObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmshell::NativeSubclassOfAbstractRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractRestrictedBaseObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DomainClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return avmplus::DomainObject::create(cls->gc(), cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::StackFrameClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmplus::StackFrameObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmplus::SampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::NewObjectSampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmplus::NewObjectSampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DeleteObjectSampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmplus::DeleteObjectSampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DictionaryClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DictionaryClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return avmplus::DictionaryObject::create(cls->gc(), cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DictionaryObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::JObjectClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::JObjectClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new(cls->gc(), cls->getExtraSize()) avmplus::JObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::JObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
