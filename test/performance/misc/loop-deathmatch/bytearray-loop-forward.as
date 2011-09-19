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

import flash.utils.ByteArray;
import avmplus.*;

var DESC = "ByteArray forward int sum loop, 2048 elements";

function main()
{
    var then:uint = getTimer();
    var v: ByteArray = new ByteArray;

    v.endian = "littleEndian"; // Specialized for x86
    v.length = 8192;
    v.position = 0;
    for ( var i:int=0 ; i < 2048 ; i++ )
        v.writeInt(1);

    for ( var outer:int = 0 ; outer < 10000 ; outer++ ) {
        var sum:int=0;
        v.position = 0;   // Sequential forward access
        for ( var inner:int = 0 ; inner < 8192 ; inner+=4 ) {
            sum += v.readInt();
        }
    }

    if (sum != 2048)
        throw DESC + ": Unexpected result: " + sum;
    print((getTimer() - then) + "ms    " + DESC);
}
main();
