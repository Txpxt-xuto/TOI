/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
const int mx = 1e3+5;
string s1,s2;
int k;
bool dp[mx][mx];
int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> s1 >> s2 >> k;
	string t;
	int n = s1.length();
	int m = s2.length();
	while(k--)
	{
		cin >> t;
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(i>0) dp[i][j] |= s1[i-1] == t[i+j-1] && dp[i-1][j];
				if(j>0) dp[i][j] |= s2[j-1] == t[i+j-1] && dp[i][j-1];
			}
		}
		if(dp[n][m]) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string a, b, s;
bool dp[1005][1005];
signed main()
{
	int k; cin>>a>>b>>k; int m = a.length(), n = b.length();	while(k--){
		cin>>s; memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for(int i = 0; i<=m; ++i){
			for(int j = 0; j<=n; ++j)
            {
				if(i && s[i+j-1] == a[i-1]) dp[i][j] |= dp[i-1][j];
				if(j && s[i+j-1] == b[j-1]) dp[i][j] |= dp[i][j-1];
			}
		}
		if(dp[m][n]) puts("Yes");
		else puts("No");
	}
}
