#include<bits/stdc++.h>

using namespace std;
vector<int> memo;
int find(int n) {
    if (memo[n] == n) return n;
    return memo[n] = find(memo[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int b,e;
    cin >> b >> e;
    memo.resize(b);
    for (int i = 0 ; i < b ; i++) {
        memo[i] = i;
    }
    int count = 0;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    //vector<vector<int>> ans;
    for (int i = 0 ; i < e ; i++) {
        int src,dest,w,status;
        cin >> src >> dest >> w >> status;
        if (status == 0) pq.push({w,src,dest});
        else {
            int a = find(src);
            int b = find(dest);
            if (a != b) {
                memo[a] = b;
                count++;
            }
        }
    }
    vector<pair<int,int>> price;
    int p;
    cin >> p;
    for (int i = 0 ; i < p ; i++) {
        int x,y;
        cin >> x >> y;
        price.push_back({x,y});
    }
    sort(price.begin(),price.end(),[](auto& x,auto& y) {
        if (x.second == y.second)return x.first<y.first;
        return x.second < y.second;
    });
    int total = 0;
    while(!pq.empty() && count < b-1) {
        vector<int> top = pq.top();
        pq.pop();
        int w = top[0];
        int src = top[1];
        int dest = top[2];
        int a = find(src);
        int b = find(dest);
        if (a != b) {
            memo[a] = b;
            //ans.push_back({src,dest,w});
            count++;
            for (int i = 0 ; i < p ; i++) {
                if (w <= price[i].first) {
                    total += price[i].second;
                    break;
                }
            }
        }
    }
    printf("%d",total);
}