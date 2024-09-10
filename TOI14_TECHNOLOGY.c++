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
