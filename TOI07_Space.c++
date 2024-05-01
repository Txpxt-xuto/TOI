/*
TASK: space
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: home
*/
#include <iostream>
using namespace std;
int d,i;
void generatebit(int n, string m)
{
    if(n==d) 
    {
        for(i=d-1;i>=0;i--) 
        {
            if(m[i]=='0') 
            {
                cout << m << " "; 
                m[i]='1'; 
                cout << m << endl; 
                m[i]='0';
            }
        }
    }
    else
    {
        generatebit(n+1,m+'0');
        generatebit(n+1,m+'1');
    }
}
int main()
{
    cin >> d;
    generatebit(0,"");
}