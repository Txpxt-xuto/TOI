#include <bits/stdc++.h>
using namespace std;
int n, i, j;
double dis[100][100];
vector <int> adj[100], order;
vector <double> vec[100][100];
int par[100];
bool vis[100];
double ans=0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)
    {
        char c1,c2;
        double d;
        cin >> c1 >> c2 >> d;
        int a,b;
        if(c1=='X') a=0;
        if(c1=='Y') a=1;
        if(c2=='X') b=0;
        if(c2=='Y') b=1;
        if(c1>='a' && c1<='z') a=c1-'a'+2;
        if(c2>='a' && c2<='z') b=c2-'a'+2;
        vec[a][b].push_back(d);
        vec[b][a].push_back(d);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            if(!vec[i][j].empty())
            {
                sort(vec[i][j].begin(),vec[i][j].end());
                int sz=vec[i][j].size();
                if(vec[i][j].size()%2==1) dis[i][j] = vec[i][j][sz/2];
                else dis[i][j] = (vec[i][j][sz/2]+vec[i][j][(sz/2)-1])/2;
            }
        }
    }
    queue <int> q;
    q.push(0);
    par[0] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int v:adj[u])
        {
            if(vis[v]) continue;
            par[v] = u;
            q.push(v);
        }
    }
    int aa = 1;
    while(par[aa]!=-1)
    {
        order.push_back(aa);
        aa = par[aa];
    }
    order.push_back(0);
    reverse(order.begin(),order.end());
    if(!vis[1])
    {
        cout << "broken";
        return 0;
    }
    for(i=0;i<order.size()-1;i++)
    {
        int a = order[i],b=order[i+1];
        char cc1,cc2;
        if(a==0) cc1 = 'X';
        if(a==1) cc1 = 'Y';
        if(a>=2) cc1 = 'a'+a-2;
        if(b==0) cc2 = 'X';
        if(b==1) cc2 = 'Y';
        if(b>=2) cc2 = 'a'+b-2;
        cout << cc1 << " " << cc2 << " " << fixed << setprecision(1) << dis[a][b] << "\n";
        ans+=dis[a][b];
    }
    cout << ans;
}
