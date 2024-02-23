/*
TASK: BRICK
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int N,M,i,j;
    scanf("%d %d",&N,&M);
    char Brick[N][M];
    int a[M];
    for(i=0;i<N;i++)
    {
        scanf("%s",&Brick[i]);
    }
    for(i=0;i<M;i++)
    {
        scanf("%s",&a[i]);
    }
}