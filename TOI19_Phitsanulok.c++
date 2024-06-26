#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
struct A{
    int u,w;
    bool operator < (const A&o)const{
        return w>o.w;
    }
};
vector<pair<int,int>> dp[1<<20];
int qwerty[1<<20];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,s,i,j,x;
    cin >> n >> s;
    memset(qwerty,0x3f,sizeof qwerty);
    priority_queue<A> pq;
    pq.push({0,0});
        qwerty[0]=0;
    for(j=1;j<=n;j++)
    {
        int a=0,w;
        cin >> w;
        int p=0;
        for(i=0;i<s;i++)
        {
            cin >> x;
            if(x==-1) p|=1<<i;
            else if(x==1) a|=1<<i;
        }
        dp[p].push_back({a,w});
    }
    int ans=0;
    while(!pq.empty())
    {
        int u = pq.top().u;
        int w =pq.top().w;
        pq.pop();
        if(qwerty[u]<w) continue;
        for(auto e : dp[u])
        {
        ans = max(ans,w);
            if(qwerty[e.first]>e.second+w)
            {
                qwerty[e.first]=w+e.second;
                pq.push({e.first,e.second+w});
            }
        }
        for(i=0;i<s;i++)
        {
            if(u&(1<<i) && qwerty[u^(1<<i)]>w)
            {
                qwerty[u^(1<<i)] = w;
                pq.push({u^(1<<i),w});
            }
        }
    }
    cout << ans;
    return 0;
} 