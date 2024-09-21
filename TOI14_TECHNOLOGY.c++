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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    vector<vector<int>> a;
    for(i = 0 ; i < m ; i++)
    {
        int x,s,e;
        int s2 = 0, s3 = 0, s5 = 0, s7 = 0;
        cin >> x >> s >> e;
        while(x%2==0)
        {
            s2++;
            x /= 2;
        }
        while(x%3==0)
        {
            s3++;
            x /= 3;
        }
        while(x%5==0)
        {
            s5++;
            x /= 5;
        }
        while(x%7==0)
        {
            s7++;
            x /= 7;
        }
        a.push_back({s,s2,s3,s5,s7});
        a.push_back({e+1,-s2,-s3,-s5,-s7});
    }
    sort(a.begin(),a.end(),[](auto& x, auto& y)
    {
        return x[0] < y[0];
    });
    ll ans = 0;
    int cnt = 0,top = 0;
    ll s2 = 1, s3 = 1, s5 = 1, s7 = 1;
    for(i = 0;i<n;i++)
    {
        while(top < a.size() && i >= a[top][0])
        {
            s2 += a[top][1];
            s3 += a[top][2];
            s5 += a[top][3];
            s7 += a[top][4];
            top++;
        }
        ll c = s2*s3*s5*s7;
        if(c > ans)
        {
            ans = c;
            cnt = 1;
        }
        else if(c == ans) cnt++;
    }
    cout << ans << ' ' << cnt;
}