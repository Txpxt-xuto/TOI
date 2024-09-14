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
		if(visited2[tmp.en])continue;
		visited2[tmp.en] = true;
		dis2[tmp.en]=tmp.w;
		if(tmp.en==en){
			return;
		}
		for(auto x:graph2[tmp.en]){
			pq.push({x.en,x.w+tmp.w});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		ll x;cin >> x;
		fuel.push_back(x);
	}
	cin >> st >> en >> tk >> m;
	while(m--){
		ll st1,en1,w;cin >> st1 >> en1 >> w;
		graph[st1].push_back({en1,w*fuel[st1-1]});
		graph[en1].push_back({st1,w*fuel[en1-1]});
		graph2[st1].push_back({en1,w*fuel[en1-1]});
		graph2[en1].push_back({st1,w*fuel[st1-1]});
	}
	stp(st);
	stp2(st);
	cout << min(dis[en],dis2[en]);
	return 0;	
}