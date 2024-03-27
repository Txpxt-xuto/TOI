/*
TASK: pair
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int n,m,i,j,sum=0;
    scanf("%d",&n);
    int x[n],y[n];
    for(i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j && x[i]>x[j] && y[i]<y[j])
            {
                sum+=x[i]+x[j];
            }
        }
    }
    printf("%d",sum);
}