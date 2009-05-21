
import time, urllib
from twisted.python import log
from twisted.web import html
from twisted.web.util import Redirect

from buildbot.status.web.base import HtmlResource, abbreviate_age, OneLineMixin, path_to_slave
from buildbot import version, util

# /buildslaves/$slavename
class OneBuildSlaveResource(HtmlResource, OneLineMixin):
    addSlash = False
    def __init__(self, slavename):
        HtmlResource.__init__(self)
        self.slavename = slavename

    def getTitle(self, req):
        return "Buildbot: %s" % html.escape(self.slavename)

    def getChild(self, path, req):
        if path == "shutdown":
            s = self.getStatus(req)
            slave = s.getSlave(self.slavename)
            slave.setGraceful(True)
        return Redirect(path_to_slave(req, slave))

    def body(self, req):
        s = self.getStatus(req)
        slave = s.getSlave(self.slavename)
        my_builders = []
        for bname in s.getBuilderNames():
            b = s.getBuilder(bname)
            for bs in b.getSlaves():
                slavename = bs.getName()
                if bs.getName() == self.slavename:
                    my_builders.append(b)

        # Current builds
        current_builds = []
        for b in my_builders:
            for cb in b.getCurrentBuilds():
                if cb.getSlavename() == self.slavename:
                    current_builds.append(cb)

        data = []

        projectName = s.getProjectName()

        data.append("<a href=\"%s\">%s</a>\n" % (self.path_to_root(req), projectName))

        data.append("<h1>Build Slave: %s</h1>\n" % self.slavename)

        shutdown_url = req.childLink("shutdown")

        if not slave.isConnected():
            data.append("<h2>NOT CONNECTED</h2>\n")
        elif not slave.getGraceful():
            data.append('''<form method="POST" action="%s">
<input type="submit" value="Gracefully Shutdown">
</form>''' % shutdown_url)
        else:
            data.append("Gracefully shutting down...\n")

        if current_builds:
            data.append("<h2>Currently building:</h2>\n")
            data.append("<ul>\n")
            for build in current_builds:
                data.append("<li>%s</li>\n" % self.make_line(req, build, True))
            data.append("</ul>\n")

        else:
            data.append("<h2>no current builds</h2>\n")

        # Recent builds
        data.append("<h2>Recent builds:</h2>\n")
        data.append("<ul>\n")
        n = 0
        try:
            max_builds = int(req.args.get('builds')[0])
        except:
            max_builds = 10
        for build in s.generateFinishedBuilds(builders=[b.getName() for b in my_builders]):
            if build.getSlavename() == self.slavename:
                n += 1
                data.append("<li>%s</li>\n" % self.make_line(req, build, True))
                if n > max_builds:
                    break
        data.append("</ul>\n")

        projectURL = s.getProjectURL()
        projectName = s.getProjectName()
        data.append('<hr /><div class="footer">\n')

        welcomeurl = self.path_to_root(req) + "index.html"
        data.append("[<a href=\"%s\">welcome</a>]\n" % welcomeurl)
        data.append("<br />\n")

        data.append('<a href="http://buildbot.sourceforge.net/">Buildbot</a>')
        data.append("-%s " % version)
        if projectName:
            data.append("working for the ")
            if projectURL:
                data.append("<a href=\"%s\">%s</a> project." % (projectURL,
                                                            projectName))
            else:
                data.append("%s project." % projectName)
        data.append("<br />\n")
        data.append("Page built: " +
                 time.strftime("%a %d %b %Y %H:%M:%S",
                               time.localtime(util.now()))
                 + "\n")
        data.append("</div>\n")

        return "".join(data)

# /buildslaves
class BuildSlavesResource(HtmlResource):
    title = "BuildSlaves"
    addSlash = True

    def body(self, req):
        s = self.getStatus(req)
        data = ""
        data += "<h1>Build Slaves</h1>\n"

        used_by_builder = {}
        for bname in s.getBuilderNames():
            b = s.getBuilder(bname)
            for bs in b.getSlaves():
                slavename = bs.getName()
                if slavename not in used_by_builder:
                    used_by_builder[slavename] = []
                used_by_builder[slavename].append(bname)

        data += "<ol>\n"
        for name in util.naturalSort(s.getSlaveNames()):
            slave = s.getSlave(name)
            slave_status = s.botmaster.slaves[name].slave_status
            isBusy = len(slave_status.getRunningBuilds())
            data += " <li><a href=\"%s\">%s</a>:\n" % (req.childLink(urllib.quote(name,'')), name)
            data += " <ul>\n"
            builder_links = ['<a href="%s">%s</a>'
                             % (req.childLink("../builders/%s" % bname),bname)
                             for bname in used_by_builder.get(name, [])]
            if builder_links:
                data += ("  <li>Used by Builders: %s</li>\n" %
                         ", ".join(builder_links))
            else:
                data += "  <li>Not used by any Builders</li>\n"
            if slave.isConnected():
                data += "  <li>Slave is currently connected</li>\n"
                admin = slave.getAdmin()
                if admin:
                    # munge it to avoid feeding the spambot harvesters
                    admin = admin.replace("@", " -at- ")
                    data += "  <li>Admin: %s</li>\n" % admin
                last = slave.lastMessageReceived()
                if last:
                    lt = time.strftime("%Y-%b-%d %H:%M:%S",
                                       time.localtime(last))
                    age = abbreviate_age(time.time() - last)
                    data += "  <li>Last heard from: %s " % age
                    data += '<font size="-1">(%s)</font>' % lt
                    data += "</li>\n"
                    if isBusy:
                        data += "<li>Slave is currently building.</li>"
                    else:
                        data += "<li>Slave is idle.</li>"
            else:
                data += "  <li><b>Slave is NOT currently connected</b></li>\n"

            data += " </ul>\n"
            data += " </li>\n"
            data += "\n"

        data += "</ol>\n"

        return data

    def getChild(self, path, req):
        return OneBuildSlaveResource(path)
