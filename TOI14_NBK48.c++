/*
TASK: nbk48.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int num[100010];
pair<int, int> adj[100010];
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, i;
    cin >> n >> q;
    for(i=1;i<=n;i++) 
    {
        cin >> adj[i].first;
        adj[i].first += adj[i - 1].first;
        adj[i].second = i;
    }
    sort(adj + 1, adj + 1 + n);
    for(i=1;i<=n;i++) 
    {
        num[i] = adj[i].first;
        adj[i].second = max(adj[i - 1].second, adj[i].second);
    }
    for(i=1;i<=q;i++) 
    {
        int bud;
        cin >> bud;
        int upper = upper_bound(num + 1, num + 1 + n, bud) - (num + 1);
        cout << adj[upper].second << "\n";
    }
}
