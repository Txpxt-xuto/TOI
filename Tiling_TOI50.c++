/*
TASK: tiling
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int n,i,j,k,count=0;
    std::cin >> n;
    int Tiling[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> Tiling[i][j];
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if((Tiling[i][j]==Tiling[i][j+1]) && (Tiling[i][j]==Tiling[i+1][j]) && (Tiling[i][j]!=Tiling[i+1][j+1]) && (Tiling[i][j]!=Tiling[i-1][j]) && (Tiling[i][j]!=Tiling[i][j-1]) && (Tiling[i][j+1]!=Tiling[i-1][j+1]) && (Tiling[i][j+1]!=Tiling[i][j+2]) && (Tiling[i+1][j]!=Tiling[i][j-1]) && (Tiling[i+1][j]!=Tiling[i+2][j]))
            {
                count++;
            }
            else if((Tiling[i][j]==Tiling[i][j+1])&& (Tiling[i][j]==Tiling[i+1][j+1]) && (Tiling[i][j]!=Tiling[i+1][j]) && (Tiling[i][j]!=Tiling[i-1][j]) && (Tiling[i][j]!=Tiling[i][j-1]) && (Tiling[i][j+1]!=Tiling[i-1][j+1]) && (Tiling[i][j+1]!=Tiling[i][j+2]) && (Tiling[i+1][j+1]!=Tiling[i+2][j+1]) && (Tiling[i+1][j+1]!=Tiling[i+1][j+2]))
            {
                count++;
            }
            else if((Tiling[i][j]==Tiling[i+1][j]) && (Tiling[i][j]==Tiling[i+1][j+1]) && (Tiling[i][j]!=Tiling[i][j+1])&& (Tiling[i][j]!=Tiling[i-1][j]) && (Tiling[i][j]!=Tiling[i][j-1]) && (Tiling[i+1][j+1]!=Tiling[i+2][j+1]) && (Tiling[i+1][j+1]!=Tiling[i+1][j+2]) && (Tiling[i+1][j]!=Tiling[i][j-1]) && (Tiling[i+1][j]!=Tiling[i+2][j]))
            {
                count++;
            }
            else if((Tiling[i][j+1]==Tiling[i+1][j+1]) && (Tiling[i][j+1]==Tiling[i+1][j]) && (Tiling[i][j+1]!=Tiling[i][j]) && (Tiling[i][j+1]!=Tiling[i-1][j+1]) && (Tiling[i][j+1]!=Tiling[i][j+2]) && (Tiling[i+1][j]!=Tiling[i][j-1]) && (Tiling[i+1][j]!=Tiling[i+2][j]) && (Tiling[i+1][j+1]!=Tiling[i+2][j+1]) && (Tiling[i+1][j+1]!=Tiling[i+1][j+2]))
            {
                count++;
                j++;
            }
        }
    }
    cout << count;
}