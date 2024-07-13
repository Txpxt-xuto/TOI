/*
TASK: beehive.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungkul
ID: none
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int r, c;
    cin >> r >> c;

    vector<vector<int>> arr(r+2, vector<int> (c+2));
    vector<vector<int>> cnt(r+2, vector<int> (c+2));
    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=c; i++)cnt[r][i] = 1;

    for(int i=r-1; i>=1; i--){
        for(int j=1; j<=c; j++){
            if(i%2){
                // down and left
                arr[i][j] += max(arr[i+1][j], arr[i+1][j-1]);
                cnt[i][j] = (arr[i+1][j] >= arr[i+1][j-1] ? cnt[i+1][j] : 0) + (arr[i+1][j-1] >= arr[i+1][j] ? cnt[i+1][j-1] : 0);
            }
            else {
                // down and right
                arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
                cnt[i][j] = (arr[i+1][j] >= arr[i+1][j+1] ? cnt[i+1][j] : 0) + (arr[i+1][j+1] >= arr[i+1][j] ? cnt[i+1][j+1] : 0);
            }
        }
    }

    int ans = 0, co = 1;
    for(int i=1; i<=c; i++){
        if(arr[1][i]>ans){
            ans = arr[1][i];
            co = cnt[1][i];
        }
        else if(arr[1][i]==ans){
            co += cnt[1][i];
        }
    }

    cout << ans << ' ' << co;


    return 0;
}