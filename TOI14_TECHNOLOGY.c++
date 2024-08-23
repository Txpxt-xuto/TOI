/*
TASK: plantation.c
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
int n, k, t, x;
int main()
{
    scanf("%d %d %d", &n, &k, &t);
    vector<int> l(n + 5), p(n + 5), cnt(k + 5), deg(n + 5);
    vector<vector<int>> v(n + 5, vector<int>());
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &l[i], &p[i]);
        deg[i] = p[i]; cnt[l[i]]++;
        for(int j = 0; j < p[i]; j++) scanf("%d", &x), v[x].emplace_back(i);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++) if (!deg[i]) pq.emplace(cnt[l[i]], i);
    while (!pq.empty() && t--) {
        auto [nl, nn] = pq.top(); pq.pop();
        cnt[l[nn]]--;
        for (auto &e: v[nn]) {
            if (!(--deg[e])) pq.emplace(cnt[l[e]], e);
        }
    }
    if (cnt[1]) printf("-1"), exit(0);
    for (int i = 1; i <= k; i++) if (cnt[i]) printf("%d", i - 1), exit(0);
    printf("%d", k);
}/*
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