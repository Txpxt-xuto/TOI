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
	cin.tie(NULL);
    int i,j;
	cin >> n >> k >> t;
	for(i=1;i<=n;i++)
	{
		cin>>l[i]>>p[i];
		r[l[i]]++;
		for(j=0;j<p[i];j++)
		{
			cin>>tt;
			v[tt].push_back({l[i],i});
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0 && !vis[i])
		{
			dfs(i);
		}
	}
	for(int i=0;i<n && i<t;i++)
	{
		r[l[ans[i]]]--;
	}
	if(r[1]>0)
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<k;i++)
	{
		if(r[i]>0)
		{
			cout<<i-1;
			break;
		}
	}
	return 0;
}
/*
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1

7 4 7
3 1 2
1 0
4 2 7 1
1 1 5
2 1 2
3 1 4
4 1 6

3 2 3
1 2 2 3
2 2 1 3
2 2 1 2