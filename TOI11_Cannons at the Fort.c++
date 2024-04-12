/*
TASK: cannon.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/ 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,m,k,l;cin>>n>>m>>k>>l;
    vector<int> cannon(n);
    for(int &x:cannon) cin>>x;
    while(k--)
    {
        int itr=0,cnt=0;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            while(itr<n&&cannon[itr]<x-l) itr++;
            while(itr<n&&cannon[itr]<=x+l) cnt++, itr++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}