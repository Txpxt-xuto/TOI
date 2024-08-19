#include <bits/stdc++.h>
using namespace std;
int n; string a;
int dp[3][256][256];
bool mcm(int i, int j, int want){
    if(i==j)
        return (a[i]-'0'==want);
    if(dp[want][i][j]!=-1) return dp[want][i][j];
    if(want==0)
    {
        for(int k=i;k<j;k++)
        {
            if(mcm(i,k,0) && mcm(k+1,j,2))return dp[want][i][j] = 1;
        }
    }
    else if(want==2)
    {
        for(int k=i;k<j;k++)
        {
            if(mcm(i,k,0) && mcm(k+1,j,0))return dp[want][i][j] = 1;
            else if(mcm(i,k,1) && mcm(k+1,j,0))return dp[want][i][j] = 1;
            else if(mcm(i,k,2) && mcm(k+1,j,1))return dp[want][i][j] = 1;
        }
    }else { //if(want ==1)
        for(int k=i;k<j;k++){
        if(mcm(i,k,0) && mcm(k+1,j,1))return dp[want][i][j] = 1;
        else if(mcm(i,k,1) &&((mcm(k+1,j,1))||(mcm(k+1,j,2))))return dp[want][i][j] = 1;
        else if(mcm(i,k,2) && ((mcm(k+1,j,0))||(mcm(k+1,j,2))))return dp[want][i][j] = 1;}
    }
return  dp[want][i][j]=0;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    for(int loop=0;loop<20;loop++){
        cin >> n >> a;
    if(a[0]=='0'){
        if(n==1){cout<<"yes\n"; continue;}
        else if(memset(dp,-1,sizeof(dp));
            mcm(0,n-1,0)){cout<<"yes\n"; continue;}
    }
    cout<<"no\n";
    }
}