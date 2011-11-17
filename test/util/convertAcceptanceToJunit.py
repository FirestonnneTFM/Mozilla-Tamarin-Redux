#!/usr/bin/env python

import getopt,sys,socket,re,os,platform,string


def fixForXmlEscape(str):
    str=str.replace('&','&amp;')
    str=str.replace("'",'&apos;')
    str=str.replace('<','&lt;')
    str=str.replace('>','&gt;')
    str=str.replace('"','&quot;')
    return str

def fixForXmlCdata(str):
    str=str.strip()
    if len(str)>0:
        # change ]]> in source string
        str=str.replace(']]>','] ]>')
        # remove invalid unicode chars
        str=re.sub(b'[\x00-\x08\x0B-\x0C\x0E-\x1F\x7F]','',str)
        str="<![CDATA[%s]]>" % str
    return str

def checkForMatchingVersion(file,version):
    lines=open(file).read().split('\n')
    for line in lines:
        if re.search('property name="version"',line):
            if re.search('value="%s"' % version,line):
                return True
            else:
                return False

def convertPerformanceToJunit(infile,outfile,toplevel):
    lines=open(infile).read().split('\n')
    properties={}
    metric='time'
    dir='.'
    testcontents=''
    skips=errors=failures=total=time=0
    hostname=socket.gethostname()
    if toplevel==None or toplevel=='':
        toplevel=platform.platform()
    systemout=systemerr=''
    properties['platform']=toplevel
    properties['version']='unknown'
    measurements=[]
    for line in lines:
        tokens=line.split()
        if line.startswith('Tamarin tests') and len(tokens)>3:
            tm=tokens[4]
            if tm.find('.'):
                tm=tm[0:tm.find('.')]
            properties['timestamp']='%sT%s' % (tokens[3],tm)
        elif line.startswith('avm'):
            properties['avm']=tokens[1]
            properties['version']=tokens[3]
        elif line.startswith('iterations'):
            properties['iterations']=tokens[1]
        elif line.startswith('Dir'):
            dir=tokens[1]
            dir=dir.replace('.','_')
        elif line.startswith('Metric'):
            metric=tokens[1]
        elif line.startswith('Executing') or line.startswith("test"):
            pass
        elif len(tokens)==2 or len(tokens)==4:
            name=tokens[0]
            value=tokens[1]
            if value.endswith("M"):
                value=value[0:-1]
            try:
                float(value)
            except:
                value=0
            measurements.append([dir,name,metric,value])
    insertMeasurements=False
    if os.path.exists(outfile):
        if checkForMatchingVersion(outfile,properties['version']):
            insertMeasurements=True
        else:
            ctr=0
            newoutfile=outfile
            if newoutfile.endswith('.xml'):
                newoutfile=newoutfile[0:-4]
            while True:
                if os.path.exists('%s%d.xml' % (newoutfile,ctr))==False:
                    outfile='%s%d.xml' % (newoutfile,ctr)
                    break
                if checkForMatchingVersion('%s%d.xml' % (newoutfile,ctr),properties['version']):
                    insertMeasurements=True
                    outfile="%s%d.xml" % (newoutfile,ctr)
                    break
                ctr+=1
    if insertMeasurements:
        lines=open(outfile).read().split('\n')
        for measurement in measurements:
            found=False
            currentclass=currentmetric='unknown'
            for i in range(len(lines)):
                if re.search('classname="%s.%s".* name="%s"' % (toplevel,measurement[0],measurement[1]),lines[i]):
                    currentclass=measurement[0]
                    currentmetric=measurement[1]
                if re.search('<measurement>',lines[i]) and measurement[0]==currentclass and measurement[1]==currentmetric:
                    lines.insert(i+1,'<measurement><name>%s</name><value>%s</value></measurement>' % (measurement[2],measurement[3]))
                    found=True
                    break
            if found==False:
                lasttest=len(lines)-1
                for i in range(len(lines)):
                    if lines[i].lstrip().startswith('</testcase>'):
                        lasttest=i
                        
                lines.insert(lasttest+1,'<testcase classname="%s.%s" name="%s" time="0">' % (toplevel,measurement[0],measurement[1]))
                lines.insert(lasttest+2,'<system-out>')
                lines.insert(lasttest+3,'<![CDATA[')
                lines.insert(lasttest+4,'<measurement><name>%s</name><value>%s</value></measurement>' % (measurement[2],measurement[3]))
                lines.insert(lasttest+5,']]>')
                lines.insert(lasttest+6,'</system-out>')
                lines.insert(lasttest+7,'</testcase>')
        open(outfile,'w').write(string.join(lines,'\n'))
    else:
        contents='<?xml version="1.0" encoding="UTF-8" ?>\n'
        contents+='<testsuite skip="%s" errors="%s" failures="%d" hostname="%s" name="performance-%s" tests="%d" time="%s" timestamp="%s">\n' % (skips,errors,failures,hostname,toplevel,len(measurements),time,properties['timestamp'])
        contents+='<properties>\n'
        for key in properties.keys(): 
            contents+='<property name="%s" value="%s" />\n' % (key,properties[key])
        contents+='</properties>\n'
        for measurement in measurements:
            contents+='<testcase classname="%s.%s" name="%s" time="0">\n<system-out>\n<![CDATA[\n<measurement><name>%s</name><value>%s</value></measurement>\n]]>\n</system-out>\n</testcase>\n' % (toplevel,measurement[0],measurement[1],measurement[2],measurement[3])
        contents+='<system-out>%s</system-out>\n<system-err>%s</system-err>\n</testsuite>' % (fixForXmlCdata(systemout),fixForXmlCdata(systemerr))
        open(outfile,'w').write(contents)
    return outfile
def convertAcceptanceToJunit(infile,outfile,toplevel):
    skips=0
    errors='0'
    failures=''
    hostname=socket.gethostname()
    name=toplevel
    tests=''
    time=''
    timestamp=''
    properties={}
    properties['failures']='0'
    properties['unexpected passes']='0'
    properties['expected failures']='0'
    testresults=[]
    systemout=''
    systemerr=''
    finishedTests=False
    lastout=''
    failedfiles=0
    totalfiles=0
    
    lines=open(infile).read().split('\n')
    for line in lines:
        tokens=line.split()
        if line=='':
            continue
        if line.startswith('Tamarin tests'):
            tm=tokens[4]
            if tm.find('.'):
                tm=tm[0:tm.find('.')]
            timestamp='%sT%s' % (tokens[3],tm)
        if line.startswith('current configuration:'):
            properties['configuration']=tokens[2]
        if line.startswith('avm version:'):
            properties['avmversion']=tokens[2]
        if line.startswith('thread count:'):
            properties['threadcount']=tokens[2]
        if line.startswith('Executing'):
            tests=tokens[1]
            properties['shell']=tokens[5]
        if finishedTests==False and len(tokens)>2 and re.search('^[0-9.]+',line):
            totalfiles+=1
            if lastout!='' and len(testresults)>0:
                testresults[len(testresults)-1]['out']=lastout
            lastout=''
            testobj={}
            fullname=tokens[2]
            testobj['class']=toplevel+'.'+fullname[0:fullname.rfind('/')+1]
            testobj['name']=fullname[fullname.rfind('/')+1:]
            testobj['time']=''
            ctr=3
            while ctr<len(tokens):
                if tokens[ctr]=='time' and len(tokens)>ctr+1:
                    testobj['time']=tokens[ctr+1]
                    break
                testobj['name']+=' %s' % tokens[ctr]
                ctr+=1
            testresults.append(testobj)
        elif finishedTests==False:
            if re.search('^\s+skipping...',line) or re.search('^\s+expected failure',line):
                skips+=1
                lastobj=testresults[len(testresults)-1]
                lastobj['skip']=True
                lastobj['skipout']=line.strip()
                lastobj['skiptype']='skipped'
                if re.search('^\s+skipping...',line):
                    lastobj['skipmessage']='skipped'
                else:
                    lastobj['skipmessage']='expected_Failure'
                lastout+=line+'\n'
            elif re.search('^\s+FAILED',line):
                failedfiles+=1
                lastobj=testresults[len(testresults)-1]
                lastobj['failure']=True
                lastobj['failuremessage']=line
                lastobj['failuretype']='failure'
                lastobj['failureout']=lastout+'\n'+line
                lastout+=line+'\n'
            else:
                lastout+=line+'\n'
        if line.startswith('EXPECTED FAILURES:') or line.startswith('FAILURES'):
            finishedTests=True
        if line.startswith('Start Date'):
            properties['startdate']=tokens[2]+' '+tokens[3]
        if line.startswith('End Date'):
            properties['enddate']=tokens[3]+' '+tokens[4]
        if line.startswith('Test Time'):
            time=tokens[3]
            properties['time']=tokens[3]
        if line.startswith('passes'):
            tests=tokens[2]
            properties['passes']=tokens[2]
        if line.startswith('failures'):
            failures=tokens[2]
            properties['failures']=tokens[2]
        if line.startswith('expected failures'):
            properties['expected failures']=tokens[3]
        if line.startswith('tests skipped'):
            properties['tests skipped']=tokens[3]
        if line.startswith('unexpected passes'):
            properties['unexpected passes']=tokens[3]
    
    contents='<?xml version="1.0" encoding="UTF-8" ?>\n'
    contents+='<testsuite skip="%s" errors="%s" failures="%d" hostname="%s" name="%s" tests="%d" time="%s" timestamp="%s">\n' % (skips,errors,failedfiles,hostname,name,totalfiles,time,timestamp)
    contents+='  <properties>\n'
    for key in properties.keys(): 
        contents+='    <property name="%s" value="%s" />\n' % (key,properties[key])
    contents+='  </properties>\n'
    for testresult in testresults:
        out=''
        contents+='  <testcase classname="%s.%s" name="%s" time="%s">' % (toplevel,testresult['class'],testresult['name'],testresult['time'])
        if testresult.has_key('out'):
            out+=testresult['out']+'\n'
        if testresult.has_key('skip'):
            contents+='<skipped message="%s" type="%s">%s</skipped>\n  ' % (fixForXmlEscape(testresult['skipmessage']),testresult['skiptype'],fixForXmlCdata(testresult['skipout']))
            out+=testresult['skipout']+'\n'
        if testresult.has_key('failure'):
            contents+='<failure message="%s" type="%s">%s</failure>\n  ' % (testresult['failuremessage'],testresult['failuretype'],fixForXmlCdata(testresult['failureout']))
            out+=testresult['failureout']+'\n'
        if out!='':
            contents+='<system-out>%s</system-out>' % fixForXmlCdata(out)
        contents+='</testcase>\n'
    contents+='<system-out>%s</system-out>\n<system-err>%s</system-err>\n</testsuite>' % (fixForXmlCdata(systemout),fixForXmlCdata(systemerr))
    open(outfile,'w').write(contents)


if __name__ == '__main__':

    infile='runtests.txt'
    outfile='runtests.xml'
    toplevel='acceptance'
    usage='--ifile=input file --ofile=junit xml file'
        
    try:
        opts, args = getopt.getopt(sys.argv[1:], '', ['ofile=','ifile=','toplevel='])
    except:
        print(sys.argv)
        print('error parsing options\n%s' % usage)
        sys.exit(1)
    
    for o,v in opts:
        if o=='--ifile':
            infile=v
        elif o=='--ofile':
            outfile=v
        elif o=='--toplevel':
            toplevel=v
    
    if os.path.exists(infile)==False:
        print('error: file %s does not exist' % infile)
        sys.exit(1)
    
    print("converting file '%s' to '%s' toplevel is '%s'" % (infile,outfile,toplevel))
    convertAcceptanceToJunit(infile,outfile,toplevel)
    print("created file '%s'" % outfile)

