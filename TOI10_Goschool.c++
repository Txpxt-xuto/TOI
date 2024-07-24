/*
TASK: goschool.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    bool path[52][52] = {false}; 
    long long dp[52][52] = {0};
    int r, c, o, x, y;
    cin >> r >> c;
    cin >> o;
    for(i=0;i<o;i++)
    {
        cin >> x >> y;
        path[x][y] = true;
    }
    
    dp[1][0] = 1;
    for(int i=1; i<= r; i++)
    {
        for(j=1;j<=c;j++)
        {
            if(path[i][j]) continue;
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    cout<< dp[r][c];
    
    return 0;
}