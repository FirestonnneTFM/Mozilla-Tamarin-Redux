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

#ifdef DEBUGGER  // DEBUGGER is typically defined by the project
  #define AVMFEATURE_DEBUGGER        1
#else
  #define AVMFEATURE_DEBUGGER        0
#endif
#define AVMFEATURE_VTUNE             0
#define AVMFEATURE_JIT               1
#define AVMFEATURE_ABC_INTERP        0
#define AVMFEATURE_WORDCODE_INTERP   1
#ifndef AVMFEATURE_THREADED_INTERP
  #ifdef __GNUC__
    #define AVMFEATURE_THREADED_INTERP 1
  #else
    #define AVMFEATURE_THREADED_INTERP 0
  #endif
#endif
// our build scripts like to set this externally, so let them
#ifndef AVMFEATURE_SELFTEST
  #define AVMFEATURE_SELFTEST          0
#endif
#define AVMFEATURE_UTF32             0
#define AVMFEATURE_EVAL              0

#endif // __avmshell_features__
