/*
TASK: Land
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int M,N,i,j,k,x,y;
    double land[5][5],min,sum=0;
    scanf("%d %d",&M,&N);
    for(i=1;i<=M;i++) for(j=1;j<=N;j++) scanf("%lf",&land[i][j]);
    for(k=0;k<(M*N);k++)
    {
        min=999999999;
        for(i=1;i<=M;i++)
        {  
            for(j=1;j<=N;j++)
            {
                if(min>land[i][j] && land[i][j]>=1)
                {
                    min = land[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        sum+=land[x][y];
        land[x+1][y]+=land[x][y]/10;
        land[x-1][y]+=land[x][y]/10;
        land[x][y+1]+=land[x][y]/10;
        land[x][y-1]+=land[x][y]/10;
        land[x+1][y-1]+=land[x][y]/10;
        land[x+1][y+1]+=land[x][y]/10;
        land[x-1][y-1]+=land[x][y]/10;
        land[x-1][y+1]+=land[x][y]/10;
        land[x][y]=-999999999;     
    }
    printf("%.2lf",sum);
}