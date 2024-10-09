/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int arr[505][505];
int qs[505][505];
int main()
{
    int n,m,t,x,y,sum,i,j,k;
    cin >> n >> m >> t;
    for(i=0;i<t;i++)
    {
        cin >> x >> y;
        arr[x+1][y+1]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+arr[i][j];
    }
    for(i=min(n,m);i>=1;i--)
    {
        for(j=1;j<=n-i+1;j++)
        {
            for(k=1;k<=m-i+1;k++)
            {
                sum = (qs[j+i-1][k+i-1]-qs[j-1][k+i-1]-qs[j+i-1][k-1]+qs[j-1][k-1])-(qs[j+i-2][k+i-2]-qs[j][k+i-2]-qs[j+i-2][k]+qs[j][k]);
                if(sum==0)
                {
                    cout << i << '\n';
                    j=n+1;
                    i=0;
                    break;
                }
            }
        }
    }
    memset(arr,0,sizeof arr);
    memset(qs,0,sizeof qs);
    cin >> n >> m >> t;
    for(i=0;i<t;i++)
    {
        cin >> x >> y;
        arr[x+1][y+1] = 1;
    }
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+arr[i][j];
    for(i=min(n,m);i>=1;i--)
    {
        for(j=1;j<=n-i+1;j++)
        {
            for(k=1;k<=m-i+1;k++)
            {
                sum = (qs[j+i-1][k+i-1]-qs[j-1][k+i-1]-qs[j+i-1][k-1]+qs[j-1][k-1])-(qs[j+i-2][k+i-2]-qs[j][k+i-2]-qs[j+i-2][k]+qs[j][k]);
                if(sum==0)
                {
                    cout << i << '\n';
                    j=n+1;
                    i=0;
                    break;
                }
            }
        }
    }
}
/*
TASK: beehive.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <limits.h>
#define ll long long int
using namespace std;
int main()
{
    for(int d = 0; d < 2; d++)
    {
        int n, m, t, i, j ,k;
        int mx = 1;
        cin >> n >> m >> t;
        vector<vector<int>> map(n + 1, (vector<int>(m + 1, 0)));
        vector<vector<int>> dp(n + 1, (vector<int>(m + 1, 0)));
        for(i=0;i<t;i++)
        {
            int x, y;
            cin >> x >> y;
            map[x + 1][y + 1] = 1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                dp[i][j] = map[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
        for(i=mx;i<=n;i++)
        {
            for(j=mx;j<=m;j++)
            {
                for(k=mx;k<=n && k<=m;k++)
                {
                    if(i-k<0 || j-k<0) break;
                    int sqr = dp[i][j] - dp[i - 1][j - 1] + dp[i - 1][j - k + 1] + dp[i - k + 1][j - 1] - dp[i - k + 1][j - k + 1] - dp[i][j - k] - dp[i - k][j] + dp[i - k][j - k];
                    if(sqr == 0) mx = max(k, mx);
                }
            }
        }
        cout << mx << endl;
    }
}