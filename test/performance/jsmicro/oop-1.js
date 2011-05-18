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

var DESC = "Object-oriented programming using prototype methods";

function makePrototype(proto, methods) {
    function f() {}
    f.prototype = proto;
    var o = new f;
    for ( var x in methods )
	o[x] = methods[x];
    return o;
}

function Obj(x, y, z) {
    this._x = x;
    this._y = y;
    this._z = z;
}
Obj.prototype = 
    makePrototype(Object.prototype,
		  { x: function () { return this._x },
		    y: function () { return this._y },
		    z: function () { return this._z },
		    move: function (xrel, yrel, zrel) { this._x += xrel; this._y += yrel; this._z += zrel },
		    volume: function () { throw new Error("Obj.volume is abstract") },
		    toString: function() { return "(OBJ " + this.x() + " " + this.y() + " " + this.z() + ")" }
		  });

function Sphere(x, y, z, r) {  // (x,y,z) is the center
    this._r = r;
    Obj.call(this, x, y, z);
}
Sphere.prototype =
    makePrototype(Obj.prototype,
		  { volume: function () { return 4/3 * Math.PI * this.r() * this.r() * this.r() },
		    r: function () { return this._r },
		    toString: function() { return "(SPHERE " + this.x() + " " + this.y() + " " + this.z() + " " + this.r() + ")" }
		  });

function TranslucentSphere(x, y, z, r, alpha) {
    this._alpha = alpha;
    Sphere.call(this, x, y, z, r);
}
TranslucentSphere.prototype = 
    makePrototype(Sphere.prototype,
		  { alpha: function () { return this._alpha } });

function Box(x, y, z, l) {  // (x,y,z) is some corner
    this._l = l;
    Obj.call(this, x, y, z);
}
Box.prototype =
    makePrototype(Obj.prototype,
		  { volume: function () { return this.l() * this.l() * this.l() },
		    l: function () { return this._l },
		    toString: function() { return "(BOX " + this.x() + " " + this.y() + " " + this.z() + " " + this.l() + ")" }
		  });

function Composite(o1, o2) {
    this._o1 = o1;
    this._o2 = o2;
    Obj.call(this, 0, 0, 0);
}
Composite.prototype = 
    makePrototype(Obj.prototype,
		  { volume: function () { return this.o1().volume() + this.o2().volume() },
		    move: function (x, y, z) { this.o1().move(x, y, z); this.o2().move(x, y, z) },
		    o1: function () { return this._o1 },
		    o2: function () { return this._o2 },
		    toString: function () { return "(COMPOSITE " + this.o1() + " " + this.o2() + ")" }
		  });

function ooploop() {
    var g = 
	new Composite(new TranslucentSphere(0,0,0,7,0.25),
		      new Box(1,1,1,4));
    var v = 0;
    for ( var i=0 ; i < 100000 ; i++ ) {
	g.move(1,2,3);
	v += g.volume();
    }
}

TEST(ooploop, "oop-1");
