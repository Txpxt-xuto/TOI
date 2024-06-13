#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500001, MOD = 1e9 + 7;
int i, j;
vector<vector<int>> graph(N);
ll parent[500001];
ll child[500001];
ll dfs(int u) {
    ll total = 1;
    for(int v : graph[u])
    {
        total *= child[u] * dfs(v);
        child[u]--;
        total %= MOD;
    }
    return total;
}
int main() 
{
    std::ios_base::sync_with_stdio(false) , cin.tie(NULL);
    int n , u, start, currentnode;
    cin >> n >> currentnode;
    start = currentnode;
    for(i=1;i<(2*n-1);i++)
    {
        cin >> u;
        if(u == parent[currentnode])
        {
            currentnode = u;
            continue;
        }
        parent[u] = currentnode;
        child[currentnode]++;
        graph[currentnode].push_back(u);
        currentnode = u;
    }
    cout << dfs(start);
    return 0;
}