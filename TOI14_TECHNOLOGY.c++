/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXX = 505, MAXY = 505;

ll N, X, Y;

ll dp[MAXX][MAXX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> X >> Y;
    for (ll i = 0; i <= X; i++) for (ll j = 0; j <= Y; j++) dp[i][j] = 1e18;
    dp[0][0] = 0;
    while (N--)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        for (ll i = X; i >= 0; i--)
        {}
        for (ll j = Y; j >= 0; j--)
        {
            dp[min(X, i+x)][min(Y, j+y)] = min(dp[min(X, i+x)][min(Y, j+y)], dp[i][j]+c);
        }
    }
    cout << (dp[X][Y] >= 1e18 ? -1 : dp[X][Y]);
    return 0;
}