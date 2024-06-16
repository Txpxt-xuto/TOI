/*
TASK: spaceship.cpp
LANG: C++
COMPILER: WCB
AUTHOR: YourFirstName YourLastName
ID: YourCenterID
*/
#include <bits/stdc++.h>
using namespace std;
int i,n,m;
int ans = 1e9;
int use[15];
int x[15],y[15],z[15],M[15],K[15],C[15];
void solve(int now,int Mleft,int Kleft,int Cleft,int total)
{
    if(ans < total)return;
    if(Mleft <= 0 && Kleft <= 0 && Cleft <= 0)
    {
        ans = total;
        return;
    }

    for(i=1;i<=m;i++)
    {
        if(use[i] == 1) continue;
        use[i] = 1;
        int cost = (x[i]-x[now])*(x[i]-x[now]) + (y[i]-y[now])*(y[i]-y[now]) + (z[i]-z[now])*(z[i]-z[now]);
        solve(i,Mleft-M[i],Kleft-K[i],Cleft-C[i],total+cost);
        use[i] = 0;
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%d %d %d",&x[0],&y[0],&z[0]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
        scanf("%d %d %d",&M[i],&K[i],&C[i]);/*
TASK: spaceship.cpp
LANG: C++
COMPILER: WCB
AUTHOR: YourFirstName YourLastName
ID: YourCenterID
*/
        use[i] = 0;
    }
    solve(0,n,n,n,0);
    printf("%d",ans);
}