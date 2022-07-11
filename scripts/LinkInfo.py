
class Link :

    def __init__(self, file="../code.cpp"):    
        f = open(file, "r")
        self.link = f.readline()[2 : -3]
