/*
TASK: domino
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Hone
*/
#include <bits/stdc++.h>
using namespace std;
int n;
void recer(int x,string s)
{
    if(x==n)
    {
        cout << s << "E\n";
        return;
    }
    if(x<n) recer(x+1,s+"--\n");
    if(x+1<n) recer(x+2,s+"||\n");
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin >> n;
    recer(0,"");
}