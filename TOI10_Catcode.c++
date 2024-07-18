/*
TASK: catcodes.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int k,m,n,c,d;
string b[100001];
int lps[100001][31];
void makelps(int x)
{
	int l=0,i=1;
    lps[x][0]=0;
    while(i<b[x].size())
	{
		if(b[x][i]==b[x][l])
		{
			l++;
			lps[x][i]=l;
			i++;
		}
		else
		{
			if(l!=0) l=lps[x][l-1];
			else
			{
				lps[x][i]=0;
				i++;
			}
		}
    }
}
bool search(string& a,int y)
{
	int asz=a.size(),bsz=b[y].size();
    int i=0,j=0;
    while(asz-i>=bsz-j)
	{
		if(a[i]==b[y][j])
		{
			i++;
			j++;
		}
		if(j==bsz)
		{
			return true;
		}
		else if(i<asz && a[i]!=b[y][j])
		{
			if(j!=0)
			{
				j=lps[y][j-1];
			}
			else
			{
				i=i+1;
			}
		}
	}
	return false;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> m;
	for(int i=0;i<k;i++)
	{
		cin >> b[i];
		makelps(i);
	}
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string a;
		cin>>d;
		cin>>a;
		c=0;
		for(int j=0;j<k;j++)
		{
			if(search(a,j))
			{
				c=1;
				cout << j+1 << " ";
			}
		}
		if(c==1) cout << "\n";
		else cout << "OK\n";
	}
	return 0;
}
