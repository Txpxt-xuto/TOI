/*
TASK: raider.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef int ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plpll;
const ll maxn = 120;
const ll inf = 1e9;
ll arr[maxn][maxn], memo[maxn][maxn];
ll di[6] = {-1, -1, 0, 1, 1, 0};
ll dj[2][6] = {{0, 1, 1, 1, 0, -1}, {0, -1, -1, -1, 0, 1}};
int main() {
    ll n, m;
    scanf("%d %d",&n, &m);
    for (int i = 0; i < n; i++) 
    {
        for(j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }

    ll mid = n / 2;
    queue<plpll> que;
    que.emplace(0, make_pair(mid, -1));
    while (!que.empty()) {
        ll nowstep = que.front().F;
        ll nowi = que.front().S.F;
        ll nowj = que.front().S.S;
        que.pop();
        if (nowi == mid && nowj == m - 1) {
            printf("%d", nowstep);
            exit(0);
        }
        ++nowstep;
        for (int i = 0; i < 6; i++) {
            ll toi = nowi + di[i];
            ll toj = nowj + dj[nowi%2][i];
            if (toi >= 0 && toi < n && toj >= 0 && toj < m && arr[toi][toj] != 0 && memo[toi][toj] != nowstep && nowstep % arr[toi][toj] == 0) {
                que.emplace(nowstep, make_pair(toi, toj));
                memo[toi][toj] = nowstep;
            }
        }
    }
	return 0;
}