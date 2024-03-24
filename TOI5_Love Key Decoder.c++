/*
TASK: LAK
LANG: C++
AUTHOR: Tapat Toungaskul
CENTER: Home
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string bit,input,p;

char check(string s)
{
    if(s=="01000001") cout << 'A';
    else if(s=="01000010")cout << 'B';        
    else if(s=="01000011")cout << 'C';
    else if(s=="01000100")cout << 'D';
    else if(s=="01000101")cout << 'E';
    else if(s=="01000110")cout << 'F';
    else if(s=="01000111")cout << 'G';
    else if(s=="01001000")cout << 'H';
    else if(s=="01001001")cout << 'I';
    else if(s=="01001010")cout << 'J';
    else if(s=="01001011")cout << 'K';
    else if(s=="01001100")cout << 'L';
    else if(s=="01001101")cout << 'M';
    else if(s=="01001110")cout << 'N';
    else if(s=="01001111")cout << 'O';
    else if(s=="01010000")cout << 'P';
    else if(s=="01010001")cout << 'Q';
    else if(s=="01010010")cout << 'R';
    else if(s=="01010011")cout << 'S';
    else if(s=="01010100")cout << 'T';
    else if(s=="01010101")cout << 'U';
    else if(s=="01010110")cout << 'V';
    else if(s=="01010111")cout << 'W';
    else if(s=="01011000")cout << 'X';
    else if(s=="01011001")cout << 'Y';
    else cout << 'Z';
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
    for(j=0;j<input.length();j+=8)
    {
        for(i=0;i<8;i++)
        {
            p+=input[i];
        }
        cout << p << endl;
    }
    
}