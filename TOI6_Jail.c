/*
TASK: jail
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j=0,k=1,n,m;
    scanf("%d %d",&n,&m);
    int Jail[n];
    for(i=1;i<=n;i++)
    {
        Jail[i]=0;
    }
    i=1;
    while(j!=n)
    {
        if(i>=n) i-=n;
        if(k%m==0 && Jail[i]==0) 
        {
            printf("%d ",i+1);
            Jail[i]=1;
            k++;
            j++;
        } 
        else if(Jail[i]!=1) k++;
        i++;
    }
}