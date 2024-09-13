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
            for(j=0;j<tmp.length();j++)
			{
                if(isdigit(tmp[j]))
				{
                    if(!done)
					{
                        num1*=10;
                        num1+= tmp[j]-'0';
                    }
                    else
					{
                        num2*=10;
                        num2+= tmp[j]-'0';
                    }
                }
                else
				{
                    done = true;
                    if(tmp[j]=='@') op = 0.04f;
                    if(tmp[j]=='#') op = 0.04f;
                    if(tmp[j]=='$') op = 0.04f;
                }
            }
            total = floor((num1+num2)*op);
            total+=num1;
            total+=num2;
            if(st.empty()) return total;
            string tmp2;
            while(total != 0)
			{
                tmp2 += (total%10) + '0';
                total/=10;
            }
            reverse(tmp2.begin(),tmp2.end());
            for(int k=0;k<tmp2.length();k++) st.push(tmp2[k]);
        }
    }
}
