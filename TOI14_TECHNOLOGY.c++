/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define MAXM 200010
using namespace std;
int n,m,now,opp[MAXM],low[MAXM];
vector<set<int>> graph;
stack<int> st;
bool changed[MAXM],onstack[MAXM];
void tarjan(int cur)
{
    low[cur]=++now;
    onstack[cur]=true;
    st.push(cur);
}