/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
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

#ifndef AOTCompiler_h
#define AOTCompiler_h

#include "avmplus.h"
#include "CDeclThunk.h"

#ifdef VMCFG_BUFFER_GUARD
#include "GenericGuard.h"
#endif

#define EXPORT_OPCODE extern "C"

namespace avmplus {
    class Traits;
    class AbcEnv;
    typedef int(*InterfaceBindingFunction)(int);
}

//------------------------------------------------------------------------------
// LLVM type hacks
//------------------------------------------------------------------------------
// Because we can't specialise templates on typedefs we hide Atoms, bool, etc. as
// pointers to these opaque structs. The pointers are never dereferenced, they
// just get cast to whatever their real type is.
//------------------------------------------------------------------------------
typedef struct LLVMAtomS* LLVMAtom;
typedef struct LLVMBoolS* LLVMBool;
typedef struct LLVMUnusedParamS* LLVMUnusedParam;
typedef struct LLVMMultinameIndexS* LLVMMultinameIndex;
typedef struct LLVMMultinameIndexMaybeIntS* LLVMMultinameIndexMaybeInt;
typedef struct LLVMMultinamePtrMaybeIntS* LLVMMultinamePtrMaybeInt;
//------------------------------------------------------------------------------

struct MethodDebugInfo {
    const int local_count;
    const int scope_count;
    const int file_name;
    const int * const local_names;
    const int line_count;
    const int * const lines;
};

typedef uintptr_t (*AOTLazyEvalFunc)(avmplus::MethodEnv *env, uintptr_t clientData);

struct AOTLazyEvalInfo
{
    uint32_t methodID;
    AOTLazyEvalFunc func;
    uintptr_t funcData;
};

struct AOTActivationInfo
{
    uint32_t initMethodId;
    const avmplus::AvmThunkNativeFunctionHandler initHandler;
};

struct AOTInfo {
    unsigned char origABCSHA1[20]; // sha1 hash of the original abc

    const unsigned char* abcBytes;
    size_t nABCBytes;

    const MethodDebugInfo* methodDebugInfos; // may be NULL if not debugging but it's always in the struct
    const avmplus::AvmThunkNativeFunctionHandler* abcMethods;
    size_t nABCMethods;

    // Script, indexed by scriptId
    avmplus::Traits** scriptTraits;

    // functions to resolve IIDs->dispids
    const avmplus::InterfaceBindingFunction* interfaceBindingFunctions;
    size_t nInterfaceBindingFunctions;

    // Activation traits info, indexed by methodId up to nActivationTraits;
    avmplus::Traits** activationTraits;
    const AOTActivationInfo *activationInfo;
    size_t nActivationTraits;

    // Per-ABC Lazy evaluation
    const AOTLazyEvalInfo *lazyEvalInfos;
    uintptr_t **lazyEvalValPtrs;
    uintptr_t *lazyEvalVals;
    size_t nLazyEvals;

    // abcEnv used to allow cross-abc callstatics
    avmplus::AbcEnv** abcEnv;

    // static multinames
    avmplus::Multiname **multinames; // TODO could probably be an array of multinames
    const int32_t *multinameIndices;
};

#ifdef VMCFG_BUFFER_GUARD
// Note that this assumes that there is only one AbcEnv/PoolObject per AOTInfo! I.e., a given ABC is only instantiated once!
class AOTLazyEvalGuard : public avmplus::LoadRedirGuard
{
protected:
    const avmplus::AbcEnv *m_abcEnv;

public:
    AOTLazyEvalGuard(const avmplus::AbcEnv *abcEnv);
    uintptr_t *redirectLoad(uintptr_t *faultAddr);
};
#endif

#define EMPTY_AOTInfo { {}, NULL, 0, NULL, NULL, 0, NULL, NULL, 0, NULL, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, NULL }

struct LLVMVectorInstance {
    avmplus::Traits* iTraits;
    avmplus::Traits** vectorParamTraitsId;
};

class AOTMethodFrame {
    avmplus::MethodFrame m_frame;
public:
    inline void enter(avmplus::AvmCore* core, avmplus::MethodEnv* e) {
        m_frame.enter(core, e);
    }

    inline void exit(avmplus::AvmCore* core) {
        m_frame.exit(core);
    }

    inline void set_dxns(avmplus::Namespace* dxns) {
        m_frame.setDxns(dxns);
    }
};

extern "C" {
    extern __attribute__ ((visibility("default"))) const AOTInfo aotInfos[];
    extern __attribute__ ((visibility("default"))) const size_t nAOTInfos;
    extern __attribute__ ((visibility("default"))) const avmplus::AbcEnv* aotAbcEnvs[];
    extern __attribute__ ((visibility("default"))) const uint32_t nAotAbcEnvs;
    extern __attribute__ ((visibility("default"))) const AOTInfo builtin_aotInfo;
    extern __attribute__ ((visibility("default"))) const AOTInfo shell_toplevel_aotInfo;
    extern __attribute__ ((visibility("default"))) const AOTInfo avmglue_aotInfo;
    extern __attribute__ ((visibility("default"))) const uint32_t abcNVectorInstances;
    extern __attribute__ ((visibility("default"))) LLVMVectorInstance abcVectorInstances[];
    extern __attribute__ ((visibility("default"))) const LLVMUnusedParam g_unusedParam;
}

#endif
