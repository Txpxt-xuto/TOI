/*
TASK: electricity.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define name "activated by thisisnithit"
//toi8_electricity
ll n,m,ans=INT_MAX;
vector<ll> v;
vector<ll> dp;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    dp.assign(n+9,INT_MAX);
    dp[0]=v[0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++) if(i-j>=0) dp[i]=min(dp[i],v[i]+dp[i-j]);
    }
    cout << dp[n-1];
    return 0;
}
