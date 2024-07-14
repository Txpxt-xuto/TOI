/*
TASK: beehive.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, m, i, j;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m));
    for(i=0;i<n;i++) 
    {
        for(j=0;j<m;j++) cin >> v[i][j];
    }
    for(j=0;j<m;j++) dp[0][j] = pair<int, int>(v[0][j], 1);
    for(i=1;i<n;i++) 
    {
        for(j=0;j<m;j++)  
        {
            if(i%2==0)
            {
                if(j==0) 
                {
                    dp[i][j].first = dp[i-1][j].first+v[i][j];
                    dp[i][j].second = dp[i-1][j].second;
                }
                else 
                {
                    if(dp[i-1][j-1].first>dp[i-1][j].first)
                    {
                        dp[i][j].first = dp[i-1][j-1].first+v[i][j];
                        dp[i][j].second = dp[i-1][j-1].second;
                    }
                    else if(dp[i-1][j-1].first<dp[i-1][j].first)
                    {
                        dp[i][j].first = dp[i-1][j].first+v[i][j];
                        dp[i][j].second = dp[i-1][j].second;
                    }
                    else
                    {
                        dp[i][j].first = dp[i-1][j-1].first+v[i][j];
                        dp[i][j].second = dp[i-1][j-1].second+dp[i-1][j].second;
                    }
                }
            }
            else 
            {
                if(j==m-1) 
                {
                    dp[i][j].first = dp[i-1][j].first+v[i][j];
                    dp[i][j].second = dp[i-1][j].second;
                }
                else 
                {
                    if(dp[i-1][j+1].first>dp[i-1][j].first) 
                    {
                        dp[i][j].first=dp[i-1][j+1].first+v[i][j];
                        dp[i][j].second=dp[i-1][j+1].second;
                    }
                    else if(dp[i-1][j+1].first<dp[i-1][j].first) 
                    {
                        dp[i][j].first=dp[i-1][j].first+v[i][j];
                        dp[i][j].second=dp[i-1][j].second;
                    }
                    else 
                    {
                        dp[i][j].first=dp[i-1][j+1].first+v[i][j];
                        dp[i][j].second=dp[i-1][j+1].second+dp[i-1][j].second;
                    }
                }
            }
        }
    }
    int mx=0, c=0;
    for(j=0;j<m; j++) mx = max(mx, dp[n-1][j].first);
    for(j=0;j<m; j++) if(dp[n-1][j].first == mx) c += dp[n-1][j].second;
    cout << mx << " " << c;
}