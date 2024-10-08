/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dist[110][2][101];
vector<pair<int,int>> adj[110];
struct A
{
    int u,f,w,free;
    bool operator<(const A&o)const
	{
        return w > o.w;
    }
};
int cost[110];
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,i;
    cin >> n;
    int s,d,f;
    for(i=1;i<=n;i++) cin >> cost[i];
    cin >> s >> d >> f;
    priority_queue<A> pq;
    pq.push({s,0,0,0});
    memset(dist,0x3f,sizeof dist);
    dist[s][0][0] = 0;
    int m;
    cin >> m;
    while(m--)
	{
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    while(!pq.empty())
	{
        int w = pq.top().w,cf = pq.top().f,free = pq.top().free,cf = pq.top().f;
        pq.pop();
        if(dist[u][free][cf] < w) continue;
        if(free == 0 && dist[u][1][f] > w)
		{
            dist[u][1][f] = w;
            pq.push({u,f,w,1});
        }
        if(cf < f && dist[u][free][cf+1] > w + cost[u])
		{
            dist[u][free][cf+1] = w + cost[u];
            pq.push({u,cf+1,w+cost[u],free});
        }
        for(auto i:adj[u])
		{
            if(i.second <= cf && dist[i.first][free][cf-i.second] > w)
			{
                dist[i.first][free][cf-i.second] = w;
                pq.push({i.first,cf-i.second,w,free});
            }
        }
    }
    cout << dist[d][1][f];
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
const int MOD=1e9+7;
struct A{
    int u,cost,fuel,ticket;
    bool operator < (const A& o)const
	{
        return cost>o.cost;
    }
};
int pc[110],dist[2][110][110];
vector<pair<int,int>>adj[110];
priority_queue<A>pq;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,i,m,st,ed,mxfuel;
    cin >> n;
    for(i=1;i<=n;i++) cin >> pc[i];
    cin >> st >> ed >> mxfuel >> m;
    for(i=1;i<=m;i++)
	{
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    memset(dist,0x3f,sizeof dist);
    dist[0][0][st] = 0;
    pq.push({st,0,0,0});
    while(!pq.empty())
	{
        int tick=pq.top().ticket,fuel=pq.top().fuel,cost=pq.top().cost,u=pq.top().u;
        pq.pop();
        if(tick==0&&cost<dist[1][mxfuel][u])
		{
            dist[1][mxfuel][u] = cost;
            pq.push({u,cost,mxfuel,1});
        }
        if(fuel<mxfuel&&cost+pc[u]<dist[tick][fuel+1][u])
		{
            dist[tick][fuel+1][u] = cost + pc[u];
            pq.push({u,cost+pc[u],fuel+1,tick});
        }
        for(auto e:adj[u])
		{
            if(fuel<e.s) continue;
            if(cost<dist[tick][fuel-e.s][e.f])
			{
                dist[tick][fuel-e.s][e.f] = cost;
                pq.push({e.f,cost,fuel-e.s,tick});
            }
        }
    }
    cout << dist[1][mxfuel][ed];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int const X=15001;
struct fenwick
{
    int a[X][X];
    void upd(int st,int en)
    {
        for(i=st;i<X;i+=i&-i) for(j=en;j>0;j-=j&-j) a[i][j]++;
    }
    int qr(int st,int en)
    {
        int i,j,ret=0;
        for(i=st;i>0;i-=i&-i) for(j=en;j<X;j+=j&-j) ret+=a[i][j];
        return ret;
    }
}tree;
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        int p1 = a - b + 5000,p2 = a + b + 5000;
        cout << tree.qr(p1,p2) << "\n";
        tree.upd(p1,p2);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct fenwick{
    int info[15004][15004]{0};
    void upd(int x,int y){
        for(int i=x;i<=15000;i+=i&-i){
            for(int j=y;j<=15000;j+=j&-j){
                info[i][j]++;
            }
        }
    }
    int fsum(int x,int y){
        int sum=0;
        for(int i=x;i>0;i-=i&-i){
            for(int j=y;j>0;j-=j&-j){
                sum+=info[i][j];
            }
        }
        return sum;
    }
}fw;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    cin >> n;
    for(i=0;i<n;i++)
    {
        int p,h;
        cin>>p >> h;
        int l=p-h;
        int r=p+h;
        cout<<fw.fsum(l+5000,15000)-fw.fsum(l+5000,r+5000-1)<<"\n";
        fw.upd(l+5000,r+5000);
    }
}