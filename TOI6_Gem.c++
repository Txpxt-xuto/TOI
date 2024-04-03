/*
TASK: gem
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int np[200100];
vector<int> adj[200100];
pair<int,int> space[100100];
int com[200100]={},go[200100]={},lowIn[200100]={},in=0,inSt[200100],comIndex;
stack<int> st;
void dfs(int a)
{
    st.push(a);
    go[a]=in;
    lowIn[a] = in;
    in++;
    inSt[a] = 1;
    for(auto np:adj[a])
    {
        if(go[np]==0)
        {
            dfs(np);
            lowIn[a] = min(lowIn[a],lowIn[np]);
        }
        else if(inSt[np]) lowIn[a] = min(lowIn[a],go[np]);
    }
    if(go[a] == lowIn[a])
    {
        while(st.top()!=a)
        {
            com[st.top()]=comIndex;
            inSt[st.top()] = 0;
            st.pop();
        }
        com[st.top()]=comIndex;
        inSt[st.top()] = 0;
        st.pop();
        comIndex++;
    }
}
void solve()
{
    int a,b,i,j,c,d,e;
    cin>>a>>b;
    in = 1;
    comIndex = 1;
    for(i=1;i<=b;i++)
    {
        go[i] = 0;
        com[i] = 0;
        inSt[i] = 0 ;
        lowIn[i] = 0;
    }
    while(st.size())
    {
        st.pop();
    }
    for(i=1;i<=a;i++)
    {
        cin>>c>>d;
        space[i].first = c;
        space[i].second = d;
    }
    for(i=0;i<b/2;i++)
    {
        cin>>c>>d;
        np[c] = d;
        np[d] = c;
    }
    for(i=1;i<=a;i++)
    {
        auto pa = space[i];
        adj[np[pa.first]].push_back(pa.second);
        adj[np[pa.second]].push_back(pa.first);
    }
    for(i=1;i<=b;i++)
    {
        if(com[i]==0) dfs(i);
    }
    for(i=1;i<=b;i++)
    {
        adj[i].clear();
    }
    for(i=1;i<=b;i++)
    {
        if(com[i] == com[np[i]])
        {
        cout<<'N';
        return ;
        }
    }
    cout<<'Y';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a=5;
    int np[200000];
    while(a--)
    {
        solve();
    }
}