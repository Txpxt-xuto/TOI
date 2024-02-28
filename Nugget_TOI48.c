/*
TASK: PATTERN
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,k=0;
    scanf("%d",&i);
    for(j=6;j<=i;j++)
    {
        if(j%3==0 || ((j-20)%3==0 && j>23) || j>43 || j%20==0)
        {
            printf("%d\n",j);
            k++;
        }
    }
    if(k==0) 
    {
        printf("no");
    }
}