/*
TASK: medal.cpp
LANG: C++
AUTHOR: Tapat TOungsakul
CENTER: Home
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,k,N,count=0;
    cin >> N;
    int stand[N],heinght[N],sum[N];
    for(i=0;i<N;i++)
    {
        cin >> heinght[i];
    }
    for(i=0;i<N;i++)
    {
        cin >> stand[i];
    }
    sort(heinght, heinght+N);
    /*for(i=0;i<N;i++)
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
    }*/
    for(i=0;i<N;i++)
    {
        sum[i]=stand[i]+heinght[i];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(sum[j]>sum[j+1])
            {
                k=sum[j];
                sum[j]=sum[j+1];
                sum[j+1]=k;
            }
        }
    }
    for(i=0;i<N-1;i++)
    {
        count+=sum[i+1]-sum[i];
    }
    cout << count;
}