#include <stdio.h>
void generatebit(int n, int arr[], int i)
{
    if (i == n) 
    {
        printTheArray(arr, n);
        return;
    }
    arr[i] = 0;
    generatebit(n, arr, i + 1);
    arr[i] = 1;
    generatebit(n, arr, i + 1);
}
int main()
{
    int d;
    int arrtogenerate[d],arrtostock[d];
    scanf("%d",&d);
    generatebit(d, arrtogenerate, 0);
    return 0;
}