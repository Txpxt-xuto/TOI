#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pii pair<ll,ll>
#define pipi pair<pii,pii>
const int N = 2e5;
ll dpl[N+5], dpr[N+5], a[N+5], l[N+5], r[N+5];
int n, q, i, j, x;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	int lis = 0;
	for(i=1;i<=n;i++)
    {
		int dp = lower_bound(dpl,dpl+lis,a[i])-dpl;
		if(dp == lis) lis++;
		dpl[dp] = a[i];
		l[i] = dp;
	}
	lis = 0;
	for(i=n;i>=1;i--)
    {
		int dp = lower_bound(dpr,dpr+lis,a[i])-dpr;
		if(dp == lis) lis++;
		dpr[dp] = a[i];
		r[i] = dp;
	}
	while(q--)
    {
		cin >> x;
		x++;
		cout << min(l[x],r[x]) << '\n';
	}
}