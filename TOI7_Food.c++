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
    int M,N,i,j,k;
    cin >> M >> N;
    int Labor[M];
    for(i=0;i<M;i++) cin >> Labor[i];
    for(k=1;k<=N;k++)
    {
        j=min(Labor[0], Labor[M]);
        for(i=0;i<M;i++) if(j==Labor[i]) Labor[i]+=j;
    }
    cout << min(Labor[0], Labor[M]);
}