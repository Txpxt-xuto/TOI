#include<bits/stdc++.h>      
using namespace std;
int n,m;
char a[1001][1001];
int sqa,dia,tri;
queue< pair<int,int> > q;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    for(int i=0; i<m;i++){
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='1')
            {
                a[i][j]='0';
                q.push({i,j});
                int cnt=0;
                int minx=i;
                int maxx=i;
                int miny=j;
                int maxy=j;
        
        while(!q.empty()){
          int x=q.front().first;
          int y=q.front().second;
          q.pop();

          cnt+=1;
          minx=min(minx,x);
          maxx=max(maxx,x);
          miny=min(miny,y);
          maxy=max(maxy,y);
          
          if(x+1<m && a[x+1][y]=='1'){
            a[x+1][y]='0';
            q.push({x+1,y});
          }
          if(y+1<n && a[x][y+1]=='1'){
            a[x][y+1]='0';
            q.push({x,y+1});
          }
          if(x-1>=0 && a[x-1][y]=='1'){
            a[x-1][y]='0';
            q.push({x-1,y});
          }
          if(y-1>=0 && a[x][y-1]=='1'){
            a[x][y-1]='0';
            q.push({x,y-1});
          }
          
        }//q
        int h=maxx-minx+1;
        int w=maxy-miny+1;
        if(h==w && h*w==cnt){// square
          sqa+=1;
        }
        else if(h==w && h*w!=cnt){//diamond
          dia+=1;
        }
        else{
          tri+=1;
        }
      }//if
      
    }//for j
  }//for i
  cout<<sqa<<" "<<dia<<" "<<tri;
  
  return 0;  
}