/*
TASK: tiling
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,count=0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int Tiling[30][30];
    for(i=2;i<=n+1;i++)
    {
        for(j=2;j<=n+1;j++)
        {
            cin >> Tiling[i][j];
        }
    }
    for(i=2;i<=n+1;i++)
    {
        for(j=2;j<=n+1;j++)
        {
            if((Tiling[i][j]==Tiling[i][j+1]) && (Tiling[i][j]==Tiling[i+1][j]) && (Tiling[i][j]!=Tiling[i+1][j+1]) && (Tiling[i][j]!=Tiling[i-1][j]) && (Tiling[i][j]!=Tiling[i][j-1]) && (Tiling[i][j+1]!=Tiling[i-1][j+1]) && (Tiling[i][j+1]!=Tiling[i][j+2]) && (Tiling[i+1][j]!=Tiling[i+1][j-1]) && (Tiling[i+1][j]!=Tiling[i+2][j]))
            {
                count++;
            }
            else if((Tiling[i][j]==Tiling[i][j+1])&& (Tiling[i][j]==Tiling[i+1][j+1]) && (Tiling[i][j]!=Tiling[i+1][j]) && (Tiling[i][j]!=Tiling[i-1][j]) && (Tiling[i][j]!=Tiling[i][j-1]) && (Tiling[i][j+1]!=Tiling[i-1][j+1]) && (Tiling[i][j+1]!=Tiling[i][j+2]) && (Tiling[i+1][j+1]!=Tiling[i+2][j+1]) && (Tiling[i+1][j+1]!=Tiling[i+1][j+2]))
            {
                count++;
            }
            else if((Tiling[i][j]==Tiling[i+1][j]) && (Tiling[i][j]==Tiling[i+1][j+1]) && (Tiling[i][j]!=Tiling[i][j+1])&& (Tiling[i][j]!=Tiling[i-1][j]) && (Tiling[i][j]!=Tiling[i][j-1]) && (Tiling[i+1][j+1]!=Tiling[i+2][j+1]) && (Tiling[i+1][j+1]!=Tiling[i+1][j+2]) && (Tiling[i+1][j]!=Tiling[i+1][j-1]) && (Tiling[i+1][j]!=Tiling[i+2][j]))
            {
                count++;
            }
            else if((Tiling[i][j+1]==Tiling[i+1][j+1]) && (Tiling[i][j+1]==Tiling[i+1][j]) && (Tiling[i][j+1]!=Tiling[i][j]) && (Tiling[i][j+1]!=Tiling[i-1][j+1]) && (Tiling[i][j+1]!=Tiling[i][j+2]) && (Tiling[i+1][j]!=Tiling[i+1][j-1]) && (Tiling[i+1][j]!=Tiling[i+2][j]) && (Tiling[i+1][j+1]!=Tiling[i+2][j+1]) && (Tiling[i+1][j+1]!=Tiling[i+1][j+2]))
            {
                count++;
                
            }
        }
    }
    cout << count;
}