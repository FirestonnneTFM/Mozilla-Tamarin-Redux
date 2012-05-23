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

const uint32_t shell_toplevel_abc_class_count = 58;
const uint32_t shell_toplevel_abc_script_count = 8;
const uint32_t shell_toplevel_abc_method_count = 339;
const uint32_t shell_toplevel_abc_length = 29864;

/* thunks (104 total) */
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
avmplus::Atom flash_system_Worker_pr_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerClass*, argv[argoff0]);
    obj->pr(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Worker_pr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_pr_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_state_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    avmplus::String* const ret = obj->get_state();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_state_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_state_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_startWithChannels_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ArrayObject* arg1 = (avmplus::ArrayObject*)(argc < 1 ? AvmThunkCoerce_ATOM_OBJECT(nullObjectAtom) : (avmplus::ArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ArrayObject*, argv[argoff1]));
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    bool const ret = obj->startWithChannels(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_startWithChannels_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_startWithChannels_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_private_startInternal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    avmplus::PromiseObject* const ret = obj->startInternal();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_private_startInternal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_private_startInternal_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_isParentOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmshell::ShellWorkerObject* arg1 = (avmshell::ShellWorkerObject*)AvmThunkUnbox_OBJECT(avmshell::ShellWorkerObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    bool const ret = obj->isParentOf(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_isParentOf_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_isParentOf_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_isPrimordial_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    bool const ret = obj->get_isPrimordial();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_isPrimordial_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_isPrimordial_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_private_newEventChannel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    avmplus::PromiseChannelObject* const ret = obj->newEventChannel();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_private_newEventChannel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_private_newEventChannel_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_setStartArgument_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::Atom arg2 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    obj->setStartArgument(
        arg1
        , arg2
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Worker_setStartArgument_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_setStartArgument_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_getStartArgument_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->getStartArgument(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_getStartArgument_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_getStartArgument_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_stop_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    bool const ret = obj->stop();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_stop_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_stop_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_descriptor_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    int32_t const ret = obj->get_descriptor();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_descriptor_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Worker_descriptor_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ByteArrayObject* arg1 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerDomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerDomainObject*, argv[argoff0]);
    avmshell::ShellWorkerObject* const ret = obj->createWorkerFromByteArrayInternal(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_currentGiid_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    int32_t const ret = obj->get_currentGiid();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_PromiseHelper_currentGiid_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_currentGiid_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_getPromiseOwnerGiid_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    int32_t const ret = obj->getPromiseOwnerGiid(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_PromiseHelper_getPromiseOwnerGiid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_getPromiseOwnerGiid_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_setPromiseOwnerGiid_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    int32_t arg2 = AvmThunkUnbox_INT(int32_t, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->setPromiseOwnerGiid(
        arg1
        , arg2
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_setPromiseOwnerGiid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_setPromiseOwnerGiid_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_getPromiseGid_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    uint32_t const ret = obj->getPromiseGid(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_PromiseHelper_getPromiseGid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_getPromiseGid_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_setPromiseGid_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    uint32_t arg2 = AvmThunkUnbox_UINT(uint32_t, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->setPromiseGid(
        arg1
        , arg2
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_setPromiseGid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_setPromiseGid_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_isPromiseEmpty_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    bool const ret = obj->isPromiseEmpty(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_PromiseHelper_isPromiseEmpty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_isPromiseEmpty_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_schedulePromiseCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->schedulePromiseCollection(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_schedulePromiseCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_schedulePromiseCollection_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_retargetIncChannel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
        , argoff3 = argoff2 + AvmThunkArgSize_INT
    };
    avmplus::PromiseChannelObject* arg1 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff1]);
    int32_t arg2 = AvmThunkUnbox_INT(int32_t, argv[argoff2]);
    int32_t arg3 = AvmThunkUnbox_INT(int32_t, argv[argoff3]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->retargetIncChannel(
        arg1
        , arg2
        , arg3
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_retargetIncChannel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_retargetIncChannel_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_retargetOutChannel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
        , argoff3 = argoff2 + AvmThunkArgSize_INT
    };
    avmplus::PromiseChannelObject* arg1 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff1]);
    int32_t arg2 = AvmThunkUnbox_INT(int32_t, argv[argoff2]);
    int32_t arg3 = AvmThunkUnbox_INT(int32_t, argv[argoff3]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->retargetOutChannel(
        arg1
        , arg2
        , arg3
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_retargetOutChannel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_retargetOutChannel_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_flash_system_waitForAnySend_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::bool32 arg1 = AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    bool const ret = obj->waitForAnySend(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_PromiseHelper_flash_system_waitForAnySend_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_flash_system_waitForAnySend_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_pr_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->pr(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_pr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_pr_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_praddr_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->praddr(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_praddr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_praddr_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_PromiseHelper_breakOn_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseHelperClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseHelperClass*, argv[argoff0]);
    obj->breakOn(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_PromiseHelper_breakOn_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_PromiseHelper_breakOn_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_registerEmptyPromise_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    int32_t arg2 = AvmThunkUnbox_INT(int32_t, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::PromiseClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseClass*, argv[argoff0]);
    obj->registerEmptyPromise(
        arg1
        , arg2
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Promise_registerEmptyPromise_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_registerEmptyPromise_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_private_printEmptyPromises_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::PromiseClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseClass*, argv[argoff0]);
    obj->printEmptyPromises();
    return undefinedAtom;
}
avmplus::Atom flash_system_Promise_private_printEmptyPromises_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_private_printEmptyPromises_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_private_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseChannelObject* arg1 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff1]);
    avmplus::PromiseChannelObject* arg2 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::PromiseClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseClass*, argv[argoff0]);
    avmplus::PromiseObject* const ret = obj->create(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Promise_private_create_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_private_create_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_private_createLocal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmplus::bool32 arg2 = AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::PromiseClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseClass*, argv[argoff0]);
    avmplus::PromiseObject* const ret = obj->createLocal(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Promise_private_createLocal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_private_createLocal_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_notifyOwner_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_UINT
        , argoff3 = argoff2 + AvmThunkArgSize_UINT
        , argoff4 = argoff3 + AvmThunkArgSize_OBJECT
    };
    uint32_t arg1 = AvmThunkUnbox_UINT(uint32_t, argv[argoff1]);
    uint32_t arg2 = AvmThunkUnbox_UINT(uint32_t, argv[argoff2]);
    avmplus::PromiseChannelObject* arg3 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff3]);
    avmplus::PromiseChannelObject* arg4 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff4]);
    (void)argc;
    (void)env;
    avmplus::PromiseClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseClass*, argv[argoff0]);
    obj->notifyOwner(
        arg1
        , arg2
        , arg3
        , arg4
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Promise_notifyOwner_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_notifyOwner_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_private_notifyEmptyOwners_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseObject* arg1 = (avmplus::PromiseObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseClass*, argv[argoff0]);
    obj->notifyEmptyOwners(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Promise_private_notifyEmptyOwners_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_private_notifyEmptyOwners_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_isOwnedLocally_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::PromiseObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseObject*, argv[argoff0]);
    bool const ret = obj->isOwnedLocally();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Promise_isOwnedLocally_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_isOwnedLocally_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Promise_delayCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    uint32_t arg1 = AvmThunkUnbox_UINT(uint32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::PromiseObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::PromiseObject*, argv[argoff0]);
    obj->delayCollection(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Promise_delayCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Promise_delayCollection_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_RemoteProxy_create_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
        , argoff3 = argoff2 + AvmThunkArgSize_OBJECT
    };
    avmplus::PromiseChannelObject* arg1 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff1]);
    avmplus::PromiseChannelObject* arg2 = (avmplus::PromiseChannelObject*)AvmThunkUnbox_OBJECT(avmplus::PromiseChannelObject*, argv[argoff2]);
    uint32_t arg3 = AvmThunkUnbox_UINT(uint32_t, argv[argoff3]);
    (void)argc;
    (void)env;
    avmplus::RemoteProxyClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::RemoteProxyClass*, argv[argoff0]);
    avmplus::RemoteProxyObject* const ret = obj->create(
        arg1
        , arg2
        , arg3
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_RemoteProxy_create_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_RemoteProxy_create_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_RemoteProxy_m_workerClass_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::RemoteProxyClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::RemoteProxyClass*, argv[argoff0]);
    avmplus::ClassClosure* const ret = obj->get_m_workerClass();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_RemoteProxy_m_workerClass_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_RemoteProxy_m_workerClass_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_RemoteProxy_callProp_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmshell::EnvelopeObject* arg2 = (avmshell::EnvelopeObject*)AvmThunkUnbox_OBJECT(avmshell::EnvelopeObject*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::RemoteProxyClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::RemoteProxyClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->callProp(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_RemoteProxy_callProp_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_RemoteProxy_callProp_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_RemoteProxy_getProp_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmshell::EnvelopeObject* arg2 = (avmshell::EnvelopeObject*)AvmThunkUnbox_OBJECT(avmshell::EnvelopeObject*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::RemoteProxyClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::RemoteProxyClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->getProp(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_RemoteProxy_getProp_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_RemoteProxy_getProp_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_RemoteProxy_triggerDelayedCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::RemoteProxyObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::RemoteProxyObject*, argv[argoff0]);
    obj->triggerDelayedCollection(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_RemoteProxy_triggerDelayedCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_RemoteProxy_triggerDelayedCollection_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Envelope_name_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::EnvelopeObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::EnvelopeObject*, argv[argoff0]);
    avmplus::String* const ret = obj->get_name();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Envelope_name_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = flash_system_Envelope_name_get_thunk(env, argc, argv);
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
avmplus::Atom avmplus_System_sleep_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->sleep(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_sleep_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_sleep_thunk(env, argc, argv);
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
avmplus::Atom avmplus_System_copy_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->copy(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom avmplus_System_copy_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_copy_thunk(env, argc, argv);
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
avmplus::Atom avmplus_System_runInSafepoint_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::SystemClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::SystemClass*, argv[argoff0]);
    obj->runInSafepoint(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom avmplus_System_runInSafepoint_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    MethodFrame frame;
    frame.enter(env->core(), env);
    avmplus::Atom retVal = avmplus_System_runInSafepoint_thunk(env, argc, argv);
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
        kSlotsOffset_avmshell_ShellWorkerClass = offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass),
        kSlotsOffset_avmshell_ShellWorkerObject = offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject),
        kSlotsOffset_avmplus_WorkerEventClass = offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass),
        kSlotsOffset_avmplus_WorkerEventObject = offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject),
        kSlotsOffset_avmshell_ShellWorkerDomainClass = offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass),
        kSlotsOffset_avmshell_ShellWorkerDomainObject = 0,
        kSlotsOffset_avmplus_PromiseStateClass = offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass),
        kSlotsOffset_avmplus_PromiseStateObject = 0,
        kSlotsOffset_avmplus_PromiseHelperClass = offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass),
        kSlotsOffset_avmplus_PromiseHelperObject = 0,
        kSlotsOffset_avmplus_PromiseClass = offsetof(avmplus::PromiseClass, m_slots_PromiseClass),
        kSlotsOffset_avmplus_PromiseObject = offsetof(avmplus::PromiseObject, m_slots_PromiseObject),
        kSlotsOffset_avmplus_RemoteProxyClass = offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass),
        kSlotsOffset_avmplus_RemoteProxyObject = offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject),
        kSlotsOffset_avmshell_EnvelopeClass = 0,
        kSlotsOffset_avmshell_EnvelopeObject = 0,
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
    static void check_avmshell_ShellWorkerClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_WorkerEventClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_ShellWorkerDomainClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_PromiseStateClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_PromiseHelperClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_PromiseClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_RemoteProxyClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_EnvelopeClass(Traits* ctraits, Traits* itraits);
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
    AvmAssert(getSlotOffset(ctraits, 43) == (offsetof(avmshell::SystemClass, m_slots_SystemClass) + offsetof(avmshell_SystemClassSlots, m_argv)));
    AvmAssert(getMethodIndex(ctraits, 30) == 5); // exit
    AvmAssert(getMethodIndex(ctraits, 31) == 6); // exec
    AvmAssert(getMethodIndex(ctraits, 32) == 7); // sleep
    AvmAssert(getMethodIndex(ctraits, 33) == 8); // getAvmplusVersion
    AvmAssert(getMethodIndex(ctraits, 34) == 9); // getFeatures
    AvmAssert(getMethodIndex(ctraits, 35) == 10); // getRunmode
    AvmAssert(getMethodIndex(ctraits, 36) == 11); // trace
    AvmAssert(getMethodIndex(ctraits, 37) == 12); // write
    AvmAssert(getMethodIndex(ctraits, 38) == 13); // debugger
    AvmAssert(getMethodIndex(ctraits, 39) == 14); // isDebugger
    AvmAssert(getMethodIndex(ctraits, 40) == 15); // getNanosecondTimer
    AvmAssert(getMethodIndex(ctraits, 41) == 16); // getTimer
    AvmAssert(getMethodIndex(ctraits, 42) == 17); // private::getArgv
    AvmAssert(getMethodIndex(ctraits, 44) == 18); // readLine
    AvmAssert(getGetterIndex(ctraits, 45) == 19); // totalMemory
    AvmAssert(getGetterIndex(ctraits, 46) == 21); // freeMemory
    AvmAssert(getGetterIndex(ctraits, 47) == 23); // privateMemory
    AvmAssert(getMethodIndex(ctraits, 48) == 25); // forceFullCollection
    AvmAssert(getMethodIndex(ctraits, 49) == 26); // queueCollection
    AvmAssert(getMethodIndex(ctraits, 50) == 27); // http://www.example.com::nstest
    AvmAssert(getMethodIndex(ctraits, 51) == 28); // isGlobal
    AvmAssert(getGetterIndex(ctraits, 52) == 29); // swfVersion
    AvmAssert(getGetterIndex(ctraits, 53) == 31); // apiVersion
    AvmAssert(getMethodIndex(ctraits, 54) == 33); // disposeXML
    AvmAssert(getMethodIndex(ctraits, 55) == 34); // deopt
    AvmAssert(getMethodIndex(ctraits, 56) == 35); // pauseForGCIfCollectionImminent
    AvmAssert(getMethodIndex(ctraits, 57) == 36); // is64bit
    AvmAssert(getMethodIndex(ctraits, 58) == 37); // copy
    AvmAssert(getMethodIndex(ctraits, 59) == 38); // isIntptr
    AvmAssert(getMethodIndex(ctraits, 60) == 39); // runInSafepoint
    AvmAssert(getMethodIndex(ctraits, 61) == 40); // canonicalizeNumber
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
    AvmAssert(getSlotOffset(ctraits, 76) == (offsetof(avmplus::ShellCoreFriend1Class, m_slots_ShellCoreFriend1Class) + offsetof(avmplus_ShellCoreFriend1ClassSlots, m_private_foo)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ShellCoreFriend2Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) == kSlotsOffset_avmplus_ShellCoreFriend2Class);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ShellCoreFriend2Class) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 79) == (offsetof(avmplus::ShellCoreFriend2Class, m_slots_ShellCoreFriend2Class) + offsetof(avmplus_ShellCoreFriend2ClassSlots, m_private_bar)));
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
    AvmAssert(getSlotOffset(itraits, 85) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var)));
    AvmAssert(getSlotOffset(itraits, 86) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_0)));
    AvmAssert(getSlotOffset(itraits, 87) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 88) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5)));
    AvmAssert(getSlotOffset(itraits, 89) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_1)));
    AvmAssert(getSlotOffset(itraits, 90) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0_32)));
    AvmAssert(getSlotOffset(itraits, 91) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 92) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 93) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_AIR_1_5_1_FP_10_0_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 94) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_var_FP_10_0_32_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 95) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const)));
    AvmAssert(getSlotOffset(itraits, 96) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_0)));
    AvmAssert(getSlotOffset(itraits, 97) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 98) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5)));
    AvmAssert(getSlotOffset(itraits, 99) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_1)));
    AvmAssert(getSlotOffset(itraits, 100) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0_32)));
    AvmAssert(getSlotOffset(itraits, 101) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 102) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_0_FP_10_0)));
    AvmAssert(getSlotOffset(itraits, 103) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_AIR_1_5_1_FP_10_0_AIR_1_5_2)));
    AvmAssert(getSlotOffset(itraits, 104) == (offsetof(avmplus::public_classObject, m_slots_public_classObject) + offsetof(avmplus_public_classObjectSlots, m_public_const_FP_10_0_32_AIR_1_0_FP_10_0)));
    AvmAssert(getMethodIndex(itraits, 105) == 3); // public_function
    AvmAssert(getMethodIndex(itraits, 106) == 4); // public_function_AIR_1_0
    AvmAssert(getMethodIndex(itraits, 107) == 5); // public_function_FP_10_0
    AvmAssert(getMethodIndex(itraits, 108) == 6); // public_function_AIR_1_5
    AvmAssert(getMethodIndex(itraits, 109) == 7); // public_function_AIR_1_5_1
    AvmAssert(getMethodIndex(itraits, 110) == 8); // public_function_FP_10_0_32
    AvmAssert(getMethodIndex(itraits, 111) == 9); // public_function_AIR_1_5_2
    AvmAssert(getMethodIndex(itraits, 112) == 10); // public_function_AIR_1_0_FP_10_0
    AvmAssert(getMethodIndex(itraits, 113) == 11); // public_function_AIR_1_5_1_FP_10_0_AIR_1_5_2
    AvmAssert(getMethodIndex(itraits, 114) == 12); // public_function_FP_10_0_32_AIR_1_0_FP_10_0
    AvmAssert(getGetterIndex(itraits, 115) == 13); // public_getset
    AvmAssert(getGetterIndex(itraits, 116) == 15); // public_getset_AIR_1_0
    AvmAssert(getGetterIndex(itraits, 117) == 17); // public_getset_FP_10_0
    AvmAssert(getGetterIndex(itraits, 118) == 19); // public_getset_AIR_1_5
    AvmAssert(getGetterIndex(itraits, 119) == 21); // public_getset_AIR_1_5_1
    AvmAssert(getGetterIndex(itraits, 120) == 23); // public_getset_FP_10_0_32
    AvmAssert(getGetterIndex(itraits, 121) == 25); // public_getset_AIR_1_5_2
    AvmAssert(getGetterIndex(itraits, 122) == 27); // public_getset_AIR_1_0_FP_10_0
    AvmAssert(getGetterIndex(itraits, 123) == 29); // public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2
    AvmAssert(getGetterIndex(itraits, 124) == 31); // public_getset_FP_10_0_32_AIR_1_0_FP_10_0
    AvmAssert(getSetterIndex(itraits, 115) == 14); // public_getset
    AvmAssert(getSetterIndex(itraits, 116) == 16); // public_getset_AIR_1_0
    AvmAssert(getSetterIndex(itraits, 117) == 18); // public_getset_FP_10_0
    AvmAssert(getSetterIndex(itraits, 118) == 20); // public_getset_AIR_1_5
    AvmAssert(getSetterIndex(itraits, 119) == 22); // public_getset_AIR_1_5_1
    AvmAssert(getSetterIndex(itraits, 120) == 24); // public_getset_FP_10_0_32
    AvmAssert(getSetterIndex(itraits, 121) == 26); // public_getset_AIR_1_5_2
    AvmAssert(getSetterIndex(itraits, 122) == 28); // public_getset_AIR_1_0_FP_10_0
    AvmAssert(getSetterIndex(itraits, 123) == 30); // public_getset_AIR_1_5_1_FP_10_0_AIR_1_5_2
    AvmAssert(getSetterIndex(itraits, 124) == 32); // public_getset_FP_10_0_32_AIR_1_0_FP_10_0
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
    AvmAssert(getSlotOffset(itraits, 151) == (offsetof(avmplus::NativeBaseExtender1Object, m_slots_NativeBaseExtender1Object) + offsetof(avmplus_NativeBaseExtender1ObjectSlots, m_private_foo)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NativeBaseExtender2Class(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) == kSlotsOffset_avmplus_NativeBaseExtender2Object);
    MMGC_STATIC_ASSERT(offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::NativeBaseExtender2Object) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 153) == (offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) + offsetof(avmplus_NativeBaseExtender2ObjectSlots, m_private_foo)));
    AvmAssert(getSlotOffset(itraits, 154) == (offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) + offsetof(avmplus_NativeBaseExtender2ObjectSlots, m_private_foo1)));
    AvmAssert(getSlotOffset(itraits, 155) == (offsetof(avmplus::NativeBaseExtender2Object, m_slots_NativeBaseExtender2Object) + offsetof(avmplus_NativeBaseExtender2ObjectSlots, m_private_foo2)));
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
    AvmAssert(getSlotOffset(itraits, 374) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(itraits, 375) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(itraits, 376) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(itraits, 377) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_scriptID)));
    AvmAssert(getMethodIndex(itraits, 378) == 3); // toString
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) == kSlotsOffset_avmplus_SampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 380) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(itraits, 381) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ClassFactoryClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) == kSlotsOffset_avmplus_ClassFactoryClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ClassFactoryClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 387) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_StackFrameClass)));
    AvmAssert(getSlotOffset(ctraits, 388) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_SampleClass)));
    AvmAssert(getSlotOffset(ctraits, 389) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_DeleteObjectSampleClass)));
    AvmAssert(getSlotOffset(ctraits, 390) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_NewObjectSampleClass)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NewObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) == kSlotsOffset_avmplus_NewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 392) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 393) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_type)));
    AvmAssert(getGetterIndex(itraits, 394) == 3); // object
    AvmAssert(getGetterIndex(itraits, 395) == 5); // size
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DeleteObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == kSlotsOffset_avmplus_DeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 392) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 395) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_TraceClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) == kSlotsOffset_avmplus_TraceClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 431) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(ctraits, 432) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(ctraits, 433) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 434) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(ctraits, 435) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 436) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(ctraits, 437) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_LISTENER)));
    AvmAssert(getMethodIndex(ctraits, 438) == 5); // setLevel
    AvmAssert(getMethodIndex(ctraits, 439) == 6); // getLevel
    AvmAssert(getMethodIndex(ctraits, 440) == 7); // setListener
    AvmAssert(getMethodIndex(ctraits, 441) == 8); // getListener
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_EndianClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) == kSlotsOffset_avmplus_EndianClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::EndianClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 447) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_BIG_ENDIAN)));
    AvmAssert(getSlotOffset(ctraits, 448) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_LITTLE_ENDIAN)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_ShellWorkerClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass) == kSlotsOffset_avmshell_ShellWorkerClass);
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::ShellWorkerClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 485) == (offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass) + offsetof(avmshell_ShellWorkerClassSlots, m_private_m_current)));
    AvmAssert(getSlotOffset(ctraits, 486) == (offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass) + offsetof(avmshell_ShellWorkerClassSlots, m_private_m_eventChannels)));
    AvmAssert(getGetterIndex(ctraits, 482) == 5); // current
    AvmAssert(getMethodIndex(ctraits, 483) == 7); // handleLifecycleEvents
    AvmAssert(getMethodIndex(ctraits, 484) == 8); // pr
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) == kSlotsOffset_avmshell_ShellWorkerObject);
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::ShellWorkerObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 501) == (offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) + offsetof(avmshell_ShellWorkerObjectSlots, m_private_m_byteCode)));
    AvmAssert(getSlotOffset(itraits, 502) == (offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) + offsetof(avmshell_ShellWorkerObjectSlots, m_private_m_eventChannel)));
    AvmAssert(getSlotOffset(itraits, 503) == (offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) + offsetof(avmshell_ShellWorkerObjectSlots, m_private_m_listeners)));
    AvmAssert(getGetterIndex(itraits, 488) == 3); // state
    AvmAssert(getMethodIndex(itraits, 489) == 5); // startWithChannels
    AvmAssert(getMethodIndex(itraits, 490) == 6); // start
    AvmAssert(getMethodIndex(itraits, 491) == 7); // private::startInternal
    AvmAssert(getMethodIndex(itraits, 492) == 8); // isParentOf
    AvmAssert(getGetterIndex(itraits, 493) == 9); // isPrimordial
    AvmAssert(getMethodIndex(itraits, 494) == 11); // private::newEventChannel
    AvmAssert(getMethodIndex(itraits, 495) == 12); // setStartArgument
    AvmAssert(getMethodIndex(itraits, 496) == 13); // getStartArgument
    AvmAssert(getMethodIndex(itraits, 497) == 14); // stop
    AvmAssert(getMethodIndex(itraits, 498) == 15); // addEventListener
    AvmAssert(getMethodIndex(itraits, 499) == 16); // private::dispatchEvent
    AvmAssert(getGetterIndex(itraits, 500) == 17); // descriptor
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_WorkerEventClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass) == kSlotsOffset_avmplus_WorkerEventClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::WorkerEventClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 510) == (offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass) + offsetof(avmplus_WorkerEventClassSlots, m_WORKER_STATE)));
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) == kSlotsOffset_avmplus_WorkerEventObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::WorkerEventObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 514) == (offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) + offsetof(avmplus_WorkerEventObjectSlots, m_private_m_previousState)));
    AvmAssert(getSlotOffset(itraits, 515) == (offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) + offsetof(avmplus_WorkerEventObjectSlots, m_private_m_currentState)));
    AvmAssert(getSlotOffset(itraits, 516) == (offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) + offsetof(avmplus_WorkerEventObjectSlots, m_flash_system_m_target)));
    AvmAssert(getGetterIndex(itraits, 511) == 3); // currentState
    AvmAssert(getGetterIndex(itraits, 512) == 5); // previousState
    AvmAssert(getGetterIndex(itraits, 513) == 7); // target
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_ShellWorkerDomainClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass) == kSlotsOffset_avmshell_ShellWorkerDomainClass);
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::ShellWorkerDomainClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 525) == (offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass) + offsetof(avmshell_ShellWorkerDomainClassSlots, m_private_m_current)));
    AvmAssert(getGetterIndex(ctraits, 482) == 5); // current
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_PromiseStateClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass) == kSlotsOffset_avmplus_PromiseStateClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::PromiseStateClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 535) == (offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass) + offsetof(avmplus_PromiseStateClassSlots, m_NEW)));
    AvmAssert(getSlotOffset(ctraits, 536) == (offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass) + offsetof(avmplus_PromiseStateClassSlots, m_RECEIVED)));
    AvmAssert(getSlotOffset(ctraits, 537) == (offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass) + offsetof(avmplus_PromiseStateClassSlots, m_BROKEN)));
    AvmAssert(getSlotOffset(ctraits, 538) == (offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass) + offsetof(avmplus_PromiseStateClassSlots, m_EXCEPTION)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_PromiseHelperClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) == kSlotsOffset_avmplus_PromiseHelperClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::PromiseHelperClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 555) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_CALL_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 556) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_RESOLUTION_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 557) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_CALLBACK_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 558) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_GETPROP_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 559) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_DESTROY_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 560) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_DESTROY_DELAYED_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 561) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_SUCCESS_RESPONSE)));
    AvmAssert(getSlotOffset(ctraits, 562) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_EXCEPTION_RESPONSE)));
    AvmAssert(getSlotOffset(ctraits, 573) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_m_empty_promises)));
    AvmAssert(getSlotOffset(ctraits, 574) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_m_local_requests)));
    AvmAssert(getSlotOffset(ctraits, 576) == (offsetof(avmplus::PromiseHelperClass, m_slots_PromiseHelperClass) + offsetof(avmplus_PromiseHelperClassSlots, m_m_delayed_requests)));
    AvmAssert(getGetterIndex(ctraits, 563) == 5); // currentGiid
    AvmAssert(getMethodIndex(ctraits, 564) == 7); // getPromiseOwnerGiid
    AvmAssert(getMethodIndex(ctraits, 565) == 8); // setPromiseOwnerGiid
    AvmAssert(getMethodIndex(ctraits, 566) == 9); // getPromiseGid
    AvmAssert(getMethodIndex(ctraits, 567) == 10); // setPromiseGid
    AvmAssert(getMethodIndex(ctraits, 568) == 11); // isPromiseEmpty
    AvmAssert(getMethodIndex(ctraits, 569) == 12); // schedulePromiseCollection
    AvmAssert(getMethodIndex(ctraits, 570) == 13); // retargetIncChannel
    AvmAssert(getMethodIndex(ctraits, 571) == 14); // retargetOutChannel
    AvmAssert(getMethodIndex(ctraits, 572) == 15); // isPromiseCreatedLocally
    AvmAssert(getMethodIndex(ctraits, 577) == 16); // flash.system::waitForAnySend
    AvmAssert(getMethodIndex(ctraits, 484) == 17); // pr
    AvmAssert(getMethodIndex(ctraits, 578) == 18); // praddr
    AvmAssert(getMethodIndex(ctraits, 579) == 19); // breakOn
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_PromiseClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseClass, m_slots_PromiseClass) == kSlotsOffset_avmplus_PromiseClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseClass, m_slots_PromiseClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::PromiseClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 535) == (offsetof(avmplus::PromiseClass, m_slots_PromiseClass) + offsetof(avmplus_PromiseClassSlots, m_NEW)));
    AvmAssert(getSlotOffset(ctraits, 536) == (offsetof(avmplus::PromiseClass, m_slots_PromiseClass) + offsetof(avmplus_PromiseClassSlots, m_RECEIVED)));
    AvmAssert(getSlotOffset(ctraits, 537) == (offsetof(avmplus::PromiseClass, m_slots_PromiseClass) + offsetof(avmplus_PromiseClassSlots, m_BROKEN)));
    AvmAssert(getSlotOffset(ctraits, 538) == (offsetof(avmplus::PromiseClass, m_slots_PromiseClass) + offsetof(avmplus_PromiseClassSlots, m_EXCEPTION)));
    AvmAssert(getSlotOffset(ctraits, 678) == (offsetof(avmplus::PromiseClass, m_slots_PromiseClass) + offsetof(avmplus_PromiseClassSlots, m_private_DESTROY_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 679) == (offsetof(avmplus::PromiseClass, m_slots_PromiseClass) + offsetof(avmplus_PromiseClassSlots, m_private_DESTROY_DELAYED_REQUEST)));
    AvmAssert(getSlotOffset(ctraits, 680) == (offsetof(avmplus::PromiseClass, m_slots_PromiseClass) + offsetof(avmplus_PromiseClassSlots, m_private_m_empty_requests)));
    AvmAssert(getMethodIndex(ctraits, 669) == 5); // wrap
    AvmAssert(getMethodIndex(ctraits, 670) == 6); // empty
    AvmAssert(getMethodIndex(ctraits, 671) == 7); // private::resolveLocal
    AvmAssert(getMethodIndex(ctraits, 672) == 8); // registerEmptyPromise
    AvmAssert(getMethodIndex(ctraits, 673) == 9); // private::printEmptyPromises
    AvmAssert(getMethodIndex(ctraits, 674) == 10); // private::create
    AvmAssert(getMethodIndex(ctraits, 675) == 11); // private::createLocal
    AvmAssert(getMethodIndex(ctraits, 676) == 12); // notifyOwner
    AvmAssert(getMethodIndex(ctraits, 677) == 13); // private::notifyEmptyOwners
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseObject, m_slots_PromiseObject) == kSlotsOffset_avmplus_PromiseObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::PromiseObject, m_slots_PromiseObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::PromiseObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 684) == (offsetof(avmplus::PromiseObject, m_slots_PromiseObject) + offsetof(avmplus_PromiseObjectSlots, m_flash_system_m_out)));
    AvmAssert(getSlotOffset(itraits, 685) == (offsetof(avmplus::PromiseObject, m_slots_PromiseObject) + offsetof(avmplus_PromiseObjectSlots, m_flash_system_m_inc)));
    AvmAssert(getSlotOffset(itraits, 686) == (offsetof(avmplus::PromiseObject, m_slots_PromiseObject) + offsetof(avmplus_PromiseObjectSlots, m_flash_system_intern_m_resolved)));
    AvmAssert(getSlotOffset(itraits, 687) == (offsetof(avmplus::PromiseObject, m_slots_PromiseObject) + offsetof(avmplus_PromiseObjectSlots, m_private_m_global)));
    AvmAssert(getSlotOffset(itraits, 688) == (offsetof(avmplus::PromiseObject, m_slots_PromiseObject) + offsetof(avmplus_PromiseObjectSlots, m_flash_system_intern_m_state)));
    AvmAssert(getSlotOffset(itraits, 689) == (offsetof(avmplus::PromiseObject, m_slots_PromiseObject) + offsetof(avmplus_PromiseObjectSlots, m_private_m_empty)));
    AvmAssert(getSlotOffset(itraits, 690) == (offsetof(avmplus::PromiseObject, m_slots_PromiseObject) + offsetof(avmplus_PromiseObjectSlots, m_private_m_async)));
    AvmAssert(getMethodIndex(itraits, 681) == 3); // isOwnedLocally
    AvmAssert(getMethodIndex(itraits, 682) == 4); // private::callProperty
    AvmAssert(getMethodIndex(itraits, 683) == 5); // private::getProperty
    AvmAssert(getGetterIndex(itraits, 691) == 6); // async
    AvmAssert(getMethodIndex(itraits, 692) == 8); // resolve
    AvmAssert(getMethodIndex(itraits, 693) == 9); // when
    AvmAssert(getMethodIndex(itraits, 694) == 10); // receive
    AvmAssert(getMethodIndex(itraits, 695) == 11); // delayCollection
    AvmAssert(getGetterIndex(itraits, 488) == 12); // state
    AvmAssert(getMethodIndex(itraits, 696) == 14); // getPID
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_RemoteProxyClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass) == kSlotsOffset_avmplus_RemoteProxyClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::RemoteProxyClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 535) == (offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass) + offsetof(avmplus_RemoteProxyClassSlots, m_NEW)));
    AvmAssert(getSlotOffset(ctraits, 536) == (offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass) + offsetof(avmplus_RemoteProxyClassSlots, m_RECEIVED)));
    AvmAssert(getSlotOffset(ctraits, 537) == (offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass) + offsetof(avmplus_RemoteProxyClassSlots, m_BROKEN)));
    AvmAssert(getSlotOffset(ctraits, 538) == (offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass) + offsetof(avmplus_RemoteProxyClassSlots, m_EXCEPTION)));
    AvmAssert(getSlotOffset(ctraits, 773) == (offsetof(avmplus::RemoteProxyClass, m_slots_RemoteProxyClass) + offsetof(avmplus_RemoteProxyClassSlots, m_m_remote_proxies)));
    AvmAssert(getMethodIndex(ctraits, 774) == 5); // create
    AvmAssert(getGetterIndex(ctraits, 775) == 6); // m_workerClass
    AvmAssert(getMethodIndex(ctraits, 776) == 8); // callProp
    AvmAssert(getMethodIndex(ctraits, 777) == 9); // getProp
    AvmAssert(getMethodIndex(ctraits, 778) == 10); // checkForCallRequestsConditional
    AvmAssert(getMethodIndex(ctraits, 779) == 11); // checkForCallRequests
    MMGC_STATIC_ASSERT(offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) == kSlotsOffset_avmplus_RemoteProxyObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::RemoteProxyObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 780) == (offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) + offsetof(avmplus_RemoteProxyObjectSlots, m_m_gpid)));
    AvmAssert(getSlotOffset(itraits, 781) == (offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) + offsetof(avmplus_RemoteProxyObjectSlots, m_m_out)));
    AvmAssert(getSlotOffset(itraits, 782) == (offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) + offsetof(avmplus_RemoteProxyObjectSlots, m_m_inc)));
    AvmAssert(getSlotOffset(itraits, 783) == (offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) + offsetof(avmplus_RemoteProxyObjectSlots, m_m_resolved)));
    AvmAssert(getSlotOffset(itraits, 784) == (offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) + offsetof(avmplus_RemoteProxyObjectSlots, m_m_global)));
    AvmAssert(getSlotOffset(itraits, 785) == (offsetof(avmplus::RemoteProxyObject, m_slots_RemoteProxyObject) + offsetof(avmplus_RemoteProxyObjectSlots, m_m_state)));
    AvmAssert(getMethodIndex(itraits, 786) == 3); // triggerDelayedCollection
    AvmAssert(getMethodIndex(itraits, 787) == 4); // handleResolution
    AvmAssert(getMethodIndex(itraits, 788) == 5); // handleCallback
    AvmAssert(getMethodIndex(itraits, 789) == 6); // private::flattenPromise
    AvmAssert(getMethodIndex(itraits, 790) == 7); // handleCall
    AvmAssert(getMethodIndex(itraits, 791) == 8); // handleGetProp
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_EnvelopeClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
#endif // DEBUG


AVMTHUNK_BEGIN_NATIVE_TABLES(shell_toplevel)

    AVMTHUNK_BEGIN_NATIVE_METHODS(shell_toplevel)
        AVMTHUNK_NATIVE_METHOD(avmplus_MI_plus, ::avmshell::MIObjectImpl::plus)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exit, avmshell::SystemClass::exit)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exec, avmshell::SystemClass::exec)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_sleep, avmshell::SystemClass::sleep)
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
        AVMTHUNK_NATIVE_METHOD(avmplus_System_copy, avmshell::SystemClass::copy)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isIntptr, avmshell::SystemClass::isIntptr)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_runInSafepoint, avmshell::SystemClass::runInSafepoint)
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
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_pr, avmshell::ShellWorkerClass::pr)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_state_get, avmshell::ShellWorkerObject::get_state)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_startWithChannels, avmshell::ShellWorkerObject::startWithChannels)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_private_startInternal, avmshell::ShellWorkerObject::startInternal)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_isParentOf, avmshell::ShellWorkerObject::isParentOf)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_isPrimordial_get, avmshell::ShellWorkerObject::get_isPrimordial)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_private_newEventChannel, avmshell::ShellWorkerObject::newEventChannel)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_setStartArgument, avmshell::ShellWorkerObject::setStartArgument)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_getStartArgument, avmshell::ShellWorkerObject::getStartArgument)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_stop, avmshell::ShellWorkerObject::stop)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_descriptor_get, avmshell::ShellWorkerObject::get_descriptor)
        AVMTHUNK_NATIVE_METHOD(flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal, avmshell::ShellWorkerDomainObject::createWorkerFromByteArrayInternal)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_currentGiid_get, avmplus::PromiseHelperClass::get_currentGiid)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_getPromiseOwnerGiid, avmplus::PromiseHelperClass::getPromiseOwnerGiid)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_setPromiseOwnerGiid, avmplus::PromiseHelperClass::setPromiseOwnerGiid)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_getPromiseGid, avmplus::PromiseHelperClass::getPromiseGid)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_setPromiseGid, avmplus::PromiseHelperClass::setPromiseGid)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_isPromiseEmpty, avmplus::PromiseHelperClass::isPromiseEmpty)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_schedulePromiseCollection, avmplus::PromiseHelperClass::schedulePromiseCollection)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_retargetIncChannel, avmplus::PromiseHelperClass::retargetIncChannel)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_retargetOutChannel, avmplus::PromiseHelperClass::retargetOutChannel)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_flash_system_waitForAnySend, avmplus::PromiseHelperClass::waitForAnySend)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_pr, avmplus::PromiseHelperClass::pr)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_praddr, avmplus::PromiseHelperClass::praddr)
        AVMTHUNK_NATIVE_METHOD(flash_system_PromiseHelper_breakOn, avmplus::PromiseHelperClass::breakOn)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_registerEmptyPromise, avmplus::PromiseClass::registerEmptyPromise)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_private_printEmptyPromises, avmplus::PromiseClass::printEmptyPromises)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_private_create, avmplus::PromiseClass::create)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_private_createLocal, avmplus::PromiseClass::createLocal)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_notifyOwner, avmplus::PromiseClass::notifyOwner)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_private_notifyEmptyOwners, avmplus::PromiseClass::notifyEmptyOwners)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_isOwnedLocally, avmplus::PromiseObject::isOwnedLocally)
        AVMTHUNK_NATIVE_METHOD(flash_system_Promise_delayCollection, avmplus::PromiseObject::delayCollection)
        AVMTHUNK_NATIVE_METHOD(flash_system_RemoteProxy_create, avmplus::RemoteProxyClass::create)
        AVMTHUNK_NATIVE_METHOD(flash_system_RemoteProxy_m_workerClass_get, avmplus::RemoteProxyClass::get_m_workerClass)
        AVMTHUNK_NATIVE_METHOD(flash_system_RemoteProxy_callProp, avmplus::RemoteProxyClass::callProp)
        AVMTHUNK_NATIVE_METHOD(flash_system_RemoteProxy_getProp, avmplus::RemoteProxyClass::getProp)
        AVMTHUNK_NATIVE_METHOD(flash_system_RemoteProxy_triggerDelayedCollection, avmplus::RemoteProxyObject::triggerDelayedCollection)
        AVMTHUNK_NATIVE_METHOD(flash_system_Envelope_name_get, avmshell::EnvelopeObject::get_name)
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
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_Worker, ShellWorkerClass, avmshell::ShellWorkerClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerClass, avmshell::ShellWorkerObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_WorkerEvent, WorkerEventClass, avmplus::WorkerEventClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_WorkerEventClass, avmplus::WorkerEventObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_WorkerEventObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_WorkerDomain, ShellWorkerDomainClass, avmshell::ShellWorkerDomainClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerDomainClass, avmshell::ShellWorkerDomainObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerDomainObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_PromiseState, PromiseStateClass, avmplus::PromiseStateClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_PromiseStateClass, avmplus::PromiseStateObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_PromiseStateObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_PromiseHelper, PromiseHelperClass, avmplus::PromiseHelperClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_PromiseHelperClass, avmplus::PromiseHelperObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_PromiseHelperObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_Promise, PromiseClass, avmplus::PromiseClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_PromiseClass, avmplus::PromiseObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_PromiseObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_RemoteProxy, RemoteProxyClass, avmplus::RemoteProxyClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_RemoteProxyClass, avmplus::RemoteProxyObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_RemoteProxyObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_Envelope, EnvelopeClass, avmshell::EnvelopeClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_EnvelopeClass, avmshell::EnvelopeObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_EnvelopeObject, false, false, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[29864] = {
  16,   0,  46,   0,  14,  42, 101,   0,   2,   1,   3,   4, 255, 255,   3,   5,
   6,   7,   8, 128,   8,   0,   8,   0,   0,   0,   0,   0,   0, 232,  63,   0,
   0,   0,   0,   0,   0, 240,  63,   0,   0,   0,   0,   0,   0,   0,  64,   0,
   0,   0,   0,   0,   0,   8,  64,   0,   0,   0,   0,   0,   0,  16,  64,   0,
   0,   0,   0,   0,   0,  20,  64,   0,   0,   0,   0,   0,   0,  24,  64, 174,
   4,   0,   4, 118, 111, 105, 100,   7,  66, 111, 111, 108, 101,  97, 110,   6,
  83, 121, 115, 116, 101, 109,  19, 115, 104, 101, 108, 108,  95, 116, 111, 112,
 108, 101, 118, 101, 108,  46,  97, 115,  36,  49,   7,  97, 118, 109, 112, 108,
 117, 115,   5, 100, 101, 111, 112, 116,   8, 114, 101,  97, 100,  76, 105, 110,
 101,   6,  83, 116, 114, 105, 110, 103,   8, 103, 101, 116,  84, 105, 109, 101,
 114,   4, 117, 105, 110, 116,   5, 116, 114,  97,  99, 101,   6,  68, 111, 109,
  97, 105, 110,  13,  99, 117, 114, 114, 101, 110, 116,  68, 111, 109,  97, 105,
 110,   8, 103, 101, 116,  67, 108,  97, 115, 115,   5,  67, 108,  97, 115, 115,
   8, 100, 101,  98, 117, 103, 103, 101, 114,  16,  97, 118, 109, 112, 108, 117,
 115,  58,  73,  84, 101, 115, 116, 238, 138, 148,   4, 116, 101, 115, 116,   5,
  73,  84, 101, 115, 116,  13,  97, 118, 109, 112, 108, 117, 115,  58,  67,  84,
 101, 115, 116,   3, 238, 138, 148,   5,  67,  84, 101, 115, 116,   6,  79,  98,
 106, 101,  99, 116,  10,  97, 118, 109, 112, 108, 117, 115,  58,  77,  73,   6,
  78, 117, 109,  98, 101, 114,   4, 112, 108, 117, 115,   2,  77,  73,  14,  97,
 118, 109, 112, 108, 117, 115,  58,  83, 121, 115, 116, 101, 109,   4,  97, 114,
 103, 118,   7, 103, 101, 116,  65, 114, 103, 118,   3, 105, 110, 116,   5,  65,
 114, 114,  97, 121,   3,  88,  77,  76,   8,  70, 117, 110,  99, 116, 105, 111,
 110,   4, 101, 120, 105, 116,   3, 102, 111, 111,   4, 101, 120, 101,  99,   3,
  98,  97, 114,   4,  97, 116, 116, 114,   8, 119, 104,  97, 116, 101, 118, 101,
 114,   5, 115, 108, 101, 101, 112,  17, 103, 101, 116,  65, 118, 109, 112, 108,
 117, 115,  86, 101, 114, 115, 105, 111, 110,  11, 103, 101, 116,  70, 101,  97,
 116, 117, 114, 101, 115,  10, 103, 101, 116,  82, 117, 110, 109, 111, 100, 101,
   5, 119, 114, 105, 116, 101,  10, 105, 115,  68, 101,  98, 117, 103, 103, 101,
 114,  18, 103, 101, 116,  78,  97, 110, 111, 115, 101,  99, 111, 110, 100,  84,
 105, 109, 101, 114,  11, 116, 111, 116,  97, 108,  77, 101, 109, 111, 114, 121,
  10, 102, 114, 101, 101,  77, 101, 109, 111, 114, 121,  13, 112, 114, 105, 118,
  97, 116, 101,  77, 101, 109, 111, 114, 121,  19, 102, 111, 114,  99, 101,  70,
 117, 108, 108,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  15, 113, 117,
 101, 117, 101,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  22, 104, 116,
 116, 112,  58,  47,  47, 119, 119, 119,  46, 101, 120,  97, 109, 112, 108, 101,
  46,  99, 111, 109,   6, 110, 115, 116, 101, 115, 116,   8, 105, 115,  71, 108,
 111,  98,  97, 108,  10, 115, 119, 102,  86, 101, 114, 115, 105, 111, 110,  10,
  97, 112, 105,  86, 101, 114, 115, 105, 111, 110,  10, 100, 105, 115, 112, 111,
 115, 101,  88,  77,  76,  30, 112,  97, 117, 115, 101,  70, 111, 114,  71,  67,
  73, 102,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  73, 109, 109, 105,
 110, 101, 110, 116,   7, 105, 115,  54,  52,  98, 105, 116,   4,  99, 111, 112,
 121,   8, 105, 115,  73, 110, 116, 112, 116, 114,  14, 114, 117, 110,  73, 110,
  83,  97, 102, 101, 112, 111, 105, 110, 116,  18,  99,  97, 110, 111, 110, 105,
  99,  97, 108, 105, 122, 101,  78, 117, 109,  98, 101, 114,  12,  97, 118, 109,
 112, 108, 117, 115,  58,  70, 105, 108, 101,  11, 102, 108,  97, 115, 104,  46,
 117, 116, 105, 108, 115,   9,  66, 121, 116, 101,  65, 114, 114,  97, 121,   6,
 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100,  13, 114, 101,  97, 100,
  66, 121, 116, 101,  65, 114, 114,  97, 121,  14, 119, 114, 105, 116, 101,  66,
 121, 116, 101,  65, 114, 114,  97, 121,   4,  70, 105, 108, 101,  21,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  65,  98, 115, 116, 114,  97,  99, 116,  66,
  97, 115, 101,   8,  97, 118, 109, 115, 104, 101, 108, 108,  12,  65,  98, 115,
 116, 114,  97,  99, 116,  66,  97, 115, 101,  23,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115,
 101,  14,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,
  31,  97, 118, 109, 115, 104, 101, 108, 108,  58,  65,  98, 115, 116, 114,  97,
  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,
  22,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99,
 116, 101, 100,  66,  97, 115, 101,  18,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  67, 104, 101,  99, 107,  66,  97, 115, 101,   9,  67, 104, 101,  99, 107,
  66,  97, 115, 101,  19,  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97,
 116, 105, 118, 101,  66,  97, 115, 101,  10,  78,  97, 116, 105, 118, 101,  66,
  97, 115, 101,  22,  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116,
 105, 118, 101,  66,  97, 115, 101,  65,  83,  51,  13,  78,  97, 116, 105, 118,
 101,  66,  97, 115, 101,  65,  83,  51,  25,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  83, 104, 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101, 110,
 100,  49,  16,  83, 104, 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101,
 110, 100,  49,  25,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 104, 101,
 108, 108,  67, 111, 114, 101,  70, 114, 105, 101, 110, 100,  50,  16,  83, 104,
 101, 108, 108,  67, 111, 114, 101,  70, 114, 105, 101, 110, 100,  50,  25, 102,
 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  67,  97, 112,  97,
  98, 105, 108, 105, 116, 105, 101, 115,   7,  65,  86,  77,  80, 108, 117, 115,
  12, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  10, 112, 108,
  97, 121, 101, 114,  84, 121, 112, 101,  12,  67,  97, 112,  97,  98, 105, 108,
 105, 116, 105, 101, 115,  21,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112,
 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  10, 112, 117,  98, 108,
 105,  99,  95, 118,  97, 114,   3, 238, 138, 149,  18, 112, 117,  98, 108, 105,
  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  48,   3,  65,  80,
  73,   3,  54,  54,  49,   3, 238, 138, 150,  18, 112, 117,  98, 108, 105,  99,
  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,   3,  54,  54,  50,
   3, 238, 138, 151,  18, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,
  65,  73,  82,  95,  49,  95,  53,   3,  54,  54,  51,   3, 238, 138, 152,  20,
 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  49,   3,  54,  54,  52,   3, 238, 138, 153,  21, 112, 117,  98,
 108, 105,  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  51,  50,   3,  54,  54,  53,   3, 238, 138, 154,  20, 112, 117,  98, 108, 105,
  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,   3,
  54,  54,  54,  26, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,
  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  38, 112,
 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  50,  37, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,
  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  12, 112, 117,  98, 108,
 105,  99,  95,  99, 111, 110, 115, 116,  20, 112, 117,  98, 108, 105,  99,  95,
  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  48,  20, 112, 117,
  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  70,  80,  95,  49,  48,
  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,
  65,  73,  82,  95,  49,  95,  53,  22, 112, 117,  98, 108, 105,  99,  95,  99,
 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  23, 112,
 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  70,  80,  95,  49,
  48,  95,  48,  95,  51,  50,  22, 112, 117,  98, 108, 105,  99,  95,  99, 111,
 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  28, 112, 117,
  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,
  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  40, 112, 117,  98, 108, 105,
  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  50,  39, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,
  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  15, 112, 117,  98, 108,
 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  23, 112, 117,  98, 108,
 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,
  49,  95,  48,  23, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116,
 105, 111, 110,  95,  70,  80,  95,  49,  48,  95,  48,  23, 112, 117,  98, 108,
 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,
  49,  95,  53,  25, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116,
 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  26, 112, 117,
  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  70,  80,
  95,  49,  48,  95,  48,  95,  51,  50,  25, 112, 117,  98, 108, 105,  99,  95,
 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  50,  31, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,
  95,  48,  43, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105,
 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  42, 112,
 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  70,
  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,
  48,  95,  70,  80,  95,  49,  48,  95,  48,  13, 112, 117,  98, 108, 105,  99,
  95, 103, 101, 116, 115, 101, 116,  21, 112, 117,  98, 108, 105,  99,  95, 103,
 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  48,  21, 112, 117,
  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,  95,  49,
  48,  95,  48,  21, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101,
 116,  95,  65,  73,  82,  95,  49,  95,  53,  23, 112, 117,  98, 108, 105,  99,
  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  49,  24, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  23, 112, 117,  98, 108, 105,
  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  50,  29, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,
  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,
  41, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  40, 112, 117,  98, 108, 105,
  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,
  48,  95,  48,  12, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,
  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  20, 112,
 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,
  49,  95,  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,
  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,
  80,  95,  49,  48,  95,  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,
  95,  49,  95,  53,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  95,  65,  73,  82,  95,  49,  95,  53,  31,  97, 118, 109, 115, 104, 101,
 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  49,  22, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,
  32,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,
  50,  23, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,
  80,  95,  49,  48,  95,  48,  95,  51,  50,  31,  97, 118, 109, 115, 104, 101,
 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  65,  73,  82,  95,  49,  95,  53,  95,  50,  22, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,
  37,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,
  80,  95,  49,  48,  95,  48,  28, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,
  48,  95,  48,  49,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  50,  40, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97,
 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  48,  97,
 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,
  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  39,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  51,  50,  95,  65,  73,  82,  95,  49,  95,  48,  95,
  70,  80,  95,  49,  48,  95,  48,  16, 112, 117,  98, 108, 105,  99,  95, 105,
 110, 116, 101, 114, 102,  97,  99, 101,  24, 112, 117,  98, 108, 105,  99,  95,
 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,
  48,  24, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,
  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  24, 112, 117,  98, 108, 105,
  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,
  49,  95,  53,  26, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114,
 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  27, 112,
 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  26, 112, 117,  98, 108, 105,
  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  50,  32, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116,
 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,
  80,  95,  49,  48,  95,  48,  44, 112, 117,  98, 108, 105,  99,  95, 105, 110,
 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  50,  43, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114,
 102,  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,
  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  37,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  83,
 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99,
 116,  66,  97, 115, 101,  28,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99,
 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97,
 115, 101,  31,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 117,  98,  99,
 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97,
 115, 101,  22,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115,
 116, 114,  97,  99, 116,  66,  97, 115, 101,  39,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115,
 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115,
 101,  30,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,
  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,
  33,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 117,  98,  99, 108,  97,
 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97,
 115, 101,  24,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  47,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,
  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  38,  78,  97, 116, 105,
 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116,
 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97,
 115, 101,  41,  97, 118, 109, 115, 104, 101, 108, 108,  58,  83, 117,  98,  99,
 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101,
 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  32,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82,
 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  28,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  66,  97, 115,
 101,  69, 120, 116, 101, 110, 100, 101, 114,  49,  19,  78,  97, 116, 105, 118,
 101,  66,  97, 115, 101,  69, 120, 116, 101, 110, 100, 101, 114,  49,  28,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  78,  97, 116, 105, 118, 101,  66,  97,
 115, 101,  69, 120, 116, 101, 110, 100, 101, 114,  50,   4, 102, 111, 111,  49,
   4, 102, 111, 111,  50,  19,  78,  97, 116, 105, 118, 101,  66,  97, 115, 101,
  69, 120, 116, 101, 110, 100, 101, 114,  50,  11,  65,  80,  73,  95,  65,  73,
  82,  95,  49,  95,  48,  11,  65,  80,  73,  95,  70,  80,  95,  49,  48,  95,
  48,  11,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  13,  65,  80,
  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  14,  65,  80,  73,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  13,  65,  80,  73,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  50,  10, 110, 115,  95, 101, 120,  97, 109,
 112, 108, 101,   6, 110,  97, 116, 105, 118, 101,   3,  99, 108, 115,  19,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  67, 108,  97,
 115, 115,   8, 105, 110, 115, 116,  97, 110,  99, 101,  20,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,  98, 106, 101,  99, 116,
   7, 109, 101, 116, 104, 111, 100, 115,  24,  58,  58,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  58,  77,  73,  79,  98, 106, 101,  99, 116,  73, 109, 112,
 108,  10,  97, 118, 109, 112, 108, 117, 115, 238, 138, 148,  23,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 121, 115, 116, 101, 109,  67,
 108,  97, 115, 115,   7,  99, 108,  97, 115, 115, 103,  99,   5, 101, 120,  97,
  99, 116,   4,  97, 117, 116, 111,   9,  99, 111, 110, 115, 116, 114, 117,  99,
 116,   4, 110, 111, 110, 101,  21,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  70, 105, 108, 101,  67, 108,  97, 115, 115,  11,  97, 118, 109,
 115, 104, 101, 108, 108, 238, 138, 148,  29,  58,  58,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115,
 101,  67, 108,  97, 115, 115,  30,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  79,
  98, 106, 101,  99, 116,   2, 103,  99,   8,  97,  98, 115, 116, 114,  97,  99,
 116,  45,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97,
 116, 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98,
 115, 116, 114,  97,  99, 116,  66,  97, 115, 101,  67, 108,  97, 115, 115,  46,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105,
 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115, 116,
 114,  97,  99, 116,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  31,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  82, 101, 115, 116, 114,
 105,  99, 116, 101, 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  32,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  82, 101, 115, 116, 114,
 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  10,
 114, 101, 115, 116, 114, 105,  99, 116, 101, 100,  47,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101,
 100,  66,  97, 115, 101,  67, 108,  97, 115, 115,  48,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,
  99, 108,  97, 115, 115,  79, 102,  82, 101, 115, 116, 114, 105,  99, 116, 101,
 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  39,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  65,  98, 115, 116, 114,  97,  99, 116,
  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  67, 108,
  97, 115, 115,  40,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116,
 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99, 116,  19,  97,  98, 115,
 116, 114,  97,  99, 116,  45, 114, 101, 115, 116, 114, 105,  99, 116, 101, 100,
  55,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116,
 105, 118, 101,  83, 117,  98,  99, 108,  97, 115, 115,  79, 102,  65,  98, 115,
 116, 114,  97,  99, 116,  82, 101, 115, 116, 114, 105,  99, 116, 101, 100,  66,
  97, 115, 101,  67, 108,  97, 115, 115,  56,  58,  58,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  83, 117,  98,  99, 108,
  97, 115, 115,  79, 102,  65,  98, 115, 116, 114,  97,  99, 116,  82, 101, 115,
 116, 114, 105,  99, 116, 101, 100,  66,  97, 115, 101,  79,  98, 106, 101,  99,
 116,  26,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67, 104,
 101,  99, 107,  66,  97, 115, 101,  67, 108,  97, 115, 115,  27,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  67, 104, 101,  99, 107,  66,  97,
 115, 101,  79,  98, 106, 101,  99, 116,   5,  99, 104, 101,  99, 107,  27,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118,
 101,  66,  97, 115, 101,  67, 108,  97, 115, 115,  28,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  78,  97, 116, 105, 118, 101,  66,  97, 115,
 101,  79,  98, 106, 101,  99, 116,   6, 102, 114, 105, 101, 110, 100,  19,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 104, 101, 108, 108,  67, 111,
 114, 101,  43,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 104, 101,
 108, 108,  67, 111, 114, 101,  44,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  83, 104, 101, 108, 108,  84, 111, 112, 108, 101, 118, 101, 108,  15, 102,
 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109, 238, 138, 148,  14, 103,
 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,  97, 109, 101,   5, 112, 114,
 105, 110, 116,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 149,  11,
  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 150,  11,  97, 118, 109, 115,
 104, 101, 108, 108, 238, 138, 151,  11,  97, 118, 109, 115, 104, 101, 108, 108,
 238, 138, 152,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 153,  11,
  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 154,  14,  97, 118, 109, 112,
 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,   4, 105, 110, 105, 116,  11,
  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,  50,   9, 108, 111,  97, 100,
  66, 121, 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,  77,  65,  73,  78,
  95,  77,  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,  84,  72,   4, 108,
 111,  97, 100,  12, 100, 111, 109,  97, 105, 110,  77, 101, 109, 111, 114, 121,
  11,  68, 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,  12,  68, 111, 109,
  97, 105, 110,  79,  98, 106, 101,  99, 116,   5,  81,  78,  97, 109, 101,  19,
  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  12,  83,  97, 109, 112, 108, 101, 114,  46,  97, 115,  36,  51,
  13, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  11,  95,
 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,   1, 102,   1, 101,   3, 114,
 101, 116,  19,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97,
 108, 108,  98,  97,  99, 107,   7, 119, 114,  97, 112, 112, 101, 114,  24, 102,
 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83, 116,  97,
  99, 107,  70, 114,  97, 109, 101,   4, 110,  97, 109, 101,   2,  40,  41,   4,
 102, 105, 108, 101,   1,  91,   1,  58,   4, 108, 105, 110, 101,   1,  93,   8,
 115,  99, 114, 105, 112, 116,  73,  68,   8, 116, 111,  83, 116, 114, 105, 110,
 103,  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  20, 102, 108,  97,
 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,  97, 109, 112, 108,
 101,   4, 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,   6,  83,  97, 109,
 112, 108, 101,  26, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101,
 114,  58,  67, 108,  97, 115, 115,  70,  97,  99, 116, 111, 114, 121,  15,  83,
 116,  97,  99, 107,  70, 114,  97, 109, 101,  67, 108,  97, 115, 115,  11,  83,
  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  23,  68, 101, 108, 101, 116,
 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97,
 115, 115,  20,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112,
 108, 101,  67, 108,  97, 115, 115,  12,  67, 108,  97, 115, 115,  70,  97,  99,
 116, 111, 114, 121,  29, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108,
 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112,
 108, 101,   2, 105, 100,   4, 116, 121, 112, 101,   6, 111,  98, 106, 101,  99,
 116,   4, 115, 105, 122, 101,  15,  78, 101, 119,  79,  98, 106, 101,  99, 116,
  83,  97, 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46, 115,  97, 109,
 112, 108, 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99,
 116,  83,  97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116, 101,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  16, 102, 108,  97, 115, 104,
  46, 115,  97, 109, 112, 108, 101, 114, 238, 138, 148,  21,  78, 101, 119,  79,
  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99,
 116,  12,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  27,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  99, 108,
 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13, 115, 116,  97, 114, 116,
  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 115, 116,  97, 114, 116,  83,  97, 109,
 112, 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105,
 110, 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,  13, 112,
  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 112,  97, 117, 115,
 101,  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,  97, 109, 112, 108, 101,
  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99, 115,  35,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115,  97,
 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,
  99, 115,  18, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108,
 108,  98,  97,  99, 107,  34,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,
  67,  97, 108, 108,  98,  97,  99, 107,   7, 103, 101, 116,  83, 105, 122, 101,
  22,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 103, 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,  77, 101, 109,  98, 101,
 114,  78,  97, 109, 101, 115,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58, 103, 101, 116,  77, 101, 109,  98, 101, 114,  78,
  97, 109, 101, 115,  10, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  26,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95,
 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  14, 103, 101, 116,  83,  97,
 109, 112, 108, 101,  67, 111, 117, 110, 116,  29,  83,  97, 109, 112, 108, 101,
 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 109, 112,
 108, 101,  67, 111, 117, 110, 116,  18, 103, 101, 116,  73, 110, 118, 111,  99,
  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  83, 101,
 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  24, 103, 101, 116,  71, 101, 116, 116, 101, 114,  73, 110, 118,
 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  34,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 103, 101, 116,
  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  14,
 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  29,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 105, 115,
  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  16, 103, 101, 116,
  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  31,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,
  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  12, 103, 101,
 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 118,
 101, 100,  84, 104, 105, 115,  15, 103, 101, 116,  77,  97, 115, 116, 101, 114,
  83, 116, 114, 105, 110, 103,  30,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58, 103, 101, 116,  77,  97, 115, 116, 101, 114,  83,
 116, 114, 105, 110, 103,   3,  54,  56,  52,  17, 102, 108,  97, 115, 104,  46,
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
 101,  67, 108,  97, 115, 115,  18, 102, 108,  97, 115, 104,  46, 117, 116, 105,
 108, 115,  58,  69, 110, 100, 105,  97, 110,  10,  66,  73,  71,  95,  69,  78,
  68,  73,  65,  78,   9,  98, 105, 103,  69, 110, 100, 105,  97, 110,  13,  76,
  73,  84,  84,  76,  69,  95,  69,  78,  68,  73,  65,  78,  12, 108, 105, 116,
 116, 108, 101,  69, 110, 100, 105,  97, 110,   6,  69, 110, 100, 105,  97, 110,
  11,  69, 110, 100, 105,  97, 110,  46,  97, 115,  36,  53,  14, 102, 108,  97,
 115, 104,  46, 117, 116, 105, 108, 115, 238, 138, 148,  19, 102, 108,  97, 115,
 104,  46, 115, 121, 115, 116, 101, 109,  58,  87, 111, 114, 107, 101, 114,  15,
 109,  95, 101, 118, 101, 110, 116,  67, 104,  97, 110, 110, 101, 108, 115,  10,
  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  11,  87, 111, 114, 107, 101,
 114,  46,  97, 115,  36,  54,   9, 109,  95,  99, 117, 114, 114, 101, 110, 116,
   6,  87, 111, 114, 107, 101, 114,  14,  80, 114, 111, 109, 105, 115, 101,  67,
 104,  97, 110, 110, 101, 108,   9, 112, 114, 111, 116, 111, 116, 121, 112, 101,
   7, 114, 101,  99, 101, 105, 118, 101,  11,  87, 111, 114, 107, 101, 114,  69,
 118, 101, 110, 116,  13, 100, 105, 115, 112,  97, 116,  99, 104,  69, 118, 101,
 110, 116,   8, 105, 115,  67, 108, 111, 115, 101, 100,   9,  97, 118,  97, 105,
 108,  97,  98, 108, 101,  13, 115, 116,  97, 114, 116,  73, 110, 116, 101, 114,
 110,  97, 108,   7,  80, 114, 111, 109, 105, 115, 101,  12,  87,  79,  82,  75,
  69,  82,  95,  83,  84,  65,  84,  69,  14, 109,  95, 101, 118, 101, 110, 116,
  67, 104,  97, 110, 110, 101, 108,  15, 110, 101, 119,  69, 118, 101, 110, 116,
  67, 104,  97, 110, 110, 101, 108,   6,  86, 101,  99, 116, 111, 114,  11,  95,
  95,  65,  83,  51,  95,  95,  46, 118, 101,  99,  11, 109,  95, 108, 105, 115,
 116, 101, 110, 101, 114, 115,   4, 112, 117, 115, 104,   8, 109,  95, 116,  97,
 114, 103, 101, 116,   2, 101, 120,   2, 101, 118,   7,  99, 117, 114, 114, 101,
 110, 116,  21, 104,  97, 110, 100, 108, 101,  76, 105, 102, 101,  99, 121,  99,
 108, 101,  69, 118, 101, 110, 116, 115,   2, 112, 114,   5, 115, 116,  97, 116,
 101,  17, 115, 116,  97, 114, 116,  87, 105, 116, 104,  67, 104,  97, 110, 110,
 101, 108, 115,   5, 115, 116,  97, 114, 116,  10, 105, 115,  80,  97, 114, 101,
 110, 116,  79, 102,  12, 105, 115,  80, 114, 105, 109, 111, 114, 100, 105,  97,
 108,  16, 115, 101, 116,  83, 116,  97, 114, 116,  65, 114, 103, 117, 109, 101,
 110, 116,  16, 103, 101, 116,  83, 116,  97, 114, 116,  65, 114, 103, 117, 109,
 101, 110, 116,   4, 115, 116, 111, 112,  16,  97, 100, 100,  69, 118, 101, 110,
 116,  76, 105, 115, 116, 101, 110, 101, 114,  10, 100, 101, 115,  99, 114, 105,
 112, 116, 111, 114,  10, 109,  95,  98, 121, 116, 101,  67, 111, 100, 101,  24,
 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  87, 111, 114,
 107, 101, 114,  69, 118, 101, 110, 116,  11, 119, 111, 114, 107, 101, 114,  83,
 116,  97, 116, 101,  15, 109,  95, 112, 114, 101, 118, 105, 111, 117, 115,  83,
 116,  97, 116, 101,  14, 109,  95,  99, 117, 114, 114, 101, 110, 116,  83, 116,
  97, 116, 101,  12,  99, 117, 114, 114, 101, 110, 116,  83, 116,  97, 116, 101,
  13, 112, 114, 101, 118, 105, 111, 117, 115,  83, 116,  97, 116, 101,   6, 116,
  97, 114, 103, 101, 116,  28,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  83, 104, 101, 108, 108,  87, 111, 114, 107, 101, 114,  67, 108,  97,
 115, 115,  29,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83,
 104, 101, 108, 108,  87, 111, 114, 107, 101, 114,  79,  98, 106, 101,  99, 116,
  25, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  87, 111,
 114, 107, 101, 114,  68, 111, 109,  97, 105, 110,  17,  87, 111, 114, 107, 101,
 114,  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,  55,  12,  87, 111, 114,
 107, 101, 114,  68, 111, 109,  97, 105, 110,  33,  99, 114, 101,  97, 116, 101,
  87, 111, 114, 107, 101, 114,  70, 114, 111, 109,  66, 121, 116, 101,  65, 114,
 114,  97, 121,  73, 110, 116, 101, 114, 110,  97, 108,  25,  99, 114, 101,  97,
 116, 101,  87, 111, 114, 107, 101, 114,  70, 114, 111, 109,  66, 121, 116, 101,
  65, 114, 114,  97, 121,  26,  99, 114, 101,  97, 116, 101,  87, 111, 114, 107,
 101, 114,  70, 114, 111, 109,  80, 114, 105, 109, 111, 114, 100, 105,  97, 108,
  34,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 104, 101,
 108, 108,  87, 111, 114, 107, 101, 114,  68, 111, 109,  97, 105, 110,  67, 108,
  97, 115, 115,  35,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  83, 104, 101, 108, 108,  87, 111, 114, 107, 101, 114,  68, 111, 109,  97, 105,
 110,  79,  98, 106, 101,  99, 116,  25, 102, 108,  97, 115, 104,  46, 115, 121,
 115, 116, 101, 109,  58,  80, 114, 111, 109, 105, 115, 101,  83, 116,  97, 116,
 101,   3,  78,  69,  87,   3, 110, 101, 119,   8,  82,  69,  67,  69,  73,  86,
  69,  68,   8, 114, 101,  99, 101, 105, 118, 101, 100,   6,  66,  82,  79,  75,
  69,  78,   6,  98, 114, 111, 107, 101, 110,   9,  69,  88,  67,  69,  80,  84,
  73,  79,  78,   9, 101, 120,  99, 101, 112, 116, 105, 111, 110,  12,  80, 114,
 111, 109, 105, 115, 101,  83, 116,  97, 116, 101,  26, 102, 108,  97, 115, 104,
  46, 115, 121, 115, 116, 101, 109,  58,  80, 114, 111, 109, 105, 115, 101,  72,
 101, 108, 112, 101, 114,  12,  67,  65,  76,  76,  95,  82,  69,  81,  85,  69,
  83,  84,  18,  82,  69,  83,  79,  76,  85,  84,  73,  79,  78,  95,  82,  69,
  81,  85,  69,  83,  84,  16,  67,  65,  76,  76,  66,  65,  67,  75,  95,  82,
  69,  81,  85,  69,  83,  84,  15,  71,  69,  84,  80,  82,  79,  80,  95,  82,
  69,  81,  85,  69,  83,  84,  15,  68,  69,  83,  84,  82,  79,  89,  95,  82,
  69,  81,  85,  69,  83,  84,  23,  68,  69,  83,  84,  82,  79,  89,  95,  68,
  69,  76,  65,  89,  69,  68,  95,  82,  69,  81,  85,  69,  83,  84,  16,  83,
  85,  67,  67,  69,  83,  83,  95,  82,  69,  83,  80,  79,  78,  83,  69,  18,
  69,  88,  67,  69,  80,  84,  73,  79,  78,  95,  82,  69,  83,  80,  79,  78,
  83,  69,  16, 109,  95, 101, 109, 112, 116, 121,  95, 112, 114, 111, 109, 105,
 115, 101, 115,  12,  80, 114, 111, 109, 105, 115, 101,  46,  97, 115,  36,  56,
  16, 109,  95, 108, 111,  99,  97, 108,  95, 114, 101, 113, 117, 101, 115, 116,
 115,  18, 109,  95, 100, 101, 108,  97, 121, 101, 100,  95, 114, 101, 113, 117,
 101, 115, 116, 115,  19, 103, 101, 116,  80, 114, 111, 109, 105, 115, 101,  79,
 119, 110, 101, 114,  71, 105, 105, 100,  11,  99, 117, 114, 114, 101, 110, 116,
  71, 105, 105, 100,  19, 115, 101, 116,  80, 114, 111, 109, 105, 115, 101,  79,
 119, 110, 101, 114,  71, 105, 105, 100,  13, 103, 101, 116,  80, 114, 111, 109,
 105, 115, 101,  71, 105, 100,  13, 115, 101, 116,  80, 114, 111, 109, 105, 115,
 101,  71, 105, 100,  14, 105, 115,  80, 114, 111, 109, 105, 115, 101,  69, 109,
 112, 116, 121,  25, 115,  99, 104, 101, 100, 117, 108, 101,  80, 114, 111, 109,
 105, 115, 101,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  18, 114, 101,
 116,  97, 114, 103, 101, 116,  73, 110,  99,  67, 104,  97, 110, 110, 101, 108,
  18, 114, 101, 116,  97, 114, 103, 101, 116,  79, 117, 116,  67, 104,  97, 110,
 110, 101, 108,  23, 105, 115,  80, 114, 111, 109, 105, 115, 101,  67, 114, 101,
  97, 116, 101, 100,  76, 111,  99,  97, 108, 108, 121,  14, 119,  97, 105, 116,
  70, 111, 114,  65, 110, 121,  83, 101, 110, 100,   6, 112, 114,  97, 100, 100,
 114,   7,  98, 114, 101,  97, 107,  79, 110,  13,  80, 114, 111, 109, 105, 115,
 101,  72, 101, 108, 112, 101, 114,  20, 102, 108,  97, 115, 104,  46, 115, 121,
 115, 116, 101, 109,  58,  80, 114, 111, 109, 105, 115, 101,  16, 109,  95, 101,
 109, 112, 116, 121,  95, 114, 101, 113, 117, 101, 115, 116, 115,  11,  99, 114,
 101,  97, 116, 101,  76, 111,  99,  97, 108,  20, 114, 101, 103, 105, 115, 116,
 101, 114,  69, 109, 112, 116, 121,  80, 114, 111, 109, 105, 115, 101,  11,  82,
 101, 109, 111, 116, 101,  80, 114, 111, 120, 121,  16, 109,  95, 114, 101, 109,
 111, 116, 101,  95, 112, 114, 111, 120, 105, 101, 115,  10, 109,  95, 114, 101,
 115, 111, 108, 118, 101, 100,   9,  91,  80, 114, 111, 109, 105, 115, 101,  93,
   7, 109,  95, 101, 109, 112, 116, 121,  52,  99,  97, 110, 110, 111, 116,  32,
  99,  97, 108, 108,  32, 109, 101, 116, 104, 111, 100, 115,  32, 111, 110,  32,
 101, 120, 112, 108, 105,  99, 105, 116, 108, 121,  32, 117, 110, 114, 101, 115,
 111, 108, 118, 101, 100,  32, 112, 114, 111, 109, 105, 115, 101,  14, 105, 115,
  79, 119, 110, 101, 100,  76, 111,  99,  97, 108, 108, 121,   7, 109,  95,  97,
 115, 121, 110,  99,   8, 109,  95, 103, 108, 111,  98,  97, 108,  19, 102, 108,
  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58, 105, 110, 116, 101, 114,
 110,   6, 108, 101, 110, 103, 116, 104,   4, 119, 114,  97, 112,   8,  99,  97,
 108, 108,  80, 114, 111, 112,   5, 109,  95, 111, 117, 116,   6, 115, 101, 110,
 100, 101, 114,   8, 114, 101,  99, 101, 105, 118, 101, 114,   5, 109,  95, 105,
 110,  99,   6,  99, 114, 101,  97, 116, 101,   4, 115, 101, 110, 100,  83, 112,
 114, 111, 109, 105, 115, 101, 115,  32, 114, 101, 112, 114, 101, 115, 101, 110,
 116, 105, 110, 103,  32, 103, 108, 111,  98,  97, 108,  32, 115,  99, 111, 112,
 101,  32,  99,  97, 110, 110, 111, 116,  32,  98, 101,  32, 112,  97, 115, 115,
 101, 100,  32, 116, 111,  32, 116, 104, 101,  32, 119, 111, 114, 107, 101, 114,
  32, 111, 119, 110, 105, 110, 103,  32, 116, 104,  97, 116,  32, 115,  99, 111,
 112, 101,   5,  97, 115, 121, 110,  99,   7, 109,  95, 115, 116,  97, 116, 101,
   6, 109,  95, 103, 112, 105, 100,  15, 100, 101, 108,  97, 121,  67, 111, 108,
 108, 101,  99, 116, 105, 111, 110,  11, 110, 111, 116, 105, 102, 121,  79, 119,
 110, 101, 114,   8, 101, 110, 118, 101, 108, 111, 112, 101,   8,  69, 110, 118,
 101, 108, 111, 112, 101,   4,  97, 114, 103, 115,   1, 105,   3, 111, 117, 116,
   3, 105, 110,  99,   3, 114, 101, 115,   9, 111, 119, 110, 101, 114,  71, 105,
 105, 100,   5, 102, 114, 101, 115, 104,  11, 114, 101, 109, 111, 116, 101,  80,
 114, 111, 120, 121,   7, 103, 101, 116,  80, 114, 111, 112,  58,  97, 110,  32,
 101, 120, 112, 108, 105,  99, 105, 116, 108, 121,  32, 117, 110, 114, 101, 115,
 111, 108, 118, 101, 100,  32, 112, 114, 111, 109, 105, 115, 101,  32,  99,  97,
 110,  32,  98, 101,  32, 114, 101, 115, 111, 108, 118, 101, 100,  32, 111, 110,
 108, 121,  32, 111, 110,  99, 101,  17, 110, 111, 116, 105, 102, 121,  69, 109,
 112, 116, 121,  79, 119, 110, 101, 114, 115,   7, 115, 117,  99,  99, 101, 115,
 115,   5, 102,  97, 117, 108, 116,   7, 104,  97, 110, 100, 108, 101, 114,   1,
 112,  15, 115, 117,  99,  99, 101, 115, 115,  67,  97, 108, 108,  98,  97,  99,
 107,  13, 102,  97, 117, 108, 116,  67,  97, 108, 108,  98,  97,  99, 107,   4,
 103, 112, 105, 100,  13, 101, 109, 112, 116, 121,  82, 101, 113, 117, 101, 115,
 116, 115,  11, 116, 104, 105, 115,  80, 114, 111, 109, 105, 115, 101,  23, 115,
 117,  99,  99, 101, 115, 115,  67,  97, 108, 108,  98,  97,  99, 107,  70, 117,
 110,  99, 116, 105, 111, 110,  21, 102,  97, 117, 108, 116,  67,  97, 108, 108,
  98,  97,  99, 107,  70, 117, 110,  99, 116, 105, 111, 110,  15,  99,  97, 108,
 108,  98,  97,  99, 107,  80, 114, 111, 109, 105, 115, 101,  19,  99,  97, 108,
 108,  98,  97,  99, 107,  82, 101, 109, 111, 116, 101,  80, 114, 111, 120, 121,
  31,  99, 104, 101,  99, 107,  70, 111, 114,  67,  97, 108, 108,  82, 101, 113,
 117, 101, 115, 116, 115,  67, 111, 110, 100, 105, 116, 105, 111, 110,  97, 108,
  54, 119, 111, 114, 107, 101, 114,  32, 116, 101, 114, 109, 105, 110,  97, 116,
 101, 100,  32, 119, 104, 105, 108, 101,  32, 119,  97, 105, 116, 105, 110, 103,
  32, 102, 111, 114,  32, 101, 109, 112, 116, 121,  32, 112, 114, 111, 109, 105,
 115, 101,  32, 115, 101, 110, 100,  54, 119, 111, 114, 107, 101, 114,  32, 116,
 101, 114, 109, 105, 110,  97, 116, 101, 100,  32, 119, 104, 105, 108, 101,  32,
 119,  97, 105, 116, 105, 110, 103,  32, 102, 111, 114,  32, 112, 114, 111, 109,
 105, 115, 101,  32, 114, 101, 115, 111, 108, 117, 116, 105, 111, 110,   8, 114,
 101, 115, 112, 111, 110, 115, 101,   5,  69, 114, 114, 111, 114,  13, 117, 110,
 107, 110, 111, 119, 110,  32, 115, 116,  97, 116, 101,   5, 101, 109, 112, 116,
 121,  12, 114, 101, 115, 111, 108, 118, 101,  76, 111,  99,  97, 108,  18, 112,
 114, 105, 110, 116,  69, 109, 112, 116, 121,  80, 114, 111, 109, 105, 115, 101,
 115,  12,  99,  97, 108, 108,  80, 114, 111, 112, 101, 114, 116, 121,  11, 103,
 101, 116,  80, 114, 111, 112, 101, 114, 116, 121,   7, 114, 101, 115, 111, 108,
 118, 101,   4, 119, 104, 101, 110,   6, 103, 101, 116,  80,  73,  68,  24, 102,
 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  82, 101, 109, 111,
 116, 101,  80, 114, 111, 120, 121,  13, 109,  95, 119, 111, 114, 107, 101, 114,
  67, 108,  97, 115, 115,   3, 112, 111, 112,  16, 104,  97, 110, 100, 108, 101,
  82, 101, 115, 111, 108, 117, 116, 105, 111, 110,  14, 104,  97, 110, 100, 108,
 101,  67,  97, 108, 108,  98,  97,  99, 107,  10, 104,  97, 110, 100, 108, 101,
  67,  97, 108, 108,  13, 104,  97, 110, 100, 108, 101,  71, 101, 116,  80, 114,
 111, 112,  24, 116, 114, 105, 103, 103, 101, 114,  68, 101, 108,  97, 121, 101,
 100,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,   4, 108, 111, 111, 112,
   5,  99, 111, 117, 110, 116,  12,  77,  65,  88,  95,  82,  69,  81,  85,  69,
  83,  84,  83,   3, 108, 101, 110,   3, 114, 101, 113,   3, 109, 115, 103,   1,
  97,  13, 115, 101, 110, 100,  67, 111, 110, 100,  84, 104, 114, 111, 119,  45,
 101, 109, 112, 116, 121,  32, 112, 114, 111, 109, 105, 115, 101, 115,  32,  99,
  97, 110, 110, 111, 116,  32,  98, 101,  32, 114, 101, 116, 117, 114, 110, 101,
 100,  32, 116, 111,  32,  97,  32, 119, 111, 114, 107, 101, 114,  85, 112, 114,
 111, 109, 105, 115, 101, 115,  32, 114, 101, 112, 114, 101, 115, 101, 110, 116,
 105, 110, 103,  32, 111,  98, 106, 101,  99, 116, 115,  32, 111, 102,  32,  97,
  32, 103, 105, 118, 101, 110,  32, 119, 111, 114, 107, 101, 114,  32,  99,  97,
 110, 110, 111, 116,  32,  98, 101,  32, 114, 101, 116, 117, 114, 110, 101, 100,
  32, 116, 111,  32, 116, 104, 101,  32, 115,  97, 109, 101,  32, 119, 111, 114,
 107, 101, 114,  14,  82, 101, 102, 101, 114, 101, 110,  99, 101,  69, 114, 114,
 111, 114,  24,  82, 101, 109, 111, 116, 101,  32, 109, 101, 116, 104, 111, 100,
  32,  99,  97, 108, 108,  32, 101, 114, 114, 111, 114,  14, 102, 108,  97, 116,
 116, 101, 110,  80, 114, 111, 109, 105, 115, 101,  20,  99, 111, 109, 109, 117,
 110, 105,  99,  97, 116, 105, 111, 110,  83, 117,  99,  99, 101, 115, 115,   6,
 114, 101, 115, 117, 108, 116,  10, 108, 111,  99,  97, 108,  69, 109, 112, 116,
 121,  25,  82, 101, 109, 111, 116, 101,  32, 118,  97, 108, 117, 101,  32,  97,
  99,  99, 101, 115, 115,  32, 101, 114, 114, 111, 114,  20,  99, 104, 101,  99,
 107,  70, 111, 114,  67,  97, 108, 108,  82, 101, 113, 117, 101, 115, 116, 115,
  21, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  69, 110,
 118, 101, 108, 111, 112, 101,   6, 105, 110, 116, 101, 114, 110,  29,  58,  58,
  97, 118, 109, 112, 108, 117, 115,  58,  58,  80, 114, 111, 109, 105, 115, 101,
  72, 101, 108, 112, 101, 114,  67, 108,  97, 115, 115,  23,  58,  58,  97, 118,
 109, 112, 108, 117, 115,  58,  58,  80, 114, 111, 109, 105, 115, 101,  67, 108,
  97, 115, 115,  24,  58,  58,  97, 118, 109, 112, 108, 117, 115,  58,  58,  80,
 114, 111, 109, 105, 115, 101,  79,  98, 106, 101,  99, 116,  27,  58,  58,  97,
 118, 109, 112, 108, 117, 115,  58,  58,  82, 101, 109, 111, 116, 101,  80, 114,
 111, 120, 121,  67, 108,  97, 115, 115,  28,  58,  58,  97, 118, 109, 112, 108,
 117, 115,  58,  58,  82, 101, 109, 111, 116, 101,  80, 114, 111, 120, 121,  79,
  98, 106, 101,  99, 116,  25,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  69, 110, 118, 101, 108, 111, 112, 101,  67, 108,  97, 115, 115,  26,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  69, 110, 118, 101,
 108, 111, 112, 101,  79,  98, 106, 101,  99, 116, 153,   1,  22,   1,   5,   5,
  23,   1,  22,   6,  23,   6,   8,  18,   5,  21,  22,  22,  24,  21,   5,  25,
  24,  25,   5,  29,  24,  29,  26,  29,  26,  24,   8,  54,   5,  66,  22,  67,
  24,  66,   5,  74,  22,  75,  24,  74,   5,  77,  24,  77,   5,  79,  24,  79,
   5,  81,  24,  81,   5,  83,  24,  83,   5,  85,  24,  85,   5,  87,  24,  87,
   5,  89,  24,  89,   5,  91,  22,  93,  23,  93,  24,  91,  26,  91,   5,  96,
  22,  98,  22, 102,  22, 105,  22, 108,  22, 111,  22, 114,  24,  96,   5, 151,
   1,  24, 151,   1,   5, 153,   1,  24, 153,   1,   5, 155,   1,  24, 155,   1,
   5, 157,   1,  24, 157,   1,   5, 159,   1,  24, 159,   1,   5, 161,   1,  24,
 161,   1,   5, 163,   1,  24, 163,   1,   5, 165,   1,  24, 165,   1,   5, 167,
   1,  24, 167,   1,   5, 179,   1,  24, 179,   1,   5, 181,   1,  24, 181,   1,
   5, 183,   1,  24, 183,   1,   5, 185,   1,  24, 185,   1,   5, 187,   1,  24,
 187,   1,   5, 189,   1,  24, 189,   1,   5, 191,   1,  24, 191,   1,   5, 193,
   1,  24, 193,   1,  23,  75,  22, 211,   1,  22, 219,   1,  22, 244,   1,  22,
 247,   1,  22, 248,   1,  22, 249,   1,  22, 250,   1,  22, 251,   1,  22, 252,
   1,   5, 253,   1,   5, 255,   1,  24, 253,   1,  26, 253,   1,   5, 136,   2,
  22, 137,   2,  23, 137,   2,   5, 144,   2,  24, 144,   2,  26, 144,   2,   5,
 155,   2,  24, 155,   2,   5, 159,   2,  24, 159,   2,   5, 165,   2,  24, 165,
   2,   5, 171,   2,  24, 171,   2,  22, 173,   2,   5, 208,   2,  22, 220,   2,
  24, 208,   2,   5, 222,   2,  23, 220,   2,  22, 223,   2,   5, 225,   2,  24,
 225,   2,   5, 231,   2,  23,  67,  22, 232,   2,   5, 233,   2,   5, 236,   2,
  24, 233,   2,  26, 233,   2,  22, 252,   2,   5, 144,   3,  24, 144,   3,  26,
 144,   3,   5, 153,   3,   5, 154,   3,  24, 153,   3,  26, 153,   3,   5, 161,
   3,  24, 161,   3,   5, 171,   3,   5, 181,   3,  24, 171,   3,  26, 171,   3,
   5, 198,   3,  24, 198,   3,  26, 198,   3,  23, 211,   3,   5, 139,   4,  24,
 139,   4,  26, 139,   4,   5, 165,   4,  24, 165,   4,  26, 165,   4,  26,  33,
  72,   4,   1,   2,   3,   4,   4,   1,   2,   4,   5,   1,   6,   1,   8,   8,
   1,   2,   4,   5,  12,  13,  14,  15,   1,  12,   1,  16,   1,  33,   1,  35,
   9,   1,   2,   4,  15,  37,  38,  39,  40,  41,   1,  43,   1,  44,   1,  45,
   1,  46,   1,  47,   1,  48,   2,  43,  44,   3,  44,  46,  48,   3,  43,  44,
  47,   1,  80,   1,  82,   1,   5,   1,   4,   1,  21,   4,   1,   2,  21,  84,
   1,  38,   5,   1,   2,   4,  38,  39,   1,  85,   1,  86,   1,  87,   1,  88,
   1,  89,   1,  90,   1,  91,   1,  92,   1,  93,   2,  88,  89,   3,  89,  91,
  93,   3,  88,  89,  92,   8,   1,   4,   5,  15,  94,  95,  96,  97,   1,  94,
   4,   1,   4,   5,  95,   4,   1,  98,  99, 100,   1, 100,   8,   1,  15,  98,
  99, 100, 101, 102, 103,   1, 112,   4,   1, 114, 116, 117,   1, 118,   4,   1,
  18, 121, 122,   1, 123,   9,   1,  15,  18,  38,  39, 124, 125, 126, 127,   8,
   1,  15,  38,  39, 124, 125, 126, 127,   9,   1,  15,  38,  39, 124, 125, 126,
 127, 128,   1,   1,  39,   1, 124,   8,   1,  15,  38,  39, 125, 129,   1, 130,
   1, 131,   1,   1, 129,   1,   4,   1,  38,  39, 125,   8,   1,  15,  38,  39,
 132,   1, 133,   1, 134,   1, 135,   1,   1, 132,   1,   4,   1,  38,  39, 133,
   1,   8,   1,  15,  38,  39, 138,   1, 139,   1, 140,   1, 141,   1,   9,   1,
  15,  38,  39, 128,   1, 138,   1, 139,   1, 140,   1, 141,   1,   8,   1,  15,
  38,  39, 139,   1, 142,   1, 143,   1, 144,   1,   9,   1,  15,  38,  39, 128,
   1, 139,   1, 142,   1, 143,   1, 144,   1,   1, 142,   1,   1, 145,   1,   8,
   1,  15,  38,  39, 139,   1, 146,   1, 147,   1, 148,   1,   1, 146,   1,   9,
   1,  15,  38,  39, 139,   1, 149,   1, 150,   1, 151,   1, 152,   1,   4,   1,
  38,  39, 139,   1, 164,   6,   7,   1,   2,   7,   1,   3,   9,   4,   1,   9,
   7,   1,   9,   8,   1,   7,   1,   9,   9,  10,   1,   7,   1,  11,   9,  12,
   1,   9,  13,   1,   9,  14,   1,   9,  15,   1,   7,   1,  16,   9,   4,   2,
   9,  17,   2,   9,  19,   3,   7,   5,  20,   9,  19,   4,   7,   5,  23,   7,
   1,  24,   7,   1,  26,   9,  27,   4,   7,   5,  28,   7,   1,  30,   9,  31,
   5,   7,   1,  32,   7,   1,  33,   7,   1,  34,   7,   1,  35,   9,  36,   4,
   9,  38,   4,   9,  42,   4,   9,  43,   4,   9,  44,   4,   9,  45,   4,   9,
  12,   4,   9,  46,   4,   9,  17,   4,   9,  47,   4,   9,  48,   4,   9,  10,
   4,   9,  31,   6,   9,  30,   4,   9,   8,   4,   9,  49,   4,   9,  50,   4,
   9,  51,   4,   9,  52,   4,   9,  53,   4,   9,  55,   7,   9,  56,   4,   9,
  57,   4,   9,  58,   4,   9,  59,   4,   9,   7,   4,   9,  60,   4,   9,  61,
   4,   9,  62,   4,   9,  63,   4,   9,  64,   4,   9,  65,   4,   7,   4,   4,
   7,  18,  68,   9,  69,   4,   9,  70,   4,   9,  71,   4,   9,  72,   4,   7,
   4,  73,   7,  21,  76,   7,  21,  78,   7,  21,  80,   7,  21,  82,   7,  21,
  84,   7,  21,  86,   7,  33,  37,   9,  37,   8,   7,  21,  88,   7,  35,  39,
   9,  39,   9,   7,  21,  90,   9,   4,  10,   9,  47,  10,   9,  94,   4,   7,
  38,  95,   9,  97,   4,   9,  99,  11,   9, 103,  12,   9, 106,  13,   9, 109,
  14,   9, 112,  15,   9, 115,  16,   9, 117,  17,   9, 118,  18,   9, 119,  19,
   9, 120,   4,   9, 121,  11,   9, 122,  12,   9, 123,  13,   9, 124,  14,   9,
 125,  15,   9, 126,  16,   9, 127,  17,   9, 128,   1,  18,   9, 129,   1,  19,
   9, 130,   1,   4,   9, 131,   1,  11,   9, 132,   1,  12,   9, 133,   1,  13,
   9, 134,   1,  14,   9, 135,   1,  15,   9, 136,   1,  16,   9, 137,   1,  17,
   9, 138,   1,  18,   9, 139,   1,  19,   9, 140,   1,   4,   9, 141,   1,  11,
   9, 142,   1,  12,   9, 143,   1,  13,   9, 144,   1,  14,   9, 145,   1,  15,
   9, 146,   1,  16,   9, 147,   1,  17,   9, 148,   1,  18,   9, 149,   1,  19,
   7,  21, 150,   1,   7,  21, 152,   1,   7,  21, 154,   1,   7,  21, 156,   1,
   7,  21, 158,   1,   7,  21, 160,   1,   7,  21, 162,   1,   7,  21, 164,   1,
   7,  21, 166,   1,   7,  21, 168,   1,   7,  21, 169,   1,   7,  21, 170,   1,
   7,  21, 171,   1,   7,  21, 172,   1,   7,  21, 173,   1,   7,  21, 174,   1,
   7,  21, 175,   1,   7,  21, 176,   1,   7,  21, 177,   1,   7,  21, 178,   1,
   7,  21, 180,   1,   7,  21, 182,   1,   7,  21, 184,   1,   7,  21, 186,   1,
   7,  21, 188,   1,   7,  21, 190,   1,   9,  37,  20,   7,  21, 192,   1,   9,
  37,  21,   9, 194,   1,  21,   9, 195,   1,  21,   7,  21, 196,   1,   9,  20,
  22,   9,  23,  22,   9,  24,   2,   9,  28,  22,   9,   4,  23,   9,  73,  23,
   9,  76,  24,   9,  24,  25,   9, 180,   1,  24,   9,  76,  25,   9, 182,   1,
  24,   9,  78,  24,   9, 184,   1,  24,   9,  78,  25,   9, 186,   1,  24,   9,
  80,  24,   9, 188,   1,  24,   9,  80,  25,   9, 190,   1,  24,   9,  82,  24,
   9,  84,  24,   9, 192,   1,  24,   9,  84,  25,   9, 196,   1,  24,   9,  86,
  24,   9,  88,  24,   9,  90,  24,   9,  95,  26,   9,  24,  27,   9, 150,   1,
  24,   9, 152,   1,  24,   9, 154,   1,  24,   9, 156,   1,  24,   9, 158,   1,
  24,   9, 160,   1,  24,   9, 162,   1,  24,   9, 164,   1,  24,   9, 166,   1,
  24,   9, 168,   1,  24,   9, 169,   1,  24,   9, 170,   1,  24,   9, 171,   1,
  24,   9, 172,   1,  24,   9, 173,   1,  24,   9, 174,   1,  24,   9, 175,   1,
  24,   9, 176,   1,  24,   9, 177,   1,  24,   9, 178,   1,  24,   9, 197,   1,
  24,   7,  21, 197,   1,   9, 198,   1,  24,   7,  21, 198,   1,   9, 199,   1,
  24,   7,  21, 199,   1,   9, 200,   1,  24,   7,  21, 200,   1,   9, 201,   1,
  24,   7,  21, 201,   1,   9, 202,   1,  24,   7,  21, 202,   1,   9,  97,  24,
   7,  21,  97,   9,  99,  24,   7,  21,  99,   9, 103,  24,   7,  21, 103,   9,
 106,  24,   7,  21, 106,   9, 109,  24,   7,  21, 109,   9, 112,  24,   7,  21,
 112,   9, 115,  24,   7,  21, 115,   9, 117,  24,   7,  21, 117,   9, 118,  24,
   7,  21, 118,   9, 119,  24,   7,  21, 119,   9, 120,  24,   7,  21, 120,   9,
 121,  24,   7,  21, 121,   9, 122,  24,   7,  21, 122,   9, 123,  24,   7,  21,
 123,   9, 124,  24,   7,  21, 124,   9, 125,  24,   7,  21, 125,   9, 126,  24,
   7,  21, 126,   9, 127,  24,   7,  21, 127,   9, 128,   1,  24,   7,  21, 128,
   1,   9, 129,   1,  24,   7,  21, 129,   1,   9, 203,   1,  22,   9,   4,  28,
   9,  73,  28,   9,  17,  28,   9,  76,  29,   9, 180,   1,  29,   9, 182,   1,
  29,   9,  78,  29,   9, 184,   1,  29,   9, 186,   1,  29,   9,  80,  29,   9,
 188,   1,  29,   9, 190,   1,  29,   9,  82,  29,   9,  84,  29,   9, 192,   1,
  29,   9, 196,   1,  29,   9,  86,  29,   9,  88,  29,   9,  90,  29,   9,  95,
  30,   9, 245,   1,   4,   9, 246,   1,   4,   9, 197,   1,  29,   9, 198,   1,
  29,   9, 199,   1,  29,   9, 200,   1,  29,   9, 201,   1,  29,   9, 202,   1,
  29,   9,  97,  29,   9,  99,  31,   9, 103,  32,   9, 106,  33,   9, 109,  34,
   9, 112,  35,   9, 115,  36,   9, 117,  37,   9, 118,  38,   9, 119,  39,   9,
 120,  29,   9, 121,  31,   9, 122,  32,   9, 123,  33,   9, 124,  34,   9, 125,
  35,   9, 126,  36,   9, 127,  37,   9, 128,   1,  38,   9, 129,   1,  39,   9,
 130,   1,  29,   9, 131,   1,  31,   9, 132,   1,  32,   9, 133,   1,  33,   9,
 134,   1,  34,   9, 135,   1,  35,   9, 136,   1,  36,   9, 137,   1,  37,   9,
 138,   1,  38,   9, 139,   1,  39,   9, 140,   1,  29,   9, 141,   1,  31,   9,
 142,   1,  32,   9, 143,   1,  33,   9, 144,   1,  34,   9, 145,   1,  35,   9,
 146,   1,  36,   9, 147,   1,  37,   9, 148,   1,  38,   9, 149,   1,  39,   9,
 150,   1,  29,   9, 152,   1,  31,   9, 154,   1,  32,   9, 156,   1,  33,   9,
 158,   1,  34,   9, 160,   1,  35,   9, 162,   1,  36,   9, 164,   1,  37,   9,
 166,   1,  38,   9, 168,   1,  39,   9, 169,   1,  29,   9, 170,   1,  31,   9,
 171,   1,  32,   9, 172,   1,  33,   9, 173,   1,  34,   9, 174,   1,  35,   9,
 175,   1,  36,   9, 176,   1,  37,   9, 177,   1,  38,   9, 178,   1,  39,   7,
   4,  13,   9, 254,   1,  40,   9,  73,  40,   9,  71,  40,   9, 128,   2,  40,
   9,  14,   4,   9, 129,   2,   4,   9, 254,   1,  41,   9, 128,   2,   4,   9,
  15,   4,   9, 130,   2,   4,   9, 131,   2,   4,   9,  13,  23,   9,  24,  42,
   9,  13,  28,   7,   1, 134,   2,   9, 135,   2,  43,   9, 138,   2,  43,   9,
 139,   2,  43,   7,   1, 140,   2,   9, 141,   2,  44,   9, 142,   2,  43,   9,
 139,   2,  44,   9, 143,   2,  44,   9, 145,   2,  45,   9, 147,   2,  45,   9,
 150,   2,  45,   9, 145,   2,   4,   9, 147,   2,   4,   9, 150,   2,   4,   9,
 152,   2,   4,   9, 153,   2,   4,   7,  99, 154,   2,   9, 156,   2,   4,   9,
 157,   2,   4,   7,  99, 158,   2,   7,   1, 160,   2,   7,   1, 161,   2,   7,
   1, 162,   2,   7,   1, 163,   2,   9, 160,   2,   4,   9, 161,   2,   4,   9,
 162,   2,   4,   9, 163,   2,   4,   7, 100, 164,   2,   9, 166,   2,   4,   9,
 167,   2,   4,   9, 168,   2,   4,   9, 169,   2,   4,   7,  99, 170,   2,   7,
  99, 172,   2,   9,  24,  43,   9, 154,   2,  46,   9, 158,   2,  46,   9, 170,
   2,  46,   9, 172,   2,  46,   9, 175,   2,  46,   9, 177,   2,  46,   9, 179,
   2,  46,   9, 181,   2,  46,   9, 183,   2,  46,   9, 185,   2,  46,   9, 142,
   2,  44,   9, 187,   2,  46,   9, 189,   2,  46,   9, 191,   2,  46,   9, 138,
   2,  44,   9, 193,   2,  46,   9, 195,   2,  46,   9, 196,   2,  46,   9, 197,
   2,  46,   9, 135,   2,  44,   9, 199,   2,  46,   9, 201,   2,  46,   9, 203,
   2,  46,   9, 205,   2,  46,   9, 164,   2,  44,   7,   1, 209,   2,   7,   1,
 210,   2,   7,   1, 211,   2,   7,   1, 212,   2,   7,   1, 213,   2,   7,   1,
 214,   2,   7,   1, 215,   2,   9, 209,   2,   4,   9, 210,   2,   4,   9, 211,
   2,   4,   9, 212,   2,   4,   9, 213,   2,   4,   9, 214,   2,   4,   9, 215,
   2,   4,   9, 216,   2,   4,   9, 217,   2,   4,   9, 218,   2,   4,   9, 219,
   2,   4,   7, 114, 221,   2,   9,  24,  47,   9, 221,   2,  48,   7,   1, 226,
   2,   7,   1, 228,   2,   9, 226,   2,   4,   9, 228,   2,   4,   7,  18, 230,
   2,   9,  24,  49,   9, 230,   2,  50,   7, 124, 234,   2,   9, 235,   2,  51,
   9, 237,   2,  52,   7,  38, 238,   2,   7,  38, 239,   2,   9, 234,   2,  52,
   9,  24,  52,   9, 240,   2,  52,  27,  52,   9, 238,   2,  52,   9, 241,   2,
  52,   9,  11,  52,   9, 242,   2,  52,   9, 243,   2,  52,   9, 244,   2,  52,
   9, 245,   2,  52,   9, 246,   2,  52,   7,  38, 247,   2,   9, 248,   2,  52,
   9, 249,   2,  52,   9, 250,   2,  52,   9, 251,   2,  53,   9,  35,  52,   9,
 253,   2,  52,   9, 254,   2,  52,   9, 255,   2,  52,   7,   1, 128,   3,   9,
 129,   3,  54,   7,  38, 242,   2,   9, 139,   2,  54,   9, 130,   3,   4,   9,
 131,   3,   4,   9, 132,   3,   4,   9, 237,   2,  55,   9, 234,   2,  55,   7,
  18, 235,   2,   9, 133,   3,   4,   9, 134,   3,   4,   9, 135,   3,   4,   9,
 246,   2,  55,   9, 136,   3,   4,   9, 137,   3,   4,   9, 250,   2,  55,   9,
 138,   3,   4,   9, 139,   3,   4,   9, 140,   3,   4,   9, 141,   3,   4,   9,
 243,   2,  55,   9, 142,   3,   4,   9, 143,   3,  55,   9, 249,   2,  55,   9,
 253,   2,  55,   7, 128,   1, 251,   2,  29, 248,   3,   1,  29,   7,   1, 248,
   2,   9, 146,   3,  56,   9, 147,   3,  56,   9, 255,   2,  56,   9, 248,   2,
   4,   9, 148,   3,   4,   9, 149,   3,   4,   9, 150,   3,   4,   9, 146,   3,
  57,   9, 147,   3,  57,   9, 255,   2,  54,   9, 238,   2,  26,   9,  24,  58,
   9, 242,   2,  26,   9, 238,   2,  30,   9, 242,   2,  30,   9, 237,   2,  59,
   7,  38, 155,   3,   9, 156,   3,  59,   9, 237,   2,  60,   9, 157,   3,   4,
   9, 158,   3,   4,   9, 156,   3,  60,   9,  24,  61,   9, 155,   3,  30,   7,
   1, 162,   3,   7,   1, 164,   3,   7,   1, 166,   3,   7,   1, 168,   3,   9,
 162,   3,   4,   9, 164,   3,   4,   9, 166,   3,   4,   9, 168,   3,   4,   7,
  38, 170,   3,   7,   1, 172,   3,   7,   1, 173,   3,   7,   1, 174,   3,   7,
   1, 175,   3,   7,   1, 176,   3,   7,   1, 177,   3,   7,   1, 178,   3,   7,
   1, 179,   3,   7,   1, 180,   3,   9,  33,  62,   7,   1, 182,   3,   9, 251,
   2,  63,   9,  24,  62,   7,   1, 183,   3,   9, 184,   3,  62,   9, 172,   3,
   4,   9, 173,   3,   4,   9, 174,   3,   4,   9, 175,   3,   4,   9, 176,   3,
   4,   9, 177,   3,   4,   9, 178,   3,   4,   9, 179,   3,   4,   9, 185,   3,
   4,   9, 184,   3,   4,   9, 186,   3,   4,   9, 187,   3,   4,   9, 188,   3,
   4,   9, 189,   3,   4,   9, 190,   3,   4,   9, 191,   3,   4,   9, 192,   3,
   4,   9, 193,   3,   4,   9, 180,   3,   4,   9, 182,   3,   4,  29, 248,   3,
   1,  20,   9, 183,   3,   4,   9, 194,   3,  54,   9, 195,   3,   4,   9, 196,
   3,   4,   7,  39, 197,   3,   7, 142,   1, 176,   3,   9, 197,   3,  64,   9,
 176,   3,  64,   7, 142,   1, 177,   3,   9, 177,   3,  64,   7, 142,   1, 199,
   3,   9,  33,  64,   9, 247,   2,  64,   9, 200,   3,  64,   9, 201,   3,  64,
   9, 185,   3,  64,   9, 180,   3,  64,   9, 187,   3,  64,  27,  64,   9, 202,
   3,  64,   9, 203,   3,  64,   7,  39, 202,   3,   9, 204,   3,  64,   9, 145,
   2,  64,   9, 206,   3,  64,   9, 208,   3,  64,   9, 193,   3,  64,   9, 209,
   3,  64,   9, 210,   3,  64,   7, 145,   1, 204,   3,   9, 212,   3,  64,   9,
 213,   3,  64,   9, 214,   3,  64,   9, 239,   2,  64,   9, 215,   3,  64,   9,
 216,   3,  64,   9, 217,   3,  64,   9, 218,   3,  64,   9, 219,   3,  64,   9,
 172,   3,  64,   9, 220,   3,  64,   9, 184,   3,  64,   9, 222,   3,  64,   7,
 145,   1, 223,   3,   9, 223,   3,  64,   9, 224,   3,  64,   9, 225,   3,  64,
   9, 226,   3,  64,   9, 190,   3,  64,   9, 166,   3,  64,   9, 227,   3,  54,
   7,  38, 228,   3,   9, 229,   3,  54,   9, 230,   3,  54,   9, 231,   3,  54,
   9, 232,   3,  54,   9, 233,   3,  54,   9, 234,   3,  54,   9, 235,   3,  54,
   9, 236,   3,  54,   9, 237,   3,  64,   9, 175,   3,  64,   9, 164,   3,  64,
   9, 239,   3,  64,   9, 186,   3,  64,   9, 240,   3,  64,   9, 241,   3,  64,
   9, 182,   3,  64,   9, 254,   2,  64,   9, 199,   3,  64,   9, 251,   2,  65,
   9,  24,  64,   9, 174,   3,  64,   9, 240,   3,  54,   9, 241,   3,  54,   9,
 246,   3,  54,   9, 247,   3,  54,   9, 248,   3,  54,   9, 249,   3,  54,   9,
 250,   3,  54,   9, 251,   3,  54,   9, 252,   3,  54,   9, 253,   3,  64,   9,
 194,   3,  64,   9, 173,   3,  64,   9, 245,   2,  64,   9, 241,   2,  64,   9,
 179,   3,  64,   9, 168,   3,  64,   9, 128,   4,  54,   9, 162,   3,  64,   9,
 170,   3,  64,   9, 129,   4,  64,   9, 213,   3,   4,   9, 131,   4,   4,   9,
 132,   4,  66,   9, 201,   3,   4,   9, 133,   4,  66,   9, 219,   3,  66,   9,
 200,   3,  66,   9, 226,   3,   4,   9, 239,   3,  66,   9, 176,   3,  66,   9,
 177,   3,  66,   9, 199,   3,  66,   9, 208,   3,   4,   9, 134,   4,  66,   9,
 135,   4,  66,   9, 215,   3,  54,   9, 218,   3,  54,   9, 204,   3,  67,   9,
 210,   3,  66,   9, 223,   3,  67,   9, 206,   3,  66,   9, 209,   3,  66,   9,
 222,   3,   4,   9, 136,   4,   4,   9, 137,   4,   4,   9, 241,   2,   4,   9,
 225,   3,   4,   9, 138,   4,   4,   9, 247,   2,  68,   9, 162,   3,  68,   9,
 164,   3,  68,   9, 166,   3,  68,   9, 168,   3,  68,   9, 140,   4,  68,   9,
 131,   3,  68,   9, 203,   3,  68,   9, 197,   3,  68,   9, 194,   3,  68,   9,
 182,   3,  68,   9, 141,   4,  68,   9, 243,   3,  68,   9, 222,   3,  68,   9,
 242,   3,  68,   9, 212,   3,  68,   9, 183,   3,  68,   9, 241,   2,  68,   9,
 137,   4,  68,  27,  68,   9, 218,   3,  68,   9, 245,   2,  68,   9, 204,   3,
  68,   9, 223,   3,  68,   9, 173,   3,  68,   9, 142,   4,  68,   9, 174,   3,
  68,   9, 143,   4,  68,   9, 172,   3,  68,   9, 144,   4,  68,   9, 175,   3,
  68,   9, 145,   4,  68,   9, 176,   3,  68,   9, 146,   4,  68,   9, 147,   4,
  54,   9, 148,   4,  54,   9, 149,   4,  54,   9, 150,   4,  54,   9, 151,   4,
  54,   9, 245,   2,  54,   9, 152,   4,  54,   9, 153,   4,  54,   9, 253,   3,
  68,   9, 215,   3,  68,   9, 178,   3,  68,   9, 220,   3,  68,   9, 179,   3,
  68,   9, 154,   4,  68,   9, 216,   3,  68,   9, 185,   3,  68,   9, 217,   3,
  68,   9, 192,   3,  68,   9, 191,   3,  68,   9, 190,   3,  68,   9, 244,   3,
  68,   9, 245,   3,  68,   9, 189,   3,  68,   9, 193,   3,  68,   9, 219,   3,
  68,   9, 224,   3,  68,   9, 225,   3,  68,   9, 184,   3,  68,   9, 187,   3,
  68,   9, 226,   3,  68,   9, 180,   3,  68,   9, 201,   3,  68,   9, 213,   3,
  68,   9, 210,   3,  68,   9, 214,   3,  68,   9, 157,   4,  68,   9, 159,   4,
  68,   9, 196,   3,  68,   9, 160,   4,  54,   9, 161,   4,  54,   9, 162,   4,
  54,   9, 237,   3,  68,   9, 203,   3,   4,   9, 219,   3,   4,   9, 140,   4,
   4,   9, 214,   3,   4,   9, 237,   3,   4,   9, 253,   3,   4,   9, 164,   4,
   4,   9, 224,   3,   4,   9, 215,   3,   4,   9, 218,   3,   4,   9, 204,   3,
   4,   9, 210,   3,   4,   9, 223,   3,   4,   9, 146,   4,   4,   9, 142,   4,
   4,   9, 143,   4,   4,   9, 159,   4,  69,   9, 144,   4,   4,   9, 145,   4,
   4,   9,  11,  70,   9, 170,   3,  26,   9,  24,  71,   9, 197,   3,  54,   9,
 247,   2,  26,   9, 202,   3,  54,   9, 228,   3,  26,   9,  33,  71,   9, 166,
   4,  54,   9, 170,   3,  30,   9, 247,   2,  30,   9, 228,   3,  30, 211,   2,
   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,
   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,
   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,
   1,   0,   1,   1,   0,   1,   0,   0,   6,   1,   0,   0,   8,   1,   0,   0,
   0,   1,   4,   0,   0,   1,   4,   1,  13,   6,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1,  21,  21,   1,
  32,   0,   0,   1,   0,   0,   0,   1,   0,   1,   1,  26,   1,  32,   1,  26,
   6,   1,  32,   1,   1,  26,   1,  32,   0,   6,   1,  32,   0,   6,   1,  32,
   0,   6,   1,  32,   1,   1,  27,   1,  32,   1,   1,   6,   1,  32,   0,   1,
   1,  32,   0,   2,   1,  32,   0,  21,   1,  32,   0,   8,   1,  32,   0,  27,
   1,  32,   0,   6,   1,  32,   0,  21,   1,  32,   0,  21,   1,  32,   0,  21,
   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   1,   2,
  20,   1,  32,   0,  26,   1,  32,   0,  26,   1,  32,   1,   1,  28,   1,  32,
   1,   1,  26,   1,  32,   1,   1,  21,   1,  40,   1,   1,   6,   0,   2,   1,
  32,   1,   0,   0,   1,  32,   1,   2,   0,   1,  32,   1,   1,  29,   1,  32,
   1,   0,   0,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   1,   2,   6,
   1,  32,   1,   6,   6,   1,  32,   2,   1,   6,   6,   1,  32,   1,  63,   6,
   1,  32,   2,   2,   6,  63,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   6,   1,   0,   0,   2,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
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
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0, 219,   2,   1,  32,   0,   8,   1,  32,   1,
   1, 219,   2,   1,  32,   1,   0, 219,   2,   1,   0,   2,   0,  63,   8,   1,
  40,   1,   3,   3,   1,  13,   6,   1,  32,   2,   0,   6,   8,   1,   8,   1,
   3,   3,   0,  63,   1,  32,   1,   0,  63,   1,  32,   0,   0,   1,   0,   1,
   6,   6,   1,  32,   1,  20,  29,   1,  32,   1,  27,  29,   1,  32,   2,   2,
  20, 234,   2,   1,  32,   3,  21,  20, 234,   2,   8,   1,  32,   2,  21,  20,
 234,   2,   1,   0,   2,  21,  20, 234,   2,   1,   0,   2,  21,  20, 234,   2,
   1,   0,   0,  21,   1,  32,   1,  20,  13,   1,  32,   0,  20,   1,   0,   2,
  20,  20,   2,   1,  40,   1,  10,  10,   1,  21,   0,   1,  32,   1,   1,  29,
   1,  32,   0,   0,   1,   2,   1,   1,  29,   1,   2,   1,   1,   2,   1,  32,
   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,
   0,   0,   1,   0,   0,   6,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,  32,   0,  21,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   2,   0,  26,  26,
   1,  40,   1,   4,   3,   1,  26,  26,   1,  40,   1,   4,   3,   1,   0,  29,
   1,  32,   0,  29,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0, 199,
   3,   1,   0,   0,   1,   1,   0,   1,   1,   6,   1,  32,   0,   0,   1,   0,
   0,   6,   1,  32,   1,   2,  27,   1,  40,   1,  12,  12,   0, 213,   3,   1,
   0,   0, 213,   3,   1,  32,   1,   2, 199,   3,   1,  32,   0,   2,   1,  32,
   0, 200,   3,   1,  32,   2,   1,   6,   0,   1,  32,   1,   0,   6,   1,  32,
   0,   2,   1,  32,   5,   1,   6,  29,   2,  26,   2,   1,   8,   3,  10,  10,
   3,   3,  10,  10,   1,   0, 224,   3,   1,   2,   0,  26,   1,  32,   0,   0,
   1,   0,   2,   0,   6,   6,   1,   0,   0,   6,   1,   0,   0,   6,   1,   0,
   0,  20,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0, 139,   4,   1,
   0,   0,   0,   1,   0,   1, 199,   3,  63,   1,   0,   0, 199,   3,   1,   0,
   1, 199,   3,  63,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,  26,   1,  32,   1,  26, 213,   3,   1,  32,
   2,   1, 213,   3,  26,   1,  32,   1,   8, 213,   3,   1,  32,   2,   1, 213,
   3,   8,   1,  32,   1,   2, 213,   3,   1,  32,   1,   1, 213,   3,   1,  32,
   3,   1, 200,   3,  26,  26,   1,  32,   3,   1, 200,   3,  26,  26,   1,  32,
   2,   2, 213,   3,  26,   1,   0,   1,   2,   2,   1,  32,   1,   1,   6,   1,
  32,   1,   1,  20,   1,  32,   1,   1,   0,   1,  32,   0,   0,   1,   0,   0,
   0,   1,   0,   1, 213,   3,  20,   1,   0,   0, 213,   3,   1,   0,   1,  20,
 213,   3,   1,   0,   2,   1, 213,   3,  26,   1,  32,   0,   1,   1,  32,   2,
 213,   3, 200,   3, 200,   3,   1,  32,   2, 213,   3,  20,   2,   1,  32,   4,
   1,   8,   8, 200,   3, 200,   3,   1,  32,   1,   1, 213,   3,   1,  32,   0,
   2,   1,  32,   1,   0, 243,   4,   1,   2,   1,   0, 243,   4,   1,   2,   0,
 213,   3,   1,   0,   1,   1,  20,   1,   0,   2,   0,  20,   8,   1,   0,   2,
   0,  20,   8,   1,   0,   2,   1,  29,  29,   1,  10,   1,  12,  12,   0,   0,
   1,   2,   1,   1,   8,   1,  32,   0,   6,   1,   0,   0,   8,   1,   0,   0,
   0,   1,   0,   0,   0,   1,   0,   3, 213,   4, 200,   3, 200,   3,   8,   1,
  32,   0,  13,   1,  32,   2,   0,   0, 243,   4,   1,  32,   2,   0,   0, 243,
   4,   1,  32,   1,   2,   2,   1,   2,   0,   2,   1,   0,   1,   1,   0,   1,
  32,   0,   1,   1,   2,   0,   1,   1,   0,   4,   0, 213,   3, 200,   3, 200,
   3,   8,   1,   0,   0,   1,   1,   2,   0,   1,   1,   2,   0,   0,   1,   0,
   0,   0,   1,   0,   1,   0,   8,   1,   0,   0,   6,   1,  32,   0,   0,   1,
   0,  50,  37,   0,  39,   1,  40,  41, 100,   1,   0, 101, 100,   1,   0, 104,
 100,   1,   0, 107, 100,   1,   0, 110, 100,   1,   0, 113, 100,   1,   0, 116,
 100,   2,   0,   0, 101, 104, 100,   3,   0,   0,   0, 110, 104, 116, 100,   3,
   0,   0,   0, 113, 101, 104, 204,   1,   3, 205,   1, 207,   1, 209,   1, 206,
   1, 208,   1, 210,   1, 204,   1,   4, 205,   1, 213,   1, 209,   1, 216,   1,
 212,   1, 214,   1, 215,   1, 217,   1, 204,   1,   3, 205,   1, 209,   1, 216,
   1, 218,   1, 215,   1, 217,   1, 204,   1,   5, 205,   1, 207,   1, 222,   1,
 209,   1, 216,   1, 220,   1, 221,   1, 214,   1, 215,   1, 223,   1, 204,   1,
   4, 205,   1, 207,   1, 222,   1, 209,   1, 224,   1, 225,   1, 214,   1, 215,
   1, 204,   1,   5, 205,   1, 207,   1, 222,   1, 209,   1, 216,   1, 226,   1,
 227,   1, 214,   1, 215,   1, 228,   1, 204,   1,   4, 205,   1, 207,   1, 222,
   1, 209,   1, 229,   1, 230,   1, 214,   1, 215,   1, 204,   1,   5, 205,   1,
 207,   1, 222,   1, 209,   1, 216,   1, 231,   1, 232,   1, 214,   1, 215,   1,
 233,   1, 204,   1,   4, 205,   1, 207,   1, 222,   1, 209,   1, 234,   1, 235,
   1, 214,   1, 215,   1, 204,   1,   5, 205,   1, 207,   1, 222,   1, 209,   1,
 216,   1, 236,   1, 237,   1, 214,   1, 215,   1, 238,   1, 204,   1,   5, 205,
   1, 207,   1, 222,   1, 209,   1, 216,   1, 239,   1, 240,   1, 214,   1, 215,
   1, 204,   1, 204,   1,   1, 216,   1, 204,   1, 204,   1,   1, 241,   1, 242,
   1, 204,   1,   1, 241,   1, 243,   1, 204,   1,   4, 205,   1, 222,   1, 207,
   1, 209,   1, 132,   2, 214,   1, 133,   2, 215,   1, 204,   1,   3, 205,   1,
 207,   1, 209,   1, 163,   2, 174,   2, 215,   1, 204,   1,   1,   0, 176,   2,
 204,   1,   1,   0, 178,   2, 204,   1,   1,   0, 180,   2, 204,   1,   1,   0,
 182,   2, 204,   1,   1,   0, 184,   2, 204,   1,   1,   0, 186,   2, 204,   1,
   1,   0, 188,   2, 204,   1,   1,   0, 190,   2, 204,   1,   1,   0, 192,   2,
 204,   1,   1,   0, 194,   2, 204,   1,   1,   0, 198,   2, 204,   1,   1,   0,
 200,   2, 204,   1,   1,   0, 202,   2, 204,   1,   1,   0, 204,   2, 204,   1,
   1,   0, 206,   2, 100,   1,   0, 207,   2, 204,   1,   3, 205,   1, 209,   1,
 216,   1, 224,   2, 215,   1, 217,   1, 204,   1,   4, 205,   1, 207,   1, 209,
   1, 216,   1, 151,   3, 152,   3, 215,   1, 204,   1, 204,   1,   3, 205,   1,
 207,   1, 209,   1, 159,   3, 160,   3, 215,   1, 204,   1,   2, 205,   1, 209,
   1, 167,   4, 215,   1, 204,   1,   4, 205,   1, 207,   1, 209,   1, 216,   1,
 168,   4, 169,   4, 215,   1, 204,   1, 204,   1,   4, 205,   1, 207,   1, 209,
   1, 216,   1, 170,   4, 171,   4, 215,   1, 204,   1, 204,   1,   3, 205,   1,
 207,   1, 209,   1, 172,   4, 173,   4, 215,   1,  58,  17,   0,   5,   0,  39,
   1,  16,   1,   0,  38,  19,  20,   9,   9,   0,  42,   1,  18,   1,   0,  41,
  23,  20,   9,  11,   0,  45,   1,  22,   1,   0,  44,  62,  20,   9,  13,   0,
  78,   0,  68,  20,   9,  19,   0,  85,   0,  69,  20,   9,  22,   0,  87,   0,
  70,  20,   9,  24,   0,  89,   0,  71,  20,   9,  26,   0,  91,   0,  72,  20,
   9,  28,   0,  93,   0,  73,  20,   9,  30,   0,  95,   0,  74,  20,   9,  32,
   0,  97,   0,  77,  20,   9,  34,   0,  99,   0,  80,  20,   9,  36,   0, 101,
   0,  84,  20,  11,  40,   0, 105,   0, 125,  20,   9,  49,   0, 137,   1,  50,
  85,   0,   0,   2,  11,  11,  86,  64,   0,   2,  11,  11,   1,   2,  87,  64,
   0,   2,  11,  11,   1,   3,  88,  64,   0,   2,  11,  11,   1,   4,  89,  64,
   0,   2,  11,  11,   1,   5,  90,  64,   0,   2,  11,  11,   1,   6,  91,  64,
   0,   2,  11,  11,   1,   7,  92,  64,   0,   2,  11,  11,   1,   8,  93,  64,
   0,   2,  11,  11,   1,   9,  94,  64,   0,   2,  11,  11,   1,  10,  95,   6,
   0,   2,  11,  11,  96,  70,   0,   2,  11,  11,   1,   2,  97,  70,   0,   2,
  11,  11,   1,   3,  98,  70,   0,   2,  11,  11,   1,   4,  99,  70,   0,   2,
  11,  11,   1,   5, 100,  70,   0,   2,  11,  11,   1,   6, 101,  70,   0,   2,
  11,  11,   1,   7, 102,  70,   0,   2,  11,  11,   1,   8, 103,  70,   0,   2,
  11,  11,   1,   9, 104,  70,   0,   2,  11,  11,   1,  10, 105,   1,   0, 107,
 106,  65,   0, 108,   1,   2, 107,  65,   0, 109,   1,   3, 108,  65,   0, 110,
   1,   4, 109,  65,   0, 111,   1,   5, 110,  65,   0, 112,   1,   6, 111,  65,
   0, 113,   1,   7, 112,  65,   0, 114,   1,   8, 113,  65,   0, 115,   1,   9,
 114,  65,   0, 116,   1,  10, 115,   2,   0, 117, 116,  66,   0, 118,   1,   2,
 117,  66,   0, 119,   1,   3, 118,  66,   0, 120,   1,   4, 119,  66,   0, 121,
   1,   5, 120,  66,   0, 122,   1,   6, 121,  66,   0, 123,   1,   7, 122,  66,
   0, 124,   1,   8, 123,  66,   0, 125,   1,   9, 124,  66,   0, 126,   1,  10,
 115,   3,   0, 127, 116,  67,   0, 128,   1,   1,   2, 117,  67,   0, 129,   1,
   1,   3, 118,  67,   0, 130,   1,   1,   4, 119,  67,   0, 131,   1,   1,   5,
 120,  67,   0, 132,   1,   1,   6, 121,  67,   0, 133,   1,   1,   7, 122,  67,
   0, 134,   1,   1,   8, 123,  67,   0, 135,   1,   1,   9, 124,  67,   0, 136,
   1,   1,  10, 126,  20,   9,  51,   0, 139,   1,   0, 127,  20,   9,  53,   0,
 141,   1,   0, 128,   1,  20,   9,  55,   0, 143,   1,   0, 129,   1,  20,   9,
  57,   0, 145,   1,   0, 130,   1,  20,   9,  59,   0, 147,   1,   0, 131,   1,
  20,   9,  61,   0, 149,   1,   0, 132,   1,  20,   9,  63,   0, 151,   1,   0,
 133,   1,  20,   9,  65,   0, 153,   1,   0, 134,   1,  20,   9,  67,   0, 155,
   1,   0, 135,   1,   0,   5,   0, 157,   1,   0, 136,   1,   0,   5,   0, 159,
   1,   0, 137,   1,   0,   5,   0, 161,   1,   0, 138,   1,   0,   5,   0, 163,
   1,   0, 139,   1,   0,   5,   0, 165,   1,   0, 140,   1,   0,   5,   0, 167,
   1,   0, 141,   1,   0,   5,   0, 169,   1,   0, 142,   1,   0,   5,   0, 171,
   1,   0, 143,   1,   0,   5,   0, 173,   1,   0, 144,   1,   0,   5,   0, 175,
   1,   0, 145,   1,  69,   9,  69,   0, 177,   1,   0, 146,   1,  69,   9,  71,
   0, 179,   1,   0, 147,   1,  70,   9,  73,   0, 181,   1,   0, 148,   1,  70,
   9,  75,   0, 183,   1,   0, 149,   1,  71,   9,  77,   0, 185,   1,   0, 150,
   1,  71,   9,  79,   0, 187,   1,   0, 152,   1,  73,   9,  81,   0, 189,   1,
   1, 151,   1,   0,   0,  26,   0, 156,   1,  73,   9,  83,   0, 191,   1,   3,
 153,   1,   0,   0,  26,   0, 154,   1,   0,   0,  26,   0, 155,   1,   0,   0,
  26,   0, 219,   2,  20,   9,  96,   0, 197,   1,   6, 226,   2,   1,   0, 196,
   1, 227,   2,   1,   0, 198,   1, 228,   2,   1,   0, 199,   1, 229,   2,   1,
   0, 200,   1, 230,   2,   2,   0, 201,   1, 230,   2,   3,   0, 202,   1, 251,
   2,  20,  11, 102,   0, 227,   1,   5, 246,   2,   6,   0,   6,   0, 247,   2,
   6,   0,   6,   0, 248,   2,   6,   0,   8,   0, 249,   2,   6,   0,  21,   0,
 250,   2,   1,   0, 226,   1, 254,   2,  20,   9, 105,   0, 229,   1,   2, 252,
   2,   6,   0,  21,   0, 253,   2,   6,   0,  27,   0, 135,   3,  20,  11, 107,
   0, 231,   1,   0, 140,   3, 254,   2,  11, 109,   0, 235,   1,   4, 136,   3,
   6,   0,  21,   0, 137,   3,   6,   0,  13,   0, 138,   3,   2,   0, 233,   1,
 139,   3,   2,   0, 234,   1, 141,   3, 254,   2,  11, 111,   0, 237,   1,   2,
 136,   3,   6,   0,  21,   0, 139,   3,   6,   0,  21,   0, 186,   3,  20,   9,
 115,   0, 244,   1,   0, 193,   3,  20,   9, 120,   0, 247,   1,   0, 199,   3,
  20,  11, 126,   0, 253,   1,  16, 232,   3,   2,   0, 254,   1, 233,   3,   1,
   0, 255,   1, 234,   3,   1,   0, 128,   2, 235,   3,   1,   0, 129,   2, 236,
   3,   1,   0, 130,   2, 237,   3,   2,   0, 131,   2, 238,   3,   1,   0, 132,
   2, 239,   3,   1,   0, 133,   2, 240,   3,   1,   0, 134,   2, 241,   3,   1,
   0, 135,   2, 242,   3,   1,   0, 136,   2, 243,   3,   1,   0, 137,   2, 244,
   3,   2,   0, 138,   2, 245,   3,   0,   0,  63,   0, 246,   3,   0,   0, 200,
   3,   0, 247,   3,   0,   0, 249,   3,   0, 224,   3,  20,  11, 130,   1,   0,
 140,   2,   6, 255,   3,   2,   0, 141,   2, 128,   4,   2,   0, 142,   2, 129,
   4,   2,   0, 143,   2, 130,   4,   0,   0,   6,   0, 131,   4,   0,   0,   6,
   0, 132,   4,   0,   0,  20,   0, 139,   4,  20,  11, 134,   1,   0, 147,   2,
   3, 142,   4,   1,   0, 148,   2, 143,   4,   1,   0, 149,   2, 144,   4,   1,
   0, 150,   2, 155,   4,  20,  11, 137,   1,   0, 153,   2,   0, 196,   4,  20,
  11, 140,   1,   0, 169,   2,   0, 213,   3,  20,  10, 143,   1,   0, 192,   2,
  17, 169,   5,   1,   0, 180,   2, 170,   5,   1,   0, 181,   2, 171,   5,   1,
   0, 182,   2, 172,   5,   0,   0, 200,   3,   0, 173,   5,   0,   0, 200,   3,
   0, 174,   5,   0,   0,  20,   0, 175,   5,   0,   0,   2,   0, 176,   5,   0,
   0,   8,   0, 177,   5,   0,   0,   2,   0, 178,   5,   0,   0, 213,   3,   0,
 179,   5,   2,   0, 183,   2, 180,   5,   1,   0, 184,   2, 181,   5,   1,   0,
 187,   2, 182,   5,   1,   0, 188,   2, 183,   5,   1,   0, 189,   2, 232,   3,
   2,   0, 190,   2, 184,   5,   1,   0, 191,   2, 213,   4,  20,  11, 147,   1,
   0, 206,   2,  12, 140,   6,   0,   0,   8,   0, 141,   6,   0,   0, 200,   3,
   0, 142,   6,   0,   0, 200,   3,   0, 143,   6,   0,   0,  20,   0, 144,   6,
   0,   0,   2,   0, 145,   6,   0,   0,   8,   0, 146,   6,   1,   0, 200,   2,
 147,   6,   1,   0, 201,   2, 148,   6,   1,   0, 202,   2, 149,   6,   1,   0,
 203,   2, 150,   6,   1,   0, 204,   2, 151,   6,   1,   0, 205,   2, 243,   4,
  27,   8, 150,   1,   0, 208,   2,   1, 246,   2,   2,   0, 209,   2,  37,   0,
  40,   0,  43,   0,  46,  32,  30,  81,   3,  47,   1,   0,  31,  81,   4,  48,
   1,   1,  32,  17,   5,  49,  33,  17,   6,  50,  34,  17,   7,  51,  35,  17,
   8,  52,  36,  17,   9,  53,  37,  17,  10,  54,  38,  17,  11,  55,  39,  17,
  12,  56,  40,  17,  13,  57,  41,  17,  14,  58,  42,  17,  15,  59,  43,   6,
   1,  27,   0,  44,  17,  16,  60,  45,  18,  17,  61,  46,  18,  18,  62,  47,
  18,  19,  63,  48,  17,  20,  64,  49,  17,  21,  65,  50,  17,  22,  66,  51,
  17,  23,  67,  52,  18,  24,  68,  53,  18,  25,  69,  54,  17,  26,  70,  55,
  17,  27,  71,  56,  17,  28,  72,  57,  17,  29,  73,  58,  17,  30,  74,  59,
  17,  31,  75,  60,  17,  32,  76,  61,  17,  33,  77,  79,   5,  64,  17,   3,
  80,  65,  17,   4,  81,  37,  17,   5,  82,  66,  17,   6,  83,  67,  17,   7,
  84,  86,   0,  88,   0,  90,   0,  92,   0,  94,   0,  96,   0,  98,   1,  76,
   0,   1,  26,   1,   3, 100,   1,  79,   0,   1,  26,   2,   3, 102,   2,  83,
  18,   3, 103,  39,  18,   4, 104, 106,   0, 138,   1,   0, 140,   1,   0, 142,
   1,   0, 144,   1,   0, 146,   1,   0, 148,   1,   0, 150,   1,   0, 152,   1,
   0, 154,   1,   0, 156,   1,   0, 158,   1,   0, 160,   1,   0, 162,   1,   0,
 164,   1,   0, 166,   1,   0, 168,   1,   0, 170,   1,   0, 172,   1,   0, 174,
   1,   0, 176,   1,   0, 178,   1,   0, 180,   1,   0, 182,   1,   0, 184,   1,
   0, 186,   1,   0, 188,   1,   0, 190,   1,   0, 193,   1,   2, 224,   2,  18,
   3, 194,   1, 225,   2,  18,   4, 195,   1, 225,   1,   0, 228,   1,   0, 230,
   1,   4, 131,   3,   6,   1,  13,   0, 132,   3,   6,   2,  13,   0, 133,   3,
   6,   3,  13,   0, 134,   3,   6,   4,  13,   0, 232,   1,   0, 236,   1,   0,
 239,   1,  11, 175,   3,   6,   1,  26,   3,   3, 176,   3,   6,   2,  26,   5,
   3, 177,   3,   6,   3,  26,   4,   3, 178,   3,   6,   4,  26,   6,   3, 179,
   3,   6,   5,  26,   7,   3, 180,   3,   6,   6,   0,   5,   3, 181,   3,   6,
   7,   0,   4,   3, 182,   3,  17,   3, 240,   1, 183,   3,  17,   4, 241,   1,
 184,   3,  17,   5, 242,   1, 185,   3,  17,   6, 243,   1, 246,   1,   2, 191,
   3,   6,   1,   6, 227,   2,   1, 192,   3,   6,   2,   6, 229,   2,   1, 249,
   1,   5, 226,   3,  18,   3, 250,   1, 227,   3,  17,   4, 251,   1, 228,   3,
  17,   5, 252,   1, 229,   3,   0,   1, 199,   3,   0, 230,   3,   0,   2, 231,
   3,   0, 139,   2,   1, 254,   3,   6,   1,   6, 145,   3,   1, 145,   2,   2,
 226,   3,  18,   3, 146,   2, 141,   4,   0,   1, 139,   4,   0, 152,   2,   4,
 151,   4,   6,   1,   6, 163,   3,   1, 152,   4,   6,   2,   6, 165,   3,   1,
 153,   4,   6,   3,   6, 167,   3,   1, 154,   4,   6,   4,   6, 169,   3,   1,
 154,   2,  25, 171,   4,   6,   1,   8,   3,   3, 172,   4,   6,   2,   8,   5,
   3, 173,   4,   6,   3,   8,   6,   3, 174,   4,   6,   4,   8,   7,   3, 175,
   4,   6,   5,   8,   9,   3, 176,   4,   6,   6,   8,  10,   3, 177,   4,   6,
   7,   8,   3,   3, 178,   4,   6,   8,   8,   5,   3, 179,   4,  18,   3, 155,
   2, 180,   4,  17,   4, 156,   2, 181,   4,  17,   5, 157,   2, 182,   4,  17,
   6, 158,   2, 183,   4,  17,   7, 159,   2, 184,   4,  17,   8, 160,   2, 185,
   4,  17,   9, 161,   2, 186,   4,  17,  10, 162,   2, 187,   4,  17,  11, 163,
   2, 188,   4,  17,  12, 164,   2, 189,   4,   0,   9,  27,   0, 190,   4,   0,
  10, 191,   4,   0, 192,   4,   0,  11, 191,   4,   0, 193,   4,  17,  13, 165,
   2, 228,   3,  17,  14, 166,   2, 194,   4,  17,  15, 167,   2, 195,   4,  17,
  16, 168,   2, 170,   2,  16, 157,   5,  17,   3, 171,   2, 158,   5,  17,   4,
 172,   2, 159,   5,  17,   5, 173,   2, 160,   5,  17,   6, 174,   2, 161,   5,
  17,   7, 175,   2, 162,   5,  17,   8, 176,   2, 163,   5,  17,   9, 177,   2,
 164,   5,  17,  10, 178,   2, 165,   5,  17,  11, 179,   2, 151,   4,   6,   1,
   8,   3,   3, 152,   4,   6,   2,   8,  11,   3, 153,   4,   6,   3,   8,  10,
   3, 154,   4,   6,   4,   8,  12,   3, 166,   5,   6,   5,   8,   9,   3, 167,
   5,   6,   6,   8,  10,   3, 168,   5,   0,   7,  27,   0, 193,   2,  11, 151,
   4,   6,   1,   8,   3,   3, 152,   4,   6,   2,   8,  11,   3, 153,   4,   6,
   3,   8,  10,   3, 154,   4,   6,   4,   8,  12,   3, 133,   6,   0,   5,  27,
   0, 134,   6,  17,   3, 194,   2, 135,   6,  18,   4, 195,   2, 136,   6,  17,
   5, 196,   2, 137,   6,  17,   6, 197,   2, 138,   6,  17,   7, 198,   2, 139,
   6,  17,   8, 199,   2, 207,   2,   0,   8, 203,   1,   1, 233,   2,  68,   0,
  42,   1,  25, 238,   1,  25, 143,   3,   4,   1,  43, 144,   3,   4,   2,  44,
 145,   3,  68,   3,  46,   1,  26, 146,   3,   4,   4,  47, 147,   3,  65,  38,
 224,   1,   1,  27, 148,   3,  65,  39, 223,   1,   1,  28, 149,   3,  65,  40,
 222,   1,   1,  29, 150,   3,  65,  41, 221,   1,   1,  30, 151,   3,  65,  42,
 220,   1,   1,  31, 152,   3,   1,  43, 219,   1, 153,   3,  65,  44, 217,   1,
   1,  32, 154,   3,  65,  45, 216,   1,   1,  33, 155,   3,  65,  46, 215,   1,
   1,  34, 156,   3,   1,  47, 214,   1, 157,   3,  65,  48, 213,   1,   1,  35,
 158,   3,  65,  49, 212,   1,   1,  36, 159,   3,   1,  50, 211,   1, 160,   3,
   1,  51, 210,   1, 161,   3,   1,  52, 209,   1, 162,   3,  65,  53, 208,   1,
   1,  37, 163,   3,  65,  54, 207,   1,   1,  38, 164,   3,  65,  55, 206,   1,
   1,  39, 165,   3,  65,  56, 205,   1,   1,  40, 166,   3,  65,  57, 204,   1,
   1,  41, 167,   3,  68,   5,  45,   1,  42, 245,   1,   1, 188,   3,  68,   1,
  48,   1,  43, 248,   1,   1, 195,   3,   4,   1,  49, 144,   2,   2, 136,   4,
  68,   0,  50,   1,  44, 137,   4,   4,   0,  51, 151,   2,   1, 146,   4,  68,
   1,  52,   1,  45, 210,   2,   6, 160,   6,   6,   0,   0, 145,   1,   8, 161,
   6,   4,   0,  53, 155,   6,  68,   0,  54,   1,  46, 162,   6,  68,   0,  55,
   1,  47, 157,   6,  68,   0,  56,   1,  48, 163,   6,  68,   0,  57,   1,  49,
 192,   1, 106, 130,   2,   6,   0,   0,  16,   8, 157,   1,   4,   0,   0, 158,
   1,   4,   0,   1, 160,   1,  68,   0,   2,   1,  11, 131,   2,  68,   0,   3,
   1,  12, 132,   2,  68,   0,   4,   1,  13, 133,   2,   1,   1,  36, 134,   2,
  68,   0,   5,   1,  14, 135,   2,  68,   0,  34,   1,  15, 136,   2,   4,   0,
  35, 137,   2,  68,   0,   6,   1,  16, 138,   2,  68,   0,  36,   1,  17, 139,
   2,   4,   0,  37, 140,   2,  68,   0,   7,   1,  18, 141,   2,  68,   0,  38,
   1,  19, 142,   2,   4,   0,  39, 143,   2,  68,   0,   8,   1,  20, 144,   2,
  68,   0,   9,   1,  21, 145,   2,   4,   0,  40, 146,   2,   4,   0,  41, 147,
   2,  68,   0,  10,   1,  22, 148,   2,  68,   0,  11,   1,  23, 149,   2,  68,
   0,  12,   1,  24, 150,   2,   4,   0,  13, 151,   2,   1,   2,  35, 152,   2,
   1,   3,  34,  36,   1,   4,  33,  41,   1,   5,  32,  44,   1,   6,  31,  55,
   1,   7,  30, 153,   2,   6,   0,   0,   2,   6, 154,   2,   6,   0,   0,   3,
   6, 155,   2,   6,   0,   0,   4,   6, 156,   2,   6,   0,   0,   5,   6, 157,
   2,   6,   0,   0,   6,   6, 158,   2,   6,   0,   0,   7,   6, 159,   2,   0,
   0,   2,   0, 160,   2,  64,   0,   2,   0,   1,   2, 161,   2,  64,   0,   2,
   0,   1,   3, 162,   2,  64,   0,   2,   0,   1,   4, 163,   2,  64,   0,   2,
   0,   1,   5, 164,   2,  64,   0,   2,   0,   1,   6, 165,   2,  64,   0,   2,
   0,   1,   7, 166,   2,  64,   0,   2,   0,   1,   8, 167,   2,  64,   0,   2,
   0,   1,   9, 168,   2,  64,   0,   2,   0,   1,  10, 169,   2,   6,   0,   2,
  11,  11, 170,   2,  70,   0,   2,  11,  11,   1,   2, 171,   2,  70,   0,   2,
  11,  11,   1,   3, 172,   2,  70,   0,   2,  11,  11,   1,   4, 173,   2,  70,
   0,   2,  11,  11,   1,   5, 174,   2,  70,   0,   2,  11,  11,   1,   6, 175,
   2,  70,   0,   2,  11,  11,   1,   7, 176,   2,  70,   0,   2,  11,  11,   1,
   8, 177,   2,  70,   0,   2,  11,  11,   1,   9, 178,   2,  70,   0,   2,  11,
  11,   1,  10, 179,   2,   1,   8,  29, 180,   2,  65,   9,  28,   1,   2, 181,
   2,  65,  10,  27,   1,   3, 182,   2,  65,  11,  26,   1,   4, 183,   2,  65,
  12,  25,   1,   5, 184,   2,  65,  13,  24,   1,   6, 185,   2,  65,  14,  23,
   1,   7, 186,   2,  65,  15,  22,   1,   8, 187,   2,  65,  16,  21,   1,   9,
 188,   2,  65,  17,  20,   1,  10, 189,   2,   2,  18,  19, 190,   2,  66,  19,
  18,   1,   2, 191,   2,  66,  20,  17,   1,   3, 192,   2,  66,  21,  16,   1,
   4, 193,   2,  66,  22,  15,   1,   5, 194,   2,  66,  23,  14,   1,   6, 195,
   2,  66,  24,  13,   1,   7, 196,   2,  66,  25,  12,   1,   8, 197,   2,  66,
  26,  11,   1,   9, 198,   2,  66,  27,  10,   1,  10, 189,   2,   3,  28,   9,
 190,   2,  67,  29,   8,   1,   2, 191,   2,  67,  30,   7,   1,   3, 192,   2,
  67,  31,   6,   1,   4, 193,   2,  67,  32,   5,   1,   5, 194,   2,  67,  33,
   4,   1,   6, 195,   2,  67,  34,   3,   1,   7, 196,   2,  67,  35,   2,   1,
   8, 197,   2,  67,  36,   1,   1,   9, 198,   2,  67,  37,   0,   1,  10, 199,
   2,   4,   0,  14, 200,   2,  68,   0,  15,   1,   2, 201,   2,  68,   0,  16,
   1,   3, 202,   2,  68,   0,  17,   1,   4, 203,   2,  68,   0,  18,   1,   5,
 204,   2,  68,   0,  19,   1,   6, 205,   2,  68,   0,  20,   1,   7, 206,   2,
  68,   0,  21,   1,   8, 207,   2,  68,   0,  22,   1,   9, 208,   2,  68,   0,
  23,   1,  10, 209,   2,   4,   0,  24, 210,   2,  68,   0,  25,   1,   2, 211,
   2,  68,   0,  26,   1,   3, 212,   2,  68,   0,  27,   1,   4, 213,   2,  68,
   0,  28,   1,   5, 214,   2,  68,   0,  29,   1,   6, 215,   2,  68,   0,  30,
   1,   7, 216,   2,  68,   0,  31,   1,   8, 217,   2,  68,   0,  32,   1,   9,
 218,   2,  68,   0,  33,   1,  10, 223,   1,   0,   1,   2,   1,   2,   3, 208,
  48,  71,   0,   0,   1,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   2,
   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   3,   1,   2,   1,   2,   3,
 208,  48,  71,   0,   0,   4,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,
   5,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   6,   1,   2,   1,   2,
   3, 208,  48,  71,   0,   0,   7,   1,   2,   1,   2,   3, 208,  48,  71,   0,
   0,   8,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   9,   1,   2,   1,
   2,   3, 208,  48,  71,   0,   0,  10,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  11,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  12,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  13,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  14,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  15,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  16,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  17,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  18,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  19,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  20,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  21,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  22,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  23,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  24,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  25,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  26,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  27,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  28,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  29,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  30,   2,   2,   1,   2,  12, 208,  48,  93,
   3, 102,   3, 209,  70,   4,   1,  41,  71,   0,   0,  31,   1,   1,   1,   2,
  10, 208,  48,  93,   3, 102,   3,  70,   5,   0,  72,   0,   0,  32,   1,   1,
   1,   2,  10, 208,  48,  93,   3, 102,   3,  70,   7,   0,  72,   0,   0,  33,
   2,   2,   1,   2,  12, 208,  48,  93,   3, 102,   3, 209,  70,   9,   1,  41,
  71,   0,   0,  34,   2,   2,   1,   2,  12, 208,  48,  93,   3, 102,   3, 209,
  70,   9,   1,  41,  71,   0,   0,  35,   2,   2,   1,   2,  13, 208,  48,  93,
  10, 102,  10, 102,  11, 209,  70,  12,   1,  72,   0,   0,  36,   1,   1,   1,
   2,  11, 208,  48,  93,  14, 102,  14,  70,  15,   0,  41,  71,   0,   0,  37,
   0,   1,   3,   3,   1,  71,   0,   0,  40,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0,  41,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0,  42,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  43,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0,  45,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0,  46,   2,   1,   3,   4,  12, 208,  48,  94,  24,  93,
  25,  70,  25,   0, 104,  24,  71,   0,   0,  78,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0,  79,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0,  85,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
  86,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  87,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0,  88,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0,  89,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0,  90,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  91,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  92,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0,  93,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0,  94,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  95,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  96,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0,  97,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0,  98,   2,   1,   3,   4,   9, 208,  48,  94,  75,
  36,  42,  97,  75,  71,   0,   0,  99,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 100,   2,   1,   3,   4,   9, 208,  48,  94,  78,  36,
 101,  97,  78,  71,   0,   0, 101,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 102,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 103,
   1,   1,   3,   4,   5, 208,  48,  44,  92,  72,   0,   0, 104,   1,   1,   3,
   4,  10, 208,  48,  93,  81, 102,  81,  70,  82,   0,  72,   0,   0, 105,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 106,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 107,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 108,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 109,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 110,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 111,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 112,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 113,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 114,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 115,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 116,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 117,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 118,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 119,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 120,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 121,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 122,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 123,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 124,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 125,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 126,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 127,   1,   2,   4,   5,   3, 208,  48,  71,
   0,   0, 128,   1,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 129,   1,
   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 130,   1,   1,   2,   4,   5,
   3, 208,  48,  71,   0,   0, 131,   1,   1,   2,   4,   5,   3, 208,  48,  71,
   0,   0, 132,   1,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 133,   1,
   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 134,   1,   1,   2,   4,   5,
   3, 208,  48,  71,   0,   0, 135,   1,   1,   2,   4,   5,   3, 208,  48,  71,
   0,   0, 136,   1,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 137,   1,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 138,   1,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0, 139,   1,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 140,   1,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 141,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 142,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 143,
   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 144,   1,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 145,   1,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 146,   1,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0, 147,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 148,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 149,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 150,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 151,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 152,   1,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 153,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 154,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 155,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 156,   1,   0,   1,   3,   3,   1,  71,   0,   0, 158,   1,   0,   1,   3,   3,
   1,  71,   0,   0, 160,   1,   0,   1,   3,   3,   1,  71,   0,   0, 162,   1,
   0,   1,   3,   3,   1,  71,   0,   0, 164,   1,   0,   1,   3,   3,   1,  71,
   0,   0, 166,   1,   0,   1,   3,   3,   1,  71,   0,   0, 168,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 170,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 172,   1,   0,   1,   3,   3,   1,  71,   0,   0, 174,   1,   0,   1,   3,   3,
   1,  71,   0,   0, 176,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0,
 177,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 178,
   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 179,   1,   1,   1,   5,
   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 180,   1,   1,   1,   4,   5,
   3, 208,  48,  71,   0,   0, 181,   1,   1,   1,   5,   6,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 182,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 183,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 184,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 185,   1,   1,   1,
   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 186,   1,   1,   1,   4,
   5,   3, 208,  48,  71,   0,   0, 187,   1,   1,   1,   5,   6,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 188,   1,   1,   1,   4,   5,   3, 208,  48,  71,
   0,   0, 189,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 190,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 191,   1,   1,
   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 192,   1,   3,   1,
   1,   4, 203,   7, 208,  48,  93, 157,   1,  32,  88,   0, 104,  17,  93, 158,
   1,  93,  20, 102,  20,  48,  93, 159,   1, 102, 159,   1,  88,   1,  29, 104,
  19,  93, 160,   1,  93,  20, 102,  20,  48,  93, 159,   1, 102, 159,   1,  88,
   2,  29, 104,  23,  93, 161,   1,  93,  20, 102,  20,  48,  93, 159,   1, 102,
 159,   1,  88,   3,  29, 104,  62,  93, 162,   1,  93,  20, 102,  20,  48,  93,
 159,   1, 102, 159,   1,  88,   4,  29, 104,  68,  93, 163,   1,  93,  20, 102,
  20,  48,  93, 164,   1, 102, 164,   1,  88,   5,  29, 104,  69,  93, 165,   1,
  93,  20, 102,  20,  48,  93,  69, 102,  69,  48,  93, 166,   1, 102, 166,   1,
  88,  34,  29,  29, 104, 145,   1,  93, 167,   1,  93,  20, 102,  20,  48,  93,
  69, 102,  69,  48,  93, 166,   1, 102, 166,   1,  88,  35,  29,  29, 104, 146,
   1,  93, 168,   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,  88,
   6,  29, 104,  70,  93, 169,   1,  93,  20, 102,  20,  48,  93,  70, 102,  70,
  48,  93, 170,   1, 102, 170,   1,  88,  36,  29,  29, 104, 147,   1,  93, 171,
   1,  93,  20, 102,  20,  48,  93,  70, 102,  70,  48,  93, 170,   1, 102, 170,
   1,  88,  37,  29,  29, 104, 148,   1,  93, 172,   1,  93,  20, 102,  20,  48,
  93, 164,   1, 102, 164,   1,  88,   7,  29, 104,  71,  93, 173,   1,  93,  20,
 102,  20,  48,  93,  71, 102,  71,  48,  93, 174,   1, 102, 174,   1,  88,  38,
  29,  29, 104, 149,   1,  93, 175,   1,  93,  20, 102,  20,  48,  93,  71, 102,
  71,  48,  93, 174,   1, 102, 174,   1,  88,  39,  29,  29, 104, 150,   1,  93,
 176,   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,  88,   8,  29,
 104,  72,  93, 177,   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,
  88,   9,  29, 104,  73,  93, 178,   1,  93,  20, 102,  20,  48,  93,  73, 102,
  73,  48,  93, 179,   1, 102, 179,   1,  88,  40,  29,  29, 104, 152,   1,  93,
 180,   1,  93,  20, 102,  20,  48,  93,  73, 102,  73,  48,  93, 179,   1, 102,
 179,   1,  88,  41,  29,  29, 104, 156,   1,  93, 181,   1,  93,  20, 102,  20,
  48,  93, 164,   1, 102, 164,   1,  88,  10,  29, 104,  74,  93, 182,   1,  93,
  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,  88,  11,  29, 104,  77,  93,
 183,   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,  88,  12,  29,
 104,  80,  93, 184,   1,  93,  20, 102,  20,  48,  93, 185,   1, 102, 185,   1,
  88,  13,  29, 104,  84,  93, 186,   1,  93,  20, 102,  20,  48,  93, 164,   1,
 102, 164,   1,  88,  14,  29, 104, 125,  93, 187,   1,  93,  20, 102,  20,  48,
  93, 164,   1, 102, 164,   1,  88,  15,  29, 104, 126,  93, 188,   1,  93,  20,
 102,  20,  48,  93, 164,   1, 102, 164,   1,  88,  16,  29, 104, 127,  93, 189,
   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,  88,  17,  29, 104,
 128,   1,  93, 190,   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,
  88,  18,  29, 104, 129,   1,  93, 191,   1,  93,  20, 102,  20,  48,  93, 164,
   1, 102, 164,   1,  88,  19,  29, 104, 130,   1,  93, 192,   1,  93,  20, 102,
  20,  48,  93, 164,   1, 102, 164,   1,  88,  20,  29, 104, 131,   1,  93, 193,
   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,  88,  21,  29, 104,
 132,   1,  93, 194,   1,  93,  20, 102,  20,  48,  93, 164,   1, 102, 164,   1,
  88,  22,  29, 104, 133,   1,  93, 195,   1,  93,  20, 102,  20,  48,  93, 164,
   1, 102, 164,   1,  88,  23,  29, 104, 134,   1,  93, 196,   1,  32,  88,  24,
 104, 135,   1,  93, 197,   1,  32,  88,  25, 104, 136,   1,  93, 198,   1,  32,
  88,  26, 104, 137,   1,  93, 199,   1,  32,  88,  27, 104, 138,   1,  93, 200,
   1,  32,  88,  28, 104, 139,   1,  93, 201,   1,  32,  88,  29, 104, 140,   1,
  93, 202,   1,  32,  88,  30, 104, 141,   1,  93, 203,   1,  32,  88,  31, 104,
 142,   1,  93, 204,   1,  32,  88,  32, 104, 143,   1,  93, 205,   1,  32,  88,
  33, 104, 144,   1,  93, 206,   1,  37, 149,   5,  37, 148,   5, 161, 104, 207,
   1,  93, 208,   1,  37, 150,   5,  37, 148,   5, 161, 104, 209,   1,  93, 210,
   1,  37, 151,   5,  37, 148,   5, 161, 104, 211,   1,  93, 212,   1,  37, 152,
   5,  37, 148,   5, 161, 104, 213,   1,  93, 214,   1,  37, 153,   5,  37, 148,
   5, 161, 104, 215,   1,  93, 216,   1,  37, 154,   5,  37, 148,   5, 161, 104,
 217,   1,  93, 218,   1,  38,  97, 219,   1,  93, 220,   1,  38,  97, 221,   1,
  93, 222,   1,  38,  97, 223,   1,  93, 224,   1,  38,  97, 225,   1,  93, 226,
   1,  38,  97, 227,   1,  93, 228,   1,  38,  97, 229,   1,  93, 230,   1,  38,
  97, 231,   1,  93, 232,   1,  38,  97, 233,   1,  93, 234,   1,  38,  97, 235,
   1,  93, 236,   1,  38,  97, 237,   1,  93, 238,   1,  38, 104, 239,   1,  93,
 240,   1,  38, 104, 241,   1,  93, 242,   1,  38, 104, 243,   1,  93, 244,   1,
  38, 104, 245,   1,  93, 246,   1,  38, 104, 247,   1,  93, 248,   1,  38, 104,
 249,   1,  93, 250,   1,  38, 104, 251,   1,  93, 252,   1,  38, 104, 253,   1,
  93, 254,   1,  38, 104, 255,   1,  93, 128,   2,  38, 104, 129,   2,  71,   0,
   0, 193,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 197,   1,   2,
   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 220,   2,   1,  41,
  71,   0,   0, 200,   1,   3,   3,   4,   5,  20, 208,  48, 208,  93, 221,   2,
 102, 221,   2, 209,  70, 222,   2,   1, 210,  70, 223,   2,   2,  72,   0,   0,
 203,   1,   2,   1,   1,   3,  23, 208,  48,  93, 231,   2,  93,  20, 102,  20,
  48,  93, 232,   2, 102, 232,   2,  88,  42,  29, 104, 219,   2,  71,   0,   0,
 209,   1,   4,   3,   1,   2,  14, 208,  48,  93, 235,   2, 209, 210,  36,   1,
  70, 235,   2,   3,  72,   0,   0, 210,   1,   4,   3,   1,   2,  14, 208,  48,
  93, 235,   2, 209, 210,  36,   2,  70, 235,   2,   3,  72,   0,   0, 211,   1,
   4,   3,   1,   2,  14, 208,  48,  93, 235,   2, 209, 210,  36,   0,  70, 235,
   2,   3,  72,   0,   0, 214,   1,   2,   1,   1,   2,  13, 208,  48,  93, 236,
   2, 100, 108,   5,  70, 236,   2,   1,  72,   0,   0, 218,   1,   3,   3,   3,
   6,  47,  87,  42, 213,  48, 101,   0,  38, 118, 109,   1,  93, 237,   2,  76,
 237,   2,   0,  41,  16,  20,   0,   0, 209,  48,  90,   0,  42, 214,  42,  48,
  43, 109,   1, 101,   0,  39, 118, 109,   1,  29,   8,   2, 101,   0, 108,   1,
  72,   1,  10,  18,  22,   0, 238,   2,   1, 239,   2,   0,   1,   2,   0, 219,
   1,   2,   3,   2,   4,  60, 208,  48,  87,  42, 214,  48, 101,   1,  33, 130,
 109,   2, 101,   1, 209, 109,   1, 101,   1, 108,   1,  32,  19,  24,   0,   0,
 101,   1,  64, 218,   1, 130, 109,   2,  93, 240,   2, 101,   1, 108,   2,  70,
 240,   2,   1,  41,  16,   9,   0,   0,  93, 240,   2,  32,  70, 240,   2,   1,
  41,  71,   0,   2, 241,   2,   0,   1,  29,   0, 242,   2,   0,   2,   0,   0,
 225,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 226,   1,   3,   1,
   4,   5,  50, 208,  48, 208, 102, 243,   2,  44, 146,   2, 160, 208, 102, 244,
   2, 118,  18,  26,   0,   0,  44, 148,   2, 208, 102, 244,   2, 160,  44, 149,
   2, 160, 208, 102, 245,   2, 160,  44, 151,   2, 160, 130,  16,   3,   0,   0,
  44,   1, 130, 160,  72,   0,   0, 227,   1,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 228,   1,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0, 229,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 230,   1,   2,   1,   3,   4,  39, 208,  48,  94, 255,   2, 100, 108,   1,
 104, 255,   2,  94, 128,   3, 100, 108,   2, 104, 128,   3,  94, 129,   3, 100,
 108,   4, 104, 129,   3,  94, 130,   3, 100, 108,   3, 104, 130,   3,  71,   0,
   0, 231,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 232,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 235,   1,   1,   1,
   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 236,   1,   1,   1,   4,
   5,   3, 208,  48,  71,   0,   0, 237,   1,   1,   1,   5,   6,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 238,   1,   2,   1,   1,   4, 108, 208,  48, 101,
   0,  93,  20, 102,  20,  48,  93, 142,   3, 102, 142,   3,  88,  43,  29, 104,
 251,   2, 101,   0,  93,  20, 102,  20,  48,  93, 142,   3, 102, 142,   3,  88,
  44,  29, 104, 254,   2, 101,   0,  93,  20, 102,  20,  48,  93, 254,   2, 102,
 254,   2,  48, 100, 108,   2,  88,  46,  29,  29, 104, 140,   3, 101,   0,  93,
  20, 102,  20,  48,  93, 254,   2, 102, 254,   2,  48, 100, 108,   2,  88,  47,
  29,  29, 104, 141,   3, 101,   0,  93,  20, 102,  20,  48,  93, 142,   3, 102,
 142,   3,  88,  45,  29, 104, 135,   3,  71,   0,   0, 239,   1,   2,   1,   3,
   4,  59, 208,  48,  94, 168,   3,  36,   0, 104, 168,   3,  94, 169,   3,  36,
   1, 104, 169,   3,  94, 170,   3,  36,   2, 104, 170,   3,  94, 171,   3,  36,
   3, 104, 171,   3,  94, 172,   3,  36,   4, 104, 172,   3,  94, 173,   3,  36,
   1, 104, 173,   3,  94, 174,   3,  36,   2, 104, 174,   3,  71,   0,   0, 244,
   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 245,   1,
   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  20, 102,  20,  48,  93, 187,
   3, 102, 187,   3,  88,  48,  29, 104, 186,   3,  71,   0,   0, 246,   1,   2,
   1,   3,   4,  21, 208,  48,  94, 189,   3,  44, 227,   2, 104, 189,   3,  94,
 190,   3,  44, 229,   2, 104, 190,   3,  71,   0,   0, 247,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 248,   1,   2,   1,   1,   3,
  22, 208,  48, 101,   0,  93,  20, 102,  20,  48,  93, 194,   3, 102, 194,   3,
  88,  49,  29, 104, 193,   3,  71,   0,   0, 249,   1,   2,   1,   3,   4,  16,
 208,  48,  94, 196,   3,  93, 197,   3,  74, 197,   3,   0,  97, 196,   3,  71,
   0,   0, 250,   1,   1,   1,   3,   4,   9, 208,  48,  93, 198,   3, 102, 198,
   3,  72,   0,   0, 251,   1,   4,   9,   3,   4, 202,   1, 208,  48,  33, 130,
 213,  32, 128, 200,   3, 214,  32, 128, 199,   3, 215,  36,   0, 116,  99,   4,
  36,   0, 116,  99,   5,  36,   0, 116,  99,   6,  36,   0,  99,   7,  93, 201,
   3, 102, 201,   3, 130,  99,   8,  16, 143,   0,   0,   9,  98,   8,  98,   7,
  30, 130, 213,  93, 202,   3, 102, 202,   3, 102, 203,   3, 209, 102, 204,   3,
 118,  18,   4,   0,   0,  16, 113,   0,   0,  93, 201,   3, 102, 201,   3, 209,
 102, 204,   3, 128, 200,   3, 214, 209,  93, 205,   3, 102, 205,   3, 135, 128,
 199,   3, 215, 210,  32,  20,   4,   0,   0,  16,  77,   0,   0,  16,  49,   0,
   0,   9, 210,  70, 206,   3,   0,  93, 207,   3, 102, 207,   3, 135, 116,  99,
   4,  98,   4,  36,  16, 166, 116,  99,   5,  98,   4,  45,   8, 168, 116,  99,
   6, 211,  93, 208,   3,  98,   5,  98,   6,  74, 208,   3,   2,  70, 209,   3,
   1,  41, 210,  70, 210,   3,   0, 150, 118,  42, 118,  18,   7,   0,   0,  41,
 210,  70, 211,   3,   0, 118,  17, 183, 255, 255,  50,   8,   7,  17, 106, 255,
 255,   8,   8,   8,   7,  71,   0,   0, 253,   1,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 128,   2,   1,   1,   4,   5,   8, 208,  48,
 208,  70, 212,   3,   0,  72,   0,   0, 136,   2,   3,   6,   4,   5,  80, 208,
  48, 209,  93, 208,   3, 102, 208,   3, 102, 214,   3,  19,   1,   0,   0,  71,
 208, 102, 215,   3,  32,  20,  43,   0,   0, 208, 208,  70, 216,   3,   0, 104,
 215,   3,  93, 201,   3, 102, 201,   3, 208, 208, 102, 215,   3,  97, 204,   3,
 208,  93, 217,   3, 102, 217,   3,  93, 218,   3, 102, 218,   3,  83,   1,  66,
   0, 104, 219,   3, 208, 102, 219,   3, 210,  70, 220,   3,   1,  41,  71,   0,
   0, 137,   2,   3,   6,   5,  10,  96, 208,  48,  87,  42, 214,  48, 101,   1,
  32, 128,  29, 109,   2, 101,   1, 209, 109,   1, 101,   1, 108,   1, 208,  97,
 221,   3,  36,   0, 215, 208, 102, 219,   3, 130,  99,   4,  16,  44,   0,   0,
   9, 101,   1,  98,   4, 211,  35, 128,  29, 109,   2, 101,   1, 108,   2, 100,
 101,   1, 108,   1,  65,   1,  41,  16,  17,   0,   0, 208,  48, 210,  48,  90,
   0,  42,  99,   5,  42,  48,  43, 109,   1,  29,   8,   5,  50,   4,   3,  17,
 205, 255, 255,   8,   4,   8,   3,  71,   1,  51,  63,  67,   0, 222,   3,   2,
 223,   3,   0,   1, 224,   3,   0, 225,   3,   0,   2,  29,   0, 139,   2,   2,
   1,   3,   4,  12, 208,  48,  94, 250,   3,  44, 145,   3, 104, 250,   3,  71,
   0,   0, 140,   2,   2,   3,   4,   5,  16, 208,  48, 208,  73,   0, 208, 209,
 104, 251,   3, 208, 210, 104, 252,   3,  71,   0,   0, 141,   2,   1,   1,   4,
   5,   7, 208,  48, 208, 102, 252,   3,  72,   0,   0, 142,   2,   1,   1,   4,
   5,   7, 208,  48, 208, 102, 251,   3,  72,   0,   0, 143,   2,   1,   1,   4,
   5,   7, 208,  48, 208, 102, 253,   3,  72,   0,   0, 144,   2,   2,   1,   1,
   3,  43, 208,  48,  93, 133,   4,  93,  20, 102,  20,  48,  93, 134,   4, 102,
 134,   4,  88,  50,  29, 104, 199,   3,  93, 135,   4,  93,  20, 102,  20,  48,
  93, 134,   4, 102, 134,   4,  88,  51,  29, 104, 224,   3,  71,   0,   0, 145,
   2,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 146,   2,   1,   1,   3,
   4,   9, 208,  48,  93, 138,   4, 102, 138,   4,  72,   0,   0, 147,   2,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 148,   2,   2,   2,
   4,   5,   9, 208,  48, 208, 209,  70, 140,   4,   1,  72,   0,   0, 149,   2,
   2,   1,   4,   5,   9, 208,  48, 208,  32,  70, 140,   4,   1,  72,   0,   0,
 151,   2,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  20, 102,  20,  48,
  93, 145,   4, 102, 145,   4,  88,  52,  29, 104, 139,   4,  71,   0,   0, 152,
   2,   2,   1,   3,   4,  39, 208,  48,  94, 147,   4,  44, 163,   3, 104, 147,
   4,  94, 148,   4,  44, 165,   3, 104, 148,   4,  94, 149,   4,  44, 167,   3,
 104, 149,   4,  94, 150,   4,  44, 169,   3, 104, 150,   4,  71,   0,   0, 153,
   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 154,   2,
   3,   1,   3,   4, 124, 208,  48,  94, 156,   4,  36,   0, 104, 156,   4,  94,
 157,   4,  36,   1, 104, 157,   4,  94, 158,   4,  36,   3, 104, 158,   4,  94,
 159,   4,  36,   4, 104, 159,   4,  94, 160,   4,  36,   5, 104, 160,   4,  94,
 161,   4,  36,   6, 104, 161,   4,  94, 162,   4,  36,   0, 104, 162,   4,  94,
 163,   4,  36,   1, 104, 163,   4,  94, 164,   4,  93, 165,   4,  74, 165,   4,
   0,  97, 164,   4,  94, 166,   4,  93, 167,   4, 102, 167,   4,  93, 168,   4,
 102, 168,   4,  83,   1,  66,   0,  97, 166,   4,  94, 169,   4,  93, 167,   4,
 102, 167,   4,  93, 168,   4, 102, 168,   4,  83,   1,  66,   0,  97, 169,   4,
  71,   0,   0, 164,   2,   2,   3,   3,   4,  13, 208,  48,  93, 170,   4, 209,
  70, 170,   4,   1, 210, 171,  72,   0,   0, 169,   2,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 170,   2,   2,   1,   3,   4,  78, 208,
  48,  94, 147,   4,  36,   0, 104, 147,   4,  94, 148,   4,  36,   7, 104, 148,
   4,  94, 149,   4,  36,   6, 104, 149,   4,  94, 150,   4,  36,   8, 104, 150,
   4,  94, 197,   4,  93, 198,   4, 102, 198,   4, 102, 199,   4, 104, 197,   4,
  94, 200,   4,  93, 198,   4, 102, 198,   4, 102, 201,   4, 104, 200,   4,  94,
 202,   4,  93, 203,   4,  74, 203,   4,   0,  97, 202,   4,  71,   0,   0, 171,
   2,   3,   2,   3,   4,  26, 208,  48, 209,  93, 204,   4, 102, 204,   4, 179,
  18,   2,   0,   0, 209,  72,  93, 205,   4, 209,  39,  70, 205,   4,   2,  72,
   0,   0, 172,   2,   3,   2,   3,   4,  59, 208,  48,  93, 205,   4,  32,  38,
  70, 205,   4,   2, 128, 213,   3, 213,  93, 206,   4, 209,  93, 198,   4, 102,
 198,   4, 102, 207,   4,  70, 206,   4,   2,  41,  93, 198,   4, 102, 198,   4,
 102, 208,   4,  93, 198,   4, 102, 198,   4, 209,  70, 209,   4,   1, 209,  97,
 210,   4, 209,  72,   0,   0, 173,   2,   3,   3,   3,   4,  34, 208,  48,  93,
 211,   4, 102, 211,   4, 102, 212,   4,  93, 198,   4, 102, 198,   4, 209,  70,
 209,   4,   1, 102, 210,   4, 128, 213,   4, 214, 210, 102, 214,   4,  72,   0,
   0, 181,   2,   6,   4,   5,  10, 222,   8, 208,  48,  87,  42, 214,  48, 101,
   1,  36,   0, 109,   3, 101,   1,  32, 128, 200,   3, 109,   4, 101,   1,  32,
 128, 200,   3, 109,   5, 101,   1,  32, 128, 213,   3, 109,   6, 101,   1,  36,
   0, 109,   7, 101,   1,  32, 128, 213,   3, 109,   8, 101,   1,  32, 128, 213,
   4, 109,   9, 101,   1, 209, 109,   1, 101,   1, 101,   1, 108,   1, 128,  27,
 109,   2, 101,   1, 108,   1, 102, 215,   4,  44, 153,   2,  20,   4,   0,   0,
  44, 205,   3,  72, 208, 102, 216,   4,  18,   4,   0,   0,  44, 207,   3,   3,
 208,  70, 217,   4,   0,  18, 191,   0,   0, 101,   1,  36,   0, 115, 109,   3,
  16, 139,   0,   0,   9, 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4,
  93, 204,   4, 102, 204,   4, 179, 118,  42, 118,  18,  32,   0,   0,  41,  93,
 198,   4, 102, 198,   4, 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4,
  93, 198,   4, 102, 198,   4, 102, 207,   4,  70, 218,   4,   2, 118,  18,  66,
   0,   0, 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4, 102, 219,   4,
 102, 220,   4, 118,  18,  16,   0,   0, 101,   1, 108,   2, 101,   1, 108,   3,
  32,  97, 210,   4,  16,  28,   0,   0, 101,   1, 108,   2, 101,   1, 108,   3,
 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4, 102, 219,   4, 102, 221,
   4,  97, 210,   4, 101,   1, 108,   3, 192, 115, 101,   1,  43, 109,   3, 101,
   1, 108,   3, 101,   1, 108,   2, 102, 222,   4,  21, 102, 255, 255,  93, 223,
   4,  93, 211,   4, 102, 211,   4, 208, 102, 221,   4, 101,   1, 108,   1,  70,
 224,   4,   2,  70, 223,   4,   1,  72, 101,   1,  93, 225,   4, 208, 102, 226,
   4, 102, 227,   4, 208, 102, 226,   4, 102, 228,   4,  74, 225,   4,   2, 128,
 200,   3, 109,   4, 101,   1,  93, 225,   4, 208, 102, 229,   4, 102, 227,   4,
 208, 102, 229,   4, 102, 228,   4,  74, 225,   4,   2, 128, 200,   3, 109,   5,
 101,   1,  93, 230,   4, 101,   1, 108,   4, 101,   1, 108,   5,  70, 230,   4,
   2, 128, 213,   3, 109,   6, 208, 102, 226,   4,  93, 198,   4, 102, 198,   4,
 102, 231,   4,  70, 232,   4,   1,  41, 208, 102, 226,   4, 101,   1, 108,   5,
  70, 232,   4,   1,  41, 208, 102, 226,   4, 101,   1, 108,   4,  70, 232,   4,
   1,  41, 208, 102, 226,   4,  93, 198,   4, 102, 198,   4, 101,   1, 108,   6,
  70, 209,   4,   1,  70, 232,   4,   1,  41, 101,   1,  36,   0, 115, 109,   3,
  16,  50,   2,   0,   9, 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4,
  93, 204,   4, 102, 204,   4, 179,  18,  16,   2,   0,  93, 198,   4, 102, 198,
   4, 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4, 208, 102, 226,   4,
 102, 228,   4,  70, 218,   4,   2,  18,  30,   0,   0, 101,   1, 108,   2, 101,
   1, 108,   3, 102, 210,   4, 102, 219,   4, 102, 220,   4, 118,  18,   4,   0,
   0,  44, 221,   3,   3,  16, 210,   1,   0, 101,   1, 108,   2, 101,   1, 108,
   3, 102, 210,   4, 102, 219,   4, 102, 216,   4, 150,  18, 188,   1,   0, 101,
   1,  93, 198,   4, 102, 198,   4, 101,   1, 108,   2, 101,   1, 108,   3, 102,
 210,   4,  70, 233,   4,   1, 115, 109,   7, 101,   1,  93, 225,   4, 208, 102,
 226,   4, 102, 228,   4, 101,   1, 108,   7,  74, 225,   4,   2, 128, 200,   3,
 109,   4, 101,   1,  93, 225,   4, 101,   1, 108,   7, 208, 102, 229,   4, 102,
 227,   4,  74, 225,   4,   2, 128, 200,   3, 109,   5, 101,   1,  93, 230,   4,
 101,   1, 108,   4, 101,   1, 108,   5,  70, 230,   4,   2, 128, 213,   3, 109,
   8, 101,   1, 108,   8, 102, 219,   4, 101,   1, 108,   2, 101,   1, 108,   3,
 102, 210,   4, 102, 219,   4, 102, 220,   4,  97, 220,   4, 101,   1, 108,   8,
 102, 234,   4, 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4, 102, 219,
   4, 102, 216,   4,  97, 216,   4,  93, 198,   4, 102, 198,   4, 101,   1, 108,
   2, 101,   1, 108,   3, 102, 210,   4,  93, 198,   4, 102, 198,   4, 102, 207,
   4,  70, 218,   4,   2,  18, 150,   0,   0, 101,   1,  93, 211,   4, 102, 211,
   4, 101,   1, 108,   8, 102, 219,   4, 102, 229,   4, 101,   1, 108,   8, 102,
 219,   4, 102, 226,   4,  93, 198,   4, 102, 198,   4, 101,   1, 108,   8,  70,
 209,   4,   1,  70, 230,   4,   3, 128, 213,   4, 109,   9, 101,   1, 108,   9,
 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4, 102, 219,   4, 102, 221,
   4,  97, 214,   4, 101,   1, 108,   9, 101,   1, 108,   2, 101,   1, 108,   3,
 102, 210,   4, 102, 219,   4, 102, 235,   4,  97, 236,   4, 101,   1, 108,   9,
 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,   4, 102, 219,   4, 102, 220,
   4,  97, 220,   4,  93, 211,   4, 102, 211,   4, 102, 212,   4, 101,   1, 108,
   9, 102, 237,   4, 101,   1, 108,   9,  97, 210,   4,  16,  93,   0,   0, 101,
   1, 108,   2, 101,   1, 108,   3, 102, 210,   4,  93, 198,   4, 102, 198,   4,
 101,   1, 108,   8,  70, 209,   4,   1,  70, 238,   4,   1,  41,  93, 239,   4,
  93, 198,   4, 102, 198,   4, 101,   1, 108,   2, 101,   1, 108,   3, 102, 210,
   4,  70, 209,   4,   1,  93, 198,   4, 102, 198,   4, 101,   1, 108,   8,  70,
 209,   4,   1, 101,   1, 108,   8, 102, 219,   4, 102, 226,   4, 101,   1, 108,
   8, 102, 219,   4, 102, 229,   4,  70, 239,   4,   4,  41, 101,   1, 108,   2,
 101,   1, 108,   3, 101,   1, 108,   8,  97, 210,   4, 101,   1, 108,   3, 192,
 115, 101,   1,  43, 109,   3, 101,   1, 108,   3, 101,   1, 108,   2, 102, 222,
   4,  21, 191, 253, 255, 208, 102, 226,   4, 101,   1, 108,   1,  70, 232,   4,
   1,  41,  93, 198,   4, 102, 198,   4, 101,   1, 108,   6,  70, 240,   4,   1,
  41, 101,   1, 108,   6,  72,  16,  43,   0,   0, 208,  48, 210,  48,  90,   0,
  42, 215,  42,  48,  43, 109,   1,  94, 221,   4, 101,   2, 108,   1, 104, 221,
   4,  94, 235,   4,  93, 241,   4, 102, 241,   4, 104, 235,   4, 101,   2, 108,
   1,   3,  29,   8,   3,  32,  72,   1, 175,   2, 173,   8, 177,   8,   0, 238,
   2,   9, 242,   4,   0,   1, 243,   4,   0, 244,   4,   0,   2,  27,   0, 245,
   4,   0,   3,  26,   0, 246,   4,   0,   4, 200,   3,   0, 247,   4,   0,   5,
 200,   3,   0, 248,   4,   0,   6, 213,   3,   0, 249,   4,   0,   7,  26,   0,
 250,   4,   0,   8, 213,   3,   0, 251,   4,   0,   9, 213,   4,   0, 182,   2,
   4,   4,   5,  10, 173,   2, 208,  48,  87,  42, 214,  48, 101,   1,  32, 128,
 213,   3, 109,   2, 101,   1,  33, 130, 109,   3, 101,   1,  33, 130, 109,   4,
 101,   1, 209, 109,   1, 208, 102, 216,   4,  18,   4,   0,   0,  44, 207,   3,
   3, 208,  70, 217,   4,   0,  18,  26,   0,   0,  93, 223,   4,  93, 211,   4,
 102, 211,   4, 208, 102, 221,   4, 101,   1, 108,   1,  70, 252,   4,   2,  70,
 223,   4,   1,  72, 101,   1,  93, 225,   4, 208, 102, 226,   4, 102, 227,   4,
 208, 102, 226,   4, 102, 228,   4,  74, 225,   4,   2, 130, 109,   3, 101,   1,
  93, 225,   4, 208, 102, 229,   4, 102, 227,   4, 208, 102, 229,   4, 102, 228,
   4,  74, 225,   4,   2, 130, 109,   4, 101,   1,  93, 230,   4, 101,   1, 108,
   3, 101,   1, 108,   4,  70, 230,   4,   2, 128, 213,   3, 109,   2, 208, 102,
 226,   4,  93, 198,   4, 102, 198,   4, 102, 253,   4,  70, 232,   4,   1,  41,
 208, 102, 226,   4, 101,   1, 108,   4,  70, 232,   4,   1,  41, 208, 102, 226,
   4, 101,   1, 108,   3,  70, 232,   4,   1,  41, 208, 102, 226,   4,  93, 198,
   4, 102, 198,   4, 101,   1, 108,   2,  70, 209,   4,   1,  70, 232,   4,   1,
  41, 208, 102, 226,   4, 101,   1, 108,   1,  70, 232,   4,   1,  41,  93, 198,
   4, 102, 198,   4, 101,   1, 108,   2,  70, 240,   4,   1,  41, 101,   1, 108,
   2,  72,  16,  43,   0,   0, 208,  48, 210,  48,  90,   0,  42, 215,  42,  48,
  43, 109,   1,  94, 221,   4, 101,   2, 108,   1, 104, 221,   4,  94, 235,   4,
  93, 241,   4, 102, 241,   4, 104, 235,   4, 101,   2, 108,   1,   3,  29,   8,
   3,  32,  72,   1,  78, 252,   1, 128,   2,   0, 238,   2,   4, 242,   4,   0,
   1, 243,   4,   0, 248,   4,   0,   2, 213,   3,   0, 246,   4,   0,   3,   0,
   0, 247,   4,   0,   4,   0,   0, 183,   2,   1,   1,   4,   5,   7, 208,  48,
 208, 102, 219,   4,  72,   0,   0, 184,   2,   3,   2,   4,   5, 102, 208,  48,
 208, 102, 219,   4, 102, 221,   4, 118,  18,   4,   0,   0,  44, 238,   3,   3,
 208, 102, 219,   4,  93, 254,   4, 102, 254,   4,  97, 235,   4, 208, 102, 219,
   4, 209,  97, 221,   4,  93, 198,   4, 102, 198,   4, 102, 208,   4,  93, 198,
   4, 102, 198,   4, 208,  70, 209,   4,   1,  32,  97, 210,   4,  93, 255,   4,
 208,  70, 255,   4,   1,  41,  93, 198,   4, 102, 198,   4, 208,  93, 198,   4,
 102, 198,   4, 102, 207,   4,  70, 128,   5,   2,  41, 208, 102, 219,   4,  39,
  97, 216,   4,  71,   0,   0, 185,   2,   2,   3,   5,   5,  30,  93, 219,   4,
 102, 219,   4, 209,  97, 221,   4,  93, 219,   4, 102, 219,   4, 210,  97, 235,
   4,  93, 129,   5, 209,  76, 129,   5,   1,  41,  71,   0,   0, 186,   2,   2,
   3,   5,   5,  30,  93, 219,   4, 102, 219,   4, 209,  97, 221,   4,  93, 219,
   4, 102, 219,   4, 210,  97, 235,   4,  93, 130,   5, 209,  76, 130,   5,   1,
  41,  71,   0,   0, 187,   2,   6,   5,   5,  10, 206,   4, 208,  48,  87,  42,
 215,  48, 101,   1,  36,   0, 116, 109,   3, 101,   1,  32, 128, 191,   4, 109,
   4, 101,   1,  32, 128, 213,   3, 109,   5, 101,   1,  33, 130, 109,   7, 101,
   1,  33, 130, 109,   8, 101,   1,  33, 130, 109,   9, 101,   1,  32, 128, 213,
   3, 109,  10, 101,   1,  32, 128, 213,   4, 109,  11, 101,   1, 209, 109,   1,
 101,   1, 210, 109,   2,  93, 198,   4, 102, 198,   4, 208,  93, 198,   4, 102,
 198,   4, 102, 207,   4,  70, 218,   4,   2,  18,  31,   0,   0,  93, 198,   4,
 102, 198,   4, 102, 131,   5,  44, 242,   3, 101,   1, 108,   1,  44, 243,   3,
 208,  85,   2,  70, 132,   5,   1,  41,  16, 205,   1,   0, 208, 102, 219,   4,
 102, 216,   4,  18, 111,   0,   0, 101,   1,  93, 198,   4, 102, 198,   4, 208,
  70, 209,   4,   1, 116, 109,   3, 101,   1,  93, 133,   5, 102, 133,   5, 101,
   1, 108,   3, 102, 210,   4, 128, 191,   4, 109,   4, 101,   1, 108,   4, 150,
  18,  40,   0,   0, 101,   1,  93, 134,   5, 102, 134,   5,  93, 135,   5, 102,
 135,   5,  83,   1,  66,   0, 128, 191,   4, 109,   4,  93, 133,   5, 102, 133,
   5, 101,   1, 108,   3, 101,   1, 108,   4,  97, 210,   4, 101,   1, 108,   4,
  44, 242,   3, 101,   1, 108,   1,  44, 243,   3, 208,  85,   2,  70, 132,   5,
   1,  41,  16,  83,   1,   0, 101,   1,  64, 185,   2, 130, 109,   6, 101,   1,
 208, 128, 213,   3, 109,   5, 101,   1,  32, 130, 109,   7, 101,   1, 108,   2,
  32,  19,   8,   0,   0, 101,   1,  64, 186,   2, 130, 109,   7, 101,   1,  93,
 225,   4, 208, 102, 219,   4, 102, 226,   4, 102, 228,   4, 208, 102, 219,   4,
 102, 226,   4, 102, 227,   4,  74, 225,   4,   2, 130, 109,   8, 101,   1,  93,
 225,   4, 208, 102, 219,   4, 102, 229,   4, 102, 228,   4, 208, 102, 219,   4,
 102, 229,   4, 102, 227,   4,  74, 225,   4,   2, 130, 109,   9, 101,   1,  93,
 230,   4, 101,   1, 108,   8, 101,   1, 108,   9,  70, 230,   4,   2, 128, 213,
   3, 109,  10, 101,   1,  93, 211,   4, 102, 211,   4, 101,   1, 108,   9, 101,
   1, 108,   8,  93, 198,   4, 102, 198,   4, 101,   1, 108,  10,  70, 209,   4,
   1,  70, 230,   4,   3, 128, 213,   4, 109,  11, 208, 102, 219,   4, 102, 226,
   4,  93, 198,   4, 102, 198,   4, 102, 136,   5,  70, 232,   4,   1,  41, 208,
 102, 219,   4, 102, 226,   4, 101,   1, 108,  10,  70, 232,   4,   1,  41, 101,
   1, 108,  11,  93, 254,   4, 102, 254,   4,  97, 236,   4, 101,   1, 108,  11,
  44, 244,   3, 101,   1, 108,   6,  44, 245,   3, 101,   1, 108,   7,  85,   2,
  97, 214,   4,  93, 211,   4, 102, 211,   4, 102, 212,   4,  93, 198,   4, 102,
 198,   4, 101,   1, 108,  10,  70, 209,   4,   1, 101,   1, 108,  11,  97, 210,
   4,  16,  68,   0,   0, 208,  48, 211,  48,  90,   0,  42,  99,   4,  42,  48,
  43, 109,   1,  93, 219,   4, 102, 219,   4,  93, 241,   4, 102, 241,   4,  97,
 235,   4, 101,   1, 108,   2,  32,  19,  27,   0,   0,  93, 198,   4, 102, 198,
   4, 102, 131,   5,  44, 242,   3, 101,   1, 108,   2,  44, 243,   3, 208,  85,
   2,  70, 132,   5,   1,  41,  29,   8,   4,  71,   1, 161,   2, 133,   4, 137,
   4,   0, 238,   2,  11, 137,   5,   0,   1,  29,   0, 138,   5,   0,   2,  29,
  12,  12, 139,   5,   0,   3,   8,   0, 140,   5,   0,   4, 191,   4,   0, 141,
   5,   0,   5, 213,   3,   0, 142,   5,   0,   6,   0,   0, 143,   5,   0,   7,
   0,   0, 246,   4,   0,   8,   0,   0, 247,   4,   0,   9,   0,   0, 144,   5,
   0,  10, 213,   3,   0, 145,   5,   0,  11, 213,   4,   0, 188,   2,   3,   3,
   5,  10, 174,   3, 208,  48,  87,  42, 213,  48, 101,   1,  36,   0, 116, 109,
   1, 208, 102, 219,   4, 102, 220,   4,  18,   2,   0,   0,  32,  72,  16,  78,
   0,   0,   9, 208, 102, 219,   4, 102, 235,   4,  93, 254,   4, 102, 254,   4,
  20,   8,   0,   0, 208, 102, 219,   4, 102, 221,   4,  72,  93, 211,   4, 102,
 211,   4,  39,  70, 146,   5,   1, 150,  18,  36,   0,   0, 208, 102, 219,   4,
 102, 216,   4, 150,  18,   4,   0,   0,  16,  31,   0,   0,  93, 198,   4, 102,
 198,   4,  38,  70, 147,   5,   1, 150,  18,   4,   0,   0,  44, 254,   3,   3,
 208, 102, 219,   4, 102, 216,   4,  17, 167, 255, 255, 208, 102, 219,   4, 102,
 221,   4,  32,  20, 242,   0,   0, 208, 102, 219,   4, 102, 226,   4,  93, 198,
   4, 102, 198,   4, 102, 148,   5,  70, 232,   4,   1,  41,  16,  37,   0,   0,
   9,  93, 211,   4, 102, 211,   4,  39,  70, 146,   5,   1, 150,  18,  20,   0,
   0,  93, 198,   4, 102, 198,   4,  38,  70, 147,   5,   1, 150,  18,   4,   0,
   0,  44, 255,   3,   3, 208, 102, 219,   4, 102, 229,   4,  70, 149,   5,   0,
 150,  17, 203, 255, 255, 101,   1, 208, 102, 219,   4, 102, 229,   4,  70, 150,
   5,   0, 116, 109,   1, 101,   1, 108,   1,  93, 198,   4, 102, 198,   4, 102,
 151,   5,  20,  43,   0,   0, 208, 102, 219,   4, 208, 102, 219,   4, 102, 229,
   4,  70, 150,   5,   0,  97, 221,   4, 208, 102, 219,   4,  93, 152,   5, 102,
 152,   5,  97, 235,   4, 208, 102, 219,   4, 102, 221,   4,   3,  16,  31,   0,
   0, 208, 102, 219,   4, 208, 102, 219,   4, 102, 229,   4,  70, 150,   5,   0,
  97, 221,   4, 208, 102, 219,   4,  93, 254,   4, 102, 254,   4,  97, 235,   4,
  16,  49,   0,   0, 208,  48, 209,  48,  90,   0,  42, 214,  42,  48,  43, 109,
   1,  93, 219,   4, 102, 219,   4, 101,   2, 108,   1,  97, 221,   4,  93, 219,
   4, 102, 219,   4,  93, 241,   4, 102, 241,   4,  97, 235,   4, 101,   2, 108,
   1,   3,  29,   8,   2,  16,  49,   0,   0, 208, 102, 219,   4, 102, 235,   4,
  93, 152,   5, 102, 152,   5, 171, 118,  42, 118,  17,  16,   0,   0,  41, 208,
 102, 219,   4, 102, 235,   4,  93, 241,   4, 102, 241,   4, 171, 118,  18,   8,
   0,   0, 208, 102, 219,   4, 102, 221,   4,   3, 208, 102, 219,   4, 102, 221,
   4,  72,   1, 131,   1, 188,   2, 192,   2,   0, 238,   2,   1, 153,   5,   0,
   1,   8,   0, 190,   2,   2,   2,   4,   5, 123, 208,  48, 208, 102, 219,   4,
 102, 235,   4, 213,  93, 204,   4, 102, 204,   4, 102, 154,   5, 209,  25,  48,
   0,   0,  93, 204,   4, 102, 204,   4, 102, 254,   4, 209,  25,  44,   0,   0,
  93, 204,   4, 102, 204,   4, 102, 241,   4, 209,  25,  40,   0,   0,  93, 204,
   4, 102, 204,   4, 102, 152,   5, 209,  25,  36,   0,   0,  16,  42,   0,   0,
   8,   1,  93, 155,   5, 102, 155,   5, 102, 154,   5,  72,  93, 155,   5, 102,
 155,   5, 102, 254,   4,  72,  93, 155,   5, 102, 155,   5, 102, 241,   4,  72,
  93, 155,   5, 102, 155,   5, 102, 152,   5,  72,  93, 156,   5,  44, 130,   4,
  74, 156,   5,   1,   3,   0,   0, 191,   2,   2,   1,   4,   5,  14, 208,  48,
  93, 198,   4, 102, 198,   4, 208,  70, 209,   4,   1,  72,   0,   0, 192,   2,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 193,   2,   2,
   1,   3,   4,  63, 208,  48,  94, 147,   4,  93, 185,   5, 102, 185,   5, 102,
 186,   5, 104, 147,   4,  94, 148,   4,  93, 185,   5, 102, 185,   5, 102, 187,
   5, 104, 148,   4,  94, 149,   4,  93, 185,   5, 102, 185,   5, 102, 188,   5,
 104, 149,   4,  94, 150,   4,  93, 185,   5, 102, 185,   5, 102, 189,   5, 104,
 150,   4,  71,   0,   0, 198,   2,   3,   4,   4,   9, 164,   6, 208,  48,  87,
  42, 214,  48, 101,   1,  39, 109,   2, 101,   1,  33, 130, 109,   5, 101,   1,
  33, 130, 109,   6, 101,   1,  32, 128,  20, 109,   7, 101,   1,  32, 128, 213,
   4, 109,   8, 101,   1,  39, 109,   9, 101,   1,  36,   0, 116, 109,  10, 101,
   1,  32, 128,  27, 109,  11, 101,   1, 209, 109,   1,  93, 190,   5, 102, 190,
   5, 102, 191,   5, 118,  18,  11,   0,   0,  93, 190,   5, 102, 190,   5,  70,
 191,   5,   0,  41,  93, 192,   5, 102, 192,   5,  32,  20,   2,   0,   0,  39,
  72, 101,   1,  36,   0, 116, 109,   3, 101,   1,  37, 128,   8, 116, 109,   4,
  16, 156,   2,   0,   9,  93, 193,   5, 102, 193,   5,  39,  70, 194,   5,   1,
  41, 101,   1,  39, 118, 109,   2, 101,   1,  36,   0, 130, 109,   5,  16,  70,
   0,   0,   9, 101,   1,  93, 193,   5, 102, 193,   5, 102, 195,   5,  70, 196,
   5,   0, 128,  20, 109,   7, 101,   1, 108,   7, 101,   1, 108,   7, 102, 197,
   5, 102, 198,   5, 102, 221,   4,  70, 199,   5,   1,  41, 101,   1, 108,   3,
 145, 116, 101,   1,  43, 109,   3, 101,   1,  38, 118, 109,   2, 101,   1, 108,
   5, 145, 130, 101,   1,  43, 109,   5, 101,   1, 108,   5,  93, 193,   5, 102,
 193,   5, 102, 195,   5, 102, 200,   5,  21, 166, 255, 255, 101,   1,  36,   0,
 130, 109,   5,  16,  79,   0,   0,   9, 101,   1,  93, 193,   5, 102, 193,   5,
 102, 201,   5,  70, 196,   5,   0, 128,  20, 109,   7, 101,   1, 108,   7, 102,
 197,   5,  70, 202,   5,   0,  41, 101,   1, 108,   7, 102, 197,   5, 101,   1,
 108,   7, 102, 199,   5,  70, 203,   5,   1,  41, 101,   1, 108,   3, 145, 116,
 101,   1,  43, 109,   3, 101,   1,  38, 118, 109,   2, 101,   1, 108,   5, 145,
 130, 101,   1,  43, 109,   5, 101,   1, 108,   5,  93, 193,   5, 102, 193,   5,
 102, 201,   5, 102, 200,   5,  21, 157, 255, 255, 101,   1,  93, 192,   5, 102,
 192,   5, 102, 200,   5, 130, 109,   6, 101,   1,  36,   0, 130, 109,   5,  16,
 118,   1,   0,   9, 101,   1,  93, 192,   5, 102, 192,   5, 101,   1, 108,   5,
 102, 204,   5, 128, 213,   4, 109,   8, 101,   1, 108,   8, 150,  18,   4,   0,
   0,  16,  73,   1,   0, 101,   1,  38, 118, 109,   9, 101,   1, 101,   1, 108,
   8, 102, 205,   5,  70, 206,   5,   0, 118, 109,   9,  16,  61,   0,   0, 208,
  48, 210,  48,  90,   0,  42, 215,  42,  48,  43, 109,   1, 101,   1, 108,   8,
 101,   2, 108,   1,  97, 207,   5, 101,   1, 108,   8,  93, 188,   5, 102, 188,
   5,  97, 208,   5,  93, 192,   5, 102, 192,   5, 101,   1, 108,   5,  32,  97,
 204,   5,  29,   8,   3,  16, 245,   0,   0,  29,   8,   3, 101,   1, 101,   1,
 108,   2, 118,  42, 118,  17,   6,   0,   0,  41, 101,   1, 108,   9, 118, 118,
 109,   2, 101,   1, 108,   9,  18, 212,   0,   0, 101,   1, 108,   3, 145, 116,
 101,   1,  43, 109,   3, 101,   1, 101,   1, 108,   8, 102, 205,   5,  70, 202,
   5,   0, 116, 109,  10, 101,   1, 108,  10,  93, 193,   5, 102, 193,   5, 102,
 209,   5,  20,  13,   0,   0, 101,   1, 108,   8,  70, 210,   5,   0,  41,  16,
 155,   0,   0, 101,   1, 108,  10,  93, 193,   5, 102, 193,   5, 102, 211,   5,
  20,  13,   0,   0, 101,   1, 108,   8,  70, 212,   5,   0,  41,  16, 125,   0,
   0, 101,   1, 108,  10,  93, 193,   5, 102, 193,   5, 102, 213,   5,  20,  13,
   0,   0, 101,   1, 108,   8,  70, 214,   5,   0,  41,  16,  95,   0,   0, 101,
   1, 108,  10,  93, 193,   5, 102, 193,   5, 102, 215,   5,  20,  13,   0,   0,
 101,   1, 108,   8,  70, 216,   5,   0,  41,  16,  65,   0,   0, 101,   1, 108,
  10,  93, 193,   5, 102, 193,   5, 102, 217,   5,  20,  18,   0,   0,  93, 192,
   5, 102, 192,   5, 101,   1, 108,   5,  32,  97, 204,   5,  16,  30,   0,   0,
 101,   1, 101,   1, 108,   8, 102, 205,   5,  70, 202,   5,   0, 128,  27, 109,
  11, 101,   1, 108,   8, 101,   1, 108,  11,  70, 218,   5,   1,  41, 101,   1,
 108,   5, 145, 130, 101,   1,  43, 109,   5, 101,   1, 108,   5, 101,   1, 108,
   6,  21, 126, 254, 255, 101,   1, 108,   2, 150, 118,  42, 118,  17,   7,   0,
   0,  41, 101,   1, 108,   1, 150, 118,  18,   4,   0,   0,  16,  12,   0,   0,
 101,   1, 108,   3, 101,   1, 108,   4,  21,  88, 253, 255, 101,   1, 108,   2,
  72,   1, 158,   3, 174,   3, 178,   3,   0, 238,   2,  11, 219,   5,   0,   1,
   2,   0, 248,   4,   0,   2,   2,   0, 220,   5,   0,   3,   8,   0, 221,   5,
   6,   4,   8,  13,   3, 245,   4,   0,   5,   0,   0, 222,   5,   0,   6,   0,
   0, 223,   5,   0,   7,  20,   0, 251,   4,   0,   8, 213,   4,   0, 224,   5,
   0,   9,   2,   0, 225,   5,   0,  10,   8,   0, 226,   5,   0,  11,  27,   0,
 199,   2,   2,   1,   3,   4,  11, 208,  48,  93, 227,   5,  38,  70, 227,   5,
   1,  72,   0,   0, 201,   2,   3,   3,   5,  10, 119, 208,  48,  87,  42, 213,
  48, 208, 102, 208,   5,  93, 187,   5, 102, 187,   5,  20,  22,   0,   0, 208,
 102, 228,   5,  93, 193,   5, 102, 193,   5, 102, 229,   5,  70, 230,   5,   1,
  41,  16,  18,   0,   0, 208, 102, 228,   5,  93, 193,   5, 102, 193,   5, 102,
 231,   5,  70, 230,   5,   1,  41, 208, 102, 228,   5, 208, 102, 207,   5,  70,
 230,   5,   1,  41,  16,  41,   0,   0, 208,  48, 209,  48,  90,   0,  42, 214,
  42,  48,  43, 109,   1,  94, 208,   5,  93, 188,   5, 102, 188,   5, 104, 208,
   5,  93, 228,   5, 102, 228,   5,  32,  39,  70, 232,   5,   2,  41,  29,   8,
   2,  71,   1,  60,  73,  77,   0, 238,   2,   0, 202,   2,   4,   4,   4,   5,
 222,   1, 208,  48,  32, 128, 200,   3, 214,  32, 128, 200,   3, 215, 208, 102,
 205,   5,  70, 202,   5,   0, 128, 213,   3, 213, 208, 102, 205,   5, 102, 233,
   5,  93, 193,   5, 102, 193,   5, 102, 234,   5, 171, 150, 118,  42, 118,  18,
  20,   0,   0,  41, 208, 102, 228,   5, 102, 235,   5,  93, 193,   5, 102, 193,
   5, 102, 234,   5, 171, 150, 118,  18,  72,   0,   0, 209, 102, 198,   5, 102,
 228,   5, 128, 200,   3, 214, 209, 102, 198,   5, 102, 205,   5, 128, 200,   3,
 215,  93, 193,   5, 102, 193,   5, 211,  93, 193,   5, 102, 193,   5, 102, 234,
   5, 211, 102, 233,   5,  70, 236,   5,   3,  41,  93, 193,   5, 102, 193,   5,
 210,  93, 193,   5, 102, 193,   5, 102, 234,   5, 210, 102, 235,   5,  70, 237,
   5,   3,  41,  93, 193,   5, 102, 193,   5, 209,  70, 238,   5,   1,  41, 208,
 102, 208,   5,  93, 187,   5, 102, 187,   5,  20,  21,   0,   0, 209, 102, 198,
   5, 208, 102, 207,   5, 208, 102, 208,   5,  70, 239,   5,   2,  41,  16,  29,
   0,   0, 209, 102, 198,   5, 102, 240,   5,  32,  19,  17,   0,   0, 209, 102,
 198,   5, 208, 102, 207,   5, 208, 102, 208,   5,  70, 240,   5,   2,  41,  71,
   0,   0, 203,   2,   5,   7,   4,   5, 219,   1, 208,  48,  33, 130,  99,   5,
  36,   0,  99,   6,  93, 193,   5, 102, 193,   5, 209,  70, 241,   5,   1,  18,
   4,   0,   0,  44, 155,   4,   3,  93, 193,   5, 102, 193,   5, 209, 210, 102,
 233,   5,  70, 242,   5,   2,  18,   4,   0,   0,  44, 156,   4,   3,  93, 193,
   5, 102, 193,   5, 209,  93, 193,   5, 102, 193,   5, 102, 234,   5,  70, 242,
   5,   2,  18,  58,   0,   0,  93, 243,   5, 211, 210,  98,   4,  70, 243,   5,
   3, 130,  99,   5,  93, 192,   5, 102, 192,   5,  98,   5, 102, 244,   5,  98,
   5,  97, 204,   5,  98,   5, 209, 102, 198,   5, 102, 221,   4,  97, 207,   5,
  98,   5, 209, 102, 198,   5, 102, 235,   4,  97, 208,   5,  16,  84,   0,   0,
 209,  98,   4,  70, 245,   5,   1,  41,  93, 193,   5, 102, 193,   5, 209,  70,
 246,   5,   1, 115,  99,   6,  93, 193,   5, 102, 193,   5, 210,  98,   6, 210,
 102, 233,   5,  70, 236,   5,   3,  41,  93, 193,   5, 102, 193,   5, 211,  98,
   6, 211, 102, 235,   5,  70, 237,   5,   3,  41,  93, 185,   5, 102, 185,   5,
  93, 193,   5, 102, 193,   5, 209,  70, 247,   5,   1,  98,   4, 210, 211,  70,
 248,   5,   4,  41,  71,   0,   0, 204,   2,   7,   3,   5,  10, 148,   7, 208,
  48,  87,  42, 213,  48, 101,   1,  32, 128, 213,   4, 109,   1, 101,   1,  39,
 109,   2, 101,   1,  32, 128, 200,   3, 109,   3, 101,   1,  32, 128, 200,   3,
 109,   4, 101,   1,  36,   0, 116, 109,   5, 101,   1,  32, 128, 243,   4, 109,
   6, 101,   1,  32, 128,  27, 109,   7, 101,   1,  33, 130, 109,   8, 101,   1,
  33, 130, 109,   9, 101,   1,  32, 128, 213,   3, 109,  10, 101,   1,  32, 128,
 213,   4, 109,   1, 101,   1,  39, 118, 109,   2, 101,   1, 208, 102, 205,   5,
  70, 202,   5,   0, 128, 200,   3, 109,   3, 101,   1, 208, 102, 205,   5,  70,
 202,   5,   0, 128, 200,   3, 109,   4, 208, 102, 205,   5, 102, 233,   5,  93,
 193,   5, 102, 193,   5, 102, 234,   5, 171, 150, 118,  42, 118,  18,  20,   0,
   0,  41, 208, 102, 228,   5, 102, 235,   5,  93, 193,   5, 102, 193,   5, 102,
 234,   5, 171, 150, 118,  18,  62,   0,   0,  93, 193,   5, 102, 193,   5, 101,
   1, 108,   4,  93, 193,   5, 102, 193,   5, 102, 234,   5, 101,   1, 108,   4,
 102, 233,   5,  70, 236,   5,   3,  41,  93, 193,   5, 102, 193,   5, 101,   1,
 108,   3,  93, 193,   5, 102, 193,   5, 102, 234,   5, 101,   1, 108,   3, 102,
 235,   5,  70, 237,   5,   3,  41, 101,   1, 208, 102, 205,   5,  70, 202,   5,
   0, 116, 109,   5, 101,   1, 208, 102, 205,   5,  70, 202,   5,   0, 128, 243,
   4, 109,   6, 101,   1, 101,   1, 108,   6, 128,  27, 109,   7, 101,   1,  38,
 118, 109,   2, 101,   1,  36,   0, 130, 109,   8,  16,  64,   1,   0,   9, 101,
   1, 108,   7, 101,   1, 108,   8, 102, 204,   5,  93, 185,   5, 102, 185,   5,
 179,  18,  30,   1,   0,  93, 193,   5, 102, 193,   5, 101,   1, 108,   7, 101,
   1, 108,   8, 102, 204,   5,  70, 241,   5,   1,  18, 147,   0,   0, 101,   1,
  93, 193,   5, 102, 193,   5, 102, 249,   5,  93, 193,   5, 102, 193,   5, 101,
   1, 108,   7, 101,   1, 108,   8, 102, 204,   5,  70, 247,   5,   1, 102, 204,
   5, 128, 213,   3, 109,  10, 101,   1, 108,  10, 118,  18,  19,   0,   0, 101,
   1, 108,   7, 101,   1, 108,   8, 101,   1, 108,  10,  97, 204,   5,  16,  75,
   0,   0,  93, 185,   5, 102, 185,   5, 101,   1, 108,   7, 101,   1, 108,   8,
 102, 204,   5,  93, 193,   5, 102, 193,   5, 102, 234,   5,  70, 250,   5,   2,
  41,  93, 193,   5, 102, 193,   5, 102, 249,   5,  93, 193,   5, 102, 193,   5,
 101,   1, 108,   7, 101,   1, 108,   8, 102, 204,   5,  70, 247,   5,   1, 101,
   1, 108,   7, 101,   1, 108,   8, 102, 204,   5,  97, 204,   5,  16, 114,   0,
   0,  93, 193,   5, 102, 193,   5, 101,   1, 108,   7, 101,   1, 108,   8, 102,
 204,   5,  93, 193,   5, 102, 193,   5, 102, 234,   5,  70, 242,   5,   2,  18,
  58,   0,   0, 101,   1, 108,   7, 101,   1, 108,   8,  93, 185,   5, 102, 185,
   5,  93, 192,   5, 102, 192,   5,  93, 193,   5, 102, 193,   5, 101,   1, 108,
   7, 101,   1, 108,   8, 102, 204,   5,  70, 247,   5,   1, 102, 204,   5, 102,
 221,   4,  70, 251,   5,   1,  97, 204,   5,  16,  22,   0,   0,  93, 193,   5,
 102, 193,   5, 101,   1, 108,   7, 101,   1, 108,   8, 102, 204,   5,  70, 238,
   5,   1,  41, 101,   1, 108,   8, 145, 130, 101,   1,  43, 109,   8, 101,   1,
 108,   8, 101,   1, 108,   7, 102, 200,   5,  21, 177, 254, 255, 208, 102, 252,
   5,  18,  21,   0,   0, 101,   1,  93, 253,   5,  32, 101,   1, 108,   6,  70,
 253,   5,   2, 130, 109,   9,  16,  40,   0,   0, 208, 102, 207,   5, 150,  18,
  11,   0,   0,  93, 254,   5,  44, 158,   4,  74, 254,   5,   1,   3, 101,   1,
  93, 253,   5, 208, 102, 207,   5, 101,   1, 108,   6,  70, 253,   5,   2, 130,
 109,   9, 101,   1, 108,   9,  93, 185,   5, 102, 185,   5, 179,  18,  26,   0,
   0, 208, 101,   1, 108,   9, 101,   1, 108,   4, 101,   1, 108,   3, 101,   1,
 108,   5,  70, 255,   5,   4,  41,  16,  85,   0,   0, 101,   1,  93, 243,   5,
 101,   1, 108,   3, 101,   1, 108,   4, 101,   1, 108,   5,  70, 243,   5,   3,
 128, 213,   4, 109,   1,  93, 192,   5, 102, 192,   5, 101,   1, 108,   1, 102,
 244,   5, 101,   1, 108,   1,  97, 204,   5,  93, 193,   5, 102, 193,   5, 101,
   1, 108,   9,  70, 128,   6,   1,  41, 101,   1, 108,   1, 101,   1, 108,   9,
  97, 207,   5, 101,   1, 108,   1,  93, 187,   5, 102, 187,   5,  97, 208,   5,
  16,  94,   0,   0, 208,  48, 209,  48,  90,   0,  42, 214,  42,  48,  43, 109,
   1, 101,   1, 108,   2,  18,  70,   0,   0, 101,   1,  93, 243,   5, 101,   1,
 108,   3, 101,   1, 108,   4, 101,   1, 108,   5,  70, 243,   5,   3, 128, 213,
   4, 109,   1,  93, 192,   5, 102, 192,   5, 101,   1, 108,   1, 102, 244,   5,
 101,   1, 108,   1,  97, 204,   5, 101,   1, 108,   1, 101,   2, 108,   1,  97,
 207,   5, 101,   1, 108,   1,  93, 189,   5, 102, 189,   5,  97, 208,   5,  29,
   8,   2,  71,   1,  91, 177,   6, 181,   6,   0, 238,   2,  10, 251,   4,   0,
   1, 213,   4,   0, 129,   6,   0,   2,   2,   0, 246,   4,   0,   3, 200,   3,
   0, 247,   4,   0,   4, 200,   3,   0, 139,   5,   0,   5,   8,   0, 242,   4,
   0,   6, 243,   4,   0, 244,   4,   0,   7,  27,   0, 245,   4,   0,   8,   0,
   0, 130,   6,   0,   9,   0,   0, 131,   6,   0,  10, 213,   3,   0, 205,   2,
   5,   3,   5,  10, 147,   4, 208,  48,  87,  42, 213,  48, 101,   1,  39, 109,
   1, 101,   1,  32, 128, 200,   3, 109,   2, 101,   1,  32, 128, 200,   3, 109,
   3, 101,   1,  36,   0, 116, 109,   4, 101,   1,  32, 128, 243,   4, 109,   5,
 101,   1,  33, 130, 109,   6, 101,   1,  32, 128, 213,   4, 109,   7, 101,   1,
  39, 118, 109,   1, 101,   1, 208, 102, 205,   5,  70, 202,   5,   0, 128, 200,
   3, 109,   2, 101,   1, 208, 102, 205,   5,  70, 202,   5,   0, 128, 200,   3,
 109,   3, 208, 102, 205,   5, 102, 233,   5,  93, 193,   5, 102, 193,   5, 102,
 234,   5, 171, 150, 118,  42, 118,  18,  20,   0,   0,  41, 208, 102, 228,   5,
 102, 235,   5,  93, 193,   5, 102, 193,   5, 102, 234,   5, 171, 150, 118,  18,
  62,   0,   0,  93, 193,   5, 102, 193,   5, 101,   1, 108,   3,  93, 193,   5,
 102, 193,   5, 102, 234,   5, 101,   1, 108,   3, 102, 233,   5,  70, 236,   5,
   3,  41,  93, 193,   5, 102, 193,   5, 101,   1, 108,   2,  93, 193,   5, 102,
 193,   5, 102, 234,   5, 101,   1, 108,   2, 102, 235,   5,  70, 237,   5,   3,
  41, 101,   1, 208, 102, 205,   5,  70, 202,   5,   0, 116, 109,   4, 101,   1,
 208, 102, 205,   5,  70, 202,   5,   0, 128, 243,   4, 109,   5, 101,   1,  38,
 118, 109,   1, 208, 102, 252,   5,  18,  21,   0,   0, 101,   1,  93, 132,   6,
  32, 101,   1, 108,   5,  70, 132,   6,   2, 130, 109,   6,  16,  40,   0,   0,
 208, 102, 207,   5, 150,  18,  11,   0,   0,  93, 254,   5,  44, 163,   4,  74,
 254,   5,   1,   3, 101,   1,  93, 132,   6, 208, 102, 207,   5, 101,   1, 108,
   5,  70, 132,   6,   2, 130, 109,   6, 101,   1, 108,   6,  93, 185,   5, 102,
 185,   5, 179,  18,  26,   0,   0, 208, 101,   1, 108,   6, 101,   1, 108,   3,
 101,   1, 108,   2, 101,   1, 108,   4,  70, 255,   5,   4,  41,  16,  85,   0,
   0, 101,   1,  93, 243,   5, 101,   1, 108,   2, 101,   1, 108,   3, 101,   1,
 108,   4,  70, 243,   5,   3, 128, 213,   4, 109,   7,  93, 192,   5, 102, 192,
   5, 101,   1, 108,   7, 102, 244,   5, 101,   1, 108,   7,  97, 204,   5, 101,
   1, 108,   7, 101,   1, 108,   6,  97, 207,   5,  93, 193,   5, 102, 193,   5,
 101,   1, 108,   6,  70, 128,   6,   1,  41, 101,   1, 108,   7,  93, 187,   5,
 102, 187,   5,  97, 208,   5,  16,  94,   0,   0, 208,  48, 209,  48,  90,   0,
  42, 214,  42,  48,  43, 109,   1, 101,   1, 108,   1,  18,  70,   0,   0, 101,
   1,  93, 243,   5, 101,   1, 108,   2, 101,   1, 108,   3, 101,   1, 108,   4,
  70, 243,   5,   3, 128, 213,   4, 109,   7,  93, 192,   5, 102, 192,   5, 101,
   1, 108,   7, 102, 244,   5, 101,   1, 108,   7,  97, 204,   5, 101,   1, 108,
   7, 101,   2, 108,   1,  97, 207,   5, 101,   1, 108,   7,  93, 189,   5, 102,
 189,   5,  97, 208,   5,  29,   8,   2,  71,   1,  62, 176,   3, 180,   3,   0,
 238,   2,   7, 129,   6,   0,   1,   2,   0, 246,   4,   0,   2, 200,   3,   0,
 247,   4,   0,   3, 200,   3,   0, 139,   5,   0,   4,   8,   0, 242,   4,   0,
   5, 243,   4,   0, 130,   6,   0,   6,   0,   0, 251,   4,   0,   7, 213,   4,
   0, 206,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 207,   2,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 208,   2,   3,   2,
   5,   6,  13, 208,  48, 208,  93, 152,   6, 102, 152,   6,  38,  73,   2,  71,
   0,   0, 210,   2,   2,   1,   1,   4, 109, 208,  48,  93, 153,   6,  93,  20,
 102,  20,  48,  93, 154,   6, 102, 154,   6,  88,  53,  29, 104, 155,   4,  93,
 155,   6,  93,  20, 102,  20,  48,  93, 154,   6, 102, 154,   6,  88,  54,  29,
 104, 196,   4,  93, 156,   6,  93,  20, 102,  20,  48,  93, 154,   6, 102, 154,
   6,  88,  55,  29, 104, 213,   3,  93, 157,   6,  93,  20, 102,  20,  48,  93,
 154,   6, 102, 154,   6,  88,  56,  29, 104, 213,   4,  93, 158,   6,  93,  20,
 102,  20,  48,  93,  27, 102,  27,  48,  93, 159,   6, 102, 159,   6,  88,  57,
  29,  29, 104, 243,   4,  71,   0,   0};


/* versioned_uris */
const char* const shell_toplevel_versioned_uris[] = {
    "__AS3__.vec", // [660]
    "avmplus", // [660]
    "avmplus:ITest", // [660]
    "avmshell", // [660, 661, 662, 663, 664, 665, 666]
    "flash.concurrent", // [682]
    "flash.errors", // [660]
    "flash.net", // [660]
    "flash.net:IDynamicPropertyOutput", // [660]
    "flash.net:IDynamicPropertyWriter", // [660]
    "flash.sampler", // [660]
    "flash.system", // [660, 682]
    "flash.trace", // [660]
    "flash.utils", // [660]
    "flash.utils:IDataInput", // [660]
    "flash.utils:IDataOutput", // [660]
    "flash.utils:IExternalizable", // [660]
    NULL
};

#ifdef VMCFG_AOT
extern "C" const struct {
    const char* const n_0; avmplus::DomainClass* const m_0;
    const char* const n_1; avmplus::DomainObject* const m_1;
    const char* const n_2; avmplus::NewObjectSampleClass* const m_2;
    const char* const n_3; avmplus::NewObjectSampleObject* const m_3;
    const char* const n_4; avmplus::PromiseClass* const m_4;
    const char* const n_5; avmplus::PromiseHelperClass* const m_5;
    const char* const n_6; avmplus::PromiseObject* const m_6;
    const char* const n_7; avmplus::RemoteProxyClass* const m_7;
    const char* const n_8; avmplus::RemoteProxyObject* const m_8;
    const char* const n_9; avmplus::TraceClass* const m_9;
    const char* const n_10; avmshell::AbstractBaseClass* const m_10;
    const char* const n_11; avmshell::AbstractBaseObject* const m_11;
    const char* const n_12; avmshell::AbstractRestrictedBaseClass* const m_12;
    const char* const n_13; avmshell::AbstractRestrictedBaseObject* const m_13;
    const char* const n_14; avmshell::CheckBaseClass* const m_14;
    const char* const n_15; avmshell::CheckBaseObject* const m_15;
    const char* const n_16; avmshell::EnvelopeClass* const m_16;
    const char* const n_17; avmshell::EnvelopeObject* const m_17;
    const char* const n_18; avmshell::FileClass* const m_18;
    const char* const n_19; avmshell::MIClass* const m_19;
    const char* const n_20; avmshell::MIObject* const m_20;
    const char* const n_21; avmshell::NativeBaseClass* const m_21;
    const char* const n_22; avmshell::NativeBaseObject* const m_22;
    const char* const n_23; avmshell::NativeSubclassOfAbstractBaseClass* const m_23;
    const char* const n_24; avmshell::NativeSubclassOfAbstractBaseObject* const m_24;
    const char* const n_25; avmshell::NativeSubclassOfAbstractRestrictedBaseClass* const m_25;
    const char* const n_26; avmshell::NativeSubclassOfAbstractRestrictedBaseObject* const m_26;
    const char* const n_27; avmshell::NativeSubclassOfRestrictedBaseClass* const m_27;
    const char* const n_28; avmshell::NativeSubclassOfRestrictedBaseObject* const m_28;
    const char* const n_29; avmshell::RestrictedBaseClass* const m_29;
    const char* const n_30; avmshell::RestrictedBaseObject* const m_30;
    const char* const n_31; avmshell::ShellWorkerClass* const m_31;
    const char* const n_32; avmshell::ShellWorkerDomainClass* const m_32;
    const char* const n_33; avmshell::ShellWorkerDomainObject* const m_33;
    const char* const n_34; avmshell::ShellWorkerObject* const m_34;
    const char* const n_35; avmshell::SystemClass* const m_35;
} aotABCTypes_shell_toplevel = {
    "DomainClass", 0,
    "DomainObject", 0,
    "NewObjectSampleClass", 0,
    "NewObjectSampleObject", 0,
    "::avmplus::PromiseClass", 0,
    "::avmplus::PromiseHelperClass", 0,
    "::avmplus::PromiseObject", 0,
    "::avmplus::RemoteProxyClass", 0,
    "::avmplus::RemoteProxyObject", 0,
    "TraceClass", 0,
    "::avmshell::AbstractBaseClass", 0,
    "::avmshell::AbstractBaseObject", 0,
    "::avmshell::AbstractRestrictedBaseClass", 0,
    "::avmshell::AbstractRestrictedBaseObject", 0,
    "::avmshell::CheckBaseClass", 0,
    "::avmshell::CheckBaseObject", 0,
    "::avmshell::EnvelopeClass", 0,
    "::avmshell::EnvelopeObject", 0,
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
    "::avmshell::ShellWorkerClass", 0,
    "::avmshell::ShellWorkerDomainClass", 0,
    "::avmshell::ShellWorkerDomainObject", 0,
    "::avmshell::ShellWorkerObject", 0,
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
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::ShellWorkerClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::ShellWorkerClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_ShellWorkerClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::ShellWorkerClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::ShellWorkerObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::WorkerEventClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::WorkerEventClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::WorkerEventClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_WorkerEventClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::WorkerEventClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::WorkerEventObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::WorkerEventClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::WorkerEventClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_WorkerEventClass
    m_slots_WorkerEventClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::WorkerEventClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass.m_WORKER_STATE),
    0};
MMgc::GCTracerCheckResult avmplus::WorkerEventClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,1);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::WorkerEventObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::WorkerEventObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_WorkerEventObject
    m_slots_WorkerEventObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::WorkerEventObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject.m_private_m_previousState),
    offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject.m_private_m_currentState),
    offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject.m_flash_system_m_target),
    0};
MMgc::GCTracerCheckResult avmplus::WorkerEventObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,3);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::ShellWorkerDomainClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::ShellWorkerDomainClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::ShellWorkerDomainClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_ShellWorkerDomainClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::ShellWorkerDomainClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::ShellWorkerDomainObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerDomainClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerDomainObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::PromiseStateClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::PromiseStateClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::PromiseStateClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_PromiseStateClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::PromiseStateClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::PromiseStateObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::PromiseStateClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::PromiseStateClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_PromiseStateClass
    m_slots_PromiseStateClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::PromiseStateClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass.m_NEW),
    offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass.m_RECEIVED),
    offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass.m_BROKEN),
    offsetof(avmplus::PromiseStateClass, m_slots_PromiseStateClass.m_EXCEPTION),
    0};
MMgc::GCTracerCheckResult avmplus::PromiseStateClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,4);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::PromiseStateObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::PromiseStateObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_PromiseStateObject
    m_slots_PromiseStateObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::PromiseStateObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::PromiseHelperClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::PromiseHelperClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::PromiseHelperClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_PromiseHelperClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::PromiseHelperClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::PromiseHelperObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::PromiseHelperClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::PromiseHelperObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::PromiseHelperObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_PromiseHelperObject
    m_slots_PromiseHelperObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::PromiseHelperObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::PromiseClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::PromiseClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_PromiseClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::PromiseClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::PromiseObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::PromiseClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::PromiseObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::RemoteProxyClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::RemoteProxyClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_RemoteProxyClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::RemoteProxyClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::RemoteProxyObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::RemoteProxyClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::RemoteProxyObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::EnvelopeClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::EnvelopeClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::EnvelopeClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_EnvelopeClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::EnvelopeClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::EnvelopeObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::EnvelopeClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::EnvelopeObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ArrayObject::construct(argc, argv); } )
