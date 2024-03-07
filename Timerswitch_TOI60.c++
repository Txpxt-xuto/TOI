/*
TASK: switch.cpp
LANG: C++
AUTHOR: YourName YourLastName
CENTER: YourCenter
*/
#include <iostream>
using namespace std;
int N,i,j=1;
string timer_switch;
int main()
{
    cin >> N >> timer_switch;
    for(i=0;i<N-1;i++)
    {
        if(timer_switch[0]==timer_switch[i+1])
        {
            cout << j;
            break;
        }
        else
        {
            j++;
        }
    }
}