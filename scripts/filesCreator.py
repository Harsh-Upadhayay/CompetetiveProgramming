import os
import shutil
from Problem import Problem
from LinkInfo import Link 
from subprocess import run
import LOCAL_VARS

prblm = Problem(Link().link)
folderPath = os.path.join(LOCAL_VARS.SOURCE_DIRECTORY_PATH, prblm.contest)
filePath = os.path.join(folderPath, prblm.name + '.cpp')
tags = ','.join(prblm.tags)

try :
    os.mkdir(folderPath)
except : 
    pass

shutil.copyfile(LOCAL_VARS.SOURCE_CODE_PATH, filePath)

run(['git', 'add', filePath])
run(['git', 'commit', '-m', tags ])