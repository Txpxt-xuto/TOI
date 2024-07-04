/*
TASK: metaverse1
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define st first
#define nd second
const int NN=2e5+10;
pii tt[NN],ed[NN];
int ans[18][NN];
int cal(pii a,pii b){
    return abs(a.st-b.st)+abs(a.nd-b.nd);
}
int main(){
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    tt[0]={1,1},ed[0]={1,1}; tt[k+1]={n,m},ed[k+1]={n,m};
    for(int i=1;i<=k;i++){
        cin>>tt[i].st>>tt[i].nd>>ed[i].st>>ed[i].nd;
    }
    for(int i=0;i<=k+1;i++) ans[0][i]=cal(tt[0],tt[i]);
    for(int i=1;i<=p;i++){
        for(int j=0;j<=k+1;j++){
            ans[i][j]=ans[i-1][j];
            for(int temp=0;temp<=k+1;temp++){
                ans[i][j]=min(ans[i][j],ans[i-1][temp]+cal(ed[temp],tt[j]));
            }
        }
    }
    // cout<<-1;
    int mn=INT_MAX,mxt;
    for(int i=p;i>=0;i--){
        // cout<<i<<" "<<ans[i][k+1]<<"\n";
        if(ans[i][k+1]<=mn){
            mxt=i;
            mn=ans[i][k+1];
        }
    }
    cout<<mn<<" "<<mxt;
}