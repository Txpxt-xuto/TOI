/*
TASK: switch.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    string s; 
    cin >> n >> s;
    queue<bool> main, sub;
    for (int i = 0;i < n;i++) 
    {
        main.push(s[i] == '0');
        sub.push(s[i] == '0');
    }
    for (int i = 1;i <= n;i++)
    {
        sub.push( sub.front()); 
        sub.pop();
        if (n % i == 0 && main ==  sub)
        {
            cout << i;
            return 0;
        }
            
    }
}
/*
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
*/