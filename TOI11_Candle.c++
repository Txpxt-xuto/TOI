/*
TASK: candle.cpp
LANG: C++
AUTHOR: YourName YourLastName
CENTER: YourCenter
*/ 
#include<bits/stdc++.h>
using namespace std;
int n,m;
char arr[2000][2000];
int cnt;
int di[8]={-1,-1,0,1,1,1,0,-1};
int dj[8]={0,1,1,1,0,-1,-1,-1};
queue<pair<int,int>> q;
bool issafe(int i,int j){
    if(i<0 or i>=n or j<0 or j>=m)return false;
    if(arr[i][j]=='0')return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(arr[i][j]=='1')
            {
                arr[i][j]='0';
                ++cnt;
                q.emplace(i,j);
                while(!q.empty()){
                    int ii=q.front().first;
                    int jj=q.front().second;
                    q.pop();
                    for(int k=0;k<8;++k){
                        int ni=ii+di[k];
                        int nj=jj+dj[k];
                        if(issafe(ni,nj)){
                            arr[ni][nj]='0';
                            q.emplace(ni,nj);
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}