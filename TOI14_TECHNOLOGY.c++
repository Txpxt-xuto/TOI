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
            }
    }
}