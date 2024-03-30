/*
TASK: labor.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
    ll N, M;
    ll Labor[1000001];
    scanf("%lld %lld", &M, &N);
    for (int i = 1; i <= M; i++) cin >> Labor[i];
    long long a = 1, b = 1e12;
    while (a < b)
    {
        long long mid = (a + b) / 2;
        long long all = 0;
        for (int i = 1; i <= M; i++) all += mid / Labor[i];
        if (all >= N) b = mid;
        else a = mid + 1;
    }
    cout << a;
    return 0;
}