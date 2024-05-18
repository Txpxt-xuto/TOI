/*
TASK: sewer
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
#define  en '\n'
#define  sp ' '
typedef long long ll;
#define android ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
char a[110][110];
int visited[110][110];
int n,m,mi=INT_MAX;
queue<pair<pii,int>> q;
int mii,mij;
const int di[]={1,0,-1,0},dj[]={0,1,0,-1};
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cin >> a[i][j],visited[i][j]=1e9;
    q.push({{1,1},visited[1][1]=1});
    while (!q.empty())
    {
        int i=q.front().first.first,j=q.front().first.second,d=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int ik=i+di[k],jk=j+dj[k];
            if(ik<1||jk<1||ik>n||jk>m)continue;
            if(di[k]==1&&(a[i][j]!='D'&&a[i][j]!='B')) continue;
            if(di[k]==-1&&(a[ik][jk]!='D'&&a[ik][jk]!='B')) continue;
            if(dj[k]==1&&(a[i][j]!='R'&&a[i][j]!='B')) continue;
            if(dj[k]==-1&&(a[ik][jk]!='R'&&a[ik][jk]!='B')) continue;
            if(visited[ik][jk]<d+1)continue;
            if(visited[ik][jk]==d+1)
            {
                cout << d+1 << en << ik << sp << jk;
                return 0;
            }
            visited[ik][jk]=d+1;
            q.push({{ik,jk},d+1});
        }
    }
    return 0;
}