/*
TASK: beehive.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int dp[N][N];
int n, m, t, i ,j ,k;
int imp(int bx, int by, int tx, int ty) 
{
    int out = dp[bx][by] - dp[tx][by] - dp[bx][ty] + dp[tx][ty];
    int in = dp[bx - 1][by - 1] - dp[tx + 1][by - 1] - dp[bx - 1][ty + 1] + dp[tx + 1][ty + 1];
    return out - in;
}
void make() 
{
    cin >> n >> m >> t;
    for(i=0;i<t;i++) 
    {
        int x,y;
        cin >> x >> y;
        dp[x + 1][y + 1] = 1;
    }
    int z = 1;
    for(i=1;i<=n;i++) 
    {
        for(j=1;j<=m;j++) 
        {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            for(k=min(i,j);k>0;k--) 
            {
                if(imp(i, j, i - k, j - k) == 0)
                    z = max(z, k);
            }
        }
    }
    cout << z << '\n';
}
int main() 
{
    make();
    memset(dp, 0, sizeof(dp));
    main();
    return 0;
}