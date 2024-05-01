#include <stdio.h>
#include <math.h>
int generatebit(int d, int arr[], int i)
{
    
    if(i == d) 
    {
        for(int j = 0; j < d-1; j++) 
        {
            return ;
        }
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
    int arr[d],memory[d*d][d];
    scanf("%d",&d);
    generatebit(d, arr, 0);
}