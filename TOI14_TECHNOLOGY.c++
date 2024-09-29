/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
//we node
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
vector<vector<pair<int,int>>> p(100001);
int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int n,m,x,y,z;
    cin>>n>>m>>x>>y>>z;
    int disx[n+1],disy[n+1];
    bool vis[n]={};
    for(int i=0;i<n;i++){
        disx[i]=2e9;
        disy[i]=2e9;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>> u >>v>>w;
        p[u].push_back({w,v});
        p[v].push_back({w,u});
    }
    q.push({0,x});
    disx[x] = 0;
    while(!q.empty())
    {
        int we = q.top().first,node = q.top().second;
        q.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto i:p[node])
        {
            if(we+i.first<disx[i.second])
            {
                disx[i.second] = we+i.first;
                q.push({disx[i.second],i.second});
            }
        }
    }
    q.push({0,y});
    disy[y] = 0;
    memset(vis,false,sizeof(vis));
    while(!q.empty())
    {
        int node = q.top().second,we = q.top().first;
        q.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto i:p[node])
        {
            if(disy[i.second]>we+i.first)
            {
                disy[i.second] = we+i.first;
                q.push({disy[i.second],i.second});
            }
        }
    }
    if(disx[y]<=z)
    {
        cout << y << " " << disx[y] << " " << 0;
        return 0;
    }
    int node,dist=2e9,rub=2e9;
    for(i=0;i<n;i++)
    {
        if(disx[i]<=z&&disy[i]<rub)
        {
            rub = disy[i];
            dist = disx[i];
            node = i;
        }
    }
    cout << node << " " << dist << " " << rub;
    return 0;
}