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
typedef vector<pld> vpld;
typedef vector<vi> vvi;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define rep0(a) for (int i = 0; i < a; ++i)
#define rep1(i, a) for (int i = 0; i < a; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (int i = a; i <= b; i+=c) 
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (int i = a; i >= 1; --i)
#define repd1(i, a) for (int i = a; i >= 1; --i)
#define repd2(i, a, b) for (int i = b; i >= a; --i)
#define repd3(i, a, b, c) for (int i = b; i >= a; i-=c)
#define repd(...) overload4(__VA_ARGS__, repd3, repd2, repd1, repd0)(__VA_ARGS__)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define ins insert
template<typename T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;
int val[MX];
bool reach[MX];
void solve() 
{
    int m, n, k; 
    cin >> m >> n >> k;
    rep(i, 1, n) cin >> val[i];
    vector<tuple<int, int, int>> stick;
    rep(i, 1, k) 
    {
        int u, h; 
        cin >> u >> h;
        stick.pb({h, u, u+1});
    }
    sort(all(stick));
    int s; cin >> s;
    reach[s] = 1;
    reach[s+1] = reach[s-1] = 1;
    for (auto [h, u, v] : stick) 
    {
        swap(reach[u], reach[v]);
        if (u == s) s++;
        else if (v == s) s--;
        reach[s+1] = reach[s-1] = 1;
    }
    int mx = 0;
    rep(i, 1, n) 
    {
        if (!reach[i]) continue;
        ckmax(mx, val[i]);
    }
    cout << mx << nl << (val[s] == mx ? "NO" : "USE") << nl;
}

int main(int argc, char* argv[]) 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL);
    int t = 1;
    while (t--) { solve(); }
    return 0;
}