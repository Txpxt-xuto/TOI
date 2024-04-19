#include <bits/stdc++.h>
using namespace std;
int a[5001],ans=0,n,dp[5001][5001],eatt[5001][5001];
int eat(int l,int r){
   if(l==r){return a[l];}
   if(eatt[l][r]>0){return eatt[l][r];}
   return eatt[l][r] =  abs(a[l]-a[r]) + max(a[l]+eat(l+1,r),a[r]+eat(l,r-1));
}
int cut(int l,int r){
    if(l>=r)return 0;
    if(dp[l][r]>0)return dp[l][r];
    
    int mx=eat(l,r);
    for(int k=l;k<r;k++){
        mx = max(mx, cut(l,k) + cut(k+1,r));
    }
    return dp[l][r]=mx;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];}
    cout<<cut(1,n);
}