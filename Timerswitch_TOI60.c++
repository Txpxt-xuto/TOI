/*
TASK: switch.cpp
LANG: C++
AUTHOR: YourName YourLastName
CENTER: YourCenter
*/
#include <iostream>
using namespace std;
int N,i,j=1,k,x,y;
string timer_switch,check;
int main()
{
    cin >> N >> timer_switch;
    check=timer_switch;
    for(i=0;i<=N;i++)
    {
        if(k==N)
        {
            cout << x ;
            break;
        }
        for(j=0;j<N-1;j++)
        {
            y=check[j];
            check[j]=check[j+1];
            check[j+1]=y;
        }
        for(j=0;j<N;j++)
        {
            cout << check[j];
        }
        cout << "\n";
        x++;
        k=0;
        for(j=0;j<N;j++)
        {    
            if(check[j]==timer_switch[j])
            {
                k++;
            }
            else{break;}
        }
    }
}