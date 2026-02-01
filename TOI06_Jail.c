/*
TASK: jail
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
/*
#include <stdio.h>
int main()
{
    int i,j=0,k=1,n,m;
    scanf("%d %d",&n,&m);
    int Jail[n];
    for(i=0;i<n;i++) Jail[i]=0;
    i=0;
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
}*/

#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,k,n,S,B,min=1000000;
    scanf("%d",n);
    int s[n],b[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",a[i],b[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            
        }
    }
    printf("%d",min);
}