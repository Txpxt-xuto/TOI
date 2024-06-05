#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n,ki=0; 
    cin >> n >> k;
    vector <int> h(n+2,0);
    for(int i=1;i<=n;++i) cin >> h[i];
    vector <int> gm;
    int ;
    while(i++<=n) 
    {
        if(h[i]>h[i-1] && h[i]>h[i+1])
        { 
            gm.push_back(h[i]); 
            i++;
        }
    }
    if(gm.empty()) 
    {
        cout << "-1"; 
        return 0;
    }
    sort(gm.begin(),gm.end());
    vector<int> rea;
    for(auto &x:gm) 
    {
        if(!rea.empty() && x==rea.back()) continue;
        rea.push_back(x);
    }
    if(k>rea.size()) 
    {
        for(auto &x:rea) cout << x << '\n';
        return 0;
    }
    for(int i=0;i<k;++i) 
    {
        cout << rea.back() << '\n';
        rea.pop_back();
    }
}