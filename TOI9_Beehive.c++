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
        int n, m, t;
        int mx = 1;
        cin >> n >> m >> t;
        vector<vector<int>> map(n + 1, (vector<int>(m + 1, 0)));
        vector<vector<int>> dp(n + 1, (vector<int>(m + 1, 0)));
        for(int i = 0; i < t; i++)
        {
            int x, y;
            cin >> x >> y;
            map[x + 1][y + 1] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = map[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
        for(int i = mx; i <= n; i++)
        {
            for(int j = mx; j <= m; j++)
            {
                for(int k = mx; k <= n && k <= m; k++)
                {
                    if(i - k < 0 || j - k < 0) break;
                    int sqr = dp[i][j] - dp[i - 1][j - 1] + dp[i - 1][j - k + 1] + dp[i - k + 1][j - 1] - dp[i - k + 1][j - k + 1] - dp[i][j - k] - dp[i - k][j] + dp[i - k][j - k];
                    if(sqr == 0) mx = max(k, mx);
                }
            }
        }
        cout << mx << endl;
    }
}
