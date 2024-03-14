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
        if(codeLR[i]=='L' && block[a][b-1]!='#')
        {
            k=block[a][b-1];
            block[a][b-1]=block[a][b];
            block[a][b]=k;
            b-=1;
            while (block[a+1][b]=='-')
            {
                k=block[a][b];
                block[a][b]=block[a+1][b];
                block[a+1][b]=k;
                a++;
            }
            if(block[a][b]==block[a+1][b])
            {
                block[a+1][b]='-';
            }
            if(block[a][b]==block[a][b+1])
            {
                block[a][b+1]='-';
            }
            if(block[a][b]==block[a][b-1])
            {
                block[a][b-1]='-';
            }
            block[a][b]='-';
        }
        else if(codeLR[i]=='R' && block[a][b+1]!='#')
        {
            k=block[a][b+1];
            block[a][b+1]=block[a][b];
            block[a][b]=k;
            b+=1;
            while (block[a+1][b]=='-')
            {
                k=block[a][b];
                block[a][b]=block[a+1][b];
                block[a+1][b]=k;
                a++;
            }
            if(block[a][b]==block[a+1][b])
            {
                block[a+1][b]='-';
            }
            if(block[a][b]==block[a][b+1])
            {
                block[a][b+1]='-';
            }
            if(block[a][b]==block[a][b-1])
            {
                block[a][b-1]='-';
            }
            block[a][b]='-';
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << block[i][j] << " ";
        }
        cout << endl;
    }
}