/*
TASK: bomb
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

bool cmp(pii a, pii b){
  if(a.first==b.first){return a.second<b.second;}
  return a.first>b.first;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> v;
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    v.push_back({x,y});
  }
  sort(v.begin(),v.end(),cmp);
  int mx=0;
  for(auto [x,y]:v){
    if(y>=mx){
      mx=y;
      cout << x << " " << y << "\n";
    }
  }
  return 0;
}
