#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> mount1;
vector<long long> ans,ans1;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,mx=-1;
    cin >> n;
    mount1.resize(n);
    ans1.resize(n);
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        x=x*-1;
        mount1[i].push_back(y);
        mount1[i].push_back(x);
        mount1[i].push_back(i);
    }
    sort(mount1.begin(), mount1.end());
    for (int i = 0; i < n; i++) {
        int x=upper_bound(ans.begin(),ans.end(),mount1[i][1])-ans.begin();
        if(x==ans.size()) 
        ans.push_back(mount1[i][1]);
        else
        ans[x]=mount1[i][1];
        ans1[mount1[i][2]]=x+1;
        if(ans1[mount1[i][2]]>mx) mx=ans1[mount1[i][2]];
    }
    cout << mx << '\n';
    for(int i=0;i<n;i++) cout << ans1[i] << " ";
    return 0;
}