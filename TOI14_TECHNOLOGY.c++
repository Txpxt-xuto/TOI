/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
using pii = pair<int,int>;
int par[3001],n,m,q,sum = 0,i;
int find(int a){
    return par[a] = (a == par[a]) ? a : find(par[a]);
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>n>>m;
    priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
    for(i=0;i<n;++i) par[i] = i;
    for(i=0;i<m;++i)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(d == 1) par[find(a)] = find(b);
        else pq.push({c,a,b});
    }
    cin >> q;
    multiset<pair<int,int>> mt;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        mt.insert({b,a});
    }
    while(!pq.empty())
    {
        auto [c,a,b] = pq.top();
        pq.pop();
        if(par[find(a)] != par[find(b)])
        {
            par[find(a)] = par[b];
            for(auto [y,x] : mt)
            {
                if(x >= c)
                {
                    sum+=y;
                    break;
                }
            }
        }
    }
    cout << sum;
}
#include<bits/stdc++.h>
using namespace std;
int a[N],b[N],n;
int main()
{
    int i;
    ios::sync_with_stdio(0); 
    cin. tie(0);
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++)
    {
        cin >> b[i];
        b[i]=-b[i];
    }
    quick(a,0,n-1);
    quick(b,0,n-1);
    for(int i=0;i<n;i++) a[i]=a[i]-b[i];
    quick(a,0,n-1);
    int ans=0;
    for(i=1;i<n;i++) ans+=a[i]-a[i-1];
    cout << ans;
}
#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
#define repd0(a) for (int i = a; i >= 1; --i)
#define repd3(i, a, b, c) for (int i = b; i >= a; i-=c)
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
const int MX = 1e7 + 10;
ll l[20], a[20], s[MX], t[20], w[20], tmp[20];
void solve()
{
    int n, m, x; cin >> n >> m >> x;
    rep(i, 1, n) cin >> l[i];
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> s[i], s[i] += s[i-1];
    rep(i, 1, x) cin >> t[i];
    sort(a+1, a+n+1);
    rep(i, 1, x)
    {
        ll prev = 0, y; cin >> y; 
        rep(i, 1, n-1) cin >> y, w[i] = s[y-1] - s[prev-1], prev = y;
        w[n] = s[m] - s[prev-1];
        sort(w+1, w+n+1, greater<ll>());
        bool ok = 0;
        sort(l+1, l+n+1);
        do{
            bool pass = 1;
            rep(j, 1, n) tmp[j] = (l[j]*t[i] - w[j])/t[i];
            rep(j, 1, n) if (a[j] > tmp[j]) {pass = 0; break;}
            if (pass) {ok = 1; break;}
        }while (next_permutation(l+1, l+n+1));
        cout << (ok ? "P" : "F") << nl;
    }
}  
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}