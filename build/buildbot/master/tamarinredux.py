# -*- python -*-
# ex: set syntax=python:
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
#  Portions created by the Initial Developer are Copyright (C) 2009-2010
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

from buildbot.process import factory
from buildbot.steps.source import Mercurial
from buildbot.steps.shell import *
from custom.buildbot_ext.steps.shellAddons import *
from buildbot.steps.trigger import Trigger

from commonsteps import *

class tamarinredux:
    
    HG_URL = "http://asteam.macromedia.com/hg/tamarin-redux/"
    BRANCHES = ["tamarin-redux","tamarin-redux-serrano"]
    BRANCHES_DEEP = ["tamarin-redux-deep","tamarin-redux-serrano-deep"]
    
    ####### SCHEDULERS
    from buildbot.scheduler import *
    # custom.buildbot_ext.scheduler import MUST happen after importing buildbot.scheduler
    from custom.buildbot_ext.scheduler import *

    compile = Scheduler(name="compile", branch=BRANCHES, treeStableTimer=30, fileIsImportant=startCompile, properties={'silent':'false'},
                     builderNames=["windows-compile", "windows64-compile",
                                   "mac-intel-10.5-compile", "mac64-intel-compile",
                                   "linux-compile",
                                   "linux64-compile",
                                   "solaris-sparc-compile",
                                   "android-compile",
                                   "linux-arm-compile",
                                   "linux-mips-compile",
                                    ])

    smoke = BuilderDependent(name="smoke",upstream=compile, callbackInterval=60, properties={'silent':'false'},
                    builderNames=["windows-smoke", "windows64-smoke",
                                   "mac-intel-10.5-smoke", "mac64-intel-smoke",
                                   "linux-smoke",
                                   "linux64-smoke",
                                   "solaris-sparc-smoke",
                                   "android-smoke",
                                   "linux-arm-smoke",
                                   "linux-mips-smoke",
                                   ],
                    builderDependencies=[
                                  ["windows-smoke", "windows-compile"], 
                                  ["windows64-smoke", "windows64-compile"], 
                                  ["mac-intel-10.5-smoke", "mac-intel-10.5-compile"],
                                  ["mac64-intel-smoke", "mac64-intel-compile"],
                                  ["linux-smoke", "linux-compile"],
                                  ["linux64-smoke", "linux64-compile"],
                                  ["solaris-sparc-smoke", "solaris-sparc-compile"],
                                  ["android-smoke","android-compile"],
                                  ["linux-arm-smoke","linux-arm-compile"],
                                  ["linux-mips-smoke","linux-mips-compile"],
                                 ])

    test = BuilderDependent(name="test",upstream=smoke, callbackInterval=60, properties={'silent':'false'},
                    builderNames=["windows-test", "windows64-test",
                                   "mac-intel-10.5-test", "mac64-intel-test",
                                   "linux-test",
                                   "linux64-test",
                                   "solaris-sparc-test",
                                   "android-test",
                                   "linux-arm-test",
                                   "linux-mips-test",
                                   ],
                    builderDependencies=[
                                  ["windows-test", "windows-smoke"], 
                                  ["windows64-test", "windows64-smoke"], 
                                  ["mac-intel-10.5-test", "mac-intel-10.5-smoke"],
                                  ["mac64-intel-test", "mac64-intel-smoke"],
                                  ["linux-test", "linux-smoke"],
                                  ["linux2-test", "linux2-smoke"],
                                  ["linux64-test", "linux64-smoke"],
                                  ["solaris-sparc-test", "solaris-sparc-smoke"],
                                  ["android-test", "android-smoke"],
                                  ["linux-arm-test", "linux-arm-smoke"],
                                  ["linux-mips-test", "linux-mips-smoke"],
                                 ])

    deep = PhaseTwoScheduler(name="deep", branch=BRANCHES_DEEP, treeStableTimer=30, properties={'silent':'false'},
                    fileIsImportant=startCompile, priority=2, changeDir="changes/deep/processed",
                    builderNames=[
                                    "windows-deep",
                                    "windows64-deep",                                    
                                    "mac-deep",
                                    "mac64-deep",
                                    "linux-deep",
                                    "linux-arm-deep",
                                    "linux-mips-deep",
                                    "solaris-sparc-deep", "solaris-sparc2-deep",                                    
                                    "windows-frr",                                    
                                                                    ],
                    builderDependencies=[
                                  ["windows-deep", "windows-test"],
                                  ["windows64-deep", "windows64-test"],
                                  ["mac-deep","mac-intel-10.5-test"],
                                  ["mac64-deep","mac64-intel-test"],                                  
                                  ["linux-deep", "linux-test"],
                                  ["linux-arm-deep", "linux-arm-test"],
                                  ["linux-mips-deep", "linux-mips-test"],                                  
                                  ["solaris-sparc-deep", "solaris-sparc-test"],
                                  ["solaris-sparc2-deep", "solaris-sparc-test"],
                                  ["windows-frr", "windows-test"],                                   
                                 ])
    
    # The promote_build phase only runs when deep passes all tests.
    promote_build = Dependent(name="promote_build", upstream=deep, properties={'silent':'false'},
                        builderNames=["promote-build"],
                    )
    

    
    schedulers = [compile, smoke, test, deep, promote_build]
    
    

    ################################################################################
    ################################################################################
    ####                                                                        ####
    ####                          COMPILE BUILDERS                              ####
    ####                                                                        ####
    ################################################################################
    ################################################################################

    #####################################
    #### builder for windows-compile ####
    #####################################

    windows_compile_factory = factory.BuildFactory()
    windows_compile_factory.addStep(sync_clean)
    windows_compile_factory.addStep(sync_clone_sandbox)
    windows_compile_factory.addStep(sync_update)
    windows_compile_factory.addStep(bb_slaveupdate(slave="windows"))
    windows_compile_factory.addStep(compile_builtin)
    windows_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args=" ", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    windows_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-debug", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    windows_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-debugger", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    windows_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-debug --enable-debugger", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    windows_compile_factory.addStep(compile_buildcheck)
    windows_compile_factory.addStep(util_upload_asteam)
    windows_compile_factory.addStep(BuildShellCommand(
                command=['../all/file-check.py', '../../../../../repo'],
                env={'branch': WithProperties('%s','branch')},
                description='running file-check against source...',
                descriptionDone='finished file-check.',
                name="FileCheck",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    windows_compile_factory.addStep(BuildShellCommand(
                command=['./build-release-sizereport.sh',WithProperties('%s','revision')],
                env={'branch': WithProperties('%s','branch')},
                description='starting win release-sizereport build...',
                descriptionDone='finished win release-sizereport build.',
                name='Build_Release_sizereport',
                workdir="../repo/build/buildbot/slaves/scripts")
    )

    windows_compile_builder = {
                'name': "windows-compile",
                'slavename': "windows",
                'factory': windows_compile_factory,
                'builddir': './windows-compile',
    }




    #######################################
    #### builder for windows64-compile ####
    #######################################
    windows_64_compile_factory = factory.BuildFactory()
    windows_64_compile_factory.addStep(sync_clean)
    windows_64_compile_factory.addStep(sync_clone_sandbox)
    windows_64_compile_factory.addStep(sync_update)
    windows_64_compile_factory.addStep(bb_slaveupdate(slave="windows64"))
    windows_64_compile_factory.addStep(compile_builtin)
    windows_64_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell_64", args="--target=x86_64-win", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64"))
    windows_64_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d_64", args="--enable-debug --target=x86_64-win", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64"))
    windows_64_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s_64", args="--enable-debugger --target=x86_64-win", upload="false", features="'+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER"))
    windows_64_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd_64", args="--enable-debug --enable-debugger --target=x86_64-win", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER"))
    windows_64_compile_factory.addStep(compile_buildcheck)
    windows_64_compile_factory.addStep(util_upload_asteam)

    windows_64_compile_builder = {
                'name': "windows64-compile",
                'slavename': "windows64",
                'factory': windows_64_compile_factory,
                'builddir': './windows64-compile',
    }


    ############################################
    #### builder for mac-intel-10_5-compile ####
    ############################################
    mac_intel_105_compile_factory = factory.BuildFactory()
    mac_intel_105_compile_factory.addStep(sync_clean)
    mac_intel_105_compile_factory.addStep(sync_clone_sandbox)
    mac_intel_105_compile_factory.addStep(sync_update)
    mac_intel_105_compile_factory.addStep(bb_slaveupdate(slave="mac-intel-10_5"))
    mac_intel_105_compile_factory.addStep(compile_builtin)
    mac_intel_105_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--mac-sdk=105 --target=i686-darwin", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    mac_intel_105_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-debug --mac-sdk=105 --target=i686-darwin", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    mac_intel_105_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-debugger --mac-sdk=105 --target=i686-darwin", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    mac_intel_105_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-debug --enable-debugger --mac-sdk=105 --target=i686-darwin", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    mac_intel_105_compile_factory.addStep(compile_buildcheck)
    mac_intel_105_compile_factory.addStep(util_upload_asteam)

    mac_intel_105_compile_builder = {
                'name': "mac-intel-10.5-compile",
                'slavename': "mac-intel-10_5",
                'factory': mac_intel_105_compile_factory,
                'builddir': './mac-intel-10_5-compile',
    }


    ##########################################
    #### builder for mac-intel-64-compile ####
    ##########################################
    mac_intel_64_compile_factory = factory.BuildFactory()
    mac_intel_64_compile_factory.addStep(sync_clean)
    mac_intel_64_compile_factory.addStep(sync_clone_sandbox)
    mac_intel_64_compile_factory.addStep(sync_update)
    mac_intel_64_compile_factory.addStep(bb_slaveupdate(slave="mac64-intel"))
    mac_intel_64_compile_factory.addStep(compile_builtin)
    mac_intel_64_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell_64", args="--target=x86_64-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64"))
    mac_intel_64_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d_64", args="--enable-debug --target=x86_64-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64"))
    mac_intel_64_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s_64", args="--enable-debugger --target=x86_64-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER"))
    mac_intel_64_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd_64", args="--enable-debug --enable-debugger --target=x86_64-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER"))
    mac_intel_64_compile_factory.addStep(compile_buildcheck)
    mac_intel_64_compile_factory.addStep(util_upload_asteam)

    mac_intel_64_compile_builder = {
                'name': "mac64-intel-compile",
                'slavename': "mac64-intel",
                'factory': mac_intel_64_compile_factory,
                'builddir': './mac64-intel-compile',
    }


    ###################################
    #### builder for linux-compile ####
    ###################################
    linux_compile_factory = factory.BuildFactory()
    linux_compile_factory.addStep(sync_clean)
    linux_compile_factory.addStep(sync_clone_sandbox)
    linux_compile_factory.addStep(sync_update)
    linux_compile_factory.addStep(bb_slaveupdate(slave="linux"))
    linux_compile_factory.addStep(compile_builtin)
    linux_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    linux_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-debug --target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    linux_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-debugger --target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    linux_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-debug --enable-debugger --target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    linux_compile_factory.addStep(compile_buildcheck)
    linux_compile_factory.addStep(util_upload_asteam)

    linux_compile_builder = {
                'name': "linux-compile",
                'slavename': "linux",
                'factory': linux_compile_factory,
                'builddir': './linux-compile',
    }


    #####################################
    #### builder for linux64-compile ####
    #####################################
    linux_64_compile_factory = factory.BuildFactory()
    linux_64_compile_factory.addStep(sync_clean)
    linux_64_compile_factory.addStep(sync_clone_sandbox)
    linux_64_compile_factory.addStep(sync_update)
    linux_64_compile_factory.addStep(bb_slaveupdate(slave="linux64"))
    linux_64_compile_factory.addStep(compile_builtin)
    linux_64_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell_64", args=" ", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64"))
    linux_64_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d_64", args="--enable-debug", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64"))
    linux_64_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s_64", args="--enable-debugger", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER"))
    linux_64_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd_64", args="--enable-debug --enable-debugger", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER"))
    linux_64_compile_factory.addStep(compile_testmedia)
    linux_64_compile_factory.addStep(compile_buildcheck_local)
    linux_64_compile_factory.addStep(util_upload_asteam_local)

    linux_64_compile_builder = {
                'name': "linux64-compile",
                'slavename': "linux64",
                'factory': linux_64_compile_factory,
                'builddir': './linux64-compile',
    }


    ###########################################
    #### builder for solaris-sparc-compile ####
    ###########################################
    solaris_sparc_compile_factory = factory.BuildFactory()
    solaris_sparc_compile_factory.addStep(sync_clean)
    solaris_sparc_compile_factory.addStep(sync_clone_sandbox)
    solaris_sparc_compile_factory.addStep(sync_update)
    solaris_sparc_compile_factory.addStep(bb_slaveupdate(slave="solaris-sparc"))
    solaris_sparc_compile_factory.addStep(compile_builtin)
    solaris_sparc_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args=" ", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_SPARC"))
    solaris_sparc_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-debugger", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_SPARC +AVMFEATURE_DEBUGGER"))
    solaris_sparc_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-debug --enable-debugger", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_SPARC +AVMFEATURE_DEBUGGER"))
    solaris_sparc_compile_factory.addStep(compile_buildcheck_local)
    solaris_sparc_compile_factory.addStep(util_upload_asteam)

    solaris_sparc_compile_builder = {
                'name': "solaris-sparc-compile",
                'slavename': "solaris-sparc",
                'factory': solaris_sparc_compile_factory,
                'builddir': './solaris-sparc-compile',
    }


    ###########################################
    #### builder for android on mac        ####
    ###########################################

    android_compile_factory = factory.BuildFactory()
    android_compile_factory.addStep(sync_clean)
    android_compile_factory.addStep(sync_clone_sandbox)
    android_compile_factory.addStep(sync_update)
    android_compile_factory.addStep(bb_slaveupdate(slave="android"))
    android_compile_factory.addStep(compile_builtin)
    android_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--arm-arch=armv7-a --target=arm-android", upload="false"))
    android_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-debug --arm-arch=armv7-a --target=arm-android", upload="false"))
    android_compile_factory.addStep(compile_buildcheck_local)
    android_compile_factory.addStep(util_upload_asteam_local)
    
    android_compile_builder = {
                'name': "android-compile",
                'slavename': "android",
                'factory': android_compile_factory,
                'builddir': './android-compile',
    }

    ###############################
    #### builder for linux-arm ####
    ###############################
    linux_arm_compile_factory = factory.BuildFactory()
    linux_arm_compile_factory.addStep(sync_clean)
    linux_arm_compile_factory.addStep(sync_clone_sandbox)
    linux_arm_compile_factory.addStep(sync_update)
    linux_arm_compile_factory.addStep(bb_slaveupdate(slave="linux-arm"))
    linux_arm_compile_factory.addStep(compile_builtin)
    linux_arm_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell_neon_arm", args="--enable-arm-neon --arm-arch=armv7-a --target=arm-linux --enable-sys-root-dir=/usr/local/arm-linux/debian5", upload="false", features=""))
    linux_arm_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_neon_arm_d", args="--enable-debug --enable-arm-neon --arm-arch=armv7-a --target=arm-linux --enable-sys-root-dir=/usr/local/arm-linux/debian5", upload="false", features=""))
    linux_arm_compile_factory.addStep(compile_buildcheck_local)
    linux_arm_compile_factory.addStep(util_upload_asteam_local)

    linux_arm_compile_builder = {
                'name': "linux-arm-compile",
                'slavename': "linux-arm",
                'factory': linux_arm_compile_factory,
                'builddir': './linux-arm-compile',
    }
    
    
    ################################
    #### builder for linux-mips ####
    ################################
    linux_mips_compile_factory = factory.BuildFactory()
    linux_mips_compile_factory.addStep(sync_clean)
    linux_mips_compile_factory.addStep(sync_clone_sandbox)
    linux_mips_compile_factory.addStep(sync_update)
    linux_mips_compile_factory.addStep(bb_slaveupdate(slave="linux-mips"))
    linux_mips_compile_factory.addStep(compile_builtin)
    linux_mips_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--target=mips-linux', 'avmshell_mips', 'false'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'CXX': 'mipsel-linux-uclibc-g++ -static',
                    'CC' : 'mipsel-linux-uclibc-gcc -static',
                    'LD' : 'mipsel-linux-uclibc-ld',
                    'AR' : 'mipsel-linux-uclibc-ar',
                },
                description='starting Release-mips-linux build...',
                descriptionDone='finished Release-mips-linux build.',
                name="Release_mips-linux",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    linux_mips_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-debug --target=mips-linux', 'avmshell_mips_d', 'false'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'CXX': 'mipsel-linux-uclibc-g++ -static',
                    'CC' : 'mipsel-linux-uclibc-gcc -static',
                    'LD' : 'mipsel-linux-uclibc-ld',
                    'AR' : 'mipsel-linux-uclibc-ar',
                },
                description='starting Debug-mips-linux build...',
                descriptionDone='finished Debug-mips-linux build.',
                name="Debug_mips-linux",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    linux_mips_compile_factory.addStep(compile_buildcheck_local)
    linux_mips_compile_factory.addStep(util_upload_asteam_local)
    
    linux_mips_compile_builder = {
                'name': "linux-mips-compile",
                'slavename': "linux-mips",
                'factory': linux_mips_compile_factory,
                'builddir': './linux-mips-compile',
    }

    

    ################################################################################
    ################################################################################
    ####                                                                        ####
    ####                            SMOKE BUILDERS                              ####
    ####                                                                        ####
    ################################################################################
    ################################################################################




    ###################################
    #### builder for windows-smoke ####
    ###################################
    windows_smoke_factory = factory.BuildFactory()
    windows_smoke_factory.addStep(download_testmedia)
    windows_smoke_factory.addStep(test_smoke)
    windows_smoke_factory.addStep(util_process_clean)

    windows_smoke_builder = {
                'name': "windows-smoke",
                'slavename': "windows",
                'factory': windows_smoke_factory,
                'builddir': './windows-smoke',
    }


    #####################################
    #### builder for windows64-smoke ####
    #####################################
    windows_64_smoke_factory = factory.BuildFactory()
    windows_64_smoke_factory.addStep(download_testmedia)
    windows_64_smoke_factory.addStep(test_smoke)
    windows_64_smoke_factory.addStep(util_process_clean)

    windows_64_smoke_builder = {
                'name': "windows64-smoke",
                'slavename': "windows64",
                'factory': windows_64_smoke_factory,
                'builddir': './windows64-smoke',
    }


    ##########################################
    #### builder for mac-intel-10_5-smoke ####
    ##########################################
    mac_intel_105_smoke_factory = factory.BuildFactory()
    mac_intel_105_smoke_factory.addStep(download_testmedia)
    mac_intel_105_smoke_factory.addStep(test_smoke)
    mac_intel_105_smoke_factory.addStep(util_process_clean)

    mac_intel_105_smoke_builder = {
                'name': "mac-intel-10.5-smoke",
                'slavename': "mac-intel-10_5",
                'factory': mac_intel_105_smoke_factory,
                'builddir': './mac-intel-10_5-smoke',
    }


    #######################################
    #### builder for mac64-intel-smoke ####
    #######################################
    mac_intel_64_smoke_factory = factory.BuildFactory()
    mac_intel_64_smoke_factory.addStep(download_testmedia)
    mac_intel_64_smoke_factory.addStep(test_smoke)
    mac_intel_64_smoke_factory.addStep(util_process_clean)

    mac_intel_64_smoke_builder = {
                'name': "mac64-intel-smoke",
                'slavename': "mac64-intel",
                'factory': mac_intel_64_smoke_factory,
                'builddir': './mac64-intel-smoke',
    }



    #################################
    #### builder for linux-smoke ####
    #################################
    linux_smoke_factory = factory.BuildFactory()
    linux_smoke_factory.addStep(download_testmedia)
    linux_smoke_factory.addStep(test_smoke)
    linux_smoke_factory.addStep(util_process_clean)

    linux_smoke_builder = {
                'name': "linux-smoke",
                'slavename': "linux",
                'factory': linux_smoke_factory,
                'builddir': './linux-smoke',
    }


    ###################################
    #### builder for linux64-smoke ####
    ###################################
    linux_64_smoke_factory = factory.BuildFactory()
    linux_64_smoke_factory.addStep(download_testmedia)
    linux_64_smoke_factory.addStep(test_smoke)
    linux_64_smoke_factory.addStep(util_process_clean)

    linux_64_smoke_builder = {
                'name': "linux64-smoke",
                'slavename': "linux64",
                'factory': linux_64_smoke_factory,
                'builddir': './linux64-smoke',
    }


    #########################################
    #### builder for solaris-sparc-smoke ####
    #########################################
    solaris_sparc_smoke_factory = factory.BuildFactory()
    solaris_sparc_smoke_factory.addStep(download_testmedia)
    solaris_sparc_smoke_factory.addStep(test_smoke)
    solaris_sparc_smoke_factory.addStep(util_process_clean)

    solaris_sparc_smoke_builder = {
                'name': "solaris-sparc-smoke",
                'slavename': "solaris-sparc",
                'factory': solaris_sparc_smoke_factory,
                'builddir': './solaris-sparc-smoke',
    }


    #########################################
    #### builder for android-smoke       ####
    #########################################
    android_smoke_factory = factory.BuildFactory()
    android_smoke_factory.addStep(download_testmedia)
    android_smoke_factory.addStep(test_smoke_local)
    android_smoke_factory.addStep(util_process_clean)

    android_smoke_builder = {
                'name': "android-smoke",
                'slavename': "android",
                'factory': android_smoke_factory,
                'builddir': './android-smoke',
    }

    ###########################################
    #### builder for linxu-arm-smoke       ####
    ###########################################
    linux_arm_smoke_factory = factory.BuildFactory()
    linux_arm_smoke_factory.addStep(download_testmedia)
    linux_arm_smoke_factory.addStep(TestSuiteShellCommand(
                command=['../all/run-smoketests-ssh.sh', WithProperties('%s','revision'), './runsmokes-ssh.txt'],
                env={'branch': WithProperties('%s','branch')},
                description='starting to run smoke tests...',
                descriptionDone='finished smoke tests.',
                name="SmokeTest",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    linux_arm_smoke_factory.addStep(util_process_clean)

    linux_arm_smoke_builder = {
                'name': "linux-arm-smoke",
                'slavename': "linux-arm",
                'factory': linux_arm_smoke_factory,
                'builddir': './linux-arm-smoke',
    }
    
    
    #########################################
    #### builder for linux-mips-smoke    ####
    #########################################
    linux_mips_smoke_factory = factory.BuildFactory()
    linux_mips_smoke_factory.addStep(download_testmedia)
    linux_mips_smoke_factory.addStep(test_smoke_ssh)
    linux_mips_smoke_factory.addStep(util_process_clean_ssh)

    linux_mips_smoke_builder = {
                'name': "linux-mips-smoke",
                'slavename': "linux-mips",
                'factory': linux_mips_smoke_factory,
                'builddir': './linux-mips-smoke',
    }



    ################################################################################
    ################################################################################
    ####                                                                        ####
    ####                            TEST BUILDERS                               ####
    ####                                                                        ####
    ################################################################################
    ################################################################################




    ##################################
    #### builder for windows-test ####
    ##################################
    windows_test_factory = factory.BuildFactory()
    windows_test_factory.addStep(test_commandline)
    windows_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    windows_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    windows_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    windows_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    windows_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs=""))
    windows_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    windows_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs=""))
    windows_test_factory.addStep(test_differential)
    windows_test_factory.addStep(util_process_clean)
    windows_test_factory.addStep(util_clean_buildsdir)
    windows_test_factory.addStep(sync_clean)
    
    windows_test_builder = {
                'name': "windows-test",
                'slavename': "windows",
                'factory': windows_test_factory,
                'builddir': './windows-test',
    }


    ####################################
    #### builder for windows64-test ####
    ####################################
    windows_64_test_factory = factory.BuildFactory()
    windows_64_test_factory.addStep(test_commandline)
    windows_64_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_64"))
    windows_64_test_factory.addStep(test_generic(name="Release", shellname="avmshell_64", vmargs="", config="", scriptargs=""))
    windows_64_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_64", vmargs="-Dinterp", config="", scriptargs=""))
    windows_64_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell_64", vmargs="-Ojit", config="", scriptargs=""))
    windows_64_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s_64", vmargs="", config="", scriptargs=""))
    windows_64_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_64", vmargs="", config="", scriptargs=""))
    windows_64_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_64", vmargs="", config="", scriptargs=""))
    windows_64_test_factory.addStep(util_process_clean)
    windows_64_test_factory.addStep(util_clean_buildsdir)
    windows_64_test_factory.addStep(sync_clean)

    windows_64_test_builder = {
                'name': "windows64-test",
                'slavename': "windows64",
                'factory': windows_64_test_factory,
                'builddir': './windows64-test',
    }


    #########################################
    #### builder for mac-intel-10_5-test ####
    #########################################
    mac_intel_105_test_factory = factory.BuildFactory()
    mac_intel_105_test_factory.addStep(test_commandline)
    mac_intel_105_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    mac_intel_105_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    mac_intel_105_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    mac_intel_105_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    mac_intel_105_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs=""))
    mac_intel_105_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    mac_intel_105_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs=""))
    mac_intel_105_test_factory.addStep(test_differential)
    mac_intel_105_test_factory.addStep(util_process_clean)
    mac_intel_105_test_factory.addStep(util_clean_buildsdir)
    mac_intel_105_test_factory.addStep(sync_clean)

    mac_intel_105_test_builder = {
                'name': "mac-intel-10.5-test",
                'slavename': "mac-intel-10_5",
                'factory': mac_intel_105_test_factory,
                'builddir': './mac-intel-10_5-test',
    }


    ######################################
    #### builder for mac64-intel-test ####
    ######################################
    mac_intel_64_test_factory = factory.BuildFactory()
    mac_intel_64_test_factory.addStep(test_commandline)
    mac_intel_64_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_64"))
    mac_intel_64_test_factory.addStep(test_generic(name="Release", shellname="avmshell_64", vmargs="", config="", scriptargs=""))
    mac_intel_64_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_64", vmargs="-Dinterp", config="", scriptargs=""))
    mac_intel_64_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell_64", vmargs="-Ojit", config="", scriptargs=""))
    mac_intel_64_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s_64", vmargs="", config="", scriptargs=""))
    mac_intel_64_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_64", vmargs="", config="", scriptargs=""))
    mac_intel_64_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_64", vmargs="", config="", scriptargs=""))
    mac_intel_64_test_factory.addStep(util_process_clean)
    mac_intel_64_test_factory.addStep(util_clean_buildsdir)
    mac_intel_64_test_factory.addStep(sync_clean)

    mac_intel_64_test_builder = {
                'name': "mac64-intel-test",
                'slavename': "mac64-intel",
                'factory': mac_intel_64_test_factory,
                'builddir': './mac64-intel-test',
    }


    ################################
    #### builder for linux-test ####
    ################################
    linux_test_factory = factory.BuildFactory()
    linux_test_factory.addStep(test_commandline)
    linux_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    linux_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    linux_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    linux_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    linux_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs=""))
    linux_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    linux_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs=""))
    linux_test_factory.addStep(test_differential)
    linux_test_factory.addStep(util_process_clean)
    linux_test_factory.addStep(util_clean_buildsdir)
    linux_test_factory.addStep(sync_clean)

    linux_test_builder = {
                'name': "linux-test",
                'slavename': "linux",
                'factory': linux_test_factory,
                'builddir': './linux-test',
    }


    ##################################
    #### builder for linux64-test ####
    ##################################
    linux_64_test_factory = factory.BuildFactory()
    linux_64_test_factory.addStep(test_commandline)
    linux_64_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_64"))
    linux_64_test_factory.addStep(test_generic(name="Release", shellname="avmshell_64", vmargs="", config="", scriptargs=""))
    linux_64_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_64", vmargs="-Dinterp", config="", scriptargs=""))
    linux_64_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell_64", vmargs="-Ojit", config="", scriptargs=""))
    linux_64_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s_64", vmargs="", config="", scriptargs=""))
    linux_64_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_64", vmargs="", config="", scriptargs=""))
    linux_64_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_64", vmargs="", config="", scriptargs=""))
    linux_64_test_factory.addStep(util_process_clean)
    linux_64_test_factory.addStep(util_clean_buildsdir)
    linux_64_test_factory.addStep(sync_clean)

    linux_64_test_builder = {
                'name': "linux64-test",
                'slavename': "linux64",
                'factory': linux_64_test_factory,
                'builddir': './linux64-test',
    }


    ########################################
    #### builder for solaris-sparc-test ####
    ########################################
    solaris_sparc_test_factory = factory.BuildFactory()
    solaris_sparc_test_factory.addStep(test_commandline)
    solaris_sparc_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    solaris_sparc_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs="--random --timeout=420"))
    solaris_sparc_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs="--random --timeout=420"))
    solaris_sparc_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs="--random --timeout=420"))
    solaris_sparc_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs="--random --timeout=420"))
    solaris_sparc_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs="--random --timeout=420"))
    solaris_sparc_test_factory.addStep(util_process_clean)
    solaris_sparc_test_factory.addStep(util_clean_buildsdir)
    solaris_sparc_test_factory.addStep(sync_clean)

    solaris_sparc_test_builder = {
                'name': "solaris-sparc-test",
                'slavename': "solaris-sparc",
                'factory': solaris_sparc_test_factory,
                'builddir': './solaris-sparc-test',
    }


    ########################################
    #### builder for android-test       ####
    ########################################
    android_test_factory = factory.BuildFactory()
    android_test_factory.addStep(test_generic_adb(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    android_test_factory.addStep(test_generic_adb(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    android_test_factory.addStep(test_generic_adb(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    android_test_factory.addStep(test_generic_adb(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    android_test_factory.addStep(util_process_clean)
    android_test_factory.addStep(util_clean_buildsdir)
    android_test_factory.addStep(sync_clean)

    android_test_builder = {
                'name': "android-test",
                'slavename': "android",
                'factory': android_test_factory,
                'builddir': './android-test',
    }
    
    
    ##########################################
    #### builder for linux-arm-test       ####
    ##########################################
    linux_arm_test_factory = factory.BuildFactory()
    linux_arm_test_factory.addStep(test_selftest_ssh(name="Release", shellname="avmshell_neon_arm"))
    linux_arm_test_factory.addStep(test_generic_ssh(name="Release-vfp", shellname="avmshell_neon_arm", vmargs="-Darm_arch 7 -Darm_vfp", config="arm-lnx-tvm-release", scriptargs=""))
    linux_arm_test_factory.addStep(test_generic_ssh(name="Release-interp", shellname="avmshell_neon_arm", vmargs="-Dinterp", config="arm-lnx-tvm-release-Dinterp", scriptargs=""))
    linux_arm_test_factory.addStep(test_generic_ssh(name="Release-jit-vfp", shellname="avmshell_neon_arm", vmargs="-Darm_arch 7 -Darm_vfp -Ojit", config="arm-lnx-tvm-release-Ojit", scriptargs=""))
    linux_arm_test_factory.addStep(util_acceptance_clean_ssh)
    linux_arm_test_factory.addStep(util_clean_buildsdir)
    linux_arm_test_factory.addStep(sync_clean)

    linux_arm_test_builder = {
                'name': "linux-arm-test",
                'slavename': "linux-arm",
                'factory': linux_arm_test_factory,
                'builddir': './linux-arm-test',
    }
    
    
    ##########################################
    #### builder for linux-mips-test      ####
    ##########################################
    linux_mips_test_factory = factory.BuildFactory()
    linux_mips_test_factory.addStep(test_generic_ssh(name="Release", shellname="avmshell_mips", vmargs="", config="mips-lnx-tvm-release", scriptargs=""))
    linux_mips_test_factory.addStep(test_generic_ssh(name="Debug", shellname="avmshell_mips_d", vmargs="", config="mips-lnx-tvm-debug", scriptargs=""))
    linux_mips_test_factory.addStep(util_acceptance_clean_ssh)
    linux_mips_test_factory.addStep(util_clean_buildsdir)
    linux_mips_test_factory.addStep(sync_clean)

    linux_mips_test_builder = {
                'name': "linux-mips-test",
                'slavename': "linux-mips",
                'factory': linux_mips_test_factory,
                'builddir': './linux-mips-test',
    }

    ################################################################################
    ################################################################################
    ####                                                                        ####
    ####                       DEEP TEST BUILDERS                               ####
    ####                                                                        ####
    ################################################################################
    ################################################################################


    ##################################
    #### builder for windows-deep ####
    ##################################
    windows_deep_factory = factory.BuildFactory()
    windows_deep_factory.addStep(sync_clean)
    windows_deep_factory.addStep(sync_clone_sandbox)
    windows_deep_factory.addStep(sync_update)
    windows_deep_factory.addStep(bb_slaveupdate(slave="windows-deep"))
    windows_deep_factory.addStep(compile_builtin)
    windows_deep_factory.addStep(compile_generic(name="Release-wordcode", shellname="avmshell_wordcode", args="--enable-wordcode-interp", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_WORDCODE_INTERP"))
    windows_deep_factory.addStep(compile_generic(name="DebugDebugger-wordcode", shellname="avmshell_sd_wordcode", args="--enable-debug --enable-debugger --enable-wordcode-interp", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_WORDCODE_INTERP"))    
    windows_deep_factory.addStep(download_testmedia)
    windows_deep_factory.addStep(deep_release_esc)
    windows_deep_factory.addStep(test_misc)
    windows_deep_factory.addStep(test_selftest(name="Debug", shellname="avmshell_d"))
    windows_deep_factory.addStep(test_selftest(name="ReleaseDebugger", shellname="avmshell_s"))
    windows_deep_factory.addStep(test_selftest(name="DebugDebugger", shellname="avmshell_sd"))
    windows_deep_factory.addStep(test_generic(name="Release-wordcode-interp", shellname="avmshell_wordcode", vmargs="-Dinterp", config="", scriptargs=""))
    windows_deep_factory.addStep(test_generic(name="DebugDebugger-wordcode-interp", shellname="avmshell_sd_wordcode", vmargs="-Dinterp", config="", scriptargs=""))
    windows_deep_factory.addStep(compile_generic(name="ReleaseDebugger-air", shellname="avmshell_air", args="--enable-override-global-new --enable-use-system-malloc --enable-debugger", upload="true", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER +AVMFEATURE_OVERRIDE_GLOBAL_NEW +AVMFEATURE_USE_SYSTEM_MALLOC"))
    windows_deep_factory.addStep(test_generic(name="ReleaseDebugger-air", shellname="avmshell_air", vmargs="", config="", scriptargs=""))
    windows_deep_factory.addStep(test_generic(name="Release-Dgreedy", shellname="avmshell", vmargs="-Dgreedy", config="", scriptargs="--timeout=180 --random"))
    windows_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyAll", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verify --timeout=300 --random"))
    windows_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyOnly", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verifyonly --timeout=300 --random"))
    windows_deep_factory.addStep(test_generic(name="Release-GCthreshold", shellname="avmshell", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    windows_deep_factory.addStep(test_generic(name="DebugDebugger-GCthreshold", shellname="avmshell_sd", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    windows_deep_factory.addStep(compile_generic(name="ReleaseHeapGraph", shellname="avmshell_heapgraph", args="--enable-heap-graph", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMTWEAK_HEAP_GRAPH"))
    windows_deep_factory.addStep(test_selftest(name="ReleaseHeapGraph", shellname="avmshell_heapgraph"))
    windows_deep_factory.addStep(BuildShellCommand(
                command=['./build-vtune.sh', WithProperties('%s','revision')],
                env={'branch': WithProperties('%s','branch')},
                description='starting VTune build...',
                descriptionDone='finished VTune build.',
                name="VTune",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    # Do a test run where we compile with -ES. MUST be the last step of the build as it recompiles the .abc files used by all the other steps
    windows_deep_factory.addStep(test_generic(name="Release_ES", shellname="avmshell", vmargs="", config="",
                                              scriptargs="--ascargs=-no-AS3 --addtoconfig=-ES -f -x abcasm,ecma3,spidermonkey"))
    windows_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run
    windows_deep_factory.addStep(util_process_clean)
    windows_deep_factory.addStep(util_clean_buildsdir)
    windows_deep_factory.addStep(sync_clean)

    windows_deep_builder = {
                'name': "windows-deep",
                'slavename': "windows-deep",
                'factory': windows_deep_factory,
                'builddir': './windows-deep',
    }

    ##################################
    #### builder for windows64-deep ####
    ##################################
    windows_64_deep_factory = factory.BuildFactory()
    windows_64_deep_factory.addStep(sync_clean)
    windows_64_deep_factory.addStep(sync_clone_sandbox)
    windows_64_deep_factory.addStep(sync_update)
    windows_64_deep_factory.addStep(bb_slaveupdate(slave="windows64-deep"))
    windows_64_deep_factory.addStep(compile_builtin)
    windows_64_deep_factory.addStep(compile_generic(name="Release-wordcode", shellname="avmshell_wordcode_64", args="--enable-wordcode-interp --target=x86_64-win", upload="true", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_WORDCODE_INTERP"))
    windows_64_deep_factory.addStep(compile_generic(name="DebugDebugger-wordcode", shellname="avmshell_sd_wordcode_64", args="--enable-debug --enable-debugger --enable-wordcode-interp --target=x86_64-win", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_WORDCODE_INTERP"))    
    windows_64_deep_factory.addStep(download_testmedia)
    windows_64_deep_factory.addStep(test_selftest(name="Debug", shellname="avmshell_d_64"))
    windows_64_deep_factory.addStep(test_selftest(name="ReleaseDebugger", shellname="avmshell_s_64"))
    windows_64_deep_factory.addStep(test_selftest(name="DebugDebugger", shellname="avmshell_sd_64"))
    windows_64_deep_factory.addStep(test_generic(name="Release-wordcode-interp", shellname="avmshell_wordcode_64", vmargs="-Dinterp", config="", scriptargs=""))
    windows_64_deep_factory.addStep(test_generic(name="DebugDebugger-wordcode-interp", shellname="avmshell_sd_wordcode_64", vmargs="-Dinterp", config="", scriptargs=""))
    windows_64_deep_factory.addStep(compile_generic(name="ReleaseDebugger-air", shellname="avmshell_air_64", args="--enable-override-global-new --enable-use-system-malloc --enable-debugger --target=x86_64-win", upload="true", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER +AVMFEATURE_OVERRIDE_GLOBAL_NEW +AVMFEATURE_USE_SYSTEM_MALLOC"))
    windows_64_deep_factory.addStep(test_generic(name="ReleaseDebugger-air", shellname="avmshell_air_64", vmargs="", config="", scriptargs=""))
    windows_64_deep_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_64", vmargs="", config="x64-win-tvm-debug-deep", scriptargs=""))
    windows_64_deep_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_64", vmargs="", config="x64-win-tvm-debugdebugger-deep", scriptargs=""))
    windows_64_deep_factory.addStep(deep_release_esc)
    windows_64_deep_factory.addStep(test_generic(name="ReleaseDebugger-Dverifyall", shellname="avmshell_s_64", vmargs="-Dverifyall", config="", scriptargs=""))
    windows_64_deep_factory.addStep(test_generic(name="DebugDebugger-Dverifyall", shellname="avmshell_sd_64", vmargs="-Dverifyall", config="", scriptargs=""))
    windows_64_deep_factory.addStep(test_generic(name="Release-GCthreshold", shellname="avmshell_64", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    windows_64_deep_factory.addStep(test_generic(name="DebugDebugger-GCthreshold", shellname="avmshell_sd_64", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    windows_64_deep_factory.addStep(compile_generic(name="ReleaseHeapGraph", shellname="avmshell_heapgraph_64", args="--enable-heap-graph --target=x86_64-win", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMTWEAK_HEAP_GRAPH"))
    windows_64_deep_factory.addStep(test_selftest(name="ReleaseHeapGraph", shellname="avmshell_heapgraph_64"))
    windows_64_deep_factory.addStep( TestSuiteShellCommand(
                command=['../all/run-acceptance-avmdiff-3264.sh', WithProperties('%s','revision')],
                env={'branch': WithProperties('%s','branch')},
                description='starting to run 32-64 differential vmtests...',
                descriptionDone='finished 32-64 differential vmtests.',
                name="Testsuite_Differential3264",
                workdir="../repo/build/buildbot/slaves/scripts"
                )
    )
    windows_64_deep_factory.addStep(test_misc)
    windows_64_deep_factory.addStep(test_generic(name="Release-Dgreedy", shellname="avmshell_64", vmargs="-Dgreedy", config="", scriptargs="--timeout=180 --random"))
    windows_64_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyAll", shellname="avmshell_sd_64", vmargs="", config="", scriptargs="--verify --timeout=300 --random"))
    windows_64_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyOnly", shellname="avmshell_sd_64", vmargs="", config="", scriptargs="--verifyonly --timeout=300 --random"))
    windows_64_deep_factory.addStep(deep_codecoverage(compilecsv="../all/codecoverage-compile.csv", testcsv="../all/codecoverage-test.csv"))
    windows_64_deep_factory.addStep(deep_codecoverage_process)
    windows_64_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run in code coverage
    # Do a test run where we compile with -ES. MUST be the last step of the build as it recompiles the .abc files used by all the other steps
    windows_64_deep_factory.addStep(test_generic(name="Release_ES", shellname="avmshell", vmargs="", config="",
                                              scriptargs="--ascargs=-no-AS3 --addtoconfig=-ES -f -x abcasm,ecma3,spidermonkey"))
    windows_64_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run
    windows_64_deep_factory.addStep(util_process_clean)
    windows_64_deep_factory.addStep(util_clean_buildsdir)
    windows_64_deep_factory.addStep(sync_clean)

    windows_64_deep_builder = {
                'name': "windows64-deep",
                'slavename': "windows64-deep",
                'factory': windows_64_deep_factory,
                'builddir': './windows64-deep',
    }


    ##################################
    #### builder for mac-deep ####
    ##################################
    mac_deep_factory = factory.BuildFactory()
    mac_deep_factory.addStep(sync_clean)
    mac_deep_factory.addStep(sync_clone_sandbox)
    mac_deep_factory.addStep(sync_update)
    mac_deep_factory.addStep(bb_slaveupdate(slave="mac-deep"))
    mac_deep_factory.addStep(compile_builtin)
    mac_deep_factory.addStep(compile_generic(name="Release-wordcode", shellname="avmshell_wordcode", args="--enable-wordcode-interp --mac-sdk=105", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_WORDCODE_INTERP"))
    mac_deep_factory.addStep(compile_generic(name="DebugDebugger-wordcode", shellname="avmshell_sd_wordcode", args="--enable-debug --enable-debugger --enable-wordcode-interp --mac-sdk=105", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_WORDCODE_INTERP"))    
    mac_deep_factory.addStep(download_testmedia)
    mac_deep_factory.addStep(deep_release_esc)
    mac_deep_factory.addStep(test_misc)
    mac_deep_factory.addStep(test_selftest(name="Debug", shellname="avmshell_d"))
    mac_deep_factory.addStep(test_selftest(name="ReleaseDebugger", shellname="avmshell_s"))
    mac_deep_factory.addStep(test_selftest(name="DebugDebugger", shellname="avmshell_sd"))
    mac_deep_factory.addStep(test_generic(name="Release-wordcode-interp", shellname="avmshell_wordcode", vmargs="-Dinterp", config="", scriptargs=""))
    mac_deep_factory.addStep(test_generic(name="DebugDebugger-wordcode-interp", shellname="avmshell_sd_wordcode", vmargs="-Dinterp", config="", scriptargs=""))
    mac_deep_factory.addStep(compile_generic(name="ReleaseDebugger-air", shellname="avmshell_air", args="--enable-override-global-new --enable-use-system-malloc --enable-debugger", upload="true", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER +AVMFEATURE_OVERRIDE_GLOBAL_NEW +AVMFEATURE_USE_SYSTEM_MALLOC"))
    mac_deep_factory.addStep(test_generic(name="ReleaseDebugger-air", shellname="avmshell_air", vmargs="", config="", scriptargs=""))
    mac_deep_factory.addStep(test_generic(name="Release-Dgreedy", shellname="avmshell", vmargs="-Dgreedy", config="", scriptargs="--timeout=180 --random"))
    mac_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyAll", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verify --timeout=300 --random"))
    mac_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyOnly", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verifyonly --timeout=300 --random"))
    mac_deep_factory.addStep(test_generic(name="Release-GCthreshold", shellname="avmshell", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    mac_deep_factory.addStep(test_generic(name="DebugDebugger-GCthreshold", shellname="avmshell_sd", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    mac_deep_factory.addStep(compile_generic(name="ReleaseHeapGraph", shellname="avmshell_heapgraph", args="--enable-heap-graph --target=i686-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMTWEAK_HEAP_GRAPH"))
    mac_deep_factory.addStep(test_selftest(name="ReleaseHeapGraph", shellname="avmshell_heapgraph"))
    mac_deep_factory.addStep(deep_run_brightspot(name='ReleaseDebugger', shell='avmshell_s', testargs='--quiet'))
    mac_deep_factory.addStep(deep_codecoverage(compilecsv="../all/codecoverage-compile.csv", testcsv="../all/codecoverage-test.csv"))
    mac_deep_factory.addStep(deep_codecoverage_process)
    mac_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run in code coverage
    mac_deep_factory.addStep(BuildShellCommand(
                command=['../all/build-doxygen.sh', WithProperties('%s','revision')],
                env={'branch': WithProperties('%s','branch'), 'silent':WithProperties('%s','silent')},
                description='starting doxygen build...',
                descriptionDone='finished doxygen build.',
                name="Doxygen",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    mac_deep_factory.addStep(compile_generic(name="ReleaseDebugger-Valgrind", shellname="avmshell_s_valgrind", args="--enable-debugger --enable-valgrind", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER +AVMFEATURE_VALGRIND"))
    mac_deep_factory.addStep(test_generic(name="ReleaseDebugger-Valgrind", shellname="avmshell_s_valgrind", vmargs="", config="", scriptargs="--valgrind"))
    # Do a test run where we compile with -ES. MUST be the last step of the build as it recompiles the .abc files used by all the other steps
    mac_deep_factory.addStep(test_generic(name="Release_ES", shellname="avmshell", vmargs="", config="",
                                              scriptargs="--ascargs=-no-AS3 --addtoconfig=-ES -f -x abcasm,ecma3,spidermonkey"))
    mac_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run
    mac_deep_factory.addStep(util_process_clean)
    mac_deep_factory.addStep(util_clean_buildsdir)
    mac_deep_factory.addStep(sync_clean)

    mac_deep_builder = {
                'name': "mac-deep",
                'slavename': "mac-deep",
                'factory': mac_deep_factory,
                'builddir': './mac-deep',
    }


    ################################
    #### builder for mac64-deep ####
    ################################
    mac64_deep_factory = factory.BuildFactory()
    mac64_deep_factory.addStep(sync_clean)
    mac64_deep_factory.addStep(sync_clone_sandbox)
    mac64_deep_factory.addStep(sync_update)
    mac64_deep_factory.addStep(bb_slaveupdate(slave="mac64-deep"))
    mac64_deep_factory.addStep(compile_builtin)
    mac64_deep_factory.addStep(compile_generic(name="Release-wordcode", shellname="avmshell_wordcode_64", args="--enable-wordcode-interp --target=x86_64-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_WORDCODE_INTERP"))
    mac64_deep_factory.addStep(compile_generic(name="DebugDebugger-wordcode", shellname="avmshell_sd_wordcode_64", args="--enable-debug --enable-debugger --enable-wordcode-interp --target=x86_64-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_WORDCODE_INTERP"))    
    mac64_deep_factory.addStep(download_testmedia)
    mac64_deep_factory.addStep(deep_release_esc)
    mac64_deep_factory.addStep(test_misc)
    mac64_deep_factory.addStep(test_selftest(name="Debug", shellname="avmshell_d_64"))
    mac64_deep_factory.addStep(test_selftest(name="ReleaseDebugger", shellname="avmshell_s_64"))
    mac64_deep_factory.addStep(test_selftest(name="DebugDebugger", shellname="avmshell_sd_64"))
    mac64_deep_factory.addStep(test_generic(name="Release-wordcode-interp", shellname="avmshell_wordcode_64", vmargs="-Dinterp", config="", scriptargs=""))
    mac64_deep_factory.addStep(test_generic(name="DebugDebugger-wordcode-interp", shellname="avmshell_sd_wordcode_64", vmargs="-Dinterp", config="", scriptargs=""))
    mac64_deep_factory.addStep(compile_generic(name="ReleaseDebugger-air", shellname="avmshell_air_64", args="--target=x86_64-darwin --enable-override-global-new --enable-use-system-malloc --enable-debugger", upload="true", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER +AVMFEATURE_OVERRIDE_GLOBAL_NEW +AVMFEATURE_USE_SYSTEM_MALLOC"))
    mac64_deep_factory.addStep(test_generic(name="ReleaseDebugger-air", shellname="avmshell_air_64", vmargs="", config="", scriptargs=""))
    mac64_deep_factory.addStep(test_generic(name="Release-Dgreedy", shellname="avmshell_64", vmargs="-Dgreedy", config="", scriptargs="--timeout=180 --random"))
    mac64_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyAll", shellname="avmshell_sd_64", vmargs="", config="", scriptargs="--verify --timeout=300 --random"))
    mac64_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyOnly", shellname="avmshell_sd_64", vmargs="", config="", scriptargs="--verifyonly --timeout=300 --random"))
    mac64_deep_factory.addStep(test_generic(name="Release-GCthreshold", shellname="avmshell_64", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    mac64_deep_factory.addStep(test_generic(name="DebugDebugger-GCthreshold", shellname="avmshell_sd_64", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    mac64_deep_factory.addStep(compile_generic(name="ReleaseHeapGraph", shellname="avmshell_heapgraph_64", args="--enable-heap-graph --target=x86_64-darwin --mac-sdk=105", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMTWEAK_HEAP_GRAPH"))
    mac64_deep_factory.addStep(test_selftest(name="ReleaseHeapGraph", shellname="avmshell_heapgraph_64"))
    mac64_deep_factory.addStep(deep_run_brightspot(name='ReleaseDebugger', shell='avmshell_s_64', testargs='--quiet'))
    mac64_deep_factory.addStep(compile_generic(name="ReleaseDebugger-Valgrind", shellname="avmshell_s_valgrind_64", args="--enable-debugger --enable-valgrind --mac-sdk=105 --target=x86_64-darwin", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER +AVMFEATURE_VALGRIND"))
    mac64_deep_factory.addStep(test_generic(name="ReleaseDebugger-Valgrind", shellname="avmshell_s_valgrind_64", vmargs="", config="", scriptargs="--valgrind"))
    mac64_deep_factory.addStep(util_process_clean)
    mac64_deep_factory.addStep(util_clean_buildsdir)
    mac64_deep_factory.addStep(sync_clean)

    mac64_deep_builder = {
                'name': "mac64-deep",
                'slavename': "mac64-deep",
                'factory': mac64_deep_factory,
                'builddir': './mac64-deep',
    }


    ##################################
    #### builder for linux-deep   ####
    ##################################
    linux_deep_factory = factory.BuildFactory()
    linux_deep_factory.addStep(sync_clean)
    linux_deep_factory.addStep(sync_clone_sandbox)
    linux_deep_factory.addStep(sync_update)
    linux_deep_factory.addStep(bb_slaveupdate(slave="linux-deep"))
    linux_deep_factory.addStep(compile_builtin)
    linux_deep_factory.addStep(compile_generic(name="Release-wordcode", shellname="avmshell_wordcode_64", args="--enable-wordcode-interp", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_WORDCODE_INTERP"))
    linux_deep_factory.addStep(compile_generic(name="DebugDebugger-wordcode", shellname="avmshell_sd_wordcode_64", args="--enable-debug --enable-debugger --enable-wordcode-interp", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_WORDCODE_INTERP"))    
    linux_deep_factory.addStep(download_testmedia)
    linux_deep_factory.addStep(test_selftest(name="Debug", shellname="avmshell_d"))
    linux_deep_factory.addStep(test_selftest(name="ReleaseDebugger", shellname="avmshell_s"))
    linux_deep_factory.addStep(test_selftest(name="DebugDebugger", shellname="avmshell_sd"))
    linux_deep_factory.addStep(test_generic(name="Release-wordcode-interp", shellname="avmshell_wordcode_64", vmargs="-Dinterp", config="", scriptargs=""))
    linux_deep_factory.addStep(test_generic(name="DebugDebugger-wordcode-interp", shellname="avmshell_sd_wordcode_64", vmargs="-Dinterp", config="", scriptargs=""))
    linux_deep_factory.addStep(test_generic(name="Release-Djitordie", shellname="avmshell", vmargs="-Djitordie", config="", scriptargs=""))
    linux_deep_factory.addStep(test_generic(name="ReleaseDebugger-nodebugger", shellname="avmshell_s", vmargs="-Dnodebugger", config="", scriptargs=""))
    linux_deep_factory.addStep(test_generic(name="DebugDebugger-nodebugger", shellname="avmshell_sd", vmargs="-Dnodebugger", config="", scriptargs=""))
    linux_deep_factory.addStep(compile_generic(name="Release-system-malloc", shellname="avmshell_sysmalloc", args="--enable-use-system-malloc", upload="true", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_USE_SYSTEM_MALLOC"))
    linux_deep_factory.addStep(test_generic(name="Release-system-malloc", shellname="avmshell_sysmalloc", vmargs="", config="x86-lnx-tvm-release-use-system-malloc", scriptargs=""))
    linux_deep_factory.addStep(test_misc)
    linux_deep_factory.addStep(compile_generic(name="ReleaseDebugger-air", shellname="avmshell_air", args="--enable-override-global-new --enable-use-system-malloc --enable-debugger", upload="true", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER +AVMFEATURE_OVERRIDE_GLOBAL_NEW +AVMFEATURE_USE_SYSTEM_MALLOC"))
    linux_deep_factory.addStep(test_generic(name="ReleaseDebugger-air", shellname="avmshell_air", vmargs="", config="", scriptargs=""))
    linux_deep_factory.addStep(test_generic(name="Release-Dgreedy", shellname="avmshell", vmargs="-Dgreedy", config="", scriptargs="--timeout=180 --random"))
    linux_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyAll", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verify --timeout=300 --random"))
    linux_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyOnly", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verifyonly --timeout=300 --random"))
    linux_deep_factory.addStep(test_generic(name="Release-GCthreshold", shellname="avmshell", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    linux_deep_factory.addStep(test_generic(name="DebugDebugger-GCthreshold", shellname="avmshell_sd", vmargs="-Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="", scriptargs=""))
    linux_deep_factory.addStep(compile_generic(name="ReleaseHeapGraph", shellname="avmshell_heapgraph_64", args="--enable-heap-graph", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMTWEAK_HEAP_GRAPH"))
    linux_deep_factory.addStep(test_selftest(name="ReleaseHeapGraph", shellname="avmshell_heapgraph_64"))
    linux_deep_factory.addStep(compile_generic(name="ReleaseDebugger-Valgrind", shellname="avmshell_s_valgrind_64", args="--enable-debugger --enable-valgrind", upload="false", features="+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER +AVMFEATURE_VALGRIND"))
    linux_deep_factory.addStep(test_generic(name="ReleaseDebugger-Valgrind", shellname="avmshell_s_valgrind_64", vmargs="", config="", scriptargs="--valgrind"))
    linux_deep_factory.addStep(deep_codecoverage(compilecsv="../all/codecoverage-compile.csv", testcsv="../all/codecoverage-test.csv"))
    linux_deep_factory.addStep(deep_codecoverage_process)
    linux_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run in code coverage
    # Do a test run where we compile with -ES. MUST be the last step of the build as it recompiles the .abc files used by all the other steps
    linux_deep_factory.addStep(test_generic(name="Release_ES", shellname="avmshell", vmargs="", config="",
                                              scriptargs="--ascargs=-no-AS3 --addtoconfig=-ES -f -x abcasm,ecma3,spidermonkey"))
    linux_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run
    linux_deep_factory.addStep(deep_run_brightspot(name='DebugDebugger', shell='avmshell_sd', testargs='--timelimit=120 --random --quiet'))
    linux_deep_factory.addStep(util_process_clean)
    linux_deep_factory.addStep(util_clean_buildsdir)
    linux_deep_factory.addStep(sync_clean)

    linux_deep_builder = {
                'name': "linux-deep",
                'slavename': "linux-deep",
                'factory': linux_deep_factory,
                'builddir': './linux-deep',
    }
    
    
    ######################################
    #### builder for linux-arm-deep   ####
    ######################################
    linux_arm_deep_factory = factory.BuildFactory()
    linux_arm_deep_factory.addStep(sync_clean)
    linux_arm_deep_factory.addStep(sync_clone_sandbox)
    linux_arm_deep_factory.addStep(sync_update)
    linux_arm_deep_factory.addStep(bb_slaveupdate(slave="linux-arm-deep"))
    linux_arm_deep_factory.addStep(download_testmedia)
    linux_arm_deep_factory.addStep(test_generic_ssh(name="Release-softfloat", shellname="avmshell_neon_arm", vmargs="", config="arm-lnx-tvm-release", scriptargs=""))
    linux_arm_deep_factory.addStep(test_selftest_ssh(name="Debug", shellname="avmshell_neon_arm_d"))
    linux_arm_deep_factory.addStep(test_generic_ssh(name="Debug-vfp", shellname="avmshell_neon_arm_d", vmargs="-Darm_arch 7 -Darm_vfp", config="arm-lnx-tvm-debug", scriptargs=""))
    linux_arm_deep_factory.addStep(test_generic_ssh(name="Debug-softfloat", shellname="avmshell_neon_arm_d", vmargs="", config="arm-lnx-tvm-debug", scriptargs=""))
    linux_arm_deep_factory.addStep(test_generic_ssh(name="Release-softfloat-deep", shellname="avmshell_neon_arm", vmargs="", config="arm-lnx-tvm-release-deep", scriptargs=""))
    linux_arm_deep_factory.addStep(test_generic_ssh(name="Release-deep", shellname="avmshell_neon_arm", vmargs="-Darm_arch 7 -Darm_vfp", config="arm-lnx-tvm-release-deep", scriptargs=""))
    linux_arm_deep_factory.addStep(test_generic_ssh(name="Release-Dinterp-deep", shellname="avmshell_neon_arm", vmargs="-Dinterp", config="arm-lnx-tvm-release-Dinterp-deep", scriptargs=""))
    linux_arm_deep_factory.addStep(test_generic_ssh(name="Release-GCthreshold", shellname="avmshell_neon_arm", vmargs="-Darm_arch 7 -Darm_vfp -Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="arm-lnx-tvm-release", scriptargs=""))
    linux_arm_deep_factory.addStep(test_generic_ssh(name="DebugDebugger-GCthreshold", shellname="avmshell_neon_arm_d", vmargs="-Darm_arch 7 -Darm_vfp -Dgcthreshold 128 -load 1.05,1,1.05,5,1.05,20", config="arm-lnx-tvm-debug", scriptargs=""))
    linux_arm_deep_factory.addStep(util_acceptance_clean_ssh)
    linux_arm_deep_factory.addStep(util_clean_buildsdir)
    linux_arm_deep_factory.addStep(sync_clean)

    linux_arm_deep_builder = {
                'name': "linux-arm-deep",
                'slavename': "linux-arm-deep",
                'factory': linux_arm_deep_factory,
                'builddir': './linux-arm-deep',
    }


    #######################################
    #### builder for linux-mips-deep   ####
    #######################################
    linux_mips_deep_factory = factory.BuildFactory()
    linux_mips_deep_factory.addStep(sync_clean)
    linux_mips_deep_factory.addStep(sync_clone_sandbox)
    linux_mips_deep_factory.addStep(sync_update)
    linux_mips_deep_factory.addStep(bb_slaveupdate(slave="linux-mips-deep"))
    linux_mips_deep_factory.addStep(download_testmedia)
    linux_mips_deep_factory.addStep(test_generic_ssh(name="Release", shellname="avmshell_mips", vmargs="-Dinterp", config="mips-lnx-tvm-release", scriptargs=""))
    linux_mips_deep_factory.addStep(test_generic_ssh(name="Debug", shellname="avmshell_mips_d", vmargs="-Dinterp", config="mips-lnx-tvm-debug", scriptargs=""))
    linux_mips_deep_factory.addStep(util_acceptance_clean_ssh)
    linux_mips_deep_factory.addStep(util_clean_buildsdir)
    linux_mips_deep_factory.addStep(sync_clean)

    linux_mips_deep_builder = {
                'name': "linux-mips-deep",
                'slavename': "linux-mips-deep",
                'factory': linux_mips_deep_factory,
                'builddir': './linux-mips-deep',
    }


    ########################################
    #### builder for solaris-sparc-deep ####
    ########################################
    solaris_sparc_deep_factory = factory.BuildFactory()
    solaris_sparc_deep_factory.addStep(sync_clean)
    solaris_sparc_deep_factory.addStep(sync_clone_sandbox)
    solaris_sparc_deep_factory.addStep(sync_update)
    solaris_sparc_deep_factory.addStep(bb_slaveupdate(slave="solaris-sparc-deep"))
    solaris_sparc_deep_factory.addStep(compile_builtin)
    solaris_sparc_deep_factory.addStep(compile_generic(name="Release-wordcode", shellname="avmshell_wordcode", args="--enable-wordcode-interp", upload="true", features="+AVMSYSTEM_32BIT +AVMSYSTEM_SPARC +AVMFEATURE_WORDCODE_INTERP"))
    solaris_sparc_deep_factory.addStep(compile_generic(name="DebugDebugger-wordcode", shellname="avmshell_sd_wordcode", args="--enable-debug --enable-debugger --enable-wordcode-interp", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_SPARC +AVMFEATURE_WORDCODE_INTERP"))    
    solaris_sparc_deep_factory.addStep(download_testmedia)
    solaris_sparc_deep_factory.addStep(test_selftest(name="ReleaseDebugger", shellname="avmshell_s"))
    solaris_sparc_deep_factory.addStep(test_selftest(name="DebugDebugger", shellname="avmshell_sd"))
    solaris_sparc_deep_factory.addStep(test_generic(name="Release-wordcode-interp", shellname="avmshell_wordcode", vmargs="-Dinterp", config="", scriptargs=""))
    solaris_sparc_deep_factory.addStep(test_generic(name="DebugDebugger-wordcode-interp", shellname="avmshell_sd_wordcode", vmargs="-Dinterp", config="", scriptargs=""))
    solaris_sparc_deep_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="sparc-sol-tvm-debugdebugger-deep", scriptargs="--showtimes", _timeout=2400))
    solaris_sparc_deep_factory.addStep(deep_release_esc)
    solaris_sparc_deep_factory.addStep(test_misc)
    solaris_sparc_deep_factory.addStep(test_generic(name="Release-Dgreedy", shellname="avmshell", vmargs="-Dgreedy", config="", scriptargs="--timeout=180 --random"))
    solaris_sparc_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyAll", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verify --timeout=300 --random"))
    solaris_sparc_deep_factory.addStep(test_generic(name="DebugDebugger_VerifyOnly", shellname="avmshell_sd", vmargs="", config="", scriptargs="--verifyonly --timeout=300 --random"))
    # Do a test run where we compile with -ES. MUST be the last step of the build as it recompiles the .abc files used by all the other steps
    solaris_sparc_deep_factory.addStep(test_generic(name="Release_ES", shellname="avmshell", vmargs="", config="",
                                              scriptargs="--ascargs=-no-AS3 --addtoconfig=-ES -f -x abcasm,ecma3,spidermonkey"))
    solaris_sparc_deep_factory.addStep(download_testmedia) # grab test media again, to protect against previous -ES run
    solaris_sparc_deep_factory.addStep(util_process_clean)
    solaris_sparc_deep_factory.addStep(util_clean_buildsdir)
    solaris_sparc_deep_factory.addStep(sync_clean)

    solaris_sparc_deep_builder = {
                'name': "solaris-sparc-deep",
                'slavename': "solaris-sparc-deep",
                'factory': solaris_sparc_deep_factory,
                'builddir': './solaris-sparc-deep',
    }


    #########################################
    #### builder for solaris-sparc2-deep ####
    #########################################
    solaris_sparc2_deep_factory = factory.BuildFactory()
    solaris_sparc2_deep_factory.addStep(sync_clean)
    solaris_sparc2_deep_factory.addStep(sync_clone_sandbox)
    solaris_sparc2_deep_factory.addStep(sync_update)
    solaris_sparc2_deep_factory.addStep(bb_slaveupdate(slave="solaris-sparc-deep"))
    solaris_sparc2_deep_factory.addStep(compile_builtin)
    solaris_sparc2_deep_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-debug", upload="true", features="+AVMSYSTEM_32BIT +AVMSYSTEM_SPARC"))
    solaris_sparc2_deep_factory.addStep(download_testmedia)
    solaris_sparc2_deep_factory.addStep(test_selftest(name="Debug", shellname="avmshell_d"))
    solaris_sparc2_deep_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    solaris_sparc2_deep_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    solaris_sparc2_deep_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    solaris_sparc2_deep_factory.addStep(test_generic(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    solaris_sparc2_deep_factory.addStep(test_generic(name="Debug-deep", shellname="avmshell_d", vmargs="", config="sparc-sol-tvm-debug-deep", scriptargs="--showtimes", _timeout=2400))
    solaris_sparc2_deep_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs=""))
    solaris_sparc2_deep_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs=""))
    solaris_sparc2_deep_factory.addStep(util_process_clean)
    solaris_sparc2_deep_factory.addStep(util_clean_buildsdir)
    solaris_sparc2_deep_factory.addStep(sync_clean)

    solaris_sparc2_deep_builder = {
                'name': "solaris-sparc2-deep",
                'slavename': "solaris-sparc2-deep",
                'factory': solaris_sparc2_deep_factory,
                'builddir': './solaris-sparc2-deep',
    }


    ##################################
    #### builder for windows-frr ####
    ##################################
    windows_frr_factory = factory.BuildFactory()
    windows_frr_factory.addStep(BuildShellCommand(
                command=['./build-frr.sh', WithProperties('%s','revision')],
                env={'branch': WithProperties('%s','branch')},
                description='building frr...',
                descriptionDone='finished building frr.',
                name="BuildFRR",
                workdir="../scripts",
                timeout=3600)
    )
    windows_frr_factory.addStep(BuildShellCommand(
                command=['./run-frunit.sh', WithProperties('%s','revision')],
                env={'branch': WithProperties('%s','branch')},
                description='running frunit...',
                descriptionDone='finished running frunit.',
                name="RunFrunit",
                workdir="../scripts",
                timeout=3600)
    )

    windows_frr_builder = {
                'name': "windows-frr",
                'slavename': "windows-frr",
                'factory': windows_frr_factory,
                'builddir': './windows-frr',
    }

    
    ##########################################
    #### builder for promote-build ####
    ##########################################
    
    promote_build_factory = factory.BuildFactory()
    promote_build_factory.addStep(sync_pull)
    promote_build_factory.addStep(sync_update)
    # since we do not wipe the repo every time, delete the scripts dir before
    # running bb_slaveupdate
    promote_build_factory.addStep(ShellCommand(
            command=['./delete-bb-scripts-dir.sh'],
            env={'branch': WithProperties('%s','branch'), 'silent':WithProperties('%s','silent')},
            description='Delete scripts dir' ,
            descriptionDone='Deleted scripts dir',
            name='Delete_Scripts_Dir',
            workdir='../repo/build/buildbot/slaves/all',
            haltOnFailure='False')
        )
    promote_build_factory.addStep(bb_slaveupdate(slave='promote-build'))
    promote_build_factory.addStep(ShellCommand(
            command=['../all/promote-build.sh', WithProperties('%s','revision')],
            env={'branch': WithProperties('%s','branch'), 'silent':WithProperties('%s','silent')},
            description='Promote revision to latest' ,
            descriptionDone='Promoted revision to latest after deep phase pass',
            name='Promote_Build',
            workdir='../repo/build/buildbot/slaves/scripts',
            haltOnFailure='True')
        )
    
    promote_build_builder = {
                'name': 'promote-build',
                'slavename': 'promote-build',
                'factory': promote_build_factory,
                'builddir': './promote-build', 
    }
    
    builders = [
                windows_compile_builder,
                windows_64_compile_builder,
                mac_intel_105_compile_builder,
                mac_intel_64_compile_builder,
                linux_compile_builder,
                linux_64_compile_builder,
                solaris_sparc_compile_builder,
                android_compile_builder,
                linux_arm_compile_builder,
                linux_mips_compile_builder,
                
                windows_smoke_builder,
                windows_64_smoke_builder,
                mac_intel_105_smoke_builder,
                mac_intel_64_smoke_builder,
                linux_smoke_builder,
                linux_64_smoke_builder,
                solaris_sparc_smoke_builder,
                android_smoke_builder,
                linux_arm_smoke_builder,
                linux_mips_smoke_builder,
                
                windows_test_builder,
                windows_64_test_builder,
                mac_intel_105_test_builder,
                mac_intel_64_test_builder,
                linux_test_builder,
                linux_64_test_builder,
                solaris_sparc_test_builder,
                android_test_builder,
                linux_arm_test_builder,
                linux_mips_test_builder,

                windows_deep_builder,
                windows_64_deep_builder,                
                mac_deep_builder,
                mac64_deep_builder,
                linux_deep_builder,
                linux_arm_deep_builder,
                linux_mips_deep_builder,
                solaris_sparc_deep_builder,
                solaris_sparc2_deep_builder,                
                windows_frr_builder,
                
                promote_build_builder,
                ]


