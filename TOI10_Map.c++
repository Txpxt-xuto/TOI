/*
TASK: map.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ #include <bits/stdc++.h>

using namespace std;

int main(void)
{
	queue<pair<int,pair<int,int> > > q;
	int m,n,idx,tx,ty;
	cin>>m>>n;
	int ans[m+1][n+1];
	vector<pair<int,int> > adj(m*n+20);
	vector<bool> vis(m*n+20,false);
	for(int i=0;i<m*n-1;i++)
	{
		int a,b;
		char c;
		cin>>a>>c>>b;
		if(c=='U')
		{
			q.push({1,{a,b}});
		}
		else
		{
			q.push({2,{a,b}});
		}
	}
	vis[0]=true;
	adj[0]={0,0};
	while(!q.empty())
	{
		int c=q.front().first;
		int a=q.front().second.first;
		int b=q.front().second.second;
		q.pop();
		if(vis[a] && vis[b])
		{
			continue;
		}
		else if(vis[a])
		{
			vis[b]=true;
			if(c==1)
			{
				adj[b]={adj[a].first+1,adj[a].second};
			}
			else
			{
				adj[b]={adj[a].first,adj[a].second+1};
			}
		}
		else if(vis[b])
		{
			vis[a]=true;
			if(c==1)
			{
				adj[a]={adj[b].first-1,adj[b].second};
			}
			else
			{
				adj[a]={adj[b].first,adj[b].second-1};
			}
		}
		else
		{
			q.push({c,{a,b}});
		}
	}
	idx=0;
	for(int i=1;i<m*n;i++)
	{
		if(adj[i].first<adj[idx].first)
		{
			idx=i;
		}
		else if(adj[i].first==adj[idx].first && adj[i].second<adj[idx].second)
		{
			idx=i;
		}
	}
	tx=adj[idx].first;
	ty=adj[idx].second;
	for(int i=0;i<m*n;i++)
	{
		//cout<<adj[i].first<<" "<<adj[i].second<<"\n";
		//cout<<adj[i].first-tx<<" "<<adj[i].second-ty<<"\n";
		ans[adj[i].first-tx][adj[i].second-ty]=i;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}