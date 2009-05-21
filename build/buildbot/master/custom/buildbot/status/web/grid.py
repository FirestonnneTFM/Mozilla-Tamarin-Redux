from __future__ import generators

import sys, time, os.path
import urllib

from buildbot import util
from buildbot import version
from buildbot.status.web.base import HtmlResource
#from buildbot.status.web.base import Box, HtmlResource, IBox, ICurrentBox, \
#     ITopBox, td, build_get_class, path_to_build, path_to_step, map_branches
from buildbot.status.web.base import build_get_class

# set grid_css to the full pathname of the css file
if hasattr(sys, "frozen"):
    # all 'data' files are in the directory of our executable
    here = os.path.dirname(sys.executable)
    grid_css = os.path.abspath(os.path.join(here, "grid.css"))
else:
    # running from source; look for a sibling to __file__
    up = os.path.dirname
    grid_css = os.path.abspath(os.path.join(up(__file__), "grid.css"))

class ANYBRANCH: pass # a flag value, used below

class GridStatusResource(HtmlResource):
    # TODO: docs
    status = None
    control = None
    changemaster = None

    def __init__(self, allowForce=True, css=None):
        HtmlResource.__init__(self)

        self.allowForce = allowForce
        self.css = css or grid_css

    def getTitle(self, request):
        status = self.getStatus(request)
        p = status.getProjectName()
        if p:
            return "BuildBot: %s" % p
        else:
            return "BuildBot"

    def getChangemaster(self, request):
        # TODO: this wants to go away, access it through IStatus
        return request.site.buildbot_service.getChangeSvc()

    # handle reloads through an http header
    # TODO: send this as a real header, rather than a tag
    def get_reload_time(self, request):
        if "reload" in request.args:
            try:
                reload_time = int(request.args["reload"][0])
                return max(reload_time, 15)
            except ValueError:
                pass
        return None

    def head(self, request):
        head = ''
        reload_time = self.get_reload_time(request)
        if reload_time is not None:
            head += '<meta http-equiv="refresh" content="%d">\n' % reload_time
        return head

#    def setBuildmaster(self, buildmaster):
#        self.status = buildmaster.getStatus()
#        if self.allowForce:
#            self.control = interfaces.IControl(buildmaster)
#        else:
#            self.control = None
#        self.changemaster = buildmaster.change_svc
#
#        # try to set the page title
#        p = self.status.getProjectName()
#        if p:
#            self.title = "BuildBot: %s" % p
#
    def build_td(self, request, build):
        if not build:
            return '<td class="build">&nbsp;</td>\n'

        if build.isFinished():
            # get the text and annotate the first line with a link
            text = build.getText()
            if not text: text = [ "(no information)" ]
            if text == [ "build", "successful" ]: text = [ "OK" ]
        else:
            text = [ 'building' ]

        name = build.getBuilder().getName()
        number = build.getNumber()
        url = "builders/%s/builds/%d" % (name, number)
        text[0] = '<a href="%s">%s</a>' % (url, text[0])
        text = '<br />\n'.join(text)
        class_ = build_get_class(build)

        return '<td class="build %s">%s</td>\n' % (class_, text)

    def builder_td(self, request, builder):
        state, builds = builder.getState()

        # look for upcoming builds. We say the state is "waiting" if the
        # builder is otherwise idle and there is a scheduler which tells us a
        # build will be performed some time in the near future. TODO: this
        # functionality used to be in BuilderStatus.. maybe this code should
        # be merged back into it.
        upcoming = []
        builderName = builder.getName()
        for s in self.getStatus(request).getSchedulers():
            if builderName in s.listBuilderNames():
                upcoming.extend(s.getPendingBuildTimes())
        if state == "idle" and upcoming:
            state = "waiting"

        # TODO: for now, this pending/upcoming stuff is in the "current
        # activity" box, but really it should go into a "next activity" row
        # instead. The only times it should show up in "current activity" is
        # when the builder is otherwise idle.

        # are any builds pending? (waiting for a slave to be free)
        url = 'builders/%s/' % urllib.quote(builder.getName(), safe='')
        text = '<a href="%s">%s</a>' % (url, builder.getName())
        pbs = builder.getPendingBuilds()
        if state != 'idle' or pbs:
            if pbs:
                text += "<br />(%s with %d pending)" % (state, len(pbs))
            else:
                text += "<br />(%s)" % state

        return  '<td valign="center" class="builder %s">%s</td>\n' % \
            (state, text)

    def stamp_td(self, stamp):
        text = stamp.getText()
        return '<td valign="bottom" class="sourcestamp">%s</td>\n' % \
            "<br />".join(text)

    def body(self, request):
        "This method builds the main waterfall display."

        # get url parameters
        numBuilds = int(request.args.get("width", [5])[0])
        categories = request.args.get("category", [])
        branch = request.args.get("branch", [ANYBRANCH])[0]
        if branch == 'trunk': branch = None

        # and the data we want to render
        status = self.getStatus(request)
        stamps = self.getRecentSourcestamps(status, numBuilds, categories, branch)

        projectURL = status.getProjectURL()
        projectName = status.getProjectName()

        data = '<table class="Grid" border="0" cellspacing="0">\n'
        data += '<tr>\n'
        data += '<td class="title"><a href="%s">%s</a>' % (projectURL, projectName)
        if categories:
            if len(categories) > 1:
                data += '\n<br /><b>Categories:</b><br/>%s' % ('<br/>'.join(categories))
            else:
                data += '\n<br /><b>Category:</b> %s' % categories[0]
        if branch != ANYBRANCH:
            data += '\n<br /><b>Branch:</b> %s' % (branch or 'trunk')
        data += '</td>\n'
        for stamp in stamps:
            data += self.stamp_td(stamp)
        data += '</tr>\n'

        sortedBuilderNames = status.getBuilderNames()[:]
        sortedBuilderNames.sort()
        for bn in sortedBuilderNames:
            builds = [None] * len(stamps)

            builder = status.getBuilder(bn)
            if categories and builder.category not in categories:
                continue

            build = builder.getBuild(-1)
            while build and None in builds:
                ss = build.getSourceStamp(absolute=True)
                for i in range(len(stamps)):
                    if ss == stamps[i] and builds[i] is None:
                        builds[i] = build
                build = build.getPreviousBuild()

            data += '<tr>\n'
            data += self.builder_td(request, builder)
            for build in builds:
                data += self.build_td(request, build)
            data += '</tr>\n'

        data += '</table>\n'

        # TODO: this stuff should be generated by a template of some sort
        data += '<hr /><div class="footer">\n'

        welcomeurl = self.path_to_root(request) + "index.html"
        data += '[<a href="%s">welcome</a>]\n' % welcomeurl
        data += "<br />\n"

        data += '<a href="http://buildbot.sourceforge.net/">Buildbot</a>'
        data += "-%s " % version
        if projectName:
            data += "working for the "
            if projectURL:
                data += "<a href=\"%s\">%s</a> project." % (projectURL,
                                                            projectName)
            else:
                data += "%s project." % projectName
        data += "<br />\n"
        data += ("Page built: " +
                 time.strftime("%a %d %b %Y %H:%M:%S",
                               time.localtime(util.now()))
                 + "\n")
        data += '</div>\n'
        return data

    def getRecentSourcestamps(self, status, numBuilds, categories, branch):
        """
        get a list of the most recent NUMBUILDS SourceStamp tuples, sorted
        by the earliest start we've seen for them
        """
        # TODO: use baseweb's getLastNBuilds?
        sourcestamps = { } # { ss-tuple : earliest time }
        for bn in status.getBuilderNames():
            builder = status.getBuilder(bn)
            if categories and builder.category not in categories:
                continue
            build = builder.getBuild(-1)
            while build:
                ss = build.getSourceStamp(absolute=True)
                start = build.getTimes()[0]
                build = build.getPreviousBuild()

                # skip un-started builds
                if not start: continue

                # skip non-matching branches
                if branch != ANYBRANCH and ss.branch != branch: continue

                sourcestamps[ss] = min(sourcestamps.get(ss, sys.maxint), start)

        # now sort those and take the NUMBUILDS most recent
        sourcestamps = sourcestamps.items()
        sourcestamps.sort(lambda x, y: cmp(x[1], y[1]))
        sourcestamps = map(lambda tup : tup[0], sourcestamps)
        sourcestamps = sourcestamps[-numBuilds:]

        return sourcestamps

