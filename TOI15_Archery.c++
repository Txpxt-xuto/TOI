/*
TASK: archery.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,ans,pos,mx=LLONG_MAX,base=0;
	cin>>n;
	pll a[n];
	ll ps[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].second;
		mx=min(mx,a[i].second);
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first;
		base=base+a[i].first;
	}
	sort(a,a+n);
	ps[0]=a[0].second;
	for(int i=1;i<n;i++)
	{
		ps[i]=ps[i-1]+a[i].second;
	}
	ans=base-a[0].first*n;
	pos=a[0].first;
	for(int i=1;i<n;i++)
	{
		if(a[i].first>mx)
		{
			break;
		}
		ll tmp=ps[i-1]+base-n*a[i].first;
		if(ans>tmp)
		{
			ans=tmp;
			pos=a[i].first;
		}
	}
	cout<<pos<<" "<<ans;
	return 0;
}