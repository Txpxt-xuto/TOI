/*
TASK: budget.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits//stdc++.h>
using namespace std;

vector<pair<int,int>> v[10002];
int n,m,i,a,b,w,dis1[10002],dis2[10002],x,y,z,cost,ver;
priority_queue<pair<int,int>> pq;

int main ()
{
    cin >> n >> m;
    cin >> x >> y >> z;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>w;
        v[a].push_back({w,b});
        v[b].push_back({w,a});
    }
    for(i=0;i<n;i++) dis1[i]=1e9;
    for(i=0;i<n;i++) dis2[i]=1e9;
    dis1[x]=0;
    pq.push({0,x});
    while(!pq.empty())
    {
        cost=-pq.top().first;
        ver=pq.top().second;
        pq.pop();
        for(i=0;i<v[ver].size();i++)
        {
            if(dis1[v[ver][i].second]>dis1[ver]+v[ver][i].first)
            {
                dis1[v[ver][i].second]=dis1[ver]+v[ver][i].first;
                pq.push({-dis1[v[ver][i].second],v[ver][i].second});
            }
        }
    }
    dis2[y]=0;
    pq.push({0,y});
    while(!pq.empty())
    {
        cost=-pq.top().first;
        ver=pq.top().second;
        pq.pop();
        for(i=0;i<v[ver].size();i++)
        {
            if(dis2[v[ver][i].second]>dis2[ver]+v[ver][i].first)
            {
                dis2[v[ver][i].second]=dis2[ver]+v[ver][i].first;
                pq.push({-dis2[v[ver][i].second],v[ver][i].second});
            }
        }
    }
    if(dis1[y]<=z) cout << y << " " << dis1[y] << " 0";
    else
    {
        int ans,ans2,ans3=1e9;
        for(i=0;i<n;i++)
        {
            if(dis1[i]<=z && dis2[i]<ans3)
            {
                ans=i;
                ans2=dis1[i];
                ans3=dis2[i];
            }
        }
        cout << ans << " " << ans2 << " " << ans3;
    }
}

