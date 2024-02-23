/*
Lang: C
TASK: CHAIN
AUTHOR: Tapat Toungsakuld
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int L,N,x,y,z;
    scanf("%d",&L);
    scanf("%d",&N);
    char word[N][L];
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
                z+=1;
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
}
