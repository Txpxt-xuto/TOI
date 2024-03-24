/*
TASK: LAK
LANG: C++
AUTHOR: Tapat Toungaskul
CENTER: Home
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N,i,j;
int main()
{
    cin >> N;
    char bit[N][16];
    for(i=0;i<N;i++)
    {
        cin >> bit[i];
    }
    for(i=0;i<N;i++)
    {
        cout << bit[i] << endl;
    }
}