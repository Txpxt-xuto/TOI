/*
TASK: art.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int i,j,k,n,m;
    vector<vector<int>> v;
    cin >> n >> m;
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
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> v[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}