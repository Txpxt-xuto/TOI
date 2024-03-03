/*
TASK: MAXSEQ
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,n,sum,max=-1000,x,y;
    scanf("%d",&n);
    int Main_Sequences[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&Main_Sequences[i]);
    }
    for (i=0;i<n;i++)
    {
        sum=0;
        for (j=i;j<n;j++)
        {
            sum+=Main_Sequences[j]; //หาค่าที่มากที่สุดของลำดับซึ่งเป็นลำดับย่อย
            if(max<sum)
            {
                max=sum;
                x=i;
                y=j;
            }
        }
    }
    if(max<=0)
    {
        printf("Empty sequence");
    }
    else
    {
        for(i=x;i<=y;i++)
        {
            printf("%d ",Main_Sequences[i]);
        }
        printf("\n%d",max);
    }
}