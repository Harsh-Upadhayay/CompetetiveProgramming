import os
import shutil
from Problem import Problem
from LinkInfo import Link 

prblm = Problem(Link().link)
fileName = prblm.name
folderName = prblm.contest

try :
    os.mkdir("../" + folderName)
except : 
    pass

shutil.copyfile("../code.cpp", "../" + folderName + "/" + fileName + ".cpp")
