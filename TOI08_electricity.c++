/*
TASK: electricity.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n),v(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    for(int i=0;i<n;i++)cin >> a[i];
    pq.push({a[0],0});
    while(v[n-1]==INT_MAX)
    {
        int cost=pq.top().first,pos=pq.top().second;
        pq.pop();
        v[pos]=cost;
        for(int i=1;i<=m;i++)if(pos+i<n&&cost+a[pos+i]<v[pos+i])pq.push({cost+a[pos+i],pos+i});
    }
    cout << v[n-1];
    return 0;
}
