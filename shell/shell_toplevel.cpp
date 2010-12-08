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

const uint32_t shell_toplevel_abc_class_count = 37;
const uint32_t shell_toplevel_abc_script_count = 7;
const uint32_t shell_toplevel_abc_method_count = 226;
const uint32_t shell_toplevel_abc_length = 12546;

/* thunks (39 unique signatures, 62 total) */

#ifndef VMCFG_INDIRECT_NATIVE_THUNKS

AvmBox avmplus_Domain_currentDomain_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainClass* const obj = (::avmshell::DomainClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ::avmshell::DomainObject* const ret = obj->get_currentDomain();
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainClass* const obj = (::avmshell::DomainClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->get_MIN_DOMAIN_MEMORY_LENGTH();
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_private_init_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->init(
        (::avmshell::DomainObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_Domain_loadBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_getClass_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ClassClosure* const ret = obj->getClass(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_domainMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ByteArrayObject* const ret = obj->get_domainMemory();
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_domainMemory_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_domainMemory(
        (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_sampler_NewObjectSample_object_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->get_object();
    return (AvmBox) ret;
}
double flash_sampler_NewObjectSample_size_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_size();
    return ret;
}
AvmBox native_script_function_flash_sampler_clearSamples_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::clearSamples(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_startSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::startSampling(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_stopSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::stopSampling(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_pauseSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::pauseSampling(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_sampleInternalAllocs_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler__setSamplerCallback_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
double native_script_function_flash_sampler_getSize_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return ret;
}
AvmBox native_script_function_flash_sampler_getMemberNames_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_AvmBool32(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getSamples_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getSamples(obj);
    return (AvmBox) ret;
}
double native_script_function_flash_sampler_getSampleCount_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}
double native_script_function_flash_sampler__getInvocationCount_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
        , argoff3 = argoff2 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}
AvmBox native_script_function_flash_sampler_isGetterSetter_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getLexicalScopes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = SamplerScript::getLexicalScopes(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getSavedThis_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getSavedThis(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getMasterString_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_setLevel_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_getLevel_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_setListener_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->setListener(
        (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_getListener_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    FunctionObject* const ret = obj->getListener();
    return (AvmBox) ret;
}
AvmBox flash_utils_Dictionary_private_init_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_JObject_create_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_createArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_AvmBox_AvmObject(kAvmThunkNull) : (ArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff3]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_toArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->toArray(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_constructorSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->constructorSignature(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_methodSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_fieldSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}
double avmplus_MI_plus_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
}
AvmBox avmplus_System_exit_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_exec_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_System_getAvmplusVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getAvmplusVersion();
    return (AvmBox) ret;
}
AvmBox avmplus_System_getFeatures_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getFeatures();
    return (AvmBox) ret;
}
AvmBox avmplus_System_getRunmode_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getRunmode();
    return (AvmBox) ret;
}
AvmBox avmplus_System_trace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->trace(
        (ArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_debugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->debugger();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_isDebugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isDebugger();
    return (AvmBox) ret;
}
AvmBox avmplus_System_getTimer_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->getTimer();
    return (AvmBox) ret;
}
AvmBox avmplus_System_private_getArgv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->getArgv();
    return (AvmBox) ret;
}
AvmBox avmplus_System_readLine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->readLine();
    return (AvmBox) ret;
}
double avmplus_System_totalMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_totalMemory();
    return ret;
}
double avmplus_System_freeMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_freeMemory();
    return ret;
}
double avmplus_System_privateMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_privateMemory();
    return ret;
}
AvmBox avmplus_System_forceFullCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->forceFullCollection();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_queueCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->queueCollection();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_ns_example_nstest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->ns_example_nstest();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_isGlobal_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isGlobal(
        AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_System_swfVersion_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_swfVersion();
    return (AvmBox) ret;
}
AvmBox avmplus_System_disposeXML_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->disposeXML(
        (XMLObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_File_exists_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->exists(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_File_read_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->read(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_File_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_File_readByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ByteArrayObject* const ret = obj->readByteArray(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_File_writeByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->writeByteArray(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}

#else // VMCFG_INDIRECT_NATIVE_THUNKS

// avmplus_JObject_methodSignature
AvmBox shell_toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler_getMasterString
AvmBox shell_toplevel_func_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler__setSamplerCallback
AvmBox shell_toplevel_func_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_System_freeMemory_get
// avmplus_System_privateMemory_get
// avmplus_System_totalMemory_get
// flash_sampler_NewObjectSample_size_get
double shell_toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_double (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// avmplus_Domain_getClass
// avmplus_File_readByteArray
AvmBox shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBox (AvmObjectT::*FuncType)(AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
}

// native_script_function_flash_sampler_isGetterSetter
AvmBox shell_toplevel_func_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}

// avmplus_JObject_toArray
// flash_trace_Trace_setListener
AvmBox shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBox (AvmObjectT::*FuncType)(AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmObject(argv[argoff1])
    );
}

// avmplus_System_getAvmplusVersion
// avmplus_System_getFeatures
// avmplus_System_getRunmode
// avmplus_System_readLine
AvmBox shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_AvmString (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// native_script_function_flash_sampler_sampleInternalAllocs
AvmBox shell_toplevel_func_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_File_write
AvmBox shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return kAvmThunkUndefined;
}

// native_script_function_flash_sampler_getSize
double shell_toplevel_func_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return ret;
}

// native_script_function_flash_sampler_clearSamples
// native_script_function_flash_sampler_pauseSampling
// native_script_function_flash_sampler_startSampling
// native_script_function_flash_sampler_stopSampling
AvmBox shell_toplevel_func_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_void (*FuncType)(AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    (*func)(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])
    );
    return kAvmThunkUndefined;
}

// avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get
// avmplus_System_getTimer
AvmBox shell_toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_uint32_t (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// avmplus_JObject_constructorSignature
AvmBox shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->constructorSignature(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler_getSampleCount
double shell_toplevel_func_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}

// avmplus_System_swfVersion_get
AvmBox shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_swfVersion();
    return (AvmBox) ret;
}

// avmplus_JObject_fieldSignature
AvmBox shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}

// avmplus_System_exec
AvmBox shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}

// avmplus_System_isGlobal
AvmBox shell_toplevel_b2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isGlobal(
        AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return (AvmBox) ret;
}

// avmplus_File_read
AvmBox shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->read(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler_getSamples
AvmBox shell_toplevel_func_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getSamples(obj);
    return (AvmBox) ret;
}

// avmplus_JObject_create
AvmBox shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler_getLexicalScopes
// native_script_function_flash_sampler_getSavedThis
AvmBox shell_toplevel_func_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBox (*FuncType)(AvmObject, AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    return (AvmBox)(*func)(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])
        , AvmThunkUnbox_AvmObject(argv[argoff1])
    );
}

// avmplus_File_exists
AvmBox shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->exists(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}

// avmplus_Domain_currentDomain_get
// avmplus_Domain_domainMemory_get
// avmplus_System_private_getArgv
// flash_sampler_NewObjectSample_object_get
// flash_trace_Trace_getListener
AvmBox shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_AvmBox (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// avmplus_Domain_loadBytes
AvmBox shell_toplevel_a2a_oou_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}

// avmplus_System_debugger
// avmplus_System_forceFullCollection
// avmplus_System_ns_example_nstest
// avmplus_System_queueCollection
AvmBox shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
    return kAvmThunkUndefined;
}

// avmplus_MI_plus
double shell_toplevel_d2d_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
}

// flash_utils_Dictionary_private_init
AvmBox shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// flash_trace_Trace_getLevel
AvmBox shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (AvmBox) ret;
}

// flash_trace_Trace_setLevel
AvmBox shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}

// avmplus_File_writeByteArray
AvmBox shell_toplevel_b2a_oso_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->writeByteArray(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}

// avmplus_JObject_createArray
AvmBox shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_AvmBox_AvmObject(kAvmThunkNull) : (ArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff3]))
    );
    return (AvmBox) ret;
}

// avmplus_Domain_domainMemory_set
// avmplus_Domain_private_init
// avmplus_System_disposeXML
// avmplus_System_trace
AvmBox shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_System_isDebugger
AvmBox shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isDebugger();
    return (AvmBox) ret;
}

// avmplus_System_write
AvmBox shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_System_exit
AvmBox shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// native_script_function_flash_sampler__getInvocationCount
double shell_toplevel_func_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
        , argoff3 = argoff2 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}

// native_script_function_flash_sampler_getMemberNames
AvmBox shell_toplevel_func_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_AvmBool32(argv[argoff2]))
    );
    return (AvmBox) ret;
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
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::DomainClass::EmptySlotsStruct_DomainClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::DomainObject::EmptySlotsStruct_DomainObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doStackFrameClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(StackFrameClass::EmptySlotsStruct_StackFrameClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) == s_slotsOffsetStackFrameObject);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(StackFrameObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 302) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(iTraits, 303) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(iTraits, 304) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(iTraits, 305) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_scriptID)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(SampleClass::EmptySlotsStruct_SampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) == s_slotsOffsetSampleObject);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 308) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(iTraits, 309) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(NewObjectSampleClass::EmptySlotsStruct_NewObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) == s_slotsOffsetNewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 311) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 312) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_type)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleClass::EmptySlotsStruct_DeleteObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == s_slotsOffsetDeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 311) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 314) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doTraceClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) == s_slotsOffsetTraceClass);
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 348) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(cTraits, 349) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(cTraits, 350) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 351) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(cTraits, 352) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 353) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(cTraits, 354) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_LISTENER)));
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
AVMTHUNK_NATIVE_CLASS_GLUE(SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::doSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::doFileClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DomainClass, ::avmshell::DomainClass, SlotOffsetsAndAsserts::doDomainClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::doStackFrameClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(SampleClass, SampleClass, SlotOffsetsAndAsserts::doSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(TraceClass, TraceClass, SlotOffsetsAndAsserts::doTraceClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::doDictionaryClassAsserts)
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
        AVMTHUNK_NATIVE_METHOD(avmplus_System_disposeXML, ::avmshell::SystemClass::disposeXML)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_exists, ::avmshell::FileClass::exists)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_read, ::avmshell::FileClass::read)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_write, ::avmshell::FileClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_readByteArray, ::avmshell::FileClass::readByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_writeByteArray, ::avmshell::FileClass::writeByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_currentDomain_get, ::avmshell::DomainClass::get_currentDomain)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get, ::avmshell::DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_private_init, ::avmshell::DomainObject::init)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_loadBytes, ::avmshell::DomainObject::loadBytes)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_getClass, ::avmshell::DomainObject::getClass)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_get, ::avmshell::DomainObject::get_domainMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_set, ::avmshell::DomainObject::set_domainMemory)
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
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, ::avmshell::DomainClass, SlotOffsetsAndAsserts::s_slotsOffsetDomainClass, ::avmshell::DomainObject, SlotOffsetsAndAsserts::s_slotsOffsetDomainObject, false)
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
const uint8_t shell_toplevel_abc_data[12546] = {
  16,   0,  46,   0,   6,   0,   2,   1,   3,   4,   0,   0, 179,   2,   0,   4,
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
 110,  10, 100, 105, 115, 112, 111, 115, 101,  88,  77,  76,  12,  97, 118, 109,
 112, 108, 117, 115,  58,  70, 105, 108, 101,  11, 102, 108,  97, 115, 104,  46,
 117, 116, 105, 108, 115,   9,  66, 121, 116, 101,  65, 114, 114,  97, 121,   6,
 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100,  13, 114, 101,  97, 100,
  66, 121, 116, 101,  65, 114, 114,  97, 121,  14, 119, 114, 105, 116, 101,  66,
 121, 116, 101,  65, 114, 114,  97, 121,   4,  70, 105, 108, 101,  25, 102, 108,
  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  67,  97, 112,  97,  98,
 105, 108, 105, 116, 105, 101, 115,   7,  65,  86,  77,  80, 108, 117, 115,  12,
 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  10, 112, 108,  97,
 121, 101, 114,  84, 121, 112, 101,  12,  67,  97, 112,  97,  98, 105, 108, 105,
 116, 105, 101, 115,  21,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  10, 112, 117,  98, 108, 105,
  99,  95, 118,  97, 114,  14, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,
  95,  54,  54,  48,   3,  65,  80,  73,   3,  54,  54,  48,   3, 238, 138, 149,
  14, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  54,  54,  49,   3,
  54,  54,  49,   3, 238, 138, 150,  14, 112, 117,  98, 108, 105,  99,  95, 118,
  97, 114,  95,  54,  54,  50,   3,  54,  54,  50,   3, 238, 138, 151,  14, 112,
 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  54,  54,  51,   3,  54,  54,
  51,   3, 238, 138, 152,  14, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,
  95,  54,  54,  52,   3,  54,  54,  52,   3, 238, 138, 153,  14, 112, 117,  98,
 108, 105,  99,  95, 118,  97, 114,  95,  54,  54,  53,   3,  54,  54,  53,  18,
 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  54,  54,  49,  95,  54,
  54,  50,   3, 238, 138, 154,  18, 112, 117,  98, 108, 105,  99,  95, 118,  97,
 114,  95,  54,  54,  54,  95,  54,  54,  48,   3,  54,  54,  54,  22, 112, 117,
  98, 108, 105,  99,  95, 118,  97, 114,  95,  54,  54,  52,  95,  54,  54,  50,
  95,  54,  54,  54,  26, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,
  54,  54,  53,  95,  54,  54,  48,  95,  54,  54,  49,  95,  54,  54,  50,  12,
 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  16, 112, 117,  98,
 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  54,  54,  48,  16, 112, 117,
  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  54,  54,  49,  16, 112,
 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  54,  54,  50,  16,
 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  54,  54,  51,
  16, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  54,  54,
  52,  16, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  54,
  54,  53,  20, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,
  54,  54,  49,  95,  54,  54,  50,  20, 112, 117,  98, 108, 105,  99,  95,  99,
 111, 110, 115, 116,  95,  54,  54,  54,  95,  54,  54,  48,  24, 112, 117,  98,
 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  54,  54,  52,  95,  54,  54,
  50,  95,  54,  54,  54,  28, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110,
 115, 116,  95,  54,  54,  53,  95,  54,  54,  48,  95,  54,  54,  49,  95,  54,
  54,  50,  15, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  19, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  95,  54,  54,  48,  19, 112, 117,  98, 108, 105,  99,  95, 102, 117,
 110,  99, 116, 105, 111, 110,  95,  54,  54,  49,  19, 112, 117,  98, 108, 105,
  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  54,  54,  50,  19, 112,
 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  54,
  54,  51,  19, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  95,  54,  54,  52,  19, 112, 117,  98, 108, 105,  99,  95, 102, 117,
 110,  99, 116, 105, 111, 110,  95,  54,  54,  53,  23, 112, 117,  98, 108, 105,
  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  54,  54,  49,  95,  54,
  54,  50,  23, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  95,  54,  54,  54,  95,  54,  54,  48,  27, 112, 117,  98, 108, 105,
  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  54,  54,  52,  95,  54,
  54,  50,  95,  54,  54,  54,  31, 112, 117,  98, 108, 105,  99,  95, 102, 117,
 110,  99, 116, 105, 111, 110,  95,  54,  54,  53,  95,  54,  54,  48,  95,  54,
  54,  49,  95,  54,  54,  50,  13, 112, 117,  98, 108, 105,  99,  95, 103, 101,
 116, 115, 101, 116,  17, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115,
 101, 116,  95,  54,  54,  48,  17, 112, 117,  98, 108, 105,  99,  95, 103, 101,
 116, 115, 101, 116,  95,  54,  54,  49,  17, 112, 117,  98, 108, 105,  99,  95,
 103, 101, 116, 115, 101, 116,  95,  54,  54,  50,  17, 112, 117,  98, 108, 105,
  99,  95, 103, 101, 116, 115, 101, 116,  95,  54,  54,  51,  17, 112, 117,  98,
 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  54,  54,  52,  17, 112,
 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  54,  54,  53,
  21, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  54,
  54,  49,  95,  54,  54,  50,  21, 112, 117,  98, 108, 105,  99,  95, 103, 101,
 116, 115, 101, 116,  95,  54,  54,  54,  95,  54,  54,  48,  25, 112, 117,  98,
 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  54,  54,  52,  95,  54,
  54,  50,  95,  54,  54,  54,  29, 112, 117,  98, 108, 105,  99,  95, 103, 101,
 116, 115, 101, 116,  95,  54,  54,  53,  95,  54,  54,  48,  95,  54,  54,  49,
  95,  54,  54,  50,   8,  97, 118, 109, 115, 104, 101, 108, 108,  12, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  25,  97, 118, 109, 115, 104,
 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,
  95,  54,  54,  48,  16, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  95,  54,  54,  48,  25,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112,
 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  49,  16,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  49,
  25,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  54,  54,  50,  16, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  50,  25,  97, 118, 109, 115,
 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  95,  54,  54,  51,  16, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  54,  54,  51,  25,  97, 118, 109, 115, 104, 101, 108, 108,  58,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  52,
  16, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,
  52,  25,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  53,  16, 112, 117,  98, 108,
 105,  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  53,  29,  97, 118, 109,
 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  54,  54,  49,  95,  54,  54,  50,  20, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  49,  95,  54,  54,  50,  29,
  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,
  99, 108,  97, 115, 115,  95,  54,  54,  54,  95,  54,  54,  48,  20, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  54,  95,  54,
  54,  48,  33,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108,
 105,  99,  95,  99, 108,  97, 115, 115,  95,  54,  54,  52,  95,  54,  54,  50,
  95,  54,  54,  54,  24, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  95,  54,  54,  52,  95,  54,  54,  50,  95,  54,  54,  54,  37,  97, 118,
 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  95,  54,  54,  53,  95,  54,  54,  48,  95,  54,  54,  49,  95,
  54,  54,  50,  28, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,
  95,  54,  54,  53,  95,  54,  54,  48,  95,  54,  54,  49,  95,  54,  54,  50,
  16, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99,
 101,  20, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,
  99, 101,  95,  54,  54,  48,  20, 112, 117,  98, 108, 105,  99,  95, 105, 110,
 116, 101, 114, 102,  97,  99, 101,  95,  54,  54,  49,  20, 112, 117,  98, 108,
 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  54,  54,  50,
  20, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99,
 101,  95,  54,  54,  51,  20, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116,
 101, 114, 102,  97,  99, 101,  95,  54,  54,  52,  20, 112, 117,  98, 108, 105,
  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  54,  54,  53,  24,
 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,
  95,  54,  54,  49,  95,  54,  54,  50,  24, 112, 117,  98, 108, 105,  99,  95,
 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  54,  54,  54,  95,  54,  54,
  48,  28, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,
  99, 101,  95,  54,  54,  52,  95,  54,  54,  50,  95,  54,  54,  54,  32, 112,
 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,
  54,  54,  53,  95,  54,  54,  48,  95,  54,  54,  49,  95,  54,  54,  50,  10,
 110, 115,  95, 101, 120,  97, 109, 112, 108, 101,   6, 110,  97, 116, 105, 118,
 101,   3,  99, 108, 115,  19,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  77,  73,  67, 108,  97, 115, 115,   8, 105, 110, 115, 116,  97, 110,
  99, 101,  20,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,
  73,  79,  98, 106, 101,  99, 116,   7, 109, 101, 116, 104, 111, 100, 115,  24,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,  98,
 106, 101,  99, 116,  73, 109, 112, 108,  10,  97, 118, 109, 112, 108, 117, 115,
 238, 138, 148,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  83, 121, 115, 116, 101, 109,  67, 108,  97, 115, 115,   4,  97, 117, 116, 111,
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
 109, 111, 114, 121,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  68, 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,  24,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  68, 111, 109,  97, 105, 110,  79,
  98, 106, 101,  99, 116,   8,  70, 117, 110,  99, 116, 105, 111, 110,   5,  81,
  78,  97, 109, 101,  19,  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116,
 105, 111, 110,  67, 111, 117, 110, 116,  12,  83,  97, 109, 112, 108, 101, 114,
  46,  97, 115,  36,  51,  13, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112,
 108, 101, 114,   1, 102,   1, 101,   3, 114, 101, 116,  19,  95, 115, 101, 116,
  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7,
 119, 114,  97, 112, 112, 101, 114,  24, 102, 108,  97, 115, 104,  46, 115,  97,
 109, 112, 108, 101, 114,  58,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,
   4, 110,  97, 109, 101,   2,  40,  41,   4, 102, 105, 108, 101,   1,  91,   1,
  58,   4, 108, 105, 110, 101,   1,  93,   8, 115,  99, 114, 105, 112, 116,  73,
  68,   8, 116, 111,  83, 116, 114, 105, 110, 103,  10,  83, 116,  97,  99, 107,
  70, 114,  97, 109, 101,  20, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112,
 108, 101, 114,  58,  83,  97, 109, 112, 108, 101,   4, 116, 105, 109, 101,   5,
 115, 116,  97,  99, 107,   6,  83,  97, 109, 112, 108, 101,  29, 102, 108,  97,
 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  78, 101, 119,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,   2, 105, 100,   4, 116, 121,
 112, 101,   6, 111,  98, 106, 101,  99, 116,   4, 115, 105, 122, 101,  15,  78,
 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  32, 102,
 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  68, 101, 108,
 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  18,
  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112,
 108, 101,  16, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,
 238, 138, 148,  15,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  67, 108,
  97, 115, 115,  16,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  79,  98,
 106, 101,  99, 116,  12,  99, 111, 110, 115, 116, 115, 101, 116, 116, 101, 114,
 115,   4, 116, 114, 117, 101,  11,  83,  97, 109, 112, 108, 101,  67, 108,  97,
 115, 115,  12,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  20,
  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67,
 108,  97, 115, 115,  21,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97,
 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  23,  68, 101, 108, 101, 116,
 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97,
 115, 115,  24,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,
  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  12,  99, 108, 101,  97,
 114,  83,  97, 109, 112, 108, 101, 115,  27,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58,  99, 108, 101,  97, 114,  83,  97, 109,
 112, 108, 101, 115,  13, 115, 116,  97, 114, 116,  83,  97, 109, 112, 108, 105,
 110, 103,  28,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 115, 116,  97, 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  12,
 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,  27,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115, 116, 111, 112,
  83,  97, 109, 112, 108, 105, 110, 103,  13, 112,  97, 117, 115, 101,  83,  97,
 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108,
 105, 110, 103,  20, 115,  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,
  97, 108,  65, 108, 108, 111,  99, 115,  35,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 115,  97, 109, 112, 108, 101,  73, 110,
 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99, 115,  18, 115, 101, 116,
  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,  34,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95,
 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,
  99, 107,   7, 103, 101, 116,  83, 105, 122, 101,  22,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83, 105, 122,
 101,  14, 103, 101, 116,  77, 101, 109,  98, 101, 114,  78,  97, 109, 101, 115,
  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 103, 101, 116,  77, 101, 109,  98, 101, 114,  78,  97, 109, 101, 115,  10, 103,
 101, 116,  83,  97, 109, 112, 108, 101, 115,  25,  83,  97, 109, 112, 108, 101,
 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 109, 112,
 108, 101, 115,  14, 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117,
 110, 116,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,
  18, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  24, 103, 101, 116,  83, 101, 116, 116, 101, 114,  73, 110, 118,
 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,
  71, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,
  67, 111, 117, 110, 116,  34,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58,  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116,
 105, 111, 110,  67, 111, 117, 110, 116,  14, 105, 115,  71, 101, 116, 116, 101,
 114,  83, 101, 116, 116, 101, 114,  29,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 105, 115,  71, 101, 116, 116, 101, 114,  83,
 101, 116, 116, 101, 114,  16, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,
  83,  99, 111, 112, 101, 115,  31,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,
  83,  99, 111, 112, 101, 115,  12, 103, 101, 116,  83,  97, 118, 101, 100,  84,
 104, 105, 115,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58, 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  15,
 103, 101, 116,  77,  97, 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,  30,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103,
 101, 116,  77,  97, 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,  17, 102,
 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,  58,  84, 114,  97,  99, 101,
   3,  79,  70,  70,   7,  77,  69,  84,  72,  79,  68,  83,  17,  77,  69,  84,
  72,  79,  68,  83,  95,  87,  73,  84,  72,  95,  65,  82,  71,  83,  17,  77,
  69,  84,  72,  79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,
  27,  77,  69,  84,  72,  79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,
  69,  83,  95,  87,  73,  84,  72,  95,  65,  82,  71,  83,   4,  70,  73,  76,
  69,   8,  76,  73,  83,  84,  69,  78,  69,  82,   8, 115, 101, 116,  76, 101,
 118, 101, 108,   8, 103, 101, 116,  76, 101, 118, 101, 108,  11, 115, 101, 116,
  76, 105, 115, 116, 101, 110, 101, 114,  11, 103, 101, 116,  76, 105, 115, 116,
 101, 110, 101, 114,  11, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,
   5,  84, 114,  97,  99, 101,  10,  84, 114,  97,  99, 101,  46,  97, 115,  36,
  52,  14, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101, 238, 138, 148,
  10,  84, 114,  97,  99, 101,  67, 108,  97, 115, 115,  22, 102, 108,  97, 115,
 104,  46, 117, 116, 105, 108, 115,  58,  68, 105,  99, 116, 105, 111, 110,  97,
 114, 121,  15,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  46,  97, 115,
  36,  53,  10,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  14, 102, 108,
  97, 115, 104,  46, 117, 116, 105, 108, 115, 238, 138, 148,  15,  68, 105,  99,
 116, 105, 111, 110,  97, 114, 121,  67, 108,  97, 115, 115,  16,  68, 105,  99,
 116, 105, 111, 110,  97, 114, 121,  79,  98, 106, 101,  99, 116,  18, 102, 108,
  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  69, 110, 100, 105,  97, 110,
  10,  66,  73,  71,  95,  69,  78,  68,  73,  65,  78,   9,  98, 105, 103,  69,
 110, 100, 105,  97, 110,  13,  76,  73,  84,  84,  76,  69,  95,  69,  78,  68,
  73,  65,  78,  12, 108, 105, 116, 116, 108, 101,  69, 110, 100, 105,  97, 110,
   6,  69, 110, 100, 105,  97, 110,  11,  69, 110, 100, 105,  97, 110,  46,  97,
 115,  36,  54,  15,  97, 118, 109, 112, 108, 117, 115,  58,  74,  79,  98, 106,
 101,  99, 116,   7,  74,  79,  98, 106, 101,  99, 116,   6,  99, 114, 101,  97,
 116, 101,  11,  99, 114, 101,  97, 116, 101,  65, 114, 114,  97, 121,   7, 116,
 111,  65, 114, 114,  97, 121,  20,  99, 111, 110, 115, 116, 114, 117,  99, 116,
 111, 114,  83, 105, 103, 110,  97, 116, 117, 114, 101,  15, 109, 101, 116, 104,
 111, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,  14, 102, 105, 101, 108,
 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,   9,  74,  97, 118,  97,  46,
  97, 115,  36,  55,  12,  74,  79,  98, 106, 101,  99, 116,  67, 108,  97, 115,
 115,  99,  22,   1,   5,   5,  23,   1,  22,   6,  23,   6,   8,  17,   5,  20,
  22,  21,  24,  20,   5,  24,  24,  24,   5,  28,  24,  28,  26,  28,  26,  23,
   8,  50,   5,  55,  22,  56,  24,  55,   5,  63,  22,  65,  23,  65,  24,  63,
  26,  63,   5,  68,  22,  73,  22,  76,  22,  79,  22,  82,  22,  85,  22,  89,
  22, 127,  24,  68,   5, 129,   1,  24, 129,   1,   5, 131,   1,  24, 131,   1,
   5, 133,   1,  24, 133,   1,   5, 135,   1,  24, 135,   1,   5, 137,   1,  24,
 137,   1,   5, 139,   1,  24, 139,   1,   5, 141,   1,  24, 141,   1,   5, 143,
   1,  24, 143,   1,   5, 145,   1,  24, 145,   1,   5, 147,   1,  24, 147,   1,
  23, 127,  22, 168,   1,  22, 172,   1,  22, 175,   1,  22, 176,   1,  22, 177,
   1,  22, 178,   1,  22, 179,   1,  22, 180,   1,  22, 181,   1,   5, 182,   1,
   5, 184,   1,  24, 182,   1,  26, 182,   1,   5, 194,   1,  22, 195,   1,  23,
 195,   1,   5, 201,   1,  24, 201,   1,  26, 201,   1,   5, 212,   1,  24, 212,
   1,   5, 216,   1,  24, 216,   1,   5, 222,   1,  24, 222,   1,  22, 224,   1,
   5, 139,   2,  22, 151,   2,  24, 139,   2,   5, 153,   2,  23, 151,   2,  22,
 154,   2,   5, 156,   2,   5, 157,   2,  23,  56,  24, 156,   2,  26, 156,   2,
  22, 159,   2,   5, 162,   2,  24, 162,   2,   5, 168,   2,   5, 169,   2,  24,
 169,   2,   5, 177,   2,  51,   4,   1,   2,   3,   4,   4,   1,   2,   4,   5,
   1,   6,   1,   8,   8,   1,   2,   4,   5,  12,  13,  14,  15,   1,  12,   1,
  16,   9,   1,   2,   4,  15,  20,  21,  22,  23,  24,   1,  26,   1,  27,   1,
  28,   1,  29,   1,  30,   2,  26,  27,   2,   8,  31,   3,  27,  29,  31,   4,
   8,  26,  27,  30,   1,   5,   1,   4,   1,  21,   5,   1,   2,   4,  21,  22,
   1,  32,   4,   1,   2,  32,  54,   1,  55,   1,  56,   1,  57,   1,  58,   1,
  59,   1,  60,   1,  61,   1,  62,   2,  58,  59,   2,  57,  63,   3,  59,  61,
  63,   4,  57,  58,  59,  62,   8,   1,   4,   5,  15,  64,  65,  66,  67,   1,
  64,   4,   1,   4,   5,  65,   4,   1,  68,  69,  70,   1,  70,   8,   1,  15,
  68,  69,  70,  71,  72,  73,   1,  80,   4,   1,  82,  84,  85,   1,  86,   8,
   1,  15,  18,  87,  88,  89,  90,  91,   1,  87,   4,   1,  18,  88,  89,   1,
  92,   4,   1,  18,  89,  95,   4,   1,   4,   5,  98, 255,   2,   7,   1,   2,
   7,   1,   3,   9,   4,   1,   9,   7,   1,   7,   1,   8,   9,   9,   1,   7,
   1,  10,   9,  11,   1,   9,  12,   1,   9,  13,   1,   9,  14,   1,   7,   1,
  15,   9,   4,   2,   9,  16,   2,   9,  18,   3,   7,   5,  19,   9,  18,   4,
   7,   5,  22,   7,   1,  23,   7,   1,  25,   9,  26,   4,   7,   5,  27,   7,
   1,  29,   9,  30,   5,   7,   1,  31,   7,   1,  32,   7,   1,  33,   9,  34,
   4,   9,  36,   4,   9,  40,   4,   9,  41,   4,   9,  42,   4,   9,  11,   4,
   9,  43,   4,   9,  16,   4,   9,  44,   4,   9,   9,   4,   9,  30,   6,   9,
  29,   4,   9,   7,   4,   9,  45,   4,   9,  46,   4,   9,  47,   4,   9,  48,
   4,   9,  49,   4,   9,  51,   7,   9,  52,   4,   9,  53,   4,   9,  54,   4,
   7,   4,   4,   7,  18,  57,   9,  58,   4,   9,  59,   4,   9,  60,   4,   9,
  61,   4,   7,   4,  62,   9,   4,   8,   9,  44,   8,   9,  66,   4,   7,  21,
  67,   9,  69,   4,   9,  70,   4,   9,  74,   9,   9,  77,  10,   9,  80,  11,
   9,  83,  12,   9,  86,  13,   9,  88,  14,   9,  90,  15,   9,  92,  16,   9,
  93,  17,   9,  94,   4,   9,  95,   4,   9,  96,   9,   9,  97,  10,   9,  98,
  11,   9,  99,  12,   9, 100,  13,   9, 101,  14,   9, 102,  15,   9, 103,  16,
   9, 104,  17,   9, 105,   4,   9, 106,   4,   9, 107,   9,   9, 108,  10,   9,
 109,  11,   9, 110,  12,   9, 111,  13,   9, 112,  14,   9, 113,  15,   9, 114,
  16,   9, 115,  17,   9, 116,   4,   9, 117,   4,   9, 118,   9,   9, 119,  10,
   9, 120,  11,   9, 121,  12,   9, 122,  13,   9, 123,  14,   9, 124,  15,   9,
 125,  16,   9, 126,  17,   7,  32, 128,   1,   7,  32, 130,   1,   7,  32, 132,
   1,   7,  32, 134,   1,   7,  32, 136,   1,   7,  32, 138,   1,   7,  32, 140,
   1,   7,  32, 142,   1,   7,  32, 144,   1,   7,  32, 146,   1,   7,  32, 148,
   1,   7,  32, 149,   1,   7,  32, 150,   1,   7,  32, 151,   1,   7,  32, 152,
   1,   7,  32, 153,   1,   7,  32, 154,   1,   7,  32, 155,   1,   7,  32, 156,
   1,   7,  32, 157,   1,   7,  32, 158,   1,   7,  32, 159,   1,   9,  19,  18,
   9,  22,  18,   9,  23,   2,   9,  27,  18,   9,   4,  19,   9,  62,  19,   9,
  67,  20,   9,  23,  21,   9, 128,   1,  22,   9,  23,  23,   9, 130,   1,  22,
   9, 132,   1,  22,   9, 134,   1,  22,   9, 136,   1,  22,   9, 138,   1,  22,
   9, 140,   1,  22,   9, 142,   1,  22,   9, 144,   1,  22,   9, 146,   1,  22,
   9, 148,   1,  22,   9, 149,   1,  22,   9, 150,   1,  22,   9, 151,   1,  22,
   9, 152,   1,  22,   9, 153,   1,  22,   9, 154,   1,  22,   9, 155,   1,  22,
   9, 156,   1,  22,   9, 157,   1,  22,   9, 158,   1,  22,   9, 159,   1,  22,
   9,  69,  22,   7,  32,  69,   9,  70,  22,   7,  32,  70,   9,  74,  22,   7,
  32,  74,   9,  77,  22,   7,  32,  77,   9,  80,  22,   7,  32,  80,   9,  83,
  22,   7,  32,  83,   9,  86,  22,   7,  32,  86,   9,  88,  22,   7,  32,  88,
   9,  90,  22,   7,  32,  90,   9,  92,  22,   7,  32,  92,   9,  93,  22,   7,
  32,  93,   9,  94,  22,   7,  32,  94,   9,  95,  22,   7,  32,  95,   9,  96,
  22,   7,  32,  96,   9,  97,  22,   7,  32,  97,   9,  98,  22,   7,  32,  98,
   9,  99,  22,   7,  32,  99,   9, 100,  22,   7,  32, 100,   9, 101,  22,   7,
  32, 101,   9, 102,  22,   7,  32, 102,   9, 103,  22,   7,  32, 103,   9, 104,
  22,   7,  32, 104,   9, 160,   1,  18,   9,   4,  24,   9,  62,  24,   9,  16,
  24,   9,  67,  25,   9, 173,   1,   4,   9, 174,   1,   4,   9,  69,  26,   9,
  70,  26,   9,  74,  27,   9,  77,  28,   9,  80,  29,   9,  83,  30,   9,  86,
  31,   9,  88,  32,   9,  90,  33,   9,  92,  34,   9,  93,  35,   9,  94,  26,
   9,  95,  26,   9,  96,  27,   9,  97,  28,   9,  98,  29,   9,  99,  30,   9,
 100,  31,   9, 101,  32,   9, 102,  33,   9, 103,  34,   9, 104,  35,   9, 105,
  26,   9, 106,  26,   9, 107,  27,   9, 108,  28,   9, 109,  29,   9, 110,  30,
   9, 111,  31,   9, 112,  32,   9, 113,  33,   9, 114,  34,   9, 115,  35,   9,
 116,  26,   9, 117,  26,   9, 118,  27,   9, 119,  28,   9, 120,  29,   9, 121,
  30,   9, 122,  31,   9, 123,  32,   9, 124,  33,   9, 125,  34,   9, 126,  35,
   9, 128,   1,  26,   9, 130,   1,  26,   9, 132,   1,  27,   9, 134,   1,  28,
   9, 136,   1,  29,   9, 138,   1,  30,   9, 140,   1,  31,   9, 142,   1,  32,
   9, 144,   1,  33,   9, 146,   1,  34,   9, 148,   1,  35,   9, 149,   1,  26,
   9, 150,   1,  26,   9, 151,   1,  27,   9, 152,   1,  28,   9, 153,   1,  29,
   9, 154,   1,  30,   9, 155,   1,  31,   9, 156,   1,  32,   9, 157,   1,  33,
   9, 158,   1,  34,   9, 159,   1,  35,   7,   4,  12,   9, 183,   1,  36,   9,
  62,  36,   9,  60,  36,   9, 185,   1,  36,   9,  13,   4,   9, 186,   1,   4,
   9, 183,   1,  37,   9, 185,   1,   4,   9,  14,   4,   9, 187,   1,   4,   9,
 188,   1,   4,   9,  12,  19,   9,  23,  38,   9,  12,  24,   7,   1, 191,   1,
   7,   1, 192,   1,   9, 193,   1,  39,   9, 196,   1,  39,   7,   1, 197,   1,
   9, 198,   1,  40,   9, 199,   1,  39,   9, 196,   1,  40,   9, 200,   1,  40,
   9, 202,   1,  41,   9, 204,   1,  41,   9, 207,   1,  41,   9, 202,   1,   4,
   9, 204,   1,   4,   9, 207,   1,   4,   9, 209,   1,   4,   9, 210,   1,   4,
   7,  69, 211,   1,   9, 213,   1,   4,   9, 214,   1,   4,   7,  69, 215,   1,
   9, 217,   1,   4,   9, 218,   1,   4,   9, 219,   1,   4,   9, 220,   1,   4,
   7,  69, 221,   1,   7,  69, 223,   1,   9,  23,  39,   9, 211,   1,  42,   9,
 215,   1,  42,   9, 221,   1,  42,   9, 223,   1,  42,   9, 235,   1,  42,   9,
 237,   1,  42,   9, 239,   1,  42,   9, 241,   1,  42,   9, 243,   1,  42,   9,
 245,   1,  42,   9, 199,   1,  40,   9, 247,   1,  42,   9, 249,   1,  42,   9,
 251,   1,  42,   9, 253,   1,  42,   9, 255,   1,  42,   9, 128,   2,  42,   9,
 129,   2,  42,   9, 193,   1,  40,   9, 131,   2,  42,   9, 133,   2,  42,   9,
 135,   2,  42,   9, 137,   2,  42,   7,   1, 140,   2,   7,   1, 141,   2,   7,
   1, 142,   2,   7,   1, 143,   2,   7,   1, 144,   2,   7,   1, 145,   2,   7,
   1, 146,   2,   9, 140,   2,   4,   9, 141,   2,   4,   9, 142,   2,   4,   9,
 143,   2,   4,   9, 144,   2,   4,   9, 145,   2,   4,   9, 146,   2,   4,   9,
 147,   2,   4,   9, 148,   2,   4,   9, 149,   2,   4,   9, 150,   2,   4,   7,
  82, 152,   2,   9,  23,  43,   9, 152,   2,  44,   9, 183,   1,  45,   9, 183,
   1,  46,   7,  18, 158,   2,   9,  23,  47,   9, 158,   2,  48,   7,   1, 163,
   2,   7,   1, 165,   2,   9, 163,   2,   4,   9, 165,   2,   4,   7,  18, 167,
   2,   9,  23,  49,   9, 167,   2,  48,   7,   4, 170,   2,   9, 171,   2,   4,
   9, 172,   2,   4,   9, 173,   2,   4,   9, 174,   2,   4,   9, 175,   2,   4,
   9, 176,   2,   4,   9,  23,  50,   9, 170,   2,  24, 226,   1,   1,   1,   0,
   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,
   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,
   1,   0,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   5,   1,   0,
   0,   7,   1,   0,   0,   0,   1,   4,   0,   0,   1,   4,   1,  12,   5,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   1,  20,  20,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   1,   1,
  25,   1,  32,   1,  25,   5,   1,  32,   0,   5,   1,  32,   0,   5,   1,  32,
   0,   5,   1,  32,   1,   1,  26,   1,  32,   1,   1,   5,   1,  32,   0,   1,
   1,  32,   0,   2,   1,  32,   0,   7,   1,  32,   0,  26,   1,  32,   0,   5,
   1,  32,   0,  20,   1,  32,   0,  20,   1,  32,   0,  20,   1,  32,   0,   1,
   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   1,   2,  19,   1,  32,   0,
  25,   1,  32,   1,   1,  27,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   1,   2,   5,   1,  32,   1,   5,   5,   1,  32,   2,   1,   5,   5,   1,  32,
   1,  51,   5,   1,  32,   2,   2,   5,  51,   1,  32,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   5,   1,   0,   0,   2,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,
   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   1,   1,   0,   1,   0,
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
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0, 147,   2,   1,  32,   0,   7,   1,  32,   1,
   1, 147,   2,   1,  32,   1,   0, 147,   2,   1,   0,   2,   0,  51,   7,   1,
  40,   1,   1,   3,   1,  12,   5,   1,  32,   2,   0,   5,   7,   1,   8,   1,
   1,   3,   0,  51,   1,  32,   1,   0,  51,   1,  32,   0,   0,   1,   0,   1,
   5,   5,   1,  32,   1,  19, 162,   2,   1,  32,   1,  26, 162,   2,   1,  32,
   2,   2,  19, 163,   2,   1,  32,   3,  20,  19, 163,   2,   7,   1,  32,   2,
  20,  19, 163,   2,   1,   0,   2,  20,  19, 163,   2,   1,   0,   2,  20,  19,
 163,   2,   1,   0,   0,  20,   1,  32,   0,  19,   1,  32,   2,  19,  19,   2,
   1,  40,   1,  10,  10,   1,  20,   0,   1,  32,   1,   1, 162,   2,   1,  32,
   0,   0,   1,   2,   1,   1, 162,   2,   1,   2,   1,   1,   2,   1,  32,   0,
   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,
   0,   1,   0,   0,   5,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,  32,   0,  20,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   2,   0,  25,  25,   1,  40,   1,   2,   3,   1,  25,  25,   1,
  40,   1,   2,   3,   1,   0, 162,   2,   1,  32,   0, 162,   2,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1,   1,   2,   1,  32,
   1,   0,   2,   1,   8,   1,  10,  10,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1, 246,   2,   5,
   1,  36,   3, 246,   2, 246,   2,  25,  26,   1,  40,   1,  12,  12,   1,  26,
 246,   2,   1,  32,   1,   5,   5,   1,  36,   2,   5, 246,   2,   5,   1,  36,
   2,   5, 246,   2,   5,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,  38,
  35,   0,  37,   1,  38,  39,  71,   1,   0,  72,  71,   1,   0,  75,  71,   1,
   0,  78,  71,   1,   0,  81,  71,   1,   0,  84,  71,   1,   0,  87,  71,   2,
   0,   0,  75,  78,  71,   2,   0,   0,  91,  72,  71,   3,   0,   0,   0,  84,
  78,  91,  71,   4,   0,   0,   0,   0,  87,  72,  75,  78, 161,   1,   3, 162,
   1, 164,   1, 166,   1, 163,   1, 165,   1, 167,   1, 161,   1,   2, 162,   1,
 166,   1, 169,   1, 170,   1, 161,   1,   2, 162,   1, 166,   1, 171,   1, 170,
   1, 161,   1,   3, 162,   1, 164,   1, 166,   1, 189,   1, 190,   1, 170,   1,
 161,   1,   4, 162,   1, 164,   1, 166,   1, 227,   1, 225,   1, 226,   1, 170,
   1, 228,   1, 161,   1,   4, 162,   1, 164,   1, 166,   1, 227,   1, 229,   1,
 230,   1, 170,   1, 228,   1, 161,   1,   4, 162,   1, 164,   1, 166,   1, 227,
   1, 231,   1, 232,   1, 170,   1, 228,   1, 161,   1,   4, 162,   1, 164,   1,
 166,   1, 227,   1, 233,   1, 234,   1, 170,   1, 228,   1, 161,   1,   1,   0,
 236,   1, 161,   1,   1,   0, 238,   1, 161,   1,   1,   0, 240,   1, 161,   1,
   1,   0, 242,   1, 161,   1,   1,   0, 244,   1, 161,   1,   1,   0, 246,   1,
 161,   1,   1,   0, 248,   1, 161,   1,   1,   0, 250,   1, 161,   1,   1,   0,
 252,   1, 161,   1,   1,   0, 254,   1, 161,   1,   1,   0, 130,   2, 161,   1,
   1,   0, 132,   2, 161,   1,   1,   0, 134,   2, 161,   1,   1,   0, 136,   2,
 161,   1,   1,   0, 138,   2, 161,   1,   2, 162,   1, 166,   1, 155,   2, 170,
   1, 161,   1,   3, 162,   1, 164,   1, 166,   1, 160,   2, 161,   2, 170,   1,
 161,   1,   3, 162,   1, 164,   1, 166,   1, 178,   2, 170,   2, 170,   1,  37,
  16,   0,   5,   0,  41,   1,  15,   1,   0,  40,  18,  19,   9,   9,   0,  44,
   1,  17,   1,   0,  43,  22,  19,   9,  11,   0,  47,   1,  21,   1,   0,  46,
  50,  19,   9,  13,   0,  70,   0,  56,  19,   9,  19,   0,  77,   0,  60,  19,
  11,  23,   0,  81,   0, 105,  19,   9,  33,   0, 116,  55,  61,   0,   0,   2,
  11,  11,  62,  64,   0,   2,  11,  11,   1,   2,  63,  64,   0,   2,  11,  11,
   1,   3,  64,  64,   0,   2,  11,  11,   1,   4,  65,  64,   0,   2,  11,  11,
   1,   5,  66,  64,   0,   2,  11,  11,   1,   6,  67,  64,   0,   2,  11,  11,
   1,   7,  68,  64,   0,   2,  11,  11,   1,   8,  69,  64,   0,   2,  11,  11,
   1,   9,  70,  64,   0,   2,  11,  11,   1,  10,  71,  64,   0,   2,  11,  11,
   1,  11,  72,   6,   0,   2,  11,  11,  73,  70,   0,   2,  11,  11,   1,   2,
  74,  70,   0,   2,  11,  11,   1,   3,  75,  70,   0,   2,  11,  11,   1,   4,
  76,  70,   0,   2,  11,  11,   1,   5,  77,  70,   0,   2,  11,  11,   1,   6,
  78,  70,   0,   2,  11,  11,   1,   7,  79,  70,   0,   2,  11,  11,   1,   8,
  80,  70,   0,   2,  11,  11,   1,   9,  81,  70,   0,   2,  11,  11,   1,  10,
  82,  70,   0,   2,  11,  11,   1,  11,  83,   1,   0,  83,  84,  65,   0,  84,
   1,   2,  85,  65,   0,  85,   1,   3,  86,  65,   0,  86,   1,   4,  87,  65,
   0,  87,   1,   5,  88,  65,   0,  88,   1,   6,  89,  65,   0,  89,   1,   7,
  90,  65,   0,  90,   1,   8,  91,  65,   0,  91,   1,   9,  92,  65,   0,  92,
   1,  10,  93,  65,   0,  93,   1,  11,  94,   2,   0,  94,  95,  66,   0,  95,
   1,   2,  96,  66,   0,  96,   1,   3,  97,  66,   0,  97,   1,   4,  98,  66,
   0,  98,   1,   5,  99,  66,   0,  99,   1,   6, 100,  66,   0, 100,   1,   7,
 101,  66,   0, 101,   1,   8, 102,  66,   0, 102,   1,   9, 103,  66,   0, 103,
   1,  10, 104,  66,   0, 104,   1,  11,  94,   3,   0, 105,  95,  67,   0, 106,
   1,   2,  96,  67,   0, 107,   1,   3,  97,  67,   0, 108,   1,   4,  98,  67,
   0, 109,   1,   5,  99,  67,   0, 110,   1,   6, 100,  67,   0, 111,   1,   7,
 101,  67,   0, 112,   1,   8, 102,  67,   0, 113,   1,   9, 103,  67,   0, 114,
   1,  10, 104,  67,   0, 115,   1,  11, 106,  19,   9,  35,   0, 118,   0, 107,
  19,   9,  37,   0, 120,   0, 108,  19,   9,  39,   0, 122,   0, 109,  19,   9,
  41,   0, 124,   0, 110,  19,   9,  43,   0, 126,   0, 111,  19,   9,  45,   0,
 128,   1,   0, 112,  19,   9,  47,   0, 130,   1,   0, 113,  19,   9,  49,   0,
 132,   1,   0, 114,  19,   9,  51,   0, 134,   1,   0, 115,  19,   9,  53,   0,
 136,   1,   0, 116,   0,   5,   0, 138,   1,   0, 117,   0,   5,   0, 140,   1,
   0, 118,   0,   5,   0, 142,   1,   0, 119,   0,   5,   0, 144,   1,   0, 120,
   0,   5,   0, 146,   1,   0, 121,   0,   5,   0, 148,   1,   0, 122,   0,   5,
   0, 150,   1,   0, 123,   0,   5,   0, 152,   1,   0, 124,   0,   5,   0, 154,
   1,   0, 125,   0,   5,   0, 156,   1,   0, 126,   0,   5,   0, 158,   1,   0,
 147,   2,  19,   9,  66,   0, 164,   1,   6, 154,   2,   1,   0, 163,   1, 155,
   2,   1,   0, 165,   1, 156,   2,   1,   0, 166,   1, 157,   2,   1,   0, 167,
   1, 158,   2,   2,   0, 168,   1, 158,   2,   3,   0, 169,   1, 179,   2,  19,
  11,  72,   0, 193,   1,   5, 174,   2,   6,   0,   5,   0, 175,   2,   6,   0,
   5,   0, 176,   2,   6,   0,   7,   0, 177,   2,   6,   0,  20,   0, 178,   2,
   1,   0, 192,   1, 182,   2,  19,   9,  75,   0, 195,   1,   2, 180,   2,   6,
   0,  20,   0, 181,   2,   6,   0,  26,   0, 187,   2, 182,   2,  11,  77,   0,
 199,   1,   4, 183,   2,   6,   0,  20,   0, 184,   2,   6,   0,  12,   0, 185,
   2,   2,   0, 197,   1, 186,   2,   2,   0, 198,   1, 188,   2, 182,   2,  11,
  79,   0, 201,   1,   2, 183,   2,   6,   0,  20,   0, 186,   2,   6,   0,  20,
   0, 231,   2,  19,   9,  83,   0, 208,   1,   0, 236,   2,  19,   8,  90,   0,
 212,   1,   1, 235,   2,   1,   0, 211,   1, 243,   2,  19,   9,  94,   0, 215,
   1,   0, 246,   2,  19,   9,  97,   0, 224,   1,   0,  39,   0,  42,   0,  45,
   0,  48,  22,  28,  81,   3,  49,   1,   0,  29,  81,   4,  50,   1,   1,  30,
  17,   5,  51,  31,  17,   6,  52,  32,  17,   7,  53,  33,  17,   8,  54,  34,
  17,   9,  55,  35,  17,  10,  56,  36,  17,  11,  57,  37,  17,  12,  58,  38,
  17,  13,  59,  39,   6,   1,  26,   0,  40,  17,  14,  60,  41,  18,  15,  61,
  42,  18,  16,  62,  43,  18,  17,  63,  44,  17,  18,  64,  45,  17,  19,  65,
  46,  17,  20,  66,  47,  17,  21,  67,  48,  18,  22,  68,  49,  17,  23,  69,
  71,   5,  52,  17,   3,  72,  53,  17,   4,  73,  34,  17,   5,  74,  54,  17,
   6,  75,  55,  17,   7,  76,  78,   2,  59,  18,   3,  79,  36,  18,   4,  80,
  82,   0, 117,   0, 119,   0, 121,   0, 123,   0, 125,   0, 127,   0, 129,   1,
   0, 131,   1,   0, 133,   1,   0, 135,   1,   0, 137,   1,   0, 139,   1,   0,
 141,   1,   0, 143,   1,   0, 145,   1,   0, 147,   1,   0, 149,   1,   0, 151,
   1,   0, 153,   1,   0, 155,   1,   0, 157,   1,   0, 160,   1,   2, 152,   2,
  18,   3, 161,   1, 153,   2,  18,   4, 162,   1, 191,   1,   0, 194,   1,   0,
 196,   1,   0, 200,   1,   0, 203,   1,  11, 220,   2,   6,   1,  25,   1,   3,
 221,   2,   6,   2,  25,   3,   3, 222,   2,   6,   3,  25,   2,   3, 223,   2,
   6,   4,  25,   4,   3, 224,   2,   6,   5,  25,   5,   3, 225,   2,   6,   6,
   0,   3,   3, 226,   2,   6,   7,   0,   2,   3, 227,   2,  17,   3, 204,   1,
 228,   2,  17,   4, 205,   1, 229,   2,  17,   5, 206,   1, 230,   2,  17,   6,
 207,   1, 210,   1,   0, 214,   1,   2, 241,   2,   6,   1,   5, 164,   2,   1,
 242,   2,   6,   2,   5, 166,   2,   1, 217,   1,   6, 247,   2,  17,   3, 218,
   1, 248,   2,  17,   4, 219,   1, 249,   2,  17,   5, 220,   1, 250,   2,  17,
   6, 221,   1, 251,   2,  17,   7, 222,   1, 252,   2,  17,   8, 223,   1,   7,
 170,   1,   1, 161,   2,  68,   0,  28,   1,  15, 202,   1,  23, 190,   2,  68,
   1,  29,   1,  16, 191,   2,  68,   2,  30,   1,  17, 192,   2,  68,   3,  31,
   1,  18, 193,   2,  68,   4,  32,   1,  19, 194,   2,  65,  40, 190,   1,   1,
  20, 195,   2,  65,  41, 189,   1,   1,  21, 196,   2,  65,  42, 188,   1,   1,
  22, 197,   2,  65,  43, 187,   1,   1,  23, 198,   2,  65,  44, 186,   1,   1,
  24, 199,   2,   1,  45, 185,   1, 200,   2,  65,  46, 183,   1,   1,  25, 201,
   2,  65,  47, 182,   1,   1,  26, 202,   2,  65,  48, 181,   1,   1,  27, 203,
   2,  65,  49, 180,   1,   1,  28, 204,   2,  65,  50, 179,   1,   1,  29, 205,
   2,   1,  51, 178,   1, 206,   2,   1,  52, 177,   1, 207,   2,   1,  53, 176,
   1, 208,   2,  65,  54, 175,   1,   1,  30, 209,   2,  65,  55, 174,   1,   1,
  31, 210,   2,  65,  56, 173,   1,   1,  32, 211,   2,  65,  57, 172,   1,   1,
  33, 212,   2,  65,  58, 171,   1,   1,  34, 209,   1,   1, 233,   2,  68,   1,
  33,   1,  35, 213,   1,   1, 238,   2,  68,   1,  34,   1,  36, 216,   1,   1,
 245,   2,   4,   1,  35, 225,   1,   1, 254,   2,  68,   1,  36,   1,  37, 159,
   1,  90, 202,   1,   6,   0,   0,  16,   8, 127,   4,   0,   0, 128,   1,   4,
   0,   1, 130,   1,  68,   0,   2,   1,  12, 203,   1,  68,   0,   3,   1,  13,
 204,   1,  68,   0,   4,   1,  14, 205,   1,   1,   1,  38, 206,   1,   4,   0,
   5, 207,   1,   1,   2,  37, 208,   1,   1,   3,  36,  33,   1,   4,  35,  37,
   1,   5,  34,  40,   1,   6,  33, 209,   1,   0,   0,   2,   0, 210,   1,  64,
   0,   2,   0,   1,   2, 211,   1,  64,   0,   2,   0,   1,   3, 212,   1,  64,
   0,   2,   0,   1,   4, 213,   1,  64,   0,   2,   0,   1,   5, 214,   1,  64,
   0,   2,   0,   1,   6, 215,   1,  64,   0,   2,   0,   1,   7, 216,   1,  64,
   0,   2,   0,   1,   8, 217,   1,  64,   0,   2,   0,   1,   9, 218,   1,  64,
   0,   2,   0,   1,  10, 219,   1,  64,   0,   2,   0,   1,  11, 220,   1,   6,
   0,   2,  11,  11, 221,   1,  70,   0,   2,  11,  11,   1,   2, 222,   1,  70,
   0,   2,  11,  11,   1,   3, 223,   1,  70,   0,   2,  11,  11,   1,   4, 224,
   1,  70,   0,   2,  11,  11,   1,   5, 225,   1,  70,   0,   2,  11,  11,   1,
   6, 226,   1,  70,   0,   2,  11,  11,   1,   7, 227,   1,  70,   0,   2,  11,
  11,   1,   8, 228,   1,  70,   0,   2,  11,  11,   1,   9, 229,   1,  70,   0,
   2,  11,  11,   1,  10, 230,   1,  70,   0,   2,  11,  11,   1,  11, 231,   1,
   1,   7,  32, 232,   1,  65,   8,  31,   1,   2, 233,   1,  65,   9,  30,   1,
   3, 234,   1,  65,  10,  29,   1,   4, 235,   1,  65,  11,  28,   1,   5, 236,
   1,  65,  12,  27,   1,   6, 237,   1,  65,  13,  26,   1,   7, 238,   1,  65,
  14,  25,   1,   8, 239,   1,  65,  15,  24,   1,   9, 240,   1,  65,  16,  23,
   1,  10, 241,   1,  65,  17,  22,   1,  11, 242,   1,   2,  18,  21, 243,   1,
  66,  19,  20,   1,   2, 244,   1,  66,  20,  19,   1,   3, 245,   1,  66,  21,
  18,   1,   4, 246,   1,  66,  22,  17,   1,   5, 247,   1,  66,  23,  16,   1,
   6, 248,   1,  66,  24,  15,   1,   7, 249,   1,  66,  25,  14,   1,   8, 250,
   1,  66,  26,  13,   1,   9, 251,   1,  66,  27,  12,   1,  10, 252,   1,  66,
  28,  11,   1,  11, 242,   1,   3,  29,  10, 243,   1,  67,  30,   9,   1,   2,
 244,   1,  67,  31,   8,   1,   3, 245,   1,  67,  32,   7,   1,   4, 246,   1,
  67,  33,   6,   1,   5, 247,   1,  67,  34,   5,   1,   6, 248,   1,  67,  35,
   4,   1,   7, 249,   1,  67,  36,   3,   1,   8, 250,   1,  67,  37,   2,   1,
   9, 251,   1,  67,  38,   1,   1,  10, 252,   1,  67,  39,   0,   1,  11, 253,
   1,   4,   0,   6, 254,   1,  68,   0,   7,   1,   2, 255,   1,  68,   0,   8,
   1,   3, 128,   2,  68,   0,   9,   1,   4, 129,   2,  68,   0,  10,   1,   5,
 130,   2,  68,   0,  11,   1,   6, 131,   2,  68,   0,  12,   1,   7, 132,   2,
  68,   0,  13,   1,   8, 133,   2,  68,   0,  14,   1,   9, 134,   2,  68,   0,
  15,   1,  10, 135,   2,  68,   0,  16,   1,  11, 136,   2,   4,   0,  17, 137,
   2,  68,   0,  18,   1,   2, 138,   2,  68,   0,  19,   1,   3, 139,   2,  68,
   0,  20,   1,   4, 140,   2,  68,   0,  21,   1,   5, 141,   2,  68,   0,  22,
   1,   6, 142,   2,  68,   0,  23,   1,   7, 143,   2,  68,   0,  24,   1,   8,
 144,   2,  68,   0,  25,   1,   9, 145,   2,  68,   0,  26,   1,  10, 146,   2,
  68,   0,  27,   1,  11, 151,   1,   0,   1,   2,   1,   2,   3, 208,  48,  71,
   0,   0,   1,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   2,   1,   2,
   1,   2,   3, 208,  48,  71,   0,   0,   3,   1,   2,   1,   2,   3, 208,  48,
  71,   0,   0,   4,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   5,   1,
   2,   1,   2,   3, 208,  48,  71,   0,   0,   6,   1,   2,   1,   2,   3, 208,
  48,  71,   0,   0,   7,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   8,
   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   9,   1,   2,   1,   2,   3,
 208,  48,  71,   0,   0,  10,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,
  11,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  12,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  13,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  14,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  15,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  16,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  17,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  18,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  19,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  20,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  21,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  22,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  23,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  24,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  25,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  26,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  27,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  28,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  29,   1,   1,   1,   2,   4, 208,  48,
  38,  72,   0,   0,  30,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,
  31,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  32,   1,   1,   1,
   2,   4, 208,  48,  38,  72,   0,   0,  33,   1,   1,   1,   2,  10, 208,  48,
  93,   3, 102,   3,  70,   4,   0,  72,   0,   0,  34,   1,   1,   1,   2,  10,
 208,  48,  93,   3, 102,   3,  70,   6,   0,  72,   0,   0,  35,   2,   2,   1,
   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   8,   1,  41,  71,   0,   0,
  36,   2,   2,   1,   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   8,   1,
  41,  71,   0,   0,  37,   2,   2,   1,   2,  13, 208,  48,  93,   9, 102,   9,
 102,  10, 209,  70,  11,   1,  72,   0,   0,  38,   1,   1,   1,   2,  11, 208,
  48,  93,  13, 102,  13,  70,  14,   0,  41,  71,   0,   0,  39,   0,   1,   3,
   3,   1,  71,   0,   0,  42,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
  43,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0,  44,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0,  45,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0,  47,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0,  48,   2,   1,   3,   4,  12, 208,  48,  94,  23,  93,  24,  70,  24,
   0, 104,  23,  71,   0,   0,  70,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0,  71,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  77,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  78,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0,  79,   1,   1,   3,   4,   5, 208,  48,
  44,  64,  72,   0,   0,  80,   1,   1,   3,   4,  10, 208,  48,  93,  57, 102,
  57,  70,  58,   0,  72,   0,   0,  81,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0,  82,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
  83,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  84,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0,  85,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0,  86,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
  87,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  88,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0,  89,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0,  90,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
  91,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  92,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0,  93,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0,  94,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
  95,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  96,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0,  97,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0,  98,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
  99,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 100,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 101,   1,   1,   4,   5,   4, 208,  48,
  38,  72,   0,   0, 102,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,
 103,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 104,   1,   1,   4,
   5,   4, 208,  48,  38,  72,   0,   0, 105,   1,   2,   4,   5,   3, 208,  48,
  71,   0,   0, 106,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 107,   1,
   2,   4,   5,   3, 208,  48,  71,   0,   0, 108,   1,   2,   4,   5,   3, 208,
  48,  71,   0,   0, 109,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 110,
   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 111,   1,   2,   4,   5,   3,
 208,  48,  71,   0,   0, 112,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0,
 113,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 114,   1,   2,   4,   5,
   3, 208,  48,  71,   0,   0, 115,   1,   2,   4,   5,   3, 208,  48,  71,   0,
   0, 116,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 117,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 118,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 119,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 120,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 121,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 122,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 123,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0, 124,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 125,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 126,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 127,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 128,   1,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 129,   1,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0, 130,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 131,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 132,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 133,   1,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 134,   1,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 135,   1,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 136,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 137,   1,   0,   1,   3,   3,   1,  71,   0,   0, 139,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 141,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 143,   1,   0,   1,   3,   3,   1,  71,   0,   0, 145,   1,   0,   1,   3,   3,
   1,  71,   0,   0, 147,   1,   0,   1,   3,   3,   1,  71,   0,   0, 149,   1,
   0,   1,   3,   3,   1,  71,   0,   0, 151,   1,   0,   1,   3,   3,   1,  71,
   0,   0, 153,   1,   0,   1,   3,   3,   1,  71,   0,   0, 155,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 157,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 159,   1,   2,   1,   1,   3, 172,   4, 208,  48,  93, 127,  32,  88,   0, 104,
  16,  93, 128,   1,  93,  19, 102,  19,  48,  93, 129,   1, 102, 129,   1,  88,
   1,  29, 104,  18,  93, 130,   1,  93,  19, 102,  19,  48,  93, 129,   1, 102,
 129,   1,  88,   2,  29, 104,  22,  93, 131,   1,  93,  19, 102,  19,  48,  93,
 129,   1, 102, 129,   1,  88,   3,  29, 104,  50,  93, 132,   1,  93,  19, 102,
  19,  48,  93, 129,   1, 102, 129,   1,  88,   4,  29, 104,  56,  93, 133,   1,
  93,  19, 102,  19,  48,  93, 134,   1, 102, 134,   1,  88,   5,  29, 104,  60,
  93, 135,   1,  93,  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,  88,   6,
  29, 104, 105,  93, 137,   1,  93,  19, 102,  19,  48,  93, 136,   1, 102, 136,
   1,  88,   7,  29, 104, 106,  93, 138,   1,  93,  19, 102,  19,  48,  93, 136,
   1, 102, 136,   1,  88,   8,  29, 104, 107,  93, 139,   1,  93,  19, 102,  19,
  48,  93, 136,   1, 102, 136,   1,  88,   9,  29, 104, 108,  93, 140,   1,  93,
  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,  88,  10,  29, 104, 109,  93,
 141,   1,  93,  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,  88,  11,  29,
 104, 110,  93, 142,   1,  93,  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,
  88,  12,  29, 104, 111,  93, 143,   1,  93,  19, 102,  19,  48,  93, 136,   1,
 102, 136,   1,  88,  13,  29, 104, 112,  93, 144,   1,  93,  19, 102,  19,  48,
  93, 136,   1, 102, 136,   1,  88,  14,  29, 104, 113,  93, 145,   1,  93,  19,
 102,  19,  48,  93, 136,   1, 102, 136,   1,  88,  15,  29, 104, 114,  93, 146,
   1,  93,  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,  88,  16,  29, 104,
 115,  93, 147,   1,  32,  88,  17, 104, 116,  93, 148,   1,  32,  88,  18, 104,
 117,  93, 149,   1,  32,  88,  19, 104, 118,  93, 150,   1,  32,  88,  20, 104,
 119,  93, 151,   1,  32,  88,  21, 104, 120,  93, 152,   1,  32,  88,  22, 104,
 121,  93, 153,   1,  32,  88,  23, 104, 122,  93, 154,   1,  32,  88,  24, 104,
 123,  93, 155,   1,  32,  88,  25, 104, 124,  93, 156,   1,  32,  88,  26, 104,
 125,  93, 157,   1,  32,  88,  27, 104, 126,  93, 158,   1,  38,  97, 159,   1,
  93, 160,   1,  38,  97, 161,   1,  93, 162,   1,  38,  97, 163,   1,  93, 164,
   1,  38,  97, 165,   1,  93, 166,   1,  38,  97, 167,   1,  93, 168,   1,  38,
  97, 169,   1,  93, 170,   1,  38,  97, 171,   1,  93, 172,   1,  38,  97, 173,
   1,  93, 174,   1,  38,  97, 175,   1,  93, 176,   1,  38,  97, 177,   1,  93,
 178,   1,  38,  97, 179,   1,  93, 180,   1,  38, 104, 181,   1,  93, 182,   1,
  38, 104, 183,   1,  93, 184,   1,  38, 104, 185,   1,  93, 186,   1,  38, 104,
 187,   1,  93, 188,   1,  38, 104, 189,   1,  93, 190,   1,  38, 104, 191,   1,
  93, 192,   1,  38, 104, 193,   1,  93, 194,   1,  38, 104, 195,   1,  93, 196,
   1,  38, 104, 197,   1,  93, 198,   1,  38, 104, 199,   1,  93, 200,   1,  38,
 104, 201,   1,  71,   0,   0, 160,   1,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0, 164,   1,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,
  70, 148,   2,   1,  41,  71,   0,   0, 167,   1,   3,   3,   4,   5,  20, 208,
  48, 208,  93, 149,   2, 102, 149,   2, 209,  70, 150,   2,   1, 210,  70, 151,
   2,   2,  72,   0,   0, 170,   1,   2,   1,   1,   3,  23, 208,  48,  93, 159,
   2,  93,  19, 102,  19,  48,  93, 160,   2, 102, 160,   2,  88,  28,  29, 104,
 147,   2,  71,   0,   0, 176,   1,   4,   3,   1,   2,  14, 208,  48,  93, 164,
   2, 209, 210,  36,   1,  70, 164,   2,   3,  72,   0,   0, 177,   1,   4,   3,
   1,   2,  14, 208,  48,  93, 164,   2, 209, 210,  36,   2,  70, 164,   2,   3,
  72,   0,   0, 178,   1,   4,   3,   1,   2,  14, 208,  48,  93, 164,   2, 209,
 210,  36,   0,  70, 164,   2,   3,  72,   0,   0, 184,   1,   3,   3,   3,   6,
  47,  87,  42, 213,  48, 101,   0,  38, 118, 109,   1,  93, 165,   2,  76, 165,
   2,   0,  41,  16,  20,   0,   0, 209,  48,  90,   0,  42, 214,  42,  48,  43,
 109,   1, 101,   0,  39, 118, 109,   1,  29,   8,   2, 101,   0, 108,   1,  72,
   1,  10,  18,  22,   0, 166,   2,   1, 167,   2,   0,   1,   2,   0, 185,   1,
   2,   3,   2,   4,  60, 208,  48,  87,  42, 214,  48, 101,   1,  33, 130, 109,
   2, 101,   1, 209, 109,   1, 101,   1, 108,   1,  32,  19,  24,   0,   0, 101,
   1,  64, 184,   1, 130, 109,   2,  93, 168,   2, 101,   1, 108,   2,  70, 168,
   2,   1,  41,  16,   9,   0,   0,  93, 168,   2,  32,  70, 168,   2,   1,  41,
  71,   0,   2, 169,   2,   0,   1, 162,   2,   0, 170,   2,   0,   2,   0,   0,
 191,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 192,   1,   3,   1,
   4,   5,  50, 208,  48, 208, 102, 171,   2,  44, 203,   1, 160, 208, 102, 172,
   2, 118,  18,  26,   0,   0,  44, 205,   1, 208, 102, 172,   2, 160,  44, 206,
   1, 160, 208, 102, 173,   2, 160,  44, 208,   1, 160, 130,  16,   3,   0,   0,
  44,   1, 130, 160,  72,   0,   0, 193,   1,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 194,   1,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0, 195,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 196,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 199,   1,   1,
   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 200,   1,   1,   1,
   4,   5,   3, 208,  48,  71,   0,   0, 201,   1,   1,   1,   5,   6,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 202,   1,   2,   1,   1,   4,  89, 208,  48,
 101,   0,  93,  19, 102,  19,  48,  93, 189,   2, 102, 189,   2,  88,  29,  29,
 104, 179,   2, 101,   0,  93,  19, 102,  19,  48,  93, 189,   2, 102, 189,   2,
  88,  30,  29, 104, 182,   2, 101,   0,  93,  19, 102,  19,  48,  93, 182,   2,
 102, 182,   2,  48, 100, 108,   2,  88,  31,  29,  29, 104, 187,   2, 101,   0,
  93,  19, 102,  19,  48,  93, 182,   2, 102, 182,   2,  48, 100, 108,   2,  88,
  32,  29,  29, 104, 188,   2,  71,   0,   0, 203,   1,   2,   1,   3,   4,  59,
 208,  48,  94, 213,   2,  36,   0, 104, 213,   2,  94, 214,   2,  36,   1, 104,
 214,   2,  94, 215,   2,  36,   2, 104, 215,   2,  94, 216,   2,  36,   3, 104,
 216,   2,  94, 217,   2,  36,   4, 104, 217,   2,  94, 218,   2,  36,   1, 104,
 218,   2,  94, 219,   2,  36,   2, 104, 219,   2,  71,   0,   0, 208,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 209,   1,   2,   1,
   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 232,   2, 102,
 232,   2,  88,  33,  29, 104, 231,   2,  71,   0,   0, 210,   1,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 212,   1,   2,   2,   4,   5,  13, 208,  48,
 208,  73,   0, 208, 209,  70, 234,   2,   1,  41,  71,   0,   0, 213,   1,   2,
   1,   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 237,   2,
 102, 237,   2,  88,  34,  29, 104, 236,   2,  71,   0,   0, 214,   1,   2,   1,
   3,   4,  21, 208,  48,  94, 239,   2,  44, 164,   2, 104, 239,   2,  94, 240,
   2,  44, 166,   2, 104, 240,   2,  71,   0,   0, 215,   1,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 216,   1,   2,   1,   1,   3,  22,
 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 244,   2, 102, 244,   2,  88,
  35,  29, 104, 243,   2,  71,   0,   0, 217,   1,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 224,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 225,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  19,
 102,  19,  48,  93, 253,   2, 102, 253,   2,  88,  36,  29, 104, 246,   2,  71,
   0,   0};


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

} }
