/*
TASK: fighter.c
LANG: C
COMPILER: WDC
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <stdio.h>
int main()
{
    int P;
    scanf("%d",&P);
    int num[2]={P,P},a=0,b=-1,x;
    for(int i=0; i<2*P; i++)
    {
        scanf("%d",&x);
        if(x%2!=b)
        {
            a=0;
            b=x%2;
        }
        if(a<2)
        {
            num[!b]--;
            a++;
        } else num[!b]-=3;
        if(num[!b]<=0)printf("%d\n%d",b,x);
    }
}