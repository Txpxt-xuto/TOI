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
        //if(id!=o.id)
        return id>o.id;
        //return i>o.i;
    }
};
int main()
{
    int n,k,t;
    cin>>n>>k>>t;
    bool vis[n+1];
    memset(vis,0,sizeof vis);
    priority_queue<info> q;
    vector<int> v[n+1];
    int d[k+1];
    memset(d,0,sizeof d);
    int dd[n+1];
    for(int i=1;i<=n;i++)
    {
        int id;
        cin>>id;
        int m;
        cin>>m;
        while(m--)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
        q.push({id,i});
        dd[i]=id;
        d[id]++;
    }
    set<int> ss;
    while((t--)&&!q.empty())
    {
        auto p=q.top();
        q.pop();
        ss.insert(p.i);
        //cout<<p.i<<" "<<t<<endl;
        if(vis[p.i])
        {
            t++;
            continue;
        }
        if(v[p.i].empty())
        {
            //cout<<p.i<<" ";
            d[dd[p.i]]--;
            vis[p.i]=1;
            ss.erase(p.i);
            continue;
        }
        int cnt=0;
        for(auto x:v[p.i])
        {
            if(!vis[x])
            {
                q.push({p.id-10,x});
                cnt++;
                if(ss.count(x)!=0)
                {
                    t=0;
                    break;
                }
            }
        }
        if(!t)
        break;
        if(cnt==0)
        {
            d[dd[p.i]]--;
            vis[p.i]=1;
            ss.erase(p.i);
            continue;
        }
        v[p.i].clear();
        q.push({p.id,p.i});
        t++;
        //ss.insert(p.i);
    }
    if(d[1]>0)
    {
        cout<<-1;
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