/*
TASK: LAK
LANG: C++
AUTHOR: Tapat Toungaskul
CENTER: Home
*/
#include <iostream>
#include <algorithm>
using namespace std;
string bit;
int main()
{
    int N,i,j;
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin >> bit;
    }
    int status=1;
    for(i=0;i<bit.length();i+=2)
    {
        if(status==1 && (bit[i]=='0' && bit[i+1]=='0'))
        {

        }
        else if(status==1 && (bit[i]=='1' && bit[i+1]=='1'))
        {
            status=2;
            cin >> "1";
        }
        else if(status==2 && (bit[i]=='1' && bit[i+1]=='0'))
        {
            status=3;
            cin >> "0";
        }
        else if(status==2 && (bit[i]=='0' && bit[i+1]=='1'))
        {
            status=4;
            cin >> "1";
        }
        else if(status==3 && (bit[i]=='0' && bit[i+1]=='0'))
        {
            status=2;
            cin >> "1";
        }
        else if(status==3 && (bit[i]=='1' && bit[i+1]=='1'))
        {
            status=1;
            cin >> "0";
        }
        else if(status==4 && (bit[i]=='0' && bit[i+1]=='1'))
        {
            status=3;
            cin >> "0";
        }
        else if(status==4 && (bit[i]=='1' && bit[i+1]=='0'))
        {
            cin >> "1";
        }
    }
}