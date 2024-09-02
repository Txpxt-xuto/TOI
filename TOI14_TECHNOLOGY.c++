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
    vis[cur] = 1;edge[cur]) d