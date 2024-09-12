/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int n,k,t,tt;
int l[100001],p[100001],r[10001];
vector<vector<pair<int,int> > > v(100001);
vector<bool> vis(100001);
vector<int> ans;
void dfs(int x)
{
    int i;
	vis[x]=true;
	ans.push_back(x);
	for(i=0;i<v[x].size();i++)
	{
		p[v[x][i].second]--;
		if(p[v[x][i].second]==0) dfs(v[x][i].second);
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
}