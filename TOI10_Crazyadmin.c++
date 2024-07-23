/*
TASK: crazyadmin.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int n, m, l, r = 1e9;
int arr[105];
int main()
{
    cin >> m >> n;
    for(i=0;i<n;i++ )
    {
        cin >> arr[i];
        l = max( l, arr[i] );
    }
    while(l<=r)
    {
        int mid = (l+r)/2, temp = 0, c = 1;
        for(i=0;i<n;i++ )
        {
            if(temp+arr[i] > mid)
            {
                temp = arr[i];
                c++;
            }
            else temp += arr[i];
        }
        if(c <= m) r = mid-1;
        else l = mid+1;
    }
    cout << l;
    return 0;
}