/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
const int inf=1e9+7;
int n,L,i;
map<pii,int> mp;
map<pair<pii,pii>,int> mp2;
int cnt;
int f0(pii x)
{
    if(mp[x]) return mp[x];
    if(x.f>=0&&x.f<L) return mp[x]=++cnt;
    return -1;
}
vector<pii> adj[400005];
int dist[400005];
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> L;
    vector<pii> vec;
    for(i=1;i<=n;++i)
	{
        int a,b,c,d,w; cin>>a>>b>>c>>d>>w;
        mp2[{{a,b},{c,d}}]=w;
        mp2[{{c,d},{a,b}}]=w;
        vec.pb({a,b});
        vec.pb({c,d});
    }
    sort(vec.begin(),vec.end());
}

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
            if(most == val)
            {
                best_x = i;
                best_y = j;
                best_x2 = i + 1;
                best_y2 = j;
            }
            if(most == val2)
            {
                best_x = i;
                best_y = j;
                best_x2 = i;
                best_y2 = j + 1;
            }
        }
    }
    cout << 2 * most << "\n";
    deque<pll> dq;
    ll nowx = best_x, nowy = best_y;
    while(nowx != 0 || nowy != 0)
    {
        dq.emplace_front(nowx, nowy);
        ll tmp = nowx;
        nowx = par_r[nowx][nowy].F;
        nowy = par_r[tmp][nowy].S;
    }
    nowx = best_x2, nowy = best_y2;
    while(nowx != n - 1 || nowy != m - 1)
    {
        dq.emplace_back(nowx, nowy);
        ll tmp = nowx;
        nowx = par_g[nowx][nowy].F;
        nowy = par_g[tmp][nowy].S;
    }
    dq.emplace_back(n - 1, m - 1);
    ll cnt_r = most, cnt_g = most;
    nowx = 0, nowy = 0;
    while(!dq.empty())
    {
        if(cnt_r && arr[nowx][nowy] == 'R')
        {
            cnt_r--;
            cout << "Y ";
        }
        else if (cnt_g && arr[nowx][nowy] == 'G') {
            cnt_g--;
            cout << "Y ";
        }
        else  cout << "N ";
        {
            cout << "N ";
        }
        ll tox = dq.front().F;
        ll toy = dq.front().S;
        dq.pop_front();
        cout << (nowx == tox ? "R\n" : "D\n");
        nowx = tox;
        nowy = toy;
    }
    cout << (cnt_r || cnt_g ? 'Y' : 'N');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) {
        mains();
    }
    return 0;
}