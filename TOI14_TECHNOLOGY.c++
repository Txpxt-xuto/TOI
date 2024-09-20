/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
#define ll long long int
#define s second
#define f first
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    vector<vector<int>> a;
    for (int i = 0 ; i < m ; i++) {
        int x,s,e;
        int s2 = 0, s3 = 0, s5 = 0, s7 = 0;
        cin >> x >> s >> e;
        while(x%2==0) {
            s2++;
            x /= 2;
        }
        while(x%3==0) {
            s3++;
            x /= 3;
        }
        while(x%5==0) {
            s5++;
            x /= 5;
        }
        while(x%7==0) {
            s7++;
            x /= 7;
        }
        a.push_back({s,s2,s3,s5,s7});
        a.push_back({e+1,-s2,-s3,-s5,-s7});
    }

    sort(a.begin(),a.end(),[](auto& x, auto& y) {
        return x[0] < y[0];
    });
    ll ans = 0;
    int cnt = 0;
    int top = 0;
    ll s2 = 1, s3 = 1, s5 = 1, s7 = 1;
    for (int i = 0 ; i < n ; i++) {
        while(top < a.size() && i >= a[top][0]) {
            s2 += a[top][1];
            s3 += a[top][2];
            s5 += a[top][3];
            s7 += a[top][4];
            top++;
        }
        ll c = s2*s3*s5*s7;
        if (c > ans) {
            ans = c;
            cnt = 1;
        } else if (c == ans) {
            cnt++;
        }
    }
    /*for (int i = 0 ; i < m ; i++) {
        cout << a[i].first << ' ' << a[i].second.first << ' ' << a[i].second.second << endl;
    }*/

    /*for (int i = 0 ; i < n ; i++) {
        power.clear();
        power.resize(8,1);
        for (int j = 0 ; j < m ; j++) {
            if (i < a[j].s.f) break;
            if (i >= a[j].s.f && i <= a[j].s.s) {
                if (a[j].f == 4) power[2]+=2;
                else if (a[j].f == 6) {
                    power[2]++;
                    power[3]++;
                } else if (a[j].f == 8) power[2] += 3;
                else if (a[j].f == 9) power[3] += 2;
                else if (a[j].f == 10) {
                    power[2]++;
                    power[5]++;
                } else power[a[j].f]++;
            }
        }
        int c = 1;
        //cout << i << " : ";
        for (int j = 2 ; j < 8 ; j++) {
            c *= power[j];
            //cout << power[j] << ' ';
        }
        //cout << endl;
        if (c > ans) {
            ans = c;
            cnt = 1;
        } else if (c == ans) {
            cnt++;
        }
    }*/
    cout << ans << ' ' << cnt;
}
