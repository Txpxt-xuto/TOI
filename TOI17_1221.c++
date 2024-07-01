#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,q;
    cin>>n>>m>>q;
    int a[n+1][n+1],b[n+1][n+1],keb[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>keb[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=keb[i]+keb[j];
            b[i][j]=2;
        }
    }
    int te,mp,temp;
    for(int i=0;i<m;i++)
    {
        cin >> te>>mp>>temp;
        a[te][mp]=min(a[te][mp],temp);
        a[mp][te]=min(a[mp][te],temp);
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
                else if(a[i][u]+a[u][j]==a[i][j])
                {
                    b[i][j]=max(b[i][u]+b[u][j],b[i][j]);
                }
            }
        }
    }
    for(i=0;i<q;i++)
    {
        cin >> te >> mp;
        cout << a[te][mp] << " " << b[te][mp] << "\n";
    }
}