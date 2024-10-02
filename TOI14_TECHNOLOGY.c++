/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ii;

/*
Construct graph : u->v means need to build v before u.
                  DFS from u in x level to all node that need to be build first.
                  If found cycle -> can't build u. -> can't build level x;
*/
ii n,k,t;
vector<ii> adjL[(int)2e5+1];
vector<ii> lvl[(int)1e4+1];

int visited[(int)2e5+1]={0};

bool dfs(int x){
    if(visited[x]==1)return 0;
    if(visited[x]==2)return 1;
    t--;
    visited[x] = 1;
    bool cango = 1;
    for(int v:adjL[x]){
        cango&=dfs(v);
    }
    visited[x]=2;
    return cango&&(t>=0);
}

int main(){
    cin>>n>>k>>t;
    for(int i=1;i<=n;i++){
        int g;cin>>g;lvl[g].push_back(i);
        int c;cin>>c;
        while(c--){
            int u;cin>>u;
            adjL[i].push_back(u);
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int j:lvl[i])
        {
            if(!dfs(j))
            {
                if(i-1==0)cout<<-1;
                else cout<<i-1;
                return 0;
            }
        }
    }
    cout<<k;
    return 0;

    return 0;
}