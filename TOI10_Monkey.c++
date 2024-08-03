/*
TASK: monkey.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct A 
{
    int h, i;
    bool operator < (const A& o) const 
    {
        if (h != o.h) return h < o.h;
        return i < o.i;
    }
} stick[1001000];
int a[200200];
int main() 
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n, k;
    cin >> m >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= k;i++) cin >> stick[i].i >> stick[i].h;
    sort(stick + 1, stick + 1 + k);
    for (int i = k;i >= 1;i--) swap(a[stick[i].i], a[stick[i].i + 1]);
    int s;
    cin >> s;
    int ans_not_use = a[s];
    int ans_use = max(a[s - 1], a[s + 1]);
    for (int i = 1;i <= k;i++) 
    {
        swap(a[stick[i].i], a[stick[i].i + 1]);
        if (s == stick[i].i) s = stick[i].i + 1;
        else if (s == stick[i].i + 1) s = stick[i].i;
        ans_use = max({ ans_use, a[s - 1] });
        ans_use = max({ ans_use, a[s + 1] });
    }
    if (ans_not_use > ans_use) cout << ans_not_use << "\nNO";
    else cout << ans_use << "\nUSE";
    return 0;
}