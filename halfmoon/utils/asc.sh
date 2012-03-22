#!/bin/bash
root=`hg root`
java -jar "$root/utils/asc.jar" -import "$root/generated/builtin.abc" $1

