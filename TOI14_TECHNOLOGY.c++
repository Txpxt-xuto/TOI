/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long pw[1000100];
int main() {
  scanf("%lld %lld", &m, &n);
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &pw[i]);
  }
  long long l = 1, r = 1000000LL * n;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long all = 0;
    for(i = 1; i <= m; i++) all += mid / pw[i];
    if (all >= n)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld", l);
  return 0;
}
