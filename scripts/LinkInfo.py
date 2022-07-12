import LOCAL_VARS

class Link :

    def __init__(self, file=LOCAL_VARS.SOURCE_CODE_PATH):    
        f = open(file, "r")
        self.link = f.readline()[2 : -3]
