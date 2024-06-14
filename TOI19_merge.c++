#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m,q;
    cin >> n >> m >> q;
    vector<int> x(n),y(m),s(n+1),t(m+1);
    for (int i=0;i<n;i++) cin >> x[i];
    for (int i=1;i<=n;i++) 
    {
        cin >> s[i];
        s[i]+=s[i-1];
    }
    for (int i=0;i<m;i++) cin >> y[i];
    for (int i=1;i<=m;i++) 
    {
        cin >> t[i];
        t[i]+=t[i-1];
    }
    int p,b,a;
    while (q--){
        cin >> a >> b>>p;
        int l=-1e9,r=1e9,md;
        while (l<r)
        {
            md=(l+r)>>1;
            int i=s[upper_bound(x.begin(),x.end(),md)-x.begin()];
            int j=t[upper_bound(y.begin(),y.end(),(md-b)/a)-y.begin()];
            if(i+j < p) l=md+1;
            else r=md;
        }
        cout << l << '\n';
    }
	return 0;
}
