/*
TASK: BRICK
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M,N,i,j,k,a;
    cin >> M >> N;
    vector<string> Brick(M);
    for(i=0;i<M;i++) cin >> Brick[i];
    for(i=0;i<N;i++)
    {
        cin >> a;
        if(Brick[0][i]=='O') continue;
        j = 0;
        while(true)
        {
            if(Brick[j][i]=='O') break;
            j++;
            if(j>=M) break;
        }
        k = j-1;
        int c = 0;
        while(true)
        {
            if(c==a) break;
            if(k<0) break;
            Brick[k][i] = '#';
            c++; 
            k--;
        }
    }
    for(i=0;i<M;i++) cout << Brick[i] << endl;
}