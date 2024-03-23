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
    int N,i,j=0;
    cin >> N;
    int Dara[N],Walailak[N];
    for(i=0;i<N;i++)
    {
        cin >> Walailak[i];
    }
    for(i=0;i<N;i++)
    {
        cin >> Dara[i];
    }
    sort(Walailak, Walailak + N);
    sort(Dara, Dara + N);
    for(i=0;i<N;i++)
    {
        j+=Walailak[i]-Dara[i];
    }
    if(j<=0)
    {
        j=-j;
    }
    cout << j;
}