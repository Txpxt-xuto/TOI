#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pii pair<ll,ll>
#define pipi pair<pii,pii>
using namespace std;

const int N = 2e5;

ll dpl[N+5], dpr[N+5], a[N+5], l[N+5], r[N+5];
int n, q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	int lis = 0;
	for(int i=1;i<=n;i++){
		int idx = lower_bound(dpl,dpl+lis,a[i])-dpl;
		if(idx == lis) lis++;
		dpl[idx] = a[i];
		l[i] = idx;
	}
	lis = 0;
	for(int i=n;i>=1;i--){
		int idx = lower_bound(dpr,dpr+lis,a[i])-dpr;
		if(idx == lis) lis++;
		dpr[idx] = a[i];
		r[i] = idx;
	}



	while(q--){
		int x;
		cin>>x;
		x++;
		cout<<min(l[x],r[x])<<'\n';
	}
}