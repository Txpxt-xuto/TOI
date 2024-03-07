/*
TASK: WORD
Lang: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int n,m,i,j,k,x;
    scanf("%d %d",&n,&m);
    char word[n][m];
    for(i=0;i<n;i++)
    {
        scanf("%s",&word[i]);
    }
    scanf("%d",&x);
    char sentense[x][15];
    for(i=0;i<x;i++)
    {
        scanf("%s",&sentense[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(word[i][j]==sentense[i][j])
            {

            }
        }
    }
}