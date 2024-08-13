/*
TASK: cats.cpp
LANG: C++
AUTHOR: YourName YourLastName
CENTER: YourCenter
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cat[2000001] , sortcat[2000001];
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int k = 0;
    for(i=0;i<n;i++)
    {
        cin >> cat[i];
        sortcat[i] = cat[i];
        if(i % 2 == 1)
        {
            if(cat[i] != cat[i-1]) k = 1;
        }
    }
    if(k == 0)
    {
        cout << 0;
        return 0;
    }
    sort(sortcat , sortcat + n);
    ll maximum = sortcat[n-1];
    int first = 0 , last = n-1;
    for(int j = 0 ; j < log(n) / log(2) + 1 ; j++){
        int mid = (first + last) / 2;
        int check = 0;
        queue<ll> q;
        for(int i = 0 ; i < n ; i++){
            if(cat[i] > sortcat[mid]) q.push(cat[i]);
        }
        while(!q.empty()){
            ll a = q.front();
            q.pop();
            ll b = q.front();
            q.pop();
            if(a != b){
                check = 1;
                break;
            }
        }
        if(check == 0){
            last = mid;
            maximum = sortcat[mid];
        }
        else{
            first = mid;
        }
    }
    cout << maximum;
    return 0;
}