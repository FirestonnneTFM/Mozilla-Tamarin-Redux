import os
import sys
import time
import shutil
from optparse import OptionParser

@staticmethod
def _onerror(func, path, exc_info): 

     import stat
     if not os.access(path, os.W_OK):
        try:
            os.chmod(path, stat.S_IWUSR)
            func(path)
        except Exception,e:
            print e
            pass

def main():
    usage = "usage: %prog [options] arg"
    parser = OptionParser(usage)
    parser.add_option("-p", "--path", type="string", dest="directory",
                      help="path to tree to delete")
    parser.add_option("-i", "--interval", type="int", dest="interval",
                      help="number of days to preserve folders")
    
    (options, args) = parser.parse_args()
    if not options.directory or not options.interval:
        parser.error("-p <path> and -i <interval> arguments required")
    
    path = options.directory        
    numdays = options.interval * 86400 # 86400 = number of seconds in a day
    now = time.time()
    
    for r,d,f in os.walk(path):
        for dir in d:
             timestamp = os.path.getmtime(os.path.join(r,dir))
             if now-timestamp > numdays:
                 try:
                      print "removing ",os.path.join(r,dir)
                      shutil.rmtree(os.path.join(r,dir), onerror=_onerror)  # comment to test
                 except Exception,e:
                      print e
                      pass
                      
if __name__ == "__main__":
    main()
