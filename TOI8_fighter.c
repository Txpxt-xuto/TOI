/*
TASK: fighter.c
LANG: C
COMPILER: WDC
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int ca = 1, cb = 1, a = n, b = n, i = 0, t;
    while (a > 0 && b > 0 && i < 2*n) {
        scanf("%d", &t);
        if (t%2==0)
        {
            cb = 1;
            if (ca >= 3) b-=3;
            else b--;
            ca++;
        } 
        else
        {
            ca = 1;
            if (cb >= 3) a-=3;
            else a--;
            cb++;
        }
        i++;
    }
    if (ca > cb) printf("%d\n%d", 0, t);
    else printf("%d\n%d", 1, t);
}
