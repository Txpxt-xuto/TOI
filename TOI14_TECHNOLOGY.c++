/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
string s;
void insrt(char p)
{
	int i,j;
    for(i=0;i<s.length();i++)
	{
        if(s[i]==p)
		{
            if(s[i]== '3') s[i] = '@';
            if(s[i]=='2') s[i]='#';
            if(s[i]=='1') s[i]='$';
            int cnt=0;
            for(j=i-1;j>=0;j--)
			{
                if(s[j] == ']') cnt++;
                else if(s[j] == '[') cnt--;
                if(cnt == 0)
				{
                    if(isalpha(s[j])) s[j]='*';
                    s.insert(j,"[");
                    i++;
                    break;
                }
            }
            for(j=i+1;j<s.length();j++)
			{
                if(s[j] == '[') cnt++;
                else if(s[j] == ']') cnt--;
                if(cnt == 0){
                    if(isalpha(s[j])) s[j]='*';
                    s.insert(j+1,"]");
                    i++;
                    break;
                }
            }
        }
    }
}
int calculate(string ss)
{
    stack<char> st;
    int total=0,i;
    for(i=0;i<s.length();i++)
	{
        st.push(s[i]);
        if(st.top() == ']')
		{
            string tmp;
            st.pop();
            while(!st.empty() && st.top()!='[')
			{
                tmp += st.top();
                st.pop();
            }
            reverse(tmp.begin(),tmp.end());
            st.pop();
            float num1=0,num2=0,op=0;
            bool done = false;
        }
    }
}