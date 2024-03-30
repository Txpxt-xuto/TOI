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
    int P,i,j,k;
    scanf("%d",&P);
    int a,pointodd=P,pointeven=P;
    for(i=0;i<2*P;++i)
    {
        scanf("%d",&a);
        if(a%2==0)
        { 
            j=0;
            k++;
            if(k>2) pointeven-=3;
            if(pointeven<=0) 
            {
                printf("0\n%d",a);
                break;
            }
            else pointeven-=1;
        }
        else
        {
            j++;
            k=0;
            if(j>2) pointodd-=3;
            if(pointodd<=0)
            {
                printf("1\n%d",a);
                break;
            } 
            else pointodd-=1;
        }
    }
}