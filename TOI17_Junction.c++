/*
TASK: Junction
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
int n;
int dp[80010];
vector<pair<int,int>> ad[80010];
bool vis[80010];
int id=1;
void dfs(int i)
{
    vis[i]=1;
    for(auto x:ad[i])
    {
        if(vis[x.f])
        continue;
        dfs(x.f);
        dp[id]=dp[id-1]+x.s;
        id++;
    }
}
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ad[u].push_back({v,w});
        ad[v].push_back({u,w});
    }
    for(int i=0;i<=n;i++)
    {
        if(ad[i].size()==1)
        {
            dfs(i);
            break;
        }
    }
    int l=0,r=dp[n];
    while(l<r)
    {
        int mid=(l+r+1)/2;
        int cnt=0;
        int sum=0;
        while(cnt<3)
        {
            int i=lower_bound(dp,dp+n+1,sum+mid)-dp;
            if(i==n+1)
            break;
            sum=dp[i];
            cnt++;
        }
        if(cnt>=3) l=mid;
        
        else r=mid-1;
        
    }
    cout<<l;
}