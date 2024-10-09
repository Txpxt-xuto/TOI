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
    int n,m,t,x,y,sum;
    cin >> n >> m >> t;
    for(int i=0;i<t;i++)
    {
        cin >> x >> y;
        arr[x+1][y+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+arr[i][j];
        }
    }
    for(int i=min(n,m);i>=1;i--)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            for(int k=1;k<=m-i+1;k++)
            {
                sum=(qs[j+i-1][k+i-1]-qs[j-1][k+i-1]-qs[j+i-1][k-1]+qs[j-1][k-1])-(qs[j+i-2][k+i-2]-qs[j][k+i-2]-qs[j+i-2][k]+qs[j][k]);
                if(sum==0)
                {
                    cout << i << '\n';j=n+1;i=0;break;
                }
            }
        }
    }
    memset(arr,0,sizeof arr);
    memset(qs,0,sizeof qs);
    cin >> n >> m >> t;
    for(int i=0;i<t;i++)
    {
        cin >> x >> y;
        arr[x+1][y+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+arr[i][j];
        }
    }
    for(int i=min(n,m);i>=1;i--)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            for(int k=1;k<=m-i+1;k++)
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
