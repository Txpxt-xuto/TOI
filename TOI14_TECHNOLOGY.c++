/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <double> adj[28][28];
vector <pair <int, double>> m[28];
bool broken = true;
vector <pair <int, pair <int, double>>> ans;