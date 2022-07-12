import LOCAL_VARS
import sys

class Link :

    def __init__(self, file=LOCAL_VARS.SOURCE_CODE_PATH):    
        
        try : 
            f = open(file, "r")
        except Exception as e :
            sys.exit("\t\t!! Source File not found, check path in LOCAL_VARS !!\n", e)
        
        self.link = f.readline()[2 : -3]

        if self.link.count("codeforces.com") != 1 :
            sys.exit("\t\t !! Problem link not added, add the link in the first line of the source code !!\n") 

l = Link()