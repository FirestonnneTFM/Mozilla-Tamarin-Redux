/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

var gTestfile = 'regress-320119.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 320119;
var summary = 'delegating objects and arguments, arity, caller, name';
var actual = '';
var expect = '';

printBugNumber(BUGNUMBER);
printStatus (summary);

printStatus('original test');

function origtest(name, bar)
{
  this.name = name;
  this.bar = bar;
}

function Monty(id, name, bar)
{
  this.id = id;
  this.base = origtest;
  this.base(name, bar);
}

Monty.prototype = origtest;

function testtwo(notNamedName, bar)
{
  this.name = notNamedName;
  this.bar = bar;
}

function Python(id, notNamedName, bar)
{
  this.id = id;
  this.base = origtest;
  this.base(notNamedName, bar);
}

Python.prototype = testtwo;

var foo = new Monty(1, 'my name', 'sna!');

var manchu = new Python(1, 'my name', 'sna!');

printStatus('foo.name: ' + foo.name);
printStatus('manchu.name: ' + manchu.name);

expect = 'my name:my name';
actual = foo.name + ':' + manchu.name;
AddTestCase(summary + ': override function..name', expect, actual);

// end original test

printStatus('test shared properties');

function testshared()
{
}

expect = false;
actual = testshared.hasOwnProperty('arguments');
AddTestCase(summary + ': arguments no longer shared', expect, actual);

expect = false;
actual = testshared.hasOwnProperty('caller');
AddTestCase(summary + ': caller no longer shared', expect, actual);

expect = false;
actual = testshared.hasOwnProperty('arity');
AddTestCase(summary + ': arity no longer shared', expect, actual);

expect = false;
actual = testshared.hasOwnProperty('name');
AddTestCase(summary + ': name no longer shared', expect, actual);

expect = true;
actual = testshared.hasOwnProperty('length');
AddTestCase(summary + ': length still shared', expect, actual);

printStatus('test overrides');

function Parent()
{
  this.arguments = 'oarguments';
  this.caller = 'ocaller';
  this.arity = 'oarity';
  this.length = 'olength';
  this.name = 'oname';
}

function Child()
{
  this.base = Parent;
  this.base();
}

Child.prototype = Parent;

Child.prototype.value = function()
{
  return this.arguments + ',' + this.caller + ',' + this.arity + ',' +
  this.length + ',' + this.name;
};

var child = new Child();

expect = 'oarguments,ocaller,oarity,olength,oname';
actual = child.value();
AddTestCase(summary + ': overrides', expect, actual);

test();
