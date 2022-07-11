from time import sleep
import requests
from bs4 import BeautifulSoup
import datetime

class Problem:
    


  def __init__(self, URL):
    
    URL = URL
    r = requests.get(URL)
    soup = BeautifulSoup(r.content, 'html5lib') 
    
    x =  soup.find('div', attrs = {'class':'title'}) 
    self.name = x.text;    
    
    x =  soup.find('th', attrs = {'class':"left", 'style':"width:100%;"})
    self.contest = x.text

    x =  soup.findAll('span', attrs = {'class':"tag-box"})
    self.tags = []
    for z in x: 
        self.tags.append(z.text.strip())
    print(self.tags)
    
p1 = Problem("https://codeforces.com/problemset/problem/266/B")

print(p1.name, p1.contest)



