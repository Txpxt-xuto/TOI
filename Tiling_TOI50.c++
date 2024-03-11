/*
TASK: tiling
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/

#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
int Tiling[30][30];
bool ck(int y,int x){
    if(Tiling[y][x]==Tiling[y-1][x] && Tiling[y][x]==Tiling[y][x+1] && Tiling[y][x]!=Tiling[y-2][x] && Tiling[y][x]!=Tiling[y-1][x+1] && Tiling[y][x]!=Tiling[y][x+2] && Tiling[y][x]!=Tiling[y+1][x+1] && Tiling[y][x]!=Tiling[y+1][x] && Tiling[y][x]!=Tiling[y][x-1] && Tiling[y][x]!=Tiling[y-1][x-1]) 
    {
        return 1;
    }
    if(Tiling[y][x]==Tiling[y-1][x] && Tiling[y][x]==Tiling[y][x-1] && Tiling[y][x]!=Tiling[y-2][x] && Tiling[y][x]!=Tiling[y-1][x+1] && Tiling[y][x]!=Tiling[y][x+1] && Tiling[y][x]!=Tiling[y+1][x] && Tiling[y][x]!=Tiling[y+1][x-1] && Tiling[y][x]!=Tiling[y][x-2] && Tiling[y][x]!=Tiling[y-1][x-1]) 
    {
        return 1;
    }
    if(Tiling[y][x]==Tiling[y+1][x] && Tiling[y][x]==Tiling[y][x-1] && Tiling[y][x]!=Tiling[y-1][x] && Tiling[y][x]!=Tiling[y][x+1] && Tiling[y][x]!=Tiling[y+1][x+1] && Tiling[y][x]!=Tiling[y+2][x] && Tiling[y][x]!=Tiling[y+1][x-1] && Tiling[y][x]!=Tiling[y][x-2] && Tiling[y][x]!=Tiling[y-1][x-1]) 
    {
        return 1;
    }
    if(Tiling[y][x]==Tiling[y+1][x] && Tiling[y][x]==Tiling[y][x+1] && Tiling[y][x]!=Tiling[y-1][x] && Tiling[y][x]!=Tiling[y-1][x+1] && Tiling[y][x]!=Tiling[y][x+2] && Tiling[y][x]!=Tiling[y+1][x+1] && Tiling[y][x]!=Tiling[y+2][x] && Tiling[y][x]!=Tiling[y+1][x-1] && Tiling[y][x]!=Tiling[y][x-1]) 
    {
        return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(Tiling,-1,sizeof(Tiling));
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=n+1;j++)
        {
            cin >> Tiling[i][j];
        }
    }
    for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=n+1;j++)
        {
            if(ck(i,j)) 
            {
                sum+=1;
            }
        }
    }
    cout << sum;
}
