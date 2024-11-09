/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <double> adj[28][28];
vector <pair <int, double>> m[28];
bool broken = true;
vector <bool> visited(28, false);
vector <pair <int, pair <int, double>>> ans;
void dfs(int n)
{
    if(n == 27) broken = false;
    visited[n] = true;
    int size = m[n].size();
    int idx = 0, mn = INT_MAX;
    bool found = false;
    for(i=0;i<size;i++)
	{
        if(!visited[m[n][i].first] && m[n][i].second < mn)
		{
            idx = i;
            mn = m[n][i].second;
            found = true;
        }
    }
    if(found)
	{
        dfs(m[n][idx].first);
        if(!broken) ans.push_back({n, {m[n][idx].first, m[n][idx].second}});
    }
}
int32_t main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n,i,t;
    cin >> n;
    for(i=0;i<n;i++)
	{
        char ch1, ch2;
        int l;
        cin >> ch1 >> ch2 >> l;
        int a, b;
        if(ch1 == 'X') a = 0;
        else if(ch1 == 'Y') a = 27;
        else a = ch1 - 'a' + 1;
        if(ch2 == 'X') b = 0;
        else if(ch2 == 'Y') b = 27;
        else b = ch2 - 'a' + 1;
        adj[a][b].push_back(l);
        adj[b][a].push_back(l);
    }
    for(i=0;i<=27;i++)
	{
    }
}