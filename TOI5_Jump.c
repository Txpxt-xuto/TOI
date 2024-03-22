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
    int N,K,i,j,sum,start,Max=0;
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<N;i++)
    {
        sum = 0;
        for(j=i+1;j<N;j++)
        {
            if(x[j]-x[i] <= K)
            {
                sum++;
            }
        }
        if(Max<sum)
        {
            Max=sum;
        }
    }
    printf("%d",Max);
}