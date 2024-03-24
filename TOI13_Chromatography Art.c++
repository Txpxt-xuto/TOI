/*
TASK: art.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int r,c;
    cin >> r >> c;
    vector<vector<double>> a(r+2,vector<double> (c+2,INT_MIN));
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin >> a[i][j];
        }
    }

}