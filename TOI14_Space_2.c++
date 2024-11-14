/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plpll;
typedef pair<ll, plpll> plplpll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 5e5 + 5;
void mains()
{
    ll n, m;
    cin >> n >> m;
    char arr[n + 5][m + 5];
    ll dp_r[n + 5][m + 5], dp_g[n + 5][m + 5];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            ll path1 = (i == n - 1 ? 0 : dp_g[i + 1][j]) + (arr[i][j] == 'G');
            ll path2 = (j == m - 1 ? 0 : dp_g[i][j + 1]) + (arr[i][j] == 'G');
            dp_g[i][j] = max(path1, path2);
            if(i != n - 1 && dp_g[i][j] == path1) par_g[i][j] = make_pair(i + 1, j);
            if(j != m - 1 && dp_g[i][j] == path2) par_g[i][j] = make_pair(i, j + 1);
        }
    }
}