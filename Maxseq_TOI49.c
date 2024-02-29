/*
TASK: MAXSEQ
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
 */
#include <stdio.h>
int main()
{
    int i,j,k,n,sum,max=0,x,y,z;
    scanf("%d",&n);
    int Main_Sequences[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&Main_Sequences[i]);
    }
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
            sum=0;
            for (k=i;k<=j;k++)
            {
                sum+=Main_Sequences[k]; //หาค่าที่มากที่สุดของลำดับซึ่งเป็นลำดับย่อย
            }
            if(max<sum)
            {
                max=sum;
                x=i;
                y=j;
                z=k;
            }
        }
    }
    if(max<=0)
    {
        printf("Empty sequence");
    }
    else if(max>0)
    {
        for(z=x;z<=y;z++)
        {
            printf("%d ",Main_Sequences[z]);
        }
        printf("%d\n",max);
    }
}