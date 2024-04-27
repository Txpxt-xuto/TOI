/*
TASK: filter
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int W,H,n,i,j;
    cin >> W >> H >> n;
    int Long[n],Position[n],Sun_100=0,Sun_50=0;
    int Area[4000]={};
    for(i=0;i<n;i++) cin >> Position[i] >> Long[i];
    for(i=0;i<n;i++)
    {
        for(j=Position[i];j<Position[i]+Long[i];j++) Area[j]+=1;
    }
    for(i=0;i<W;i++)
    {
        if(Area[i]==0) Sun_100+=1;
        else if(Area[i]==1) Sun_50+=1;
    }
    cout << Sun_100*H << " " << Sun_50*H;
}