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