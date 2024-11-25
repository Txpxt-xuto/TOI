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
        for(i=0;i<m;i++)
        {
            k+=a[i];
            if(k>mid)
            {
                k=a[i];
                cou++;
            }
        }
        if(cou>n || mid<_max) l=mid+1;
        else r=mid;
    }
    cout << l;
}
#define ll long long
const int N = 1e6 + 7;
const ll M = 1e9 + 7;
bool occupied[N], foundCode[N];
int hashMap[N], hashKey[N];
string binaryCode;
int n, m, k, i, j;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> m;
    for(i=0;i<k;i++)
    {
    }
    return 0;
}