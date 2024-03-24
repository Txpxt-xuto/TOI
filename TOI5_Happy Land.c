/*
TASK: Land
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home

#include <stdio.h>
int main()
{
    int M,N,i,j,k,x,y;
    scanf("%d %d",&M,&N);
    float land[M][N],min=999999999,sum=0,l;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%f",&land[i][j]);
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
                if(min>land[i][j] && land[i][j]>0)
                {
                    min = land[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        sum+=land[x][y];
        l = land[x][y]/10;
        land[x][y]=-1000000000;
        
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
*/
#include <stdio.h>

int main()
{
    int i,j,m,n;
    scanf("%d %d",&m,&n);
    float sum=0,land[m*n],k,q;
    for(i=0;i<m*n;i++)
    {
        scanf("%f",&land[i]);
    }
    for(j=0;j<m*n;j++)
    {
        for(i=0;i<(m*n)-1;i++)
        {
            if(land[i]>land[i+1])
            {
                k=land[i];
                land[i]=land[i+1];
                land[i+1]=k;
            }
        }
    }
    for(i=0;i<m*n;i++)
    {
        sum+=land[i];
        printf("%f ",land[i]);
        q=land[i]/10;
        for(j=i+1;j<m*n;j++)
        {
            land[j]+=q;
        }
    }
    printf("\n%f",sum);
}