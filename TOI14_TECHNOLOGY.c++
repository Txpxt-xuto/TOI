/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;

int m, n, cnt, h;
int hive[1005][1005];
int dp[1005][1005];
int way[1005][1005];

int main()
{
    scanf("%d %d", &m, &n);


    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &hive[i][j]);
            if(i == 1){
                for(int j = 1; j <= n; j++){
                    dp[1][j] = hive[i][j];
                    way[i][j] = 1;
                }
                continue;
            }

            if(i%2){
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
                if(dp[i][j] == dp[i-1][j-1]){
                    way[i][j] += way[i-1][j-1];
                }
                if(dp[i][j] == dp[i-1][j]){
                    way[i][j] += way[i-1][j];
                }
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]);
                if(dp[i][j] == dp[i-1][j]){
                    way[i][j] += way[i-1][j];
                }
                if(dp[i][j] == dp[i-1][j+1]){
                    way[i][j] += way[i-1][j+1];
                }
            }
            dp[i][j] += hive[i][j];

        }

    }

    for(j=1;j<=n;j++) h = max(h, dp[m][j]);
    }
    {
        h = max(h, dp[m][j]);
    }
    for(j=1;j<=n;j++) if(dp[m][j] == h) cnt += way[m][j];
    printf("%d %d",h,cnt);
    return 0;
}