/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int arr[4][4], tmp[10], table[10], num_x[] = {1, 0, -1, 0, 1, 1, -1, -1}, num_y[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
double min = 2000000000;
int in_range(int x, int a){
    if(x >= 0 && x <= a) return 1;
    return 0;
}
void run(int index)
{
    int i;
    if(index == n * m)
	{
        int j, x, y;
        double c, sum = 0, land[4][4];
        for(i=0;i<n;i++)
		{
            for(j=0;j<m;j++) land[i][j] = 1.0*arr[i][j];
        }
        for(i=0;i<n*m;i++)
		{
            sum += land[table[i] / m][table[i] % m];
            c = land[table[i] / m][table[i] % m]/10;
            land[table[i] / m][table[i] % m] = 0;
            x = table[i] / m;
            y = table[i] % m;
            for(j=0;j<8;j++)
			{
                if(in_range(x+num_x[j], n) && in_range(y+num_y[j], m)) land[x+num_x[j]][y+num_y[j]] += c;
            }
        }
        if(sum < min) min = sum;
        return;
    }
    for(i=0;i<n*m;i++)
	{
        if(tmp[i] == 1) continue;
        tmp[i]++;
        table[index] = i;
        run(index+1);
        tmp[i]--;
    }
}
int main()
{
<<<<<<< HEAD:toi14_space_2.c++
    int i, j, k;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
	{
        for(j=0;j<m;j++) scanf("%d", &arr[i][j]);
    }
    run(0);
    printf("%.2lf", min);
    return 0;
}
=======
	ios::sync_with_stdio(0); 
    	cin.tie(0);
	int ans1 = 0, ans2 = 0, ans3 = 0;
	int n, m, i, j, k;
	cin >> n >> m;
	for(i=1;i<=m;i++)
    	{
		for(j=1;j<=n;j++)
        	{
			char c;
			cin >> c;
			if(c=='1') a[i][j]=true;
		}
	}
	for(i=1;i<=m;i++)
    	{
		for(j=1;j<=n;j++)
       		{
	        	if(a[i][j]==true)
            		{
				int c = 0, xm = i, xi = i, ym = j, yi = j;
				q.push({i,j});
				a[i][j]==false;
				while(!q.empty())
                		{
					int x = q.front().first,y = q.front().second;
					xm = max(xm,x);
					xi = min(xi,x);
					ym = max(ym,y);
					yi = min(yi,y);
					q.pop();
					for(k=0;k<4;k++)
                   			 {
						int xx=x+dx[k], yy=y+dy[k];
						if(a[xx][yy]==true)
                        			{
							a[xx][yy] = false;
							q.push({xx,yy});
							c++;	
						}
					}
				}
				if((xm-xi+1)*(xm-xi+1)==c && (ym-yi+1)*(ym-yi+1)==c) ans1++;			
				else if(xm-xi==ym-yi) ans2++;
				else ans3++;
			}
		}
	}
	cout << ans1 << ' ' << ans2 << ' ' << ans3;
}
>>>>>>> 1ff3fad6191e91ab22d838da43218f9d4920f112:TOI14_Space_2.c++
