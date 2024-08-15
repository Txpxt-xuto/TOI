/*
TASK: observatory.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>

using namespace std;
#define ll long long
const int N = 2003;

ll a[N][N], sum[N][N], sum2[N][N], dp[N][N], dp2[N][N];

int main(){
    int n, m, k, i, j; 
    scanf("%d %d %d", &n, &m, &k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%lld", &a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
            dp[i][j] = dp[i-1][j-1] + sum[i][j] - sum[i-1][j];
        }
    }
    ll ans = -1e18;

    for (int i = k;i <= n;i++){
        for (int j = k;j <= m;j++){
            ll res = dp[i][j] - dp[i-k][j-k] - (sum[i][j-k] - sum[i-k][j-k]);
            ans = max(ans , res);
        }
    }

    for (int i = 1;i <= n;i++){
        for (int j = m;j >= 1;j--){
            sum2[i][j] = sum[i][m] - sum[i][j-1];
            dp2[i][j] = dp2[i-1][j+1] + (sum2[i][j] - sum2[i-1][j]);
        }
    }

    for (int i = k;i <= n;i++){
        for (int j = m-k+1;j >= 1;j--){
            ll res = dp2[i][j] - dp2[i-k][j+k] - (sum2[i][j+k] - sum2[i-k][j+k]);
            ans = max(ans , res);
        }
    }

    printf("%lld", ans);

    return 0;
}