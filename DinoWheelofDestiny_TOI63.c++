/*
TASK: wheel.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j,k,N,sum=1;
    char T;
    cin >> N >> T;
    int count[N];
    char wheel[N][100];
    for(i=0;i<N;i++)
    {
        cin >> wheel[i];
    }
    for(i=0;i<N;i++)
    {
        count[i]=0;
        for(j=0;j<100;j++)
        {
            if(wheel[i][j]>='0' && wheel[i][j]<='9')
            {
                count[i]+=1;
            }
            else
            {
                break;
            }
        }
    }
    for(j=1;j<100;j++)
    {
        k=0;
        for(i=0;i<N;i++)
        {
            if(T==wheel[i][j%count[i]])
            {
                k+=1;
            }
            else
            {
                sum+=1;
                break;
            }
        }
        if(k==N)
        {
            cout << sum;
            break;
        }
    }
}