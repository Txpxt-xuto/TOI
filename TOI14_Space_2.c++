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
    pll par_r[n + 5][m + 5], par_g[n + 5][m + 5];
    for(i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for(j=0;j<m;j++)
        {
            arr[i][j] = s[j];
            ll path1 = (i == 0 ? 0 : dp_r[i - 1][j]) + (s[j] == 'R');
            ll path2 = (j == 0 ? 0 : dp_r[i][j - 1]) + (s[j] == 'R');
            dp_r[i][j] = max(path1, path2);
            if(i && dp_r[i][j] == path1) par_r[i][j] = make_pair(i - 1, j);
            if(j && dp_r[i][j] == path2) par_r[i][j] = make_pair(i, j - 1);
        }
    }
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
    ll most = -1;
    ll best_x = -1, best_y = -1, best_x2 = -1, best_y2 = -1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            ll most_r = dp_r[i][j] + (n - i - 1) + (m - j - 1) - (i == n - 1 ? inf : dp_g[i + 1][j]);
            ll most_g = (i == n - 1 ? inf : dp_g[i + 1][j]) + i + j + 1 - dp_r[i][j];
            ll val = min(most_r, most_g);
            ll most_r2 = dp_r[i][j] + (n - i - 1) + (m - j - 1) - (j == m - 1 ? inf : dp_g[i][j + 1]);
            ll most_g2 = (j == m - 1 ? inf : dp_g[i][j + 1]) + i + j + 1 - dp_r[i][j];
            ll val2 = min(most_r2, most_g2);
            most = max(most, max(val, val2));
        }
    }
    cout << 2 * most << "\n";
    nowx = best_x2, nowy = best_y2;
    while(nowx != n - 1 || nowy != m - 1)
    {
        dq.emplace_back(nowx, nowy);
        ll tmp = nowx;
    }
}