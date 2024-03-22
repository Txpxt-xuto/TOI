/*
TASK: Jump
LANG: C
AUTHOR: YourName YourLastName 
CENTER: YourCenter
*/
#include <stdio.h>
unsigned int x[30005];
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
        for(j=i;j<N-1;j++)
        {
            if(x[j+1]-x[i] <= K) sum=j-i+1;
            else break;
        }
        if(Max<sum) Max=sum;
    }
    printf("%d",Max);
}