/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l=0,r=1e6,_max,i;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> a[i];
        _max=max(_max,a[i]);
    }
    while(l<r)
    {
        int mid=(l+r)/2,cou=1,k=0;
    }
}