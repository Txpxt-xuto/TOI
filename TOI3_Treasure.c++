/*
TASK: treasure
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <bits/stdc++.h>
using namespace std;
string treasure;
int main()
{
    int i=0;
    float x=0,y=0;
    while(i==0)
    {
		cin >> treasure;
		int num = 0;
		if(treasure == "*")
        {
            i=10;
        }
        while(treasure[0] >= '0' && treasure[0] <= '9')
        {
			num = num*10 + (treasure[0] -'0');
			treasure.erase(0,1);
        }
        if(treasure =="N") y+=num;
        else if(treasure =="S") y-=num;
        else if(treasure =="E") x+=num;            
        else if(treasure =="W") x-=num;
        else if(treasure =="NE"){y+=(num/sqrt(2));x+=(num/sqrt(2));}
        else if(treasure =="SE"){y-=(num/sqrt(2));x+=(num/sqrt(2));}
        else if(treasure =="NW"){y+=(num/sqrt(2));x-=(num/sqrt(2));}
        else if(treasure =="SW"){y-=(num/sqrt(2));x-=(num/sqrt(2));}
    }
    printf("%.3f %.3f \n%.3f",x,y,sqrt((y*y)+(x*x)));
}