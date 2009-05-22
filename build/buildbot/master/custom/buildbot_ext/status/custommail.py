# -*- test-case-name: buildbot.test.test_status -*-

# the email.MIMEMultipart module is only available in python-2.2.2 and later

import re
from email.Message import Message
from email.Utils import formatdate
from email.MIMEText import MIMEText
try:
    from email.MIMEMultipart import MIMEMultipart
    canDoAttachments = True
except ImportError:
    canDoAttachments = False
import urllib
import string
import os
from cPickle import load, dump

from zope.interface import implements
from twisted.internet import defer
from twisted.mail.smtp import sendmail
from twisted.python import log as twlog

from buildbot import interfaces, util
from buildbot.status import base
from buildbot.status.builder import FAILURE, SUCCESS, WARNINGS
from buildbot.status.mail import MailNotifier


class CustomMail(MailNotifier):
    def __init__(self, fromaddr, mode="all", categories=None, builders=None, branch="",
                 addLogs=False, relayhost="localhost",
                 subject="[buildbot-%(result)s] %(blamelist)s: %(branch)s rev %(src)s",
                 lookup=None, extraRecipients=[],
                 sendToInterestedUsers=True):
                     
        self.builders = None;
        self.branch = branch;
        
        
        
        MailNotifier.__init__(self, fromaddr, mode, categories, builders,
                 addLogs, relayhost,
                 subject,
                 lookup, extraRecipients,
                 sendToInterestedUsers)
                 
                 
    def buildMessage(self, name, build, results):
                
        if build.getSourceStamp().branch != self.branch:
            return
        
        projectName = self.status.getProjectName()
        source = build.getSourceStamp().revision
        buildurl = "%sbuilders/%s/builds/%d" % (self.status.getBuildbotURL(),name,build.getNumber())
        
        # Delimiting wht "," causes email subject line to contain a TAB character for some reason
        blamelist = "|".join(build.getResponsibleUsers())
        p = re.compile(" <[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?>")
        blamelist = p.sub("", blamelist)
        
        res = "pass"
        if results == FAILURE:
            res = "fail"
        text = ""

        text += "Blame:  %s\n" % blamelist
        text += "Slave:  %s\n" % name
        text += "Bot:    %s\n" % self.branch
        text += "        %s\n" % self.status.getBuildbotURL()
        text += "Change: %s\n" % source
        text += "Status: %s\n" % res
        text += "\n"
        
        if results == FAILURE:
            text += "Log(s) of failed build steps:\n"
            for step in build.getSteps():
                if step.getResults()[0] == FAILURE:
                    text += "        %s\n" % ''.join(step.getResults()[1])
                    text += "        %s/steps/%s/logs/stdio\n" % (buildurl,''.join(step.getResults()[1]))
                    text += "\n"
        
        
        # get the previous builds status from file (if exists)
        # buildinfo pickle file structure:
        #  {buildstep:{blamelist:'', revision:'', status:'FAILURE' OR 'WARNING'}}
        # the buildinfo.pck file is located in the platform subdirectory of the master
        
        filename = os.path.join(build.getBuilder().basedir,'buildinfo.pck')
        
        
        buildinfoFileCreated = True
        buildinfoLoaded=True
        
        try:
            buildinfoFile = open(filename, 'r+b')
            buildinfo = load(buildinfoFile)
            buildinfoFile.close()
        except:
            buildinfoLoaded=False
            
        try:
            #overwrite old info file
            buildinfoFile = open(filename, 'wb')
            if not buildinfoLoaded:
                buildinfo = {}
        except:  # can't write so give up
            buildinfoFileCreated = False
        
        # remove any failures that now pass, add new failures
        if buildinfoFileCreated:
            failSteps = []
            for step in build.getSteps():
                result = step.getResults()
                stepname = step.getName()
                if result[0] == SUCCESS:
                    # remove any failures / warnings for this step
                    if stepname in buildinfo:
                        del buildinfo[stepname]
                elif result[0] == FAILURE:
                    # did this step fail previously?
                    if stepname in buildinfo:
                        if buildinfo[stepname]['status'] == 'FAILURE':
                            failSteps.append(stepname)
                    else:
                        # new failure, add to buildinfo
                        buildinfo[stepname] = {'blamelist': blamelist, 'revision':source, 'status':'FAILURE'}
                elif result[0] == WARNINGS:
                    if stepname in buildinfo:
                        if buildinfo[stepname]['status'] == 'WARNING':
                            failSteps.append(stepname)
                    else:
                        # new warning, add to buildinfo
                        buildinfo[stepname] = {'blamelist': blamelist, 'revision':source, 'status':'WARNING'}
            # save the buildinfo file
            dump(buildinfo, buildinfoFile)
            buildinfoFile.close()
            
            # add previous failures to email
            if failSteps:
                text += 'Buildsteps that were failing before this build:\n'
                for step in failSteps:
                    text += '    %s Revision: %s Blamelist: %s\n' %  (step, buildinfo[step]['revision'], buildinfo[step]['blamelist'])
                text += "\n"
        
        m = Message()
        m.set_payload(text)
        
        m['Date'] = formatdate(localtime=True)
        m['Subject'] = self.subject % { 'result': res,
                                        'blamelist': blamelist,
                                        'branch': self.branch,
                                        'src': source,
                                        }

        m['From'] = self.fromaddr
        # m['To'] is added later

        if self.addLogs:
            for log in build.getLogs():
                name = "%s.%s" % (log.getStep().getName(),
                                  log.getName())
                a = MIMEText(log.getText())
                a.add_header('Content-Disposition', "attachment",
                             filename=name)
                m.attach(a)

        # now, who is this message going to?
        dl = []
        recipients = self.extraRecipients[:]
        if self.sendToInterestedUsers and self.lookup:
            for u in build.getInterestedUsers():
                d = defer.maybeDeferred(self.lookup.getAddress, u)
                d.addCallback(recipients.append)
                dl.append(d)
        d = defer.DeferredList(dl)
        d.addCallback(self._gotRecipients, recipients, m)
        return d


    def sendMessage(self, m, recipients):
        s = m.as_string()
        ds = []
        twlog.msg("sending mail (%d bytes) to" % len(s), recipients)
        ds.append(sendmail(self.relayhost, self.fromaddr, recipients, s))
        return defer.DeferredList(ds)


