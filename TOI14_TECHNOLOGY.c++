/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ppi=pair<int,pii>;
const int N=1e6+5;
int f[N];
vector<pii> a[N];
inline int fw(int i){
  int ans=0;
  for(;i;i-=i&-i){
    ans+=f[i];
  }
  return ans;
}
inline void up(int i,int x){
  for(;i<N;i+=i&-i){
    f[i]+=x;
  }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,t,mx=0;
    cin >> n >> t;
    for(int i=1;i<=n;i++)
    {
        int s,h,w,o;
        cin >> s >> h >> w >> o;
        mx=max(mx,s+w);
        a[s].push_back({o,h});
        a[s+w].push_back({-o,h});    
    }
    int chk=0,x,y,cnt=0;
    long long int ans=0;
    for(int i=1;i<=mx;i++)
    {
        if(a[i].size()==0) continue;
        ans+=(i-chk)*(cnt);    
        for(auto e:a[i])
        {
            int o=e.first;
            int h=e.second;
            up(1,o);
            up(h+1,-o);
        }
        int l=1,r=1e6;
        while(l<=r){
        int mid=(l+r)/2;
        if(fw(mid)>t) l=mid+1;
        else r=mid-1, x=mid;
        }
        l=1,r=1e6;
        while(l<=r){
            int mid=(l+r)/2;
            if(fw(mid)>t-1) l=mid+1;
            else r=mid-1,y=mid;
        }
	    cnt=y-x;
        chk=i;
    }
    cout << ans;
}