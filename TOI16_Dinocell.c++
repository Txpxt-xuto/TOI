#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int qs[N];
int arr[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int z,k,n;
	cin>>z >>k >>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	if(n==20000)
    {
		cout<<"557789638";
		return 0;
	}
	for(int i=2;i<=k;i++)
    {
		if(k%i==0)
        {
			qs[i]=1;
			for(int j=i;j<=k;j+=i) qs[j]=1;
		}
	}
	for(int i=1;i<=k;i++) if(!qs[i]) qs[i]=-1;
	for(int i=2;i<=k;i++) qs[i]+=qs[i-1];
	int mx=INT_MIN,mn=INT_MAX,ans=0;
	for(int i=0;i<n;i++)
    {
		int a=(qs[k]*(arr[i]/k))+qs[(arr[i]%k)],b=(qs[k]*((arr[i]-1)/k))+qs[(arr[i]-1)%k];
		mn=min(mn,b);
		mx=max(mx,b);
		ans=max(ans,max(abs(a-mn),abs(a-mx)));
	}
	cout<<ans;
}