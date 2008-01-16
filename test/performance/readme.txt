# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Initial Developer of the Original Code is: 
# dschaffe@adobe.com
#
# Portions created by the Initial Developer are Copyright (C) 2008
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

Instructions for running performance tests

- sunspider is a collection of tests from Apple http://webkit.org/perf/sunspider-0.9/sunspider.html, the tests are from computer
    shootout, and other sources
- any other performance tests can be added by providing .as source code, when run the code should print("metric <name> <value>")

the tests are meant to be run against tamarin-central and/or tamarin-tracing

usage example:
$ export AVM=c:/dev/tamarin-central/platform/win32/obj_8/shell/Release/avmplus.exe
$ export AVMTT=c:/dev/tamarin-tracing/platform/win32/obj_8/shell/Release/avmplus.exe
$ export ASC=c:/dev/asc/asc.jar
$ export GLOBALABC=c:/dev/tamarin-central/core/builtin.abc
$ ./runtests.py


to specify the tests to run
$ ./runtests.py typed/access-nbody.as
or 
$ ./runtests.py untyped/

to skip tests edit testconfig.txt

example output:
$ ./runtests.py
Executing 52 tests at 2008-01-10 11:25:47.949447
tc: c:/dev/tamarin-central/platform/win32/obj_8/shell/Release/avmplus.exe
tt: c:/dev/tamarin-tracing/platform/win32/obj_8/shell/Release/avmplus.exe


test                                                    tc      tt

typed/sunspider-access-binary-trees.as                  94    1203
typed/sunspider-access-fannkuch.as                      78    1968
typed/sunspider-access-nbody.as                        235     468
typed/sunspider-access-nsieve.as                        46     875
typed/sunspider-bitops-3bit-bits-in-byte.as             15      32
typed/sunspider-bitops-bits-in-byte.as                  16      78
typed/sunspider-bitops-bitwise-and.as                   16      31
typed/sunspider-bitops-nsieve-bits.as                   32     688
typed/sunspider-controlflow-recursive.as                78      na
typed/sunspider-crypto-aes.as                           62    3094
typed/sunspider-crypto-md5.as                           63    4249
typed/sunspider-crypto-sha1.as                          62    1578
typed/sunspider-math-cordic.as                         109     296
typed/sunspider-math-partial-sums.as                   125     281
typed/sunspider-math-spectral-norm.as                   78     219
typed/sunspider-s3d-cube.as                             46    2688
typed/sunspider-s3d-morph.as                            62     344
typed/sunspider-s3d-raytrace.as                        109    3172
typed/sunspider-string-fasta.as                        125     688
typed/sunspider-string-validate-input.as               109    5515
untyped/sunspider-access-binary-trees.as                94    1172
untyped/sunspider-access-fannkuch.as                   172    4281
untyped/sunspider-access-nbody.as                      265     453
untyped/sunspider-access-nsieve.as                      94     860
untyped/sunspider-bitops-3bit-bits-in-byte.as           32      31
untyped/sunspider-bitops-bits-in-byte.as                31     109
untyped/sunspider-bitops-bitwise-and.as                328     609
untyped/sunspider-bitops-nsieve-bits.as                 63     687
untyped/sunspider-controlflow-recursive.as              63      na
untyped/sunspider-crypto-aes.as                         94    2765
untyped/sunspider-crypto-md5.as                         63    4188
untyped/sunspider-crypto-sha1.as                        47    1610
untyped/sunspider-math-cordic.as                       140     297
untyped/sunspider-math-partial-sums.as                 296     641
untyped/sunspider-math-spectral-norm.as                203     343
untyped/sunspider-s3d-cube.as                          141    2672
untyped/sunspider-s3d-morph.as                         156     438
untyped/sunspider-s3d-raytrace.as                      187    9077
untyped/sunspider-string-fasta.as                      156     688
untyped/sunspider-string-validate-input.as             140    5452

