/*
TASK: nbk48.c
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main() 
{
    int n, q, i, j, money, count;
    scanf("%d %d", &n, &q);
    int a[n], b[q];
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    for(i=0;i<q;i++) 
    {
        count = 0;
        scanf("%d", &money);
        for(j=0;j<n;j++) 
        {
            if(money - a[j] >= 0) count = j+1;
            money -= a[j];
        }
        printf("%d\n", count);
    }
}
