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
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,a;
    int p2,p1,p0;
    int q;
    cin >> q;
    while(q--){
    cin >> n >> a;
    p2=0;
    p1=1;
    p0=a;
    for(int i=1;i<=n;i++){
        p2=(p1*p1)%MOD + ((2*a)%MOD)*p2;
        p2%=MOD;
        p1=((2*a)%MOD*p1)%MOD;
    }
    cout << p2 <<"\n";
    }
}