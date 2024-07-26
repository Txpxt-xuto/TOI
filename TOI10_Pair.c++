/*
TASK: pair4.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+7;
char a[N];
int n,dp[N][N];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++) cin >> a[i];
    for(l=2;l<=n;l++)
    {
        for(i=0;i+l-1<n;i++)
        {
            int j = i+l-1;
            if(a[i]==a[j]) dp[i][j] = dp[i+1][j-1]+1;
            for(k=i;k<j;k++) dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    cout << dp[0][n-1];
}
