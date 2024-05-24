/*
TASK: nbk48.c
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>

int main() 
{
    int n, q;
    scanf("%d%d", &n, &q);
    int a[n], b[q];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < q; i++) 
    {
        int count = 0, money;
        scanf("%d", &money);

        for (int j = 0; j < n; j++) 
        {
            if (money - a[j] >= 0) count = j+1;

            money -= a[j];
        }
        printf("%d\n", count);
    }
}
