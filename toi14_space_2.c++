/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool a[10050][2050];
//bool vis[10050][2050];
queue<pair<int,int>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int ans_1=0,ans_2=0,ans_3=0;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			char c;
			cin >> c;
			if(c=='1') a[i][j]=true;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
	 	if(a[i][j]==true){
				int c=0,xm=i,xi=i,ym=j,yi=j;
				q.push({i,j});
				a[i][j]==false;
				while(!q.empty()){
					int x=q.front().first;
					int y=q.front().second;
					xm=max(xm,x);
					xi=min(xi,x);
					ym=max(ym,y);
					yi=min(yi,y);
					q.pop();
					for(int k=0;k<4;k++){
						int xx=x+dx[k];
						int yy=y+dy[k];
						if(a[xx][yy]==true){
							a[xx][yy]=false;
							q.push({xx,yy});
							c++;	
						}
					}
				}
				if((xm-xi+1)*(xm-xi+1)==c && (ym-yi+1)*(ym-yi+1)==c) ans_1++;			
				else if(xm-xi==ym-yi) ans_2++;
				else ans_3++;
			}
		}
	}
	cout << ans_1 << ' ' << ans_2 << ' ' << ans_3;
}