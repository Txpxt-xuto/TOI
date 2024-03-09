/*
TASK: orchid.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j,N;
    cin >> N;
    int orchid[N];
    for(i=0;i<N;i++)
    {
        cin >> orchid[i];
    }
    int Forchid[N],Borchid[N];
    for(i=0;i<N;i++)
    {
        Forchid[i]=orchid[i];
        Borchid[i]=orchid[i];
    }
    int k1=0;
    //Front
    for(j=0;j<N;j++)
    {
        for(i=0;i<N-1;i++)
        {
            if(Forchid[i]>Forchid[i+1])
            {
                k1++;
                Forchid[i]=Forchid[i+1];
            }
        }
    }
    int k2=0;
    //Back
    for(i=0;i<N-1;i++)
    {
        if(Borchid[i]>Borchid[i+1])
        {
            k2++;
            Borchid[i+1]=Borchid[i];
        }
    }
    if(k1>=k2){cout << k2;}
    else{cout << k1;}
}