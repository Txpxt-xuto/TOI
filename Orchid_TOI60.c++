/*
TASK: orchid.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j=0,N;
    cin >> N;
    int orchid[N];
    for(i=0;i<N;i++)
    {
        cin >> orchid[i];
    }
    for(i=0;i<N-1;i++)
    {
        if(orchid[i]>orchid[i+1])
        {
            j++;
            orchid[i+1]=orchid[i];
        }
    }
    cout << j;
}