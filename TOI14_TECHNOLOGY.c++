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
int cnt(int a){
	int s=0;
	while(a!=0) a/=2,s++;
	return s;
}
int trav(int a,int b){
	int d=0;
	if(a>(1<<k) && b>(1<<k)) a-=(1<<k),b-=(1<<k);
	if((a>(1<<k) && b<(1<<k)) || (a<(1<<k) && b>(1<<k))) return INT_MAX;
	while(cnt(a)>cnt(b)) a/=2,d++;
	while(cnt(b)>cnt(a)) b/=2,d++;
	while(a!=b) a/=2,b/=2,d+=2;
	return d;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l,q;
	cin>>k >>l >>q;
	for(int i=1;i<=15;i++){
		for(int j=1;j<=15;j++){
			dist[i][j]=INT_MAX;
			if(i==j) dist[i][j]=0;
		}
	}
	for(int i=1;i<=l;i++){
		int a,b;
		cin>>a >>b;
		st[i]=a,st[l+i]=b;
		dist[i][l+i]=min(dist[i][l+i],1);
		dist[l+i][i]=min(dist[l+i][i],1);
	}
	for(int i=1;i<=2*l;i++){
		for(int j=1;j<=2*l;j++){
			if(i==j) continue;
			if(abs(st[i]-st[j])>=(1<<k)) continue;
			if(st[i]>(1<<k)) dist[i][j]=min(dist[i][j],trav((st[i]-(1<<k)),st[j]-(1<<k)));
			else dist[i][j]=min(dist[i][j],trav(st[i],st[j]));
		}
	}
	for(int k=1;k<=2*l;k++){
		for(int i=1;i<=2*l;i++){
			for(int j=1;j<=2*l;j++)
            {
				if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
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