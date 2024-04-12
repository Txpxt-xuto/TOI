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
    int N,M,K,L;
    int i,j,Cannons[N+1],Fort[M+1][K+1];
    cin >> N >> M >> K >> L;
    for(i=1;i<N;i++) cin >> Cannons[i];
    for(i=1;i<M;i++)
    {
        for(j=1;j<K;j++) 
        {
            cin >> Fort[i][j];
        }
    }
    for(i=1;i<N;i++) cout << Cannons[i];
    cout << endl;
    for(i=1;i<M;i++)
    {
        for(j=1;j<K;j++) 
        {
            cout << Fort[i][j];
        }
        cout << endl;
    }
}