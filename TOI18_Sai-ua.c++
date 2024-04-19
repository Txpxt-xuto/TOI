#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5005;
ll dp[N][N];
bool check(int start,int end) {
    if (end - start == 1) {
        return true;
    }
    return abs(dp[start+1][start+1]-dp[end][end]) > abs(dp[start][start]-dp[end-1][end-1]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> dp[i][i];
    }
    for(int i=n-2;i>=0;i--) {
        for (int j=i+1;j<n;j++) {
            dp[i][j] = max(dp[i][j-1]+dp[j][j],dp[i+1][j]+dp[i][i])+abs(dp[i][i]-dp[j][j]);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=i;k<j;k++) {
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}