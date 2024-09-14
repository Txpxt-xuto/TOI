/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[105];
int a[105],dp[105][2];


priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>> pq;

int main(){

    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    int n,s,e,box;
    
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    //cout<<"hi";
    cin>>s>>e>>box;
    int c;
    cin>>c;
    for(i=0;i<c;++i)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    pq.push({0,1,0,s});
    while(!pq.empty())
    {
        auto [x1,x2,x3,x4] = pq.top();
        pq.pop();
        int w=x1;
        for(i=x3;i<=box;++i)
        {
            for(j=0;j<v[x4].size();++j)
            {
                int a1=v[x4][j].first;
                int a2=v[x4][j].second;
                if(dp[a1][x2]>x1||i<a2)
                {
                    dp[a1][x2]=i;
                    pq.push({x1,x2,i,a1});
                }
                x1+=a[x4];
                if(x2||dp[a1][0]>w)
                {
                    dp[a1][0]=w;
                    pq.push({w,0,box,a1});
                }
            }
        }
    }
    cout << min(dp[e][0],dp[e][1]);
}