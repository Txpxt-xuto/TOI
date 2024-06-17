#include <bits/stdc++.h>

using namespace std;
const int B=400;
int niza[100002],i,j;
int dp[100002][B+4];
int main()
{
    int n,q;
    cin >> n >> q;
    for (int i=0;i<n;i++) cin>>niza[i];

    for (i=n-1;i>=0;i--)
    {
        for (skok=1;skok<B;skok++)
        {
            dp[i][skok]=niza[i];
            if (skok+i<n) dp[i][skok]+=dp[i+skok][skok];
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