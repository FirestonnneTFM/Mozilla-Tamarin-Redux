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

const uint32_t shell_toplevel_abc_class_count = 50;
const uint32_t shell_toplevel_abc_script_count = 7;
const uint32_t shell_toplevel_abc_method_count = 249;
const uint32_t shell_toplevel_abc_length = 16009;

/* thunks (64 total) */
avmplus::Atom avmplus_Domain_currentDomain_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::DomainClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainClass*, argv[argoff0]);
    avmplus::DomainObject* const ret = obj->get_currentDomain();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::DomainClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainClass*, argv[argoff0]);
    uint32_t const ret = obj->get_MIN_DOMAIN_MEMORY_LENGTH();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    obj->init(
        (avmplus::DomainObject*)AvmThunkUnbox_OBJECT(avmplus::DomainObject*, argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->loadBytes(
        (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_INT_UINT(0) : AvmThunkUnbox_UINT(uint32_t, argv[argoff2]))
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::ClassClosure* const ret = obj->getClass(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_Domain_domainMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::ByteArrayObject* const ret = obj->get_domainMemory();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    obj->set_domainMemory(
        (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1])
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
    avmplus::NewObjectSampleObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::NewObjectSampleObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->get_object();
    return avmplus::Atom(ret);
}
double flash_sampler_NewObjectSample_size_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::NewObjectSampleObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::NewObjectSampleObject*, argv[argoff0]);
    double const ret = obj->get_size();
    return double(ret);
}
avmplus::Atom native_script_function_flash_sampler_clearSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
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
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
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
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
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
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::pauseSampling(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_BOOLEAN(bool32, argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1])
    );
    return undefinedAtom;
}
double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1])
    );
    return double(ret);
}
avmplus::Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_BOOLEAN(bool32, argv[argoff2]))
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler__getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::_getSamples(obj
        , (avmplus::ClassClosure*)AvmThunkUnbox_OBJECT(avmplus::ClassClosure*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
double native_script_function_flash_sampler_getSampleCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return double(ret);
}
double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
        , argoff3 = argoff2 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1])
        , (avmplus::QNameObject*)AvmThunkUnbox_OBJECT(avmplus::QNameObject*, argv[argoff2])
        , AvmThunkUnbox_UINT(uint32_t, argv[argoff3])
    );
    return double(ret);
}
avmplus::Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1])
        , (avmplus::QNameObject*)AvmThunkUnbox_OBJECT(avmplus::QNameObject*, argv[argoff2])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::ArrayObject* const ret = SamplerScript::getLexicalScopes(obj
        , (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getSavedThis(obj
        , (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_INT
    };
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->setLevel(
        AvmThunkUnbox_INT(int32_t, argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_INT(int32_t, argv[argoff2]))
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_INT(int32_t, argv[argoff1]))
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->setListener(
        (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_getListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::FunctionObject* const ret = obj->getListener();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_utils_Dictionary_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::DictionaryObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DictionaryObject*, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_BOOLEAN(bool32, argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_JObject_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_STRING;
    (void)env;
    avmplus::JObjectClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::JObjectClass*, argv[argoff0]);
    avmplus::JObject* const ret = obj->create(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_JObject_createArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
        , argoff3 = argoff2 + AvmThunkArgSize_INT
    };
    (void)env;
    avmplus::JObjectClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::JObjectClass*, argv[argoff0]);
    avmplus::JObject* const ret = obj->createArray(
        (avmplus::JObject*)AvmThunkUnbox_OBJECT(avmplus::JObject*, argv[argoff1])
        , AvmThunkUnbox_INT(int32_t, argv[argoff2])
        , (avmplus::ArrayObject*)(argc < 3 ? AvmThunkCoerce_ATOM_OBJECT(nullObjectAtom) : (avmplus::ArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ArrayObject*, argv[argoff3]))
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_JObject_toArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::JObjectClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::JObjectClass*, argv[argoff0]);
    avmplus::ArrayObject* const ret = obj->toArray(
        (avmplus::JObject*)AvmThunkUnbox_OBJECT(avmplus::JObject*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_JObject_constructorSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_STRING;
    (void)env;
    avmplus::JObjectClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::JObjectClass*, argv[argoff0]);
    avmplus::String* const ret = obj->constructorSignature(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_JObject_methodSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_STRING;
    (void)env;
    avmplus::JObjectClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::JObjectClass*, argv[argoff0]);
    avmplus::String* const ret = obj->methodSignature(
        (avmplus::JObject*)AvmThunkUnbox_OBJECT(avmplus::JObject*, argv[argoff1])
        , AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_JObject_fieldSignature_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmplus::JObjectClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::JObjectClass*, argv[argoff0]);
    avmplus::String* const ret = obj->fieldSignature(
        (avmplus::JObject*)AvmThunkUnbox_OBJECT(avmplus::JObject*, argv[argoff1])
        , AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2])
    );
    return avmplus::Atom(ret);
}
double avmplus_MI_plus_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::MIObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::MIObject*, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_DOUBLE(double, argv[argoff1])
    );
    return double(ret);
}
avmplus::Atom avmplus_System_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_INT(int32_t, argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_getAvmplusVersion_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getAvmplusVersion();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_getFeatures_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getFeatures();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_getRunmode_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getRunmode();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->trace(
        (avmplus::ArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ArrayObject*, argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
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
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
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
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    bool const ret = obj->isDebugger();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_getTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    uint32_t const ret = obj->getTimer();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_private_getArgv_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    avmplus::ArrayObject* const ret = obj->getArgv();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_readLine_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    avmplus::String* const ret = obj->readLine();
    return avmplus::Atom(ret);
}
double avmplus_System_totalMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    double const ret = obj->get_totalMemory();
    return double(ret);
}
double avmplus_System_freeMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    double const ret = obj->get_freeMemory();
    return double(ret);
}
double avmplus_System_privateMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    double const ret = obj->get_privateMemory();
    return double(ret);
}
avmplus::Atom avmplus_System_forceFullCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
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
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
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
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->ns_example_nstest();
    return undefinedAtom;
}
avmplus::Atom avmplus_System_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    bool const ret = obj->isGlobal(
        AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_swfVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    int32_t const ret = obj->get_swfVersion();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_apiVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    int32_t const ret = obj->get_apiVersion();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->disposeXML(
        (avmplus::XMLObject*)AvmThunkUnbox_OBJECT(avmplus::XMLObject*, argv[argoff1])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_pauseForGCIfCollectionImminent_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->pauseForGCIfCollectionImminent(
        (argc < 1 ? 0.75 : AvmThunkUnbox_DOUBLE(double, argv[argoff1]))
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_File_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    bool const ret = obj->exists(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_File_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    avmplus::String* const ret = obj->read(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_File_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
        , AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2])
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_File_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    avmplus::ByteArrayObject* const ret = obj->readByteArray(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_File_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    bool const ret = obj->writeByteArray(
        AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1])
        , (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff2])
    );
    return avmplus::Atom(ret);
}

class SlotOffsetsAndAsserts
{
public:
    static uint32_t getSlotOffset(Traits* t, int nameId);
    enum {
        kSlotsOffset_avmplus_CTestClass = 0,
        kSlotsOffset_avmplus_CTestObject = 0,
        kSlotsOffset_avmshell_MIClass = 0,
        kSlotsOffset_avmshell_MIObject = 0,
        kSlotsOffset_avmshell_SystemClass = offsetof(avmshell::SystemClass, m_slots_SystemClass),
        kSlotsOffset_avmplus_SystemObject = 0,
        kSlotsOffset_avmshell_FileClass = 0,
        kSlotsOffset_avmplus_FileObject = 0,
        kSlotsOffset_avmshell_AbstractBaseClass = 0,
        kSlotsOffset_avmshell_AbstractBaseObject = 0,
        kSlotsOffset_avmshell_RestrictedBaseClass = 0,
        kSlotsOffset_avmshell_RestrictedBaseObject = 0,
        kSlotsOffset_avmshell_AbstractRestrictedBaseClass = 0,
        kSlotsOffset_avmshell_AbstractRestrictedBaseObject = 0,
        kSlotsOffset_avmshell_CheckBaseClass = 0,
        kSlotsOffset_avmshell_CheckBaseObject = 0,
        kSlotsOffset_avmshell_NativeBaseClass = 0,
        kSlotsOffset_avmshell_NativeBaseObject = 0,
        kSlotsOffset_avmplus_NativeBaseAS3Class = 0,
        kSlotsOffset_avmplus_NativeBaseAS3Object = 0,
        kSlotsOffset_avmplus_ShellCoreFriend1Class = offsetof(avmplus::ShellCoreFriend1Class, m_slots_ShellCoreFriend1Class),
        kSlotsOffset_avmplus_ShellCoreFriend1Object = 0,
        kSlotsOffset_avmplus_ShellCoreFriend2Class = offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class),
        kSlotsOffset_avmplus_ShellCoreFriend2Object = 0,
        kSlotsOffset_avmplus_CapabilitiesClass = 0,
        kSlotsOffset_avmplus_CapabilitiesObject = 0,
        kSlotsOffset_avmplus_public_classClass = 0,
        kSlotsOffset_avmplus_public_classObject = offsetof(avmplus::public_classObject, m_slots_public_classObject),
        kSlotsOffset_avmplus_public_class_AIR_1_0Class = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_0Object = 0,
        kSlotsOffset_avmplus_public_class_FP_10_0Class = 0,
        kSlotsOffset_avmplus_public_class_FP_10_0Object = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5Class = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5Object = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5_1Class = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5_1Object = 0,
        kSlotsOffset_avmplus_public_class_FP_10_0_32Class = 0,
        kSlotsOffset_avmplus_public_class_FP_10_0_32Object = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5_2Class = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5_2Object = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_0_FP_10_0Class = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_0_FP_10_0Object = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class = 0,
        kSlotsOffset_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object = 0,
        kSlotsOffset_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class = 0,
        kSlotsOffset_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Object = 0,
        kSlotsOffset_avmshell_NativeSubclassOfAbstractBaseClass = 0,
        kSlotsOffset_avmshell_NativeSubclassOfAbstractBaseObject = 0,
        kSlotsOffset_avmplus_SubclassOfAbstractBaseClass = 0,
        kSlotsOffset_avmplus_SubclassOfAbstractBaseObject = 0,
        kSlotsOffset_avmshell_NativeSubclassOfRestrictedBaseClass = 0,
        kSlotsOffset_avmshell_NativeSubclassOfRestrictedBaseObject = 0,
        kSlotsOffset_avmplus_SubclassOfRestrictedBaseClass = 0,
        kSlotsOffset_avmplus_SubclassOfRestrictedBaseObject = 0,
        kSlotsOffset_avmshell_NativeSubclassOfAbstractRestrictedBaseClass = 0,
        kSlotsOffset_avmshell_NativeSubclassOfAbstractRestrictedBaseObject = 0,
        kSlotsOffset_avmplus_SubclassOfAbstractRestrictedBaseClass = 0,
        kSlotsOffset_avmplus_SubclassOfAbstractRestrictedBaseObject = 0,
        kSlotsOffset_avmplus_DomainClass = 0,
        kSlotsOffset_avmplus_DomainObject = 0,
        kSlotsOffset_avmplus_StackFrameClass = 0,
        kSlotsOffset_avmplus_StackFrameObject = offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject),
        kSlotsOffset_avmplus_SampleClass = 0,
        kSlotsOffset_avmplus_SampleObject = offsetof(avmplus::SampleObject, m_slots_SampleObject),
        kSlotsOffset_avmplus_ClassFactoryClass = offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass),
        kSlotsOffset_avmplus_ClassFactoryObject = 0,
        kSlotsOffset_avmplus_NewObjectSampleClass = 0,
        kSlotsOffset_avmplus_NewObjectSampleObject = offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject),
        kSlotsOffset_avmplus_DeleteObjectSampleClass = 0,
        kSlotsOffset_avmplus_DeleteObjectSampleObject = offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject),
        kSlotsOffset_avmplus_TraceClass = offsetof(avmplus::TraceClass, m_slots_TraceClass),
        kSlotsOffset_avmplus_TraceObject = 0,
        kSlotsOffset_avmplus_DictionaryClass = 0,
        kSlotsOffset_avmplus_DictionaryObject = 0,
        kSlotsOffset_avmplus_EndianClass = offsetof(avmplus::EndianClass, m_slots_EndianClass),
        kSlotsOffset_avmplus_EndianObject = 0,
        kSlotsOffset_avmplus_JObjectClass = 0,
        kSlotsOffset_avmplus_JObject = 0,
        kSlotsOffset_fnord
    };
    #ifdef DEBUG
    static void check_avmplus_CTestClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_MIClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_SystemClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_FileClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_AbstractBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_RestrictedBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_AbstractRestrictedBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_CheckBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_NativeBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_NativeBaseAS3Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_ShellCoreFriend1Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_ShellCoreFriend2Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_CapabilitiesClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_classClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_AIR_1_0Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_FP_10_0Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_AIR_1_5Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_AIR_1_5_1Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_FP_10_0_32Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_AIR_1_5_2Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_AIR_1_0_FP_10_0Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(Traits* ctraits, Traits* itraits);
    static void check_avmshell_NativeSubclassOfAbstractBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SubclassOfAbstractBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_NativeSubclassOfRestrictedBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SubclassOfRestrictedBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_NativeSubclassOfAbstractRestrictedBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SubclassOfAbstractRestrictedBaseClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DomainClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_StackFrameClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_ClassFactoryClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_NewObjectSampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DeleteObjectSampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_TraceClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DictionaryClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_EndianClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_JObjectClass(Traits* ctraits, Traits* itraits);
    #endif
};
#ifdef DEBUG
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_CTestClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_MIClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_SystemClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmshell::SystemClass, m_slots_SystemClass) == kSlotsOffset_avmshell_SystemClass);
    MMGC_STATIC_ASSERT(offsetof(avmshell::SystemClass, m_slots_SystemClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::SystemClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 39) == (offsetof(avmshell::SystemClass, m_slots_SystemClass) + offsetof(avmshell_SystemClassSlots, m_argv)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_FileClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_AbstractBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_RestrictedBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_AbstractRestrictedBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_CheckBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_NativeBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NativeBaseAS3Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend1Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend1Class, m_slots_ShellCoreFriend1Class) == kSlotsOffset_avmplus_ShellCoreFriend1Class);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend1Class, m_slots_ShellCoreFriend1Class) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ShellCoreFriend1Class) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 66) == (offsetof(avmplus::ShellCoreFriend1Class, m_slots_ShellCoreFriend1Class) + offsetof(avmplus_ShellCoreFriend1ClassSlots, m_private_foo)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend2Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) == kSlotsOffset_avmplus_ShellCoreFriend2Class);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ShellCoreFriend2Class) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 69) == (offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) + offsetof(avmplus_ShellCoreFriend2ClassSlots, m_private_bar)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_CapabilitiesClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_classClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::public_classObject, m_slots_public_classObject) == kSlotsOffset_avmplus_public_classObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::public_classObject, m_slots_public_classObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::public_classObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 75) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var)));
    AvmAssert(getSlotOffset(itraits, 76) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_0)));
    AvmAssert(getSlotOffset(itraits, 77) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 78) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5)));
    AvmAssert(getSlotOffset(itraits, 79) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_1)));
    AvmAssert(getSlotOffset(itraits, 80) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0_32)));
    AvmAssert(getSlotOffset(itraits, 81) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 82) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 83) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 84) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0_32_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 85) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const)));
    AvmAssert(getSlotOffset(itraits, 86) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_0)));
    AvmAssert(getSlotOffset(itraits, 87) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 88) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5)));
    AvmAssert(getSlotOffset(itraits, 89) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_1)));
    AvmAssert(getSlotOffset(itraits, 90) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0_32)));
    AvmAssert(getSlotOffset(itraits, 91) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 92) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 93) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 94) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0_32_AIR_1_0_FP_10_0)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_0Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_1Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0_32Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_2Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_0_FP_10_0Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfAbstractBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SubclassOfAbstractBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfRestrictedBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SubclassOfRestrictedBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfAbstractRestrictedBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SubclassOfAbstractRestrictedBaseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DomainClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_StackFrameClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) == kSlotsOffset_avmplus_StackFrameObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::StackFrameObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 354) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(itraits, 355) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(itraits, 356) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(itraits, 357) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_scriptID)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) == kSlotsOffset_avmplus_SampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 360) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(itraits, 361) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ClassFactoryClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) == kSlotsOffset_avmplus_ClassFactoryClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ClassFactoryClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 367) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_StackFrameClass)));
    AvmAssert(getSlotOffset(ctraits, 368) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_SampleClass)));
    AvmAssert(getSlotOffset(ctraits, 369) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_DeleteObjectSampleClass)));
    AvmAssert(getSlotOffset(ctraits, 370) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_NewObjectSampleClass)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NewObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) == kSlotsOffset_avmplus_NewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 372) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 373) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_type)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DeleteObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == kSlotsOffset_avmplus_DeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 372) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 375) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_TraceClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) == kSlotsOffset_avmplus_TraceClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 411) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(ctraits, 412) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(ctraits, 413) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 414) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(ctraits, 415) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 416) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(ctraits, 417) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_LISTENER)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DictionaryClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_EndianClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) == kSlotsOffset_avmplus_EndianClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::EndianClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 432) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_BIG_ENDIAN)));
    AvmAssert(getSlotOffset(ctraits, 433) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_LITTLE_ENDIAN)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_JObjectClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
#endif // DEBUG


AVMTHUNK_BEGIN_NATIVE_TABLES(shell_toplevel)

    AVMTHUNK_BEGIN_NATIVE_METHODS(shell_toplevel)
        AVMTHUNK_NATIVE_METHOD(avmplus_MI_plus, ::avmshell::MIObjectImpl::plus)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exit, avmshell::SystemClass::exit)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exec, avmshell::SystemClass::exec)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getAvmplusVersion, avmshell::SystemClass::getAvmplusVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getFeatures, avmshell::SystemClass::getFeatures)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getRunmode, avmshell::SystemClass::getRunmode)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_trace, avmshell::SystemClass::trace)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_write, avmshell::SystemClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_debugger, avmshell::SystemClass::debugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isDebugger, avmshell::SystemClass::isDebugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getTimer, avmshell::SystemClass::getTimer)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_private_getArgv, avmshell::SystemClass::getArgv)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_readLine, avmshell::SystemClass::readLine)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_totalMemory_get, avmshell::SystemClass::get_totalMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_freeMemory_get, avmshell::SystemClass::get_freeMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_privateMemory_get, avmshell::SystemClass::get_privateMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_forceFullCollection, avmshell::SystemClass::forceFullCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_queueCollection, avmshell::SystemClass::queueCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_ns_example_nstest, avmshell::SystemClass::ns_example_nstest)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isGlobal, avmshell::SystemClass::isGlobal)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_swfVersion_get, avmshell::SystemClass::get_swfVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_apiVersion_get, avmshell::SystemClass::get_apiVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_disposeXML, avmshell::SystemClass::disposeXML)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_pauseForGCIfCollectionImminent, avmshell::SystemClass::pauseForGCIfCollectionImminent)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_exists, avmshell::FileClass::exists)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_read, avmshell::FileClass::read)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_write, avmshell::FileClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_readByteArray, avmshell::FileClass::readByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_writeByteArray, avmshell::FileClass::writeByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_currentDomain_get, avmplus::DomainClass::get_currentDomain)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get, avmplus::DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_private_init, avmplus::DomainObject::init)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_loadBytes, avmplus::DomainObject::loadBytes)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_getClass, avmplus::DomainObject::getClass)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_get, avmplus::DomainObject::get_domainMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_set, avmplus::DomainObject::set_domainMemory)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMasterString, SamplerScript::getMasterString)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSavedThis, SamplerScript::getSavedThis)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getLexicalScopes, SamplerScript::getLexicalScopes)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_isGetterSetter, SamplerScript::isGetterSetter)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__getInvocationCount, SamplerScript::_getInvocationCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSampleCount, SamplerScript::getSampleCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__getSamples, SamplerScript::_getSamples)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMemberNames, SamplerScript::getMemberNames)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSize, SamplerScript::getSize)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__setSamplerCallback, SamplerScript::_setSamplerCallback)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_sampleInternalAllocs, SamplerScript::sampleInternalAllocs)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_pauseSampling, SamplerScript::pauseSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_stopSampling, SamplerScript::stopSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_startSampling, SamplerScript::startSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_clearSamples, SamplerScript::clearSamples)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_object_get, avmplus::NewObjectSampleObject::get_object)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_size_get, avmplus::NewObjectSampleObject::get_size)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setLevel, avmplus::TraceClass::setLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getLevel, avmplus::TraceClass::getLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setListener, avmplus::TraceClass::setListener)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getListener, avmplus::TraceClass::getListener)
        AVMTHUNK_NATIVE_METHOD(flash_utils_Dictionary_private_init, avmplus::DictionaryObject::init)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_create, avmplus::JObjectClass::create)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_createArray, avmplus::JObjectClass::createArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_toArray, avmplus::JObjectClass::toArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_constructorSignature, avmplus::JObjectClass::constructorSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_methodSignature, avmplus::JObjectClass::methodSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_fieldSignature, avmplus::JObjectClass::fieldSignature)
    AVMTHUNK_END_NATIVE_METHODS()

    AVMTHUNK_BEGIN_NATIVE_CLASSES(shell_toplevel)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_CTest, CTestClass, avmplus::CTestClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CTestClass, avmplus::CTestObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CTestObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_MI, MIClass, avmshell::MIClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_MIClass, avmshell::MIObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_MIObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_System, SystemClass, avmshell::SystemClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_SystemClass, avmplus::SystemObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SystemObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_File, FileClass, avmshell::FileClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_FileClass, avmplus::FileObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_FileObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_AbstractBase, AbstractBaseClass, avmshell::AbstractBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_AbstractBaseClass, avmshell::AbstractBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_AbstractBaseObject, false, false, true)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_RestrictedBase, RestrictedBaseClass, avmshell::RestrictedBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_RestrictedBaseClass, avmshell::RestrictedBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_RestrictedBaseObject, false, true, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_AbstractRestrictedBase, AbstractRestrictedBaseClass, avmshell::AbstractRestrictedBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_AbstractRestrictedBaseClass, avmshell::AbstractRestrictedBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_AbstractRestrictedBaseObject, false, true, true)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_CheckBase, CheckBaseClass, avmshell::CheckBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CheckBaseClass, avmshell::CheckBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CheckBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeBase, NativeBaseClass, avmshell::NativeBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeBaseClass, avmshell::NativeBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeBaseAS3, NativeBaseAS3Class, avmplus::NativeBaseAS3Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NativeBaseAS3Class, avmplus::NativeBaseAS3Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NativeBaseAS3Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_ShellCoreFriend1, ShellCoreFriend1Class, avmplus::ShellCoreFriend1Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ShellCoreFriend1Class, avmplus::ShellCoreFriend1Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ShellCoreFriend1Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_ShellCoreFriend2, ShellCoreFriend2Class, avmplus::ShellCoreFriend2Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ShellCoreFriend2Class, avmplus::ShellCoreFriend2Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ShellCoreFriend2Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_Capabilities, CapabilitiesClass, avmplus::CapabilitiesClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CapabilitiesClass, avmplus::CapabilitiesObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CapabilitiesObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class, public_classClass, avmplus::public_classClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_classClass, avmplus::public_classObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_classObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_AIR_1_0, public_class_AIR_1_0Class, avmplus::public_class_AIR_1_0Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_0Class, avmplus::public_class_AIR_1_0Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_0Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_FP_10_0, public_class_FP_10_0Class, avmplus::public_class_FP_10_0Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_FP_10_0Class, avmplus::public_class_FP_10_0Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_FP_10_0Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_AIR_1_5, public_class_AIR_1_5Class, avmplus::public_class_AIR_1_5Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5Class, avmplus::public_class_AIR_1_5Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_AIR_1_5_1, public_class_AIR_1_5_1Class, avmplus::public_class_AIR_1_5_1Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5_1Class, avmplus::public_class_AIR_1_5_1Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5_1Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_FP_10_0_32, public_class_FP_10_0_32Class, avmplus::public_class_FP_10_0_32Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_FP_10_0_32Class, avmplus::public_class_FP_10_0_32Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_FP_10_0_32Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_AIR_1_5_2, public_class_AIR_1_5_2Class, avmplus::public_class_AIR_1_5_2Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5_2Class, avmplus::public_class_AIR_1_5_2Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5_2Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_AIR_1_0_FP_10_0, public_class_AIR_1_0_FP_10_0Class, avmplus::public_class_AIR_1_0_FP_10_0Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_0_FP_10_0Class, avmplus::public_class_AIR_1_0_FP_10_0Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_0_FP_10_0Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2, public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class, avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class, avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_public_class_FP_10_0_32_AIR_1_0_FP_10_0, public_class_FP_10_0_32_AIR_1_0_FP_10_0Class, avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class, avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeSubclassOfAbstractBase, NativeSubclassOfAbstractBaseClass, avmshell::NativeSubclassOfAbstractBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeSubclassOfAbstractBaseClass, avmshell::NativeSubclassOfAbstractBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeSubclassOfAbstractBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_SubclassOfAbstractBase, SubclassOfAbstractBaseClass, avmplus::SubclassOfAbstractBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SubclassOfAbstractBaseClass, avmplus::SubclassOfAbstractBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SubclassOfAbstractBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeSubclassOfRestrictedBase, NativeSubclassOfRestrictedBaseClass, avmshell::NativeSubclassOfRestrictedBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeSubclassOfRestrictedBaseClass, avmshell::NativeSubclassOfRestrictedBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeSubclassOfRestrictedBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_SubclassOfRestrictedBase, SubclassOfRestrictedBaseClass, avmplus::SubclassOfRestrictedBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SubclassOfRestrictedBaseClass, avmplus::SubclassOfRestrictedBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SubclassOfRestrictedBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeSubclassOfAbstractRestrictedBase, NativeSubclassOfAbstractRestrictedBaseClass, avmshell::NativeSubclassOfAbstractRestrictedBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeSubclassOfAbstractRestrictedBaseClass, avmshell::NativeSubclassOfAbstractRestrictedBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_NativeSubclassOfAbstractRestrictedBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_SubclassOfAbstractRestrictedBase, SubclassOfAbstractRestrictedBaseClass, avmplus::SubclassOfAbstractRestrictedBaseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SubclassOfAbstractRestrictedBaseClass, avmplus::SubclassOfAbstractRestrictedBaseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SubclassOfAbstractRestrictedBaseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, avmplus::DomainClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DomainClass, avmplus::DomainObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DomainObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, avmplus::StackFrameClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackFrameClass, avmplus::StackFrameObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackFrameObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, avmplus::SampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SampleClass, avmplus::SampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_ClassFactory, ClassFactoryClass, avmplus::ClassFactoryClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ClassFactoryClass, avmplus::ClassFactoryObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ClassFactoryObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, avmplus::NewObjectSampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NewObjectSampleClass, avmplus::NewObjectSampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NewObjectSampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, avmplus::DeleteObjectSampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DeleteObjectSampleClass, avmplus::DeleteObjectSampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DeleteObjectSampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, avmplus::TraceClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_TraceClass, avmplus::TraceObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_TraceObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Dictionary, DictionaryClass, avmplus::DictionaryClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DictionaryClass, avmplus::DictionaryObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DictionaryObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Endian, EndianClass, avmplus::EndianClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EndianClass, avmplus::EndianObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EndianObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, avmplus::JObjectClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_JObjectClass, avmplus::JObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_JObject, false, false, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[16009] = {
  16,   0,  46,   0,   8,  42, 101,   0,   2,   1,   3,   4,   0,   8,   0,   0,
   0,   0,   0,   0, 232,  63,   0,   0,   0,   0,   0,   0, 240,  63,   0,   0,
   0,   0,   0,   0,   0,  64,   0,   0,   0,   0,   0,   0,   8,  64,   0,   0,
   0,   0,   0,   0,  16,  64,   0,   0,   0,   0,   0,   0,  20,  64,   0,   0,
   0,   0,   0,   0,  24,  64, 234,   2,   0,   4, 118, 111, 105, 100,   7,  66,
 111, 111, 108, 101,  97, 110,   6,  83, 121, 115, 116, 101, 109,  19, 115, 104,
 101, 108, 108,  95, 116, 111, 112, 108, 101, 118, 101, 108,  46,  97, 115,  36,
  49,   7,  97, 118, 109, 112, 108, 117, 115,   8, 114, 101,  97, 100,  76, 105,
 110, 101,   6,  83, 116, 114, 105, 110, 103,   8, 103, 101, 116,  84, 105, 109,
 101, 114,   4, 117, 105, 110, 116,   5, 116, 114,  97,  99, 101,   6,  68, 111,
 109,  97, 105, 110,  13,  99, 117, 114, 114, 101, 110, 116,  68, 111, 109,  97,
 105, 110,   8, 103, 101, 116,  67, 108,  97, 115, 115,   5,  67, 108,  97, 115,
 115,   8, 100, 101,  98, 117, 103, 103, 101, 114,  13,  97, 118, 109, 112, 108,
 117, 115,  58,  73,  84, 101, 115, 116,   4, 116, 101, 115, 116,   5,  73,  84,
 101, 115, 116,  13,  97, 118, 109, 112, 108, 117, 115,  58,  67,  84, 101, 115,
 116,   3, 238, 138, 148,   5,  67,  84, 101, 115, 116,   6,  79,  98, 106, 101,
  99, 116,  10,  97, 118, 109, 112, 108, 117, 115,  58,  77,  73,   6,  78, 117,
 109,  98, 101, 114,   4, 112, 108, 117, 115,   2,  77,  73,  14,  97, 118, 109,
 112, 108, 117, 115,  58,  83, 121, 115, 116, 101, 109,   4,  97, 114, 103, 118,
   7, 103, 101, 116,  65, 114, 103, 118,   3, 105, 110, 116,   5,  65, 114, 114,
  97, 121,   3,  88,  77,  76,   4, 101, 120, 105, 116,   3, 102, 111, 111,   4,
 101, 120, 101,  99,   3,  98,  97, 114,   4,  97, 116, 116, 114,   8, 119, 104,
  97, 116, 101, 118, 101, 114,  17, 103, 101, 116,  65, 118, 109, 112, 108, 117,
 115,  86, 101, 114, 115, 105, 111, 110,  11, 103, 101, 116,  70, 101,  97, 116,
 117, 114, 101, 115,  10, 103, 101, 116,  82, 117, 110, 109, 111, 100, 101,   5,
 119, 114, 105, 116, 101,  10, 105, 115,  68, 101,  98, 117, 103, 103, 101, 114,
  11, 116, 111, 116,  97, 108,  77, 101, 109, 111, 114, 121,  10, 102, 114, 101,
 101,  77, 101, 109, 111, 114, 121,  13, 112, 114, 105, 118,  97, 116, 101,  77,
 101, 109, 111, 114, 121,  19, 102, 111, 114,  99, 101,  70, 117, 108, 108,  67,
 111, 108, 108, 101,  99, 116, 105, 111, 110,  15, 113, 117, 101, 117, 101,  67,
 111, 108, 108, 101,  99, 116, 105, 111, 110,  22, 104, 116, 116, 112,  58,  47,
  47, 119, 119, 119,  46, 101, 120,  97, 109, 112, 108, 101,  46,  99, 111, 109,
   6, 110, 115, 116, 101, 115, 116,   8, 105, 115,  71, 108, 111,  98,  97, 108,
  10, 115, 119, 102,  86, 101, 114, 115, 105, 111, 110,  10,  97, 112, 105,  86,
 101, 114, 115, 105, 111, 110,  10, 100, 105, 115, 112, 111, 115, 101,  88,  77,
  76,  30, 112,  97, 117, 115, 101,  70, 111, 114,  71,  67,  73, 102,  67, 111,
 108, 108, 101,  99, 116, 105, 111, 110,  73, 109, 109, 105, 110, 101, 110, 116,
  12,  97, 118, 109, 112, 108, 117, 115,  58,  70, 105, 108, 101,  11, 102, 108,
  97, 115, 104,  46, 117, 116, 105, 108, 115,   9,  66, 121, 116, 101,  65, 114,
 114,  97, 121,   6, 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100,  13,
 114, 101,  97, 100,  66, 121, 116, 101,  65, 114, 114,  97, 121,  14, 119, 114,
 105, 116, 101,  66, 121, 116, 101,  65, 114, 114,  97, 121,   4,  70, 105, 108,
 101,  21,  97, 118, 109, 115, 104, 101, 108, 108,  58,  65,  98, 115, 116, 114,
  97,  99, 116,  66,  97, 115, 101,   8,  97, 118, 109, 115, 104, 101, 108, 108,
  12,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  23,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  82, 101, 115, 116, 114, 105,  99, 116, 101,
 100,  66,  97, 115, 101,  14,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,
  66,  97, 115, 101,  31,  97, 118, 109, 115, 104, 101, 108, 108,  58,  65,  98,
 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,
  66,  97, 115, 101,  22,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  18,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  67, 104, 101,  99, 107,  66,  97, 115, 101,   9,  67,
 104, 101,  99, 107,  66,  97, 115, 101,  19,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  78,  97, 116, 105, 118, 101,  66,  97, 115, 101,  10,  78,  97, 116,
 105, 118, 101,  66,  97, 115, 101,  22,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  78,  97, 116, 105, 118, 101,  66,  97, 115, 101,  65,  83,  51,  13,  78,
  97, 116, 105, 118, 101,  66,  97, 115, 101,  65,  83,  51,  25,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  83, 104, 101, 108, 108,  67, 111, 114, 101,  70,
 114, 105, 101, 110, 100,  49,  16,  83, 104, 101, 108, 108,  67, 111, 114, 101,
  70, 114, 105, 101, 110, 100,  49,  25,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  83, 104, 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101, 110, 100,
  50,  16,  83, 104, 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101, 110,
 100,  50,  25, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,
  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,   7,  65,  86,  77,
  80, 108, 117, 115,  12, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101,
 109,  10, 112, 108,  97, 121, 101, 114,  84, 121, 112, 101,  12,  67,  97, 112,
  97,  98, 105, 108, 105, 116, 105, 101, 115,  21,  97, 118, 109, 115, 104, 101,
 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  10,
 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,   3, 238, 138, 149,  18, 112,
 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,
  48,   3,  65,  80,  73,   3,  54,  54,  49,   3, 238, 138, 150,  18, 112, 117,
  98, 108, 105,  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,
   3,  54,  54,  50,   3, 238, 138, 151,  18, 112, 117,  98, 108, 105,  99,  95,
 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,   3,  54,  54,  51,   3,
 238, 138, 152,  20, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  49,   3,  54,  54,  52,   3, 238, 138, 153,
  21, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,
  48,  95,  48,  95,  51,  50,   3,  54,  54,  53,   3, 238, 138, 154,  20, 112,
 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  50,   3,  54,  54,  54,  26, 112, 117,  98, 108, 105,  99,  95, 118,
  97, 114,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,
  95,  48,  38, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  50,  37, 112, 117,  98, 108, 105,  99,
  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,
  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  12,
 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  20, 112, 117,  98,
 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,
  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  70,
  80,  95,  49,  48,  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 111,
 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  22, 112, 117,  98, 108,
 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  49,  23, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  22, 112, 117,  98, 108, 105,
  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  50,  28, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,
  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  40, 112,
 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  50,  39, 112, 117,  98, 108, 105,  99,  95,  99,
 111, 110, 115, 116,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,
  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  15,
 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  23,
 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,
  65,  73,  82,  95,  49,  95,  48,  23, 112, 117,  98, 108, 105,  99,  95, 102,
 117, 110,  99, 116, 105, 111, 110,  95,  70,  80,  95,  49,  48,  95,  48,  23,
 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,
  65,  73,  82,  95,  49,  95,  53,  25, 112, 117,  98, 108, 105,  99,  95, 102,
 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  49,  26, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111,
 110,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  25, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  31, 112, 117,  98, 108, 105,  99,  95, 102, 117,
 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,
  80,  95,  49,  48,  95,  48,  43, 112, 117,  98, 108, 105,  99,  95, 102, 117,
 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  50,  42, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,
  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  13, 112, 117,
  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  21, 112, 117,  98, 108,
 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,
  48,  21, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,
  70,  80,  95,  49,  48,  95,  48,  21, 112, 117,  98, 108, 105,  99,  95, 103,
 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,  23, 112, 117,
  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  49,  24, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116,
 115, 101, 116,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  23, 112,
 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  29, 112, 117,  98, 108, 105,  99,  95, 103, 101,
 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,
  49,  48,  95,  48,  41, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115,
 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  40, 112,
 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,
  70,  80,  95,  49,  48,  95,  48,  12, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,
  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  65,  73,  82,  95,  49,  95,  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,
  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,
  95,  49,  48,  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  29,  97, 118, 109, 115, 104,
 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,
  95,  65,  73,  82,  95,  49,  95,  53,  20, 112, 117,  98, 108, 105,  99,  95,
  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  31,  97, 118,
 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  22, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  49,  32,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,
  95,  48,  95,  51,  50,  23, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  31,  97, 118,
 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  22, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  50,  37,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,
  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  28, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,
  70,  80,  95,  49,  48,  95,  48,  49,  97, 118, 109, 115, 104, 101, 108, 108,
  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  50,  40, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  50,  48,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108,
 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,
  48,  95,  48,  39, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,
  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  16, 112, 117,  98, 108,
 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  24, 112, 117,  98,
 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,
  82,  95,  49,  95,  48,  24, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116,
 101, 114, 102,  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  24, 112,
 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,
  65,  73,  82,  95,  49,  95,  53,  26, 112, 117,  98, 108, 105,  99,  95, 105,
 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  49,  27, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,
  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  26, 112,
 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  50,  32, 112, 117,  98, 108, 105,  99,
  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,
  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  44, 112, 117,  98, 108, 105,
  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  50,  43, 112, 117,  98, 108, 105,  99,  95, 105,
 110, 116, 101, 114, 102,  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,
  48,  95,  48,  37,  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116,
 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115,
 116, 114,  97,  99, 116,  66,  97, 115, 101,  28,  78,  97, 116, 105, 118, 101,
  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,
  99, 116,  66,  97, 115, 101,  31,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,
  99, 116,  66,  97, 115, 101,  22,  83, 117,  98,  99, 108,  97, 115, 115,  79,
 102,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  39,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101,
 100,  66,  97, 115, 101,  30,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99,
 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,
  66,  97, 115, 101,  33,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 117,
  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116,
 101, 100,  66,  97, 115, 101,  24,  83, 117,  98,  99, 108,  97, 115, 115,  79,
 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  47,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  83,
 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99,
 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  38,
  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,
  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116,
 101, 100,  66,  97, 115, 101,  41,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,
  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,
  32,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,
  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115,
 101,  11,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  48,  11,  65,  80,
  73,  95,  70,  80,  95,  49,  48,  95,  48,  11,  65,  80,  73,  95,  65,  73,
  82,  95,  49,  95,  53,  13,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  49,  14,  65,  80,  73,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  51,  50,  13,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,
  10, 110, 115,  95, 101, 120,  97, 109, 112, 108, 101,   6, 110,  97, 116, 105,
 118, 101,   3,  99, 108, 115,  19,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  77,  73,  67, 108,  97, 115, 115,   8, 105, 110, 115, 116,  97,
 110,  99, 101,  20,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  77,  73,  79,  98, 106, 101,  99, 116,   7, 109, 101, 116, 104, 111, 100, 115,
  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,
  98, 106, 101,  99, 116,  73, 109, 112, 108,  10,  97, 118, 109, 112, 108, 117,
 115, 238, 138, 148,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  83, 121, 115, 116, 101, 109,  67, 108,  97, 115, 115,   7,  99, 108,  97,
 115, 115, 103,  99,   5, 101, 120,  97,  99, 116,   4,  97, 117, 116, 111,   9,
  99, 111, 110, 115, 116, 114, 117,  99, 116,   4, 110, 111, 110, 101,  21,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  70, 105, 108, 101,  67,
 108,  97, 115, 115,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 148,
  29,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115,
 116, 114,  97,  99, 116,  66,  97, 115, 101,  67, 108,  97, 115, 115,  30,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,
  97,  99, 116,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,   8,  97,  98,
 115, 116, 114,  97,  99, 116,  45,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115,
 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  67,
 108,  97, 115, 115,  46,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79,
 102,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  79,  98, 106,
 101,  99, 116,  31,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  67, 108,
  97, 115, 115,  32,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98,
 106, 101,  99, 116,  10, 114, 101, 115, 116, 114, 105,  99, 116, 101, 100,  47,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105,
 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116,
 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  48,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105,
 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116,
 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,
  39,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115,
 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,
  97, 115, 101,  67, 108,  97, 115, 115,  40,  58,  58,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99,
 116,  19,  97,  98, 115, 116, 114,  97,  99, 116,  45, 114, 101, 115, 116, 114,
 105,  99, 116, 101, 100,  55,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,
  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,
  99, 116, 101, 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  56,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,
  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,
  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,
  79,  98, 106, 101,  99, 116,  26,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  67, 104, 101,  99, 107,  66,  97, 115, 101,  67, 108,  97, 115,
 115,  27,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67, 104,
 101,  99, 107,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,   5,  99, 104,
 101,  99, 107,  27,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  78,  97, 116, 105, 118, 101,  66,  97, 115, 101,  67, 108,  97, 115, 115,  28,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105,
 118, 101,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,   6, 102, 114, 105,
 101, 110, 100,  19,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 104,
 101, 108, 108,  67, 111, 114, 101,  43,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  83, 104, 101, 108, 108,  67, 111, 114, 101,  44,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  58,  83, 104, 101, 108, 108,  84, 111, 112, 108, 101,
 118, 101, 108,  15, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,
 238, 138, 148,  14, 103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,  97,
 109, 101,   5, 112, 114, 105, 110, 116,  11,  97, 118, 109, 115, 104, 101, 108,
 108, 238, 138, 149,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 150,
  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 151,  11,  97, 118, 109,
 115, 104, 101, 108, 108, 238, 138, 152,  11,  97, 118, 109, 115, 104, 101, 108,
 108, 238, 138, 153,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 154,
  14,  97, 118, 109, 112, 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,   4,
 105, 110, 105, 116,  11,  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,  50,
   9, 108, 111,  97, 100,  66, 121, 116, 101, 115,  24,  77,  73,  78,  95,  68,
  79,  77,  65,  73,  78,  95,  77,  69,  77,  79,  82,  89,  95,  76,  69,  78,
  71,  84,  72,   4, 108, 111,  97, 100,  12, 100, 111, 109,  97, 105, 110,  77,
 101, 109, 111, 114, 121,  11,  68, 111, 109,  97, 105, 110,  67, 108,  97, 115,
 115,   2, 103,  99,  12,  68, 111, 109,  97, 105, 110,  79,  98, 106, 101,  99,
 116,   8,  70, 117, 110,  99, 116, 105, 111, 110,   5,  81,  78,  97, 109, 101,
  19,  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67,
 111, 117, 110, 116,  12,  83,  97, 109, 112, 108, 101, 114,  46,  97, 115,  36,
  51,  13, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  11,
  95, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,   1, 102,   1, 101,   3,
 114, 101, 116,  19,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,
  97, 108, 108,  98,  97,  99, 107,   7, 119, 114,  97, 112, 112, 101, 114,  24,
 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83, 116,
  97,  99, 107,  70, 114,  97, 109, 101,   4, 110,  97, 109, 101,   2,  40,  41,
   4, 102, 105, 108, 101,   1,  91,   1,  58,   4, 108, 105, 110, 101,   1,  93,
   8, 115,  99, 114, 105, 112, 116,  73,  68,   8, 116, 111,  83, 116, 114, 105,
 110, 103,  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  20, 102, 108,
  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,  97, 109, 112,
 108, 101,   4, 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,   6,  83,  97,
 109, 112, 108, 101,  26, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108,
 101, 114,  58,  67, 108,  97, 115, 115,  70,  97,  99, 116, 111, 114, 121,  15,
  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  67, 108,  97, 115, 115,  11,
  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  23,  68, 101, 108, 101,
 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,
  97, 115, 115,  20,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109,
 112, 108, 101,  67, 108,  97, 115, 115,  12,  67, 108,  97, 115, 115,  70,  97,
  99, 116, 111, 114, 121,  29, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112,
 108, 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109,
 112, 108, 101,   2, 105, 100,   4, 116, 121, 112, 101,   6, 111,  98, 106, 101,
  99, 116,   4, 115, 105, 122, 101,  15,  78, 101, 119,  79,  98, 106, 101,  99,
 116,  83,  97, 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46, 115,  97,
 109, 112, 108, 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,
  99, 116,  83,  97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116, 101,  79,
  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  16, 102, 108,  97, 115,
 104,  46, 115,  97, 109, 112, 108, 101, 114, 238, 138, 148,  21,  78, 101, 119,
  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,
  99, 116,  12,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  27,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  99,
 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13, 115, 116,  97, 114,
 116,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112, 108, 101,
 114,  83,  99, 114, 105, 112, 116,  58,  58, 115, 116,  97, 114, 116,  83,  97,
 109, 112, 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,  97, 109, 112, 108,
 105, 110, 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,  13,
 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 112,  97, 117,
 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,  97, 109, 112, 108,
 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99, 115,  35,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115,
  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108,
 111,  99, 115,  18, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97,
 108, 108,  98,  97,  99, 107,  34,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101,
 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 103, 101, 116,  83, 105, 122,
 101,  22,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 103, 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,  77, 101, 109,  98,
 101, 114,  78,  97, 109, 101, 115,  29,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77, 101, 109,  98, 101, 114,
  78,  97, 109, 101, 115,  10, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,
  26,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
  95, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  14, 103, 101, 116,  83,
  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  29,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 109,
 112, 108, 101,  67, 111, 117, 110, 116,  18, 103, 101, 116,  73, 110, 118, 111,
  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  83,
 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67,
 111, 117, 110, 116,  24, 103, 101, 116,  71, 101, 116, 116, 101, 114,  73, 110,
 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  34,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 103, 101,
 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,
  14, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  29,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 105,
 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  16, 103, 101,
 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  31,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101,
 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  12, 103,
 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97,
 118, 101, 100,  84, 104, 105, 115,  15, 103, 101, 116,  77,  97, 115, 116, 101,
 114,  83, 116, 114, 105, 110, 103,  30,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77,  97, 115, 116, 101, 114,
  83, 116, 114, 105, 110, 103,   3,  54,  55,  54,  17, 102, 108,  97, 115, 104,
  46, 116, 114,  97,  99, 101,  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,
   7,  77,  69,  84,  72,  79,  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,
  95,  87,  73,  84,  72,  95,  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,
  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,
  72,  79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,
  73,  84,  72,  95,  65,  82,  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,
  83,  84,  69,  78,  69,  82,   8, 115, 101, 116,  76, 101, 118, 101, 108,   8,
 103, 101, 116,  76, 101, 118, 101, 108,  11, 115, 101, 116,  76, 105, 115, 116,
 101, 110, 101, 114,  11, 103, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,
  11, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,   5,  84, 114,  97,
  99, 101,  10,  84, 114,  97,  99, 101,  46,  97, 115,  36,  52,  14, 102, 108,
  97, 115, 104,  46, 116, 114,  97,  99, 101, 238, 138, 148,  10,  84, 114,  97,
  99, 101,  67, 108,  97, 115, 115,  22, 102, 108,  97, 115, 104,  46, 117, 116,
 105, 108, 115,  58,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  15,  68,
 105,  99, 116, 105, 111, 110,  97, 114, 121,  46,  97, 115,  36,  53,  10,  68,
 105,  99, 116, 105, 111, 110,  97, 114, 121,  14, 102, 108,  97, 115, 104,  46,
 117, 116, 105, 108, 115, 238, 138, 148,  15,  68, 105,  99, 116, 105, 111, 110,
  97, 114, 121,  67, 108,  97, 115, 115,  16,  68, 105,  99, 116, 105, 111, 110,
  97, 114, 121,  79,  98, 106, 101,  99, 116,  18, 102, 108,  97, 115, 104,  46,
 117, 116, 105, 108, 115,  58,  69, 110, 100, 105,  97, 110,  10,  66,  73,  71,
  95,  69,  78,  68,  73,  65,  78,   9,  98, 105, 103,  69, 110, 100, 105,  97,
 110,  13,  76,  73,  84,  84,  76,  69,  95,  69,  78,  68,  73,  65,  78,  12,
 108, 105, 116, 116, 108, 101,  69, 110, 100, 105,  97, 110,   6,  69, 110, 100,
 105,  97, 110,  11,  69, 110, 100, 105,  97, 110,  46,  97, 115,  36,  54,  15,
  97, 118, 109, 112, 108, 117, 115,  58,  74,  79,  98, 106, 101,  99, 116,   7,
  74,  79,  98, 106, 101,  99, 116,   6,  99, 114, 101,  97, 116, 101,  11,  99,
 114, 101,  97, 116, 101,  65, 114, 114,  97, 121,   7, 116, 111,  65, 114, 114,
  97, 121,  20,  99, 111, 110, 115, 116, 114, 117,  99, 116, 111, 114,  83, 105,
 103, 110,  97, 116, 117, 114, 101,  15, 109, 101, 116, 104, 111, 100,  83, 105,
 103, 110,  97, 116, 117, 114, 101,  14, 102, 105, 101, 108, 100,  83, 105, 103,
 110,  97, 116, 117, 114, 101,   9,  74,  97, 118,  97,  46,  97, 115,  36,  55,
  12,  74,  79,  98, 106, 101,  99, 116,  67, 108,  97, 115, 115, 127,  22,   1,
   5,   5,  23,   1,  22,   6,  23,   6,   8,  17,   5,  20,  22,  21,  24,  20,
   5,  24,  24,  24,   5,  28,  24,  28,  26,  28,  26,  23,   8,  50,   5,  57,
  22,  58,  24,  57,   5,  65,  22,  66,  24,  65,   5,  68,  24,  68,   5,  70,
  24,  70,   5,  72,  24,  72,   5,  74,  24,  74,   5,  76,  24,  76,   5,  78,
  24,  78,   5,  80,  24,  80,   5,  82,  22,  84,  23,  84,  24,  82,  26,  82,
   5,  87,  22,  89,  22,  93,  22,  96,  22,  99,  22, 102,  22, 105,  24,  87,
   5, 142,   1,  24, 142,   1,   5, 144,   1,  24, 144,   1,   5, 146,   1,  24,
 146,   1,   5, 148,   1,  24, 148,   1,   5, 150,   1,  24, 150,   1,   5, 152,
   1,  24, 152,   1,   5, 154,   1,  24, 154,   1,   5, 156,   1,  24, 156,   1,
   5, 158,   1,  24, 158,   1,   5, 170,   1,  24, 170,   1,   5, 172,   1,  24,
 172,   1,   5, 174,   1,  24, 174,   1,   5, 176,   1,  24, 176,   1,   5, 178,
   1,  24, 178,   1,   5, 180,   1,  24, 180,   1,  23,  66,  22, 196,   1,  22,
 204,   1,  22, 228,   1,  22, 231,   1,  22, 232,   1,  22, 233,   1,  22, 234,
   1,  22, 235,   1,  22, 236,   1,   5, 237,   1,   5, 239,   1,  24, 237,   1,
  26, 237,   1,   5, 250,   1,  22, 251,   1,  23, 251,   1,   5, 130,   2,  24,
 130,   2,  26, 130,   2,   5, 141,   2,  24, 141,   2,   5, 145,   2,  24, 145,
   2,   5, 151,   2,  24, 151,   2,   5, 157,   2,  24, 157,   2,  22, 159,   2,
   5, 194,   2,  22, 206,   2,  24, 194,   2,   5, 208,   2,  23, 206,   2,  22,
 209,   2,   5, 211,   2,   5, 212,   2,  23,  58,  24, 211,   2,  26, 211,   2,
  22, 214,   2,   5, 217,   2,  24, 217,   2,   5, 223,   2,   5, 224,   2,  24,
 224,   2,   5, 232,   2,  53,   4,   1,   2,   3,   4,   4,   1,   2,   4,   5,
   1,   6,   1,   8,   8,   1,   2,   4,   5,  12,  13,  14,  15,   1,  12,   1,
  16,   1,  33,   1,  35,   9,   1,   2,   4,  15,  37,  38,  39,  40,  41,   1,
  43,   1,  44,   1,  45,   1,  46,   1,  47,   1,  48,   2,  43,  44,   3,  44,
  46,  48,   3,  43,  44,  47,   1,   5,   1,   4,   1,  21,   4,   1,   2,  21,
  80,   1,  38,   5,   1,   2,   4,  38,  39,   1,  81,   1,  82,   1,  83,   1,
  84,   1,  85,   1,  86,   1,  87,   1,  88,   1,  89,   2,  84,  85,   3,  85,
  87,  89,   3,  84,  85,  88,   8,   1,   4,   5,  15,  90,  91,  92,  93,   1,
  90,   4,   1,   4,   5,  91,   4,   1,  94,  95,  96,   1,  96,   8,   1,  15,
  94,  95,  96,  97,  98,  99,   1, 108,   4,   1, 110, 112, 113,   1, 114,   8,
   1,  15,  18, 115, 116, 117, 118, 119,   1, 115,   4,   1,  18, 116, 117,   1,
 120,   4,   1,  18, 117, 123,   4,   1,   4,   5, 126, 190,   3,   7,   1,   2,
   7,   1,   3,   9,   4,   1,   9,   7,   1,   7,   1,   8,   9,   9,   1,   7,
   1,  10,   9,  11,   1,   9,  12,   1,   9,  13,   1,   9,  14,   1,   7,   1,
  15,   9,   4,   2,   9,  16,   2,   9,  18,   3,   7,   5,  19,   9,  18,   4,
   7,   5,  22,   7,   1,  23,   7,   1,  25,   9,  26,   4,   7,   5,  27,   7,
   1,  29,   9,  30,   5,   7,   1,  31,   7,   1,  32,   7,   1,  33,   9,  34,
   4,   9,  36,   4,   9,  40,   4,   9,  41,   4,   9,  42,   4,   9,  11,   4,
   9,  43,   4,   9,  16,   4,   9,  44,   4,   9,   9,   4,   9,  30,   6,   9,
  29,   4,   9,   7,   4,   9,  45,   4,   9,  46,   4,   9,  47,   4,   9,  48,
   4,   9,  49,   4,   9,  51,   7,   9,  52,   4,   9,  53,   4,   9,  54,   4,
   9,  55,   4,   9,  56,   4,   7,   4,   4,   7,  18,  59,   9,  60,   4,   9,
  61,   4,   9,  62,   4,   9,  63,   4,   7,   4,  64,   7,  21,  67,   7,  21,
  69,   7,  21,  71,   7,  21,  73,   7,  21,  75,   7,  21,  77,   7,  33,  35,
   9,  35,   8,   7,  21,  79,   7,  35,  37,   9,  37,   9,   7,  21,  81,   9,
   4,  10,   9,  44,  10,   9,  85,   4,   7,  38,  86,   9,  88,   4,   9,  90,
  11,   9,  94,  12,   9,  97,  13,   9, 100,  14,   9, 103,  15,   9, 106,  16,
   9, 108,  17,   9, 109,  18,   9, 110,  19,   9, 111,   4,   9, 112,  11,   9,
 113,  12,   9, 114,  13,   9, 115,  14,   9, 116,  15,   9, 117,  16,   9, 118,
  17,   9, 119,  18,   9, 120,  19,   9, 121,   4,   9, 122,  11,   9, 123,  12,
   9, 124,  13,   9, 125,  14,   9, 126,  15,   9, 127,  16,   9, 128,   1,  17,
   9, 129,   1,  18,   9, 130,   1,  19,   9, 131,   1,   4,   9, 132,   1,  11,
   9, 133,   1,  12,   9, 134,   1,  13,   9, 135,   1,  14,   9, 136,   1,  15,
   9, 137,   1,  16,   9, 138,   1,  17,   9, 139,   1,  18,   9, 140,   1,  19,
   7,  21, 141,   1,   7,  21, 143,   1,   7,  21, 145,   1,   7,  21, 147,   1,
   7,  21, 149,   1,   7,  21, 151,   1,   7,  21, 153,   1,   7,  21, 155,   1,
   7,  21, 157,   1,   7,  21, 159,   1,   7,  21, 160,   1,   7,  21, 161,   1,
   7,  21, 162,   1,   7,  21, 163,   1,   7,  21, 164,   1,   7,  21, 165,   1,
   7,  21, 166,   1,   7,  21, 167,   1,   7,  21, 168,   1,   7,  21, 169,   1,
   7,  21, 171,   1,   7,  21, 173,   1,   7,  21, 175,   1,   7,  21, 177,   1,
   7,  21, 179,   1,   7,  21, 181,   1,   9,  19,  20,   9,  22,  20,   9,  23,
   2,   9,  27,  20,   9,   4,  21,   9,  64,  21,   9,  67,  22,   9,  23,  23,
   9, 171,   1,  22,   9,  67,  23,   9, 173,   1,  22,   9,  69,  22,   9, 175,
   1,  22,   9,  69,  23,   9, 177,   1,  22,   9,  71,  22,   9, 179,   1,  22,
   9,  71,  23,   9, 181,   1,  22,   9,  73,  22,   9,  75,  22,   9,  77,  22,
   9,  79,  22,   9,  81,  22,   9,  86,  24,   9,  23,  25,   9, 141,   1,  22,
   9, 143,   1,  22,   9, 145,   1,  22,   9, 147,   1,  22,   9, 149,   1,  22,
   9, 151,   1,  22,   9, 153,   1,  22,   9, 155,   1,  22,   9, 157,   1,  22,
   9, 159,   1,  22,   9, 160,   1,  22,   9, 161,   1,  22,   9, 162,   1,  22,
   9, 163,   1,  22,   9, 164,   1,  22,   9, 165,   1,  22,   9, 166,   1,  22,
   9, 167,   1,  22,   9, 168,   1,  22,   9, 169,   1,  22,   9, 182,   1,  22,
   7,  21, 182,   1,   9, 183,   1,  22,   7,  21, 183,   1,   9, 184,   1,  22,
   7,  21, 184,   1,   9, 185,   1,  22,   7,  21, 185,   1,   9, 186,   1,  22,
   7,  21, 186,   1,   9, 187,   1,  22,   7,  21, 187,   1,   9,  88,  22,   7,
  21,  88,   9,  90,  22,   7,  21,  90,   9,  94,  22,   7,  21,  94,   9,  97,
  22,   7,  21,  97,   9, 100,  22,   7,  21, 100,   9, 103,  22,   7,  21, 103,
   9, 106,  22,   7,  21, 106,   9, 108,  22,   7,  21, 108,   9, 109,  22,   7,
  21, 109,   9, 110,  22,   7,  21, 110,   9, 111,  22,   7,  21, 111,   9, 112,
  22,   7,  21, 112,   9, 113,  22,   7,  21, 113,   9, 114,  22,   7,  21, 114,
   9, 115,  22,   7,  21, 115,   9, 116,  22,   7,  21, 116,   9, 117,  22,   7,
  21, 117,   9, 118,  22,   7,  21, 118,   9, 119,  22,   7,  21, 119,   9, 120,
  22,   7,  21, 120,   9, 188,   1,  20,   9,   4,  26,   9,  64,  26,   9,  16,
  26,   9,  67,  27,   9, 171,   1,  27,   9, 173,   1,  27,   9,  69,  27,   9,
 175,   1,  27,   9, 177,   1,  27,   9,  71,  27,   9, 179,   1,  27,   9, 181,
   1,  27,   9,  73,  27,   9,  75,  27,   9,  77,  27,   9,  79,  27,   9,  81,
  27,   9,  86,  28,   9, 229,   1,   4,   9, 230,   1,   4,   9, 182,   1,  27,
   9, 183,   1,  27,   9, 184,   1,  27,   9, 185,   1,  27,   9, 186,   1,  27,
   9, 187,   1,  27,   9,  88,  27,   9,  90,  29,   9,  94,  30,   9,  97,  31,
   9, 100,  32,   9, 103,  33,   9, 106,  34,   9, 108,  35,   9, 109,  36,   9,
 110,  37,   9, 111,  27,   9, 112,  29,   9, 113,  30,   9, 114,  31,   9, 115,
  32,   9, 116,  33,   9, 117,  34,   9, 118,  35,   9, 119,  36,   9, 120,  37,
   9, 121,  27,   9, 122,  29,   9, 123,  30,   9, 124,  31,   9, 125,  32,   9,
 126,  33,   9, 127,  34,   9, 128,   1,  35,   9, 129,   1,  36,   9, 130,   1,
  37,   9, 131,   1,  27,   9, 132,   1,  29,   9, 133,   1,  30,   9, 134,   1,
  31,   9, 135,   1,  32,   9, 136,   1,  33,   9, 137,   1,  34,   9, 138,   1,
  35,   9, 139,   1,  36,   9, 140,   1,  37,   9, 141,   1,  27,   9, 143,   1,
  29,   9, 145,   1,  30,   9, 147,   1,  31,   9, 149,   1,  32,   9, 151,   1,
  33,   9, 153,   1,  34,   9, 155,   1,  35,   9, 157,   1,  36,   9, 159,   1,
  37,   9, 160,   1,  27,   9, 161,   1,  29,   9, 162,   1,  30,   9, 163,   1,
  31,   9, 164,   1,  32,   9, 165,   1,  33,   9, 166,   1,  34,   9, 167,   1,
  35,   9, 168,   1,  36,   9, 169,   1,  37,   7,   4,  12,   9, 238,   1,  38,
   9,  64,  38,   9,  62,  38,   9, 240,   1,  38,   9,  13,   4,   9, 241,   1,
   4,   9, 238,   1,  39,   9, 240,   1,   4,   9,  14,   4,   9, 242,   1,   4,
   9, 243,   1,   4,   9,  12,  21,   9,  23,  40,   9,  12,  26,   7,   1, 247,
   1,   7,   1, 248,   1,   9, 249,   1,  41,   9, 252,   1,  41,   9, 253,   1,
  41,   7,   1, 254,   1,   9, 255,   1,  42,   9, 128,   2,  41,   9, 253,   1,
  42,   9, 129,   2,  42,   9, 131,   2,  43,   9, 133,   2,  43,   9, 136,   2,
  43,   9, 131,   2,   4,   9, 133,   2,   4,   9, 136,   2,   4,   9, 138,   2,
   4,   9, 139,   2,   4,   7,  95, 140,   2,   9, 142,   2,   4,   9, 143,   2,
   4,   7,  95, 144,   2,   7,   1, 146,   2,   7,   1, 147,   2,   7,   1, 148,
   2,   7,   1, 149,   2,   9, 146,   2,   4,   9, 147,   2,   4,   9, 148,   2,
   4,   9, 149,   2,   4,   7,  96, 150,   2,   9, 152,   2,   4,   9, 153,   2,
   4,   9, 154,   2,   4,   9, 155,   2,   4,   7,  95, 156,   2,   7,  95, 158,
   2,   9,  23,  41,   9, 140,   2,  44,   9, 144,   2,  44,   9, 156,   2,  44,
   9, 158,   2,  44,   9, 161,   2,  44,   9, 163,   2,  44,   9, 165,   2,  44,
   9, 167,   2,  44,   9, 169,   2,  44,   9, 171,   2,  44,   9, 128,   2,  42,
   9, 173,   2,  44,   9, 175,   2,  44,   9, 177,   2,  44,   9, 252,   1,  42,
   9, 179,   2,  44,   9, 181,   2,  44,   9, 182,   2,  44,   9, 183,   2,  44,
   9, 249,   1,  42,   9, 185,   2,  44,   9, 187,   2,  44,   9, 189,   2,  44,
   9, 191,   2,  44,   9, 150,   2,  42,   7,   1, 195,   2,   7,   1, 196,   2,
   7,   1, 197,   2,   7,   1, 198,   2,   7,   1, 199,   2,   7,   1, 200,   2,
   7,   1, 201,   2,   9, 195,   2,   4,   9, 196,   2,   4,   9, 197,   2,   4,
   9, 198,   2,   4,   9, 199,   2,   4,   9, 200,   2,   4,   9, 201,   2,   4,
   9, 202,   2,   4,   9, 203,   2,   4,   9, 204,   2,   4,   9, 205,   2,   4,
   7, 110, 207,   2,   9,  23,  45,   9, 207,   2,  46,   9, 238,   1,  47,   9,
 238,   1,  48,   7,  18, 213,   2,   9,  23,  49,   9, 213,   2,  50,   7,   1,
 218,   2,   7,   1, 220,   2,   9, 218,   2,   4,   9, 220,   2,   4,   7,  18,
 222,   2,   9,  23,  51,   9, 222,   2,  50,   7,   4, 225,   2,   9, 226,   2,
   4,   9, 227,   2,   4,   9, 228,   2,   4,   9, 229,   2,   4,   9, 230,   2,
   4,   9, 231,   2,   4,   9,  23,  52,   9, 225,   2,  26, 249,   1,   1,   1,
   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   5,   1,   0,   0,   7,   1,   0,   0,   0,   1,   4,   0,   0,   1,   4,
   1,  12,   5,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   1,  20,  20,   1,  32,   0,   0,   1,   0,   0,   0,
   1,   0,   1,   1,  25,   1,  32,   1,  25,   5,   1,  32,   0,   5,   1,  32,
   0,   5,   1,  32,   0,   5,   1,  32,   1,   1,  26,   1,  32,   1,   1,   5,
   1,  32,   0,   1,   1,  32,   0,   2,   1,  32,   0,   7,   1,  32,   0,  26,
   1,  32,   0,   5,   1,  32,   0,  20,   1,  32,   0,  20,   1,  32,   0,  20,
   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   1,   2,
  19,   1,  32,   0,  25,   1,  32,   0,  25,   1,  32,   1,   1,  27,   1,  32,
   1,   1,  20,   1,  40,   1,   1,   6,   0,   0,   1,   0,   0,   0,   1,   0,
   1,   2,   5,   1,  32,   1,   5,   5,   1,  32,   2,   1,   5,   5,   1,  32,
   1,  53,   5,   1,  32,   2,   2,   5,  53,   1,  32,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   5,   1,   0,   0,   2,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,
   1,   1,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0, 198,   2,   1,  32,   0,   7,
   1,  32,   1,   1, 198,   2,   1,  32,   1,   0, 198,   2,   1,   0,   2,   0,
  53,   7,   1,  40,   1,   3,   3,   1,  12,   5,   1,  32,   2,   0,   5,   7,
   1,   8,   1,   3,   3,   0,  53,   1,  32,   1,   0,  53,   1,  32,   0,   0,
   1,   0,   1,   5,   5,   1,  32,   1,  19, 213,   2,   1,  32,   1,  26, 213,
   2,   1,  32,   2,   2,  19, 214,   2,   1,  32,   3,  20,  19, 214,   2,   7,
   1,  32,   2,  20,  19, 214,   2,   1,   0,   2,  20,  19, 214,   2,   1,   0,
   2,  20,  19, 214,   2,   1,   0,   0,  20,   1,  32,   1,  19,  12,   1,  32,
   0,  19,   1,   0,   2,  19,  19,   2,   1,  40,   1,  10,  10,   1,  20,   0,
   1,  32,   1,   1, 213,   2,   1,  32,   0,   0,   1,   2,   1,   1, 213,   2,
   1,   2,   1,   1,   2,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,
   1,   1,  32,   0,   1,   1,  32,   0,   0,   1,   0,   0,   5,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,  32,   0,  20,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   2,   0,  25,  25,   1,  40,   1,   4,   3,   1,  25,  25,   1,
  40,   1,   4,   3,   1,   0, 213,   2,   1,  32,   0, 213,   2,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1,   1,   2,   1,  32,
   1,   0,   2,   1,   8,   1,  10,  10,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1, 181,   3,   5,
   1,  36,   3, 181,   3, 181,   3,  25,  26,   1,  40,   1,  12,  12,   1,  26,
 181,   3,   1,  32,   1,   5,   5,   1,  36,   2,   5, 181,   3,   5,   1,  36,
   2,   5, 181,   3,   5,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,  46,
  35,   0,  37,   1,  38,  39,  91,   1,   0,  92,  91,   1,   0,  95,  91,   1,
   0,  98,  91,   1,   0, 101,  91,   1,   0, 104,  91,   1,   0, 107,  91,   2,
   0,   0,  92,  95,  91,   3,   0,   0,   0, 101,  95, 107,  91,   3,   0,   0,
   0, 104,  92,  95, 189,   1,   3, 190,   1, 192,   1, 194,   1, 191,   1, 193,
   1, 195,   1, 189,   1,   4, 190,   1, 198,   1, 194,   1, 201,   1, 197,   1,
 199,   1, 200,   1, 202,   1, 189,   1,   3, 190,   1, 194,   1, 201,   1, 203,
   1, 200,   1, 202,   1, 189,   1,   4, 190,   1, 192,   1, 194,   1, 201,   1,
 205,   1, 206,   1, 200,   1, 207,   1, 189,   1,   3, 190,   1, 192,   1, 194,
   1, 208,   1, 209,   1, 200,   1, 189,   1,   4, 190,   1, 192,   1, 194,   1,
 201,   1, 210,   1, 211,   1, 200,   1, 212,   1, 189,   1,   3, 190,   1, 192,
   1, 194,   1, 213,   1, 214,   1, 200,   1, 189,   1,   4, 190,   1, 192,   1,
 194,   1, 201,   1, 215,   1, 216,   1, 200,   1, 217,   1, 189,   1,   3, 190,
   1, 192,   1, 194,   1, 218,   1, 219,   1, 200,   1, 189,   1,   4, 190,   1,
 192,   1, 194,   1, 201,   1, 220,   1, 221,   1, 200,   1, 222,   1, 189,   1,
   4, 190,   1, 192,   1, 194,   1, 201,   1, 223,   1, 224,   1, 200,   1, 189,
   1, 189,   1,   1, 201,   1, 189,   1, 189,   1,   1, 225,   1, 226,   1, 189,
   1,   1, 225,   1, 227,   1, 189,   1,   4, 190,   1, 245,   1, 192,   1, 194,
   1, 244,   1, 199,   1, 246,   1, 200,   1, 189,   1,   3, 190,   1, 192,   1,
 194,   1, 149,   2, 160,   2, 200,   1, 189,   1,   1,   0, 162,   2, 189,   1,
   1,   0, 164,   2, 189,   1,   1,   0, 166,   2, 189,   1,   1,   0, 168,   2,
 189,   1,   1,   0, 170,   2, 189,   1,   1,   0, 172,   2, 189,   1,   1,   0,
 174,   2, 189,   1,   1,   0, 176,   2, 189,   1,   1,   0, 178,   2, 189,   1,
   1,   0, 180,   2, 189,   1,   1,   0, 184,   2, 189,   1,   1,   0, 186,   2,
 189,   1,   1,   0, 188,   2, 189,   1,   1,   0, 190,   2, 189,   1,   1,   0,
 192,   2,  91,   1,   0, 193,   2, 189,   1,   3, 190,   1, 194,   1, 201,   1,
 210,   2, 200,   1, 202,   1, 189,   1,   4, 190,   1, 245,   1, 192,   1, 194,
   1, 215,   2, 199,   1, 216,   2, 200,   1, 189,   1,   3, 190,   1, 192,   1,
 194,   1, 233,   2, 225,   2, 200,   1,  50,  16,   0,   5,   0,  38,   1,  15,
   1,   0,  37,  18,  19,   9,   9,   0,  41,   1,  17,   1,   0,  40,  22,  19,
   9,  11,   0,  44,   1,  21,   1,   0,  43,  52,  19,   9,  13,   0,  69,   0,
  58,  19,   9,  19,   0,  76,   0,  59,  19,   9,  22,   0,  78,   0,  60,  19,
   9,  24,   0,  80,   0,  61,  19,   9,  26,   0,  82,   0,  62,  19,   9,  28,
   0,  84,   0,  63,  19,   9,  30,   0,  86,   0,  64,  19,   9,  32,   0,  88,
   0,  67,  19,   9,  34,   0,  90,   0,  70,  19,   9,  36,   0,  92,   0,  74,
  19,  11,  40,   0,  96,   0, 115,  19,   9,  49,   0, 128,   1,  50,  75,   0,
   0,   2,  11,  11,  76,  64,   0,   2,  11,  11,   1,   2,  77,  64,   0,   2,
  11,  11,   1,   3,  78,  64,   0,   2,  11,  11,   1,   4,  79,  64,   0,   2,
  11,  11,   1,   5,  80,  64,   0,   2,  11,  11,   1,   6,  81,  64,   0,   2,
  11,  11,   1,   7,  82,  64,   0,   2,  11,  11,   1,   8,  83,  64,   0,   2,
  11,  11,   1,   9,  84,  64,   0,   2,  11,  11,   1,  10,  85,   6,   0,   2,
  11,  11,  86,  70,   0,   2,  11,  11,   1,   2,  87,  70,   0,   2,  11,  11,
   1,   3,  88,  70,   0,   2,  11,  11,   1,   4,  89,  70,   0,   2,  11,  11,
   1,   5,  90,  70,   0,   2,  11,  11,   1,   6,  91,  70,   0,   2,  11,  11,
   1,   7,  92,  70,   0,   2,  11,  11,   1,   8,  93,  70,   0,   2,  11,  11,
   1,   9,  94,  70,   0,   2,  11,  11,   1,  10,  95,   1,   0,  98,  96,  65,
   0,  99,   1,   2,  97,  65,   0, 100,   1,   3,  98,  65,   0, 101,   1,   4,
  99,  65,   0, 102,   1,   5, 100,  65,   0, 103,   1,   6, 101,  65,   0, 104,
   1,   7, 102,  65,   0, 105,   1,   8, 103,  65,   0, 106,   1,   9, 104,  65,
   0, 107,   1,  10, 105,   2,   0, 108, 106,  66,   0, 109,   1,   2, 107,  66,
   0, 110,   1,   3, 108,  66,   0, 111,   1,   4, 109,  66,   0, 112,   1,   5,
 110,  66,   0, 113,   1,   6, 111,  66,   0, 114,   1,   7, 112,  66,   0, 115,
   1,   8, 113,  66,   0, 116,   1,   9, 114,  66,   0, 117,   1,  10, 105,   3,
   0, 118, 106,  67,   0, 119,   1,   2, 107,  67,   0, 120,   1,   3, 108,  67,
   0, 121,   1,   4, 109,  67,   0, 122,   1,   5, 110,  67,   0, 123,   1,   6,
 111,  67,   0, 124,   1,   7, 112,  67,   0, 125,   1,   8, 113,  67,   0, 126,
   1,   9, 114,  67,   0, 127,   1,  10, 116,  19,   9,  51,   0, 130,   1,   0,
 117,  19,   9,  53,   0, 132,   1,   0, 118,  19,   9,  55,   0, 134,   1,   0,
 119,  19,   9,  57,   0, 136,   1,   0, 120,  19,   9,  59,   0, 138,   1,   0,
 121,  19,   9,  61,   0, 140,   1,   0, 122,  19,   9,  63,   0, 142,   1,   0,
 123,  19,   9,  65,   0, 144,   1,   0, 124,  19,   9,  67,   0, 146,   1,   0,
 125,   0,   5,   0, 148,   1,   0, 126,   0,   5,   0, 150,   1,   0, 127,   0,
   5,   0, 152,   1,   0, 128,   1,   0,   5,   0, 154,   1,   0, 129,   1,   0,
   5,   0, 156,   1,   0, 130,   1,   0,   5,   0, 158,   1,   0, 131,   1,   0,
   5,   0, 160,   1,   0, 132,   1,   0,   5,   0, 162,   1,   0, 133,   1,   0,
   5,   0, 164,   1,   0, 134,   1,   0,   5,   0, 166,   1,   0, 135,   1,  59,
   9,  69,   0, 168,   1,   0, 136,   1,  59,   9,  71,   0, 170,   1,   0, 137,
   1,  60,   9,  73,   0, 172,   1,   0, 138,   1,  60,   9,  75,   0, 174,   1,
   0, 139,   1,  61,   9,  77,   0, 176,   1,   0, 140,   1,  61,   9,  79,   0,
 178,   1,   0, 198,   2,  19,   9,  92,   0, 184,   1,   6, 205,   2,   1,   0,
 183,   1, 206,   2,   1,   0, 185,   1, 207,   2,   1,   0, 186,   1, 208,   2,
   1,   0, 187,   1, 209,   2,   2,   0, 188,   1, 209,   2,   3,   0, 189,   1,
 231,   2,  19,  11,  98,   0, 214,   1,   5, 226,   2,   6,   0,   5,   0, 227,
   2,   6,   0,   5,   0, 228,   2,   6,   0,   7,   0, 229,   2,   6,   0,  20,
   0, 230,   2,   1,   0, 213,   1, 234,   2,  19,   9, 101,   0, 216,   1,   2,
 232,   2,   6,   0,  20,   0, 233,   2,   6,   0,  26,   0, 243,   2,  19,  11,
 103,   0, 218,   1,   0, 248,   2, 234,   2,  11, 105,   0, 222,   1,   4, 244,
   2,   6,   0,  20,   0, 245,   2,   6,   0,  12,   0, 246,   2,   2,   0, 220,
   1, 247,   2,   2,   0, 221,   1, 249,   2, 234,   2,  11, 107,   0, 224,   1,
   2, 244,   2,   6,   0,  20,   0, 247,   2,   6,   0,  20,   0, 166,   3,  19,
   9, 111,   0, 231,   1,   0, 171,   3,  19,   8, 118,   0, 235,   1,   1, 170,
   3,   1,   0, 234,   1, 178,   3,  19,   9, 122,   0, 238,   1,   0, 181,   3,
  19,   9, 125,   0, 247,   1,   0,  36,   0,  39,   0,  42,   0,  45,  24,  28,
  81,   3,  46,   1,   0,  29,  81,   4,  47,   1,   1,  30,  17,   5,  48,  31,
  17,   6,  49,  32,  17,   7,  50,  33,  17,   8,  51,  34,  17,   9,  52,  35,
  17,  10,  53,  36,  17,  11,  54,  37,  17,  12,  55,  38,  17,  13,  56,  39,
   6,   1,  26,   0,  40,  17,  14,  57,  41,  18,  15,  58,  42,  18,  16,  59,
  43,  18,  17,  60,  44,  17,  18,  61,  45,  17,  19,  62,  46,  17,  20,  63,
  47,  17,  21,  64,  48,  18,  22,  65,  49,  18,  23,  66,  50,  17,  24,  67,
  51,  17,  25,  68,  70,   5,  54,  17,   3,  71,  55,  17,   4,  72,  34,  17,
   5,  73,  56,  17,   6,  74,  57,  17,   7,  75,  77,   0,  79,   0,  81,   0,
  83,   0,  85,   0,  87,   0,  89,   1,  66,   0,   1,  25,   1,   3,  91,   1,
  69,   0,   1,  25,   2,   3,  93,   2,  73,  18,   3,  94,  36,  18,   4,  95,
  97,   0, 129,   1,   0, 131,   1,   0, 133,   1,   0, 135,   1,   0, 137,   1,
   0, 139,   1,   0, 141,   1,   0, 143,   1,   0, 145,   1,   0, 147,   1,   0,
 149,   1,   0, 151,   1,   0, 153,   1,   0, 155,   1,   0, 157,   1,   0, 159,
   1,   0, 161,   1,   0, 163,   1,   0, 165,   1,   0, 167,   1,   0, 169,   1,
   0, 171,   1,   0, 173,   1,   0, 175,   1,   0, 177,   1,   0, 180,   1,   2,
 203,   2,  18,   3, 181,   1, 204,   2,  18,   4, 182,   1, 212,   1,   0, 215,
   1,   0, 217,   1,   4, 239,   2,   6,   1,  12,   0, 240,   2,   6,   2,  12,
   0, 241,   2,   6,   3,  12,   0, 242,   2,   6,   4,  12,   0, 219,   1,   0,
 223,   1,   0, 226,   1,  11, 155,   3,   6,   1,  25,   3,   3, 156,   3,   6,
   2,  25,   5,   3, 157,   3,   6,   3,  25,   4,   3, 158,   3,   6,   4,  25,
   6,   3, 159,   3,   6,   5,  25,   7,   3, 160,   3,   6,   6,   0,   5,   3,
 161,   3,   6,   7,   0,   4,   3, 162,   3,  17,   3, 227,   1, 163,   3,  17,
   4, 228,   1, 164,   3,  17,   5, 229,   1, 165,   3,  17,   6, 230,   1, 233,
   1,   0, 237,   1,   2, 176,   3,   6,   1,   5, 219,   2,   1, 177,   3,   6,
   2,   5, 221,   2,   1, 240,   1,   6, 182,   3,  17,   3, 241,   1, 183,   3,
  17,   4, 242,   1, 184,   3,  17,   5, 243,   1, 185,   3,  17,   6, 244,   1,
 186,   3,  17,   7, 245,   1, 187,   3,  17,   8, 246,   1,   7, 190,   1,   1,
 212,   2,  68,   0,  40,   1,  25, 225,   1,  25, 251,   2,   4,   1,  41, 252,
   2,   4,   2,  42, 253,   2,  68,   3,  44,   1,  26, 254,   2,   4,   4,  45,
 255,   2,  65,  37, 211,   1,   1,  27, 128,   3,  65,  38, 210,   1,   1,  28,
 129,   3,  65,  39, 209,   1,   1,  29, 130,   3,  65,  40, 208,   1,   1,  30,
 131,   3,  65,  41, 207,   1,   1,  31, 132,   3,   1,  42, 206,   1, 133,   3,
  65,  43, 204,   1,   1,  32, 134,   3,  65,  44, 203,   1,   1,  33, 135,   3,
  65,  45, 202,   1,   1,  34, 136,   3,   1,  46, 201,   1, 137,   3,  65,  47,
 200,   1,   1,  35, 138,   3,  65,  48, 199,   1,   1,  36, 139,   3,   1,  49,
 198,   1, 140,   3,   1,  50, 197,   1, 141,   3,   1,  51, 196,   1, 142,   3,
  65,  52, 195,   1,   1,  37, 143,   3,  65,  53, 194,   1,   1,  38, 144,   3,
  65,  54, 193,   1,   1,  39, 145,   3,  65,  55, 192,   1,   1,  40, 146,   3,
  65,  56, 191,   1,   1,  41, 147,   3,  68,   5,  43,   1,  42, 232,   1,   1,
 168,   3,  68,   1,  46,   1,  43, 236,   1,   1, 173,   3,  68,   1,  47,   1,
  44, 239,   1,   1, 180,   3,   4,   1,  48, 248,   1,   1, 189,   3,  68,   1,
  49,   1,  45, 179,   1, 103, 239,   1,   6,   0,   0,  16,   8, 141,   1,   4,
   0,   0, 142,   1,   4,   0,   1, 144,   1,  68,   0,   2,   1,  11, 240,   1,
  68,   0,   3,   1,  12, 241,   1,  68,   0,   4,   1,  13, 242,   1,   1,   1,
  35, 243,   1,  68,   0,   5,   1,  14, 244,   1,  68,   0,  34,   1,  15, 245,
   1,   4,   0,  35, 246,   1,  68,   0,   6,   1,  16, 247,   1,  68,   0,  36,
   1,  17, 248,   1,   4,   0,  37, 249,   1,  68,   0,   7,   1,  18, 250,   1,
  68,   0,  38,   1,  19, 251,   1,   4,   0,  39, 252,   1,  68,   0,   8,   1,
  20, 253,   1,  68,   0,   9,   1,  21, 254,   1,  68,   0,  10,   1,  22, 255,
   1,  68,   0,  11,   1,  23, 128,   2,  68,   0,  12,   1,  24, 129,   2,   4,
   0,  13, 130,   2,   1,   2,  34, 131,   2,   1,   3,  33,  33,   1,   4,  32,
  37,   1,   5,  31,  40,   1,   6,  30, 132,   2,   6,   0,   0,   2,   6, 133,
   2,   6,   0,   0,   3,   6, 134,   2,   6,   0,   0,   4,   6, 135,   2,   6,
   0,   0,   5,   6, 136,   2,   6,   0,   0,   6,   6, 137,   2,   6,   0,   0,
   7,   6, 138,   2,   0,   0,   2,   0, 139,   2,  64,   0,   2,   0,   1,   2,
 140,   2,  64,   0,   2,   0,   1,   3, 141,   2,  64,   0,   2,   0,   1,   4,
 142,   2,  64,   0,   2,   0,   1,   5, 143,   2,  64,   0,   2,   0,   1,   6,
 144,   2,  64,   0,   2,   0,   1,   7, 145,   2,  64,   0,   2,   0,   1,   8,
 146,   2,  64,   0,   2,   0,   1,   9, 147,   2,  64,   0,   2,   0,   1,  10,
 148,   2,   6,   0,   2,  11,  11, 149,   2,  70,   0,   2,  11,  11,   1,   2,
 150,   2,  70,   0,   2,  11,  11,   1,   3, 151,   2,  70,   0,   2,  11,  11,
   1,   4, 152,   2,  70,   0,   2,  11,  11,   1,   5, 153,   2,  70,   0,   2,
  11,  11,   1,   6, 154,   2,  70,   0,   2,  11,  11,   1,   7, 155,   2,  70,
   0,   2,  11,  11,   1,   8, 156,   2,  70,   0,   2,  11,  11,   1,   9, 157,
   2,  70,   0,   2,  11,  11,   1,  10, 158,   2,   1,   7,  29, 159,   2,  65,
   8,  28,   1,   2, 160,   2,  65,   9,  27,   1,   3, 161,   2,  65,  10,  26,
   1,   4, 162,   2,  65,  11,  25,   1,   5, 163,   2,  65,  12,  24,   1,   6,
 164,   2,  65,  13,  23,   1,   7, 165,   2,  65,  14,  22,   1,   8, 166,   2,
  65,  15,  21,   1,   9, 167,   2,  65,  16,  20,   1,  10, 168,   2,   2,  17,
  19, 169,   2,  66,  18,  18,   1,   2, 170,   2,  66,  19,  17,   1,   3, 171,
   2,  66,  20,  16,   1,   4, 172,   2,  66,  21,  15,   1,   5, 173,   2,  66,
  22,  14,   1,   6, 174,   2,  66,  23,  13,   1,   7, 175,   2,  66,  24,  12,
   1,   8, 176,   2,  66,  25,  11,   1,   9, 177,   2,  66,  26,  10,   1,  10,
 168,   2,   3,  27,   9, 169,   2,  67,  28,   8,   1,   2, 170,   2,  67,  29,
   7,   1,   3, 171,   2,  67,  30,   6,   1,   4, 172,   2,  67,  31,   5,   1,
   5, 173,   2,  67,  32,   4,   1,   6, 174,   2,  67,  33,   3,   1,   7, 175,
   2,  67,  34,   2,   1,   8, 176,   2,  67,  35,   1,   1,   9, 177,   2,  67,
  36,   0,   1,  10, 178,   2,   4,   0,  14, 179,   2,  68,   0,  15,   1,   2,
 180,   2,  68,   0,  16,   1,   3, 181,   2,  68,   0,  17,   1,   4, 182,   2,
  68,   0,  18,   1,   5, 183,   2,  68,   0,  19,   1,   6, 184,   2,  68,   0,
  20,   1,   7, 185,   2,  68,   0,  21,   1,   8, 186,   2,  68,   0,  22,   1,
   9, 187,   2,  68,   0,  23,   1,  10, 188,   2,   4,   0,  24, 189,   2,  68,
   0,  25,   1,   2, 190,   2,  68,   0,  26,   1,   3, 191,   2,  68,   0,  27,
   1,   4, 192,   2,  68,   0,  28,   1,   5, 193,   2,  68,   0,  29,   1,   6,
 194,   2,  68,   0,  30,   1,   7, 195,   2,  68,   0,  31,   1,   8, 196,   2,
  68,   0,  32,   1,   9, 197,   2,  68,   0,  33,   1,  10, 173,   1,   0,   1,
   2,   1,   2,   3, 208,  48,  71,   0,   0,   1,   1,   2,   1,   2,   3, 208,
  48,  71,   0,   0,   2,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   3,
   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   4,   1,   2,   1,   2,   3,
 208,  48,  71,   0,   0,   5,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,
   6,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   7,   1,   2,   1,   2,
   3, 208,  48,  71,   0,   0,   8,   1,   2,   1,   2,   3, 208,  48,  71,   0,
   0,   9,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,  10,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  11,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  12,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  13,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  14,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  15,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  16,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  17,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  18,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  19,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  20,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  21,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  22,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  23,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  24,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  25,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  26,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  27,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  28,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  29,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  30,   1,   1,   1,
   2,  10, 208,  48,  93,   3, 102,   3,  70,   4,   0,  72,   0,   0,  31,   1,
   1,   1,   2,  10, 208,  48,  93,   3, 102,   3,  70,   6,   0,  72,   0,   0,
  32,   2,   2,   1,   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   8,   1,
  41,  71,   0,   0,  33,   2,   2,   1,   2,  12, 208,  48,  93,   3, 102,   3,
 209,  70,   8,   1,  41,  71,   0,   0,  34,   2,   2,   1,   2,  13, 208,  48,
  93,   9, 102,   9, 102,  10, 209,  70,  11,   1,  72,   0,   0,  35,   1,   1,
   1,   2,  11, 208,  48,  93,  13, 102,  13,  70,  14,   0,  41,  71,   0,   0,
  36,   0,   1,   3,   3,   1,  71,   0,   0,  39,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0,  40,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0,  41,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  42,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0,  44,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0,  45,   2,   1,   3,   4,  12, 208,  48,  94,  23,
  93,  24,  70,  24,   0, 104,  23,  71,   0,   0,  69,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0,  70,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0,  76,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0,  77,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  78,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  79,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0,  80,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0,  81,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  82,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  83,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0,  84,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0,  85,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
  86,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  87,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0,  88,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0,  89,   2,   1,   3,   4,   9, 208,  48,  94,
  65,  36,  42,  97,  65,  71,   0,   0,  90,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0,  91,   2,   1,   3,   4,   9, 208,  48,  94,  68,
  36, 101,  97,  68,  71,   0,   0,  92,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0,  93,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
  94,   1,   1,   3,   4,   5, 208,  48,  44,  83,  72,   0,   0,  95,   1,   1,
   3,   4,  10, 208,  48,  93,  71, 102,  71,  70,  72,   0,  72,   0,   0,  96,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  97,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0,  98,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0,  99,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 100,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 101,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 102,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 103,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 104,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 105,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 106,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 107,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 108,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 109,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 110,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 111,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 112,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 113,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 114,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 115,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 116,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 117,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 118,   1,   2,   4,   5,   3, 208,  48,
  71,   0,   0, 119,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 120,   1,
   2,   4,   5,   3, 208,  48,  71,   0,   0, 121,   1,   2,   4,   5,   3, 208,
  48,  71,   0,   0, 122,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 123,
   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 124,   1,   2,   4,   5,   3,
 208,  48,  71,   0,   0, 125,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0,
 126,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 127,   1,   2,   4,   5,
   3, 208,  48,  71,   0,   0, 128,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 129,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 130,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 131,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 132,   1,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 133,   1,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 134,   1,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 135,   1,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0, 136,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 137,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 138,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 139,   1,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 140,   1,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 141,   1,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 142,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 143,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 144,   1,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 145,   1,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0, 146,   1,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 147,   1,   0,   1,   3,   3,   1,  71,
   0,   0, 149,   1,   0,   1,   3,   3,   1,  71,   0,   0, 151,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 153,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 155,   1,   0,   1,   3,   3,   1,  71,   0,   0, 157,   1,   0,   1,   3,   3,
   1,  71,   0,   0, 159,   1,   0,   1,   3,   3,   1,  71,   0,   0, 161,   1,
   0,   1,   3,   3,   1,  71,   0,   0, 163,   1,   0,   1,   3,   3,   1,  71,
   0,   0, 165,   1,   0,   1,   3,   3,   1,  71,   0,   0, 167,   1,   1,   1,
   4,   5,   3, 208,  48,  71,   0,   0, 168,   1,   1,   1,   5,   6,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 169,   1,   1,   1,   4,   5,   3, 208,  48,
  71,   0,   0, 170,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 171,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 172,   1,
   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 173,   1,   1,
   1,   4,   5,   3, 208,  48,  71,   0,   0, 174,   1,   1,   1,   5,   6,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 175,   1,   1,   1,   4,   5,   3, 208,
  48,  71,   0,   0, 176,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 177,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 178,
   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 179,   1,
   3,   1,   1,   4, 141,   7, 208,  48,  93, 141,   1,  32,  88,   0, 104,  16,
  93, 142,   1,  93,  19, 102,  19,  48,  93, 143,   1, 102, 143,   1,  88,   1,
  29, 104,  18,  93, 144,   1,  93,  19, 102,  19,  48,  93, 143,   1, 102, 143,
   1,  88,   2,  29, 104,  22,  93, 145,   1,  93,  19, 102,  19,  48,  93, 143,
   1, 102, 143,   1,  88,   3,  29, 104,  52,  93, 146,   1,  93,  19, 102,  19,
  48,  93, 143,   1, 102, 143,   1,  88,   4,  29, 104,  58,  93, 147,   1,  93,
  19, 102,  19,  48,  93, 148,   1, 102, 148,   1,  88,   5,  29, 104,  59,  93,
 149,   1,  93,  19, 102,  19,  48,  93,  59, 102,  59,  48,  93, 150,   1, 102,
 150,   1,  88,  34,  29,  29, 104, 135,   1,  93, 151,   1,  93,  19, 102,  19,
  48,  93,  59, 102,  59,  48,  93, 150,   1, 102, 150,   1,  88,  35,  29,  29,
 104, 136,   1,  93, 152,   1,  93,  19, 102,  19,  48,  93, 148,   1, 102, 148,
   1,  88,   6,  29, 104,  60,  93, 153,   1,  93,  19, 102,  19,  48,  93,  60,
 102,  60,  48,  93, 154,   1, 102, 154,   1,  88,  36,  29,  29, 104, 137,   1,
  93, 155,   1,  93,  19, 102,  19,  48,  93,  60, 102,  60,  48,  93, 154,   1,
 102, 154,   1,  88,  37,  29,  29, 104, 138,   1,  93, 156,   1,  93,  19, 102,
  19,  48,  93, 148,   1, 102, 148,   1,  88,   7,  29, 104,  61,  93, 157,   1,
  93,  19, 102,  19,  48,  93,  61, 102,  61,  48,  93, 158,   1, 102, 158,   1,
  88,  38,  29,  29, 104, 139,   1,  93, 159,   1,  93,  19, 102,  19,  48,  93,
  61, 102,  61,  48,  93, 158,   1, 102, 158,   1,  88,  39,  29,  29, 104, 140,
   1,  93, 160,   1,  93,  19, 102,  19,  48,  93, 148,   1, 102, 148,   1,  88,
   8,  29, 104,  62,  93, 161,   1,  93,  19, 102,  19,  48,  93, 148,   1, 102,
 148,   1,  88,   9,  29, 104,  63,  93, 162,   1,  93,  19, 102,  19,  48,  93,
 148,   1, 102, 148,   1,  88,  10,  29, 104,  64,  93, 163,   1,  93,  19, 102,
  19,  48,  93, 148,   1, 102, 148,   1,  88,  11,  29, 104,  67,  93, 164,   1,
  93,  19, 102,  19,  48,  93, 148,   1, 102, 148,   1,  88,  12,  29, 104,  70,
  93, 165,   1,  93,  19, 102,  19,  48,  93, 166,   1, 102, 166,   1,  88,  13,
  29, 104,  74,  93, 167,   1,  93,  19, 102,  19,  48,  93, 148,   1, 102, 148,
   1,  88,  14,  29, 104, 115,  93, 168,   1,  93,  19, 102,  19,  48,  93, 148,
   1, 102, 148,   1,  88,  15,  29, 104, 116,  93, 169,   1,  93,  19, 102,  19,
  48,  93, 148,   1, 102, 148,   1,  88,  16,  29, 104, 117,  93, 170,   1,  93,
  19, 102,  19,  48,  93, 148,   1, 102, 148,   1,  88,  17,  29, 104, 118,  93,
 171,   1,  93,  19, 102,  19,  48,  93, 148,   1, 102, 148,   1,  88,  18,  29,
 104, 119,  93, 172,   1,  93,  19, 102,  19,  48,  93, 148,   1, 102, 148,   1,
  88,  19,  29, 104, 120,  93, 173,   1,  93,  19, 102,  19,  48,  93, 148,   1,
 102, 148,   1,  88,  20,  29, 104, 121,  93, 174,   1,  93,  19, 102,  19,  48,
  93, 148,   1, 102, 148,   1,  88,  21,  29, 104, 122,  93, 175,   1,  93,  19,
 102,  19,  48,  93, 148,   1, 102, 148,   1,  88,  22,  29, 104, 123,  93, 176,
   1,  93,  19, 102,  19,  48,  93, 148,   1, 102, 148,   1,  88,  23,  29, 104,
 124,  93, 177,   1,  32,  88,  24, 104, 125,  93, 178,   1,  32,  88,  25, 104,
 126,  93, 179,   1,  32,  88,  26, 104, 127,  93, 180,   1,  32,  88,  27, 104,
 128,   1,  93, 181,   1,  32,  88,  28, 104, 129,   1,  93, 182,   1,  32,  88,
  29, 104, 130,   1,  93, 183,   1,  32,  88,  30, 104, 131,   1,  93, 184,   1,
  32,  88,  31, 104, 132,   1,  93, 185,   1,  32,  88,  32, 104, 133,   1,  93,
 186,   1,  32,  88,  33, 104, 134,   1,  93, 187,   1,  37, 149,   5,  37, 148,
   5, 161, 104, 188,   1,  93, 189,   1,  37, 150,   5,  37, 148,   5, 161, 104,
 190,   1,  93, 191,   1,  37, 151,   5,  37, 148,   5, 161, 104, 192,   1,  93,
 193,   1,  37, 152,   5,  37, 148,   5, 161, 104, 194,   1,  93, 195,   1,  37,
 153,   5,  37, 148,   5, 161, 104, 196,   1,  93, 197,   1,  37, 154,   5,  37,
 148,   5, 161, 104, 198,   1,  93, 199,   1,  38,  97, 200,   1,  93, 201,   1,
  38,  97, 202,   1,  93, 203,   1,  38,  97, 204,   1,  93, 205,   1,  38,  97,
 206,   1,  93, 207,   1,  38,  97, 208,   1,  93, 209,   1,  38,  97, 210,   1,
  93, 211,   1,  38,  97, 212,   1,  93, 213,   1,  38,  97, 214,   1,  93, 215,
   1,  38,  97, 216,   1,  93, 217,   1,  38,  97, 218,   1,  93, 219,   1,  38,
 104, 220,   1,  93, 221,   1,  38, 104, 222,   1,  93, 223,   1,  38, 104, 224,
   1,  93, 225,   1,  38, 104, 226,   1,  93, 227,   1,  38, 104, 228,   1,  93,
 229,   1,  38, 104, 230,   1,  93, 231,   1,  38, 104, 232,   1,  93, 233,   1,
  38, 104, 234,   1,  93, 235,   1,  38, 104, 236,   1,  93, 237,   1,  38, 104,
 238,   1,  71,   0,   0, 180,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 184,   1,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,  70,
 199,   2,   1,  41,  71,   0,   0, 187,   1,   3,   3,   4,   5,  20, 208,  48,
 208,  93, 200,   2, 102, 200,   2, 209,  70, 201,   2,   1, 210,  70, 202,   2,
   2,  72,   0,   0, 190,   1,   2,   1,   1,   3,  23, 208,  48,  93, 210,   2,
  93,  19, 102,  19,  48,  93, 211,   2, 102, 211,   2,  88,  40,  29, 104, 198,
   2,  71,   0,   0, 196,   1,   4,   3,   1,   2,  14, 208,  48,  93, 215,   2,
 209, 210,  36,   1,  70, 215,   2,   3,  72,   0,   0, 197,   1,   4,   3,   1,
   2,  14, 208,  48,  93, 215,   2, 209, 210,  36,   2,  70, 215,   2,   3,  72,
   0,   0, 198,   1,   4,   3,   1,   2,  14, 208,  48,  93, 215,   2, 209, 210,
  36,   0,  70, 215,   2,   3,  72,   0,   0, 201,   1,   2,   1,   1,   2,  13,
 208,  48,  93, 216,   2, 100, 108,   5,  70, 216,   2,   1,  72,   0,   0, 205,
   1,   3,   3,   3,   6,  47,  87,  42, 213,  48, 101,   0,  38, 118, 109,   1,
  93, 217,   2,  76, 217,   2,   0,  41,  16,  20,   0,   0, 209,  48,  90,   0,
  42, 214,  42,  48,  43, 109,   1, 101,   0,  39, 118, 109,   1,  29,   8,   2,
 101,   0, 108,   1,  72,   1,  10,  18,  22,   0, 218,   2,   1, 219,   2,   0,
   1,   2,   0, 206,   1,   2,   3,   2,   4,  60, 208,  48,  87,  42, 214,  48,
 101,   1,  33, 130, 109,   2, 101,   1, 209, 109,   1, 101,   1, 108,   1,  32,
  19,  24,   0,   0, 101,   1,  64, 205,   1, 130, 109,   2,  93, 220,   2, 101,
   1, 108,   2,  70, 220,   2,   1,  41,  16,   9,   0,   0,  93, 220,   2,  32,
  70, 220,   2,   1,  41,  71,   0,   2, 221,   2,   0,   1, 213,   2,   0, 222,
   2,   0,   2,   0,   0, 212,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 213,   1,   3,   1,   4,   5,  50, 208,  48, 208, 102, 223,   2,  44, 132,
   2, 160, 208, 102, 224,   2, 118,  18,  26,   0,   0,  44, 134,   2, 208, 102,
 224,   2, 160,  44, 135,   2, 160, 208, 102, 225,   2, 160,  44, 137,   2, 160,
 130,  16,   3,   0,   0,  44,   1, 130, 160,  72,   0,   0, 214,   1,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 215,   1,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 216,   1,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 217,   1,   2,   1,   3,   4,  39, 208,  48,  94,
 235,   2, 100, 108,   1, 104, 235,   2,  94, 236,   2, 100, 108,   2, 104, 236,
   2,  94, 237,   2, 100, 108,   4, 104, 237,   2,  94, 238,   2, 100, 108,   3,
 104, 238,   2,  71,   0,   0, 218,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 219,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 222,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 223,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 224,   1,   1,   1,
   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 225,   1,   2,   1,   1,
   4, 108, 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 250,   2, 102, 250,
   2,  88,  41,  29, 104, 231,   2, 101,   0,  93,  19, 102,  19,  48,  93, 250,
   2, 102, 250,   2,  88,  42,  29, 104, 234,   2, 101,   0,  93,  19, 102,  19,
  48,  93, 234,   2, 102, 234,   2,  48, 100, 108,   2,  88,  44,  29,  29, 104,
 248,   2, 101,   0,  93,  19, 102,  19,  48,  93, 234,   2, 102, 234,   2,  48,
 100, 108,   2,  88,  45,  29,  29, 104, 249,   2, 101,   0,  93,  19, 102,  19,
  48,  93, 250,   2, 102, 250,   2,  88,  43,  29, 104, 243,   2,  71,   0,   0,
 226,   1,   2,   1,   3,   4,  59, 208,  48,  94, 148,   3,  36,   0, 104, 148,
   3,  94, 149,   3,  36,   1, 104, 149,   3,  94, 150,   3,  36,   2, 104, 150,
   3,  94, 151,   3,  36,   3, 104, 151,   3,  94, 152,   3,  36,   4, 104, 152,
   3,  94, 153,   3,  36,   1, 104, 153,   3,  94, 154,   3,  36,   2, 104, 154,
   3,  71,   0,   0, 231,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 232,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  19,
 102,  19,  48,  93, 167,   3, 102, 167,   3,  88,  46,  29, 104, 166,   3,  71,
   0,   0, 233,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 235,   1,
   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 169,   3,   1,
  41,  71,   0,   0, 236,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,
  19, 102,  19,  48,  93, 172,   3, 102, 172,   3,  88,  47,  29, 104, 171,   3,
  71,   0,   0, 237,   1,   2,   1,   3,   4,  21, 208,  48,  94, 174,   3,  44,
 219,   2, 104, 174,   3,  94, 175,   3,  44, 221,   2, 104, 175,   3,  71,   0,
   0, 238,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 239,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,
  93, 179,   3, 102, 179,   3,  88,  48,  29, 104, 178,   3,  71,   0,   0, 240,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 247,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 248,   1,   2,   1,   1,   3,
  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 188,   3, 102, 188,   3,
  88,  49,  29, 104, 181,   3,  71,   0,   0};


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
    const char* const n_0; avmplus::DictionaryClass* const m_0;
    const char* const n_1; avmplus::DictionaryObject* const m_1;
    const char* const n_2; avmplus::DomainClass* const m_2;
    const char* const n_3; avmplus::DomainObject* const m_3;
    const char* const n_4; avmplus::JObject* const m_4;
    const char* const n_5; avmplus::JObjectClass* const m_5;
    const char* const n_6; avmplus::NewObjectSampleClass* const m_6;
    const char* const n_7; avmplus::NewObjectSampleObject* const m_7;
    const char* const n_8; avmplus::ScriptObject* const m_8;
    const char* const n_9; avmplus::TraceClass* const m_9;
    const char* const n_10; avmshell::AbstractBaseClass* const m_10;
    const char* const n_11; avmshell::AbstractBaseObject* const m_11;
    const char* const n_12; avmshell::AbstractRestrictedBaseClass* const m_12;
    const char* const n_13; avmshell::AbstractRestrictedBaseObject* const m_13;
    const char* const n_14; avmshell::CheckBaseClass* const m_14;
    const char* const n_15; avmshell::CheckBaseObject* const m_15;
    const char* const n_16; avmshell::FileClass* const m_16;
    const char* const n_17; avmshell::MIClass* const m_17;
    const char* const n_18; avmshell::MIObject* const m_18;
    const char* const n_19; avmshell::NativeBaseClass* const m_19;
    const char* const n_20; avmshell::NativeBaseObject* const m_20;
    const char* const n_21; avmshell::NativeSubclassOfAbstractBaseClass* const m_21;
    const char* const n_22; avmshell::NativeSubclassOfAbstractBaseObject* const m_22;
    const char* const n_23; avmshell::NativeSubclassOfAbstractRestrictedBaseClass* const m_23;
    const char* const n_24; avmshell::NativeSubclassOfAbstractRestrictedBaseObject* const m_24;
    const char* const n_25; avmshell::NativeSubclassOfRestrictedBaseClass* const m_25;
    const char* const n_26; avmshell::NativeSubclassOfRestrictedBaseObject* const m_26;
    const char* const n_27; avmshell::RestrictedBaseClass* const m_27;
    const char* const n_28; avmshell::RestrictedBaseObject* const m_28;
    const char* const n_29; avmshell::SystemClass* const m_29;
} aotABCTypes_shell_toplevel = {
    "DictionaryClass", 0,
    "DictionaryObject", 0,
    "DomainClass", 0,
    "DomainObject", 0,
    "JObject", 0,
    "JObjectClass", 0,
    "NewObjectSampleClass", 0,
    "NewObjectSampleObject", 0,
    "ScriptObject", 0,
    "TraceClass", 0,
    "::avmshell::AbstractBaseClass", 0,
    "::avmshell::AbstractBaseObject", 0,
    "::avmshell::AbstractRestrictedBaseClass", 0,
    "::avmshell::AbstractRestrictedBaseObject", 0,
    "::avmshell::CheckBaseClass", 0,
    "::avmshell::CheckBaseObject", 0,
    "::avmshell::FileClass", 0,
    "::avmshell::MIClass", 0,
    "::avmshell::MIObject", 0,
    "::avmshell::NativeBaseClass", 0,
    "::avmshell::NativeBaseObject", 0,
    "::avmshell::NativeSubclassOfAbstractBaseClass", 0,
    "::avmshell::NativeSubclassOfAbstractBaseObject", 0,
    "::avmshell::NativeSubclassOfAbstractRestrictedBaseClass", 0,
    "::avmshell::NativeSubclassOfAbstractRestrictedBaseObject", 0,
    "::avmshell::NativeSubclassOfRestrictedBaseClass", 0,
    "::avmshell::NativeSubclassOfRestrictedBaseObject", 0,
    "::avmshell::RestrictedBaseClass", 0,
    "::avmshell::RestrictedBaseObject", 0,
    "::avmshell::SystemClass", 0,
};
#endif
} }
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::CTestClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::CTestClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::CTestClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_CTestClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::CTestClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::CTestObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CTestClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CTestObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::MIClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::MIClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::MIClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_MIClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::MIClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::MIObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::MIClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::MIObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::SystemClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::SystemClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_SystemClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::SystemClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SystemObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::FileClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::FileClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_FileClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::FileClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::FileObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::AbstractBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::AbstractBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_AbstractBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::RestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::RestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::RestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_RestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::RestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::RestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::RestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::RestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::AbstractRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::AbstractRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_AbstractRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CheckBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::CheckBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::CheckBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CheckBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::CheckBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    avmshell::CheckBaseClass::preCreateInstanceCheck(cls);
    return new (cls->gc(), cls->getExtraSize()) avmshell::CheckBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CheckBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CheckBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::NativeBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::NativeBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::NativeBaseAS3Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::NativeBaseAS3Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_NativeBaseAS3Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::NativeBaseAS3Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::NativeBaseAS3Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseAS3Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseAS3Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ShellCoreFriend1Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ShellCoreFriend1Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::ShellCoreFriend1Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend1Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ShellCoreFriend1Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::ShellCoreFriend1Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend1Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend1Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ShellCoreFriend2Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ShellCoreFriend2Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::ShellCoreFriend2Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend2Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ShellCoreFriend2Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::ShellCoreFriend2Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend2Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend2Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::CapabilitiesClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::CapabilitiesClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::CapabilitiesClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_CapabilitiesClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::CapabilitiesClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::CapabilitiesObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CapabilitiesClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CapabilitiesObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_classClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_classClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_classClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_classClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_classClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_classObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_classClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_classObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_AIR_1_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_AIR_1_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_FP_10_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_FP_10_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_FP_10_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_FP_10_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_FP_10_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_AIR_1_5Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_AIR_1_5Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5_1Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5_1Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_AIR_1_5_1Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_1Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5_1Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_AIR_1_5_1Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_FP_10_0_32Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_FP_10_0_32Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_FP_10_0_32Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0_32Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_FP_10_0_32Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_FP_10_0_32Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5_2Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5_2Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_AIR_1_5_2Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_2Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5_2Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_AIR_1_5_2Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_2Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_2Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_0_FP_10_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_0_FP_10_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_AIR_1_0_FP_10_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_0_FP_10_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_0_FP_10_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_AIR_1_0_FP_10_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0_FP_10_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0_FP_10_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeSubclassOfAbstractBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::NativeSubclassOfAbstractBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::NativeSubclassOfAbstractBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfAbstractBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfAbstractBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::NativeSubclassOfAbstractBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SubclassOfAbstractBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SubclassOfAbstractBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::SubclassOfAbstractBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SubclassOfAbstractBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SubclassOfAbstractBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::SubclassOfAbstractBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeSubclassOfRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::NativeSubclassOfRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::NativeSubclassOfRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::NativeSubclassOfRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::RestrictedBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SubclassOfRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SubclassOfRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::SubclassOfRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SubclassOfRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SubclassOfRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::SubclassOfRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::RestrictedBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::NativeSubclassOfAbstractRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfAbstractRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::NativeSubclassOfAbstractRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractRestrictedBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SubclassOfAbstractRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SubclassOfAbstractRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::SubclassOfAbstractRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SubclassOfAbstractRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SubclassOfAbstractRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::SubclassOfAbstractRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractRestrictedBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::DomainClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::DomainClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::DomainClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_DomainClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DomainClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::DomainObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::StackFrameClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::StackFrameClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::StackFrameClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_StackFrameClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::StackFrameClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::StackFrameObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SampleClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SampleClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::SampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::SampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ClassFactoryClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ClassFactoryClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::ClassFactoryClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ClassFactoryClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ClassFactoryClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::ClassFactoryObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ClassFactoryClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ClassFactoryObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::NewObjectSampleClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::NewObjectSampleClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::NewObjectSampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_NewObjectSampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::NewObjectSampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::NewObjectSampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::DeleteObjectSampleClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::DeleteObjectSampleClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::DeleteObjectSampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_DeleteObjectSampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DeleteObjectSampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::DeleteObjectSampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::TraceClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::TraceClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_TraceClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::DictionaryClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::DictionaryClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::DictionaryClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_DictionaryClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DictionaryClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::DictionaryObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DictionaryClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DictionaryObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::EndianClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::EndianClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::EndianClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_EndianClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::EndianClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::EndianObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EndianClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EndianObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::JObjectClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::JObjectClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::JObjectClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_JObjectClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::JObjectClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::JObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::JObjectClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::JObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
