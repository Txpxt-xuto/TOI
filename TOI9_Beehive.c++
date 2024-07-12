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
int n, m, t;
int fence(int bx, int by, int tx, int ty) 
{
    int outer = dp[bx][by] - dp[tx][by] - dp[bx][ty] + dp[tx][ty];
    int inner = dp[bx - 1][by - 1] - dp[tx + 1][by - 1] - dp[bx - 1][ty + 1] + dp[tx + 1][ty + 1];
    return outer - inner;
}
void solve() 
{
    cin >> n >> m >> t;
    for(i=0;i<t;i++) 
    {
        int x, y;
        cin >> x >> y;
        dp[x + 1][y + 1] = 1;
    }
    int res = 1;
    for(i=1;i<=n;i++) 
    {
        for(j=1;j<=m;j++) 
        {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            for(k=min(i,j);k>0;k--) 
            {
                if(fence(i, j, i - k, j - k) == 0)
                    res = max(res, k);
            }
        }
    }
    cout << res << '\n';
}
int main() {
    solve();
    memset(dp, 0, sizeof(dp));
    solve();

    return 0;
}

/*
5 8
6
0 7
1 3
2 0
3 6
4 2
4 5
5 5
8
0 0
0 4
4 0
4 4
0 1
2 0
2 4
4 3
*/