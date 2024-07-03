#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define int long long
int n,m,k,tmp,i;
vector<int> e;

bool solve(int mid){
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum=0,cnt=0;
    for(int i=0;i<n;++i)
    {
        sum+=e[i];
        pq.push(e[i]);
        if(pq.size()>k)
        {
            sum-=pq.top(); 
            pq.pop();
        }
        if(sum>=mid && pq.size()==k)
        {
            ++cnt;
            sum=0;
            while(!pq.empty()) pq.pop();
        }
    }
    return cnt>=m;
}
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for(i=0;i<n;++i)
    {
        cin >> tmp;
        e.push_back(tmp);
    }
    int l=0,r=1e18;
    int ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(solve(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
  cout << ans;
}