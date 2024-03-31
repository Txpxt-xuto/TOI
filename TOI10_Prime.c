/*
TASK: prime.c 
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <stdio.h>
int main()
{
    int n,i,j=1,k,sum=0;
    scanf("%d",&n);
    while(sum<n)
    {
        j++;
        k=0;
        for(i=1;i<j;i++)
        {
            if(j%i!=0 || j==2 || i==1) k++;
            else i=j;
        }
        if(k==j-1) sum++;
        
    }
    printf("%d",j);
}