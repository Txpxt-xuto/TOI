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
    i=0;
    k=1;
    for(i=0;i<2*P;i)
    {
        j=0;
        while(num[i]%2==0)
        {
            if(pointodd<=0)
            {
                printf("0\n%d %d",num[i-1],i);
                break;
            }
            else if(j>=2)
            {
                pointodd-=3;
                printf("pointodd %d %d\n",pointodd,i);
            }
            else
            {
                pointodd-=1;
                printf("pointodd %d %d \n",pointodd,i);
            }
            j++;
            i++;
        }
        j=0;
        while(num[i]%2==1)
        {
            if(pointeven<=0)
            {
                printf("1\n%d",num[i-1]);
                break;
            }
            else if(j>=2)
            {
                pointeven-=3;
                printf("pointeven %d \n",pointeven);
            }
            else
            {
                pointeven-=1;
                printf("pointeven %d \n",pointeven);
            }
            j++;
            i++;
        }
    }
}
