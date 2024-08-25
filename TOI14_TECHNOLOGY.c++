/*
TASK: plantation.cpp
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
	//cout<<"helllo";
	vis[x]=true;
	ans.push_back(x);
	for(int i=0;i<v[x].size();i++)
	{
		p[v[x][i].second]--;
		if(p[v[x][i].second]==0)
		{
			dfs(v[x][i].second);
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> t;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i] >> p[i];
		r[l[i]]++;
		for(j=0;j<p[i];j++)
		{
			cin >> tt;
			v[tt].push_back({l[i],i});
		}
	}
	for(int i=1;i<=n;i++) if(p[i]==0 && !vis[i]) dfs(i);
	for(i=0;i<n && i<t;i++) r[l[ans[i]]]--;
	cout << -1;
	return 0;
}