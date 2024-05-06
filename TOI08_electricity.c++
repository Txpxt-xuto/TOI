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
int arr[N];
deque<pair<int,int> > dq;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin>>arr[i];
	dq.push_back(make_pair(arr[1],1));
	for(int i=2;i<=n;i++){
		while(!dq.empty() && dq.front().second<=i-k-1) dq.pop_front();
		while(!dq.empty() && dq.back().first>dq.front().first+arr[i]) dq.pop_back();
		dq.push_back(make_pair(dq.front().first+arr[i],i));
	}
	cout<<dq.back().first;
}