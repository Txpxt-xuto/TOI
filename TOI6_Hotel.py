"""
TASK: hotel
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
"""
n=int(input())
while n>0 :
    if n>=9 :
        n-=15
        sum=sum+3000
    elif n>=4 :
        n-=5
        sum+=1500
    elif n>=2 :
        n-=2
        sum+=800
    elif n==1 :
        n-=1
        sum+=500
print(sum)