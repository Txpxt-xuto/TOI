/*
TASK: jail
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,k,n,m,p,loop=0;
    scanf("%d %d",&n,&m);
    int Jail[n],a[n];
    for(i=0;i<n;i++)
    {
        Jail[i]=i;
    }
    for(i=0;i<n;i++)
    {
        loop+=m;
        printf("\n%d",Jail[i+loop%(n-i)]);
        for(j=0;j<n;j++)
        {
            for(k=0;k<n-1;k++)
            {
                p=Jail[k];
                Jail[k]=Jail[k+1];
                Jail[k+1]=p;
            }
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
            printf("%d",Jail[i]);
        }
        printf("\n");
    }
}