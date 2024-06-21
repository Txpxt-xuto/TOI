#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+6;
int n,cnt,ans,mid,l,dp[N];
string s;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(l=1;l<=n;l++)
    {
        if(s[l-1]=='F') ans+=cnt;
        else
        {
            int r=l;
            while(r<n && s[r]=='T') r++;
            for(mid=l;mid<=r;mid++)
            {
                cnt+=mid-dp[mid-l+1];
                ans+=cnt;
                dp[mid-l+1]=r-(mid-l);
            }
            l=r;
        }
    }
    cout << ans;
}