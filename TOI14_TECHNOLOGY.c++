/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll b,c,d,e,f,g,h,i,j,k,l,m,a,x,z,y,n,o,p,q,r,s,t,u,v,w;
ll Mn = LLONG_MAX;

struct pos
{
    ll X;
    ll Y;
    ll operator-(const pos x) const
    {
        return abs(X-x.X) + abs(Y-x.Y);
    }
} in[20002], out[20002];

ll BU[18][20002];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> w >> p;

    while(i++<w)
    {
        cin >> k >> x >> y >> z;
        in[i] = {k,x};
        out[i] = {y,z};
    }

    for(u=0;u<=p;u++)
        for(t=0;t<=w+1;t++)
            BU[u][t] = LLONG_MAX;

    in[0] = out[0] = {1,1};
    in[w+1] = out[w+1] = {n,m};

    for(u=0;u<=p;u++)
        for(f=0;f<=w+1;f++)
            for(t=0;t<=w+1;t++)
            {
                if(!u)
                    BU[0][f] = in[0] - in[f], t=w+1;
                else
                    BU[u][t] = min(BU[u][t], BU[u-1][f] + (out[f] - in[t]));
            }

    for(i=0;i<=p;i++)
        if(BU[i][w+1] < Mn)
        {
            Mn = BU[i][w+1];
            a = i;
        }

    cout << Mn << " " << a;
    return 0;
}