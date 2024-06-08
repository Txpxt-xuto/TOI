/*
TASK: maze.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
vector<vector<int>> dist1(159, vector<int>(159, INF)), dist2(159, vector<int>(159, INF));
queue<pair<int,int>> q;
int i, j, n, m, sy, sx, ey, ex, v[159][159], dy[]={0,-1,0,1}, dx[]={-1,0,1,0};
void bfs(int sy, int sx, vector<vector<int>> &dist) 
{
	q.push({sy, sx});
	while(!q.empty()) 
    {
		auto [y, x]=q.front(); q.pop();
		for(i=0;i<4;i++) 
        {
			int yy=y+dy[i], xx=x+dx[i];
			if(yy<1 || yy>m || xx<1 || x>n) continue;
			if(!v[yy][xx]) 
            {
				dist[yy][xx] = min(dist[yy][xx], dist[y][x]);
				continue;	
			}
			if(dist[y][x]+1<dist[yy][xx]) 
            {
				dist[yy][xx] = dist[y][x]+1;
				q.push({yy, xx});
			}
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	cin >> m >> n >> sy >> sx >> ey >> ex;	
	for(i=1;i<=m;i++) 
    {
		for(j=1;j<=n;j++) cin >> v[i][j];
	}
	dist1[sy][sx] = dist2[ey][ex] = 1;
	bfs(sy, sx, dist1);
	bfs(ey, ex, dist2);
	int cnt=0, ans=INF;
	for(i=1;i<=m;i++)
    {
		for(j=1;j<=n;j++) 
        {
			if(dist1[i][j]==INF || dist2[i][j]==INF) continue;
			cnt++;
			ans = min(ans, dist1[i][j]+dist2[i][j]);
		}
	}
	cout << cnt << "\n" << ans+1;
	return 0;
}