/*
TASK: BEE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,k,l;
    int n[0]=3,n[1]=5,sum[1]=7;
    scanf("%d %d %d",&i,&j,&k);
    for(l=i+2;i<=j;l++)
    {
        n[l]=n[l-1]+n[l-2];
        sum[l]=sum[l-1]+n[l];
    }
    for(l=i+2;i<=j;l++)
    {
        printf("%d ",sum[l]);
    }
}