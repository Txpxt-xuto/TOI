#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
int n,s,power,bit,potion,poison,d[1100005],u;
vector<pair<int,int> > v[1100005];
vector<int> blue;
priority_queue<pair<int,int> > pq;
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&power);
        potion=0,poison=0;
        for(int j=0;j<s;j++)
        {
            scanf("%d",&bit);
            if(bit==-1)poison|=(1<<j);
            if(bit==1)potion|=(1<<j);
        }
        blue.pb(poison);
        v[poison].pb({potion,power});
    }
    /*for(int i=0;i<=3;i++)
    {
        printf("%d\n",i);
        for(int j=0;j<v[i].size();j++)
        {
            printf("%d %d\n",v[i][j].X,v[i][j].Y);
        }
        printf("\n");
    }*/
    for(int i=0;i<=1100000;i++)d[i]=1e9;
    d[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int dist=-pq.top().X;
        u=pq.top().Y;
        pq.pop();
        if(dist>d[u])continue;
        for(auto [y,w]:v[u])
        {
            if(dist+w<d[y])
            {
                d[y]=dist+w;
                pq.push({-d[y],y});
            }
        }
        for(int i=0;i<s;i++)
        {
            if(((1<<i)|u)==u)
            {
                int y=(u^(1<<i));
                if(dist<d[y])
                {
                    d[y]=dist;
                    pq.push({-d[y],y});
                }
            }
        }
    }
    int mx=-1e9;
    for(auto node:blue) if(d[node]!=1e9) mx=max(mx,d[node]);
    printf("%d\n",mx);
}