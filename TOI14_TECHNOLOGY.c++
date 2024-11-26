/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
using pii = pair<int,int>;
int par[3001],n,m,q,sum = 0,i;
int find(int a){
    return par[a] = (a == par[a]) ? a : find(par[a]);
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin>>n>>m;
    priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
    for(i=0;i<n;++i) par[i] = i;
    for(i=0;i<m;++i)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(d == 1) par[find(a)] = find(b);
        else pq.push({c,a,b});
    }
    cin >> q;
    multiset<pair<int,int>> mt;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        mt.insert({b,a});
    }
    while(!pq.empty())
    {
        auto [c,a,b] = pq.top();
        pq.pop();
        if(par[find(a)] != par[find(b)])
        {
            par[find(a)] = par[b];
            for(auto [y,x] : mt)
            {
                if(x >= c)
                {
                    sum+=y;
                    break;
                }
            }
        }
    }
    cout << sum;
}
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],n;

void quick(int p[],int l,int h){
//	cout << l << ' ' << h << "\n";
  if(l<h){
    int x=p[h],i=l-1;
    for(int j=l;j<h;j++){
      if(p[j]<x){
        i++;
        swap(p[i],p[j]);
      }
    }
    
    swap(p[i+1],p[h]);
    int xx=i+1;
    quick(p,l,xx-1);
    quick(p,xx+1,h);
  }
}


int main(){
  ios::sync_with_stdio(0); cin. tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
    b[i]=-b[i];
  }
    quick(a,0,n-1);
    quick(b,0,n-1);
    for(int i=0;i<n;i++) a[i]=a[i]-b[i];
    quick(a,0,n-1);
    int ans=0;
    for(int i=1;i<n;i++) ans+=a[i]-a[i-1];
    cout << ans;
}