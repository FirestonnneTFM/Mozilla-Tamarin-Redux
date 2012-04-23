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
const uint32_t shell_toplevel_abc_script_count = 5;
const uint32_t shell_toplevel_abc_method_count = 246;
const uint32_t shell_toplevel_abc_length = 15947;

/* thunks (62 total) */
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
avmplus::Atom avmplus_Domain_currentDomain_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_Domain_currentDomain_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::DomainObject* arg1 = (avmplus::DomainObject*)AvmThunkUnbox_OBJECT(avmplus::DomainObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    obj->init(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_Domain_private_init_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_Domain_private_init_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    avmplus::ByteArrayObject* arg1 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1]);
    uint32_t arg2 = (argc < 2 ? AvmThunkCoerce_INT_UINT(0) : AvmThunkUnbox_UINT(uint32_t, argv[argoff2]));
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->loadBytes(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_Domain_loadBytes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_Domain_loadBytes_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::ClassClosure* const ret = obj->getClass(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_Domain_getClass_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_Domain_getClass_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_Domain_domainMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_Domain_domainMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ByteArrayObject* arg1 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    obj->set_domainMemory(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_Domain_domainMemory_set_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_Domain_domainMemory_set_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom flash_sampler_NewObjectSample_object_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_sampler_NewObjectSample_object_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
double flash_sampler_NewObjectSample_size_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = flash_sampler_NewObjectSample_size_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom native_script_function_flash_sampler_clearSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_clearSamples_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom native_script_function_flash_sampler_startSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_startSampling_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom native_script_function_flash_sampler_stopSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_stopSampling_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom native_script_function_flash_sampler_pauseSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_pauseSampling_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::bool32 arg1 = AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , arg1
    );
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_sampleInternalAllocs_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , arg1
    );
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler__setSamplerCallback_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , arg1
    );
    return double(ret);
}
double native_script_function_flash_sampler_getSize_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = native_script_function_flash_sampler_getSize_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmplus::bool32 arg2 = (argc < 2 ? false : AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff2]));
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getMemberNames(obj
        , arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getMemberNames_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_getMemberNames_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler__getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ClassClosure* arg1 = (avmplus::ClassClosure*)AvmThunkUnbox_OBJECT(avmplus::ClassClosure*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::_getSamples(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler__getSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler__getSamples_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
double native_script_function_flash_sampler_getSampleCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = native_script_function_flash_sampler_getSampleCount_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
        , argoff3 = argoff2 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmplus::QNameObject* arg2 = (avmplus::QNameObject*)AvmThunkUnbox_OBJECT(avmplus::QNameObject*, argv[argoff2]);
    uint32_t arg3 = AvmThunkUnbox_UINT(uint32_t, argv[argoff3]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , arg1
        , arg2
        , arg3
    );
    return double(ret);
}
double native_script_function_flash_sampler__getInvocationCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = native_script_function_flash_sampler__getInvocationCount_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmplus::QNameObject* arg2 = (avmplus::QNameObject*)AvmThunkUnbox_OBJECT(avmplus::QNameObject*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = SamplerScript::isGetterSetter(obj
        , arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_isGetterSetter_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_isGetterSetter_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::ArrayObject* const ret = SamplerScript::getLexicalScopes(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_getLexicalScopes_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getSavedThis(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getSavedThis_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_getSavedThis_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = SamplerScript::getMasterString(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getMasterString_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = native_script_function_flash_sampler_getMasterString_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_INT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    int32_t arg2 = (argc < 2 ? 2 : AvmThunkUnbox_INT(int32_t, argv[argoff2]));
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->setLevel(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_setLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_trace_Trace_setLevel_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = (argc < 1 ? 2 : AvmThunkUnbox_INT(int32_t, argv[argoff1]));
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_getLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_trace_Trace_getLevel_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->setListener(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_setListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_trace_Trace_setListener_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom flash_trace_Trace_getListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_trace_Trace_getListener_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double avmplus_MI_plus_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    double arg1 = AvmThunkUnbox_DOUBLE(double, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::MIObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::MIObject*, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        arg1
    );
    return double(ret);
}
double avmplus_MI_plus_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = avmplus_MI_plus_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->exit(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_exit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_exit_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    int32_t const ret = obj->exec(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_exec_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_exec_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_getAvmplusVersion_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_getAvmplusVersion_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_getFeatures_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_getFeatures_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_getRunmode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_getRunmode_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ArrayObject* arg1 = (avmplus::ArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ArrayObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->trace(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_trace_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_trace_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->write(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_write_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_debugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_debugger_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_isDebugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_isDebugger_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double avmplus_System_getNanosecondTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    double const ret = obj->getNanosecondTimer();
    return double(ret);
}
double avmplus_System_getNanosecondTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = avmplus_System_getNanosecondTimer_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_getTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_getTimer_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_private_getArgv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_private_getArgv_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_readLine_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_readLine_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
double avmplus_System_totalMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = avmplus_System_totalMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
double avmplus_System_freeMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = avmplus_System_freeMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
double avmplus_System_privateMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    double retVal = avmplus_System_privateMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_forceFullCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_forceFullCollection_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_queueCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_queueCollection_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_ns_example_nstest_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_ns_example_nstest_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    bool const ret = obj->isGlobal(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_isGlobal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_isGlobal_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_swfVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_swfVersion_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
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
avmplus::Atom avmplus_System_apiVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_apiVersion_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::XMLObject* arg1 = (avmplus::XMLObject*)AvmThunkUnbox_OBJECT(avmplus::XMLObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->disposeXML(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_disposeXML_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_disposeXML_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_deopt_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->deopt(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_deopt_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_deopt_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_pauseForGCIfCollectionImminent_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    double arg1 = (argc < 1 ? 0.75 : AvmThunkUnbox_DOUBLE(double, argv[argoff1]));
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->pauseForGCIfCollectionImminent(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_pauseForGCIfCollectionImminent_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_pauseForGCIfCollectionImminent_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_is64bit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    bool const ret = obj->is64bit();
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_is64bit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_is64bit_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_isIntptr_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    bool const ret = obj->isIntptr(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_isIntptr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_isIntptr_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_System_canonicalizeNumber_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->canonicalizeNumber(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_canonicalizeNumber_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_canonicalizeNumber_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_File_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    bool const ret = obj->exists(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_File_exists_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_File_exists_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_File_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    avmplus::String* const ret = obj->read(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_File_read_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_File_read_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_File_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::String* arg2 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    obj->write(
        arg1
        , arg2
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_File_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_File_write_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_File_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    avmplus::ByteArrayObject* const ret = obj->readByteArray(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_File_readByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_File_readByteArray_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom avmplus_File_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::ByteArrayObject* arg2 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    bool const ret = obj->writeByteArray(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_File_writeByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_File_writeByteArray_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}

class SlotOffsetsAndAsserts
{
public:
    #ifdef DEBUG
    static uint32_t getSlotOffset(Traits* t, int nameId);
    static uint32_t getMethodIndex(Traits* t, int nameId);
    static uint32_t getGetterIndex(Traits* t, int nameId);
    static uint32_t getSetterIndex(Traits* t, int nameId);
    #endif // DEBUG
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
        kSlotsOffset_avmplus_NativeBaseExtender1Class = 0,
        kSlotsOffset_avmplus_NativeBaseExtender1Object = offsetof(avmplus::NativeBaseExtender1Object, m_slots_NativeBaseExtender1Object),
        kSlotsOffset_avmplus_NativeBaseExtender2Class = 0,
        kSlotsOffset_avmplus_NativeBaseExtender2Object = offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object),
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
        kSlotsOffset_avmplus_EndianClass = offsetof(avmplus::EndianClass, m_slots_EndianClass),
        kSlotsOffset_avmplus_EndianObject = 0,
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
    static void check_avmplus_NativeBaseExtender1Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_NativeBaseExtender2Class(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DomainClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_StackFrameClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_ClassFactoryClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_NewObjectSampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DeleteObjectSampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_TraceClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_EndianClass(Traits* ctraits, Traits* itraits);
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
    AvmAssert(getSlotOffset(ctraits, 41) == (offsetof(avmshell::SystemClass, m_slots_SystemClass) + offsetof(avmshell_SystemClassSlots, m_argv)));
    AvmAssert(getMethodIndex(ctraits, 29) == 5); // exit
    AvmAssert(getMethodIndex(ctraits, 30) == 6); // exec
    AvmAssert(getMethodIndex(ctraits, 31) == 7); // getAvmplusVersion
    AvmAssert(getMethodIndex(ctraits, 32) == 8); // getFeatures
    AvmAssert(getMethodIndex(ctraits, 33) == 9); // getRunmode
    AvmAssert(getMethodIndex(ctraits, 34) == 10); // trace
    AvmAssert(getMethodIndex(ctraits, 35) == 11); // write
    AvmAssert(getMethodIndex(ctraits, 36) == 12); // debugger
    AvmAssert(getMethodIndex(ctraits, 37) == 13); // isDebugger
    AvmAssert(getMethodIndex(ctraits, 38) == 14); // getNanosecondTimer
    AvmAssert(getMethodIndex(ctraits, 39) == 15); // getTimer
    AvmAssert(getMethodIndex(ctraits, 40) == 16); // private::getArgv
    AvmAssert(getMethodIndex(ctraits, 42) == 17); // readLine
    AvmAssert(getGetterIndex(ctraits, 43) == 18); // totalMemory
    AvmAssert(getGetterIndex(ctraits, 44) == 20); // freeMemory
    AvmAssert(getGetterIndex(ctraits, 45) == 22); // privateMemory
    AvmAssert(getMethodIndex(ctraits, 46) == 24); // forceFullCollection
    AvmAssert(getMethodIndex(ctraits, 47) == 25); // queueCollection
    AvmAssert(getMethodIndex(ctraits, 48) == 26); // http://www.example.com::nstest
    AvmAssert(getMethodIndex(ctraits, 49) == 27); // isGlobal
    AvmAssert(getGetterIndex(ctraits, 50) == 28); // swfVersion
    AvmAssert(getGetterIndex(ctraits, 51) == 30); // apiVersion
    AvmAssert(getMethodIndex(ctraits, 52) == 32); // disposeXML
    AvmAssert(getMethodIndex(ctraits, 53) == 33); // deopt
    AvmAssert(getMethodIndex(ctraits, 54) == 34); // pauseForGCIfCollectionImminent
    AvmAssert(getMethodIndex(ctraits, 55) == 35); // is64bit
    AvmAssert(getMethodIndex(ctraits, 56) == 36); // isIntptr
    AvmAssert(getMethodIndex(ctraits, 57) == 37); // canonicalizeNumber
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
    AvmAssert(getSlotOffset(ctraits, 72) == (offsetof(avmplus::ShellCoreFriend1Class, m_slots_ShellCoreFriend1Class) + offsetof(avmplus_ShellCoreFriend1ClassSlots, m_private_foo)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend2Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) == kSlotsOffset_avmplus_ShellCoreFriend2Class);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ShellCoreFriend2Class) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 75) == (offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) + offsetof(avmplus_ShellCoreFriend2ClassSlots, m_private_bar)));
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
    AvmAssert(getSlotOffset(itraits, 81) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var)));
    AvmAssert(getSlotOffset(itraits, 82) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_0)));
    AvmAssert(getSlotOffset(itraits, 83) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 84) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5)));
    AvmAssert(getSlotOffset(itraits, 85) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_1)));
    AvmAssert(getSlotOffset(itraits, 86) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0_32)));
    AvmAssert(getSlotOffset(itraits, 87) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 88) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 89) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 90) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0_32_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 91) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const)));
    AvmAssert(getSlotOffset(itraits, 92) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_0)));
    AvmAssert(getSlotOffset(itraits, 93) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 94) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5)));
    AvmAssert(getSlotOffset(itraits, 95) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_1)));
    AvmAssert(getSlotOffset(itraits, 96) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0_32)));
    AvmAssert(getSlotOffset(itraits, 97) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 98) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 99) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 100) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0_32_AIR_1_0_FP_10_0)));
    AvmAssert(getMethodIndex(itraits, 101) == 3); // public_function
    AvmAssert(getMethodIndex(itraits, 102) == 4); // public_function_AIR_1_0
    AvmAssert(getMethodIndex(itraits, 103) == 5); // public_function_FP_10_0
    AvmAssert(getMethodIndex(itraits, 104) == 6); // public_function_AIR_1_5
    AvmAssert(getMethodIndex(itraits, 105) == 7); // public_function_AIR_1_5_1
    AvmAssert(getMethodIndex(itraits, 106) == 8); // public_function_FP_10_0_32
    AvmAssert(getMethodIndex(itraits, 107) == 9); // public_function_AIR_1_5_2
    AvmAssert(getMethodIndex(itraits, 108) == 10); // public_function_AIR_1_0_FP_10_0
    AvmAssert(getMethodIndex(itraits, 109) == 11); // public_function_AIR_1_5_1_FP_10_0_AIR_1_5_2
    AvmAssert(getMethodIndex(itraits, 110) == 12); // public_function_FP_10_0_32_AIR_1_0_FP_10_0
    AvmAssert(getGetterIndex(itraits, 111) == 13); // public_getset
    AvmAssert(getGetterIndex(itraits, 112) == 15); // public_getset_AIR_1_0
    AvmAssert(getGetterIndex(itraits, 113) == 17); // public_getset_FP_10_0
    AvmAssert(getGetterIndex(itraits, 114) == 19); // public_getset_AIR_1_5
    AvmAssert(getGetterIndex(itraits, 115) == 21); // public_getset_AIR_1_5_1
    AvmAssert(getGetterIndex(itraits, 116) == 23); // public_getset_FP_10_0_32
    AvmAssert(getGetterIndex(itraits, 117) == 25); // public_getset_AIR_1_5_2
    AvmAssert(getGetterIndex(itraits, 118) == 27); // public_getset_AIR_1_0_FP_10_0
    AvmAssert(getGetterIndex(itraits, 119) == 29); // public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2
    AvmAssert(getGetterIndex(itraits, 120) == 31); // public_getset_FP_10_0_32_AIR_1_0_FP_10_0
    AvmAssert(getSetterIndex(itraits, 111) == 14); // public_getset
    AvmAssert(getSetterIndex(itraits, 112) == 16); // public_getset_AIR_1_0
    AvmAssert(getSetterIndex(itraits, 113) == 18); // public_getset_FP_10_0
    AvmAssert(getSetterIndex(itraits, 114) == 20); // public_getset_AIR_1_5
    AvmAssert(getSetterIndex(itraits, 115) == 22); // public_getset_AIR_1_5_1
    AvmAssert(getSetterIndex(itraits, 116) == 24); // public_getset_FP_10_0_32
    AvmAssert(getSetterIndex(itraits, 117) == 26); // public_getset_AIR_1_5_2
    AvmAssert(getSetterIndex(itraits, 118) == 28); // public_getset_AIR_1_0_FP_10_0
    AvmAssert(getSetterIndex(itraits, 119) == 30); // public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2
    AvmAssert(getSetterIndex(itraits, 120) == 32); // public_getset_FP_10_0_32_AIR_1_0_FP_10_0
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
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NativeBaseExtender1Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::NativeBaseExtender1Object, m_slots_NativeBaseExtender1Object) == kSlotsOffset_avmplus_NativeBaseExtender1Object);
    MMGC_STATIC_ASSERT(offsetof(avmplus::NativeBaseExtender1Object, m_slots_NativeBaseExtender1Object) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::NativeBaseExtender1Object) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 147) == (offsetof(avmplus::NativeBaseExtender1Object, m_slots_NativeBaseExtender1Object) + offsetof(avmplus_NativeBaseExtender1ObjectSlots, m_private_foo)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NativeBaseExtender2Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) == kSlotsOffset_avmplus_NativeBaseExtender2Object);
    MMGC_STATIC_ASSERT(offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::NativeBaseExtender2Object) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 149) == (offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) + offsetof(avmplus_NativeBaseExtender2ObjectSlots, m_private_foo)));
    AvmAssert(getSlotOffset(itraits, 150) == (offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) + offsetof(avmplus_NativeBaseExtender2ObjectSlots, m_private_foo1)));
    AvmAssert(getSlotOffset(itraits, 151) == (offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) + offsetof(avmplus_NativeBaseExtender2ObjectSlots, m_private_foo2)));
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
    AvmAssert(getSlotOffset(itraits, 371) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(itraits, 372) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(itraits, 373) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(itraits, 374) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_scriptID)));
    AvmAssert(getMethodIndex(itraits, 375) == 3); // toString
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) == kSlotsOffset_avmplus_SampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 377) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(itraits, 378) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ClassFactoryClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) == kSlotsOffset_avmplus_ClassFactoryClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ClassFactoryClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 384) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_StackFrameClass)));
    AvmAssert(getSlotOffset(ctraits, 385) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_SampleClass)));
    AvmAssert(getSlotOffset(ctraits, 386) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_DeleteObjectSampleClass)));
    AvmAssert(getSlotOffset(ctraits, 387) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_NewObjectSampleClass)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NewObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) == kSlotsOffset_avmplus_NewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 389) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 390) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_type)));
    AvmAssert(getGetterIndex(itraits, 391) == 3); // object
    AvmAssert(getGetterIndex(itraits, 392) == 5); // size
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DeleteObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == kSlotsOffset_avmplus_DeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 389) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 392) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_TraceClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) == kSlotsOffset_avmplus_TraceClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 428) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(ctraits, 429) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(ctraits, 430) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 431) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(ctraits, 432) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 433) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(ctraits, 434) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_LISTENER)));
    AvmAssert(getMethodIndex(ctraits, 435) == 5); // setLevel
    AvmAssert(getMethodIndex(ctraits, 436) == 6); // getLevel
    AvmAssert(getMethodIndex(ctraits, 437) == 7); // setListener
    AvmAssert(getMethodIndex(ctraits, 438) == 8); // getListener
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_EndianClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) == kSlotsOffset_avmplus_EndianClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::EndianClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 444) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_BIG_ENDIAN)));
    AvmAssert(getSlotOffset(ctraits, 445) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_LITTLE_ENDIAN)));
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
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getNanosecondTimer, avmshell::SystemClass::getNanosecondTimer)
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
        AVMTHUNK_NATIVE_METHOD(avmplus_System_deopt, avmshell::SystemClass::deopt)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_pauseForGCIfCollectionImminent, avmshell::SystemClass::pauseForGCIfCollectionImminent)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_is64bit, avmshell::SystemClass::is64bit)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isIntptr, avmshell::SystemClass::isIntptr)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_canonicalizeNumber, avmshell::SystemClass::canonicalizeNumber)
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
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeBaseExtender1, NativeBaseExtender1Class, avmplus::NativeBaseExtender1Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NativeBaseExtender1Class, avmplus::NativeBaseExtender1Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NativeBaseExtender1Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmshell_NativeBaseExtender2, NativeBaseExtender2Class, avmplus::NativeBaseExtender2Class, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NativeBaseExtender2Class, avmplus::NativeBaseExtender2Object, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NativeBaseExtender2Object, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, avmplus::DomainClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DomainClass, avmplus::DomainObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DomainObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, avmplus::StackFrameClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackFrameClass, avmplus::StackFrameObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackFrameObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, avmplus::SampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SampleClass, avmplus::SampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_ClassFactory, ClassFactoryClass, avmplus::ClassFactoryClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ClassFactoryClass, avmplus::ClassFactoryObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ClassFactoryObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, avmplus::NewObjectSampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NewObjectSampleClass, avmplus::NewObjectSampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NewObjectSampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, avmplus::DeleteObjectSampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DeleteObjectSampleClass, avmplus::DeleteObjectSampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DeleteObjectSampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, avmplus::TraceClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_TraceClass, avmplus::TraceObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_TraceObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Endian, EndianClass, avmplus::EndianClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EndianClass, avmplus::EndianObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EndianObject, false, false, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[15947] = {
  16,   0,  46,   0,   8,  42, 101,   0,   2,   1,   3,   4,   0,   8,   0,   0,
   0,   0,   0,   0, 232,  63,   0,   0,   0,   0,   0,   0, 240,  63,   0,   0,
   0,   0,   0,   0,   0,  64,   0,   0,   0,   0,   0,   0,   8,  64,   0,   0,
   0,   0,   0,   0,  16,  64,   0,   0,   0,   0,   0,   0,  20,  64,   0,   0,
   0,   0,   0,   0,  24,  64, 230,   2,   0,   4, 118, 111, 105, 100,   7,  66,
 111, 111, 108, 101,  97, 110,   6,  83, 121, 115, 116, 101, 109,  19, 115, 104,
 101, 108, 108,  95, 116, 111, 112, 108, 101, 118, 101, 108,  46,  97, 115,  36,
  49,   7,  97, 118, 109, 112, 108, 117, 115,   5, 100, 101, 111, 112, 116,   8,
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
  98, 117, 103, 103, 101, 114,  18, 103, 101, 116,  78,  97, 110, 111, 115, 101,
  99, 111, 110, 100,  84, 105, 109, 101, 114,  11, 116, 111, 116,  97, 108,  77,
 101, 109, 111, 114, 121,  10, 102, 114, 101, 101,  77, 101, 109, 111, 114, 121,
  13, 112, 114, 105, 118,  97, 116, 101,  77, 101, 109, 111, 114, 121,  19, 102,
 111, 114,  99, 101,  70, 117, 108, 108,  67, 111, 108, 108, 101,  99, 116, 105,
 111, 110,  15, 113, 117, 101, 117, 101,  67, 111, 108, 108, 101,  99, 116, 105,
 111, 110,  22, 104, 116, 116, 112,  58,  47,  47, 119, 119, 119,  46, 101, 120,
  97, 109, 112, 108, 101,  46,  99, 111, 109,   6, 110, 115, 116, 101, 115, 116,
   8, 105, 115,  71, 108, 111,  98,  97, 108,  10, 115, 119, 102,  86, 101, 114,
 115, 105, 111, 110,  10,  97, 112, 105,  86, 101, 114, 115, 105, 111, 110,  10,
 100, 105, 115, 112, 111, 115, 101,  88,  77,  76,  30, 112,  97, 117, 115, 101,
  70, 111, 114,  71,  67,  73, 102,  67, 111, 108, 108, 101,  99, 116, 105, 111,
 110,  73, 109, 109, 105, 110, 101, 110, 116,   7, 105, 115,  54,  52,  98, 105,
 116,   8, 105, 115,  73, 110, 116, 112, 116, 114,  18,  99,  97, 110, 111, 110,
 105,  99,  97, 108, 105, 122, 101,  78, 117, 109,  98, 101, 114,  12,  97, 118,
 109, 112, 108, 117, 115,  58,  70, 105, 108, 101,  11, 102, 108,  97, 115, 104,
  46, 117, 116, 105, 108, 115,   9,  66, 121, 116, 101,  65, 114, 114,  97, 121,
   6, 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100,  13, 114, 101,  97,
 100,  66, 121, 116, 101,  65, 114, 114,  97, 121,  14, 119, 114, 105, 116, 101,
  66, 121, 116, 101,  65, 114, 114,  97, 121,   4,  70, 105, 108, 101,  21,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  65,  98, 115, 116, 114,  97,  99, 116,
  66,  97, 115, 101,   8,  97, 118, 109, 115, 104, 101, 108, 108,  12,  65,  98,
 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  23,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97,
 115, 101,  14,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115,
 101,  31,  97, 118, 109, 115, 104, 101, 108, 108,  58,  65,  98, 115, 116, 114,
  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115,
 101,  22,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,
  99, 116, 101, 100,  66,  97, 115, 101,  18,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  67, 104, 101,  99, 107,  66,  97, 115, 101,   9,  67, 104, 101,  99,
 107,  66,  97, 115, 101,  19,  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,
  97, 116, 105, 118, 101,  66,  97, 115, 101,  10,  78,  97, 116, 105, 118, 101,
  66,  97, 115, 101,  22,  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97,
 116, 105, 118, 101,  66,  97, 115, 101,  65,  83,  51,  13,  78,  97, 116, 105,
 118, 101,  66,  97, 115, 101,  65,  83,  51,  25,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  83, 104, 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101,
 110, 100,  49,  16,  83, 104, 101, 108, 108,  67, 111, 114, 101,  70, 114, 105,
 101, 110, 100,  49,  25,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 104,
 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101, 110, 100,  50,  16,  83,
 104, 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101, 110, 100,  50,  25,
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
  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  28,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  66,  97,
 115, 101,  69, 120, 116, 101, 110, 100, 101, 114,  49,  19,  78,  97, 116, 105,
 118, 101,  66,  97, 115, 101,  69, 120, 116, 101, 110, 100, 101, 114,  49,  28,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  66,
  97, 115, 101,  69, 120, 116, 101, 110, 100, 101, 114,  50,   4, 102, 111, 111,
  49,   4, 102, 111, 111,  50,  19,  78,  97, 116, 105, 118, 101,  66,  97, 115,
 101,  69, 120, 116, 101, 110, 100, 101, 114,  50,  11,  65,  80,  73,  95,  65,
  73,  82,  95,  49,  95,  48,  11,  65,  80,  73,  95,  70,  80,  95,  49,  48,
  95,  48,  11,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  13,  65,
  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  14,  65,  80,  73,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  13,  65,  80,  73,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  50,  10, 110, 115,  95, 101, 120,  97,
 109, 112, 108, 101,   6, 110,  97, 116, 105, 118, 101,   3,  99, 108, 115,  19,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  67, 108,
  97, 115, 115,   8, 105, 110, 115, 116,  97, 110,  99, 101,  20,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,  98, 106, 101,  99,
 116,   7, 109, 101, 116, 104, 111, 100, 115,  24,  58,  58,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  58,  77,  73,  79,  98, 106, 101,  99, 116,  73, 109,
 112, 108,  10,  97, 118, 109, 112, 108, 117, 115, 238, 138, 148,  23,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 121, 115, 116, 101, 109,
  67, 108,  97, 115, 115,   7,  99, 108,  97, 115, 115, 103,  99,   5, 101, 120,
  97,  99, 116,   4,  97, 117, 116, 111,   9,  99, 111, 110, 115, 116, 114, 117,
  99, 116,   4, 110, 111, 110, 101,  21,  58,  58,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  58,  70, 105, 108, 101,  67, 108,  97, 115, 115,  11,  97, 118,
 109, 115, 104, 101, 108, 108, 238, 138, 148,  29,  58,  58,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97,
 115, 101,  67, 108,  97, 115, 115,  30,  58,  58,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,
  79,  98, 106, 101,  99, 116,   2, 103,  99,   8,  97,  98, 115, 116, 114,  97,
  99, 116,  45,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,
  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,
  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  67, 108,  97, 115, 115,
  46,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116,
 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115,
 116, 114,  97,  99, 116,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  31,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  82, 101, 115, 116,
 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  32,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  82, 101, 115, 116,
 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,
  10, 114, 101, 115, 116, 114, 105,  99, 116, 101, 100,  47,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,
  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116,
 101, 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  48,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,
  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116,
 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  39,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,  99,
 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  67,
 108,  97, 115, 115,  40,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99,
 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  19,  97,  98,
 115, 116, 114,  97,  99, 116,  45, 114, 101, 115, 116, 114, 105,  99, 116, 101,
 100,  55,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97,
 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98,
 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,
  66,  97, 115, 101,  67, 108,  97, 115, 115,  56,  58,  58,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99,
 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101,
 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,
  99, 116,  26,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67,
 104, 101,  99, 107,  66,  97, 115, 101,  67, 108,  97, 115, 115,  27,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67, 104, 101,  99, 107,  66,
  97, 115, 101,  79,  98, 106, 101,  99, 116,   5,  99, 104, 101,  99, 107,  27,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105,
 118, 101,  66,  97, 115, 101,  67, 108,  97, 115, 115,  28,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  66,  97,
 115, 101,  79,  98, 106, 101,  99, 116,   6, 102, 114, 105, 101, 110, 100,  19,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 104, 101, 108, 108,  67,
 111, 114, 101,  43,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 104,
 101, 108, 108,  67, 111, 114, 101,  44,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  83, 104, 101, 108, 108,  84, 111, 112, 108, 101, 118, 101, 108,  15,
 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109, 238, 138, 148,  14,
 103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,  97, 109, 101,   5, 112,
 114, 105, 110, 116,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 149,
  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 150,  11,  97, 118, 109,
 115, 104, 101, 108, 108, 238, 138, 151,  11,  97, 118, 109, 115, 104, 101, 108,
 108, 238, 138, 152,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 153,
  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 154,  14,  97, 118, 109,
 112, 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,   4, 105, 110, 105, 116,
  11,  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,  50,   9, 108, 111,  97,
 100,  66, 121, 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,  77,  65,  73,
  78,  95,  77,  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,  84,  72,   4,
 108, 111,  97, 100,  12, 100, 111, 109,  97, 105, 110,  77, 101, 109, 111, 114,
 121,  11,  68, 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,  12,  68, 111,
 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,   8,  70, 117, 110,  99, 116,
 105, 111, 110,   5,  81,  78,  97, 109, 101,  19,  95, 103, 101, 116,  73, 110,
 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  12,  83,  97,
 109, 112, 108, 101, 114,  46,  97, 115,  36,  51,  13, 102, 108,  97, 115, 104,
  46, 115,  97, 109, 112, 108, 101, 114,  11,  95, 103, 101, 116,  83,  97, 109,
 112, 108, 101, 115,   1, 102,   1, 101,   3, 114, 101, 116,  19,  95, 115, 101,
 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,
   7, 119, 114,  97, 112, 112, 101, 114,  24, 102, 108,  97, 115, 104,  46, 115,
  97, 109, 112, 108, 101, 114,  58,  83, 116,  97,  99, 107,  70, 114,  97, 109,
 101,   4, 110,  97, 109, 101,   2,  40,  41,   4, 102, 105, 108, 101,   1,  91,
   1,  58,   4, 108, 105, 110, 101,   1,  93,   8, 115,  99, 114, 105, 112, 116,
  73,  68,   8, 116, 111,  83, 116, 114, 105, 110, 103,  10,  83, 116,  97,  99,
 107,  70, 114,  97, 109, 101,  20, 102, 108,  97, 115, 104,  46, 115,  97, 109,
 112, 108, 101, 114,  58,  83,  97, 109, 112, 108, 101,   4, 116, 105, 109, 101,
   5, 115, 116,  97,  99, 107,   6,  83,  97, 109, 112, 108, 101,  26, 102, 108,
  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  67, 108,  97, 115,
 115,  70,  97,  99, 116, 111, 114, 121,  15,  83, 116,  97,  99, 107,  70, 114,
  97, 109, 101,  67, 108,  97, 115, 115,  11,  83,  97, 109, 112, 108, 101,  67,
 108,  97, 115, 115,  23,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99,
 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  20,  78, 101, 119,
  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115,
 115,  12,  67, 108,  97, 115, 115,  70,  97,  99, 116, 111, 114, 121,  29, 102,
 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  78, 101, 119,
  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,   2, 105, 100,   4,
 116, 121, 112, 101,   6, 111,  98, 106, 101,  99, 116,   4, 115, 105, 122, 101,
  15,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,
  32, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  68,
 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108,
 101,  18,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97,
 109, 112, 108, 101,  16, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108,
 101, 114, 238, 138, 148,  21,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,
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
 101, 116,  83,  97, 109, 112, 108, 101, 115,  26,  83,  97, 109, 112, 108, 101,
 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 103, 101, 116,  83,  97, 109,
 112, 108, 101, 115,  14, 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111,
 117, 110, 116,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58, 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110,
 116,  18, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67,
 111, 117, 110, 116,  24, 103, 101, 116,  83, 101, 116, 116, 101, 114,  73, 110,
 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101,
 116,  71, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111,
 110,  67, 111, 117, 110, 116,  34,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58,  95, 103, 101, 116,  73, 110, 118, 111,  99,  97,
 116, 105, 111, 110,  67, 111, 117, 110, 116,  14, 105, 115,  71, 101, 116, 116,
 101, 114,  83, 101, 116, 116, 101, 114,  29,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 105, 115,  71, 101, 116, 116, 101, 114,
  83, 101, 116, 116, 101, 114,  16, 103, 101, 116,  76, 101, 120, 105,  99,  97,
 108,  83,  99, 111, 112, 101, 115,  31,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  76, 101, 120, 105,  99,  97,
 108,  83,  99, 111, 112, 101, 115,  12, 103, 101, 116,  83,  97, 118, 101, 100,
  84, 104, 105, 115,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58, 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,
  15, 103, 101, 116,  77,  97, 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,
  30,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 103, 101, 116,  77,  97, 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,   3,
  54,  56,  52,  17, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,  58,
  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,  77,  69,  84,  72,  79,  68,
  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  87,  73,  84,  72,  95,  65,
  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  65,  78,  68,  95,
  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,  79,  68,  83,  95,  65,  78,
  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,  84,  72,  95,  65,  82,  71,
  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,  84,  69,  78,  69,  82,   8,
 115, 101, 116,  76, 101, 118, 101, 108,   8, 103, 101, 116,  76, 101, 118, 101,
 108,  11, 115, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 103, 101,
 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 102, 108,  97, 115, 104,  46,
 116, 114,  97,  99, 101,   5,  84, 114,  97,  99, 101,  10,  84, 114,  97,  99,
 101,  46,  97, 115,  36,  52,  14, 102, 108,  97, 115, 104,  46, 116, 114,  97,
  99, 101, 238, 138, 148,  10,  84, 114,  97,  99, 101,  67, 108,  97, 115, 115,
  18, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  69, 110, 100,
 105,  97, 110,  10,  66,  73,  71,  95,  69,  78,  68,  73,  65,  78,   9,  98,
 105, 103,  69, 110, 100, 105,  97, 110,  13,  76,  73,  84,  84,  76,  69,  95,
  69,  78,  68,  73,  65,  78,  12, 108, 105, 116, 116, 108, 101,  69, 110, 100,
 105,  97, 110,   6,  69, 110, 100, 105,  97, 110,  11,  69, 110, 100, 105,  97,
 110,  46,  97, 115,  36,  53,  14, 102, 108,  97, 115, 104,  46, 117, 116, 105,
 108, 115, 238, 138, 148, 124,  22,   1,   5,   5,  23,   1,  22,   6,  23,   6,
   8,  18,   5,  21,  22,  22,  24,  21,   5,  25,  24,  25,   5,  29,  24,  29,
  26,  29,  26,  24,   8,  52,   5,  62,  22,  63,  24,  62,   5,  70,  22,  71,
  24,  70,   5,  73,  24,  73,   5,  75,  24,  75,   5,  77,  24,  77,   5,  79,
  24,  79,   5,  81,  24,  81,   5,  83,  24,  83,   5,  85,  24,  85,   5,  87,
  22,  89,  23,  89,  24,  87,  26,  87,   5,  92,  22,  94,  22,  98,  22, 101,
  22, 104,  22, 107,  22, 110,  24,  92,   5, 147,   1,  24, 147,   1,   5, 149,
   1,  24, 149,   1,   5, 151,   1,  24, 151,   1,   5, 153,   1,  24, 153,   1,
   5, 155,   1,  24, 155,   1,   5, 157,   1,  24, 157,   1,   5, 159,   1,  24,
 159,   1,   5, 161,   1,  24, 161,   1,   5, 163,   1,  24, 163,   1,   5, 175,
   1,  24, 175,   1,   5, 177,   1,  24, 177,   1,   5, 179,   1,  24, 179,   1,
   5, 181,   1,  24, 181,   1,   5, 183,   1,  24, 183,   1,   5, 185,   1,  24,
 185,   1,   5, 187,   1,  24, 187,   1,   5, 189,   1,  24, 189,   1,  23,  71,
  22, 207,   1,  22, 215,   1,  22, 240,   1,  22, 243,   1,  22, 244,   1,  22,
 245,   1,  22, 246,   1,  22, 247,   1,  22, 248,   1,   5, 249,   1,   5, 251,
   1,  24, 249,   1,  26, 249,   1,   5, 133,   2,  22, 134,   2,  23, 134,   2,
   5, 141,   2,  24, 141,   2,  26, 141,   2,   5, 152,   2,  24, 152,   2,   5,
 156,   2,  24, 156,   2,   5, 162,   2,  24, 162,   2,   5, 168,   2,  24, 168,
   2,  22, 170,   2,   5, 205,   2,  22, 217,   2,  24, 205,   2,   5, 219,   2,
  23, 217,   2,  22, 220,   2,   5, 222,   2,  24, 222,   2,   5, 228,   2,  23,
  63,  22, 229,   2,  51,   4,   1,   2,   3,   4,   4,   1,   2,   4,   5,   1,
   6,   1,   8,   8,   1,   2,   4,   5,  12,  13,  14,  15,   1,  12,   1,  16,
   1,  33,   1,  35,   9,   1,   2,   4,  15,  37,  38,  39,  40,  41,   1,  43,
   1,  44,   1,  45,   1,  46,   1,  47,   1,  48,   2,  43,  44,   3,  44,  46,
  48,   3,  43,  44,  47,   1,  80,   1,  82,   1,   5,   1,   4,   1,  21,   4,
   1,   2,  21,  84,   1,  38,   5,   1,   2,   4,  38,  39,   1,  85,   1,  86,
   1,  87,   1,  88,   1,  89,   1,  90,   1,  91,   1,  92,   1,  93,   2,  88,
  89,   3,  89,  91,  93,   3,  88,  89,  92,   8,   1,   4,   5,  15,  94,  95,
  96,  97,   1,  94,   4,   1,   4,   5,  95,   4,   1,  98,  99, 100,   1, 100,
   8,   1,  15,  98,  99, 100, 101, 102, 103,   1, 112,   4,   1, 114, 116, 117,
   1, 118,   4,   1,  18, 121, 122,   1, 123, 193,   3,   7,   1,   2,   7,   1,
   3,   9,   4,   1,   9,   7,   1,   9,   8,   1,   7,   1,   9,   9,  10,   1,
   7,   1,  11,   9,  12,   1,   9,  13,   1,   9,  14,   1,   9,  15,   1,   7,
   1,  16,   9,   4,   2,   9,  17,   2,   9,  19,   3,   7,   5,  20,   9,  19,
   4,   7,   5,  23,   7,   1,  24,   7,   1,  26,   9,  27,   4,   7,   5,  28,
   7,   1,  30,   9,  31,   5,   7,   1,  32,   7,   1,  33,   7,   1,  34,   9,
  35,   4,   9,  37,   4,   9,  41,   4,   9,  42,   4,   9,  43,   4,   9,  12,
   4,   9,  44,   4,   9,  17,   4,   9,  45,   4,   9,  46,   4,   9,  10,   4,
   9,  31,   6,   9,  30,   4,   9,   8,   4,   9,  47,   4,   9,  48,   4,   9,
  49,   4,   9,  50,   4,   9,  51,   4,   9,  53,   7,   9,  54,   4,   9,  55,
   4,   9,  56,   4,   9,  57,   4,   9,   7,   4,   9,  58,   4,   9,  59,   4,
   9,  60,   4,   9,  61,   4,   7,   4,   4,   7,  18,  64,   9,  65,   4,   9,
  66,   4,   9,  67,   4,   9,  68,   4,   7,   4,  69,   7,  21,  72,   7,  21,
  74,   7,  21,  76,   7,  21,  78,   7,  21,  80,   7,  21,  82,   7,  33,  36,
   9,  36,   8,   7,  21,  84,   7,  35,  38,   9,  38,   9,   7,  21,  86,   9,
   4,  10,   9,  45,  10,   9,  90,   4,   7,  38,  91,   9,  93,   4,   9,  95,
  11,   9,  99,  12,   9, 102,  13,   9, 105,  14,   9, 108,  15,   9, 111,  16,
   9, 113,  17,   9, 114,  18,   9, 115,  19,   9, 116,   4,   9, 117,  11,   9,
 118,  12,   9, 119,  13,   9, 120,  14,   9, 121,  15,   9, 122,  16,   9, 123,
  17,   9, 124,  18,   9, 125,  19,   9, 126,   4,   9, 127,  11,   9, 128,   1,
  12,   9, 129,   1,  13,   9, 130,   1,  14,   9, 131,   1,  15,   9, 132,   1,
  16,   9, 133,   1,  17,   9, 134,   1,  18,   9, 135,   1,  19,   9, 136,   1,
   4,   9, 137,   1,  11,   9, 138,   1,  12,   9, 139,   1,  13,   9, 140,   1,
  14,   9, 141,   1,  15,   9, 142,   1,  16,   9, 143,   1,  17,   9, 144,   1,
  18,   9, 145,   1,  19,   7,  21, 146,   1,   7,  21, 148,   1,   7,  21, 150,
   1,   7,  21, 152,   1,   7,  21, 154,   1,   7,  21, 156,   1,   7,  21, 158,
   1,   7,  21, 160,   1,   7,  21, 162,   1,   7,  21, 164,   1,   7,  21, 165,
   1,   7,  21, 166,   1,   7,  21, 167,   1,   7,  21, 168,   1,   7,  21, 169,
   1,   7,  21, 170,   1,   7,  21, 171,   1,   7,  21, 172,   1,   7,  21, 173,
   1,   7,  21, 174,   1,   7,  21, 176,   1,   7,  21, 178,   1,   7,  21, 180,
   1,   7,  21, 182,   1,   7,  21, 184,   1,   7,  21, 186,   1,   9,  36,  20,
   7,  21, 188,   1,   9,  36,  21,   9, 190,   1,  21,   9, 191,   1,  21,   7,
  21, 192,   1,   9,  20,  22,   9,  23,  22,   9,  24,   2,   9,  28,  22,   9,
   4,  23,   9,  69,  23,   9,  72,  24,   9,  24,  25,   9, 176,   1,  24,   9,
  72,  25,   9, 178,   1,  24,   9,  74,  24,   9, 180,   1,  24,   9,  74,  25,
   9, 182,   1,  24,   9,  76,  24,   9, 184,   1,  24,   9,  76,  25,   9, 186,
   1,  24,   9,  78,  24,   9,  80,  24,   9, 188,   1,  24,   9,  80,  25,   9,
 192,   1,  24,   9,  82,  24,   9,  84,  24,   9,  86,  24,   9,  91,  26,   9,
  24,  27,   9, 146,   1,  24,   9, 148,   1,  24,   9, 150,   1,  24,   9, 152,
   1,  24,   9, 154,   1,  24,   9, 156,   1,  24,   9, 158,   1,  24,   9, 160,
   1,  24,   9, 162,   1,  24,   9, 164,   1,  24,   9, 165,   1,  24,   9, 166,
   1,  24,   9, 167,   1,  24,   9, 168,   1,  24,   9, 169,   1,  24,   9, 170,
   1,  24,   9, 171,   1,  24,   9, 172,   1,  24,   9, 173,   1,  24,   9, 174,
   1,  24,   9, 193,   1,  24,   7,  21, 193,   1,   9, 194,   1,  24,   7,  21,
 194,   1,   9, 195,   1,  24,   7,  21, 195,   1,   9, 196,   1,  24,   7,  21,
 196,   1,   9, 197,   1,  24,   7,  21, 197,   1,   9, 198,   1,  24,   7,  21,
 198,   1,   9,  93,  24,   7,  21,  93,   9,  95,  24,   7,  21,  95,   9,  99,
  24,   7,  21,  99,   9, 102,  24,   7,  21, 102,   9, 105,  24,   7,  21, 105,
   9, 108,  24,   7,  21, 108,   9, 111,  24,   7,  21, 111,   9, 113,  24,   7,
  21, 113,   9, 114,  24,   7,  21, 114,   9, 115,  24,   7,  21, 115,   9, 116,
  24,   7,  21, 116,   9, 117,  24,   7,  21, 117,   9, 118,  24,   7,  21, 118,
   9, 119,  24,   7,  21, 119,   9, 120,  24,   7,  21, 120,   9, 121,  24,   7,
  21, 121,   9, 122,  24,   7,  21, 122,   9, 123,  24,   7,  21, 123,   9, 124,
  24,   7,  21, 124,   9, 125,  24,   7,  21, 125,   9, 199,   1,  22,   9,   4,
  28,   9,  69,  28,   9,  17,  28,   9,  72,  29,   9, 176,   1,  29,   9, 178,
   1,  29,   9,  74,  29,   9, 180,   1,  29,   9, 182,   1,  29,   9,  76,  29,
   9, 184,   1,  29,   9, 186,   1,  29,   9,  78,  29,   9,  80,  29,   9, 188,
   1,  29,   9, 192,   1,  29,   9,  82,  29,   9,  84,  29,   9,  86,  29,   9,
  91,  30,   9, 241,   1,   4,   9, 242,   1,   4,   9, 193,   1,  29,   9, 194,
   1,  29,   9, 195,   1,  29,   9, 196,   1,  29,   9, 197,   1,  29,   9, 198,
   1,  29,   9,  93,  29,   9,  95,  31,   9,  99,  32,   9, 102,  33,   9, 105,
  34,   9, 108,  35,   9, 111,  36,   9, 113,  37,   9, 114,  38,   9, 115,  39,
   9, 116,  29,   9, 117,  31,   9, 118,  32,   9, 119,  33,   9, 120,  34,   9,
 121,  35,   9, 122,  36,   9, 123,  37,   9, 124,  38,   9, 125,  39,   9, 126,
  29,   9, 127,  31,   9, 128,   1,  32,   9, 129,   1,  33,   9, 130,   1,  34,
   9, 131,   1,  35,   9, 132,   1,  36,   9, 133,   1,  37,   9, 134,   1,  38,
   9, 135,   1,  39,   9, 136,   1,  29,   9, 137,   1,  31,   9, 138,   1,  32,
   9, 139,   1,  33,   9, 140,   1,  34,   9, 141,   1,  35,   9, 142,   1,  36,
   9, 143,   1,  37,   9, 144,   1,  38,   9, 145,   1,  39,   9, 146,   1,  29,
   9, 148,   1,  31,   9, 150,   1,  32,   9, 152,   1,  33,   9, 154,   1,  34,
   9, 156,   1,  35,   9, 158,   1,  36,   9, 160,   1,  37,   9, 162,   1,  38,
   9, 164,   1,  39,   9, 165,   1,  29,   9, 166,   1,  31,   9, 167,   1,  32,
   9, 168,   1,  33,   9, 169,   1,  34,   9, 170,   1,  35,   9, 171,   1,  36,
   9, 172,   1,  37,   9, 173,   1,  38,   9, 174,   1,  39,   7,   4,  13,   9,
 250,   1,  40,   9,  69,  40,   9,  67,  40,   9, 252,   1,  40,   9,  14,   4,
   9, 253,   1,   4,   9, 250,   1,  41,   9, 252,   1,   4,   9,  15,   4,   9,
 254,   1,   4,   9, 255,   1,   4,   9,  13,  23,   9,  24,  42,   9,  13,  28,
   7,   1, 130,   2,   7,   1, 131,   2,   9, 132,   2,  43,   9, 135,   2,  43,
   9, 136,   2,  43,   7,   1, 137,   2,   9, 138,   2,  44,   9, 139,   2,  43,
   9, 136,   2,  44,   9, 140,   2,  44,   9, 142,   2,  45,   9, 144,   2,  45,
   9, 147,   2,  45,   9, 142,   2,   4,   9, 144,   2,   4,   9, 147,   2,   4,
   9, 149,   2,   4,   9, 150,   2,   4,   7,  99, 151,   2,   9, 153,   2,   4,
   9, 154,   2,   4,   7,  99, 155,   2,   7,   1, 157,   2,   7,   1, 158,   2,
   7,   1, 159,   2,   7,   1, 160,   2,   9, 157,   2,   4,   9, 158,   2,   4,
   9, 159,   2,   4,   9, 160,   2,   4,   7, 100, 161,   2,   9, 163,   2,   4,
   9, 164,   2,   4,   9, 165,   2,   4,   9, 166,   2,   4,   7,  99, 167,   2,
   7,  99, 169,   2,   9,  24,  43,   9, 151,   2,  46,   9, 155,   2,  46,   9,
 167,   2,  46,   9, 169,   2,  46,   9, 172,   2,  46,   9, 174,   2,  46,   9,
 176,   2,  46,   9, 178,   2,  46,   9, 180,   2,  46,   9, 182,   2,  46,   9,
 139,   2,  44,   9, 184,   2,  46,   9, 186,   2,  46,   9, 188,   2,  46,   9,
 135,   2,  44,   9, 190,   2,  46,   9, 192,   2,  46,   9, 193,   2,  46,   9,
 194,   2,  46,   9, 132,   2,  44,   9, 196,   2,  46,   9, 198,   2,  46,   9,
 200,   2,  46,   9, 202,   2,  46,   9, 161,   2,  44,   7,   1, 206,   2,   7,
   1, 207,   2,   7,   1, 208,   2,   7,   1, 209,   2,   7,   1, 210,   2,   7,
   1, 211,   2,   7,   1, 212,   2,   9, 206,   2,   4,   9, 207,   2,   4,   9,
 208,   2,   4,   9, 209,   2,   4,   9, 210,   2,   4,   9, 211,   2,   4,   9,
 212,   2,   4,   9, 213,   2,   4,   9, 214,   2,   4,   9, 215,   2,   4,   9,
 216,   2,   4,   7, 114, 218,   2,   9,  24,  47,   9, 218,   2,  48,   7,   1,
 223,   2,   7,   1, 225,   2,   9, 223,   2,   4,   9, 225,   2,   4,   7,  18,
 227,   2,   9,  24,  49,   9, 227,   2,  50, 246,   1,   1,   1,   0,   1,   0,
   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,
   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,
   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   1,   1,   0,
   1,   0,   0,   6,   1,   0,   0,   8,   1,   0,   0,   0,   1,   4,   0,   0,
   1,   4,   1,  13,   6,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   1,  21,  21,   1,  32,   0,   0,   1,   0,
   0,   0,   1,   0,   1,   1,  26,   1,  32,   1,  26,   6,   1,  32,   0,   6,
   1,  32,   0,   6,   1,  32,   0,   6,   1,  32,   1,   1,  27,   1,  32,   1,
   1,   6,   1,  32,   0,   1,   1,  32,   0,   2,   1,  32,   0,  21,   1,  32,
   0,   8,   1,  32,   0,  27,   1,  32,   0,   6,   1,  32,   0,  21,   1,  32,
   0,  21,   1,  32,   0,  21,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,
   0,   1,   1,  32,   1,   2,  20,   1,  32,   0,  26,   1,  32,   0,  26,   1,
  32,   1,   1,  28,   1,  32,   1,   1,  26,   1,  32,   1,   1,  21,   1,  40,
   1,   1,   6,   0,   2,   1,  32,   1,   2,   0,   1,  32,   1,   0,   0,   1,
  32,   0,   0,   1,   0,   0,   0,   1,   0,   1,   2,   6,   1,  32,   1,   6,
   6,   1,  32,   2,   1,   6,   6,   1,  32,   1,  59,   6,   1,  32,   2,   2,
   6,  59,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   6,   1,   0,
   0,   2,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,
   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,
   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   0,   0,
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
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0, 215,   2,   1,  32,   0,   8,   1,  32,   1,   1, 215,   2,   1,
  32,   1,   0, 215,   2,   1,   0,   2,   0,  59,   8,   1,  40,   1,   3,   3,
   1,  13,   6,   1,  32,   2,   0,   6,   8,   1,   8,   1,   3,   3,   0,  59,
   1,  32,   1,   0,  59,   1,  32,   0,   0,   1,   0,   1,   6,   6,   1,  32,
   1,  20, 230,   2,   1,  32,   1,  27, 230,   2,   1,  32,   2,   2,  20, 231,
   2,   1,  32,   3,  21,  20, 231,   2,   8,   1,  32,   2,  21,  20, 231,   2,
   1,   0,   2,  21,  20, 231,   2,   1,   0,   2,  21,  20, 231,   2,   1,   0,
   0,  21,   1,  32,   1,  20,  13,   1,  32,   0,  20,   1,   0,   2,  20,  20,
   2,   1,  40,   1,  10,  10,   1,  21,   0,   1,  32,   1,   1, 230,   2,   1,
  32,   0,   0,   1,   2,   1,   1, 230,   2,   1,   2,   1,   1,   2,   1,  32,
   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,
   0,   0,   1,   0,   0,   6,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,  32,   0,  21,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   2,   0,  26,  26,
   1,  40,   1,   4,   3,   1,  26,  26,   1,  40,   1,   4,   3,   1,   0, 230,
   2,   1,  32,   0, 230,   2,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,  44,  36,   0,  38,
   1,  39,  40,  96,   1,   0,  97,  96,   1,   0, 100,  96,   1,   0, 103,  96,
   1,   0, 106,  96,   1,   0, 109,  96,   1,   0, 112,  96,   2,   0,   0,  97,
 100,  96,   3,   0,   0,   0, 106, 100, 112,  96,   3,   0,   0,   0, 109,  97,
 100, 200,   1,   3, 201,   1, 203,   1, 205,   1, 202,   1, 204,   1, 206,   1,
 200,   1,   4, 201,   1, 209,   1, 205,   1, 212,   1, 208,   1, 210,   1, 211,
   1, 213,   1, 200,   1,   3, 201,   1, 205,   1, 212,   1, 214,   1, 211,   1,
 213,   1, 200,   1,   5, 201,   1, 203,   1, 218,   1, 205,   1, 212,   1, 216,
   1, 217,   1, 210,   1, 211,   1, 219,   1, 200,   1,   4, 201,   1, 203,   1,
 218,   1, 205,   1, 220,   1, 221,   1, 210,   1, 211,   1, 200,   1,   5, 201,
   1, 203,   1, 218,   1, 205,   1, 212,   1, 222,   1, 223,   1, 210,   1, 211,
   1, 224,   1, 200,   1,   4, 201,   1, 203,   1, 218,   1, 205,   1, 225,   1,
 226,   1, 210,   1, 211,   1, 200,   1,   5, 201,   1, 203,   1, 218,   1, 205,
   1, 212,   1, 227,   1, 228,   1, 210,   1, 211,   1, 229,   1, 200,   1,   4,
 201,   1, 203,   1, 218,   1, 205,   1, 230,   1, 231,   1, 210,   1, 211,   1,
 200,   1,   5, 201,   1, 203,   1, 218,   1, 205,   1, 212,   1, 232,   1, 233,
   1, 210,   1, 211,   1, 234,   1, 200,   1,   5, 201,   1, 203,   1, 218,   1,
 205,   1, 212,   1, 235,   1, 236,   1, 210,   1, 211,   1, 200,   1, 200,   1,
   1, 212,   1, 200,   1, 200,   1,   1, 237,   1, 238,   1, 200,   1,   1, 237,
   1, 239,   1, 200,   1,   4, 201,   1, 218,   1, 203,   1, 205,   1, 128,   2,
 210,   1, 129,   2, 211,   1, 200,   1,   3, 201,   1, 203,   1, 205,   1, 160,
   2, 171,   2, 211,   1, 200,   1,   1,   0, 173,   2, 200,   1,   1,   0, 175,
   2, 200,   1,   1,   0, 177,   2, 200,   1,   1,   0, 179,   2, 200,   1,   1,
   0, 181,   2, 200,   1,   1,   0, 183,   2, 200,   1,   1,   0, 185,   2, 200,
   1,   1,   0, 187,   2, 200,   1,   1,   0, 189,   2, 200,   1,   1,   0, 191,
   2, 200,   1,   1,   0, 195,   2, 200,   1,   1,   0, 197,   2, 200,   1,   1,
   0, 199,   2, 200,   1,   1,   0, 201,   2, 200,   1,   1,   0, 203,   2,  96,
   1,   0, 204,   2, 200,   1,   3, 201,   1, 205,   1, 212,   1, 221,   2, 211,
   1, 213,   1,  50,  17,   0,   5,   0,  39,   1,  16,   1,   0,  38,  19,  20,
   9,   9,   0,  42,   1,  18,   1,   0,  41,  23,  20,   9,  11,   0,  45,   1,
  22,   1,   0,  44,  58,  20,   9,  13,   0,  75,   0,  64,  20,   9,  19,   0,
  82,   0,  65,  20,   9,  22,   0,  84,   0,  66,  20,   9,  24,   0,  86,   0,
  67,  20,   9,  26,   0,  88,   0,  68,  20,   9,  28,   0,  90,   0,  69,  20,
   9,  30,   0,  92,   0,  70,  20,   9,  32,   0,  94,   0,  73,  20,   9,  34,
   0,  96,   0,  76,  20,   9,  36,   0,  98,   0,  80,  20,  11,  40,   0, 102,
   0, 121,  20,   9,  49,   0, 134,   1,  50,  81,   0,   0,   2,  11,  11,  82,
  64,   0,   2,  11,  11,   1,   2,  83,  64,   0,   2,  11,  11,   1,   3,  84,
  64,   0,   2,  11,  11,   1,   4,  85,  64,   0,   2,  11,  11,   1,   5,  86,
  64,   0,   2,  11,  11,   1,   6,  87,  64,   0,   2,  11,  11,   1,   7,  88,
  64,   0,   2,  11,  11,   1,   8,  89,  64,   0,   2,  11,  11,   1,   9,  90,
  64,   0,   2,  11,  11,   1,  10,  91,   6,   0,   2,  11,  11,  92,  70,   0,
   2,  11,  11,   1,   2,  93,  70,   0,   2,  11,  11,   1,   3,  94,  70,   0,
   2,  11,  11,   1,   4,  95,  70,   0,   2,  11,  11,   1,   5,  96,  70,   0,
   2,  11,  11,   1,   6,  97,  70,   0,   2,  11,  11,   1,   7,  98,  70,   0,
   2,  11,  11,   1,   8,  99,  70,   0,   2,  11,  11,   1,   9, 100,  70,   0,
   2,  11,  11,   1,  10, 101,   1,   0, 104, 102,  65,   0, 105,   1,   2, 103,
  65,   0, 106,   1,   3, 104,  65,   0, 107,   1,   4, 105,  65,   0, 108,   1,
   5, 106,  65,   0, 109,   1,   6, 107,  65,   0, 110,   1,   7, 108,  65,   0,
 111,   1,   8, 109,  65,   0, 112,   1,   9, 110,  65,   0, 113,   1,  10, 111,
   2,   0, 114, 112,  66,   0, 115,   1,   2, 113,  66,   0, 116,   1,   3, 114,
  66,   0, 117,   1,   4, 115,  66,   0, 118,   1,   5, 116,  66,   0, 119,   1,
   6, 117,  66,   0, 120,   1,   7, 118,  66,   0, 121,   1,   8, 119,  66,   0,
 122,   1,   9, 120,  66,   0, 123,   1,  10, 111,   3,   0, 124, 112,  67,   0,
 125,   1,   2, 113,  67,   0, 126,   1,   3, 114,  67,   0, 127,   1,   4, 115,
  67,   0, 128,   1,   1,   5, 116,  67,   0, 129,   1,   1,   6, 117,  67,   0,
 130,   1,   1,   7, 118,  67,   0, 131,   1,   1,   8, 119,  67,   0, 132,   1,
   1,   9, 120,  67,   0, 133,   1,   1,  10, 122,  20,   9,  51,   0, 136,   1,
   0, 123,  20,   9,  53,   0, 138,   1,   0, 124,  20,   9,  55,   0, 140,   1,
   0, 125,  20,   9,  57,   0, 142,   1,   0, 126,  20,   9,  59,   0, 144,   1,
   0, 127,  20,   9,  61,   0, 146,   1,   0, 128,   1,  20,   9,  63,   0, 148,
   1,   0, 129,   1,  20,   9,  65,   0, 150,   1,   0, 130,   1,  20,   9,  67,
   0, 152,   1,   0, 131,   1,   0,   5,   0, 154,   1,   0, 132,   1,   0,   5,
   0, 156,   1,   0, 133,   1,   0,   5,   0, 158,   1,   0, 134,   1,   0,   5,
   0, 160,   1,   0, 135,   1,   0,   5,   0, 162,   1,   0, 136,   1,   0,   5,
   0, 164,   1,   0, 137,   1,   0,   5,   0, 166,   1,   0, 138,   1,   0,   5,
   0, 168,   1,   0, 139,   1,   0,   5,   0, 170,   1,   0, 140,   1,   0,   5,
   0, 172,   1,   0, 141,   1,  65,   9,  69,   0, 174,   1,   0, 142,   1,  65,
   9,  71,   0, 176,   1,   0, 143,   1,  66,   9,  73,   0, 178,   1,   0, 144,
   1,  66,   9,  75,   0, 180,   1,   0, 145,   1,  67,   9,  77,   0, 182,   1,
   0, 146,   1,  67,   9,  79,   0, 184,   1,   0, 148,   1,  69,   9,  81,   0,
 186,   1,   1, 147,   1,   0,   0,  26,   0, 152,   1,  69,   9,  83,   0, 188,
   1,   3, 149,   1,   0,   0,  26,   0, 150,   1,   0,   0,  26,   0, 151,   1,
   0,   0,  26,   0, 215,   2,  20,   9,  96,   0, 194,   1,   6, 222,   2,   1,
   0, 193,   1, 223,   2,   1,   0, 195,   1, 224,   2,   1,   0, 196,   1, 225,
   2,   1,   0, 197,   1, 226,   2,   2,   0, 198,   1, 226,   2,   3,   0, 199,
   1, 248,   2,  20,  11, 102,   0, 224,   1,   5, 243,   2,   6,   0,   6,   0,
 244,   2,   6,   0,   6,   0, 245,   2,   6,   0,   8,   0, 246,   2,   6,   0,
  21,   0, 247,   2,   1,   0, 223,   1, 251,   2,  20,   9, 105,   0, 226,   1,
   2, 249,   2,   6,   0,  21,   0, 250,   2,   6,   0,  27,   0, 132,   3,  20,
  11, 107,   0, 228,   1,   0, 137,   3, 251,   2,  11, 109,   0, 232,   1,   4,
 133,   3,   6,   0,  21,   0, 134,   3,   6,   0,  13,   0, 135,   3,   2,   0,
 230,   1, 136,   3,   2,   0, 231,   1, 138,   3, 251,   2,  11, 111,   0, 234,
   1,   2, 133,   3,   6,   0,  21,   0, 136,   3,   6,   0,  21,   0, 183,   3,
  20,   9, 115,   0, 241,   1,   0, 190,   3,  20,   9, 120,   0, 244,   1,   0,
  37,   0,  40,   0,  43,   0,  46,  29,  29,  81,   3,  47,   1,   0,  30,  81,
   4,  48,   1,   1,  31,  17,   5,  49,  32,  17,   6,  50,  33,  17,   7,  51,
  34,  17,   8,  52,  35,  17,   9,  53,  36,  17,  10,  54,  37,  17,  11,  55,
  38,  17,  12,  56,  39,  17,  13,  57,  40,  17,  14,  58,  41,   6,   1,  27,
   0,  42,  17,  15,  59,  43,  18,  16,  60,  44,  18,  17,  61,  45,  18,  18,
  62,  46,  17,  19,  63,  47,  17,  20,  64,  48,  17,  21,  65,  49,  17,  22,
  66,  50,  18,  23,  67,  51,  18,  24,  68,  52,  17,  25,  69,  53,  17,  26,
  70,  54,  17,  27,  71,  55,  17,  28,  72,  56,  17,  29,  73,  57,  17,  30,
  74,  76,   5,  60,  17,   3,  77,  61,  17,   4,  78,  35,  17,   5,  79,  62,
  17,   6,  80,  63,  17,   7,  81,  83,   0,  85,   0,  87,   0,  89,   0,  91,
   0,  93,   0,  95,   1,  72,   0,   1,  26,   1,   3,  97,   1,  75,   0,   1,
  26,   2,   3,  99,   2,  79,  18,   3, 100,  37,  18,   4, 101, 103,   0, 135,
   1,   0, 137,   1,   0, 139,   1,   0, 141,   1,   0, 143,   1,   0, 145,   1,
   0, 147,   1,   0, 149,   1,   0, 151,   1,   0, 153,   1,   0, 155,   1,   0,
 157,   1,   0, 159,   1,   0, 161,   1,   0, 163,   1,   0, 165,   1,   0, 167,
   1,   0, 169,   1,   0, 171,   1,   0, 173,   1,   0, 175,   1,   0, 177,   1,
   0, 179,   1,   0, 181,   1,   0, 183,   1,   0, 185,   1,   0, 187,   1,   0,
 190,   1,   2, 220,   2,  18,   3, 191,   1, 221,   2,  18,   4, 192,   1, 222,
   1,   0, 225,   1,   0, 227,   1,   4, 128,   3,   6,   1,  13,   0, 129,   3,
   6,   2,  13,   0, 130,   3,   6,   3,  13,   0, 131,   3,   6,   4,  13,   0,
 229,   1,   0, 233,   1,   0, 236,   1,  11, 172,   3,   6,   1,  26,   3,   3,
 173,   3,   6,   2,  26,   5,   3, 174,   3,   6,   3,  26,   4,   3, 175,   3,
   6,   4,  26,   6,   3, 176,   3,   6,   5,  26,   7,   3, 177,   3,   6,   6,
   0,   5,   3, 178,   3,   6,   7,   0,   4,   3, 179,   3,  17,   3, 237,   1,
 180,   3,  17,   4, 238,   1, 181,   3,  17,   5, 239,   1, 182,   3,  17,   6,
 240,   1, 243,   1,   2, 188,   3,   6,   1,   6, 224,   2,   1, 189,   3,   6,
   2,   6, 226,   2,   1,   5, 200,   1,   1, 229,   2,  68,   0,  42,   1,  25,
 235,   1,  25, 140,   3,   4,   1,  43, 141,   3,   4,   2,  44, 142,   3,  68,
   3,  46,   1,  26, 143,   3,   4,   4,  47, 144,   3,  65,  38, 221,   1,   1,
  27, 145,   3,  65,  39, 220,   1,   1,  28, 146,   3,  65,  40, 219,   1,   1,
  29, 147,   3,  65,  41, 218,   1,   1,  30, 148,   3,  65,  42, 217,   1,   1,
  31, 149,   3,   1,  43, 216,   1, 150,   3,  65,  44, 214,   1,   1,  32, 151,
   3,  65,  45, 213,   1,   1,  33, 152,   3,  65,  46, 212,   1,   1,  34, 153,
   3,   1,  47, 211,   1, 154,   3,  65,  48, 210,   1,   1,  35, 155,   3,  65,
  49, 209,   1,   1,  36, 156,   3,   1,  50, 208,   1, 157,   3,   1,  51, 207,
   1, 158,   3,   1,  52, 206,   1, 159,   3,  65,  53, 205,   1,   1,  37, 160,
   3,  65,  54, 204,   1,   1,  38, 161,   3,  65,  55, 203,   1,   1,  39, 162,
   3,  65,  56, 202,   1,   1,  40, 163,   3,  65,  57, 201,   1,   1,  41, 164,
   3,  68,   5,  45,   1,  42, 242,   1,   1, 185,   3,  68,   1,  48,   1,  43,
 245,   1,   1, 192,   3,   4,   1,  49, 189,   1, 106, 254,   1,   6,   0,   0,
  16,   8, 153,   1,   4,   0,   0, 154,   1,   4,   0,   1, 156,   1,  68,   0,
   2,   1,  11, 255,   1,  68,   0,   3,   1,  12, 128,   2,  68,   0,   4,   1,
  13, 129,   2,   1,   1,  36, 130,   2,  68,   0,   5,   1,  14, 131,   2,  68,
   0,  34,   1,  15, 132,   2,   4,   0,  35, 133,   2,  68,   0,   6,   1,  16,
 134,   2,  68,   0,  36,   1,  17, 135,   2,   4,   0,  37, 136,   2,  68,   0,
   7,   1,  18, 137,   2,  68,   0,  38,   1,  19, 138,   2,   4,   0,  39, 139,
   2,  68,   0,   8,   1,  20, 140,   2,  68,   0,   9,   1,  21, 141,   2,   4,
   0,  40, 142,   2,   4,   0,  41, 143,   2,  68,   0,  10,   1,  22, 144,   2,
  68,   0,  11,   1,  23, 145,   2,  68,   0,  12,   1,  24, 146,   2,   4,   0,
  13, 147,   2,   1,   2,  35, 148,   2,   1,   3,  34,  34,   1,   4,  33,  39,
   1,   5,  32,  42,   1,   6,  31,  53,   1,   7,  30, 149,   2,   6,   0,   0,
   2,   6, 150,   2,   6,   0,   0,   3,   6, 151,   2,   6,   0,   0,   4,   6,
 152,   2,   6,   0,   0,   5,   6, 153,   2,   6,   0,   0,   6,   6, 154,   2,
   6,   0,   0,   7,   6, 155,   2,   0,   0,   2,   0, 156,   2,  64,   0,   2,
   0,   1,   2, 157,   2,  64,   0,   2,   0,   1,   3, 158,   2,  64,   0,   2,
   0,   1,   4, 159,   2,  64,   0,   2,   0,   1,   5, 160,   2,  64,   0,   2,
   0,   1,   6, 161,   2,  64,   0,   2,   0,   1,   7, 162,   2,  64,   0,   2,
   0,   1,   8, 163,   2,  64,   0,   2,   0,   1,   9, 164,   2,  64,   0,   2,
   0,   1,  10, 165,   2,   6,   0,   2,  11,  11, 166,   2,  70,   0,   2,  11,
  11,   1,   2, 167,   2,  70,   0,   2,  11,  11,   1,   3, 168,   2,  70,   0,
   2,  11,  11,   1,   4, 169,   2,  70,   0,   2,  11,  11,   1,   5, 170,   2,
  70,   0,   2,  11,  11,   1,   6, 171,   2,  70,   0,   2,  11,  11,   1,   7,
 172,   2,  70,   0,   2,  11,  11,   1,   8, 173,   2,  70,   0,   2,  11,  11,
   1,   9, 174,   2,  70,   0,   2,  11,  11,   1,  10, 175,   2,   1,   8,  29,
 176,   2,  65,   9,  28,   1,   2, 177,   2,  65,  10,  27,   1,   3, 178,   2,
  65,  11,  26,   1,   4, 179,   2,  65,  12,  25,   1,   5, 180,   2,  65,  13,
  24,   1,   6, 181,   2,  65,  14,  23,   1,   7, 182,   2,  65,  15,  22,   1,
   8, 183,   2,  65,  16,  21,   1,   9, 184,   2,  65,  17,  20,   1,  10, 185,
   2,   2,  18,  19, 186,   2,  66,  19,  18,   1,   2, 187,   2,  66,  20,  17,
   1,   3, 188,   2,  66,  21,  16,   1,   4, 189,   2,  66,  22,  15,   1,   5,
 190,   2,  66,  23,  14,   1,   6, 191,   2,  66,  24,  13,   1,   7, 192,   2,
  66,  25,  12,   1,   8, 193,   2,  66,  26,  11,   1,   9, 194,   2,  66,  27,
  10,   1,  10, 185,   2,   3,  28,   9, 186,   2,  67,  29,   8,   1,   2, 187,
   2,  67,  30,   7,   1,   3, 188,   2,  67,  31,   6,   1,   4, 189,   2,  67,
  32,   5,   1,   5, 190,   2,  67,  33,   4,   1,   6, 191,   2,  67,  34,   3,
   1,   7, 192,   2,  67,  35,   2,   1,   8, 193,   2,  67,  36,   1,   1,   9,
 194,   2,  67,  37,   0,   1,  10, 195,   2,   4,   0,  14, 196,   2,  68,   0,
  15,   1,   2, 197,   2,  68,   0,  16,   1,   3, 198,   2,  68,   0,  17,   1,
   4, 199,   2,  68,   0,  18,   1,   5, 200,   2,  68,   0,  19,   1,   6, 201,
   2,  68,   0,  20,   1,   7, 202,   2,  68,   0,  21,   1,   8, 203,   2,  68,
   0,  22,   1,   9, 204,   2,  68,   0,  23,   1,  10, 205,   2,   4,   0,  24,
 206,   2,  68,   0,  25,   1,   2, 207,   2,  68,   0,  26,   1,   3, 208,   2,
  68,   0,  27,   1,   4, 209,   2,  68,   0,  28,   1,   5, 210,   2,  68,   0,
  29,   1,   6, 211,   2,  68,   0,  30,   1,   7, 212,   2,  68,   0,  31,   1,
   8, 213,   2,  68,   0,  32,   1,   9, 214,   2,  68,   0,  33,   1,  10, 172,
   1,   0,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   1,   1,   2,   1,
   2,   3, 208,  48,  71,   0,   0,   2,   1,   2,   1,   2,   3, 208,  48,  71,
   0,   0,   3,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   4,   1,   2,
   1,   2,   3, 208,  48,  71,   0,   0,   5,   1,   2,   1,   2,   3, 208,  48,
  71,   0,   0,   6,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   7,   1,
   2,   1,   2,   3, 208,  48,  71,   0,   0,   8,   1,   2,   1,   2,   3, 208,
  48,  71,   0,   0,   9,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,  10,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  11,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  12,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  13,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  14,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  15,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  16,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  17,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  18,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  19,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  20,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  21,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  22,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  23,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  24,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  25,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  26,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  27,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  28,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  29,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  30,
   2,   2,   1,   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   4,   1,  41,
  71,   0,   0,  31,   1,   1,   1,   2,  10, 208,  48,  93,   3, 102,   3,  70,
   5,   0,  72,   0,   0,  32,   1,   1,   1,   2,  10, 208,  48,  93,   3, 102,
   3,  70,   7,   0,  72,   0,   0,  33,   2,   2,   1,   2,  12, 208,  48,  93,
   3, 102,   3, 209,  70,   9,   1,  41,  71,   0,   0,  34,   2,   2,   1,   2,
  12, 208,  48,  93,   3, 102,   3, 209,  70,   9,   1,  41,  71,   0,   0,  35,
   2,   2,   1,   2,  13, 208,  48,  93,  10, 102,  10, 102,  11, 209,  70,  12,
   1,  72,   0,   0,  36,   1,   1,   1,   2,  11, 208,  48,  93,  14, 102,  14,
  70,  15,   0,  41,  71,   0,   0,  37,   0,   1,   3,   3,   1,  71,   0,   0,
  40,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  41,   1,   1,   4,   5,
   3, 208,  48,  71,   0,   0,  42,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0,  43,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  45,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  46,   2,   1,
   3,   4,  12, 208,  48,  94,  24,  93,  25,  70,  25,   0, 104,  24,  71,   0,
   0,  75,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  76,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  82,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0,  83,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0,  84,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0,  85,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  86,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  87,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0,  88,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0,  89,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  90,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  91,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0,  92,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0,  93,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
  94,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  95,   2,
   1,   3,   4,   9, 208,  48,  94,  71,  36,  42,  97,  71,  71,   0,   0,  96,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  97,   2,   1,
   3,   4,   9, 208,  48,  94,  74,  36, 101,  97,  74,  71,   0,   0,  98,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  99,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 100,   1,   1,   3,   4,   5, 208,  48,  44,
  88,  72,   0,   0, 101,   1,   1,   3,   4,  10, 208,  48,  93,  77, 102,  77,
  70,  78,   0,  72,   0,   0, 102,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 103,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 104,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 105,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 106,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 107,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 108,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 109,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 110,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 111,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 112,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 113,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 114,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 115,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 116,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 117,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 118,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 119,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 120,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 121,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 122,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 123,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 124,
   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 125,   1,   2,   4,   5,   3,
 208,  48,  71,   0,   0, 126,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0,
 127,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 128,   1,   1,   2,   4,
   5,   3, 208,  48,  71,   0,   0, 129,   1,   1,   2,   4,   5,   3, 208,  48,
  71,   0,   0, 130,   1,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 131,
   1,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 132,   1,   1,   2,   4,
   5,   3, 208,  48,  71,   0,   0, 133,   1,   1,   2,   4,   5,   3, 208,  48,
  71,   0,   0, 134,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 135,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 136,   1,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 137,   1,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0, 138,   1,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 139,   1,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 140,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 141,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 142,
   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 143,   1,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 144,   1,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 145,   1,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0, 146,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 147,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 148,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 149,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 150,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 151,   1,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 152,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 153,   1,   0,   1,   3,   3,   1,  71,   0,   0, 155,
   1,   0,   1,   3,   3,   1,  71,   0,   0, 157,   1,   0,   1,   3,   3,   1,
  71,   0,   0, 159,   1,   0,   1,   3,   3,   1,  71,   0,   0, 161,   1,   0,
   1,   3,   3,   1,  71,   0,   0, 163,   1,   0,   1,   3,   3,   1,  71,   0,
   0, 165,   1,   0,   1,   3,   3,   1,  71,   0,   0, 167,   1,   0,   1,   3,
   3,   1,  71,   0,   0, 169,   1,   0,   1,   3,   3,   1,  71,   0,   0, 171,
   1,   0,   1,   3,   3,   1,  71,   0,   0, 173,   1,   1,   1,   4,   5,   3,
 208,  48,  71,   0,   0, 174,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 175,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0,
 176,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 177,
   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 178,   1,   1,   1,   5,
   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 179,   1,   1,   1,   4,   5,
   3, 208,  48,  71,   0,   0, 180,   1,   1,   1,   5,   6,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 181,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 182,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 183,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 184,   1,   1,   1,
   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 185,   1,   1,   1,   4,
   5,   3, 208,  48,  71,   0,   0, 186,   1,   1,   1,   5,   6,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 187,   1,   1,   1,   4,   5,   3, 208,  48,  71,
   0,   0, 188,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 189,   1,   3,   1,   1,   4, 199,   7, 208,  48,  93, 153,   1,  32,  88,
   0, 104,  17,  93, 154,   1,  93,  20, 102,  20,  48,  93, 155,   1, 102, 155,
   1,  88,   1,  29, 104,  19,  93, 156,   1,  93,  20, 102,  20,  48,  93, 155,
   1, 102, 155,   1,  88,   2,  29, 104,  23,  93, 157,   1,  93,  20, 102,  20,
  48,  93, 155,   1, 102, 155,   1,  88,   3,  29, 104,  58,  93, 158,   1,  93,
  20, 102,  20,  48,  93, 155,   1, 102, 155,   1,  88,   4,  29, 104,  64,  93,
 159,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,   5,  29,
 104,  65,  93, 161,   1,  93,  20, 102,  20,  48,  93,  65, 102,  65,  48,  93,
 162,   1, 102, 162,   1,  88,  34,  29,  29, 104, 141,   1,  93, 163,   1,  93,
  20, 102,  20,  48,  93,  65, 102,  65,  48,  93, 162,   1, 102, 162,   1,  88,
  35,  29,  29, 104, 142,   1,  93, 164,   1,  93,  20, 102,  20,  48,  93, 160,
   1, 102, 160,   1,  88,   6,  29, 104,  66,  93, 165,   1,  93,  20, 102,  20,
  48,  93,  66, 102,  66,  48,  93, 166,   1, 102, 166,   1,  88,  36,  29,  29,
 104, 143,   1,  93, 167,   1,  93,  20, 102,  20,  48,  93,  66, 102,  66,  48,
  93, 166,   1, 102, 166,   1,  88,  37,  29,  29, 104, 144,   1,  93, 168,   1,
  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,   7,  29, 104,  67,
  93, 169,   1,  93,  20, 102,  20,  48,  93,  67, 102,  67,  48,  93, 170,   1,
 102, 170,   1,  88,  38,  29,  29, 104, 145,   1,  93, 171,   1,  93,  20, 102,
  20,  48,  93,  67, 102,  67,  48,  93, 170,   1, 102, 170,   1,  88,  39,  29,
  29, 104, 146,   1,  93, 172,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102,
 160,   1,  88,   8,  29, 104,  68,  93, 173,   1,  93,  20, 102,  20,  48,  93,
 160,   1, 102, 160,   1,  88,   9,  29, 104,  69,  93, 174,   1,  93,  20, 102,
  20,  48,  93,  69, 102,  69,  48,  93, 175,   1, 102, 175,   1,  88,  40,  29,
  29, 104, 148,   1,  93, 176,   1,  93,  20, 102,  20,  48,  93,  69, 102,  69,
  48,  93, 175,   1, 102, 175,   1,  88,  41,  29,  29, 104, 152,   1,  93, 177,
   1,  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,  10,  29, 104,
  70,  93, 178,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,
  11,  29, 104,  73,  93, 179,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102,
 160,   1,  88,  12,  29, 104,  76,  93, 180,   1,  93,  20, 102,  20,  48,  93,
 181,   1, 102, 181,   1,  88,  13,  29, 104,  80,  93, 182,   1,  93,  20, 102,
  20,  48,  93, 160,   1, 102, 160,   1,  88,  14,  29, 104, 121,  93, 183,   1,
  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,  15,  29, 104, 122,
  93, 184,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,  16,
  29, 104, 123,  93, 185,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,
   1,  88,  17,  29, 104, 124,  93, 186,   1,  93,  20, 102,  20,  48,  93, 160,
   1, 102, 160,   1,  88,  18,  29, 104, 125,  93, 187,   1,  93,  20, 102,  20,
  48,  93, 160,   1, 102, 160,   1,  88,  19,  29, 104, 126,  93, 188,   1,  93,
  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,  20,  29, 104, 127,  93,
 189,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,   1,  88,  21,  29,
 104, 128,   1,  93, 190,   1,  93,  20, 102,  20,  48,  93, 160,   1, 102, 160,
   1,  88,  22,  29, 104, 129,   1,  93, 191,   1,  93,  20, 102,  20,  48,  93,
 160,   1, 102, 160,   1,  88,  23,  29, 104, 130,   1,  93, 192,   1,  32,  88,
  24, 104, 131,   1,  93, 193,   1,  32,  88,  25, 104, 132,   1,  93, 194,   1,
  32,  88,  26, 104, 133,   1,  93, 195,   1,  32,  88,  27, 104, 134,   1,  93,
 196,   1,  32,  88,  28, 104, 135,   1,  93, 197,   1,  32,  88,  29, 104, 136,
   1,  93, 198,   1,  32,  88,  30, 104, 137,   1,  93, 199,   1,  32,  88,  31,
 104, 138,   1,  93, 200,   1,  32,  88,  32, 104, 139,   1,  93, 201,   1,  32,
  88,  33, 104, 140,   1,  93, 202,   1,  37, 149,   5,  37, 148,   5, 161, 104,
 203,   1,  93, 204,   1,  37, 150,   5,  37, 148,   5, 161, 104, 205,   1,  93,
 206,   1,  37, 151,   5,  37, 148,   5, 161, 104, 207,   1,  93, 208,   1,  37,
 152,   5,  37, 148,   5, 161, 104, 209,   1,  93, 210,   1,  37, 153,   5,  37,
 148,   5, 161, 104, 211,   1,  93, 212,   1,  37, 154,   5,  37, 148,   5, 161,
 104, 213,   1,  93, 214,   1,  38,  97, 215,   1,  93, 216,   1,  38,  97, 217,
   1,  93, 218,   1,  38,  97, 219,   1,  93, 220,   1,  38,  97, 221,   1,  93,
 222,   1,  38,  97, 223,   1,  93, 224,   1,  38,  97, 225,   1,  93, 226,   1,
  38,  97, 227,   1,  93, 228,   1,  38,  97, 229,   1,  93, 230,   1,  38,  97,
 231,   1,  93, 232,   1,  38,  97, 233,   1,  93, 234,   1,  38, 104, 235,   1,
  93, 236,   1,  38, 104, 237,   1,  93, 238,   1,  38, 104, 239,   1,  93, 240,
   1,  38, 104, 241,   1,  93, 242,   1,  38, 104, 243,   1,  93, 244,   1,  38,
 104, 245,   1,  93, 246,   1,  38, 104, 247,   1,  93, 248,   1,  38, 104, 249,
   1,  93, 250,   1,  38, 104, 251,   1,  93, 252,   1,  38, 104, 253,   1,  71,
   0,   0, 190,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 194,   1,
   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 216,   2,   1,
  41,  71,   0,   0, 197,   1,   3,   3,   4,   5,  20, 208,  48, 208,  93, 217,
   2, 102, 217,   2, 209,  70, 218,   2,   1, 210,  70, 219,   2,   2,  72,   0,
   0, 200,   1,   2,   1,   1,   3,  23, 208,  48,  93, 227,   2,  93,  20, 102,
  20,  48,  93, 228,   2, 102, 228,   2,  88,  42,  29, 104, 215,   2,  71,   0,
   0, 206,   1,   4,   3,   1,   2,  14, 208,  48,  93, 232,   2, 209, 210,  36,
   1,  70, 232,   2,   3,  72,   0,   0, 207,   1,   4,   3,   1,   2,  14, 208,
  48,  93, 232,   2, 209, 210,  36,   2,  70, 232,   2,   3,  72,   0,   0, 208,
   1,   4,   3,   1,   2,  14, 208,  48,  93, 232,   2, 209, 210,  36,   0,  70,
 232,   2,   3,  72,   0,   0, 211,   1,   2,   1,   1,   2,  13, 208,  48,  93,
 233,   2, 100, 108,   5,  70, 233,   2,   1,  72,   0,   0, 215,   1,   3,   3,
   3,   6,  47,  87,  42, 213,  48, 101,   0,  38, 118, 109,   1,  93, 234,   2,
  76, 234,   2,   0,  41,  16,  20,   0,   0, 209,  48,  90,   0,  42, 214,  42,
  48,  43, 109,   1, 101,   0,  39, 118, 109,   1,  29,   8,   2, 101,   0, 108,
   1,  72,   1,  10,  18,  22,   0, 235,   2,   1, 236,   2,   0,   1,   2,   0,
 216,   1,   2,   3,   2,   4,  60, 208,  48,  87,  42, 214,  48, 101,   1,  33,
 130, 109,   2, 101,   1, 209, 109,   1, 101,   1, 108,   1,  32,  19,  24,   0,
   0, 101,   1,  64, 215,   1, 130, 109,   2,  93, 237,   2, 101,   1, 108,   2,
  70, 237,   2,   1,  41,  16,   9,   0,   0,  93, 237,   2,  32,  70, 237,   2,
   1,  41,  71,   0,   2, 238,   2,   0,   1, 230,   2,   0, 239,   2,   0,   2,
   0,   0, 222,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 223,   1,
   3,   1,   4,   5,  50, 208,  48, 208, 102, 240,   2,  44, 143,   2, 160, 208,
 102, 241,   2, 118,  18,  26,   0,   0,  44, 145,   2, 208, 102, 241,   2, 160,
  44, 146,   2, 160, 208, 102, 242,   2, 160,  44, 148,   2, 160, 130,  16,   3,
   0,   0,  44,   1, 130, 160,  72,   0,   0, 224,   1,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 225,   1,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 226,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 227,   1,   2,   1,   3,   4,  39, 208,  48,  94, 252,   2, 100,
 108,   1, 104, 252,   2,  94, 253,   2, 100, 108,   2, 104, 253,   2,  94, 254,
   2, 100, 108,   4, 104, 254,   2,  94, 255,   2, 100, 108,   3, 104, 255,   2,
  71,   0,   0, 228,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 229,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 232,   1,
   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 233,   1,   1,
   1,   4,   5,   3, 208,  48,  71,   0,   0, 234,   1,   1,   1,   5,   6,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 235,   1,   2,   1,   1,   4, 108, 208,
  48, 101,   0,  93,  20, 102,  20,  48,  93, 139,   3, 102, 139,   3,  88,  43,
  29, 104, 248,   2, 101,   0,  93,  20, 102,  20,  48,  93, 139,   3, 102, 139,
   3,  88,  44,  29, 104, 251,   2, 101,   0,  93,  20, 102,  20,  48,  93, 251,
   2, 102, 251,   2,  48, 100, 108,   2,  88,  46,  29,  29, 104, 137,   3, 101,
   0,  93,  20, 102,  20,  48,  93, 251,   2, 102, 251,   2,  48, 100, 108,   2,
  88,  47,  29,  29, 104, 138,   3, 101,   0,  93,  20, 102,  20,  48,  93, 139,
   3, 102, 139,   3,  88,  45,  29, 104, 132,   3,  71,   0,   0, 236,   1,   2,
   1,   3,   4,  59, 208,  48,  94, 165,   3,  36,   0, 104, 165,   3,  94, 166,
   3,  36,   1, 104, 166,   3,  94, 167,   3,  36,   2, 104, 167,   3,  94, 168,
   3,  36,   3, 104, 168,   3,  94, 169,   3,  36,   4, 104, 169,   3,  94, 170,
   3,  36,   1, 104, 170,   3,  94, 171,   3,  36,   2, 104, 171,   3,  71,   0,
   0, 241,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 242,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  20, 102,  20,  48,
  93, 184,   3, 102, 184,   3,  88,  48,  29, 104, 183,   3,  71,   0,   0, 243,
   1,   2,   1,   3,   4,  21, 208,  48,  94, 186,   3,  44, 224,   2, 104, 186,
   3,  94, 187,   3,  44, 226,   2, 104, 187,   3,  71,   0,   0, 244,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 245,   1,   2,   1,
   1,   3,  22, 208,  48, 101,   0,  93,  20, 102,  20,  48,  93, 191,   3, 102,
 191,   3,  88,  49,  29, 104, 190,   3,  71,   0,   0};


/* versioned_uris */
const char* const shell_toplevel_versioned_uris[] = {
    "__AS3__.vec", // [660]
    "avmplus", // [660]
    "avmshell", // [660, 661, 662, 663, 664, 665, 666]
    "flash.errors", // [660]
    "flash.net", // [660]
    "flash.sampler", // [660]
    "flash.system", // [660]
    "flash.trace", // [660]
    "flash.utils", // [660]
    NULL
};

#ifdef VMCFG_AOT
extern "C" const struct {
    const char* const n_0; avmplus::DomainClass* const m_0;
    const char* const n_1; avmplus::DomainObject* const m_1;
    const char* const n_2; avmplus::NewObjectSampleClass* const m_2;
    const char* const n_3; avmplus::NewObjectSampleObject* const m_3;
    const char* const n_4; avmplus::TraceClass* const m_4;
    const char* const n_5; avmshell::AbstractBaseClass* const m_5;
    const char* const n_6; avmshell::AbstractBaseObject* const m_6;
    const char* const n_7; avmshell::AbstractRestrictedBaseClass* const m_7;
    const char* const n_8; avmshell::AbstractRestrictedBaseObject* const m_8;
    const char* const n_9; avmshell::CheckBaseClass* const m_9;
    const char* const n_10; avmshell::CheckBaseObject* const m_10;
    const char* const n_11; avmshell::FileClass* const m_11;
    const char* const n_12; avmshell::MIClass* const m_12;
    const char* const n_13; avmshell::MIObject* const m_13;
    const char* const n_14; avmshell::NativeBaseClass* const m_14;
    const char* const n_15; avmshell::NativeBaseObject* const m_15;
    const char* const n_16; avmshell::NativeSubclassOfAbstractBaseClass* const m_16;
    const char* const n_17; avmshell::NativeSubclassOfAbstractBaseObject* const m_17;
    const char* const n_18; avmshell::NativeSubclassOfAbstractRestrictedBaseClass* const m_18;
    const char* const n_19; avmshell::NativeSubclassOfAbstractRestrictedBaseObject* const m_19;
    const char* const n_20; avmshell::NativeSubclassOfRestrictedBaseClass* const m_20;
    const char* const n_21; avmshell::NativeSubclassOfRestrictedBaseObject* const m_21;
    const char* const n_22; avmshell::RestrictedBaseClass* const m_22;
    const char* const n_23; avmshell::RestrictedBaseObject* const m_23;
    const char* const n_24; avmshell::SystemClass* const m_24;
} aotABCTypes_shell_toplevel = {
    "DomainClass", 0,
    "DomainObject", 0,
    "NewObjectSampleClass", 0,
    "NewObjectSampleObject", 0,
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
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::CTestClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_CTestClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::CTestClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::CTestObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CTestClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::CTestClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CTestClass
    m_slots_CTestClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CTestClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CTestObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::CTestObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CTestObject
    m_slots_CTestObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CTestObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
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
bool avmplus::SystemObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SystemObject
    m_slots_SystemObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SystemObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::FileClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::FileClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_FileClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::FileClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::FileObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::FileObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_FileObject
    m_slots_FileObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::FileObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::AbstractBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::AbstractBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_AbstractBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::RestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::RestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::RestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_RestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::RestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmshell::RestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::RestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::RestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::AbstractRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::AbstractRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_AbstractRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::AbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CheckBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::CheckBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::CheckBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CheckBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::CheckBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    avmshell::CheckBaseClass::preCreateInstanceCheck(cls);
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmshell::CheckBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CheckBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CheckBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::NativeBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmshell::NativeBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeBaseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::NativeBaseAS3Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::NativeBaseAS3Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_NativeBaseAS3Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::NativeBaseAS3Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::NativeBaseAS3Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseAS3Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::NativeBaseAS3Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NativeBaseAS3Class
    m_slots_NativeBaseAS3Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::NativeBaseAS3Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseAS3Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::NativeBaseAS3Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NativeBaseAS3Object
    m_slots_NativeBaseAS3Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::NativeBaseAS3Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ShellCoreFriend1Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ShellCoreFriend1Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::ShellCoreFriend1Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend1Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ShellCoreFriend1Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::ShellCoreFriend1Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend1Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::ShellCoreFriend1Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ShellCoreFriend1Class
    m_slots_ShellCoreFriend1Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ShellCoreFriend1Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend1Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::ShellCoreFriend1Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ShellCoreFriend1Object
    m_slots_ShellCoreFriend1Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ShellCoreFriend1Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ShellCoreFriend2Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ShellCoreFriend2Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::ShellCoreFriend2Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend2Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ShellCoreFriend2Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::ShellCoreFriend2Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend2Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::ShellCoreFriend2Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ShellCoreFriend2Class
    m_slots_ShellCoreFriend2Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ShellCoreFriend2Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ShellCoreFriend2Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::ShellCoreFriend2Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ShellCoreFriend2Object
    m_slots_ShellCoreFriend2Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ShellCoreFriend2Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::CapabilitiesClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::CapabilitiesClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::CapabilitiesClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_CapabilitiesClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::CapabilitiesClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::CapabilitiesObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CapabilitiesClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::CapabilitiesClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CapabilitiesClass
    m_slots_CapabilitiesClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CapabilitiesClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CapabilitiesObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::CapabilitiesObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CapabilitiesObject
    m_slots_CapabilitiesObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CapabilitiesObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_classClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_classClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_classClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_classClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_classClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_classObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_classClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_classClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_classClass
    m_slots_public_classClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_classClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_classObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_classObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_classObject
    m_slots_public_classObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_classObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_AIR_1_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_AIR_1_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_0Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_0Class
    m_slots_public_class_AIR_1_0Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_0Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_0Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_0Object
    m_slots_public_class_AIR_1_0Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_0Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_FP_10_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_FP_10_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_FP_10_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_FP_10_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_FP_10_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_FP_10_0Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_FP_10_0Class
    m_slots_public_class_FP_10_0Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_FP_10_0Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_FP_10_0Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_FP_10_0Object
    m_slots_public_class_FP_10_0Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_FP_10_0Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_AIR_1_5Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_AIR_1_5Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5Class
    m_slots_public_class_AIR_1_5Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5Object
    m_slots_public_class_AIR_1_5Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5_1Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5_1Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_AIR_1_5_1Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_1Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5_1Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_AIR_1_5_1Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5_1Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5_1Class
    m_slots_public_class_AIR_1_5_1Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5_1Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5_1Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5_1Object
    m_slots_public_class_AIR_1_5_1Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5_1Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_FP_10_0_32Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_FP_10_0_32Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_FP_10_0_32Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0_32Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_FP_10_0_32Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_FP_10_0_32Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_FP_10_0_32Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_FP_10_0_32Class
    m_slots_public_class_FP_10_0_32Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_FP_10_0_32Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_FP_10_0_32Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_FP_10_0_32Object
    m_slots_public_class_FP_10_0_32Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_FP_10_0_32Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5_2Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5_2Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_AIR_1_5_2Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_2Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5_2Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_AIR_1_5_2Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_2Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5_2Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5_2Class
    m_slots_public_class_AIR_1_5_2Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5_2Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_2Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5_2Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5_2Object
    m_slots_public_class_AIR_1_5_2Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5_2Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_0_FP_10_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_0_FP_10_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_AIR_1_0_FP_10_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_0_FP_10_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_0_FP_10_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_AIR_1_0_FP_10_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0_FP_10_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_0_FP_10_0Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_0_FP_10_0Class
    m_slots_public_class_AIR_1_0_FP_10_0Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_0_FP_10_0Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_0_FP_10_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_0_FP_10_0Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_0_FP_10_0Object
    m_slots_public_class_AIR_1_0_FP_10_0Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_0_FP_10_0Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class
    m_slots_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object
    m_slots_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class
    m_slots_public_class_FP_10_0_32_AIR_1_0_FP_10_0Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_public_class_FP_10_0_32_AIR_1_0_FP_10_0Object
    m_slots_public_class_FP_10_0_32_AIR_1_0_FP_10_0Object.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::public_class_FP_10_0_32_AIR_1_0_FP_10_0Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeSubclassOfAbstractBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::NativeSubclassOfAbstractBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::NativeSubclassOfAbstractBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfAbstractBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfAbstractBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmshell::NativeSubclassOfAbstractBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SubclassOfAbstractBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SubclassOfAbstractBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SubclassOfAbstractBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SubclassOfAbstractBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SubclassOfAbstractBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SubclassOfAbstractBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SubclassOfAbstractBaseClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SubclassOfAbstractBaseClass
    m_slots_SubclassOfAbstractBaseClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SubclassOfAbstractBaseClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractBaseObject::construct(argc, argv); } )
bool avmplus::SubclassOfAbstractBaseObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SubclassOfAbstractBaseObject
    m_slots_SubclassOfAbstractBaseObject.gcTracePrivateProperties(gc);
#endif
    avmshell::AbstractBaseObject::gcTrace(gc, 0);
    (void)(avmshell_AbstractBaseObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SubclassOfAbstractBaseObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmshell::AbstractBaseObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeSubclassOfRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::NativeSubclassOfRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::NativeSubclassOfRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmshell::NativeSubclassOfRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::RestrictedBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SubclassOfRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SubclassOfRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SubclassOfRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SubclassOfRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SubclassOfRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SubclassOfRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SubclassOfRestrictedBaseClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SubclassOfRestrictedBaseClass
    m_slots_SubclassOfRestrictedBaseClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SubclassOfRestrictedBaseClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::RestrictedBaseObject::construct(argc, argv); } )
bool avmplus::SubclassOfRestrictedBaseObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SubclassOfRestrictedBaseObject
    m_slots_SubclassOfRestrictedBaseObject.gcTracePrivateProperties(gc);
#endif
    avmshell::RestrictedBaseObject::gcTrace(gc, 0);
    (void)(avmshell_RestrictedBaseObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SubclassOfRestrictedBaseObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmshell::RestrictedBaseObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::NativeSubclassOfAbstractRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_NativeSubclassOfAbstractRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::NativeSubclassOfAbstractRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmshell::NativeSubclassOfAbstractRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::NativeSubclassOfAbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractRestrictedBaseObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SubclassOfAbstractRestrictedBaseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SubclassOfAbstractRestrictedBaseClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SubclassOfAbstractRestrictedBaseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SubclassOfAbstractRestrictedBaseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SubclassOfAbstractRestrictedBaseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SubclassOfAbstractRestrictedBaseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractRestrictedBaseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SubclassOfAbstractRestrictedBaseClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SubclassOfAbstractRestrictedBaseClass
    m_slots_SubclassOfAbstractRestrictedBaseClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SubclassOfAbstractRestrictedBaseClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SubclassOfAbstractRestrictedBaseObject::construct(int argc, avmplus::Atom* argv) { return avmshell::AbstractRestrictedBaseObject::construct(argc, argv); } )
bool avmplus::SubclassOfAbstractRestrictedBaseObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SubclassOfAbstractRestrictedBaseObject
    m_slots_SubclassOfAbstractRestrictedBaseObject.gcTracePrivateProperties(gc);
#endif
    avmshell::AbstractRestrictedBaseObject::gcTrace(gc, 0);
    (void)(avmshell_AbstractRestrictedBaseObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SubclassOfAbstractRestrictedBaseObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmshell::AbstractRestrictedBaseObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::NativeBaseExtender1Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::NativeBaseExtender1Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::NativeBaseExtender1Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_NativeBaseExtender1Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::NativeBaseExtender1Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::NativeBaseExtender1Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseExtender1Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::NativeBaseExtender1Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NativeBaseExtender1Class
    m_slots_NativeBaseExtender1Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::NativeBaseExtender1Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseExtender1Object::construct(int argc, avmplus::Atom* argv) { return avmshell::NativeBaseObject::construct(argc, argv); } )
bool avmplus::NativeBaseExtender1Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NativeBaseExtender1Object
    m_slots_NativeBaseExtender1Object.gcTracePrivateProperties(gc);
#endif
    avmshell::NativeBaseObject::gcTrace(gc, 0);
    (void)(avmshell_NativeBaseObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::NativeBaseExtender1Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmshell::NativeBaseObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::NativeBaseExtender2Class::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::NativeBaseExtender2Class::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::NativeBaseExtender2Class(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_NativeBaseExtender2Class(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::NativeBaseExtender2Class::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::NativeBaseExtender2Object(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseExtender2Class::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::NativeBaseExtender2Class::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NativeBaseExtender2Class
    m_slots_NativeBaseExtender2Class.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::NativeBaseExtender2Class::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NativeBaseExtender2Object::construct(int argc, avmplus::Atom* argv) { return avmshell::NativeBaseObject::construct(argc, argv); } )
bool avmplus::NativeBaseExtender2Object::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NativeBaseExtender2Object
    m_slots_NativeBaseExtender2Object.gcTracePrivateProperties(gc);
#endif
    avmshell::NativeBaseObject::gcTrace(gc, 0);
    (void)(avmshell_NativeBaseObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::NativeBaseExtender2Object::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmshell::NativeBaseObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
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
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::StackFrameClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_StackFrameClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::StackFrameClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::StackFrameObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::StackFrameClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_StackFrameClass
    m_slots_StackFrameClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::StackFrameClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::StackFrameObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_StackFrameObject
    m_slots_StackFrameObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::StackFrameObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject.m_name),
    offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject.m_file),
    0};
MMgc::GCTracerCheckResult avmplus::StackFrameObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,2);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SampleClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SampleClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SampleClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SampleClass
    m_slots_SampleClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SampleClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::SampleObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SampleObject
    m_slots_SampleObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::SampleObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::SampleObject, m_slots_SampleObject.m_stack),
    0};
MMgc::GCTracerCheckResult avmplus::SampleObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,1);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ClassFactoryClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ClassFactoryClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::ClassFactoryClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ClassFactoryClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ClassFactoryClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::ClassFactoryObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ClassFactoryClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::ClassFactoryClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ClassFactoryClass
    m_slots_ClassFactoryClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::ClassFactoryClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_StackFrameClass),
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_SampleClass),
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_DeleteObjectSampleClass),
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_NewObjectSampleClass),
    0};
MMgc::GCTracerCheckResult avmplus::ClassFactoryClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,4);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ClassFactoryObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::ClassFactoryObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ClassFactoryObject
    m_slots_ClassFactoryObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ClassFactoryObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
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
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::DeleteObjectSampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_DeleteObjectSampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DeleteObjectSampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::DeleteObjectSampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::DeleteObjectSampleClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DeleteObjectSampleClass
    m_slots_DeleteObjectSampleClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::DeleteObjectSampleClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
bool avmplus::DeleteObjectSampleObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DeleteObjectSampleObject
    m_slots_DeleteObjectSampleObject.gcTracePrivateProperties(gc);
#endif
    avmplus::SampleObject::gcTrace(gc, 0);
    (void)(avmplus_SampleObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::DeleteObjectSampleObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::SampleObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::TraceClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::TraceClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_TraceClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::TraceObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_TraceObject
    m_slots_TraceObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::TraceObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::EndianClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::EndianClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::EndianClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_EndianClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::EndianClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::EndianObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EndianClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::EndianClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EndianClass
    m_slots_EndianClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::EndianClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::EndianClass, m_slots_EndianClass.m_BIG_ENDIAN),
    offsetof(avmplus::EndianClass, m_slots_EndianClass.m_LITTLE_ENDIAN),
    0};
MMgc::GCTracerCheckResult avmplus::EndianClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,2);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EndianObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::EndianObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EndianObject
    m_slots_EndianObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::EndianObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
