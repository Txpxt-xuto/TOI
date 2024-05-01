#include <stdio.h>
#include <math.h>
void stock(int arr[], int d)
{
    for(int i = 0; i < d-1; i++) 
    {
        for(int j = 0; j < d; j++) 
        {
            if(arr[i+1]-arr[i]==pow(10, j))
            {
                printf("%d %d\n",arr[i],arr[i+1]);
            }
        }
    }
}
void generatebit(int d, int arr[], int i)
{
    if(i == d) 
    {
        stock(arr, d);
        return;
    }
    arr[i] = 0;
    generatebit(d, arr, i + 1);
    arr[i] = 1;
    generatebit(d, arr, i + 1);
}
int main()
{
    int d;
    int arr[d];
    scanf("%d",&d);
    generatebit(d, arr, 0);
    return 0;
}