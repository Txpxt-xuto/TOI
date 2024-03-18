/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Function(int x)
{
    return x*x;
}

int main()
{
    //pointer
    int i;
    cin >> i;
    int k = Function(i);
    cout << k;
}