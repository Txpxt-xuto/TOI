/*
TASK: SEGMENT
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,m,x,y,i,j;
    string s1,s2,s3,s4,s5,s6;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin.ignore();
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    getline(cin,s4);
    getline(cin,s5);
    getline(cin,s6);
    for(i=0;i<n;i++)
    {
        string str="";
        ll a;
        for(j=0;j<3;j++)
        {
            str+=s1[i*4+j];
            str+=s2[i*4+j];
            str+=s3[i*4+j];
        }
        if(str=="       ||") a=1;
        else if(str=="  |___ | ") a=2;
        else if(str=="   ___ ||") a=3;
        else if(str==" |  _  ||") a=4;
        else if(str==" | ___  |") a=5;
        else if(str==" ||___  |") a=6;
        else if(str=="   _   ||") a=7;
        else if(str==" ||___ ||") a=8;
        else if(str==" | ___ ||") a=9;
        else if(str==" ||_ _ ||") a=0;
        x+=pow(10,(n-i-1))*a;
    }
    for(i=0;i<m;i++)
    {
        string str="";
        ll a;
        for(j=0;j<3;j++)
        {
            str+=s4[i*4+j];
            str+=s5[i*4+j];
            str+=s6[i*4+j];
        }
        if(str=="       ||") a=1;
        else if(str=="  |___ | ") a=2;
        else if(str=="   ___ ||") a=3;
        else if(str==" |  _  ||") a=4;
        else if(str==" | ___  |") a=5;
        else if(str==" ||___  |") a=6;
        else if(str=="   _   ||") a=7;
        else if(str==" ||___ ||") a=8;
        else if(str==" | ___ ||") a=9;
        else if(str==" ||_ _ ||") a=0;
        y+=pow(10,(m-i-1))*a;
    }
    cout << x+y;
}