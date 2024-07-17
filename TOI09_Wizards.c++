#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  cout.tie(0);

  int xt, yt;
  cin >> xt >> yt;

  int n;
  cin >> n;

  vector<vector<pair<int, int>>> v(4);
  vector<tuple<ll, ll, int, int>> f, s;

  for(int i=0; i<4; i++) {
    for(int j=0; j<n; j++) {
      int x, y;
      cin >> x >> y;
      v[i].push_back({x, y});
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      f.push_back({v[0][i].first + v[1][j].first, v[0][i].second + v[1][j].second, i, j});
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      s.push_back({v[2][i].first + v[3][j].first, v[2][i].second + v[3][j].second, i, j});
    }
  }

  sort(f.begin(), f.end());
  sort(s.begin(), s.end());

  for(int l=0, r=n*n-1;;) {
    ll temp_x = get<0>(f[l]) + get<0>(s[r]);
    ll temp_y = get<1>(f[l]) + get<1>(s[r]);

    if(temp_x < xt) {
      l++;
    }else if(temp_x > xt) {
      r--;
    }else if(temp_y < yt) {
      l++;
    }else if(temp_y > yt) r--;
        else 
        {
            cout << v[0][get<2>(f[l])].first << " " << v[0][get<2>(f[l])].second << endl;
            cout << v[1][get<3>(f[l])].first << " " << v[1][get<3>(f[l])].second << endl;
            cout << v[2][get<2>(s[r])].first << " " << v[2][get<2>(s[r])].second << endl;
            cout << v[3][get<3>(s[r])].first << " " << v[3][get<3>(s[r])].second;
            return 0;
        }
    }
}