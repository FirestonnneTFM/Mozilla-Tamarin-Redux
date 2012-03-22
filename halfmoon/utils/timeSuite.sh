#!/bin/bash

root=`hg root`
test="$root/halfmoon/test"
utils="$root/halfmoon/utils"
rm -f "$test/benchmarkResults.csv"

find $test/benchmarks -name \*.abc | xargs rm

python "$utils/timeTestSuite.py" $1 "$root/utils/asc.jar" "$root/generated/builtin.abc" "$test/benchmarks"
