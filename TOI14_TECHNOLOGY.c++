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
void stp(ll st)
{
	dis.assign(109,INT_MAX);
	priority_queue<edge> pq;
	visited[st]=true;
	for(auto x:graph[st]) pq.push(x);
	while(!pq.empty())
    {
		edge tmp = pq.top();
		pq.pop();
		if(visited[tmp.en]) continue;
		visited[tmp.en] = true;
		dis[tmp.en]=tmp.w;
		if(tmp.en==en) return;
		for(auto x:graph[tmp.en]) pq.push({x.en,x.w+tmp.w});
	}
}
void stp2(ll st)
{
	dis2.assign(109,INT_MAX);
	priority_queue<edge> pq;
	visited2[st]=true;
	for(auto x:graph2[st]) pq.push(x);
	while(!pq.empty())
    {
		edge tmp = pq.top();
		pq.pop();
		if(visited2[tmp.en]) continue;
		visited2[tmp.en] = true;
		dis2[tmp.en]=tmp.w;
		if(tmp.en==en) return;
		for(auto x:graph2[tmp.en]) pq.push({x.en,x.w+tmp.w});
	}
}
