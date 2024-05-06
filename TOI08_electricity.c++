/*
TASK: electricity.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    deque<pair<int,int> > dp;
	int n, k, arr[N];
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> arr[i];
	dp.push_back(make_pair(arr[1],1));
	for(int i=2;i<=n;i++)
    {
		while(!dp.empty() && dp.front().second<=i-k-1) dp.pop_front();
		while(!dp.empty() && dp.back().first>dp.front().first+arr[i]) dp.pop_back();
		dp.push_back(make_pair(dp.front().first+arr[i],i));
	}
	cout << dp.back().first;
}