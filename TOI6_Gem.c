/*
TASK: gem
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int linear,n[5],m[5],i;
    int Gem[5][100000*2],danger[5][100000];
    for(linear=0;linear<5;linear++)
    {
        scanf("%d %d",&n[linear],&m[linear]);
        for(i=0;i<n[linear]*2;i++)
        {
            scanf("%d",&Gem[linear][i]);
        }
        for(i=0;i<m[linear];i++)
        {
            scanf("%d",&danger[linear][i]);
        }
    }
    for(linear=0;linear<5;linear++)
    {
        printf("%d\n%d\n",n[linear],m[linear]);
        for(i=0;i<n[linear]*2;i++)
        {
            printf("%d ",Gem[linear][i]);
        }
        printf("\n");
        for(i=0;i<m[linear];i++)
        {
            printf("%d ",danger[linear][i]);
        }
        printf("\n");
    }
}