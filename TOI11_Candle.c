/*
TASK: candle.cpp
LANG: C++
AUTHOR: YourName YourLastName
CENTER: YourCenter
*/ 
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
char arr[2000][2000];
int ;
int di[8]={-1,-1,0,1,1,1,0,-1};
int dj[8]={0,1,1,1,0,-1,-1,-1};
queue<pair<int,int>> q;
bool issafe(int i,int j)
{
    if(i<0 or i>=n or j<0 or j>=m)return false;
    if(arr[i][j]=='0')return false;
    return true;
}
