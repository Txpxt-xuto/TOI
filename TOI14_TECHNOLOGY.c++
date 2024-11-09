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
}