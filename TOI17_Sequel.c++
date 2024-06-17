/*
TASK: Sequel
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
const int B=400;
int arr[100002],i,j,n,q;
int dp[100002][B+4];
int main()
{
    cin >> n >> q;
    for (int i=0;i<n;i++) cin >> arr[i];
    for (i=n-1;i>=0;i--)
    {
        for (j=1;j<B;j++)
        {
            dp[i][j]=arr[i];
            if (j+i<n) dp[i][j]+=dp[i+j][j];
        }
    }
    while(q--)
    {
        int l,m,r;
        cin >> l >> m >> r;
        l--;
        r--;
        int pd=0,x=(r-l)/m,num = l+x*m;
        if (m<B)
        {
            pd=dp[l][m];
            if (num+m<n) pd -= dp[num+m][m];
        }
        else for(i=l;i<=r;i+=m) pd += arr[i];
        cout << pd << " ";
    }
    return 0;
}