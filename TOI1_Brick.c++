/*
TASK: BRICK
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int N,M,i,j,k;
    scanf("%d %d",&N,&M);
    char Brick[N][M];
    for(i=0;i<M;i++) scanf("%s",&Brick[i]);
    for(i=0;i<N;i++)
    {
        scanf("%d",&k);
        if(Brick[0][i]=='O') continue;
        j = 0;
        while(1)
        {
            if(Brick[j][i]=='O') break;
            j++;
            if(j>=M) break;
        }
        int x = j-1,c = 0;
        while(1)
        {
            if(c==k) break;
            if(x<0) break;
            Brick[x][i] = '#';
            c++; 
            x--;
        }
    }
    for(i=0;i<M;i++) scanf("%s\n",Brick[i]);
}