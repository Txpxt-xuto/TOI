/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>      
using namespace std;
int n,m,i,j,sqa,dia,tri;
char a[1001][1001];
queue< pair<int,int> > q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(i=0;i<m;i++)
    { 
        for(j=0;j<n;j++) cin >> a[i][j];
    } 
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]=='1')
            {
                a[i][j] = '0';
                q.push({i,j});
                int cnt = 0, minx = i, maxx = i, miny = j, maxy = j;
                while(!q.empty())
                {
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    cnt+=1;
                    minx = min(minx,x);
                    maxx = max(maxx,x);
                    miny = min(miny,y);
                    maxy = max(maxy,y);
                    if(x+1<m && a[x+1][y]=='1')
                    {
                        a[x+1][y]='0';
                        q.push({x+1,y});
                    }
                    if(y+1<n && a[x][y+1]=='1')
                    {
                        a[x][y+1]='0';
                        q.push({x,y+1});
                    }
                    if(x-1>=0 && a[x-1][y]=='1')
                    {
                        a[x-1][y]='0';
                        q.push({x-1,y});
                    }
                    if(y-1>=0 && a[x][y-1]=='1')
                    {
                        a[x][y-1]='0';
                        q.push({x,y-1});
                    }
                }
                int h = maxx-minx+1, w = maxy-miny+1;
                if(h==w && h*w==cnt) sqa+=1;
                else if(h==w && h*w!=cnt) dia+=1;
                else tri+=1;
            }
        }
    }
    cout << sqa << " " << dia << " " << tri;
    return 0;  
}