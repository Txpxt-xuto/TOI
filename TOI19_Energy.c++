#include <bits/stdc++.h>
using namespace std;
#define int long long
int qs[330],dp[330][330][15],n,k,d;
const int md = 1e9+7;
int cal(int l,int r,int K){
    if(dp[l][r][K]!=-1)return dp[l][r][K];
    if(!K)return dp[l][r][K]=1;
    int cnt=0;
    for(int cut=l;cut<r;cut++){
        if(abs(2*qs[cut]-qs[l-1]-qs[r])>d)continue;
        cnt=(cnt+(cal(l,cut,K-1)*cal(cut+1,r,K-1))%md)%md;
    }
    return dp[l][r][K]=cnt;
}
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k > >d;
    memset(dp,-1,sizeof dp);
    for(i=1;i<=n;i++) cin >> qs[i],qs[i]+=qs[i-1];
    cout << cal(1,n,k-1);
    return 0;
}