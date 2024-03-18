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
    //int* ptr = vec.data();
    vector<int>::iterator it = vec.begin();
    cout << *it;
    *it = 10;
    cout << endl;
    cout << vec[0];
} 