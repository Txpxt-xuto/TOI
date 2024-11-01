/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
struct A{
    long long x,y,z,i,j,k;
}store[20];


ll want=0,mn=1e18,n;
bitset<20>vis;
long long calcdis(int ii,int jj){
    return (store[ii].x-store[jj].x)*(store[ii].x-store[jj].x)+(store[ii].y-store[jj].y)*(store[ii].y-store[jj].y)+(store[ii].z-store[jj].z)*(store[ii].z-store[jj].z);
}
void fly(ll dis,int cur,int i,int j,int k){
    if(i>=want && j>=want && k>=want)
    {
        mn = min(dis,mn);
        return;
    }
    for(int o=1;o<=n;o++)
    {
        if(vis[o]) continue;
        vis[o]=1;
        fly(calcdis(cur,o)+dis,o,i+store[o].i,j+store[o].j,k+store[o].k);
        vis[o]=0;
    }
}
void solve(){
    int stx,sty,stz,i;
    cin >> want >> stx>>sty>>stz;
    cin>>n;
    store[0] = {stx,sty,stz,0,0,0};
    for(i=1;i<=n;i++)
    {
        cin >> store[i].x>>store[i].y>>store[i].z;
        cin >> store[i].i>>store[i].j>>store[i].k;
    }
    fly(0,0,0,0,0);
    cout << mn;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q=1;
    while(q--)solve();;
    return 0;
}