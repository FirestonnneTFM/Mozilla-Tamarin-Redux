#!/bin/bash

root=`hg root`

find "$root/halfmoon/test/sanity" -name '*.abc' | xargs rm
