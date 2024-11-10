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
    for(auto v: graph[cur])
    {
        if(!low[v]) tarjan(v);
        if(onstack[v] && low[v]<low[cur])
        {
            low[cur]=low[v];
            changed[cur]=true;
        }
    }
    if(!changed[cur])
    {
        while(st.top()!=cur)
        {
            low[st.top()]=cur;
            onstack[st.top()]=false;
            st.pop();
        }
        onstack[cur]=false;
        st.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    for(int t=0; t<5; t++)
    {
        cin >> n >> m;
        graph.resize(m+1);
        for(int i=1; i<=m; i++) graph[i].clear();
        now=0;
        int arr[2*n];
        memset(changed,0,sizeof(changed));
        memset(low,0,sizeof(low));
        for(int i=0; i<2*n; i++) cin >> arr[i];
        for(int i=0; i<m/2; i++)
        {
            cin >> a >> b;
            opp[a]=b;
            opp[b]=a;
        }
    }
}