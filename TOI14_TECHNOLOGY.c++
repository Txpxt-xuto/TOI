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
}