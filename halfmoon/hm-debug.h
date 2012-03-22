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

// Debug assistance code.

#ifndef HM_DEBUG_H_
#define HM_DEBUG_H_

namespace halfmoon {

//debug routines that are potentially useful throughout halfmoon

extern const bool debug_stubs;      // call stubs rather than generate code
extern bool stub_out[];             // call stubs rather than generate code

/**
 * print available debug flags
 */
void debugWelcome();

/**
 * initialize debug tools
 */
void debugInit();

/**
 * Originally written so that the inliner could be made to skip inlining certain candidates.
 * idea is that user set env var to contain list of ; separated names. this function
 * @param env_var_name value something like ;foo;bar;baz;
 * @param query_string
 * @return true if tokens within env variable named by env_var_name contains query_string.
 * idea is that user sets env var to contain list of ; separated names. this function returns true
 * if query_string is one of those tokens.
 */
extern bool debugIsInSkiplist(const char *env_var_name, String *query_string );

} //namespace halfmoon

#endif /* HM_DEBUG_H_ */
