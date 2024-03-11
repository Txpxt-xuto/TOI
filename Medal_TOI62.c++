/*
TASK: medal.cpp
LANG: C++
AUTHOR: Tapat TOungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int i,j,k,N;
    cin >> N;
    int stand[N],heinght[N];
    for(i=0;i<N;i++)
    {
        cin >> heinght[i];
    }
    for(i=0;i<N;i++)
    {
        cin >> stand[i];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(heinght[j]>heinght[j+1])
            {
                k=heinght[j];
                heinght[j]=heinght[j+1];
                heinght[j+1]=k;
            }
            if(stand[j]<stand[j+1])
            {
                k=stand[j];
                stand[j]=stand[j+1];
                stand[j+1]=k;
            }
        }
    }
}