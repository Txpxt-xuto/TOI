/*
TASK: FILTER
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
using namespace std;
int main()
{
    int n,m,i;
    cin >> n >> m;
    char word[n][m];
    for(i=0;i<n;i++)
    {
        cin >> word[i];
    }
    for(i=0;i<n;i++)
    {
        cout << word[i] << endl;
    }
}