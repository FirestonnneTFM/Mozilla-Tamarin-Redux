#!/usr/bin/env python
# -*- Mode: Python; indent-tabs-mode: nil -*-
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
# The Original Code is [Open Source Virtual Machine].
#
# The Initial Developer of the Original Code is
# Adobe System Incorporated.
# Portions created by the Initial Developer are Copyright (C) 2005-2006
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


"""Pipes stdin | stdout and extracts a list of all header dependencies to
a file.  It requires exactly three arguments.

The input is expected to take form of C preprocessor output, where
paths to originating input source files are indicated via the form
# LINENO "PATH"

The first argument to the script is the target file to be overwritten.
It will contain the extracted dependencies (unquoted paths).

The second argument is the preprocessor otuput file, this file will
be rewritten to have uniform path separators.
(Mixing of separators has caused issues with code coverage on windows
under cygwin, see bug 587151)

The third argument to the script is the path of an originating source
file.  It is used to resolve relative paths within the input.
(Relative paths are unusual, but can arise via manual #line directives
in the source code; e.g. see bug 477230.)"""

import re
import sys
import os

if len(sys.argv) != 4:
    raise Exception("Unexpected command line argument.")

outfile          = sys.argv[1]
ii_outfile       = sys.argv[2]
originating_file = sys.argv[3]

relative_to_dir  = os.path.dirname(originating_file)

# Need to also find dependencies that do not start at the begining of the line
_lineExp = re.compile("[ \t]*#(?:line)? ?\d+ \"([^\"<>]+[^/])\"");

deps = set()
_file=""

for line in sys.stdin:
    m = _lineExp.match(line)
    if m:
        path = m.group(1)
        if not os.path.isabs(path):
            path = os.path.abspath(os.path.join(relative_to_dir, path))
        deps.add(path)
        _file+=re.sub(r"\\\\", r"/", line)
    else:
        _file+=line
        
ostream = open(outfile, "w")
ostream.write("\n".join(deps))
ostream.close()

ostream = open(ii_outfile, "w")
ostream.write(_file)
ostream.close()
