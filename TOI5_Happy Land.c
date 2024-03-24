/*
TASK: Land
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int M,N,i,j,k;
    scanf("%d %d",&M,&N);
    int x,y,test[M][N];
    float land[M][N],min=999999999,sum=0;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%f",&land[i][j]);
            test[i][j]=0;
        }
    }
    for(k=0;k<(M*N);k++)
    {
        min=999999999;
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                printf(" %d %d",i,j);
                if(min>land[i][j] && test[i][j]==0)
                {
                    min = land[i][j];
                    printf(" --> %.2f ",min);
                    x=i;
                    y=j;
                    
                }
            }
        }
        test[x][y]=1;
        sum+=land[x][y];

        printf("\n%.2f",min);
        printf(" %d %d %d\n",x,y,test[x][y]);

        land[x-1][y-1]+=land[x][y]*0.1;
        land[x-1][y]+=land[x][y]*0.1;
        land[x-1][y+1]+=land[x][y]*0.1;
        land[x][y-1]+=land[x][y]*0.1;
        land[x][y+1]+=land[x][y]*0.1;
        land[x+1][y-1]+=land[x][y]*0.1;
        land[x+1][y]+=land[x][y]*0.1;
        land[x+1][y+1]+=land[x][y]*0.1;
    }
    printf("--%.2f",sum);

}