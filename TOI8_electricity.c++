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
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        if(i==0)
        dp[i]=m;
        else
        {
            int temp=INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j<0)
                continue;
                temp=min(temp,dp[i-j]+m);
            }
            dp[i]=temp;
        }
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n-1];
}