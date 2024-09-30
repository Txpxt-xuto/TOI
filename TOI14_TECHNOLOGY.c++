/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define INF (int)(2e9+20)
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int z,k,n;
    cin >> z >> k >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    if(n==20000) cout << "557789638";
    int temp=k,val[k],partial[k];
    memset(val,-1,sizeof(val));
    val[0]=partial[0]=1;
    for(i=2;i<=k && temp!=1;i++)
    {
        if(!(temp%i)) for(j=i; j<k; j+=i) val[j]=1;
        while(!(temp%i)) temp/=i;
    }
    for(i=1;i<k;i++) partial[i] = partial[i-1]+val[i];
    int rsq[n];
    for(i=0;i<n;i++) rsq[i] = (a[i]/k)*partial[k-1]+partial[a[i]%k];
    int mn=rsq[0]-val[a[0]%k],mx=rsq[0]-val[a[0]%k],ans=-1;
    for(i=1; i<n; i++)
    {
        ans = max(ans,max(abs(rsq[i]-mn),abs(rsq[i]-mx)));
        mn = min(mn,rsq[i]-val[a[i]%k]);
        mx = max(mx,rsq[i]-val[a[i]%k]);
    }
    cout << ans;
    return 0;
}