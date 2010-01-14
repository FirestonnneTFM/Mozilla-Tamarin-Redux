#! /usr/bin/python
#  ***** BEGIN LICENSE BLOCK *****
#  Version: MPL 1.1/GPL 2.0/LGPL 2.1
# 
#  The contents of this file are subject to the Mozilla Public License Version
#  1.1 (the "License"); you may not use this file except in compliance with
#  the License. You may obtain a copy of the License at
#  http://www.mozilla.org/MPL/
# 
#  Software distributed under the License is distributed on an "AS IS" basis,
#  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
#  for the specific language governing rights and limitations under the
#  License.
# 
#  The Original Code is [Open Source Virtual Machine.].
# 
#  The Initial Developer of the Original Code is
#  Adobe System Incorporated.
#  Portions created by the Initial Developer are Copyright (C) 2009
#  the Initial Developer. All Rights Reserved.
# 
#  Contributor(s):
#    Adobe AS3 Team
# 
#  Alternatively, the contents of this file may be used under the terms of
#  either the GNU General Public License Version 2 or later (the "GPL"), or
#  the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
#  in which case the provisions of the GPL or the LGPL are applicable instead
#  of those above. If you wish to allow use of your version of this file only
#  under the terms of either the GPL or the LGPL, and not to allow others to
#  use your version of this file under the terms of the MPL, indicate your
#  decision by deleting the provisions above and replace them with the notice
#  and other provisions required by the GPL or the LGPL. If you do not delete
#  the provisions above, a recipient may use your version of this file under
#  the terms of any one of the MPL, the GPL or the LGPL.
# 
#  ***** END LICENSE BLOCK ****

# This is a script which delivers Change events from Mercurial to the
# buildmaster each time a changeset is pushed into a repository. Add it to
# the 'incoming' commit hook on your canonical "central" repository, by
# putting something like the following in the .hg/hgrc file of that
# repository:
#
#  [hooks]
#  incoming.buildbot = /PATH/TO/hg_buildbot_trigger.py SCP_UPLOAD_DESTINATION
#
# Note that both Buildbot and Mercurial must be installed on the repository
# machine.

import os, sys, commands
from StringIO import StringIO
from buildbot.scripts import runner


if len(sys.argv)==2:
        print("ERROR: must pass scp upload destination as parameter")
        sys.exit(1)
DESTINATION = sys.argv[1]
PRIORITY = sys.argv[2]


revision=''
if os.environ.has_key("HG_NODE"):
    revision = os.environ["HG_NODE"]
if revision == '':
    print("ERROR: unknown revision")
    sys.exit(1)



# TODO: consider doing 'import mercurial.hg' and extract this information
# using the native python
out = commands.getoutput("hg -v log -r %s" % revision)

print("hg -v log:\n%s" % out)

# Find the revision
s = StringIO(out)
while True:
    line = s.readline()
    if not line:
        break
    if line.startswith("changeset:"):
        revision = line[line.find(":")+1:].strip().replace(":","-")

showconfig = commands.getoutput("hg showconfig")
url = ''
# Find the path.default
s = StringIO(showconfig)
while True:
    line = s.readline()
    if not line:
        break
    if line.startswith("paths.default="):
        url = line[line.find("=")+1:].strip()

# Write out a file that contains the output from "hg log"
filename = "change-%s.%s" % (revision,PRIORITY)

changefile = open("/var/log/%s" % filename, "w")
changefile.write("url:         %s\n" % url)
s = StringIO(out)
while True:
    line = s.readline()
    if not line:
        break
    if line.startswith("files:"):
        orig = line[line.find(":")+1:].strip()
        changefile.write("files:       %s\n" % filename)
    elif line.startswith("description:"):
        changefile.write(line)
        changefile.write("%s\n\n" % orig)
    else:
        changefile.write(line)

# Close the file
changefile.close()

# Copy the change file out to buildbot master host machine
scpcall = commands.getoutput("scp /var/log/%s %s/%s" % (filename, DESTINATION, filename))

# Remove the file as it is no longer needed
os.remove("/var/log/%s" % filename)
