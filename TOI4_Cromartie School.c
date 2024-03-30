/*
TASK: SCHOOL
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>

int main()
{
    int P,i,j,k=1;
    scanf("%d",&P);
    int num[P*2],pointodd=P,pointeven=P;
    for(i=0;i<2*P;i++) scanf("%d",&num[i]);
    i=0;
    for(i=0;i<2*P;i++)
    {
        j=0;
        if(num[i]%2==0)
        {
            if(pointodd<=0)
            {
                printf("0\n%d",num[i-1]);
                break;
                break;
                i=2*P;
            }
            else if(j>=2)
            {
                pointodd-=3;
            }
            else
            {
                pointodd-=1;
            }
            j++;
            i++;
        }
        j=0;
        else if(num[i]%2==1)
        {
            if(pointeven<=0)
            {
                printf("1\n%d",num[i-1]);
                break;
                break;
                i=2*P;
            }
            else if(j>=2)
            {
                pointeven-=3;
            }
            else
            {
                pointeven-=1;
            }
            j++;
            i++;
        }
    }
}
