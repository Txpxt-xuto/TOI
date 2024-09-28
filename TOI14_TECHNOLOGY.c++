/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream> 

using namespace std;

int arr[1001][1001];
int qs[1001][1001]; 

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    for(i=1; i<=n; i++)
	{
        for(j=1; j<=m; j++) cin >> arr[i][j];
    }
    for(i=1; i<=n; i++)
	{
        for(j=1; j<=m; j++) qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + arr[i][j];
    }
    int ans = 0;
    for(i=k; i<=n; i++)
	{
        for(j=k; j<=m; j++) ans = max(ans, qs[i][j] - qs[i-k][j] - qs[i][j-k] + qs[i-k][j-k]);
    }
    cout << ans << '\n';
    return 0;
}