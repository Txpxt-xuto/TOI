/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> point[1007];
ll cost[1007];
ll dp[507][507];

int main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int n,X,Y;
    cin>>n>>X>>Y;
    for(int i=0;i<=500;i++)for(int j=0;j<=500;j++)dp[i][j]=1e18+7;
    for(int i=1;i<=n;i++)cin>>point[i].first>>point[i].second>>cost[i];
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int x=X;x>=0;x--)
        {
            for(int y=Y;y>=0;y--)
            {
                dp[x][y]=min(dp[x][y],dp[max(0,x-point[i].first)][max(0,y-point[i].second)]+cost[i]);
            }
        }
    }
    if(dp[X][Y]==1e18+7) cout<<"-1";
    else cout<<dp[X][Y];
    return 0;
}