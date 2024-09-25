/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int board[2050][2050],sq[2050][2050],qs[2050][2050],dp[2050][2050],mx=INT_MIN;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int m,n,k;
    cin >> m >> n >> k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
        {
            cin >> board[i][j];
            sq[i][j]=board[i][j]+sq[i-1][j]+sq[i][j-1]-sq[i-1][j-1];
            qs[i][j]=board[i][j]+qs[i][j-1];
            dp[i][j]=board[i][j]+dp[i-1][j-1]+qs[i][j-1];
            if(i>=k && j>=k) mx=max(mx,dp[i][j]-dp[i-k][j-k]-sq[i][j-k]+sq[i-k][j-k]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n/2;j++)
        {
            swap(board[i][j],board[i][n-j+1]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sq[i][j]=board[i][j]+sq[i-1][j]+sq[i][j-1]-sq[i-1][j-1];
            qs[i][j]=board[i][j]+qs[i][j-1];
            dp[i][j]=board[i][j]+dp[i-1][j-1]+qs[i][j-1];
            if(i>=k && j>=k) mx=max(mx,dp[i][j]-dp[i-k][j-k]-sq[i][j-k]+sq[i-k][j-k]);
        }
    }
    cout << mx;
    return 0;
}