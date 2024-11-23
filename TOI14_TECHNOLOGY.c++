/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i=1;i<=n;i++)
    {
        int s,h,w,o;
        cin >> s >> h >> w >> o;
        mx=max(mx,s+w);
        a[s].push_back({o,h});
        a[s+w].push_back({-o,h});    
    }
    int chk=0,x,y,cnt=0;
    long long int ans=0;
    for(i=1;i<=mx;i++)
    {
        int l=1,r=1e6;
        while(l<=r)
        chk=i;
    }
    cout << ans;
}