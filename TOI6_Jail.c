/*
TASK: jail
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,k=0,n,m;
    scanf("%d %d",&n,&m);
    int Jail[n],a[n];
    for(i=0;i<n;i++)
    {
        Jail[i]=i;
    }
    for(i=0;i<n;i++)
    {
        k+=m;
        printf("%d",Jail[k%(n-i+1)]);
        Jail[k%(n-i+1)]=0;
        for(k=0;k<n;k++)
        {
            for(j=0;j<n;j++)
            {
                if(Jail[j]!=0)
                {
                    a[k]=Jail[j]
                }
            }
        }
    }

}