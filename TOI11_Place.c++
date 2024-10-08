/*
TASK: place.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <functional>
using namespace std;
int sz[200000], p[200000];
tuple<int,int,int> E[1000000];
int fp(int x){
    if(x == p[x]) return x; 
    return p[x] = fp(p[x]);
    }
signed main()
{
	int n, m, i; 
    scanf("%d %d", &n, &m);
	for(i=0;i<n;++i)
    {
        p[i] = i; 
        sz[i] = 1;
    }
	for(i=0;i<m;++i)
    {
		int u, v, w; 
        scanf("%d %d %d", &u, &v, &w); 
		E[i] = make_tuple(w-1, u-1, v-1);
	}
	sort(E, E+m, greater<std::tuple<int,int,int>>());
	long long MST = 0;
	for(i=0;i<m;++i)
    {
		int w, u, v;
        tie(w, u, v) = E[i];
		if(fp(u) != fp(v))
        {
			u = fp(u); 
            v = fp(v); 
            MST += w;
			if(sz[u] < sz[v]) swap(u, v);
			sz[u] += sz[v]; 
            p[v] = u;
		}
	}
	printf("%lld", MST);
}