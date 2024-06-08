#include <bits/stdc++.h>
#define newline cout << "\n";
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
int i,j;
using namespace std;
struct A
{
    int m,d;
};
int jj[1050],k[1050],m,n;
A dp[1050][1050];
A check(int current,int add)
{
    if(current+add<=m) return {current+add,0};
    else return {add,1};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for(i=1;i<=n;i++)
    {
        cin >> jj[i];
        dp[i][0].d=dp[i-1][0].d;
        A res=check(dp[i-1][0].m,jj[i]);
        dp[i][0].m=res.m;
        dp[i][0].d+=res.d;
    }
    for(i=1;i<=n;i++)
    {
        cin >> k[i];
        dp[0][i].d=dp[0][i-1].d;
        A res=check(dp[0][i-1].m,k[i]);
        dp[0][i].m=res.m;
        dp[0][i].d+=res.d;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            A a={0,0},b={0,0};
            a.d=dp[i-1][j].d;
            A res=check(dp[i-1][j].m,jj[i]);
            a.m=res.m;
            a.d+=res.d;
            b.d=dp[i][j-1].d;
            res=check(dp[i][j-1].m,k[j]);
            b.m=res.m;
            b.d+=res.d;
            if(a.d==b.d)
            {
                if(a.m>=b.m) dp[i][j]=b;
                else dp[i][j]=a;
            }
            else if(a.d>b.d) dp[i][j]=b;
            else dp[i][j]=a;
        }
    }
    cout << dp[n][n].d+1; newline
    cout << dp[n][n].m;
    return 0;
}