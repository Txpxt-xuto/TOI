#include <bits/stdc++.h>
using namespace std;
const int hi=1005;
bool dp[hi][hi];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b,c;
    int an,bn,q,i,j,t;
    cin>> a >> b;
    an = a.size();
    bn = b.size();
    cin >> q;
    for(t=0;t<q;t++)
    {
        cin >> c;
        memset(dp,false,sizeof dp);
        dp[0][0] = true;
        for(int i=1;i<=an;i++)
        {
            if(a[i-1]!=c[i-1]) dp[i][0] = false;
            else dp[i][0]=dp[i-1][0];
        }
        for(i=1;i<=bn;i++)
        {
            if(b[i-1]!=c[i-1]) dp[0][i] = false;
            else dp[0][i]=dp[0][i-1];
        }
        for(i=1;i<=an;i++)
        {
            for(j=1;j<=bn;j++)
            {
                if(dp[i-1][j]==true && a[i-1]==c[i+j-1]) dp[i][j] = true;
                else if(dp[i][j-1]==true && b[j-1]==c[i+j-1]) dp[i][j] = true;
            }
        } 
        if(dp[an][bn]==true) cout << "Yes\n";
        else cout << "No\n";
    }
}