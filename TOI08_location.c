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
    int M,N,K,i,j,k,max=0;
    scanf("%d %d",&M,&N);
    scanf("%d",&K);
    int arr[M][N],sum[K][K];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++) scanf("%d",&arr[i][j]);
    }
    for(i=0;i<M-K+1;i++)
    {
        for(j=0;j<N-K+1;j++) 
        {
            for(int x=0;x<K;x++)
            {
                for(int y=0;y<K;y++) 
                {
                    sum[x][yj]
                }
            }
        }
    }
}