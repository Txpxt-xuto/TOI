/*
TASK: technology.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> path; 
vector<vector<int>> memo;
void findPath(vector<vector<int>>& road, int i, int j, int t, int m) {

    if (j < 0 || j >= m || road[i][j] == 1) return;

    if (i == t) {
        for (int move : path) {
            cout << move << '\n';
        }
        return;
    }
    if (memo[i][j] != -1) return;

    path.emplace_back(1);
    findPath(road, i + 1, j - 1, t, m);
    path.pop_back(); 

    path.emplace_back(2); 
    findPath(road, i + 1, j + 1, t, m);
    path.pop_back(); 

    path.emplace_back(3);
    findPath(road, i + 1, j, t, m);
    path.pop_back();

    memo[i][j] = 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m, n, t;
    cin >> m >> n >> t;

    vector<vector<int>> road(t + 1, vector<int>(m, 0));
    memo.assign(t + 1, vector<int>(m, -1));
    
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < m; j++) {
            cin >> road[i][j];
        }
    }

    findPath(road, 0, n - 1, t, m);

    return 0;
}