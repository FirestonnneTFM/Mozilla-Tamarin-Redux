/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

namespace foons = "foo";

function ns_to_string(ns:Namespace) { return String(ns); }

startTest();

AddTestCase("ns_to_string(foons)", "foo", ns_to_string(foons));
AddTestCase("ns_to_string(null)", "null", ns_to_string(null));
AddTestCase("ns_to_string(void 0)", "null", ns_to_string(void 0)); // unbox undefined -> Namespace should yield null


test();
