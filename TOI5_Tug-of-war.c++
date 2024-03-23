/*
TASK: Tug
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N,i;
    cin >> N;
    int Dara[N],Walailak[N];
    for(i=0;i<N;i++)cin >> Walailak[i];
    for(i=0;i<N;i++)cin >> Dara[i];
    sort(Walailak, Walailak + N);
    sort(Dara, Dara + N);
    long j=0;
    for(i=0;i<N;i++)j+=abs(Walailak[i]-Dara[i]);
    cout << j;
}