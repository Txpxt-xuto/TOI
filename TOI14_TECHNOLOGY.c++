/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N=8e4+5;
vector<pii>g[N];
int a[N],idx=0;
void dfs(int u,int p){
    for(auto v:g[u]){
        if(v.f==p)continue;
        dfs(v.f,u);
        a[idx++]=v.s;
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int u,v,w;cin>>u>>v>>w;g[u].pb({v,w});g[v].pb({u,w});
    }int st;
    for(int i=0;i<=n;i++){if(g[i].size()==1){st=i;break;}}
    dfs(st,st);
    ll l=0,r=1e16;
    while(l<r){
        ll m=(l+r+1)>>1;
        int cnt=0;ll sum=0;
        for(int i=0;i<idx;i++)
        {
            sum+=a[i];
            if(sum>=m) cnt++,sum=0;
        }
        if(cnt>=3) l=m;
        else r=m-1;
    }cout<<l;
}