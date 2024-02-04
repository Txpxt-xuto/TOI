/*
TASK: ROMAN
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int d,i=0,v=0,x=0,l=0,c=0;
    scanf("%d",&d);
    while (d>=1)
    {
        if(d/100>=1)
        {
            c+=d/100;
        }
        else if(d%10==9)
        {
            i+=1;
            x+=1;
        }
        d-=1;
    }
    printf("%d %d %d %d %d",i,v,x,l,c);
}