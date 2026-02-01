/*
TASK: pair4.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
/*#include <bits/stdc++.h>
using namespace std;
int n,i,l,k;
char a[1005];
int dp[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    for(l=2;l<=n;l++)
    {
        for(i=0;i+l-1<n;i++)
        {
            int j = i+l-1;
            if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1]+1;
            else
            {
                for(k=i;k<j;k++) dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1];
}*/

#include <bits/stdc++.h>
using namespace std;
int n,i,l,k;
char a[1005];
int dp[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    for(l=2;l<=n;l++)
    {
        for(i=0;i+l-1<n;i++)
        {
            int j = i+l-1;
            if(a[i] == a[j]) dp[i][j] = dp[i+1][j-1]+1;
            else
            {
                for(k=i;k<j;k++) dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1];
}