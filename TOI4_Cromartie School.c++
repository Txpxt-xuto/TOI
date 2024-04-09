/*
TASK: SCHOOL
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
const int mxN = 70;
int n,m;
int sum[mxN][mxN];
char mp[mxN][mxN];
bool vis[mxN][mxN];
int di[] = {0,-1,0,1} , dj[] = {1,0,-1,0};

void bfs(int ssi,int ssj){
    queue<pair<int,int>> q;
    q.push({ssi,ssj});

    while(!q.empty()){
        int si = q.front().first;
        int sj = q.front().second;
        q.pop();

        if(vis[si][sj])continue;
        
        vis[si][sj] = 1;

        for(int k=0;k<4;k++){
            int ni = si + di[k];
            int nj = sj + dj[k];
            
            if(ni<=0 || ni>n || nj<=0 || nj>m)continue;
            if(vis[ni][nj] || mp[ni][nj]!='P')continue;

            q.push({ni,nj});
        }
    }
}

int main(){

    cin>> m >> n;

    for(int i=1;i<=n;i++){
        string s;
        cin>> s;
        for(int j=1;j<=m;j++){
            mp[i][j] = s[j-1];

            int a = (s[j-1] == 'T');
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a;
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<< sum[i][j] << " ";
    //     }
    //     cout<<"\n";
    // }

    int mx = 0 , wt = 1e5;

    for(int sz=min(n,m);sz>0;sz--){
        bool d = 0;
        for(int i=sz;i<=n;i++){
            for(int j=sz;j<=m;j++){
                int tmp = sum[i][j] - sum[i-sz][j] - sum[i][j-sz] + sum[i-sz][j-sz];

                if(tmp == 0){
                    mx = sz;

                    int cnt = 0;
                    memset(vis,0,sizeof(vis));

                    for(int a=i-sz+1;a<=i;a++){
                        for(int b=j-sz+1;b<=j;b++){
                            if(!vis[a][b] && mp[a][b]=='P'){
                                cnt++;
                                bfs(a,b);
                            }
                        }
                    }

                    wt = min(wt,cnt);
                    d = 1;
                }
            }
        }

        if(d){
            cout<< mx*mx << " " << wt;
            return 0;
        }
    }

    cout<< 0 << " "<< 0;

    return 0;
}