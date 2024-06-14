#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int a[500500], fac[500500];
signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n,i; 
    cin >> n;
    for(i=1; i<=n*2-1; i++)
    {
        int x; 
        cin >> x;
        a[x]++;
    }
    fac[0] = fac[1] = 1;
    for(i=2; i<=500000; i++)
    {
        fac[i] = fac[i-1] * i;
        fac[i] %= MOD;
    }
    int ans = 1;
    for(i=1; i<=n; i++)
    {
        ans = ans * fac[a[i] - 1];
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}