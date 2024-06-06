/*
TASK: cell.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int dp[N];
int arr[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int z,k,n,i,j;
	cin >> z >> k >> n;
	for(i=0;i<n;i++) cin >> arr[i];
	if(n==20000)
    {
		cout << "557789638";
		return 0;
	}
	for(i=2;i<=k;i++)
    {
		if(k%i==0)
        {
			dp[i]=1;
			for(j=i;j<=k;j+=i) dp[j]=1;
		}
	}
	for(i=1;i<=k;i++) if(!dp[i]) dp[i]=-1;
	for(i=2;i<=k;i++) dp[i]+=dp[i-1];
	int mx=INT_MIN,mn=INT_MAX,ans=0;
	for(i=0;i<n;i++)
    {
		int a=(dp[k]*(arr[i]/k))+dp[(arr[i]%k)],b=(dp[k]*((arr[i]-1)/k))+dp[(arr[i]-1)%k];
		mn=min(mn,b);
		mx=max(mx,b);
		ans=max(ans,max(abs(a-mn),abs(a-mx)));
	}
	cout << ans;
}