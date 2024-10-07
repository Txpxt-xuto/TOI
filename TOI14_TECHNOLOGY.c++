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
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
int cost[110];

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int s,d,f;
    for(int i=1;i<=n;i++){
        cin>> cost[i];
    }
    cin >> s >>d >>f;
    priority_queue<A> pq;
    pq.push({s,0,0,0});
    memset(dist,0x3f,sizeof dist);
    dist[s][0][0]=0;
    int m;
    cin >> m;
    while(m--){
        int a,b,w;
        cin >> a >> b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    while(!pq.empty())
	{
        int u = pq.top().u;
        int cf = pq.top().f;
        int w = pq.top().w,free = pq.top().free;
        int free = pq.top().free;
        pq.pop();
        if(dist[u][free][cf]<w)continue;
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