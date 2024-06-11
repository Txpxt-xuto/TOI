/*
TASK: location.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include<bits/stdc++.h>
using namespace std;
int n, m, k, i, j;
int ans, psum[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(i=1;i<=n;++i) 
    {
        for(j=1;j<=m;++j) 
        {
            cin >> psum[i][j];
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
            if(i-k>=0 && j-k>=0) 
            {
                ans = max(ans,psum[i][j] -(psum[i][j-k] + psum[i-k][j] - psum[i-k][j-k]));
            }      
        }
    }
    cout << ans;
}