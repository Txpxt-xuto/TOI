#include<bits/stdc++.h>
using namespace std;
const int NN=1e5+1;
#define pb push_back
vector<int> x,s,t,y;
int a,b,k;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    x.pb(-1e9-10),y.pb(-1e9-10),s.pb(0),t.pb(0);
    for(int i=0;i<n;i++) cin>>a,x.pb(a);
    for(int i=1;i<=n;i++) cin>>a,s.pb(a),s[i]+=s[i-1];
    for(int i=0;i<m;i++) cin>>a,y.pb(a);
    for(int i=1;i<=m;i++) cin>>a,t.pb(a),t[i]+=t[i-1];
    long long l,r;
    while(q--){
        l=-1e9,r=1e9;
        cin>>a>>b>>k;
        while(l<r){
            long long mid=(l+r)>>1;
            // cout<<l<<" "<<mid<<" "<<r<<"\n";
            int k1=upper_bound(x.begin(),x.end(),mid)-x.begin()-1;
            int k2=upper_bound(y.begin(),y.end(),(mid-b)/a)-y.begin()-1;
            if(s[k1]+t[k2]<k) l=mid+1;
            else r=mid;
        }
        cout<<l<<"\n";
    }
}
