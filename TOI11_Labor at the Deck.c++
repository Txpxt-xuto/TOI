#include <bits/stdc++.h>
using namespace std;
long long N, M;
long long Labor[1000100];
int main() 
{
    scanf("%lld %lld", &M, &N);
    for (int i = 1; i <= M; i++) scanf("%lld", &Labor[i]);
    long long l = 1, r = 1000000LL * N;
    while (l < r)
    {
        long long mid = (l + r) / 2;
        long long all = 0;
        for (int i = 1; i <= M; i++) all += mid / Labor[i];
        if (all >= N) r = mid;
        else l = mid + 1;
    }
    printf("%lld", l);
}