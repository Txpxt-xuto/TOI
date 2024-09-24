/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#pragma GCC optimize("O3","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int i;
int solve(int a,int b,int c)
{
    if(c==1) return ((a+b)*104)/100;
    if(c==2) return ((a+b)*108)/100;
    if(c==3) return ((a+b)*116)/100;
}
string s;
int c=0;
int dfs(int a,int b){
    if(a>=b) return 20;
    int parse=0;
    bool ok=false;
    for(i=a;i<b;i++)
	{
        if(s[i]=='[')parse++;
        if(s[i]==']')parse--;
        if(parse==0)ok=true;
    }
    if(!ok)return dfs(a+1,b-1);
    parse=0;
    int mn=99,j=-1;
    for(i=a;i<=b;i++)
	{
        if(s[i]=='[') parse++;
        if(s[i]==']') parse--;
        if(parse<=0 && '1'<=s[i] && s[i]<='3' && mn>=s[i]-'0')
		{
            mn = s[i]-'0';
            j = i;
        }
    }
    return solve(dfs(j+1,b),dfs(a,j-1),mn);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    cout << dfs(0,s.length()-1);
}