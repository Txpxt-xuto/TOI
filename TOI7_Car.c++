/*
TASK: TOI07_car
LANG: C++
AUTHOR: Hattakorn Hattakarn(Karnhh._.)
CENTER: WU
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n,t,memx,memy;
    cin>>m>>n>>t;
    int arr[t+2][m+2];
    int mem[t+2][m+2];
    for(int i=0;i<=t+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            mem[i][j] = 0;
            if(i == 0 || j == 0 || i == t+1 || j == m+1)
            {
                arr[i][j] = 1;
            }else{
                cin>>arr[i][j];
                if(i == t && arr[i][j] == 0)
                {
                    memx = i;
                    memy = j;
                }
            }
        }
    }
    arr[0][n] = 0;
    for(int i=0;i<t;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j] == 0 && mem[i][j] == i)
            {
                if(arr[i+1][j] == 0) mem[i+1][j] = i+1;
                {
                    
                }
                if(arr[i+1][j-1] == 0) mem[i+1][j-1] = i+1;
                {
                    
                }
                if(arr[i+1][j+1] == 0) mem[i+1][j+1] = i+1;
                {
                    
                }
            }
        }
    }
    int i = memx,j = memy;
    vector<int> v;
    while(1)
    {
        if(i == 0)
        {
            break;
        }
        if(mem[i-1][j] == mem[i][j]-1 && arr[i-1][j] == 0)
        {
            i--;
            v.push_back(3);
        }else if(mem[i-1][j-1] == mem[i][j]-1 && arr[i-1][j-1] == 0)
        {
            i--;
            j--;
            v.push_back(2);
        }else if(mem[i-1][j+1] == mem[i][j]-1 && arr[i-1][j+1] == 0)
        {
            i--;
            j++;
            v.push_back(1);
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<"\n";
    }
    return 0;
}