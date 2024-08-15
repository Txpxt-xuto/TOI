/*
TASK: observatory.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#define INF (int)1e9
using namespace std;
int h[2000][2001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,n,k,mx=-INF,i,j,r;
    cin >> m >> n >> k;
    for(i=0;i<m;i++) 
    {
        
    }
    for(int j=1; j<=n; j++)
    {
        cin >> h[i][j];
        h[i][j]+=h[i][j-1];
    }
    for(i=0;i<=m-k;i++) for(int j=1; j<=n-k+1; j++)
    {
        int sum=0;
        for(int r=0;r<k;r++) sum+=h[i+r][j+r]-h[i+r][j-1];
        mx=max(mx,sum);
    }
    for(i=0;i<=m-k;i++) 
    {
        for(j=n;j>=k;j--)
        {
            int sum=0;
            for(r=0;r<k;r++) sum+=h[i+r][j]-h[i+r][j-r-1];
            mx=max(mx,sum);
        }
    }
    cout << mx;
    return 0;
}