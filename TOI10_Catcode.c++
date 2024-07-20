/*
TASK: catcodes.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e6+3;
int h[mod], a[mod];
bool vis[mod];

int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
	string s;
	int n, m, sz;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin>>s;
		int cur = 0;
		for(int i=0;i<m;i++){
			cur = (cur<<1)|(s[i]-'0');
		}
		int now = cur%mod;
		while(h[now] != 0){
			now = (now+1)%mod;
		}
		h[now] = i;
		a[i] = cur;
	}
	int q, cur;
	bool f;
	cin>>q;
	while(q--){
		f=0;
		cur = 0;
		cin>>sz>>s;
		for(int i=0;i<m-1;i++){
			cur = (cur<<1)|(s[i]-'0');
		}
		for(int i=m-1;i<sz;i++){
			cur = (cur<<1)|(s[i]-'0');
			int now = cur%mod;
			while(h[now] != 0){
				if(a[h[now]] == cur){
					vis[h[now]] = 1;
					f = 1;
					break;
				}
				now = (now+1)%mod;
			}
			cur -= cur&(1<<(m-1));
		}
		if(f == true){
			for(int i=1;i<=n;i++){
				if(vis[i] == 1){
					cout<<i<<' ';
					vis[i] = 0;
				}
			}
			cout<<'\n';
		}else{
			cout<<"OK\n";
		}
	}
}