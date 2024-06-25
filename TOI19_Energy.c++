#include<bits/stdc++.h>
using namespace std;
#define int long long
int qs[310];
int dp[10][310][310];
int vis[10][310][310];
int k,d;
int MOD = 1e9+7;
int play(int lv,int l,int r){
    if(l>r)return 0;
    if(lv==k)return 1;
    if(l==r)return 0;
    if(vis[lv][l][r]){
        return dp[lv][l][r];
    }
    vis[lv][l][r]=1;
    int cnt = 0;
    for(int  i= l;i<=r;i++){
        if(abs(qs[r]-qs[i]*2+qs[l-1])<=d){
            cnt=(cnt+(play(lv+1,l,i)*play(lv+1,i+1,r))%MOD)%MOD;
        }
    }
    dp[lv][l][r]=cnt;
    return cnt;
}
int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n>> k >> d;
    for(int i = 1;i<=n;i++){
        cin>>qs[i];
        qs[i]+=qs[i-1];
    }
    cout << play(1,1,n);
}