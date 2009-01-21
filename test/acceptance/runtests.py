#!/usr/bin/env python

import os, sys, getopt, datetime, pipes, glob, itertools, tempfile, string, re, platform
from os.path import *
from os import getcwd,environ,walk
from datetime import datetime
from glob import glob
from sys import argv, exit
from getopt import getopt
from itertools import count
from subprocess import PIPE,STDOUT
from time import time

# add parent dir to python module search path
sys.path.append('..')

from util.runtestBase import RuntestBase

class AcceptanceRuntest(RuntestBase):
    runESC = False
    escbin = '../../esc/bin/'

    def __init__(self):
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
        print '    --threads       number of threads to run (default=1), set to 1 to have tests finish sequentially'
        exit(c)
    
    def setOptions(self):
        RuntestBase.setOptions(self)
        # self.options += ''
        self.longOptions.extend(['ext=','esc','escbin=','threads='])
    
    def parseOptions(self):
        opts = RuntestBase.parseOptions(self)
        for o, v in opts:
            if o in ('--ext'):
                self.sourceExt = v
            elif o in ('--esc'):
                self.runESC = True
            elif o in ('--escbin'):
                self.escbin = v
            elif o in ('--threads'):
                self.threads=int(v)

runtest = AcceptanceRuntest()