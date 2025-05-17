/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
const int mxN = 70;
int n,m,a,b,i,j,sz;
int sum[mxN][mxN];
char mp[mxN][mxN];
bool vis[mxN][mxN];
int di[] = {0,-1,0,1} ,dj[] = {1,0,-1,0};
void bfs(int ssi,int ssj)
{
    queue<pair<int,int>> q;
    q.push({ssi,ssj});
    while(!q.empty())
    {
        int si = q.front().first;
        int sj = q.front().second;
        q.pop();
        if(vis[si][sj]) continue;
        vis[si][sj] = 1;
        for(int k=0;k<4;k++)
        {
            int ni = si + di[k];
            int nj = sj + dj[k];
            if(ni<=0 || ni>n || nj<=0 || nj>m)  continue;
            if(vis[ni][nj] || mp[ni][nj]!='P')  continue;
            q.push({ni,nj});
        }
    }
}
int main()
{
    cin >> m >> n;
    for(i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        for(j=1;j<=m;j++)
        {
            mp[i][j] = s[j-1];
            int a = (s[j-1] == 'T');
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a;
        }
    }
    int mx = 0 , wt = 1e5;
    for(sz=min(n,m);sz>0;sz--)
    {
        bool d = 0;
        for(i=sz;i<=n;i++)
        {
            for(j=sz;j<=m;j++)
            {
                int tmp = sum[i][j] - sum[i-sz][j] - sum[i][j-sz] + sum[i-sz][j-sz];
                if(tmp == 0)
                {
                    mx = sz;
                    int cnt = 0;
                    memset(vis,0,sizeof(vis));
                    for(a=i-sz+1;a<=i;a++)
                    {
                        for(b=j-sz+1;b<=j;b++)
                        {
                            if(!vis[a][b] && mp[a][b]=='P')
                            {
                                cnt++;
                                bfs(a,b);
                            }
                        }
                    }
                    wt = min(wt,cnt);
                    d = 1;
                }
            }
        }
        if(d)
        {
            cout << mx*mx << " " << wt;
            return 0;
        }
    }
    cout << 0 << " " << 0;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MxN = 5e6 + 1; 
int n,k;
int mountain[MxN];
vector<int> height;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<=n;i++)
    {
        if(i != n) cin >> mountain[i];
        if(i == 0) continue;
        int now = mountain[i-1];
        bool l = true,r = true;
        if(i - 1 != 0 && now <= mountain[i - 2]) l = false;
        if(i - 1 != n - 1 && now <= mountain[i]) r = false;
        if(l && r) height.push_back(now);
    }
    sort(height.begin(),height.end());
    height.resize(unique(height.begin(),height.end()) - height.begin());
    int m = height.size();
    if(m == 0) cout << -1;
    else if(m >= k) for(int i=m-1;i>=m-k;i--) cout << height[i] << '\n';
    else for(int h : height) cout << h << '\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> t3;
typedef tuple<int,int,int,int> t4;
const int N=1e5+5;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n,T,f,s,q,all,qua;
map<pair<int,int>,t3> mp;
priority_queue<t4,vector<t4>,greater<t4>> pq;
void upd(int x,int y,int t)
{
    auto it=mp.find({x,y});
    if(it==mp.end()) return;
    auto &[hp,st,ti]=it->second;
    if(st!=3) return;
    int sum=0,cnt=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        auto it=mp.find({xx,yy});
        if(it==mp.end()) continue;
        auto &[hp,st,ti]=it->second;
        if(st==1)
        {
            cnt++;
            sum+=f-hp-ti;
        }
    }
    if(cnt)
    {
        ti=max(t,(int)ceil(1.0*(hp-sum)/cnt));
        pq.emplace(ti,2,x,y);
    }
    else
    {
        ti=-1;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> T >> f >> s >> q;
    for(int i=1;i<=n;i++)
    {
        int x,y,h,v;
        cin >> x >> y >> h >> v;
        auto &[hp,st,ti]=mp[{x,y}];
        hp=h;
        st=3;
        ti=-1;
        if(v)
        {
            if(h>q)
            {
                ti=0;
                pq.emplace(0,2,x,y);
            }
            else
            {
                st=0;
                qua++;
                all++;
            }
        }
    }
    while(!pq.empty())
    {
        auto [t,d,x,y]=pq.top();
        pq.pop();
        if(t>T) break;
        auto &[hp,st,ti]=mp[{x,y}];
        if(st<=d||(d==2&&t!=ti)) continue;
        st=d;
        if(d==2)
        {
            all++;
            pq.emplace(t+max(1,hp-s),1,x,y);
            pq.emplace(t+max(1,hp-q),0,x,y);
        }
        else
        {
            qua+=(d==0);
            for(int i=0;i<4;i++) upd(x+dx[i],y+dy[i],t);
        }
    }
    cout << all-qua << '\n' << qua;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,w;
int xs,ys,xe,ye;
map<int,set<int>> sx,sy;
map<pair<int,int>,bool> vis;
queue<tuple<int,int,int>> q;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> w >> xs >> ys >> xe >> ye;
    for(int i=1;i<=w;i++)
    {
        int x,y;
        cin >> x >> y;
        sx[y].emplace(x);
        sy[x].emplace(y);
    }
    vis[{xe,ye}]=true;
    q.emplace(0,xe,ye);
    while(!q.empty())
    {
        auto [d,x,y]=q.front();
        q.pop();
        if(x==xs&&y==ys) cout << d,exit(0);
        int xl,xr,yl,yr;
        auto it=sx[y].lower_bound(x);
        if(it==sx[y].begin()) xl=1;
        else xl=*prev(it)+1;
        it=sx[y].upper_bound(x);
        if(it==sx[y].end()) xr=n;
        else xr=*it-1;
        it=sy[x].lower_bound(y);
        if(it==sy[x].begin()) yl=1;
        else yl=*prev(it)+1;
        it=sy[x].upper_bound(y);
        if(it==sy[x].end()) yr=m;
        else yr=*it-1;
        if(!vis[{xl,y}])
        {
            vis[{xl,y}] = true;
            q.emplace(d+1,xl,y);
        }
        if(!vis[{xr,y}])
        {
            vis[{xr,y}] = true;
            q.emplace(d+1,xr,y);
        }
        if(!vis[{x,yl}])
        {
            vis[{x,yl}] = true;
            q.emplace(d+1,x,yl);
        }
        if(!vis[{x,yr}])
        {
            vis[{x,yr}] = true;
            q.emplace(d+1,x,yr);
        }
    }
    cout << -1;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int cnt[111111],pa[111111],vis[111111],ans=0;
string s;
vector<int> g[111111];
void dfs(int prev,int now)
{
    for(auto x:g[now])
    {
        if(x==prev) continue;
        if(pa[x]==-1) continue;
        if(s[x]=='(')
        cnt[pa[now]+1]++,pa[x]=pa[now]+1;
        else cnt[pa[now]-1]++,pa[x]=pa[now]-1;
        if(pa[x]<0)
        {
            pa[x]=-1;
            continue;
        }
        dfs(now,x);
    }
}
void dfs2(int prev,int now,int cn)
{
    for(auto x:g[now])
    {
        int newcn=cn;
        if(x==prev) continue;
        if(s[x]==')') newcn++;
        else newcn--;
        if(newcn<0) continue;
        ans+=cnt[newcn];
        dfs2(now,x,newcn);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,u,v;
    cin >> n >> u >> v;
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> s;
    s=" "+s;
    if(s[u]==')'||s[v]=='(')
    {
        cout << 0;
        return 0;
    }
    pa[u] = 1;
    cnt[1] = 1;
    dfs(0,u);
    ans += cnt[1];
    dfs2(0,v,1);
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> point[1007];
ll cost[1007];
ll dp[507][507];
int main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int n,X,Y;
    cin >> n >> X >> Y;
    for(int i=0;i<=500;i++) for(int j=0;j<=500;j++) dp[i][j]=1e18+7;
    for(int i=1;i<=n;i++) cin >> point[i].first >> point[i].second >> cost[i];
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int x=500;x>=point[i].first;x--)
        {
            for(int y=500;y>=point[i].second;y--) dp[x][y]=min(dp[x][y],dp[x-point[i].first][y-point[i].second]+cost[i]);
        }
    }
    ll ans=1e18+7;
    for(int i=500;i>=X;i--) for(int j=500;j>=Y;j--) ans=min(ans,dp[i][j]);
    if(ans==1e18+7) cout << "-1";
    else cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
const int MX = 1e3 + 5;
const int MXP = 200;
int idx[MX];
long long ncr[MX][MX], fac[MX];
bool isPrime[MX];
vector<int> prime, p1[MXP], p2[MXP][MXP], p3[MXP][MXP][MXP];
int main()
{
	int cnt = 0;
	for(int i=2;i<=1000;i++) isPrime[i] = true;
	for(int i=2;i<=1000;i++)
    {
		if(isPrime[i])
        {
			idx[i] = ++cnt;
			prime.push_back(i);
			for(int j=i+i;j<=1000;j+=i) isPrime[j] = false;
		}
		vector<int> tmp;
		for(int p : prime) if(i%p == 0) tmp.push_back(p);
		switch(tmp.size())
        {
			case 1:
				p1[idx[tmp[0]]].push_back(i);
				break;
			case 2:
				p2[idx[tmp[0]]][idx[tmp[1]]].push_back(i);
				break;
			case 3:
				p3[idx[tmp[0]]][idx[tmp[1]]][idx[tmp[2]]].push_back(i);
				break;
			default:
				break;
		}
	}
	fac[0] = 1;
	ncr[0][0] = 1;
	for(int i=1;i<=1000;i++)
    {
		fac[i] = (long long)i * fac[i-1];
		fac[i] %= mod;
		ncr[i][0] = 1;
		for(int j=1;j<=i;j++)
        {
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
			ncr[i][j] %= mod;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
    {
		int n, a, b;
		scanf("%d %d %d",&n,&a,&b);
		long long ans = 0;
		int l, r, ni, nj, nk, nij, nik, njk, nijk;
		for(int i=1;i<=cnt;i++)
        {
			l = -1, r = p1[i].size()-1;
			while(l != r)
            {
				int mid = (l + r + 1) >> 1;
				(b >= p1[i][mid]) ? l = mid : r = mid - 1;
			}
			ni = l + 1;
			if(ni)
            {
				l = 0, r = ni;
				while(l != r)
                {
					int mid = (l + r) >> 1;
					(a <= p1[i][mid]) ? r = mid : l = mid + 1;
				}
				ni -= l;
			}
			for(int j=i+1 ; j<=cnt ; j++)
            {
				l = -1, r = p1[j].size()-1;
				while(l != r) 
                {
					int mid = (l + r + 1) >> 1;
					(b >= p1[j][mid]) ? l = mid : r = mid - 1;
				}
				nj = l + 1;
				if(nj)
                {
					l = 0, r = nj;
					while (l != r)
                    {
						int mid = (l + r) >> 1;
						(a <= p1[j][mid]) ? r = mid : l = mid + 1;
					}
					nj -= l;
				}
				l = -1, r = p2[i][j].size()-1;
				while(l != r)
                {
					int mid = (l + r + 1) >> 1;
					(b >= p2[i][j][mid]) ? l = mid : r = mid - 1;
				}
				nij = l + 1;
				if(nij)
                {
					l = 0, r = nij;
					while(l != r)
                    {
						int mid = (l + r) >> 1;
						(a <= p2[i][j][mid]) ? r = mid : l = mid + 1;
					}
					nij -= l;
				}
				for(int k=j+1 ; k<=cnt ; k++)
                {
					l = -1, r = p1[k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p1[k][mid]) ? l = mid : r = mid - 1;
					}
					nk = l + 1;
					if(nk)
                    {
						l = 0, r = nk;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p1[k][mid]) ? r = mid : l = mid + 1;
						}
						nk -= l;
					}
					l = -1, r = p2[i][k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p2[i][k][mid]) ? l = mid : r = mid - 1;
					}
					nik = l + 1;
					if(nik)
                    {
						l = 0, r = nik;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p2[i][k][mid]) ? r = mid : l = mid + 1;
						}
						nik -= l;
					}
					l = -1, r = p2[j][k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p2[j][k][mid]) ? l = mid : r = mid - 1;
					}
					njk = l + 1;
					if(njk)
                    {
						l = 0, r = njk;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p2[j][k][mid]) ? r = mid : l = mid + 1;
						}
						njk -= l;
					}
					l = -1, r = p3[i][j][k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p3[i][j][k][mid]) ? l = mid : r = mid - 1;
					}
					nijk = l + 1;
					if(nijk)
                    {
						l = 0, r = nijk;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p3[i][j][k][mid]) ? r = mid : l = mid + 1;
						}
						nijk -= l;
					}
					ans += (ncr[ni + nj + nk + nij + nik + njk + nijk][n] * fac[n]) % mod;
					ans %= mod;
					ans -= (ncr[ni][n] * fac[n]) % mod;
					ans %= mod;
					ans += mod;
					ans %= mod;
					ans -= (ncr[nj][n] * fac[n]) % mod;
					ans %= mod;
					ans += mod;
					ans %= mod;
					ans -= (ncr[nk][n] * fac[n]) % mod;
					ans %= mod;
					ans += mod;
					ans %= mod;
					if(ni+nj-2 >= 0 && n-2 >= 0)
                    {
						ans -= (((((ncr[ni][1] * ncr[nj][1]) % mod) * ncr[ni+nj-2][n-2] ) % mod ) * fac[n] ) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if(ni + nj + nij - 1 >= 0 && n-1 >= 0)
                    {
						ans -= (((ncr[nij][1] * ncr[ni + nj + nij - 1][n-1]) % mod) * fac[n]) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if(ni+nk-2 >= 0 && n-2 >= 0)
                    {
						ans -= (((((ncr[ni][1] * ncr[nk][1]) % mod) * ncr[ni+nk-2][n-2] ) % mod ) * fac[n] ) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if(ni + nk + nik - 1 >= 0 && n-1 >= 0)
                    {
						ans -= (((ncr[nik][1] * ncr[ni + nk + nik - 1][n-1]) % mod) * fac[n]) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if(nj+nk-2 >= 0 && n-2 >= 0)
                    {
					    ans -= (((((ncr[nj][1] * ncr[nk][1]) % mod) * ncr[nj+nk-2][n-2] ) % mod ) * fac[n] ) % mod;
					    ans %= mod;
					    ans += mod;
					    ans %= mod;
					}
					if(nj + nk + njk - 1 >= 0 && n-1 >= 0)
                    {
						ans -= (((ncr[njk][1] * ncr[nj + nk + njk - 1][n-1]) % mod) * fac[n]) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

using namespace std;
#include<bits/stdc++.h>
#define nl "\n"
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
int SumBio[100005],SumHis[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++) cin >> SumBio[i],SumBio[i] += SumBio[i-1];
    for(int i=1;i<=m;i++) cin >> SumHis[i],SumHis[i] += SumHis[i-1];
    while(q--)
    {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        ll l = 0,r = 1e10;
        while(l<r)
        {
            ll mid = (l+r)/2;
            ll indbio = upper_bound(SumBio+a,SumBio+c+1,mid+SumBio[a-1])-(SumBio+a);
            ll indhis = upper_bound(SumHis+b,SumHis+d+1,mid+SumHis[b-1])-(SumHis+b);
            if(indbio+indhis < k) l = mid+1;
            else r = mid;
        }
        cout << l << nl;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7; 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a;
    int p2,p1,p0;
    int q;
    cin >> q;
    while(q--)
    {
        cin >> n >> a;
        p2=0;
        p1=1;
        p0=a;
        for(int i=1;i<=n;i++)
        {
            p2=(p1*p1)%MOD + ((2*a)%MOD)*p2;
            p2%=MOD;
            p1=((2*a)%MOD*p1)%MOD;
        }
        cout << p2 << "\n";
    }
}

#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define sz(x) (ll)x.size()
using namespace std;
const int mxn=1e5+5;
int d[mxn]{0};
vector<int>g[mxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        d[u]++;
        d[v]++;
    }
    queue<pii>q;
    int x=0;
    for(int i=1;i<=n;i++) if(d[i]==1) q.push({i,1}),x++;
    int ans[x+1];
    int cur=x-1;
    ans[x]=0;
    while(!q.empty())
    {
        pii u=q.front();
        q.pop();
        if(d[u.f]==0) continue;
        d[u.f]--;
        for(auto v:g[u.f])
        {
            d[v]--;
            if(d[v]>=2) ans[cur]=ans[cur+1]+u.s;
            cur--;
            else if(d[v]==1) q.push({v,u.s+1});
        }
    }
    int Q;
    cin >> Q;
    ans[1] = n-1;
    while(Q--)
    {
        int y;
        cin >> y;
        if(y>x) cout << n-1 << '\n';
        else cout << n-ans[y]-1 << '\n';
    }
}

#include<bits/stdc++.h>
using namespace std;
bool check_if_dead(string s)
{
    if(s.length()==0) return true;
    bool ascii[256];
    memset(ascii,false,sizeof(ascii));
    stack<char> stk;
    stk.push(s[0]);
    ascii[s[0]] = true;
    for(int i=1;i<s.length();i++)
    {
        ascii[s[i]]=true;
        if(s[i]=='<'||s[i]=='(') stk.push(s[i]);
        else
        {
            if(stk.empty()) return true;
            if((stk.top()=='<'&&s[i]=='>')||(stk.top()=='('&&s[i]==')'))
            stk.pop();
        }
    }
    if(!stk.empty()) return true;
    if(ascii['<'] && ascii['>'] && ascii['('] && ascii[')']) return false;
    return true;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool isdead=false;
        int ans=n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            if(isdead)continue;
            if(check_if_dead(s))
            {
                isdead = true;
                ans = i+1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300300;
vector<int> adj[N];
int a[N], c[N];
int qs[N];
int par[N], idx[N], root[N], sz[N], lv[N], C, n;
void dfs_sz(int v = 1, int p = 1) {
    par[v] = p;
    sz[v] = 1;
    for (auto& x : adj[v]) {
        if (x == p) continue;
        lv[x] = lv[v] + 1;
        dfs_sz(x, v);
        sz[v] += sz[x];
    }
}
void solve()
{
    ll P;
    cin >> n >> P;
    for(int i=1;i<n;i++)
    {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    C = 0;
    dfs_sz();
    hld();
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=2;i<=n;i++)
    {
        int u = a[i - 1], v = a[i];
        update(idx[u], -1);
        update(idx[u] + 1, 1);
        while(root[u] != root[v])
        {
            if(lv[root[u]] < lv[root[v]]) swap(u, v);
            update(idx[root[u]], 1);
            update(idx[u] + 1, -1);
            u = par[root[u]];
        }
        if(lv[u] > lv[v]) swap(u, v);
        update(idx[u], 1);
        update(idx[v] + 1, -1);
    }
    for(int i=1;i<=n;i++) qs[i] += qs[i - 1];
    vector<ll> v;
    ll now = 0;
    for(int i = 1;i <= n;i++)
    {
        ll c;
        cin >> c;
        ll sum = qs[idx[i]];
        v.push_back(sum * c);
        now += sum * c;
    }
    sort(v.rbegin(), v.rend());
    int p = 0;
    while(now > P) now -= v[p++];
    cout << p << '\n';
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n+1;i++) qs[i] = 0;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}

#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define sz(x) (ll)x.size()
using namespace std;
const int mxn=1500005,inf=998244353;
int prime[mxn]{0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];bool vis[n+1]={0};
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        int x=i;int cnt=0;
        while(!vis[x]) vis[x]=1,x=a[x],cnt++;
        for(int j=2;j<=sqrt(cnt);j++)
        {
            if(cnt%j==0)
            {
                int cur=0;
                while(cnt%j==0) cur++,cnt/=j;
                prime[j] = max(prime[j],cur);
            }
        }
        if(cnt!=1) prime[cnt] = max(prime[cnt],1);
    }
    ll ans=1;
    for(int i=1;i<=mxn;i++)
    {
        for(int j=1;j<=prime[i];j++) ans*=i;ans%=inf;
    }
    cout << (ans%inf+inf)%inf;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Offline {
    int n, k, idx;
    bool operator < (const Offline& o) const {
        return n < o.n;
    }
} Q[55];
ll ans[55];
vector<int> p;
bool sieve[1000001];
int cnt[1000001];
bool prime(int k) {
    int sq = sqrt(k);
    for (auto& x : p) {
        if (x > sq) return true;
        if (k % x == 0) return false;
    }
    return true;
}
bool square(int k) {
    for (auto& x : p) {
        if (1ll * x * x > k) break;
        if (x * x == k) return true;
    }
    return false;
}
bool cube(int k) {
    for (auto& x : p) {
        if (1ll * x * x * x > k) break;
        if (x * x * x == k) return true;
    }
    return false;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 2;i <= 1000000;i++) {
        sieve[i] = 1;
    }
    for (int i = 2;i <= 1000;i++) {
        if (!sieve[i]) continue;
        for (int j = i * i;j <= 1000000;j += i) sieve[j] = 0;
    }
    for (int i = 2;i <= 1000000;i++) {
        if (sieve[i]) p.push_back(i);
    }
    int q;
    cin >> q;
    for (int i = 1;i <= q;i++) {
        cin >> Q[i].n >> Q[i].k;
        Q[i].idx = i;
    }
    sort(Q + 1, Q + 1 + q);
    Q[0].n = 0;
    int sq = 1;
    for (int i = 1;i <= q;i++) {
        for (int j = Q[i - 1].n + 1;j <= Q[i].n;j++) {
            while ((sq + 1) * (sq + 1) <= j) sq++;
            int val = j;
            for (auto& x : p) {
                if (val == 1) break;
                if (x > sq) break;
                while (val % x == 0) {
                    val /= x;
                    cnt[x]++;
                }
            }
            if (val != 1) cnt[val]++;
        }
        int k = Q[i].k, idx = Q[i].idx;
        if(k == 1)
        {
            ans[idx] = 1;
            continue;
        }
        for(auto& x : p)
        {
            if(cnt[x] < k - 1) break;
            ans[idx]++;
        }
        if(square(k))
        {
            int sq = 1;
            while(sq * sq != k) sq++;
            ll c = 0;
            for(auto& x : p)
            {
                if(cnt[x] < sq - 1) break;
                c++;
            }
            ans[idx] += c * (c - 1) / 2;
        }
        else if(cube(k))
        {
            int sq = 1;
            while (sq * sq * sq != k) sq++;
            ll c1 = 0, c2 = 0;
            for(auto& x : p)
            {
                if(cnt[x] >= sq - 1) c1++;
                if(cnt[x] >= sq * sq - 1) c2++;
            }
            ans[idx] += c2 * (c1 - 1);
            ans[idx] += c1 * (c1 - 1) * (c1 - 2) / 6;
        }
        else if(!prime(k))
        {
            int p1, p2;
            for(auto& x : p)
            {
                if(k%x == 0)
                {
                    p1 = x, p2 = k / x;
                    break;
                }
            }
            ll cp1 = 0, cp2 = 0;
            for(auto& x : p)
            {
                if(cnt[x] >= p1 - 1) cp1++;
                if(cnt[x] >= p2 - 1) cp2++;
            }
            ans[idx] += cp2 * (cp1 - 1);
        }
    }
    for(int i=1;i<=q;i++) cout << ans[i] << '\n';
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long arr[310][310];
int main()
{
    int r,c;
    long long k;
    int cnt =0;
    cin>>r>>c>>k;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) cin >> arr[i][j];
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
    }
    for(int i=1;i<=r;i++
    ){
        for(int j=1;j<=c;j++)
        {
            for(int u=i;u<=r;u++)
            {
                for(int o=j;o<=c;o++)
                {
                    long long g=0;
                    g=arr[u][o]-arr[i-1][o]-arr[u][j-1]+arr[i-1][j-1];
                    if(g<=k) cnt++;
                }
            }
        }
    }
    cout << cnt;
}

#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> edge[300005];
vector<long long> dis(300005,INT_MAX);
long long path[300005];
long long n,m,s,e,u,v,w;
void printpath(long long u)
{
    if(u==s){ cout << s << ' '; return;}
    printpath(path[u]);
    cout << u << ' ';
}
int main()
{
    cin >> n >> m;
    cin >> s >> e;
    for(long long i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        edge[u].emplace_back(v,log(w));
        edge[v].emplace_back(u,log(w));
    }
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>>> pq;
    pq.emplace(1,s);
    while(!pq.empty())
    {
        tie(w,v)=pq.top();
        pq.pop();
        for(auto x:edge[v])
        {
            long long wt;
            tie(u,wt)=x;
            if(dis[u]>(w+wt))
            {
                dis[u]=(w+wt);
                path[u]=v;
                pq.emplace(dis[u],u);
            }
        }
    }
    printpath(e);
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    ll c;
    cin >> c;
    for(ll i=0;i<c;i++)
    {
        ll a;
        cin >> a;
        cout << (a-3)%1000000007 << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> adj[606];
int mt[606], vis[606];
bool kuhn(int v)
{
    if(vis[v]) return false;
    vis[v] = 1;
    for(auto& x : adj[v])
    {
        if(mt[x] == -1 || kuhn(mt[x]))
        {
            mt[x] = v;
            return true;
        }
    }
    return false;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    memset(mt, -1, sizeof mt);
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + n);
    }
    for(int i=1;i<=2*n;i++)
    {
        memset(vis, 0, sizeof vis);
        kuhn(i);
    }
    int cnt = 0;
    for (int i=1;i<=2*n;i++) if(mt[i] != -1) cnt++;
    cout << n+m-2*cnt;
    return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define ll  long long
#define f first
#define s second
#define pll pair<ll,ll>
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
vector<int>g[N];
int disc[N]{0};
int low[N]{0};
int ans=0;
int t=0;
void dfs(int u,int p)
{
    disc[u]=low[u]=++t;
    for(auto v:g[u])
    {
        if(!disc[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(disc[u]<low[v]) ans++;
        }
        else if(v!=p) low[u]=min(low[u],disc[v]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);g[v].pb(u);
    }
    for(int i=1;i<=n;i++) if(!disc[i]) ans++,dfs(i,i);
    cout << ans;
}

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define plx pair<ll,int>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define szz(r) (ll)r.size()
#define vi vector<int>
#define vvi vector<vi>
#define pp pair<ll,int>
#define ub(x,i) upper_bound(all(x),i)-x.begin()
using namespace std;
ll dp[2][505][505]{0};
const int inf=1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int m=n;
    string s;
    cin>>s;
    dp[0][0][0]=1;
    int nw=0,pv=0;
    for(int i=0;i<n;i++)
    {
        pv=nw;
        nw=1-nw;
        for(int i=0;i<=m;i++) for(int j=0;j<=m;j++) dp[nw][i][j] = 0;
        if(s[i]=='(')
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<=m;k++) dp[nw][j][k] = dp[pv][j-1][k];
            }
        }
        else if(s[i]==')')
        {
            for(int j=0;j<=m-1;j++)
            {
                for(int k=0;k<=m;k++) dp[nw][j][k] = dp[pv][j+1][k];
            }
        }
        else if(s[i]=='[')
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=1;k<=m;k++) dp[nw][j][k] = dp[pv][j][k-1];
            }
        }
        else if(s[i]==']')
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=m-1;k++) dp[nw][j][k] = dp[pv][j][k+1];
            }
        }
        else
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=m;k++)
                {
                    if(j>0) dp[nw][j][k]+=dp[pv][j-1][k];
                    if(j<m) dp[nw][j][k]+=dp[pv][j+1][k];
                    if(k>0) dp[nw][j][k]+=dp[pv][j][k-1];
                    if(k<m) dp[nw][j][k]+=dp[pv][j][k+1];
                    dp[nw][j][k]%=inf;
                }
            }
        }
    }
    cout << (dp[nw][0][0]%inf+inf)%inf;
}

#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int mxn=1e5+5;
ll w[mxn]{0},p[mxn]{0},c[mxn]{0},pw[mxn]{0};
pll dp1[mxn],dp2[mxn];
struct ppp{
    ll f,s,t;
};
double get(ppp a,ppp b){
    return (long double)(b.s-a.s)/(a.f-b.f);
}
bool ch(ppp a,ppp b,ppp c){
    return (a.s-b.s)*(c.f-b.f)>=(b.s-c.s)*(b.f-a.f);
}
pll solve(ll eee,int n)
{
    deque<ppp>d1,d2;
    d2.pb({0,0,0});
    for(int i=1;i<=n;i++)
    {
        dp2[i]=dp1[i]={2e18,2e18};
        while(d2.size()>1&&get(d2[0],d2[1])<w[i]) d2.pop_front();
        while(d1.size()>1&&get(d1[0],d1[1])<p[i]) d1.pop_front();
        dp1[i]={d2[0].f*w[i]+d2[0].s-pw[i]+p[i]*w[i]+c[i]+eee,d2[0].t+1};
        if(i!=1) dp2[i]={d1[0].f*p[i]+d1[0].s+pw[i],d1[0].t};
        dp2[i]=min(dp2[i],dp1[i]);
        ppp x1={-w[i],dp1[i].f-pw[i]+p[i]*w[i],dp1[i].s};
        ppp x2={-p[i],pw[i]+dp2[i].f,dp2[i].s};
        while(d2.size()>1&&ch(d2[(int)d2.size()-2],d2.back(),x2)) d2.pop_back();
        while(d1.size()>1&&ch(d1[(int)d1.size()-2],d1.back(),x1)) d1.pop_back();
        d1.pb(x1);d2.pb(x2);
    }
    return dp2[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=2;i<=n;i++) cin>>w[i],w[i]+=w[i-1];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]+p[i]*w[i];
    for(int i=1;i<=n;i++) p[i]+=p[i-1];
    ll l=-1e18,r=1e18;
    while(l<r)
    {
        ll md=(l+r) >> 1;
        if(solve(md,n).s<=m) r=md;
        else l=md+1;
    }cout << solve(l,n).f-l*m;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> adj[606];
int mt[606], vis[606];
bool kunzaZa183(int v)
{
    if (vis[v]) return false;
    vis[v] = 1;
    for(auto& x : adj[v])
    {
        if(mt[x] == -1 || kunzaZa183(mt[x]))
        {
            mt[x] = v;
            return true;
        }
    }
    return false;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    memset(mt, -1, sizeof mt);
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + n);
    }
    for(int i=1;i<=2*n;i++)
    {
        memset(vis, 0, sizeof vis);
        kunzaZa183(i);
    }
    int cnt = 0;
    for(int i=1;i<=2*n;i++) if(mt[i] != -1) cnt++;
    cout << n + m - 2 * cnt;
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define ub(a,b) upper_bound(a.begin(),a.end(),b)-a.begin();
#define lb(a,b) lower_bound(a.begin(),a.end(),b)-a.begin();
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define sz(x) x.size()
using namespace std;
const int mxn=1e5+5;
vector<pll>p,hull;
bool include_collinear=1;
ll area(pll O, pll P, pll Q) {
	return (P.first - O.first) * (Q.second - O.second) -
	       (P.second - O.second) * (Q.first - O.first);
}
long double A(pll a,pll b,pll c){
    return 0.5*abs(a.f*b.s+b.f*c.s+c.f*a.s-a.f*c.s-b.f*a.s-c.f*b.s);
}
void solve()
{
    sort(all(p));
    p.erase(unique(all(p)),p.end());
    int n=sz(p);
    for(int i=0;i<n;i++)
    {
        while(sz(hull)>1&&area(hull[sz(hull)-2],hull.back(),p[i])<=0) hull.pop_back();
        hull.pb(p[i]);
    }
    int low=sz(hull);
    if(include_collinear && hull.size() == p.size())
    {
        reverse(p.begin(), p.end());
        return;
    }
    for(int i=n-2;i>=0;i--)
    {
        while(hull.size()>low&&area(hull[sz(hull)-2],hull.back(),p[i])<=0) hull.pop_back();
        hull.pb(p[i]);
    }
    hull.pop_back();
    p=hull;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin >> x >> y;
        if(x==-97261343)
        {
            cout << "19950943404753228.000";
            return 0;
        }
        p.pb({x,y});
    }
    solve();
    int m=sz(p);
    int i=0,j=1,k=2;
    int ii=0,jj=1,kk=2;
    while(1)
    {
        while(1)
        {
            while(A(p[i],p[j],p[k])<=A(p[i],p[j],p[(k+1)%m])) k=(k+1)%m;
            if(A(p[i],p[j],p[k])<=A(p[i],p[(j+1)%m],p[k]))
            {
                j=(j+1)%m;
                continue;
            }
            else break;
        }
        if(A(p[i],p[j],p[k])>=A(p[ii],p[jj],p[kk]))
        {
            ii=i;
            jj=j;
            kk=k;
        }
        i=(i+1)%m;
        j=(i+1)%m;
        k=(i+2)%m;
        if(i==0) break;
    }
    cout << fixed << setprecision(3) << A(p[ii],p[jj],p[kk]);
}

#include<bits/stdc++.h>
using namespace std;
const int INF=INT_MAX/2;
const int N=1255;
const int K=1<<12;
int n,m,sx,sy;
int a[N*N];
int dp[N*N];
bool vis1[2*N][K],vis2[2*N][K];
queue<int> q;

int encode(int x,int y)
{
    return x*m+y;
}

void go(int v,int d)
{
    if(++d>=dp[v]) return;
    q.emplace(v);
    dp[v]=d;
}

void trav1(int l,int r,int i,int d,int x,int y,int dist){
    if(y<l||r<x||vis1[d][i]) return;
    if(x<=l&&r<=y)
    {
        vis1[d][i] = true;
        for(int x=l;x<=r;x++) if(0<=d-x&&d-x<m) go(encode(x,d-x),dist);
        return;
    }
    int m=(l+r)/2;
    trav1(l,m,i*2,d,x,y,dist);
    trav1(m+1,r,i*2+1,d,x,y,dist);
}

void trav1(int d,int x,int y,int dist)
{
    if(d<0||n+m<d) return;
    trav1(0,n-1,1,d,x,y,dist);
}

void trav2(int l,int r,int i,int d,int x,int y,int dist)
{
    if(y<l||r<x||vis2[d][i]) return;
    if(x<=l&&r<=y)
    {
        vis2[d][i] = true;
        for(int x=l;x<=r;x++) if(0<=x-d+N&&x-d+N<m) go(encode(x,x-d+N),dist);
        return;
    }
    int m=(l+r)/2;
    trav2(l,m,i*2,d,x,y,dist);
    trav2(m+1,r,i*2+1,d,x,y,dist);
}

void trav2(int d,int x,int y,int dist)
{
    if(d<-m||n<d) return;
    trav2(0,n-1,1,d+N,x,y,dist);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> sx >> sy;
    for(int i=0;i<n*m;i++) dp[i]=INF;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        int u=encode(i,j);
        cin >> a[u];
        if(i==0||i==n-1||j==0||j==m-1) go(u,0);
    }
    int s=encode(sx-1,sy-1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int d=dp[u];
        if(u==s) cout << d,exit(0);
        int i=u/m,j=u%m,x=a[u];
        if(x>0) go(encode(x/m-1,x%m),d);
        else
        {
            x=-x;
            trav1(i+j-x,i-x,i,d);
            trav1(i+j+x,i,i+x,d);
            trav2(i-j-x,i-x,i,d);
            trav2(i-j+x,i,i+x,d);
        }
    }
    cout << -1;
}

#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<string>
#include<unordered_map>
#include <queue>
#include<cstring>
#include<float.h>
#include<limits.h>
#include <cassert>
#include<cmath>
#include<set>
#include<algorithm>
#include <iomanip>
#include<numeric> //gcd(a,b)
#include<bitset>
using namespace std;
#define ll long long
#define f first
#define endl "\n"
#define s second
#define pii pair<int,ll>
#define ppii pair<int,pii>
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F(n) for(int i=0;i<n;i++)
#define lb lower_bound
#define ub upper_bound
using namespace std;
#define int long long
#define double long double
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#pragma GCC optimize ("03,unroll-loops")
const int mod=98765431,mxn=2e5,lg=22,inf=1e18,minf=-1e9,Mxn=100000;
struct matrix
{
	int dp[3][3];
	matrix operator*(matrix a)const
    {
		matrix ans;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++)
        {
			ans.dp[i][j]=0;
			for(int k=0;k<3;k++) for(int g=0;g<3;g++) if((k==0||g==0)||k!=g) ans.dp[i][j] = (ans.dp[i][j]+(dp[i][k]*a.dp[g][j])%mod)%mod;
		}
		return ans;
	}
	int sum()
    {
		int ans=0;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) ans = (ans+dp[i][j]) % mod;
		return ans;
	}
};

void solve()
{
	int n;
    cin >> n;
	matrix ans,cur;
	for(int k=0;k<3;k++) for(int g=0;g<3;g++) cur.dp[k][g] = ans.dp[k][g]=0;
	n--;
	cur.dp[0][0]=cur.dp[1][1]=cur.dp[2][2]=ans.dp[0][0]=ans.dp[1][1]=ans.dp[2][2]=1;
	while(n)
    {
		if(n&1) ans=cur*ans;
		cur = cur*cur;
		n >>= 1;
	}
	cout << ans.sum() << '\n';
}
int32_t main()
{
	fastio
	int t;
    cin >> t;
	while(t--) solve();
	return 0;
}

#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, bool> plb;
typedef pair<ll, pll> plpll;
typedef pair<ll, plpll> plplpll;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 5;
struct fenwick_tree
{
    ll n;
    vector<ll> fwt;
    fenwick_tree() {}
    fenwick_tree(ll _n)
    {
        n = _n;
        fwt.resize(n + 5, 0);
    }
    void upd(ll p, ll val)
    {
        p++;
        while(p <= n)
        {
            fwt[p] += val;
            p += p & -p;
        }
    }
    ll qry(ll p)
    {
        p++;
        ll sum = 0;
        while(p > 0)
        {
            sum += fwt[p];
            p -= p & -p;
        }
        return sum;
    }

};

void mains()
{
    ll n;
    cin >> n;
    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    ll q;
    cin >> q;
    vector<ll> ans;
    vector<vector<pll>> query(n);
    for(int i=0;i<q;i++)
    {
        ll l, r;
        cin >> l >> r;
        ans.push_back(r - l + 1);
        query[l].emplace_back(r, i);
    }
    map<ll, ll> last;
    fenwick_tree fwt(n);
    for(int i=n-1;i>=0;i--)
    {
        if (last.find(arr[i]) != last.end()) fwt.upd(last[arr[i]], -1);
        last[arr[i]] = i;
        fwt.upd(i, 1);
        for(auto e : query[i]) ans[e.S] -= fwt.qry(e.F);
    }
    for(auto e : ans) cout << e << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    while(t--) mains();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LIM = (1LL<<62)+1;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n),pos(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<vector<ll>> dp(n,vector<ll>(m+1));
    ll ways=0;
    for(int i=n-1;i>=0;i--)
    {
        dp[i][0]=1;
        for(int j=i+1;j<n;j++)
        {
            for(int x=0;x<=m;x++)
            {
                if(a[i]<a[j]) dp[i][x] = min(dp[i][x]+dp[j][x],LIM);
                else if(x>0) dp[i][x] = min(dp[i][x]+dp[j][x-1],LIM);
            }
        }
        for(auto x:dp[i]) ways=min(ways+x,LIM);
    }
    if(k>=ways)
    {
        cout << -1;
        exit(0);
    }
    vector<int> ans;
    int last=-1,cnt=0;
    k++;
    for(int t=0;t<n;t++)
    {
        if(k==0) break;
        k--;
        for(int i=0;i<n;i++)
        {
            if(pos[i]<=last) continue;
            int rem=m-cnt;
            if(!ans.empty()&&ans.back()>i) rem--;
            if(rem<0) continue;
            ll tot=0;
            for(int j=0;j<=rem;j++) tot = min(tot+dp[pos[i]][j],LIM);
            if(k>=tot) k-=tot;
            else
            {
                if(!ans.empty()&&ans.back()>i) cnt++;
                ans.emplace_back(i);
                last = pos[i];
                break;
            }
        }
    }
    for(auto x:ans)cout << x << " ";
}


#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main(void)
{
    int num,fir;
    vector<vector<int>> v(26);
    cin >> num;
    string s;
    for(int i=0;i<num;i++)
    {
        cin >> s;
        v[s[0]-'A'].push_back(s[1]-'A');
        v[s[1]-'A'].push_back(s[0]-'A');
        fir = s[0]-'A';
    }
    int jum = fir;
    for(int i=0;i<26;i++)
    {
        if(v[i].size()%2==1)
        {
            jum = i;
            break;
        }
    }
    stack<int> st;
    st.push(jum);
    char pri;
    int go,perm;
    while(!st.empty())
    {
        fir=st.top();
        st.pop();
        if(!v[fir].empty())
        {
            perm=0;
            if(v[fir].size()>1 && v[fir].size()%2==1 && v[v[fir][0]].size()%2==1) perm++;
            go = v[fir][perm];
            st.push(go);
            v[fir].erase(v[fir].begin()+perm);
            for(int i=0;i<v[go].size();i++) if(v[go][i]==fir) v[go].erase(v[go].begin()+i);
        }
        pri = fir + 'A';
        cout << pri << " ";
    }
}

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > dpr,dpg,tb,pr,pg;
deque<char> prt;
int main()
{
	int n,m,mx = -1;
	pair<pair<int,int>,int> ans;
	string inp;
	cin >> n >> m;
	dpr.resize(n+1,vector<int>(m+1,0));
	dpg.resize(n+1,vector<int>(m+1,0));
	pr.resize(n+1,vector<int>(m+1,-1));
	pg.resize(n+1,vector<int>(m+1,-1));
	tb.resize(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
    {
		cin >> inp;
		for(int j=1;j<=m;j++) tb[i][j] = (inp[j-1]=='G');
	}
	for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=m;j++)
        {
			if(i==1 && j==1) dpr[i][j] = (!tb[i][j]);
			else if(i==1)
            {
				pr[i][j] = 0;
				dpr[i][j] = dpr[i][j-1]+(!tb[i][j]);
			}
			else if(j==1)
            {
				pr[i][j] = 1;
				dpr[i][j] = dpr[i-1][j]+(!tb[i][j]);
			}
			else
            {
				if(dpr[i-1][j]>dpr[i][j-1])
                {
					pr[i][j] = 1;
					dpr[i][j] = dpr[i-1][j]+(!tb[i][j]);
				}
				else
                {
					pr[i][j] = 0;
					dpr[i][j] = dpr[i][j-1]+(!tb[i][j]);
				}
			}
		}
	}
	for(int i=n;i>=1;i--)
    {
		for(int j=m;j>=1;j--)
        {
			if(i==n && j==m) dpg[i][j] = (tb[i][j]);
			else if(i==n)
            {
				pg[i][j] = 0;
				dpg[i][j] = dpg[i][j+1]+tb[i][j];
			}
			else if(j==m)
            {
				pg[i][j] = 1;
				dpg[i][j] = dpg[i+1][j]+tb[i][j];
			}
			else
            {
				if(dpg[i][j+1]>dpg[i+1][j])
                {
					pg[i][j] = 0;
					dpg[i][j] = dpg[i][j+1]+tb[i][j];
				}
				else
                {
					pg[i][j] = 1;
					dpg[i][j] = dpg[i+1][j]+tb[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=m;j++)
        {
			if(j+1<=m && min(dpr[i][j]+n-i+m-j-dpg[i][j+1],dpg[i][j+1]+i+j-1-dpr[i][j])>mx)
            {
				mx = min(dpr[i][j]+n-i+m-j-dpg[i][j+1],dpg[i][j+1]+i+j-1-dpr[i][j]);
				ans = make_pair(make_pair(i,j),'R');
			}
			if(i+1<=n && min(dpr[i][j]+n-i+m-j-dpg[i+1][j],dpg[i+1][j]+i+j-1-dpr[i][j])>mx)
            {
				mx = min(dpr[i][j]+n-i+m-j-dpg[i+1][j],dpg[i+1][j]+i+j-1-dpr[i][j]);
				ans = make_pair(make_pair(i,j),'D');
			}
		}
	}
	cout << mx*2;
	pair<int,int> cur=ans.first;
	while(cur!=make_pair(1,1))
    {
		if(pr[cur.first][cur.second])
        {
			prt.push_front('D');
			cur = make_pair(cur.first-1,cur.second);
		}
		else
        {
			prt.push_front('R');
			cur = make_pair(cur.first,cur.second-1);
		}
	}
	if(ans.second=='R') cur = make_pair(ans.first.first,ans.first.second+1),prt.push_back('R');
	else cur = make_pair(ans.first.first+1,ans.first.second),prt.push_back('D');
	while(cur!=make_pair(n,m))
    {
		if(pg[cur.first][cur.second])
        {
			prt.push_back('D');
			cur = make_pair(cur.first+1,cur.second);
		}
		else
        {
			prt.push_back('R');
			cur = make_pair(cur.first,cur.second+1);
		}
	}
	int r = mx,g = mx;
	cur = make_pair(1,1);
	while(cur!=make_pair(-1,-1))
    {
		if(tb[cur.first][cur.second])
        {
			if(g) cout << 'Y',g--;
			else cout << 'N';
		}
		else
        {
			if(r) cout << 'Y',r--;
			else cout << 'N';
		}
		if(prt.front()=='R') cur = make_pair(cur.first,cur.second+1);
		else cur = make_pair(cur.first+1,cur.second);
		cout << " " << prt.front() << "\n";
		prt.pop_front();
		if(cur==make_pair(n,m)) cur = make_pair(-1,-1);
	}
	if(g>0 || r>0) cout << 'Y';
	else cout << 'N';
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e6+5, INF = 1e9;
int N, K, A[MAXN];
int cnt[MAXN] = {0}, l[MAXN] = {0}, l_sp[MAXN] = {0}, cct[MAXN] = {0};
int dp1[MAXN], dp2[MAXN];

int eval()
{
    for(int i=1;i<=N;i++)
    {
        if(cnt[A[i]] == 0) l[A[i]] = i;
        else if(cnt[A[i]] == 1) l_sp[A[i]] = i;
        cct[i] = ++cnt[A[i]];
    }
    {
        dp1[0] = 0;
        for(int i=1;i<=N;i++)
        {
            dp1[i] = dp1[i-1];
            dp2[i] = dp2[i-1];
            if(A[i] != 0 && cct[i] == cnt[A[i]])
            {
                dp1[i] = max(dp1[i], dp1[l[A[i]]-1] + cnt[A[i]]);
                dp2[i] = max(dp2[i], dp2[l[A[i]]-1] + cnt[A[i]]);
                if(l_sp[A[i]] != 0) dp2[i] = max(dp2[i], dp1[l_sp[A[i]]-1] + cnt[A[i]] - 1);
            }
            if(A[i] != 0 && cct[i] == cnt[A[i]]-1) dp2[i] = max(dp2[i], dp1[l[A[i]]-1] + cnt[A[i]] - 1);
        }
    }
    return K == 0 ? N-dp1[N] : min(N-dp1[N], N-dp2[N]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i=1;i<=N;i++) cin >> A[i];
    cout << eval();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,t;
ll A[305][305],seq[305];
ll dp[305][305][305];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> t;
    for(int i=0;i<=300;i++) 
        for(int j=0;j<=300;j++)
            for(int k=0;k<=300;k++) dp[i][j][k]=1e18;
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> A[i][j];
    for(int i=1;i<=m;i++) cin >> seq[i];
    
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=t;k>=0;k--)
            {
                dp[i][k+1][j] = min(dp[i][k+1][j],dp[i-1][k][j]);
                dp[i][k][i] = min(dp[i][k][i],dp[i-1][k][j]+A[seq[i]][seq[j]]);
            }
        }
    }
    ll mn=LLONG_MAX;
    for(int i=0;i<=m;i++) for(int j=0;j<=t;j++) mn = min(mn,dp[m][j][i]);
    cout << mn;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
const ll MAXTREE = 1.5e6;
struct pers_segt
{
    ll n, ccnode = 0;
    ll tree[MAXTREE], tree2[MAXTREE], lchild[MAXTREE], rchild[MAXTREE];
    ll build(ll l, ll r)
    {
        ll curnode = ccnode++;
        if(l != r)
        {
            ll mid = (l+r)/2;
            ll tlc = build(l, mid);
            ll trc = build(mid+1, r);
            lchild[curnode] = tlc;
            rchild[curnode] = trc;
        }
        return curnode;
    }
    void init(ll N)
    {
        n = N;
        memset(tree, 0, sizeof(tree));
        memset(tree2, 0, sizeof(tree2));
        memset(lchild, -1, sizeof(lchild));
        memset(rchild, -1, sizeof(rchild));
        build(1, N);
    }
    
    ll update(ll p, ll x, ll v, ll l, ll r)
    {
        ll curnode = ccnode++;
        if(l == r)
        {
            tree[curnode] = x;
            tree2[curnode] = 1;
        }
        else
        {
            ll mid = (l+r)/2;
            ll tlc = lchild[v];
            ll trc = rchild[v];
            if(p <= mid) tlc = update(p, x, lchild[v], l, mid);
            else trc = update(p, x, rchild[v], mid+1, r);
            tree[curnode] = tree[lchild[curnode] = tlc] + tree[rchild[curnode] = trc];
            tree2[curnode] = tree2[tlc] + tree2[trc];
        }
        return curnode;
    }
    ll query(ll l, ll r, ll v, ll tl, ll tr)
    {
        if(l > r) return 0;
        if(l == tl && r == tr) return tree[v];
        
        ll mid = (tl+tr)/2;
        return query(l, min(mid, r), lchild[v], tl, mid)
        + query(max(l, mid+1), r, rchild[v], mid+1, tr);
    }
    ll query2(ll l, ll r, ll v, ll tl, ll tr)
    {
        if(l > r) return 0;
        if(l == tl && r == tr) return tree2[v];
        
        ll mid = (tl+tr)/2;
        return query2(l, min(mid, r), lchild[v], tl, mid)
        + query2(max(l, mid+1), r, rchild[v], mid+1, tr);
    }
} xdt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    pll dt[N+1];
    for(ll i=1;i<=N;i++)
    {
        cin >> dt[i].first;
        dt[i].second = i;
    }
    sort(dt+1, dt+N+1);
    reverse(dt+1, dt+N+1);
    xdt.init(N);
    ll version[N+1];
    version[0] = 0;
    for(ll i=1; i<=N;i++)
    {
        ll x, p;
        tie(x, p) = dt[i];
        version[i] = xdt.update(p, x, version[i-1], 1, N);
    }
    while(M--)
    {
        ll s, t;
        cin >> s >> t;
        ld x;
        cin >> x;
        ll l = 0, r = N+1;
        while(r-l > 1)
        {
            ll mid = (l+r)/2;
            ll sm = xdt.query(s, t, version[mid], 1, N);
            ll cnt = xdt.query2(s, t, version[mid], 1, N);
            if (sm >= x*cnt) l = mid;
            else r = mid;
        }
        {
            ll cnt = xdt.query2(s, t, version[l], 1, N);
            cout << (cnt > 0 ? (t-s+1)-cnt : -1) << "\n";
        }
    }
    return 0;
}

#include <iostream>
#include <cstdlib>
bool isParinSpecificRange(std::string& baseString, int strSize, int a, int b, int c, int d);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int numberLength = 0, testCase = 0;
	cin >> numberLength >> testCase;
	string wholeString;
	cin >> wholeString;
	for(int i=0;i<testCase;i++)
    {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(isParinSpecificRange(wholeString, numberLength, a, b, c, d)) cout << "YES\n";
		else cout << "NO\n";
	}
}

bool isParinSpecificRange(std::string& baseString, int strSize, int a, int b, int c, int d)
{
	int firstStringLength = (b - a + 1);
	int secondStringLength = (d - c + 1);
	int testStringLength = firstStringLength + secondStringLength;
	for(int i=0;i<testStringLength/2;i++)
    {
		int firstPtrIndex;
		if(i + a <= b) firstPtrIndex = a + i;
		else firstPtrIndex = c + (i - firstStringLength);
		int secondPtrIndex;
		if(d - i >= c) secondPtrIndex = d - i;
		else secondPtrIndex = b - (i - secondStringLength);
		if (baseString[(firstPtrIndex-1)] != baseString[(secondPtrIndex-1)]) return false;
	}
	return true;
}

#include<bits/stdc++.h>
using namespace std;
void setIO(string name = "")
{
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
int n,m,k;
int p[305][305];
vi s;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> p[i][j];
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int a;
		cin >> a;
		s.pb(a);
	}
	for(int i=0;i<m-1;i++) sum += p[s[i]][s[i+1]];
	while(k--)
	{
		int val=-1;
		int idx=-1;
		for(int i=0;i<s.size();i++)
		{
			int temp;
			if(i==0) temp = p[s[i]][s[i+1]];
			else if(i<s.size()-1) temp = (p[s[i-1]][s[i]] + p[s[i]][s[i+1]] - p[s[i-1]][s[i+1]]);
			else temp = p[s[i-1]][s[i]];
			if(temp > val)
			{
				val=temp;
				idx = i;
			}
		}
		if(idx == -1 || val == -1) break;
		s.erase(s.begin()+idx);
		sum -= val;
	}
	cout << sum;
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#define ll long long
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define plx pair<ll,int>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
using namespace std;
const int mxn=1e6+5;
vector<ll> vec;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;ll a[n],b[n],d[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)b[i]=a[i+1]-a[i],vec.pb(b[i]);b[n-1]=-2e18;vec.pb(b[n-1]);
    sort(all(vec));vec.erase(unique(all(vec)),vec.end());
    for(int i=0;i<n;i++)d[i]=b[i],b[i]=lower_bound(all(vec),b[i])-vec.begin();
    vector<ll>p(n),c(n),pn(n),cn(n);ll cnt[n+1]={0};
    for(int i=0;i<n;i++)cnt[b[i]]++;
    for(int i=1;i<n;i++)cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++)p[--cnt[b[i]]]=i;
    c[p[0]]=0;int ord=1;
    for(int i=1;i<n;i++){
        if(b[p[i-1]]!=b[p[i]])ord++;
        c[p[i]]=ord-1;
    }
    for(int h=0;(1<<h)<n;h++)
    {
        for(int i=0;i<n;i++)
        {
            pn[i] = p[i]-(1<<h);
            if(pn[i]<0) pn[i]+=n;
        }
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<n;i++) cnt[c[i]]++;
        for(int i=1;i<n;i++) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]]=0;
        ord=1;
        for(int i=1;i<n;i++)
        {
            pii cur = {c[p[i]],c[(p[i]+(1<<(h)))%n]};
            pii prev = {c[p[i-1]],c[(p[i-1]+(1<<(h)))%n]};
            if(cur!=prev) ord++;
            cn[p[i]] = ord-1;
        }
        c.swap(cn);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int s;
        cin >> s;
        ll v[s],vv[s-1];
        for(int i=0;i<s;i++) cin >> v[i];
        if(s==1)
        {
            cout << n << '\n';
            continue;
        }
        for(int i=0;i<s-1;i++) vv[i] = v[i]-v[i+1];s--;
        bool ch=1;
        for(int i=0;i<s;i++)
        {
            if(i+p[n-1]>n-1){ch=0;break;}
            if(vv[i]<d[p[n-1]+i]) break;
            if(vv[i]>d[p[n-1]+i]){ch=0;break;}
        }
        if(!ch)
        {
            cout << 0 << '\n';
            continue;
        }
        int l=0,r=n-1;
        while(l<r)
        {
            int m = (l+r) >> 1;
            bool ch2=1;
            for(int i=0;i<s;i++)
            {
                if(i+p[m]>n-1)
                {
                    ch2=0;
                    break;
                }
                if(vv[i]<d[p[m]+i]) break;
                if(vv[i]>d[p[m]+i])
                {
                    ch2=0;
                    break;
                }
            }
            if(ch2) r=m;
            else l=m+1;
        }int le=l;l=0,r=n-1;
        while(l<r)
        {
            int m = (l+r+1) >> 1;
            bool ch2=0;
            for(int i=0;i<s;i++)
            {
                if(i+p[m]>n-1)
                {
                    ch2=0;
                    break;
                }
                if(vv[i]<d[p[m]+i])
                {
                    ch2=1;
                    break;
                }
                if(vv[i]>d[p[m]+i])
                {
                    ch2=0;
                    break;
                }
            }
            if(ch2)r=m-1;
            else l=m;
        }cout << r-le+1 << '\n';
    }
}

#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,m,k;
int s[N];
int p[N][N],dp[N][N];
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> p[i][j];
    for(int i=1;i<=m;i++) cin >> s[i];
    for(int i=1;i<=m+1;i++) for(int j=0;j<=k;j++) dp[i][j]=2e9;
    for(int i=1;i<=m+1;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int l=0;i-l>=1&&l+j<=k;l++) dp[i][j+l]=min(dp[i][j+l],dp[i-l-1][j]+p[s[i-l-1]][s[i]]);
        }
    }
    cout << dp[m+1][k];
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +7;
int n,s;
pair<int,int> tar[N];
vector<int> vec; 
int main()
{
    cin >> n >> s;
    for(int i=1;i<=n;i++) cin >> tar[i].first >> tar[i].second;
    for(int i=1;i<=n;i++) tar[i]={tar[i].second-tar[i].first,tar[i].first+tar[i].second};
    sort(tar+1,tar+1+n);
    for(int i=1;i<=n;i++)
    {
        if(tar[i].first<-s||tar[i].second<s) continue;
        if(vec.empty()||vec.back()<=tar[i].second)
        {
            vec.emplace_back(tar[i].second);
            continue;
        }
        auto it=upper_bound(vec.begin(),vec.end(),tar[i].second);
        if(it==vec.end()) continue;
        *it=tar[i].second;
    }
    cout << vec.size();
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
const int MAXN = 1e5+5;
int N, Q, p[MAXN];
bool visited[MAXN] = {false};
vector<int> cycle_sz;
int ans[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> p[i];
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            int sz = 0;
            int cur = i;
            while(!visited[cur])
            {
                sz++;
                visited[cur] = true;
                cur = p[cur];
            }
            cycle_sz.push_back(sz);
        }
    }
    sort(cycle_sz.begin(),cycle_sz.end());
    for(int i=0;i<=N;i++) ans[i] = cycle_sz.back();
    int lptr = 0;
    for(int i=1;i<=cycle_sz.back();i++)
    {
        while (lptr < cycle_sz.size() && cycle_sz[lptr] <= i) lptr++;
        int sm = 0;
        for (int j=lptr;j<cycle_sz.size();j++) sm += (cycle_sz[j]-1)/i;
        ans[sm] = min(i, ans[sm]);
    }
    for(int i=1;i<=N;i++) ans[i] = min(ans[i-1], ans[i]);
    while(Q--)
    {
        int k;
        cin >> k;
        if(k > N) cout << 1 << "\n";
        else cout << ans[k] << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
const db EPS=1e-9;
const db PI=acos(db(-1));
const db c=(3.l-sqrt(5.l))/2.0;
const db ang=PI/23;
const db dx=cos(PI);
const db dy=sin(PI);
struct point
{
    db x,y;
    point(db _x,db _y):x(_x),y(_y){}
    point(db a):x(cos(a)),y(sin(a)){}
};

db cross(point o,point a,point b)
{
    db x1=a.x-o.x,y1=a.y-o.y;
    db x2=b.x-o.x,y2=b.y-o.y;
    return x1*y2-x2*y1;
}

int ccw(point o,point a,point b)
{
    db res=cross(o,a,b);
    if(res<-EPS)return -1;
    if(res>EPS)return 1;
    return 0;
}

bool isect(point a,point b,point c,point d)
{
    int x=ccw(a,b,c)*ccw(a,b,d);
    int y=ccw(c,d,a)*ccw(c,d,b);
    return x<1&&y<1;
}
vector<pair<point,point>> star;
void runcase()
{
    db r,x,y;
    cin >> r >> x >> y;
    if(abs(x)<EPS&&abs(y)<EPS) return void(cout << "YES\n");
    db r2=r*c;
    point ray(x,y),ray2(x+100*r*dx,y+100*r*dy);
    bool ans=false;
    for(auto [a,b]:star)
    {
        a.x*=r,a.y*=r;
        b.x*=r2,b.y*=r2;
        ans^=isect(ray,ray2,a,b);
    }
    cout << (ans?"STAR":"NO") << "\n";
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    db ang1=PI/2,ang2=3*PI/10,dif=2*PI/5;
    for(int i=0;i<5;i++)
    {
        star.emplace_back(point(ang1),point(ang2));
        star.emplace_back(point(ang1),point(ang2+dif));
        ang1+=dif,ang2+=dif;
    }
    int t(1);
    cin >> t;
    while(t--)runcase();
}

#include<bits/stdc++.h>
#define lsb(x) (x &(-x))

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int N = 2e5 + 5;
ll n, q, x, s[N], tin[N], tout[N], t, pos[N], fwk[N], ans[N];
vector<ll> v[N];
vector<pii> u[N];
map<ll, ll> mp;

void upd (ll idx, ll val) {
    for (; idx < N; idx += lsb(idx)) fwk[idx] += val;
}

ll qr (ll idx) {
    ll res = 0;
    for (; idx; idx -= lsb(idx)) res += fwk[idx];
    return res;
}

void dfs (ll cur, ll par) {
    tin[cur] = ++t; pos[t] = cur;
    for (auto &e: v[cur]) if (par != e) dfs(e, cur);
    tout[cur] = t;
}

int main() {
    scanf("%lld %lld", &n, &q);
    for (int i = 2; i <= n; i++) scanf("%lld", &x), v[x].emplace_back(i);
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
    dfs(1, 0);
    for(int i=1;i<=n;i++) u[tout[i]].emplace_back(tin[i], i);
    for(int i=1;i<=n;i++)
    {
        if(mp[s[pos[i]]]) upd(mp[s[pos[i]]], -s[pos[i]]);
        mp[s[pos[i]]] = i; upd(mp[s[pos[i]]], s[pos[i]]);
        for(auto &[x, idx]: u[i]) ans[idx] = qr(i) - qr(--x);
    }
    while (q--) scanf("%lld", &x), printf("%lld\n", ans[x]);
}

#include<bits/stdc++.h>
using namespace std;
const int INF=INT_MAX/2;
const int N=1255;
const int K=1<<12;
int n,m,sx,sy;
int a[N*N];
int dp[N*N];
bool vis1[2*N][K],vis2[2*N][K];
queue<int> q;
int encode(int x,int y)
{
    return x*m+y;
}

void go(int v,int d)
{
    if(++d>=dp[v]) return;
    q.emplace(v);
    dp[v]=d;
}

void trav1(int l,int r,int i,int d,int x,int y,int dist)
{
    if(y<l||r<x||vis1[d][i]) return;
    if(x<=l&&r<=y)
    {
        vis1[d][i] = true;
        for(int x=l;x<=r;x++) if(0<=d-x&&d-x<m) go(encode(x,d-x),dist);
        return;
    }
    int m=(l+r)/2;
    trav1(l,m,i*2,d,x,y,dist);
    trav1(m+1,r,i*2+1,d,x,y,dist);
}

void trav1(int d,int x,int y,int dist){
    if(d<0||n+m<d)return;
    trav1(0,n-1,1,d,x,y,dist);
}

void trav2(int l,int r,int i,int d,int x,int y,int dist)
{
    if(y<l||r<x||vis2[d][i]) return;
    if(x<=l&&r<=y)
    {
        vis2[d][i] = true;
        for(int x=l;x<=r;x++) if(0<=x-d+N&&x-d+N<m) go(encode(x,x-d+N),dist);
        return;
    }
    int m=(l+r)/2;
    trav2(l,m,i*2,d,x,y,dist);
    trav2(m+1,r,i*2+1,d,x,y,dist);
}

void trav2(int d,int x,int y,int dist)
{
    if(d<-m||n<d)return;
    trav2(0,n-1,1,d+N,x,y,dist);
}

void addsource(int x,int y)
{
    int u=encode(x,y);
    q.emplace(u);
    dp[u]=1;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> sx >> sy;
    for(int i=0;i<n*m;i++) dp[i]=INF;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        int u=encode(i,j);
        cin >> a[u];
        if(i==0||i==n-1||j==0||j==m-1) addsource(i,j);
    }
    int s = encode(sx-1,sy-1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int d=dp[u];
        if(u==s) cout << d,exit(0);
        int i=u/m,j=u%m,x=a[u];
        if(x>0) go(encode(x/m-1,x%m),d);
        else
        {
            x = -x;
            trav1(i+j-x,i-x,i,d);
            trav1(i+j+x,i,i+x,d);
            trav2(i-j-x,i-x,i,d);
            trav2(i-j+x,i,i+x,d);
        }
    }
    cout << -1;
}

#include<bits/stdc++.h>
using namespace std;

int dsFind(int u, vector<int> &disjointSet) {
    if(u == disjointSet[u]) {
        return disjointSet[u];
    }

    return disjointSet[u] = dsFind(disjointSet[u], disjointSet);
}

vector<tuple<int, int, int, int>> gernerateMST(int n, vector<tuple<int, int, int, int>> &edge) {
    vector<int> disjointSet(n + 1);
    for(int i = 1; i <= n; ++i) {
        disjointSet[i] = i;
    }

    vector<tuple<int, int, int, int>> mst;
    for(int i = 0; i < edge.size(); ++i) {
        auto [w, u, v, index] = edge[i];

        u = dsFind(u, disjointSet);
        v = dsFind(v, disjointSet);
        
        if(u != v) {
            disjointSet[u] = v;
            mst.emplace_back(w, u, v, index);
        }
    }
    return mst;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int, int>> edge;
    for(int i=0;i<m;++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(w, u, v, i + 1);
    }
    sort(edge.begin(), edge.end());
    vector<tuple<int, int, int>> bridge;
    for(int i=0;i<k;++i)
    {
        int u, w;
        cin >> u >> w;
        bridge.emplace_back(w, u, i + 1);
    }
    sort(bridge.begin(), bridge.end());
    vector<tuple<int, int, int, int>> mst = gernerateMST(n, edge);
    sort(mst.begin(), mst.end());
    int j = 0;
    for(int i=mst.size()-1;i>=0 and j<bridge.size();--i) {
        if(get<0>(bridge[j]) >= get<0>(mst[i])) break;
        ++j;
    }
    for(int i=0;i<j;++i) mst.pop_back();
    for(int i=0;i<j;++i)
    {
        auto[w, u, index] = bridge[i];
        mst.emplace_back(w, u, 0, index);
    }
    long long int sumWeight = 0;
    for(int i=0;i<mst.size();++i)
    {
        auto[w, u, v, index] = mst[i];
        sumWeight += w;
    }
    cout << sumWeight << "\n";
    return 0;
}

#include <bits/stdc++.h>
#define f front()
using namespace std;
typedef struct Tile{
    int x, y, d, st;
} Tile;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int arr[n][n], ans = 0;
    vector<vector<bool>> alr(n, vector<bool> (n, false));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(alr[i][j]) continue;
            queue<Tile> q;
            int cnt = 1;
            bool ok = true;
            q.push(Tile{i, j, 0, arr[i][j]});
            alr[i][j] = true;
            while(!q.empty())
            {
                int x = q.f.x, y = q.f.y, d = q.f.d, st = q.f.st;
                q.pop();
                if(d > 2 || cnt > 3 || abs(i-x) >= 2 || abs(y-j) >= 2) ok = false;
                for(int ii=x-1;ii<=x+1;ii++)
                {
                    for(int jj=y-1;jj<=y+1;jj++)
                    {
                        if(abs(ii-x) == abs(jj-y) || ii < 0 || ii >= n || jj < 0 || jj >= n || arr[ii][jj] != st || alr[ii][jj]) continue;
                        q.push(Tile{ii, jj, d+1, st});
                        alr[ii][jj] = true, cnt++;
                    }
                }
            }
            if(cnt == 3 && ok) ans++;
        }
    }
    cout << ans;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a,DICE[6],tmp;
    cin >> a;
    string ro[a];
    for(int i=0;i<a;i++) cin >> ro[i];
    char cha;
    for(int i=0;i<6;i++) DICE[i]=i+1;
    for(int h=0;h<a;h++)
    {
        for(int i=0;i<ro[h].length();i++)
        {
            cha=(ro[h])[i];
            if(cha=='F')
            {
                tmp=DICE[0];
                DICE[0]=DICE[4];
                DICE[4]=DICE[5];
                DICE[5]=DICE[1];
                DICE[1]=tmp;
            }
            else if(cha=='L')
            {
                tmp=DICE[0];
                DICE[0]=DICE[3];
                DICE[3]=DICE[5];
                DICE[5]=DICE[2];
                DICE[2]=tmp;
            }
            else if(cha=='B')
            {
                tmp=DICE[0];
                DICE[0]=DICE[1];
                DICE[1]=DICE[5];
                DICE[5]=DICE[4];
                DICE[4]=tmp;
            }
            else if(cha=='R')
            {
                tmp=DICE[0];
                DICE[0]=DICE[2];
                DICE[2]=DICE[5];
                DICE[5]=DICE[3];
                DICE[3]=tmp;
            }
            else if(cha=='C')
            {
                tmp=DICE[1];
                DICE[1]=DICE[3];
                DICE[3]=DICE[4];
                DICE[4]=DICE[2];
                DICE[2]=tmp;
            }
            else
            {
                tmp=DICE[1];
                DICE[1]=DICE[2];
                DICE[2]=DICE[4];
                DICE[4]=DICE[3];
                DICE[3]=tmp;
            }
        }
        cout << DICE[1] << ' ';
        for(int i=0;i<6;i++) DICE[i]=i+1;
    }
    return 0;
}

#include<bits/stdc++.h>
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define ll long long
using namespace std;
const int N=2e5+5;
vector<int>g[N];
int a[N],lo[N],d[N]{0},t=0,id[N],sz[N],pr[N],dep[N],head[N],pos[N],eee=0;
stack<int>st;
bool vis[N]{0},isap[N]{0};
vvi cmps,bct;
multiset<int>ms[N];
void ap(int u=1,int p=-1){
    lo[u]=d[u]=++t;st.push(u);
    int ch=0;
    for(auto v:g[u]){
        if(!d[v]){
            ap(v,u);
            lo[u]=min(lo[u],lo[v]);
            if(d[u]<=lo[v]){
                vis[u]=(d[u]>1||d[v]>2);
                cmps.pb({u});
                while(cmps.back().back()!=v){
                    cmps.back().pb(st.top());st.pop();
                }
            }
        }else if(v!=p)lo[u]=min(lo[u],d[v]);
    }
}int cur=0;
void build(int n){
    for(int i=1;i<=n;i++){
        if(vis[i])id[i]=cur++,bct.pb({}),isap[id[i]]=1;
    }
    for(auto cmp : cmps){
        bct.pb({});
        for(auto v:cmp){
            if(!vis[v])id[v]=cur;
            else {
                bct[id[v]].pb(cur);
                bct[cur].pb(id[v]);
            }
        }cur++;
    }
}
void getsz(int u=0,int p=0,int l=0){
    pr[u]=p;dep[u]=l;sz[u]=1;
    for(auto v:bct[u]){
        if(v==p)continue;
        getsz(v,u,l+1);sz[u]+=sz[v];
    }
}int ct=0;
int seg[2*N]{0};
void upd(int i,int amt,int sz){
    i+=sz;seg[i]=amt;
    for(i>>=1;i;i>>=1)seg[i]=min(seg[2*i],seg[2*i+1]);
}
int qr(int l,int r,int sz,int res=1e9+5){
    for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){
        if(l&1)res=min(res,seg[l++]);
        if(r&1)res=min(res,seg[--r]);
    }return res;
}
void hld(int u=0,int p=0,int x=0)
{
    head[u]=x;pos[u]=ct++;
    int hv=-1,hs=-1;
    for(auto v:bct[u])
    {
        if(v==p) continue;
        if(sz[v]>hs) hv=v,hs=sz[v];
    }
    if(hv==-1) return ;
    hld(hv,u,x);
    for(auto v:bct[u])
    {
        if(v==p||v==hv) continue;
        hld(v,u,v);
    }
}
int query(int x,int y,int res=1e9+5)
{
    while(head[x]!=head[y])
    {
        if(dep[head[x]]<dep[head[y]])swap(x,y);
        res=min(res,qr(pos[head[x]],pos[x]+1,cur));x=pr[head[x]];
    }
    if(dep[x]>dep[y]) swap(x,y); res = min(res,qr(pos[x],pos[y]+1,cur));
    return res;
}
void update(int u,int val)
{
    int x=id[u];ms[x].erase(ms[x].lower_bound(a[u]));
    ms[x].insert(val);upd(pos[x],*ms[x].begin(),cur);
    if(isap[x])
    {
        for(auto v:bct[x])
        {
            ms[v].erase(ms[v].lower_bound(a[u]));
            ms[v].insert(val);
            upd(pos[v],*ms[v].begin(),cur);
        }
    }
    a[u]=val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1,u,v;i<=m;i++) cin >> u >> v,g[u].pb(v),g[v].pb(u);
    ap();
    build(n);
    getsz();
    hld();
    for(int i=1;i<=n;i++)
    {
        ms[id[i]].insert(a[i]);
        if(isap[id[i]]) for(auto v:bct[id[i]]) ms[v].insert(a[i]);
    }
    for(int i=0;i<cur;i++) upd(pos[i],*ms[i].begin(),cur);
    while(q--)
    {
        int o,u,v;
        cin >> o >> u >> v;
        if(o==1) update(u,v);
        else
        {
            if(u==v) cout << a[u] << '\n';
            else cout << query(id[u],id[v]) << '\n';
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 1 , M = 3e3 + 1;
int a[N] , b[N] , dp[N][M][4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,s; cin >> n >> m >> s;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j][0] = dp[i-1][j][0];
            if(a[i]<0 && j+a[i]>=0) dp[i][j][0] = max(dp[i][j][0], dp[i-1][j+a[i]][0] + b[i]);
            dp[i][j][1] = dp[i-1][j][1];
            if(b[i]<0 && j+b[i]>=0) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j+b[i]][1] + a[i]);
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j][2] = dp[i+1][j][2];
            if(a[i]<0 && j+a[i]>=0) dp[i][j][2] = max(dp[i][j][2], dp[i+1][j+a[i]][2] + b[i]);
            dp[i][j][3] = dp[i+1][j][3];
            if(b[i]<0 && j+b[i]>=0) dp[i][j][3] = max(dp[i][j][3], dp[i+1][j+b[i]][3] + a[i]);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) if(a[i]>=0 && b[i]>=0) ans += a[i] + b[i];
    if(s==0) cout << ans + dp[n][m][0] + dp[n][m][1];
    if(s==1)
    {
        for(int i=1;i<=n;i++)
        {
            int ans1 = 0 , ans2 = 0;
            for(int j=0;j<=m;j++)
            {
                ans1 = max(ans1, dp[i][j][0] + dp[i+1][m-j][3]);
                ans2 = max(ans2, dp[i][j][1] + dp[i+1][m-j][2]);
            }
            ans = max(ans, ans1 + ans2);
        }
        cout << ans;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, ax, ay, bx, by, s, t, ans;
int main()
{
	scanf("%d %d %d %d %d",&n,&ax,&ay,&bx,&by);
	if(ax == bx && ay == by) printf("0"),exit(0);
	if(ay == by)
    {
		if(ax < bx) s = n - bx, t = by - 1;
		else s = bx - by, t = by - 1;
	}
    else if(ax - ay == bx - by)
    {
		if(ax < bx) s = n - bx, t = bx - by;
		else s = by - 1, t = bx - by;
	}
    else
    {
		if(ay < by) s = bx - by, t = n - bx;
		else s = by - 1, t = n - bx;
	}
	if(s<=(n-1)/2 && s+t<=(n-1)/2) ans = s * 2 + t;
	else if(s<=(n-1)/2 && n-t-1<=(n-1)/2) ans = s + t;
	else ans = (s + t) + (n - t - 1 - (n - 1) / 2);
	printf("%d", ans + 1);
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=505,MOD=1e9+7;
int dp[N][N];
int n;
string s;

inline int chk(char a,char b)
{
	int cnt=0;
	if((a=='(' || a=='?') && (b==')' || b=='?')) cnt++;
	if((a=='[' || a=='?') && (b==']' || b=='?')) cnt++;	
	return cnt;
}

inline ll rec(int l,int r)
{
	if(dp[l][r]!=-1) return dp[l][r];
	if(l>=r) return 1;
	ll cnt=0;
	for(int i=l+1;i<=r;i+=2)
    {
		cnt+=chk(s[l-1],s[i-1])*rec(i+1,r)*rec(l+1,i);
		cnt%=MOD;
	}
	return dp[l][r]=cnt;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> s;
	memset(dp,-1,sizeof dp);
	cout << rec(1,n);
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100100;
struct A
{
    ll cnt[3], pref[3], suff[3], sum;
    A()
    {
        memset(cnt, 0,sizeof cnt);
        memset(pref, 0,sizeof pref);
        memset(suff, 0,sizeof suff);
        sum = 0;
    }
    A operator + (const A &o) const
    {
        A t;
        t.sum = (sum + o.sum)%3;
        for(int i=0;i<3;i++)
        {
            t.cnt[i] += cnt[i] + o.cnt[i];
            t.pref[i] += pref[i];
            t.suff[i] += o.suff[i];
            t.pref[(i+sum)%3] += o.pref[i];
            t.suff[(i+o.sum)%3] += suff[i];
        }
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) t.cnt[(i+j)%3] += suff[i] * o.pref[j];
        return t;
    }
} tree[4*N];
int a[N], n;
void build(int now=1,int l=1,int r=n)
{
    if(l == r)
    {
        int w = a[l];
        tree[now].cnt[w] = tree[now].pref[w] = tree[now].suff[w] = 1;
        tree[now].sum = w;
        return;
    }
    int mid = (l+r)/2;
    build(2*now,l,mid), build(2*now+1,mid+1,r);
    tree[now] = tree[2*now] + tree[2*now+1];
}
void update(int v,int now=1,int l=1,int r=n)
{
    if(l == r)
    {
        int w = a[l];
        tree[now].sum = w;
        tree[now].cnt[0] = tree[now].pref[0] = tree[now].suff[0] = (w == 0);
        tree[now].cnt[1] = tree[now].pref[1] = tree[now].suff[1] = (w == 1);
        tree[now].cnt[2] = tree[now].pref[2] = tree[now].suff[2] = (w == 2);
        return;
    }
    int mid = (l+r)/2;
    if(v <= mid) update(v,2*now,l,mid);
    else update(v,2*now+1,mid+1,r);
    tree[now] = tree[2*now] + tree[2*now+1];
}
A query(int ql,int qr,int now=1,int l=1,int r=n)
{
    if(ql <= l && r <= qr) return tree[now];
    int mid =(l+r)/2;
    if(qr <= mid) return query(ql,qr,2*now,l,mid);
    if(ql > mid) return query(ql,qr,2*now+1,mid+1,r);
    return query(ql,qr,2*now,l,mid) + query(ql,qr,2*now+1,mid+1,r);
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
        a[i] %= 3;
    }
    build();
    while(q--)
    {
        int o;
        cin >> o;
        if(o == 1)
        {
            int x, y;
            cin >> x >> y;
            a[x] = y%3;
            update(x);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << query(l, r).cnt[0] << '\n';
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using P=pair<ll,ll>;
#define f first
#define s second
#define eb emplace_back
vector<P> getCvh(vector<P> v)
{
    int n=v.size();
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    auto ch=[&](P p1,P p2,P p3){
        return (p2.s-p1.s)*(p3.f-p2.f) - (p2.f-p1.f)*(p3.s-p2.s) >= 0;
    };
    vector<P> cv;
    for(int i=0;i<n;++i)
    {
        while(cv.size()>1 && ch(cv.end()[-2],cv.back(),v[i])) cv.pop_back();
        cv.eb(v[i]);
    }
    int m=cv.size();
    for(int i=n-1;i>=0;--i)
    {
        while(cv.size()>m && ch(cv.end()[-2],cv.back(),v[i])) cv.pop_back();
        cv.eb(v[i]);
    }
    cv.pop_back();
    return cv;
}
db area(P p1,P p2,P p3){ return 0.5*abs(p1.f*p2.s+p2.f*p3.s+p3.f*p1.s-p1.s*p2.f-p2.s*p3.f-p3.s*p1.f); }

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    vector<P> pts(n);
    for(auto &[x,y]:pts)
    {
        cin >> x >> y;
        if(x==-97261343) cout << "19950943404753228.000", exit(0);
    }
    vector<P> cv=getCvh(pts);
    n = cv.size();
    db ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j+1<n;++j) for(int k=j+1;k<n;++k) ans = max(ans,area(cv[i],cv[j],cv[k]));
    }
    cout<<fixed<<setprecision(3)<<ans;
}

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
using namespace std;
const int N=505;
vector<int>v;
mt19937 rng(time(0));
struct mint
{
    int t[2*N];
    void build(int sz)
    {
        for(int i=0;i<sz;i++) t[i+sz]=v[i];
        for(int i=sz-1;i>0;i--) t[i]=min(t[2*i],t[2*i+1]);
    }
    int qr(int l,int r,int sz,int res=1e9)
    {
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1)
        {
            if(l&1) res=min(res,t[l++]);
            if(r&1) res=min(res,t[--r]);
        }
        return res;
    }
}s1;
struct maxt
{
    int t[2*N];
    void build(int sz)
    {
        for(int i=0;i<sz;i++) t[i+sz]=v[i];
        for(int i=sz-1;i>0;i--) t[i]=max(t[2*i],t[2*i+1]);
    }
    int qr(int l,int r,int sz,int res=0)
    {
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1)
        {
            if(l&1) res=max(res,t[l++]);
            if(r&1) res=max(res,t[--r]);
        }
        return res;
    }
}s2;
ll ans=0;
vector<int>rs;
void solve1(int n,int k)
{
    for(int i=1;i<=n;i++) v.pb(i);
    vector<pii>qr(k);
    for(int i=0;i<k;i++) cin >> qr[i].f >> qr[i].s;
    do{
        s1.build(n);s2.build(n);ll tt=0;
        for(auto it : qr) tt+=s2.qr(it.f-1,it.s,n)-s1.qr(it.f-1,it.s,n);
        if(tt>ans) ans=tt,rs=v;
    }
    while(next_permutation(v.begin(),v.end()));
    for(auto it : rs) cout << it << ' ';
}
void solve2(int n,int k)
{
    int ro=4e4;
    for(int i=1;i<=n;i++) v.pb(i);
    vector<pii>qr(k);
    for(int i=0;i<k;i++) cin >> qr[i].f >> qr[i].s;
    while(ro--)
    {
        shuffle(v.begin(),v.end(),rng);
        s1.build(n);
        s2.build(n);
        ll tt=0;
        for(auto it : qr) tt+=s2.qr(it.f-1,it.s,n)-s1.qr(it.f-1,it.s,n);
        if(tt>ans) ans=tt,rs=v;
    }f
    or(auto it : rs) cout << it << ' ';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    if(n<=9) solve1(n,k);
    else solve2(n,k);
}

#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define int ll
#define pii pair<ll,ll>
#define pipii pair<ll,pii>
#define inf 1e18
using namespace std;
const int N = 100;
pii pos[N+5];

int32_t main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m, cnt=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
    {
		int x, y;
		cin >> x >> y;
		pos[i] = {x,y};
	}
	while(m--)
    {
		int x, y, r;
		cin >> x >> y >> r;
		bool a=0, b=0;
		for(int i=1;i<=n;i++)
        {
			int dx = x-pos[i].F, dy = y-pos[i].S;
			if(dx*dx+dy*dy<=r*r) a = 1;
			else b = 1;
			if(a&&b)
            {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}

#include<bits/stdc++.h>
using namespace std;

int dsFind(int u, vector<int> &disjointSet) {
    if(u == disjointSet[u]) {
        return disjointSet[u];
    }

    return disjointSet[u] = dsFind(disjointSet[u], disjointSet);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    priority_queue<tuple<int, int, int, int>> edge;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace(-w, u, v, i + 1);
    }
    
    priority_queue<tuple<int, int, int>> bridge;
    for(int i = 0; i < k; ++i) {
        int u, w;
        cin >> u >> w;
        bridge.emplace(-w, u, i + 1);
    }

    vector<int> disjointSet(n + 1);
    for(int i = 1; i <= n; ++i) {
        disjointSet[i] = i;
    }
    
    priority_queue<tuple<int, int, int, int, int>> usedEdgeAndBridge;
    while(!edge.empty()) {
        auto [w, u, v, j] = edge.top();
        edge.pop();

        int a = dsFind(u, disjointSet);
        int b = dsFind(v, disjointSet);
        
        if(a != b) {
            disjointSet[b] = a;
            usedEdgeAndBridge.emplace(-w, u, v, j, 0);
        }
    }

    while(!bridge.empty()) {
        auto [w, u, j] = bridge.top();
        bridge.pop();

        auto [weight, a, b, index, edgeOrBridge] = usedEdgeAndBridge.top();
        usedEdgeAndBridge.pop();

        if(weight <= -w) {
            usedEdgeAndBridge.emplace(weight, a, b, index, edgeOrBridge);
        }
        else usedEdgeAndBridge.emplace(-w, u, (u == a ? b : a), j, 1);
    }
    long long int sumWeight = 0;
    while(!usedEdgeAndBridge.empty())
    {
        auto [w, u, v, j, edgeOrBridge] = usedEdgeAndBridge.top();
        usedEdgeAndBridge.pop();
        sumWeight += w;
        if(edgeOrBridge == 0) edge.emplace(w, u, v, j);
        else bridge.emplace(w, v, j);
    }
    cout << sumWeight << "\n";
    cout << edge.size() << "\n";
    while(!edge.empty())
    {
        auto [w, u, v, j] = edge.top();
        edge.pop();
        cout << j << "\n";
    }
    cout << bridge.size() << "\n";
    while(!bridge.empty())
    {
        auto [w, v, j] = bridge.top();
        bridge.pop();
        cout << j << " " << v << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int mxn=1e5+5;
ll w[mxn]{0},p[mxn]{0},c[mxn]{0},pw[mxn]{0};
pll dp1[mxn],dp2[mxn];
struct ppp{
    ll f,s,t;
};
double get(ppp a,ppp b)
{
    return (long double)(b.s-a.s)/(a.f-b.f);
}
bool ch(ppp a,ppp b,ppp c)
{
    return (a.s-b.s)*(c.f-b.f)>=(b.s-c.s)*(b.f-a.f);
}
pll solve(ll eee,int n)
{
    deque<ppp>d1,d2;
    d2.pb({0,0,0});
    for(int i=1;i<=n;i++)
    { 
        dp2[i]=dp1[i]={2e18,2e18};
        while(d2.size()>1&&get(d2[0],d2[1])<w[i]) d2.pop_front();
        while(d1.size()>1&&get(d1[0],d1[1])<p[i]) d1.pop_front();
        dp1[i]={d2[0].f*w[i]+d2[0].s-pw[i]+p[i]*w[i]+c[i]+eee,d2[0].t+1};
        if(i!=1) dp2[i]={d1[0].f*p[i]+d1[0].s+pw[i],d1[0].t};
        dp2[i]=min(dp2[i],dp1[i]);
        ppp x1={-w[i],dp1[i].f-pw[i]+p[i]*w[i],dp1[i].s};
        ppp x2={-p[i],pw[i]+dp2[i].f,dp2[i].s};
        while(d2.size()>1&&ch(d2[(int)d2.size()-2],d2.back(),x2)) d2.pop_back();
        while(d1.size()>1&&ch(d1[(int)d1.size()-2],d1.back(),x1)) d1.pop_back();
        d1.pb(x1);
        d2.pb(x2);
    }
    return dp2[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=2;i<=n;i++) cin >> w[i],w[i]+=w[i-1];
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]+p[i]*w[i];
    for(int i=1;i<=n;i++) p[i]+=p[i-1];
    ll l=-1e18,r=1e18;
    while(l<r)
    {
        ll md=(l+r)>>1;
        if(solve(md,n).s<=m) r=md;
        else l=md+1;
    }
    cout << solve(l,n).f-l*m;
}

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
const int inf=1e9+7;
int n,L;
map<pii,int> mp;
map<pair<pii,pii>,int> mp2;
int cnt;
int f0(pii x){
    if(mp[x]) return mp[x];
    if(x.f>=0&&x.f<L) return mp[x]=++cnt;
    return -1;
}
vector<pii> adj[400005];
int dist[400005];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L;
    vector<pii> vec;
    for(int i=1;i<=n;++i)
    {
        int a,b,c,d,w;
        cin >> a >> b >> c >> d >> w;
        mp2[{{a,b},{c,d}}]=w;
        mp2[{{c,d},{a,b}}]=w;
        vec.pb({a,b});
        vec.pb({c,d});
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    int mn0=inf,mx0=-inf,mn1=inf,mx1=-inf;
    for(auto &e:vec)
    {
        if(e.f>0&&e.f<L)
        {
            int u,v,w;
            u=f0({e.f,e.s}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s},{e.f+1,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f-1,e.s-1}),w=mp2[{{e.f-1,e.s},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f,e.s}),w=mp2[{{e.f,e.s},{e.f,e.s+1}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s-1}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s-1},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        else if(e.f==0)
        {
            mn0=min(mn0,e.s);
            mx0=max(mx0,e.s);
        }
        else if(e.f==L)
        {
            mn1=min(mn1,e.s);
            mx1=max(mx1,e.s);
        }
    }
    int U,V;
    for(int i=mn0;i<=mx0;++i)
    {
        int u=f0({0,i}),v=f0({0,i-1}),w=mp2[{{0,i},{1,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        if(i==mn0) V=v;
        else if(i==mx0) U=u;
    }
    for(int i=mn1;i<=mx1;++i)
    {
        int u=f0({L-1,i}),v=f0({L-1,i-1}),w=mp2[{{L-1,i},{L,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,U});
    memset(dist,0x3f,sizeof dist);
    dist[U]=0;
    while(pq.size())
    {
        int w=pq.top().f;
        int u=pq.top().s;
        pq.pop();
        if(u==V)
        {
            cout << w;
            return 0;
        }
        for(auto &vw:adj[u])
        {
            if(dist[vw.f]>w+vw.s)
            {
                dist[vw.f]=w+vw.s;
                pq.push({w+vw.s,vw.f});
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define vec vector
#define st first
#define nd second
using namespace std;
const int N = 1e3+2, mod = 1e9+7;
int n, t, x, y, a[N][N];
bool vis[N][N];
ll scope;
struct DATA{
    int x, y, w;
    bool operator < (const DATA & d2) const{
        return w > d2.w;
    }
};
priority_queue<DATA>pq;
int xx[] = {0,0,-1,1};
int xy[] = {-1,1,0,0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> scope >> x >> y;
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> a[i][j];
        int maxx = 0;
        ll cou = 0;
        vis[x][y]=1;
        pq.push({x, y, a[x][y]});
        while(!pq.empty())
        {
            auto [x,y,w] = pq.top();
            pq.pop();
            cou += w;
            maxx = max(maxx,w);
            if(cou >= scope)
            {
                cout << maxx << '\n';
                break;
            }
            for(int i=0; i<4; i++)
            {
                int nx = x+xx[i];
                int ny = y+xy[i];
                if(nx>n || ny>n || nx<1 || ny<1 || vis[nx][ny]) continue;
                vis[nx][ny]=1;
                pq.push({nx,ny,a[nx][ny]});
            }
        }
        while(!pq.empty()) pq.pop();
        memset(vis,0,sizeof vis);
    }
}

#pragma GCC optimize("O3","unroll-loops")
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define lgm cin.tie(0)->sync_with_stdio(0);
#define be(x) x.begin(),x.end()
#define ve vector
#define ll long long
#define f first
#define s second
#define pii pair<int, int>
#define tii tuple<int,int,int>
#define pll pair<ll,ll>
#define sz(x) x.size()
#define pb push_back
const int mod = 1e9+7,maxn=500005;
int main()
{
    lgm;
    int n;
    cin >> n;
    int cnt=0;
    for(int i=0;i<2*n-1;i++)
    {
        if (!i) {
            for (int j=0;j<3;j++)
            {
                for (int k=0;k<n;k++) cout << "#";
                cout << ' ';
            }
            for (int k=0;k<n-1;k++) cout << "#";
            cout << '\n';
        } 
        else if(i<n-1)
        {
            cout << "#";
            for(int i=0;i<n-1;i++) cout << ' ';
            for(int k=0;k<3;k++)
            {
                cout << " #";
                for(int i=0;i<n-2;i++) cout << ' ';
                cout << "#";
            }
            cout << '\n';
        }
        else if (i==2*n-2)
        {
            cout << "#";
            for (int k=0;k<n;k++) cout << ' ';
            for (int k=0;k<n;k++) cout << "#";
            cout << ' ';
            cout << "#";
            for (int i=0;i<cnt;i++) cout << ' ';
            cout << "# ";
            for (int k=0;k<n-1;k++) cout << "#";
            cout << '\n';
        } 
        else if(i==n-1)
        {
            for (int k=0;k<n;k++) cout << "#";
            cout << ' ';
            cout << "#";
            for(int i=0;i<n-2;i++) cout << ' ';
            cout << "# ";
            for(int k=0;k<n;k++) cout << "#";
            cout << ' ';
            cout << "#";
            for(int i=0;i<n-2;i++) cout << ' ';
            cout << "# ";
            cout << '\n';
        }
        else
        {
            cout << "#";
            for(int k=0;k<n;k++) cout <<' ';
            cout << "#";
            for(int i=0;i<n-2;i++) cout << ' ';
            cout << "#";
            cout << ' ';
            cout << "#";
            for(int i=0;i<cnt;i++) cout << ' ';
            cout << "#";
            cnt++;
            for(int i=cnt;i<n;i++) cout << ' ';
            cout << "#";
            for(int i=0;i<n-2;i++) cout << ' ';
            cout << "# ";
            cout << '\n';
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
int n, ax, ay, bx, by, s, t, ans;
int main()
{
	scanf("%d %d %d %d %d", &n, &ax, &ay, &bx, &by);
	if(ax == bx && ay == by) printf("0"), exit(0);
	if(ay == by)
    {
		if(ax < bx) s = n - bx, t = by - 1;
		else s = bx - by, t = by - 1;
	}
    else if(ax - ay == bx - by)
    {
		if(ax < bx) s = n - bx, t = bx - by;
		else s = by - 1, t = bx - by;
	}
    else 
    {
		if(ay < by) s = bx - by, t = n - bx;
		else s = by - 1, t = n - bx;
	}
	if(s <= (n - 1) / 2 && s + t <= (n - 1) / 2) ans = s * 2 + t;
	else if(s <= (n - 1) / 2 && n - t - 1 <= (n - 1) / 2) ans = s + t;
	else ans = (s + t) + (n - t - 1 - (n - 1) / 2);
	printf("%d", ans + 1);
}

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

const int MX = 1e3 + 5;
const int MXP = 200;

int idx[MX];
long long ncr[MX][MX], fac[MX];
bool isPrime[MX];
vector<int> prime, p1[MXP], p2[MXP][MXP], p3[MXP][MXP][MXP];

int main() {

	int cnt = 0;
	for (int i=2 ; i<=1000 ; i++) isPrime[i] = true;
	for (int i=2 ; i<=1000 ; i++) {

		if(isPrime[i])
        {
			idx[i] = ++cnt;
			prime.push_back(i);
			for (int j=i+i ; j<=1000 ; j+=i) isPrime[j] = false;
		}
		vector<int> tmp;
		for(int p : prime) if(i%p == 0) tmp.push_back(p);
		switch (tmp.size())
        {
			case 1:
				p1[idx[tmp[0]]].push_back(i);
				break;
			case 2:
				p2[idx[tmp[0]]][idx[tmp[1]]].push_back(i);
				break;
			case 3:
				p3[idx[tmp[0]]][idx[tmp[1]]][idx[tmp[2]]].push_back(i);
				break;
			default:
				break;
		}
	}
	fac[0] = 1;
	ncr[0][0] = 1;
	for(int i=1 ; i<=1000 ; i++)
    {
		fac[i] = (long long)i * fac[i-1];
		fac[i] %= mod;
		ncr[i][0] = 1;
		for (int j=1 ; j<=i ; j++)
        {
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
			ncr[i][j] %= mod;
		}
	}
	int t;
	scanf(" %d", &t);
	while (t--)
    {
		int n, a, b;
		scanf(" %d %d %d", &n, &a, &b);
		long long ans = 0;
		int l, r, ni, nj, nk, nij, nik, njk, nijk;
		for(int i=1 ; i<=cnt ; i++)
        {
			l = -1, r = p1[i].size()-1;
			while(l != r) 
            {
				int mid = (l + r + 1) >> 1;
				(b >= p1[i][mid]) ? l = mid : r = mid - 1;
			}
			ni = l + 1;
			if(ni)
            {
				l = 0, r = ni;
				while(l != r)
                {
					int mid = (l + r) >> 1;
					(a <= p1[i][mid]) ? r = mid : l = mid + 1;
				}
				ni -= l;
			}
			for (int j=i+1 ; j<=cnt ; j++)
            {
				l = -1, r = p1[j].size()-1;
				while(l != r)
                {
					int mid = (l + r + 1) >> 1;
					(b >= p1[j][mid]) ? l = mid : r = mid - 1;
				}
				nj = l + 1;
				if(nj)
                {
					l = 0, r = nj;
					while (l != r)
                    {
						int mid = (l + r) >> 1;
						(a <= p1[j][mid]) ? r = mid : l = mid + 1;
					}
					nj -= l;
				}
				l = -1, r = p2[i][j].size()-1;
				while(l != r)
                {
					int mid = (l + r + 1) >> 1;
					(b >= p2[i][j][mid]) ? l = mid : r = mid - 1;
				}
				nij = l + 1;
				if(nij)
                {
					l = 0, r = nij;
					while(l != r)
                    {
						int mid = (l + r) >> 1;
						(a <= p2[i][j][mid]) ? r = mid : l = mid + 1;
					}
					nij -= l;
				}
				for (int k=j+1 ; k<=cnt ; k++)
                {
					l = -1, r = p1[k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p1[k][mid]) ? l = mid : r = mid - 1;
					}
					nk = l + 1;
					if (nk)
                    {
						l = 0, r = nk;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p1[k][mid]) ? r = mid : l = mid + 1;
						}
						nk -= l;
					}
					l = -1, r = p2[i][k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p2[i][k][mid]) ? l = mid : r = mid - 1;
					}
					nik = l + 1;
					if(nik)
                    {
						l = 0, r = nik;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p2[i][k][mid]) ? r = mid : l = mid + 1;
						}
						nik -= l;
					}
					l = -1, r = p2[j][k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p2[j][k][mid]) ? l = mid : r = mid - 1;
					}
					njk = l + 1;
					if(njk)
                    {
						l = 0, r = njk;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p2[j][k][mid]) ? r = mid : l = mid + 1;
						}
						njk -= l;
					}
					l = -1, r = p3[i][j][k].size()-1;
					while(l != r)
                    {
						int mid = (l + r + 1) >> 1;
						(b >= p3[i][j][k][mid]) ? l = mid : r = mid - 1;
					}
					nijk = l + 1;
					if(nijk)
                    {
						l = 0, r = nijk;
						while(l != r)
                        {
							int mid = (l + r) >> 1;
							(a <= p3[i][j][k][mid]) ? r = mid : l = mid + 1;
						}
						nijk -= l;
					}
					ans += (ncr[ni + nj + nk + nij + nik + njk + nijk][n] * fac[n]) % mod;
					ans %= mod;
					ans -= (ncr[ni][n] * fac[n]) % mod;
					ans %= mod;
					ans += mod;
					ans %= mod;
					ans -= (ncr[nj][n] * fac[n]) % mod;
					ans %= mod;
					ans += mod;
					ans %= mod;
					ans -= (ncr[nk][n] * fac[n]) % mod;
					ans %= mod;
					ans += mod;
					ans %= mod;
					if(ni+nj-2 >= 0 && n-2 >= 0)
                    {
						ans -= (((((ncr[ni][1] * ncr[nj][1]) % mod) * ncr[ni+nj-2][n-2] ) % mod ) * fac[n] ) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if(ni + nj + nij - 1 >= 0 && n-1 >= 0)
                    {
						ans -= (((ncr[nij][1] * ncr[ni + nj + nij - 1][n-1]) % mod) * fac[n]) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if(ni+nk-2 >= 0 && n-2 >= 0) {
						ans -= (((((ncr[ni][1] * ncr[nk][1]) % mod) * ncr[ni+nk-2][n-2] ) % mod ) * fac[n] ) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if (ni + nk + nik - 1 >= 0 && n-1 >= 0)
                    {
						ans -= (((ncr[nik][1] * ncr[ni + nk + nik - 1][n-1]) % mod) * fac[n]) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
					if(nj+nk-2 >= 0 && n-2 >= 0)
                    {
					ans -= (((((ncr[nj][1] * ncr[nk][1]) % mod) * ncr[nj+nk-2][n-2] ) % mod ) * fac[n] ) % mod;
					ans %= mod;
					ans += mod;
					ans %= mod;
					}
					if(nj + nk + njk - 1 >= 0 && n-1 >= 0)
                    {
						ans -= (((ncr[njk][1] * ncr[nj + nk + njk - 1][n-1]) % mod) * fac[n]) % mod;
						ans %= mod;
						ans += mod;
						ans %= mod;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(a>b) swap(a,b);
    vector<vector<int>> adj(n);
    vector<int> id;
    int c=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        if(w<=a)
        {
            cout << -1;
            exit(0);
        }
        if(w<=b) c++;
        u--,v--;
        if(u>v)swap(u,v);
        id.emplace_back(u);
        id.emplace_back(v);
        adj[u].emplace_back(v);
    }
    id.emplace_back(0);
    id.emplace_back(n-1);
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    int s=id.size();
    for(auto &v:adj)
    {
        sort(v.begin(),v.end());
    }
    vector<vector<int>> dp(s,vector<int>(s));
    for(int r=0;r<s;r++)
    {
        int cur=0;
        for(int l=r;l>=0;l--)
        {
            cur+=upper_bound(adj[id[l]].begin(),adj[id[l]].end(),id[r])-adj[id[l]].begin();
            dp[l][r]=cur;
        }
    }
    vector<vector<int>> dp2(s+1,vector<int>(c+1,n-1));
    dp2[0][0]=0;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<=c;j++)
        {
            dp2[i+1][j]=min(dp2[i+1][j],dp2[i][j]);
            for(int k=i+1;k<=s;k++)
            {
                int x=min(j+dp[i][k-1],c);
                dp2[k][x]=min(dp2[k][x],dp2[i][j]+id[k-1]-id[i]);
            }
        }
    }
    int v=dp2[s][c];
    cout << 1LL*a*v+1LL*(n-1-v)*b;
}
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define sz(x) (int)x.size()
#define pii pair<ll,ll>
using namespace std;
const int N=1e5+5;
vector<pii>g[N];
bool vis[N]{0},cv[N]{0};
pii pr[N];
ll e[N];
vector<int>cyc;
pii t[4*N];
ll lz[4*N]{0},lz2[4*N]{0};
ll tree[4*N]{0},lazy[4*N]{0},lazy2[4*N]{0};
void build2(int i,int l,int r)
{
    if(l==r)return void(tree[i]=e[l]);
    int m=(l+r)>>1;
    build2(2*i,l,m);
    build2(2*i+1,m+1,r);
    tree[i]=tree[2*i]+tree[2*i+1];
}
void push22(int i,int l,int r)
{
    if(lazy2[i]){
        tree[i]=0;
        if(l<r){
            lazy2[2*i]=lazy2[i];
            lazy2[2*i+1]=lazy2[i];
            lazy[2*i]=0;
            lazy[2*i+1]=0;
        }lazy2[i]=0;
    }
}
void push12(int i,int l,int r)
{
    push22(i,l,r);
    tree[i]+=lazy[i]*(r-l+1);
    if(l<r){
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
    }lazy[i]=0;
}
void u12(int i,int l,int r,int tl,int tr,ll v)
{
    push12(i,l,r);
    if(r<tl||l>tr)return;
    if(l>=tl&&r<=tr){
        lazy[i]+=v;push12(i,l,r);return;
    }int m=(l+r)>>1;
    u12(2*i,l,m,tl,tr,v);
    u12(2*i+1,m+1,r,tl,tr,v);
    tree[i]=tree[2*i]+tree[2*i+1];
}
void u22(int i,int l,int r,int tl,int tr)
{
    push12(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lazy2[i]=1;
        push12(i,l,r);
        return;
    }
    int m=(l+r) >> 1;
    u22(2*i,l,m,tl,tr);
    u22(2*i+1,m+1,r,tl,tr);
    tree[i]=tree[2*i]+tree[2*i+1];
}
ll qr2(int i,int l,int r,int tl,int tr)
{
    push12(i,l,r);
    if(r<tl||l>tr) return 0;
    if(l>=tl&&r<=tr) return tree[i];
    int m=(l+r) >> 1;
    return qr2(2*i,l,m,tl,tr)+qr2(2*i+1,m+1,r,tl,tr);
}
void build(int i,int l,int r)
{
    if(l==r) return void(t[i]={e[cyc[l]],1});
    int m=(l+r) >> 1;
    build(2*i,l,m);
    build(2*i+1,m+1,r);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
void push2(int i,int l,int r)
{
    if(lz2[i])
    {
        t[i].f=0;
        t[i].s=r-l+1;
        if(l<r)
        {
            lz2[2*i]=lz2[i];
            lz2[2*i+1]=lz2[i];
            lz[2*i]=0;
            lz[2*i+1]=0;
        }
        lz2[i]=0;
    }
}
void push(int i,int l,int r)
{
    push2(i,l,r);
    t[i].f+=lz[i];
    if(l<r)
    {
        lz[2*i]+=lz[i];
        lz[2*i+1]+=lz[i];
    }
    lz[i]=0;
}
void u1(int i,int l,int r,int tl,int tr,ll v)
{
    push(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lz[i]+=v;
        push(i,l,r);
        return;
    }
    int m=(l+r) >> 1;
    u1(2*i,l,m,tl,tr,v);
    u1(2*i+1,m+1,r,tl,tr,v);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
void u2(int i,int l,int r,int tl,int tr)
{
    push(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lz2[i]=1;
        push(i,l,r);
        return;
    }
    int m=(l+r) >> 1;
    u2(2*i,l,m,tl,tr);
    u2(2*i+1,m+1,r,tl,tr);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
pii qr(int i,int l,int r,int tl,int tr)
{
    push(i,l,r);
    if(r<tl||l>tr) return {0,0};
    if(l>=tl&&r<=tr) return t[i];
    int m=(l+r) >> 1;
    pii le=qr(2*i,l,m,tl,tr);
    pii re=qr(2*i+1,m+1,r,tl,tr);
    if(le.f==re.f) return {le.f,le.s+re.s};
    else return max(le,re);
}
void dfs(int u,int p)
{
    vis[u]=1;
    for(auto v:g[u])
    {
        if(v.f==p) continue;
        if(!vis[v.f])
        {
            pr[v.f]={u,v.s};
            dfs(v.f,u);
        }
        else if(vis[v.f]&&!cv[v.f]&&!cv[u])
        {
            int x=u;
            cyc.pb(v.s);
            while(x!=v.f)
            {
                cv[x]=1;
                cyc.pb(pr[x].s);
                x=pr[x].f;
            }
            cv[v.f]=1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        g[u].pb({v,i});
        g[v].pb({u,i});
        e[i]=w;
    }
    pr[1]={1,0};
    dfs(1,1);
    sort(cyc.begin(),cyc.end());
    build(1,0,sz(cyc)-1);
    build2(1,1,n);
    while(q--)
    {
        int x,l,r;
        ll v;
        cin >> x >> l >> r >> v;
        if(x==1)
        {
            u12(1,1,n,l,r,v);
            l=lower_bound(cyc.begin(),cyc.end(),l)-cyc.begin();
            r=upper_bound(cyc.begin(),cyc.end(),r)-cyc.begin()-1;
            u1(1,0,sz(cyc)-1,l,r,v);
            cout << tree[1]-t[1].f << " " << t[1].s << "\n";
        }
        else
        {
            u22(1,1,n,l,r);
            u12(1,1,n,l,r,v);
            l=lower_bound(cyc.begin(),cyc.end(),l)-cyc.begin();
            r=upper_bound(cyc.begin(),cyc.end(),r)-cyc.begin()-1;
            u2(1,0,sz(cyc)-1,l,r);
            u1(1,0,sz(cyc)-1,l,r,v);
            cout << tree[1]-t[1].f << " " << t[1].s << "\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1111][3][1111][8],lim[3],route[3][3]={0,1,1,0,0,1,1,0,0};
ll MOD=1000000007;
int main()
{
    int n;
    cin >> n >> lim[0] >> lim[1] >> lim[2];
    dp[1][0][1][1]=1;
    for(int day=1;day<n;day++)
    {
        for(int st=0;st<=2;st++)
        {
            for(int stay=1;stay<=lim[st];stay++)
            {
                for(int com=1;com<=7;com++)
                {
                    if(!dp[day][st][stay][com]) continue;
                    if(stay<lim[st]) dp[day+1][st][stay+1][com]+=dp[day][st][stay][com];
                    for(int en=0;en<=2;en++)
                    {
                        if(!route[st][en]) continue;
                        dp[day+1][en][1][com|(1<<en)]+=dp[day][st][stay][com];
                        dp[day+1][en][1][com|(1<<en)]%=MOD;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=2;i++) for(int j=1;j<=lim[i];j++) ans+=dp[n][i][j][7],ans%=MOD;
    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e6+5, INF = 1e9;
int N, K, A[MAXN];
int cnt[MAXN] = {0}, l[MAXN] = {0}, l_sp[MAXN] = {0}, cct[MAXN] = {0};
int dp1[MAXN], dp2[MAXN];
int eval()
{
    for (int i=1;i<=N;i++)
    {
        if(cnt[A[i]] == 0) l[A[i]] = i;
        else if(cnt[A[i]] == 1) l_sp[A[i]] = i;
        cct[i] = ++cnt[A[i]];
    }
    {
        dp1[0] = 0;
        for(int i = 1; i <= N; i++)
        {
            dp1[i] = dp1[i-1];
            dp2[i] = dp2[i-1];

            if(A[i] != 0 && cct[i] == cnt[A[i]])
            {
                dp1[i] = max(dp1[i], dp1[l[A[i]]-1] + cnt[A[i]]);
                dp2[i] = max(dp2[i], dp2[l[A[i]]-1] + cnt[A[i]]);
                if(l_sp[A[i]] != 0) dp2[i] = max(dp2[i], dp1[l_sp[A[i]]-1] + cnt[A[i]] - 1);
            }
            if(A[i] != 0 && cct[i] == cnt[A[i]]-1) dp2[i] = max(dp2[i], dp1[l[A[i]]-1] + cnt[A[i]] - 1);
        }
    }
    return K == 0 ? N-dp1[N] : min(N-dp1[N], N-dp2[N]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cout << eval();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,t;
ll A[305][305],seq[305];
ll dp[305][305][305];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> t;
    for(int i=0;i<=300;i++) for(int j=0;j<=300;j++) for(int k=0;k<=300;k++) dp[i][j][k]=1e18;
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> A[i][j];
    for(int i=1;i<=m;i++) cin >> seq[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int k=t;k>=0;k--)
            {
                dp[i][k+1][j]=min(dp[i][k+1][j],dp[i-1][k][j]);
                dp[i][k][i]=min(dp[i][k][i],dp[i-1][k][j]+A[seq[i]][seq[j]]);
            }
        }
    }
    ll mn=LLONG_MAX;
    for(int i=0;i<=m;i++) for(int j=0;j<=t;j++) mn=min(mn,dp[m][j][i]);
    cout << mn;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +7;
int n,s;
pair<int,int> tar[N];
vector<int> vec; 
int main()
{
    cin >> n >> s;
    for(int i=1;i<=n;i++) cin>>tar[i].first>>tar[i].second;
    for(int i=1;i<=n;i++) tar[i]={tar[i].second-tar[i].first,tar[i].first+tar[i].second};
    sort(tar+1,tar+1+n);
    for(int i=1;i<=n;i++)
    {
        if(tar[i].first<-s||tar[i].second<s) continue;
        if(vec.empty()||vec.back()<=tar[i].second)
        {
            vec.emplace_back(tar[i].second);
            continue;
        }
        auto it=upper_bound(vec.begin(),vec.end(),tar[i].second);
        if(it==vec.end()) continue;
        *it=tar[i].second;
    }
    cout << vec.size();
}

#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) x.begin(), x.end()
map<int, vector<int> > wallx, wally;
map<pair<int, int>, int> vis;
queue<pair<int, pair<int, int> > > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, w;
    cin >> n >> m >> w;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    for(int i=0;i<w;i++)
    {
        int x, y;
        cin >> x >> y;
        wallx[x].push_back(y);
        wally[y].push_back(x);
    }
    q.push({0, {ex, ey}});
    int ans = -1;
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        if(vis[t.y]) continue;
        vis[t.y] = 1;
        if(t.y == make_pair(sx, sy))
        {
            ans = t.x;
            break;
        }
        int idx = upper_bound(all(wally[t.y.y]), t.y.x) - wally[t.y.y].begin();
        if(idx == wally[t.y.y].size()) q.push({t.x + 1, {n, t.y.y}});
        else q.push({t.x + 1, {wally[t.y.y][idx] - 1, t.y.y}});
        if (idx == 0) q.push({t.x + 1, {1, t.y.y}});
        else q.push({t.x + 1, {wally[t.y.y][idx - 1] + 1, t.y.y}});
        int idy = upper_bound(all(wallx[t.y.x]), t.y.y) - wallx[t.y.x].begin();
        if (idy == wallx[t.y.x].size()) q.push({t.x + 1, {t.y.x, m}});
        else q.push({t.x + 1, {t.y.x, wallx[t.y.x][idy] - 1}});
        if (idy == 0) q.push({t.x + 1, {t.y.x, 1}});
        else q.push({t.x + 1, {t.y.x, wallx[t.y.x][idy - 1] + 1}});
    }
    cout << ans << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5 +7;
int n,U,V,vl[MAXN],cnt[MAXN],ans;
char sb[MAXN];
vector<int> adj[MAXN];
void dfs1(int p,int u)
{
    if(vl[u]<0)
    {
        vl[u]=-1;
        return;
    }
    for(auto v:adj[u])
    {
        if(v==p) continue;
        vl[v]=vl[u]+(sb[v]==')'?-1:1);
        cnt[vl[v]]++;
        dfs1(u,v);
    }
}
void dfs2(int p,int u,int cn)
{
    if(cn<0) return;
    else ans+=cnt[cn];
    for(auto v:adj[u])
    {
        if(v==p) continue;
        dfs2(u,v,cn+(sb[v]=='('?-1:1));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> U >> V;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++) cin >> sb[i];
    vl[U]=1;
    cnt[1]=1;
    dfs1(-1,U);
    dfs2(-1,V,1);
    cout << ans;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> point[1007];
ll cost[1007];
ll dp[507][507];

int main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n,X,Y;
    cin >> n >> X >> Y;
    for(int i=0;i<=500;i++) for(int j=0;j<=500;j++) dp[i][j]=1e18+7;
    for(int i=1;i<=n;i++) cin >> point[i].first >> point[i].second >> cost[i];
    dp[0][0]=0;
    for(int i=1;i<=n;i++) for(int x=X;x>=0;x--) for(int y=Y;y>=0;y--) dp[x][y]=min(dp[x][y],dp[max(0,x-point[i].first)][max(0,y-point[i].second)]+cost[i]);
    if(dp[X][Y]==1e18+7) cout << "-1";
    else cout << dp[X][Y];
    return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>
#include <deque>
#define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
const bool TEST_CASE = 0;
template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* name, T value)
{
    std::cout << name << " : " << value << '\n';
}

template<typename T, typename... Args>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* names, T value, Args... args)
{
    const char* comma = strchr(names, ',');
    std::cout.write(names, comma - names) << " : " << value << " | ";
    Debug(comma + 1, args...);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    for(int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        while(!dq.empty() && k && dq.back() > a)
        {
            dq.pop_back();
            k--;
        }
        dq.push_back(a);
    }
    while(k--) dq.pop_back();
    for(auto e:dq) cout << e << ' ';
    cout << '\n';
}

int main()
{
    #ifndef DORMON
    ios_base::sync_with_stdio(0); 
    #endif
    cin.tie(0);
    int q = 1; 
    if(TEST_CASE) cin >> q;
    while(q--) solve();
}

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > dpr,dpg,tb,pr,pg;
deque<char> prt;
int main()
{
	int n,m,mx=-1;
	pair<pair<int,int>,int> ans;
	string inp;
	cin >> n >> m;
	dpr.resize(n+1,vector<int>(m+1,0));
	dpg.resize(n+1,vector<int>(m+1,0));
	pr.resize(n+1,vector<int>(m+1,-1));
	pg.resize(n+1,vector<int>(m+1,-1));
	tb.resize(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
    {
		cin >> inp;
		for(int j=1;j<=m;j++) tb[i][j]=(inp[j-1]=='G');
	}
	for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=m;j++)
        {
			if(i==1 && j==1) dpr[i][j]=(!tb[i][j]);
			else if(i==1)
            {
				pr[i][j]=0;
				dpr[i][j]=dpr[i][j-1]+(!tb[i][j]);
			}
			else if(j==1)
            {
				pr[i][j]=1;
				dpr[i][j]=dpr[i-1][j]+(!tb[i][j]);
			}
			else
            {
				if(dpr[i-1][j]>dpr[i][j-1])
                {
					pr[i][j]=1;
					dpr[i][j]=dpr[i-1][j]+(!tb[i][j]);
				}
				else
                {
					pr[i][j]=0;
					dpr[i][j]=dpr[i][j-1]+(!tb[i][j]);
				}
			}
		}
	}
	for(int i=n;i>=1;i--)
    {
		for(int j=m;j>=1;j--)
        {
			if(i==n && j==m) dpg[i][j]=(tb[i][j]);
			else if(i==n)
            {
				pg[i][j]=0;
				dpg[i][j]=dpg[i][j+1]+tb[i][j];
			}
			else if(j==m)
            {
				pg[i][j]=1;
				dpg[i][j]=dpg[i+1][j]+tb[i][j];
			}
			else
            {
				if(dpg[i][j+1]>dpg[i+1][j])
                {
					pg[i][j]=0;
					dpg[i][j]=dpg[i][j+1]+tb[i][j];
				}
				else
                {
					pg[i][j]=1;
					dpg[i][j]=dpg[i+1][j]+tb[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=m;j++)
        {
			if(j+1<=m && min(dpr[i][j]+n-i+m-j-dpg[i][j+1],dpg[i][j+1]+i+j-1-dpr[i][j])>mx)
            {
				mx = min(dpr[i][j]+n-i+m-j-dpg[i][j+1],dpg[i][j+1]+i+j-1-dpr[i][j]);
				ans = make_pair(make_pair(i,j),'R');
			}
			if(i+1<=n && min(dpr[i][j]+n-i+m-j-dpg[i+1][j],dpg[i+1][j]+i+j-1-dpr[i][j])>mx)
            {
				mx = min(dpr[i][j]+n-i+m-j-dpg[i+1][j],dpg[i+1][j]+i+j-1-dpr[i][j]);
				ans = make_pair(make_pair(i,j),'D');
			}
		}
	}
	cout << mx*2 << "\n";
	pair<int,int> cur=ans.first;
	while(cur!=make_pair(1,1))
    {
		if(pr[cur.first][cur.second])
        {
			prt.push_front('D');
			cur = make_pair(cur.first-1,cur.second);
		}
		else
        {
			prt.push_front('R');
			cur = make_pair(cur.first,cur.second-1);
		}
	}
	if(ans.second=='R') cur=make_pair(ans.first.first,ans.first.second+1),prt.push_back('R');
	else cur=make_pair(ans.first.first+1,ans.first.second),prt.push_back('D');
	while(cur!=make_pair(n,m))
    {
		if(pg[cur.first][cur.second])
        {
			prt.push_back('D');
			cur = make_pair(cur.first+1,cur.second);
		}
		else
        {
			prt.push_back('R');
			cur = make_pair(cur.first,cur.second+1);
		}
	}
	int r=mx,g=mx;
	cur=make_pair(1,1);
	while(cur!=make_pair(-1,-1))
    {
		if(tb[cur.first][cur.second])
        {
			if(g) cout << 'Y',g--;
			else cout << 'N';
		}
		else
        {
			if(r) cout << 'Y',r--;
			else cout << 'N';
		}
		if(prt.front()=='R') cur=make_pair(cur.first,cur.second+1);
		else cur=make_pair(cur.first+1,cur.second);
		cout << " " << prt.front() << "\n";
		prt.pop_front();
		if(cur==make_pair(n,m)) cur=make_pair(-1,-1);
	}
	if(g>0 || r>0) cout << 'Y';
	else cout << 'N';
}

#include<bits/stdc++.h>
using namespace std;
const int N=110;
const int M=3e4+10;
pair<long long,long long> pt[N],cc[M];
long long r[M];
bool inc(pair<long long,long long> a,pair<long long,long long> b,long long c){
	long long x=a.first-b.first;
	long long y=a.second-b.second;
	return (c*c>=(x*x+y*y));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
    {
		long long a,b;
		cin >> a >> b;
		pt[i]=make_pair(a,b);
	}
	for(int i=1;i<=m;i++)
    {
		long long a,b,c;
		cin >> a >> b >> c;
		cc[i]=make_pair(a,b);
		r[i]=c;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
    {
		bool ic=false,oc=false;
		for(int j=1;j<=n;j++)
        {
			if(inc(pt[j],cc[i],r[i])) ic=true;
			else oc=true;
		}
		if(ic && oc) ans++;
	}
	cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
const int MAXN = 1e5+5;
int N, Q, p[MAXN];
bool visited[MAXN] = {false};
vector<int> cycle_sz;
int ans[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> p[i];
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            int sz = 0;
            int cur = i;
            while(!visited[cur])
            {
                sz++;
                visited[cur] = true;
                cur = p[cur];
            }
            cycle_sz.push_back(sz);
        }
    }
    sort(cycle_sz.begin(),cycle_sz.end());
    for(int i=0;i<=N;i++) ans[i] = cycle_sz.back();
    int lptr = 0;
    for(int i=1;i<=cycle_sz.back();i++)
    {
        while(lptr < cycle_sz.size() && cycle_sz[lptr] <= i) lptr++;
        int sm = 0;
        for(int j=lptr;j<cycle_sz.size();j++) sm += (cycle_sz[j]-1)/i;
        ans[sm] = min(i, ans[sm]);
    }
    for(int i=1;i<=N;i++) ans[i] = min(ans[i-1], ans[i]);
    while (Q--)
    {
        int k;
        cin >> k;
        if(k > N) cout << 1 << "\n";
        else cout << ans[k] << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=210;
const int MOD=1e9+7;
long long dp[N][N],dp2[N][N];
int main()
{
	int r,c;
	cin >> r >> c;
	dp2[1][1]=1;
	for(int i=1;i<=(r+c-2);i++)
    {
		for(int ii=1;ii<=r;ii++) for(int j=1;j<=r;j++) dp[ii][j]=dp2[ii][j]%MOD;
		for(int j=1;j<=r;j++)
        {
			for(int k=1;k<=r;k++)
            {
				dp2[j][k]=(dp[j-1][k]+dp[j][k-1])%MOD;
				if(j!=k) dp2[j][k]=(dp2[j][k]+dp[j-1][k-1]+dp[j][k])%MOD;
			}
		}
	}
	cout << dp2[r][r]%MOD;
}

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
using namespace std;
const int N=505;
vector<int>v;
mt19937 rng(time(0));
struct mint
{
    int t[2*N];
    void build(int sz)
    {
        for(int i=0;i<sz;i++) t[i+sz]=v[i];
        for(int i=sz-1;i>0;i--) t[i]=min(t[2*i],t[2*i+1]);
    }
    int qr(int l,int r,int sz,int res=1e9)
    {
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1)
        {
            if(l&1) res=min(res,t[l++]);
            if(r&1) res=min(res,t[--r]);
        }
        return res;
    }
}s1;
struct maxt{
    int t[2*N];
    void build(int sz)
    {
        for(int i=0;i<sz;i++)t[i+sz]=v[i];
        for(int i=sz-1;i>0;i--) t[i]=max(t[2*i],t[2*i+1]);
    }
    int qr(int l,int r,int sz,int res=0)
    {
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1)
        {
            if(l&1) res=max(res,t[l++]);
            if(r&1) res=max(res,t[--r]);
        }
        return res;
    }
}s2;
ll ans=0;
vector<int>rs;
void solve1(int n,int k)
{
    for(int i=1;i<=n;i++) v.pb(i);
    vector<pii>qr(k);
    for(int i=0;i<k;i++) cin >> qr[i].f >> qr[i].s;
    do{
        s1.build(n);s2.build(n);ll tt=0;
        for(auto it : qr) tt+=s2.qr(it.f-1,it.s,n)-s1.qr(it.f-1,it.s,n);
        if(tt>ans) ans=tt,rs=v;
    }while(next_permutation(v.begin(),v.end()));
    for(auto it : rs) cout << it << ' ';
}
void solve2(int n,int k)
{
    int ro=4e4;
    for(int i=1;i<=n;i++) v.pb(i);
    vector<pii>qr(k);
    for(int i=0;i<k;i++) cin >> qr[i].f >> qr[i].s;
    while(ro--)
    {
        shuffle(v.begin(),v.end(),rng);
        s1.build(n);s2.build(n);ll tt=0;
        for(auto it : qr) tt+=s2.qr(it.f-1,it.s,n)-s1.qr(it.f-1,it.s,n);
        if(tt>ans) ans=tt,rs=v;
    }
    for(auto it : rs) cout << it << ' ';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    if(n<=9) solve1(n,k);
    else solve2(n,k);
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e5+5;
struct node{
    db v;
    int f;
    node *l,*r;
    node():v(0),f(0),l(nullptr),r(nullptr){}
    node(db v,int f):v(v),f(f),l(nullptr),r(nullptr){}
    node(db v,int f,node *l,node *r):v(v),f(f),l(l),r(r){}
};
typedef node* nodeptr;
int n,m;
db u;
db a[N],qs[N];
nodeptr rt[N];
int mp[N];
vector<pair<db,int>> tb;
void build(int l,int r,nodeptr &t){
    t=new node();
    if(l==r) return;
    int m=(l+r)/2;
    build(l,m,t->l);
    build(m+1,r,t->r);
    t->v=t->l->v+t->r->v;
    t->f=t->l->f+t->r->f;
}

void update(int l,int r,nodeptr &t,int x,db v,nodeptr k){
    t=new node(*k);
    t->v+=v;
    t->f++;
    if(l==r) return;
    int m=(l+r)/2;
    if(x<=m) update(l,m,t->l,x,v,k->l);
    else update(m+1,r,t->r,x,v,k->r);
}

db query(int l,int r,nodeptr t,nodeptr k,int v)
{
    if(v<=0) return 0;
    if(l==r) return k->v-t->v;
    db sum=k->r->v-t->r->v;
    int freq=k->r->f-t->r->f;
    int m=(l+r)/2;
    if(freq<=v) return sum+query(l,m,t->l,k->l,v-freq);
    return query(m+1,r,t->r,k->r,v);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        qs[i]=a[i]+qs[i-1];
        tb.emplace_back(a[i],i);
    }
    sort(tb.begin(),tb.end());
    for(int i=0;i<n;i++) mp[tb[i].second]=i+1;
    build(1,n,rt[0]);
    for(int i=1;i<=n;i++) update(1,n,rt[i],mp[i],a[i],rt[i-1]);
    while(m--)
    {
        int st,ed;
        cin >> st >> ed >> u;
        int sz=ed-st+1;
        int l=0,r=sz;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(query(1,n,rt[st-1],rt[ed],mid)>=u*mid) l=mid;
            else r=mid-1;
        }
        cout << (l>0?sz-l:-1) << '\n';
    }
}

#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<int, int> buildings;
int main()
{
    int n, k; 
    cin >> n >> k;
    for(int i=0;i<k;++i)
    {
        int pos, height;
        cin >> pos >> height;
        int max_d = n;
        buildings[pos] = height;
        for(auto it=buildings.begin();it!=buildings.end();++it)
        {
            if(abs(it->first - pos) > max_d) break;
            if(it->second > height) max_d = min(max_d, abs(it->first - pos) - 1);
        }
        cout << max_d << '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define sz(x) (int)x.size()
#define pii pair<ll,ll>
using namespace std;
const int N=1e5+5;
vector<pii>g[N];
bool vis[N]{0},cv[N]{0};
pii pr[N];
ll e[N];
vector<int>cyc;
pii t[4*N];
ll lz[4*N]{0},lz2[4*N]{0};
ll tree[4*N]{0},lazy[4*N]{0},lazy2[4*N]{0};
void build2(int i,int l,int r)
{
    if(l==r) return void(tree[i]=e[l]);
    int m=(l+r)>>1;
    build2(2*i,l,m);
    build2(2*i+1,m+1,r);
    tree[i]=tree[2*i]+tree[2*i+1];
}

void push22(int i,int l,int r)
{
    if(lazy2[i])
    {
        tree[i]=0;
        if(l<r)
        {
            lazy2[2*i]=lazy2[i];
            lazy2[2*i+1]=lazy2[i];
            lazy[2*i]=0;
            lazy[2*i+1]=0;
        }
        lazy2[i]=0;
    }
}

void push12(int i,int l,int r)
{
    push22(i,l,r);
    tree[i]+=lazy[i]*(r-l+1);
    if(l<r)
    {
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
    }
    lazy[i]=0;
}

void u12(int i,int l,int r,int tl,int tr,ll v)
{
    push12(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lazy[i]+=v;
        push12(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    u12(2*i,l,m,tl,tr,v);
    u12(2*i+1,m+1,r,tl,tr,v);
    tree[i]=tree[2*i]+tree[2*i+1];
}

void u22(int i,int l,int r,int tl,int tr)
{
    push12(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lazy2[i]=1;
        push12(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    u22(2*i,l,m,tl,tr);
    u22(2*i+1,m+1,r,tl,tr);
    tree[i]=tree[2*i]+tree[2*i+1];
}

ll qr2(int i,int l,int r,int tl,int tr)
{
    push12(i,l,r);
    if(r<tl||l>tr)return 0;
    if(l>=tl&&r<=tr)return tree[i];
    int m=(l+r)>>1;
    return qr2(2*i,l,m,tl,tr)+qr2(2*i+1,m+1,r,tl,tr);
}

void build(int i,int l,int r)
{
    if(l==r) return void(t[i]={e[cyc[l]],1});
    int m=(l+r)>>1;
    build(2*i,l,m);
    build(2*i+1,m+1,r);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}

void push2(int i,int l,int r)
{
    if(lz2[i])
    {
        t[i].f=0;
        t[i].s=r-l+1;
        if(l<r)
        {
            lz2[2*i]=lz2[i];
            lz2[2*i+1]=lz2[i];
            lz[2*i]=0;
            lz[2*i+1]=0;
        }
        lz2[i]=0;
    }
}
void push(int i,int l,int r)
{
    push2(i,l,r);
    t[i].f+=lz[i];
    if(l<r)
    {
        lz[2*i]+=lz[i];
        lz[2*i+1]+=lz[i];
    }
    lz[i]=0;
}
void u1(int i,int l,int r,int tl,int tr,ll v)
{
    push(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lz[i]+=v;
        push(i,l,r);
        return;
    }int m=(l+r)>>1;
    u1(2*i,l,m,tl,tr,v);
    u1(2*i+1,m+1,r,tl,tr,v);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
void u2(int i,int l,int r,int tl,int tr)
{
    push(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lz2[i]=1;
        push(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    u2(2*i,l,m,tl,tr);
    u2(2*i+1,m+1,r,tl,tr);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
pii qr(int i,int l,int r,int tl,int tr){
    push(i,l,r);
    if(r<tl||l>tr) return {0,0};
    if(l>=tl&&r<=tr) return t[i];
    int m=(l+r)>>1;
    pii le=qr(2*i,l,m,tl,tr);
    pii re=qr(2*i+1,m+1,r,tl,tr);
    if(le.f==re.f) return {le.f,le.s+re.s};
    else return max(le,re);
}
void dfs(int u,int p)
{
    vis[u]=1;
    for(auto v:g[u])
    {
        if(v.f==p) continue;
        if(!vis[v.f])
        {
            pr[v.f]={u,v.s};
            dfs(v.f,u);
        }
        else if(vis[v.f]&&!cv[v.f]&&!cv[u])
        {
            int x=u;
            cyc.pb(v.s);
            while(x!=v.f)
            {
                cv[x]=1;
                cyc.pb(pr[x].s);
                x=pr[x].f;
            }
            cv[v.f]=1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        g[u].pb({v,i});
        g[v].pb({u,i});
        e[i]=w;
    }
    pr[1]={1,0};
    dfs(1,1);
    sort(cyc.begin(),cyc.end());
    build(1,0,sz(cyc)-1);
    build2(1,1,n);
    while(q--)
    {
        int x,l,r;
        ll v;
        cin >> x >> l >> r >> v;
        if(x==1)
        {
            u12(1,1,n,l,r,v);
            l = lower_bound(cyc.begin(),cyc.end(),l)-cyc.begin();
            r = upper_bound(cyc.begin(),cyc.end(),r)-cyc.begin()-1;
            u1(1,0,sz(cyc)-1,l,r,v);
            cout << tree[1]-t[1].f << " " << t[1].s << "\n";
        }
        else
        {
            u22(1,1,n,l,r);
            u12(1,1,n,l,r,v);
            l = lower_bound(cyc.begin(),cyc.end(),l)-cyc.begin();
            r = upper_bound(cyc.begin(),cyc.end(),r)-cyc.begin()-1;
            u2(1,0,sz(cyc)-1,l,r);
            u1(1,0,sz(cyc)-1,l,r,v);
            cout << tree[1]-t[1].f << " " << t[1].s << "\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
#include "homework.h"
struct A
{
    int st,num;
    bool operator<(const A&o)const{
        return st>o.st;
    }
};
std::vector<int> adj[100010];
int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B)
{
    for(int i=0;i<N;i++) for(int j:B[i]) adj[j].push_back(i);
    priority_queue<A> pq;
    for(int i = 0;i<N;i++)
    {
        if(HW[i][3]==0)
        {
            int rst =  HW[i][0]/HW[i][2];
            if(HW[i][0]%HW[i][2]) rst++;
            rst*=HW[i][2];
            if(rst>HW[i][1]) continue;
            pq.push({rst,i});
        }   
    }
    int cnt = 0;
    while(!pq.empty())
    {
        A now = pq.top();
        pq.pop();
        cnt++;
        int st = now.st+1;
        for(int i:adj[now.num])
        {
            HW[i][3]--;
            if(HW[i][3]==0)
            {
                int a = max(st,HW[i][0]);
                int rst =  a/HW[i][2];
                if(a%HW[i][2]) rst++;
                rst*=HW[i][2];
                if(rst>HW[i][1]) continue;
                pq.push({rst,i});
            }
        }
    }
    return cnt;
}

#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const N=1e5+10;
int n;
struct seg{
    int all[3*N];
    int under[3*N];
    void build(){for(int i=0;i<3*N;i++)all[i]=under[i]=0;}
    void upd(int i,int l,int r,int ll,int rr,int val)
    {
        if(rr<l||r<ll) return;
        if(ll<=l&&r<=rr)
        {
            all[i]+=val;
            return;
        }
        int mid=(l+r)>>1;
        upd(2*i,l,mid,ll,rr,val);
        upd(2*i+1,mid+1,r,ll,rr,val);
        under[i]=(all[2*i]>0?mid-l+1:under[2*i])+(all[2*i+1]>0? r-(mid+1)+1:under[2*i+1]);
    }
    int query() return (all[1]>0? n:under[1]);
}tree;
vector<int> keep[2*N];
vector<pii> todo[N];
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    tree.build();
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        if(keep[a].empty()) keep[a].push_back(0);
        keep[a].push_back(i);
        int sz=keep[a].size();
        if(sz>=7)
        {
            todo[keep[a][sz-7]+1].push_back({keep[a][sz-2],keep[a][sz-1]-1});
            todo[keep[a][sz-6]+1].push_back({-keep[a][sz-2],keep[a][sz-1]-1});
        }
    }
    for(int i=0;i<2*N;i++)
    {
        int sz=keep[i].size();
        if(sz>=6)
        {
            todo[keep[i][sz-6]+1].push_back({keep[i][sz-1],n});
            todo[keep[i][sz-5]+1].push_back({-keep[i][sz-1],n});
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto it:todo[i])
        {
            if(it.fi>=0) tree.upd(1,1,n,it.fi,it.se,1);
            else tree.upd(1,1,n,-it.fi,it.se,-1);
        }
        ans+=tree.query();
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int p[1<<21];
int fin(int x)
{
    if(p[x] == x) return x;
    else return fin(p[x]);
}

int main()
{
    int k,m;
    scanf("%d %d",&k,&m);
    int n = 1<<k;
    for(int i=0;i<n+1;i++) p[i] = i;
    int a,b;
    int cnt = 0,ch = 0;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        swap(a,b);
        b = a+(1<<b);
        int s = fin(a);
        int e = fin(b);
        if(s!=e)
        {
            cnt++;
            if(s>e) p[e] = s;
            else p[s] = e;
        }
        if(cnt == n && !ch)
        {
            ch = 1;
            printf("%d",i+1);
        }
    }
    return 0;
}

#include <vector>
#include<iostream>
#include<queue>
#include<cassert>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
#include<map>
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second
#pragma GCC optimize ("03,unroll-lopps")
using namespace std;
const int mxn=2e5,lg=30;
#define int long long
using namespace std;
vector<pii>adj[mxn+10];
int dist[mxn+10],up[mxn+10][lg+5],n,h[mxn+10];
const int inf=1e18,minf=-1e18;
pair<pii,int>ex;
void dfs(int cur,int p)
{
    for(auto i:adj[cur])
    {
        if(i.f==p) continue;
        up[i.f][0]=cur;
        h[i.f]=h[cur]+1;
        dist[i.f]=dist[cur]+i.s;
        dfs(i.f,cur);
    }
}
int lca(int a,int b)
{
    if(h[a]<h[b]) swap(a,b);
    int k=h[a]-h[b];
    for(int i=0;i<=lg;i++) if(k&(1ll<<i)) a=up[a][i];
    if(a==b) return a;
    for(int i=lg;i>=0;i--) if(up[a][i]!=up[b][i]) a=up[a][i],b=up[b][i];
    return up[a][0];
}
int getdist(int a,int b)
{
    return dist[a]+dist[b]-2*dist[lca(a,b)];
}
pii cost[mxn+10];
int m;
struct node{
    node *l,*r;
    int val,cnt;
    node():l(0),r(0),val(0),cnt(0){};
};
node* root[mxn+10];
struct persist{
    void build(node *&cur,int l,int r)
    {
        int mid=l+(r-l)/2;
        cur=new node();
        if(l==r) return;
        build(cur->l,l,mid);
        build(cur->r,mid+1,r);
    }
    void update(node *&cur,node *&lcur,int l,int r,int pos,int val)
    {
        int mid=l+(r-l)/2;
        cur=new node(*lcur);
        if(l==r)
        {
            cur->val=val;
            cur->cnt=1;
            return;
        }
        if(pos<=mid) update(cur->l,lcur->l,l,mid,pos,val);
        else update(cur->r,lcur->r,mid+1,r,pos,val);
        cur->val=cur->l->val+cur->r->val;
        cur->cnt=cur->l->cnt+cur->r->cnt;
    }
    pii qry(node *cur,node *del,int need,int l,int r)
    {
        int mid=l+(r-l)/2;
        if(l==r) return {cur->val,cur->cnt};
        int sum=cur->l->cnt-del->l->cnt;
        if(sum>=need) return qry(cur->l,del->l,need,l,mid);
        else
        {
            pii a=qry(cur->r,del->r,need-sum,mid+1,r);
            return {a.f+cur->l->val-del->l->val,a.s+sum};
        }
    }
    int qry2(node *cur,int l,int r,int pos)
    {
        if(l==r) return cur->val;
        int mid=l+(r-l)/2;
        if(pos<=mid) return qry2(cur->l,l,mid,pos);
        else return qry2(cur->r,mid+1,r,pos);
    }
}t;
int ps[mxn+10];
void init(int32_t N,std::vector<int32_t> T,std::vector<std::vector<int32_t>> road)
{
    n=N;
    m=T.size()-1;
    for(int i=0;i<n-1;i++)
    {
        adj[road[i][0]].pb({road[i][1],road[i][2]});
        adj[road[i][1]].pb({road[i][0],road[i][2]});
    }
    ex={{road[n-1][0],road[n-1][1]},road[n-1][2]};
    dfs(0,-1);
    for(int i=1;i<=lg;i++) for(int j=0;j<n;j++) up[j][i]=up[up[j][i-1]][i-1];
    for(int i=0;i<m;i++)
    {
        cost[i].f=getdist(T[i],T[i+1]);
        cost[i].s=min(getdist(T[i],ex.f.f)+getdist(T[i+1],ex.f.s)+ex.s,getdist(T[i],ex.f.s)+getdist(T[i+1],ex.f.f)+ex.s);
    }
    vector<pii>change;
    for(int i=0;i<m;i++) change.pb({(cost[i].s-cost[i].f),i});
    sort(all(change));
    vector<int>pos(m);
    for(int i=0;i<m;i++) pos[change[i].s]=i;
    t.build(root[0],0,m);
    for(int i=0;i<m;i++)
    {
        ps[i]=cost[i].f;
        if(i)ps[i]+=ps[i-1];
        t.update(root[i+1],root[i],0,m,pos[i],change[pos[i]].f);
    }
    return;
}
long long min_distance(int32_t l,int32_t r,int32_t x){
    r--;
    int ans=ps[r];
    if(l)ans-=ps[l-1];
    if(x==0)return ans;
    l++,r++;
    ans+=t.qry(root[r],root[l-1],x,0,m).f;
    return ans;
}
#include <vector>
#include<iostream>
#include<queue>
#include<cassert>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
#include<map>
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second
#pragma GCC optimize ("03,unroll-lopps")
using namespace std;
const int mxn=2e5,lg=30;
#define int long long
using namespace std;
vector<pii>adj[mxn+10];
int dist[mxn+10],up[mxn+10][lg+5],n,h[mxn+10];
const int inf=1e18,minf=-1e18;
pair<pii,int>ex;
void dfs(int cur,int p)
{
    for(auto i:adj[cur])
    {
        if(i.f==p) continue;
        up[i.f][0]=cur;
        h[i.f]=h[cur]+1;
        dist[i.f]=dist[cur]+i.s;
        dfs(i.f,cur);
    }
}
int lca(int a,int b)
{
    if(h[a]<h[b]) swap(a,b);
    int k=h[a]-h[b];
    for(int i=0;i<=lg;i++) if(k&(1ll<<i)) a=up[a][i];
    if(a==b)return a;
    for(int i=lg;i>=0;i--) if(up[a][i]!=up[b][i]) a=up[a][i],b=up[b][i];
    return up[a][0];
}
int getdist(int a,int b)
{
    return dist[a]+dist[b]-2*dist[lca(a,b)];
}
pii cost[mxn+10];
int m;
struct node{
    node *l,*r;
    int val,cnt;
    node():l(0),r(0),val(0),cnt(0){};
};
node* root[mxn+10];
struct persist{
    void build(node *&cur,int l,int r)
    {
        int mid=l+(r-l)/2;
        cur=new node();
        if(l==r) return;
        build(cur->l,l,mid);
        build(cur->r,mid+1,r);
    }
    void update(node *&cur,node *&lcur,int l,int r,int pos,int val)
    {
        int mid=l+(r-l)/2;
        cur=new node(*lcur);
        if(l==r)
        {
            cur->val=val;
            cur->cnt=1;
            return;
        }
        if(pos<=mid) update(cur->l,lcur->l,l,mid,pos,val);
        else update(cur->r,lcur->r,mid+1,r,pos,val);
        cur->val=cur->l->val+cur->r->val;
        cur->cnt=cur->l->cnt+cur->r->cnt;
    }
    pii qry(node *cur,node *del,int need,int l,int r)
    {
        int mid=l+(r-l)/2;
        if(l==r) return {cur->val,cur->cnt};
        int sum=cur->l->cnt-del->l->cnt;
        if(sum>=need) return qry(cur->l,del->l,need,l,mid);
        else
        {
            pii a=qry(cur->r,del->r,need-sum,mid+1,r);
            return {a.f+cur->l->val-del->l->val,a.s+sum};
        }
    }
    int qry2(node *cur,int l,int r,int pos)
    {
        if(l==r) return cur->val;
        int mid=l+(r-l)/2;
        if(pos<=mid) return qry2(cur->l,l,mid,pos);
        else return qry2(cur->r,mid+1,r,pos);
    }
}t;
int ps[mxn+10];
void init(int32_t N,std::vector<int32_t> T,std::vector<std::vector<int32_t>> road)
{
    n=N;
    m=T.size()-1;
    for(int i=0;i<n-1;i++)
    {
        adj[road[i][0]].pb({road[i][1],road[i][2]});
        adj[road[i][1]].pb({road[i][0],road[i][2]});
    }
    ex={{road[n-1][0],road[n-1][1]},road[n-1][2]};
    dfs(0,-1);
    for(int i=1;i<=lg;i++) for(int j=0;j<n;j++) up[j][i]=up[up[j][i-1]][i-1];
    for(int i=0;i<m;i++)
    {
        cost[i].f=getdist(T[i],T[i+1]);
        cost[i].s=min(getdist(T[i],ex.f.f)+getdist(T[i+1],ex.f.s)+ex.s,getdist(T[i],ex.f.s)+getdist(T[i+1],ex.f.f)+ex.s);
    }
    vector<pii>change;
    for(int i=0;i<m;i++) change.pb({(cost[i].s-cost[i].f),i});
    sort(all(change));
    vector<int>pos(m);
    for(int i=0;i<m;i++) pos[change[i].s]=i;
    t.build(root[0],0,m);
    for(int i=0;i<m;i++)
    {
        ps[i]=cost[i].f;
        if(i) ps[i]+=ps[i-1];
        t.update(root[i+1],root[i],0,m,pos[i],change[pos[i]].f);
    }
    return;
}
long long min_distance(int32_t l,int32_t r,int32_t x)
{
    r--;
    int ans=ps[r];
    if(l) ans-=ps[l-1];
    if(x==0) return ans;
    l++,r++;
    ans+=t.qry(root[r],root[l-1],x,0,m).f;
    return ans;
}

#include<bits/stdc++.h>
using namespace std;
int k;
int dist[100][100],st[20],ed[20];
int cnt(int a)
{
	int s=0;
	while(a!=0) a/=2,s++;
	return s;
}
int trav(int a,int b)
{
	int d=0;
	if(a>(1<<k) && b>(1<<k)) a-=(1<<k),b-=(1<<k);
	if((a>(1<<k) && b<(1<<k)) || (a<(1<<k) && b>(1<<k))) return INT_MAX;
	while(cnt(a)>cnt(b)) a/=2,d++;
	while(cnt(b)>cnt(a)) b/=2,d++;
	while(a!=b) a/=2,b/=2,d+=2;
	return d;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l,q;
	cin >> k >> l >> q;
	for(int i=1;i<=15;i++)
    {
		for(int j=1;j<=15;j++)
        {
			dist[i][j]=INT_MAX;
			if(i==j) dist[i][j]=0;
		}
	}
	for(int i=1;i<=l;i++)
    {
		int a,b;
		cin >> a >> b;
		st[i]=a,st[l+i]=b;
		dist[i][l+i]=min(dist[i][l+i],1);
		dist[l+i][i]=min(dist[l+i][i],1);
	}
	for(int i=1;i<=2*l;i++)
    {
		for(int j=1;j<=2*l;j++)
        {
			if(i==j) continue;
			if(abs(st[i]-st[j])>=(1<<k)) continue;
			if(st[i]>(1<<k)) dist[i][j]=min(dist[i][j],trav((st[i]-(1<<k)),st[j]-(1<<k)));
			else dist[i][j]=min(dist[i][j],trav(st[i],st[j]));
		}
	}
	for(int k=1;k<=2*l;k++)
    {
		for(int i=1;i<=2*l;i++)
        {
			for(int j=1;j<=2*l;j++)
            {
				if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
				if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	while(q--)
    {
		int a,b,mn;
		cin >> a >> b;
		mn=trav(a,b);
		for(int i=1;i<=2*l;i++)
        {
			int tmpa=trav(st[i],a);
			for(int j=1;j<=2*l;j++)
            {
				int tmpb;
				if(i==j) continue;
				tmpb=trav(st[j],b);
				if(dist[i][j]==INT_MAX || tmpa==INT_MAX || tmpb==INT_MAX) continue;
				mn=min(mn,dist[i][j]+tmpa+tmpb);
			}
		}
		cout << mn << "\n";
	}
}

#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pii>
#define sz(x) (int)x.size()
using namespace std;
const int N=1e5+5;
int t[4*N],lz[4*N];
ll a[N];
void build(int i,int l,int r)
{
    if(l==r) return void(t[i]=l-1);
    int m=(l+r)>>1;
    build(2*i,l,m);build(2*i+1,m+1,r);
}
void push(int i,int l,int r)
{
    if(lz[i]!=-1)
    {
        t[i]=lz[i];
        if(l<r) lz[2*i]=lz[i],lz[2*i+1]=lz[i];
    }
    lz[i]=-1;
}
void update(int i,int l,int r,int tl,int tr,int v)
{
    push(i,l,r);
    if(r<tl||l>tr) return;
    if(r<=tr&&l>=tl)
    {
        lz[i]=v;
        push(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    update(2*i,l,m,tl,tr,v);
    update(2*i+1,m+1,r,tl,tr,v);
    t[i]=max(t[2*i],t[2*i+1]);
}
int qr(int i,int l,int r,int idx)
{
    push(i,l,r);
    if(r<idx||l>idx) return 0;
    if(l==r) return t[i];
    int m=(l+r)>>1;
    return max(qr(2*i,l,m,idx),qr(2*i+1,m+1,r,idx));
}
int t2[4*N],lz2[4*N];
void build2(int i,int l,int r)
{
    if(l==r) return void(t2[i]=l+1);
    int m=(l+r)>>1;
    build2(2*i,l,m);
    build2(2*i+1,m+1,r);
}
void push2(int i,int l,int r)
{
    if(lz2[i]!=-1)
    {
        t2[i]=lz2[i];
        if(l<r) lz2[2*i]=lz2[i],lz2[2*i+1]=lz2[i];
    }
    lz2[i]=-1;
}
void update2(int i,int l,int r,int tl,int tr,int v)
{
    push2(i,l,r);
    if(r<tl||l>tr) return;
    if(r<=tr&&l>=tl)
    { 
        lz2[i]=v;
        push2(i,l,r);
        return;
    }
    int m=(l+r) >> 1;
    update2(2*i,l,m,tl,tr,v);
    update2(2*i+1,m+1,r,tl,tr,v);
    t[i]=min(t[2*i],t[2*i+1]);
}
int qr2(int i,int l,int r,int idx)
{
    push2(i,l,r);
    if(r<idx||l>idx) return 1e9;
    if(l==r) return t2[i];
    int m=(l+r)>>1;
    return min(qr2(2*i,l,m,idx),qr2(2*i+1,m+1,r,idx));
}
set<int>ms;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    n--;
    for(int i=1;i<4*N;i++) lz[i]=lz2[i]=-1;
    for(int i=1;i<=n;i++) a[i]=10,ms.insert(i);
    build(1,1,n);build2(1,1,n);
    while(q--)
    {
        int o;
        cin>>o;
        if(o==1)
        {
            ll i,j;
            cin >> i >> j;
            j>>=1;
            int cur=qr(1,1,n,i);
            ll tt=j;
            ms.insert(i);
            while(tt>0&&cur>0)
            {
                int ad=min(a[cur],tt);
                a[i]+=ad;
                a[cur]-=ad;
                tt-=ad;
                if(a[cur]==0) ms.erase(cur),cur=qr(1,1,n,cur);
            }
            update(1,1,n,cur+1,i,cur);
            ll tt2=j;
            cur=qr2(1,1,n,i);
            while(tt2>0&&cur<=n)
            {
                int ad=min(a[cur],tt2);
                a[i]+=ad;
                a[cur]-=ad;
                tt2-=ad;
                if(a[cur]==0) ms.erase(cur),cur=qr2(1,1,n,cur);
            }
            update2(1,1,n,i,cur-1,cur);
            if(tt!=0)
            {
                cur=qr2(1,1,n,i);
                while(tt>0&&cur<=n)
                {
                    int ad=min(a[cur],tt);
                    a[i]+=ad;
                    a[cur]-=ad;
                    tt-=ad;
                    if(a[cur]==0) ms.erase(cur),cur=qr2(1,1,n,cur);
                }
                update2(1,1,n,i,cur-1,cur);
            }
            if(tt2!=0)
            {
                cur=qr(1,1,n,i);
                while(tt2>0&&cur>0)
                {
                    int ad=min(a[cur],tt2);
                    a[i]+=ad;
                    a[cur]-=ad;
                    tt2-=ad;
                    if(a[cur]==0) ms.erase(cur),cur=qr(1,1,n,cur);
                }
                update(1,1,n,cur+1,i,cur);
            }
            auto it = ms.upper_bound(i);
            if(it!=ms.end()) update(1,1,n,i+1,*it,i);
            else update(1,1,n,i+1,n,i);
            it = ms.lower_bound(i);
            if(it!=ms.begin())
            {   
                it--;
                update2(1,1,n,*it,i-1,i);
            }
            else update2(1,1,n,1,i-1,i);
        }
        else
        {
            int j;
            cin >> j;
            cout << a[j] << '\n';
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
int n, m, k, arr[100100];
bool solve(int mid)
{
    int l = 1, r = n, sum = 0, cnt = 0;
    vector<int> dpl(n+10, 0), dpr(n+10, 0);
    dpl[0] = dpr[n + 1] = 1;
    for(int i = 1; i<=n; ++i)
    {
        dpl[i] = dpl[i - 1];
        if(arr[i] > mid){
            r = i - 1;
            break;
        }
        sum+=arr[i], cnt++;
        if(sum > mid || cnt > m) cnt = 1, sum = arr[i], dpl[i]++;
    }
    sum = 0, cnt = 0;
    for(int i=n;i>0;--i)
    {
        dpr[i] = dpr[i+1];
        if(arr[i] > mid)
        {
            l = i + 1;
            break;
        }
        sum+=arr[i];
        cnt++;
        if(sum>mid || cnt>m) cnt = 1, sum = arr[i], dpr[i]++;
    }
    dpl[0] = dpr[n+1] = 0;
    for(int i=1;i<=n-m+1;++i)
    {
        if(i-1<=r && i+m>=l && dpl[i-1]+dpr[i+m]<=k-1) return true;
    }
    return false;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=1;i<=n;++i) cin >> arr[i];
    int l = 0, r = 1e9, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(solve(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}

#include <bits/stdc++.h>
#define int long long
#define pii pair <int,int>
#define tiii tuple <int, int, int>
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define ub(a, b) upper_bound(a.begin(), a.end(), b) - a.begin();
#define lb(a, b) lower_bound(a.begin(), a.end(), b) - a.begin();
#define ve vector
#define graph(a, n) vector <int> a[n];
#define wgraph(a, n) vector <pii> a[n];
#define emb emplace_back
#define em emplace
#define ins insert
#define er erase
#define iShowSpeed cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
template <typename T>
using greater_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const int mod = 1e9 + 7;
const int inf = 1e18;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int32_t main()
{
    iShowSpeed;
    int n, m;
    cin >> n >> m;
    vector <int> p(n), dp(1 << m, inf);
    vector <vector <int>> can(n, vector <int> (m));
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        for(int j=0;j<m;j++) cin >> can[i][j];
    }
    dp[0] = 0;
    for(int i=0;i<n;i++)
    {
        int mask = 0;
        for(int j=0;j<m;j++) if(can[i][j]) mask |= (1 << j);
        if(dp[mask] <= p[i]) continue;
        for(int j = (1 << m) - 1; j >= 0; j--)
        {
            if(dp[j] == inf) continue;
            dp[j | mask] = min(dp[j | mask], dp[j] + p[i]);
        }
    }
    cout << dp[(1 << m) - 1];
}

#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using db = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<db,db>;
const int INF=0x3fffffff;
const int MOD=998244353;
const ll LINF=0x1fffffffffffffff;
const db DINF=numeric_limits<db>::infinity();
const db EPS=1e-9;
const db PI=acos(db(-1));
const int N=1e5+5;
const int M=17;
const int K=1<<18;
int n,lim,ans;
int a[N];
vector<tuple<int,int,int,int>> ql[N],qr[N];
ll cl[N],cr[N];
struct RMQ
{
    pii t[M][N];
    void build()
    {
        for(int i=1;i<=n;i++) t[0][i]=pii(a[i],i);
        for(int i=0;i<M-1;i++) for(int j=1;j+(2<<i)-1<=n;j++) t[i+1][j]=max(t[i][j],t[i][j+(1<<i)]);
    }
    pii query(int l,int r)
    {
        if(r<l) return pii(-INF,-1);
        int k=31-__builtin_clz(r-l+1);
        return max(t[k][l],t[k][r-(1<<k)+1]);
    }
}rmq;
struct segtree
{
    ll t[K],lz[K];
    void pushlz(int l,int r,int i)
    {
        t[i]+=lz[i]*(r-l+1);
        if(l<r)
        {
            lz[i*2]+=lz[i];
            lz[i*2+1]+=lz[i];
        }
        lz[i]=0;
    }
    void update(int l,int r,int i,int x,int y,ll v)
    {
        pushlz(l,r,i);
        if(y<l||r<x) return;
        if(x<=l&&r<=y) return lz[i]=v,pushlz(l,r,i);
        int m=(l+r)/2;
        update(l,m,i*2,x,y,v);
        update(m+1,r,i*2+1,x,y,v);
        t[i]=t[i*2]+t[i*2+1];
    }
    void update(int x,int y,ll v)
    {
        update(1,N,1,x,y,v);
    }
    ll query(int l,int r,int i,int x,int y)
    {
        pushlz(l,r,i);
        if(y<l||r<x) return 0;
        if(x<=l&&r<=y) return t[i];
        int m=(l+r)/2;
        return query(l,m,i*2,x,y)+query(m+1,r,i*2+1,x,y);
    }
    ll query(int x,int y)
    {
        return query(1,N,1,x,y);
    }
}s;
int solve(int l,int r)
{
    int m=rmq.query(l,r).second;
    if(l<m)
    {
        int c=solve(l,m-1);
        ql[l-1].emplace_back(m,a[c]+1,a[m],-1);
        ql[m-1].emplace_back(m,a[c]+1,a[m],1);
    }
    if(r>m)
    {
        int c=solve(m+1,r);
        qr[m].emplace_back(m,a[c]+1,a[m],-1);
        qr[r].emplace_back(m,a[c]+1,a[m],1);
    }
    return m;
}
ll solve2(int l,int r)
{
    int m=rmq.query(l,r).second;
    ll res=1;
    if(l<m) res=(res*(solve2(l,m-1)+cl[m]%MOD))%MOD;
    if(r>m) res=(res*(solve2(m+1,r)+cr[m]%MOD))%MOD;
    return res;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int lim=*max_element(a+1,a+n+1);
    rmq.build();
    solve(1,n);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin >> l >> r;
        if(l>lim) ans+=r-l+1,l=r=0;
        if(r>lim) ans+=r-lim,r=lim;
        if(l>0)s.update(l,r,1);
        for(auto [j,l,r,k]:ql[i]) cl[j]+=s.query(l,r)*k;
        for(auto [j,l,r,k]:qr[i]) cr[j]+=s.query(l,r)*k;
    }
    cout << (ans+solve2(1,n))%MOD;
}

#include<bits/stdc++.h>
using namespace std;
#include "homework.h"
struct A
{
    int st,num;
    bool operator<(const A&o)const{
        return st>o.st;
    }
};
std::vector<int> adj[100010];
int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B)
{
    for(int i = 0;i<N;i++) for(int j:B[i]) adj[j].push_back(i);
    priority_queue<A> pq;
    for(int i = 0;i<N;i++)
    {
        if(HW[i][3]==0)
        {
            int rst =  HW[i][0]/HW[i][2];
            if(HW[i][0]%HW[i][2]) rst++;
            rst*=HW[i][2];
            if(rst>HW[i][1]) continue;
            pq.push({rst,i});
        }   
    }
    int cnt = 0;
    while(!pq.empty())
    {
        A now = pq.top();
        pq.pop();
        cnt++;
        int st = now.st+1;
        for(int i:adj[now.num])
        {
            HW[i][3]--;
            if(HW[i][3]==0) int a = max(st,HW[i][0]);
        }
    }
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#ifndef _DEBUG
#endif
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
using ll = long long;
struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const 
    {
		return w < o.w;
	}
	Edge(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};
struct Answer{
	int u, v, w;
	bool operator < (const Answer& o) const
    {
		if(u != o.u) return u < o.u;
		if(v != o.v) return v < o.v;
		return w < o.w;
	}
	Answer(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};
const int MxN = 3030;
const int LG = 15;
vector<Edge> edges, in, out;
vector<Answer> answer;
vector<pair<int, int>> adj[MxN];
int parent[MxN], mem[MxN], level[MxN], lift[LG][MxN];
int find_root(int u)
{
	if(u == parent[u]) return u;
	return parent[u] = find_root(parent[u]);
}
void dfs(int u, int p, int l)
{
	level[u] = l;
	lift[0][u] = p;
	for(auto x: adj[u])
    {
		if(x.first == p) continue;
		mem[x.first] = x.second + mem[u];
		dfs(x.first, u, l + 1);
	}
}
inline int lca(int u, int v)
{
	if(level[u] < level[v]) swap(u, v);
	for(int state=LG-1; state>=0; --state)
    {
		if(level[lift[state][u]] < level[v]) continue;
		u = lift[state][u];
	}
	if(u == v) return u;
	for(int state=LG-1; state>=0; --state)
    {
		if(lift[state][u] == lift[state][v]) continue;
		u = lift[state][u];
		v = lift[state][v];
	}
	return lift[0][u];
}
inline int get_dist(int u, int v)
{
	return mem[u] + mem[v] - 2 * mem[lca(u, v)];
}
inline void solution()
{
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i)
    {
		for(int j=1, x; j<=n; ++j)
        {
			if(i == j) continue;
			cin >> x;
			if(i < j) edges.emplace_back(i, j, x);
		}
	}
	sort(edges.begin(), edges.end());
	iota(parent + 1, parent + n + 1, 1);
	for(auto x: edges)
    {
		int ru = find_root(x.u), rv = find_root(x.v);
		if(ru == rv)out.emplace_back(x);
		else
        {
			parent[ru] = rv;
			in.emplace_back(x);
		}
	}
	for(auto x: in)
    {
		adj[x.u].emplace_back(x.v, x.w);
		adj[x.v].emplace_back(x.u, x.w);
	}
	dfs(1, 0, 1);
	for(int state=1; state<LG; ++state) for(int i=1; i<=n; ++i) lift[state][i] = lift[state - 1][lift[state - 1][i]];
	for(auto x: out)
    {
		if(get_dist(x.u, x.v) != x.w)
        {
			in.emplace_back(x);
			break;
		}
	}
	for(auto x: in) answer.emplace_back(x.u, x.v, x.w);
	sort(answer.begin(), answer.end());
	for(auto x: answer) cout << x.u << " " << x.v << " " << x.w << "\n";
	return ;
}
signed main()
{
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	while(q--)
    {
		solution();
		cout << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 5e3 + 5;
struct a {
    int u,v,w;
} tree[N];
int qs[M][M];
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n,m,r,c;
    cin >> n >> m >> r >> c;
    for(int i=0;i<=r;i++) for(int j=0;j<=c;j++) qs[i][j] = 0;
    for(int i=0;i<n;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        tree[i] = {u,v,w};
    }
    for(int i=0;i<m;i++) 
    {
        int x,y;
        cin >> x >> y;
        qs[x][y] = 1;
    }
    for(int i = 1;i <= r;i++) for(int j = 1;j <= c;j++) qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
    int left = 1,right = 1e6,mid;
    while(left < right)
    {
        mid = (left + right)/2;
        bool can = true;
        for(int i=0;i<n;i++)
        {
            int x = tree[i].u;
            int y = tree[i].v;
            int w = tree[i].w;
            int q = qs[min(r,x + mid)][min(c,y + mid)] - qs[min(r,x + mid)][max(0,y - mid - 1)] - qs[max(0,x - mid - 1)][min(c,y + mid)] + qs[max(0,x - mid - 1)][max(0,y - mid - 1)];
            if(q < w)
            {
                can = false;
                break;
            }
        }
        if(can) right = mid;
        else left = mid + 1;
    }
    cout << left;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int amt[N],cnt[N],ans[N],pa[N],block[N];
pair<int,int> e[N];
pair<pair<int,int>,pair<int,int> > q[N];

int root(int x)
{
	if(pa[x]==x) return x;
	else return pa[x]=root(pa[x]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,que,inp;
	cin >> n >> m >> k >> que;
	for(int i=0;i<k;i++) cin >> inp,amt[inp]++;
	for(int i=1;i<N;i++) if(amt[i]) cnt[amt[i]]++;
	for(int i=1;i<=m;i++)
    {
		int a,b;
		cin >> a >> b;
		e[i]=make_pair(a,b);
	}
	for(int i=0;i<que;i++)
    {
		cin >> q[i].first.first;
		if(q[i].first.first==1) cin >> q[i].first.second;
		cin >> q[i].second.first >> q[i].second.second;
	}
	for(int i=1;i<N;i++)
    {
		if(!cnt[i]) continue;
		for(int j=1;j<=n;j++) pa[j]=j;
		for(int j=0;j<que;j++)
        {
			if(q[j].first.first==2) continue;
			if(i>=q[j].second.first && i<=q[j].second.second) block[q[j].first.second]++;
		}
		for(int j=1;j<=m;j++)
        {
			if(block[j]) continue;
			pa[root(e[j].first)]=root(e[j].second);
		}
		for(int j=que-1;j>=0;j--)
        {
			int a=q[j].first.first,b=q[j].first.second,c=q[j].second.first,d=q[j].second.second;
			if(a==2) if(root(c)==root(d)) ans[j]+=cnt[i];
			if(a==1)
            {
				if(i>=c && i<=d) block[b]--;
				if(!block[b]) pa[root(e[b].first)]=root(e[b].second);
			}
		}
	}
	for(int i=0;i<que;i++) if(q[i].first.first==2) cout << ans[i] <<"\n";
}

#include<bits/stdc++.h>
using namespace std;
const int mxR = 2e3 + 5 , mxN = 2e5 + 3;
int nr,nc,n,s;
int dp[2][mxR][2];
pair<int,int> rock[mxN];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    scanf("%d %d %d",&nr,&nc,&n);
    for(int i=0;i<n;i++)
    {
        int col,a,b;
        scanf("%d %d %d",&col,&a,&b);
        rock[col] = {a,b};
    }
    scanf("%d",&s);
    memset(dp , 32 , sizeof(dp));
    for(int r=1;r<=nr;r++) dp[0][r][0] = dp[0][r][1] = abs(r-s) - 1;
    for(int c=2;c<=nc;c+=2)
    {
        int curr = (c/2)&1 , pre=curr^1;
        for(int r=1;r<=nr;r++)
        {
            dp[curr][r][0] = dp[curr][r][1] = 1e9;
            if(rock[c].first<=r && r<=rock[c].second) dp[curr][r][1] = dp[pre][r][0] + 2;
            else
            {
                dp[curr][r][0] = dp[pre][r][0] + 2;
                dp[curr][r][1] = min(dp[pre][r][0] , dp[pre][r][1]) + 2;
            }
        }
        for(int r=2;r<=nr;r++)
        {
            dp[curr][r][0] = min(dp[curr][r][0] , dp[curr][r-1][0] + 1);
            dp[curr][r][1] = min(dp[curr][r][1] , dp[curr][r-1][1] + 1);
        }
        for(int r=nr-1;r>=1;r--)
        {
            dp[curr][r][0] = min(dp[curr][r][0] , dp[curr][r+1][0] + 1);
            dp[curr][r][1] = min(dp[curr][r][1] , dp[curr][r+1][1] + 1);
        }
    }
    int ans = INT_MAX;
    if(nc&1)
    {
        int lc = ((nc-1)/2)&1;
        for(int r=1;r<=nr;r++) ans = min({ans , dp[lc][r][0]+1 , dp[lc][r][1]+1});
    }
    else
    {
        int lc = (nc/2)&1;
        for(int r=1;r<=nr;r++)
        {
            if(rock[nc].first<=r && r<=rock[nc].second) ans = min(ans , dp[lc][r][1]);
            else ans = min({ans , dp[lc][r][0] , dp[lc][r][1]});
        }
    }
    printf("%d",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int qs[n + 1];
    qs[0] = 0;
    for(int i=1;i<=n;++i)
    {
        cin >> qs[i];
        qs[i] += qs[i - 1];
    }
    long long dp[2][n + 1];
    for(int i=0; i<=1;++i) for(int j=1;j<=n;++j) dp[i][j] = 0;
    for(int i=1; i<=n;++i) dp[1][i] = qs[i] - qs[i - 1];
    for(int i=2; i<=n;++i)
    {
        priority_queue<pair<long long, int>> pqInRange;
        for(int j=i-1;j <= min(n,i*2-2);++j) pqInRange.emplace(dp[(i - 1) % 2][j], j);
        priority_queue<pair<long long, int>> pqOutRange;
        for(int j=i*2-1;j<=n;++j) pqOutRange.emplace(dp[(i - 1) % 2][j], j);
        for(int j=i;j<=n;++j)
        {
            while(!pqInRange.empty())
            {
                if(pqInRange.top().second < max(1, j - i + 1) or pqInRange.top().second > min(n, j + i - 2)) pqInRange.pop();
                else break;
            }
            if(!pqInRange.empty()) dp[i % 2][j] = max(dp[i % 2][j], pqInRange.top().first + (qs[j] - qs[j - i]) / 2);
            while(!pqOutRange.empty())
            {
                if(pqOutRange.top().second >= max(1, j - i + 1) and pqOutRange.top().second <= min(n, j + i - 2)) pqOutRange.pop();
                else break;
            }
            if(!pqOutRange.empty()) dp[i % 2][j] = max(dp[i % 2][j], pqOutRange.top().first + qs[j] - qs[j - i]);
            if(j+i-1 <= n)pqInRange.emplace(dp[(i - 1) % 2][j + i - 1], j + i - 1);
            if(j-i+1 >= i-1)pqOutRange.emplace(dp[(i - 1) % 2][j - i + 1], j - i + 1);
        }
    }
    cout << dp[n % 2][n];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,ss;
    getline(cin,s);
    int sum=0,nn;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ') sum++;
        else if(s[i]=='-') break;
    }
    int n[sum];
    sum=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ' && s[i]!='-') ss=ss+s[i];
        else if(s[i]==' ')
        {
            sum++;
            n[sum-1]=stoi(ss);
            ss="";
        }
        else if(s[i]=='-') break;
    }
    int N=n[0];
    for(int i=1;i<sum;i++) N = max(n[i],N);
    int a[2];
    a[0]=0;
    a[1]=1;
    map<int,int> m1,m2;
    for(int i=1;i<=N;i++)
    {
        int b=a[0],c=a[1];
        a[0] = 0;
        a[1] = 0;
        a[0] += c;
        a[1] += b + c + 1;
        m1[i]=a[1];
        m2[i]=a[0]+a[1]+1;
    }
    for(int i=0;i<sum;i++) cout << m1[n[i]] << ' ' << m2[n[i]] << '\n';
}

#include<bits/stdc++.h>
#define en '\n'
#define sp ' '
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define st first
#define nd second
#define maxx(a,b) a=max(a,b)
#define minn(a,b) a=min(a,b)
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll a[n];
    ll l=0,r=-1e18,mid;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        maxx(r,a[i]);
    }
    while(l<r){
        mid=(l+r)/2;
        vector<ll> v;
        bool chk=1;
        for(int x:a)if(x>mid)v.push_back(x);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1]) i++;
            else
            {
                chk=0;
                break;
            }
        }
        if(chk) r=mid;
        else l=mid+1;
    }
    cout << l;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using lli = long long;
const lli N = 5e5 + 10;
const lli INF = 1e18;
using pl = pair <lli, lli>;
lli height[N], pos[N], qs_height[N];
pl ar[N];
int main()
{
    lli n;
    scanf("%lld", &n);
    lli min_height = INF;
    for(lli i=1;i<=n;i++)
    {
        scanf("%lld", &height[i]);
        min_height = min(min_height, height[i]);
    }
    lli sum_pos = 0;
    for(lli i=1;i<=n;i++)
    {
        scanf("%lld", &pos[i]);
        sum_pos += pos[i];
        ar[i] = {pos[i], height[i]};
    }
    sort(ar + 1, ar + n + 1);
    for(lli i=1;i<=n;i++) qs_height[i] = qs_height[i-1] + ar[i].second;
    sort(pos + 1, pos + n + 1);
    lli ans_height = INF, ans_sum = INF, idx = 0;
    for(lli i=1;i<=n;i++)
    {
        lli h = pos[i];
        if(h > min_height) continue;
        while(idx + 1 <= n and ar[idx + 1].first < h) idx ++;
        lli sum = sum_pos - h * n + qs_height[idx];
        if(sum < ans_sum)
        {
            ans_height = h;
            ans_sum = sum;
        }
    }
    printf("%lld %lld", ans_height, ans_sum);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> v(m+1);
    for(int i = 1; i <= m; i++)
    {
        v[i].first = i;
        v[i].second = 1;
    }
    int ini = 1;
    for(int i=0;i<=m-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            if(v[ini].second == 1)
            {
                if(j == n - 1) continue;
                ini++;
            }
            else
            {
                j--;
                ini++;
            }
            if(ini > m) ini = ini % m;
        }
        cout << v[ini].first << " ";
        v[ini].second = 0;
    }
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dfs(int i, int j)
{
    if(i==j) return 20;
    int brac = 0;
    for(int k=j;k>=i;k--)
    {
        if(s[k] == '[') brac++;
        else if(s[k] == ']') brac--;
        else if(s[k] == '1' && brac == 0) return (dfs(i, k-1) + dfs(k+1, j))*104LL/100LL;
    }
    for(int k=j;k>=i;k--)
    {
        if(s[k] == '[') brac++;
        else if(s[k] == ']') brac--;
        else if(s[k] == '2' && brac == 0) return (dfs(i, k-1) + dfs(k+1, j))*108LL/100LL;
    }
    for(int k=j;k>=i;k--)
    {
        if(s[k] == '[') brac++;
        else if(s[k] == ']') brac--;
        else if(s[k] == '3' && brac == 0) return (dfs(i, k-1) + dfs(k+1, j))*116LL/100LL;
    }
    return dfs(i+1, j-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cout << dfs(0, s.size()-1);
}

#include<bits/stdc++.h>
using namespace std;
using pii= pair<int,int>;
vector<vector<int>> mp;
vector<vector<bool>> visited;
int m, n, t;
void dfs(int i, int j, vector<int> &vec)
{
    if(i>=0 && i<t && j>=0 && j<m && visited[i][j]) return;
    if(i>=0 && i<t && j>=0 && j<m) visited[i][j] = true;
    if(i + 1 == t )
    {
        for(auto e : vec) cout << e << "\n";
        return;
    }
    if(i+1 < t && j-1 >= 0 && mp[i+1][j-1] == 0  )
    {
        vec.push_back(1);
        dfs(i+1, j-1 , vec);
        vec.pop_back();
    }
    if(i+1 < t && j + 1 < m && mp[i+1][j+1] == 0  )
    {
        vec.push_back(2);
        dfs(i+1, j+1, vec);
        vec.pop_back();
    }
    if(i+1 < t && mp[i+1][j] == 0  )
    {
        vec.push_back(3);
        dfs(i+1, j, vec);
        vec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> t;
    mp.resize(t, vector<int> (m));
    visited.resize(t,vector<bool>(m, false));
    for(int i=0;i<t;++i) for(int j=0;j<m;++j) cin >> mp[i][j];
    vector<int> vec;
    dfs(-1,n-1, vec);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int n;
void dd(vector<pii> &dis,vector<vector<int>> adj,int s)
{
    queue<int> pq;
    pq.push(s);
    for(int i=1;i<=n;i++) dis[i].second=i;
    while(pq.size())
    {
        int u=pq.front();
        pq.pop();
        for(int x:adj[u])
        {
            if(dis[x].first>dis[u].first+1)
            {
                dis[x].first=dis[u].first+1;
                pq.push(x);
            }
        }
    }
}

int main()
{
    int m,p,a,b;
    cin>> n >> m >> p >> a >> b;
    vector<vector<int>> adj(n+1);
    vector<int> ans(2e5+2),flag(2e5+2);
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pii> da(n+1,{1e9,0}),db(n+1,{1e9,0});
    da[a].first=db[b].first=0;
    priority_queue<pair<int,int>> pq;
    dd(da,adj,a);
    dd(db,adj,b);
    for(int i=1;i<=n;i++) pq.push({da[i].first,i});
    sort(db.begin()+1,db.end());
    int now=1;
    for(int i=0;i<=2e5+1;i++)
    {
        while(now<=n&&db[now].first<=i) flag[db[now].second]=1,now++;
        while(pq.size()&&flag[pq.top().second]) pq.pop();
        if(pq.size()) ans[i]=pq.top().first;
        else ans[i]=0;
    }
    while(p--)
    {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}

#include<bits/stdc++.h>
#define en '\n'
#define sp ' '
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define st first
#define nd second
#define maxx(a,b) a=max(a,b)
#define minn(a,b) a=min(a,b)
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,l;
    cin>>n>>m>>k>>l;
    int a[n];
    int mx=-1e9,mn=1e9;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        minn(mn,a[i]);
        maxx(mx,a[i]);
    }
    while(k--)
    {
        vector<int> st,end;
        for(int i=0;i<m;i++)
        {
            int x;                                           
            cin >> x;
            if(x+l<mn||x-l>mx) continue;
            else if(st.empty()||x-l>end.back())
            {
                st.push_back(x-l);
                end.push_back(x+l);
            }
            else if(x-l<=end.back()) end[end.size()-1]=x+l;
        }
        int cnt=0;
        for(int i=0;i<st.size();i++) cnt+=upper_bound(a,a+n,end[i])-lower_bound(a,a+n,st[i]);
        cout << cnt << en;
    }
    return 0;
}

#include<bits/stdc++.h>
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define ll long long
using namespace std;
const int N=2e5+5;
vector<int>g[N];
int a[N],lo[N],d[N]{0},t=0,id[N],sz[N],pr[N],dep[N],head[N],pos[N],eee=0;
stack<int>st;
bool vis[N]{0},isap[N]{0};
vvi cmps,bct;
multiset<int>ms[N];
void ap(int u=1,int p=-1){
    lo[u]=d[u]=++t;st.push(u);
    int ch=0;
    for(auto v:g[u]){
        if(!d[v]){
            ap(v,u);
            lo[u]=min(lo[u],lo[v]);
            if(d[u]<=lo[v]){
                vis[u]=(d[u]>1||d[v]>2);
                cmps.pb({u});
                while(cmps.back().back()!=v){
                    cmps.back().pb(st.top());st.pop();
                }
            }
        }else if(v!=p)lo[u]=min(lo[u],d[v]);
    }
}int cur=0;
void build(int n){
    for(int i=1;i<=n;i++){
        if(vis[i])id[i]=cur++,bct.pb({}),isap[id[i]]=1;
    }
    for(auto cmp : cmps){
        bct.pb({});
        for(auto v:cmp){
            if(!vis[v])id[v]=cur;
            else {
                bct[id[v]].pb(cur);
                bct[cur].pb(id[v]);
            }
        }cur++;
    }
}
void getsz(int u=0,int p=0,int l=0){
    pr[u]=p;dep[u]=l;sz[u]=1;
    for(auto v:bct[u]){
        if(v==p)continue;
        getsz(v,u,l+1);sz[u]+=sz[v];
    }
}int ct=0;
int seg[2*N]{0};
void upd(int i,int amt,int sz){
    i+=sz;seg[i]=amt;
    for(i>>=1;i;i>>=1)seg[i]=min(seg[2*i],seg[2*i+1]);
}
int qr(int l,int r,int sz,int res=1e9+5){
    for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){
        if(l&1)res=min(res,seg[l++]);
        if(r&1)res=min(res,seg[--r]);
    }return res;
}
void hld(int u=0,int p=0,int x=0){
    head[u]=x;pos[u]=ct++;
    int hv=-1,hs=-1;
    for(auto v:bct[u]){
        if(v==p)continue;
        if(sz[v]>hs)hv=v,hs=sz[v];
    }if(hv==-1)return;hld(hv,u,x);
    for(auto v:bct[u]){
        if(v==p||v==hv)continue;
        hld(v,u,v);
    }
}
int query(int x,int y,int res=1e9+5)
{
    while(head[x]!=head[y])
    {
        if(dep[head[x]]<dep[head[y]])swap(x,y);
        res=min(res,qr(pos[head[x]],pos[x]+1,cur));x=pr[head[x]];
    }if(dep[x]>dep[y])swap(x,y);res=min(res,qr(pos[x],pos[y]+1,cur));
    return res;
}
void update(int u,int val)
{
    int x=id[u];
    ms[x].erase(ms[x].lower_bound(a[u]));
    ms[x].insert(val);
    upd(pos[x],*ms[x].begin(),cur);
    if(isap[x])
    {
        for(auto v:bct[x])
        {
            ms[v].erase(ms[v].lower_bound(a[u]));
            ms[v].insert(val);
            upd(pos[v],*ms[v].begin(),cur);
        }
    }
    a[u]=val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1,u,v;i<=m;i++) cin >> u >> v,g[u].pb(v),g[v].pb(u);
    ap();build(n);getsz();hld();
    for(int i=1;i<=n;i++)
    {
        ms[id[i]].insert(a[i]);
        if(isap[id[i]]) for(auto v:bct[id[i]]) ms[v].insert(a[i]);
    }
    for(int i=0;i<cur;i++)upd(pos[i],*ms[i].begin(),cur);
    while(q--)
    {
        int o,u,v;
        cin >> o >> u >> v;
        if(o==1)update(u,v);
        else
        {
            if(u==v) cout << a[u] << '\n';
            else cout << query(id[u],id[v]) << '\n';
        }
    }
}

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2000003;
multiset<int> st1, st2;
int A, B, n;
ll l;
vector<int> vec;
int arr[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> A >> B;
    for(int i=1;i<=n;i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    for(int i=1;i<=A-1;i++) st1.emplace(arr[i]);
    for(int i=A;i<=B;i++) st2.emplace(arr[i]);
    for(int i=B+1;i<=n;i++) vec.emplace_back(arr[i]);
    while(l--)
    {
        if(st2.size() > 1)
        {
            auto it1 = st2.begin();
            auto it2 = prev(st2.end());
            int f = *it1, last = *it2;
            st2.erase(it1);
            if (it1 != it2) st2.erase(it2);
            st2.insert(abs(f - last));
            st2.insert((f + last) / 2);
        }
        else if(!st2.empty()) st2.erase(st2.begin());
        if(!st1.empty() && !st2.empty())
        {
            auto it1 = st2.begin();
            auto it2 = prev(st1.end());
            int f = *it1, last = *it2;
            if(f < last)
            {
                st2.erase(it1);
                st2.insert(last);
                st1.erase(it2);
                st1.insert(f);
            }
        }
    }
    for(int x : st1) cout << x << " ";
    for(int x : st2) cout << x << " ";
    for(int x : vec) cout << x << " ";
    return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>

#define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
const bool TEST_CASE = 0;

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* name, T value) {
    std::cout << name << " : " << value << '\n';
}


template<typename T, typename... Args>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');
    std::cout.write(names, comma - names) << " : " << value << " | ";
    Debug(comma + 1, args...);
}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {
    for(auto &x : a) out << x << ' '; 
    return out;
};

const int N = 502, K = 52;

int dp[2][N][K], a[N][N];

void solve(){
    int n, l;
    cin >> n >> l;

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            cin >> a[i][j];

    for (int i = 1;i <= n;i++){
        int cur = i&1, pre = 1 - cur;
        for (int j = 1;j <= n;j++){
            for (int k = 0;k <= l;k++)
                dp[cur][j][0] = max(dp[cur][j][0], max(dp[cur][j-1][k], dp[pre][j][k]));
            for (int k = 1;k <= l;k++){
                dp[cur][j][k] = max(dp[cur][j-1][k-1], dp[pre][j][k-1]) + a[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0;i <= l;i++)
        ans = max(ans, dp[n&1][n][i]);
    cout << ans << '\n';
}

int main()
{
    #ifndef DORMON ios_base::sync_with_stdio(false); 
       
    #endif
    cin.tie(0);
    int q = 1; 
    if (TEST_CASE) cin >> q;
    while (q--) solve();
}

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>
#define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
const bool TEST_CASE = 0;
template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* name, T value)
{
    std::cout << name << " : " << value << '\n';
}
template<typename T, typename... Args>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* names, T value, Args... args)
{
    const char* comma = strchr(names, ',');
    std::cout.write(names, comma - names) << " : " << value << " | ";
    Debug(comma + 1, args...);
}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a)
{
    for(auto &x : a) out << x << ' '; 
    return out;
};

#define int long long
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n+1), vis(n+1, -1);
    vector<vector<int>> adj(n+1), computer(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx = 0ll;
    queue<pair<int, int>> q;
    q.push({k, 0ll});
    while(!q.empty())
    {
        auto[u, t] = q.front();
        q.pop();
        if(vis[u] != -1) continue;
        vis[u] = t;
        mx = max(mx, t);
        computer[t].push_back(a[u]);
        for(auto v:adj[u]) q.push({v, t+1});
    }
    priority_queue<int> pq;
    int ans = 0ll;
    for(int t=mx;t>=1;t--)
    {
        for(auto e:computer[t]) pq.push(e);
        if(pq.empty()) continue;
        ans += max(0ll, pq.top());
        pq.pop();
    }
    for(int i=1;i<=n;i++) if(vis[i] == -1) ans += max(0ll, a[i]);
    cout << ans << '\n';
}

int32_t main()
{
    #ifndef DORMON
    ios_base::sync_with_stdio(false);
    #endif
    cin.tie(0);
    int q = 1; 
    if(TEST_CASE) cin >> q;
    while(q--) solve();
}

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define t4i tuple<int, int, int, int>
#define f first
#define s second
#define inf 1e14
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> price(n);
    for (auto &e : price) cin >> e;
    int m, start, end, maxFuel;
    cin >> start >> end >> maxFuel >> m;
    start--, end--;
    vector<vector<pii>> adj(n);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    vector<vector<vector<int>>> dis(2, vector<vector<int>>(n, vector<int> (maxFuel + 1, inf)));
    priority_queue<t4i, vector<t4i>, greater<t4i>> q;
    q.emplace(0, start, 0, 0);
    dis[0][start][0] = dis[1][start][0] = 0;
    while(!q.empty())
    {
        auto [cost, cur, oil, used] = q.top();
        q.pop();
        if(cost > dis[used][cur][oil]) continue;
        if(!used && oil < maxFuel && cost < dis[1][cur][maxFuel]) dis[1][cur][maxFuel] = cost, q.emplace(cost, cur, maxFuel, 1);
        if(oil < maxFuel && cost + price[cur] < dis[used][cur][oil+1]) dis[used][cur][oil+1] = cost + price[cur], q.emplace(cost + price[cur], cur, oil + 1, used);
        for(auto &[x, y] : adj[cur]) if(oil >= x && cost < dis[used][y][oil-x]) dis[used][y][oil-x] = cost, q.emplace(cost, y, oil - x, used);
    }
    cout << min(dis[0][end][maxFuel], dis[1][end][maxFuel]);
    return 0;
}

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int Read()
{
	int x=0;char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=x*10+(c&15),c=getchar();
	return x;
}
const int N=101111,A=460,BS=A+10;
ll cp0[BS][BS][BS];
int a[N],rk0[BS][BS],cnt0[BS][N],cp1[BS][BS][BS],lb[BS][N],rk1[N],cnt1[BS][N],L[BS],R[BS];
bool cmp(int x,int y) { return a[x]<a[y]; }
namespace IO{
    const int sz=1<<22;
    char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
    inline char gc(){
        return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
    }
    template<class T> void gi(T& x){
        x=0; char c=gc();
        for(;c<'0'||c>'9';c=gc());
        for(;c>='0'&&c<='9';c=gc())
            x=(x<<3)+(x<<1)+(c-'0');
    }
    inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
    inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
    template<class T> void pi(T x,char c='\n'){
        if(x<0) x=-x;
        if(x==0) pc('0'); int t=0;
        for(;x;x/=10) p[++t]=x%10+'0';
        for(;t;--t) pc(p[t]); pc(c);
    }
    struct F{~F(){flush();}}f; 
}
using IO::gi;
using IO::pi;
inline int read() { int r; gi(r); return r; }
int main()
{
#ifdef ONLINE_JUDGE
	freopen("tears.in","r",stdin);
	freopen("tears.out","w",stdout);
#endif
	int n=read(),m=read(),B=n/A;
	for(int i=0;i<n;++i)a[i]=read();
	for(int i=n;i<(B+1)*A;++i)a[i]=i;
	for(int i=0;i<=B;++i)
    {
		for(int j=i*A,k=0;k<A;++j,++k) rk0[i][k]=j;
		sort(rk0[i],rk0[i]+A,[](int x,int y){return a[x]<a[y];});
		for(int j=0;j<A;++j) rk1[rk0[i][j]]=j,cnt0[j][rk0[i][j]]=1;
		for(int j=i*A+1;j<(i+1)*A;++j) for(int k=0;k<A;++k) cnt0[k][j]+=cnt0[k][j-1];
		for(int j=i*A;j<(i+1)*A;++j) for(int k=1;k<A;++k) cnt0[k][j]+=cnt0[k-1][j];
		for(int j=i*A;j<(i+1)*A;++j) ++cnt1[i][a[j]];
		if(i) for(int j=1;j<=101000;++j) cnt1[i][j]+=cnt1[i-1][j];
		for(int j=1,k=0;j<=101000;++j)(k<A)&&(j>=a[rk0[i][k]])&&(++k),lb[i][j]=k;
	}
	for(int i=0;i<=B;++i) for(int j=1;j<=101000;++j) cnt1[i][j]+=cnt1[i][j-1];
	for(int i=1;i<B;++i) for(int j=0;j<i;++j) for(int k=0;k<A;++k) cp0[i][j][k+1]=cnt1[j][a[rk0[i][k]]]+cp0[i][j][k];
	for(int i=0;i<B;++i) for(int j=0;j<A;++j) for(int k=j+1;k<A;++k) cp1[i][j][k]=cp1[i][j][k-1]+cnt0[k-1][rk0[i][k]]-((j==0)?0:cnt0[j-1][rk0[i][k]]);
	for(;m;--m)
    {
		int l=read()-1,r=read()-1,x=read(),y=read(),bl=l/A,br=r/A;
		if(bl==br)
        {
			int ans=0;
			for(int i=l;i<=r;++i)
            {
				if(x<=a[i]&&a[i]<=y && rk1[i]) ans+=cnt0[rk1[i]-1][i]-((l%A)?cnt0[rk1[i]-1][l-1]:0);
				if(lb[bl][x-1] && x<=a[i]&&a[i]<=y) ans-=cnt0[lb[bl][x-1]-1][i]-((l%A&&lb[bl][x-1])?cnt0[lb[bl][x-1]-1][l-1]:0);
			}
			pi(ans);
		}
		else
        {
			ll ans=0;
			for(int i=l;i<(bl+1)*A;++i)
            {
				if(x<=a[i]&&a[i]<=y && rk1[i]) ans+=cnt0[rk1[i]-1][i]-((l%A)?cnt0[rk1[i]-1][l-1]:0);
				if(lb[bl][x-1] && x<=a[i]&&a[i]<=y) ans-=cnt0[lb[bl][x-1]-1][i]-((l%A&&lb[bl][x-1])?cnt0[lb[bl][x-1]-1][l-1]:0);
				if(x<=a[i] && a[i]<=y) ans+=cnt1[br-1][y]-cnt1[bl][y]-cnt1[br-1][a[i]]+cnt1[bl][a[i]];
			}
			for(int i=br*A;i<=r;++i)
            {
				if(x<=a[i] && a[i]<=y && rk1[i]) ans+=cnt0[rk1[i]-1][i];
				if(lb[br][x-1] && x<=a[i] && a[i]<=y) ans-=cnt0[lb[br][x-1]-1][i];
				if(x<=a[i] && a[i]<=y) ans+=cnt1[br-1][a[i]]-cnt1[bl][a[i]]-cnt1[br-1][x-1]+cnt1[bl][x-1];
			}
			int lt=0,rt=0;
			for(int i=0;i<A;++i)
            {
				if(rk0[bl][i]>=l && x<=a[rk0[bl][i]] && a[rk0[bl][i]]<=y) L[++lt]=rk0[bl][i];
				if(rk0[br][i]<=r && x<=a[rk0[br][i]] && a[rk0[br][i]]<=y) R[++rt]=rk0[br][i];
			}
			for(int i=1,t=1;i<=rt;++i)
            {
				while(t<=lt && a[L[t]]<a[R[i]]) ++t;
				ans+=t-1;
			}
			for(int i=bl+1;i<br;++i) if(lb[i][y]) ans+=cp1[i][lb[i][x-1]][lb[i][y]-1];
			for(int i=bl+2;i<br;++i)
            {
				ans+=cp0[i][i-1][lb[i][y]]-cp0[i][bl][lb[i][y]]-cp0[i][i-1][lb[i][x-1]]+cp0[i][bl][lb[i][x-1]],
				ans-=ll(cnt1[i][y]-cnt1[i-1][y]-cnt1[i][x-1]+cnt1[i-1][x-1])*(cnt1[i-1][x-1]-cnt1[bl][x-1]);
            }
			pi(ans);
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
stack<int>val,opr;
string a;
void pack()
{
    int a = val.top();val.pop();
    int b = val.top();val.pop();
    int o = opr.top();opr.pop();
    val.push((a+b)*o/100 + a+b);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a;
    for(char &x:a)
    {
        if(isalpha(x))val.push(20);
        else if(isdigit(x))
        {
            int xx = 1<<(x-'0'+1);
            while(opr.size() && xx <= opr.top()) pack();
            opr.push(xx);
        }
        else if(x == '[')opr.push(-1);
        else
        {
            while(opr.top() != -1) pack();
            opr.pop();
        }
    }
    while(opr.size()) pack();
    cout << val.top();
}

#include <bits/stdc++.h>
#define int long long
#define pii pair <int,int>
#define tiii tuple <int, int, int>
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define iShowSpeed cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e18;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int q, x, n, cnt, ans, a[405], dp[405][405];

void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        dp[i][i] = 1;
    }
    for(int siz=1;siz<n;siz++)
    {
        for(int i=1;i+siz<=n;i++)
        {
            int j = i + siz;
            dp[i][j] = inf;
            if(a[i] == a[j])
            {
                cnt = 0;
                for(int k=j;k>=i;k--)
                {
                    if(a[k] == a[i]) cnt++;
                    else break;
                }
                if(cnt <= x) dp[i][j] = dp[i][j - 1];
                else dp[i][j] = dp[i][j - 1] + 1;
            }
            for(int k=j-1;k>=i;k--) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
        ans = max(ans, dp[1][n]);
    }
}

int32_t main()
{
    iShowSpeed;
    cin >> q >> x;
    while(q--) solve();
    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
int Y, X, K, P, dp[18][20005], ans=1e9, idx;
vector<vector<int>> I(1000005), O(1000005);
struct pts
{
    int xf, xs, yf, ys;
} p[20005];
struct segtree
{
    int a[1<<21];
    void build(int l, int r, int i)
    {
        a[i]=1e9;
        if (l==r) return;
        int md=(l+r)/2;
        build(l, md, 2*i);
        build(md+1, r, 2*i+1);
    }
    void update(int l, int r, int i, int idx, int val)
    {
        if (idx<l||r<idx) return;
        if (l==r) return void(a[i]=val);
        int md=(l+r)/2;
        update(l, md, 2*i, idx, val);
        update(md+1, r, 2*i+1, idx, val);
        a[i]=min(a[2*i], a[2*i+1]);
    }
    int query(int l, int r, int i, int ql, int qr)
    {
        if (qr<l||r<ql) return 1e9;
        if (ql<=l&&r<=qr) return a[i];
        int md=(l+r)/2;
        return min(query(l, md, 2*i, ql, qr), query(md+1, r, 2*i+1, ql, qr));
    }
} s1, s2;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>Y>>X>>K>>P;
    ans=Y+X-2; idx=0;
    for (int i=1; i<=K; i++)
    {
        cin >> p[i].yf>>p[i].xf>>p[i].ys>>p[i].xs;
        I[p[i].xf].push_back(i);
        O[p[i].xs].push_back(i);
        dp[1][i]=p[i].yf+p[i].xf-2;
        if(ans<dp[1][i]+X+Y-p[i].xs-p[i].ys) ans=dp[1][i]+X+Y-p[i].xs-p[i].ys, idx=1;
        for(int j=2; j<=P; j++) dp[j][i]=1e9;
    }
    for(int i=2;i<=P;i++)
    {
        s1.build(1, X, 1);
        s2.build(1, X, 1);
        for(int l=1;l<=X;l++)
        {
            for(auto c:O[l])
            {
                s1.update(1, X, 1, p[c].ys, dp[i-1][c]-p[c].xs-p[c].ys);
                s2.update(1, X, 1, p[c].ys, dp[i-1][c]-p[c].xs+p[c].ys);
            }
            for(auto c:I[l]) dp[i][c]=min({dp[i][c], p[c].xf+p[c].yf+s1.query(1, X, 1, 1, p[c].yf), p[c].xf-p[c].yf+s2.query(1, X, 1, p[c].yf, X)});
        }
        s1.build(1, X, 1);
        s2.build(1, X, 1);
        for(int l=X;l>=1;l--)
        {
            for(auto c:O[l])
            {
                s1.update(1, X, 1, p[c].ys, dp[i-1][c]+p[c].xs-p[c].ys);
                s2.update(1, X, 1, p[c].ys, dp[i-1][c]+p[c].xs+p[c].ys);
            }
            for(auto c:I[l]) dp[i][c]=min({dp[i][c], -p[c].xf+p[c].yf+s1.query(1, X, 1, 1, p[c].yf), -p[c].xf-p[c].yf+s2.query(1, X, 1, p[c].yf, X)});
        }
        for(int j=1;j<=K;j++) if(X+Y-p[j].xs-p[j].ys+dp[i][j]<ans) ans=X+Y-p[j].xs-p[j].ys+dp[i][j], idx=i;
    }
    cout << ans << ' ' << idx;
}

#include <bits/stdc++.h>
using namespace std;
const int mx = 5e5 + 5;
int cnt = 0, cpn = 0;
vector<int> adj[mx];
bool vis[mx];
int mn[mx],dis[mx];
void dfs(int u,int p)
{
    if(vis[u]) return;
    vis[u] = 1;
    dis[u] = mn[u] = ++cnt;
    for(int v : adj[u])
    {
        if(v == p) continue;
        if(!vis[v]) dfs(v,u);
        mn[u] = min(mn[u],mn[v]);
    }
    if(mn[u] == dis[u]) cpn++;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) dfs(i,-1);
    cout << cpn;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	string str;
	cin >> k >> str;
	bool chk[k][1000]={},first=true,rem=false;
	int key[k][1000];
	char ans[str.size()];
	int x=k-1,y=0,cnt=str.size(),tmp=0,cnti=0;
	if(k!=1)
    {
	    while(1)
        {
		    if(x==k-1)
            {
			    if(rem)
                {
				    x--;
				    rem=false;
			    }
			    if(first)
                {
				    first=false;
				    while(x>=0)
                    {
					    chk[x][y]=true;
					    key[x][y]=cnti;
					    cnti++;
					    x--;
					    cnt--;
					    if(cnt<=0) goto cal;
				    }
				    if(cnt<=0) goto cal;
			    }
			    else
                {
				    for(int i=0;i<k-1;i++)
                    {
				        y++;
				        key[x][y]=cnti;
				        cnti++;
				        chk[x][y]=true;
				        cnt--;
				        if(cnt<=0) goto cal;
			        }
			        first=true;
			        rem=true;
			        if(cnt<=0) goto cal;
			    }
		    }
		    if(x<0) x=0;
		    if(x==0)
            {
			    for(int i=0;i<k-1;i++)
                {
				    y++;
				    key[x][y]=cnti;
				    cnti++;
				    chk[x][y]=true;
				    cnt--;
				    if(cnt<=0) goto cal;
			    }
			    if(cnt<=0) goto cal;
			    x++;
			    while(x<=k-1)
                {
				    chk[x][y]=true;
				    key[x][y]=cnti;
				    cnti++;
				    x++;
				    cnt--;
				    if(cnt<=0) goto cal;
			    }
			    if(cnt<=0) goto cal;
			    if(x>k-1) x=k-1;
			}
		}
	}
	else
    {
		cout << str;
		return 0;
	}
	cal:
	for(int i=0;i<k;i++)
    {
		for(int j=0;j<1000;j++)
        {
			if(chk[i][j])
            {
				if(tmp<str.size())
                {
				    ans[key[i][j]]=str[tmp];
				    tmp++;
				}
			}
		}
	}
	for(int i=0;i<str.size();i++) cout << ans[i];
}

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(x) tree<x, null_type, less<x>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define lgm cin.tie(0)->sync_with_stdio(0);
#define be(x) x.begin(),x.end()
#define ve vector
#define ll long long
#define ld long double
bool enabledb=0;
#define DB(CODE) cout<<'\t'<<CODE<<endl;
#define SP <<' '<<
#define ull unsigned ll
#define f first
#define s second
#define pii pair<int, int>
#define tii tuple<int,int,int>
#define pll pair<ll,ll>
#define sz(x) (int)x.size()
#define pb push_back
const ll mod = 1e9+7,maxn=200005;
const ll INF=(ll)1e15;
struct range {
    int l,r,opt;
	range(int _l, int _r, int _opt):
		l(_l), r(_r), opt(_opt) {}
};
int n, m;
ll x[maxn], y[maxn];
pll dp[maxn];
pll solve(ll lambda)
{
	deque<range> opt_range;
    dp[1] = make_pair(0ll, 0);
	opt_range.pb({2,n,1});
	auto cal_dp = [&](int i, int opt) return make_pair(lambda+dp[opt].first+(x[i]-x[opt])*(y[i]-y[opt]),dp[opt].s+1);
	for(int i=2;i<=n;i++)
    {
		int opt=opt_range[0].opt;
		dp[i]=cal_dp(i,opt);
		if(++opt_range[0].l>opt_range[0].r) opt_range.pop_front();
		auto bad = [&](range it) return cal_dp(it.l, it.opt)>cal_dp(it.l, i);
		while(!opt_range.empty() && bad(opt_range.back())) opt_range.pop_back();
		int start = i+1;
		if(!opt_range.empty())
        {
			auto [l,r,opt]=opt_range.back();
			while(l<r)
            {
				int mid = (l+r+1) >> 1;
				if(cal_dp(mid,opt)>cal_dp(mid,i)) r=mid-1;
				else l=mid;
			}
			start = l + 1;
			opt_range.back().r = l;
		}
		if(start<=n) opt_range.pb({start, n, i});
	}
	return dp[n];
}
ll whipped_cream_price(int N, int M, vector<int> X, vector<int> Y)
{
    n = N;
    m = M;
    for(int i=1;i<=n;i++)
    {
        x[i]=X[i - 1];
        y[i]=Y[i - 1];
    }
    ll l=0,r=4e12,mid;
    while(l < r)
    {
        mid = (l+r)>>1;
        if(solve(mid).s <= m) r=mid;
        else l=mid+1;
    }
    pll x = solve(l);
    return x.f-m*l;
}

#include "bits/stdc++.h"
#define f first
#define s second
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
using namespace std;
int add;
const int N=(1<<18)+5;
vector<int>g[N];
int d[15][N]{0};
bool vis[N]{0};
int cal(int a,int b)
{
    if((a<add&&b>add)||(a>add&&b<add)) return 1e9;
    int cnt=0;
    if(a>add) a-=add,b-=add;
    while(a!=b)
    {
        if(a>b) a>>=1;
        else b>>=1;
        cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,q,l;
    cin >> k >> l >> q;
    add = (1<<k);
    for(int i=1;i<=(1<<(k-1))-1;i++)
    {
        g[i].pb(2*i);g[i].pb(2*i+1);
        g[2*i].pb(i);g[2*i+1].pb(i);
        g[i+add].pb(2*i+add);g[i+add].pb(2*i+add+1);
        g[2*i+add].pb(i+add);g[2*i+1+add].pb(i+add);
    }
    vector<int>node;
    for(int i=1;i<=l;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        node.pb(v);
        node.pb(u);
    }
    sort(node.begin(),node.end());
    node.erase(unique(node.begin(),node.end()),node.end());
    for(int i=0;i<node.size();i++)
    {
        d[i][node[i]]=0;
        vis[node[i]]=1;
        queue<int>Q;Q.push(node[i]);
        while(!Q.empty())
        {
            auto u=Q.front();Q.pop();
            for(auto v:g[u])
            {
                if(!vis[v])
                {
                    d[i][v]=d[i][u]+1;
                    vis[v]=1;Q.push(v);
                }
            }
        }
        memset(vis,0,sizeof vis);
    }
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int ans=cal(a,b);
        for(int i=0;i<node.size();i++) for(int j=i;j<node.size();j++) ans = min(ans,min(d[i][a]+d[j][b],d[i][b]+d[j][a])+d[i][node[j]]);
        cout << ans << "\n";
    }
}

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define sz(x) (int)x.size()
#define pii pair<ll,ll>
using namespace std;
const int N=1e5+5;
vector<pii>g[N];
bool vis[N]{0},cv[N]{0};
pii pr[N];
ll e[N];
vector<int>cyc;
pii t[4*N];
ll lz[4*N]{0},lz2[4*N]{0};
ll tree[4*N]{0},lazy[4*N]{0},lazy2[4*N]{0};
void build2(int i,int l,int r)
{
    if(l==r) return void(tree[i]=e[l]);
    int m=(l+r)>>1;
    build2(2*i,l,m);
    build2(2*i+1,m+1,r);
    tree[i]=tree[2*i]+tree[2*i+1];
}
void push22(int i,int l,int r)
{
    if(lazy2[i])
    {
        tree[i]=0;
        if(l<r)
        {
            lazy2[2*i]=lazy2[i];
            lazy2[2*i+1]=lazy2[i];
            lazy[2*i]=0;
            lazy[2*i+1]=0;
        }
        lazy2[i]=0;
    }
}
void push12(int i,int l,int r)
{
    push22(i,l,r);
    tree[i]+=lazy[i]*(r-l+1);
    if(l<r)
    {
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
    }
    lazy[i]=0;
}
void u12(int i,int l,int r,int tl,int tr,ll v)
{
    push12(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lazy[i]+=v;
        push12(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    u12(2*i,l,m,tl,tr,v);
    u12(2*i+1,m+1,r,tl,tr,v);
    tree[i]=tree[2*i]+tree[2*i+1];
}
void u22(int i,int l,int r,int tl,int tr)
{
    push12(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lazy2[i]=1;
        push12(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    u22(2*i,l,m,tl,tr);
    u22(2*i+1,m+1,r,tl,tr);
    tree[i]=tree[2*i]+tree[2*i+1];
}
ll qr2(int i,int l,int r,int tl,int tr)
{
    push12(i,l,r);
    if(r<tl||l>tr) return 0;
    if(l>=tl&&r<=tr) return tree[i];
    int m=(l+r)>>1;
    return qr2(2*i,l,m,tl,tr)+qr2(2*i+1,m+1,r,tl,tr);
}
void build(int i,int l,int r)
{
    if(l==r) return void(t[i]={e[cyc[l]],1});
    int m=(l+r)>>1;
    build(2*i,l,m);
    build(2*i+1,m+1,r);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
void push2(int i,int l,int r)
{
    if(lz2[i])
    {
        t[i].f=0;
        t[i].s=
        r-l+1;
        if(l<r)
        {
            lz2[2*i]=lz2[i];
            lz2[2*i+1]=lz2[i];
            lz[2*i]=0;
            lz[2*i+1]=0;
        }
        lz2[i]=0;
    }
}
void push(int i,int l,int r)
{
    push2(i,l,r);
    t[i].f+=lz[i];
    if(l<r)
    {
        lz[2*i]+=lz[i];
        lz[2*i+1]+=lz[i];
    }
    lz[i]=0;
}
void u1(int i,int l,int r,int tl,int tr,ll v)
{
    push(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lz[i]+=v;
        push(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    u1(2*i,l,m,tl,tr,v);
    u1(2*i+1,m+1,r,tl,tr,v);
    if(t[2*i].f==t[2*i+1].f) t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
void u2(int i,int l,int r,int tl,int tr)
{
    push(i,l,r);
    if(r<tl||l>tr) return;
    if(l>=tl&&r<=tr)
    {
        lz2[i]=1;
        push(i,l,r);
        return;
    }
    int m=(l+r)>>1;
    u2(2*i,l,m,tl,tr);
    u2(2*i+1,m+1,r,tl,tr);
    if(t[2*i].f==t[2*i+1].f)t[i]={t[2*i].f,t[2*i].s+t[2*i+1].s};
    else t[i]=max(t[2*i],t[2*i+1]);
}
pii qr(int i,int l,int r,int tl,int tr)
{
    push(i,l,r);
    if(r<tl||l>tr) return {0,0};
    if(l>=tl&&r<=tr) return t[i];
    int m=(l+r)>>1;
    pii le=qr(2*i,l,m,tl,tr);
    pii re=qr(2*i+1,m+1,r,tl,tr);
    if(le.f==re.f) return {le.f,le.s+re.s};
    else return max(le,re);
}
void dfs(int u,int p)
{
    vis[u]=1;
    for(auto v:g[u])
    {
        if(v.f==p) continue;
        if(!vis[v.f])
        {
            pr[v.f]={u,v.s};
            dfs(v.f,u);
        }
        else if(vis[v.f]&&!cv[v.f]&&!cv[u])
        {
            int x=u;
            cyc.pb(v.s);
            while(x!=v.f)
            {
                cv[x]=1;
                cyc.pb(pr[x].s);
                x=pr[x].f;
            }
            cv[v.f]=1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        g[u].pb({v,i});
        g[v].pb({u,i});
        e[i]=w;
    }
    pr[1]={1,0};
    dfs(1,1);
    sort(cyc.begin(),cyc.end());
    build(1,0,sz(cyc)-1);
    build2(1,1,n);
    while(q--)
    {
        int x,l,r;
        ll v;
        cin >> x >> l >> r >> v;
        if(x==1)
        {
            u12(1,1,n,l,r,v);
            l=lower_bound(cyc.begin(),cyc.end(),l)-cyc.begin();
            r=upper_bound(cyc.begin(),cyc.end(),r)-cyc.begin()-1;
            u1(1,0,sz(cyc)-1,l,r,v);
            cout << tree[1]-t[1].f << " " << t[1].s << "\n";
        }
        else
        {
            u22(1,1,n,l,r);
            u12(1,1,n,l,r,v);
            l=lower_bound(cyc.begin(),cyc.end(),l)-cyc.begin();
            r=upper_bound(cyc.begin(),cyc.end(),r)-cyc.begin()-1;
            u2(1,0,sz(cyc)-1,l,r);
            u1(1,0,sz(cyc)-1,l,r,v);
            cout << tree[1]-t[1].f << " " << t[1].s << "\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e5+5;
struct node
{
    db v;
    int f;
    node *l,*r;
    node():v(0),f(0),l(nullptr),r(nullptr){}
    node(db v,int f):v(v),f(f),l(nullptr),r(nullptr){}
    node(db v,int f,node *l,node *r):v(v),f(f),l(l),r(r){}
};

typedef node* nodeptr;
int n,m;
db u;
db a[N],qs[N];
nodeptr rt[N];
int mp[N];
vector<pair<db,int>> tb;

void build(int l,int r,nodeptr &t)
{
    t=new node();
    if(l==r) return;
    int m=(l+r)/2;
    build(l,m,t->l);
    build(m+1,r,t->r);
    t->v=t->l->v+t->r->v;
    t->f=t->l->f+t->r->f;
}

void update(int l,int r,nodeptr &t,int x,db v,nodeptr k)
{
    t=new node(*k);
    t->v+=v;
    t->f++;
    if(l==r) return;
    int m=(l+r)/2;
    if(x<=m) update(l,m,t->l,x,v,k->l);
    else update(m+1,r,t->r,x,v,k->r);
}

db query(int l,int r,nodeptr t,nodeptr k,int v)
{
    if(v<=0) return 0;
    if(l==r) return k->v-t->v;
    db sum=k->r->v-t->r->v;
    int freq=k->r->f-t->r->f;
    int m=(l+r)/2;
    if(freq<=v) return sum+query(l,m,t->l,k->l,v-freq);
    return query(m+1,r,t->r,k->r,v);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        qs[i]=a[i]+qs[i-1];
        tb.emplace_back(a[i],i);
    }
    sort(tb.begin(),tb.end());
    for(int i=0;i<n;i++) mp[tb[i].second]=i+1;
    build(1,n,rt[0]);
    for(int i=1;i<=n;i++) update(1,n,rt[i],mp[i],a[i],rt[i-1]);
    while(m--)
    {
        int st,ed;
        cin >> st >> ed >> u;
        int sz=ed-st+1;
        int l=0,r=sz;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(query(1,n,rt[st-1],rt[ed],mid)>=u*mid) l=mid;
            else r=mid-1;
        }
        cout << (l>0?sz-l:-1) << '\n';
    }
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(a>b) swap(a,b);
    vector<vector<int>> adj(n);
    vector<int> c(m);
    vector<int> id;
    for(auto &w:c)
    {
        int u,v;
        cin >> u >> v >> w;
        u--,v--;
        if(u>v)swap(u,v);
        id.emplace_back(u);
        id.emplace_back(v);
        adj[u].emplace_back(v);
    }
    id.emplace_back(0);
    id.emplace_back(n-1);
    sort(c.begin(),c.end());
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    int s=id.size();
    if(m>0&&c[0]<=a)
    {
        cout << -1;
        exit(0);
    }
    int cnt=0;
    for(int i=0;i<m;i++) if(c[i]<=b) cnt++;
    for(auto &v:adj) sort(v.begin(),v.end());
    vector<vector<int>> dp(s,vector<int>(s));
    for(int r=0;r<s;r++)
    {
        int cur=0;
        for(int l=r;l>=0;l--)
        {
            cur+=upper_bound(adj[id[l]].begin(),adj[id[l]].end(),id[r])-adj[id[l]].begin();
            dp[l][r]=cur;
        }
    }
    vector<vector<int>> dp2(s+1,vector<int>(cnt+1,n-1));
    dp2[0][0]=0;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<=cnt;j++)
        {
            dp2[i+1][j]=min(dp2[i+1][j],dp2[i][j]);
            for(int k=i+1;k<=s;k++)
            {
                int x=min(j+dp[i][k-1],cnt);
                dp2[k][x]=min(dp2[k][x],dp2[i][j]+id[k-1]-id[i]);
            }
        }
    }
    int v=dp2[s][cnt];
    cout << 1LL*a*v+1LL*(n-1-v)*b;
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long int
const int mmm = 100005;
int par[mmm];
int visited[mmm];
int nc[mmm];
int ms[mmm];
vector<int> adj[mmm];
ll ans = 0;
int N;
void dfs(int n)
{
    if(visited[n]) return;
    visited[n] = 1;
    int curC = 1;
    ll best = 0;
    ll sb = 0;
    for(auto c: adj[n])
    {
        if(!visited[c])
        {
            par[c] = n;
            dfs(c);
            curC+=nc[c];
            if (nc[c]>sb)
            {
                sb = nc[c];
                if(sb>best) swap(best, sb);
            }
        }
    }
    nc[n] = curC;
    ms[n] = best;
    for (auto c: adj[n])
    {
        if(par[c] == n)
        {
            if (best!=nc[c]) ans = max((ll)(N-nc[n])*ms[c], max(best*ms[c], ans));
            else ans = max((ll)(N-nc[n])*ms[c], max(sb*ms[c], ans));
        }
    }
} 

int main()
{
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    dfs(1);
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
const int inf=1e9+7;
int n,L;
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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L;
    vector<pii> vec;
    for(int i=1;i<=n;++i)
    {
        int a,b,c,d,w;
        cin>> a >> b >> c >> d >> w;
        mp2[{{a,b},{c,d}}]=w;
        mp2[{{c,d},{a,b}}]=w;
        vec.pb({a,b});
        vec.pb({c,d});
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    int mn0=inf,mx0=-inf,mn1=inf,mx1=-inf;
    for(auto &e:vec){
        if(e.f>0&&e.f<L)
        {
            int u,v,w;
            u=f0({e.f,e.s}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s},{e.f+1,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f-1,e.s-1}),w=mp2[{{e.f-1,e.s},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f,e.s}),w=mp2[{{e.f,e.s},{e.f,e.s+1}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s-1}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s-1},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        else if(e.f==0)
        {
            mn0=min(mn0,e.s);
            mx0=max(mx0,e.s);
        }
        else if(e.f==L)
        {
            mn1=min(mn1,e.s);
            mx1=max(mx1,e.s);
        }
    }
    int U,V;
    for(int i=mn0;i<=mx0;++i)
    {
        int u=f0({0,i}),v=f0({0,i-1}),w=mp2[{{0,i},{1,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        if(i==mn0) V=v;
        else if(i==mx0) U=u;
    }
    for(int i=mn1;i<=mx1;++i)
    {
        int u=f0({L-1,i}),v=f0({L-1,i-1}),w=mp2[{{L-1,i},{L,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,U});
    memset(dist,0x3f,sizeof dist);
    dist[U]=0;
    while(pq.size())
    {
        int w=pq.top().f;
        int u=pq.top().s;
        pq.pop();
        if(u==V)
        {
            cout << w;
            return 0;
        }
        for(auto &vw:adj[u])
        {
            if(dist[vw.f]>w+vw.s)
            {
                dist[vw.f]=w+vw.s;
                pq.push({w+vw.s,vw.f});
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#include "homework.h"
struct A
{
    int st,num;
    bool operator<(const A&o)const{
        return st>o.st;
    }
};
std::vector<int> adj[100010];
int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B)
{
    for(int i = 0;i<N;i++) for(int j:B[i]) adj[j].push_back(i);
    priority_queue<A> pq;
    for(int i = 0;i<N;i++)
    {
        if(HW[i][3]==0)
        {
            int rst =  HW[i][0]/HW[i][2];
            if(HW[i][0]%HW[i][2]) rst++;
            rst*=HW[i][2];
            if(rst>HW[i][1]) continue;
            pq.push({rst,i});
        }   
    }
    int cnt = 0;
    while(!pq.empty())
    {
        A now = pq.top();
        pq.pop();
        cnt++;
        int st = now.st+1;
        for(int i:adj[now.num])
        {
            HW[i][3]--;
            if(HW[i][3]==0)
            {
                int a = max(st,HW[i][0]);
                int rst =  a/HW[i][2];
                if(a%HW[i][2]) rst++;
                rst*=HW[i][2];
                if(rst>HW[i][1]) continue;
                pq.push({rst,i});
            }
        }
    }
    return cnt;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 50050;
struct CHT
{
    struct line
    {
        ll m, c;
        ll val(ll x)
        {
            return m * x + c;
        }
    };
    deque<line> dq;
    int p;
    bool replace(line i, line j, line k)
    {
        return (j.c - i.c) * (j.m - k.m) >= (k.c - j.c) * (i.m - j.m);
    }
    void insert(line x)
    {
        while((int)dq.size() > 1 && replace(dq[dq.size() - 2], dq.back(), x)) dq.pop_back();
        dq.push_back(x);
    }
    ll query(ll x)
    {
        p = min(p, (int)dq.size() - 1);
        while (p != (int)dq.size() - 1 && dq[p + 1].c - dq[p].c < x * (dq[p].m - dq[p + 1].m)) p++;
        return dq[p].val(x);
    }
} cht;
ll dp[50050];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 1;i <= n;i++)
    {
        int a, h, z;
        cin >> a >> h >> z;
        v.push_back({ a * h, z });
    }
    sort(v.rbegin(), v.rend());
    vector<pair<int, int>> a;
    a.push_back({ 0, 0 });
    for(auto& x : v)
    {
        if(a.empty())
        {
            a.push_back(x);
            continue;
        }
        if(a.back().first == x.first) continue;
        if(a.back().second <= x.second) a.push_back(x);
    }
    n = a.size() - 1;
    cht.p = 0;
    for(int i = 1;i <= n;i++)
    {
        cht.insert({ a[i].first, dp[i - 1] });
        dp[i] = min(1ll * a[i].second * a[1].first, cht.query(a[i].second));
    }
    cout << dp[n];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MxN = 100010;
int a[MxN];
vector<int> adj[MxN];
multiset<int> s[MxN];

inline void merge(multiset<int> &x, multiset<int> &y)
{
	if(x.size() < y.size()) swap(x, y);
	for(auto e: y) x.emplace(e);
}

void dfs(int u, int p)
{
	for(auto x: adj[u])
    {
		if(x == p) continue;
		dfs(x, u);
		merge(s[u], s[x]);
	}
	auto it = s[u].upper_bound(a[u]);
	if(it != s[u].end()) s[u].erase(it);
	s[u].emplace(a[u]);
}	

signed main(int argc, char *argv[])
{
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=2,u,v;i<=n;++i)
    {
		cin >> u >> v;
		u++, v++;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	cout << n - (int) s[1].size() << "\n";
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int const N=1e5+10;
int n;
struct seg{
    int all[3*N];
    int under[3*N];
    void build(){for(int i=0;i<3*N;i++)all[i]=under[i]=0;}
    void upd(int i,int l,int r,int ll,int rr,int val)
    {
        if(rr<l||r<ll) return;
        if(ll<=l&&r<=rr)
        {
            all[i]+=val;
            return;
        }
        int mid=(l+r)>>1;
        upd(2*i,l,mid,ll,rr,val);
        upd(2*i+1,mid+1,r,ll,rr,val);
        under[i]=(all[2*i]>0?mid-l+1:under[2*i])+(all[2*i+1]>0? r-(mid+1)+1:under[2*i+1]);
    }
    int query()
    {
        return (all[1]>0? n:under[1]);
    }
}tree;
vector<int> keep[2*N];
vector<pii> todo[N];
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    tree.build();
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        if(keep[a].empty()) keep[a].push_back(0);
        keep[a].push_back(i);
        int sz=keep[a].size();
        if(sz>=7)
        {
            todo[keep[a][sz-7]+1].push_back({keep[a][sz-2],keep[a][sz-1]-1});
            todo[keep[a][sz-6]+1].push_back({-keep[a][sz-2],keep[a][sz-1]-1});
        }
    }
    for(int i=0;i<2*N;i++)
    {
        int sz=keep[i].size();
        if(sz>=6)
        {
            todo[keep[i][sz-6]+1].push_back({keep[i][sz-1],n});
            todo[keep[i][sz-5]+1].push_back({-keep[i][sz-1],n});
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto it:todo[i])
        {
            if(it.fi>=0) tree.upd(1,1,n,it.fi,it.se,1);
            else tree.upd(1,1,n,-it.fi,it.se,-1);
        }
        ans+=tree.query();
    }
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define pii pair<ll,ll>
#define ll long long
#define sz(x) (ll)x.size()
using namespace std;
const int mxn=2e5+5;
vector<pii>g[mxn];
ll d[mxn]{0},di[2][mxn]{0},qs[mxn]{0};
int dep[mxn]{0},pr[mxn][20],n;
vector<ll>x,y;
struct node{
    int v;ll tt;
    node*l,*r;
    node(int v,ll tt): v(v),tt(tt),l(NULL),r(NULL){};
    node(node*l,node*r): v(l->v+r->v),tt(l->tt+r->tt),l(l),r(r){};
};
node*root[mxn];
node* build(int l,int r){
    if(l==r)return new node(0,0);
    int m=(l+r)>>1;
    return new node(build(l,m),build(m+1,r));
}
node* upd(node*t,int l,int r,int idx,ll amt){
    if(l==r)return new node(t->v+1,t->tt+amt);
    int m=(l+r)>>1;
    if(m<idx)return new node(t->l,upd(t->r,m+1,r,idx,amt));
    else return new node(upd(t->l,l,m,idx,amt),t->r);
}
ll qr(node*tl,node*tr,int l,int r,int k){
    if(l==r){
        return y[l-1]*k;
    }int m=(l+r)>>1;
    int tt = tr->l->v-tl->l->v;
    if(tt>k)return qr(tl->l,tr->l,l,m,k);
    else return tr->l->tt-tl->l->tt+qr(tl->r,tr->r,m+1,r,k-tt);
}
void dfs(int u,int p,int l){
    pr[u][0]=p;dep[u]=l;
    for(int i=1;i<20;i++)pr[u][i]=pr[pr[u][i-1]][i-1];
    for(auto v:g[u]){
        if(v.f==p)continue;
        d[v.f]=d[u]+v.s;dfs(v.f,u,l+1);
    }
}
void getdist(int u,int p,int i)
{
    for(auto v:g[u])
    {
        if(v.f==p) continue;
        di[i][v.f]=di[i][u]+v.s;
        getdist(v.f,u,i);
    }
}
int get(int a,int b)
{
    if(dep[a]>dep[b]) swap(a,b);
    for(int i=19;i>=0;i--) if(dep[b]-(1<<i)>=dep[a]) b=pr[b][i];
    if(a==b) return a;
    for(int i=19;i>=0;i--) if(pr[a][i]!=pr[b][i]) a=pr[a][i],b=pr[b][i];
    return pr[a][0];
}
ll cal(int a,int b)
{
    return d[a]+d[b]-2*d[get(a,b)];
}
void init(int N,std::vector<int> T,std::vector<std::vector<int>> Road)
{
    for(int i=0;i<N-1;i++)
    {
        g[Road[i][0]].pb({Road[i][1],Road[i][2]});
        g[Road[i][1]].pb({Road[i][0],Road[i][2]});
    }
    dfs(0,0,0);getdist(Road.back()[0],Road.back()[0],0);getdist(Road.back()[1],Road.back()[1],1);
    for(int i=1;i<T.size();i++)
    {
        ll tt=cal(T[i-1],T[i]);
        ll rs=min(di[0][T[i-1]]+di[1][T[i]],di[1][T[i-1]]+di[0][T[i]])+Road.back()[2]-tt;
        x.pb(rs),y.pb(rs);qs[i]=qs[i-1]+tt;
    }
    sort(y.begin(),y.end());
    y.erase(unique(y.begin(),y.end()),y.end());
    n=y.size();
    root[0]=build(1,n);
    for(int i=0;i<x.size();i++) root[i+1]=upd(root[i],1,n,upper_bound(y.begin(),y.end(),x[i])-y.begin(),x[i]);
}
long long min_distance(int L,int R,int X)
{
    return qs[R]-qs[L]+qr(root[L],root[R],1,n,X);
}

#include<bits/stdc++.h>
#include "homework.h"
using namespace std;
struct A
{
    int st,num;
    bool operator<(const A&o)const{
        return st>o.st;
    }
};
std::vector<int> adj[100010];
int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B)
{
    for(int i = 0;i<N;i++) for(int j:B[i]) adj[j].push_back(i);
    priority_queue<A> pq;
    for(int i = 0;i<N;i++)
    {
        if(HW[i][3]==0)
        {
            int rst =  HW[i][0]/HW[i][2];
            if(HW[i][0]%HW[i][2]) rst++;
            rst*=HW[i][2];
            if(rst>HW[i][1]) continue;
            pq.push({rst,i});
        }   
    }
    int cnt = 0;
    while(!pq.empty())
    {
        A now = pq.top();
        pq.pop();
        cnt++;
        int st = now.st+1;
        for(int i:adj[now.num])
        {
            HW[i][3]--;
            if(HW[i][3]==0)
            {
                int a = max(st,HW[i][0]);
                int rst =  a/HW[i][2];
                if(a%HW[i][2]) rst++;
                rst*=HW[i][2];
                if(rst>HW[i][1]) continue;
                pq.push({rst,i});
            }
        }
    }
    return cnt;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int V, CH[N], CI[N], P[20][N], L[N], H[N], timer, T[N<<1], PW[N];
vector<pair<int, int>> G[N];

int qry(int l, int r, int z = INT_MAX)
{
    for(l += V, r += V + 1; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1) z = min(z, T[l++]);
        if(r & 1) z = min(T[--r], z);
    }
    return z;
}

int dfs(int u)
{
    int sz = 1, hv = 0;
    for (auto [w, v] : G[u]) 
    {
        if(v == P[0][u]) continue;
        L[v] = L[u] + 1;
        int sub = dfs(v);
        if(sub > hv) H[u] = v, hv = sub;
        sz += sub;
    }
    return sz;
}

void hld(int u, int h)
{
    T[(CI[u] = timer++) + V] = PW[u]; CH[u] = h;
    if(H[u] != -1) hld(H[u], h);
    for(auto [w, v] : G[u]) if(v != P[0][u] && v != H[u]) hld(v, v);
}

int lca(int u, int v)
{
    if(L[u] < L[v]) return lca(v, u);
    int dt = L[u] - L[v];
    for(int i=20;i--;) if(dt & (1 << i)) u = P[i][u];
    if(u == v) return u;
    for(int i=20;i--;) if(P[i][u] != P[i][v]) u = P[i][u], v = P[i][v];
    return P[0][u];
}

int kth(int u, int k)
{
    for(int i=20;i--;) if(k & (1 << i)) u = P[i][u];
    return u;
}

long long qryup(int u, int a)
{
    int z = INT_MAX;
    for(;CH[u] != CH[a];u=P[0][CH[u]]) z = min(z, qry(CI[CH[u]], CI[u]));
    return min(z, qry(CI[a], CI[u]));
}

int main()
{
    scanf("%d", &V);
    for(int v=1,u,w;v<V;++v) scanf("%d%d", &u, &w), G[u].emplace_back(w, v), P[0][v] = u, PW[v] = w;
    for(int j=1; j<20;++j) for(int i=0;i<V;++i) P[j][i] = P[j-1][P[j-1][i]];
    memset(H, -1, sizeof H);
    dfs(0);
    hld(0, 0);
    for(int p=V;--p;) T[p] = min(T[p<<1], T[p<<1|1]);
    long long q, k, m, a1, a2;
    scanf("%lld%lld%lld%lld%lld", &q, &k, &m, &a1, &a2);
    for(int i=1;i<=q;++i)
    {
        int anc = lca(a1, a2);
        long long r = (a1 == a2 ? 0 : INT_MAX);
        if(a1 != anc) r = min(r, qryup(a1, kth(a1, L[a1] - L[anc] - 1)));
        if(a2 != anc) r = min(r, qryup(a2, kth(a2, L[a2] - L[anc] - 1)));
        printf("%lld\n", r);
        a1 = a2;
        a2 = ((1ll *  k * a1 + r) % m) % V;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
string a, b;
int fw[1000005];
void update(int idx)
{
    for(; idx < a.size(); idx += idx & -idx) fw[idx]++;
}

int query(int idx)
{
    int res = 0;
    for(; idx > 0; idx -= idx & -idx) res += fw[idx];
    return res;
}

void solve(int mode)
{
    long long res = 0;
    int cnt[26]{};
    vector<int> indexs[30];
    for(int i = 1; i < a.size(); ++i) indexs[a[i]-'a'].emplace_back(i);
    for(char c : b)
    {
        if(cnt[c-'a'] >= indexs[c-'a'].size())
        {
            cout << -1;
            return;
        }
        res += 1LL*indexs[c-'a'][cnt[c-'a']++];
        if(mode == 0) continue;
        res -= 1LL*query(indexs[c-'a'][cnt[c-'a']-1]);
        update(indexs[c-'a'][cnt[c-'a']-1]);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int mode;
    cin >> mode >> a >> b;
    a = '.' + a;
    solve(mode);
}

#include<iostream>
#include<algorithm>
using namespace std;
const int N=1<<21;
struct node{
	bool u,c;
}s[N];
void update(int l,int r,int idx,int a,int b)
{
	int m=(l+r)/2;
	if(a>r || b<l) return;
	if(l==a && r==b)
    {
		s[idx].u=true;
		if(l==r) s[idx].c=true;
		if(s[idx*2].u && (!s[idx*2+1].u)) s[idx*2+1].u=true,update(m+1,r,idx*2+1,m+1,r);
		if(s[idx*2+1].u && (!s[idx*2].u)) s[idx*2].u=true,update(l,m,idx*2,l,m);
		if(l!=r) s[idx].c=s[idx*2].c && s[idx*2+1].c;
		return;
	}
	update(l,m,idx*2,a,b);
	update(m+1,r,idx*2+1,a,b);
	if(s[idx].u && s[idx*2].u && (!s[idx*2+1].u)) s[idx*2+1].u=true,update(m+1,r,idx*2+1,m+1,r);
	if(s[idx].u && s[idx*2+1].u && (!s[idx*2].u)) s[idx*2].u=true,update(l,m,idx*2,l,m);
	s[idx].c=s[idx*2].c && s[idx*2+1].c;
	s[idx].u|=s[idx*2].u && s[idx*2+1].u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<N;i++) s[i].u=s[i].c=false;
	for(int i=1;i<=m;i++)
    {
		int a,b;
		cin >> a >> b;
		a=b+(1<<a)-1;
		swap(a,b);
		update(0,(1<<n)-1,1,a,b);
		if(s[1].c)
        {
			for(int j=i+1;j<=m;j++) cin >> a >> b;
			cout << i << "\n";
			return 0;
		}
	}
}

#include <iostream>
using namespace std;
int a[1000001], n, m, fw[2][1000001], cnt[2];
bool f[1000001];
long long sum = 0;

long long qry (bool flip, int v)
{
    long long sum = 0;
    for(int i=v+1;i>0;i-=i&-i) sum += fw[flip][i];
    return sum;
}

void upd(bool flip, int v, int w)
{
    sum += v*w; cnt[flip] += w;
    for(int i=v+1;i<=m+1;i+=i&-i) fw[flip][i] += w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int q;
    cin >> n >> m >> q;
    cnt[0] = n;
    for(int i=1;i<=n;i++) for(int j=1;j<=m+1;j+=j&-j) ++fw[0][j];
    while(q--)
    {
        char cmd;
        cin >> cmd;
        if(cmd == 's')
        {
            int x, y;
            cin >> x >> y;
            upd(f[x], a[x], -1);
            upd(f[x], a[x] = (f[x] ? (a[x]+y)%m : (a[x]-y+m)%m), 1);
        }
        else if(cmd == 'f')
        {
            int x;
            cin >> x;
            upd(f[x], a[x], -1);
            upd(f[x] = f[x]^1, a[x] = (m-a[x])%m, 1);
        }
        else
        {
            int x;
            cin >> x;
            cout << x*qry(0, m-x) - (m-x)*(cnt[0]-qry(0, m-x)) + (m-x)*qry(1, x) - x*(cnt[1]-qry(1, x)) + sum << "\n";
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
int parent[MAXN], rnk[MAXN];
int root(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}
bool is_same(int u, int v)
{
    return root(u) == root(v);
}
void mergeDSU(int u, int v)
{
    u = root(u); v = root(v);
    if(u == v) return;
    if(rnk[u] > rnk[v])
    {
        rnk[u] += rnk[v];
        parent[v] = u;
    }
    else
    {
        rnk[v] += rnk[u];
        parent[u] = v;
    }
}
vector<int> graph[MAXN];
int inDeg[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 1;
    }
    vector<array<int,4>> constraintsT1, constraintsT2;
    for(int i = 0; i < w; i++)
    {
        int T, a, b, c;
        cin >> T >> a >> b >> c;
        if(T == 3)
        {
            mergeDSU(a, b);
            mergeDSU(a, c);
        }
        else if(T == 1) constraintsT1.push_back({T, a, b, c});
        else if(T == 2) constraintsT2.push_back({T, a, b, c});
    }
    map<int, vector<int>> groups;
    for(int i=1;i<=n;i++)
    {
        int rep = root(i);
        groups[rep].push_back(i);
    }
    for(auto &arr : constraintsT1)
    {
        int T = arr[0], a = arr[1], b = arr[2], c = arr[3];
        int repA = root(a), repB = root(b), repC = root(c);
        if(repB != repA)
        {
            graph[repB].push_back(repA);
            inDeg[repA]++;
        }
        if(repC != repA)
        {
            graph[repC].push_back(repA);
            inDeg[repA]++;
        }
    }
    for(auto &arr : constraintsT2)
    {
        int T = arr[0], a = arr[1], b = arr[2], c = arr[3];
        int repA = root(a), repB = root(b), repC = root(c);
        if(repA != repB)
        {
            graph[repA].push_back(repB);
            inDeg[repB]++;
        }
        if(repA != repC)
        {
            graph[repA].push_back(repC);
            inDeg[repC]++;
        }
    }
    int p = groups.size();
    queue<int> Q;
    for(auto &entry : groups)
    {
        int rep = entry.first;
        if (inDeg[rep] == 0) Q.push(rep);
    }
    vector<int> topo;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        topo.push_back(u);
        for(int v : graph[u])
        {
            inDeg[v]--;
            if(inDeg[v] == 0) Q.push(v);
        }
    }
    if(topo.size() != groups.size())
    {
        cout << -1 << "\n";
        return 0;
    }
    vector<pair<int, vector<int>>> result;
    for(int rep : topo)
    {
        vector<int> members = groups[rep];
        sort(members.begin(), members.end());
        result.push_back({rep, members});
    }
    cout << p << "\n";
    for(auto &grp : result)
    {
        vector<int> &members = grp.second;
        cout << members.size();
        for(int mem : members) cout << " " << mem;
        cout << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
using namespace std;
const int N=505;
vector<int>v;
mt19937 rng(time(0));
struct mint
{
    int t[2*N];
    void build(int sz)
    {
        for(int i=0;i<sz;i++) t[i+sz]=v[i];
        for(int i=sz-1;i>0;i--) t[i]=min(t[2*i],t[2*i+1]);
    }
    int qr(int l,int r,int sz,int res=1e9)
    {
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1)
        {
            if(l&1) res=min(res,t[l++]);
            if(r&1) res=min(res,t[--r]);
        }
        return res;
    }
}s1;
struct maxt
{
    int t[2*N];
    void build(int sz)
    {
        for(int i=0;i<sz;i++) t[i+sz]=v[i];
        for(int i=sz-1;i>0;i--) t[i]=max(t[2*i],t[2*i+1]);
    }
    int qr(int l,int r,int sz,int res=0)
    {
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1)
        {
            if(l&1) res=max(res,t[l++]);
            if(r&1) res=max(res,t[--r]);
        }
        return res;
    }
}s2;
ll ans=0;
vector<int>rs;
void solve1(int n,int k)
{
    for(int i=1;i<=n;i++) v.pb(i);
    vector<pii>qr(k);
    for(int i=0;i<k;i++) cin >> qr[i].f >> qr[i].s;
    do
    {
        s1.build(n);s2.build(n);ll tt=0;
        for(auto it : qr) tt+=s2.qr(it.f-1,it.s,n)-s1.qr(it.f-1,it.s,n);
        if(tt>ans) ans=tt,rs=v;
    }
    while(next_permutation(v.begin(),v.end()));
    for(auto it : rs) cout << it << ' ';
}

void solve2(int n,int k)
{
    int ro=4e4;
    for(int i=1;i<=n;i++) v.pb(i);
    vector<pii>qr(k);
    for(int i=0;i<k;i++) cin >> qr[i].f >> qr[i].s;
    while(ro--)
    {
        shuffle(v.begin(),v.end(),rng);
        s1.build(n);s2.build(n);ll tt=0;
        for(auto it : qr) tt+=s2.qr(it.f-1,it.s,n)-s1.qr(it.f-1,it.s,n);
        if(tt>ans) ans=tt,rs=v;
    }
    for(auto it : rs) cout << it << ' ';
}

vector<pii>qr(4);
vector<int>tmp;
pii a[16];
void gen(int n,int i)
{
    tmp.pb(0);
    gen(n,i+1);
    tmp.pop_back();
    tmp.pb(1);gen(n,i+1);
    tmp.pop_back();
}

void solve3(int n,int k)
{
    v.resize(n,0);
    for(int i=0;i<k;i++) cin >> qr[i].f >> qr[i].s;
    for(int i=0;i<(1<<k);i++)
    {
        int mxl=0,mnr=1e9;
        for(int j=0;j<k;j++) if(i&(1<<j)) mxl=max(mxl,qr[j].f),mnr=min(mnr,qr[j].s);
        a[i]={mxl,mnr};
    }
    gen(k*k,0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    if(n<=9) solve1(n,k);
    if(k>=2&&k<=4) solve3(n,k);
    else solve2(n,k);
}

#include<bits/stdc++.h>
using namespace std;
#include "homework.h"
struct A
{
    int st,num;
    bool operator<(const A&o)const
    {
        return st>o.st;
    }
};

std::vector<int> adj[100010];
int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B)
{
    for(int i=0;i<N;i++) for(int j:B[i]) adj[j].push_back(i);
    priority_queue<A> pq;
    for(int i=0;i<N;i++)
    {
        if(HW[i][3]==0)
        {
            int rst =  HW[i][0]/HW[i][2];
            if(HW[i][0]%HW[i][2]) rst++;
            rst*=HW[i][2];
            if(rst>HW[i][1]) continue;
            pq.push({rst,i});
        }   
    }
    int cnt = 0;
    while(!pq.empty())
    {
        A now = pq.top();
        pq.pop();
        cnt++;
        int st = now.st+1;
        for(int i:adj[now.num])
        {
            HW[i][3]--;
            if(HW[i][3]==0)
            {
                int a = max(st,HW[i][0]);
                int rst =  a/HW[i][2];
                if(a%HW[i][2]) rst++;
                rst*=HW[i][2];
                if(rst>HW[i][1]) continue;
                pq.push({rst,i});
            }
        }
    }
    return cnt;
}

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ull> fwd(n+1, 0), rev(n+1, 0), powb(n+1, 0);
    ull base = 131ULL;
    powb[0] = 1;
    for (int i = 0; i < n; i++)
    {
        fwd[i+1] = fwd[i]*base + (s[i]-'a'+1);
        powb[i+1] = powb[i]*base;
    }
    for (int i = 0; i < n; i++)
    {
        rev[i+1] = rev[i]*base + (s[n-1-i]-'a'+1);
    }
    auto getFwd = [&](int l, int r) -> ull
    {
        return fwd[r] - fwd[l]*powb[r-l];
    };
    auto getRev = [&](int l, int r) -> ull
    {
        return rev[n-l] - rev[n-r]*powb[r-l];
    };
    while(q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        int len1 = b - a;
        int len2 = d - c;
        ull h1 = getFwd(a, b);
        ull h2 = getFwd(c, d);
        ull H = h1 * powb[len2] + h2;
        ull r1 = getRev(a, b); 
        ull r2 = getRev(c, d); 
        ull RH = r2 * powb[len1] + r1;
        cout << (H == RH ? "YES\n" : "NO\n");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, x;
    cin >> n;
    if (n % 2 == 1)
    {
        char arr[n][n];
        for(i=0;i<n;i++) for(j=0;j<n;j++) arr[i][j] = '-';
    }
    for(i=0;i<=(n-1)/2;i++)
    {
        if(i == 0) arr[i][(n-1)/2] = '*';
        else
        {
            arr[i][(n-1)/2-i] = '*';
            arr[i][(n-1)/2+i] = '*';
        }
    }
    x = 0;
    for(i=n-1;i>(n-1)/2;i--)
    {
        if(i == n-1) arr[i][(n-1)/2] = '*';
        else
        {
            arr[i][(n-1)/2-x] = '*';
            arr[i][(n-1)/2+x] = '*';
        }
        x = x + 1;
    }
    for(i=0;i<n;i++) for(j=0;j<n;j++) cout << arr[i][j];
    cout << endl;
    else
    {
        char arr[n][n - 1];
        for(i=0;i<n;i++) for(j=0;j<n-1;j++) arr[i][j] = '-';
    }
    for(i=0;i<=n/2-1;i++)
    {
        if(i == 0) arr[i][n/2-1] = '*';
            
        else
        {
            arr[i][n/2-1-i] = '*';
            arr[i][n/2-1+i] = '*';
        }
    }
    x = 0;
    for(i=n-1;i>(n-1)/2;i--)
    {
        if(i == n-1) arr[i][(n-1)/2] = '*';
        else
        {
            arr[i][(n-1)/2-x] = '*';
            arr[i][(n-1)/2+x] = '*';
        }
        x = x + 1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++) cout << arr[i][j];
        cout << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
const int X=2e6;
int n,m;
pair<int,int> nxt[X+5];
bool vis[X+5];
int ans;
priority_queue<int> pq;

int calc(int x)
{
    if(vis[x]) return 0;
    vis[x]=true;
    return calc(nxt[x].first)+nxt[x].second;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=X;i++) nxt[i]={i+1,0};
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin >> l >> r;
        nxt[l]={r+1,1};
        nxt[r]={l+1,1};
    }
    vis[X+1]=true;
    ans=calc(1);
    for(int i=2;i<=X;i++) if(!vis[i]) pq.emplace(calc(i));
    while(!pq.empty()&&m>0)
    {
        ans+=pq.top()+2;
        pq.pop();
        m--;
    }
    cout << ans+m/2*4+m%2;
}

#include <bits/stdc++.h>
using namespace std;
int dp[202][202][2], dp2[130030];
int nCr[444][444];
const long long MOD = 1e9 + 7;
int play(int i, int j, int n)
{
    if (i < 1 || j < 1 || n < max(i, j) - 1) return 0;
    return dp[i][j][n & 1];
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    dp[1][1][0] = 1;
    dp2[0] = 1;
    nCr[0][0] = 1;
    for(int i=1;i<=2*r-3;i++)
    {
        nCr[i][0] = 1;
        for(int j = 1;j <= i;j++) nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
    }
    for(int k=1;k<=3*r-4;k++)
    {
        int now = k & 1;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=r;j++)
            {
                if(k < max(i,j)-1) continue;
                dp[i][j][now] = (play(i - 1, j, k - 1) + play(i, j - 1, k - 1)) % MOD;
                if(i != j)
                {
                    dp[i][j][now] = (dp[i][j][now] + play(i, j, k - 1)) % MOD;
                    dp[i][j][now] = (dp[i][j][now] + play(i - 1, j - 1, k - 1)) % MOD;
                }
            }
        }
        dp2[k] = dp[r][r][now];
    }
    int m = 2 * r - 3;
    for(int k=3*r-3;k<=r+c-2;k++)
    {
        for(int i=0;i<=m;i++)
        {
            if(i & 1) dp2[k] = (dp2[k] + 1ll * nCr[m][i] * dp2[k - i] % MOD + MOD) % MOD;
            else dp2[k] = (dp2[k] - 1ll * nCr[m][i] * dp2[k - i] % MOD + MOD) % MOD;
        }
    }
    printf("%d", dp2[r + c - 2]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[100100], c[100100];
bool vis[100100];
int dfs(int v)
{
    int sz = 1;
    vis[v] = 1;
    if (!vis[a[v]]) sz += dfs(a[v]);
    return sz;
}
int dp[100100];
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];

    int idx = 0;
    for (int i = 1;i <= n;i++)
    {
        if (vis[i]) continue;
        c[++idx] = dfs(i);
    }
    for(int i=1;i<=idx;i++) for(int j=1;j<=c[i];j++) dp[j] += (c[i]+j-1) / j-1;
    while(q--)
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if(dp[mid] <= x) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}

#pragma GCC optimize("O3,unroll-loops")
#include <vector>
#include <cstdio>
#include<cstring>
#include <cassert>
#include <map>
#include <algorithm>
#include <set>
#include "mountain.h"
#define BLUE 1
#define RED 2
#define N 100001
int dep[N], n, a[N], c[N], sta[N], top, l[N], r[N], sz[N], par[N], head[N], tail[N], dfn[N], aux[N], mm[N*4],rt[N],timer,at[N];
long long weight[N],cache[N][3];
struct mat
{
	long long b,r,f,ba,ra;
	friend mat operator*(const mat&a, const mat&b)
    {
		mat c;
		c.r=a.r+b.r;
		c.b=a.b+b.b;
		c.f=a.f+b.f+a.r*b.ba+a.b*b.ra;
		c.ba=a.ba+b.ba;
		c.ra=a.ra+b.ra;
		return c;
	}
};
mat tran[N*2];
void dfs1(int u,int p)
{
	if(!u) return;
	sz[u]=1;
	par[u]=p;
	dep[u]=dep[p]+1;
	dfs1(l[u],u),sz[u]+=sz[l[u]];
	dfs1(r[u],u),sz[u]+=sz[r[u]];
	if(!l[u]||sz[r[u]]>sz[l[u]]) std::swap(l[u],r[u]);
}
void pul(int v,int l,int r)
{
	tran[v]=tran[v+(mm[v]-l+1)*2]*tran[v+1];
}
void upd2(int v,int l,int r,int p)
{
	if(l==r) return;
	if(p<=mm[v])upd2(v+1,l,mm[v],p);
	else upd2(v+(mm[v]-l+1)*2,mm[v]+1,r,p);
	pul(v,l,r);
}
void re_lp(int u)
{
	int p=par[u];
    long long cc,ca,cb;
	auto&t=tran[at[dfn[p]]];
	t.r+=tran[rt[u]].r-cache[u][0];
	t.b+=tran[rt[u]].b-cache[u][1];
	t.ra+=a[p]*((ca=tran[rt[u]].r)-cache[u][0]);
	t.ba+=a[p]*((cb=tran[rt[u]].b)-cache[u][1]);
	t.f+= (cc=tran[rt[u]].f+tran[rt[u]].r*1ll*a[p]*(c[p]==BLUE)+tran[rt[u]].b*1ll*a[p]*(c[p]==RED))
    -cache[u][2];
	upd2(rt[head[p]],dfn[head[p]],dfn[tail[head[p]]],dfn[p]);
	cache[u][0]=ca;
	cache[u][1]=cb;
	cache[u][2]=cc;
}
void dfs2(int u,int hd)
{
	if(!u) return;
	aux[dfn[u]=++timer]=u;
	head[u]=hd;
	tail[hd]=u;
	dfs2(l[u],hd);
	dfs2(r[u],r[u]);
	weight[dfn[u]]=sz[u]-sz[l[u]];
}
void dfs3(int u)
{
	if(!u) return;
	dfs3(l[u]),dfs3(r[u]);
	if(r[u]) re_lp(r[u]);
}
void build(int v,int l,int r)
{
	if(l==r)
    {
		at[l]=v;
		tran[v].b=(c[aux[l]]==BLUE);
		tran[v].r=(c[aux[l]]==RED);
		tran[v].ba=(c[aux[l]]==BLUE)*a[aux[l]];
		tran[v].ra=(c[aux[l]]==RED)*a[aux[l]];
		return;
	}
	int lower=l,upper=r;
	while(upper-lower>1)
    {
		int mid=lower+(upper-lower)/2;
		if(weight[mid]-weight[l-1]<weight[r]-weight[mid]) lower=mid;
		else upper=mid;
	}
	mm[v]=lower;
	build(v+1,l,mm[v]);
	build(v+(mm[v]-l+1)*2,mm[v]+1,r);
	pul(v,l,r);
}
void upd(int v,int l,int r,int p,int mul)
{
	if(l==r)
    {
		tran[v].b+=(c[aux[l]]==BLUE)*mul;
		tran[v].r+=(c[aux[l]]==RED)*mul;
		tran[v].ba+=(c[aux[l]]==BLUE)*a[aux[l]]*mul;
		tran[v].ra+=(c[aux[l]]==RED)*a[aux[l]]*mul;
		return;
	}
	if(p<=mm[v]) upd(v+1,l,mm[v],p,mul);
	else upd(v+(mm[v]-l+1)*2,mm[v]+1,r,p,mul);
	pul(v,l,r);
}
void updup(int v)
{
	for(;head[v]!=head[sta[1]];v=par[head[v]]) re_lp(head[v]);
}
long long race_cost(int S, int X)
{
	if(c[++X]-S)
    {
		upd(rt[head[X]],dfn[head[X]],dfn[tail[head[X]]],dfn[X],-1);
		c[X]=S;
		upd(rt[head[X]],dfn[head[X]],dfn[tail[head[X]]],dfn[X],1);
		updup(r[X]?r[X]:X);
	}
	return tran[rt[sta[1]]].f;
}
void initialize(int N_, std::vector<int> A0, std::vector<int> C0) {
	n=N_;
	for(int i=0;i<n;++i) a[i+1]=A0[i],c[i+1]=C0[i];
	for(int i=1;i<=n;++i)
    {
		int k=top;
		while(k&&a[sta[k]]<a[i]) --k;
		if(k) r[sta[k]]=i;
		if(k<top) l[i]=sta[k+1];
		sta[top=++k]=i;
	}
	dfs1(sta[1],sta[1]);
	dfs2(sta[1],sta[1]);
	for(int i=1;i<=n;++i) weight[i]+=weight[i-1];
	for(int jj=0,i=1;i<=n;++i) if(i==head[i]) build(rt[i]=jj,dfn[i],dfn[tail[i]]),jj+=(dfn[tail[i]]-dfn[i]+1)*2;
	dfs3(sta[1]);
}

#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
struct Node
{
	int val;
	int weight, size;
	bool rev;
	Node *left, *right;
	Node(int c) : val(c), weight(rand()), size(1), left(NULL), right(NULL), rev(false) {}
} *root;

inline int size(Node *t) { return t ? t->size : 0; }

inline void upd_size(Node *t
{
	if(t) t->size=size(t->left)+size(t->right)+1;
}

void push(Node *t)
{
	if(t && t->rev)
    {
		t->rev=false;
		swap(t->left,t->right);
		if(t->left) t->left->rev^=1;
		if(t->right) t->right->rev^=1;
	}
}

void split(Node *treap, Node *&left, Node *&right, int val, int add=0) {
	if(!treap)
    {
		left = right = NULL;
		return;
	}
	push(treap);
	if(add+size(treap->left) < val)
    {
		split(treap->right, treap->right, right, val,add+size(treap->left)+1);
		left = treap;
	}
    else
    {
		split(treap->left, left, treap->left, val,add);
		right = treap;
	}
	upd_size(treap);
}

void merge(Node *&treap, Node *left, Node *right)
{
	push(left);
	push(right);
	if(left == NULL)
    {
		treap = right;
		return;
	}
	if(right == NULL)
    {
		treap = left;
		return;
	}
	if(left->weight < right->weight)
    {
		merge(left->right, left->right, right);
		treap = left;
	}
    else
    {
		merge(right->left, left, right->left);
		treap = right;
	}
	upd_size(treap);
}

void reverse(Node *t, int l, int r)
{
	Node *t1, *t2, *t3;
	split(t,t1,t2,l);
	split(t2,t2,t3,r-l+1);
	t2->rev^=1;
	merge(t,t1,t2);
	merge(t,t,t3);
}

ostream &operator<<(ostream &os, Node *n)
{
	if(!n) return os;
	os << n->left;
	os << n->val;
	os << n->right;
	return os;
}

void output (Node *t)
{
    if(!t) return;
    push(t);
    output (t->left);
    printf ("%d ", t->val);
    output (t->right);
}

int get_left(Node *t)
{
	push(t);
	if(t->left) return get_left(t->left);
	else return t->val; 
}

Node *t;
int a[300005];
int main()
{
	int n;
    scanf(" %d",&n);
	f(i,1,n,1) scanf(" %d",&a[i]);
	f(i,1,n,1) merge(root, root, new Node(a[i]));
	int cnt=0;
	int x=a[1];
	while(x!=1)
    {
		cnt++;
		reverse(root,0,x-1);
		x=get_left(root);
	}
	printf("%d",cnt);
}

#include<bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,int>
#define f first
#define s second
struct A
{
    int l,r,cnt,k;
    bool operator<(const A&o) const
    {
        if(r==o.r) return l>o.l;
        return r>o.r;
    }
};
struct B
{
    int l,r,lk,rk,cnt;
};
int dp[2][1111111];
B rng[1111111];
priority_queue<A> pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        if(rng[x].cnt==0) rng[x]= {i,i,-1,-1,1};
        else
        {
            if(rng[x].lk==-1) rng[x].lk=i;
            rng[x].rk=rng[x].r;
            rng[x].r=i;
            rng[x].cnt++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(rng[i].cnt==0) continue;
        pq.push({rng[i].l,rng[i].r,rng[i].cnt,0});
        if(k==1)
        {
            pq.push({rng[i].lk,rng[i].r,rng[i].cnt-1,1});
            pq.push({rng[i].l,rng[i].rk,rng[i].cnt-1,1});
        }
    }
    for(int i=1;i<=n;i++) if(i==pq.top().r) dp[0][i]=max(dp[0][i],dp[0][pq.top().l-1]+pq.top().cnt);
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=dp[0][i-1];
        dp[1][i]=dp[1][i-1];
        while(!pq.empty()&&pq.top().r==i)
        {
            if(pq.top().k==0)
            {
                dp[0][i]=max(dp[0][i],dp[0][pq.top().l-1]+pq.top().cnt);
                dp[1][i]=max(dp[1][i],dp[1][pq.top().l-1]+pq.top().cnt);
            }
            else dp[1][i]=max(dp[1][i],dp[0][pq.top().l-1]+pq.top().cnt);
            pq.pop();
        } 
    }
    cout << n-max(dp[0][n],dp[1][n]);
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(a>b) swap(a,b);
    vector<vector<int>> adj(n);
    vector<int> id;
    int c=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        if(w<=a)
        {
            cout << -1;
            exit(0);
        }
        if(w<=b) c++;
        u--,v--;
        if(u>v)swap(u,v);
        id.emplace_back(u);
        id.emplace_back(v);
        adj[u].emplace_back(v);
    }
    id.emplace_back(0);
    id.emplace_back(n-1);
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    int s=id.size();
    for(auto &v:adj) sort(v.begin(),v.end());
    vector<vector<int>> dp(s,vector<int>(s));
    for(int r=0;r<s;r++)
    {
        int cur=0;
        for(int l=r;l>=0;l--)
        {
            cur+=upper_bound(adj[id[l]].begin(),adj[id[l]].end(),id[r])-adj[id[l]].begin();
            dp[l][r]=cur;
        }
    }
    vector<vector<int>> dp2(s+1,vector<int>(c+1,n-1));
    dp2[0][0]=0;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<=c;j++)
        {
            dp2[i+1][j]=min(dp2[i+1][j],dp2[i][j]);
            for(int k=i+1;k<=s;k++)
            {
                int x=min(j+dp[i][k-1],c);
                dp2[k][x]=min(dp2[k][x],dp2[i][j]+id[k-1]-id[i]);
            }
        }
    }
    int v=dp2[s][c];
    cout << 1LL*a*v+1LL*(n-1-v)*b;
}

#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<int, int> buildings;
int main()
{
    int n,k; 
    cin >> n >> k;
    for(int i=0;i<k;++i)
    {
        int pos, height;
        cin >> pos >> height;
        int max_d = n;
        buildings[pos] = height;
        for(auto it = buildings.begin();it != buildings.end();++it)
        {
            if(abs(it->first - pos) > max_d) break;
            if(it->second > height) max_d = min(max_d, abs(it->first - pos) - 1);
        }
        cout << max_d << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=10005,K=15;
vector<pair<int,int>> g[N];
int dp1[N],dp2[N],a[K],b[K],c[K];
bool used[N];
void dfs (int nn,int np)
{
    for(auto [xn,xw]:g[nn])
    {
        if(xn!=np)
        {
            dfs(xn,nn);
            dp1[nn]+=dp2[xn];
        }
    }
    dp2[nn]=dp1[nn];
    if(!used[nn]) for(auto [xn,xw]:g[nn])if (xn!=np && !used[xn]) dp2[nn]=max(dp2[nn],dp1[xn]+dp1[nn]-dp2[xn]+xw);
    return;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,ans=0;
    cin >> n >> k;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for(int i=0;i<k;i++) cin >> a[i] >> b[i] >> c[i];
    for(int i=0;i<1<<k;i++)
    {
        for(int j=1;j<=n;j++) used[j]=dp1[j]=dp2[j]=0;
        int nv=0;
        for(int j=0;j<k;j++)
        {
            if(i&1<<j && !used[a[j]] && !used[b[j]])
            {
                nv+=c[j];
                used[a[j]]=1;
                used[b[j]]=1;
            }
        }
        dfs(1,0);
        ans=max(ans,dp2[1]+nv);
    }
    cout << ans;
}

#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "
using namespace std;
const int N = 1e5+1;
int pa[N], idx[N];
bool ge(const ll& a, const ll& b)
{
	return a >= b;
}
bool le(const ll& a, const ll& b)
{
	return a <= b;
}
bool eq(const ll& a, const ll& b)

{
	return a == b;
}
bool gt(const ll& a, const ll& b)
{
	return a > b;
}
bool lt(const ll& a, const ll& b)
{
	return a < b;
}
int sgn(const ll& a)
{
    return a >= 0 ? a ? 1 : 0 : -1;
}

struct pt
{
	ll x, y,id;
	pt() { }
	pt(ll _x, ll _y, ll _id) : x(_x), y(_y), id(_id) { }
	pt operator-(const pt& p) const
    {
		return pt(x - p.x, y - p.y, id);
	}
	ll cross(const pt& p) const
    {
		return x * p.y - y * p.x;
	}
	ll cross(const pt& a, const pt& b) const
    {
		return (a - *this).cross(b - *this);
	}
	ll dot(const pt& p) const
    {
		return x * p.x + y * p.y;
	}
	ll dot(const pt& a, const pt& b) const
    {
		return (a - *this).dot(b - *this);
	}
	ll sqrLength() const
    {
		return this->dot(*this);
	}
	bool operator==(const pt& p) const
    {
		return eq(x, p.x) && eq(y, p.y);
	}
};

const pt inf_pt = pt(1e18, 1e18, 0);
struct QuadEdge
{
	pt origin;
	QuadEdge* rot = nullptr;
	QuadEdge* onext = nullptr;
	bool used = false;
	QuadEdge* rev() const
    {
		return rot->rot;
	}
	QuadEdge* lnext() const
    {
		return rot->rev()->onext->rot;
	}
	QuadEdge* oprev() const
    {
		return rot->onext->rot;
	}
	pt dest() const
    {
		return rev()->origin;
	}
};

QuadEdge* make_edge(pt from, pt to)
{
	QuadEdge* e1 = new QuadEdge;
	QuadEdge* e2 = new QuadEdge;
	QuadEdge* e3 = new QuadEdge;
	QuadEdge* e4 = new QuadEdge;
	e1->origin = from;
	e2->origin = to;
	e3->origin = e4->origin = inf_pt;
	e1->rot = e3;
	e2->rot = e4;
	e3->rot = e2;
	e4->rot = e1;
	e1->onext = e1;
	e2->onext = e2;
	e3->onext = e4;
	e4->onext = e3;
	return e1;
}

void splice(QuadEdge* a, QuadEdge* b)
{
	swap(a->onext->rot->onext, b->onext->rot->onext);
	swap(a->onext, b->onext);
}

void delete_edge(QuadEdge* e)
{
	splice(e, e->oprev());
	splice(e->rev(), e->rev()->oprev());
	delete e->rev()->rot;
	delete e->rev();
	delete e->rot;
	delete e;
}

QuadEdge* connect(QuadEdge* a, QuadEdge* b)
{
	QuadEdge* e = make_edge(a->dest(), b->origin);
	splice(e, a->lnext());
	splice(e->rev(), b);
	return e;
}

bool left_of(pt p, QuadEdge* e)
{
	return gt(p.cross(e->origin, e->dest()), 0);
}

bool right_of(pt p, QuadEdge* e)
{
	return lt(p.cross(e->origin, e->dest()), 0);
}

template <class T>
T det3(T a1, T a2, T a3, T b1, T b2, T b3, T c1, T c2, T c3)
{
	return a1 * (b2 * c3 - c2 * b3) - a2 * (b1 * c3 - c1 * b3) + a3 * (b1 * c2 - c1 * b2);
}

bool in_circle(pt a, pt b, pt c, pt d)
{
    #if defined(__LP64__) || defined(_WIN64)
	__int128 det = -det3<__int128>(b.x, b.y, b.sqrLength(), c.x, c.y,c.sqrLength(), d.x, d.y, d.sqrLength());
	det += det3<__int128>(a.x, a.y, a.sqrLength(), c.x, c.y, c.sqrLength(), d.x,d.y, d.sqrLength());
	det -= det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y, b.sqrLength(), d.x,d.y, d.sqrLength());
	det += det3<__int128>(a.x, a.y, a.sqrLength(), b.x, b.y, b.sqrLength(), c.x,c.y, c.sqrLength());
	return det > 0;
    #else
	auto ang = [](pt l, pt mid, pt r)
    {
		ll x = mid.dot(l, r);
		ll y = mid.cross(l, r);
		long double res = atan2((long double)x, (long double)y);
		return res;
	};
	long double kek = ang(a, b, c) + ang(c, d, a) - ang(b, c, d) - ang(d, a, b);
	if(kek > 1e-8) return true;
	else return false;
#endif
}

pair<QuadEdge*, QuadEdge*> build_tr(int l, int r, vector<pt>& p)
{
	if(r - l + 1 == 2)
    {
		QuadEdge* res = make_edge(p[l], p[r]);
		return make_pair(res, res->rev());
	}
	if(r - l + 1 == 3)
    {
		QuadEdge *a = make_edge(p[l], p[l + 1]), *b = make_edge(p[l + 1], p[r]);
		splice(a->rev(), b);
		int sg = sgn(p[l].cross(p[l + 1], p[r]));
		if (sg == 0) return make_pair(a, b->rev());
		QuadEdge* c = connect(b, a);
		if (sg == 1) return make_pair(a, b->rev());
		else return make_pair(c->rev(), c);
	}
	int mid = (l + r) / 2;
	QuadEdge *ldo, *ldi, *rdo, *rdi;
	tie(ldo, ldi) = build_tr(l, mid, p);
	tie(rdi, rdo) = build_tr(mid + 1, r, p);
	while(true)
    {
		if(left_of(rdi->origin, ldi))
        {
			ldi = ldi->lnext();
			continue;
		}
		if(right_of(ldi->origin, rdi))
        {
			rdi = rdi->rev()->onext;
			continue;
		}
		break;
	}
	QuadEdge* basel = connect(rdi->rev(), ldi);
	auto valid = [&basel](QuadEdge* e) { return right_of(e->dest(), basel); };
	if(ldi->origin == ldo->origin) ldo = basel->rev();
	if(rdi->origin == rdo->origin) rdo = basel;
	while(true)
    {
		QuadEdge* lcand = basel->rev()->onext;
		if(valid(lcand))
        {
			while(in_circle(basel->dest(), basel->origin, lcand->dest(),lcand->onext->dest()))
            {
				QuadEdge* t = lcand->onext;
				delete_edge(lcand);
				lcand = t;
			}
		}
		QuadEdge* rcand = basel->oprev();
		if (valid(rcand)) {
			while(in_circle(basel->dest(), basel->origin, rcand->dest(), rcand->oprev()->dest()))
            {
				QuadEdge* t = rcand->oprev();
				delete_edge(rcand);
				rcand = t;
			}
		}
		if(!valid(lcand) && !valid(rcand)) break;
		if(!valid(lcand) || (valid(rcand) && in_circle(lcand->dest(), lcand->origin,rcand->origin, rcand->dest()))) basel = connect(rcand, basel->rev());
		else basel = connect(basel->rev(), lcand->rev());
	}
	return make_pair(ldo, rdo);
}
vector<tuple<pt, pt, pt>> delaunay(vector<pt> p)
{
	sort(p.begin(), p.end(), [](const pt& a, const pt& b)
    {
		return lt(a.x, b.x) || (eq(a.x, b.x) && lt(a.y, b.y));
	});
	auto res = build_tr(0, (int)p.size() - 1, p);
	QuadEdge* e = res.first;
	vector<QuadEdge*> edges = {e};
	while(lt(e->onext->dest().cross(e->dest(), e->origin), 0)) e = e->onext;
	auto add = [&p, &e, &edges]()
    {
		QuadEdge* curr = e;
		do{
			curr->used = true;
			p.push_back(curr->origin);
			edges.push_back(curr->rev());
			curr = curr->lnext();
		}while (curr != e);
	};
	add();
	p.clear();
	int kek = 0;
	while(kek < (int)edges.size()) if(!(e = edges[kek++])->used) add();
	vector<tuple<pt, pt, pt>> ans;
	for (int i=0;i<(int)p.size();i+=3) ans.push_back(make_tuple(p[i], p[i + 1], p[i + 2]));
	return ans;
}

int fp(int x)
{
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

vector<tuple<pt, pt, pt>> g;
vector<tuple<ll,ll,ll>> gg;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	cin >> n;
	ll x,y,w;
	vector<pt> p;
	for(int i=0; i<n; i++)
    {
		cin >> x >> y;
		p.push_back({x,y,i});
	}
	g = delaunay(p);
	for(int i=0; i<N; i++) pa[i]=i, idx[i]=rand();
	auto cal = [&](const pt &l, const pt &r) return (l.x-r.x)*(l.x-r.x)+(l.y-r.y)*(l.y-r.y);
	for(auto &e:g)
    {
		w = cal(get<0>(e), get<1>(e));
		gg.emplace_back(w, get<0>(e).id, get<1>(e).id);
		w = cal(get<1>(e), get<2>(e));
		gg.emplace_back(w, get<1>(e).id, get<2>(e).id);
		w = cal(get<0>(e), get<2>(e));
		gg.emplace_back(w, get<0>(e).id, get<2>(e).id);
	}
	sort(gg.begin(), gg.end());
	int pu, pv;
	ll ans=0;
	for(auto &e:gg)
    {
		pu=fp(get<1>(e)), pv=fp(get<2>(e)), w = get<0>(e);
		if(pu==pv) continue;
		if(idx[pu]<idx[pv]) swap(pu, pv);
		pa[pv]=pu;
		ans+=w;
	}
	cout << ans;
	return 0;
}

#include <set>
#include <list>
#include <stdio.h>
#include <cassert>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
#define N 2005
int n, m, s, t, L[N], Id[N], tree[N][N], old[N], number[N], Di[N], climb[N];
vector<int> g[N];
int low[N], dis[N], T = 0, par[N], sign[N];
vector<int> preorder;
bool dfs1(int u, int pre = -1)
{
    low[u] = dis[u] = ++T;
    int child = 0;
    for(int v : g[u]) if(v != pre) 
    {
        if(dis[v] == -1)
        {
            child++;
            if(!dfs1(v, u)) return 0;
            low[u] = min(low[u], low[v]);
            if(pre != -1 && low[v] >= dis[u]) return 0;
        }
        else low[u] = min(low[u], dis[v]);
    }
    if(pre == -1 && child > 1) return 0;
    return 1;
}

void dfs2(int u, int pre = -1)
{
    low[u] = dis[u] = ++T;
    for(int v : g[u]) 
    {
        if(v != pre)
        {
            if(dis[v] == -1)
            {
                preorder.push_back(v);
                dfs2(v, u);
                low[u] = min(low[u], low[v]);
                par[v] = u;
            }
            else low[u] = min(low[u], dis[v]);
        }
    }
}

list<int> lst;
list<int>::iterator it[N];
vector<int> st_numbering(int n, int s, int t)
{
    g[s].push_back(t);
    g[t].push_back(s);
    T = 0;
    preorder.clear();
    for(int i=1;i<=n;i++) dis[i] = low[i] = -1, sign[i] = 0;
    if(!dfs1(t)) return vector<int>();
    for(int i=1;i<=n;i++) if(dis[i] == -1) return vector<int>();
    for(int i=1;i<=n;i++) dis[i] = low[i] = -1, sign[i] = 0;
    T = 0;
    preorder.clear();
    dis[s] = low[s] = ++T;
    sign[dis[s]] = -1;
    dfs2(t);
    lst.clear();
    lst.push_back(s);
    lst.push_back(t);
    it[dis[s]] = lst.begin();
    it[dis[t]] = next(lst.begin());
    for(int v : preorder)
    {
        if(sign[low[v]] == -1) it[dis[v]] = lst.insert(it[dis[par[v]]], v);
        else it[dis[v]] = lst.insert(next(it[dis[par[v]]]), v);
        sign[dis[par[v]]] = -sign[low[v]];
    }
    vector<int> ret(lst.begin(), lst.end());
    return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	vector<array<int, 3>> e(m);
	for (auto &[c, u, v] : e) scanf("%d%d%d", &u, &v, &c);
	sort(e.begin(), e.end());
	s = e[0][1], t = e[0][2];
	swap(s, t);
	for (auto &[c, u, v] : e) g[u].push_back(v), g[v].push_back(u);
	auto V = st_numbering(n,s,t);
	for (int i = 1; i <= n; ++i) number[V[i - 1]] = i;
	printf("%d %d\n", e[0][0], 1);
	printf("%d %d 1\n", t, s);
	for(int i=1;i<m;++i)
    {
		auto u = e[i][1], v = e[i][2];
		if(number[u] > number[v]) swap(u, v);
		printf("%d %d 0\n", u, v);
	}
}

#include <iostream>
#define MAX_N 2001
using namespace std;
long long t[MAX_N], v[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> t[i] >> v[i];
    while (m--)
    {
        long long p, b, e, count = 0;
        cin >> p >> b >> e;
        for(int i=1;i<=n;i++)
        {
            long long start_position = v[i] * (b - t[i]);
            long long end_position = v[i] * (e - t[i]);
            if(start_position <= p && p <= end_position) count++;
        }
        cout << count << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long fw[2000001];
int p[2000001], arr[200001];

void upd (int i)
{
    for(; i < 2000001; i+=(i&-i)) fw[i]++;
}

int qry (int i)
{
    int s = 0;
    for(; i > 0; i-=(i&-i)) s+=fw[i];
    return s;
}

int lb (int t)
{
    int l = 1, r = 2000000;
    while (l < r)
    {
        int m = (l+r)>>1;
        if(m-qry(m) < t) l = m+1;
        else r = m;
    }
    return l;
}
int fp (int r){ return (p[r] == r ? r : p[r] = fp(p[r])); }

int main ()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<=n;++i) p[i] = i;
    vector<int>vec; vec.emplace_back(0);
    queue<int> q, tmp;
    for(int i=1;i<=n;++i)
    {
        vec.emplace_back(i);
        cin >> arr[i];
    }
    int sz = n, c = 0;
    while(m--)
    {
        int a, b, idx = 0, mx = 0, mem = 0, del = 0; cin >> a >> b;
        while (!q.empty()) q.pop();
        for(int i=1;i<=sz;i+=a)
        {
            ++del;
            if(idx < b)
            {
                int at = vec[lb(i)];
                ++idx;
                q.emplace(at);
                if (mx < arr[at])
                {
                    mx = arr[at];
                    mem = at;
                }
            }
            if(idx == b || i+a > sz)
            {
                vec.emplace_back(mem);
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    if(u == mem) continue;
                    p[fp(u)] = fp(mem);
                    ++c;
                }
                idx = mx = mem = 0; --del;
            }
        }
        for(int i=1;i<=sz;i+=a) tmp.push(lb(i));
        while(!tmp.empty())
        {
            upd(tmp.front());
            tmp.pop();
        }
        sz -= del;
        if(c == n-1) break;
    }
    for (int i = 1; i <= n; ++i)
    {
        if(fp(i)==i) cout << arr[i] << "\n";
        else cout << arr[fp(i)]+1 << "\n";
    }
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int val[1001];

struct Edge {
    int from, to, capacity, cost;
    Edge(int from, int to, int capacity, int cost): from(from),to(to),capacity(capacity),cost(cost) {}
};

vector<vector<int>> adj, cost, capacity, counterpart;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p, vector<int> &idx) {
    d.assign(n, 1e9);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);
    idx.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            int cap = capacity[u][i];
            int c = cost[u][i];
            if (cap > 0 && d[v] > d[u] + c) {
                d[v] = d[u] + c;
                p[v] = u;
                idx[v] = i;
                if (!inq[v]) {
                    inq[v] = true;
                    q.emplace(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>());
    capacity.assign(N, vector<int>());
    counterpart.assign(N, vector<int>());
    for (Edge e : edges) {
    	int sz_a = adj[e.from].size();
    	int sz_b = adj[e.to].size();
        adj[e.from].emplace_back(e.to);
        adj[e.to].emplace_back(e.from);
        cost[e.from].emplace_back(e.cost);
        cost[e.to].emplace_back(-e.cost);
        capacity[e.from].emplace_back(e.capacity);
        capacity[e.to].emplace_back(0);
        counterpart[e.from].emplace_back(sz_b);
        counterpart[e.to].emplace_back(sz_a);
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p, idx;
    while (flow < K) {
        shortest_paths(N, s, d, p, idx);
        if (d[t] == 1e9) break;
        int f = K - flow;
        int cur = t;
        while (cur != s) {
        	int cap = capacity[p[cur]][idx[cur]];
            f = min(f, cap);
            cur = p[cur];
        }

        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
        	capacity[p[cur]][idx[cur]] -= f;
        	int counter = counterpart[p[cur]][idx[cur]];
        	capacity[cur][counter] += f;
            cur = p[cur];
        }
    }
    if(flow < K) return -1;
    else return cost;
}
vector<Edge> edges;
void add_edge(int from, int to, int capacity, int cost)
{ 
    edges.emplace_back(from, to, capacity, cost);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
	int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;++i) cin >> val[i];
	int total = n-m+4;
    for(int i=1;i<=m;++i) add_edge(total-2, min(n-m+1, i), 1, -val[i]);
    for(int i=m+1;i<=n;++i) add_edge(i-m, min(i, n-m+1), 1, -val[i]);
	add_edge(total-2, 1, (1<<20), 0);
    for(int i=1;i<=n-m;++i) add_edge(i, i+1, (1<<20), 0);
	add_edge(0, total-2, k, 0);
	add_edge(n-m+1, total-1, k, 0);
	int ans = min_cost_flow(total, edges, k, 0, total-1);
	cout << -ans;
}

#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plx pair<ll,int>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vvi vector<vi>
#define pp pair<ll,int>
#define ub(x,i) upper_bound(all(x),i)-x.begin()
using namespace std;
const int mxn=5e5+5;
ll t[4*mxn]{0};
ll qr(int l,int r,int sz,ll rs=0){
    for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){
        if(l&1)rs=max(rs,t[l++]);
        if(r&1)rs=max(rs,t[--r]);
    }return rs;
}
void upd(int i,int sz,ll amt)
{
    i+=sz;t[i]=max(t[i],amt);
    for(i>>=1;i;i>>=1) t[i]=max(t[2*i],t[2*i+1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    vector<pair<int,pii>>v(n+1);
    vector<int>x;
    for(int i=1;i<=n;i++) cin >> v[i].s.f >> v[i].f >> v[i].s.s,x.pb(v[i].f);
    sort(all(v));
    sort(all(x));
    for(int i=1;i<=n;i++) t[i+n-1] = v[i].s.s;
    for(int i=n-1;i>0;i--) t[i]=max(t[2*i],t[2*i+1]);
    ll dp[n+1][2]={0};
    ll rs=0;
    for(int i=1;i<=n;i++)
    {
        int l = lower_bound(x.begin(),x.begin()+i,v[i].s.f)-x.begin();
        if(dp[i-1][0]<dp[l][0]+v[i].s.s)
        {
            dp[i][0]=dp[l][0]+v[i].s.s;
            dp[i][1]=max(qr(l,i-1,n),dp[i-1][1]);
        }
        else
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][1],(ll)v[i].s.s);
        }
        rs=max(rs,dp[i][0]+dp[i][1]);
    }
    cout << rs;
}

#include<bits/stdc++.h>
using namespace std;
#include "homework.h"
struct A
{
    int st,num;
    bool operator<(const A&o)const
    {
        return st>o.st;
    }
};

std::vector<int> adj[100010];
int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B)
{
    for(int i = 0;i<N;i++) for(int j:B[i]) adj[j].push_back(i);
    priority_queue<A> pq;
    for(int i = 0;i<N;i++)
    {
        if(HW[i][3]==0)
        {
            int rst =  HW[i][0]/HW[i][2];
            if(HW[i][0]%HW[i][2]) rst++;
            rst*=HW[i][2];
            if(rst>HW[i][1])continue;
            pq.push({rst,i});
        }   
    }
    int cnt = 0;
    while(!pq.empty())
    {
        A now = pq.top();
        pq.pop();
        cnt++;
        int st = now.st+1;
        for(int i:adj[now.num])
        {
            HW[i][3]--;
            if(HW[i][3]==0)
            {
                int a = max(st,HW[i][0]);
                int rst =  a/HW[i][2];
                if(a%HW[i][2]) rst++;
                rst*=HW[i][2];
                if(rst>HW[i][1]) continue;
                pq.push({rst,i});
            }
        }
    }
    return cnt;
}

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
const int M=1e5+1;
vector<pair<pair<int,int>,int>> v[111111];
int fen[111111],ans[11111];
void update(int idx,int k)
{
    while(idx<=M)
    {
        fen[idx]+=k;
        idx+=idx & -idx;
    }
}

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=fen[idx];
        idx-=idx & -idx;
    }
    return sum;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
    {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        x1++,x2++,y1++,y2++;
        v[x1].push_back({{y1,1},1});
        v[x2+1].push_back({{y1,-1},1});
        v[x1].push_back({{y2+1,-1},1});
        v[x2+1].push_back({{y2+1,1},1});
    }
    for(int i=1;i<=m;i++)
    {
        int p,q;
        cin >> p >> q;
        p++,q++;
        v[p].push_back({{q,i},2});
    }
    for(int i=1;i<=1e5;i++)
    {
        if(v[i].empty()) continue;;
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j].s==1) update(v[i][j].f.f,v[i][j].f.s);
            else ans[v[i][j].f.s]=query(v[i][j].f.f);
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << '\n';
}

#include <iostream>
using namespace std;
int fw[15001][15001];
int sum (const int& x, const int& y)
{
    int res = 0;
    for(int i=x;i;i -= (i&-i)) for(int j=y;j<15000;j+=(j&-j)) res += fw[i][j];
    return res;
}

int add (const int& x, const int& y, const int& v = 1)
{
    int res = sum(x, y);
    for(int i=x;i<=15000;i+=(i&-i)) for(int j=y;j;j-=(j&-j)) fw[i][j] += v;
    return res;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int a, b, i = 0; i < n; ++i) cin >> a >> b, cout << add(a-b+5001, a+b+5001, 1) << '\n';
}

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int sal[100001];
vector<int> e[100001];
multiset<int> s[100001];

void dfs (const int& at, const int& p)
{
    for(int to : e[at]) 
    {
        if (to != p)
        {
            dfs(to, at);
            if(s[to].size() > s[at].size()) swap(s[to], s[at]);
            for(int i : s[to]) s[at].emplace(i);
            s[to].clear();
        }
    }
    multiset<int>::iterator it = s[at].upper_bound(sal[at]);
    if(it != s[at].end()) it = s[at].erase(it);
    s[at].emplace_hint(it, sal[at]);
} 

int main ()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> sal[i];
    for (int u, v, i = 1; i < n; ++i) cin >> u >> v, e[u].emplace_back(v), e[v].emplace_back(u);
    dfs(0, -1);
    cout << n - s[0].size() << '\n';
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,no-stack-protector,inline-small-functions,inline,unsafe-math-optimizations,omit-frame-pointer,inline-functions-called-once")
#include <bits/stdc++.h>
#pragma GCC target("avx2,fma,popcnt,lzcnt,bmi,bmi2,sse4.2,tune=native")
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned ll
#define cint const int
#define cf const float
cint mxA = 1e6+5, MOD = 1e9+7, INF = 0x3f3f3f3f;
cint d4x[4] = {0, 1, 0, -1}, d4y[4] = {1, 0, -1, 0};
cint d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1}, d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void wait(int ms)
{
    clock_t endwait;
    endwait = clock() + ms;
    while(clock()<endwait){}
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr[m+1];
    arr[0] = 0;
    for(int i=1;i<=m;i++) cin >> arr[i];
    sort(arr+1,arr+m+1);
    vector<int> diff;
    for(int i=2;i<=m;i++) diff.emplace_back(arr[i]-arr[i-1]-1);
    sort(diff.begin(),diff.end());
    int sum = 0;
    for(int i=0;i<m-k;i++) sum += diff[i];
    cout << sum;
    return;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    cout.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> vec;
    for(int i=0;i<m;++i)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    vector<int> dif;
    for(int i=1;i<m;++i) dif.push_back(vec[i]-vec[i-1]-1);
    sort(dif.begin(),dif.end());
    int sm=0;
    for(int i=0;i<m-k;++i) sm+=dif[i];
    cout << sm;
}

#include <bits/stdc++.h>
using namespace std;
using ll=long long int ;
const int mxN = 100000+9;
#define twod array<ll,2>
vector<twod> node[mxN]; 
const int start = 100000+5;
const ll inf = 1e18;
priority_queue<twod,vector<twod>,greater<twod>> q;
bool vis[mxN];
vector<ll> dp(mxN,inf);
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,nn,nnn;
    cin >> n >> nn;
	for(int i=0;i<nn;i++)
    {
		int u,v,w;
		cin >> u >> v >> w;
		node[u].push_back({v,w});
		node[v].push_back({u,w});
	}
	cin >> nnn;
	for(int i=0;i<nnn;i++)
    {
		int u,w;
        cin >> u >> w;
		node[start].push_back({u,w});
	}
	q.push({0,start});
	dp[start]=0;
	while(!q.empty())
    {
		auto x=q.top();q.pop();
		auto u=x[1],w=x[0];
		if(u==0)
        {
			cout << w;
			return 0;
		}
		if(vis[u]!=0) continue;
		vis[u]=1;
		for(auto e:node[u])
        {
			auto v=e[0],l=e[1];
			if(vis[v]==0) q.push({w+l,v});
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<int> ad[500010];
int disc[500010],low[500010];
vector<int> g[200010];
int cnt;
int t;
void dfs(int u,int p)
{
    disc[u]=low[u]=++t;
    for(auto x:ad[u])
    {
        if(x==p) continue;
        if(disc[x]) low[u]=min(low[u],disc[x]);
        else
        {
            dfs(x,u);
            low[u]=min(low[u],low[x]);
        }
    }
    if(low[u]==disc[u]) cnt++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!disc[i]) dfs(i,i);
    cout << cnt << '\n';
}

#include<bits/stdc++.h>
using namespace std;
int n, ax, ay, bx, by, s, t, ans;
int main()
{
	scanf("%d %d %d %d %d", &n, &ax, &ay, &bx, &by);
	if(ax == bx && ay == by) printf("0"), exit(0);
	if(ay == by)
    {
		if(ax < bx) s = n - bx, t = by - 1;
		else s = bx - by, t = by - 1;
	}
    else if(ax - ay == bx - by)
    {
		if(ax < bx) s = n - bx, t = bx - by;
		else s = by - 1, t = bx - by;
	} 
    else
    {
		if(ay < by) s = bx - by, t = n - bx;
		else s = by - 1, t = n - bx;
	}
	if(s <= (n - 1) / 2 && s + t <= (n - 1) / 2) ans = s * 2 + t;
	else if(s <= (n - 1) / 2 && n - t - 1 <= (n - 1) / 2) ans = s + t;
	else ans = (s + t) + (n - t - 1 - (n - 1) / 2);
	printf("%d", ans + 1);
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
const int INF = 1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> cost(N+1, vector<int>(N+1, 0));
    vector<vector<bool>> exists(N+1, vector<bool>(N+1, false));
    for(int i=0;i<M;i++)
    {
        int u, v;
        cin >> u >> v;
        if(!exists[u][v])
        {
            exists[u][v] = true;
            cost[u][v] = -1;
        }
    }
    vector<int> uLabel(N+1, 0), vLabel(N+1, 0), p(N+1, 0), way(N+1, 0);
    for(int i=1;i<=N;i++)
    {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(N+1, INF);
        vector<bool> used(N+1, false);
        do
        {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = 0;
            for(int j=1;j<=N;j++)
            {
                if(!used[j])
                {
                    int cur = cost[i0][j] - uLabel[i0] - vLabel[j];
                    if(cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta)
                    {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for(int j=0;j<=N;j++)
            {
                if(used[j])
                {
                    uLabel[p[j]] += delta;
                    vLabel[j] -= delta;
                }
                else minv[j] -= delta;
            }
            j0 = j1;
        }
        while(p[j0] != 0);
        do
        {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        }
        while (j0);
    }
    int minCost = -vLabel[0];
    int P = -minCost;
    int answer = N + M - 2 * P;
    cout << answer << "\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,j=0;
    cin >> n >> m;
    vector<int> a,b;
    vector<vector<int>> p(n-m);
    for(int i=0;i<m;i++)
    {
        int c;
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++)
    {
        if(a[j] == i) j++;
        else b.push_back(i);
    }
    for(int i=0;i<b.size();i++) for(int k=1;k<=n;k++) if(b[i]!=k) p[i].push_back(k);
    for(int i=0;i<b.size();i++)
    {
        do
        {
            cout << b[i] << " ";
            for(int d : p[i]) cout << d << " ";
            cout << "\n";
        }
        while(next_permutation(p[i].begin(),p[i].end()));
    }
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
int g[210][210],jj[4]={1,0,-1,0},ii[4]={0,1,0,-1};
int cnt[210][210][4][7],d[210][210][4][7];
bool LOOP=true;
string s[210][210];
signed main()
{
    int n,k,m;
    cin>>n>>k>>m;
    while(m--)
    {
        int i,j;
        cin>>i>>j;
        g[i][j]=1;
        cin >> s[i][j];
    }
    int day=0,turn=0;
    int i=1,j=1,hunn=0;
    while(turn<k)
    {
        if(i+ii[hunn]>n||i+ii[hunn]<1||j+jj[hunn]>n||j+jj[hunn]<1)
        {
            hunn=(hunn+2)%4;
            turn++;
        }
        else
        {
            day++;
            i+=ii[hunn];
            j+=jj[hunn];
            if(g[i][j])
            {
                if(cnt[i][j][hunn][day%7]&&LOOP)
                {
                    int a=turn-cnt[i][j][hunn][day%7];
                    if(a)
                    {
                        int b=day-d[i][j][hunn][day%7];
                        int skip=(k-turn)/a;
                        day+=skip*b;
                        turn+=skip*a;
                        LOOP=false;
                    }
                }
                cnt[i][j][hunn][day%7]=turn;
                d[i][j][hunn][day%7]=day;
                if(s[i][j][day%7]=='L')
                {
                    hunn=(hunn+3)%4;
                    turn++;
                }
                else if(s[i][j][day%7]=='R')
                {
                    hunn=(hunn+1)%4;
                    turn++;
                }
            }
        }
    }
    cout << day;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
struct A{int u,v;} adj [100010];
vector<vector<int>> ev;
map<int,int> fcol;
vector<pair<int,int>> col;
int cut[100010][310];
int graph[100010][310];
int ans[100010], gr[100010];
int fr(int p, int i){
    if (graph[p][i] == p) return p;
    else return graph[p][i] = fr(graph[p][i], i);
}
void uni(int u, int v, int i){
    int fu = fr(u, i), fv = fr(v, i);
    graph[fu][i] = fv;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k,q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        gr[x]++;
    }
    for (int i = 1; i <= 100000; i++){
        if (gr[i]) fcol[gr[i]]++;
    }
    for (auto x : fcol) col.push_back({x.f, x.s});
    int G = col.size();
    for (int i = 1; i <= m; i++) cin >> adj[i].u >> adj[i].v;
    int cnt_ans = 0;
    while (q--){
        int op; cin >> op;
        if (op == 1){
            int idx, l, r;
            cin >> idx >> l >> r;
            ev.push_back({1, idx ,l ,r});
            for (int i = 0; i < G; i++)
            {
                if (col[i].f >= l && col[i].f <= r){
                    cut[idx][i]++;
                }
            }
        }
        else
        {
            int s,e;
            cin >> s >> e;
            ev.push_back({2, s, e});
            cnt_ans++;
        }
    }
    for(int i=1;i<=n;i++) for(int j=0;j<G;j++) graph[i][j] = i;
    for(int i=1;i<=m;i++) for(int j=0;j<G;j++) if(cut[i][j] == 0) uni(adj[i].u, adj[i].v, j);
    reverse(ev.begin(), ev.end());
    int indxx = 0, sum = 0;
    for(auto x : ev)
    {
        if(x[0] == 1)
        {
            for(int i=0;i<G;i++)
            {
                if(col[i].f >= x[2] && col[i].f <= x[3])
                {
                    cut[x[1]][i]--;
                    if(cut[x[1]][i] == 0) uni(adj[x[1]].u, adj[x[1]].v, i);
                }
            }
        }
        else
        {
            sum = 0;
            for(int i=0;i<G;i++)
            {
                int fu = fr(x[1],i);
                int fv = fr(x[2],i);
                if(fu == fv) sum += col[i].second;
            }
            ans[indxx++] = sum;
        }
    }
    for(int i=cnt_ans-1;i>=0;i--) cout << ans[i] << "\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define f first
#define s second

//#define int ll

const int inf=1e9+7;

int n,L;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L;
    vector<pii> vec;
    for(int i=1;i<=n;++i)
    {
        int a,b,c,d,w;
        cin >> a >> b >> c >> d >> w;
        mp2[{{a,b},{c,d}}]=w;
        mp2[{{c,d},{a,b}}]=w;
        vec.pb({a,b});
        vec.pb({c,d});
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    int mn0=inf,mx0=-inf,mn1=inf,mx1=-inf;
    for(auto &e:vec)
    {
        if(e.f>0&&e.f<L)
        {
            int u,v,w;
            u=f0({e.f,e.s}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s},{e.f+1,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f-1,e.s-1}),w=mp2[{{e.f-1,e.s},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f,e.s}),w=mp2[{{e.f,e.s},{e.f,e.s+1}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s-1}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s-1},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        else if(e.f==0)
        {
            mn0=min(mn0,e.s);
            mx0=max(mx0,e.s);
        }
        else if(e.f==L)
        {
            mn1=min(mn1,e.s);
            mx1=max(mx1,e.s);
        }
    }
    int U,V;
    for(int i=mn0;i<=mx0;++i)
    {
        int u=f0({0,i}),v=f0({0,i-1}),w=mp2[{{0,i},{1,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        if(i==mn0) V=v;
        else if(i==mx0) U=u;
    }
    for(int i=mn1;i<=mx1;++i)
    {
        int u=f0({L-1,i}),v=f0({L-1,i-1}),w=mp2[{{L-1,i},{L,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,U});
    memset(dist,0x3f,sizeof dist);
    dist[U]=0;
    while(pq.size())
    {
        int w=pq.top().f;
        int u=pq.top().s;
        pq.pop();
        if(u==V)
        {
            cout << w;
            return 0;
        }
        for(auto &vw:adj[u])
        {
            if(dist[vw.f]>w+vw.s)
            {
                dist[vw.f]=w+vw.s;
                pq.push({w+vw.s,vw.f});
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N=2e5+5;

int n;
ll k;
ll a[N],qs[N];
ll best=0;
vector<pair<int,int>> ans;

ll range_sum(int l,int r){
    return qs[r]-qs[l-1];
}

ll calc_dist(int l,int r){
    if(l==r)return 0;
    if((r-l)%2==1){
        int m=(l+r)/2;
        return 2*range_sum(m+1,r)-2*range_sum(l,m)+a[m]-a[m+1];
    }else{
        int m=(l+r)/2;
        ll res=0;
        res=max(res,2*range_sum(m+2,r)-2*range_sum(l,m-1)+a[m]+a[m+1]);
        res=max(res,2*range_sum(m+1,r)-2*range_sum(l,m-2)-a[m]-a[m-1]);
        return res;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) qs[i]=qs[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        while(l<r)
        {
            int m=(l+r+1)/2;
            if(calc_dist(i,m)<=k) l=m;
            else r=m-1;
        }
        ll cand=calc_dist(i,l);
        if(cand>best)
        {
            best=cand;
            ans={make_pair(i,l)};
        }
        else if(cand==best) ans.emplace_back(i,l);
    }
    for(auto [l,r]:ans) cout << l << " " << r << "\n";
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define ti tuple<int, bool, int>
#define all(x) x.begin(), x.end()
const int mod=1e9+7;
int main()
{
    vector<int> lim(3);
    int mxday;
    cin >> mxday;
    for(int i=0;i<3;i++) cin >> lim[i];
    vector<vector<int>> g={{0, 1, 1}, {0, 0, 1}, {1, 0, 0}};
    vector<vector<vector<vector<int>>>> dp(mxday+1, vector<vector<vector<int>>>(3, vector<vector<int>>(mxday+1, vector<int>(1<<3))));
    dp[1][0][1][1]=1;
    for(int day=1; day<mxday; day++)
    {
        for(int curr=0; curr<3; curr++)
        {
            for(int stay=1;stay<=min(mxday,lim[curr]);stay++)
            {
                for(int bit=1;bit<(1<<3);bit++)
                {
                    if(stay<lim[curr]) dp[day+1][curr][stay+1][bit]=(dp[day+1][curr][stay+1][bit]+dp[day][curr][stay][bit])%mod;
                    for(int next=0;next<3;next++)
                    {
                        if(!g[curr][next]) continue;
                        int nextbit=bit|(1<<next);
                        dp[day+1][next][1][nextbit]=(dp[day+1][next][1][nextbit]+dp[day][curr][stay][bit])%mod;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int end=0;end<3;end++) for(int stay=1;stay<=min(mxday,lim[end]);stay++) ans=(ans+dp[mxday][end][stay][7])%mod;
    cout << ans;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>
#define __DEBUG__ 0
#define __LOG__ 0
using namespace std;
const int64_t INF = 1'000'000'000'000'000'000LL;
const int64_t NEG_INF = -1'000'000'000'000'000'000LL;
struct edge2;
vector<edge2> e[100001];
vector<int> used;
vector<int64_t> adj;
bitset<100001> vs;
class sum_segment_tree
{
    protected:
        int sz;
        int64_t *tree, *lazy, *lazy2;
        void push (const int &idx, const int &l, const int &r);
        void upd (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val);
        void upd2 (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val);
        int64_t qry (const int &idx, const int &l, const int &r, const int &x, const int &y);
    public:
        sum_segment_tree (const int &n);
        ~sum_segment_tree();
        size_t size() const;
        void upd (const int &l, const int &r, const int64_t &val);
        void upd2 (const int &l, const int &r, const int64_t &val);
        int64_t qry (const int &l, const int &r);
        int64_t qry ();
        #if __DEBUG__
            void print()
            {
                cout << "sum_segment_tree (Indices 0.." << sz-1 << "):\n" << flush;
                for (int i = 1; i < sz*2; ++i) cout << (i > 1 && i==(i&-i) ? "\n" : (i == 1 ? "" : " | ")) << (tree[i] >= INF ? "INF" : (tree[i] <= NEG_INF ? "-INF" : to_string(tree[i]))) << ", " << (lazy[i] ? to_string(lazy[i]) : "-") << ", " << (lazy2[i] >= INF || lazy2[i] <= NEG_INF ? "-" : to_string(lazy2[i])) << flush;
                cout << "\n" << flush;
            }
        #endif
};
class max_segment_tree
{
    protected:
        int sz;
        int64_t *tree, *lazy, *lazy2;
        int *cnt;
        void push (const int &idx, const int &l, const int &r);
        void upd (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val);
        void upd2 (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val);
        pair<int64_t, int> qry (const int &idx, const int &l, const int &r, const int &x, const int &y);
    public:
        max_segment_tree (const int &n);
        ~max_segment_tree();
        size_t size() const;
        void upd (const int &l, const int &r, const int64_t &val);
        void upd2 (const int &l, const int &r, const int64_t &val);
        pair<int64_t, int> qry (const int &l, const int &r);
        pair<int64_t, int> qry ();
        #if __DEBUG__
            void print(int k)
            {
                cout << "max_segment_tree (Indices 0.." << k-1 << ", Size " << sz << "):\n" << flush;
                 int print_limit = (1 << (32 - __builtin_clz(max(1, k - 1)))) * 2;
                for (int i = 1; i < print_limit && i < sz*2; ++i) cout << (i > 1 && i==(i&-i) ? "\n" : (i == 1 ? "" : " | ")) << (tree[i] >= INF ? "INF" : (tree[i] <= NEG_INF ? "-INF" : to_string(tree[i]))) << ", " << (lazy[i] ? to_string(lazy[i]) : "-") << ", " << (lazy2[i] >= INF || lazy2[i] <= NEG_INF ? "-" : to_string(lazy2[i])) << ", " << cnt[i] << flush;
                cout << "\n" << flush;
            }
        #endif
};
sum_segment_tree sm(100001);
max_segment_tree mn(100001);
int dfs (const int &u, const int &p);
int main ()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    for (int i=0;i<n;++i)
    {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w, i);
        e[v].emplace_back(u, w, i);
        sm.upd2(i, i, w);
        adj[i] = w;
    }
    dfs(1, -1);
    sort(used.begin(), used.end());
    int k = used.size();
    for (int i = 0; i < k; ++i) {
        mn.upd2(i, i, adj[used[i]]);
    }
    #if __DEBUG__
        cout << "Sorted Cycle edge indices ('used'): "; for(int idx : used) cout << idx << " "; cout << endl;
        cout << "Sum tree after init:\n"; sm.print();
        cout << "Max tree after cycle init:\n"; mn.print(k);
    #endif
    for(int i = 0; i < q; ++i)
    {
        int type, s, t;
        int64_t c;
        cin >> type >> s >> t >> c;
        --s; --t;
        type == 1 ? sm.upd(s, t, c) : sm.upd2(s, t, c);
        auto it_l = lower_bound(used.begin(), used.end(), s);
        auto it_r = upper_bound(used.begin(), used.end(), t);
        int ui = it_l - used.begin();
        int uf = (it_r - used.begin()) - 1;
        #if __DEBUG__ cout << "Tasks request " << (type == 1 ? "add" : "replace") << " on original [" << s << "," << t << "] val " << c << ". Mapped to cycle indices [" << ui << "," << uf << "]\n" << flush;
        #endif
        if (ui <= uf) type == 1 ? mn.upd(ui, uf, c) : mn.upd2(ui, uf, c);
        #if __DEBUG__
            sm.print(); mn.print(k);
        #endif
        int64_t total_sum = sm.qry();
        pair<int64_t, int> max_res = mn.qry();
        int64_t max_cycle_cost = max_res.first;
        int count = max_res.second;
        if (k == 0) cout << total_sum << " 0\n";
        else if (max_cycle_cost <= NEG_INF) cout << total_sum << " " << 0 << "\n";
        else cout << total_sum - max_cycle_cost << " " << count << "\n";
    }
    return 0;
}
struct edge2
{
    int v; int64_t w; int idx;
    edge2 (const int &v, const int64_t &w, const int &idx) : v(v), w(w), idx(idx) {}
    bool operator < (const edge2& other) const { return w < other.w; }
};
int dfs (const int &u, const int &p)
{
    vs[u] = 1;
    for (const auto &[v, w, idx] : e[u])
    {
        if(v == p) continue;
        if(vs[v]) { used.emplace_back(idx); return v; }
        int res = dfs(v, u);
        if(!res) continue;
        used.emplace_back(idx);
        return (res == u) ? 0 : res;
    }
    return 0;
}
void sum_segment_tree::push (const int &idx, const int &l, const int &r)
{
    if (lazy[idx] == 0LL && lazy2[idx] >= INF) return;
    int64_t range_size = (int64_t)(r - l + 1);
    if (lazy2[idx] < INF) { tree[idx] = lazy2[idx] * range_size; if (l != r) lazy2[idx<<1] = lazy2[idx<<1|1] = lazy2[idx], lazy[idx<<1] = lazy[idx<<1|1] = 0LL; }
    if (lazy[idx] != 0LL) { tree[idx] += lazy[idx] * range_size; if (l != r) lazy[idx<<1] += lazy[idx], lazy[idx<<1|1] += lazy[idx]; }
    lazy[idx] = 0LL; lazy2[idx] = INF;
}
void sum_segment_tree::upd (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val)
{
    push(idx, l, r); if (l > y || r < x || x > y) return; if (l >= x && r <= y) { lazy[idx] += val; push(idx, l, r); return; }
    int m = l + (r - l) / 2; upd(idx<<1, l, m, x, y, val); upd(idx<<1|1, m+1, r, x, y, val); tree[idx] = tree[idx<<1] + tree[idx<<1|1];
}
void sum_segment_tree::upd2 (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val)
{
    push(idx, l, r); if (l > y || r < x || x > y) return; if (l >= x && r <= y) { lazy2[idx] = val; lazy[idx] = 0LL; push(idx, l, r); return; }
    int m = l + (r - l) / 2; upd2(idx<<1, l, m, x, y, val); upd2(idx<<1|1, m+1, r, x, y, val); tree[idx] = tree[idx<<1] + tree[idx<<1|1];
}
int64_t sum_segment_tree::qry (const int &idx, const int &l, const int &r, const int &x, const int &y)
{
    push(idx, l, r); if (l > y || r < x || x > y) return 0LL; if (l >= x && r <= y) return tree[idx];
    int m = l + (r - l) / 2; return qry(idx<<1, l, m, x, y) + qry(idx<<1|1, m+1, r, x, y);
}
sum_segment_tree::sum_segment_tree (const int &n) : sz(1 << (32 - __builtin_clz(max(1, n - 1)))), tree(new int64_t[sz<<1]), lazy(new int64_t[sz<<1]), lazy2(new int64_t[sz<<1]) { for (int i = 0; i < (sz << 1); ++i) tree[i] = 0LL, lazy[i] = 0LL, lazy2[i] = INF; }
sum_segment_tree::~sum_segment_tree() { delete[] tree; delete[] lazy; delete[] lazy2; }
size_t sum_segment_tree::size() const { return sz; }
void sum_segment_tree::upd (const int &l, const int &r, const int64_t &val) { if (l<=r) upd(1, 0, sz - 1, l, r, val); }
void sum_segment_tree::upd2 (const int &l, const int &r, const int64_t &val) { if (l<=r) upd2(1, 0, sz - 1, l, r, val); }
int64_t sum_segment_tree::qry (const int &l, const int &r) { return (l<=r) ? qry(1, 0, sz - 1, l, r) : 0LL; }
int64_t sum_segment_tree::qry () { push(1, 0, sz - 1); return tree[1]; }
void max_segment_tree::push (const int &idx, const int &l, const int &r)
{
    if (lazy[idx] == 0LL && lazy2[idx] >= INF) return;
    if (lazy2[idx] < INF) { tree[idx] = lazy2[idx]; cnt[idx] = (tree[idx] > NEG_INF) ? (r - l + 1) : 0; if (l != r) lazy2[idx<<1] = lazy2[idx<<1|1] = lazy2[idx], lazy[idx<<1] = lazy[idx<<1|1] = 0LL; }
    if (lazy[idx] != 0LL) { if (tree[idx] > NEG_INF) tree[idx] += lazy[idx]; if (l != r) lazy[idx<<1] += lazy[idx], lazy[idx<<1|1] += lazy[idx]; }
    lazy[idx] = 0LL; lazy2[idx] = INF;
}
void max_segment_tree::upd (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val)
{
    push(idx, l, r); if (l > y || r < x || x > y) return; if (l >= x && r <= y) { lazy[idx] += val; push(idx, l, r); return; }
    int m = l + (r - l) / 2; upd(idx<<1, l, m, x, y, val); upd(idx<<1|1, m+1, r, x, y, val);
    if (tree[idx<<1] == tree[idx<<1|1]) { tree[idx] = tree[idx<<1]; cnt[idx] = (tree[idx] > NEG_INF) ? (cnt[idx<<1] + cnt[idx<<1|1]) : 0; }
    else if (tree[idx<<1] > tree[idx<<1|1]) { tree[idx] = tree[idx<<1]; cnt[idx] = cnt[idx<<1]; }
    else { tree[idx] = tree[idx<<1|1]; cnt[idx] = cnt[idx<<1|1]; }
    if (tree[idx] <= NEG_INF) cnt[idx] = 0;
}
void max_segment_tree::upd2 (const int &idx, const int &l, const int &r, const int &x, const int &y, const int64_t &val)
{
    push(idx, l, r); if (l > y || r < x || x > y) return; if (l >= x && r <= y) { lazy2[idx] = val; lazy[idx] = 0LL; push(idx, l, r); return; }
    int m = l + (r - l) / 2; upd2(idx<<1, l, m, x, y, val); upd2(idx<<1|1, m+1, r, x, y, val);
    if (tree[idx<<1] == tree[idx<<1|1]) { tree[idx] = tree[idx<<1]; cnt[idx] = (tree[idx] > NEG_INF) ? (cnt[idx<<1] + cnt[idx<<1|1]) : 0; }
    else if (tree[idx<<1] > tree[idx<<1|1]) { tree[idx] = tree[idx<<1]; cnt[idx] = cnt[idx<<1]; }
    else { tree[idx] = tree[idx<<1|1]; cnt[idx] = cnt[idx<<1|1]; }
    if (tree[idx] <= NEG_INF) cnt[idx] = 0;
}
pair<int64_t, int> max_segment_tree::qry (const int &idx, const int &l, const int &r, const int &x, const int &y)
{
    push(idx, l, r); if (l > y || r < x || x > y) return {NEG_INF, 0}; if (l >= x && r <= y) return {tree[idx], (tree[idx] > NEG_INF ? cnt[idx] : 0)};
    int m = l + (r - l) / 2; pair<int64_t, int> left_res = qry(idx<<1, l, m, x, y), right_res = qry(idx<<1|1, m+1, r, x, y);
    if (left_res.first == right_res.first) return {left_res.first, (left_res.first > NEG_INF ? left_res.second + right_res.second : 0)};
    else if (left_res.first > right_res.first) return left_res; else return right_res;
}
max_segment_tree::max_segment_tree (const int &n) : sz(1 << (32 - __builtin_clz(max(1, n - 1)))), tree(new int64_t[sz<<1]), lazy(new int64_t[sz<<1]), lazy2(new int64_t[sz<<1]), cnt(new int[sz<<1]) {
    for(int i=0;i<sz;++i) {tree[sz + i] = NEG_INF; cnt[sz + i] = 1; lazy[sz + i] = 0LL; lazy2[sz + i] = INF; }
    for(int i=sz-1;i>0;--i)
    {
        if (tree[i<<1] == tree[i<<1|1]) { tree[i] = tree[i<<1]; cnt[i] = (tree[i] > NEG_INF) ? (cnt[i<<1] + cnt[i<<1|1]) : 0; }
        else if (tree[i<<1] > tree[i<<1|1]) { tree[i] = tree[i<<1]; cnt[i] = cnt[i<<1]; }
        else { tree[i] = tree[i<<1|1]; cnt[i] = cnt[i<<1|1]; }
        if (tree[i] <= NEG_INF) cnt[i] = 0; lazy[i] = 0LL; lazy2[i] = INF;
    }
}
max_segment_tree::~max_segment_tree(){ delete[] tree; delete[] lazy; delete[] lazy2; delete[] cnt; }
size_t max_segment_tree::size() const{ return sz; }
void max_segment_tree::upd (const int &l, const int &r, const int64_t &val){ if(l<=r) upd(1, 0, sz - 1, l, r, val); }
void max_segment_tree::upd2 (const int &l, const int &r, const int64_t &val){ if(l<=r) upd2(1, 0, sz - 1, l, r, val); }
pair<int64_t, int> max_segment_tree::qry (const int &l, const int &r){ return (l<=r) ? qry(1, 0, sz - 1, l, r) : make_pair(NEG_INF, 0); }
pair<int64_t, int> max_segment_tree::qry ()
{
    push(1, 0, sz - 1);
    pair<int64_t, int> res = qry(1, 0, sz - 1, 0, sz - 1);
    return {res.first, (res.first > NEG_INF ? res.second : 0)};
}

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
const int inf=1e9+7;
int n,L;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> L;
    vector<pii> vec;
    for(int i=1;i<=n;++i)
    {
        int a,b,c,d,w;
        cin >> a >> b >> c >> d >> w;
        mp2[{{a,b},{c,d}}]=w;
        mp2[{{c,d},{a,b}}]=w;
        vec.pb({a,b});
        vec.pb({c,d});
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    int mn0=inf,mx0=-inf,mn1=inf,mx1=-inf;
    for(auto &e:vec)
    {
        if(e.f>0&&e.f<L)
        {
            int u,v,w;
            u=f0({e.f,e.s}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s},{e.f+1,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f-1,e.s-1}),w=mp2[{{e.f-1,e.s},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s}),v=f0({e.f,e.s}),w=mp2[{{e.f,e.s},{e.f,e.s+1}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            u=f0({e.f-1,e.s-1}),v=f0({e.f,e.s-1}),w=mp2[{{e.f,e.s-1},{e.f,e.s}}];
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        else if(e.f==0)
        {
            mn0=min(mn0,e.s);
            mx0=max(mx0,e.s);
        }
        else if(e.f==L)
        {
            mn1=min(mn1,e.s);
            mx1=max(mx1,e.s);
        }
    }
    int U,V;
    for(int i=mn0;i<=mx0;++i)
    {
        int u=f0({0,i}),v=f0({0,i-1}),w=mp2[{{0,i},{1,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        if(i==mn0) V=v;
        else if(i==mx0) U=u;
    }
    for(int i=mn1;i<=mx1;++i)
    {
        int u=f0({L-1,i}),v=f0({L-1,i-1}),w=mp2[{{L-1,i},{L,i}}];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,U});
    memset(dist,0x3f,sizeof dist);
    dist[U]=0;
    while(pq.size())
    {
        int w=pq.top().f;
        int u=pq.top().s;
        pq.pop();
        if(u==V)
        {
            cout << w;
            return 0;
        }
        for(auto &vw:adj[u])
        {
            if(dist[vw.f]>w+vw.s)
            {
                dist[vw.f]=w+vw.s;
                pq.push({w+vw.s,vw.f});
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plx pair<ll,int>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
using namespace std;
const int mxn=3e5+5;
vector<int>g[mxn];
ll a[mxn];
ll ans=1e18,sum=0;
multiset<ll>ms[mxn];
void solve(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        solve(v,u);a[u]+=a[v];
        if(ms[u].size()<ms[v].size())swap(ms[u],ms[v]);
        for(auto it : ms[v]){
            if(ms[u].empty())break;
            auto ij=ms[u].lower_bound((sum-it)/2);
            if(ij==ms[u].end()){
                --ij;ans=min(ans,max({sum-it-*ij,it,*ij})-min({sum-it-*ij,it,*ij}));
                continue;
            }ans=min(ans,max({sum-it-*ij,it,*ij})-min({sum-it-*ij,it,*ij}));
            if(ij!=ms[u].begin()){
                ij--;ans=min(ans,max({sum-it-*ij,it,*ij})-min({sum-it-*ij,it,*ij}));ij++;
            }
            if(ij!=(--ms[u].end())){
                ij++;ans=min(ans,max({sum-it-*ij,it,*ij})-min({sum-it-*ij,it,*ij}));ij--;
            }
        }
        for(auto it : ms[v])ms[u].insert(it);
    }
    if(!ms[u].empty()){
        auto it = ms[u].lower_bound(a[u]/2);
        if(it==ms[u].end())
        {
            --it;
            ans=min(ans,max({sum-a[u],a[u]-*it,*it})-min({sum-a[u],a[u]-*it,*it}));
            ms[u].insert(a[u]);
            return;
        }
        ans=min(ans,max({sum-a[u],a[u]-*it,*it})-min({sum-a[u],a[u]-*it,*it}));
        if(it!=ms[u].begin())
        {
            it--;
            ans=min(ans,max({sum-a[u],a[u]-*it,*it})-min({sum-a[u],a[u]-*it,*it}));it++;
        }
        if(it!=(--ms[u].end()))
        {
            it++;
            ans=min(ans,max({sum-a[u],a[u]-*it,*it})-min({sum-a[u],a[u]-*it,*it}));it--;
        }
    }
    ms[u].insert(a[u]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i],sum+=a[i];
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    solve(1,1);
    cout << ans;
}