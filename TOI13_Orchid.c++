/*
TASK: orchid.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> L;
    int n,i,j,k;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> j;
        k=upper_bound(L.begin(),L.end(),j)-L.begin();
        if(k==L.size())
        {
            L.push_back(j);
        } 
        else L[k]=j;
        {
            
        
    }
    cout << n-L.size();
}