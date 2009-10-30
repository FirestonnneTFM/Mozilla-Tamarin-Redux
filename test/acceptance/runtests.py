#!/usr/bin/env python
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
# The Original Code is [Open Source Virtual Machine.].
#
# The Initial Developer of the Original Code is
# Adobe System Incorporated.
# Portions created by the Initial Developer are Copyright (C) 2005-2009
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#   christine@netscape.com
#   Adobe AS3 Team
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
# ***** END LICENSE BLOCK ***** */
#

import os, sys, getopt, datetime, pipes, glob, itertools, tempfile, string, re, platform
from os.path import *
from os import getcwd,environ,walk
from datetime import datetime
from glob import glob
from sys import argv, exit
from getopt import getopt
from itertools import count
from subprocess import Popen, PIPE,STDOUT
from time import time

# add parent dir to python module search path
sys.path.append('..')

try:
    from util.runtestBase import RuntestBase
except ImportError:
    print "Import error.  Please make sure that the test/acceptance/util directory has been deleted."
    print "   (directory has been moved to test/util)."

class AcceptanceRuntest(RuntestBase):
    runESC = False
    escbin = '../../esc/bin/'
    

    def __init__(self):
        # Set threads to # of available cpus/cores
        self.threads = self.detectCPUs()
        RuntestBase.__init__(self)

    def setEnvironVars(self):
        RuntestBase.setEnvironVars(self)
        if 'ESCBIN' in environ:
            self.escbin = environ['ESCBIN'].strip()
        
    def usage(self, c):
        RuntestBase.usage(self, c)
        print '    --esc           run esc instead of avm'
        print '    --escbin        location of esc/bin directory - defaults to ../../esc/bin'
        print '    --ext           set the testfile extension (defaults to .as)'
        print '    --ats           generate ats swfs instead of running tests'
        print '    --atsdir        base output directory for ats swfs - defaults to ATS_SWFS'
        print '    --threads       number of threads to run (default=# of cpu/cores), set to 1 to have tests finish sequentially'
        print '    --verify        run a verify pass instead of running abcs'
        exit(c)
    
    def setOptions(self):
        RuntestBase.setOptions(self)
        self.longOptions.extend(['ext=','esc','escbin=','threads=','ats','atsdir=','verify'])
    
    def parseOptions(self):
        opts = RuntestBase.parseOptions(self)
        for o, v in opts:
            if o in ('--ext',):
                self.sourceExt = v
            elif o in ('--esc',):
                self.runESC = True
            elif o in ('--escbin',):
                self.escbin = v
            elif o in ('--threads',):
                self.threads=int(v)
            elif o in ('--ats',):
                self.genAtsSwfs = True
                self.rebuildtests = True
            elif o in ('--atsdir',):
                self.atsDir = v
            elif o in ('--verify',):
                self.verify = True
                self.vmargs = '-Dverifyall -Dverbose=verify'
    
    def detectCPUs(self):
        """
        Detects the number of CPUs on a system.
        """
        # Linux, Unix and MacOS:
        if hasattr(os, "sysconf"):
            if os.sysconf_names.has_key("SC_NPROCESSORS_ONLN"):
                # Linux & Unix:
                ncpus = os.sysconf("SC_NPROCESSORS_ONLN")
                if isinstance(ncpus, int) and ncpus > 0:
                    return ncpus
            else: # OSX:
                p = Popen("sysctl -n hw.ncpu", shell=True, close_fds=True, stdin=PIPE, stdout=PIPE)
                return int(p.stdout.read())
        # Windows:
        if os.environ.has_key("NUMBER_OF_PROCESSORS"):
            ncpus = int(os.environ["NUMBER_OF_PROCESSORS"]);
            if ncpus > 0:
                return ncpus
        return 1 # Default                

runtest = AcceptanceRuntest()