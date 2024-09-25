/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
const ll md=5000011;

ll pw[5000005] = {1};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s+=s;
    ll a = 0,mx = 1;
    for(i=0;i<n;i++)
    {
        mx = (mx << 1) % md;
        a = (a << 1) % md;
        if(s[i]=='1') a = (a + 1) % md;
    }
    ll b = a;
    for(i=0;i<n;i++)
    {
        b = (b << 1) % md;
        if(s[i] =='1')b=(b-mx+1+md)%md;
        if(a==b){
            cout<<(i+1);
            return 0;
        }
    }
}