/*
TASK: Land
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int M,N,i,j,k,x,y,check[10];
double land[3][3],min=999999999,sum=0,l;
void place(int k,double x){
    if(k==M*N)
    {
        if(min>x) min = x;
        return;
    }
    for(int i=0;i<M*N;i++)
    {
        if(check[i]==1) continue;
        i=(i/N)+1,j=(i%N)+1;
        l=land[i][j]/10;
        check[i]=1;
        land[i+1][j]+=l;
        land[i-1][j]+=l;
        land[i][j+1]+=l;
        land[i][j-1]+=l;
        land[i+1][j-1]+=l;
        land[i+1][j+1]+=l;
        land[i-1][j-1]+=l;
        land[i-1][j+1]+=l;
        place(k+1,x+land[i][j]);
        check[i]=0;
        land[i+1][j]-=l;
        land[i-1][j]-=l;
        land[i][j+1]-=l;
        land[i][j-1]-=l;
        land[i+1][j-1]-=l;
        land[i+1][j+1]-=l;
        land[i-1][j-1]-=l;
        land[i-1][j+1]-=l;
    }
}
int main()
{
    scanf("%d %d",&M,&N);
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%lf",&land[i][j]);
        }
    }
    place(0,0);
    printf("sum = %.2lf",sum);
    printf("sum = %.2lf",min);
}