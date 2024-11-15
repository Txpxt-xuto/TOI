/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll z, k, n, i, j;
ll dino[2000005], bond[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> z >> k >> n;
    for(i=0;i<n;i++) cin >> bond[i];
    dino[1] = -1;
    for(i=2;i<=z;i++)
    {
        if(dino[i] != 0) continue;
    }
}
