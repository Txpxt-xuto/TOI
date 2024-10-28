/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
map<vector<pair<int,int>> , int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,q;
    cin>>t>>q;
    while(t--){
        int m;
        cin>>m;
        m--;
        vector<pair<int,int>> vec;
        while(m--){
            int u,v;
            cin>>u>>v;
            vec.emplace_back(min(u,v),max(u,v));
        }
        sort(vec.begin(),vec.end());
        mp[vec]++;
    }
    while (q--){
        int m;
        cin>>m;
        m--;
        vector<pair<int,int>> vec;
        while(m--){
            int u,v;
            cin>>u>>v;
            vec.emplace_back(min(u,v),max(u,v));
        }
        sort(vec.begin(),vec.end());
        cout<<mp[vec]<<'\n';
    }
    
}
/*
3 2
10
1 2
6 4
2 5
3 5
8 6
2 7
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
5 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 