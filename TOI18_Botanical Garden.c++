#include<bits/stdc++.h>
using namespace std;
int r[200001],l[200001],arr[200001],n,q,t1,i,temp;
vector<int> vr,vl;
int main()
{
    cin >> n >> q ;
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
        int idx=lower_bound(vl.begin(),vl.end(),arr[i])-vl.begin();
        if(idx == vl.size())vl.push_back(arr[i]);
        vl[idx] = arr[i];
        l[i] = idx;
    }
    for(i=n-1;i>=0;i--)
    {
        int idx=lower_bound(vr.begin(),vr.end(),arr[i])-vr.begin();
        if(idx == vr.size())vr.push_back(arr[i]);
        vr[idx] = arr[i];
        r[i] = idx;
    }
    while(q--)
    {
        cin >> temp;
        cout << min(r[temp],l[temp]) << " ";
    }
}