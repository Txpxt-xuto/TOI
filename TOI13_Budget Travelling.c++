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
    cin>>n>>m;
    cin>>x>>y>>z;
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
    
}

