/*
TASK: plantation.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,k,N,K,T,x,y,z=0;
    scanf("%d %d %d",&N,&K,&T);
    int L[N],P[N],q[N][100];
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&L[i],&P[i]);
        for(j=0;j<P[i];j++) scanf("%d",&q[i][j]);
    }
    for(i=0;i<N;i++)
    {
        if(L[i]==1&&P[i]==0)
        {
            z++;
            break;
        }
        else if(L[i]==1&&P[i]!=0) printf("-1");
    }
    if(z==1)
    {
        T=T-1;
        for(x=0;x<N;x++)
        {
            for(y=0;y<P[x];y++)
            {
                for(i=0;i<N;i++)
                {
                    for(j=0;j<P[i];j++)
                    {
                        if(T==0)
                        {
                            printf("%d",x);
                            x=N-1;
                            i=N-1;
                        }
                        else if(q[x][y]==q[i][j]) T+=-1;
                    }
                }
            }
        }
    }
}