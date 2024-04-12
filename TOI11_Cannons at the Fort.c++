/*
TASK: cannon.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int N,M,K,L,Cannons[N+1],Fort[M][K],i,j;
    cin >> N >> M >> K >> L;
    for(i=1;i<N;i++) cin >> Cannons[i];
    for(i=1;i<N;i++)
    {
        for(j=1;j<N;j++) 
        {
            cin >> Fort[i][j];
        }
    }
}