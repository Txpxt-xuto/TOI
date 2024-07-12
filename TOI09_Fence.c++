/*
TASK: fence.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N][N],b[N][N];
int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int t=2,i,j,k,n,m;
	while(t--)
	{
		cin >> n >> m >> k;
		for(i=1;i<=k;i++)
		{
			int x,y;
			cin >> x >> y;
			x++,y++;
			a[x][y]=-1;
			b[x][y]=-1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]==-1) a[i][j]=0;
				else a[i][j]=a[i-1][j]+1;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(b[i][j]==-1) b[i][j]=0;
				else b[i][j]=b[i][j-1]+1;
			}
		}
		int mx=0,ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]==0 || b[i][j]==0) continue;
				mx=min({a[i][j],b[i][j]});
				for(k=mx;k>ans;k--)
				{
					if(a[i][j-k+1]>=k && b[i-k+1][j]>=k)
					{
						ans=max(ans,k);
						break;
					}
				}
			}
		}		
		cout << ans << "\n";
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
	}
}