"""
TASK: sport.c
LANG: C
COMPILER: WCB
AUTHOR: YourName YourLastName
CENTER: 
"""
def sport(n,w,l,str):
    if(w==n or l==n): 
        for i in str : print(i,end=" ")
        print("",end="\n")
        return
    sport(n,w+1,l,str+'W')
    sport(n,w,l+1,str+'L')

k=int(input())
a=int(input())
b=int(input())
sport(k,a,b,"")