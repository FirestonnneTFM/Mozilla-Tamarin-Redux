#!/usr/bin/env python

#* ***** BEGIN LICENSE BLOCK *****
#* Version: MPL 1.1/GPL 2.0/LGPL 2.1
#*
#* The contents of this file are subject to the Mozilla Public License Version
#* 1.1 (the "License"); you may not use this file except in compliance with
#* the License. You may obtain a copy of the License at
#* http://www.mozilla.org/MPL/
#*
#* Software distributed under the License is distributed on an "AS IS" basis,
#* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
#* for the specific language governing rights and limitations under the
#* License.
#*
#* The Original Code is [Open Source Virtual Machine.].
#*
#* The Initial Developer of the Original Code is
#* Adobe System Incorporated.
#* Portions created by the Initial Developer are Copyright (C) 2009
#* the Initial Developer. All Rights Reserved.
#*
#* Contributor(s):
#*   Adobe AS3 Team
#*
#* Alternatively, the contents of this file may be used under the terms of
#* either the GNU General Public License Version 2 or later (the "GPL"), or
#* the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
#* in which case the provisions of the GPL or the LGPL are applicable instead
#* of those above. If you wish to allow use of your version of this file only
#* under the terms of either the GPL or the LGPL, and not to allow others to
#* use your version of this file under the terms of the MPL, indicate your
#* decision by deleting the provisions above and replace them with the notice
#* and other provisions required by the GPL or the LGPL. If you do not delete
#* the provisions above, a recipient may use your version of this file under
#* the terms of any one of the MPL, the GPL or the LGPL.
#*
#* ***** END LICENSE BLOCK ***** */
#

from cmdutils import *
import os

def run():
    r=RunTestLib()
    r.run_test('VMPIThreads(-Dselftest=vmpi,threads)','%s -Dselftest=vmpi,threads' % r.avm,expectedcode=0,
               expectedout=[
								"\['start', 'vmpi', 'threads'\]",
								"\['test', 'vmpi', 'threads', 'mutexes'\]",
								"\['pass', 'vmpi', 'threads', 'mutexes'\]",
								"\['test', 'vmpi', 'threads', 'conditions'\]",
								"\['pass', 'vmpi', 'threads', 'conditions'\]",
								"\['test', 'vmpi', 'threads', 'atomic_increment_without_barrier'\]",
								"\['pass', 'vmpi', 'threads', 'atomic_increment_without_barrier'\]",
								"\['test', 'vmpi', 'threads', 'atomic_decrement_without_barrier'\]",
								"\['pass', 'vmpi', 'threads', 'atomic_decrement_without_barrier'\]",
								"\['test', 'vmpi', 'threads', 'compare_and_swap_without_barrier'\]",
								"\['pass', 'vmpi', 'threads', 'compare_and_swap_without_barrier'\]",
								"\['test', 'vmpi', 'threads', 'atomic_increment_with_barrier'\]",
								"\['pass', 'vmpi', 'threads', 'atomic_increment_with_barrier'\]",
								"\['test', 'vmpi', 'threads', 'atomic_decrement_with_barrier'\]",
								"\['pass', 'vmpi', 'threads', 'atomic_decrement_with_barrier'\]",
								"\['test', 'vmpi', 'threads', 'compare_and_swap_with_barrier'\]",
								"\['pass', 'vmpi', 'threads', 'compare_and_swap_with_barrier'\]",
								"\['test', 'vmpi', 'threads', 'memory_barrier'\]",
								"\['pass', 'vmpi', 'threads', 'memory_barrier'\]",
								"\['test', 'vmpi', 'threads', 'try_lock'\]",
								"\['pass', 'vmpi', 'threads', 'try_lock'\]",
								"\['test', 'vmpi', 'threads', 'condition_with_wait'\]",
								"\['pass', 'vmpi', 'threads', 'condition_with_wait'\]",
								"\['test', 'vmpi', 'threads', 'sleep'\]",
								"\['pass', 'vmpi', 'threads', 'sleep'\]",
								"\['test', 'vmpi', 'threads', 'detach'\]",
								"\['pass', 'vmpi', 'threads', 'detach'\]",
								"\['test', 'vmpi', 'threads', 'thread_attributes'\]",
								"\['pass', 'vmpi', 'threads', 'thread_attributes'\]",
								"\['end', 'vmpi', 'threads'\]"
                            ]
   )

if __name__ == '__main__':
    r=RunTestLib()
    run()
