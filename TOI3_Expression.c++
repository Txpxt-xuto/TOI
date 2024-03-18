/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{   
    vector<int> vec={1,2,3};
    int* ptr = vec.data();
    cout << ptr[0];
    cout << ptr[1];
    cout << ptr[2];
    ptr[0]=10;
    cout << ptr[0];
    cout << ptr[1];
    cout << ptr[2];
} 