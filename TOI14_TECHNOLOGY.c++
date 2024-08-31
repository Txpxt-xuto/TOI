/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e8;
int deg[N], lg[N], sz[N], dp[N], lv[N];
vector<int> adj[N], topo, root;
bool ch[N], vis[N];
signed main(){
	int n, k, T; scanf("%d %d %d", &n, &k, &T);
	for(int i = 0, sz; i<n; ++i){
		scanf("%d %d", lv+i, &sz);
		for(int j = 0, x; j<sz; ++j){
			scanf("%d", &x); adj[--x].push_back(i); ++deg[i];
		}
	}
	queue<int> q;
	for(int i = 0; i<n; ++i) if(!deg[i]) q.push(i), root.push_back(i);
	while(!q.empty()){
		int u = q.front(); q.pop();  topo.push_back(u);
		for(int v: adj[u]) if(!--deg[v]) q.push(v);
	}
	reverse(topo.begin(), topo.end());
	int ans = -1, low = 1, high = k;
	while(low<=high){
		int mid = low + ((high-low)>>1), cnt = 0;
		for(int i = 0; i<n; ++i) ch[i] = (lv[i] <= mid);
		for(int i = 0; i<n; ++i) cnt += ch[i];
		fill(lg, lg+n, -inf); fill(sz, sz+n, 0); fill(dp, dp+n, 0); fill(vis, vis+n, false);
		for(int u: topo){
			if(ch[u]) lg[u] = max(lg[u], 0), sz[u] = 1;
			for(int v: adj[u]){
				lg[u] = max(lg[u], lg[v]+1);
				if(sz[v] > 0 && !vis[v])
				{
					dp[u] += 2; vis[v] = true;
					sz[u] += sz[v];
				}
				dp[u] += dp[v];
			}
		}
		bool ch = false;
		for(int r: root)
		{
			if(sz[r] == cnt)
			{
				if(dp[r] - lg[r] <= T)
				{
					ch = true; 
					break;
				}
			}
		}
		if(ch) low = mid+1, ans = mid;
		else high = mid-1;
	}
	printf("%d", ans);
}