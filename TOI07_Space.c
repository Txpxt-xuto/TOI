#include <stdio.h>
int d;
int memory[d];
void stock(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
}
void generatebit(int n, int arr[], int i)
{
    if (i == n) 
    {
        stock(arr, n);
        return;
    }
    arr[i] = 0;
    generatebit(n, arr, i + 1);
    arr[i] = 1;
    generatebit(n, arr, i + 1);
}
int main()
{
    int arr[d];
    scanf("%d",&d);
    generatebit(d, arr, 0);
    return 0;
}