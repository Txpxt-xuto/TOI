#include<bits/stdc++.h>
using namespace std;
#define iii tuple<int,int,int>
#define pii pair<int,int>
const int N = 2e4+5;
const int M = 2e5+5;
const int INF = 1e9+7;
vector<iii> g[N];
int n,m,k,p,cnt = 1;
int dist[N],gecko[N],to[N];
iii edge[M];
bool vis[M];
set<pii> ss;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> m >> k >> p;
    p++;
    for(int i=1;i<=k;++i)
    {
        cin >> gecko[i];
        gecko[i]++;
    }
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u++; v++;
        g[u].emplace_back(v,w,i);
        g[v].emplace_back(u,w,i);
        edge[i] = {u,v,i};
        vis[i] = false;
    }
    fill(dist,dist+n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[p] = 0;
    pq.push({dist[p],p});
    while(!pq.empty())
    {
        auto [dis,u] = pq.top();
        pq.pop();
        for(auto [v,w,num] : g[u])
        {
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
                to[v] = u;
            }
        }
    }
