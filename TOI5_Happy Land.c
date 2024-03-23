/*
TASK: Land
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int M,N,i,j,x,y;
    scanf("%d %d",&M,&N);
    double land[M][N],min=9999999999999;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%f",&land[i][j]);
        }
    }
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(min<land[i][j])
            {
                min = land[i][j];
                x=i;
                y=j;
            }
        }
    }
}