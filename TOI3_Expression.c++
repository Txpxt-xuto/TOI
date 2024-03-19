/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    int n,i=0,j,h,t;
    cin >> n;
    int a[100];
    h=0;
    t=sizeof(a)/sizeof(a[0]);
    for(i=0;i<t;i++)
    {
        a[i]=i+1;
    }
    
    while(true)
    {
        i=(h+t)/2;
        if(a[i]==n)
        {
            cout << endl << i;
            break;
        }
        else if(a[i]>n)
        {
            t=i+1;
            cout << i << " ";
        }
        else if(a[i]<n)
        {
            h=i+1;
            cout << i << " ";
        }
    }
}