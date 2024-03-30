/*
TASK: SCHOOL
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int P,i,j,k;
    scanf("%d",&P);
    int num[P*2],pointodd=P,pointeven=P;
    for(i=0;i<2*P;i++) scanf("%d",&num[i]);
    for(i=0;i<2*P;i++)
    {
        if(num[i]%2==0)
        { 
            j=0;
            k++;
            if(pointodd<=0) printf("0\n%d",num[i-1]);
            else if(k>=2) pointodd-=3;
            else pointodd-=1;
        }
        else
        {
            j++;
            k=0;
            if(pointeven<=0) printf("1\n%d",num[i-1]);
            else if(j>=2) pointeven-=3;
            else pointeven-=1;
        }
    }
}
