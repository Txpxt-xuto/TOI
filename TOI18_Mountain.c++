/*
TASK: mountain.cpp
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Data 
{
    ll c, u, d;
    bool operator<(const Data &other) const 
    {
        if (c == other.c) return d > other.d;
        return c > other.c;
    }
};

const int N = 501, M = 200001;
ll n, m, x[N], y[N], s[M];

ll distance(int i, int j) 
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

Data dijkstra(ll dis)
{
    vector<ll> d(n + 1, 1e18);
    d[1] = 0;
    priority_queue<Data> pq;
    pq.push({0, 1, 0});
    while (!pq.empty()) 
    {
        ll cc = pq.top().c;
        ll cu = pq.top().u;
        ll cd = pq.top().d;
        pq.pop();
        if (cu == n) return {cc, cu, cd};
        if (d[cu] != cc) continue;
        for (int nu = 1; nu <= n; nu++) 
        {
            ll nw = distance(cu, nu);
            if (d[nu] > d[cu] + 1 && nw <= dis) 
            {
                d[nu] = d[cu] + 1;
                pq.push({d[nu], nu, max(nw, cd)});
            }
        }
    }
    return {-1, -1, -1};
}

int main() {
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%lld", &s[i]);
    }

    sort(s + 1, s + m + 1, greater<ll>());
    
    Data data = dijkstra(s[1]);
    ll dist = data.d;
    ll ans = data.c;
    ll total = 0;

    for (int i = 1; i <= m;) {
        if (dist <= s[i]) {
            total += ans;
            i++;
        }
        else {
            data = dijkstra(s[i]);
            dist = data.d;
            ans = data.c;
        }
    }

    printf("%lld", total);
}