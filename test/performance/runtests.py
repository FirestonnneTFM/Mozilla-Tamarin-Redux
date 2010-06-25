#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# -*- Mode: Python; indent-tabs-mode: nil -*-
# vi: set ts=4 sw=4 expandtab:

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

import os, sys, getopt, datetime, pipes, glob, itertools, tempfile, string, re, platform, traceback
import subprocess, math
from math import sqrt
from os.path import *
from os import getcwd,environ,walk
from datetime import datetime
from glob import glob
from sys import argv, exit
from getopt import getopt
from itertools import count
from time import time
from socket import *

# add parent dir to python module search path
sys.path.append('..')

try:
    from util.runtestBase import RuntestBase
    from util.runtestUtils import *
except ImportError:
    print "Import error.  Please make sure that the test/acceptance/util directory has been deleted."
    print "   (directory has been moved to test/util)."

class PerformanceRuntest(RuntestBase):
    avm2 = ''
    avmname = ''
    avmDefaultName = 'avm'
    avm2DefaultName = 'avm2'
    avm2name = ''
    iterations = 1
    vmname = 'unknown'  # name sent to socketserver
    memory = False
    avmrevision = ''
    avm2version = ''
    avm2revision = ''
    detail = False
    vmargs2 = ''
    optimize = True
    perfm = False
    tmpfile = None
    osName = ''
    logresults = False
    socketlogFile = None
    serverHost = '10.60.48.47'
    serverPort = 1188
    finalexitcode=0
    prettyprint = False
    currentMetric = ''
    testFieldLen = 30   # field length for test name and path

    def __init__(self):
        RuntestBase.__init__(self)

    def run(self):
        self.setEnvironVars()
        self.loadPropertiesFile()
        self.setOptions()
        self.parseOptions()
        self.altsearchpath='../../other-licenses/test/performance/'
        self.setTimestamp()
        self.checkPath(['avm2'])
        self.determineOS()
        self.tests = self.getTestsList(self.args)
        # Load the root testconfig file
        self.settings, self.includes = self.parseTestConfig('.')
        # Load root .asc_args and .java_args files
        self.parseRootConfigFiles()
        self.preProcessTests()
        self.printHeader()
        self.runTests(self.tests)
        #self.cleanup()

    def setEnvironVars(self):
        RuntestBase.setEnvironVars(self)
        if 'AVM2' in environ:
            self.avm2 = environ['AVM2'].strip()
        if 'VMARGS2' in environ:
            self.vmargs2 = environ['VMARGS2'].strip()


    def usage(self, c):
        RuntestBase.usage(self, c)
        print " -S --avm2          second avmplus command to use"
        print "    --avmname       nickname for avm to use as column header"
        print "    --avm2name      nickname for avm2 to use as column header"
        print "    --detail        output with more details about each run"
        print " -i --iterations    number of times to repeat test"
        print " -l --log           logs results to a file"
        print " -k --socketlog     logs results to a socket server"
        print " -r --runtime       name of the runtime VM used, including switch info eg. TTVMi (tamarin-tracing interp)"
        print " -m --memory        logs the high water memory mark"
        print "    --aotsdk        location of the AOT sdk used to compile tests to standalone executables."
        print "    --aotout        where the resulting binaries should be put (defaults to the location of the as file)."
        print "    --aotargs       any extra arguments to pass to compile.py."
        print "    --vmversion     specify vmversion e.g. 502, use this if cannot be calculated from executable"
        print "    --vm2version    specify version of avm2"
        print "    --vmargs2       args to pass to avm2, if not specified --vmargs will be used"
        print "    --nooptimize    do not optimize files when compiling"
        print "    --perfm         parse the perfm results from avm"
        print "    --csv           output in csv format"
        print " -p --prettyprint   enhanced terminal coloring"
        exit(c)

    def setOptions(self):
        RuntestBase.setOptions(self)
        self.options += 'S:i:lkr:mp'
        self.longOptions.extend(['avm2=','avmname=','avm2name=','iterations=','log','socketlog',
                                 'runtime=','memory','larger','vmversion=', 'vm2version=','vmargs2=','nooptimize',
                                 'perfm','csv','prettyprint', 'detail'])

    def parseOptions(self):
        opts = RuntestBase.parseOptions(self)
        for o, v in opts:
            if o in ('-S', '--avm2'):
                self.avm2 = v
            elif o in ('--avmname',):
                self.avmname = v
            elif o in ('--avm2name',):
                self.avm2name = v
            elif o in ('-i', '--iterations'):
                self.iterations = int(v)
            elif o in ('-l','--log'):
                self.logFileType='log'
                self.createOutputFile()
            elif o in ('-k', '--socketlog'):
                self.logresults = True
            elif o in ('-r', '--runtime'):
                self.vmname = v
            elif o in ('-m', '--memory'):
                self.memory = True
            elif o in ('--aotsdk'):
                self.aotsdk = v
            elif o in ('--aotout'):
                self.aotout = v
            elif o in ('--aotargs'):
                self.aotextraargs = v
            elif o in ('--vmversion',):
                self.avmversion = v
            elif o in ('--vm2version',):
                self.avm2version = v
            elif o in ('--vmargs2',):
                self.vmargs2 = v
            elif o in ('--nooptimize',):
                self.optimize = False
            elif o in ('--perfm',):
                self.perfm = True
            elif o in ('--csv',):
                self.csv = True
            elif o in ('-p', '--prettyprint'):
                self.prettyprint = True
            elif o in ('--detail',):
                print 'self.detail = True'
                self.detail = True

    def compile_test(self, as_file):
        if not isfile(self.shellabc):
            exit("ERROR: shell.abc %s does not exist, SHELLLABC environment variable or --shellabc must be set to shell.abc" % self.shellabc)
        args = []
        args.append('-import %s' % self.shellabc)
        if self.optimize:
            args.append('-optimize -AS3')
        debugoutput = []
        RuntestBase.compile_test(self, as_file, args, debugoutput)
        self.printOutput(None, debugoutput)
        RuntestBase.compile_aot(self, splitext(as_file)[0] + ".abc")

    def formatExceptionInfo(maxTBlevel=5):
        cla, exc, trbk = sys.exc_info()
        excName = cla.__name__
        try:
            excArgs = exc.__dict__["args"]
        except KeyError:
            excArgs = "<no args>"
        excTb = traceback.format_tb(trbk, maxTBlevel)
        return (excName, excArgs, excTb)


    def socketlog(self, msg):
        if self.logresults:
            if not self.socketlogFile:
                file="socketlog-%s.txt" % self.avmversion
                ctr=0
                while os.path.exists(file):
                    ctr += 1
                    file = "socketlog-%s-%s.txt" % (self.avmversion,ctr)
                self.socketlogFile=file
            open(self.socketlogFile,'a').write(msg)
            try:
                s = socket(AF_INET, SOCK_STREAM)    # create a TCP socket
                s.connect((self.serverHost, self.serverPort)) # connect to server on the port
                s.send("%s;exit\r\n" % msg)         # send the data
                data = s.recv(1024)
                #print('Sent: %s' % msg)
                #print('Received: %s \n\n' % data)
                #s.shutdown(SHUT_RDWR)
                s.close()
            except :
                print("Socket error occured:")
                print(sys.exc_info())
                print('buildbot_status: WARNINGS')

    def parsePerfm(self, line,dic):
        try:
            result = line.strip().split(' ')[-2]
            if 'verify & IR gen' in line:
                dic['verify'].append(int(result))
            elif 'code ' in line:
                dic['code'].append(int(result))
            elif 'compile ' in line:
                dic['compile'].append(int(result))
            elif ('IR-bytes' in line) or ('mir bytes' in line):
                dic['irbytes'].append(int(result))
            elif ('IR ' in line) or ('mir ' in line): #note trailing space
                dic['ir'].append(int(result))
                dic['count'].append(int(line.strip().split(' ')[-1]))
        except:
            pass

    def preProcessTests(self):
        'Code that must be executed before beginning a testrun'
        if not self.aotsdk:
            self.checkExecutable(self.avm, 'AVM environment variable or --avm must be set to avmplus')
            if not self.avmversion:
                self.avmversion = self.getAvmVersion(self.avm)
            if not self.avmrevision:
                self.avmrevision = self.getAvmRevision(self.avmversion)
            if self.avm2:
                self.checkExecutable(self.avm2, '--avm2 must be set to avmplus')
                if not self.avm2version:
                    self.avm2version = self.getAvmVersion(self.avm2)
                if not self.avm2revision:
                    self.avm2revision = self.getAvmRevision(self.avm2version)


    def printHeader(self):
        'Print run info and headers'
        self.js_print('Executing %d test(s)' % len(self.tests), overrideQuiet=True, csv=False)
        self.js_print("%s: %s %s version: %s" % (self.avmname or self.avmDefaultName, self.avm, self.vmargs, self.avmversion))
        if self.avm2:
            self.js_print("%s: %s %s version: %s" % (self.avm2name or self.avm2DefaultName, self.avm2, self.vmargs2, self.avm2version))
        self.avmDefaultName += ':'+self.avmrevision
        self.js_print('iterations: %s' % self.iterations)
        if self.avm2:
            self.avm2DefaultName += ':'+self.avm2revision
            if self.iterations == 1:
                self.js_print('\n%-*s %5s %7s %7s\n' % (self.testFieldLen, 'test', self.avmname or self.avmDefaultName,
                                                        self.avm2name or self.avm2DefaultName, '%diff'))
            else:
                if self.memory:
                    self.js_print('Note that %diff is calculated using the largest memory value (not avg) from all runs', csv=False)
                else:
                    self.js_print('Note that %diff is calculated using the fastest value (not avg) of all runs', csv=False)
                if self.detail:
                    self.js_print('\n%-*s %-33s %-33s' % (self.testFieldLen, '', self.avmname or self.avmDefaultName, self.avm2name or self.avm2DefaultName))
                    self.js_print('%-*s  %7s :%7s  %7s %6s    %7s :%7s  %7s %6s %7s %8s %8s' % (self.testFieldLen, 'test', 'min','max','avg','stdev','min','max','avg','stdev','%diff','sig  ','metric'))
                    self.js_print('%*s ---------------------------------   ---------------------------------   -----  --------  ------' % (self.testFieldLen, '') )
                else:
                    self.js_print('\n%-*s   %-13s %s' % (self.testFieldLen, '',
                                                         self.avmname or self.avmDefaultName,
                                                         self.avm2name or self.avm2DefaultName))
                    self.js_print('%-*s %6s %6s %6s %6s %6s %4s' % (self.testFieldLen, 'test', 'best','avg','best','avg','%diff','sig'))
        else:
            if (self.iterations>2):
                runFormatStr = ''
                if self.csv:
                    for i in range(1,self.iterations+1):
                        runFormatStr += '%7s' % 'run'+str(i)
                self.js_print(("\n\n%-*s %5s %7s "+runFormatStr+"\n") % (self.testFieldLen, "test",self.avmname or self.avmDefaultName,"95%_conf"))
            else:
                self.js_print("\n\n%-*s %7s \n" % (self.testFieldLen, "test", self.avmname or self.avmDefaultName))


    def runTests(self, testList):
        testnum = len(testList)
        for t in testList:
            testnum -= 1
            o = self.runTest((t, testnum))

    def parseMemHigh(self, line):
        memoryhigh = 0
        tokens=line.rsplit()
        if len(tokens)>4:
            _mem=tokens[3]
            if _mem.startswith('('):
                _mem=_mem[1:]
            if _mem.endswith(')'):
                _mem=_mem[:-1]
            if _mem.endswith('M'):
                val=float(_mem[:-1])*1024
            else:
                val=float(_mem[:-1])
            if val>memoryhigh:
                memoryhigh=val
        return memoryhigh

    def loadTestSettings(self, dir, testname):
        settings = {}
        includes = self.includes #list

        # get settings for this test (from main testconfig file loaded into self.settings)
        for k in self.settings.keys():
            if re.search('^'+k+'$', testname):
                for k2 in self.settings[k].keys():
                    if k2 in settings:
                        settings[k2].update(self.settings[k][k2])
                    else:
                        settings[k2] = self.settings[k][k2].copy()


        if isfile(join(dir,self.testconfig)):
            localIncludes, localSettings = self.parseTestConfig(dir)
            # have a local testconfig, so we create a copy of the global settings to not overwrite
            includes = list(self.includes) #copy list - don't use reference
            includes.extend(localIncludes)
            if localSettings.has_key(testname):
                settings.update(localSettings[testname])

        return settings, includes

    def parsePerfTestOutput(self, output, resultList, perfmDict):
        metric = ''
        for line in output:
            if self.memory:
                if '[mem]' in line and 'private' in line:
                    memoryhigh = self.parseMemHigh(line)
            elif 'metric' in line:
                rl=[]
                rl=line.rsplit()
                if len(rl)>2:
                    if '.' in rl[2]:
                        resultList.append(float(rl[2]))
                    else:
                        resultList.append(int(rl[2]))
                    metric=rl[1]
            elif self.perfm:
                self.parsePerfm(line, perfmDict)
        if self.memory:
            metric="memory"
            resultList.append(memoryhigh)
        return metric

    def calculateSpeedup(self, resultList, resultList2, largerIsFaster):
        spdup = 9999
        result1 = result2 = 0
        memoryhigh = memoryhigh2 = 0
        if largerIsFaster:
            result1 = max(resultList)
            if resultList2:
                result2 = max(resultList2)
        else:
            result1 = min(resultList)
            if resultList2:
                result2 = min(resultList2)
        if self.memory:
            memoryhigh = max(resultList)
            if self.avm2:
                memoryhigh2 = max(resultList2)
                if memoryhigh<=0:
                    spdup = 9999
                else:
                    spdup = ((memoryhigh2-memoryhigh)/memoryhigh)*100.0
        elif self.avm2:
            if result1==0 or result2==0:
                spdup = 9999
            else:
                if largerIsFaster:
                    spdup = float(result2-result1)/result1*100.0
                else:
                    spdup = float(result1-result2)/result1*100.0
        return spdup, result1, result2, memoryhigh, memoryhigh2

    def perfmOutput(self, perfm1Dict, perfm2Dict):
        def calcPerfm(desc, key):
        # calculate min, max, average and %diff of averages
            try:
                if self.iterations == 1:
                    self.js_print( '     %-45s %7s %7s %7.1f' % (desc, perfm1Dict[key][0], perfm2Dict[key][0],
                                ((perfm1Dict[key][0]-perfm2Dict[key][0])/float(perfm2Dict[key][0])*100.0)))
                else:
                    avg1 = sum(perfm1Dict[key])/len(perfm1Dict[key])
                    avg2 = sum(perfm2Dict[key])/len(perfm2Dict[key])
                    self.js_print('     %-45s [%7s :%7s] %7s   [%7s :%7s] %7s %7.1f' % (desc, min(perfm1Dict[key]), max(perfm1Dict[key]), avg1,
                                                                 min(perfm2Dict[key]), max(perfm2Dict[key]), avg2,
                                                                 ((avg1-avg2)/float(avg2))*100.0))
            except:
                pass

        calcPerfm('verify & IR gen (time)','verify')
        calcPerfm('compile (time)','compile')
        calcPerfm('code size (bytes)','code')
        calcPerfm('mir/lir bytes', 'irbytes')
        calcPerfm('mir/lir (# of inst)', 'ir')
        calcPerfm('count', 'count')
        self.js_print('-------------------------------------------------------------------------------------------------------------')

    def perfmLog(self, config, perfm1Dict, perfm2Dict):
        #calc confidence and mean for each stat
        def perfmSocketlog(metric,key):
            self.socketlog("addresult2::%s::%s::%s::%0.1f::%s::%s::%s::%s::%s::%s;" %
                   (testName, metric,min(perfm1Dict[key]), conf95(perfm1Dict[key]), mean(perfm1Dict[key]), self.iterations, self.osName.upper(), config, self.avmrevision, self.vmname))
        perfmSocketlog('vprof-compile-time','compile')
        perfmSocketlog('vprof-code-size','code')
        perfmSocketlog('vprof-verify-time','verify')
        perfmSocketlog('vprof-ir-bytes','irbytes')
        perfmSocketlog('vprof-ir-time','ir')
        perfmSocketlog('vprof-count','count')


    def abnormalExit(self, explanation, extraOutput=[]):
        'Print out explanation for exiting and exit w/ exitcode 1'
        print 'Abnormal Exit!!'
        print explanation
        for line in extraOutput:
            print(line.strip())
        sys.exit(1)

    def checkForMetricChange(self, metric, largerIsFaster):
        'If the test metric has changed, print out a line indicating so'
        if self.currentMetric != metric:
            self.currentMetric = metric
            self.js_print('Metric: %s %s' % (metric, ('('+largerIsFaster+')') if largerIsFaster else '') )

    def getSigString(self, sig, spdup):
        'generate a string of +/- to give a quick visual representation of the perf difference'
        return '--' if (sig < -2.0 and spdup < -5.0) else '- ' if sig < -1.0 \
            else '++' if (sig > 2.0 and spdup > 5.0) else '+ ' if sig > 1.0 else '  '


    def truncateTestname(self, testName):
        'Return testName truncated to self.testFieldLen'
        return testName if len(testName) <= self.testFieldLen else testName[(len(testName) - self.testFieldLen):]

    def runTest(self, testAndNum):
        'Run a singe performance testcase self.iterations times and print out results'
        ast = testAndNum[0]
        testName = ast

        # strip off ./ as test is then treated differently in perf db
        if testName[:2] == './':
            testName = testName[2:]
        if self.altsearchpath!=None and ast.startswith(self.altsearchpath):
            testName = ast[len(self.altsearchpath):]
        testnum = testAndNum[1]

        if ast.startswith("./"):
            ast=ast[2:]
        dir =ast[0:ast.rfind('/')]
        root,ext = splitext(ast)
        tname = root[root.rfind('/')+1:]
        abc = "%s.abc" % root

        settings, includes = self.loadTestSettings(dir, root)

        #TODO: possibly handle includes by building test list?  This works for now...
        if includes and not list_match(includes,root):
            return

        if settings.has_key('.*') and settings['.*'].has_key('skip'):
            self.verbose_print('  skipping %s' % testName)
            self.allskips += 1
            return

        if settings.has_key('.*') and settings['.*'].has_key('largerValuesFaster'):
            largerIsFaster = 'largerValuesFaster'
        else:
            largerIsFaster = ''

        self.verbose_print("%d running %s" % (testnum, testName));
        if self.forcerebuild and isfile(abc):
            os.unlink(abc)
        if isfile(abc) and getmtime(ast)>getmtime(abc):
            self.verbose_print("%s has been modified, recompiling" % ast)
            os.unlink(abc)
        if not isfile(abc):
            self.compile_test(ast)
            if not isfile(abc):
                self.js_print("compile FAILED!, file not found " + abc)

        # determine current config
        config = "%s" % self.vmargs.replace(" ", "")
        config = "%s" % config.replace("\"", "")
        if config.find("-memlimit")>-1:
            config=config[0:config.find("-memlimit")]

        result1=9999999
        result2=9999999
        resultList=[]
        resultList2=[]
        if self.memory and self.vmargs.find("-memstats")==-1:
            self.vmargs="%s -memstats" % self.vmargs
        if self.memory and len(self.vmargs2)>0 and self.vmargs2.find("-memstats")==-1:
            self.vmargs2="%s -memstats" % self.vmargs2

        # setup dictionary for vprof (perfm) results
        perfm1Dict = {'verify':[], 'code':[], 'compile':[], 'irbytes':[], 'ir':[], 'count':[] }
        perfm2Dict = {'verify':[], 'code':[], 'compile':[], 'irbytes':[], 'ir':[], 'count':[] }

        for i in range(self.iterations):
            if self.aotsdk and self.aotout:
                progname = string.replace(testName, ".as", "")
                progname = string.replace(progname, "/", ".")
                (f1,err,exitcode) = self.run_pipe(os.path.join(self.aotout, progname))
                # print "about to execute: " + os.path.join(self.aotout, progname)
                exitcode = 0 # hack!
            else:
                (f1,err,exitcode) = self.run_pipe("%s %s %s" % (self.avm, self.vmargs, abc))
                self.debug_print("%s %s %s" % (self.avm, self.vmargs, abc))
                self.debug_print(f1)
            if self.avm2:
                (f2,err2,exitcode2) = self.run_pipe("%s %s %s" % (self.avm2, self.vmargs2 if self.vmargs2 else self.vmargs, abc))
                self.debug_print("%s %s %s" % (self.avm2, self.vmargs2 if self.vmargs2 else self.vmargs, abc))
                self.debug_print(f2)
            try:
                if exitcode!=0:
                    self.finalexitcode=1
                    self.js_print("%-50s %7s %s" % (testName,'Avm1 Error: Test Exited with exit code:', exitcode))
                    return
                else:
                    metric = self.parsePerfTestOutput(f1, resultList, perfm1Dict)
                if self.avm2:
                    if exitcode2!=0:
                        self.finalexitcode=1
                        self.js_print("%-50s %7s %s" % (testName,'Avm2 Error: Test Exited with exit code:', exitcode))
                        return
                    else:
                        self.parsePerfTestOutput(f2, resultList2, perfm2Dict)
            except:
                print self.formatExceptionInfo()
                exit(-1)
        # end for i in range(iterations)

        if len(resultList)!=self.iterations:
            # something went wrong, dump output
            self.abnormalExit('avm resultlist: %s is not the same length as the # of iterations (%s)' % (resultList, self.iterations), f1)
        if self.avm2 and (len(resultList2) != self.iterations):
            self.abnormalExit('avm2 resultlist: %s is not the same length as the # of iterations (%s)' % (resultList2, self.iterations), f2)

        # calculate best result
        spdup, result1, result2, memoryhigh, memoryhigh2 = self.calculateSpeedup(resultList, resultList2, largerIsFaster)

        if self.memory:
            if self.avm2:
                if self.iterations == 1:
                    self.checkForMetricChange(metric, largerIsFaster)
                    self.js_print('%-*s %5s %7s %7.1f' %
                                  (self.testFieldLen, self.truncateTestname(testName),
                                   formatMemory(memoryhigh),formatMemory(memoryhigh2),
                                   spdup))
                else:
                    mem1_avg = formatMemory(sum(resultList)/float(len(resultList)))
                    mem2_avg = formatMemory(sum(resultList2)/float(len(resultList2)))
                    relStdDev1 = rel_std_dev(resultList)
                    relStdDev2 = rel_std_dev(resultList2)
                    try:
                        sig = spdup / (relStdDev1+relStdDev2)
                    except ZeroDivisionError:
                        sig = cmp(spdup,0) * (3.0 if abs(spdup) > 5.0 else 2.0 if abs(spdup) > 1.0 else 0.0)
                    sig_str = self.getSigString(sig, spdup)
                    bold = '\033[1m' if (abs(sig)>1.0 and self.prettyprint) else ''
                    endbold = '\033[0;0m' if bold else ''
                    if self.detail:
                        self.js_print('%s%-50s [%7s :%7s] %7s ±%4.1f%%   [%7s :%7s] %7s ±%4.1f%% %6.1f%% %6.1f %2s %7s %s%s' %
                                      (bold,testName,formatMemory(min(resultList)),formatMemory(memoryhigh),mem1_avg,
                                        rel_std_dev(resultList), formatMemory(min(resultList2)),
                                        formatMemory(memoryhigh2),mem2_avg,rel_std_dev(resultList2),
                                        spdup, sig, sig_str, metric, largerIsFaster,endbold) )
                    else:
                        self.checkForMetricChange(metric, largerIsFaster)
                        self.js_print('%s%-*s %6s %6s %6s %6s %6s % 3.1f %2s%s' %
                                      (bold,self.testFieldLen, self.truncateTestname(testName),
                                       formatMemory(min(resultList)), mem1_avg,
                                       formatMemory(min(resultList2)), mem2_avg,
                                       format(spdup,'3.1f') if abs(spdup) < 1000 else int(spdup),
                                       sig, sig_str, endbold) )
            else:
                confidence=0
                meanRes=memoryhigh
                if self.iterations>2:
                    meanRes=mean(resultList)
                    if meanRes>0:
                        confidence = ((tDist(len(resultList)) * standard_error(resultList) / meanRes) * 100)
                    runResults = ''
                    for i in range(self.iterations):
                        runResults += '%8s' % formatMemory(resultList[i])
                    self.js_print(("%-50s %7s %10.1f%%  %7s "+runResults) % (testName,formatMemory(memoryhigh),confidence, "memory"))
                else:
                    self.js_print("%-50s %7s %7s" % (testName,formatMemory(memoryhigh), metric))
                config = config.replace("-memstats","")
                self.socketlog("addresult2::%s::%s::%s::%0.1f::%s::%s::%s::%s::%s::%s;" % (testName, metric, memoryhigh, confidence, meanRes, self.iterations, self.osName.upper(), config, self.avmrevision, self.vmname))
        else:
            if self.avm2:
                if self.iterations == 1:
                    self.checkForMetricChange(metric, largerIsFaster)
                    self.js_print('%-*s %5s %7s %6.1f' % (self.testFieldLen, self.truncateTestname(testName),result1,result2,spdup))
                else:
                    try:
                        rl1_avg=sum(resultList)/float(len(resultList))
                        rl2_avg=sum(resultList2)/float(len(resultList2))
                        min1 = float(min(resultList))
                        min2 = float(min(resultList2))
                        max1 = float(max(resultList))
                        max2 = float(max(resultList2))
                        relStdDev1 = rel_std_dev(resultList)
                        relStdDev2 = rel_std_dev(resultList2)
                        try:
                            if largerIsFaster:
                                spdup = 100.0*(max2-max1)/max1
                                best1 = max1
                                best2 = min2
                            else:
                                spdup = 100.0*(min1-min2)/min1
                                best1 = min1
                                best2 = min2
                        except ZeroDivisionError:
                            spdup = 9999
                        try:
                            sig = spdup / (relStdDev1+relStdDev2)
                        except ZeroDivisionError:
                            # determine sig by %diff (spdup) only
                            sig = cmp(spdup,0) * (3.0 if abs(spdup) > 5.0 else 2.0 if abs(spdup) > 1.0 else 0.0)
                        sig_str = self.getSigString(sig, spdup)
                        # only bold if abs > 1 and averages are > 3 ms apart
                        bold = '\033[1m' if (abs(sig)>1.0 and abs(rl1_avg-rl2_avg) > 3 and self.prettyprint) else ''
                        endbold = '\033[0;0m' if bold else ''
                        if self.detail:
                            self.js_print('%s%-*s [%7s :%7s] %7.1f ±%4.1f%%   [%7s :%7s] %7.1f ±%4.1f%% %6.1f%% %6.1f %2s %7s %s%s' %
                                          (bold, self.testFieldLen, self.truncateTestname(testName), min1, max1, rl1_avg, relStdDev1,
                                           min2, max2, rl2_avg, relStdDev2,
                                           spdup, sig,sig_str, metric, largerIsFaster,endbold))
                        else:
                            self.checkForMetricChange(metric, largerIsFaster)
                            self.js_print('%s%-*s %6s %6s %6s %6s %6s % 3.1f %2s%s' %
                                          (bold,
                                           self.testFieldLen,
                                           self.truncateTestname(testName),
                                           int(best1) if best1 == int(best1) else best1,
                                           format(rl1_avg, '6.1f') if rl1_avg < 10000 else int(rl1_avg) ,
                                           int(best2) if best2 == int(best2) else best2,
                                           format(rl2_avg, '6.1f') if rl2_avg < 10000 else int(rl2_avg),
                                           format(spdup,'3.1f') if abs(spdup) < 1000 else int(spdup),
                                           sig,
                                           sig_str, endbold))
                    except:
                        import traceback
                        traceback.print_exc()
                if self.perfm and perfm1Dict['verify']: # only calc if data present
                    self.perfmOutput(perfm1Dict, perfm2Dict)
            else: # only one avm tested
                if result1 < 9999999:   # TODO: would be nice to not rely on arbitrary number to determine if results are valid
                    meanRes = mean(resultList)
                    if (self.iterations > 2):
                        confidence = conf95(resultList)
                        if self.perfm and perfm1Dict['verify']:  #send vprof results to db
                                self.perfmLog(config, perfm1Dict, perfm2Dict)
                        self.socketlog("addresult2::%s::%s::%s::%0.1f::%s::%s::%s::%s::%s::%s;" % (ast, metric, result1, confidence, meanRes, self.iterations, self.osName.upper(), config, self.avmrevision, self.vmname))
                        runResults = ''
                        if self.csv:
                            for i in range(self.iterations):
                                runResults += '%8s' % resultList[i]
                        else:
                            runResults = str(resultList)
                        self.checkForMetricChange(metric, largerIsFaster)
                        self.js_print(("%-*s %5s %4.1f%% "+runResults) % (self.testFieldLen, self.truncateTestname(ast),result1,confidence))
                    else: #one iteration
                        self.checkForMetricChange(metric, largerIsFaster)
                        self.js_print("%-*s %7s" % (self.testFieldLen, self.truncateTestname(testName),result1))
                else:
                        self.js_print("%-*s %5s %s" % (self.testFieldLen, truncateTestname(testName),'no test result - test output: ',f1))
                        self.finalexitcode=1



runtest = PerformanceRuntest()
exit(runtest.finalexitcode)
