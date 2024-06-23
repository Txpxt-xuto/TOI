#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MD = 1e9 + 7;
ll arr[301];
ll qs[301];
ll dp[10][301][301];
bool vis[10][301][301];
ll n , k , d;
ll dfs(ll l,ll r,ll state)
{
    if(vis[state][l][r]) return dp[state][l][r];    
    vis[state][l][r] = 1;
    if(state == k) return dp[state][l][r] = 1;
    ll sum = 0;
    for(i=l;i<r;i++)
    {
        if(abs( (qs[i] - qs[l-1]) - (qs[r] - qs[i]) ) <= d)
        {
            sum = (sum + (dfs(l,i,state+1) * dfs(i+1,r,state+1))%MD)%MD;
        }
    }
    return dp[state][l][r] = sum;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> d;
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
        qs[i] = qs[i-1] + arr[i]; 
    }
    cout << dfs(1,n,1);
    return 0;
}