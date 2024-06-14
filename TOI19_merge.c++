#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int n,m,q,i;
    cin >> n >> m >> q;
    int a[n],y[n],b[m],z[m];
    for(i=0;i<n;i++) cin >> a[i];
    cin >> y[0];
    for(i=1;i<n;i++)
    {
        cin >> y[i];
        y[i]+=y[i-1];
    }
    for(i=0;i<m;i++) cin >> b[i];
    cin >> z[0];
    for(i=1;i<m;i++)
    {
        cin >> z[i];
        z[i]+=z[i-1];
    }
    for(i=0;i<q;i++)
    {
        int aa,bb,k;
        cin >> aa >> bb >> k;
        long long int l=-1e18,r=1e18;
        while(l<r)
        {
            long long int mid=l+(r-l)/2,sum=0;
            auto it=upper_bound(a,a+n,mid)-a-1,it2=upper_bound(b,b+m,double(mid-bb)/double(aa))-b-1;
            if(it!=-1)sum+=y[it];
            if(it2!=-1)sum+=z[it2];
            if(sum>=k) r=mid;
            else l=mid+1;
        }
        cout << l << "\n";
    }
}
