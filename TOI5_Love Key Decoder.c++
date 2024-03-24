/*
TASK: LAK
LANG: C++
AUTHOR: Tapat Toungaskul
CENTER: Home
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
string bit,input;
int bin_to_int(string);

int bin_to_int(string s)
{
    int dec = 0,j,len = s.length();
    for (int j = 0; j < len; j+=8)
    {
        dec = 0;
        for (int i = 0; i < 8; i++)
        {
            dec += ((int)s[i] - '0') * pow(2, len - i - 1);
        }
        cout << dec;
    }
    return 0;
}

int main()
{
    int N,i,j;
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin >> input;
        bit += input;
    }
    int status=1;
    i=0;
    input={};
    while (i<bit.length())
    {
        if(status==1 && (bit[i]=='0' && bit[i+1]=='0'))
        {
            input+='0';
        }
        else if(status==1 && (bit[i]=='1' && bit[i+1]=='1'))
        {
            status=2;
            input+='1';
        }
        else if(status==2 && (bit[i]=='1' && bit[i+1]=='0'))
        {
            status=3;
            input+='0';
        }
        else if(status==2 && (bit[i]=='0' && bit[i+1]=='1'))
        {
            status=4;
            input+='1';
        }
        else if(status==3 && (bit[i]=='0' && bit[i+1]=='0'))
        {
            status=2;
            input+='1';
        }
        else if(status==3 && (bit[i]=='1' && bit[i+1]=='1'))
        {
            status=1;
            input+='0';
        }
        else if(status==4 && (bit[i]=='0' && bit[i+1]=='1'))
        {
            status=3;
            input+='0';
        }
        else if(status==4 && (bit[i]=='1' && bit[i+1]=='0'))
        {
            input+='1';
        }
        i+=2;
    }
    cout << input;
    bin_to_int(input);
}