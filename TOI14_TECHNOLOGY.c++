/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<vi> vvi;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef t
#define ins insert

template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 10;
vi before[MX], lvl[MX];
int mark[MX];
void solve()
{
    int n, k, t;
    cin >> n >> k >> t;
    rep(i, 1, n)
    {
        int l, m; cin >> l >> m;
        lvl[l].pb(i);
        rep(j, 1, m){ int x; cin >> x; before[i].pb(x); }
    }
    int mx = 0;
    function<bool(int)> upgrade = [&](int i)
    {
        if(mark[i]==2) return 1;
        if(mark[i]==1) return 0;
        if(t==0) return 0;
        mark[i] = 1; t--;
        trav(x, before[i]) if(!upgrade(x)) return 0;
        mark[i] = 2;
        return 1;
    };
    rep(i, 1, k)
    {
        trav(x, lvl[i]) if(!upgrade(x)) return void(cout << (i==1?-1:i-1) << nl);
    }  
    cout << k << nl;
}
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 1;
    while (t--) { solve(); }
    return 0;
}