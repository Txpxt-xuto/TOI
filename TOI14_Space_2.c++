/*
TASK: space.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int a[1050][1050];
int n,cnt=0,ans=0;
int di[] = {1,1,-1,-1};
int dj[] = {1,-1,1,-1};
bool check(int i,int j){
    bool ans = false;
    for(int k=0;k<4 && !ans;k++){
        int i1 = i+di[k],j1 = j;
        int i2 = i      ,j2 = j+dj[k];
        int i3 = i+di[k],j3 = j+dj[k];
        if(i3 < 1 || i3 > n || j3 < 1 || j3 >n)continue;
        if(a[i][j] == a[i1][j1]){
            if(a[i][j] == a[i2][j2])
            {
                if(a[i][j] !=a[i3][j3]) ans=true;
            }
        }
    }
    return ans;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
}