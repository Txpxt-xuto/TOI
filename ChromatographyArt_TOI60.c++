/*
TASK: art.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j,k,N,non,z,max=0;
    cin >> N >> non;
    int s[N],h[N],w[N],o[N];
    int table[3*N][3*N],count[100];
    for(i=0;i<N;i++)
    {
        cin >> s[i] >> h[i] >> w[i] >> o[i];
    }
    for(i=0;i<N;i++)
    {
        int position=s[i];
        for(j=0;j<h[i];j++)
        {
            for(k=0;k<w[i];k++)
            {
                table[position+k][j]=+o[i];
            }
        }
    }
    //สิ้้นสุดเขต work
    for(i=0;i<N;i++)
    {
        int position=s[i];
        for(j=0;j<h[i];j++)
        {
            for(k=0;k<w[i];k++)
            {
                for(z=0;z<100;z++)
                {
                    if(z==table[position+k][j])
                    {
                        count[z]++;
                    }
                    else{break;}
                }
            }
        }
    }
    for(z=0;z<100;z++)
    {
        if(max<count[z])
        {
            max=count[z];
        }
    }
    cout << max;
}