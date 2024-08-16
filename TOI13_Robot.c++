/*
TASK: robot.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
const int MAX_N = 1e4;
char A[MAX_N][MAX_N];
int pa[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N]={0};
const vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}}; 
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<pp> robots;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> A[i][j];
            if(A[i][j]=='X') robots.emplace_back(i,j);
        }
    }
    int Acnt=0,ans=0;
    queue<pp> q;
    for(auto [i,j]:robots)
    {
        q.emplace(i,j);
        pa[i][j]=0;
        visited[i][j]=1;
    }
    while(!q.empty())
    {
        auto [y,x] = q.front();
        q.pop();
        for(auto [u,v]:dir)
        {
            int ny=y+u,nx=x+v;
            if(ny<0||nx<0||ny>=n||nx>=m)continue;
            if(A[ny][nx]=='W')continue;
            if(visited[ny][nx])continue;
            visited[ny][nx]=1;
            pa[ny][nx]=pa[y][x]+1;
            if(A[ny][nx]=='A'){
                Acnt++;
                ans+=pa[ny][nx]*2;
            }
            q.emplace(ny,nx);
        }
    }
    cout << Acnt <<" " << ans;
}