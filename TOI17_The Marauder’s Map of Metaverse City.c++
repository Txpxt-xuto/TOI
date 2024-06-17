#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll b,c,d,e,f,g,h,i,j,k,l,m,a,x,z,y,n,o,p,q,r,s,t,u,v,w;
ll Mn = LLONG_MAX;
ll inX[20002], outX[20002];
ll inY[20002], outY[20002];
ll BU[18][20002];
ll _abs(ll n)
{
    return (n<0)*-n + (n>0)*n;
}
int main()
{
    cin >> n >> m >> w >> p;

    while(i++<w)
        cin >> inX[i] >> inY[i] >> outX[i] >> outY[i];

    fill_n(BU[0],18*20002,Mn);

    inX[0] = outX[0] = inY[0] = outY[0] = 1;
    inX[w+1] = outX[w+1] = n;
    inY[w+1] = outY[w+1] = m;

    for(u=0;u<=p;u++)
        for(f=0;f<=w+1;f++)
        {
            BU[0][f] = _abs(inX[0] - inX[f]) + _abs(inY[0] - inY[f]);
            for(t=0;t<=w+1;t++)
            {
                BU[u][t] = min(BU[u][t], BU[u-1][f] + _abs(outX[f] - inX[t]) + _abs(outY[f] - inY[t]));
            }
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
