#include <iostream>
using namespace std;
int d;
void generatebit(int n, char s[])
{
    if(n==d) 
    {
        for(int i=d-1;i>=0;i--) 
        {
            if(s[i]=='0') 
            {
                cout << s << " "; 
                s[i]='1'; 
                cout << s << endl; 
                s[i]='0';
            }
        }
    }
    else
    {
        generatebit(n+1,s+'0');
        generatebit(n+1,s+'1');
    }
}
int main()
{
    cin >> d;
    generatebit(d,"");
}