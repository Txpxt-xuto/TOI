/*
TASK: block
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n,m,k,x,y;
    cin >> n >> m;
    char a[n][m],aa;
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
    int co=0;
    queue <pair<int,int> > q,qq;
    cin >> k;
    while(k--)
    {
        cin>>x>>y>>aa;
        if(x<0||y<0||x>=n||y>=m||a[x][y]=='#'||a[x][y]=='-'){co-=5; continue;}
        if(aa=='L')
        {
            if(y-1==-1 || a[x][y-1]!='-') co-=5; continue;
            swap(a[x][y],a[x][y-1]);
            y--;
        }
        else
        {
            if(y+1==m || a[x][y+1]!='-') co-=5; continue;
            swap(a[x][y],a[x][y+1]);
            y++;
        }
        while (x+1<n && a[x+1][y]=='-')
        {
            swap(a[x][y],a[x+1][y]);
            x++;
        }
        qq.push(make_pair(x,y));
        while(!qq.empty())
        {
            x=qq.front().first; y= qq.front().second;
            qq.pop();
            if(a[x][y]=='-') continue;
            char c = a[x][y];
            for(int i=0;i<4;i++)
            {
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||yy<0||xx==n||yy==m||a[xx][yy]=='#'||a[xx][yy]=='-')continue;
                if(c == a[xx][yy])co+=5; q.push(make_pair(xx,yy));
            } 
            if(!q.empty()) co+=5; a[x][y]='-';
            while (!q.empty())
            {
                x=q.front().first; y= q.front().second;
                q.pop();
                if(a[x][y]=='-')continue;
                a[x][y]='-';
                for(int i=0;i<4;i++)
                {
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<0||yy<0||xx==n||yy==m||a[xx][yy]=='#'||a[xx][yy]=='-')continue;
                    if(c == a[xx][yy]) co+=5; q.push(make_pair(xx,yy));
                }
            }
            for(int i=n-1;i>0;i--)
            {
                for(int j=0;j<m;j++)
                {
                    if(a[i][j]=='-'&&a[i-1][j]!='#'&&a[i-1][j]!='-')
                    {
                        swap(a[i][j],a[i-1][j]); 
                        qq.push(make_pair(i,j));
                    }
                } 
            }
        }
    }
    cout << co << "\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}