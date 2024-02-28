/*
TASK: DICE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    char word[n][1000];
    for(i=0;i<n;i++)
    {
        scanf("%s",&word[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%s\n",word[i]);
    }
}