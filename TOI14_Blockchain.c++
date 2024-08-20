/*
TASK: blockchain.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
/*
TASK: blockchain.cpp
LANG: C++
AUTHOR: Tanakorn Sookhanonsawat
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    int t, q;
    map<vector<pi>, int> m;
    cin >> t >> q;
    for (i = 0; i < t; i++) {
        vector<pi> v;
        int ti;
        cin >> ti;
        for (j = 0; j < ti - 1; j++) {
            int a, b;
            cin >> a >> b;
            if (a < b) {
                v.push_back({a, b});
            }
            else {
                v.push_back({b, a});
            }
        }
        sort(v.begin(), v.end());
        m[v]++;
    }
    for (i = 0; i < q; i++) {
        vector<pi> v;
        int qi;
        cin >> qi;
        for (j = 0; j < qi - 1; j++) {
            int a, b;
            cin >> a >> b;
            if (a < b) {
                v.push_back({a, b});
            }
            else {
                v.push_back({b, a});
            }
        }
        sort(v.begin(), v.end());
        cout << m[v] << "\n";
    }
    return 0;
}
/*
3 2
10
1 2
6 4
2 5
3 5
8 6
2 7
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
5 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10
6
1 4
2 4
4 3
5 4
1 6
10
1 2
2 7
2 5
3 5
8 6
4 6
5 8
8 9
4 10