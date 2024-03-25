/*
TASK: hotel
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    while(n>0)
    {
        if(n>=9)
        {
            n-=15;
            sum+=3000;
        }
        else if(n>=4)
        {
            n-=5;
            sum+=1500;
        }
        else if(n>=2)
        {
            n-=2;
            sum+=800;
            
        }
        else if(n==1)
        {
            n-=1;
            sum+=500;
        }
    }
    printf("%d",sum);
}