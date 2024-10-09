/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int arr[505][505];
int qs[505][505];
int main()
{
    int n,m,t,x,y,sum,i,j,k;
    cin >> n >> m >> t;
    for(i=0;i<t;i++)
    {
        cin >> x >> y;
        arr[x+1][y+1]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+arr[i][j];
    }
    for(i=min(n,m);i>=1;i--)
    {
        for(j=1;j<=n-i+1;j++)
        {
            for(k=1;k<=m-i+1;k++)
            {
                sum = (qs[j+i-1][k+i-1]-qs[j-1][k+i-1]-qs[j+i-1][k-1]+qs[j-1][k-1])-(qs[j+i-2][k+i-2]-qs[j][k+i-2]-qs[j+i-2][k]+qs[j][k]);
                if(sum==0)
                {
                    cout << i << '\n';
                    j=n+1;
                    i=0;
                    break;
                }
            }
        }
    }
    memset(arr,0,sizeof arr);
    memset(qs,0,sizeof qs);
    cin >> n >> m >> t;
    for(i=0;i<t;i++)
    {
        cin >> x >> y;
        arr[x+1][y+1] = 1;
    }
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+arr[i][j];
    for(i=min(n,m);i>=1;i--)
    {
        for(j=1;j<=n-i+1;j++)
        {
            for(k=1;k<=m-i+1;k++)
            {
                sum = (qs[j+i-1][k+i-1]-qs[j-1][k+i-1]-qs[j+i-1][k-1]+qs[j-1][k-1])-(qs[j+i-2][k+i-2]-qs[j][k+i-2]-qs[j+i-2][k]+qs[j][k]);
                if(sum==0)
                {
                    cout << i << '\n';
                    j=n+1;
                    i=0;
                    break;
                }
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int a[550][550],qs[550][550];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q=2;
    while(q--)
    {
        int n,m,t,mx=1;
        cin >> n >> m >> t;
        for(i=1;i<=t;i++)
        {
            int x,y;
            cin >> x >> y;
            a[x+1][y+1]++;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                qs[i][j]+=a[i][j]+qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1];
            }
        }
        if(qs[n][m]==n*m)
        {
            cout << 0 << '\n';
            continue;
        }
        for(sz=2;sz<=min(n,m);sz++)
        {
            for(int i=sz;i<=n;i++)
            {
                for(j=sz;j<=m;j++)
                {
                    int sumout = qs[i][j]-qs[i][j-sz]-qs[i-sz][j]+qs[i-sz][j-sz];
                    int sumin = qs[i-1][j-1]-qs[i-1][j-(sz-1)]-qs[i-(sz-1)][j-1]+qs[i-(sz-1)][j-(sz-1)];
                    if(sumout==sumin) mx=max(mx,sz);
                }
            }
        }
        cout << mx << '\n';
        memset(qs,0,sizeof qs);
        memset(a,0,sizeof a);
    }
    

    return 0;
}