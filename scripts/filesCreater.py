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
    
p1 = Problem("https://codeforces.com/problemset/problem/71/A")

print(p1.name, p1.contest)



