/*
TASK: SMS
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	int n,s,m,i,r=0,c=0;
	string table="ABCDEFGHIJKLMNOPQRSTUVWXYZ",ans="";
	cin>>n;
	for(i=0;i<n;i++)
    {
		if(i==0)
        {
			cin>>s>>m;
		}
		else
        {
			cin>>r>>c>>m;	
		}
		s=s+r+(3*c);
		if(s==1)
        {
			while(m>0&&ans!="")
            {
				ans.pop_back();
				m--;
			}		
		} 
		else if(s==7) ans+=table[3*(s-2)+((m-1)%4)];
		else if(s==8||s==9) ans+=table[(3*(s-2))+1+((m-1)%(3+(s%2)))];
		else ans+=table[3*(s-2)+((m-1)%3)];		
	}
	if(ans!="") cout<<ans;
	else cout<<"null";
}