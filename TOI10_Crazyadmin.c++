/*
TASK: crazyadmin.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#define ll long long int
#define f first
#define s second
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    int l = 0, r = 1e9;
    for(int i= 0 ; i < m ; i++) 
    {
        cin >> a[i];
        l = max(l,a[i]);
    }
    while(l<r) {
        int mid = (l+r)/2;
        int sum = 0;
        int cnt = 0;
        for (int i = 0 ; i < m ; i++){
            sum += a[i];
            if (sum > mid) {
                sum = a[i];
                cnt++;
            }
        }
        if(sum > 0) cnt++;
        if(cnt <= n) r = mid;
        else l = mid + 1;
    }
    cout << r;
}