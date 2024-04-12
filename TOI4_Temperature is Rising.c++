#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main()
{
    int n,x,y,z,i,j;
    cin >> n >> x >> y;
    vector<vector<int>> dist(n+2,vector<int>(n+2,-6));
    vector<vector<int>> vis(n+2,vector<int>(n+2,0));
    queue<pair<pair<int,int>,int>> q;
    int row[]={0,-1,0,1},collumn[]={-1,0,1,0};
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> z;
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
        for(i=0;i<=3;i++)
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
    cout << maximum;
    return 0;
}