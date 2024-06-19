/*
TASK: constellation.cpp
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int pascal[800][800]={};
int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a,b,c,i,j,k;
    cin >> a >> b >> c;
    int ps1[310][310]={},ps2[310][310]={};
    char arr[310][310];
    for(i=1;i<=a;i++) 
    {
        for(j=1;j<=b;j++) cin >> arr[i][j];
    }
    for(i=1;i<=a;i++) 
    {
        for(j=1;j<=b;j++) 
        {
            if (arr[i][j]=='#') 
            {
                ps1[i][j]++;
                ps2[i][j]++;
            }
        }
        for(j=1;j<=b;j++) 
        {
            ps1[i][j]+=ps1[i-1][j-1];
            ps2[i][j]+=ps2[i-1][j+1];
        }
    }
    int NCR[1000]={};
    
    for(i=1;i<700;i++)
    {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for(j=1;j<i;j++)
        {
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            pascal[i][j] %= 1000003;
        }
    }
    NCR[c] = 1;
    for(i=c+1;i<700;i++) NCR[i] = pascal[i][c];
    auto SE=[&ps1,&a,&b](int i1,int j1,int i2,int j2) 
    {
        if (i1-j1>=a||j1-i1>=b) return (int)0;
        if (i1>a) 
        {
            j1-=i1-a;
            i1=a;
        }
        else if(j1>b) 
        {
            i1-=j1-b;
            j1=b;
        }
        if(i2<0) 
        {
            j2-=i2;
            i2=0;
        }
        else if(j2<0) 
        {
            i2-=j2;
            j2=0;
        }
        return ps1[i1][j1]-ps1[i2][j2];
    };
    auto SW=[&ps2,&a,&b](int i1,int j1,int i2,int j2) 
    {
        if(i1+j1<2||i1+j1 >a+b) return (int)0;
        if(i1>a) 
        {
            j1+=i1-a;
            i1=a;
        }
        else if(j1<1) 
        {
            i1+=j1-1;
            j1=1;
        }
        if(i2<0) 
        {
            j2+=i2;
            i2=0;
        }
        else if(j2>b+1) 
        {
            i2+=j2-b-1;
            j2=b+1;
        }
        return ps2[i1][j1]-ps2[i2][j2];
    };
    
    int cnt = 0,cur,cap = a+b;
    i = 5;
    j = 4;
    k = 4;
    for(i=1;i<=a;i++) 
    {
        for(j=1;j<=b;j++) 
        {
            for(k=1;k<cap;k++)
            {
                cur = SE(i+k,j,i,j-k)+SW(i+k-1,j+1,i,j+k) + SE(i,j+k,i-k,j) + SW(i,j-k,i-k-1,j+1);
                cnt += NCR[cur];
                cnt %= 1000003;
            }
        }
    }
    cout << cnt;
}