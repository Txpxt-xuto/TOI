/*
TASK: BEE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    int n,a,b,i,j;
    scanf("%d", &n);
    while (n != -1) 
    {
        a = 1;
        b = 0;
        for (i=0;i<n;i++)
        {
            j = b;
            b = a;
            a = a + 1 + j;
        }
        printf("%d %d\n", a, a + b + 1);
        scanf("%d", &n);
    }
}