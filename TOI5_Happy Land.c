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
    scanf("%d %d",&M,&N);
    double land[M][N],min=9999999999999,sum,test[M][N];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%f",&land[i][j]);
        }
    }
    for(k=0;k<M*N;k++)
    {
        min=9999999999999;
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                if(min<land[i][j] && test[i][j]==0)
                {
                    min = land[i][j];
                    printf("%.2f",min);
                    x=i;
                    y=j;
                }
            }
        }
        test[x][y]=1;
        sum+=land[x][y];
        land[i-1][j-1]+=land[x][y]/10;
        land[i-1][j]+=land[x][y]/10;
        land[i-1][j+1]+=land[x][y]/10;
        land[i][j-1]+=land[x][y]/10;
        land[i][j+1]+=land[x][y]/10;
        land[i+1][j-1]+=land[x][y]/10;
        land[i+1][j]+=land[x][y]/10;
        land[i+1][j+1]+=land[x][y]/10;
    }
    printf("%.2f",sum);

}