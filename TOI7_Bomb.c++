/*
TASK: switch.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j,k,n;
    cin >> n;
    int x[n],y[n];
    for(i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
    }
    for(i=0;i<n;i++)
    {
        int a=x[i],b=y[i];
        for(j=0;j<n;j++)
        {
            if(a<x[j] && b<y[j])
            {
                a=x[j];
                b=y[j];
            }
        }
        cout << a << " " << b << endl;
    }
}