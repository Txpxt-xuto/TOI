/*
TASK: robot.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int row,col;
	cin >> row >> col;
	vector<vector<char> > robot(row,vector<char> (col));
	queue<pair<int, int> > q;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin >> robot[i][j];
			if(robot[i][j]=='X')
            {
				q.push({i,j});
			}
		}
	}
	vector<vector<int>> distance(row, vector<int>(col, 0));
	int dx[4]={0,0,1,-1};
	int dy[4]={-1,1,0,0};
	int count=0;
	int move=0;
	while(!q.empty())
    {
		int _x=q.front().first;
		int _y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
        {
			int x=_x+dx[i];
			int y=_y+dy[i];
			if(x<0 || x>=row || y<0 || y>=col)
            {
				continue;
			}
			if((robot[x][y]=='E' || robot[x][y]=='A') && distance[x][y]<=distance[_x][_y]){
				distance[x][y]=distance[_x][_y]+1;
				if(robot[x][y]=='A'){
					count++;
					move=move+2*distance[x][y];
				}
				robot[x][y]=' ';
				q.push({x,y});
			}
		}
	}
	cout << count << " " << move;
}