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
queue<pair<int,int>> q;
int main()
{
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
			}
		}
	}
}