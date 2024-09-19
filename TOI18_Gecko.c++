#include<bits/stdc++.h>
using namespace std;
#define iii tuple<int,int,int>
#define pii pair<int,int>
const int N = 2e4+5;
const int M = 2e5+5;
const int INF = 1e9+7;
vector<iii> g[N];
int n,m,k,p,cnt = 1;
int dist[N],gecko[N],to[N];
iii edge[M];
bool vis[M];
set<pii> ss;
