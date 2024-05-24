/*
TASK: nbk48.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int num[100010], n, q, i;
pair<int, int> dp[100010];
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(i=1;i<=n;i++) 
    {
        cin >> dp[i].first;
        dp[i].first += dp[i - 1].first;
        dp[i].second = i;
    }
    sort(dp + 1, dp + 1 + n);
    for(i=1;i<=n;i++) 
    {
        num[i] = dp[i].first;
        dp[i].second = max(dp[i - 1].second, dp[i].second);
    }
    for(i=1;i<=q;i++) 
    {
        int bud;
        cin >> bud;
        int upper = upper_bound(num + 1, num + 1 + n, bud) - (num + 1);
        cout << dp[upper].second << "\n";
    }
}
