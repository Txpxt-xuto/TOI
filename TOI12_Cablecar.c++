/*
TASK: cablecar.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int p[2525];
struct A{
    int u,v,w;
    bool operator < (const A&o)const
    {
        return w<o.w; 
    }
};
priority_queue<A> pq;
int fr(int i)
{
    if(p[i]==i) return i;
    return p[i]=fr(p[i]);
}
signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,i;
    cin >> n >> m;
    for(i=1;i<=n;i++) p[i] = i;
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        pq.push({u,v,w-1});
    }
    int mn,st,en,pp;
    cin >> st >> en >> pp;
    while(!pq.empty())
    {
        auto x=pq.top();
        pq.pop();
        int u=x.u,v=x.v,w=x.w;
        mn = w;
        int pa=fr(u),pb=fr(v);
        if(pa!=pb) p[pb] = pa;
        if(fr(st)==fr(en)) break;
    }
    cout << pp/mn+(pp%(mn)!=0);
}