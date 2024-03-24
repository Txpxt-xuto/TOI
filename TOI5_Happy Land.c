/*
TASK: Land
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int M,N,i,j,k,l;
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
                printf("%f ",land[i][j]);
                if(min>land[i][j] && test[i][j]==0)
                {
                    min = land[i][j];
                    x=i;
                    y=j;
                    
                }
            }
        }
        test[x][y]=1;
        sum+=land[x][y];
        l = land[x][y]/10;
        printf("-- %.2f %.2f\n",min,l);
        land[x-1][y-1]+=l;
        land[x-1][y]+=l;
        land[x-1][y+1]+=l;
        land[x][y-1]+=l;
        land[x][y+1]+=l;
        land[x+1][y-1]+=l;
        land[x+1][y]+=l;
        land[x+1][y+1]+=l;
        for(i=0;i<M;i++)
        printf("\n");
        {
            for(j=0;j<N;j++)
            {
                printf("%f ",land[i][j]);
            }
            
        }
        printf("\n");
    }
    printf("sum = %.2f",sum);

}