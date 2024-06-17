#include <bits/stdc++.h>

using namespace std;
const int B=400;
int niza[100002],i,j,n,q;
int dp[100002][B+4];
int main()
{
    cin >> n >> q;
    for (int i=0;i<n;i++) cin >> niza[i];
    for (i=n-1;i>=0;i--)
    {
        for (j=1;j<B;j++)
        {
            dp[i][j]=niza[i];
            if (j+i<n) dp[i][j]+=dp[i+j][j];
        }
    }
    while(q--)
    {
        int l,m,r;
        cin >> l >> m >> r;
        l--;
        r--;
        int pd=0,x=(r-l)/m,desno = l+x*m;
        int ;
        if (m<B)
        {
            pd=dp[l][m];
            if (desno+m<n) pd-=dp[desno+m][m];
        }
        else for(i=l;i<=r;i+=m) pd+=niza[i];
        cout << pd << " ";
    }
    return 0;
}