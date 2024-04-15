/*
TASK: art.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vvi vector<vi>
#define vp vector<pii>
using namespace std;
const int N=1e6+5;
int fw[N]{0};

void add(int i,int amt)
{
    for(;i<N;i+=i&-i) fw[i]+=amt;
}

int qr(int i,int res=0)
{
    for(;i;i-=i&-i) res+=fw[i];
    return res;
}

int getl(int t)
{
    int l=1,r=N-1;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(qr(m)<=t) r=m;
        else l=m+1;
    }
    return l;
}

int getr(int t)
{
    int l=1,r=N-1;
    while(l<r)
    {
        int m=(l+r)>>1;
        if(qr(m)<t) r=m;
        else l=m+1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,t;
    cin >> n >> t;
    vector<pair<int,pii>>v;
    for(int i=0;i<n;i++)
    {
        int s,h,w,o;cin>>s>>h>>w>>o;
        v.pb({s,{h,o}});
        v.pb({s+w,{h,-o}});
    }
    sort(all(v));int ans=0;
    for(int i=0;i<v.size()-1;i++)
    {
        add(1,v[i].s.s);
        add(1+v[i].s.f,-v[i].s.s);
        ans+=(v[i+1].f-v[i].f)*(getr(t)-getl(t));
    }
    cout << ans;
}
