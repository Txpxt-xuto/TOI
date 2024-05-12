"""
TASK: sport.py
LANG: Python
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
"""
def sport(n,w,l,str):
    if(w==n or l==n): 
        for i in str : print(i,end=" ")
        print("",end="\n")
        return
    sport(n,w+1,l,str+'W')
    sport(n,w,l+1,str+'L')

k=int(input())
teama=int(input())
teamb=int(input())
sport(k,teama,teamb,"")