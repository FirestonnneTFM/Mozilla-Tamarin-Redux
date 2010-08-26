#!/usr/bin/env python
# -*- Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5)
#
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
# Portions created by the Initial Developer are Copyright (C) 2010
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
# ***** END LICENSE BLOCK ***** */
#

'''
usage:
  The script parses a bullseye code coverage binary file and generates a list of missing functions, and several csv files
  for use with confluence tables and charts.

  requirement for the csv filename output to look correct must run this script with cwd set to the tamarin-redux directory

  parsecodecoverage.py --covfile avm.cov --build=5110 --skips=other-licenses,pcre,eval,Total --datadir=./data

  input:
     --covfile <bullseye merged binary .cov>
     --incsvfile <optional: use a bullseye csv as input instead of a binary .cov file>
     --build   <hg revision number>
     --skips   <list of modules to skip seperated by ,>
     --datadir <data directory>
     
     codecoverage-fn-summary.csv        # historical uncovered functions
     codecoverage-fnpercent-summary.csv # historical coverage % branches
     codecoverage-bc-summary.csv        # historical uncovered branches
     codecoverage-bcpercent-summary.csv # historical coverage % branches 

     ** can pass in --incsvfile=file.csv instead of avm.cov

  output:
     these files are created:
         codecoverage-info.csv              # build number and timestamp
         codecoverage-summary.csv           # function and branch data table for current build for table
         codecoverage-missingfn.csv         # list of uncovered functions
         codecoverage.csv                   # bullseye csv
     these files are appended:
         codecoverage-fn-summary.csv        # uncovered function historical for chart
         codecoverage-bc-summary.csv        # uncovered branches/conditions historical for chart
         codecoverage-fnpercent-summary.csv # function coverage % historical for chart
         codecoverage-bcpercent-summary.csv # branches/conditions coverage % historical for chart

  bullseye tool must be installed and in the path, covfn is executed from bullseye tested with version 7.13.32

  CSV output formats:
  codecoverage-missingfn.csv format:  build,module name,source file name, function name
  codecoverage-info.csv format (single line): build: ###, updated: YYYY-MM-DD HH:MM
  codecoverage-summary.csv format: module,uncovered fns,total fns,% fn cov,uncovered branches,% branch cov,total branches,% branch cov
  codecoverage-fn-summary.csv format: each column is per build uncovered functions, rows are modules
  codecoverage-fnpercent-summary.csv format: each column is per build % function coverage, rows are modules
  codecoverage-bc-summary.csv format: each column is per build uncovered branches, rows are modules
  codecoverage-bcpercent-summary.csv format: each column is per build % branch coverage, rows are modules

'''
import getopt,os,re,subprocess,sys,datetime

class ParseCodeCoverage:
    covfile=None
    incsvfile=None
    outcsvfile=None

    datadir='./data'
    missingfnfile=None
    info=None
    summary=None
    fnsummary=None
    fnpercentsummary=None
    bcsummary=None
    bcpercentsummary=None
    defaultcovcsv=None
    modulelist=None

    skips='other-licenses,pcre,Total,eval'
    build='unknown'

    options=''
    longOptions=['covfile=','build=','skips=','incsvfile=','datadir=']

    def __init__(self):
        self.parseOptions()

        # set file names
        self.missingfnfile=self.datadir+'/codecoverage-missingfn.csv'
        self.info=self.datadir+'/codecoverage-info.csv'
        self.summary=self.datadir+'/codecoverage-summary.csv'
        self.fnsummary=self.datadir+'/codecoverage-fn-summary.csv'
        self.fnpercentsummary=self.datadir+'/codecoverage-fnpercent-summary.csv'
        self.bcsummary=self.datadir+'/codecoverage-bc-summary.csv'
        self.bcpercentsummary=self.datadir+'/codecoverage-bcpercent-summary.csv'
        self.defaultcovcsv=self.datadir+'/codecoverage.csv'

        # if incsvfile not set run covfn to generate the csv file
        if self.incsvfile==None:
            self.runcovfn()
        else:
            self.outcsvfile=self.incsvfile

        # parse the csv file into missingfn csv string, and dictionaries: module:fncovered, module:fntotal, 
        #       module:bccovered, module:bctotal
        csvdata, fnucovered,fntotal,bcucovered,bctotal = self.processCSV()
        self.modulelist=fntotal.keys()
        self.modulelist.sort(key=str.lower)

        # write the missing fn csv file
        if self.missingfnfile!=None:
            self.saveCSV(csvdata)

        # write the csv table for current build and csv table with build number and timestamp
        if self.summary!=None:
            self.generateSummaryTable(fnucovered,fntotal,bcucovered,bctotal)
            self.generateTime()
   
        # append csv for missing function chart
        if self.fnsummary!=None:
            self.generateSummary(self.fnsummary,fnucovered)

        # append csv for uncovered branches chart
        if self.bcsummary!=None:
            self.generateSummary(self.bcsummary,bcucovered)

        # append csv for function percent chart
        if self.fnpercentsummary!=None:
            self.generatePercentSummary(self.fnpercentsummary,fnucovered,fntotal)

        # append csv for branches percent chart
        if self.bcpercentsummary!=None:
            self.generatePercentSummary(self.bcpercentsummary,bcucovered,bctotal)

        print('finished')        

    def usage(self,c):
        print('usage: %s [options]' % sys.argv[0])
        print('    --covfile     set the bullseye .cov file to be processing, assumes bullseye is installed')
        print('    --incsvfile   set the csv file to load, the csv is returned by covfn --csv > file.csv,')
        print('                     if not set covfn --csv is run')
        print('    --build       set the build number')
        print('    --skips       set the list of modules to skip use , as separator e.g. pcre,Total,eval')
        print('    --datadir     sets the data directory')
        sys.exit(c)

    def parseOptions(self):
        try:
            opts,args = getopt.getopt(sys.argv[1:], self.options,self.longOptions)
        except:
            print(sys.exc_info()[1])
            self.usage(2)

        for o,v in opts:
            if o in ('--covfile'):
                self.covfile=v
            if o in ('--incsvfile'):
                self.incsvfile=v
            if o in ('--build'):
                self.build=v
            if o in ('--skips'):
                self.skips=v.split(',')
            if o in ('--datadir'):
                self.datadir=v
                if os.path.exists(self.datadir)==False:
                    os.mkdirs(self.datadir)

        if self.covfile==None and self.incsvfile==None:
            print('--covfile or --incsvfile must be set')
            sys.exit(1)

    def runcovfn(self):
        if self.outcsvfile==None:
            self.outcsvfile=self.defaultcovcsv

        print('processing .cov binary to %s...' % self.outcsvfile)
 
        covarg=''
        if self.covfile!=None:
            covarg='--file %s' % self.covfile

        cmd='covfn %s --no-banner --csv' % covarg
        if os.path.exists(self.outcsvfile):
            os.unlink(self.outcsvfile)

        process=subprocess.Popen(cmd,shell=True,stdout=open(self.outcsvfile,'w'),stderr=subprocess.PIPE)
        (stdout,stderr)=process.communicate()

    def processCSV(self):
        print('parsing %s...' % self.outcsvfile)
        lines=open(self.outcsvfile).read()
        output=""
        # throw away header(1st) and summary(last) lines
        lines=lines.split('\n')[1:-1]
        uncoveredfncount={}
        totalfncount={}
        uncoveredbccount={}
        totalbccount={}
        output+='build,module,source,function\n'
        modulefiles={}
        for line in lines:
            tokens=self.mysplit(line)
            if len(tokens)<6:
                continue
            # check if file name contains extra directories
            if tokens[1].find('repo/')>-1:
                tokens[1]=tokens[1][tokens[1].find('repo/')+5:]
            if tokens[1].find('tamarin-redux/')>-1:
                tokens[1]=tokens[1][tokens[1].find('tamarin-redux/')+14:]
            # set module to name before '/'
            module=''
            dirs=re.findall('[A-Za-z0-9_.-]+',tokens[1])
            if len(dirs)>1:
                module=dirs[0]
            else:
                continue
            # skip modules for third-party apis
            if module in self.skips:
                continue
            # check if function is not covered
            if tokens[3]=='0':
                output+='%s,%s,%s,"%s"\n'%(self.build,module,tokens[1],tokens[0])
                if uncoveredfncount.has_key(module)==False:
                    uncoveredfncount[module]=0
                uncoveredfncount[module]+=1
            # add to function total
            if totalfncount.has_key(module)==False:
                totalfncount[module]=0
            totalfncount[module]+=1
            # add to b/c covered
            if uncoveredbccount.has_key(module)==False:
                uncoveredbccount[module]=0
            uncoveredbccount[module]+=int(tokens[4])
            # add to b/c total
            if totalbccount.has_key(module)==False:
                totalbccount[module]=0
            totalbccount[module]+=int(tokens[5])
        # flip b/c totals to make uncovered
        for module in uncoveredbccount.keys():
            uncoveredbccount[module]=totalbccount[module]-uncoveredbccount[module]
        return output, uncoveredfncount, totalfncount, uncoveredbccount,totalbccount
        

    def saveCSV(self,csvdata):
        print('saving csv data to %s' % self.missingfnfile)
        open(self.missingfnfile,'w').write(csvdata)

    def generateSummaryTable(self,fnuncovered,fntotal,bcuncovered,bctotal):
        print('generating summary data...')
        if os.path.exists(self.summary):
            os.unlink(self.summary)
        fnuncoveredsum=0
        fntotalsum=0
        bcuncoveredsum=0
        bctotalsum=0
        contents='module,uncovered functions,total functions,% function coverage,uncovered branches,total branches,% branch coverage\n'
        for module in self.modulelist:
            fnuncoveredsum+=fnuncovered[module]
            fntotalsum+=fntotal[module]
            bcuncoveredsum+=bcuncovered[module]
            bctotalsum+=bctotal[module]
            contents+='%s,%s,%s,%s%s,%s,%s,%s%s\n' % (module,fnuncovered[module],fntotal[module],self.calcpercent(fnuncovered[module],fntotal[module]),'%',bcuncovered[module],bctotal[module],self.calcpercent(bcuncovered[module],bctotal[module]),'%')
        contents+='total,%s,%s,%s%s,%s,%s,%s%s\n' % (fnuncoveredsum,fntotalsum,self.calcpercent(fnuncoveredsum,fntotalsum),'%',bcuncoveredsum,bctotalsum,self.calcpercent(bcuncoveredsum,bctotalsum),'%')
        open(self.summary,'w').write(contents)

    def generateTime(self):
        print('generating time file...')
        open(self.info,'w').write('current build: %s,updated: %s' % (self.build,datetime.datetime.today().strftime('%Y-%m-%d %H:%M')))

    def generateSummary(self, file, modulescount):
        print('generating summary %s...' % file)

        if os.path.exists(file)==False:
            summaryFile=open(file,'w')
            summaryFile.write('build\n')
            for module in self.modulelist:
                summaryFile.write('%s\n' % module)
            summaryFile.close()

        modules=modulescount.keys()
        modulefile=open(file).read()
        modulefilelistupdated=''
        fieldslen=0
        for line in modulefile.split('\n'):
            if line=='':
                continue
            if line.startswith('build'):
                modulefileupdated=line+','+self.build+'\n'
            else:
                fields=line.split(',')
                fieldslen=len(fields)
                if modulescount.has_key(fields[0]):
                    modulefileupdated+="%s,%s\n" % (line,modulescount[fields[0]])
                    modules.remove(fields[0])

        for newmodule in modules:
            line=newmodule
            for i in range(fieldslen-1):
                line+=',0'
            line='%s,%s\n' % (line,modulescount[newmodule])
            modulefileupdated+=line
        open(file,'w').write(modulefileupdated)

    def generatePercentSummary(self, file, modulescount, totalmodulescount):
        print('generating percent function summary data...')

        if os.path.exists(file)==False:
            summaryFile=open(file,'w')
            summaryFile.write('build\n')
            for module in self.modulelist:
                summaryFile.write('%s\n' % module)
            summaryFile.close()
        modulefile=open(file).read()
        modulefilelistupdated=''
        fieldslen=0
        modules=modulescount.keys()
        for line in modulefile.split('\n'):
            if line=='':
                continue
            if line.startswith('build'):
                modulefileupdated=line+','+self.build+'\n'
            else:
                fields=line.split(',')
                fieldslen=len(fields)
                if modulescount.has_key(fields[0]):
                    modulefileupdated+="%s,%s\n" % (line,self.calcpercent(modulescount[fields[0]],totalmodulescount[fields[0]]))
                    modules.remove(fields[0])
        for newmodule in modules:
            line=newmodule
            for i in range(fieldslen-1):
                line+=',0'
            line='%s,%s\n' % (line,self.calcpercent(modulescount[newmodule],totalmodulescount[newmodule]))
            modulefileupdated+=line
        open(file,'w').write(modulefileupdated)
        
    def calcpercent(self,value,total):
        value=float(value)
        total=float(total)
        pct=(total-value)*100.0/total
        return '%.1f' % pct

    # workaround since python split does not allow " to span multiple tokens
    # "func1(param1,param)","foo","foo" would not split correctly
    def mysplit(self,line):
        tokens=[]
        while True:
            if len(line)==0:
                break
            if line[0]=='"':
                line=line[1:]
                if line.find('"')==-1:
                    tokens.append(line)
                    break
                tokens.append(line[0:line.find('"')])
                line=line[line.find('"')+2:]
            else:
                if line.find(',')==-1:
                    tokens.append(line)
                    break
                else:
                    tokens.append(line[0:line.find(',')])
                    line=line[line.find(',')+1:]
        return tokens 

if __name__ == '__main__':
    p = ParseCodeCoverage()
