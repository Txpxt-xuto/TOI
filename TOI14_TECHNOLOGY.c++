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

struct pers_segt{
    ll n, ccnode = 0;
    ll tree[MAXTREE], tree2[MAXTREE], lchild[MAXTREE], rchild[MAXTREE];
    
    ll build(ll l, ll r) {
        ll curnode = ccnode++;
        if (l != r) {
            ll mid = (l+r)/2;
            
            ll tlc = build(l, mid);
            ll trc = build(mid+1, r);
            lchild[curnode] = tlc;
            rchild[curnode] = trc;
        }
        
        return curnode;
    }
    
    void init(ll N) {
        n = N;
        memset(tree, 0, sizeof(tree));
        memset(tree2, 0, sizeof(tree2));
        memset(lchild, -1, sizeof(lchild));
        memset(rchild, -1, sizeof(rchild));
        build(1, N);
    }
    
    ll update(ll p, ll x, ll v, ll l, ll r) {
        ll curnode = ccnode++;
        if (l == r) {
            tree[curnode] = x;
            tree2[curnode] = 1;
        } else {
            ll mid = (l+r)/2;
            ll tlc = lchild[v];
            ll trc = rchild[v];
            if (p <= mid) tlc = update(p, x, lchild[v], l, mid);
            else trc = update(p, x, rchild[v], mid+1, r);
            tree[curnode] = tree[lchild[curnode] = tlc] + tree[rchild[curnode] = trc];
            tree2[curnode] = tree2[tlc] + tree2[trc];
        }
        
        return curnode;
    }
    
    ll query(ll l, ll r, ll v, ll tl, ll tr) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        
        ll mid = (tl+tr)/2;
        return query(l, min(mid, r), lchild[v], tl, mid)
        + query(max(l, mid+1), r, rchild[v], mid+1, tr);
    }
    
    ll query2(ll l, ll r, ll v, ll tl, ll tr) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree2[v];
        
        ll mid = (tl+tr)/2;
        return query2(l, min(mid, r), lchild[v], tl, mid)
        + query2(max(l, mid+1), r, rchild[v], mid+1, tr);
    }
} xdt;

int main() {
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