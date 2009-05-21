# -*- test-case-name: buildbot.test.test_runner -*-

# N.B.: don't import anything that might pull in a reactor yet. Some of our
# subcommands want to load modules that need the gtk reactor.
import os, sys, stat, re, time
import traceback
from twisted.python import usage, util, runtime

from buildbot.interfaces import BuildbotNotRunningError

# this is mostly just a front-end for mktap, twistd, and kill(1), but in the
# future it will also provide an interface to some developer tools that talk
# directly to a remote buildmaster (like 'try' and a status client)

# the create/start/stop commands should all be run as the same user,
# preferably a separate 'buildbot' account.

class MakerBase(usage.Options):
    optFlags = [
        ['help', 'h', "Display this message"],
        ["quiet", "q", "Do not emit the commands being run"],
        ]

    #["basedir", "d", None, "Base directory for the buildmaster"],
    opt_h = usage.Options.opt_help

    def parseArgs(self, *args):
        if len(args) > 0:
            self['basedir'] = args[0]
        else:
            self['basedir'] = None
        if len(args) > 1:
            raise usage.UsageError("I wasn't expecting so many arguments")

    def postOptions(self):
        if self['basedir'] is None:
            raise usage.UsageError("<basedir> parameter is required")
        self['basedir'] = os.path.abspath(self['basedir'])

makefile_sample = """# -*- makefile -*-

# This is a simple makefile which lives in a buildmaster/buildslave
# directory (next to the buildbot.tac file). It allows you to start/stop the
# master or slave by doing 'make start' or 'make stop'.

# The 'reconfig' target will tell a buildmaster to reload its config file.

start:
	twistd --no_save -y buildbot.tac

stop:
	kill `cat twistd.pid`

reconfig:
	kill -HUP `cat twistd.pid`

log:
	tail -f twistd.log
"""

class Maker:
    def __init__(self, config):
        self.config = config
        self.basedir = config['basedir']
        self.force = config.get('force', False)
        self.quiet = config['quiet']

    def mkdir(self):
        if os.path.exists(self.basedir):
            if not self.quiet:
                print "updating existing installation"
            return
        if not self.quiet: print "mkdir", self.basedir
        os.mkdir(self.basedir)

    def mkinfo(self):
        path = os.path.join(self.basedir, "info")
        if not os.path.exists(path):
            if not self.quiet: print "mkdir", path
            os.mkdir(path)
        created = False
        admin = os.path.join(path, "admin")
        if not os.path.exists(admin):
            if not self.quiet:
                print "Creating info/admin, you need to edit it appropriately"
            f = open(admin, "wt")
            f.write("Your Name Here <admin@youraddress.invalid>\n")
            f.close()
            created = True
        host = os.path.join(path, "host")
        if not os.path.exists(host):
            if not self.quiet:
                print "Creating info/host, you need to edit it appropriately"
            f = open(host, "wt")
            f.write("Please put a description of this build host here\n")
            f.close()
            created = True
        if created and not self.quiet:
            print "Please edit the files in %s appropriately." % path

    def chdir(self):
        if not self.quiet: print "chdir", self.basedir
        os.chdir(self.basedir)

    def makeTAC(self, contents, secret=False):
        tacfile = "buildbot.tac"
        if os.path.exists(tacfile):
            oldcontents = open(tacfile, "rt").read()
            if oldcontents == contents:
                if not self.quiet:
                    print "buildbot.tac already exists and is correct"
                return
            if not self.quiet:
                print "not touching existing buildbot.tac"
                print "creating buildbot.tac.new instead"
            tacfile = "buildbot.tac.new"
        f = open(tacfile, "wt")
        f.write(contents)
        f.close()
        if secret:
            os.chmod(tacfile, 0600)

    def makefile(self):
        target = "Makefile.sample"
        if os.path.exists(target):
            oldcontents = open(target, "rt").read()
            if oldcontents == makefile_sample:
                if not self.quiet:
                    print "Makefile.sample already exists and is correct"
                return
            if not self.quiet:
                print "replacing Makefile.sample"
        else:
            if not self.quiet:
                print "creating Makefile.sample"
        f = open(target, "wt")
        f.write(makefile_sample)
        f.close()

    def sampleconfig(self, source):
        target = "master.cfg.sample"
        config_sample = open(source, "rt").read()
        if os.path.exists(target):
            oldcontents = open(target, "rt").read()
            if oldcontents == config_sample:
                if not self.quiet:
                    print "master.cfg.sample already exists and is up-to-date"
                return
            if not self.quiet:
                print "replacing master.cfg.sample"
        else:
            if not self.quiet:
                print "creating master.cfg.sample"
        f = open(target, "wt")
        f.write(config_sample)
        f.close()
        os.chmod(target, 0600)

    def public_html(self, index_html, buildbot_css, robots_txt):
        webdir = os.path.join(self.basedir, "public_html")
        if os.path.exists(webdir):
            if not self.quiet:
                print "public_html/ already exists: not replacing"
            return
        else:
            os.mkdir(webdir)
        if not self.quiet:
            print "populating public_html/"
        target = os.path.join(webdir, "index.html")
        f = open(target, "wt")
        f.write(open(index_html, "rt").read())
        f.close()

        target = os.path.join(webdir, "buildbot.css")
        f = open(target, "wt")
        f.write(open(buildbot_css, "rt").read())
        f.close()

        target = os.path.join(webdir, "robots.txt")
        f = open(target, "wt")
        f.write(open(robots_txt, "rt").read())
        f.close()

    def populate_if_missing(self, target, source, overwrite=False):
        new_contents = open(source, "rt").read()
        if os.path.exists(target):
            old_contents = open(target, "rt").read()
            if old_contents != new_contents:
                if overwrite:
                    if not self.quiet:
                        print "%s has old/modified contents" % target
                        print " overwriting it with new contents"
                    open(target, "wt").write(new_contents)
                else:
                    if not self.quiet:
                        print "%s has old/modified contents" % target
                        print " writing new contents to %s.new" % target
                    open(target + ".new", "wt").write(new_contents)
            # otherwise, it's up to date
        else:
            if not self.quiet:
                print "populating %s" % target
            open(target, "wt").write(new_contents)

    def upgrade_public_html(self, index_html, buildbot_css, robots_txt):
        webdir = os.path.join(self.basedir, "public_html")
        if not os.path.exists(webdir):
            if not self.quiet:
                print "populating public_html/"
            os.mkdir(webdir)
        self.populate_if_missing(os.path.join(webdir, "index.html"),
                                 index_html)
        self.populate_if_missing(os.path.join(webdir, "buildbot.css"),
                                 buildbot_css)
        self.populate_if_missing(os.path.join(webdir, "robots.txt"),
                                 robots_txt)

    def check_master_cfg(self):
        from buildbot.master import BuildMaster
        from twisted.python import log, failure

        master_cfg = os.path.join(self.basedir, "master.cfg")
        if not os.path.exists(master_cfg):
            if not self.quiet:
                print "No master.cfg found"
            return 1

        # side-effects of loading the config file:

        #  for each Builder defined in c['builders'], if the status directory
        #  didn't already exist, it will be created, and the
        #  $BUILDERNAME/builder pickle might be created (with a single
        #  "builder created" event).

        # we put basedir in front of sys.path, because that's how the
        # buildmaster itself will run, and it is quite common to have the
        # buildmaster import helper classes from other .py files in its
        # basedir.

        if sys.path[0] != self.basedir:
            sys.path.insert(0, self.basedir)

        m = BuildMaster(self.basedir)
        # we need to route log.msg to stdout, so any problems can be seen
        # there. But if everything goes well, I'd rather not clutter stdout
        # with log messages. So instead we add a logObserver which gathers
        # messages and only displays them if something goes wrong.
        messages = []
        log.addObserver(messages.append)
        try:
            # this will raise an exception if there's something wrong with
            # the config file. Note that this BuildMaster instance is never
            # started, so it won't actually do anything with the
            # configuration.
            m.loadConfig(open(master_cfg, "r"))
        except:
            f = failure.Failure()
            if not self.quiet:
                print
                for m in messages:
                    print "".join(m['message'])
                print f
                print
                print "An error was detected in the master.cfg file."
                print "Please correct the problem and run 'buildbot upgrade-master' again."
                print
            return 1
        return 0

class UpgradeMasterOptions(MakerBase):
    optFlags = [
        ["replace", "r", "Replace any modified files without confirmation."],
        ]

    def getSynopsis(self):
        return "Usage:    buildbot upgrade-master [options] <basedir>"

    longdesc = """
    This command takes an existing buildmaster working directory and
    adds/modifies the files there to work with the current version of
    buildbot. When this command is finished, the buildmaster directory should
    look much like a brand-new one created by the 'create-master' command.

    Use this after you've upgraded your buildbot installation and before you
    restart the buildmaster to use the new version.

    If you have modified the files in your working directory, this command
    will leave them untouched, but will put the new recommended contents in a
    .new file (for example, if index.html has been modified, this command
    will create index.html.new). You can then look at the new version and
    decide how to merge its contents into your modified file.
    """

def upgradeMaster(config):
    basedir = config['basedir']
    m = Maker(config)
    # TODO: check Makefile
    # TODO: check TAC file
    # check web files: index.html, classic.css, robots.txt
    webdir = os.path.join(basedir, "public_html")
    m.upgrade_public_html(util.sibpath(__file__, "../status/web/index.html"),
                          util.sibpath(__file__, "../status/web/classic.css"),
                          util.sibpath(__file__, "../status/web/robots.txt"),
                          )
    m.populate_if_missing(os.path.join(basedir, "master.cfg.sample"),
                          util.sibpath(__file__, "sample.cfg"),
                          overwrite=True)
    rc = m.check_master_cfg()
    if rc:
        return rc
    if not config['quiet']:
        print "upgrade complete"


class MasterOptions(MakerBase):
    optFlags = [
        ["force", "f",
         "Re-use an existing directory (will not overwrite master.cfg file)"],
        ]
    optParameters = [
        ["config", "c", "master.cfg", "name of the buildmaster config file"],
        ["log-size", "s", "1000000",
         "size at which to rotate twisted log files"],
        ["log-count", "l", "None",
         "limit the number of kept old twisted log files"],
        ]
    def getSynopsis(self):
        return "Usage:    buildbot create-master [options] <basedir>"

    longdesc = """
    This command creates a buildmaster working directory and buildbot.tac
    file. The master will live in <dir> and create various files there.

    At runtime, the master will read a configuration file (named
    'master.cfg' by default) in its basedir. This file should contain python
    code which eventually defines a dictionary named 'BuildmasterConfig'.
    The elements of this dictionary are used to configure the Buildmaster.
    See doc/config.xhtml for details about what can be controlled through
    this interface."""

    def postOptions(self):
        MakerBase.postOptions(self)
        if not re.match('^\d+$', self['log-size']):
            raise usage.UsageError("log-size parameter needs to be an int")
        if not re.match('^\d+$', self['log-count']) and \
                self['log-count'] != 'None':
            raise usage.UsageError("log-count parameter needs to be an int "+
                                   " or None")


masterTAC = """
from twisted.application import service
from buildbot.master import BuildMaster

basedir = r'%(basedir)s'
configfile = r'%(config)s'
rotateLength = %(log-size)s
maxRotatedFiles = %(log-count)s

application = service.Application('buildmaster')
try:
  from twisted.python.logfile import LogFile
  from twisted.python.log import ILogObserver, FileLogObserver
  logfile = LogFile.fromFullPath("twistd.log", rotateLength=rotateLength,
                                 maxRotatedFiles=maxRotatedFiles)
  application.setComponent(ILogObserver, FileLogObserver(logfile).emit)
except ImportError:
  # probably not yet twisted 8.2.0 and beyond, can't set log yet
  pass
BuildMaster(basedir, configfile).setServiceParent(application)

"""

def createMaster(config):
    m = Maker(config)
    m.mkdir()
    m.chdir()
    contents = masterTAC % config
    m.makeTAC(contents)
    m.sampleconfig(util.sibpath(__file__, "sample.cfg"))
    m.public_html(util.sibpath(__file__, "../status/web/index.html"),
                  util.sibpath(__file__, "../status/web/classic.css"),
                  util.sibpath(__file__, "../status/web/robots.txt"),
                  )
    m.makefile()

    if not m.quiet: print "buildmaster configured in %s" % m.basedir

class SlaveOptions(MakerBase):
    optFlags = [
        ["force", "f", "Re-use an existing directory"],
        ]
    optParameters = [
#        ["name", "n", None, "Name for this build slave"],
#        ["passwd", "p", None, "Password for this build slave"],
#        ["basedir", "d", ".", "Base directory to use"],
#        ["master", "m", "localhost:8007",
#         "Location of the buildmaster (host:port)"],

        ["keepalive", "k", 600,
         "Interval at which keepalives should be sent (in seconds)"],
        ["usepty", None, 0,
         "(1 or 0) child processes should be run in a pty (default 0)"],
        ["umask", None, "None",
         "controls permissions of generated files. Use --umask=022 to be world-readable"],
        ["maxdelay", None, 300,
         "Maximum time between connection attempts"],
        ["log-size", "s", "1000000",
         "size at which to rotate twisted log files"],
        ["log-count", "l", "None",
         "limit the number of kept old twisted log files"],
        ]
    
    longdesc = """
    This command creates a buildslave working directory and buildbot.tac
    file. The bot will use the <name> and <passwd> arguments to authenticate
    itself when connecting to the master. All commands are run in a
    build-specific subdirectory of <basedir>. <master> is a string of the
    form 'hostname:port', and specifies where the buildmaster can be reached.

    <name>, <passwd>, and <master> will be provided by the buildmaster
    administrator for your bot. You must choose <basedir> yourself.
    """

    def getSynopsis(self):
        return "Usage:    buildbot create-slave [options] <basedir> <master> <name> <passwd>"

    def parseArgs(self, *args):
        if len(args) < 4:
            raise usage.UsageError("command needs more arguments")
        basedir, master, name, passwd = args
        self['basedir'] = basedir
        self['master'] = master
        self['name'] = name
        self['passwd'] = passwd

    def postOptions(self):
        MakerBase.postOptions(self)
        self['usepty'] = int(self['usepty'])
        self['keepalive'] = int(self['keepalive'])
        self['maxdelay'] = int(self['maxdelay'])
        if self['master'].find(":") == -1:
            raise usage.UsageError("--master must be in the form host:portnum")
        if not re.match('^\d+$', self['log-size']):
            raise usage.UsageError("log-size parameter needs to be an int")
        if not re.match('^\d+$', self['log-count']) and \
                self['log-count'] != 'None':
            raise usage.UsageError("log-count parameter needs to be an int "+
                                   " or None")

slaveTAC = """
from twisted.application import service
from buildbot.slave.bot import BuildSlave

basedir = r'%(basedir)s'
buildmaster_host = '%(host)s'
port = %(port)d
slavename = '%(name)s'
passwd = '%(passwd)s'
keepalive = %(keepalive)d
usepty = %(usepty)d
umask = %(umask)s
maxdelay = %(maxdelay)d
rotateLength = %(log-size)s
maxRotatedFiles = %(log-count)s

application = service.Application('buildslave')
try:
  from twisted.python.logfile import LogFile
  from twisted.python.log import ILogObserver, FileLogObserver
  logfile = LogFile.fromFullPath("twistd.log", rotateLength=rotateLength,
                                 maxRotatedFiles=maxRotatedFiles)
  application.setComponent(ILogObserver, FileLogObserver(logfile).emit)
except ImportError:
  # probably not yet twisted 8.2.0 and beyond, can't set log yet
  pass
s = BuildSlave(buildmaster_host, port, slavename, passwd, basedir,
               keepalive, usepty, umask=umask, maxdelay=maxdelay)
s.setServiceParent(application)

"""

def createSlave(config):
    m = Maker(config)
    m.mkdir()
    m.chdir()
    try:
        master = config['master']
        host, port = re.search(r'(.+):(\d+)', master).groups()
        config['host'] = host
        config['port'] = int(port)
    except:
        print "unparseable master location '%s'" % master
        print " expecting something more like localhost:8007"
        raise
    contents = slaveTAC % config

    m.makeTAC(contents, secret=True)

    m.makefile()
    m.mkinfo()

    if not m.quiet: print "buildslave configured in %s" % m.basedir



def stop(config, signame="TERM", wait=False):
    import signal
    basedir = config['basedir']
    quiet = config['quiet']
    os.chdir(basedir)
    try:
        f = open("twistd.pid", "rt")
    except:
        raise BuildbotNotRunningError
    pid = int(f.read().strip())
    signum = getattr(signal, "SIG"+signame)
    timer = 0
    os.kill(pid, signum)
    if not wait:
        if not quiet:
            print "sent SIG%s to process" % signame
        return
    time.sleep(0.1)
    while timer < 10:
        # poll once per second until twistd.pid goes away, up to 10 seconds
        try:
            os.kill(pid, 0)
        except OSError:
            if not quiet:
                print "buildbot process %d is dead" % pid
            return
        timer += 1
        time.sleep(1)
    if not quiet:
        print "never saw process go away"

def restart(config):
    quiet = config['quiet']
    from buildbot.scripts.startup import start
    try:
        stop(config, wait=True)
    except BuildbotNotRunningError:
        pass
    if not quiet:
        print "now restarting buildbot process.."
    start(config)


def loadOptions(filename="options", here=None, home=None):
    """Find the .buildbot/FILENAME file. Crawl from the current directory up
    towards the root, and also look in ~/.buildbot . The first directory
    that's owned by the user and has the file we're looking for wins. Windows
    skips the owned-by-user test.
    
    @rtype:  dict
    @return: a dictionary of names defined in the options file. If no options
             file was found, return an empty dict.
    """

    if here is None:
        here = os.getcwd()
    here = os.path.abspath(here)

    if home is None:
        if runtime.platformType == 'win32':
            home = os.path.join(os.environ['APPDATA'], "buildbot")
        else:
            home = os.path.expanduser("~/.buildbot")

    searchpath = []
    toomany = 20
    while True:
        searchpath.append(os.path.join(here, ".buildbot"))
        next = os.path.dirname(here)
        if next == here:
            break # we've hit the root
        here = next
        toomany -= 1 # just in case
        if toomany == 0:
            raise ValueError("Hey, I seem to have wandered up into the "
                             "infinite glories of the heavens. Oops.")
    searchpath.append(home)

    localDict = {}

    for d in searchpath:
        if os.path.isdir(d):
            if runtime.platformType != 'win32':
                if os.stat(d)[stat.ST_UID] != os.getuid():
                    print "skipping %s because you don't own it" % d
                    continue # security, skip other people's directories
            optfile = os.path.join(d, filename)
            if os.path.exists(optfile):
                try:
                    f = open(optfile, "r")
                    options = f.read()
                    exec options in localDict
                except:
                    print "error while reading %s" % optfile
                    raise
                break

    for k in localDict.keys():
        if k.startswith("__"):
            del localDict[k]
    return localDict

class StartOptions(MakerBase):
    optFlags = [
        ['quiet', 'q', "Don't display startup log messages"],
        ]
    def getSynopsis(self):
        return "Usage:    buildbot start <basedir>"

class StopOptions(MakerBase):
    def getSynopsis(self):
        return "Usage:    buildbot stop <basedir>"

class ReconfigOptions(MakerBase):
    optFlags = [
        ['quiet', 'q', "Don't display log messages about reconfiguration"],
        ]
    def getSynopsis(self):
        return "Usage:    buildbot reconfig <basedir>"



class RestartOptions(MakerBase):
    optFlags = [
        ['quiet', 'q', "Don't display startup log messages"],
        ]
    def getSynopsis(self):
        return "Usage:    buildbot restart <basedir>"

class DebugClientOptions(usage.Options):
    optFlags = [
        ['help', 'h', "Display this message"],
        ]
    optParameters = [
        ["master", "m", None,
         "Location of the buildmaster's slaveport (host:port)"],
        ["passwd", "p", None, "Debug password to use"],
        ]

    def parseArgs(self, *args):
        if len(args) > 0:
            self['master'] = args[0]
        if len(args) > 1:
            self['passwd'] = args[1]
        if len(args) > 2:
            raise usage.UsageError("I wasn't expecting so many arguments")

def debugclient(config):
    from buildbot.clients import debug
    opts = loadOptions()

    master = config.get('master')
    if not master:
        master = opts.get('master')
    if master is None:
        raise usage.UsageError("master must be specified: on the command "
                               "line or in ~/.buildbot/options")

    passwd = config.get('passwd')
    if not passwd:
        passwd = opts.get('debugPassword')
    if passwd is None:
        raise usage.UsageError("passwd must be specified: on the command "
                               "line or in ~/.buildbot/options")

    d = debug.DebugWidget(master, passwd)
    d.run()

class StatusClientOptions(usage.Options):
    optFlags = [
        ['help', 'h', "Display this message"],
        ]
    optParameters = [
        ["master", "m", None,
         "Location of the buildmaster's status port (host:port)"],
        ]

    def parseArgs(self, *args):
        if len(args) > 0:
            self['master'] = args[0]
        if len(args) > 1:
            raise usage.UsageError("I wasn't expecting so many arguments")

def statuslog(config):
    from buildbot.clients import base
    opts = loadOptions()
    master = config.get('master')
    if not master:
        master = opts.get('masterstatus')
    if master is None:
        raise usage.UsageError("master must be specified: on the command "
                               "line or in ~/.buildbot/options")
    c = base.TextClient(master)
    c.run()

def statusgui(config):
    from buildbot.clients import gtkPanes
    opts = loadOptions()
    master = config.get('master')
    if not master:
        master = opts.get('masterstatus')
    if master is None:
        raise usage.UsageError("master must be specified: on the command "
                               "line or in ~/.buildbot/options")
    c = gtkPanes.GtkClient(master)
    c.run()

class SendChangeOptions(usage.Options):
    optParameters = [
        ("master", "m", None,
         "Location of the buildmaster's PBListener (host:port)"),
        ("username", "u", None, "Username performing the commit"),
        ("branch", "b", None, "Branch specifier"),
        ("category", "c", None, "Category of repository"),
        ("revision", "r", None, "Revision specifier (string)"),
        ("revision_number", "n", None, "Revision specifier (integer)"),
        ("revision_file", None, None, "Filename containing revision spec"),
        ("comments", "m", None, "log message"),
        ("logfile", "F", None,
         "Read the log messages from this file (- for stdin)"),
        ]
    def getSynopsis(self):
        return "Usage:    buildbot sendchange [options] filenames.."
    def parseArgs(self, *args):
        self['files'] = args


def sendchange(config, runReactor=False):
    """Send a single change to the buildmaster's PBChangeSource. The
    connection will be drpoped as soon as the Change has been sent."""
    from buildbot.clients.sendchange import Sender

    opts = loadOptions()
    user = config.get('username', opts.get('username'))
    master = config.get('master', opts.get('master'))
    branch = config.get('branch', opts.get('branch'))
    category = config.get('category', opts.get('category'))
    revision = config.get('revision')
    # SVN and P4 use numeric revisions
    if config.get("revision_number"):
        revision = int(config['revision_number'])
    if config.get("revision_file"):
        revision = open(config["revision_file"],"r").read()

    comments = config.get('comments')
    if not comments and config.get('logfile'):
        if config['logfile'] == "-":
            f = sys.stdin
        else:
            f = open(config['logfile'], "rt")
        comments = f.read()
    if comments is None:
        comments = ""

    files = config.get('files', [])

    assert user, "you must provide a username"
    assert master, "you must provide the master location"

    s = Sender(master, user)
    d = s.send(branch, revision, comments, files, category=category)
    if runReactor:
        d.addCallbacks(s.printSuccess, s.printFailure)
        d.addBoth(s.stop)
        s.run()
    return d


class ForceOptions(usage.Options):
    optParameters = [
        ["builder", None, None, "which Builder to start"],
        ["branch", None, None, "which branch to build"],
        ["revision", None, None, "which revision to build"],
        ["reason", None, None, "the reason for starting the build"],
        ]

    def parseArgs(self, *args):
        args = list(args)
        if len(args) > 0:
            if self['builder'] is not None:
                raise usage.UsageError("--builder provided in two ways")
            self['builder'] = args.pop(0)
        if len(args) > 0:
            if self['reason'] is not None:
                raise usage.UsageError("--reason provided in two ways")
            self['reason'] = " ".join(args)


class TryOptions(usage.Options):
    optParameters = [
        ["connect", "c", None,
         "how to reach the buildmaster, either 'ssh' or 'pb'"],
        # for ssh, use --tryhost, --username, and --trydir
        ["tryhost", None, None,
         "the hostname (used by ssh) for the buildmaster"],
        ["trydir", None, None,
         "the directory (on the tryhost) where tryjobs are deposited"],
        ["username", "u", None, "Username performing the trial build"],
        # for PB, use --master, --username, and --passwd
        ["master", "m", None,
         "Location of the buildmaster's PBListener (host:port)"],
        ["passwd", None, None, "password for PB authentication"],

        ["diff", None, None,
         "Filename of a patch to use instead of scanning a local tree. Use '-' for stdin."],
        ["patchlevel", "p", 0,
         "Number of slashes to remove from patch pathnames, like the -p option to 'patch'"],

        ["baserev", None, None,
         "Base revision to use instead of scanning a local tree."],

        ["vc", None, None,
         "The VC system in use, one of: cvs,svn,tla,baz,darcs"],
        ["branch", None, None,
         "The branch in use, for VC systems that can't figure it out"
         " themselves"],

        ["builder", "b", None,
         "Run the trial build on this Builder. Can be used multiple times."],
        ["properties", None, None,
         "A set of properties made available in the build environment, format:prop=value,propb=valueb..."],
        ]

    optFlags = [
        ["wait", None, "wait until the builds have finished"],
        ["dryrun", 'n', "Gather info, but don't actually submit."],
        ]

    def __init__(self):
        super(TryOptions, self).__init__()
        self['builders'] = []
        self['properties'] = {}

    def opt_builder(self, option):
        self['builders'].append(option)

    def opt_properties(self, option):
        # We need to split the value of this option into a dictionary of properties
        properties = {}
        propertylist = option.split(",")
        for i in range(0,len(propertylist)):
            print propertylist[i]
            splitproperty = propertylist[i].split("=")
            properties[splitproperty[0]] = splitproperty[1]
        self['properties'] = properties

    def opt_patchlevel(self, option):
        self['patchlevel'] = int(option)

    def getSynopsis(self):
        return "Usage:    buildbot try [options]"

def doTry(config):
    from buildbot.scripts import tryclient
    t = tryclient.Try(config)
    t.run()

class TryServerOptions(usage.Options):
    optParameters = [
        ["jobdir", None, None, "the jobdir (maildir) for submitting jobs"],
        ]

def doTryServer(config):
    import md5
    jobdir = os.path.expanduser(config["jobdir"])
    job = sys.stdin.read()
    # now do a 'safecat'-style write to jobdir/tmp, then move atomically to
    # jobdir/new . Rather than come up with a unique name randomly, I'm just
    # going to MD5 the contents and prepend a timestamp.
    timestring = "%d" % time.time()
    jobhash = md5.new(job).hexdigest()
    fn = "%s-%s" % (timestring, jobhash)
    tmpfile = os.path.join(jobdir, "tmp", fn)
    newfile = os.path.join(jobdir, "new", fn)
    f = open(tmpfile, "w")
    f.write(job)
    f.close()
    os.rename(tmpfile, newfile)


class CheckConfigOptions(usage.Options):
    optFlags = [
        ['quiet', 'q', "Don't display error messages or tracebacks"],
    ]

    def getSynopsis(self):
        return "Usage		:buildbot checkconfig [configFile]\n" + \
         "		If not specified, 'master.cfg' will be used as 'configFile'"

    def parseArgs(self, *args):
        if len(args) >= 1:
            self['configFile'] = args[0]
        else:
            self['configFile'] = 'master.cfg'


def doCheckConfig(config):
    quiet = config.get('quiet')
    configFile = config.get('configFile')
    try:
        from buildbot.scripts.checkconfig import ConfigLoader
        ConfigLoader(configFile)
    except:
        if not quiet:
            # Print out the traceback in a nice format
            t, v, tb = sys.exc_info()
            traceback.print_exception(t, v, tb)
        sys.exit(1)

    if not quiet:
        print "Config file is good!"


class Options(usage.Options):
    synopsis = "Usage:    buildbot <command> [command options]"

    subCommands = [
        # the following are all admin commands
        ['create-master', None, MasterOptions,
         "Create and populate a directory for a new buildmaster"],
        ['upgrade-master', None, UpgradeMasterOptions,
         "Upgrade an existing buildmaster directory for the current version"],
        ['create-slave', None, SlaveOptions,
         "Create and populate a directory for a new buildslave"],
        ['start', None, StartOptions, "Start a buildmaster or buildslave"],
        ['stop', None, StopOptions, "Stop a buildmaster or buildslave"],
        ['restart', None, RestartOptions,
         "Restart a buildmaster or buildslave"],

        ['reconfig', None, ReconfigOptions,
         "SIGHUP a buildmaster to make it re-read the config file"],
        ['sighup', None, ReconfigOptions,
         "SIGHUP a buildmaster to make it re-read the config file"],

        ['sendchange', None, SendChangeOptions,
         "Send a change to the buildmaster"],

        ['debugclient', None, DebugClientOptions,
         "Launch a small debug panel GUI"],

        ['statuslog', None, StatusClientOptions,
         "Emit current builder status to stdout"],
        ['statusgui', None, StatusClientOptions,
         "Display a small window showing current builder status"],

        #['force', None, ForceOptions, "Run a build"],
        ['try', None, TryOptions, "Run a build with your local changes"],

        ['tryserver', None, TryServerOptions,
         "buildmaster-side 'try' support function, not for users"],

        ['checkconfig', None, CheckConfigOptions,
         "test the validity of a master.cfg config file"],

        # TODO: 'watch'
        ]

    def opt_version(self):
        import buildbot
        print "Buildbot version: %s" % buildbot.version
        usage.Options.opt_version(self)

    def opt_verbose(self):
        from twisted.python import log
        log.startLogging(sys.stderr)

    def postOptions(self):
        if not hasattr(self, 'subOptions'):
            raise usage.UsageError("must specify a command")


def run():
    config = Options()
    try:
        config.parseOptions()
    except usage.error, e:
        print "%s:  %s" % (sys.argv[0], e)
        print
        c = getattr(config, 'subOptions', config)
        print str(c)
        sys.exit(1)

    command = config.subCommand
    so = config.subOptions

    if command == "create-master":
        createMaster(so)
    elif command == "upgrade-master":
        upgradeMaster(so)
    elif command == "create-slave":
        createSlave(so)
    elif command == "start":
        from buildbot.scripts.startup import start
        start(so)
    elif command == "stop":
        stop(so, wait=True)
    elif command == "restart":
        restart(so)
    elif command == "reconfig" or command == "sighup":
        from buildbot.scripts.reconfig import Reconfigurator
        Reconfigurator().run(so)
    elif command == "sendchange":
        sendchange(so, True)
    elif command == "debugclient":
        debugclient(so)
    elif command == "statuslog":
        statuslog(so)
    elif command == "statusgui":
        statusgui(so)
    elif command == "try":
        doTry(so)
    elif command == "tryserver":
        doTryServer(so)
    elif command == "checkconfig":
        doCheckConfig(so)


