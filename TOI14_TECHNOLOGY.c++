/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
using pii = pair<int,int>;
int par[3001],n,m,q,sum = 0,i;
int find(int a){
    return par[a] = (a == par[a]) ? a : find(par[a]);
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>n>>m;
    priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
    for(i=0;i<n;++i) par[i] = i;
    for(i=0;i<m;++i)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(d == 1) par[find(a)] = find(b);
        else pq.push({c,a,b});
    }
    cin >> q;
    multiset<pair<int,int>> mt;
    while(!pq.empty())
        auto [c,a,b] = pq.top();
        pq.pop();
        if(