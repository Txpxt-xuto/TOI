/*
TASK: metaverse2
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll inf = 1e18;

const int K = 20001, P = 20;
ll n, m, k, p, ans, tic, wrow[K], wcol[K], orow[K], ocol[K], dp[P][K];

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &k, &p);

    for (int i = 1; i <= k; i++) 
    {
        scanf("%lld %lld %lld %lld", &wrow[i], &wcol[i], &orow[i], &ocol[i]);
    }
    for (int l = 1; l <= p; l++) 
    {
        for (int i = 1; i <= k; i++) 
        {
            dp[l][i] = inf;
        }
    }
    for (int i = 1; i <= k; i++) 
    {
        dp[1][i] = abs(wrow[i] - 1) + abs(wcol[i] - 1);
    }
    for (int l = 2; l <= p; l++) 
    {
        for (int i = 1; i <= k; i++) 
        {
            for (int j = 1; j <= k; j++) 
            {
                dp[l][i] = min(dp[l][i], dp[l-1][j] + abs(orow[j] - wrow[i]) + abs(ocol[j] - wcol[i]));
            }
        }
    }
    ans = n + m - 2;
    for (int l = 1; l <= p; l++) 
    {
        for (int i = 1; i <= k; i++) 
        {
            ll dist = dp[l][i] + abs(orow[i] - n) + abs(ocol[i] - m);
            if (ans > dist) 
            {
                ans = dist;
                tic = l;
            }
        }
    }
    printf("%lld %lld", ans, tic);
}
