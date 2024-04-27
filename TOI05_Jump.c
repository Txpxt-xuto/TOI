/*
TASK: Jump
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
unsigned int x[30005];
int main()
{
    int N,K,i,j,Max=0;
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++) scanf("%d",&x[i]);
    i=0;
    j=0;
    while( j < N )
    {
        if( x[j] - x[i] > K ) i++;
        else
        {
            if(Max<j-i) Max=j-i;
            j++;
        }
    }
    printf("%d",Max);
}