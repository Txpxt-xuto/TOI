/*
TASK: electricity.cpp
LANG: C++
COMPILER: WCB
AUTHOR: YourName YourLastName
CENTER: YourCenter
*/ 
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[500100];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    deque<int> dq;
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int temp; 
        cin >> temp;
        while(dq.front()<=i-k)dq.pop_front();
        arr[i]=temp+arr[dq.front()];
        while(arr[dq.back()]>=arr[i])dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[n];
}