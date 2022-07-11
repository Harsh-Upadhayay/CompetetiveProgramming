import os
import shutil
from Problem import Problem
from LinkInfo import Link 
from subprocess import run

prblm = Problem(Link().link)
fileName = prblm.name
folderName = prblm.contest
tags = ','.join(prblm.tags)

try :
    os.mkdir("../" + folderName)
except : 
    pass

shutil.copyfile("../code.cpp", "../" + folderName + "/" + fileName + ".cpp")

run(['git', 'add', '../' + folderName + '/' + fileName + '.cpp'])
run(['git', 'commit', '-m', tags ])