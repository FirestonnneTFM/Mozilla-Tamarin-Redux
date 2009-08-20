//                     DO NOT EDIT THIS FILE
// 
//  This file has been generated by the script core/avmfeatures.as,
//  from a set of configuration parameters in that file.
// 
//  If you feel you need to make changes below, instead edit the configuration
//  file and rerun it to get a new version of this file.
// 
//  ***** BEGIN LICENSE BLOCK *****
//  Version: MPL 1.1/GPL 2.0/LGPL 2.1
// 
//  The contents of this file are subject to the Mozilla Public License Version
//  1.1 (the "License"); you may not use this file except in compliance with
//  the License. You may obtain a copy of the License at
//  http://www.mozilla.org/MPL/
// 
//  Software distributed under the License is distributed on an "AS IS" basis,
//  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
//  for the specific language governing rights and limitations under the
//  License.
// 
//  The Original Code is [Open Source Virtual Machine.].
// 
//  The Initial Developer of the Original Code is
//  Adobe System Incorporated.
//  Portions created by the Initial Developer are Copyright (C) 2009
//  the Initial Developer. All Rights Reserved.
// 
//  Contributor(s):
//    Adobe AS3 Team
// 
//  Alternatively, the contents of this file may be used under the terms of
//  either the GNU General Public License Version 2 or later (the "GPL"), or
//  the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
//  in which case the provisions of the GPL or the LGPL are applicable instead
//  of those above. If you wish to allow use of your version of this file only
//  under the terms of either the GPL or the LGPL, and not to allow others to
//  use your version of this file under the terms of the MPL, indicate your
//  decision by deleting the provisions above and replace them with the notice
//  and other provisions required by the GPL or the LGPL. If you do not delete
//  the provisions above, a recipient may use your version of this file under
//  the terms of any one of the MPL, the GPL or the LGPL.
// 
//  ***** END LICENSE BLOCK ****

#include "avmplus.h"

#ifdef AVMSHELL_BUILD

// The string avmfeatures contains the names of all features that were enabled
// when the program was compiled.  Each feature name is terminated by a semicolon.
const char * const avmfeatures = ""
  #if AVMSYSTEM_32BIT
    "AVMSYSTEM_32BIT;"
  #endif
  #if AVMSYSTEM_64BIT
    "AVMSYSTEM_64BIT;"
  #endif
  #if AVMSYSTEM_BIG_ENDIAN
    "AVMSYSTEM_BIG_ENDIAN;"
  #endif
  #if AVMSYSTEM_LITTLE_ENDIAN
    "AVMSYSTEM_LITTLE_ENDIAN;"
  #endif
  #if AVMSYSTEM_DOUBLE_MSW_FIRST
    "AVMSYSTEM_DOUBLE_MSW_FIRST;"
  #endif
  #if AVMSYSTEM_ARM_FPU
    "AVMSYSTEM_ARM_FPU;"
  #endif
  #if AVMSYSTEM_IA32
    "AVMSYSTEM_IA32;"
  #endif
  #if AVMSYSTEM_AMD64
    "AVMSYSTEM_AMD64;"
  #endif
  #if AVMSYSTEM_ARM
    "AVMSYSTEM_ARM;"
  #endif
  #if AVMSYSTEM_PPC
    "AVMSYSTEM_PPC;"
  #endif
  #if AVMSYSTEM_SPARC
    "AVMSYSTEM_SPARC;"
  #endif
  #if AVMSYSTEM_UNIX
    "AVMSYSTEM_UNIX;"
  #endif
  #if AVMSYSTEM_MAC
    "AVMSYSTEM_MAC;"
  #endif
  #if AVMSYSTEM_WIN32
    "AVMSYSTEM_WIN32;"
  #endif
  #if AVMSYSTEM_SYMBIAN
    "AVMSYSTEM_SYMBIAN;"
  #endif
  #if AVMFEATURE_DEBUGGER
    "AVMFEATURE_DEBUGGER;"
  #endif
  #if AVMFEATURE_ALLOCATION_SAMPLER
    "AVMFEATURE_ALLOCATION_SAMPLER;"
  #endif
  #if AVMFEATURE_VTUNE
    "AVMFEATURE_VTUNE;"
  #endif
  #if AVMFEATURE_JIT
    "AVMFEATURE_JIT;"
  #endif
  #if AVMFEATURE_ABC_INTERP
    "AVMFEATURE_ABC_INTERP;"
  #endif
  #if AVMFEATURE_WORDCODE_INTERP
    "AVMFEATURE_WORDCODE_INTERP;"
  #endif
  #if AVMFEATURE_THREADED_INTERP
    "AVMFEATURE_THREADED_INTERP;"
  #endif
  #if AVMFEATURE_SELFTEST
    "AVMFEATURE_SELFTEST;"
  #endif
  #if AVMFEATURE_EVAL
    "AVMFEATURE_EVAL;"
  #endif
  #if AVMFEATURE_PROTECT_JITMEM
    "AVMFEATURE_PROTECT_JITMEM;"
  #endif
  #if AVMFEATURE_SHARED_GCHEAP
    "AVMFEATURE_SHARED_GCHEAP;"
  #endif
  #if AVMFEATURE_USE_SYSTEM_MALLOC
    "AVMFEATURE_USE_SYSTEM_MALLOC;"
  #endif
  #if AVMFEATURE_CPP_EXCEPTIONS
    "AVMFEATURE_CPP_EXCEPTIONS;"
  #endif
  #if AVMFEATURE_INTERIOR_POINTERS
    "AVMFEATURE_INTERIOR_POINTERS;"
  #endif
  #if AVMFEATURE_JNI
    "AVMFEATURE_JNI;"
  #endif
  #if AVMFEATURE_HEAP_ALLOCA
    "AVMFEATURE_HEAP_ALLOCA;"
  #endif
  #if AVMFEATURE_STATIC_FUNCTION_PTRS
    "AVMFEATURE_STATIC_FUNCTION_PTRS;"
  #endif
  #if AVMFEATURE_INDIRECT_NATIVE_THUNKS
    "AVMFEATURE_INDIRECT_NATIVE_THUNKS;"
  #endif
  #if AVMFEATURE_OVERRIDE_GLOBAL_NEW
    "AVMFEATURE_OVERRIDE_GLOBAL_NEW;"
  #endif
;

#endif // AVMSHELL_BUILD
