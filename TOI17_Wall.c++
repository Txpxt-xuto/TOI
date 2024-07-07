
#include<iostream>
#include<queue>
using namespace std;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int r, c, i, j, k, x, y, mx=0, sum=0;
	cin >> r >> c;
	char chr[r][c];
	for(i=0; i<r; i++)
    {
		for(j=0; j<c; j++) cin>>chr[i][j];
	}
	short d[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	bool t[r][c]={};
	queue<pair<int, int> > q;
	q.push({0, 0});
	t[0][0]=1;
	while(!q.empty()) 
    {
		y=q.front().first;
		x=q.front().second;
		q.pop();
		for(i=0; i<4; i++) 
        {
			if(y+d[i][0]>=0 && y+d[i][0]<r && x+d[i][1]>=0 && x+d[i][1]<c && chr[y+d[i][0]][x+d[i][1]]=='.' && !t[y+d[i][0]][x+d[i][1]]) 
            {
				t[y+d[i][0]][x+d[i][1]]=1;
				q.push({y+d[i][0], x+d[i][1]});
			}
		}
	}
	bool v[r][c]={};
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			if(chr[i][j]=='X' && !v[i][j]) 
            {
				sum=0;
				queue<pair<int, int> > p;
				p.push({i, j});
				v[i][j]=1;
				while(!p.empty()) 
                {
					y=p.front().first;
					x=p.front().second;
					p.pop();
					for(k=0; k<4; k++) 
                    {
						if(y+d[k][0]>=0 && y+d[k][0]<r && x+d[k][1]>=0 && x+d[k][1]<c && chr[y+d[k][0]][x+d[k][1]]=='.' && t[y+d[k][0]][x+d[k][1]]) sum++;
						if(y+d[k][0]>=0 && y+d[k][0]<r && x+d[k][1]>=0 && x+d[k][1]<c && chr[y+d[k][0]][x+d[k][1]]=='X' && !v[y+d[k][0]][x+d[k][1]]) 
                        {
							v[y+d[k][0]][x+d[k][1]]=1;
							p.push({y+d[k][0], x+d[k][1]});
						}
					}
				}
				if(sum>mx) mx=sum;
			}
		}
	}
	cout << mx;
	return 0;
}
