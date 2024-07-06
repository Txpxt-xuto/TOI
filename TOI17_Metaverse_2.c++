/*
TASK: metaverse2
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pii pair<int,int>
using namespace std;
const int N=2e4+10;
pii st[N],ed[N];
int dp[20][N];
int dis(pii a,pii b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,p,i,j;
	cin >> n >> m >> k >> p;
	st[0]=ed[0]=make_pair(1,1);
	st[k+1]=ed[k+1]=make_pair(n,m);
	for(i=1;i<=k;i++)
    {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		st[i] = make_pair(a,b);
		ed[i] = make_pair(c,d);
	}
	for(i=0;i<=p;i++)
    {
		for(j=0;j<=k+1;j++) dp[i][j]=INT_MAX;
	}
	for(i=0;i<=k+1;i++) dp[0][i]=dis(ed[0],st[i]);
	for(i=1;i<=p;i++)
    {
		for(j=0;j<=k+1;j++)
        {
			dp[i][j]=dp[i-1][j];
			for(int ii=0;ii<=k+1;ii++) dp[i][j]=min(dp[i][j],dp[i-1][ii]+dis(ed[ii],st[j]));
		}
	}
	int mn=INT_MAX,mntk=INT_MAX;
	for(i=0;i<=p;i++)
    {
		if(dp[i][k+1]<mn)
        {
			mn=dp[i][k+1];
			mntk=i;
		}
	}
	cout << mn << " " << mntk;
}
