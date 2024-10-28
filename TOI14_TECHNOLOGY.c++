/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
map<vector<pair<int,int>> , int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,q;
    cin >> t >> q;
    while(t--)
    {
        int m;
        cin >> m;
        m--;
        vector<pair<int,int>> vec;
        while(m--)
        {
            int u,v;
            cin >> u >> v;
            vec.emplace_back(min(u,v),max(u,v));
        }
        sort(vec.begin(),vec.end());
        mp[vec]++;
    }
    while (q--)
    {
        int m;
        cin >> m;
        m--;
        vector<pair<int,int>> vec;
        while(m--)
        {
            int u,v;
            cin >> u >> v;
            vec.emplace_back(min(u,v),max(u,v));
        }
        sort(vec.begin(),vec.end());
        cout << mp[vec] << '\n';
    }
    
}