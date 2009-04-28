#!/usr/bin/env python
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
from sys import argv
from platform import *
from socket import *
serverHost = '10.60.48.47'
serverPort = 1188
logresults=False
# ===========================================
# If logging is enabled, log results to 
# performance database
# ===========================================
def socketlog(msg):
    if logresults:
        s = socket(AF_INET, SOCK_STREAM)    # create a TCP socket
        s.connect((serverHost, serverPort)) # connect to server on the port
        s.send("%s;exit" % msg)             # send the data
        s.shutdown(SHUT_RDWR)
        s.close()

msg = ""
version=argv[1]
argv=argv[1:]
OS_name = {'CYGWIN_NT-5.2':'WIN','CYGWIN_NT-5.1':'WIN','Windows':'WIN','Darwin':'MAC','Linux':'LNX','Solaris':'SOL',}[system()]
VM_reporting = '%s %s %s' % ("esc",OS_name,version)
print(VM_reporting)
for a in argv:
    n=a.find("=")
    if (n>-1):
        msg+="addresult::esc::%s::%s::%s;" % ( a[:n],a[n+1:],VM_reporting)
        print(msg)
socketlog(msg)
