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
	int l=0;
    lps[x][0]=0;
    int i=1;
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
			if(l!=0)
			{
				l=lps[x][l-1];
			}
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
	int asz=a.size();
	int bsz=b[y].size();
    int i=0;
    int j=0;
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
	cin>>k>>m;
	for(int i=0;i<k;i++)
	{
		cin>>b[i];
		makelps(i);
	}
	cin>>n;
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
				cout<<j+1<<" ";
			}
		}
		if(c==1)
		{
			cout<<"\n";
		}
		else
		{
			cout<<"OK\n";
		}
	}
	return 0;
}
/*
5 5
01001
10110
11100
10100
11111
2
15
101010101010101
20
11110110011111000010

5 6
000111
111000
110011
100110
001100
4
16
0100000011111101
16
1011101001110011
18
000111000000000000
20
00011100011001101001
*/