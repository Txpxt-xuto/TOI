/*
TASK: plantation.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> edge[100001],level[100001];
int ti[100001];
int vis[100001];
int n,k,t;
ll sm;
bool dfs(int cur) {
    if (vis[cur] == 1) {
        return 0;
    } else if (vis[cur] == 2) {
        return 1;
    }
    vis[cur] = 1;
    for (auto i:edge[cur]) {
        dfs(i);
    }
    vis[cur] = 2;
    return (++sm<=t);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> t;
    int x,r,s;
    for (int i=1;i<=n;i++) {
        cin >> x >> r;
        level[x].push_back(i);
        for (int j=0;j<r;j++) {
            cin >> s;
            edge[i].push_back(s);
        }
    }
    bool c=false;
    sm=0;
    memset(vis,0,sizeof vis);
    c=false;
    int i;
    for (i=1;i<=k;i++) {
        for(auto j:level[i])
        {
            if (!dfs(j)) {
                c=true;
                break;
            }
        }
        if(c) break;
            
    }
    cout << ((i==1)?-1:i-1);
}
/*
#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,k,N,K,T,x,y,z=0;
    scanf("%d %d %d",&N,&K,&T);
    int L[N],P[N],q[N][100];
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&L[i],&P[i]);
        for(j=0;j<P[i];j++) scanf("%d",&q[i][j]);
    }
    for(i=0;i<N;i++)
    {
        if(L[i]==1&&P[i]==0)
        {
            z++;
            break;
        }
        else if(L[i]==1&&P[i]!=0) printf("-1");
    }
    if(z==1)
    {
        T=T-1;
        for(x=0;x<N;x++)
        {
            for(y=0;y<P[x];y++)
            {
                for(i=0;i<N;i++)
                {
                    for(j=0;j<P[i];j++)
                    {
                        if(T==0)
                        {
                            printf("%d",x);
                            x=N-1;
                            i=N-1;
                        }
                        else if(q[x][y]==q[i][j]) T+=-1;
                    }
                }
            }
        }
    }
}*/