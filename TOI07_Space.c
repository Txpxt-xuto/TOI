#include <stdio.h>
void generatebit(int n, int arrtogenerate[], int i)
{
    if (i == n) 
    {
        printTheArray(arrtogenerate, n);
        return;
    }
    arrtogenerate[i] = 0;
    generatebit(n, arrtogenerate, i + 1);
    arr[i] = 1;
    generatebit(n, arrtogenerate, i + 1);
}
int main()
{
    int d;
    int arrtogenerate[d],arrtostock[d];
    scanf("%d",&d);
    generatebit(d, arrgenerate, 0);
    return 0;
}