/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
/*
TASK: SCHOOL
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
bool kunzaZa183(int v) {
    if (vis[v]) return false;
    vis[v] = 1;
    for (auto& x : adj[v]) {
        if (mt[x] == -1 || kunzaZa183(mt[x])) {
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
        kunzaZa183(i);
    }
    int cnt = 0;
    for(int i=1;i<=2*n;i++) if(mt[i] != -1) cnt++;
    cout << n + m - 2 * cnt;
    return 0;
}