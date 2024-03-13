/*
TASK: medal.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
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
    sort(stand, stand+N, greater<int>());
    for(i=0;i<N;i++)
    {
        sum[i]=stand[i]+heinght[i];
    }
    sort(sum, sum+N);
    for(i=0;i<N-1;i++)
    {
        count+=sum[i+1]-sum[i];
    }
    cout << count;
}