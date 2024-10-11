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
                if(sum==0)
                {
                }
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
void func(int i, string p)
{
    if(i == 0)
    {
        for(auto j : p) cout << j << j << "\n";
        cout << "E\n";
        return;
    }
    string t1 = p + '-';
    func(i-1, t1);
    if(i >= 2)
    {
        string t2 = p + '|';
        func(i-2, t2);
    }
    
}
