/*
TASK: catcodes.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int mod = 1e6+3;
int h[mod], a[mod];
string s;
int n, m, cur, q, sz,now;
bool f = 0;
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
	cin >> n >> m;
    bool vis[n+1]{};
	for(int i=1;i<=n;++i){
		cin>>s;
		cur = 0;
		for(int i=0;i<m;++i) cur = (cur<<1)+(s[i]-'0');
		now = cur%mod;
		while(h[now] != 0){
			++now;
			if(now == mod) now = 0;
		}
		h[now] = i;
		a[i] = cur;
	}
	cin>>q;
	while(q--){
		f=0;
		cur = 0;
		cin>>sz>>s;
		for(int i=0;i<m-1;++i){
			cur = (cur<<1)+(s[i]-'0');
		}
		for(int i=m-1;i<sz;++i){
			cur = (cur<<1)+(s[i]-'0');
			now = cur%mod;
			while(h[now] != 0){
				if(a[h[now]] == cur){
					vis[h[now]] = 1;
					f = 1;
					break;
				}
				++now;
				if(now == mod) now = 0;
			}
			cur -= cur&(1<<(m-1));
		}
		if(f){
			for(int i=1;i<=n;++i){
				if(vis[i] == 1) cout<<i<<' ',vis[i]=0;
			}
			cout<<'\n';
		}else{
			cout<<"OK\n";
		}
	}
}