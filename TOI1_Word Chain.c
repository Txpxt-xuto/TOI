/*
Lang: C
TASK: CHAIN
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int L,N,x,y,z;
    scanf("%d",&L);
    scanf("%d",&N);
    char word[N][L+1];
    for(x=0;x<N;x++)
    {
        scanf("%s",&word[x]);
    }
    for(x=0;x<N-1;x++)
    {
        z=0;
        for(y=0;y<L;y++)
        {
            if(word[x][y]!=word[x+1][y])
            {
                z++;
            }
        }
        if(z>2)
        {
            for(y=0;y<L;y++)
            {
                printf("%c",word[x][y]);
            }
            break;
        }
    }
    if(z<=2)
    {
        for(y=0;y<L;y++)
        {
            printf("%c",word[N-1][y]);
        }
    }
}