#!/usr/bin/env python
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
# Portions created by the Initial Developer are Copyright (C) 2009
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

import sys, array, re, os, struct, time, signal, platform, subprocess, SocketServer, os.path
from os import environ
from subprocess import Popen
from sys import argv
import socket
import re

# for windows use win32api to kill processes
ostype={'CYGWIN_NT-5.1':'win','CYGWIN_NT-5.2':'win','CYGWIN_NT-6.0-WOW64':'win','Windows':'win','Darwin':'mac','Linux':'lnx','Solaris':'sol',}[platform.system()]
if ostype=='win':
    import win32api

# define default players, common locations
ie="c:/Program Files/Internet Explorer/iexplore.exe"
safari="/Applications/Safari.app"
ff={"win":"c:/Program Files/Mozilla Firefox/firefox.exe","lnx":"/usr/bin/firefox","mac":"/Applications/Firefox.app"}[ostype]
sa="c:/builds/latest/FlashPlayer.exe"

# set environment variable: playertype=ie,ff,sa,safari
# if default does not work set: playerpath=path to player or browser
try:
    if environ.has_key('player')==False:
        playertype=ff
    else:
        playertype=environ['player']

    if environ.has_key('playerpath'):
        player=environ['playerpath']
    else:
        player={
            'ie':ie,
            'ff':ff,
            'sa':sa,
            'internetexplorer':ie,
            'firefox':ff,
            'saplayer':sa,
            'safari':safari
        }[playertype]
except:
    player=playertype
    playertype="sa"

if re.search('player',player,re.IGNORECASE):
    buildshell=False
else:
    buildshell=True
# timeout in seconds
socketTimeout=60
scriptTimeoutSeconds=30
maxRecursionDepth=255
pid=0
process=0
delay=2

def putbyte(bytes,n):
    bytes.append(n)

def putword(bytes,n):
    bytes.append(n&0xFF)
    bytes.append((n>>8)&0xFF)

def setlength(bytes):
    length=len(bytes)
    #print("length is %d" % length)
    bytes[4]=length&0xFF
    bytes[5]=(length>>8)&0xFF
    bytes[6]=(length>>16)&0xFF
    bytes[7]=(length>>24)&0xFF

def putdword(bytes,n):
    bytes.append(n&0xFF)
    bytes.append((n>>8)&0xFF)
    bytes.append((n>>16)&0xFF)
    bytes.append((n>>24)&0xFF)	

def buildswf(data):
    bytes=[]
    # set magic numbers
    putbyte(bytes,ord('F'))
    putbyte(bytes,ord('W'))
    putbyte(bytes,ord('S'))
    putbyte(bytes,9)
    # length is bytes[4]
    putdword(bytes,0)
    # set size to 550x400
    putbyte(bytes,0x78)
    putbyte(bytes,0x00)
    putbyte(bytes,0x05)
    putbyte(bytes,0x5f)
    putbyte(bytes,0x00)
    putbyte(bytes,0x00)
    putbyte(bytes,0x0f)
    putbyte(bytes,0xa0)
    putbyte(bytes,0x00)
    putbyte(bytes,0x00)
    # frame rate = 12
    putbyte(bytes,12)
    # number of frames=1
    putword(bytes,1)
    # FileAttributes tag, 69 = AS3|usenetwork	
    putword(bytes,(69<<6)+4)
    putdword(bytes,0x00000008|0x00000001)
    # set ScriptLimits tag, MaxRecursionDepth and ScriptTimeoutSeconds
    putword(bytes,(65<<6)+4)
    putword(bytes,maxRecursionDepth)
    putword(bytes,scriptTimeoutSeconds)
    # doabc2 tag = 72
    putword(bytes,(72<<6)+0x3f)
    putdword(bytes,len(data))
    for i in range(len(data)):
       	putbyte(bytes,ord(data[i]))
    # showframe
    putword(bytes,1<<6)
    setlength(bytes)
    return bytes

def killbrowser(process):
    try:
        if ostype=="win":
    	    win32api.TerminateProcess(int(process._handle), -1)
        elif ostype=="lnx":
            if playertype=='ff' or playertype=='firefox':
                os.system("killall firefox-bin")
            else:
                os.system("killall flashplayer")
        elif ostype=="mac":
            if playertype=='safari':
                os.system("killall Safari")
            elif playertype=='ff':
                os.system("killall firefox-bin")
            else:
                os.system("killall \"Flash Player\"")
        else:
            print("ERROR: unsupported platform, cannot kill player")
    except:
        print "ERROR: cannot terminate player"
        time.sleep(1)

def buildhtmlshell(name):
    width="550"
    height="400"
    template=open('../template.html').read()
    outfile=re.sub('template',name,'./template.html')
    template=re.sub('\$template_name',name,template)
    template=re.sub('\$template_title',name,template)
    template=re.sub('\$template_swf',name,template)
    template=re.sub('\$template_width',width,template)
    template=re.sub('\$template_height',height,template)
    open(outfile,'w').write(template)

# main
if len(sys.argv)<2:
    print("ERROR: infile.abc")
    sys.exit(1)
infile=sys.argv[1]
p1=re.compile('\.[a-z]+')
p1a=re.compile('-')
basename=p1.sub("",infile)
basename=p1a.sub("",basename)
if (len(basename)>30):
    basename=basename[0:30]
swffile=basename+"swf.swf"
classname=basename+"gen"
outfile=classname+".as"
outswf=classname+".swf"
outhtml=classname+".html"

if os.path.exists(swffile)==False or os.path.getmtime(infile)>os.path.getmtime(swffile):
    # convert abc to a simple swf
    fd1=open(infile,'rb')
    abccode=fd1.read()
    fd1.close()
    swfcode=buildswf(abccode)
    #print("swfcode=%s"%swfcode)
    #print("len=%d" % len(swfcode))
    fd2=open(swffile,'wb')

    # read the simple swf into byte array
    data=""
    for num in range(len(swfcode)):
        data=struct.pack('B',swfcode[num])
        fd2.write(data)
    fd2.close()
    #print("wrote %s" % swffile)
    p2=re.compile('var bytes=\[\];//pointer')
    p3=re.compile('template')
    fd3=open("../template.as","r")
    template=fd3.read()
    if len(swfcode)<1000:
        out="var bytes=["
        for byte in swfcode:
            out+="%s," % byte
        if len(out)>0:
            out=out[0:len(out)-1]
        out+="];"
    else:
        total=0
        out="var bytes=[];\n"
        while total<len(swfcode):
            out+="bytes.push("
            for i in range(1000):
                if total+i==len(swfcode):
                    break
                out+="%s," % swfcode[total+i]
            if len(out)>0:
                out=out[0:len(out)-1]
            out+=");\n"
            total+=1000
    template=p2.sub(out,template)
    template=p3.sub(classname,template)
    fd4=open(outfile,'w')
    fd4.write(template)
    fd1.close()
    fd3.close()
    fd4.close()
    #print("generated %s" % outfile)

    #ascline="java -jar %s %s -swf %s,550,400 %s" % (environ['ASC'].strip(),environ['ASCARGS'].strip(),classname,outfile)
    ascline="java -jar %s -import %s -import %s -swf %s,550,400 %s" % (environ['ASC'].strip(),environ['GLOBALABC'].strip(),environ['PLAYERGLOBALABC'].strip(),classname,outfile)

    p=subprocess.Popen(ascline,stderr=subprocess.STDOUT,stdout=subprocess.PIPE,shell=True)
    p.communicate()
    buildhtmlshell(classname)
# end check timestamps

if buildshell:
    url="file://%s/%s" % (os.getcwd(),outhtml)
else:
    url="file://%s/%s" % (os.getcwd(),outswf)
if ostype=="mac":
    try:
        process = subprocess.Popen([ "open","-a",player,url])
    except:
        print("ERROR running: open -a %s %s" % (player,url))
else:
    try:
        process = subprocess.Popen([ player, url])
    except:
        print("ERROR running: %s %s" % (player,url))
serversocket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
serversocket.settimeout(socketTimeout)
serversocket.bind(("",1189))
serversocket.listen(5)
conn=0
try:
    (conn,addr)=serversocket.accept()
except socket.timeout:
    print("ERROR: socket timed out, no connection")
data=""
if conn:
    conn.settimeout(socketTimeout)
    while True:
        str=conn.recv(4096)
        if (len(str)==0):
            break
        data+=str
        data=data.replace(""+chr(13),""+chr(10))
print(data)
time.sleep(delay)
killbrowser(process)
exit(0)
