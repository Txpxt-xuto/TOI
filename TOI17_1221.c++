/*
TASK: 12.21
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,q,i,j;
    cin >> n >> m >> q;
    int a[n+1][n+1],b[n+1][n+1],keb[n+1];
    for(i=1;i<=n;i++) cin >> keb[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=keb[i]+keb[j];
            b[i][j]=2;
        }
    }
    int z,mp,dp,u;
    for(i=0;i<m;i++)
    {
        cin >> z >> mp >> dp;
        a[z][mp]=min(a[z][mp],dp);
        a[mp][z]=min(a[mp][z],dp);
    }
    for(u=1;u<=n;u++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][u]+a[u][j]<a[i][j])
                {
                    a[i][j]=a[i][u]+a[u][j];
                    b[i][j]=b[i][u]+b[u][j];
                }
                else if(a[i][u]+a[u][j]==a[i][j]) b[i][j]=max(b[i][u]+b[u][j],b[i][j]);
            }
        }
    }
    for(i=0;i<q;i++)
    {
        cin >> z >> mp;
        cout << a[z][mp] << " " << b[z][mp] << "\n";
    }
}