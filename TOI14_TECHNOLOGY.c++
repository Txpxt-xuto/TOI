/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <cstdio>
#include <algorithm>
#include <tuple>
using namespace std;
int x[4][1500], y[4][1500];
tuple<int,int,int> v[2250000], tg, *itr;
signed main()
{
	int xt, yt, n, m = 0, i, j;
    scanf("%d %d %d", &xt, &yt, &n);
	for(t=0;t<4;++t)
    {
		for(i=0;i<n;++i) scanf("%d %d", &x[t][i], &y[t][i]);
	}
	for(i=0;i<n;++i)
    {
		for(j=0;j<n;++j) v[m++] = make_tuple(x[0][i] + x[1][j], y[0][i] + y[1][j], i);
	}
	sort(v, v+m); 
	for(i=0;i<n;++i)
	{
	}
}