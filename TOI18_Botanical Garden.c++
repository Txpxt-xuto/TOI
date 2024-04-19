#include<bits/stdc++.h>
using namespace std;
int n,q,h[200002],LIS[200002],LDS[200002],i,pos;
vector<int> v;
int main ()
{
    cin >> n >> q;
    for(i=1;i<=n;i++) cin >> h[i];
    for(i=1;i<=n;i++)
    {
        if(v.size()==0||v[v.size()-1]<=h[i])
        {
            v.push_back(h[i]);
            LIS[i]=v.size();
        }
        else
        {
            auto idx=upper_bound(v.begin(),v.end(),h[i])-v.begin();
            v[idx]=h[i];
            LIS[i]=idx+1;
        }
    }
    v.clear();
    for(i=n;i>=1;i--)
    {
        if(v.size()==0||v[v.size()-1]<=(h[i]))
        {
            v.push_back(h[i]);
            LDS[i]=v.size();
        }
        else
        {
            auto idx=upper_bound(v.begin(),v.end(),h[i])-v.begin();
            v[idx]=h[i];
            LDS[i]=idx+1;
        }
    }
    for(i=1;i<=q;i++)
    {
        cin >> pos;
        cout << min(LIS[pos+1],LDS[pos+1])-1<<"\n";
    }
}