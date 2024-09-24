/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
string a;
vector <char> op;
vector <int> v;
int x,y,i;
void cal()
{
    y = v.back();
	v.pop_back();
    x = v.back();
	v.pop_back();
    if(op.back()=='3') v.push_back((x+y)*116/100);
    else if(op.back()=='2') v.push_back((x+y)*108/100);
    else v.push_back(((x+y)*104)/100);
    op.pop_back();
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    getline(cin,a);
    int n = a.size();
    for(i=0;i<n;i++)
	{
        if(a[i]>='A' && a[i]<='Z') v.push_back(20);
        else if(a[i]==']')
		{
            while(op.back()!='[') cal();
			op.pop_back();
        }
		else
		{
            while(!op.empty() && a[i]<=op.back() && op.back()!='[') cal();
            op.push_back(a[i]);
        }
    }
    while (!op.empty()) cal();
    cout<<v[0];
}