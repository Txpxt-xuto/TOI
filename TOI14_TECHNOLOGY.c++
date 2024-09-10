/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n, r, d;
vector<pair<double, double>> vctor;
vector<pair<double, double>> lefts, rights;
double dist(pair<double, double> a, pair<double, double> b){
    return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}
double closest_pair(int l, int r)
{
    double mn = (double)1e18;
    if(r-l <= 2)
	{
        for(i=l;i<r;++i)
		{
            for(j=i+1;j<=r;++j) mn = min(mn, dist(vctor[i], vctor[j]));
        }
        return mn;}}