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