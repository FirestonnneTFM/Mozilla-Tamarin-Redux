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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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

#ifndef __avmshell_features__
#define __avmshell_features__

// Include the refactored, standard, system determination.  It defines
// all the AVMSYSTEM_ names for tier-one platforms.  It may be used by 
// other feature definition files than this one.

#include "system-selection.h"

// vm features for shell builds
//
// In general these can and will be set by our external build script, and
// any external definition should override the ones here.  So every definition
// here is a default and should be protected by an #ifdef

#ifndef AVMFEATURE_DEBUGGER
  // DEBUGGER is typically defined by the project file and gets preferenatial
  // treatment here, but we should get rid of DEBUGGER by and by and switch
  // to AVMFEATURE_DEBUGGER as the only external control
  #ifdef DEBUGGER
    #define AVMFEATURE_DEBUGGER        1
  #else
    #define AVMFEATURE_DEBUGGER        0
  #endif
#endif

#ifndef AVMFEATURE_VTUNE
  #define AVMFEATURE_VTUNE             0
#endif

#ifndef AVMFEATURE_JIT
  #define AVMFEATURE_JIT               1
#endif

#ifndef AVMFEATURE_ABC_INTERP
  #define AVMFEATURE_ABC_INTERP        0
#endif

#ifndef AVMFEATURE_WORDCODE_INTERP
  #define AVMFEATURE_WORDCODE_INTERP   1
#endif

#if AVMFEATURE_WORDCODE_INTERP
  #ifndef AVMFEATURE_THREADED_INTERP
    #ifdef __GNUC__
      #define AVMFEATURE_THREADED_INTERP 1
    #else
      #define AVMFEATURE_THREADED_INTERP 0
    #endif
  #endif
#else
  #define AVMFEATURE_THREADED_INTERP   0
#endif

#ifndef AVMFEATURE_SELFTEST
  #define AVMFEATURE_SELFTEST          0
#endif

#ifndef AVMFEATURE_UTF32
  #define AVMFEATURE_UTF32             0
#endif

#ifndef AVMFEATURE_EVAL
  #define AVMFEATURE_EVAL              1
#endif

#ifndef AVMFEATURE_PROTECT_JITMEM
  #define AVMFEATURE_PROTECT_JITMEM    1
#endif

#ifndef AVMFEATURE_SHARED_GCHEAP
  #define AVMFEATURE_SHARED_GCHEAP     1
#endif

#ifndef AVMFEATURE_USE_SYSTEM_MALLOC
  #define AVMFEATURE_USE_SYSTEM_MALLOC 0
#endif

#ifndef AVMFEATURE_CPP_EXCEPTIONS
  #define AVMFEATURE_CPP_EXCEPTIONS    0
#endif

#ifndef AVMFEATURE_INTERIOR_POINTERS
  #define AVMFEATURE_INTERIOR_POINTERS 0
#endif

#endif // __avmshell_features__
