/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
bitset<2000> ss[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i, j;
    cin >> m >> n;
    for(i=0;i<n;i++)
    cin >> ss[i];
    int r=0,t=0,k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(ss[i][j])
            {
                if(j+1<m && i+1<n && ss[i][j+1] && ss[i+1][j]) r++;
                else if(j+1<m && ss[i][j+1]) t++;
                else if(i+1<n && j-1>=0 && j+1<m && ss[i+1][j-1] && ss[i+1][j+1])
                {
                    int o=0;
                    while(i+o<n && ss[i+o][j]) o++;
                    if(ss[i+o-1][j-1]) t++;
                    else k++;
                }
                else t++;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty())
                {
                    auto p=q.front();
                    q.pop();
                    if(ss[p.f][p.s]==0)
                    continue;
                    ss[p.f][p.s]=0;
                    for(int l=0;l<4;l++)
                    {
                        int iii=p.f+di[l],jjj=p.s+dj[l];
                        if(iii<0||iii>=n||jjj<0||jjj>=m)
                        continue;
                        if(ss[iii][jjj])
                        q.push({iii,jjj});
                    }
                }
            }
        }
    }
    cout << r << " " << k << " " << t;
}