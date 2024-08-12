/*
TASK: pipe.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int,int> arr[15005];
int dp[15005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++ ) cin >> arr[i].first >> arr[i].second;
    for(int i=0;i<15005;i++ ) dp[i] = INT_MAX;
    for(inti=1;i<n;i++ )
    {
        int mini = INT_MAX, temp;
        for( int j=i+1;j<=n;j++ )
        {
            dp[j] = min( dp[j], (abs(arr[i].first-arr[j].first)+abs( arr[i].second-arr[j].second )) );
            if( mini > dp[j] )
            {
                mini = dp[j];
                temp = j;
            }
        }
        swap( arr[i+1], arr[temp] ), swap( dp[i+1], dp[temp] );
    }
    sort( dp, dp+15005 );
    long long ans = 0;
    for( int i=0;i<n-k;i++ ) ans += dp[i];
    cout << ans;
    return 0;
}
