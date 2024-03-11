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
    vector<int> L;
    int A[1000005];
    for (int t = 1; t <= N; t++)
    {
        int x = A[t];
        auto it = upper_bound(L.begin(), L.end(), x);
        if (it == L.end())
        L.push_back(x);
        else
        *it = x;
    }   
}