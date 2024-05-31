#include<bits/stdc++.h>
using namespace std;

long long sausage[5010];
long long dp[5010][5010];
int n;
long long eat(int l,int r)
{
    if(l>=r) return sausage[l];
    else if(dp[l][r]!=0) return dp[l][r];
    else
    {
        dp[l][r] = max(eat(l+1,r)+sausage[l],eat(l,r-1)+sausage[r])+abs(sausage[l]-sausage[r]);
        return dp[l][r];
    }
}
int main()
{

    cin >> n;
    for(int i=0;i<n;i++) cin>>sausage[i];
    eat(0,n-1);
    for(int c=1;c<n-1;c++)
    {
        for(int r=0;r<n;r++) dp[0][r] = max(dp[0][r],dp[0][c]+dp[c+1][r]);
    }
    cout << dp[0][n-1];
}