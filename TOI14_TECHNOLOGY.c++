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
        }
    }
}