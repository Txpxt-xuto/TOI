/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t[1000001],m,n;
ll check(ll mid){
    ll work = 0;
    for(int i=0;i<m;++i) work += mid/t[i];
    return work >= n;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;++i) cin >> t[i];
    ll lo = 0,hi = (ll)1e12+1;
    while(lo<hi){
        ll mid = (lo+hi)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
    return 0;
}
/*
2 5
7
12

3 3
6
13
2