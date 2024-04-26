/*
TASK: car
LANG: C++
AUTHOR: Tapt Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[44][44];
int ans[44];
int n , m , s;

void solve(int nowi , int nowj)
{
    if(nowi == n)
    {
        for(int i=0;i<nowi;i++)
        {
            cout << ans[i] << "\n";
        }
        exit(0);
    }
    if(nowj > 1 && arr[nowi+1][nowj-1] == 0)
    {
        ans[nowi] = 1;
        solve(nowi+1,nowj-1);
    }
    if(nowj < m && arr[nowi+1][nowj+1] == 0)
    {
        ans[nowi] = 2;
        solve(nowi+1,nowj+1);
    }
    if(arr[nowi+1][nowj] == 0)
    {
        ans[nowi] = 3;
        solve(nowi+1,nowj);
    }
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> s >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(0,s);
    return 0;
}