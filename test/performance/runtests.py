#!/usr/bin/env python
#
# ***** BEGIN LICENSE BLOCK ***** 
# Version: MPL 1.1/GPL 2.0/LGPL 2.1 
#
# The contents of this file are subject to the Mozilla Public License Version 1.1 (the 
# "License"); you may not use this file except in compliance with the License. You may obtain 
# a copy of the License at http://www.mozilla.org/MPL/ 
#
# Software distributed under the License is distributed on an "AS IS" basis, WITHOUT 
# WARRANTY OF ANY KIND, either express or implied. See the License for the specific 
# language governing rights and limitations under the License. 
#
# The Original Code is open source virtual machine.
#
# The Initial Developer of the Original Code is
# dschaffe@adobe.com
# Portions created by the Initial Developer are Copyright (C) 2008
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of either the GNU 
# General Public License Version 2 or later (the "GPL"), or the GNU Lesser General Public 
# License Version 2.1 or later (the "LGPL"), in which case the provisions of the GPL or the 
# LGPL are applicable instead of those above. If you wish to allow use of your version of this 
# file only under the terms of either the GPL or the LGPL, and not to allow others to use your 
# version of this file under the terms of the MPL, indicate your decision by deleting provisions 
# above and replace them with the notice and other provisions required by the GPL or the 
# LGPL. If you do not delete the provisions above, a recipient may use your version of this file 
# under the terms of any one of the MPL, the GPL or the LGPL. 
# 
# ***** END LICENSE BLOCK ***** 
#
# simple script that executes tests on tamarin-central or tamarin-tracing vm
#
import os, os.path, sys, getopt, datetime, pipes, glob, itertools, tempfile, string, re, platform, time, subprocess, socket, math
from math import sqrt
from os.path import *
from os import getcwd,environ,walk
from datetime import datetime
from glob import glob
from sys import argv, exit
from getopt import getopt
from itertools import count
from platform import *
from socket import *

verbose = False
timestamps = True
forcerebuild = False
logresults = False
iterations = 1

# needed for pipe
fd,tmpfile = tempfile.mkstemp()
os.close(fd)
js_output_f=False

globs = { 'avm':'','avm2':'', 'asc':'', 'globalabc':'', 'exclude':[], 'tmpfile':tmpfile, 'config':'sunspider', 'ascargs':'', 
          'vmargs':'', 'vmargs2':'', 'vmname':'unknown', 'vmversion':'', 'socketlog':'', 'perfm':False, 'avmname':'avm', 'avm2name':'avm2'}
if 'AVM' in environ:
  globs['avm'] = environ['AVM'].strip()
if 'AVM2' in environ:
  globs['avm2'] = environ['AVM2'].strip()
if 'ASC' in environ:
  globs['asc'] = environ['ASC'].strip()
if 'GLOBALABC' in environ:
  globs['globalabc'] = environ['GLOBALABC'].strip()
if 'ASCARGS' in environ:
  globs['ascargs'] = environ['ASCARGS'].strip()
if 'VMARGS' in environ:
  globs['vmargs'] = environ['VMARGS'].strip()
if 'VMARGS2' in environ:
  globs['vmargs2'] = environ['VMARGS2'].strip()

def log_print(m):
  print(m)
  if (js_output_f):
    js_output_f.write("%s\n" % m)
    js_output_f.flush()


def verbose_print(m):
  if verbose:
    log_print(m)

def usage(c):
  print "usage: %s [options] [tests]" % basename(argv[0])
  print " -v --verbose       enable additional output"
  print " -E --avm           avmplus command to use"
  print " -S --avm2          second avmplus command to use"
  print "    --avmname       nickname for avm to use as column header"
  print "    --avm2name      nickname for avm2 to use as column header"
  print " -a --asc           compiler to use"
  print " -c --config        configuration to use with testconfig.txt"
  print " -g --globalabc     location of global.abc"
  print " -h --help          display help and exit"
  print " -f --forcerebuild  force rebuild all test files"
  print " -i --iterations    number of times to repeat test"
  print " -l --log           logs results to a file"
  print " -d --socketlog     logs results to a socket server"
  print " -r --runtime     name of the runtime VM used, including switch info eg. TTVMi (tamarin-tracing interp)"
  print "    --vmversion     specify vmversion e.g. 502, use this if cannot be calculated from executable"
  print "    --ascargs     args to pass to asc on rebuild of test files"
  print "    --vmargs        args to pass to vm"
  print "    --vmargs2     args to pass to avm2, if not specified --vmargs will be used"
  print "    --perfm         parse the perfm results from avm"
  exit(c)

try:
  opts, args = getopt(argv[1:], "vE:S:a:g:hfi:c:ldr:", ["verbose","avm=","asc=","globalabc=","help","forcerebuild","ascargs=","vmargs=","log",
                      "socketlog","avm2=","vmargs2=","iterations=","config=","runtime=","vmversion=","perfm", "avmname=","avm2name="])
except:
  usage(2)

if not args:
  args = ["."]
for o, v in opts:
  if o in ("-v", "--verbose"):
    verbose = True
  elif o in ("-h", "--help"):
    usage(0)
  elif o in ("-E", "--avm"):
    globs['avm'] = v
  elif o in ("-S", "--avm2"):
    globs['avm2'] = v
  elif o in ("-a", "--asc"):
    globs['asc'] = v
  elif o in ("-g", "--globalabc"):
    globs['globalabc'] = v
  elif o in ("-x", "--exclude"):
    globs['exclude'] += v.split(",")
  elif o in ("-t", "--notime"):
    timestamps = False
  elif o in ("-f", "--forcerebuild"):
    forcerebuild = True
  elif o in ("-i", "--iterations"):
    iterations = int(v)
  elif o in ("-c", "--config"):
    globs['config'] = v
  elif o in ("--ascargs"):
    globs['ascargs'] = v
  elif o in ("--vmargs"):
    globs['vmargs'] = v
  elif o in ("--vmargs2"):
    globs['vmargs2'] = v
  elif o in ("-l","--log"):
    now = datetime.today()
    for i in count(1):
      js_output = "%d-%s-%s.%d.log" % (now.year, str(now.month).zfill(2), str(now.day).zfill(2), i)
      if not isfile(js_output):
        break
    print "Writing results to %s" % js_output
    js_output_f = open(js_output, "w")
  elif o in ("-d", "--socketlog"):
    logresults = True
  elif o in ("-r", "--runtime"):
    globs['vmname'] = v
  elif o in ("--vmversion"):
    globs['vmversion'] = v
  elif o in ("--perfm"):
    globs['perfm'] = True
  elif o in ("--avmname"):
    globs['avmname'] = v
  elif o in ("--avm2name"):
    globs['avm2name'] = v

def istest(f):
  return f.endswith(".as")

tests = [a for a in args if isfile(a) and istest(a)]
for a in [d for d in args if isdir(d)]:
  for d, dirs, files in walk(a):
    tests += [join(d,f) for f in files if istest(f)]
    utils = [d for d in dirs if d+".as" in files]

def parents(d):
  while d != "":
    yield d
    d = dirname(d)
  yield d

# run a command and return its output
def run_pipe(cmd):
  proc = subprocess.Popen(cmd.split(), stdout=subprocess.PIPE, shell=False)
  proc.wait()
  return proc.stdout
  #t = pipes.Template()
  #t.append("%s 2>&1" % cmd, "--")
  #verbose_print(cmd)
  #return t.open(globs['tmpfile'], "r")


def compile_test(as):
  asc, globalabc, ascargs = globs['asc'], globs['globalabc'], globs['ascargs']
  if not isfile(asc):
    exit("ERROR: cannot build %s, ASC environment variable or --asc must be set to asc.jar" % as)
  if not isfile(globalabc):
    exit("ERROR: global.abc %s does not exist, GLOBALABC environment variable or --globalabc must be set to global.abc" % globalabc)
  
  if asc.endswith(".jar"):
    cmd = "java -jar " + asc
  else:
    cmd = asc
  cmd += " " + ascargs
  cmd += " -import " + globalabc
  (dir, file) = split(as)
  verbose_print("   compiling %s" % file)
  (testdir, ext) = splitext(as)
  try:
    f = run_pipe("%s %s" % (cmd,as))
    for line in f:
      verbose_print(line.strip())
  finally:
    f.close()


def mean(population):
  mean = 0.0
  for x in population:
    mean = mean + float(x)
  return mean / len(population)

def variance(population):
  n = 0
  mean = 0.0
  s = 0.0
  for x in population:
    n = n + 1
    delta = int(x) - mean
    mean = mean + (delta / n)
    s = s + delta * (int(x) - mean)

  # if you want to calculate std deviation
  # of a sample change this to "s / (n-1)"
  return s / (n-1)

def standard_deviation(population):
  return sqrt(variance(population))


def standard_error(population):
  return standard_deviation(population) / sqrt(len(population))

tDistribution = [ 999, 999, 12.71, 4.30, 3.18, 2.78, 2.57, 2.45, 2.36, 2.31, 2.26, 2.23, 2.20, 2.18, 2.16, 2.14, 2.13, 2.12, 2.11, 2.10, 2.09, 2.09, 2.08, 2.07, 2.07, 2.06, 2.06, 2.06, 2.05, 2.05, 2.05, 2.04, 2.04, 2.04, 2.03, 2.03, 2.03, 2.03, 2.03, 2.02, 2.02, 2.02, 2.02, 2.02, 2.02, 2.02, 2.01, 2.01, 2.01, 2.01, 2.01, 2.01, 2.01, 2.01, 2.01, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 2.00, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.99, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.98, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.97, 1.96]
tMax = len(tDistribution)
tLimit = 1.96

def tDist(n):
    if (n > tMax):
        return tLimit
    return tDistribution[n]


# ================================================
# Determine the version number associated with the 
# VM, will be cyclone if not from build machine
# ================================================
VM_version = ''
VM_name = globs['vmname']

if globs['vmversion']:
  VM_version=globs['vmversion']
else:
    f = run_pipe("%s" % globs['avm'])
    try:
      for line in f:
        version = line.split()
        version = version[len(version)-1]
        if version.find(":") != -1:   # if this is an actual build we need to remove the hash
          version = version.split(":")
          version = version[0]
        VM_version = version
        globs['vmversion'] = version
        break
    except:
      nop = True

OS_name = {'CYGWIN_NT-5.1':'WIN','CYGWIN_NT-5.2':'WIN','CYGWIN_NT-6.0-WOW64':'WIN','Windows':'WIN','Darwin':'MAC','Linux':'LNX','Solaris':'SOL','SunOS':'SOL',}[system()]
VM_reporting = '%s %s %s' % (VM_name,OS_name,VM_version)
# ================================================
# Prepare the data to be sent through a socket to 
# be recorded to the database
# ================================================
serverHost = '10.60.48.47'
serverPort = 1188
# ===========================================
# If logging is enabled, log results to 
# performance database
# ===========================================
def socketlog(msg):
  if logresults:
    if globs['socketlog']=='':
      file="socketlog-%s.txt" % globs['vmversion']
      ctr=0
      while os.path.exists(file):
        ctr+=1
        file="socketlog-%s-%s.txt" % (globs['vmversion'],ctr)
      globs['socketlog']=file
    alltext=''
    try:
      alltext=open(globs['socketlog']).read()
    except:
      print("creating new socket log file %s" % globs['socketlog'])
    alltext+="%s\n" % msg
    open(globs['socketlog'],'w').write(alltext)
    s = socket(AF_INET, SOCK_STREAM)    # create a TCP socket
    s.connect((serverHost, serverPort)) # connect to server on the port
    s.send("%s;exit\r\n" % msg)         # send the data
    data = s.recv(1024)
    #print('Sent: %s' % msg)
    #print('Received: %s \n\n' % data)
    s.shutdown(SHUT_RDWR)
    s.close()


def parsePerfm(line,dic):
  try:
    result = line.strip().split(' ')[-2]
    if 'verify & IR gen' in line:
      dic['verify'].append(int(result))
    elif 'code ' in line:
      dic['code'].append(int(result))
    elif 'compile ' in line:
      dic['compile'].append(int(result))
    elif 'ir bytes' in line:
      dic['irbytes'].append(int(result))
    elif 'IR/tick' in line:
      dic['tick'].append(int(result))
    elif ('lir ' in line) or ('mir ' in line): #note trailing space
      dic['ir'].append(int(result))
      dic['count'].append(int(line.strip().split(' ')[-1]))
  except:
    pass

# setup dictionary for vprof (perfm) results
if globs['perfm']:
  perfm1Dict = {'verify':[], 'code':[], 'compile':[], 'irbytes':[], 'tick':[], 'ir':[], 'count':[] }
  perfm2Dict = {'verify':[], 'code':[], 'compile':[], 'irbytes':[], 'tick':[], 'ir':[], 'count':[] }
  


skips=[]
if isfile('./testconfig.txt'):
  for line in open('./testconfig.txt').read().splitlines():
    fields = line.split(',')
    for f in range(len(fields)):
      fields[f]=fields[f].strip()
    if len(fields)<3:
      continue
    if re.match(fields[1],globs['config'])==None:
      continue
    if fields[2]=='skip':
      skips.append(fields[0])
vmargs = globs['vmargs']
vmargs2 = globs['vmargs2']
avm = globs['avm']
avm2 = globs['avm2']
if not avm: # or not isfile(avm.split()[0]): /* isfile() fails for alias on OSX */
  exit("ERROR: cannot run %s, AVM environment variable or --avm must be set to avmplus" % avm)
log_print("Executing tests at %s" % (datetime.now()))
log_print("avm: %s %s" % (avm,vmargs));
if len(avm2)>0:
  if len(vmargs2)>0:
    log_print("avm2: %s %s" % (avm2,vmargs2));
  else:
    log_print("avm2: %s" % (avm2,));
log_print('iterations: %s' % iterations)

if len(avm2)>0:
  if iterations == 1:
    log_print("\n%-50s %7s %7s %7s\n" % ("test",globs['avmname'],globs['avm2name'], "%sp"))
  else:
    log_print("\n%-50s %20s   %20s" % ("test",globs['avmname'],globs['avm2name']))
    log_print('%-50s  %5s :%5s  %5s    %5s :%5s  %5s %7s' % ('', 'min','max','avg','min','max','avg','%diff'))
    log_print('                                                   --------------------   --------------------   -----')
else:
  if (iterations>2):
    log_print("\n\n%-50s %7s %12s\n" % ("test",globs['avmname'],"95% conf"))
  else:
    log_print("\n\n%-50s %7s\n" % ("test",globs['avmname']))
testnum = len(tests)
for ast in tests:
  if ast.startswith("./"):
    ast=ast[2:]
  skip=False
  for sk in skips:
    if re.match("^%s$" % sk,ast):
      verbose_print("skipping %s" % ast)
      testnum-=1
      skip=True
      break
  if skip:
    continue
  testnum -= 1
  dir =ast[0:ast.rfind('/')]
  root,ext = splitext(ast)
  tname = root[root.rfind('/')+1:]
  abc = "%s.abc" % root
  verbose_print("%d running %s" % (testnum, ast));
  if forcerebuild and isfile(abc):
    os.unlink(abc)
  if not isfile(abc):
    compile_test(ast)
    if not isfile(abc):
      log_print("compile FAILED!, file not found " + abc)
      
  result1=9999999
  resultList = []
  resultList2 = []
  result2=9999999
  
  perfm1 = {}
  perfm2 = {}
  
  for i in range(iterations):
    f1 = run_pipe("%s %s %s" % (avm, vmargs, abc))
    if len(avm2)>0:
      if len(vmargs2)>0:
        f2 = run_pipe("%s %s %s" % (avm2, vmargs2, abc))
      else:
        f2 = run_pipe("%s %s %s" % (avm2, vmargs, abc))
    #try:
    for line in f1:
      if "metric" in line:
        result1list=line.rsplit()
        if len(result1list)>2:
          resultList.append(int(result1list[2]))
          if result1 > int(result1list[2]):
            result1=float(result1list[2])
      elif globs['perfm']:
        parsePerfm(line, perfm1Dict)
          
    if len(avm2)>0:
      for line in f2:
        if "metric" in line:
          result2list=line.rsplit()
          if len(result2list)>2:
            resultList2.append(int(result1list[2]))
            if result2 > int(result2list[2]):
              result2=float(result2list[2])
        elif globs['perfm']:
          parsePerfm(line, perfm2Dict)
    if result1==0:
      spdup = 9999
    else:
      spdup = ((result1-result2)/result2)*100.0
    #except:
    #  log_print("exception: %s" % sys.exc_info()[0])
    #  exit(-1)

  if len(avm2)>0:
    if iterations == 1:
      log_print('%-50s %7s %7s %7.1f' % (ast,result1,result2,spdup))
    else:
      try:
        log_print('%-50s [%5s :%5s] %5.1f   [%5s :%5s] %5.1f %7.1f' % (ast, min(resultList), max(resultList), sum(resultList)/len(resultList), min(resultList2), max(resultList2), sum(resultList2)/len(resultList2),spdup))
      except:
        log_print('%-50s [%5s :%5s] %5.1f   [%5s :%5s] %5.1f %7.1f' % (ast, '', '', result1, '', '', result2, spdup))
    
    if globs['perfm']:
      def calcPerfm(desc, key):
        # calculate min, max, average and %diff of averages
        try:
          if iterations == 1:
            return '     %-45s %7s %7s %7.1f' % (desc, perfm1Dict[key][0], perfm2Dict[key][0],
                                ((perfm1Dict[key][0]-perfm2Dict[key][0])/float(perfm2Dict[key][0])*100.0))
          else:
            avg1 = sum(perfm1Dict[key])/len(perfm1Dict[key])
            avg2 = sum(perfm2Dict[key])/len(perfm2Dict[key])
            return '     %-45s [%5s :%5s] %5s   [%5s :%5s] %5s %7.1f' % (desc, min(perfm1Dict[key]), max(perfm1Dict[key]), avg1,
                                                                 min(perfm2Dict[key]), max(perfm2Dict[key]), avg2,
                                                                 ((avg1-avg2)/float(avg2))*100.0)
        except:
          return ''
          
      log_print(calcPerfm('verify & IR gen (time)','verify'))
      log_print(calcPerfm('compile (time)','compile'))
      log_print(calcPerfm('code size (bytes)','code'))
      log_print(calcPerfm('mir/lir bytes', 'irbytes'))
      log_print(calcPerfm('mir/lir (# of inst)', 'ir'))
      log_print(calcPerfm('IR/tick', 'tick'))
      log_print(calcPerfm('count', 'count'))
      log_print('------------------------------------------------------------------------------------------------------')
  else:
    if result1 < 9999999 :
      meanRes = mean(resultList)
      if (iterations > 2):
        if meanRes==0:
          confidence = 0
        else:
          confidence = ((tDist(len(resultList)) * standard_error(resultList) / meanRes) * 100)
        config = "%s%s" % (VM_name, vmargs.replace(" ", ""))
        socketlog("addresult2::%s::time::%s::%0.1f::%s::%s::%s::%s::%s;" % (ast, result1, confidence, meanRes, iterations, OS_name, config, VM_version))
        log_print("%-50s %7s %10.1f%%" % (ast,result1,confidence)) 
      else:
        log_print("%-50s %7s" % (ast,result1)) 
    else:
        log_print("%-50s crash" % (ast)) 

