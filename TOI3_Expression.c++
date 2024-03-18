/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void hello(int a)
{
    cout << "auto " << a << endl;
}

int main()
{   
    //pointer
    /*  (number = *ptr and &number = ptr) */
    int number = 10;
    int* ptr = &number;
    cout << &number << endl;
    cout << *ptr << endl;

    number = 20;
    cout << &number << endl;
    cout << *ptr << endl;

    *ptr = 30; // number = 30
    cout << endl;
    cout << &number << endl;
    cout << ptr << endl;
    cout << number << endl;
    cout << *ptr << endl;
    cout << endl;
    int arr[5]={1,2,3,4,5};
    int* ptrarr = arr ; //มีค่าเท่ากับ int* ptrarr = &arr[0];
    cout << *ptrarr << endl; //ค่าเริ่มที่ array ตำแหน่งที่ 0
    cout << ptrarr << endl; //pointer เริ่มที่ array ตำแหน่งที่ 0
    cout << arr << endl; //pointer เริ่มที่ array ตำแหน่งที่ 0
    void (*functionptr)(int) = hello;
    functionptr(1);


    return 0;
}