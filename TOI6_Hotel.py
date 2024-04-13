"""
TASK: hotel
LANG: Python
AUTHOR: Tapat Toungsakul
CENTER: Home
"""
n=int(input())
sum=0
while n>0 :
    if n>=9 :
        n-=15
        sum=sum+3000
    elif n>=4 :
        n-=5
        sum=sum+1500
    elif n>=2 :
        n-=2
        sum=sum+800
    elif n==1 :
        n-=1
        sum=sum+500
print(sum)