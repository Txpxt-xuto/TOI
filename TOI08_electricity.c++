/*
TASK: electricity.cpp
LANG: C++
COMPILER: VS code
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
struct cmp
{
    bool operator()(const pair<int, int> &l, const pair<int,int> &r) const{
        return l.second > r.second;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    pq.push(make_pair(0, arr[0]));
    while(!pq.empty())
    {
        pair<int, int> cell = pq.top();
        pq.pop();
        if(cell.first == n-1)
        {
            cout << cell.second;
            break;
        }
        for(int i = 1; i <= k; i++) if(cell.first + i < n) pq.push(make_pair(cell.first + i, cell.second + arr[cell.first + i]));
    }
}