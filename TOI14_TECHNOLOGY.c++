/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100005],lv[100005];
int vis[100005],cur;

bool dfs(int u,int p){
    vis[u]=1;
    for(auto &v:adj[u]){
        if(vis[v]==2)continue;
        if(vis[v]==1 || !dfs(v,u))return 0;
    }
    vis[u]=2;
    ++cur;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,k,t;cin>>n>>k>>t;
    for(int i=1;i<=n;i++){
        int x,m;cin>>x>>m;
        lv[x].push_back({i});
        for(int j=0;j<m;j++){
            int u;cin>>u;
            adj[i].push_back({u});
        }
    }
    for(i=1;i<=k;i++)
    {
        for(auto e:lv[i])
        {
            if(vis[e] ==2 || dfs(e,e) && cur<=t) continue;
            if(i==1) cout << -1;
            else cout << i-1;
            return 0;
        }
    }
    cout << k << "\n";
}
