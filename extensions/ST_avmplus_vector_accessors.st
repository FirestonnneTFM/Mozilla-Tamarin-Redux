// -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
// vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
//
// ***** BEGIN LICENSE BLOCK *****
// Version: MPL 1.1/GPL 2.0/LGPL 2.1
//
// The contents of this file are subject to the Mozilla Public License Version
// 1.1 (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
// http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
// for the specific language governing rights and limitations under the
// License.
//
// The Original Code is [Open Source Virtual Machine.].
//
// The Initial Developer of the Original Code is
// Adobe System Incorporated.
// Portions created by the Initial Developer are Copyright (C) 2004-2006
// the Initial Developer. All Rights Reserved.
//
// Contributor(s):
//   Adobe AS3 Team
//
// Alternatively, the contents of this file may be used under the terms of
// either the GNU General Public License Version 2 or later (the "GPL"), or
// the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
// in which case the provisions of the GPL or the LGPL are applicable instead
// of those above. If you wish to allow use of your version of this file only
// under the terms of either the GPL or the LGPL, and not to allow others to
// use your version of this file under the terms of the MPL, indicate your
// decision by deleting the provisions above and replace them with the notice
// and other provisions required by the GPL or the LGPL. If you do not delete
// the provisions above, a recipient may use your version of this file under
// the terms of any one of the MPL, the GPL or the LGPL.
//
// ***** END LICENSE BLOCK ***** */

// Bugzilla 609145 - VectorObject needs fast inline getter/setters
// Make sure the APIs, which are used by the Flash Player and AIR only, do not disappear.
//
// NOTE, the following comment is stale and we can fix the code, see the code for
// VectorAccessor further down for how to access a toplevel.
//
// We can't test them because we don't have access to a Toplevel*, but we can reference
// them, and a link error will ensue if they disappear.
//
// Code coverage will get worse with this test, not better.  C'est la guerre.

%%component avmplus
%%category vector_accessors

%%prefix 

int32_t reference_getUintPropertyFast(IntVectorObject* obj, uint32_t x)
{
    return obj->getUintPropertyFast(x);
}

void reference_setUintPropertyFast(IntVectorObject* obj, uint32_t x, int32_t v)
{
    obj->setUintPropertyFast(x, v);
}

%%test getOrSetUintPropertyFast

%%verify true

%%test DataListAccessor_on_int

DataList<int> dl(core->GetGC(), 3);
dl.add(1);
dl.add(1);
dl.add(2);
dl.add(3);
dl.add(5);
dl.add(8);
dl.add(13);
DataListAccessor<int> dla(&dl);
int* xs = dla.addr();

%%verify xs[0] == 1
%%verify xs[1] == 1
%%verify xs[2] == 2
%%verify xs[3] == 3
%%verify xs[4] == 5
%%verify xs[5] == 8
%%verify xs[6] == 13

%%test DataListAccessor_on_float4

#ifdef VMCFG_FLOAT

DataList<float4_t, 16> dl4(core->GetGC(), 3);
float4_t x0 = { 1,1,2,3 };
float4_t x1 = { 5,8,13,21 };
float4_t x2 = { 34,55,89,144 };
dl4.add(x0);
dl4.add(x1);
dl4.add(x2);
DataListAccessor<float4_t,16> dla4(&dl4);
float4_t* x4s = dla4.addr();

%%verify f4_eq_i(x4s[0], x0) == 1
%%verify f4_eq_i(x4s[1], x1) == 1
%%verify f4_eq_i(x4s[2], x2) == 1

#else

%%verify true

#endif

%%test VectorAccessor_on_int

#ifdef AVMSHELL_BUILD

avmshell::ShellCore* c = (avmshell::ShellCore*)core;
avmshell::ShellToplevel* top = c->shell_toplevel;
IntVectorObject* vec = top->intVectorClass()->newVector();

vec->_setNativeUintProperty(0, 1);
vec->_setNativeUintProperty(1, 1);
vec->_setNativeUintProperty(2, 2);
vec->_setNativeUintProperty(3, 3);
vec->_setNativeUintProperty(4, 5);
vec->_setNativeUintProperty(5, 8);
vec->_setNativeUintProperty(6, 13);

IntVectorAccessor va(vec);
int* xs = va.addr();

%%verify xs[0] == 1
%%verify xs[1] == 1
%%verify xs[2] == 2
%%verify xs[3] == 3
%%verify xs[4] == 5
%%verify xs[5] == 8
%%verify xs[6] == 13

#else

%%verify true

#endif // AVMSHELL_BUILD

%%test VectorAccessor_on_float4

#if defined VMCFG_FLOAT && defined AVMSHELL_BUILD

avmshell::ShellCore* c = (avmshell::ShellCore*)core;
avmshell::ShellToplevel* top = c->shell_toplevel;
Float4VectorObject* vec = top->float4VectorClass()->newVector();

float4_t x0 = { 1,1,2,3 };
float4_t x1 = { 5,8,13,21 };
float4_t x2 = { 34,55,89,144 };

vec->_setNativeUintProperty(0, x0);
vec->_setNativeUintProperty(1, x1);
vec->_setNativeUintProperty(2, x2);

Float4VectorAccessor va(vec);
float4_t* x4s = va.addr();

%%verify f4_eq_i(x4s[0], x0) == 1
%%verify f4_eq_i(x4s[1], x1) == 1
%%verify f4_eq_i(x4s[2], x2) == 1

#else

%%verify true

#endif // AVMSHELL_BUILD
