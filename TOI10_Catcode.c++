/*
TASK: catcodes.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ii;
int n,i,k,q;
const ii md = 1e6+3;
bool B[(int)1e6+1]={0};
int hmap[md]={0};
ii recheck[md]={0};
int main()
{    
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
	{
        int b = 0;
        cin >> s;
        for(int i=0;i<k;i++) b = (b<<1)+(s[i]-'0');
        ii idx = b%md;
        while(hmap[idx]!=0)
		{
            idx = (idx+1)%md;
        }
        hmap[idx] = i;
        recheck[i] = b;
    }
	cin >> q;
    int b = 0,f = 0,g = 0,w,sz;
    while(q--)
	{
        b=0;
        f=0;    
        cin >> w >> s;
        sz = min(w,k-1);
        for(i=0;i<sz;i++) b = (b<<1)+(s[i]-'0');
        for(i=k-1;i<w;i++)
		{
            b = (b<<1) + (s[i]-'0');
            g = -1;
            ii idx = b%md;
            while(hmap[idx]!=0&&recheck[hmap[idx]]!=b)
			{
                idx = (idx+1)%md;
            }
            if(hmap[idx]==0||recheck[hmap[idx]]!=b) g=-1;
            else g = hmap[idx];
            if(g!=-1) {
				B[g]=1;
				f=1;
			}
            b -= b&(1<<(k-1));
        }
        if(!f) cout << "OK\n";
        else 
		{
            for(i=1;i<=n;i++)
			{
                if(B[i]) cout << i << ' ';
				B[i]=0;
            }
            cout << '\n';
        }
    }
    return 0;
}