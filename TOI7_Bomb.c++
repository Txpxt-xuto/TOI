/*
TASK: bomb
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j,k,n,sum=0;
    cin >> n;
    int x[n],y[n],bombx[n],bomby[n];
    for(i=0;i<n;i++)
    {
        cin >> x[i] >> y[i];
        bombx[i]=0;
        bomby[i]=0;
    }
    for(i=0;i<n;i++)
    {
        int a=x[i],b=y[i];
        k=i;
        for(j=0;j<n;j++)
        {
            if(a<x[j] && b<y[j])
            {
                a=x[j];
                b=y[j];
                k=j;
            }
        }
        if(bombx[k]!=a && bomby[k]!=b)
        {
            cout << a << " " << b << endl;
            bombx[k]=a;
            bomby[k]=b;
        }
    }
}