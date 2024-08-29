/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>

using namespace std;

int n,k,t,tt,c;
int l[100001],p[100001];
vector<vector<int> > v(100001);
vector<vector<int> > r(10001);
vector<int> vis(100001);
vector<int> ans;

int dfs(int x)
{
	if(c==-1)
	{
		c=-1;
		return -1;
	}
	if(vis[x]==1)
	{
		c=-1;
		return -1;
	}
	if(vis[x]==2)
	{
		return 0;
	}
	int sum=0;
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		sum=sum+dfs(v[x][i]);
		if(c==-1)
		{
			c=-1;
			return -1;
		}
	}
	vis[x]=2;
	return 1+sum;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>p[i];
		r[l[i]].push_back(i);
		for(int j=0;j<p[i];j++)
		{
			cin>>tt;
			v[i].push_back(tt);
		}
	}
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<r[i].size();j++)
		{
			cnt=cnt+dfs(r[i][j]);
		}
		if(c==-1)
		{
			cout<<-1;
			return 0;
		}
		if(cnt>t)
		{
			if(i==1)
			{
				cout<<-1;
				return 0;
			}
			else
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	cout<<k;
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

