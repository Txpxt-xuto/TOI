#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y

int n,m,mnn=2e9,ch[15];
struct store
{
    int x,y,z;
    int mo,ke,ca;
}arr[15];

int dis(int i,int j)
{
    return (arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)+(arr[i].y-arr[j].y)*(arr[i].y-arr[j].y)+(arr[i].z-arr[j].z)*(arr[i].z-arr[j].z);
}

void play(int mocnt,int kecnt,int cacnt,int store,int cntall)
{
    mocnt += arr[store].mo;
    kecnt += arr[store].ke;
    cacnt += arr[store].ca;
    if(mocnt >= n && kecnt >= n && cacnt >= n)
    {
        if(cntall < mnn) mnn = cntall;
        return ;
    }
    int i;
    for(i=1;i<=m;i++)
    {
        if(ch[i] == 1) continue;
        ch[i] = 1;
        play(mocnt,kecnt,cacnt,i,cntall+dis(i,store));
        ch[i] = 0;
    }
}

int main()
{ 
    scanf("%d %d %d %d %d",&n,&arr[0].x,&arr[0].y,&arr[0].z,&m);
    int i;
    for(i=1;i<=m;i++) scanf("%d %d %d %d %d %d",&arr[i].x,&arr[i].y,&arr[i].z,&arr[i].mo,&arr[i].ke,&arr[i].ca);
    for(i=1;i<=m;i++)
    {
        ch[i] = 1;
        play(0,0,0,i,dis(i,0));
        ch[i] = 0;
    }
    printf("%d",mnn);
    return 0;
}