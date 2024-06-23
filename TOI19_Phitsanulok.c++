#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
//#define s second

struct A{
    int u,w;
    bool operator < (const A&o)const{
        return w>o.w;
    }
};
vector<pair<int,int>> adj[1<<20];
int dist[1<<20];
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,s;
    cin >> n>> s;
    memset(dist,0x3f,sizeof dist);
    priority_queue<A> pq;
    pq.push({0,0});
    dist[0]=0;
    for(int z= 1;z<=n;z++){
        int a=0;
        int w;
        cin >> w;
        int p=0;
        for(int i = 0;i<s;i++){
            int x;
            cin >>x;
            if(x==-1)p|=1<<i;
            else if(x==1)a|=1<<i;
        }
        adj[p].push_back({a,w});
    }
    int ans = 0;
    while(!pq.empty()){
        int u = pq.top().u;
        int w =pq.top().w;
        pq.pop();
        if(dist[u]<w)continue;
        for(auto e : adj[u]){
        ans = max(ans,w);
            if(dist[e.first]>e.second+w){
                dist[e.first]=w+e.second;
                pq.push({e.first,e.second+w});
            }
        }
        for(int i = 0;i<s;i++){
            if(u&(1<<i) && dist[u^(1<<i)]>w){
                dist[u^(1<<i)]=w;
                pq.push({u^(1<<i),w});
            }
        }
    }
    cout << ans;
    return 0;
} 