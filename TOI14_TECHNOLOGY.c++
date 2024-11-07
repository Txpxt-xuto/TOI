/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) x.begin(), x.end()
map<int, vector<int> > wallx, wally;
map<pair<int, int>, int> vis;
queue<pair<int, pair<int, int> > > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, w;
    cin >> n >> m >> w;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    for(i=0;i<w;i++)
    {
        int x, y;
        cin >> x >> y;
        wallx[x].push_back(y);
        wally[y].push_back(x);
    }
    q.push({0, {ex, ey}});
    int ans = -1;
    while (!q.empty()) 
    {
        auto t = q.front();
        q.pop();
        if (vis[t.y]) continue;
        vis[t.y] = 1;
        if(t.y == make_pair(sx, sy))
        {
            ans = t.x;
            break;
        }

    }
}