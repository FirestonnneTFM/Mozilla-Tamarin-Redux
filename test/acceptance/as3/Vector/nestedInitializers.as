/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    nested.as
   Description:  tests nested Vectors: Vector.<Vector.<int>>
   *
   */
var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " nested Vector-initializers");

var v1:Vector.<Vector.<int>> = new <Vector.<int>> [
    new <int>[0,1],
    new <int>[2,3],
    new <int>[4,5]];
AddTestCase("push nested vector.<int>",
            "0,1,2,3,4,5",
            v1.toString());

var v3:Vector.<Vector.<String>>=new <Vector.<String>>
[
    new <String>['one','two'],
    new <String>['three','four'],
    new <String>['five','six'],
]
AddTestCase("push nested vector.<String>",
            "one,two,three,four,five,six",
            v3.toString());


AddTestCase("push nested vector.<String> as value",
            "one,two,three,four,five,six",
                new <Vector.<String>>
                [
                    new <String>['one','two'],
                    new <String>['three','four'],
                    new <String>['five','six'],
                ]
            .toString());

var v5:Vector.<Vector.<Vector.<int>>> =
    new <Vector.<Vector.<int>>>[
    new <Vector.<int>>[ new <int>[0,1]],
    new <Vector.<int>>[ new <int>[2,3]],
    new <Vector.<int>>[ new <int>[4,5]],
    ];

AddTestCase("push nested vector.<vector.<int>>",
            "0,1,2,3,4,5",
            v5.toString());

AddTestCase("nested vector.<vector.<int>> as value",
            "0,1,2,3,4,5",
            new <Vector.<Vector.<int>>>[
                new <Vector.<int>>[ new <int>[0,1]],
                new <Vector.<int>>[ new <int>[2,3]],
                new <Vector.<int>>[ new <int>[4,5]],
            ].toString());

test();
