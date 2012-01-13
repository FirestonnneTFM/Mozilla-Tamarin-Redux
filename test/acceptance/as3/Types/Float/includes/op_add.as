/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

/*
Typed: (vars and return type)
toplevel op toplevel
localvar op localvar
arg      op arg
arg      op toplevel
arg      op localvar
localvar op toplevel

Untyped: (vars and return type)
toplevel op toplevel
localvar op localvar
arg      op arg
arg      op toplevel
arg      op localvar
localvar op toplevel
 */

var flt1:float = 3.124f;
var flt2:float = 1.125f;
var any1:* = 3.124f;
var any2:* = 1.125f;

function runner():void
{
    AddStrictTestCase("typed: toplevel + toplevel",   4.249f, addTopLevelTyped());
    AddStrictTestCase("typed: local + local",         4.249f, addLocalsTyped());
    AddStrictTestCase("typed: arg + arg",             4.249f, addArgsTyped(flt1, flt2));
    AddStrictTestCase("typed: arg + toplevel",        4.249f, addArgTopLevelTyped(flt1));
    AddStrictTestCase("typed: arg + local",           4.249f, addArgLocalTyped(flt1));
    AddStrictTestCase("typed: local + toplevel",      4.249f, addLocalTopLevelTyped());

    AddStrictTestCase("untyped: toplevel + toplevel", 4.249f, addTopLevelUntyped());
    AddStrictTestCase("untyped: local + local",       4.249f, addLocalsUntyped());
    AddStrictTestCase("untyped: arg + arg",           4.249f, addArgsUntyped(any1, any2));
    AddStrictTestCase("untyped: arg + toplevel",      4.249f, addArgTopLevelUntyped(any1));
    AddStrictTestCase("untyped: arg + local",         4.249f, addArgLocalUntyped(any1));
    AddStrictTestCase("untyped: local + toplevel",    4.249f, addLocalTopLevelUntyped());
}

function addTopLevelTyped():float { return flt1 + flt2; }

function addLocalsTyped():float
{
    var f1:float = 3.124f;
    var f2:float = 1.125f;
    return f1 + f2;
}
function addArgsTyped(param1:float, param2:float):float
{
    return param1 + param2;
}

function addArgTopLevelTyped(param1:float):float
{
    return param1 + flt2;
}

function addArgLocalTyped(param1:float):float
{
    var f2:float = 1.125f;
    return param1 + f2;
}

function addLocalTopLevelTyped():float
{
    var f1:float = 3.124f;
    return f1 + flt2;
}

function addTopLevelUntyped():* { return any1 + any2; }

function addLocalsUntyped():*
{
    var f1:* = 3.124f;
    var f2:* = 1.125f;
    return f1 + f2;
}

function addArgsUntyped(param1:*, param2:*):*
{
    return param1 + param2;
}

function addArgTopLevelUntyped(param1:*):*
{
    return param1 + any2;
}

function addArgLocalUntyped(param1:*):*
{
    var f2:* = 1.125f;
    return param1 + f2;
}

function addLocalTopLevelUntyped():*
{
    var f1:* = 3.124f;
    return f1 + any2;
}

