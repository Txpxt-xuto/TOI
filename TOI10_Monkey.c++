
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
int a[200001];
bitset<200001> vs;
vector<pair<int, int>> br;
int main () 
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int m, n, k; 
    cin >> m >> n >> k;
    for(i=1;i<=n;++i) cin >> a[i];
    for(i=0;i<k;++i) 
    {
        int pi, hi; 
        cin >> pi >> hi;
        br.emplace_back(hi, pi);
    }
    sort(br.begin(),br.end());
    int st;
    cin >> st;
    vs[st]=1;
    if(st>=2) vs[st-1]=1;
    if(st<=n-1) vs[st+1]=1;
    for(auto x : br)
    {
        bool t = vs[x.second];
        vs[x.second] = vs[x.second+1];
        vs[x.second+1] = t;
        if(x.second == st) st = x.second+1;
        else if(x.second+1 == st) st = x.second;
        if(st>=2) vs[st-1] = 1;
        if(st<=n-1) vs[st+1] = 1;
    }
    int mx = 0;
    for(i=1;i<=n;++i) if(vs[i]) mx = max(mx,a[i]);
    cout << mx << "\n" << (a[st]==mx ? "NO" : "USE");
}