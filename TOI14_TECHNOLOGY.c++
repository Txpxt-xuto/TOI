/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int maxsz = 500005;
int tin[maxsz];
int low[maxsz];
int tim=0;
vector<int> edges[maxsz];
int bridges=0;
int n,m,u,v;
void dfs(int node, int par)
{
	tin[node]=tim;
	low[node]=tim;
	tim++;
	for(auto to:edges[node])
	{
		if(to==par) continue;
		if(tin[to]==-1) //havent explored yet
		{
			dfs(to,node);
			low[node]=min(low[node],low[to]);
		}
		else low[node]=min(low[node],tin[to]);
		{
			low[node]=min(low[node],tin[to]);
		}
	}
	if(low[node]==tin[node]) bridges++;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	memset(tin,-1,sizeof(tin));
	for(i=0;i<m;i++)
	{
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		if(tin[i]!=-1) continue;
		dfs(i,i);
	}
	cout << bridges;
}