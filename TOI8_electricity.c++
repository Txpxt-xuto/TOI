/*
TASK: electricity.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include<bits/stdc++.h>
using namespace std;
int dp[500010];
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n,m,i,j,k;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> m;
        if(i==0)
        dp[i]=m;
        else
        {
            int temp=INT_MAX;
            for(j=1;j<=k;j++)
            {
                if(i-j<0)
                continue;
                temp=min(temp,dp[i-j]+m);
            }
            dp[i] = temp;
        }
    }
    cout << dp[n-1];
}