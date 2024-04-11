#include <bits/stdc++.h>
using namespace std;

bool ans[500009];
vector<tuple<int,int,int>> e;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)
    {
		int s, f;
		cin >> s >> f;
		e.push_back({s, 1, i});
		e.push_back({f+1, -1, i});
	}
	sort(e.begin(), e.end());
	int cnt=0;
	for (auto [t,status,i] : e)
    {
		if (status == 1 && cnt < k)
        {
			ans[i] = true;
			cnt++;
		}
		else if (status == -1 && ans[i]) cnt--;
	}
	while(m--)
    {
		int q;
		cin >> q;
		cout << (ans[q] ? "Y" : "N") << " ";
	}
	return 0;	
}