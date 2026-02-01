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
    int i,j,k,human,sum,max=0;
    int score[5][4];
    for(i=0;i<5;i++)
    {
        sum=0;
        for(j=0;j<4;j++)
        {
            scanf("%d", &score[i][j]);
            sum=sum+score[i][j];
        }
        if(sum>max)
        {
            max=sum;
            k=i;
        }
    }
    printf("%d %d",k+1,max);
}