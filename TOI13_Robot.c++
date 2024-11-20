/*
TASK: robot.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
string path[2002];
int dist[2002][2002];
queue<pair<int, int> > gq;
pair<int, int> front;
int n,m,x,y,i,j;
int main()
{
    int sum = 0,cnt = 0;
    cin >> m >> n;
    for(i=1;i<=m;++i)
    {
            cin >> path[i];
            path[i] = '@' + path[i];
    }
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(path[i][j] == 'X')
            {
                dist[i][j] = 0;
                gq.push({i, j});
            }
            else dist[i][j] = 9999;
        }
    }
    while(!gq.empty())
    {
        front = gq.front();
        x = front.first;
        y = front.second;
        gq.pop();
        if(x >= 2 && path[x-1][y] != 'W' && dist[x-1][y] == 9999)
        {
            gq.push({x-1, y});
            dist[x-1][y] = min(dist[x][y] +1, dist[x-1][y]);
        }
        if(x <= m-1 && path[x+1][y] != 'W' && dist[x+1][y] == 9999)
        {
            gq.push({x+1, y});
            dist[x+1][y] = min(dist[x][y] +1, dist[x+1][y]);
        }
        if(y >= 2 && path[x][y-1] != 'W' && dist[x][y-1] == 9999)
        {
            gq.push({x, y-1});
            dist[x][y-1] = min(dist[x][y] +1, dist[x][y-1]);
        }
        if(y <= n-1 && path[x][y+1] != 'W' && dist[x][y+1] == 9999)
        {
            gq.push({x, y+1});
            dist[x][y+1] = min(dist[x][y] +1, dist[x][y+1]);
        }
    }
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(path[i][j] == 'A' && dist[i][j] != 9999) 
            {
                sum += dist[i][j];
                cnt += 1;
            }
        }
    }
    cout << cnt << " " << sum*2;
}