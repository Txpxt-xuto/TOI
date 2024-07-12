/*
TASK: beehive.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <limits.h>
#define ll long long int
using namespace std;
int main()
{
    int n, m, t, i, j ,k, d;
    for(d=0;d<2;d++)
    {
        int mx = 1;
        cin >> n >> m >> t;
        vector<vector<int>> map(n + 1, (vector<int>(m + 1, 0)));
        vector<vector<int>> dp(n + 1, (vector<int>(m + 1, 0)));
        for(i=0;i<t;i++)
        {
            int x, y;
            cin >> x >> y;
            map[x + 1][y + 1] = 1;
   