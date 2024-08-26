/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
struct info
{
    int id,i;
    bool operator < (const info&o) const
    {
        return id>o.id;
    }
};
int main()
{
    int n, k, t, i;
    cin >> n >> k >> t;
    bool vis[n+1];
    memset(vis,0,sizeof vis);
    priority_queue<info> q;
    vector<int> v[n+1];
    int d[k+1];
    memset(d,0,sizeof d);
    int dd[n+1];
    for(i=1;i<=n;i++)
    {
        int id, m, x;
        cin >> id;
        cin >> m;
        ush({id,i});
        dd[i] = id;
        d[id]++;
    }
    set<int> ss;
    while((t--)&&!q.empty())
    {
        auto p = q.top();
        q.pop();
        ss.insert(p.i);
        if(!t) break;
       
        v[p.i].clear();
        q.push({p.id,p.i});
        t++;
    }
    if(d[1]>0)
    {
        cout << -1;
        return 0;
    }
    for(i=2;i<=k;i++)
    {
        if(d[i]>0)
        {
            cout << i-1;
            return 0;
        }
    }
    cout << k;
}