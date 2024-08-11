/*
TASK: cablecar.cpp
LANG: C++
AUTHOR: YourName YourLastName
CENTER: YourCenter
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
struct edge
{
	int st;
	int en;
	int we;
	bool operator<(const edge &x)const
    {
	return x.we > we;
	}
};
vector <edge> v;
int head[2600];
void addedge(int st,int en,int we)
{
	v.push_back({st,en,we});
}

int findhead(int n)
{
	if(head[n]==n) return n;
	else return findhead(head[n]);
}

void merge(int st,int en)
{
	int x1 = findhead(st);
	int x2 = findhead(en);
	
	if(x1 < x2) head[x1]=x2;
	else head[x2]=x1;
}
int n,m,ans=0;
void krukal(int sta,int ens)
{
	for(int i=1;i<=n;i++) head[i]=i;
	priority_queue <edge> pq;
	for(auto x: v) pq.push(x);
	while(!pq.empty())
    {
		edge temp = pq.top();
		pq.pop();
		if(head[temp.st]!=head[temp.en]){
			merge(temp.st,temp.en);
			if(findhead(sta)==findhead(ens)){
				ans = temp.we;
				break;
			}
		}
	}
}
double people;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int st,en,we;
		scanf("%d %d %d",&st,&en,&we);
		addedge(st,en,we);
	}
	int stx,enx;
	scanf("%d %d %lf",&stx,&enx,&people);
	krukal(stx,enx);
	int an = ceil(people/(ans-1));
	printf("%d",an);
}