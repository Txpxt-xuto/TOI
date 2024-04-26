/*
TASK: car
LANG: C++
AUTHOR: Tapt Toungsakul
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std;
char arr[100][100];
int k[1000];
int m,n,t,i,j;
void recur(int row,int col)
{
    if(row == t)
    {
        for(int i = 0; i<t; i++) cout << k[i] << "\n";
    }
    if(arr[row+1][col-1]=='0')
    {
        k[row] = 1;
        recur(row+1,col-1);
    }
    if(arr[row+1][col]=='0')
    {
        k[row] = 3;
        recur(row+1,col);
    }
    if(arr[row+1][col+1]=='0')
    {
        k[row] = 2;
        recur(row+1,col+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> t;
    for(i =1 ; i<=t; i++)
    {
        for(j=0; j<m; j++) cin>>arr[i][j];
    }
    recur(0,n-1);
}
