#!/usr/bin/env python
# -*- Mode: Python; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
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
# Portions created by the Initial Developer are Copyright (C) 2004-2006
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
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
# ***** END LICENSE BLOCK *****

# This is a wrapper script around the exactgc script. Usage:
# Env:
# The AVM env var must point to an avmshell
# The ASC env var must point to asc.jar
# Invocation:
# The script exports one function "GenerateTracers" with these arguments:
# prefix = module specific prefix string used in generated file names, ie "avmplus", "avmglue"
# inputfiles = string of list of files, can contain wildcards
# outputdir = where output files go

import os
import shutil
import sys
import filecmp
import glob
import tempfile
import platform

utilsdir = os.path.abspath(os.path.dirname(__file__))

def gen(prefix,inputfiles,outputdir,srcdir=os.getcwd(),ns="avmplus"):
    avm = os.environ.get('AVM')
    if avm == None:
        print "ERROR: AVM environment variable must point to avm executable"
        exit(1)

    asfile = utilsdir + "/exactgc.as"
    abcfile = utilsdir + "/exactgc.abc"

    # note this script tries not to rely on CWD but compiling exactgc.as does.
    if not os.path.exists(abcfile) or (os.path.getmtime(abcfile) < os.path.getmtime(asfile) and os.access(abcfile, os.W_OK)):
        classpath = os.environ.get('ASC')
        if classpath == None:
            print "ERROR: ASC environment variable must point to asc.jar"
            exit(1)
        print("Compiling exactgc script...")
        os.system("java -jar %s -AS3 -import %s/../generated/builtin.abc -import %s/../generated/shell_toplevel.abc -debug %s" % (classpath, utilsdir, utilsdir, asfile))

    # in case outputdir is relative make it absolute before chdir'ing
    outputdir = os.path.abspath(outputdir)
        
    print("Generating "+prefix+" exact gc generated code into " + outputdir)
    savedir = os.getcwd()

    os.chdir(srcdir)

    # expand wildcards in input file list
    filelist = '\n'.join([y for x in map(glob.glob, inputfiles.split()) for y in x])
    
    # don't bother trying to pass via os.system, dump into a tmp file
    # for windows we need a new python API to keep the file around ater closing, which
    # we must do in order for the exact gc script to open it.
    oldpy = sys.version_info < (2,6)
    if oldpy and platform.system() == 'Windows':
		print "Error: exactgc script requirets newer python on windows."
		exit(1)
		
    if oldpy:
		tmpfile = tempfile.NamedTemporaryFile()
	else:
	    tmpfile = tempfile.NamedTemporaryFile(delete = False)
	    
	tmpfile.write(filelist)
	
	# close deletes in old world
	if not oldpy:
		tmpfile.close()
    else:
        tmpfile.flush()

    exactgccmd = '%s %s -- -b %s-tracers.hh -n %s-tracers.hh -i %s-tracers.h -ns %s %s' % (avm, abcfile, prefix, prefix, prefix, ns, '@'+tmpfile.name)
    ret = os.system(exactgccmd)
    
    if oldpy:
        tmpfile.close()
    else:
        os.unlink(tmpfile.name)
        
    if ret != 0:
        print "Invoking avmshell on exactgc script failed"
        return False

    tmpfile.close()

    if not os.path.exists(prefix+'-tracers.hh'):
        print "Error: failed to generate tracers"
        exit(1)
    
    if not os.path.exists(outputdir):
        os.makedirs(outputdir)

    # copy changed headers stuff to output dir
    for src in [prefix+'-tracers.hh', prefix+'-tracers.h']:
        target = outputdir + "/" + src
        if not os.path.exists(target) or not filecmp.cmp(target,src):
            shutil.move(src,target)
        else:
            os.remove(src)
    os.chdir(savedir)
            
def gen_builtins(outdir):
    coredir = utilsdir + "/../core/"
    gen(prefix = 'avmplus', inputfiles = '*.h *.as', outputdir = outdir, srcdir = coredir)

def gen_shell(outdir):
    shelldir = utilsdir + "/../shell/"
    gen(prefix = 'avmshell', inputfiles = 'shell_toplevel.as DebugCLI.h ShellCore.h SystemClass.h', outputdir = outdir, srcdir = shelldir, ns = 'avmshell')
    gen(prefix = 'extensions', inputfiles = 'DomainClass.h Domain.as ../extensions/*.h ../extensions/*.as', outputdir = outdir, srcdir = shelldir)
