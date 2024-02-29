/*
TASK: TILING
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
int main()
{
    int n,i,j,k,count=0;
    std::cin >> n;
    int Tiling[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            std::cin >> Tiling[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(Tiling[i][j]==Tiling[i][j+1] && Tiling[i][j+1]==Tiling[i+1][j] && Tiling[i+1][j]!=Tiling[i+1][j+1])
            {
                count++;
            }
            else if(Tiling[i][j]==Tiling[i][j+1] && Tiling[i][j+1]==Tiling[i+1][j+1] && Tiling[i+1][j+1]!=Tiling[i+1][j])
            {
                count++;
            }
            else if(Tiling[i][j]==Tiling[i+1][j] && Tiling[i+1][j]==Tiling[i+1][j+1] && Tiling[i+1][j+1]!=Tiling[i][j+1])
            {
                count++;
            }
            else if(Tiling[i][j+1]==Tiling[i+1][j+1] && Tiling[i+1][j+1]==Tiling[i+1][j] && Tiling[i+1][j]!=Tiling[i][j])
            {
                count++;
            }
        }
    }
    std::cout << count;
}