/*
TASK: minreq.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int l[11],p[11],s[10000001],t[11],r[12],h[12],wt;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>l[i];
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=m;i++)cin>>s[i],s[i]+=s[i-1];
    for(int j=1;j<=q;j++)cin>>t[j];

    for(int j=1;j<=q;j++)
    {
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<=n;i++)h[i]=i;
    r[n+1] = m+1;
    bool ck=0,ckin=1;
    do
    {
        int k=1;
        ckin = 1;
        for(i=1;i<=n;i++)
        {
            wt = s[r[i+1]-1] - s[r[i]-1];
            wt = (wt/(l[i]-p[h[k]])) + !(wt%(l[i]-p[h[k]])==0); 
            if(wt > t[j])
            {
                ckin=0; 
                break;
            }
            k++;
        } 
        if(ckin)
        {
            ck=1; 
            break;
        }
    }
    while(next_permutation(h+1,h+n+1));
    if(ck) cout << "P\n";
    else cout << F\n";
}
}