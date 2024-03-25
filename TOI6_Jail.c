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
    int Jail[n];
    for(i=0;i<n;i++)
    {
        Jail[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        loop+=m;
        printf("\n%d",Jail[i+(loop-1)%(n-i)]);
        Jail[i+(loop-1)%(n-i)]=0;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n-1;k++)
            {
                if(Jail[k]>Jail[k+1])
                {
                    p=Jail[k];
                    Jail[k]=Jail[k+1];
                    Jail[k+1]=p;
                }
            }
        }
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ",Jail[j]);
        }    
        printf("||||\n");
    }
}