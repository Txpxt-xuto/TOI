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
    float x=0,y=0;
    while(true)
    {
		cin >> treasure;
		int num = 0;
		if(treasure == "*")
        {
            printf("%.3f %.3f %.3f",x,y,sqrt((y*y)+(x*x)));
        }
        while(treasure[0] >= '0' && treasure[0] <= '9')
        {
			num = num*10 + (treasure[0] -'0');
			treasure.erase(0,1);
        }
        int len = treasure.length();
        if(len==1)
        {
            if(treasure =="N") y+=num;
            else if(treasure =="S") y-=num;
            else if(treasure =="E") x+=num;
            else if(treasure =="W") x-=num;
        }
        else if(len!=1)
        {
            if(treasure =="NE"){y+=num;x+=num;} 
            else if(treasure =="SE"){y-=num;x+=num;}
            else if(treasure =="NW"){y+=num;x-=num;}
            else if(treasure =="SW"){y-=num;x-=num;}
        }
    }
}