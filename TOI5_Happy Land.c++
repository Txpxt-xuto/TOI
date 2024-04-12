/*
TASK: Land
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int i,j,m,n;
double a[5][5]={},mini=INT_MAX;
bool vis[10]={};
void land(int deep,double cur)
{
    if(deep==m*n)
    {
        mini=min(cur,mini);
        return;
    }
    for(int i=0;i<m*n;i++)
    {
        if(vis[i]) continue;
        int r = (i/n)+1,c = (i%n)+1;
        double add = a[r][c]*0.1;
        vis[i]=1;
        a[r+1][c]+=add;
        a[r-1][c]+=add;
        a[r][c+1]+=add;
        a[r][c-1]+=add;
        a[r+1][c-1]+=add;
        a[r+1][c+1]+=add;
        a[r-1][c-1]+=add;
        a[r-1][c+1]+=add;
        land(deep+1,cur+a[r][c]);
        vis[i]=0;
        a[r+1][c]-=add;
        a[r-1][c]-=add;
        a[r][c+1]-=add;
        a[r][c-1]-=add;
        a[r+1][c-1]-=add;
        a[r+1][c+1]-=add;
        a[r-1][c-1]-=add;
        a[r-1][c+1]-=add;
    }
}
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++)for(j=1;j<=n;j++) cin>>a[i][j];
    land(0,0);
    cout << fixed<<setprecision(2) << mini;
}