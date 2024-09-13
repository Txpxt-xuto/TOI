/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int dp[100100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll int chap,q;
    ll int cost;
    cin >> chap >> q;
    for(int i=1;i<=chap;i++)
    {
        cin >> cost;
        dp[i] = dp[i-1] + cost;
    }
    for(int i=chap;i>=1;i--) if(dp[i] < dp[i-1]) dp[i-1] = dp[i];

    while(q--)
    {
        ll price;
        cin >> price;
        ll ans = upper_bound(dp+1,dp+chap+1,price) - dp - 1;
        cout << ans << endl;
    }
    return 0;
}