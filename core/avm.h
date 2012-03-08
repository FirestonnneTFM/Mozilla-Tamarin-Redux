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
 * Portions created by the Initial Developer are Copyright (C) 1993-2007
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


#ifndef __avm__
#define __avm__

#include "VMPI.h"


namespace avm {
using avmplus::Atom;
using avmplus::CodeContext;
using avmplus::ScriptObject;
using avmplus::Toplevel;

/**
 * If the given Object is a Function (or subclass thereof), return true. Otherwise, return false.
 */
bool isFunction(const ScriptObject* o);

/**
 * Given an Object that is a Function or MethodClosure, return the CodeContext
 * that is associated with the function's point of definition.
 * It will not return a useful result for anything other than a Function (or MethodClosure
 * or other subclass of Function): passing such an object to this call will return NULL
 * (and assert in debug builds.)
 */
CodeContext* getFunctionCodeContext(const ScriptObject* o);

/**
 * Given an Object, return the CodeContext that is associated with the object's
 * point of definition. Note that this API is deprecated and should really only be
 * used for legacy code that relies on this; do NOT use this for new code.
 * It will not return a useful result for Functions, MethodClosures, activation
 * objects, or catch objects: passing such an object to this call will return NULL
 * (and assert in debug builds.)
 */
CodeContext* getClassCodeContext(const ScriptObject* o);

/**
 * If f is a non-null Function, invoke it.  Otherwise throw an exception.
 */
Atom callFunction(Toplevel*, Atom f, int argc, Atom* args);

/**
 * f must be a non-null ScriptObject.  invoke the [[Call]] internal method to invoke
 * f as a closure.  Exceptions can  be thrown if f is not a Function or Class, or if the
 * target user code throws.
 */
Atom callFunction(ScriptObject*, int argc, Atom* args);
Atom callFunction(ScriptObject*); // call with no args and receiver=null

} // namespace avm

#endif /* __avm__ */
