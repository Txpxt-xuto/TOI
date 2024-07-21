
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
tuple<int,int,int,int> prime[11] = {{0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},{0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0},{1,0,1,0}};
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,i,s,e;
    vector<pair<long long,int>> num;
    int m,x;
    cin >> n >> m;
    for(i=0;i<n;i++) 
    {
        cin >> x >> s >> e;
        num.push_back({s,x});
        num.push_back({e+1,-x});
    }
    sort(num.begin(),num.end());
    long long maxi=0,t,amt=0;
    tuple<long long,long long,long long,long long> curr = {1,1,1,1};
    n = num.size();
    long long currpos=0;
    for(auto i : num) 
    {
        if(i.f != currpos) 
        {
            t = get<0>(curr)*get<1>(curr)*get<2>(curr)*get<3>(curr);
            if(t > maxi) 
            {
                if (i.f-currpos == 0) continue;
                amt = i.f-currpos;
                maxi = t;
            } 
            else if(t == maxi) 
            {
                if(i.f-currpos == 0) continue;
                amt += i.f-currpos;
            }
        }
        if(i.s > 0) 
        {
            get<0>(curr) += get<0>(prime[i.s]);
            get<1>(curr) += get<1>(prime[i.s]);
            get<2>(curr) += get<2>(prime[i.s]);
            get<3>(curr) += get<3>(prime[i.s]);
        } 
        else 
        {
            get<0>(curr) -= get<0>(prime[-i.s]);
            get<1>(curr) -= get<1>(prime[-i.s]);
            get<2>(curr) -= get<2>(prime[-i.s]);
            get<3>(curr) -= get<3>(prime[-i.s]);
        }
        currpos = i.f;
    }
    cout << maxi << ' ' << amt;
}