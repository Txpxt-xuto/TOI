#include <bits/stdc++.h>
using namespace std;

int parent[200001];

int findParent(int u){
    if(parent[u] == u){
        return u; // it is its own parent
    }
    return parent[u] = findParent(parent[u]);
}

int main(){
    int n, m, u, v, w;
    cin >> n >> m; // nodes, edges
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    priority_queue<pair<int, pair<int, int>>> pq; // graph
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        pq.push({w, {u, v}});
    }
    int maxdist = 0;
    while(!pq.empty()){
        w = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            maxdist += w - 1;
            parent[v] = u; // set new parent
        }
    }
    cout << maxdist;
    return 0;
}