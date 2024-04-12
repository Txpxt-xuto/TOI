/*
TASK: cannon.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,k,l,x;
    cin >> n >> m >> k >> l;
    vector<int> cannon(n);
    for(int &x:cannon) cin >> x;
    while(k--)
    {
        int itr=0,cnt=0;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            while(itr<n&&cannon[itr]<x-l)itr++;
            while(itr<n&&cannon[itr]<=x+l)cnt++,itr++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    vector<vector<int>> dist(n+2,vector<int>(n+2,-6));
    vector<vector<int>> vis(n+2,vector<int>(n+2,0));
    queue<pair<pair<int,int>,int>> q;
    int row[]={0,-1,0,1},collumn[]={-1,0,1,0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int z;
            cin>>z;
            if(z!=100)dist[i][j]=z;
        }
    }
    int maximum=dist[y][x];
    q.push({{y,x},dist[y][x]});
    while(!q.empty())
    {
        int cy=q.front().f.f;
        int cx=q.front().f.s;
        int cattempt=q.front().s;
        q.pop();
        for(int i=0;i<=3;i++)
        {
            int ny=cy+row[i];
            int nx=cx+collumn[i];
            if(cattempt<dist[ny][nx] & !(vis[ny][nx]))
            {
                vis[ny][nx]=1;
                maximum=max(dist[ny][nx],maximum);
                q.push({{ny,nx},dist[ny][nx]});
            }
        }
    }
    cout<<maximum;
    return 0;
}