/*
TASK: block
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,l,m,n,o;
    cin >> m >> n;
    char k,block[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> block[i][j];
        }
    }
    cin >> l;
    int codexy[l][2];
    char codeLR[l];
    for(i=0;i<l;i++)
    {
        cin >> codexy[i][0] >> codexy[i][1] >> codeLR[i];
    }
    
}