/*
TASK: beehive.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second

pair<int,int>dp[5050][5050];
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin >> x;
            if(i==1)dp[i][j]={x,1};
            else{
                if((i%2==1)&&j==1||(i%2==0)&&j==m)dp[i][j]=dp[i-1][j];
                else{
                    if(i%2==1){
                        if(dp[i-1][j].f!=dp[i-1][j-1].f)dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
                        else {
                            dp[i][j]=dp[i-1][j];
                            dp[i][j].s+=dp[i-1][j-1].s;
                        }
                    }
                    else{
                        if(dp[i-1][j].f!=dp[i-1][j+1].f)dp[i][j]=max(dp[i-1][j],dp[i-1][j+1]);
                        else {
                            dp[i][j]=dp[i-1][j];
                            dp[i][j].s+=dp[i-1][j+1].s;
                        }
                    }
                }
                dp[i][j].f+=x;
            }
        }
    }
    pair<int,int>ans={0,0};
    for(int i=1;i<=m;i++){
        if(dp[n][i].f>ans.f) ans=dp[n][i];
        else if(dp[n][i].f==ans.f) ans.s+=dp[n][i].s;
    }
    cout << ans.f << " " << ans.s;
    return 0;