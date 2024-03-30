/*
TASK: labor.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
long long N, M;
long long Labor[1000100];
int main() 
{
    scanf("%lld %lld", &M, &N);
    for (int i = 1; i <= M; i++) cin >> Labor[i];
    long long a = 1, b = 1000000LL * N;
    while (a < b)
    {
        long long mid = (a + b) / 2;
        long long all = 0;
        for (int i = 1; i <= M; i++) all += mid / Labor[i];
        if (all >= N) b = mid;
        else a = mid + 1;
    }
    cout << a
}