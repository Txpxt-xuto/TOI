/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> edge[100001],level[100001];
int ti[100001];
int vis[100001];
int n,k,t;
ll sm;
bool dfs(int cur){
    if(vis[cur] == 1) return 0;
    else if(vis[cur] == 2) return 1;
    vis[cur] = 1;
    for (auto i:edge[cur]) dfs(i);
    vis[cur] = 2;
    return (++sm<=t);
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> t;
    int x, r, s, i, j;
    for(i=1;i<=n;i++)
	{
        cin >> x >> r;
        level[x].push_back(i);
        for(j=0;j<r;j++)
}