/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
struct A{
    long long x,y,z,i,j,k;
}store[20];
ll want=0,mn=1e18,n;
bitset<20>vis;
long long calcdis(int ii,int jj){
    return (store[ii].x-store[jj].x)*(store[ii].x-store[jj].x)+(store[ii].y-store[jj].y)*(store[ii].y-store[jj].y)+(store[ii].z-store[jj].z)*(store[ii].z-store[jj].z);
}
void fly(ll dis,int cur,int i,int j,int k)
{
    int o;
    if(i>=want && j>=want && k>=want)
    {
        mn = min(dis,mn);
        return;
    }

}