/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
void kha(int left,int right,vector<long long> &v)
{
	int temp1,temp2,j;
	//cout<<left<<" "<<right<<"\n";
	/*for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";*/
	for(int i=left;i<right;i++)
	{
		if(v[i]==-3)
		{
			temp1=v[i-1];
			temp2=v[i+1];
			v[i-1]+=v[i+1];
			v[i-1]+=v[i-1]*16/100;
			v[i]=v[i-1];
			v[i+1]=v[i-1];
			j=i-2;
			while(j>=left&&(v[j]==temp1||v[j]==-5))
			{
				v[j]=v[i-1];
				j--;
			}
			j=i+2;
			while(j<=right&&(v[j]==temp2||v[j]==-5))
			{
				v[j]=v[i-1];
				j++;
			}
		}
	}
	/*for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";*/
	for(int i=left;i<right;i++)
	{
		if(v[i]==-2)
		{
			temp1=v[i-1];
			temp2=v[i+1];
			v[i-1]+=v[i+1];
			v[i-1]+=v[i-1]*8/100;
			v[i]=v[i-1];
			v[i+1]=v[i-1];
			j=i-2;
			while(j>=left&&(v[j]==temp1||v[j]==-5))
			{
				v[j]=v[i-1];
				j--;
			}
			j = i + 2;
			while(j<=right&&(v[j]==temp2||v[j]==-5))
			{
				v[j] = v[i-1];
				j++;
			}
		}
	}
	for(i=left;i<right;i++)
	{
		if(v[i]==-1)
		{
			temp1 = v[i-1];
			temp2 = v[i+1];
			v[i-1]+=v[i+1];
			v[i-1]+=v[i-1]*4/100;
			v[i] = v[i-1];
			v[i+1] = v[i-1];
			j = i - 2;
			while(j>=left&&(v[j]==temp1||v[j]==-5))
			{
				v[j] = v[i-1];
				j--;
			}
			j = i + 2;
			while(j<=right&&(v[j]==temp2||v[j]==-5))
			{
				v[j] = v[i-1];
				j++;
			}
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
    int i;
	cin >> a;
	vector<long long> v;
	stack<long long> check;
	for(i=0;i<a.size();i++)
	{
		if(a[i]>='1'&&a[i]<='3') v.push_back((a[i]-'0')*-1);
		else if(a[i]=='[')
		{
			check.push(i);
			v.push_back(-5);
		}
		else if(a[i]==']')
		{
			v.push_back(-5);
			kha(check.top(),i,v);
			check.pop();
		}
		else v.push_back(20);
	}
	kha(0,v.size(),v);
	cout << v[0];
}