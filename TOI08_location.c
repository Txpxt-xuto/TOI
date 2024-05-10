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
    int M,N,K,i,j,k;
    scanf("%d %d",&M,&N);
    scanf("%d",&K);
    int arr[M][N];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++) scanf("%d",&arr[i][j]);
    }
}