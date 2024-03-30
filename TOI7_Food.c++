/*
TASK: food
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int M,N,i,j;
    cin >> M >> N;
    int Labor[M];
    for(i=0;i<M;i++) cin >> Labor[i];
    j=min(Labor[0], Labor[M]);
    cout << j;
    
}