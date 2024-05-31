#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int shop = 500050;
ll a[shop], cost[shop], point[shop];
int main()
{
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n,q,i;
	cin >> n >> q;
	for(i=1; i<=n; ++i)
    {
		cin >> a[i];
		if(a[i] >= 0){
			point[i] += a[i];
		}
		else{
			cost[i] -= a[i];
		}
		point[i] += point[i - 1];
		cost[i] += cost[i - 1];
	}
	int k,x;
	while(q--)
    {
		cin >> k >> x;
		int id = lower_bound(cost + 1, cost + n + 1, x + cost[k]) - (cost + 1);
		cout << point[id] - point[k] << "\n";
	}
	return 0;
}