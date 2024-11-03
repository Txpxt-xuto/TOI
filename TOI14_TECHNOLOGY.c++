/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long
#define pii pair <int,int>
#define pipii pair <int,pii>
#define f first
#define s second
const int N=1005;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int n,m,sum,mx,a[N][N],sy,sx;
bool vis[N][N];
priority_queue <pipii,vector<pipii>,greater<pipii>> pq;

void slove(){
    while(!pq.empty()) pq.pop();
    memset(a,0,sizeof(a));
    memset(vis,false,sizeof(vis));
    sum=mx=0;
    cin >> n >> m >> sy >> sx;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];
    pq.push({a[sy][sx],{sy,sx}});
    vis[sy][sx]=1;
    while(!pq.empty()){
        int d_u=pq.top().f,y=pq.top().s.f,x=pq.top().s.s;
        pq.pop();
        sum+=d_u;
        mx=max(mx,d_u);
        if(sum>=m){
            cout << mx << "\n";
            return ;
        }
        for(int i=0;i<4;i++){
            int yy=y+dy[i],xx=x+dx[i];
            if(yy<1 || yy>n || xx<1 || xx>n) continue;
            if(!vis[yy][xx]) pq.push({a[yy][xx],{yy,xx}}),vis[yy][xx]=1;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) slove();
}
