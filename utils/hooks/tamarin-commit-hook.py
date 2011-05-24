#! /usr/bin/python
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
#  Portions created by the Initial Developer are Copyright (C) 2010
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
#
#  Hook script used by tamarin team on tamarin-redux and tamarin-central.
#
# For documentation on hook scripts see:
#   http://hgbook.red-bean.com/read/handling-repository-events-with-hooks.html
#   http://mercurial.selenic.com/wiki/MercurialApi

# This file is to be run using a pretxncommit hook
# Place this in your .hg/hgrc file in the repo:
#
# [hooks]
# pretxncommit.master = python:/path/to/tamarin-commit-hook.py:master_hook
# preoutgoing.checklog = python:/path/to/tamarin-commit-hook.py:preoutgoing_hook

import sys, re, os
from mercurial import hg, ui, commands, cmdutil, patch
from mercurial.node import hex, short
from HTMLParser import HTMLParser
from urllib2 import urlopen

class BugType:
    NORMAL = 1
    SECURITY = 2
    INVALID = 3

class TitleParser(HTMLParser):
    '''Very simple parser to extract the title from an HTML page'''
    in_title = False
    title = ''
    def handle_starttag(self, tag, attrs):
        if tag == 'title':
            self.in_title = True
    def handle_data(self, data):
        if self.in_title:
            self.title = data
            self.in_title = False

def master_hook(ui, repo, **kwargs):
    ui.debug('running tamarin master_hook\n')
    ui.debug('kwargs: %s\n' % kwargs)
    # The mercurial hook script expects the equivalent of an exit code back from
    # this call:
    #   False = 0 = No Error : allow push
    #   True = 1 = Error : abort push
    error = False
    error = error or diff_check(ui, repo, **kwargs)

    if error:
        # Save the commit message so it can be reused by user
        desc = repo[repo[kwargs['node']].rev()].description()
        ui.debug('Description: %s\n' % desc)
        try:
            f = open('%s/.hg/commit.save' % repo.root, 'w')
            f.write(desc)
            f.close()
            ui.warn('Commit message saved to .hg/commit.save\nSaved message can be recommitted using -l .hg/commit.save\n')
        except IOError:
            ui.warn('Error writing .hg/commit.save file')

    return error

def preoutgoing_hook(ui, repo, **kwargs):
    ui.debug('running tamarin preoutgoing_hook\n')
    ui.debug('kwargs: %s\n' % kwargs)
    operation = kwargs['source']

    # Like master_hook, return code False implies No Error, allow push.
    error = False
    error = error or heuristic_log_check(ui, repo, operation, **kwargs)

    return error

def heuristic_log_check(ui, repo, operation, **kwargs):
    # Bug 630416: Unlike master_hook, the hg preoutgoing hook (as of
    # Mercurial version 1.7) has very little to work with: no
    # reference to targeted repo, no description of changesets being
    # gathered to propagate, etc.
    #
    # We just want to catch log entry oversights before pushing to
    # other repositories.  As a heuristic, assume tip changeset is the
    # (only) revision being pushed; heuristic can misfire, but should
    # catch the common cases (a more formal guard would belong
    # server-side anyway).
    #
    # If future Mercurial versions address this problem with
    # preoutgoing, then could drop heuristic and apply description
    # check across all outgoing changesets; then we should print all
    # warnings in one pass and prompt for confirmation at most once.

    # Don't do format-check on hg-strip
    if (operation in ["strip"]):
        return False

    tip_id = repo.changelog.tip()
    tip_changeset = repo[tip_id]

    # See master_hook for interpretation of error flag.
    error = check_desc_for_bugnum_and_reviews(ui, tip_changeset, operation)
    error = error or check_user_for_valid_email(ui, tip_changeset, operation)
    return error

def prompt_yesno(ui, operation):
    return ui.promptchoice(('Continue %s (n)o, (y)es? [n]' % operation),
                           (('&No'),('&Yes')), 0)

def bugzilla_reference(line):
    # Match bug number of >= 6 digits and prefixed by "Bug", "For", etc
    try:
        bug_number = re.match(r'.*(Bug|For|Fix)\s*([0-9]{6,})',
                              line, re.IGNORECASE).group(2)
    except AttributeError:
        return None
    return bug_number

def has_reviewer_notes(line):
    # Match "r=<name>" or "r+<name>"; assumes names are alphanumeric.
    return re.match(r'.*r(=|\+)[a-zA-Z0-9]+', line)

def check_bug_type(bug):
    p = TitleParser()
    u = urlopen('https://bugzilla.mozilla.org/show_bug.cgi?id=%s' % bug)
    p.feed(u.read().decode(u.info().getparam('charset')))
    p.close()
    
    if p.title == 'Access Denied':
        return BugType.SECURITY
    elif p.title == 'Invalid Bug ID':
        return BugType.INVALID
    return BugType.NORMAL

def has_email_in_brackets(user):
    return re.match(r'.*<.+>', user)

def has_email_with_domain(user):
    return re.match(r'.*<.+@.+>', user)

def check_user_for_valid_email(ui, changeset, operation):
    user = changeset.user()
    ui.debug('\ncheck_user_for_valid_email: %s' % user)
    has_email = has_email_in_brackets(user)
    if not has_email:
        ui.warn('\nUser missing email address for changeset %s: \n  %s\n'
                % (changeset, user))
        response = prompt_yesno(ui, operation)
        if response == 0:
            ui.warn('Aborting %s due to user missing email.\n' % operation)
            return True;
    else:
        has_domain = has_email_with_domain(user)
        if not has_domain:
            ui.warn('\nUser email missing domain for changeset %s: \n  %s\n'
                    % (changeset, user))
            response = prompt_yesno(ui, operation)
            if response == 0:
                ui.warn('Aborting %s due to email without domain.\n' % operation)
                return True;

    return False;

def check_desc_for_bugnum_and_reviews(ui, changeset, operation):
    # Check first line of log of tip changeset; if it appears questionable,
    # prompt the user to confirm that they want to continue the operation.
    desc = changeset.description()
    lines = desc.split('\n')
    first_line = lines[0]
    bug_num = bugzilla_reference(first_line)
    has_review = has_reviewer_notes(first_line)

    if not bug_num or not has_review:
        ui.warn('\nQuestionable log for changeset %s:\n  %s\n'
                % (changeset,first_line))

    if not bug_num:
        ui.warn('Missing bug number, e.g. "Bug NNNNNN: ..."\n')
        response = prompt_yesno(ui, operation)
        if response == 0:
            ui.warn('Aborting %s due to missing bug number.\n' % operation)
            return True
    else:
        bug_type = check_bug_type(bug_num)
        if bug_type == BugType.SECURITY:
            ui.warn('Bug %s is a security bug.' % bug_num)
            response = prompt_yesno(ui, operation)
            if response == 0:
                ui.warn('Aborting %s due to security bug.\n' % operation)
                return True
        elif bug_type == BugType.INVALID:
            ui.warn('Bug %s is a not defined in bugzilla.' % bug_num)
            response = prompt_yesno(ui, operation)
            if response == 0:
                ui.warn('Aborting %s due to invalid bug number.\n' % operation)
                return True

    if not has_review:
        ui.warn('Missing review notes, e.g. "... (r=<name>,sr=<name>)"\n')
        response = prompt_yesno(ui, operation)
        if response == 0:
            ui.warn('Aborting %s due to missing review notes.\n' % operation)
            return True

    return False;


def diff_check(ui, repo, **kwargs):
    ui.debug('running diff_check\n')

    # get all the change contexts for this commit
    # kwargs['node'] returns the first changecontext nodeid
    changecontexts = [repo[i] for i in range(repo[kwargs['node']].rev(), len(repo))]
    # check for tabs
    def tabCheck(line):
        tab = line.find('\t')
        if tab >= 0:    # find returns -1 if not found
            return True, tab
        return False, tab

    def windowsLineendingsCheck(line):
        if line.endswith('\r'):
            return True, len(line)-1
        return False, 0

    def trailingWhitespaceCheck(line):
        if len(line.strip()) > 1:   # skip empty lines (will have a +) see bug 600536
            m = re.match(r'\+.*?(\s+$)', line)
            if m:
                return True, m.start(1)
        return False, 0
    
    def securityCheck(line):
        loc = line.find('MARK_SECURITY_CHANGE')
        if loc != -1:
            # found security change ifdef
            return True, loc
        return False, 0

    # check for tabs - exit if user chooses to abort
    if checkChangeCtxDiff(ui, repo, changecontexts, tabCheck,
                          'Tab', ('.cpp', '.c', '.h', '.as', '.abs', '.py')):
        return True

    if checkChangeCtxDiff(ui, repo, changecontexts, windowsLineendingsCheck,
                          'Windows line ending', ('.cpp', '.c', '.h', '.as', '.abs', '.py')):
        return True

    if checkChangeCtxDiff(ui, repo, changecontexts, trailingWhitespaceCheck,
                          'Trailing Whitespace', ('.cpp', '.c', '.h', '.as', '.abs', '.py')):
        return True

    if checkChangeCtxDiff(ui, repo, changecontexts, securityCheck,
                          'Security Check', ('.cpp', '.c', '.h', '.as', '.abs', '.py')):
        return True

    return False

def checkChangeCtxDiff(ui, repo, changecontexts, testFunc, testDesc, fileEndings):
    '''Loop through each diff for each change and run the testFunc against each line'''
    ui.debug('Checking %s\n' % testDesc)
    for ctx in changecontexts:
        # Get the diff for each change and file
        for file in [f for f in ctx.files() if f.endswith(fileEndings)]:
            ui.debug('checking change: %s, file: %s\n' % (short(ctx.node()), file))
            fmatch = cmdutil.matchfiles(repo,[file])
            # diff from this nodes parent to current node
            diff = ''.join(patch.diff(repo, ctx.parents()[0].node(), ctx.node(), fmatch)).split('\n')
            for i in range(3, len(diff)):    # start checking after diff header
                line = diff[i]
                if line.startswith('@@'):
                    diffLocation = line
                # only check new lines added/modified in the file
                if line.startswith('+'):
                    ui.debug('\nchecking line for %s: %s\n\n' % (testDesc, line))
                    testResult, errorLocation = testFunc(line)
                    if testResult:
                        ui.warn('\n%s(s) found in %s for rev %s (change %s):\n' %
                                (testDesc, file, ctx.rev(), short(ctx.node())))
                        ui.warn('%s\n' % diffLocation)
                        ui.warn('%s\n' % line)
                        ui.warn('%s^\n' % (' '*errorLocation,)) # show a pointer to error
                        try:
                            response = ui.promptchoice('(n)o, (y)es, (a)llow %ss for current file\n' % testDesc +
                                                    'Are you sure you want to commit this change? [n]: ' ,
                                                   (('&No'), ('&Yes'), ('&Allow')), 0)
                        except AttributeError:
                            ui.warn('This commit hook requires that you have mercurial 1.4+ installed.  Please upgrade your hg installation.')
                            response = 0
                        if response == 1:
                            # next occurance in file
                            continue
                        elif response == 2:
                            # next file
                            break
                        else:
                            ui.warn('Aborting commit due to %s.\n' % testDesc)
                            # error = True
                            return True
    return False
