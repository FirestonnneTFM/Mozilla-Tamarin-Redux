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

class sandbox:
    
    BRANCH = "sandbox"
    
    ####### SCHEDULERS
    from buildbot.scheduler import *
    # custom.buildbot_ext.scheduler import MUST happen after importing buildbot.scheduler
    from custom.buildbot_ext.scheduler import *
    
    #### SANDBOX
    compile = Scheduler(name="compile-sandbox", branch=BRANCH, treeStableTimer=30, properties={'silent':'true'},
                     builderNames=["windows-compile-sandbox", "windows64-compile-sandbox",
                                   "mac-intel-10.4-compile-sandbox", "mac-intel-10.5-compile-sandbox", "mac64-intel-compile-sandbox",
                                   "linux-compile-sandbox", "linux2-compile-sandbox",
                                   "linux64-compile-sandbox",
                                   "solaris-sparc-compile-sandbox",
                                   "android-compile-sandbox",
                                   "linux-arm-compile-sandbox", "linux-arm2-compile-sandbox", "linux-arm3-compile-sandbox",
                                   "linux-mips-compile-sandbox",
                                   "linux-sh4-compile-sandbox"
                                   ])

    smoke = BuilderDependent(name="smoke-sandbox",upstream=compile, callbackInterval=60, properties={'silent':'true'},
                    builderNames=["windows-smoke-sandbox", "windows64-smoke-sandbox",
                                   "mac-intel-10.4-smoke-sandbox", "mac-intel-10.5-smoke-sandbox", "mac64-intel-smoke-sandbox",
                                   "linux-smoke-sandbox", "linux2-smoke-sandbox",
                                   "linux64-smoke-sandbox",
                                   "solaris-sparc-smoke-sandbox",
                                   "android-smoke-sandbox",
                                   "linux-arm-smoke-sandbox", "linux-arm2-smoke-sandbox", "linux-arm3-smoke-sandbox",
                                   "linux-mips-smoke-sandbox",
                                   "linux-sh4-smoke-sandbox"],
                    builderDependencies=[
                                  ["windows-smoke-sandbox", "windows-compile-sandbox"], 
                                  ["windows64-smoke-sandbox", "windows64-compile-sandbox"], 
                                  ["mac-intel-10.4-smoke-sandbox", "mac-intel-10.4-compile-sandbox"], 
                                  ["mac-intel-10.5-smoke-sandbox", "mac-intel-10.5-compile-sandbox"],
                                  ["mac64-intel-smoke-sandbox", "mac64-intel-compile-sandbox"],
                                  ["linux-smoke-sandbox", "linux-compile-sandbox"],
                                  ["linux2-smoke-sandbox", "linux2-compile-sandbox"],
                                  ["linux64-smoke-sandbox", "linux64-compile-sandbox"],
                                  ["solaris-sparc-smoke-sandbox", "solaris-sparc-compile-sandbox"],
                                  ["android-smoke-sandbox","android-compile-sandbox"],
                                  ["linux-arm-smoke-sandbox","linux-compile-sandbox"],
                                  ["linux-arm2-smoke-sandbox","linux-compile-sandbox"],
                                  ["linux-arm3-smoke-sandbox","linux-compile-sandbox"],
                                  ["linux-mips-smoke-sandbox","linux-mips-compile-sandbox"],
                                  ["linux-sh4-smoke-sandbox","linux2-compile-sandbox"],
                                 ])

    test = BuilderDependent(name="test-sandbox",upstream=smoke, callbackInterval=60, properties={'silent':'true'},
                    builderNames=["windows-test-sandbox", "windows64-test-sandbox",
                                   "mac-intel-10.4-test-sandbox", "mac-intel-10.5-test-sandbox", "mac64-intel-test-sandbox",
                                   "linux-test-sandbox", "linux2-test-sandbox",
                                   "linux64-test-sandbox",
                                   "solaris-sparc-test-sandbox",
                                   "android-test-sandbox",
                                   "linux-arm-test-sandbox", "linux-arm2-test-sandbox", "linux-arm3-test-sandbox",
                                   "linux-mips-test-sandbox",
                                   "linux-sh4-test-sandbox"],
                    builderDependencies=[
                                  ["windows-test-sandbox", "windows-smoke-sandbox"], 
                                  ["windows64-test-sandbox", "windows64-smoke-sandbox"], 
                                  ["mac-intel-10.4-test-sandbox", "mac-intel-10.4-smoke-sandbox"], 
                                  ["mac-intel-10.5-test-sandbox", "mac-intel-10.5-smoke-sandbox"],
                                  ["mac64-intel-test-sandbox", "mac64-intel-smoke-sandbox"],
                                  ["linux-test-sandbox", "linux-smoke-sandbox"],
                                  ["linux2-test-sandbox", "linux2-smoke-sandbox"],
                                  ["linux64-test-sandbox", "linux64-smoke-sandbox"],
                                  ["solaris-sparc-test-sandbox", "solaris-sparc-smoke-sandbox"],
                                  ["android-test-sandbox", "android-smoke-sandbox"],
                                  ["linux-arm-test-sandbox", "linux-arm-smoke-sandbox"],
                                  ["linux-arm2-test-sandbox", "linux-arm2-smoke-sandbox"],
                                  ["linux-arm3-test-sandbox", "linux-arm3-smoke-sandbox"],
                                  ["linux-mips-test-sandbox", "linux-mips-smoke-sandbox"],
                                  ["linux-sh4-test-sandbox", "linux-sh4-smoke-sandbox"],
                                 ])

    schedulers = [compile, smoke, test]


    ################################################################################
    ################################################################################
    ####                                                                        ####
    ####                    SANDBOX COMPILE BUILDERS                            ####
    ####                                                                        ####
    ################################################################################
    ################################################################################

    #############################################
    #### builder for windows-compile-sandbox ####
    #############################################
    sb_windows_compile_factory = factory.BuildFactory()
    sb_windows_compile_factory.addStep(sync_clean)
    sb_windows_compile_factory.addStep(sync_clone_sandbox)
    sb_windows_compile_factory.addStep(sync_update)
    sb_windows_compile_factory.addStep(bb_slaveupdate(slave="windows"))
    sb_windows_compile_factory.addStep(compile_builtin)
    sb_windows_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--enable-shell", upload="false"))
    sb_windows_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-shell --enable-debug", upload="false"))
    sb_windows_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-shell --enable-debugger", upload="false"))
    sb_windows_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-shell --enable-debug --enable-debugger", upload="false"))
    sb_windows_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --target=x86_64-win', 'avmshell_64', 'false', '+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'compile64':'true',
                },
                description='starting Release64 build...',
                descriptionDone='finished Release64 build.',
                name="Release64",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_windows_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --enable-debug --target=x86_64-win', 'avmshell_d_64', 'false', '+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'compile64':'true'
                },
                description='starting Debug64 build...',
                descriptionDone='finished Debug64 build.',
                name="Debug64",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_windows_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --enable-debugger --target=x86_64-win', 'avmshell_s_64', 'false', '+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'compile64':'true'
                },
                description='starting ReleaseDebugger64 build...',
                descriptionDone='finished ReleaseDebugger64 build.',
                name="ReleaseDebugger64",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_windows_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --enable-debug --enable-debugger --target=x86_64-win', 'avmshell_sd_64', 'false', '+AVMSYSTEM_64BIT +AVMSYSTEM_AMD64 +AVMFEATURE_DEBUGGER'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'compile64':'true'
                },
                description='starting DebugDebugger64 build...',
                descriptionDone='finished DebugDebugger64 build.',
                name="DebugDebugger64",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_windows_compile_factory.addStep(compile_buildcheck_local)
    sb_windows_compile_factory.addStep(util_upload_asteam_local)
    sb_windows_compile_factory.addStep(BuildShellCommand(
                command=['../all/file-check.py', '../../../../../repo'],
                env={'branch': WithProperties('%s','branch'), 'silent':WithProperties('%s','silent')},
                description='running file-check against source...',
                descriptionDone='finished file-check.',
                name="FileCheck",
                workdir="../repo/build/buildbot/slaves/scripts")
    )

    sb_windows_compile_builder = {
                'name': "windows-compile-sandbox",
                'slavename': "windows",
                'factory': sb_windows_compile_factory,
                'builddir': './sandbox-windows-compile',
    }


    ###############################################
    #### builder for windows64-compile-sandbox ####
    ###############################################
    sb_windows_64_compile_factory = factory.BuildFactory()
    sb_windows_64_compile_factory.addStep(sync_clean)
    sb_windows_64_compile_factory.addStep(sync_clone_sandbox)
    sb_windows_64_compile_factory.addStep(sync_update)
    sb_windows_64_compile_factory.addStep(bb_slaveupdate(slave="windows64"))

    sb_windows_64_compile_builder = {
                'name': "windows64-compile-sandbox",
                'slavename': "windows64",
                'factory': sb_windows_64_compile_factory,
                'builddir': './sandbox-windows64-compile',
    }


    ####################################################
    #### builder for mac-intel-10_4-compile-sandbox ####
    ####################################################
    sb_mac_intel_104_compile_factory = factory.BuildFactory()
    sb_mac_intel_104_compile_factory.addStep(sync_clean)
    sb_mac_intel_104_compile_factory.addStep(sync_clone_sandbox)
    sb_mac_intel_104_compile_factory.addStep(sync_update)
    sb_mac_intel_104_compile_factory.addStep(bb_slaveupdate(slave="mac-intel-10_4"))
    sb_mac_intel_104_compile_factory.addStep(compile_builtin)
    sb_mac_intel_104_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell_104", args="--enable-shell --mac-sdk=104u", upload="false"))
    sb_mac_intel_104_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d_104", args="--enable-shell --enable-debug --mac-sdk=104u", upload="false"))
    sb_mac_intel_104_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s_104", args="--enable-shell --enable-debugger --mac-sdk=104u", upload="false"))
    sb_mac_intel_104_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd_104", args="--enable-shell --enable-debug --enable-debugger --mac-sdk=104u", upload="false"))
    sb_mac_intel_104_compile_factory.addStep(compile_buildcheck)
    sb_mac_intel_104_compile_factory.addStep(util_upload_asteam)

    sb_mac_intel_104_compile_builder = {
                'name': "mac-intel-10.4-compile-sandbox",
                'slavename': "mac-intel-10_4",
                'factory': sb_mac_intel_104_compile_factory,
                'builddir': './sandbox-mac-intel-10_4-compile',
    }


    ####################################################
    #### builder for mac-intel-10_5-compile-sandbox ####
    ####################################################
    sb_mac_intel_105_compile_factory = factory.BuildFactory()
    sb_mac_intel_105_compile_factory.addStep(sync_clean)
    sb_mac_intel_105_compile_factory.addStep(sync_clone_sandbox)
    sb_mac_intel_105_compile_factory.addStep(sync_update)
    sb_mac_intel_105_compile_factory.addStep(bb_slaveupdate(slave="mac-intel-10_5"))
    sb_mac_intel_105_compile_factory.addStep(compile_builtin)
    sb_mac_intel_105_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--enable-shell --mac-sdk=104u", upload="false"))
    sb_mac_intel_105_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-shell --enable-debug --mac-sdk=104u", upload="false"))
    sb_mac_intel_105_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-shell --enable-debugger --mac-sdk=104u", upload="false"))
    sb_mac_intel_105_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-shell --enable-debug --enable-debugger --mac-sdk=104u", upload="false"))
    sb_mac_intel_105_compile_factory.addStep(compile_buildcheck)
    sb_mac_intel_105_compile_factory.addStep(util_upload_asteam)

    sb_mac_intel_105_compile_builder = {
                'name': "mac-intel-10.5-compile-sandbox",
                'slavename': "mac-intel-10_5",
                'factory': sb_mac_intel_105_compile_factory,
                'builddir': './sandbox-mac-intel-10_5-compile',
    }


    ##################################################
    #### builder for mac-intel-64-compile-sandbox ####
    ##################################################
    sb_mac_intel_64_compile_factory = factory.BuildFactory()
    sb_mac_intel_64_compile_factory.addStep(sync_clean)
    sb_mac_intel_64_compile_factory.addStep(sync_clone_sandbox)
    sb_mac_intel_64_compile_factory.addStep(sync_update)
    sb_mac_intel_64_compile_factory.addStep(bb_slaveupdate(slave="mac64-intel"))
    sb_mac_intel_64_compile_factory.addStep(compile_builtin)
    sb_mac_intel_64_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell_64", args="--enable-shell --target=x86_64-darwin --mac-sdk=105", upload="false"))
    sb_mac_intel_64_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d_64", args="--enable-shell --enable-debug --target=x86_64-darwin --mac-sdk=105", upload="false"))
    sb_mac_intel_64_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s_64", args="--enable-shell --enable-debugger --target=x86_64-darwin --mac-sdk=105", upload="false"))
    sb_mac_intel_64_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd_64", args="--enable-shell --enable-debug --enable-debugger --target=x86_64-darwin --mac-sdk=105", upload="false"))
    sb_mac_intel_64_compile_factory.addStep(compile_buildcheck)
    sb_mac_intel_64_compile_factory.addStep(util_upload_asteam)

    sb_mac_intel_64_compile_builder = {
                'name': "mac64-intel-compile-sandbox",
                'slavename': "mac64-intel",
                'factory': sb_mac_intel_64_compile_factory,
                'builddir': './sandbox-mac64-intel-compile',
    }


    ###########################################
    #### builder for linux-compile-sandbox ####
    ###########################################
    sb_linux_compile_factory = factory.BuildFactory()
    sb_linux_compile_factory.addStep(sync_clean)
    sb_linux_compile_factory.addStep(sync_clone_sandbox)
    sb_linux_compile_factory.addStep(sync_update)
    sb_linux_compile_factory.addStep(bb_slaveupdate(slave="linux"))
    sb_linux_compile_factory.addStep(compile_builtin)
    sb_linux_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--enable-shell --target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    sb_linux_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-shell --enable-debug --target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32"))
    sb_linux_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-shell --enable-debugger --target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    sb_linux_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-shell --enable-debug --enable-debugger --target=i686-linux", upload="false", features="+AVMSYSTEM_32BIT +AVMSYSTEM_IA32 +AVMFEATURE_DEBUGGER"))
    sb_linux_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --enable-arm-neon --arm-arch=armv7-a --target=arm-linux --enable-sys-root-dir=/usr/local/arm-linux/debian5', 'avmshell_neon_arm', 'false'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'CXX': 'arm-none-linux-gnueabi-g++',
                    'CC' : 'arm-none-linux-gnueabi-gcc',
                    'LD' : 'arm-none-linux-gnueabi-ld',
                    'AR' : 'arm-none-linux-gnueabi-ar',
                },
                description='starting Release_arm-linux build...',
                descriptionDone='finished Release_arm-linux build.',
                name="Release_arm-linux",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_linux_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --enable-debug --enable-arm-neon --arm-arch=armv7-a --target=arm-linux --enable-sys-root-dir=/usr/local/arm-linux/debian5', 'avmshell_neon_arm_d', 'false'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'CXX': 'arm-none-linux-gnueabi-g++',
                    'CC' : 'arm-none-linux-gnueabi-gcc',
                    'LD' : 'arm-none-linux-gnueabi-ld',
                    'AR' : 'arm-none-linux-gnueabi-ar',
                },
                description='starting Debug_arm-linux build...',
                descriptionDone='finished Debug_arm-linux build.',
                name="Debug_arm-linux",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_linux_compile_factory.addStep(compile_buildcheck_local)
    sb_linux_compile_factory.addStep(util_upload_asteam_local)

    sb_linux_compile_builder = {
                'name': "linux-compile-sandbox",
                'slavename': "linux",
                'factory': sb_linux_compile_factory,
                'builddir': './sandbox-linux-compile',
    }


    ####################################
    #### builder for linux2-compile ####
    ####################################
    sb_linux2_compile_factory = factory.BuildFactory()
    sb_linux2_compile_factory.addStep(sync_clean)
    sb_linux2_compile_factory.addStep(sync_clone_sandbox)
    sb_linux2_compile_factory.addStep(sync_update)
    sb_linux2_compile_factory.addStep(bb_slaveupdate(slave="linux"))
    sb_linux2_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --target=sh4-linux', 'avmshell_sh4', 'true'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'CXX': 'sh4-linux-g++',
                    'CC' : 'sh4-linux-gcc',
                    'LD' : 'sh4-linux-ld',
                    'AR' : 'sh4-linux-ar',
                },
                description='starting Release_sh4-linux build...',
                descriptionDone='finished Release_sh4-linux build.',
                name="Release_sh4-linux",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_linux2_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --enable-debug --target=sh4-linux', 'avmshell_sh4_d', 'true'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
                    'CXX': 'sh4-linux-g++',
                    'CC' : 'sh4-linux-gcc',
                    'LD' : 'sh4-linux-ld',
                    'AR' : 'sh4-linux-ar',
                },
                description='starting Debug_sh4-linux build...',
                descriptionDone='finished Debug_sh4-linux build.',
                name="Debug_sh4-linux",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    
    sb_linux2_compile_builder = {
                'name': "linux2-compile-sandbox",
                'slavename': "linux2",
                'factory': sb_linux2_compile_factory,
                'builddir': './sandbox-linux2-compile',
    }


    #############################################
    #### builder for linux64-compile-sandbox ####
    #############################################
    sb_linux_64_compile_factory = factory.BuildFactory()
    sb_linux_64_compile_factory.addStep(sync_clean)
    sb_linux_64_compile_factory.addStep(sync_clone_sandbox)
    sb_linux_64_compile_factory.addStep(sync_update)
    sb_linux_64_compile_factory.addStep(bb_slaveupdate(slave="linux64"))
    sb_linux_64_compile_factory.addStep(compile_builtin)
    sb_linux_64_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell_64", args="--enable-shell", upload="false"))
    sb_linux_64_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d_64", args="--enable-shell --enable-debug", upload="false"))
    sb_linux_64_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s_64", args="--enable-shell --enable-debugger", upload="false"))
    sb_linux_64_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd_64", args="--enable-shell --enable-debug --enable-debugger", upload="false"))
    sb_linux_64_compile_factory.addStep(compile_testmedia)
    sb_linux_64_compile_factory.addStep(compile_buildcheck_local)
    sb_linux_64_compile_factory.addStep(util_upload_asteam_local)

    sb_linux_64_compile_builder = {
                'name': "linux64-compile-sandbox",
                'slavename': "linux64",
                'factory': sb_linux_64_compile_factory,
                'builddir': './sandbox-linux64-compile',
    }


    ###################################################
    #### builder for solaris-sparc-compile-sandbox ####
    ###################################################
    sb_solaris_sparc_compile_factory = factory.BuildFactory()
    sb_solaris_sparc_compile_factory.addStep(sync_clean)
    sb_solaris_sparc_compile_factory.addStep(sync_clone_sandbox)
    sb_solaris_sparc_compile_factory.addStep(sync_update)
    sb_solaris_sparc_compile_factory.addStep(bb_slaveupdate(slave="solaris-sparc"))
    sb_solaris_sparc_compile_factory.addStep(compile_builtin)
    sb_solaris_sparc_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--enable-shell", upload="false"))
    sb_solaris_sparc_compile_factory.addStep(compile_generic(name="ReleaseDebugger", shellname="avmshell_s", args="--enable-shell --enable-debugger", upload="false"))
    sb_solaris_sparc_compile_factory.addStep(compile_generic(name="DebugDebugger", shellname="avmshell_sd", args="--enable-shell --enable-debug --enable-debugger", upload="false"))
    sb_solaris_sparc_compile_factory.addStep(compile_buildcheck_local)
    sb_solaris_sparc_compile_factory.addStep(util_upload_asteam)

    sb_solaris_sparc_compile_builder = {
                'name': "solaris-sparc-compile-sandbox",
                'slavename': "solaris-sparc",
                'factory': sb_solaris_sparc_compile_factory,
                'builddir': './sandbox-solaris-sparc-compile',
    }


    ###########################################
    #### builder for android on mac        ####
    ###########################################

    sb_android_compile_factory = factory.BuildFactory()
    sb_android_compile_factory.addStep(sync_clean)
    sb_android_compile_factory.addStep(sync_clone_sandbox)
    sb_android_compile_factory.addStep(sync_update)
    sb_android_compile_factory.addStep(bb_slaveupdate(slave="android"))
    sb_android_compile_factory.addStep(compile_builtin)
    sb_android_compile_factory.addStep(compile_generic(name="Release", shellname="avmshell", args="--enable-shell --arm-arch=armv7-a --target=arm-android", upload="false"))
    sb_android_compile_factory.addStep(compile_generic(name="Debug", shellname="avmshell_d", args="--enable-shell --enable-debug --arm-arch=armv7-a --target=arm-android", upload="false"))
    sb_android_compile_factory.addStep(compile_buildcheck_local)
    sb_android_compile_factory.addStep(util_upload_asteam_local)
    
    sb_android_compile_builder = {
                'name': "android-compile-sandbox",
                'slavename': "android",
                'factory': sb_android_compile_factory,
                'builddir': './sandbox-android-compile',
    }
    
    ###############################
    #### builder for linux-arm ####
    ###############################
    sb_linux_arm_compile_factory = factory.BuildFactory()
    sb_linux_arm_compile_factory.addStep(sync_clean)
    sb_linux_arm_compile_factory.addStep(sync_clone_sandbox)
    sb_linux_arm_compile_factory.addStep(sync_update)
    sb_linux_arm_compile_factory.addStep(bb_slaveupdate(slave="linux-arm"))

    sb_linux_arm_compile_builder = {
                'name': "linux-arm-compile-sandbox",
                'slavename': "linux-arm",
                'factory': sb_linux_arm_compile_factory,
                'builddir': './sandbox-linux-arm-compile',
    }
    
    
    ################################
    #### builder for linux-arm2 ####
    ################################
    sb_linux_arm2_compile_factory = factory.BuildFactory()
    sb_linux_arm2_compile_factory.addStep(sync_clean)
    sb_linux_arm2_compile_factory.addStep(sync_clone_sandbox)
    sb_linux_arm2_compile_factory.addStep(sync_update)
    sb_linux_arm2_compile_factory.addStep(bb_slaveupdate(slave="linux-arm"))

    sb_linux_arm2_compile_builder = {
                'name': "linux-arm2-compile-sandbox",
                'slavename': "linux-arm2",
                'factory': sb_linux_arm2_compile_factory,
                'builddir': './sandbox-linux-arm2-compile',
    }


    ################################
    #### builder for linux-arm3 ####
    ################################
    sb_linux_arm3_compile_factory = factory.BuildFactory()
    sb_linux_arm3_compile_factory.addStep(sync_clean)
    sb_linux_arm3_compile_factory.addStep(sync_clone_sandbox)
    sb_linux_arm3_compile_factory.addStep(sync_update)
    sb_linux_arm3_compile_factory.addStep(bb_slaveupdate(slave="linux-arm"))

    sb_linux_arm3_compile_builder = {
                'name': "linux-arm3-compile-sandbox",
                'slavename': "linux-arm3",
                'factory': sb_linux_arm3_compile_factory,
                'builddir': './sandbox-linux-arm3-compile',
    }


    ################################
    #### builder for linux-mips ####
    ################################
    sb_linux_mips_compile_factory = factory.BuildFactory()
    sb_linux_mips_compile_factory.addStep(sync_clean)
    sb_linux_mips_compile_factory.addStep(sync_clone_sandbox)
    sb_linux_mips_compile_factory.addStep(sync_update)
    sb_linux_mips_compile_factory.addStep(bb_slaveupdate(slave="linux-mips"))
    sb_linux_mips_compile_factory.addStep(compile_builtin)
    sb_linux_mips_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --target=mips-linux', 'avmshell_mips', 'false'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
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
    sb_linux_mips_compile_factory.addStep(BuildShellCommand(
                command=['../all/compile-generic.sh', WithProperties('%s','revision'), '--enable-shell --enable-debug --target=mips-linux', 'avmshell_mips_d', 'false'],
                env={
                    'branch': WithProperties('%s','branch'),
                    'silent':WithProperties('%s','silent'),
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
    sb_linux_mips_compile_factory.addStep(compile_buildcheck_local)
    sb_linux_mips_compile_factory.addStep(util_upload_asteam_local)
    
    sb_linux_mips_compile_builder = {
                'name': "linux-mips-compile-sandbox",
                'slavename': "linux-mips",
                'factory': sb_linux_mips_compile_factory,
                'builddir': './sandbox-linux-mips-compile',
    }


    ###############################
    #### builder for linux-sh4 ####
    ###############################
    sb_linux_sh4_compile_factory = factory.BuildFactory()
    sb_linux_sh4_compile_factory.addStep(sync_clean)
    sb_linux_sh4_compile_factory.addStep(sync_clone_sandbox)
    sb_linux_sh4_compile_factory.addStep(sync_update)
    sb_linux_sh4_compile_factory.addStep(bb_slaveupdate(slave="linux-sh4"))

    sb_linux_sh4_compile_builder = {
                'name': "linux-sh4-compile-sandbox",
                'slavename': "linux-sh4",
                'factory': sb_linux_sh4_compile_factory,
                'builddir': './sandbox-linux-sh4-compile',
    }


    ################################################################################
    ################################################################################
    ####                                                                        ####
    ####                     SANDBOX SMOKE BUILDERS                             ####
    ####                                                                        ####
    ################################################################################
    ################################################################################




    ###########################################
    #### builder for windows-smoke-sandbox ####
    ###########################################
    sb_windows_smoke_factory = factory.BuildFactory()
    sb_windows_smoke_factory.addStep(download_testmedia)
    sb_windows_smoke_factory.addStep(test_smoke)
    sb_windows_smoke_factory.addStep(util_process_clean)

    sb_windows_smoke_builder = {
                'name': "windows-smoke-sandbox",
                'slavename': "windows",
                'factory': sb_windows_smoke_factory,
                'builddir': './sandbox-windows-smoke',
    }


    #############################################
    #### builder for windows64-smoke-sandbox ####
    #############################################
    sb_windows_64_smoke_factory = factory.BuildFactory()
    sb_windows_64_smoke_factory.addStep(download_testmedia)
    sb_windows_64_smoke_factory.addStep(test_smoke)
    sb_windows_64_smoke_factory.addStep(util_process_clean)

    sb_windows_64_smoke_builder = {
                'name': "windows64-smoke-sandbox",
                'slavename': "windows64",
                'factory': sb_windows_64_smoke_factory,
                'builddir': './sandbox-windows64-smoke',
    }


    ##################################################
    #### builder for mac-intel-10_4-smoke-sandbox ####
    ##################################################
    sb_mac_intel_104_smoke_factory = factory.BuildFactory()
    sb_mac_intel_104_smoke_factory.addStep(download_testmedia)
    sb_mac_intel_104_smoke_factory.addStep(test_smoke)
    sb_mac_intel_104_smoke_factory.addStep(util_process_clean)

    sb_mac_intel_104_smoke_builder = {
                'name': "mac-intel-10.4-smoke-sandbox",
                'slavename': "mac-intel-10_4",
                'factory': sb_mac_intel_104_smoke_factory,
                'builddir': './sandbox-mac-intel-10_4-smoke',
    }


    ##################################################
    #### builder for mac-intel-10_5-smoke-sandbox ####
    ##################################################
    sb_mac_intel_105_smoke_factory = factory.BuildFactory()
    sb_mac_intel_105_smoke_factory.addStep(download_testmedia)
    sb_mac_intel_105_smoke_factory.addStep(test_smoke)
    sb_mac_intel_105_smoke_factory.addStep(util_process_clean)

    sb_mac_intel_105_smoke_builder = {
                'name': "mac-intel-10.5-smoke-sandbox",
                'slavename': "mac-intel-10_5",
                'factory': sb_mac_intel_105_smoke_factory,
                'builddir': './sandbox-mac-intel-10_5-smoke',
    }


    ###############################################
    #### builder for mac64-intel-smoke-sandbox ####
    ###############################################
    sb_mac_intel_64_smoke_factory = factory.BuildFactory()
    sb_mac_intel_64_smoke_factory.addStep(download_testmedia)
    sb_mac_intel_64_smoke_factory.addStep(test_smoke)
    sb_mac_intel_64_smoke_factory.addStep(util_process_clean)

    sb_mac_intel_64_smoke_builder = {
                'name': "mac64-intel-smoke-sandbox",
                'slavename': "mac64-intel",
                'factory': sb_mac_intel_64_smoke_factory,
                'builddir': './sandbox-mac64-intel-smoke',
    }


    #########################################
    #### builder for linux-smoke-sandbox ####
    #########################################
    sb_linux_smoke_factory = factory.BuildFactory()
    sb_linux_smoke_factory.addStep(download_testmedia)
    sb_linux_smoke_factory.addStep(test_smoke)
    sb_linux_smoke_factory.addStep(util_process_clean)

    sb_linux_smoke_builder = {
                'name': "linux-smoke-sandbox",
                'slavename': "linux",
                'factory': sb_linux_smoke_factory,
                'builddir': './sandbox-linux-smoke',
    }


    ##################################
    #### builder for linux2-smoke ####
    ##################################
    sb_linux2_smoke_factory = factory.BuildFactory()
    sb_linux2_smoke_factory.addStep(download_testmedia)
    # Machine currently ONLY compiles for SH4 platform
    #sb_linux2_smoke_factory.addStep(test_smoke)
    #sb_linux2_smoke_factory.addStep(util_process_clean)

    sb_linux2_smoke_builder = {
                'name': "linux2-smoke-sandbox",
                'slavename': "linux2",
                'factory': sb_linux2_smoke_factory,
                'builddir': './sandbox-linux2-smoke',
    }


    ###########################################
    #### builder for linux64-smoke-sandbox ####
    ###########################################
    sb_linux_64_smoke_factory = factory.BuildFactory()
    sb_linux_64_smoke_factory.addStep(download_testmedia)
    sb_linux_64_smoke_factory.addStep(test_smoke)
    sb_linux_64_smoke_factory.addStep(util_process_clean)

    sb_linux_64_smoke_builder = {
                'name': "linux64-smoke-sandbox",
                'slavename': "linux64",
                'factory': sb_linux_64_smoke_factory,
                'builddir': './sandbox-linux64-smoke',
    }


    #################################################
    #### builder for solaris-sparc-smoke-sandbox ####
    #################################################
    sb_solaris_sparc_smoke_factory = factory.BuildFactory()
    sb_solaris_sparc_smoke_factory.addStep(download_testmedia)
    sb_solaris_sparc_smoke_factory.addStep(test_smoke)
    sb_solaris_sparc_smoke_factory.addStep(util_process_clean)

    sb_solaris_sparc_smoke_builder = {
                'name': "solaris-sparc-smoke-sandbox",
                'slavename': "solaris-sparc",
                'factory': sb_solaris_sparc_smoke_factory,
                'builddir': './sandbox-solaris-sparc-smoke',
    }


    #########################################
    #### builder for android-smoke       ####
    #########################################
    sb_android_smoke_factory = factory.BuildFactory()
    sb_android_smoke_factory.addStep(download_testmedia)
    sb_android_smoke_factory.addStep(test_smoke_local)
    sb_android_smoke_factory.addStep(util_process_clean)

    sb_android_smoke_builder = {
                'name': "android-smoke-sandbox",
                'slavename': "android",
                'factory': sb_android_smoke_factory,
                'builddir': './sanbox-android-smoke',
    }
    
    ###########################################
    #### builder for linxu-arm-smoke       ####
    ###########################################
    sb_linux_arm_smoke_factory = factory.BuildFactory()
    sb_linux_arm_smoke_factory.addStep(download_testmedia)
    sb_linux_arm_smoke_factory.addStep(TestSuiteShellCommand(
                command=['../all/run-smoketests.sh', WithProperties('%s','revision'), './runsmokes-arm.txt'],
                env={'branch': WithProperties('%s','branch'), 'silent':WithProperties('%s','silent')},
                description='starting to run smoke tests...',
                descriptionDone='finished smoke tests.',
                name="SmokeTest",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_linux_arm_smoke_factory.addStep(util_process_clean)

    sb_linux_arm_smoke_builder = {
                'name': "linux-arm-smoke-sandbox",
                'slavename': "linux-arm",
                'factory': sb_linux_arm_smoke_factory,
                'builddir': './sandbox-linux-arm-smoke',
    }
    
    
    ###########################################
    #### builder for linxu-arm2-smoke      ####
    ###########################################
    sb_linux_arm2_smoke_factory = factory.BuildFactory()
    sb_linux_arm2_smoke_factory.addStep(download_testmedia)
    sb_linux_arm2_smoke_factory.addStep(TestSuiteShellCommand(
                command=['../all/run-smoketests.sh', WithProperties('%s','revision'), './runsmokes-arm.txt'],
                env={'branch': WithProperties('%s','branch'), 'silent':WithProperties('%s','silent')},
                description='starting to run smoke tests...',
                descriptionDone='finished smoke tests.',
                name="SmokeTest",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_linux_arm2_smoke_factory.addStep(util_process_clean)

    sb_linux_arm2_smoke_builder = {
                'name': "linux-arm2-smoke-sandbox",
                'slavename': "linux-arm2",
                'factory': sb_linux_arm2_smoke_factory,
                'builddir': './sandbox-linux-arm2-smoke',
    }


    ###########################################
    #### builder for linxu-arm3-smoke      ####
    ###########################################
    sb_linux_arm3_smoke_factory = factory.BuildFactory()
    sb_linux_arm3_smoke_factory.addStep(download_testmedia)
    sb_linux_arm3_smoke_factory.addStep(TestSuiteShellCommand(
                command=['../all/run-smoketests.sh', WithProperties('%s','revision'), './runsmokes-arm.txt'],
                env={'branch': WithProperties('%s','branch'), 'silent':WithProperties('%s','silent')},
                description='starting to run smoke tests...',
                descriptionDone='finished smoke tests.',
                name="SmokeTest",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_linux_arm3_smoke_factory.addStep(util_process_clean)

    sb_linux_arm3_smoke_builder = {
                'name': "linux-arm3-smoke-sandbox",
                'slavename': "linux-arm3",
                'factory': sb_linux_arm3_smoke_factory,
                'builddir': './sandbox-linux-arm3-smoke',
    }


    #########################################
    #### builder for linux-mips-smoke    ####
    #########################################
    sb_linux_mips_smoke_factory = factory.BuildFactory()
    sb_linux_mips_smoke_factory.addStep(download_testmedia)
    sb_linux_mips_smoke_factory.addStep(test_smoke_local)
    sb_linux_mips_smoke_factory.addStep(util_process_clean)

    sb_linux_mips_smoke_builder = {
                'name': "linux-mips-smoke-sandbox",
                'slavename': "linux-mips",
                'factory': sb_linux_mips_smoke_factory,
                'builddir': './sandbox-linux-mips-smoke',
    }

    ##########################################
    #### builder for linux-sh4-smoke      ####
    ##########################################
    sb_linux_sh4_smoke_factory = factory.BuildFactory()
    sb_linux_sh4_smoke_factory.addStep(download_testmedia)
    sb_linux_sh4_smoke_factory.addStep(TestSuiteShellCommand(
                command=['../all/run-smoketests.sh', WithProperties('%s','revision'), './runsmokes-arm.txt'],
                env={'branch': WithProperties('%s','branch')},
                description='starting to run smoke tests...',
                descriptionDone='finished smoke tests.',
                name="SmokeTest",
                workdir="../repo/build/buildbot/slaves/scripts")
    )
    sb_linux_sh4_smoke_factory.addStep(util_process_clean)

    sb_linux_sh4_smoke_builder = {
                'name': "linux-sh4-smoke-sandbox",
                'slavename': "linux-sh4",
                'factory': sb_linux_sh4_smoke_factory,
                'builddir': './sandbox-linux-sh4-smoke',
    }

    ################################################################################
    ################################################################################
    ####                                                                        ####
    ####                    SANDBOX TEST BUILDERS                               ####
    ####                                                                        ####
    ################################################################################
    ################################################################################




    ##########################################
    #### builder for windows-test-sandbox ####
    ##########################################
    sb_windows_test_factory = factory.BuildFactory()
    sb_windows_test_factory.addStep(test_commandline)
    sb_windows_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    sb_windows_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    sb_windows_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    sb_windows_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    sb_windows_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs=""))
    sb_windows_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    sb_windows_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs=""))
    sb_windows_test_factory.addStep(test_differential)
    sb_windows_test_factory.addStep(util_process_clean)
    sb_windows_test_factory.addStep(util_clean_buildsdir)
    sb_windows_test_factory.addStep(sync_clean)

    sb_windows_test_builder = {
                'name': "windows-test-sandbox",
                'slavename': "windows",
                'factory': sb_windows_test_factory,
                'builddir': './sandbox-windows-test',
    }

    ############################################
    #### builder for windows64-test-sandbox ####
    ############################################
    sb_windows_64_test_factory = factory.BuildFactory()
    sb_windows_64_test_factory.addStep(test_commandline)
    sb_windows_64_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_64"))
    sb_windows_64_test_factory.addStep(test_generic(name="Release", shellname="avmshell_64", vmargs="", config="", scriptargs=""))
    sb_windows_64_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_64", vmargs="-Dinterp", config="", scriptargs=""))
    sb_windows_64_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell_64", vmargs="-Ojit", config="", scriptargs=""))
    sb_windows_64_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s_64", vmargs="", config="", scriptargs=""))
    sb_windows_64_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_64", vmargs="", config="", scriptargs=""))
    sb_windows_64_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_64", vmargs="", config="", scriptargs=""))
    sb_windows_64_test_factory.addStep(util_process_clean)
    sb_windows_64_test_factory.addStep(util_clean_buildsdir)
    sb_windows_64_test_factory.addStep(sync_clean)

    sb_windows_64_test_builder = {
                'name': "windows64-test-sandbox",
                'slavename': "windows64",
                'factory': sb_windows_64_test_factory,
                'builddir': './sandbox-windows64-test',
    }


    #################################################
    #### builder for mac-intel-10_4-test-sandbox ####
    #################################################
    sb_mac_intel_104_test_factory = factory.BuildFactory()
    sb_mac_intel_104_test_factory.addStep(test_commandline)
    sb_mac_intel_104_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_104"))
    sb_mac_intel_104_test_factory.addStep(test_generic(name="Release", shellname="avmshell_104", vmargs="", config="", scriptargs=""))
    sb_mac_intel_104_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_104", vmargs="-Dinterp", config="", scriptargs=""))
    sb_mac_intel_104_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell_104", vmargs="-Ojit", config="", scriptargs=""))
    sb_mac_intel_104_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s_104", vmargs="", config="", scriptargs=""))
    sb_mac_intel_104_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_104", vmargs="", config="", scriptargs=""))
    sb_mac_intel_104_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_104", vmargs="", config="", scriptargs=""))
    sb_mac_intel_104_test_factory.addStep(test_differential)
    sb_mac_intel_104_test_factory.addStep(util_process_clean)
    sb_mac_intel_104_test_factory.addStep(util_clean_buildsdir)
    sb_mac_intel_104_test_factory.addStep(sync_clean)

    sb_mac_intel_104_test_builder = {
                'name': "mac-intel-10.4-test-sandbox",
                'slavename': "mac-intel-10_4",
                'factory': sb_mac_intel_104_test_factory,
                'builddir': './sandbox-mac-intel-10_4-test',
    }



    #################################################
    #### builder for mac-intel-10_5-test-sandbox ####
    #################################################
    sb_mac_intel_105_test_factory = factory.BuildFactory()
    sb_mac_intel_105_test_factory.addStep(test_commandline)
    sb_mac_intel_105_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    sb_mac_intel_105_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    sb_mac_intel_105_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    sb_mac_intel_105_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    sb_mac_intel_105_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs=""))
    sb_mac_intel_105_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    sb_mac_intel_105_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs=""))
    sb_mac_intel_105_test_factory.addStep(test_differential)
    sb_mac_intel_105_test_factory.addStep(util_process_clean)
    sb_mac_intel_105_test_factory.addStep(util_clean_buildsdir)
    sb_mac_intel_105_test_factory.addStep(sync_clean)

    sb_mac_intel_105_test_builder = {
                'name': "mac-intel-10.5-test-sandbox",
                'slavename': "mac-intel-10_5",
                'factory': sb_mac_intel_105_test_factory,
                'builddir': './sandbox-mac-intel-10_5-test',
    }

    ##############################################
    #### builder for mac64-intel-test-sandbox ####
    ##############################################
    sb_mac_intel_64_test_factory = factory.BuildFactory()
    sb_mac_intel_64_test_factory.addStep(test_commandline)
    sb_mac_intel_64_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_64"))
    sb_mac_intel_64_test_factory.addStep(test_generic(name="Release", shellname="avmshell_64", vmargs="", config="", scriptargs=""))
    sb_mac_intel_64_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_64", vmargs="-Dinterp", config="", scriptargs=""))
    sb_mac_intel_64_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell_64", vmargs="-Ojit", config="", scriptargs=""))
    sb_mac_intel_64_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s_64", vmargs="", config="", scriptargs=""))
    sb_mac_intel_64_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_64", vmargs="", config="", scriptargs=""))
    sb_mac_intel_64_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_64", vmargs="", config="", scriptargs=""))
    sb_mac_intel_64_test_factory.addStep(util_process_clean)
    sb_mac_intel_64_test_factory.addStep(util_clean_buildsdir)
    sb_mac_intel_64_test_factory.addStep(sync_clean)

    sb_mac_intel_64_test_builder = {
                'name': "mac64-intel-test-sandbox",
                'slavename': "mac64-intel",
                'factory': sb_mac_intel_64_test_factory,
                'builddir': './sandbox-mac64-intel-test',
    }


    ########################################
    #### builder for linux-test-sandbox ####
    ########################################
    sb_linux_test_factory = factory.BuildFactory()
    sb_linux_test_factory.addStep(test_commandline)
    sb_linux_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    sb_linux_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    sb_linux_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    sb_linux_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    sb_linux_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs=""))
    sb_linux_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    sb_linux_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs=""))
    sb_linux_test_factory.addStep(test_differential)
    sb_linux_test_factory.addStep(util_process_clean)
    sb_linux_test_factory.addStep(util_clean_buildsdir)
    sb_linux_test_factory.addStep(sync_clean)

    sb_linux_test_builder = {
                'name': "linux-test-sandbox",
                'slavename': "linux",
                'factory': sb_linux_test_factory,
                'builddir': './sandbox-linux-test',
    }


    #################################
    #### builder for linux2-test ####
    #################################
    sb_linux2_test_factory = factory.BuildFactory()
    # Builder currently ONLY compiles for the SH4 platform
    sb_linux2_test_factory.addStep(util_process_clean)
    sb_linux2_test_factory.addStep(util_clean_buildsdir)
    sb_linux2_test_factory.addStep(sync_clean)

    sb_linux2_test_builder = {
                'name': "linux2-test-sandbox",
                'slavename': "linux2",
                'factory': sb_linux2_test_factory,
                'builddir': './sandbox-linux2-test',
    }


    ##########################################
    #### builder for linux64-test-sandbox ####
    ##########################################
    sb_linux_64_test_factory = factory.BuildFactory()
    sb_linux_64_test_factory.addStep(test_commandline)
    sb_linux_64_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_64"))
    sb_linux_64_test_factory.addStep(test_generic(name="Release", shellname="avmshell_64", vmargs="", config="", scriptargs=""))
    sb_linux_64_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_64", vmargs="-Dinterp", config="", scriptargs=""))
    sb_linux_64_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell_64", vmargs="-Ojit", config="", scriptargs=""))
    sb_linux_64_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s_64", vmargs="", config="", scriptargs=""))
    sb_linux_64_test_factory.addStep(test_generic(name="Debug", shellname="avmshell_d_64", vmargs="", config="", scriptargs=""))
    sb_linux_64_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd_64", vmargs="", config="", scriptargs=""))
    sb_linux_64_test_factory.addStep(util_process_clean)
    sb_linux_64_test_factory.addStep(util_clean_buildsdir)
    sb_linux_64_test_factory.addStep(sync_clean)

    sb_linux_64_test_builder = {
                'name': "linux64-test-sandbox",
                'slavename': "linux64",
                'factory': sb_linux_64_test_factory,
                'builddir': './sandbox-linux64-test',
    }


    ########################################
    #### builder for solaris-sparc-test ####
    ########################################
    sb_solaris_sparc_test_factory = factory.BuildFactory()
    sb_solaris_sparc_test_factory.addStep(test_commandline)
    sb_solaris_sparc_test_factory.addStep(test_selftest(name="Release", shellname="avmshell"))
    sb_solaris_sparc_test_factory.addStep(test_generic(name="Release", shellname="avmshell", vmargs="", config="", scriptargs="--random --timeout=480"))
    sb_solaris_sparc_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs="--random --timeout=480"))
    sb_solaris_sparc_test_factory.addStep(test_generic(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs="--random --timeout=480"))
    sb_solaris_sparc_test_factory.addStep(test_generic(name="ReleaseDebugger", shellname="avmshell_s", vmargs="", config="", scriptargs="--random --timeout=480"))
    sb_solaris_sparc_test_factory.addStep(test_generic(name="DebugDebugger", shellname="avmshell_sd", vmargs="", config="", scriptargs="--random --timeout=480"))
    sb_solaris_sparc_test_factory.addStep(util_process_clean)
    sb_solaris_sparc_test_factory.addStep(util_clean_buildsdir)
    sb_solaris_sparc_test_factory.addStep(sync_clean)

    sb_solaris_sparc_test_builder = {
                'name': "solaris-sparc-test-sandbox",
                'slavename': "solaris-sparc",
                'factory': sb_solaris_sparc_test_factory,
                'builddir': './sandbox-solaris-sparc-test',
    }


    ########################################
    #### builder for android-test       ####
    ########################################
    sb_android_test_factory = factory.BuildFactory()
    sb_android_test_factory.addStep(test_generic_adb(name="Release", shellname="avmshell", vmargs="", config="", scriptargs=""))
    sb_android_test_factory.addStep(test_generic_adb(name="Release-interp", shellname="avmshell", vmargs="-Dinterp", config="", scriptargs=""))
    sb_android_test_factory.addStep(test_generic_adb(name="Release-jit", shellname="avmshell", vmargs="-Ojit", config="", scriptargs=""))
    sb_android_test_factory.addStep(test_generic_adb(name="Debug", shellname="avmshell_d", vmargs="", config="", scriptargs=""))
    sb_android_test_factory.addStep(util_process_clean)
    sb_android_test_factory.addStep(util_clean_buildsdir)
    sb_android_test_factory.addStep(sync_clean)

    sb_android_test_builder = {
                'name': "android-test-sandbox",
                'slavename': "android",
                'factory': sb_android_test_factory,
                'builddir': './sandbox-android-test',
    }
    
    ##########################################
    #### builder for linux-arm-test       ####
    ##########################################
    sb_linux_arm_test_factory = factory.BuildFactory()
    sb_linux_arm_test_factory.addStep(test_selftest(name="Release", shellname="avmshell_neon_arm"))
    sb_linux_arm_test_factory.addStep(test_generic(name="Release-vfp", shellname="avmshell_neon_arm", vmargs="-Darm_arch 7 -Darm_vfp", config="", scriptargs=""))
    sb_linux_arm_test_factory.addStep(util_process_clean)
    sb_linux_arm_test_factory.addStep(util_clean_buildsdir)
    sb_linux_arm_test_factory.addStep(sync_clean)

    sb_linux_arm_test_builder = {
                'name': "linux-arm-test-sandbox",
                'slavename': "linux-arm",
                'factory': sb_linux_arm_test_factory,
                'builddir': './sandbox-linux-arm-test',
    }
    
    
    ##########################################
    #### builder for linux-arm2-test      ####
    ##########################################
    sb_linux_arm2_test_factory = factory.BuildFactory()
    sb_linux_arm2_test_factory.addStep(test_generic(name="Release-interp", shellname="avmshell_neon_arm", vmargs="-Dinterp", config="", scriptargs=""))
    sb_linux_arm2_test_factory.addStep(util_process_clean)
    sb_linux_arm2_test_factory.addStep(util_clean_buildsdir)
    sb_linux_arm2_test_factory.addStep(sync_clean)

    sb_linux_arm2_test_builder = {
                'name': "linux-arm2-test-sandbox",
                'slavename': "linux-arm2",
                'factory': sb_linux_arm2_test_factory,
                'builddir': './sandbox-linux-arm2-test',
    }


    ###########################################
    #### builder for linux-arm3-test       ####
    ###########################################
    sb_linux_arm3_test_factory = factory.BuildFactory()
    sb_linux_arm3_test_factory.addStep(test_generic(name="Release-jit-vfp", shellname="avmshell_neon_arm", vmargs="-Darm_arch 7 -Darm_vfp -Ojit", config="", scriptargs=""))
    sb_linux_arm3_test_factory.addStep(util_process_clean)
    sb_linux_arm3_test_factory.addStep(util_clean_buildsdir)
    sb_linux_arm3_test_factory.addStep(sync_clean)

    sb_linux_arm3_test_builder = {
                'name': "linux-arm3-test-sandbox",
                'slavename': "linux-arm3",
                'factory': sb_linux_arm3_test_factory,
                'builddir': './sandbox-linux-arm3-test',
    }


    ##########################################
    #### builder for linux-mips-test      ####
    ##########################################
    sb_linux_mips_test_factory = factory.BuildFactory()
    sb_linux_mips_test_factory.addStep(test_generic_ssh(name="Release", shellname="avmshell_mips", vmargs="", config="mips-lnx-tvm-release", scriptargs="--threads=1 --timeout=600 --random"))
    sb_linux_mips_test_factory.addStep(test_generic_ssh(name="Debug", shellname="avmshell_mips_d", vmargs="", config="mips-lnx-tvm-debug", scriptargs="--threads=1 --timeout=600 --random"))
    sb_linux_mips_test_factory.addStep(util_process_clean)
    sb_linux_mips_test_factory.addStep(util_clean_buildsdir)
    sb_linux_mips_test_factory.addStep(sync_clean)

    sb_linux_mips_test_builder = {
                'name': "linux-mips-test-sandbox",
                'slavename': "linux-mips",
                'factory': sb_linux_mips_test_factory,
                'builddir': './sandbox-linux-mips-test',
    }
    

    #########################################
    #### builder for linux-sh4-test      ####
    #########################################
    sb_linux_sh4_test_factory = factory.BuildFactory()
    sb_linux_sh4_test_factory.addStep(test_generic(name="Release", shellname="avmshell_sh4", vmargs="", config="", scriptargs=""))
    sb_linux_sh4_test_factory.addStep(util_process_clean)
    sb_linux_sh4_test_factory.addStep(util_clean_buildsdir)
    sb_linux_sh4_test_factory.addStep(sync_clean)

    sb_linux_sh4_test_builder = {
                'name': "linux-sh4-test-sandbox",
                'slavename': "linux-sh4",
                'factory': sb_linux_sh4_test_factory,
                'builddir': './sandbox-linux-sh4-test',
    }
    
    builders = [
                sb_windows_compile_builder,
                sb_windows_64_compile_builder,
                sb_mac_intel_104_compile_builder,
                sb_mac_intel_105_compile_builder,
                sb_mac_intel_64_compile_builder,
                sb_linux_compile_builder,
                sb_linux2_compile_builder,
                sb_linux_64_compile_builder,
                sb_solaris_sparc_compile_builder,
                sb_android_compile_builder,
                sb_linux_arm_compile_builder,
                sb_linux_arm2_compile_builder,
                sb_linux_arm3_compile_builder,
                sb_linux_mips_compile_builder,
                sb_linux_sh4_compile_builder,
                
                sb_windows_smoke_builder,
                sb_windows_64_smoke_builder,
                sb_mac_intel_104_smoke_builder,
                sb_mac_intel_105_smoke_builder,
                sb_mac_intel_64_smoke_builder,
                sb_linux_smoke_builder,
                sb_linux2_smoke_builder,
                sb_linux_64_smoke_builder,
                sb_solaris_sparc_smoke_builder,
                sb_android_smoke_builder,
                sb_linux_arm_smoke_builder,
                sb_linux_arm2_smoke_builder,
                sb_linux_arm3_smoke_builder,
                sb_linux_mips_smoke_builder,
                sb_linux_sh4_smoke_builder,
                
                sb_windows_test_builder,
                sb_windows_64_test_builder,
                sb_mac_intel_104_test_builder,
                sb_mac_intel_105_test_builder,
                sb_mac_intel_64_test_builder,
                sb_linux_test_builder,
                sb_linux2_test_builder,
                sb_linux_64_test_builder,
                sb_solaris_sparc_test_builder,
                sb_android_test_builder,
                sb_linux_arm_test_builder,
                sb_linux_arm2_test_builder,
                sb_linux_arm3_test_builder,
                sb_linux_mips_test_builder,
                sb_linux_sh4_test_builder,

                ]

