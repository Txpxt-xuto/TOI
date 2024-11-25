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
        cin >> binaryCode;
        ll hashCode = 0;
        for(j=0;j<m;j++) hashCode = (hashCode << 1) | (binaryCode[j] == '1');
        int idx = hashCode * M % N;
        while(occupied[idx]) idx = (idx + 1) % N;
        occupied[idx] = true;
        hashMap[idx] = hashCode;
        hashKey[idx] = i + 1;
    }
    cin >> n;
    for(i=0;i<n;i++)
    {
        int d;
        cin >> d >> binaryCode;
        ll currCode = 0;
        bool found = false;
        for(j=0;j<m-1;j++) currCode = (currCode << 1) | (binaryCode[j] == '1');
        for(j=m-1;j<d;j++)
        {
            currCode = (currCode << 1) | (binaryCode[j] == '1');
            currCode &= ~(1 << m);
            int idx = currCode * M % N;
            while(occupied[idx])
            {
                if(hashMap[idx] == currCode)
                {
                    foundCode[hashKey[idx]] = true;
                    found = true;
                    break;
                }
                idx = (idx + 1) % N;
            }
        }
        if(!found) cout << "OK";
        else
        {
            for(int j = 1; j <= k; j++)
            {
                if(foundCode[j])
                {
                    cout << j << ' ';
                    foundCode[j] = false;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
bool mat[50][50];
int sum = 0;
int recur(int x, int y, int m, int n){
}