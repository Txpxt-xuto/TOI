/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l=0,r=1e6,_max;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> a[i];
        _max=max(_max,a[i]);
    }
    while(l<r) {
        int mid=(l+r)/2,cou=1,k=0;
        for(int i=0;i<m;i++) {
            k+=a[i];
            if(k>mid) {
                k=a[i];
                cou++;
            }
        }
        // cout << l << " " << r << " " << mid << " " << cou << endl;
        if(cou>n || mid<_max) l=mid+1;
        else r=mid;
    }
    cout << l;
}