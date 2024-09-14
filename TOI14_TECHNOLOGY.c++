/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct edge
{
	ll en,w;
	bool operator<(const edge&x)const
    {
		return w>x.w;
	}
};
ll n,m,st,en,tk;
vector<edge> graph[109],graph2[109];
vector<ll> dis,dis2,fuel;
bool visited[109],visited2[109];