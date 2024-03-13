/*
TASK: block
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,l,m,n;
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
    for(i=0;i<l;i++)
    {
        int a=codexy[i][0],b=codexy[i][1];
        if(codeLR[i]=='L')
        {
            k=block[a][b-1];
            block[a][b-1]=block[a][b];
            block[a][b]=k;
        }
        else if(codeLR[i]=='R')
        {
            k=block[a][b+1];
            block[a][b+1]=block[a][b];
            block[a][b]=k;
        }
    }
    
}