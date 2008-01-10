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
import os, os.path, sys, getopt, datetime, pipes, glob, itertools, tempfile, string, re, platform, time
from os.path import *
from os import getcwd,environ,walk
from datetime import datetime
from glob import glob
from sys import argv, exit
from getopt import getopt
from itertools import count

verbose = False
timestamps = True
forcerebuild = False

# needed for pipe
fd,tmpfile = tempfile.mkstemp()
os.close(fd)
js_output_f=False

globs = { 'avm':'','avmtt':'', 'asc':'', 'globalabc':'', 'exclude':[], 'tmpfile':tmpfile, 'config':'', 'ascargs':'', 'vmargs':''}
if 'AVM' in environ:
	globs['avm'] = environ['AVM'].strip()
if 'AVMTT' in environ:
	globs['avmtt'] = environ['AVMTT'].strip()
if 'ASC' in environ:
	globs['asc'] = environ['ASC'].strip()
if 'GLOBALABC' in environ:
	globs['globalabc'] = environ['GLOBALABC'].strip()
if 'ASCARGS' in environ:
	globs['ascargs'] = environ['ASCARGS'].strip()
if 'VMARGS' in environ:
	globs['vmargs'] = environ['VMARGS'].strip()

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
	print " -T --avmtt         avmplus tamarin-tracing command to use"
	print " -a --asc           compiler to use"
	print " -g --globalabc     location of global.abc"
	print " -h --help          display help and exit"
	print " -f --forcerebuild  force rebuild all test files"
	print " -l --log           logs results to a file"
	print "    --ascargs	   args to pass to asc on rebuild of test files"
	print "    --vmargs	       args to pass to vm"
	exit(c)

try:
	opts, args = getopt(argv[1:], "vE:T:a:g:hfc:l", ["verbose","avm=","asc=","globalabc=","help","forcerebuild","ascargs=","vmargs=","log"])
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
	elif o in ("-T", "--avmtt"):
		globs['avmtt'] = v
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
	elif o in ("-c", "--config"):
		globs['config'] = v
	elif o in ("--ascargs"):
		globs['ascargs'] = v
	elif o in ("--vmargs"):
		globs['vmargs'] = v
	elif o in ("-l","--log"):
		now = datetime.today()
		for i in count(1):
			js_output = "%d-%s-%s.%d.log" % (now.year, str(now.month).zfill(2), str(now.day).zfill(2), i)
			if not isfile(js_output):
				break
		print "Writing results to %s" % js_output
		js_output_f = open(js_output, "w")

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
	t = pipes.Template()
	t.append("%s 2>&1" % cmd, "--")
	verbose_print(cmd)
	return t.open(globs['tmpfile'], "r")

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

skips=[]
if isfile('./testconfig.txt'):
	for line in open('./testconfig.txt').read().splitlines():
		fields = line.split(',')
		for f in range(len(fields)):
			fields[f]=fields[f].strip()
		if len(fields)>1 and fields[1]=='skip':
			skips.append(fields[0])
vmargs = globs['vmargs']
avm = globs['avm']
avmtt = globs['avmtt']
if not avm: # or not isfile(avm.split()[0]): /* isfile() fails for alias on OSX */
	exit("ERROR: cannot run %s, AVM environment variable or --avm must be set to avmplus" % avm)
log_print("Executing %d tests at %s" % (len(tests),datetime.now()))
log_print("tc: %s" % avm);
if len(avmtt)>0:
	log_print("tt: %s" % avmtt);

if len(avmtt)>0:
	log_print("\n\n%-50s %7s %7s\n" % ("test","tc","tt"));
else:
	log_print("\n\n%-50s %7s\n" % ("test","tc"));
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
	f1 = run_pipe("nice --10 %s %s %s" % (avm, vmargs, abc))
	if len(avmtt)>0:
		f2 = run_pipe("nice --10 %s %s %s" % (avmtt, vmargs, abc))
	try:
		tc="na"
		tt="na"
		for line in f1:
			if "metric" in line:
				tclist=line.rsplit()
				if len(tclist)>2:
					tc=tclist[2]
		if len(avmtt)>0:
			for line in f2:
				if "metric" in line:
					ttlist=line.rsplit()
					if len(ttlist)>2:
						tt=ttlist[2]
		if len(avmtt)>0:
			log_print("%-50s %7s %7s" % (ast,tc,tt)) 
		else:
			log_print("%-50s %7s" % (ast,tc)) 
	except:
		log_print("exception")
		exit(-1)
