/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll z, k, n;
ll dino[2000005], bond[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> z >> k >> n;
    for( ll i=0;i<n;i++ ) cin >> bond[i];
    dino[1] = -1;
    for( ll i=2;i<=z;i++ )
    {
        if( dino[i] != 0 ) continue;
        if( k%i == 0 ) for( ll j=i;j<=z;j+=i ) dino[j] = 1;
        else dino[i] = -1;
    }
    /*cout << "------------------\n";
    for( int i=0;i<=z;i++ ) cout << dino[i] << " ";
    cout << endl;*/
    for( ll i=1;i<=z;i++ ) dino[i] += dino[i-1];
    ll ans = 0;
    for( int i=0;i<n;i++ )
    {
        for( int j=i+1;j<n;j++ )
        {
            ans = max( ans, dino[bond[j]]-dino[bond[i]-1] );
        }
    }
    cout << ans;
    return 0;
}
