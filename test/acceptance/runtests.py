#!/usr/bin/env python
# -*- Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5)
#
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

import os, sys, getopt, datetime, pipes, glob, itertools, tempfile, string
import re, platform, threading, time, copy
from os.path import *
from os import getcwd,environ,walk
from datetime import datetime
from glob import glob
from sys import argv, exit
from getopt import getopt
from itertools import count


# add parent dir to python module search path
sys.path.append('..')
from util.runtestBase import RuntestBase
# runtestUtils must be imported after "from os.path import *" as walk is overridden
from util.runtestUtils import *

class AcceptanceRuntest(RuntestBase):
    runESC = False
    escbin = '../../esc/bin/'
    passthreadid = False
    androidthreads = False
    androiddevices = []
    verifyonly = False
    swfversions = [9,10,11,12,13,14,15,16,17]
    apiversions = [12,13,14,15,16,17]

    def __init__(self):
        # Set threads to # of available cpus/cores
        self.threads = detectCPUs()
        RuntestBase.__init__(self)
    
    def __str__(self):
        return 'AcceptanceRuntest'

    def setEnvironVars(self):
        RuntestBase.setEnvironVars(self)
        if 'ESCBIN' in environ:
            self.escbin = environ['ESCBIN'].strip()

    def usage(self, c):
        RuntestBase.usage(self, c)
        print('    --esc           run esc instead of avm')
        print('    --escbin        location of esc/bin directory - defaults to ../../esc/bin')
        print('    --eval          use run-time compiler')
        print('    --ext           set the testfile extension (defaults to .as)')
        print('    --ats           generate ats swfs instead of running tests')
        print('    --atsdir        base output directory for ats swfs - defaults to ATS_SWFS')
        print('    --threads       number of threads to run (default=# of cpu/cores), set to 1 to have tests finish sequentially')
        print('    --passthreadid  set the environment variable threadid when calling the AVM script.  The threadid is an integer 0...n-1 where threads=n.')
        print('    --androidthreads    assign a thread for each android device connected.')
        print('    --verify        run a verify pass instead of running abcs')
        print('    --verifyonly    run a -Dverifyonly pass: only checks test exitcode')
        print('    --remoteip      IP/DNS address of the machine to run the tests on.')
        print('    --remoteuser    user name to use to connect to the remote machine.')
        exit(c)

    def setOptions(self):
        RuntestBase.setOptions(self)
        self.longOptions.extend(['ext=','esc','escbin=','eval','threads=','ats',
                                 'atsdir=','verify','verifyonly','androidthreads','passthreadid'])

    def parseOptions(self):
        opts = RuntestBase.parseOptions(self)
        for o, v in opts:
            if o in ('--ext',):
                self.sourceExt = v
            elif o in ('--esc',):
                self.runESC = True
            elif o in ('--escbin',):
                self.escbin = v
            elif o in ('--eval',):
                self.eval = True
            elif o in ('--passthreadid',):
                self.passthreadid=True
            elif o in ('--androidthreads',):
                self.androidthreads=True
                self.threads=1
            elif o in ('--threads',):
                try:
                    self.threads=int(v)
                except ValueError:
                    print('Incorrect threads value: %s\n' % v)
                    self.usage(2)
            elif o in ('--ats',):
                self.genAtsSwfs = True
                self.rebuildtests = True
                # Need to run single threaded since we create a temp file for
                # every test and this file can collide when using multiple threads
                self.threads = 1
            elif o in ('--atsdir',):
                self.atsDir = v
            elif o in ('--verify',):
                self.verify = True
                self.vmargs = '-Dverifyall -Dverbose=verify'
            elif o in ('--verifyonly',):
                self.verifyonly = True
                if '-Dverifyonly' not in self.vmargs:
                    self.vmargs += ' -Dverifyonly'
            elif o in ('--remoteip',):
                self.remoteip = v
            elif o in ('--remoteuser',):
                self.remoteuser = v

    def run(self):
        self.setEnvironVars()
        self.loadPropertiesFile()
        self.setOptions()
        self.parseOptions()
        self.setTimestamp()
        self.checkPath()
        if not self.config:
            self.determineConfig()
        if self.verifyonly and 'debugger' not in self.vmtype:
            exit('You must be running a debugger build in order to use the -Dverifyonly option')
        if self.rebuildtests==False and (re.search('arm-winmobile-emulator',self.config)!=None or self.osName=='winmobile'):
            if re.search('^arm-winmobile-emulator',self.config)==None:
                print('ERROR: to use windows mobile build set --config arm-winmobile-emulator-tvm-release or install cygwin utility /usr/bin/file.exe')
                sys.exit(1)
            self.setupCEEmulators()
        if self.htmlOutput and not self.rebuildtests:
            self.createOutputFile()
        # extension lists must be tuples
        self.otherTestExtensions = (self.abcasmExt,)
        self.executableExtensions = (self.abcOnlyExt,)
        
        # test configuration is contained in two files: failconfig & testconfig)
        self.settings, self.directives = self.parseTestConfig(self.testconfig)
        failconfig_settings, failconfig_directives = self.parseTestConfig(self.failconfig)
        self.settings.update(failconfig_settings)
        self.directives.update(failconfig_directives)
        
        self.tests = self.getTestsList(self.args)
        # Load root .asc_args and .java_args files
        self.parseRootConfigFiles()
        self.preProcessTests()
        if self.rebuildtests:
            self.rebuildTests()
        else:
            self.runTests(self.tests)
        self.cleanup()

    def preProcessTests(self):
        RuntestBase.preProcessTests(self)
        # Are we running esc - depends on a valid avm
        if self.runESC:
            self.runSource = True
            # generate the executable cmd for esc
            #escAbcs = [f for f in os.listdir(self.escbin) if f.endswith('.abc')] #not all abcs are used for esc
            escAbcs = ['debug','util','bytes-tamarin','util-tamarin','lex-char','lex-token',
                       'lex-scan','ast','ast-decode','parse','asm','abc','emit','cogen',
                       'cogen-stmt','cogen-expr','esc-core','eval-support','esc-env','main']
            if not self.escbin.endswith('/'):
                self.escbin += '/'
            for f in escAbcs:
                self.avm += ' %s%s.es.abc' % (self.escbin, f)
            self.avm += ' -- '
            self.avm += ' %s../test/spidermonkey-prefix.es' % self.escbin  #needed to run shell harness
        if self.androidthreads:
            p=subprocess.Popen('adb devices',shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
            (out,err)=p.communicate()
            out = out.decode('latin_1','replace')
            out = out.split('\n')
            for line in out:
                items=line.split()
                if len(items)==2 and items[1]=='device':
                    for i in range(self.threads):
                        self.androiddevices.append(items[0])
            if len(self.androiddevices)==0:
                print("error: adb did not detect any attached devices")
                print("adb devices stdout: %s stderr: %s" % (out,err))
                sys.exit(1)
            print("detected %d android devices" % (len(self.androiddevices)/self.threads))
            self.threads=len(self.androiddevices)
    
    def skip_test(self, ast, testnum, settings, key):
        '''Skip the given test, returns output_calls'''
        output_calls = []
        output_calls.append((self.js_print, ('%d running %s' % (testnum, ast),
                                             '<b>', '</b><br/>')))
        output_calls.append((self.js_print,('  skipping... reason: %s' %
                                            settings['.*'][key],)))
        self.allskips += 1
        return output_calls

    def exclude_test(self, ast, testnum, settings, key):
        '''Exclude the given test, returns output_calls'''
        output_calls = []
        output_calls.append((self.js_print, ('%d running %s' % (testnum, ast),
                                             '<b>', '</b><br/>')))
        output_calls.append((self.js_print,('  excluding... reason: %s' %
                                            settings['.*'][key],)))
        return output_calls
     
    def runTestPrep(self, testAndNum):
        ast = testAndNum[0]
        testnum = testAndNum[1]
        outputCalls = [] #queue all output calls so that output is written in a block
        extraVmArgs = ''
        abcargs = ''

        dir = os.path.split(ast)[0]
        root,ext = splitext(ast)
        if self.runSource or self.eval or ext in self.executableExtensions:
            testName = ast
        else:
            testName = root + '.abc'

        includes = self.includes #list

        settings = self.get_test_settings(root)

        # exclude entire test if specified
        if '.*' in settings and 'exclude' in settings['.*']:
            return self.exclude_test(ast, testnum, settings, 'exclude')

        # skip entire test if specified
        if '.*' in settings and 'skip' in settings['.*']:
            return self.skip_test(ast, testnum, settings, 'skip')
        
        # skip tests that can't be verified
        if self.verify and '.*' in settings and 'verify_skip' in settings['.*']:
            return self.skip_test(ast, testnum, settings, 'verify_skip')
            
        # Check for a timezone file
        if isfile('%s.tz' % ast):
            if not self.valid_time_zone(ast, testnum, outputCalls):
                return outputCalls
        
        # delete abc if forcerebuild
        if self.forcerebuild and isfile(testName) and ext not in self.executableExtensions:
            os.unlink(testName)
        if isfile(testName) and getmtime(ast)>getmtime(testName) and self.timestampcheck:
            outputCalls.append((self.verbose_print, ("%s has been modified, recompiling" % ast,)))
            os.unlink(testName)
        
        # process support dir
        if exists(root+self.supportFolderExt) and not (self.runSource or self.eval):
            self.compile_support_files(root+self.supportFolderExt, outputCalls)
        
        # compile file if needed
        if not isfile(testName):
            compileOutput = self.compile_test(ast, outputCalls=outputCalls)
            if not isfile(testName):
                if ast.endswith(self.abcasmExt):
                    # file didn't compile, compare compile output
                    flines = self.compareAbcAsmOutput(ast, compileOutput)
                    if flines:
                        self.allfails += 1
                        outputCalls.append((self.fail,(testName, 'FAILED! :\nExpected:\n'+''.join(flines)+'\nGOT:\n'+''.join(compileOutput), self.failmsgs)))
                        outputCalls.append((self.js_print, ('   FAILED passes: 0 fails: 1 unexpected passes: 0 expected failures: 0', '', '<br/>')))
                    else:
                        self.allpasses += 1
                        outputCalls.append((self.verbose_print, ('   PASSED passes: 1 fails: 0 unexpected passes: 0 expected failures: 0', '', '<br/>')))
                    outputCalls.insert(0,(self.js_print,('%d running %s' % (testnum, ast), '<b>', '</b><br/>')));
                    return outputCalls
                else:
                    self.allfails += 1
                    outputCalls.append((self.js_print, ('%s' % '\n'.join(compileOutput),)))
                    outputCalls.append((self.fail,(testName, 'FAILED! file did not compile: %s' %
                                                   testName, self.failmsgs)))
                    return outputCalls

        if self.runSource or self.eval:
            incfiles=self.build_incfiles(testName)
            # With eval, shell.as must come first
            incfiles.append("shell" + self.sourceExt)
            for incfile in incfiles:
                if not (incfile == "./shell.as"):
                    testName=incfile+" "+testName

        # read any extra avm arguments, each line will execute the avm with those args
        if isfile('%s.avm_args' % ast):
            avm_args_file = open('%s.avm_args' % ast,'r')
            index = 0
            uses_swfversion = re.compile('uses_swfversion', re.IGNORECASE)
            uses_apiversion = re.compile('uses_apiversion', re.IGNORECASE)
            for line in avm_args_file:
                line = line.strip()
                if line.startswith('#'):
                    continue
                index += 1
                # uses_swfversion
                if uses_swfversion.search(line):
                    # run avm with all bugcompat versions
                    for swf_ver in self.swfversions:
                        line = uses_swfversion.sub('', line)
                        line, extraVmArgs, abcargs, multiabc = self.process_avm_args_line(line, dir)
                        extraVmArgs += ' -swfversion %s ' % swf_ver
                        outputCalls.extend(self.runTest(
                            ast, root, testName, '%s.%s' % (testnum, index),
                            settings, extraVmArgs, abcargs))
                        index += 1
                    continue
                # uses_apiversion
                if uses_apiversion.search(line):
                    # run avm with all api versions
                    for api_ver in self.apiversions:
                        line = uses_apiversion.sub('', line)
                        line, extraVmArgs, abcargs, multiabc = self.process_avm_args_line(line, dir)
                        extraVmArgs += ' -api SWF_%s ' % api_ver
                        outputCalls.extend(self.runTest(
                            ast, root, testName, '%s.%s' % (testnum, index),
                            settings, extraVmArgs, abcargs))
                        index += 1
                    continue
                line, extraVmArgs, abcargs, multiabc = self.process_avm_args_line(line, dir)
                outputCalls.extend(self.runTest(ast, root, testName, '%s.%s' % (testnum, index),
                                                settings, extraVmArgs, abcargs, multiabc))
            avm_args_file.close()
        else:
            outputCalls.extend(self.runTest(ast, root, testName, testnum, settings))

        return outputCalls

    def valid_time_zone(self, testname, testnum, outputCalls):
        '''Read in the associated time zone (testname.as.tz) file and
            check if we match that timezone.  Returns a boolean indicating
            whether we are in the right timezone'''
        tz_file = open('%s.tz' % testname)
        valid_timezones = []
        for line in tz_file:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            valid_timezones.append(line)
        tz_file.close()
        
        # windows python time.tzname returns time zone strings instead of
        # abbreviations.  Take the string and condense it so that it matches
        # the unix tzname values.  Not ideal, but works for most time zones.
        # e.g.: computer set to Pacific Standard Time
        # windows tzname = ('Pacific Standard Time', 'Pacific Daylight Time')
        # cygwin  tzname = ('PST', 'PDT')
        if self.osName == 'win' and not self.cygwin:
            # extract only the upper case letters from the windows time zone
            tzname = tuple([''.join(re.findall('[A-Z]',tz)) for tz in time.tzname])
        else:
            tzname = time.tzname
        # check if current tz is in the list
        if str(tzname) not in valid_timezones:
            outputCalls.append(
                    (self.js_print,
                    ('  skipping... reason: Current timezone: %s not in %s.tz timezones:\n' \
                     '                      %s'
                    % (tzname, testname, ','.join(valid_timezones)),)))
            outputCalls.insert(0,(self.js_print,('%d running %s' % (testnum, testname), '<b>', '</b><br/>')));
            self.allskips += 1
            return False
        return True

    def process_avm_args_line(self, line, dir):
        abcargs = ''
        multiabc = ''
        extraVmArgs = ''
        line = line.replace("$DIR", dir)
        if line.find('--') != -1:
            (line, abcargs) = line.split('--')
        if line.find('|multiabc|') != -1:
            multiabc = line[line.find('|multiabc|')+10:]
            extraVmArgs += line[:line.find('|multiabc|')]
        else:
            extraVmArgs = line
        return line, extraVmArgs, abcargs, multiabc

    def runTest(self, ast, root, testName, testnum, settings, extraVmArgs='', abcargs='', multiabc=''):
        passByEnv=None
        if self.passthreadid:
            try:
                if threading.currentThread().getName()=='MainThread':
                    n=0
                else:
                    n=int(threading.currentThread().getName()[7:])-1
                passByEnv=copy.deepcopy(os.environ)
                passByEnv["threadid"]='%s' % n
            except:
                print(sys.exc_info())
               
        if self.androidthreads:
            try:
                if threading.currentThread().getName()=='MainThread':
                    n=0
                else:
                    n=int(threading.currentThread().getName()[7:])-1
                if n<len(self.androiddevices):
                   extraVmArgs=" --threadid=%d --androidid=%s %s" % (n,self.androiddevices[n],extraVmArgs)
            except:
                print(sys.exc_info())
        
        outputCalls = []
        lpass = 0
        lfail = 0
        lexpfail = 0
        lunpass = 0
        ltimeout = 0
        lassert = 0
        starttime=time.time()

        if self.aotsdk and self.aotout:
            avm_args = ""
            if isfile("%s.avm_args" % ast):
                avm_args_file = open("%s.avm_args" % ast)
                avm_args = avm_args_file.readline()
                avm_args_file.close()
                if avm_args.find("mops") >= 0:
                    avm_args = ""
            progname = testName.replace(".abc", "")
            progname = progname.replace("/", ".")
            progpath = os.path.join(self.aotout, progname)
            if self.remoteip:
                retryCount = 5
                while retryCount > 0:
                    # copy file to remote device
                    cmd = "scp %s %s@%s:" % (progpath, self.remoteuser, self.remoteip)
                    self.run_pipe(cmd, outputCalls=outputCalls)
                    # run app
                    cmd = "ssh %s@%s ./%s %s" % (self.remoteuser, self.remoteip, progname, avm_args)
                    (f,err,exitcode) = self.run_pipe(cmd, outputCalls=outputCalls)
                    if exitcode != 0:
                        time.sleep(5)
                        retryCount -= 1
                    else:
                        break
                # delete app
                cmd = "ssh %s@%s rm %s" % (self.remoteuser, self.remoteip, progname)
                self.run_pipe(cmd, outputCalls=outputCalls)
            elif self.avm: # AVM is set to a script that will handle SSH communications
                cmd = "%s %s %s %s" % (self.avm, progpath, self.vmargs, extraVmArgs)
                (f,err,exitcode) = self.run_pipe(cmd, outputCalls=outputCalls, envVars=passByEnv)
            else: # Execute on OSX
                cmd = "%s %s" % (progpath, avm_args)
                # print("about to execute: " + cmd)
                (f,err,exitcode) = self.run_pipe(cmd, outputCalls=outputCalls)
        elif ast.endswith(self.abcasmExt):
            # make sure util file has been compiled
            if not exists(self.abcasmShell+'.abc'):  # compile abcasmShell with no additional args
                self.run_pipe('"%s" -jar %s %s' % (self.java, self.asc, self.abcasmShell+'.as'), outputCalls=outputCalls)
            (f,err,exitcode) = self.run_pipe('%s %s %s %s %s' % (self.avm, self.vmargs, extraVmArgs, self.abcasmShell+'.abc', testName), outputCalls=outputCalls, envVars=passByEnv)
        elif self.verify:
            # get the abcdump for the file
            (f,err,exitcode) = self.run_pipe('%s %s -- %s' % (self.avm, self.abcdump+'.abc', testName), outputCalls=outputCalls)
            abcdumpFunctions = [line.strip() for line in f if line.startswith('var function')]
            if self.verbose:
                outputCalls.append((self.js_print,(abcdumpFunctions,)))
            # get -Dverifyall -Dverbose=verify output
            (f,err,exitcode) = self.run_pipe('%s %s %s' % (self.avm, self.vmargs, testName), outputCalls=outputCalls)
            verifyFunctions = [line.strip() for line in f if line.startswith('verify Function/')]
            if self.verbose:
                outputCalls.append((self.js_print,(verifyFunctions,)))

            # we can't compare actual function names since abcdump treats function names and var names the same
            # we instead just compare that the # of functions verified == the # of functions listed out by abcdump
            if len(abcdumpFunctions) != len(verifyFunctions):
                lfail += 1
                outputCalls.append((self.fail,(testName, 'FAILED! :\nExpected (from abcdump): %s functions verified\nGOT (-Dverifyall -Dverbose=verify): %s functions verified' %
                                               (len(abcdumpFunctions),len(verifyFunctions)), self.failmsgs)))
            else:
                lpass += 1
        else:
            if abcargs:
                (f,err,exitcode) = self.run_pipe('%s %s %s %s %s -- %s' % (self.avm, self.vmargs, extraVmArgs, multiabc, testName, abcargs), outputCalls=outputCalls, envVars=passByEnv)
            elif multiabc:
                (f,err,exitcode) = self.run_pipe('%s %s %s %s %s' % (self.avm, self.vmargs, extraVmArgs, multiabc,testName), outputCalls=outputCalls, envVars=passByEnv)
            else:
                (f,err,exitcode) = self.run_pipe('%s %s %s %s' % (self.avm, self.vmargs, extraVmArgs, testName), outputCalls=outputCalls, envVars=passByEnv)

        # Test has been run, handle output
        if self.verifyonly:
            # only check the exit code when running a verifyonly pass
            ec_lfail, ec_lexpfail, expectedExitcode = self.check_exit_code(
                exitcode, root, testName, f, err, settings, outputCalls)
            if ec_lfail or ec_lexpfail:
                lfail += ec_lfail
                lexpfail += ec_lexpfail
            else:
                lpass += 1
        elif not self.verify:
            outputLines = []
            if isfile(root+'.out'):
                lpass, lfail, lexpfail, lunpass = self.check_out_file(
                                            root, testName, f+err, settings, outputCalls)
            else:
                for line in f+err:
                    outputLines.append(line)
                    outputCalls.append((self.verbose_print,('   %s' % line.strip(),)))
                    if 'Assertion failed:' in line:
                        lassert += 1
                        outputCalls.append((self.fail,(testName+extraVmArgs, line, self.assertmsgs)))
                    testcase=''
                    if len(line)>9:
                        testcase=line.strip()
                    skipTestDesc = dict_match(settings,testcase,'skip')
                    if skipTestDesc:
                        outputCalls.append((self.js_print,('  skipping "%s" ... reason: %s' % (line.strip(),skipTestDesc),)))
                        self.allskips+=1
                        continue
                    if 'PASSED!' in line:
                        res=dict_match(settings,testcase,'expectedfail')
                        if res:
                            outputCalls.append((self.fail,(testName, 'unexpected pass: ' + line.strip() + ' reason: '+res, self.unpassmsgs)))
                            lunpass += 1
                        else:
                            lpass += 1
                    if 'FAILED!' in line:
                        res=dict_match(settings,testcase,'expectedfail')
                        if res:
                            outputCalls.append((self.fail,(testName, 'expected failure: ' + line.strip().replace('FAILED','failed') + ' reason: '+res, self.expfailmsgs)))
                            lexpfail += 1
                        else:
                            lfail += 1
                            if not self.verbose:
                                outputCalls.append((self.fail,(testName+extraVmArgs, line, self.failmsgs)))

            # exitcode check
            ec_lfail, ec_lexpfail, expectedExitcode = self.check_exit_code(exitcode, root, testName, f, err, settings, outputCalls)
            if ec_lfail or ec_lexpfail:
                lfail += ec_lfail
                lexpfail += ec_lexpfail
            elif err:
                # TODO: When needed, add support for expected stderr output - see https://bugzilla.mozilla.org/show_bug.cgi?id=561892
                outputCalls.append((self.fail,(testName, "unexpected stderr expected:'%s' actual:'%s'" % ('',err), self.failmsgs)))
                lfail += 1  # any messages to stderr automatically fail the test
            elif lpass == 0 and lfail == 0 and lunpass==0 and lexpfail==0:
                res=dict_match(settings,'*','expectedfail')
                if res:
                    outputCalls.append((self.fail,(testName, 'expected failure: FAILED contained no testcase messages reason: %s' % res,self.expfailmsgs)))
                    lexpfail += 1
                else:
                    # test may not have any output but is still passing if a non-standard exitcode was expected (e.g. VerifyErrors)
                    if expectedExitcode != 0 and exitcode==expectedExitcode:
                        #outputCalls.append((self.js_print,('  Expected Exit Code: %s Actual Exit Code: %s PASSED' % (expectedExitcode, exitcode),)))
                        lpass = 1
                    else:
                        lfail = 1
                        outputmsg=''
                        for l in outputLines:
                            outputmsg+=l.strip()+'|'
                        outputCalls.append((self.fail,(testName, '   FAILED contained no testcase messages - reason: %s' % outputmsg, self.failmsgs)))

        self.allfails += lfail
        self.allpasses += lpass
        self.allexpfails += lexpfail
        self.allunpass += lunpass
        self.alltimeouts += ltimeout
        self.allasserts += lassert
        if lfail or lunpass:
            outputCalls.append((self.js_print, ('   FAILED passes:%d fails:%d unexpected passes: %d expected failures: %d\n' % (lpass,lfail,lunpass,lexpfail), '', '<br/>')))
        else:
            outputCalls.append((self.verbose_print, ('   PASSED passes:%d fails:%d unexpected passes: %d expected failures: %d\n' % (lpass,lfail,lunpass,lexpfail), '', '<br/>')))
        if self.show_time:
            if self.passthreadid:
                outputCalls.insert(0,(self.js_print,('%s running %s %s %s threadid=%s time %.1f' % (testnum, ast, extraVmArgs, abcargs, passByEnv['threadid'], time.time()-starttime), '<b>', '</b><br/>')));
            else:
                outputCalls.insert(0,(self.js_print,('%s running %s %s %s time %.1f' % (testnum, ast, extraVmArgs, abcargs, time.time()-starttime), '<b>', '</b><br/>')));
        else:
            if self.passthreadid:
                outputCalls.insert(0,(self.js_print,('%s running %s %s %s threadid=%s' % (testnum, ast, extraVmArgs, abcargs, passByEnv['threadid']), '<b>', '</b><br/>')));
            else:
                outputCalls.insert(0,(self.js_print,('%s running %s %s %s' % (testnum, ast, extraVmArgs, abcargs), '<b>', '</b><br/>')));


        return outputCalls

    def check_out_file(self, root, testName, output, settings, outputCalls):
        # override standard runtests behavior, just compare the .out file with stdout+stderr
        lpass, lfail, lexpfail, lunpass = 0, 0, 0, 0
        actual = [line.strip() for line in output if line.strip()]
        try:
            outfile = open(root+'.out', 'r')
            expectedOut = [line.strip() for line in outfile.readlines() if line.strip()]
            outfile.close()
        except IOError:
            outputCalls.append((self.js_print,('Error opening %s.out' % root,)))
            lfail += 1
            return lpass, lfail, lexpfail, lunpass
            
        outputCalls.append((self.verbose_print,('%s.out file (expected):' % root,)))
        outputCalls.append((self.verbose_print,(expectedOut,)))
        outputCalls.append((self.verbose_print,('\nactual output:',)))
        outputCalls.append((self.verbose_print,(actual,)))
        # check settings if this should be an expected failure
        expectedfail = dict_match(settings,'','expectedfail')
        # .out files can contain regex but must be prefaced with REGEXP as the first line in the file
        try:
            if expectedOut[0] == 'REGEXP':
                expectedOut = expectedOut[1:]
                if len(actual) < len(expectedOut):
                    # pad actual output w/ empty lines
                    for i in range(len(expectedOut)-len(actual)):
                        actual.append('')
                for i in range(len(actual)):
                    if not re.search(expectedOut[i], actual[i]):
                        raise IndexError
            else:
                if actual != expectedOut:
                    raise IndexError
            # test passed - check to make sure its not an expected failure
            if expectedfail:
                outputCalls.append((self.fail,(
                    testName, 'unexpected .out file pass. ' +
                    ' reason: '+expectedfail, self.unpassmsgs)))
                lunpass += 1
            else:
                lpass += 1
        except IndexError:
            # test failed
            if expectedfail:
                outputCalls.append((self.fail,(
                    testName,
                    'expected failure: .out file does not match stdout+stderr. ' +
                    ' reason: '+expectedfail, self.expfailmsgs)))
                lexpfail += 1
            else:
                outputCalls.append((self.fail,(testName,
                    '.out file does not match output:\n%s.out file (expected):\n%s\nactual output:\n%s' % (root, expectedOut,actual),
                    self.failmsgs)))
                lfail += 1
        return lpass, lfail, lexpfail, lunpass
                    
    def check_exit_code(self, exitcode, root, testName, f, err, settings, outputCalls):
        '''Check the exitcode for a test against any expected non-zero exitcodes
            Return the fail and the expected exitcode if non-zero
        '''
        lfail = 0
        lexpfail = 0
        expectedExitcode=0
        if isfile(root+'.err'):
            # .err file holds both the expected (non-catchable) error (usually a VerifyError) and the expected exitcode
            expectedErr,expectedExitcode = self.loadExpectedErr(root+'.err')
            # check the expectedErr - error is always the last (non-empty) line of output
            actualErr = ''
            for line in reversed(f):
                # When running in --verifyonly mode, output will be VERIFY FAILED instead of VerifyError
                line = line.replace('VERIFY FAILED', 'VerifyError')
                # make sure we have an error
                if re.search('.*Error:.*', line):
                    actualErr = self.getError(line.strip())
                    break
            if actualErr != expectedErr:
                outputCalls.append((self.fail,(testName, 'unexpected error message. expected: %s actual: %s'
                                               % (expectedErr, actualErr), self.failmsgs)))
                lfail += 1
        elif isfile(root+".exitcode"):
            try:
                expectedExitcode=int(open(root+".exitcode").read())
            except:
                print("ERROR: reading exit code file '%s' should contain an integer")
        
        res=dict_match(settings,'exitcode','expectedfail')
        
        if exitcode!=expectedExitcode:
            res2=dict_match(settings,'exitcode','skip')
            if res2==None and res:
                outputCalls.append((self.js_print,(testName, 'expected failure: exitcode reason: %s'
                                                   % res,self.expfailmsgs)))
                lexpfail += 1
            elif res2==None:
                outputCalls.append((self.fail,(testName, 'unexpected exit code expected:%d actual:%d Signal Name: %s FAILED!'
                                               % (expectedExitcode,exitcode,getSignalName(abs(exitcode))),
                                               self.failmsgs)))
                outputmsg=''
                for l in f+err:
                    outputmsg+=l.strip()+'|'
                outputCalls.append((self.fail,(testName, 'captured output: %s'
                                               % outputmsg,self.failmsgs)))
                lfail+= 1
        return lfail, lexpfail, expectedExitcode

    def loadExpectedErr(self, file):
        try:
            f = open(file, 'r')
            expectedErr = ''
            expectedExitcode = 0
            for line in f:
                line = line.strip()
                if line and not line.startswith('#'):
                    if line.lower().startswith('exitcode:'):
                        try:
                            expectedExitcode = int(line.split(':')[1].strip())
                        except ValueError:
                            pass
                    else:
                        # check to see if line is a number - if so set expectedExitcode
                        try:
                            expectedExitcode = int(line)
                        except ValueError:
                            expectedErr = line
            f.close()
            return expectedErr, expectedExitcode
        except:
            return 'Error reading .err file: %s' % file, 0

    def getError(self, line):
        # Parse out the error type and #, but strip the description
        try:
            return ':'.join(line.split(':')[0:2])
        except:
            return line

runtest = AcceptanceRuntest()
