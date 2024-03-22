/*
TASK: Jump
LANG: C
AUTHOR: YourName YourLastName 
CENTER: YourCenter
*/
#include <stdio.h>
unsigned int x[30000];
int main()
{
    int N,K,i,j,sum,max=0;
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(x[i]+K > x[j])
            {
                sum=j-i;
            }
        }
        if(sum > max)
        {
            max=sum;
            sum=0;
        }
    }
    printf("%d",max);
}