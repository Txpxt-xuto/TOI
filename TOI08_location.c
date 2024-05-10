/*
TASK: location.c
LANG: C
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <stdio.h>
int main()
{
    int M,N,K,i,j;
    scanf("%d %d",&M,&N);
    scanf("%d",&K);
    int arr[M][N],sum[K][K];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++) 
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<M-K+1;i++)
    {
        for(j=0;j<N-K+1;j++) 
        {
            int max=0;
            for(int x=i;x<i+K;x++)
            {
                for(int y=j;y<j+K;y++) 
                {
                    max+=sum[x][y];
                }
            }
            printf("%d\n",max);
        }
    }
}