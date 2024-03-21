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
    int N,K,i,j;
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<N;i++)
    {
        printf("%d ",x[i]);
    }
}