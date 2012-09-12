/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("11.2.4 - XML Filtering Predicate Operator");

var p;

e = <employees>
    <employee id="0"><fname>John</fname><age>20</age></employee>
    <employee id="1"><fname>Sue</fname><age>30</age></employee>
    </employees>;


correct = <employee id="0"><fname>John</fname><age>20</age></employee>;

john = e.employee.(fname == "John");
TEST(1, correct, john);

john = e.employee.(fname == "John");
TEST(2, correct, john);

correct =
<employee id="0"><fname>John</fname><age>20</age></employee> +
<employee id="1"><fname>Sue</fname><age>30</age></employee>;

twoEmployees = e.employee.(@id == 0 || @id == 1);
TEST(3, correct, twoEmployees);

twoEmployees = e.employee.(@id == 0 || @id == 1);
TEST(4, correct, twoEmployees);

i = 0;
twoEmployees = new XMLList();
for each (p in e..employee)
{
    if (p.@id == 0 || p.@id == 1)
    {
        twoEmployees += p;
    }
}
TEST(5, correct, twoEmployees);

i = 0;
twoEmployees = new XMLList();
for each (p in e..employee)
{
    if (p.@id == 0 || p.@id == 1)
    {
        twoEmployees[i++] = p;
    }
}
TEST(6, correct, twoEmployees);

// test with syntax
e = <employees>
    <employee id="0"><fname>John</fname><age>20</age></employee>
    <employee id="1"><fname>Sue</fname><age>30</age></employee>
    </employees>;

correct =
<employee id="0"><fname>John</fname><age>20</age></employee> +
<employee id="1"><fname>Sue</fname><age>30</age></employee>;

i = 0;
twoEmployees = new XMLList();
for each (p in e..employee)
{
    with (p)
    {
        if (@id == 0 || @id == 1)
        {
            twoEmployees[i++] = p;
        }
    }
}
TEST(7, correct, twoEmployees);

var xml = "<employees><employee id=\"1\"><fname>Joe</fname><age>20</age></employee><employee id=\"2\"><fname>Sue</fname><age>Joe</age></employee></employees>";
var e = new XML(xml);

// get employee with fname Joe
AddTestCase("e.employee.(fname == \"Joe\")", 1, (joe = e.employee.(fname == "Joe"), joe.length()));


// employees with id's 0 & 1
AddTestCase("employees with id's 1 & 2", 2, (emps = e.employee.(@id == 1 || @id == 2), emps.length()));


// name of employee with id 1
AddTestCase("name of employee with id 1", "Joe", (emp = e.employee.(@id == 1).fname, emp.toString()));


// get the two employees with ids 0 and 1 using a predicate
var i = 0;
var twoEmployees = new XMLList();
for each (p in e..employee) {
    with (p) {
        if (@id == 1 || @id == 2) {
            twoEmployees[i++] = p;
        }
    }
}

var twoEmployees = e..employee.(@id == 1 || @id == 2);

AddTestCase("Compare to equivalent XMLList", true, (emps = e..employee.(@id == 1 || @id == 2), emps == twoEmployees));

 var employees:XML =
<employees>
<employee ssn="123-123-1234" id="1">
<name first="John" last="Doe"/>
<address>
<street>11 Main St.</street>
<city>San Francisco</city>
<state>CA</state>
<zip>98765</zip>
</address>
</employee>
<employee ssn="789-789-7890" id="2">
<name first="Mary" last="Roe"/>
<address>
<street>99 Broad St.</street>
<city>Newton</city>
<state>MA</state>
<zip>01234</zip>
</address>
</employee>
</employees>;

for each (var id:XML in employees.employee.@id) {
trace(id); // 123-123-1234
}

correct =
<employee ssn="789-789-7890" id="2">
<name first="Mary" last="Roe"/>
<address>
<street>99 Broad St.</street>
<city>Newton</city>
<state>MA</state>
<zip>01234</zip>
</address>
</employee>;

var idToFind:String = "2";
AddTestCase("employees.employee.(@id == idToFind)", correct, (employees.employee.(@id == idToFind)));


END();
