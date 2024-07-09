/*
TASK: cave.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>

#define tu tuple<long long int,int,int>
#define pii pair<long long int,int>
const int N = 2005 ;

using namespace std;

vector<pii> adj[N];
priority_queue<tu,vector<tu>,greater<tu>> q;
pii dist[N];
vector <pii> ans;
bool visited[N];

int main(){
    
    int n,m,s,o,lr,i,j;
    long long int lw;
    lw = LLONG_MAX;
    lr = INT_MAX;
    cin >> n >> s >> o >> m ;

    int a,b,d,c=0 ;
    for(int i=0;i<m;i++){
        cin >> a >> b >> d ;
        adj[a].push_back({d,b});
    }
    int nh;
    cin >> nh ;
    int h[nh];
    for(int i=0;i<nh;i++){
        cin >> h[i] ;
    }
    
    for(int i=0;i<2005;i++){
        dist[i] = {LLONG_MAX,INT_MAX};
    }
    
    q.push({0,s,0});
    long long int u,nw,nr;
    int r,t;
    while(!q.empty()){
        auto [u,t,r] = q.top(); 
        q.pop();

        if(t==o)
        {
            if(u<lw||r<lr)
            {
                ans.push_back({u,r});
                lw = u,lr = r;
            }
            continue;
        }
        if(dist[t].first<u&&dist[t].second<r) continue;
        for(i=0;i<adj[t].size();i++)
        {
            int w = adj[t][i].first,v = adj[t][i].second;
            nw = dist[v].first , nr = dist[v].second ;
                if(u+w<nw||r+1<nr)
                {
                    q.push({u+w,v,r+1});
                    dist[v] = {u+w,r+1};
                }
        }
    }
    long long int tr;
    for(i=0;i<nh;i++)
    {
        tr = LLONG_MAX;
        for(j=0;j<ans.size();j++) tr = min(tr,ans[j].first+(ans[j].second-1)*h[i]);
        cout << tr << " " ;
    }

}
