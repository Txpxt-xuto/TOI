/*
TASK: wheel.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include<bits/stdc++.h>
using namespace std;
int n,x;
string s[15];
long long sz[15], arr[15], mn = LLONG_MAX;
void f(int idx, long long cnt)
{
    if(idx == n+1 && cnt)
    { 
        mn = min(mn, cnt); 
        return; 
    }
    for(long long i = 0; i < arr[idx] && cnt+i < mn; i += arr[idx-1]) 
    {   
        if(s[idx][(cnt+i) % sz[idx]] - '0' == x) 
        {
            f(idx+1, cnt+i);
        }
    }
        
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> x;
    arr[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        sz[i] = s[i].size();
        arr[i] = (arr[i-1]*sz[i])/__gcd(arr[i-1], sz[i]);
    }
    f(1, 0);
    cout << mn;
}