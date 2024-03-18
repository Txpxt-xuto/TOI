/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{   
    vector<int> a;
    int i,j,k,n;
    cin >> j;
    for(i=0;i<j;i++)
    {
        cin >> k;
        a.push_back(k);
    }
    for(i=0;i<j;i++)
    {
        cout << a[i] << " ";
    }
    cin >> n;
    a.erase(a.begin()+n);
    cout << endl;
    for(i=0;i<a.size();i++)
    {
        cout << a[i] << " ";
    }
} 