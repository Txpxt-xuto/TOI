/*
TASK: The Marauder’s Map of Metaverse City
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define pii pair <int,int>
#define f first
#define s second
const int N=2e4+5;
const int K=20;
const int INF=2e9;
int n,tk,d[K][N],mn=INF,cnt,i,j,k,t;
pii st={1,1},en,pos1[N],pos2[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill_n(d[0],K*N,INF);
    cin >> en.f >> en.s >> n >> tk;
    for(int i=1;i<=n;i++) cin >> pos1[i].f >> pos1[i].s >> pos2[i].f >> pos2[i].s;
    pos1[n+1]=en;
    for(i=1;i<=n+1;i++) d[0][i]=abs(1-pos1[i].f)+abs(1-pos1[i].s);
    for(t=1;t<=tk;t++)
    {
        for(k=1;k<=n;k++)
        {
            for(j=1;j<=n+1;j++)
            {
                d[t][j] = min(d[t][j],d[t-1][k]+abs(pos1[j].f-pos2[k].f)+abs(pos1[j].s-pos2[k].s));
            }
        }
    }
    for(i=0;i<=tk;i++) if(d[i][n+1]<mn) mn=d[i][n+1],cnt=i;
    cout << mn << " " << cnt;
}
